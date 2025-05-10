#!/usr/bin/env python3
import os
import re
import pygame
import tempfile
import numpy as np
from PIL import Image

def parse_diff_index(filename):
    """
    Extract numeric index from filenames like 'frame_00010_diff.png'.
    Returns an integer (e.g. 10), or None if not matched.
    """
    m = re.search(r'frame_(\d+)_diff', filename.lower())
    if not m:
        return None
    return int(m.group(1))

def replace_magenta_with_transparent(in_path):
    """
    1) Open in_path as RGBA via PIL
    2) Replace pure magenta pixels (255,0,255) with alpha=0
    3) Write result to a temporary PNG file
    4) Return the path to that temporary file
    """
    # Open image in RGBA mode
    img = Image.open(in_path).convert("RGBA")
    arr = np.array(img)  # shape: (H, W, 4)

    # Find pure magenta with full alpha
    # arr[..., 0] = R, arr[..., 1] = G, arr[..., 2] = B, arr[..., 3] = A
    magenta_mask = (
        (arr[..., 0] == 255) &
        (arr[..., 1] == 0) &
        (arr[..., 2] == 255) &
        (arr[..., 3] == 255)
    )
    # Set alpha to 0 where mask is True
    arr[magenta_mask, 3] = 0

    # Create a new image and save to a temp file
    new_img = Image.fromarray(arr, mode="RGBA")
    tmp = tempfile.NamedTemporaryFile(suffix=".png", delete=False)
    tmp_path = tmp.name
    tmp.close()
    new_img.save(tmp_path)
    return tmp_path

def view_diff_images(diff_dir, frame_rate, scale_factor):
    """
    A simple Pygame "slideshow" that displays all PNGs in 'diff_dir'
    whose filenames match 'frame_XXXXX_diff.png' in ascending order of XXXXX.

    We have one extra step: for each diff image, we convert pure magenta to
    transparent (via PIL) before loading it into Pygame.
    
    :param diff_dir:     Path to directory containing the diff PNGs.
    :param frame_rate:   FPS to display (float or int).
    :param scale_factor: integer scaling factor for each image, e.g. 2 => 2x in each dimension.
    """
    # Initialize pygame
    pygame.init()
    clock = pygame.time.Clock()

    # Gather and sort diff images by numeric frame index
    frames = []
    for fname in os.listdir(diff_dir):
        if fname.lower().endswith("_diff.png"):
            idx = parse_diff_index(fname)
            if idx is not None:
                frames.append((idx, fname))

    if not frames:
        print(f"No diff PNGs found in '{diff_dir}'. Nothing to display.")
        pygame.quit()
        return

    frames.sort(key=lambda x: x[0])
    print(f"Found {len(frames)} diff images in '{diff_dir}'.")

    # Load each image into memory
    surfaces = []
    for (idx, fname) in frames:
        path = os.path.join(diff_dir, fname)
        # 1) Convert magenta -> transparent using PIL, save to temp file
        tmp_path = replace_magenta_with_transparent(path)
        # 2) Load temp file with Pygame
        img = pygame.image.load(tmp_path)  # We do NOT call convert_alpha() here
        # 3) Remove temp file
        os.remove(tmp_path)

        w, h = img.get_width(), img.get_height()
        if scale_factor != 1:
            img = pygame.transform.scale(img, (w * scale_factor, h * scale_factor))

        surfaces.append((idx, img))

    # Create a window sized to the first image
    first_idx, first_surf = surfaces[0]
    win_w, win_h = first_surf.get_width(), first_surf.get_height()
    screen = pygame.display.set_mode((win_w, win_h))
    pygame.display.set_caption("Diff Image Viewer")

    running = True
    frame_i = 0
    total_frames = len(surfaces)

    # Main loop
    while running:
        # Check events (quit, etc.)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        if frame_i < total_frames:
            # Display next image
            frame_idx, surf = surfaces[frame_i]
            screen.blit(surf, (0, 0))
            pygame.display.flip()

            frame_i += 1
            clock.tick(frame_rate)
        else:
            # All frames displayed => end
            running = False

    pygame.quit()
    print("All done. Exiting.")

if __name__ == "__main__":
    noDitherMethod = 'RGB'  # e.g. "bayer" or "RGB"
    dither_method  = 'floyd' # final dithering
    diff_dir       = f'/home/smith/Agon/mystuff/assets/video/diffs_{noDitherMethod}_{dither_method}'
    frame_rate     = 8   # frames per second
    scale_factor   = 2   # scale images by 2x

    if not os.path.isdir(diff_dir):
        print(f"Error: '{diff_dir}' not found or not a directory.")
    else:
        view_diff_images(diff_dir, frame_rate, scale_factor)
