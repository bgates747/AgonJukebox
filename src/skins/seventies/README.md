# 70s prototype skin

Separate compile-time profile based on the preserved SKIN-018 flat-color artwork.
Art Deco remains the default. Ten 6×12 Terminus playlist rows include durations
cached during existing WAV validation; the small status font is Neutrino 5×8.
Sprite 0 follows browser selection. No gradients or hardware-sprite enablement.

Build from the project root using `.venv/bin/python src/skins/seventies/build.py`.
Uses `skin.json` and the [shared skin compiler](../../../docs/skin-authoring.md).
Requires the canonical sibling agon-utils AGNB helpers; the font editor API is
no longer a build-time dependency. Prepared-art provenance is preserved.
Use `--output-root /tmp/jukebox-70-repeat` for an isolated reproduction.
Existing font sources and source.png are immutable inputs.

Assemble from src/asm with ez80asm 2.2:

```sh
ez80asm app_seventies.asm ../../tgt/jukebox-seventies.bin
```

Deploy that binary as /bin/jukebox.bin, config/jukebox-seventies.cfg as
/bin/jukebox.cfg and skins/seventies under /jukebox/skins/seventies on the SD.
Use the canonical agon-dev-env emulator generator and generated local wrapper.
The profile uses the strict seventies-test1 package/layout contract; runtime
skin switching is not implemented. The existing Art Deco package is preserved.

`tests/functional.py --help` documents the shared harness; select --skin seventies.
The stock Fab/MOS suite passed 26 scenarios, 6,978 widget pixels and 6,922 font
pixels. Host rebuild matched all 19 generated files. The Author confirmed correct
execution and accepted the skin on physical hardware on 2026-09-13 while playing
Fleetwood Mac's Rumours. Emulator audio was choppy with both this skin and the
previous accepted Art Deco build; hardware review established prototype acceptance.

The reviewed hardware installation uses /mystuff/jukebox/jukebox.bin, with
skin_dir=/mystuff/jukebox/seventies and music_dir=/jukebox/tgt/music in
/bin/jukebox.cfg. Set those paths for the destination card; the supplied config
retains the isolated emulator layout. Existing music and old executables were
preserved. No firmware change was needed for this deployment.

Validation evidence is in tests/seventies-evidence/. General runtime skin
switching, gradients and hardware-sprite qualification remain future work.
