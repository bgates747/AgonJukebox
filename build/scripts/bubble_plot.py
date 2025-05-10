import os
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Define compression methods to filter
SZIP_OPTIONS = [
    "Szip -b1 -o6 -r1",  
    "Szip -b10 -o6 -r1",  
    "Szip -b1 -o10 -r1",  
    "Szip -b1 -o0 -r1",  
    "Szip -b1 -o6 -r3",  
    "Szip -b1 -o6 -r1 -i",  
    # "TurboVega"
]

def load_data_from_file(dir_path, filename="compression_results.txt"):
    """Load and filter data based on predefined compression methods."""
    file_path = os.path.join(dir_path, filename)
    data = []
    
    with open(file_path, "r") as f:
        lines = f.readlines()

    for line in lines:
        parts = line.strip().split()
        if len(parts) < 6 or parts[0] == "File":
            continue  # Skip headers and invalid lines

        file_name = parts[0]
        method = " ".join(parts[1:-4])  # Extract method name
        comp_time = float(parts[-4])
        decomp_time = float(parts[-3])
        compressed_size = int(parts[-2])
        compression_ratio = float(parts[-1])

        # Filter only the desired compression methods
        if method in SZIP_OPTIONS:
            data.append([file_name, method, comp_time, decomp_time, compressed_size, compression_ratio])

    return pd.DataFrame(data, columns=["File", "Method", "Comp Time", "Decomp Time", "Size", "Compression Ratio"])

def plot_bubble_chart(df):
    """Generate a bubble chart showing compression vs decompression time with size representing compressed file size."""
    plt.figure(figsize=(10, 6))

    unique_methods = df["Method"].unique()
    colors = plt.cm.tab10(np.linspace(0, 1, len(unique_methods)))
    color_map = dict(zip(unique_methods, colors))

    for method in unique_methods:
        subset = df[df["Method"] == method]
        plt.scatter(subset["Comp Time"], subset["Decomp Time"], 
                    s=subset["Size"] / 50, label=method, alpha=0.7, 
                    c=[color_map[method]])

    plt.xlabel("Compression Time (s)")
    plt.ylabel("Decompression Time (s)")
    plt.title("Compression vs Decompression Performance")
    plt.legend(loc="upper right", fontsize="small")
    plt.grid(True, linestyle="--", alpha=0.6)

    plt.xlim(0, 0.2)

    plt.show()

def main():
    dir_path = "/home/smith/Agon/mystuff/assets/video/frames"
    df = load_data_from_file(dir_path)
    
    if df.empty:
        print("No matching records found in the dataset.")
    else:
        plot_bubble_chart(df)

if __name__ == "__main__":
    main()
