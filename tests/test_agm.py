#!/usr/bin/env python3
import agonutils as au

if __name__ == '__main__':
    input_video = "/home/smith/Agon/mystuff/assets/video/staging/a_ha__Take_On_Me_short.mp4"
    output_video = "/home/smith/Agon/mystuff/assets/video/staging/a_ha__Take_On_Me_short_rle.agm"
    palette_file = "/home/smith/Agon/mystuff/agz/src/palettes/Agon64.gpl"
    
    # Use "RGB" as the no-dither method (base conversion) and "bayer" for the dithered conversion.
    noDither_method = "RGB"
    dither_method = "bayer"
    
    # Lookback parameter for reusing dithering (i.e. how many consecutive frames to consider unchanged).
    lookback = 5

    # Define target output dimensions.
    output_width = 320
    output_height = 240

    transparent_color = None  # No transparency

    print(f"Processing video: {input_video}")
    result = au.process_mp4(input_video, output_video, output_width, output_height,
                            palette_file, noDither_method, dither_method, lookback, transparent_color)

    if result == 0:
        print(f"Video successfully processed and saved to: {output_video}")
    else:
        print(f"Video processing failed with error code {result}")
