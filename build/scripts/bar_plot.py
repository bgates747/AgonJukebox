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
    """Load and filter data based on predefined compression methods, compute mean and standard deviation."""
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
        compression_ratio = float(parts[-1]) * 100  # Convert to percentage

        if method in SZIP_OPTIONS:
            data.append([method, comp_time, decomp_time, compressed_size, compression_ratio])

    df = pd.DataFrame(data, columns=["Method", "Comp Time", "Decomp Time", "Size", "Compression Ratio"])

    # Compute mean & standard deviation for each method
    grouped = df.groupby("Method").agg(
        CompTimeMean=("Comp Time", "mean"),
        CompTimeStd=("Comp Time", "std"),
        DecompTimeMean=("Decomp Time", "mean"),
        DecompTimeStd=("Decomp Time", "std"),
        CompressionRatioMean=("Compression Ratio", "mean")
    ).reset_index()

    return grouped

def plot_bar_chart(df):
    """Generate a bar plot with dual y-axes for time and compression ratio."""
    fig, ax1 = plt.subplots(figsize=(12, 6))

    # X-axis positions
    x_pos = np.arange(len(df["Method"]))
    width = 0.3  # Bar width

    # Plot compression & decompression times (Primary Y-axis)
    ax1.bar(x_pos - width, df["CompTimeMean"], width, yerr=df["CompTimeStd"], label="Compression Time", capsize=5, color="blue")
    ax1.bar(x_pos, df["DecompTimeMean"], width, yerr=df["DecompTimeStd"], label="Decompression Time", capsize=5, color="green")
    
    ax1.set_ylabel("Time (seconds)")
    ax1.set_xlabel("Compression Method")
    ax1.set_xticks(x_pos)
    ax1.set_xticklabels(df["Method"], rotation=30, ha="right")
    ax1.legend(loc="upper left")
    ax1.grid(axis="y", linestyle="--", alpha=0.6)
    # ax1.set_ylim(0, max(df["DecompTimeMean"] + df["DecompTimeStd"]) * 1.2)  # Ensure 0-based scaling
    ax1.set_ylim(0, 0.01)  # Ensure 0-based scaling

    # Plot compression ratio as bars on the secondary axis
    ax2 = ax1.twinx()
    ax2.bar(x_pos + width, df["CompressionRatioMean"], width, label="Compression Ratio (%)", color="red", alpha=0.6)
    ax2.set_ylabel("Compression Ratio (%)")
    ax2.set_ylim(0, 100)  # Full-scale 0-100%
    ax2.legend(loc="upper right")

    plt.title("Compression & Decompression Times with Compression Ratio")
    plt.tight_layout()
    plt.show()

def main():
    dir_path = "assets/video/frames"
    df = load_data_from_file(dir_path)

    if df.empty:
        print("No matching records found in the dataset.")
    else:
        plot_bar_chart(df)

if __name__ == "__main__":
    main()
