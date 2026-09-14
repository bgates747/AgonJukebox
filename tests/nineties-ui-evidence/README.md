# Nineties UI review update

Checkpoint before edits: 885e38b. Author accepted these requested updates and authorized commit/push.
26 functional scenarios, 7,552 widget pixels and 6,922 font pixels pass on the
patched 1.2.5-beta1 runtime. 49 descriptor cases, two partial asset cleanup cases,
chooser behavior and four skin cycles pass, including absence of the message
record and rejection of a nonzero absent record or an absent required path.
Seven host schema tests pass; 24 compiler outputs reproduce byte-for-byte.
Host assertions verify the two transport states change only the active symbol,
with both symbols retained, and mock-deck keys/LED pixels match exactly.

Initial functional run nu01 failed the existing timing assertion at step 17
while host repeat-build work overlapped. Isolated nu02 passed with no timing or
assertion changes. Contract nc01 exposed a mutable fixture reused after adding
its valid case; copying the bytes corrected the fixture and nc02 passed.
Initial malformed-height test was made relative to the moved path field.
The Seventies schema test setup now includes its current concept source.
No claim of automated visual acceptance or monitored human playback is made.
