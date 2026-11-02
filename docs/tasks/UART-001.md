# UART-001 — Explore runtime-selectable MOS UART0 transport

Explore whether the experimental MOS UART0 sender gives Jukebox useful CPU
headroom while preserving audio, input responsiveness and skin rendering.
Keep the experiment on its own branch. Let the user change transport mode
and independently enable/disable logging during playback, and collect metrics
that distinguish scheduler changes from UART batching gains. The accepted
player remains the rollback/control; this task does not approve a replacement.

- Requested: 2026-11-01
- Started: 2026-11-01
- Finished: --
- Status: CTS1 provisionally passes Author hardware playback/input review; full runtime switching/logging remains incomplete; UART-002 batch16 test next
- Implementation branch: `codex/uart0-runtime-ab` in `.emulator/uart001-worktree`
- Task evidence: `docs/tasks/UART-001/` (private, when needed)
- Authority: Author requested this task, a separate branch, metrics, live mode
  changes while a file plays, and independent runtime logging controls.

## Authorized first tranche — 2026-11-01

The Author has selected a minimal async prototype first and authorized a
checkpoint/push of existing dirt followed by autonomous implementation through
available automated checks. Start with one async session and the default
per-byte CTS policy, startup capability detection/synchronous fallback, safe
borrowed-packet lifetime, foreground feeding and cleanup. Preserve the accepted
binary and isolate the branch. Include lightweight in-memory counters and a
post-playback report sufficient to diagnose the prototype. Live transport
switching, batch16 selection, runtime logging controls and full performance
A/B remain subsequent tranches; they do not block this prototype. No physical
flashing or hardware execution is implied. Continue until a concrete fixture
needs the Author's hardware/audio review.

## Source and baseline

1. Start implementation from the latest accepted skin-enabled application,
   inspecting current source and Git state first. Record exact source revision,
   binary, config and asset hashes, and pin a rollback before edits. Do not
   accidentally use this chat's older root checkout as the current baseline or
   inherit the separate startup-reset logger as an unrecorded timing change.
   The latest runtime source examined for this plan is `f3cd592`; the plan-only
   AMP-001 checkout is `b2ec77d`. Recheck before implementation.
2. Create `codex/uart0-runtime-ab` in an isolated checkout when implementation
   starts. Preserve other branches, pending artwork and startup diagnostics.
   No production merge or deployment follows merely from creating this task.
3. Read the MOS-owned handoff and authoritative contracts; do not copy their
   evolving ABI into a competing project specification:
   `/Agon/mystuff/agon-mos/docs/handoffs/jukebox-uart0-candidate-2026-11-01.txt`,
   `docs/uart0-async.md` (Candidate API), `docs/uart0-cts-batching-api.md`,
   `docs/uart0-jukebox-skins-audit.md`, and
   `experiments/uart0-startup-safe/README.md` in that repository. The dated
   handoff supersedes stale qualification prose, not the register ABI.
4. Supplied startup-safe candidate pair, to verify against its provenance before
   any test: MOS `build/uart0-startup-safe/run004/MOS.bin`, SHA256
   `89ea8694194e0488337bf1dcbfa91e2b084b3afc75a9c3916f4acc9ae12aa42b`;
   VDP `build/uart0-startup-safe/provenance/frozen-runtime/esp32-firmware.bin`,
   SHA256 `201ad8ab4af807c261cb92634286b2fbaedcf3879f140e820b60ab54cf707e2a`.
   Both paths are relative to the MOS project. This is an experimental ZDS II
   MOS build and a specifically matched receiver. Do not infer receiver
   qualification from another VDP merely sharing the Bistromathics version.
5. Retain a stock-Arthur compatibility case with synchronous fallback.
   Discovery alone must not activate async. Firmware installation is a separate
   explicit Author action; no flashing or firmware edits are assigned here.

## Runtime behavior

1. Provide three selectable modes within the experimental executable:
   **SYNC** (ordinary synchronous MOS output, async session closed),
   **ASYNC-1** (foreground async API, per-byte CTS), and **ASYNC-16**
   (foreground async API, explicitly selected batch16 OTIRX). SYNC starts by
   default, and logging starts off. Treat the original accepted binary as a
   separate control; do not label the adapted SYNC scheduler as unchanged
   production behavior. Other supported batch sizes are optional follow-up.
2. Mode selection and logging controls must work while playing, paused and
   idle, without restarting the executable or reopening/restarting the song.
   Preserve playback position, sample accounting, volume, loop/shuffle state
   and skin state. Exercise repeated mode changes within one playing file.
   No intentional mute, pause or skipped/replayed samples to disguise handoff
   gaps. Record any observed glitch or control delay.
3. Give mode selection, logging toggle and metrics snapshot distinct controls.
   Audit existing keys before assigning them: preserve browsing, pause, seek,
   loop/shuffle, skin chooser and quit bindings. Show requested versus effective
   mode and pending/unavailable/error state, plus logging state. A request must
   not appear successful before the driver confirms the handoff. Keep the
   experimental feedback compact and avoid continuous telemetry redraws.
4. Reject unavailable/incompatible async choices visibly and retain the working
   effective mode. Never silently present synchronous fallback as ASYNC-16.
   Reset/app startup must not persist automatic async activation.

## Scheduling and ordered ownership

1. Re-audit current input, timer, WAV feed, EOF/track changes, seeking, skin
   switching and teardown. The inspected player blocks in `mos_getkey` with
   timer-driven audio/UI under DI. The MOS async API is foreground-only: it
   cannot simply replace a send inside that ISR. Making the ISR post work and
   servicing audio in foreground is an explicit experiment here, not a general
   input-loop improvement. Preserve the carefully tuned original as control.
2. Design the smallest foreground service/wakeup arrangement that avoids being
   stranded in blocking keyboard input while audio is due. Compare actual
   responsiveness with the accepted baseline. ISR work is bounded posting and
   timer acknowledgement; no SD reads, rendering or async API calls there.
   No long DI sections around SD reads, encoding or sends, and no enabling
   nested interrupts inside the old handler as a shortcut. Preserve register,
   interrupt-state and automatic track-transition contracts.
3. Inventory callbacks precisely. MOS keyboard-callback exclusion matters to
   async open; the skin's VDP MODE-reply suppression callback is a different
   mechanism and must not be removed or misclassified on name alone.
4. Use one ordered MOS-owned UART output path. Build complete immutable audio
   command+payload packets in bounded preallocated RAM slots. Never borrow the
   existing mutable upload header or overwrite shared WAV staging data while
   MOS owns it. Retain each published source until RELEASED, then reap its
   descriptor. Reserve/publish BUSY retains the packet and accounting for retry;
   it must not drop samples or advance the file stream as if sent.
5. Preserve command order across audio, graphics, buffer clear/play, EOF, seek,
   track and skin changes. Bound graphics occupancy so audio can meet its next
   handoff. Legacy synchronous output within an async session is an ordered
   compatibility barrier; audit/count such barriers instead of assuming all
   existing printing becomes asynchronous. No direct app UART register writes.
6. Track due-work multiplicity and bounded backlog. Distinguish late feed ticks
   from failure to ready a whole next VDP sample. Preserve quotient/remainder
   scheduling for non-divisible sample rates. Assess RAM limits using the
   actual packet pool, queue capacity and skin assets before choosing sizes.

## Switching transport while playing

1. Implement an explicit foreground transition state machine. Stop admitting
   new publications at a complete command boundary; retain queued packet/source
   ownership and due audio work. Continue input/service progression and use
   measured playout headroom to finish accepted traffic. Do not spin under DI
   or flush FIFOs/reset the parser to force a switch.
2. ASYNC-1 ↔ ASYNC-16 changes policy only when the queue is empty and TEMT is
   true; setter BUSY leaves the old effective policy intact. SYNC → async waits
   for prior synchronous output to drain, opens explicitly, then selects and
   verifies the requested policy. Async → SYNC resolves tickets, drains queue
   and TEMT, and closes before returning to the synchronous output path.
3. Retain pending work/old mode on a busy handoff, with an honest pending state
   and bounded retry policy. Define how another mode request, seek, EOF, skin
   change or quit interacts with a pending transition. Never free borrowed
   sources or abort an active partial packet on a timeout. Do not promise live
   recovery from corrupted firmware/protocol state.
4. Validate ABI magic/version/length/flags and supported-size bitmap before
   using extensions. Follow the ADL=1, MBASE=0 register ABI and 24-bit pointer
   layout; three descriptors, borrowed readable RAM and positive <=65535-byte
   lengths impose real bounds. RELEASED permits source reuse; queue-empty plus
   TEMT means wire drain. Neither proves VDP execution or audible completion.
5. Normal quit/error cleanup must resolve ownership, drain/close the session
   and restore the CLI's stock UART handler. Reject API misuse rather than
   relying on context guards to detect arbitrary timer-ISR calls.

## Metrics and logging

1. Maintain small fixed-size counters/histograms in RAM. Logging off means no
   per-event formatting or file writes; counters needed for comparison remain
   available. Snapshot/reset metrics are explicit operations and not side effects
   of a logging toggle. Record counter widths, overflow handling, timer source,
   calibration/resolution and instrumentation cost. Do not invent sub-tick
   latency precision or infer CPU utilization from wire-time arithmetic.
2. Capture, where actually observable: elapsed time; payload versus header/UI
   bytes submitted and accepted; completed/released packets; queue/packet-pool
   high-water and BUSY/retries; pending-feed high-water; feed lateness/deadline
   misses; packet lifetime/drain latency; complete-next-sample readiness; mode
   requests/effective changes and handoff duration; errors; input dispatch
   latency; bounded useful foreground work and UI work completed. Specify
   measurement endpoints for each. Label summaries/estimated histogram percentiles
   accordingly. Count transmitted bytes only if the available evidence supports
   that term; accepted bytes are not receiver acknowledgement.
3. Record exact firmware/app/asset/file identities, WAV format/rate, transport,
   scheduler, logging/metric settings, test duration and output workload with
   every measurement segment. A live mode change ends the old segment and
   starts a new one; report transition costs separately from steady state.
4. Toggle buffered logging independently in every mode while playing. Use a
   dedicated experimental file, provisionally `/JUART.LOG`, separate from
   `/JBSTART.LOG`. Log mode/control/error events and bounded summaries rather
   than one line per PCM feed. Never send telemetry through UART0 to a terminal.
   Flush/close from foreground with a defined headroom/budget policy. Disabling
   stops new log events and safely completes pending writes without affecting
   audio ownership. Define file failure, log-buffer overflow/dropped-log counters
   and visible logging-error state; audio must not depend on logging success.
5. Benchmark with logging off first. Measure logging-on overhead separately and
   keep identical instrumentation/workload across modes. An explicit snapshot
   may write a bounded report with continuous logging off; identify that cost.
   No extra synthetic work or animated UI in only one comparison mode.
6. Use MOS diagnostics only under their contract. `diag_take` requires a closed
   session; do not silently close/reopen during a live measurement merely to
   clear latches. Establish closed-session diagnostic epochs outside timed
   intervals. Sticky RX bits are neither event counts nor TX-loss proof; do not
   subtract bitmasks or invent unavailable firmware ISR/CTS counters. Request
   upstream instrumentation separately if a necessary measurement is absent.

## Work sequence and evidence gates

1. Pin baseline/create branch, inventory source/resources and write a concise
   design for scheduler wakeup, packet lifetime, transition and measurement
   boundaries before restructuring playback. Keep upstream MOS/VDP unchanged.
2. Establish baseline metrics on the original accepted player. Build adapted
   foreground SYNC first; verify audio/input/UI/EOF/seek/skin/quit behavior before
   enabling async. Keep scheduler cost separate from transport benefit.
3. Add ASYNC-1, then ASYNC-16 with the same scheduler, packet pool, WAV data and
   UI workload. Add live transitions and independent logging controls. Do not
   substitute a bulk UART benchmark for real Jukebox playback.
4. Qualify stock-Arthur fallback and exact-pair experimental behavior headlessly
   on Pi5 only (current Author policy; no reservation). Include playing/paused/
   idle transitions in both directions; BUSY, queue pressure, non-divisible
   rates, EOF/loop/shuffle, seek/track/skin changes, logging on/off/failure,
   normal quit and relaunch. Observe packet ownership/order and captured audio.
   Emulator functional results cannot establish hardware timing benefit.
5. Prepare a reviewable hardware fixture with exact hashes/rollback/instructions.
   Author controls firmware installation and physical execution. Keep current
   Jukebox logger, agonAMP fixture, autoexec and unrelated files intact. Confirm
   the actual matched receiver before ASYNC-16 tests. Record human listening,
   real input responsiveness and repeatable alternating comparison segments on
   the same file at the same rate/load; multiple repeats expose variability.
6. Compare original scheduling against adapted SYNC separately; compare adapted
   SYNC/ASYNC-1/ASYNC-16 for transport effects. Report useful-work recovery,
   latency, backlog, audio continuity and overhead, including regressions. Do
   not claim audible underruns or wire integrity from backlog counters alone;
   distinguish measured glitches/receiver evidence from inferred risk.
7. Report whether the complexity earns a useful benefit, remaining limits and
   recommended default. Keep production adoption a separate explicit decision.
   Candidate/emulator changes stay uncommitted/unpushed until human validation
   and explicit commit approval under the standing project rules.

## Acceptance

1. An isolated, reproducible experimental branch plus exact accepted rollback.
2. Runtime effective mode selection including switching during one uninterrupted
   playing file, with honest pending/failure behavior and synchronous fallback.
3. Independent runtime logging toggle and retrievable, documented metrics.
4. No borrowed-buffer corruption, lost/duplicated audio accounting, mixed VDP
   packets, broken controls or CLI cleanup across tested transitions.
5. Comparable per-mode results that separate scheduler, transport and logging
   costs, with physical audio/latency review and an honest benefit assessment.

AMP-001 tracker-player work and SKIN-018 startup-reset diagnosis remain separate.
The original registration was planning-only. The Author subsequently authorized
the first prototype tranche and checkpoint/push. Current results and hardware
handoff are recorded in `docs/tasks/UART-001/README.md` and `qualification.json`.
Prototype deployed to /test/jukebox/; Author reports sustained playback, fewer navigation skips and snappy commands. No agent flashing or production promotion occurred. Actual hardware firmware/mode confirmation and /JUART.DAT remain pending. UART-002 owns the next explicit batch16 test.
