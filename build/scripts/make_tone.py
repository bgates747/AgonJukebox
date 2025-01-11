import wave
import struct
import math
import os

def generate_c_maj_chord():
    """
    Generates a 60-second C major chord (C4, E4, G4) and saves it 
    to assets/sound/music/staging/c_maj_4.wav.
    """
    # Frequencies for C4, E4, G4 (approximate)
    freq_c = 261.63
    freq_e = 329.63
    freq_g = 392.00

    sample_rate = 48000  # Hz
    duration_seconds = 60
    num_samples = int(sample_rate * duration_seconds)

    # Ensure the output directory exists
    output_dir = os.path.dirname("assets/sound/music/staging/c_maj_4.wav")
    os.makedirs(output_dir, exist_ok=True)

    # Open a .wav file for writing: 16-bit, mono, sample_rate
    with wave.open("assets/sound/music/staging/c_maj_4.wav", "wb") as wfile:
        wfile.setnchannels(1)         # mono
        wfile.setsampwidth(2)        # 16 bits
        wfile.setframerate(sample_rate)

        # Generate samples and write them directly
        for n in range(num_samples):
            t = float(n) / sample_rate  # time in seconds

            # Sum of sine waves for C, E, G
            sample_val = (
                math.sin(2 * math.pi * freq_c * t) +
                math.sin(2 * math.pi * freq_e * t) +
                math.sin(2 * math.pi * freq_g * t)
            )

            # Scale down to avoid clipping: ~0.3 is comfortable
            # (since we are summing three waves)
            sample_val *= 0.3

            # Convert floating value (-1.0 to +1.0) to 16-bit integer
            amplitude = 32767
            int_val = int(sample_val * amplitude)

            # Pack into binary data (little-endian, 16-bit)
            data = struct.pack('<h', int_val)
            wfile.writeframesraw(data)

    print("Saved C major chord to assets/sound/music/staging/c_maj_4.wav")

# Example usage:
if __name__ == "__main__":
    generate_c_maj_chord()
