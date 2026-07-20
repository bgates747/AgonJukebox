import os

def clean_macos_litter(root_dir):
    """
    Recursively remove macOS-generated files like `.DS_Store` and `._*`
    from the given root directory, excluding `.venv` and `.vscode` directories.
    """
    excluded_dirs = {'.venv', '.vscode'}
    litter_files = ['.DS_Store', '._DS_Store', '.DS._Store', '._DS._Store']

    for dirpath, dirnames, filenames in os.walk(root_dir):
        # Exclude specified directories
        dirnames[:] = [d for d in dirnames if d not in excluded_dirs]

        # Remove macOS litter files
        for filename in filenames:
            if filename in litter_files or filename.startswith("._"):
                file_path = os.path.join(dirpath, filename)
                try:
                    os.remove(file_path)
                    print(f"Removed: {file_path}")
                except Exception as e:
                    print(f"Failed to remove {file_path}: {e}")


if __name__ == "__main__":
    # Set the root directory to the current directory
    root_dir = os.path.dirname(os.path.abspath(__file__))
    clean_macos_litter(root_dir)
