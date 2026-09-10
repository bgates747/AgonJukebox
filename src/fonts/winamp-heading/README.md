# Winamp Base heading — 5×6

Open `WinampBase_Heading_5x6.font` in the Agon Tkinter font editor. Its adjacent
`.font.xml` file supplies all editor settings, including true 5×6 cells,
zero offsets/scaling, monochrome threshold rendering and a 16-column grid.
`original_font_path` currently points to this project's local file so opening
the XML directly also works; update that field if the project moves.

The file contains 256 slots, six bytes per glyph, 1,536 bytes total. Bits 7–3
hold each five-pixel scanline; the three low padding bits are zero. ASCII A–Z
contain the exact heading glyphs imported from Base 2.91 `TEXT.BMP`. All other
slots, including lowercase and space, are blank. This is the existing heading
alphabet, not a newly completed text font. Artwork provenance is recorded in
`provenance.json` and the reference skin's README.

The font editor's reader, writer and actual Tk startup were exercised. The
font round-trips byte-for-byte and all 7,680 cell pixels match the source.
This editable asset does not replace the current runtime heading. It has true
five-pixel advance; use a six-pixel cell when a separating column is desired.
