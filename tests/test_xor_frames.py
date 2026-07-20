#!/usr/bin/env python3
from PIL import Image
import numpy as np
import agonutils as au

# # Open the images and convert them to 24-bit RGB (ignoring alpha channel)
# img1 = Image.open("/home/smith/Agon/mystuff/assets/video/frames/frame_00137.png").convert("RGB")
# img2 = Image.open("/home/smith/Agon/mystuff/assets/video/frames/frame_00138.png").convert("RGB")

# # Convert the images to numpy arrays.
# arr1 = np.array(img1)
# arr2 = np.array(img2)

# # Ensure both images have the same dimensions.
# if arr1.shape != arr2.shape:
#     raise ValueError("Images do not have the same dimensions.")

# # Compute the pixel-wise XOR of the two arrays.
# xor_result = np.bitwise_xor(arr1, arr2)

# # Convert the result back to an image in RGB mode.
# result_img = Image.fromarray(xor_result, mode="RGB")

# # Save the resulting image.
# result_img.save("diff_00138.png")


method = 'RGB'
transparent_color = None 
palette_file = 'src/palettes/Agon64.gpl'

base_file = "diff_00138"
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

# Now, convert the 32-bit RGBA data to a packed RGBA2 bytes packet in memory
rgba2_bytes = au.rgba32_to_rgba2_bytes(converted_bytes, width, height)

# Save the RGBA2 raw data to file (this is a raw binary file, not a PNG)
with open(rgba2_file, "wb") as f:
    f.write(rgba2_bytes)

