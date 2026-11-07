"""Finite host checks for bounded requests, opaque PCM and desktop playback."""
from contextlib import contextmanager
import io
import json
from pathlib import Path
import socket
import sys
import tempfile
import threading
import unittest
from unittest.mock import patch
import wave

import client
from protocol import Connection, ProtocolError, exact
from server import Server


@contextmanager
def running(source, max_block=256):
    with Server(("127.0.0.1", 0), source, max_block) as server:
        thread = threading.Thread(target=server.serve_forever, kwargs={"poll_interval": .01})
        thread.start()
        try:
            yield server.server_address
        finally:
            server.shutdown()
            thread.join(timeout=2)
            if thread.is_alive():
                raise AssertionError("Owned server thread did not stop")


class StreamTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.folder = Path(self.temporary.name)
        # Contains every byte value plus AT-looking text; not text-safe payload.
        self.data = bytes(range(256)) * 32 + b"\x00\r\nOK\r\n+IPD,4:DATA\xff"
        self.source = self.folder / "test.wav"
        with wave.open(str(self.source), "wb") as target:
            target.setnchannels(1)
            target.setsampwidth(1)
            target.setframerate(8000)
            target.writeframes(self.data)

    def test_bounded_binary_blocks_and_fractional_eof(self):
        with running(self.source) as address, Connection(*address) as connection:
            self.assertEqual(connection.track.rate, 8000)
            self.assertEqual(connection.track.length, len(self.data))
            received = bytearray()
            while connection.position < connection.track.length:
                received.extend(connection.get(127))
            self.assertEqual(bytes(received), self.data)
            self.assertEqual(connection.get(1), b"")

    def test_no_audio_without_request_and_oversized_request_refused(self):
        with running(self.source) as address, Connection(*address) as connection:
            connection.socket.settimeout(.03)
            with self.assertRaises(TimeoutError):
                connection.socket.recv(1)
            connection.socket.settimeout(1)
            connection.socket.sendall(b"GET 257\n")
            self.assertEqual(connection.stream.readline(), b"ERR count\n")
            self.assertEqual(connection.stream.read(1), b"")

    def test_each_connection_starts_at_track_beginning(self):
        with running(self.source) as address:
            for _ in range(2):
                with Connection(*address) as connection:
                    self.assertEqual(connection.get(31), self.data[:31])

    def test_partial_reads_and_truncated_body(self):
        class Short(io.BytesIO):
            def read(self, count=-1):
                return super().read(min(count, 3))
        self.assertEqual(exact(Short(self.data), len(self.data)), self.data)
        with self.assertRaises(ProtocolError):
            exact(Short(b"short"), 6)

    def test_probe_does_not_start_audio(self):
        with running(self.source) as address, Connection(*address) as connection:
            with patch("client.subprocess.Popen", side_effect=AssertionError("Audio started")):
                report = client.probe(connection, .125)
            self.assertEqual(report["received_pcm_bytes"], 1000)
            self.assertFalse(report["audio_started"])

    def test_timed_client_with_silent_capture_sink(self):
        sink = self.folder / "capture-player"
        output = self.folder / "played.u8"
        sink.write_text(f"#!{sys.executable}\nimport sys\nfrom pathlib import Path\nPath({str(output)!r}).write_bytes(sys.stdin.buffer.read())\n")
        sink.chmod(0o700)
        args = type("Args", (), {"seconds": None, "chunk_ms": 20, "prebuffer_ms": 500})()
        with running(self.source, 2048) as address, Connection(*address) as connection:
            with patch("client.shutil.which", return_value=str(sink)):
                report = client.play(connection, args)
        self.assertEqual(output.read_bytes(), self.data)
        self.assertEqual(report["source_pcm_bytes_played"], len(self.data))
        self.assertEqual(report["silence_bytes_inserted"], 0)


if __name__ == "__main__":
    unittest.main()
