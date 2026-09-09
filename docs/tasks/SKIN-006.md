# SKIN-006 — Design and build the rich reference skin

## State

- Status: Not started — proposal phase 4
- Started: --
- Finished: --

## Intent and scope

Create a visually rich first-party mode-20 package with backgrounds, panels,
custom font treatment, branding and icons. The example `velvet-hifi` name and
art direction are provisional. Preserve the fixed interaction model and
single-buffered rendering constraints.
Use the classic Winamp artwork import direction accepted in
[ADR-0002](../decisions/ADR-0002-classic-winamp-skin-import.md) as the starting
point, with additional artwork only where the jukebox needs it.

## Authority and dependencies

1. [Proposal](../agents/skinning_proposal.md): goals, layout, assets and rendering.
2. [SKIN-001](SKIN-001.md) D001/D007/D008/D009. Early layout studies can inform
   D001; first runtime work uses the bounded SKIN-004 milestone. Classic
   parity is deferred to SKIN-009 and is not a prerequisite.
3. Use [SKIN-005](SKIN-005.md) tooling and coordinate provisional resource budgets
   and measurements with [SKIN-007](SKIN-007.md).
4. [SKIN-000](SKIN-000.md) reviewed native-resolution preview, import subset
   and candidate permissions/provenance. A final skin choice remains D007.
5. [SKIN-012](SKIN-012.md) specifies agent-owned scripted extraction and
   refinement of the Author's Art Deco candidate, preserving axis-based and
   contour-following bevel gradients in RGB222. Its specification was accepted
   on 2026-09-09; final art/layout adoption remains open. Its proof
   feeds this task's asset construction and visual review.

The [Work 2 corpus](SKIN-000/corpus.md) distinguishes inspected historic
references from artwork available for release. Resolve W2-F005 with SKIN-008
for any selected third-party art; Vizor is currently an external geometry and
appearance reference only.

Use the [Work 3 mapping](SKIN-000/component-mapping.md) for semantic roles and
W3-G001–G007 for the original text/art needed alongside imports. Preserve visible
keyboard hints and filesystem identity, and demonstrate clean frame/backdrop
adaptation without Winamp EQ, playlist-editing or unsupported transport controls.
These are inputs to mockup review, not an accepted visual layout.

The [Work 4 plates and measurements](SKIN-000/geometry-colour-study.md) show
native font/digit spacing, thin browser framing, background-specific antialiasing
and loss of subtle metallic shading under RGB222 conversion. Use them in mockup
review; the selected font samples and 14px row pitch are provisional. No source
art is silently resized to fit, and no study plate is a completed player design.

The completed [Work 5 proof](SKIN-000/import-proof.md) supplies four composed
base previews for visual review. The candidate retains all ten rows, independent
browser/playing identity, both time fields, actual key hints and the original
logo. Its 14px font cells and rearranged panels are provisional D001 input.
Vizor passes packaging but its converted text/background contrast is poor and
its volume thumb needs adaptation or the documented frame-and-number fallback.
Successful conversion alone does not qualify an art direction or release rights.

The Author's Work 7 colour corrections restore the base right-border inner
stroke with a recorded palette override and set the canvas to the existing
logo's `#0000AA` blue. Preserve the logo bytes, including manually adjusted
antialiasing; adapt the surrounding background to this retained artwork.
The [revised proof](SKIN-000/import-proof.md#work-7-colour-corrections) checks
both border contrast and logo blending in all four previews.

The [Work 6 study](SKIN-000/command-traffic-study.md) connects art choices to
command traffic: repeated horizontal pieces print cheaply, irregular spacing
needs position commands, and solid backgrounds restore more cheaply as fills
than as blank bitmap rows. Keep colour/contrast, complete font coverage, clean
donor strips and release rights explicit adaptation inputs. Byte counts alone
do not settle visual acceptance or on-target drawing behavior.

The [Work 7 handoff](SKIN-000/review-and-handoff.md#implementation-ownership-and-promotion)
assigns final reference-skin/profile adaptation here, using the four native
previews and named component gaps. The Author accepted the corrected prototype
as a starting point; final art, default-skin choice and release rights remain open.
Resolve final geometry through D001 before
production layout work. Work 7 review of the corrected preview is complete.

## Work

1. [ ] Review an art direction and native 512x384 mockups with the Author,
   including all browser/status fields, selection, messages and long values.
   Start with reviewed Winamp import candidates and retain their compact visual
   scale; record any adaptation and redistribution conditions before packaging.
   Omit the graphic equalizer panel and controls entirely; retain the ordinary
   playback volume control. The reference skin does not display inactive EQ UI.
2. [ ] Create background/panel, font/glyph, logo and icon assets within fixed
   regions and colour roles. Keep changing information legible and make panel
   restoration practical without repeated full-screen redraws.
   Build the main UI primarily from printable multicolour bitmap tiles per
   [ADR-0001](../decisions/ADR-0001-character-based-ui-rendering.md), allowing
   independent large decorative bitmaps. Tile artwork must follow accepted
   font-cell advance and alignment rules.
3. [ ] Build a reproducible data-only package through SKIN-005, including only
   declared target assets. Retain editable first-party artwork in a suitable
   durable asset location and record its provenance.
4. [ ] Review the running skin on stock Console8 at native resolution; correct
   clipping, truncation, contrast, selection and stale-pixel problems.
5. [ ] Submit the validated package for hardware resource/audio testing and the
   default-skin decision SKIN-001-D007. Adjust assets to the accepted cap.

## Validation and acceptance

1. Host package validation and golden-package checks pass.
2. The Author accepts the running visual treatment; comparison with released
   player behavior confirms unchanged browsing and controls. Classic is deferred.
3. SKIN-007 records measured limits and human emulator/hardware results before
   the package becomes a qualified release asset. Default selection is recorded
   separately from visual approval.
