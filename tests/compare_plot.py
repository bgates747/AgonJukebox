import pandas as pd
import matplotlib.pyplot as plt

df_6 = pd.read_csv("tests/compare_compressions_interleaved_06.csv")
df_10 = pd.read_csv("tests/compare_compressions_interleaved_10.csv")
df_30 = pd.read_csv("tests/compare_compressions_interleaved_30.csv")

# For each DataFrame, compute average compressed size relative to original.
# For example, 'indiv_diffed_ratio' = indiv_diffed_bytes / original_bytes.

for df, fps_label in [(df_6, "6fps"), (df_10, "10fps"), (df_30, "30fps")]:
    # Calculate ratio columns
    df["indiv_diffed_ratio"] = df["indiv_diffed_bytes"] / df["original_bytes"]
    df["sequential_diffed_ratio"] = df["sequential_diffed_bytes"] / df["original_bytes"]
    df["interleaved_rle_diffed_ratio"] = df["interleaved_rle_diffed_bytes"] / df["original_bytes"]
    
    # Average the ratio columns
    means = {
        "indiv_diffed": df["indiv_diffed_ratio"].mean(),
        "sequential_diffed": df["sequential_diffed_ratio"].mean(),
        "interleaved_rle_diffed": df["interleaved_rle_diffed_ratio"].mean(),
    }
    
    plt.figure(figsize=(5,4))
    plt.bar(means.keys(), means.values(), color=['royalblue','orange','green'])
    plt.title(f"Average Diffed Compression Ratios @ {fps_label}")
    plt.ylabel("Mean Ratio (compressed / original)")
    plt.ylim(0, max(means.values())*1.2)  # for some margin
    for i, v in enumerate(means.values()):
        plt.text(i, v + 0.01, f"{v*100:.2f}%", ha='center')
    plt.show()
