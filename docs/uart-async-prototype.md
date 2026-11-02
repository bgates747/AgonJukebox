# Foreground UART0 playback prototype

This experimental executable moves WAV feeding into the foreground and uses
the opt-in MOS UART0 API to submit complete audio packets. It is a first
functional prototype, not a production transport change or a performance win.
It preserves a stock-MOS synchronous fallback. Live transport switching,
runtime logging controls remain later work. UART-002 adds a separate explicit
batch16 test build; physical batch16 acceptance remains pending.

## Build and run

1. Assemble `app_async.asm` from `src/asm` with agon-ez80asm:

   ```text
   ez80asm app_async.asm ../../tgt/jukebox-async.bin
   ez80asm app_async16.asm ../../tgt/jukebox-async16.bin
   ```

2. Keep this binary separate from the normal player. It uses the existing
   `/bin/jukebox.cfg` schema and external runtime-v1 skin packages. On MOS:

   ```text
   load /test/jukebox/jukebox-async.bin
   run
   ```

3. Ordinary player keys remain: Enter selects a song, P toggles playback,
   brackets seek, comma/period adjust volume, L/S toggle loop/shuffle, K opens
   the skin chooser and Q/Esc exits. Transport is selected at session startup,
   not changed by a new hotkey. Exiting prints the effective transport and a
   prototype status code; `00` means no prototype API error was recorded.
4. The prototype writes `/JUART.DAT` after stopping audio and closing the async
   session. Retrieve it for diagnosis. Each skin session exit overwrites the
   file with cumulative application counters; keep a copy before another run.
   No continuous logger is implemented. A failed snapshot write prints a warning
   and does not make playback depend on writable logging storage.

## Firmware and isolation

1. The normal application entry points keep their original scheduler. A zero
   `uart_proto` build selector removes the prototype hooks; the runtime control
   rebuild matches the published 62,799-byte `tgt/jukebox-runtime.bin` exactly.
   A separate experimental branch contains this work. No production adoption
   follows from a successful test.
2. Stock MOS Arthur has no matching API and uses the adapted foreground
   synchronous fallback. That is not the original blocking-keyboard/ISR
   scheduler; the original executable remains a separate control.
3. The supplied experimental MOS/VDP pair and qualification scope are owned by
   the MOS project. The selected MOS image SHA256 is
   `89ea8694194e0488337bf1dcbfa91e2b084b3afc75a9c3916f4acc9ae12aa42b`;
   selected ESP32 VDP image SHA256 is
   `201ad8ab4af807c261cb92634286b2fbaedcf3879f140e820b60ab54cf707e2a`.
   A different receiver is not qualified by sharing the Bistromathics name.
   This prototype does not flash firmware, change startup files or enable the
   sender merely through capability discovery.

## Implementation boundary

1. PRT1 remains a 60-Hz producer, but its ISR only acknowledges the timer,
   posts bounded due work and updates counters. File reads, rendering and MOS
   async calls execute in interruptible foreground code. The original PRT1
   vector is saved/restored using the MOS vector API and the timer is stopped
   on exit. There is no second UART hardware owner.
2. A foreground poll loop handles one due audio tick, UI work and keyboard
   state. It polls during the prototype rather than implementing a new sleeping
   scheduler. Earlier sleep-based trials could stall; no CPU-idle or useful-work
   headroom claim is made by this busy-loop prototype. Short DI spans protect
   counter/key snapshots. Long SD reads and UART sends do not intentionally run
   under the original timer ISR's global interrupt mask.
3. Startup validates `UTX1`, major1/minor>=2, length>=54, batching capability
   and support for size1. Operation addresses are 24-bit register-ABI pointers.
   Open is explicit, with bounded startup BUSY retries; a successful open's
   batch policy is queried and must match the build. `app_async.asm` remains
   CTS1 and rebuilds byte-for-byte to the accepted baseline. `app_async16.asm`
   also requires size16 bitmap bit15; after open it polls drain, explicitly sets
   B=16 through offset46, checks success/effective16, and independently queries
   offset49 to verify16. BUSY retries are bounded by the existing raw-time
   startup budget. Unexpected policy errors/timeouts abort through drain/close;
   unavailable capabilities retain synchronous fallback. No packets are
   published before the policy is verified. Every skin reopen repeats selection.
4. One application-owned 2,048-byte packet slot at `0x092000` holds a complete
   eight-byte buffer-write header plus PCM. The WAV staging area at `0x09034c`
   is separate. Existing validated rates require at most1,093 PCM bytes per
   60-Hz tick. Zero/oversized uploads are rejected before copying. The slot lies
   within the API's application RAM range and outside the directory, file and
   code storage used by this build.
5. Publication borrows that stable slot. The next upload waits for RELEASED and
   reaps the descriptor before touching the slot. BUSY does not discard or
   advance an accepted packet. Graphics and other output retain MOS's ordered
   synchronous compatibility path, which can drain the queue and reduce overlap.
   They are not silently described as asynchronous. The VDP MODE-reply filter
   is retained; it is not a MOS keyboard callback.
6. Pause, seek, EOF/automatic track changes and skin switching keep the player's
   existing audio accounting. The chooser closes the old session and opens a
   fresh session only after new assets load. Consuming its selection key once
   prevents that key being replayed as a player command. Quit drains/reaps and
   closes before CLI return; the snapshot is written afterward. An unexpected
   ownership/teardown error does not free borrowed RAM or pretend safe recovery.

## Snapshot schema

Run the project Python interpreter with:

```text
.venv/bin/python scripts/uart_async_report.py /path/to/JUART.DAT --expect-async
```

| Offset | Width | Meaning |
| --- | --- | --- |
| 0 | 4 | `JUA1` |
| 4 | 1 | Schema version1 |
| 5 | 1 | Effective mode: 0 foreground sync fallback, 1 async CTS1, 2 async CTS16 after successful getter verification |
| 6 | 1 | Compatible API discovered |
| 7 | 1 | Last open status |
| 8 | 1 | Prototype error; 0 means none recorded |
| 9 | 1 | Maximum pending audio ticks |
| 10 | 3 | Elapsed MOS `sysvar_time` ticks modulo2^24; not independently calibrated |
| 13 | 4 each | Nine little-endian u32 counters, in order below |

The counters are timer IRQs, foreground audio ticks served, saturated due-posts,
API BUSY retries, source-release wait iterations, async packets published,
async sources released/reaped, async PCM payload bytes and async packet bytes
submitted including their eight-byte headers. The file is exactly49 bytes.
The nine counters wrap modulo2^32; these bounded qualification runs do not
approach wrap. Elapsed MOS time is retained raw because emulator clock behavior
differs; do not convert it to CPU utilization or unverified microseconds.

Only async publications contribute to the packet/byte counters; zero values in
fallback mode do not mean no audio was sent. They exclude compatibility/UI
traffic, wire acknowledgements and VDP execution. Pending-feed high-water is
not an audible-underrun counter. All sources should be released on a normal
final snapshot. Full metrics, on/off logging and fair performance A/B belong
to the subsequent UART-001 tranche.

## Qualification limits

1. Headless tests use a dedicated Pi5 Fab profile for stock fallback and Flexe
   for the exact experimental MOS plus actual compiled ESP32 firmware. Real
   PS/2 entry points drive input. Byte-stream checks compare complete uploaded
   PCM against the source, including EOF and fractional-rate tails.
2. Captured output and input/state checks are functional evidence. Host ESP32
   emulation and audio presentation clocks can differ; emulator timing/audio
   gaps cannot by themselves diagnose physical playback. Physical listening,
   input responsiveness and a useful CPU benefit remain unqualified.
3. Candidate profiles/binaries and this report remain provisional pending human
   hardware review. Preserve the production executable and original firmware
   when preparing a hardware comparison.

## Provisional hardware progress — 2026-11-01

The Author reports sustained playback, fewer skips during directory navigation
and snappy commands while playing. This is a provisional functional progress
pass, not a complete implementation or a measured CPU-headroom gain. Returned hardware snapshot confirms CTS1, error0 and all95902 published sources
released. Installed-pair identity attestation has not been collected yet.
The CTS1 build is preserved for comparison; explicit batch16 is the next test.

## Batch16 hardware test (UART-002)

1. Preserve the CTS1 executable and its report before running the separate
   `jukebox-async16.bin`. Keep the same skin, music, controls and scheduler for
   comparison. Run only on the exact MOS/VDP pair above; Author installs firmware
   and operates hardware manually. An application API cannot attest ROM/flash
   SHA256 identities, so pair confirmation must be recorded separately.
2. Normal exit must say `async CTS16 OTIRX; status 00`. Decode the resulting
   snapshot using `--expect-async --expect-batch 16`. Mode2 means the getter
   confirmed16 at session startup; a discovery or requested setting alone never
   earns that label. A fallback or nonzero status is not a successful batch16 run.
3. Observe sustained playback, arrows/directory navigation, pause/resume, seek,
   EOF progression, skin change and quit/relaunch. Collect the snapshot after
   normal quit. Audible results and input observations remain separate from
   calibrated performance metrics; no speedup follows from emulator wall time.
4. Application code never executes OTIRX itself: the matched MOS sender owns
   UART0, gates blocks on CTS and executes its bounded OTIRX path. The build
   selector changes startup policy only. Existing ordered synchronous graphics
   retain their compatibility behavior. Reusable-code extraction is a later
   promotion step after validating this small comparison.

Current SD fixture (2026-11-01): `/test/jukebox/jukebox-async.bin` now contains
the batch16 build from `app_async16.asm`. Author requested replacing this stable
filename, without a parallel CTS1 executable on card. Earlier CTS1 binary/source
and returned report are preserved on the PCs. This supersedes the separate
`jukebox-async16.bin` hardware filename in the initial bundle above.
