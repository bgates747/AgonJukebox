# Shared transport controls

All four current skins use the common Nineties button geometry, recolored for
their palettes. `button-nineties.png` preserves its 45×30 border pixels with a
cleared face. The six `*-mask.png` icons are 16 pixels high; shuffle and repeat
are reduced to match play, pause and seek. Place masks at
`((45 - width) // 2, 7)`; odd differences use the nearest whole pixel.

`transport.svg` retains the original vector derivation, before icon normalization.
Prepared per-skin PNGs are the current compilation inputs. Colors supply separate
outline, face, bevel, neutral ink and active ink; do not merge these roles.

Play and pause remain visible together with the active state highlighted.
Shuffle/repeat have on/off states. Volume has eleven segments for levels 0–11.
Seek uses `[` / `]`, Enter starts selection, `p` pauses/resumes, `s` shuffles,
`l` loops, and comma/period change volume. No mouse behavior is introduced.

Seventies extends its panel upward with the base fixed at y342. All four skins
omit the message/READY widget. Latest emulator and hardware qualification remain
deferred; layout review and earlier revision test evidence are separate.
