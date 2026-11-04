# Eirene RC2 player: hardware debrief, 2026-11-04

The same RC2 application runs on Console8 with Eirene and on the Olimex with
Eirene-based EMOS in native Legacy mode. Console8 listening was positive. On
Olimex, Smith judges standard and asynchronous playback about even overall,
with variable audible skips; he still judges the asynchronous controls more
responsive. These are qualitative observations, not measured throughput or
latency results. This is a successful compatibility checkpoint with incomplete
performance qualification, not a release or a claim that sample timing is fixed.

## Recorded observations

1. **Console8:** Smith reported playback “running like a champ,” slightly
   snappier controls and fewer skips when changing directories with the RC2
   asynchronous app. The existing one-second sample-boundary behavior remains.
2. **Olimex:** both builds run. Initial impressions favored async playback,
   but repeated listening varied. Smith's final assessment is **about even**
   for playback, retaining his judgement that async controls feel more responsive.
   Earlier better/worse impressions must not be treated as a settled ranking.
3. **Listening reference:** Dire Straits, “Down to the Waterline,” opening track
   on side one of the debut album. Its clear steady beat makes skips easier to
   hear. This was a manual listening comparison, not a controlled recording or
   timestamped underrun measurement. The apparent early/late sample handoffs
   are an interpretation of the sound, not a diagnosed event sequence.
4. **Identity:** common RC2 executable is 65,563 bytes, SHA-256
   `f906ff83d1a79d7c8217975732f53f1af9a7909ef0a77ddae071404253434dd1`.
   Standard skins/analyzer comparison is 65,048 bytes, SHA-256
   `1469e437a5ba6c80a32de71cfa079906cdd43e8c03a2b214019348a6fa376ec3`.
   The application has no EMOS-specific target or ROM allowlist. API-compatible
   firmware is an installation prerequisite. No firmware was changed for the
   Olimex comparison; its native VDP is an identified derivative, not an asserted
   stock receiver. Target file readback was stopped at Smith's request after
   all uploads completed; no complete target-hash verification is claimed.

## Considerations and competing explanations

1. **Two UART workloads on Olimex.** Its mainboard keyboard port is broken, so
   keyboard input arrives through the Extender board. EMOS must service that
   UART as well as the VDP UART. This changes interrupt/input workload relative
   to Console8. It could affect audio scheduling and perceived key latency;
   its cost has not been measured, and neither EMOS nor the input path is
   established as the cause of the skips. Reported responsiveness is end-to-end,
   not an isolated measurement of the player or UART0 sender.
2. **Commands versus bulk streams.** A 16-byte OTIRX batch ceiling is a maximum,
   not a minimum payload size. A short VDU command need not fill a whole batch;
   setup, interrupt and finish costs may outweigh savings for small writes.
   Continuous bulk PCM and short commands therefore need separate cost models.
   In this candidate **only PCM buffered-write packets** use submit/finish;
   each has an eight-byte header plus payload, in a 2,048-byte staging area.
   Ordinary VDU/UI commands remain synchronous. Short-command async setup is
   consequently a general transport design consideration, not an explanation
   already demonstrated in this build. Packet copying, per-packet setup,
   callbacks, finish barriers, CTS waiting and competing interrupts can still
   influence its useful foreground work. No optimal crossover size is known.
3. **Missing historical Olimex baseline.** Console8 was Smith's only Agon when
   Jukebox was written and has been his regular player. Olimex might always
   have performed worse with stock MOS/VDP; that baseline was never established.
   The present standard-app comparison still runs on EMOS and the retained
   receiver. It does not isolate hardware, storage, firmware or Extender effects,
   and does not establish a regression introduced by asynchronous transmission.
4. **One-second scheduling remains.** Both builds retain the sample/chunk
   scheduling design. Async transport changes foreground availability, not the
   requirement to cue successive samples on time. Variable skips do not prove
   one specific lateness mechanism, early triggering, UART corruption or a
   receiver defect. Source released, transmitter empty and receiver execution
   are different milestones; successful API completion alone is not proof of
   continuous audible playback.

## Evidence limits and remaining work

1. Earlier gated-model tests establish ordered PCM/controls for that earlier
   artifact, not physical timing of this common binary. The common source
   rebuild and unchanged standard executable were checked before deployment.
   Physical listening supports compatibility, not a CPU percentage, calibrated
   latency improvement, pop-free output or full all-skin playback acceptance.
2. No post-run diagnostic reports were collected for this listening comparison.
   Fixed-size JRC2/JSPEC reports on normal exit can help characterize API errors,
   completions and due backlog, but do not directly timestamp every audible
   handoff or prove a skip's cause. Further measurements need a separately
   planned scope; this debrief authorizes no additional runs or firmware changes.
3. A useful future comparison would hold WAV bytes, sample rate, skin/analyzer,
   navigation pattern and receiver constant, distinguish idle from exercised
   Extender input, and separately measure bulk-transfer and short-command costs.
   A true historical stock-MOS Olimex comparison would require a planned input
   solution and explicit firmware/restoration scope; do not flash merely to
   simplify the comparison. Any handoff-timing instrumentation needs bounded
   overhead and must distinguish upload, play-command and actual playback time.
4. Smith is handling physical bench release. No agent release, cleanup, reset,
   restoration or further target access is implied by this checkpoint. The
   temporary configuration and host backup are recorded in the private handoff
   for the bench custodian. Publication and merging into standard skins remain
   separate decisions.

## Credits

Eirene/MOS UART0 API: Tom Morton and upstream contributors. Visualization
techniques: **Nick J. Date (Pollito / SanPollo), agonAMP**; the independent PCM
analyzer retains the existing notices and upstream license in the source tree.
