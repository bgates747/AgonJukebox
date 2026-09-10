# Art Deco elements for review and GIMP editing

Start with [the visual gallery](index.html) or open **components/** in GIMP.
These are copies of the current `review-v6` proof, exported after the Author
reported remaining dirt/ragged edges. No further cleanup was applied.

1. **components/** — 30 named pieces: both columns in sections,
   crown/title, stepped borders, browser frame, now-playing surround, transport
   row, footer panels, and individual button surrounds and symbols.
2. **tiles/** — all 96 exact reusable bitmap assets, with descriptive
   filenames and their original part IDs. Repeated strips and fallback patches
   are here, as well as the frames, icons and ornaments.
3. **reference.png** shows the complete composition; **static-reference.png**
   shows the art without sample filenames, timings and other changing content.
4. **index.json** records native dimensions, original pixel/file hashes,
   screen coordinates, sharing, repeat placements and mirrored derivations.

All editable PNGs are native-size, opaque indexed images with the complete
64-color Agon palette embedded. Pixel colors are unchanged: exact palette
lookup only, no resampling or dithering. **Agon64.gpl** is also included for
GIMP's palette dock. The gallery enlarges only the display, using nearest pixels.

You can edit an individual PNG and export back to the same filename, or save
an XCF beside it and export a PNG when ready. Keep its dimensions for direct
reassembly. Filenames make convenient references for feedback.

The larger pieces are convenient review/edit regions; some overlap. Separate
control PNGs duplicate the corresponding tile for convenience. Their mapping
is recorded so changes can be reconciled in a later refinement pass. Editing
a shared tile can affect several placements; the gallery lists those uses.
The right top fan is currently derived by mirroring the left one, with both
orientations supplied for inspection. No edits are automatically imported.

The original source, v6 proof and AGNB container are preserved. This exporter
refuses to write into an existing destination, protecting subsequent hand edits.
To create another fresh packet from the project root:

```bash
.venv/bin/python docs/tasks/SKIN-012/export_elements.py --output /path/to/new-folder
```

Export checks: all 126 editable PNGs match their input pixels;
the 96 tiles reconstruct `static-reference.png` exactly. Larger
review crops collectively cover the entire canvas.
