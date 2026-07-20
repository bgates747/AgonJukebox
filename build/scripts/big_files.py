# import os
# import subprocess

# # Path to save the big files list
# output_file_path = "build/scripts/big_files.txt"
# os.makedirs(os.path.dirname(output_file_path), exist_ok=True)

# try:
#     # Run the commands sequentially
#     rev_list = subprocess.Popen(
#         ["git", "rev-list", "--objects", "--all"], stdout=subprocess.PIPE, text=True
#     )
#     cat_file = subprocess.Popen(
#         ["git", "cat-file", "--batch-check=%(objectname) %(objecttype) %(objectsize) %(rest)"],
#         stdin=rev_list.stdout, stdout=subprocess.PIPE, text=True
#     )
#     sort = subprocess.Popen(
#         ["sort", "-k3", "-n", "-r"],
#         stdin=cat_file.stdout, stdout=subprocess.PIPE, text=True
#     )
    
#     # Write to the output file
#     with open(output_file_path, "w") as output_file:
#         subprocess.run(["head", "-n", "100"], stdin=sort.stdout, stdout=output_file, text=True)

#     print(f"Large files written to: {output_file_path}")

# except subprocess.CalledProcessError as e:
#     print("Error running Git commands:", e)

import subprocess

# Path to the file with the list of files to purge
file_list_path = "build/scripts/big_files.txt"

try:
    # Read the list of files to purge
    with open(file_list_path, "r") as file:
        # Extract file paths from the list
        files_to_remove = [line.strip().split(" ", 1)[1] for line in file if line.strip()]

    # Prepare the arguments for git filter-repo
    args = ["git", "filter-repo", "--force"]  # Added --force here
    for file_path in files_to_remove:
        args += ["--path", file_path, "--invert-paths"]
    
    # Run git filter-repo
    subprocess.run(args, check=True)
    print("Successfully purged files from Git history.")
except Exception as e:
    print(f"Error: {e}")


