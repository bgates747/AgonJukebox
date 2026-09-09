# Art Deco concept — 2026-09-09

Mode: built-in imagegen, followed by user-authorized local conversion. Both raw generated outputs failed the requested 512×384 RGB222 export constraints; see validation.json. The original was selected as the design source, resized with Lanczos, then rounded to RGB222 with no dithering. The final `art-deco-512x384-agon64.png` meets the requested constraints; see conversion.json. `convert.py` records the reproducible conversion. This is a private art concept, with no application or emulator integration.

## Generation prompt

Use case: ui-mockup.
Create ONE new native-resolution pixel-art Agon Jukebox interface, inspired by the attached image's Art Deco jukebox architecture. The attachment is a STYLE AND COMPOSITION REFERENCE, not an image to simply shrink. Recompose and simplify its ornament so the new design reads clearly at a TRUE EXACT 512 x 384 pixel canvas (4:3). Return the final image at exactly 512 pixels wide and 384 pixels high.
HARD COLOR CONSTRAINT: use ONLY Agon's RGB222 64-color palette. Each red, green and blue channel must independently be exactly one of 0, 85, 170, 255. This means every hexadecimal channel is 00, 55, AA or FF. No intermediate color values, no antialiasing, no transparency, no smooth gradients, no simulated blurry pixel art. Sharp individual pixels on a native 512x384 grid. Gold highlights can use #FFFFAA, #FFFF55, #FFAA00 and #AA5500 against #550000, #000000 and #000055; jewel accents #AA0000/#FF0000 and turquoise #005555/#00AAAA/#55FFFF. White #FFFFFF is allowed. Use solid color clusters and very restrained deliberate pixel dithering.
Style: elegant symmetrical 1920s Art Deco cabinet, bold stepped gold/brass frames, a central fan-shaped crown with a small ruby jewel, two slim luminous gold side columns, restrained turquoise inlays, black/deep blue recessed panels. Simplify lavish reference details into clean readable pixel shapes. Large flat dark areas keep text readable. No photographic lighting, no glow that adds intermediate colors, no perspective, no monitor bezel. The entire image is the interface.
Composition: around 44-pixel-wide decorative side pillars leave a central panel approximately 400 pixels wide. Top crown/header roughly y=6..60; central browser roughly y=65..235; now-playing panel y=242..292; transport/controls y=300..336; compact bottom status strip y=344..378. Keep generous margins between text and ornate frames. Render the right border as clearly as the left. Border detailing must not compete with text.
Text and function: this is a WAV audio player, with NO graphic equalizer. Main title exactly "AGON JUKEBOX", made of bold purpose-drawn pixel letters. Browser header "FILE NAME" and "TIME"; ten evenly spaced rows with compact legible monospaced bitmap lettering, not miniature antialiased Arial:
"0 SWING_TIME.WAV" with "03:24"
"1 NIGHT_TRAIN.WAV" with "04:12"
"2 LULLABY.WAV" with "02:58"
"3 SAPPHIRE.WAV" with "04:18"
"4 VINTAGE.WAV" with "03:05"
"5 TEA_DANCE.WAV" with "02:46"
"6 CAROUSEL.WAV" with "03:52"
"7 MOONLIGHT.WAV" with "05:10"
"8 SPEAKEASY.WAV" with "03:36"
"9 RAGTIME.WAV" with "02:59"
Highlight the SAPPHIRE row with solid amber and black lettering, a small triangular selection indicator. Below, "NOW PLAYING", "SAPPHIRE.WAV", and "01:26 / 04:18" with a simple progress bar. Controls use clear pixel icons for previous, play, pause, next, shuffle and repeat, with a small volume indicator. Bottom status text "/MUSIC" and "10 FILES", with a small Art Deco jewel ornament. Do not copy the reference's MOD/SID/IT/XM/STM formats, large file-size columns or eject icon. Use the available space for clear WAV player information.
A finished attractive native 512x384 screenshot-like art concept, designed pixel by pixel for the actual low resolution. No additional explanatory labels, watermark, surrounding margins or presentation board.

## Correction prompt

Edit target: the supplied generated Art Deco AGON JUKEBOX interface. Preserve its exact composition, wording, ornaments, colors' intended roles and controls. Change ONLY its technical raster format: the delivered PNG must be exactly 512 pixels wide by 384 pixels high, not an enlarged simulation of that resolution. It must have only Agon's RGB222 colors: every R, G, and B channel must be exactly 0, 85, 170 or 255. Downsample the design into clean native pixel clusters and snap every resulting pixel to the nearest allowed RGB222 color. No antialiasing, gradients, fractional pixel positions or transparency. Verify output file dimensions 512x384 and quantize the saved pixels themselves, rather than just approximating a limited palette visually. The previous file was actually 1448x1086 with 271330 unique colors; correct those two problems. Keep the visible design otherwise unchanged.
