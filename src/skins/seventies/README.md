# Seventies skin

The current review candidate rebuilds the original retro concept as smooth,
coordinate-authored SVG geometry: records, flowers, rainbow bands and rounded
panels. `concept.png` preserves the original full-size artwork; `source.png`
preserves the earlier accepted flat-color source. `seventies.svg` contains
self-contained paths, including outlined static lettering. The target raster
uses eight exact Agon colors, with warm dark red retained for the panel interiors.

Playlist and status fields use the existing 6×12 Terminus glyphs. A 56-character
current-directory field replaces the static NOW PLAYING plaque and former
15-character footer field. Overlong paths retain the existing trailing ellipsis;
track identity, times and status remain independent. The existing selection
sprite path is unchanged. No gradients or hardware-sprite enablement are claimed.

Build from the project root:

```sh
.venv/bin/python src/skins/seventies/build.py
.venv/bin/python scripts/skin_schema/runtime.py --skin seventies
```

The [shared compiler](../../../docs/skin-authoring.md) consumes `skin.json` and
prepared assets. Use `--output-root /tmp/jukebox-70-repeat` for an isolated
compiler reproduction. Font files remain unchanged. The SVG authoring pass used
fontTools 4.59.1 to outline macOS Arial Rounded Bold; the finished SVG and normal
compiler do not require that installed font. Direct Cairo rasterization disables
antialiasing to retain the exact Agon palette.

Use the shared `tgt/jukebox-runtime.bin` and `skins/runtime/seventies` for the
[runtime skin chooser](../../../docs/runtime-skins.md). This candidate requires
the status-font extension (descriptor byte 22 = 1). The older compile-time
`app_seventies.asm` entry point remains available. Always deploy through the
canonical agon-dev-env emulator setup tool and launch its profile-local wrapper.

The original prototype was accepted on hardware on 2026-09-13; evidence remains
in `tests/seventies-evidence`. That acceptance does not extend to this redraw.
Current emulator checks and review status are in `tests/seventies-vector-evidence`.
