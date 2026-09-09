# Art Deco source snapshot for SKIN-012

The Author approved [SKIN-012](../../SKIN-012.md) on 2026-09-09 and requested
that its specification, relevant artwork, and referring documents be frozen
in a commit before implementation. This directory and the two referring task
records are a scoped tracking exception; other private working material keeps
its existing ignore policy. This snapshot is source/evidence, not an installed
or qualified application skin.

1. `art-deco-scaled-palettized.png` is the immutable authoring baseline supplied
   by the Author: 512x384, 27 RGB222 colors, deliberately undithered. SHA256:
   `178e443dfcc3a47a4ebfbf3df6385a57b75b8c54533d9595d96101756197ef55`.
2. `art-deco-smooth-master.png` is the high-resolution smooth image generated
   before SKIN-012. `smooth-master-prompt.md` and `art-deco-smooth-master.json`
   record its prompt and provenance. Use it to interpret intended shading.
3. `art-deco-original.png`, `art-deco-correction.png`, `prompts.md`, and
   `validation.json` retain the earlier deliberately pixelated generation
   experiments and their failed size/palette checks. They are historical
   comparisons, not inputs for SKIN-012 reconstruction.
4. `preview-*.png`, `resampling-comparison.png`, `art-deco-512x384-agon64.png`,
   `convert.py`, and `conversion.json` preserve the earlier authorized local
   conversion experiment. The later Author-supplied baseline supersedes it.

SKIN-012 permits only deterministic local processing of the existing artwork;
historical image-generation prompts do not authorize further generation.
Future scripts, parameters, outputs, and iteration notes belong to the private
`docs/tasks/SKIN-012/` workspace until separately promoted.
