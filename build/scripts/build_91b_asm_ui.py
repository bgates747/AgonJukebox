import json
import os
from PIL import Image
from agonImages import img_to_rgba2

def make_tbl_91b_UI(json_path, img_dir):
    """
    Scans a directory for .png files, stores each file’s name, width, and height
    in a list of dicts, and writes the data to a JSON file.
    """
    # Gather image metadata
    img_rows = []
    for filename in os.listdir(img_dir):
        if filename.endswith('.png'):
            file_path = os.path.join(img_dir, filename)
            with Image.open(file_path) as img:
                img_rows.append({
                    'panel_base_filename': filename[:-4],
                    'dim_x': img.width,
                    'dim_y': img.height
                })

    # Write out to JSON file
    with open(json_path, 'w', encoding='utf-8') as f:
        json.dump(img_rows, f, indent=2)

def make_rgba2_files(json_path, src_png_dir, tgt_rgba2_dir):
    """
    Reads metadata from a JSON file and converts each .png
    into a .rgba2 file in the target directory.
    """
    # Create target directory if it doesn't exist
    if not os.path.exists(tgt_rgba2_dir):
        os.makedirs(tgt_rgba2_dir)

    # Remove all .rgba2 files from target directory
    for filename in os.listdir(tgt_rgba2_dir):
        if filename.endswith('.rgba2'):
            os.remove(os.path.join(tgt_rgba2_dir, filename))

    # Load panel metadata from JSON
    with open(json_path, 'r', encoding='utf-8') as f:
        img_rows = json.load(f)

    # Convert each PNG to RGBA2
    for row in img_rows:
        panel_base_filename = row['panel_base_filename']
        src_file = os.path.join(src_png_dir, panel_base_filename + ".png")
        tgt_file = os.path.join(tgt_rgba2_dir, panel_base_filename + ".rgba2")
        with Image.open(src_file) as src_img:
            img_to_rgba2(src_img, tgt_file)

def make_asm_ui(json_path, ui_inc_path, last_buffer_id):
    """
    Reads metadata from a JSON file, then writes an .asm file that:
      1) Defines buffer IDs
      2) Creates code to load the bitmaps into VDP buffers
      3) Declares file paths for each image
    """
    # Load panel metadata from JSON
    with open(json_path, 'r', encoding='utf-8') as f:
        img_rows = json.load(f)

    buffer_id_counter = last_buffer_id
    with open(ui_inc_path, 'w', encoding='utf-8') as asm_writer:
        # Write the bitmap indices
        asm_writer.write("; Bitmap indices:\n")
        for row in img_rows:
            name = row['panel_base_filename'].upper()
            asm_writer.write(f"BUF_UI_{name}: equ 0x{buffer_id_counter:04X}\n")
            buffer_id_counter += 1

        # Write the code that loads the .rgba2 files
        asm_writer.write("\n; Import .rgba2 bitmap files and load them into VDP buffers\n")
        asm_writer.write("load_ui_images:\n")

        for row in img_rows:
            panel_base_filename = row['panel_base_filename']
            dim_x = row['dim_x']
            dim_y = row['dim_y']
            constName = "BUF_UI_" + panel_base_filename.upper()
            asm_writer.write("\n")
            asm_writer.write(f"\tld hl,F_UI_{panel_base_filename}\n")
            asm_writer.write(f"\tld de,filedata\n")
            asm_writer.write(f"\tld bc,{65536}\n")  # some extra padding just in case
            asm_writer.write("\tld a,mos_load\n")
            asm_writer.write("\tRST.LIL 08h\n")
            asm_writer.write(f"\tld hl,{constName}\n")
            asm_writer.write(f"\tld bc,{dim_x}\n")
            asm_writer.write(f"\tld de,{dim_y}\n")
            asm_writer.write(f"\tld ix,{dim_x * dim_y}\n")
            asm_writer.write("\tcall vdu_load_img\n")
            asm_writer.write("\tLD A, '.'\n")  # breadcrumbs now handled by vdu_load_img
            asm_writer.write("\tRST.LIL 10h\n")

        asm_writer.write("\n\tret\n\n")

        # Write out the file references
        for row in img_rows:
            panel_base_filename = row['panel_base_filename']
            asm_writer.write(f"F_UI_{panel_base_filename}: db \"ui/{panel_base_filename}.rgba2\",0\n")

    return buffer_id_counter

if __name__ == "__main__":
    # Adjust these paths as you see fit
    json_path   = 'build/data/ui_data.json'
    ui_inc_path = 'src/asm/ui_img.asm'
    src_png_dir = 'assets/images'
    tgt_rgba2_dir = 'tgt/ui'
    next_buffer_id = 0x2000

    make_tbl_91b_UI(json_path, src_png_dir)
    make_rgba2_files(json_path, src_png_dir, tgt_rgba2_dir)
    make_asm_ui(json_path, ui_inc_path, next_buffer_id)
