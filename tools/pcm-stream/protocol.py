#!/usr/bin/env python3
"""JPCM/1: bounded pull requests for unsigned 8-bit mono PCM."""
from dataclasses import dataclass
import socket

MAX_LINE = 96


class ProtocolError(RuntimeError):
    pass


def line(stream):
    data = stream.readline(MAX_LINE + 1)
    if not data or len(data) > MAX_LINE or not data.endswith(b"\n"):
        raise ProtocolError("Missing, truncated or oversized protocol line")
    try:
        return data.decode("ascii").rstrip("\r\n").split()
    except UnicodeError as exc:
        raise ProtocolError("Non-ASCII protocol line") from exc


def exact(stream, count):
    result = bytearray()
    while len(result) < count:
        part = stream.read(count - len(result))
        if not part:
            raise ProtocolError("Connection ended inside a PCM block")
        result.extend(part)
    return bytes(result)


@dataclass(frozen=True)
class Track:
    rate: int
    length: int
    max_block: int


class Connection:
    def __init__(self, host, port, timeout=5):
        self.socket = socket.create_connection((host, port), timeout)
        self.socket.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
        self.stream = self.socket.makefile("rb")
        self.position = 0
        try:
            header = line(self.stream)
            if len(header) != 5 or header[:2] != ["JPCM", "1"]:
                raise ProtocolError("Expected JPCM version 1")
            self.track = Track(*(int(x) for x in header[2:]))
            if not (1 <= self.track.rate <= 65535 and
                    0 < self.track.length <= 0xffffffff and
                    1 <= self.track.max_block <= 65536):
                raise ProtocolError("Unsupported track metadata")
        except BaseException:
            self.close()
            raise

    def get(self, count):
        if not 1 <= count <= self.track.max_block:
            raise ProtocolError("Request exceeds negotiated block limit")
        self.socket.sendall(f"GET {count}\n".encode("ascii"))
        header = line(self.stream)
        if len(header) != 2 or header[0] != "DATA":
            raise ProtocolError("Expected DATA response")
        try:
            size = int(header[1])
        except ValueError as exc:
            raise ProtocolError("Invalid DATA length") from exc
        if size != min(count, self.track.length - self.position):
            raise ProtocolError("Unexpected DATA length/early EOF")
        data = exact(self.stream, size)
        self.position += size
        return data

    def close(self):
        # Also wakes a pending background receive during Ctrl-C/failed playback.
        try:
            self.socket.shutdown(socket.SHUT_RDWR)
        except OSError:
            pass
        self.stream.close()
        self.socket.close()

    def __enter__(self):
        return self

    def __exit__(self, *_):
        self.close()
