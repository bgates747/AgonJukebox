import os
import subprocess

def assemble_jukebox():
    """
    Executes the equivalent of the shell command:
    (cd src/asm && ez80asm -l jukebox.asm ../../tgt/jukebox.bin)
    Ensures the working directory is restored to its original state.
    """
    original_cwd = os.getcwd()  # Save the current working directory
    try:
        os.chdir('src/asm')  # Change to the target directory
        # Run the subprocess command
        subprocess.run(
            ['ez80asm', '-l', 'app.asm', '../../tgt/jukebox.bin'],
            check=True
        )
    except subprocess.CalledProcessError as e:
        print(f"Error: Assembly process failed with return code {e.returncode}")
    except FileNotFoundError:
        print("Error: Command 'ez80asm' or the specified files not found.")
    finally:
        os.chdir(original_cwd)  # Restore the original working directory

import os

def make_asm_sfx(sfx_inc_path, tgt_dir, asm_tgt_dir):
    # Get the list of `.wav` files from the target directory
    raw_files = sorted(
        [f for f in os.listdir(tgt_dir) if f.endswith(".wav")]
    )

    # Write to the include file for assembly
    with open(sfx_inc_path, 'w') as f:
        # Write the header
        f.write("; This file is created by build_98_asm_sfx.py, do not edit it!\n\n")

        # Write the file name lookup index
        f.write("; File name lookup index:\n")
        f.write("SFX_filename_index:\n")
        for raw_file in raw_files:
            base_filename = os.path.splitext(raw_file)[0]
            f.write(f"\tdl FN_{base_filename}\n")

        # Write the file name lookups
        f.write("\n; File name lookups:\n")
        for raw_file in raw_files:
            base_filename = os.path.splitext(raw_file)[0]
            f.write(f"FN_{base_filename}: db \"{asm_tgt_dir}/{base_filename}.wav\",0\n")

if __name__ == "__main__":
    tgt_dir = 'tgt/music'
    asm_tgt_dir = 'music'
    sfx_inc_path = f'src/asm/music.inc'
    make_asm_sfx(sfx_inc_path, tgt_dir, asm_tgt_dir)
    assemble_jukebox()