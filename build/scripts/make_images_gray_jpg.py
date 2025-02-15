from PIL import Image
import numpy as np

def convert_rgba2_to_jpeg(input_path, output_path, width=320, height=136):
    """Convert a raw grayscale .rgba2 file to a grayscale JPEG."""
    try:
        # Read the raw grayscale data (assuming 8-bit grayscale, 1 byte per pixel)
        with open(input_path, "rb") as f:
            raw_data = f.read()

        # Ensure the file contains the expected amount of data
        expected_size = width * height
        if len(raw_data) != expected_size:
            raise ValueError(f"Unexpected file size: got {len(raw_data)} bytes, expected {expected_size} bytes")

        # Convert raw data to a NumPy array
        image_array = np.frombuffer(raw_data, dtype=np.uint8).reshape((height, width))

        # Create a grayscale PIL image
        image = Image.fromarray(image_array, mode="L")  # "L" mode = grayscale

        # Save as JPEG with grayscale compression
        image.save(output_path, "JPEG", quality=50, optimize=True)  # Adjust quality as needed

        print(f"Successfully converted {input_path} to {output_path}")

    except Exception as e:
        print(f"Error: {e}")

# Example usage
convert_rgba2_to_jpeg("assets/video/frames/frame_00009.rgba2", "assets/video/frames/frame_00009.jpg")
