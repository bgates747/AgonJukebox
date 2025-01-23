import os

def rename_files_in_order(source_dir, titles_file):
    """
    Renames files in the source directory to match titles in the titles file.

    Parameters:
    - source_dir: Path to the source directory containing files to rename.
    - titles_file: Path to the file containing the new titles (one per line).
    """
    # Get a sorted list of files in the source directory (non-recursive)
    original_files = sorted(os.listdir(source_dir))

    # Read the new titles from the titles file
    with open(titles_file, "r") as f:
        new_titles = [line.strip() for line in f if line.strip()]

    # Check if the number of files matches the number of titles
    if len(original_files) != len(new_titles):
        raise ValueError("Number of files in source directory does not match the number of titles.")

    # Rename each file in order
    for original, new_title in zip(original_files, new_titles):
        original_path = os.path.join(source_dir, original)
        new_path = os.path.join(source_dir, new_title)

        # Rename the file
        os.rename(original_path, new_path)
        print(f"Renamed: {original} -> {new_title}")

if __name__ == "__main__":
    # Define source directory and titles file
    source_directory = "assets/sound/music/staging"
    titles_file_path = "src/asm/song_list.txt"

    # Perform the renaming
    rename_files_in_order(source_directory, titles_file_path)
