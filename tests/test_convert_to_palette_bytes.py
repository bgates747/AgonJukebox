#!/usr/bin/env python3
import agonutils as au
from PIL import Image

if __name__ == '__main__':
    method = 'floyd'
    transparent_color = None 
    palette_file = 'src/palettes/Agon64.gpl'

    # base_file = "tests/rainbow_swirl"
    base_file = "/home/smith/Agon/mystuff/AgonJukebox/tgt/rainbow_swirl"
    rgba2_file = f"{base_file}_{method}.rgba2"
    png_file = f"{base_file}.png"

    # Open the source PNG and force it to RGBA mode (ensuring 4 bytes per pixel)
    pil_img = Image.open(png_file).convert('RGBA')
    input_data = pil_img.tobytes()
    width, height = pil_img.size

    # Use the palette conversion function to get a 32-bit RGBA result
    converted_bytes = au.convert_to_palette_bytes(
        input_data, width, height, palette_file, method, transparent_color
    )

    # Save the converted 32-bit RGBA data as a PNG (for verification)
    pil_img2 = Image.frombytes('RGBA', (width, height), converted_bytes)
    pil_img2.save(f"{base_file}_{method}_bytes.png")

    # Also run the file-based palette conversion (for comparison)
    au.convert_to_palette(
        png_file, f"{base_file}_{method}_file.png", palette_file, method, transparent_color
    )

    # Now, convert the 32-bit RGBA data to a packed RGBA2 bytes packet in memory
    rgba2_bytes = au.rgba32_to_rgba2_bytes(converted_bytes, width, height)

    # Save the RGBA2 raw data to file (this is a raw binary file, not a PNG)
    with open(rgba2_file, "wb") as f:
        f.write(rgba2_bytes)

    # Optional: convert the RGBA2 bytes back to 32-bit RGBA to verify round-trip integrity
    restored_rgba32 = au.rgba2_to_rgba32_bytes(rgba2_bytes, width, height)
    pil_img3 = Image.frombytes('RGBA', (width, height), restored_rgba32)
    pil_img3.save(f"{base_file}_{method}_restored.png")
