# Base reference skin

Install this directory's contents under `/jukebox/skins/base`, matching the
example `/bin/jukebox.cfg`. The required files are `skin.cfg`, `graphics.agnb`,
`fonts/body8x8.font` and `fonts/body8x14.font`.

This is the reference package accepted in the 2026-09-08 functional test.
`skin004-proof1` remains the provisional manifest version; it is retained
unchanged to reproduce the accepted binary. The loader currently requires this
package's exact 67 image records, dimensions and resource IDs. Arbitrary Winamp
archives cannot be loaded directly.

The graphics are derived from the Winamp Base 2.91 skin supplied by the project
owner, available at
[Webamp's skin archive](https://skins.webamp.org/skin/5e4f10275dcb1fb211d4a8b4f1bda236/base-2.91.wsz/).
Source archive SHA256:
`0166fb878cd41de07e1cc51067525ccd3f055b94dc3c227d61124fe528788f6f`.
The imported artwork retains its original provenance; the application's
public-domain license does not relicense that artwork.

The package adds the existing Jukebox logo, time colon and frame/restoration
pieces, and corrects the right-border contrast. Its screen blue matches the
logo's hand-adjusted background. The complete existing Jukebox 8x8 font is
retained; the 8x14 font pads each glyph with three blank rows above and below.
The EQ artwork and controls are omitted.
