import colorsys
import numpy as np
from PIL import Image
import struct

colors64 = [
    (0, 0, 0), # 0 Black
    (170, 0, 0), # 1 Dark red
    (0, 170, 0), # 2 Dark green
    (170, 170, 0), # 3 Olive
    (0, 0, 170), # 4 Dark blue
    (170, 0, 170), # 5 Dark magenta
    (0, 170, 170), # 6 Teal
    (170, 170, 170), # 7 Light gray
    (85, 85, 85), # 8 Gray
    (255, 0, 0), # 9 Red
    (0, 255, 0), # 10 Lime
    (255, 255, 0), # 11 Yellow
    (0, 0, 255), # 12 Blue
    (255, 0, 255), # 13 Magenta
    (0, 255, 255), # 14 Aqua
    (255, 255, 255), # 15 White
    (0, 0, 85), # 16 Navy (darkest blue)
    (0, 85, 0), # 17 Dark olive green
    (0, 85, 85), # 18 Darker teal
    (0, 85, 170), # 19 Azure
    (0, 85, 255), # 20 Lighter azure
    (0, 170, 85), # 21 Spring green
    (0, 170, 255), # 22 Sky blue
    (0, 255, 85), # 23 Light spring green
    (0, 255, 170), # 24 Medium spring green
    (85, 0, 0), # 25 Maroon
    (85, 0, 85), # 26 Violet
    (85, 0, 170), # 27 Indigo
    (85, 0, 255), # 28 Electric indigo
    (85, 85, 0), # 29 Dark khaki
    (85, 85, 170), # 30 Slate blue
    (85, 85, 255), # 31 Light slate blue
    (85, 170, 0), # 32 Chartreuse
    (85, 170, 85), # 33 Medium sea green
    (85, 170, 170), # 34 Light sea green
    (85, 170, 255), # 35 Deep sky blue
    (85, 255, 0), # 36 Lawn green
    (85, 255, 85), # 37 Light green
    (85, 255, 170), # 38 Pale green
    (85, 255, 255), # 39 Pale turquoise
    (170, 0, 85), # 40 Medium violet
    (170, 0, 255), # 41 Medium blue
    (170, 85, 0), # 42 Golden brown
    (170, 85, 85), # 43 Rosy brown
    (170, 85, 170), # 44 Medium orchid
    (170, 85, 255), # 45 Medium purple
    (170, 170, 85), # 46 Tan
    (170, 170, 255), # 47 Light steel blue
    (170, 255, 0), # 48 Bright green
    (170, 255, 85), # 49 Pale lime green
    (170, 255, 170), # 50 Pale light green
    (170, 255, 255), # 51 Light cyan
    (255, 0, 85), # 52 Hot pink
    (255, 0, 170), # 53 Deep pink
    (255, 85, 0), # 54 Dark orange
    (255, 85, 85), # 55 Salmon
    (255, 85, 170), # 56 Orchid
    (255, 85, 255), # 57 Bright magenta
    (255, 170, 0), # 58 Orange
    (255, 170, 85), # 59 Light salmon
    (255, 170, 170), # 60 Light pink
    (255, 170, 255), # 61 Lavender pink
    (255, 255, 85), # 62 Pale yellow
    (255, 255, 170) # 63 Light yellow
]

colors16 = [
    (0, 0, 0),         # Color 0
    (170, 0, 0),       # Color 1
    (0, 170, 0),       # Color 2
    (170, 170, 0),     # Color 3
    (0, 0, 170),       # Color 4
    (170, 0, 170),     # Color 5
    (0, 170, 170),     # Color 6
    (170, 170, 170),   # Color 7
    (85, 85, 85),      # Color 8
    (255, 0, 0),       # Color 9
    (0, 255, 0),       # Color 10
    (255, 255, 0),     # Color 11
    (0, 0, 255),       # Color 12
    (255, 0, 255),     # Color 13
    (0, 255, 255),     # Color 14
    (255, 255, 255)    # Color 15
]

def get_rgba_color_by_index(index):
    """
    Fetches a color by index from the global 'colors64' list and adds full opacity.

    Args:
    index (int): The zero-based index for the color in the 'colors64' list.

    Returns:
    tuple: An RGBA color tuple.
    """
    global colors64  # Reference the global variable

    if index == -1:
        return (0, 0, 0, 0)

    # Check if the index is within the bounds of the colors64 list
    if index < 0 or index >= len(colors64):
        raise IndexError("Color index out of range")

    # Fetch the color and add an alpha value of 255 for full opacity
    rgb = colors64[index]
    rgba = rgb + (255,)  # Add full opacity

    return rgba

def rgb_to_hsv(color):
    """Convert an RGB color (with each component in the range [0, 255]) to HSV."""
    return colorsys.rgb_to_hsv(color[0]/255.0, color[1]/255.0, color[2]/255.0)

def getColorDistanceHSV(hsv1, hsv2):
    """Calculate the Euclidean distance between two colors in HSV space."""
    # Simple Euclidean distance. Consider more sophisticated approaches for hue.
    return np.sqrt((hsv1[0]-hsv2[0])**2 + (hsv1[1]-hsv2[1])**2 + (hsv1[2]-hsv2[2])**2)

def getColorDistanceRGB(color1, color2):
    """Calculate the Euclidean distance between two RGB colors."""
    return np.sqrt(sum((np.array(color1) - np.array(color2)) ** 2))

def findNearestColorRGB(targetColor, numcolors):
    """Find the nearest color in the 16-color palette to the target RGB color, ignoring alpha for distance calculation."""
    if targetColor[3] == 0:  # Check if the target color is fully transparent
        return (0, 0, 0, 0)  # Return a fully transparent color
    # Remove alpha channel from target color for comparison
    targetRGB = targetColor[:3]
    minDistance = float('inf')
    nearestColor = None
    if numcolors == 16:
            colors = colors16
    else:
            colors = colors64
    for color in colors:
        distance = getColorDistanceRGB(targetRGB, color)
        if distance < minDistance:
            minDistance = distance
            nearestColor = color
    # Return the nearest color with full opacity
    return nearestColor + (255,)

def findNearestColorHSV(targetColor, numcolors):
    """Find the nearest color in the 16-color palette to the target RGB color using HSV color space."""
    if targetColor[3] == 0:  # Check if the target color is fully transparent
        return (0, 0, 0, 0)  # Return a fully transparent color

    # Convert target RGB to HSV for comparison, ignoring alpha
    targetHSV = rgb_to_hsv(targetColor[:3])
    minDistance = float('inf')
    nearestColor = None

    if numcolors == 16:
            colors = colors16
    else:
            colors = colors64

    for color in colors:
        # Convert each palette color to HSV
        paletteHSV = rgb_to_hsv(color)
        distance = getColorDistanceHSV(targetHSV, paletteHSV)
        if distance < minDistance:
            minDistance = distance
            nearestColor = color

    # Return the nearest color with full opacity
    return nearestColor + (255,)

# the optional transparent_color parameter is a tuple of RGB values to treat as transparent
# it can contain a fourth value for alpha, but it will be ignored
def convert_to_agon_palette(image, numcolors, method, transparent_color=None):
    width, height = image.size
    # Ensure the image is in RGBA mode
    if image.mode != 'RGBA':
        image = image.convert('RGBA')
    
    new_img = Image.new('RGBA', (width, height))

    # Process each pixel according to the color conversion method
    if method == 'RGB':
        for x in range(width):
            for y in range(height):
                current_pixel = image.getpixel((x, y))
                # Only compare RGB channels for transparency
                if transparent_color and current_pixel[:3] == transparent_color[:3]:
                    nearest_color = (0, 0, 0, 0)
                else:
                    nearest_color = findNearestColorRGB(current_pixel, numcolors)
                    nearest_color = nearest_color[:3] + (255,)  # Preserve full opacity unless transparent
                new_img.putpixel((x, y), nearest_color)
    elif method == 'HSV':
        for x in range(width):
            for y in range(height):
                current_pixel = image.getpixel((x, y))
                # Apply transparency check for HSV method if needed
                if transparent_color and current_pixel[:3] == transparent_color[:3]:
                    nearest_color = (0, 0, 0, 0)
                else:
                    nearest_color = findNearestColorHSV(current_pixel, numcolors)
                    nearest_color = nearest_color[:3] + (255,)  # Preserve full opacity unless transparent
                new_img.putpixel((x, y), nearest_color)
    else:
        raise ValueError("convert_to_agon_palette: Invalid method. Use 'RGB' or 'HSV'.")

    return new_img

def img_to_rgba8(image, filepath):
    """
    Save the RGBA values of each pixel in the given Pillow image to a file.

    Args:
    - image: A Pillow Image object.
    - filepath: Full path and file name where to save the pixel data.
    """
    # Ensure the image is in RGBA mode
    if image.mode != 'RGBA':
        image = image.convert('RGBA')
    
    width, height = image.size
    with open(filepath, 'wb') as file:
        # Iterate over each pixel
        for y in range(height):
            for x in range(width):
                r, g, b, a = image.getpixel((x, y))
                # Write the RGBA values sequentially
                file.write(struct.pack('4B', r, g, b, a))

def quantize_to_2bit(value):
    """
    Quantize the value into one of four buckets and return the corresponding 2-bit representation.
    """
    if value < (85 / 2):
        return 0b00  
    elif value < (85 + 170) / 2:
        return 0b01  
    elif value < (170 + 255) / 2:
        return 0b10 
    else:
        return 0b11 

def img_to_rgba2(image, filepath):
    """
    Convert an image to a custom 2-bit per channel format in ABGR order and save it to a file.

    Args:
    - image: A Pillow Image object.
    - filepath: Full path and file name where to save the compressed pixel data.
    """
    # Ensure the image is in RGBA mode
    if image.mode != 'RGBA':
        image = image.convert('RGBA')
    
    with open(filepath, 'wb') as file:
        for y in range(image.height):
            for x in range(image.width):
                r, g, b, a = image.getpixel((x, y))
                # Quantize each component
                a_q = quantize_to_2bit(a)
                b_q = quantize_to_2bit(b)
                g_q = quantize_to_2bit(g)
                r_q = quantize_to_2bit(r)
                # Combine quantized components into a single byte
                combined = (a_q << 6) | (b_q << 4) | (g_q << 2) | r_q
                file.write(struct.pack('B', combined))

def rgba8_to_img(src_file_path, dim_x, dim_y):
    """
    Converts an RGBA8 binary file to a PNG image and returns the PIL Image object.

    Args:
    - src_file_path (str): The path to the source RGBA8 binary file.
    - dim_x (int): The width of the image.
    - dim_y (int): The height of the image.

    Returns:
    - PIL.Image: An image object.
    """
    # Read the binary data from the file
    with open(src_file_path, "rb") as file:
        data = file.read()
    
    # Create an image from the binary data
    image = Image.frombytes("RGBA", (dim_x, dim_y), data)

    # Return the PIL Image object
    return image

def decode_pixel(pixel):
    a = (pixel >> 6) & 0b11
    b = (pixel >> 4) & 0b11
    g = (pixel >> 2) & 0b11
    r = pixel & 0b11
    mapping = {0: 0, 1: 85, 2: 170, 3: 255}
    return [mapping[r], mapping[g], mapping[b], mapping[a]]

def rgba2_to_img(src_file_path, dim_x, dim_y):
    # print(f"src_file_path: {src_file_path}, dim_x: {dim_x}, dim_y: {dim_y}")
    """
    Converts an RGBA2 binary file to a PNG image and returns the PIL Image object.

    Args:
    - src_file_path (str): The path to the source RGBA2 binary file.
    - dim_x (int): The width of the image.
    - dim_y (int): The height of the image.

    Returns:
    - PIL.Image: An image object.
    """
    # Initialize an empty list to accumulate our decoded pixel data
    pixel_data = []
    
    # Read the binary data from the file
    with open(src_file_path, "rb") as file:
        binary_data = file.read()
        
    # Decode each byte of the binary data
    for byte in binary_data:
        decoded_pixels = decode_pixel(byte)
        pixel_data.extend(decoded_pixels)
    
    # Convert the pixel data list to a bytes object
    pixel_data_bytes = bytes(pixel_data)
    
    # Create an image from the decoded pixel data
    image = Image.frombytes('RGBA', (dim_x, dim_y), pixel_data_bytes)

    # Return the PIL Image object
    return image

if __name__ == "__main__":
    rgba2_file = "tgt/3.rgba2"
    bmp_file = "tgt/3.bmp"
    png_file = "tgt/3b.png"
    pil_img = Image.open(bmp_file)
    transparent_color = (255,255,255) ; # White
    pil_img = convert_to_agon_palette(pil_img, 64, 'HSV', transparent_color)
    img_to_rgba2(pil_img, rgba2_file)
    height = pil_img.height
    width = pil_img.width
    pil_img2 = rgba2_to_img(rgba2_file, width, height)
    pil_img2.save(png_file)
