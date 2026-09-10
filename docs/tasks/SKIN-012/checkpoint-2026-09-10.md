# Art Deco processing checkpoint — 2026-09-10

The Author requested a commit of all pending work before a separate task is
planned for an alternative vector workflow. This checkpoint preserves the
current raster workflow, its iterations and review copies for comparison.
It records progress, not visual acceptance or production promotion.

## Where the current workflow got

1. `review-v6/` is the selected host proof. It is 512x384 with 27 Agon palette
   colors and no dithering. It reconstructs from canonical AGNB records,
   bitmap placements, fills, a mirrored ornament and a separate demonstration
   overlay. Runtime integration of this Art Deco skin has not happened.
2. Column shading was regularized using modal cross-sections and exact
   quantized piecewise-linear ramps. Selected plaques and button surrounds
   were rebuilt from geometric masks with directional bevel shading. Four
   buttons share a surround, and the two upper fans share mirrored geometry.
3. This was localized regularization, without general image-edge detection or
   contour tracing. Bevel distance fields came from predefined shapes.
   Light-pixel detection located the complete control symbols. Much of the
   ornamentation retained its original quantization irregularities.
4. The Author found improvement insufficient: dirt and ragged boundaries are
   still conspicuous. The visual result is unaccepted. Area reduction and
   exact reconstruction do not establish visual quality.
5. `element-review/` provides 30 named editable pieces and all 96 reusable
   tiles, with native-size indexed Agon PNGs, a zoomable gallery, screen
   coordinates, sharing/derivation metadata and initial hashes. Exporting
   these introduced no additional smoothing. No edits to the 126 element
   PNGs were found at checkpoint inspection; future hand edits must be kept.

## Evidence and costs

1. Unique uploaded RGBA2222 pixel data is 120,373 bytes, 38.78% below a complete
   196,608-byte raster and 11.80% below the equivalent unrefined extraction.
   The container has 95 uploaded records, 96 resident bitmap assets after the
   mirrored variant, and 125,024 total file bytes.
2. The modeled static drawing sequence is 2,063 bytes. Upload traffic, resident
   memory and draw traffic are separately itemized in [README.md](README.md).
   These are host measurements and protocol estimates, not VDP timing results.
3. The saved verifier checks independent AGNB reconstruction, source hashes,
   exact dimensions/palette, preserved symbols, idempotence, and rejection of
   corrupted pixels and invalid placements. The earlier frozen-script rebuild
   reproduced all 206 generated artifacts byte for byte; its report is retained.
4. All 126 review PNGs were checked against their input pixels on export; the
   96 exported tiles reconstruct the static reference exactly. Native crops
   cover the full screen. The original supplied PNG remains unchanged.

## Scope of the snapshot

1. Retain the scripts, parameters, controls, iterations, selected AGNB proof,
   comparison reports and editable review packet under `SKIN-012/`. Python
   bytecode caches are excluded. This requested checkpoint is a scoped
   exception to the normal task-directory ignore policy; general agent notes
   and the local emulator remain private.
2. Include the pending 5x6 heading-font editor asset, its metadata/provenance,
   and the original PB2000 skin archive and task registration. PB2000 adoption
   remains uninvestigated; the exported font is not a runtime font replacement.
3. Preserve the existing application, asset-loading contract and deployed
   emulator profile. There is no push or new application qualification here.

The next proposed experiment will start from higher-resolution shapes, derive
clean regions/contours and rasterize vectors with explicit final-pixel outline
widths. Its specification will be reviewed separately before implementation;
it will coexist with this workflow and use it as the comparison baseline.
