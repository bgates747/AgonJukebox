import shutil
import os

# Define source and target directories
source_dir = "/home/smith/Agon/szip"
target_dir = "/home/smith/Agon/os/agon-vdp/video/szip"

# List of filenames to copy
files_to_copy = [
    "bitmodel.c",
    "bitmodel.h",
    "history.txt",
    "port.h",
    "qsmodel.c",
    "qsmodel.h",
    "qsort_u4.c",
    "rangecod.c",
    "rangecod.h",
    "readme.txt",
    "reorder.c",
    "reorder.h",
    "sz_err.h",
    "sz_mod4.c",
    "sz_mod4.h",
    "sz_srt.c",
    "sz_srt.h",
    "techinfo.txt"
]

# Ensure the target directory exists
os.makedirs(target_dir, exist_ok=True)

# Copy each file
for file in files_to_copy:
    src = os.path.join(source_dir, file)
    dest = os.path.join(target_dir, file)
    try:
        shutil.copy2(src, dest)
        print(f"Copied: {src} -> {dest}")
    except FileNotFoundError:
        print(f"Warning: {src} not found.")

print("File copying complete.")
