import sqlite3
import os
import subprocess

def make_asm_sfx(db_path, sfx_inc_path, asm_tgt_dir, next_buffer_id, sample_rate):
    # Connect to the database
    conn = sqlite3.connect(db_path)
    conn.row_factory = sqlite3.Row  # Set row_factory to access columns by names
    cursor = conn.cursor()

    # Execute the query
    cursor.execute("""
        -- SELECT sfx_id, size, duration, filename
        --- SELECT sfx_id, size, cast(duration*16/16.384 as integer) as duration, filename
        SELECT sfx_id, size, cast(duration*16/16.4 as integer) as duration, filename
        FROM tbl_08_sfx
        ORDER BY sfx_id;""")
    rows = cursor.fetchall()

    # Write to the include file for assembly
    with open(sfx_inc_path, 'w') as f:
        # Write the header
        f.write("; This file is created by build_98_asm_sfx.py, do not edit it!\n\n")
        f.write(f"SFX_num_buffers: equ {len(rows)}\n")
        f.write(f"sample_rate: equ {sample_rate}\n\n")

        # # Write the buffer ids
        # f.write("; SFX buffer ids:\n")
        # for row in rows:
        #     sfx_id = row['sfx_id']
        #     base_filename = row['filename'].split('.')[0].upper()
        #     buf_id = next_buffer_id + sfx_id
        #     buf_label = f"BUF_{base_filename}"
        #     f.write(f"{buf_label}: equ 0x{buf_id:04X}\n")

        # # Write the buffer id reverse lookup
        # f.write("\n; SFX buffer id reverse lookup:\n")
        # f.write("SFX_buffer_id_lut:\n")
        # for row in rows:
        #     sfx_id = row['sfx_id']
        #     base_filename = row['filename'].split('.')[0].upper()
        #     buf_label = f"BUF_{base_filename}"
        #     f.write(f"\tdl {buf_label}\n")

        # # Write the sfx duration lookup
        # f.write("\n; SFX duration lookup:\n")
        # f.write("SFX_duration_lut:\n")
        # for row in rows:
        #     duration = row['duration']
        #     base_filename = row['filename'].split('.')[0].upper()
        #     f.write(f"\tdl {duration} ; {base_filename}\n")

        # # Write the load routines jump table
        # f.write("\n; SFX load routines jump table:\n")
        # f.write("SFX_load_routines_table:\n")
        # for row in rows:
        #     sfx_id = row['sfx_id']
        #     base_filename = row['filename'].split('.')[0].upper()
        #     f.write(f"\tdl load_sfx_{base_filename}\n")

        # # Write the load routines
        # f.write("\n; Import sfx .raw files and load them into VDP buffers\n")
        # for row in rows:
        #     sfx_id = row['sfx_id']
        #     base_filename = row['filename'].split('.')[0].upper()
        #     buf_label = f"BUF_{base_filename}"
        # # write the load routine
        #     f.write(f"\nload_sfx_{base_filename}:\n")
        #     f.write(f"\tld hl,{buf_label}\n")
        #     f.write(f"\tld de,{sample_rate}\n")
        #     f.write(f"\tld iy,F{base_filename}\n")
        #     f.write(f"\tcall vdu_load_sfx\n")
        #     f.write(f"\tret\n")

        # Write the file name lookup index
        f.write("\n; File name lookup index:\n")
        f.write("SFX_filename_index:\n")
        for row in rows:
            base_filename = row['filename'].split('.')[0]
            f.write(f"\tdl FN_{base_filename}\n")

        # Write the file name lookups
        f.write("\n; File name lookups:\n")
        for row in rows:
            base_filename = row['filename'].split('.')[0]
            f.write(f"FN_{base_filename}: db \"{asm_tgt_dir}/{base_filename}.raw\",0\n")

        # # Make the play sfx routines
        # f.write("\n; Play sfx routines\n")
        # for row in rows:
        #     sfx_id, size, duration, filename = row['sfx_id'], row['size'], row['duration'], row['filename']
        #     buf_label = f"BUF_{row['filename'].split('.')[0].upper()}"
        #     base_filename = filename.split('.')[0].upper() #.lower()
        #     f.write(f"\nsfx_play_{base_filename}:\n")
        #     f.write(f"\tld hl,{buf_label}\n")
        #     f.write(f"\tld bc,0\n") # 0 means play entire sample once
        #     f.write(f"\tjp vdu_play_sfx\n")

    # Close the connection
    conn.close()

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
            ['ez80asm', '-l', 'jukebox.asm', '../../tgt/jukebox.bin'],
            check=True
        )
    except subprocess.CalledProcessError as e:
        print(f"Error: Assembly process failed with return code {e.returncode}")
    except FileNotFoundError:
        print("Error: Command 'ez80asm' or the specified files not found.")
    finally:
        os.chdir(original_cwd)  # Restore the original working directory

            

if __name__ == "__main__":
    db_path = 'build/data/build.db'
    asm_tgt_dir = 'music'
    sfx_inc_path = f"src/asm/music.inc"
    next_buffer_id = 0x3000
    # sample_rate = 44100 # standard high quality audio
    # sample_rate = 44100 // 2 # powers of two are good
    # sample_rate = 16384 # default rate for Agon
    sample_rate = 32768 # a nice power of two of bytes/sec if she'll take it
    # sample_rate = 16000 # A standard Audacity option
    # sample_rate = 15360 # for 8-bit PCM this is 256 bytes per 1/60th of a second
    # sample_rate = 15360*2 # for 8-bit PCM this is 512 bytes per 1/60th of a second
    make_asm_sfx(db_path, sfx_inc_path, asm_tgt_dir, next_buffer_id, sample_rate)
    assemble_jukebox()
