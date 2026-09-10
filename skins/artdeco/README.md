# Art Deco test skin

Basic 512×384 Art Deco candidate using the Author's selected Neutrino 5×8
font. Install this directory at `/jukebox/skins/artdeco` and use the ordinary
`app.asm` build with `config/jukebox.cfg`. The `artdeco-test1` manifest belongs
to this bounded build profile; the Base build has its own manifest version.

Graphics load only through `graphics.agnb`, a canonical AGNB 0.1 container
with 163 RGBA2222 records. The font is the unchanged 2,048-byte loose
`fonts/neutrino_5x8.font`. No image or font payload is embedded in the binary.

The browser retains ten numbered rows and 60 character cells per row. Directory
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
checkpoint commit. Hardware qualification remains pending. This is a test skin, not a
frozen general package format.
