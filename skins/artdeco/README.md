# Art Deco test skin

Basic 512×384 Art Deco candidate using antialiased ArtDeco Concept 02 6×12 for the playlist
and Neutrino 5×8 for small fields. Install this directory at `/jukebox/skins/artdeco` and use the ordinary
`app.asm` build with `config/jukebox.cfg`. The `artdeco-test3` manifest belongs
to this bounded build profile; the Base build has its own manifest version.

Artwork loads through `graphics.agnb`, a canonical AGNB 0.1 container
with 163 RGBA2222 records. `fonts/ArtDeco_Concept_02_6x12.agnb` holds 190 color
glyph bitmaps for ASCII 32–126 in normal and highlighted states (22,824 bytes).
Both variants preserve the Author's quantized antialiasing. The loose fonts are
`fonts/neutrino_5x8.font` (2,048 bytes) and
`fonts/ArtDeco_Concept_02_6x12.font` (3,072 bytes); the latter supplies cursor metrics
for the mapped bitmap characters.
No image or font payload is embedded in the binary.

The browser retains ten numbered rows with 58 character cells per row. Directory
and page information sit above the list; playback identity, times and progress
sit below. The bottom icons show playback, shuffle, loop and volume state.
Sample rate and numeric volume occupy the footer. Control legends are omitted
for this test, with the keyboard controls retained. F1 help is not implemented.

Source artwork, generator, layout metadata and preview are kept in
[src/skins/artdeco](../../src/skins/artdeco/README.md). The accepted flat-color
artwork is preserved there as PNG and SVG; generated artwork clears concept
sample text and composes live fields. Font source/export provenance lives in
[src/fonts](../../src/fonts/README.md).

Automated emulator functional and pixel checks pass. The project owner
accepted this as a good working concept on 2026-09-10 and authorized its
checkpoint commit. The Lat7 version also passed the owner's hardware review.
The owner also reviewed Concept 02 on hardware with a CRT and authorized its
checkpoint. Extended resource qualification remains open. This is a test skin, not a
frozen general package format.
