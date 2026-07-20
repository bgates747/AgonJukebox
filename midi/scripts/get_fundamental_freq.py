#!/usr/bin/env python3
import os
import numpy as np
from scipy import signal
import soundfile as sf
import matplotlib.pyplot as plt

def estimate_fundamental_frequency(audio_data, sample_rate, plot=False):
    """
    Estimate the fundamental frequency of an audio sample using FFT.
    
    Args:
        audio_data: Audio data as numpy array
        sample_rate: Sample rate in Hz
        plot: Whether to plot the FFT spectrum
        
    Returns:
        Estimated fundamental frequency in Hz
    """
    # Prepare the audio data
    # Use a Hanning window to minimize spectral leakage
    windowed_data = audio_data * signal.windows.hann(len(audio_data))
    
    # Compute FFT
    n = len(windowed_data)
    fft_data = np.abs(np.fft.rfft(windowed_data))
    
    # Compute frequency bins
    freqs = np.fft.rfftfreq(n, 1/sample_rate)
    
    # Ignore very low frequencies (below 20 Hz) which are often noise
    min_freq_idx = np.argmax(freqs >= 20)
    
    # Set a reasonable upper limit for fundamental frequency (4 kHz)
    max_freq_idx = np.argmax(freqs >= 4000) if np.any(freqs >= 4000) else len(freqs)
    
    # Find peaks in the FFT spectrum
    peak_indices = signal.find_peaks(fft_data[min_freq_idx:max_freq_idx], height=0.1*np.max(fft_data))[0] + min_freq_idx
    
    if len(peak_indices) == 0:
        # If no clear peaks, use the max value
        fund_idx = np.argmax(fft_data[min_freq_idx:max_freq_idx]) + min_freq_idx
    else:
        # Sort peaks by amplitude and take the most prominent one
        peak_indices = sorted(peak_indices, key=lambda i: fft_data[i], reverse=True)
        fund_idx = peak_indices[0]
    
    fundamental_freq = freqs[fund_idx]
    
    # If frequency seems too high, it might be a harmonic - try to find a lower peak
    if fundamental_freq > 1000 and len(peak_indices) > 1:
        for idx in peak_indices[1:]:
            if freqs[idx] < fundamental_freq * 0.7:  # Check if it's significantly lower
                # Check if it's possibly a sub-harmonic
                ratio = fundamental_freq / freqs[idx]
                if 1.8 < ratio < 2.2 or 2.8 < ratio < 3.2:
                    fundamental_freq = freqs[idx]
                    fund_idx = idx
                    break
    
    # Plot if requested
    if plot:
        plt.figure(figsize=(12, 6))
        plt.plot(freqs, fft_data)
        plt.scatter(freqs[fund_idx], fft_data[fund_idx], color='red', s=100)
        plt.xlim(0, 2000)  # Limit x-axis to 2 kHz for visibility
        plt.xlabel('Frequency (Hz)')
        plt.ylabel('Magnitude')
        plt.title(f'FFT Spectrum - Fundamental: {fundamental_freq:.2f} Hz')
        plt.grid(True)
        plt.tight_layout()
        plt.show()
    
    return fundamental_freq

def get_nearest_midi_note(frequency):
    """Convert frequency to nearest MIDI note number"""
    if frequency <= 0:
        return None
    
    midi_note = 69 + 12 * np.log2(frequency / 440.0)
    return round(midi_note)

def analyze_wav_files(directory):
    """
    Analyze all WAV files in the directory and determine their fundamental frequencies.
    
    Args:
        directory: Directory containing WAV files
        
    Returns:
        List of (filename, frequency, midi_note) tuples, sorted by filename
    """
    # Find all WAV files
    wav_files = [f for f in os.listdir(directory) if f.lower().endswith('.wav')]
    
    if not wav_files:
        print(f"No WAV files found in {directory}")
        return []
    
    results = []
    
    for filename in wav_files:
        filepath = os.path.join(directory, filename)
        
        try:
            # Load the audio file
            data, sample_rate = sf.read(filepath)
            
            # Convert to mono if stereo
            if data.ndim > 1:
                data = data.mean(axis=1)
            
            # Get fundamental frequency
            fundamental_freq = estimate_fundamental_frequency(data, sample_rate)
            
            # Get nearest MIDI note
            midi_note = get_nearest_midi_note(fundamental_freq)
            
            # Extract declared MIDI note from filename if available
            declared_midi = None
            try:
                declared_midi = int(filename.split('_')[0])
            except (ValueError, IndexError):
                pass
            
            results.append((filename, fundamental_freq, midi_note, declared_midi))
            
            print(f"Analyzed {filename}:")
            print(f"  Fundamental frequency: {fundamental_freq:.2f} Hz")
            print(f"  Nearest MIDI note: {midi_note} ({get_note_name(midi_note)})")
            if declared_midi is not None:
                print(f"  Declared MIDI note in filename: {declared_midi}")
                if midi_note != declared_midi:
                    print(f"  DISCREPANCY DETECTED! Actual note appears to be: {get_note_name(midi_note)}")
            print()
            
        except Exception as e:
            print(f"Error analyzing {filename}: {e}")
    
    # Sort results by filename
    results.sort(key=lambda x: x[0])
    
    return results

def get_note_name(midi_note):
    """Convert MIDI note number to note name (e.g., 60 -> C4)"""
    if midi_note is None:
        return "Unknown"
    
    notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
    octave = (midi_note // 12) - 1
    note = notes[midi_note % 12]
    return f"{note}{octave}"

def main():
    directory = "midi/sf2/loops"
    print(f"Analyzing WAV files in {directory}...\n")
    
    results = analyze_wav_files(directory)
    
    # Write results to a CSV file
    output_file = "midi/sf2/loops_analysis.csv"
    with open(output_file, 'w') as f:
        f.write("Filename,Detected Frequency (Hz),Detected MIDI Note,Detected Note Name,Declared MIDI Note,Match?\n")
        for filename, freq, midi_note, declared_midi in results:
            match = "Yes" if declared_midi is None or midi_note == declared_midi else "No"
            f.write(f"{filename},{freq:.2f},{midi_note},{get_note_name(midi_note)},{declared_midi if declared_midi is not None else 'N/A'},{match}\n")
    
    print(f"\nAnalysis complete. Results saved to {output_file}")
    
    # Print summary of discrepancies
    discrepancies = [(filename, declared_midi, midi_note) 
                     for filename, _, midi_note, declared_midi in results 
                     if declared_midi is not None and midi_note != declared_midi]
    
    if discrepancies:
        print("\nDiscrepancies between filename and detected note:")
        print("Filename, Declared, Detected, Difference")
        for filename, declared, detected in discrepancies:
            difference = detected - declared
            print(f"{filename}, {declared} ({get_note_name(declared)}), {detected} ({get_note_name(detected)}), {difference:+d} semitones")

if __name__ == "__main__":
    main()