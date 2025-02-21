#!/usr/bin/env python3
import agonutils as au
import agonImages as ai
from PIL import Image

def main(input_path, output_path):
    # Read the input file as binary
    with open(input_path, 'rb') as infile:
        data = infile.read()

    # Invert the image data using the au.invert function
    inverted_data = au.invert(data)

    # Write the inverted data back to a new file
    with open(output_path, 'wb') as outfile:
        outfile.write(inverted_data)

if __name__ == '__main__':
    method = 'RGB'

    base_file = "tests/black"
    rgba2_file = f"{base_file}_{method}.rgba2"
    inv_rgba2_file = f"{base_file}_{method}_inv.rgba2"
    png_file = f"{base_file}.png"
    pil_img = Image.open(png_file)
    transparent_color = None 
    pil_img = ai.convert_to_palette(pil_img, 64, method, transparent_color)
    ai.img_to_rgba2(pil_img, rgba2_file)

    height = pil_img.height
    width = pil_img.width
    pil_img2 = ai.rgba2_to_img(rgba2_file, width, height)
    pil_img2.save(f"{base_file}_{method}.png")

    main(rgba2_file, inv_rgba2_file)
    pil_img3 = ai.rgba2_to_img(inv_rgba2_file, width, height)
    pil_img3.save(f"{base_file}_{method}_inv.png")
