# Bounded network PCM experiment

The first host-side test serves one prepared 8 kHz Africa WAV from the Pi to a
small Python client on Oryx. The server sends audio only when requested. The
client fetches ahead in a background worker while a timed foreground consumes
buffered audio through the installed ffplay. This is a listening and connection
test, not a measurement of the ESP8266, eZ80 or VDP.

## Run

Python 3 and its standard library are sufficient for serving and probing.
Playback also needs ffplay. Run from the project root:

```bash
python3 tools/pcm-stream/server.py --file /path/to/Africa_8000.wav --bind 0.0.0.0
python3 tools/pcm-stream/client.py --host PI_HOSTNAME
```

The default TCP port is 8768. Ctrl-C stops the client. A fresh connection starts
at the beginning. To check connectivity without playing sound:

```bash
python3 tools/pcm-stream/client.py --host PI_HOSTNAME --probe 2
```

The service exposes only the single configured WAV. It provides no directory
browser, file upload, authentication or internet-facing deployment. Start it on
the trusted test LAN. Remote browsing and on-the-fly codec conversion are later
work; no existing Jukebox executable or firmware is changed by these tools.

Prepare the first source with the existing converter. Suppress another loudness
normalization pass when resampling an already-converted WAV:

```bash
python3 scripts/make_wav.py /path/to/Africa_65535.wav --sample-rate 8000 --no-normalize -o /path/to/Africa_8000.wav
```

## JPCM version 1

A connection opens with a bounded ASCII metadata line:

```text
JPCM 1 SAMPLE_RATE PCM_LENGTH MAX_BLOCK\n
```

Format is always unsigned 8-bit mono PCM. Length counts PCM bytes, excluding the
WAV container. The client sends `GET N\n`, with 1 <= N <= MAX_BLOCK. The server
responds `DATA M\n` followed by exactly M opaque PCM bytes, where M is N or the
remaining track length. At EOF, M is zero. The next request continues the track.
`QUIT\n` returns `BYE\n` and closes. A malformed or oversized request returns an
error line and closes. There are no payload checksums or acknowledgements.
A TCP read is not a message boundary; headers and bodies may arrive in pieces.

The default maximum body is 2048 bytes. The desktop client defaults to a 500 ms
start reserve and 20 ms foreground intervals. Each tick collects completed
background work, requests future data when needed, and feeds existing PCM to
ffplay. Fractional interval byte counts follow the audio timeline. A late block
can cause silence insertion, counted as an underrun; it does not reset the tick
clock. This desktop policy does not settle the eventual Console8 underrun policy.

Printed queue/underrun counters describe this Python pipeline. ffplay and the
host audio system add buffering; these are not calibrated speaker timestamps,
hardware underrun counters or evidence that UART0/UART1 overlap is safe.

## Host checks

```bash
python3 -m unittest discover -s tools/pcm-stream -p 'test_stream.py' -v
```

These finite checks cover arbitrary binary samples, bounded requests, EOF,
partial/truncated reads, independent connections, a silent connection probe and
the timed client using a capture process instead of a speaker. No emulator runs.

## Accepted first test

On 2026-11-07, the six host checks passed, Oryx fetched two seconds of PCM from
the Pi, and a two-second run through the installed ffplay using dummy output
completed with no inserted silence or client underrun ticks. The operator then
accepted audible 8 kHz Africa playback on Oryx.

This checkpoint establishes the host source and client. ESP8266/UART1 reception,
Console8 playback, remote file browsing and higher sample rates remain future
work. No payload checksum is computed during normal playback.
