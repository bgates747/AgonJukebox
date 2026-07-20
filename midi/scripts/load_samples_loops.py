def load_samples(samples_dir, inc_file, instrument):
    """
    Scan 'samples_dir' for .wav files named PPP.wav.
    Writes sample_dictionary and sample_filenames tables to 'inc_file'.
    Includes frequency (Hz), pitch (MIDI), and note name information in each entry.
    """
    import os, re
    
    def midi_to_hz(midi_pitch):
        """Convert MIDI pitch (0-127) to frequency in Hz"""
        return 440.0 * (2.0 ** ((midi_pitch - 69) / 12.0))
    
    def midi_to_note_name(midi_pitch):
        """Convert MIDI note number to note name (e.g., 60 -> C4)"""
        notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
        octave = (midi_pitch // 12) - 1
        note = notes[midi_pitch % 12]
        return f"{note}{octave}"
    
    files = sorted(f for f in os.listdir(samples_dir) if f.lower().endswith('.wav'))
    sample_dictionary = []
    sample_filenames = []
    
    for fname in files:
        m = re.search(r'(\d{3})\.wav$', fname)
        if not m:
            continue
            
        ppp = m.group(1)
        midi_pitch = int(ppp)
        frequency = midi_to_hz(midi_pitch)
        note_name = midi_to_note_name(midi_pitch)
        
        # Convert frequency to an integer value
        frequency_int = int(round(frequency))
        
        # Create the frequency_pitch value (frequency in low 2 bytes, pitch in upper byte)
        # Format: 0xPPFFFF where PP is pitch and FFFF is frequency
        freq_pitch_hex = (midi_pitch << 16) | (frequency_int & 0xFFFF)
        
        # Create the combined entry with hex and decimal values, plus note name
        sample_dictionary.append(f" dl fn_{ppp}, 0x{freq_pitch_hex:06X} ; freq={frequency_int} Hz, pitch={midi_pitch} ({note_name})")
        
        sample_filenames.append(f" fn_{ppp}: asciz \"{instrument}/{fname}\"")
    
    with open(inc_file, 'w') as f:
        f.write(f"\nnum_samples: equ {len(sample_filenames)}\n\n")
        f.write("; Sample dictionary (pointer, frequency/pitch)\n")
        f.write("; Format: pointer, 0xPPFFFF (PP=MIDI pitch, FFFF=frequency in Hz)\n")
        f.write("sample_dictionary:\n")
        for line in sample_dictionary:
            f.write(f"{line}\n")
        f.write("\n; Sample filename strings\n")
        f.write("sample_filenames:\n")
        for line in sample_filenames:
            f.write(f"{line}\n")

if __name__ == '__main__':
    instrument = 'piano_yamaha'
    samples_dir = f"midi/tgt/{instrument}"
    inc_file = f"midi/src/asm/samples_{instrument}.inc"
    load_samples(samples_dir, inc_file, instrument)