import pandas as pd
import matplotlib.pyplot as plt

# Load spectrum data
spectrum_file = "assets/sound/music/spectrum.txt"
spectrum_data = pd.read_csv(spectrum_file, sep="\t")

# Extract Frequency and Level columns
frequency = spectrum_data['Frequency (Hz)']
level = spectrum_data['Level (dB)']

# Identify dominant frequencies
threshold = -60  # dB level above which frequencies are considered dominant
dominant_frequencies = spectrum_data[frequency > threshold]  # Fixed indexing

# Print dominant frequencies
print("Dominant Frequencies (Hz):")
print(dominant_frequencies)

# Plot the spectrum
plt.figure(figsize=(10, 6))
plt.plot(frequency, level, label="Noise Spectrum", color="blue")
plt.axhline(threshold, color='red', linestyle='--', label=f"Threshold ({threshold} dB)")
plt.title("Frequency Spectrum")
plt.xlabel("Frequency (Hz)")
plt.ylabel("Level (dB)")
plt.legend()
plt.grid(True, linestyle='--', alpha=0.7)
plt.show()
