import os
import subprocess
import json

src_dir = 'assets/sound/music/trimmed'

def scan_files_with_ffprobe(directory):
    """
    Scans all files in the given directory (non-recursive) and outputs the entire ffprobe output for each file.
    """
    for filename in sorted(os.listdir(directory)):
        file_path = os.path.join(directory, filename)
        
        if os.path.isfile(file_path):
            print(f"Processing file: {filename}")
            
            try:
                result = subprocess.run(
                    [
                        'ffprobe', '-v', 'error', '-show_format', '-show_streams',
                        '-print_format', 'json', file_path
                    ],
                    capture_output=True,
                    text=True
                )
                
                metadata = json.loads(result.stdout)
                print(json.dumps(metadata, indent=4))
                print("-" * 40)
            except Exception as e:
                print(f"Error processing {filename}: {e}")

if __name__ == "__main__":
    scan_files_with_ffprobe(src_dir)
