import time
import os
import shutil
from PIL import Image
import agonutils as au

def crop_images_fixed_size(img, target_width=1920, target_height=1280):
    """
    Crops the given image to exactly 1920x1280 pixels if it is larger than that.
    Images smaller than 1920x1280 are left untouched.
    
    Parameters:
    - img (PIL.Image): The image to be cropped.
    - target_width (int): The target width to crop to.
    - target_height (int): The target height to crop to.
    
    Returns:
    - PIL.Image: The cropped image or original image if cropping is not needed.
    """
    # Get the original image dimensions
    original_width, original_height = img.size
    
    # Check if the image is larger than the target dimensions
    if original_width >= target_width and original_height >= target_height:
        print(f"Cropping image from {original_width}x{original_height} to {target_width}x{target_height}")
        
        # Perform the crop (top-left corner is (0, 0))
        cropped_img = img.crop((0, 0, target_width, target_height))
        return cropped_img
    
    # If the image is smaller than the target size, leave it untouched
    print(f"No cropping required for image with dimensions: {original_width}x{original_height}")
    return img


def crop_images(img, target_aspect_ratio=(4, 3)):
    """
    Crops the given image to the target aspect ratio if it's wider than taller.
    
    Parameters:
    - img (PIL.Image): The image to be cropped.
    - target_aspect_ratio (tuple): The target aspect ratio as a (width, height) tuple.
    
    Returns:
    - PIL.Image: The cropped image.
    """
    # Get the original image dimensions
    original_width, original_height = img.size
    
    # Calculate the target width and height based on the target aspect ratio
    target_width_ratio, target_height_ratio = target_aspect_ratio
    target_aspect = target_width_ratio / target_height_ratio
    
    # Calculate the current aspect ratio of the image
    current_aspect = original_width / original_height

    # Debugging: Print the original aspect ratio and target aspect ratio
    print(f"Original Aspect Ratio: {current_aspect}, Target Aspect Ratio: {target_aspect}")
    
    # If the image is wider than the target aspect ratio, we need to crop
    if current_aspect > target_aspect:
        print(f"Cropping required for image with dimensions: {original_width}x{original_height}")
        # Calculate the new width based on the target aspect ratio
        new_width = int(original_height * target_aspect)
        
        # Calculate the horizontal cropping offsets (to crop from the center)
        left = (original_width - new_width) // 2
        right = left + new_width
        
        # Crop the image to the new dimensions
        cropped_img = img.crop((left, 0, right, original_height))
        return cropped_img
    
    # Debugging: Print message if no cropping is needed
    print(f"No cropping required for image with dimensions: {original_width}x{original_height}")
    
    # If the image is not wider than the target aspect ratio, return it as-is
    return img


def scale_image(image, target_width, target_height):
    return image.resize((target_width, target_height), Image.BICUBIC)

def process_images(staging_directory, processed_directory, palette_filepath, transparent_rgb, screen_width, screen_height, palette_conversion_method, agon_rgba_type):


    os.makedirs(target_directory, exist_ok=True)
    os.makedirs(processed_directory, exist_ok=True)

    # Convert .jpeg, .jpg, and .gif files to .png
    for input_image_filename in os.listdir(staging_directory):
        input_image_path = os.path.join(staging_directory, input_image_filename)
        if input_image_filename.endswith(('.jpeg', '.jpg', '.gif')):
            # Load the image
            img = Image.open(input_image_path)

            # Convert to .png format and save with the same name but .png extension
            png_filename = os.path.splitext(input_image_filename)[0] + '.png'
            png_filepath = os.path.join(staging_directory, png_filename)
            img.save(png_filepath, 'PNG')

            # Optionally, delete the original .jpeg, .jpg, or .gif file after conversion
            os.remove(input_image_path)

    # Now scan the directory again for all .png files and sort them
    filenames = sorted([f for f in os.listdir(staging_directory) if f.endswith('.png')])

    # Process the images
    for input_image_filename in filenames:
        input_image_path = os.path.join(staging_directory, input_image_filename)

        # Continue only if it's a .png file
        if input_image_filename.endswith('.png'):
            # Open the image
            img = Image.open(input_image_path)

            # Remove ICC profile if present to avoid the warning
            if "icc_profile" in img.info:
                img.info.pop("icc_profile")

            # Re-save the image to remove the incorrect ICC profile
            img.save(input_image_path, 'PNG')

        input_image_filepath = f'{staging_directory}/{input_image_filename}'
        file_name, ext = os.path.splitext(input_image_filename)
        output_image_filepath_png = f'{processed_directory}/{input_image_filename}'

        with Image.open(input_image_filepath) as img:
            # Crop the image to the target aspect ratio if needed
            img = crop_images(img)
            scaled_img = scale_image(img, screen_width, screen_height)
            scaled_img.save(output_image_filepath_png)

        au.convert_to_palette(output_image_filepath_png, output_image_filepath_png, palette_filepath, palette_conversion_method, transparent_rgb)

        if agon_rgba_type == 1:
            rgba_filepath = f'{target_directory}/{file_name}.rgba2'
            au.img_to_rgba2(output_image_filepath_png, rgba_filepath)
        else:
            rgba_filepath = f'{target_directory}/{file_name}.rgba8'
            au.img_to_rgba8(output_image_filepath_png, rgba_filepath)

if __name__ == '__main__':
    staging_directory =         'assets/images/staging'
    processed_directory =  'assets/images/processed'
    target_directory =       'tgt/images'
    palette_filepath =      'assets/images/palettes/Agon64.gpl'
    transparent_rgb = (0, 0, 0, 0)
    screen_width = 120
    screen_height = 90
    palette_conversion_method = 'floyd'
    agon_rgba_type = 1  # RGBA2222

    process_images(staging_directory, processed_directory, palette_filepath, transparent_rgb, screen_width, screen_height, palette_conversion_method, agon_rgba_type)
