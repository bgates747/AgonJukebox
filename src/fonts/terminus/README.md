# Lat7 Terminus 6×12

Selected by the Author for the Art Deco playlist. The `.font` is an unchanged
copy of the existing font-editor export; the original PSF2 source is vendored
beside it. The 3,072 font bytes exactly match the PSF's 256-glyph payload.
Each glyph has twelve byte-padded scanlines, six visible MSB-first pixels per
line and two zero padding bits. Cell size and cursor advance are 6×12 and 6.

The adjacent `.font.xml` retains the editor's metadata with its source path
adjusted to this project's bitmap, so it can be reopened without the sibling
font collection. Update that absolute path if relocating the checkout.
`provenance.json` preserves the original metadata and source/export hashes.
The editor application was neither launched nor modified for this change.

The Art Deco playlist uses ten rows on a 12-pixel pitch, with 58 character cells
per row (348 pixels). Three cells contain the entry number and spacing, leaving
55 filename cells, or 49 after a directory's `<DIR> ` prefix. Other live fields
retain Neutrino 5×8. Graphics continue to load through AGNB; both fonts are loose
assets declared by the `artdeco-test2` manifest.
