#!/usr/bin/env python3
"""Serve one prepared U8 mono WAV as client-requested raw PCM blocks."""
import argparse
from datetime import datetime, timezone
import json
import os
from pathlib import Path
import signal
import socket
import socketserver
import wave

from protocol import ProtocolError, line


def describe(path):
    with wave.open(str(path), "rb") as source:
        if (source.getnchannels(), source.getsampwidth(), source.getcomptype()) != (1, 1, "NONE"):
            raise ValueError("Source must be uncompressed unsigned 8-bit mono WAV")
        rate, length = source.getframerate(), source.getnframes()
        if not 1 <= rate <= 65535 or not 0 < length <= 0xffffffff:
            raise ValueError("Unsupported rate or empty/oversized source")
        return rate, length


class Handler(socketserver.StreamRequestHandler):
    def handle(self):
        self.connection.settimeout(10)
        self.connection.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
        server = self.server
        try:
            with wave.open(str(server.source), "rb") as source:
                self.wfile.write(f"JPCM 1 {server.rate} {server.length} {server.max_block}\n".encode())
                while True:
                    request = line(self.rfile)
                    if request == ["QUIT"]:
                        self.wfile.write(b"BYE\n")
                        return
                    if len(request) != 2 or request[0] != "GET" or not request[1].isascii() or not request[1].isdecimal():
                        self.wfile.write(b"ERR request\n")
                        return
                    count = int(request[1])
                    if not 1 <= count <= server.max_block:
                        self.wfile.write(b"ERR count\n")
                        return
                    data = source.readframes(count)
                    self.wfile.write(f"DATA {len(data)}\n".encode())
                    self.wfile.write(data)
        except (ProtocolError, ConnectionError, TimeoutError, OSError):
            return


class Server(socketserver.ThreadingTCPServer):
    allow_reuse_address = True
    daemon_threads = True

    def __init__(self, address, source, max_block=2048):
        if not 1 <= max_block <= 65536:
            raise ValueError("max-block must be 1..65536")
        self.source = Path(source)
        self.rate, self.length = describe(self.source)
        self.max_block = max_block
        super().__init__(address, Handler)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--file", type=Path, required=True)
    parser.add_argument("--bind", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=8768)
    parser.add_argument("--max-block", type=int, default=2048)
    parser.add_argument("--ready-file", type=Path)
    args = parser.parse_args()

    def interrupt(_signum, _frame):
        raise KeyboardInterrupt

    signal.signal(signal.SIGTERM, interrupt)
    with Server((args.bind, args.port), args.file, args.max_block) as server:
        status = {"status": "running", "pid": os.getpid(), "bind": server.server_address[0],
                  "port": server.server_address[1], "track": args.file.name,
                  "sample_rate": server.rate, "pcm_bytes": server.length,
                  "max_block": server.max_block,
                  "started_utc": datetime.now(timezone.utc).isoformat()}

        def record():
            if args.ready_file:
                args.ready_file.parent.mkdir(parents=True, exist_ok=True)
                temporary = args.ready_file.with_suffix(".tmp")
                temporary.write_text(json.dumps(status, indent=2) + "\n")
                temporary.replace(args.ready_file)

        record()
        print(json.dumps(status), flush=True)
        try:
            server.serve_forever()
        except KeyboardInterrupt:
            pass
        finally:
            status["status"] = "stopped"
            record()


if __name__ == "__main__":
    main()
