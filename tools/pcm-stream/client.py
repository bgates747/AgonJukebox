#!/usr/bin/env python3
"""Listen to the bounded PCM source; Python stdlib plus installed ffplay."""
import argparse
from concurrent.futures import ThreadPoolExecutor
import json
import shutil
import subprocess
import sys
import time

from protocol import Connection, ProtocolError


def probe(connection, seconds):
    count = min(connection.track.length, max(1, int(connection.track.rate * seconds)))
    start = time.monotonic()
    while connection.position < count:
        connection.get(min(connection.track.max_block, count - connection.position))
    return {"mode": "probe", "sample_rate": connection.track.rate,
            "received_pcm_bytes": connection.position, "seconds_of_audio": connection.position / connection.track.rate,
            "transfer_seconds": round(time.monotonic() - start, 6), "audio_started": False}


def play(connection, args):
    player = shutil.which("ffplay")
    if not player:
        raise RuntimeError("ffplay is required for playback; --probe needs only Python")
    rate = connection.track.rate
    limit = connection.track.length if args.seconds is None else min(connection.track.length, int(rate * args.seconds))
    quantum = max(1, (rate * args.chunk_ms + 999) // 1000)
    if quantum > connection.track.max_block:
        raise ValueError("Reduce --chunk-ms to fit the server's block limit")
    prebuffer = min(limit, max(quantum, int(rate * args.prebuffer_ms / 1000)))
    buffer = bytearray()
    while len(buffer) < prebuffer:
        buffer.extend(connection.get(min(connection.track.max_block, prebuffer - len(buffer))))
    print(f"Playing {rate} Hz U8 mono; prebuffer {len(buffer)} bytes. Ctrl-C stops.", file=sys.stderr)
    process = subprocess.Popen([player, "-nodisp", "-autoexit", "-loglevel", "error",
                                "-f", "u8", "-sample_rate", str(rate), "-ch_layout", "mono", "-i", "pipe:0"],
                               stdin=subprocess.PIPE)
    pool = ThreadPoolExecutor(max_workers=1)
    pending = None
    played = silence = underruns = late_ticks = 0
    low_water = len(buffer)
    tick = 0
    start = time.monotonic()
    next_status = start + 1
    try:
        while played < limit:
            deadline = start + tick * args.chunk_ms / 1000
            delay = deadline - time.monotonic()
            if delay > 0:
                time.sleep(delay)
            elif -delay > args.chunk_ms / 1000:
                late_ticks += 1
            # Only collect completed network work at the scheduled boundary.
            if pending is not None and pending.done():
                buffer.extend(pending.result())
                pending = None
            # Replenish ahead of consumption; one network request is outstanding.
            if pending is None and connection.position < limit:
                wanted = max(quantum, prebuffer - len(buffer))
                count = min(connection.track.max_block, limit - connection.position, wanted)
                pending = pool.submit(connection.get, count)
            quota = ((tick + 1) * rate * args.chunk_ms // 1000) - (tick * rate * args.chunk_ms // 1000)
            quota = min(quota, limit - played)
            available = min(quota, len(buffer))
            data = bytes(buffer[:available])
            del buffer[:available]
            played += available
            missing = quota - available
            if missing:
                underruns += 1
                silence += missing
                data += b"\x80" * missing
            low_water = min(low_water, len(buffer))
            process.stdin.write(data)
            process.stdin.flush()
            tick += 1
            if time.monotonic() >= next_status:
                print(f"{played / rate:6.1f}s  queue={len(buffer):5d}  underruns={underruns}", file=sys.stderr)
                next_status += 1
        if pending is not None:
            pending.result()
        process.stdin.close()
        process.wait(timeout=10)
        if process.returncode:
            raise RuntimeError(f"ffplay exited with status {process.returncode}")
    finally:
        connection.close()
        pool.shutdown(wait=True, cancel_futures=True)
        if process.poll() is None:
            process.terminate()
            try:
                process.wait(timeout=3)
            except subprocess.TimeoutExpired:
                process.kill()
                process.wait()
        if process.stdin and not process.stdin.closed:
            process.stdin.close()
    return {"mode": "play", "sample_rate": rate, "source_pcm_bytes_played": played,
            "silence_bytes_inserted": silence, "underrun_ticks": underruns,
            "late_foreground_ticks": late_ticks, "queue_low_water_bytes": low_water,
            "audio_timeline_seconds": tick * args.chunk_ms / 1000}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", required=True)
    parser.add_argument("--port", type=int, default=8768)
    parser.add_argument("--probe", type=float, metavar="AUDIO_SECONDS", help="Fetch only; do not start audio")
    parser.add_argument("--seconds", type=float, help="Limit source duration for playback")
    parser.add_argument("--chunk-ms", type=int, default=20)
    parser.add_argument("--prebuffer-ms", type=int, default=500)
    parser.add_argument("--timeout", type=float, default=5)
    args = parser.parse_args()
    if (args.chunk_ms < 1 or args.prebuffer_ms < 0 or args.timeout <= 0 or
            (args.seconds is not None and args.seconds <= 0) or
            (args.probe is not None and args.probe <= 0)):
        parser.error("Durations must be positive (prebuffer may be zero)")
    try:
        with Connection(args.host, args.port, args.timeout) as connection:
            print(f"Connected: {connection.track.rate} Hz, {connection.track.length / connection.track.rate:.2f}s, "
                  f"maximum block {connection.track.max_block} bytes", file=sys.stderr)
            result = probe(connection, args.probe) if args.probe is not None else play(connection, args)
        print(json.dumps(result, indent=2))
        return 0
    except KeyboardInterrupt:
        print("Stopped.", file=sys.stderr)
        return 130
    except (OSError, ValueError, ProtocolError, RuntimeError) as exc:
        print(f"PCM client: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
