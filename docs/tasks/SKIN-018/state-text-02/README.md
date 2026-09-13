# Candidate 1: application-state text excised

Current browser worksheet: index.html. Original input remains in review-01.
Manually inspected at full source resolution. Removed ten row numbers,
ten filenames, ten durations, playing filename, elapsed/total time, current
path and file count. Selected-row text restored to white; other text to black.
34 explicit half-open rectangles; 49,107 changed pixels. No pixels outside
those regions changed. All output remains binary at 1448×1086.
Static headings, folder icon, rules, selection marker/bar, progress/volume
and decorative artwork retained. No palette proposal or runtime integration.

state-text-01 is the historical first pass: two underscore remnants were
found visually and corrected in state-text-02. Current source is
../clear_state_text.py. Reproduce from project root with:

.venv/bin/python docs/tasks/SKIN-018/clear_state_text.py --out NEW_DIRECTORY

All 15 generated files repeat byte-for-byte; saved pixels and protected static
regions pass checks. See report.json and verification.json. Human review pending.
