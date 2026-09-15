> Historical evidence for intermediate PCB revisions. These results do not
> qualify the latest shared-control, font or status-layout packages. Emulator
> and hardware testing of those packages remains deferred.

# PCB footer typography update

Only RATE, file count and volume change to normal 6x12 glyphs. The directory/
now-playing layout and accepted transport feedback are untouched; graphics AGNB
is byte-identical. Native checks pass: 26 scenarios, 14,066 pixels, 56 descriptor
cases and existing cleanup/chooser/four-skin cycles. Eight host tests and 24
repeat-build outputs pass. Mixed-font checks reject row/unused override bits,
undersized rectangles, mismatched glyph colors and a too-short RATE field.

Runtime header bytes 23..25 encode per-status large-font overrides; byte 22
retains the original default. RATE may display 13..23 cells, retaining 23 cells
of producer storage in compile-time packets. Runtime slots already reserve 96
bytes. PCB compile-time variant assembles. Human review pending.
