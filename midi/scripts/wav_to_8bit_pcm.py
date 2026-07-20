import os
import re
import numpy as np
import soundfile as sf
from scipy import signal

def convert_wavs_to_8bit_pcm(source_dir, dest_dir, target_sample_rate):
    """
    Convert all WAV files in source_dir to 8-bit PCM mono and rename them
    to just the pitch number (as a 3-digit number) with the .wav extension.
    
    Args:
        source_dir: Directory containing source WAV files
        dest_dir: Directory to save converted WAV files
        target_sample_rate: If provided, resample audio to this rate (in Hz)
    
    Returns:
        List of paths to converted files
    """
    # Create destination directory if it doesn't exist
    os.makedirs(dest_dir, exist_ok=True)
    
    # Find all .wav files in the source directory
    wav_files = [f for f in os.listdir(source_dir) if f.lower().endswith('.wav')]
    
    if not wav_files:
        print(f"No WAV files found in {source_dir}")
        return []
    
    converted_files = []
    
    for filename in wav_files:
        source_path = os.path.join(source_dir, filename)
        
        # Extract pitch number from filename
        # Assume pitch is the first number in the filename
        match = re.search(r'^(\d+)', filename)
        if match:
            pitch = int(match.group(1))
            new_filename = f"{pitch:03d}.wav"  # Format as 3-digit with leading zeros
        else:
            # If we can't find a pitch number, just use the original filename
            print(f"Warning: Could not extract pitch from {filename}, keeping original name")
            new_filename = filename
        
        dest_path = os.path.join(dest_dir, new_filename)
        
        # Check if destination file already exists
        if os.path.exists(dest_path):
            print(f"Warning: Destination file {new_filename} already exists, skipping")
            continue
        
        try:
            # Load audio file
            data, sample_rate = sf.read(source_path)
            
            # Convert to mono if stereo
            if data.ndim > 1:
                data = data.mean(axis=1)
            
            # Resample if target_sample_rate is specified and different from source
            if target_sample_rate and target_sample_rate != sample_rate:
                # Calculate number of samples in resampled audio
                num_samples = int(len(data) * target_sample_rate / sample_rate)
                
                # Resample data
                data = signal.resample(data, num_samples)
                print(f"Resampled {filename} from {sample_rate}Hz to {target_sample_rate}Hz")
                sample_rate = target_sample_rate
            
            # Normalize before converting to 8-bit
            peak = np.max(np.abs(data))
            if peak > 0:
                data = data / peak
            
            # Save as 8-bit PCM with the new filename
            sf.write(dest_path, data, sample_rate, subtype='PCM_U8')
            
            print(f"Converted {filename} to {new_filename} (8-bit PCM mono at {sample_rate}Hz)")
            converted_files.append(dest_path)
            
        except Exception as e:
            print(f"Error converting {filename}: {e}")
    
    print(f"Converted {len(converted_files)} files to 8-bit PCM mono in {dest_dir}")
    return converted_files

if __name__ == "__main__":
    # source_dir = "midi/sf2/loops"
    source_dir = "midi/sf2/samples"
    dest_dir = "midi/tgt/piano_yamaha"
    target_sample_rate = 32000

    convert_wavs_to_8bit_pcm(source_dir, dest_dir, target_sample_rate)