#!/usr/bin/env python3
import os
import sys
import numpy as np
import soundfile as sf
from scipy import signal

def generate_pitched_sample(source_loop_path, midi_source_pitch, midi_target_pitch, 
                           attack_ms, decay_ms, sustain_level, release_ms, 
                           target_volume, duration_ms, output_dir):
    """
    Generate a new pitched sample from a loop file with ADSR envelope.
    Follows the target system's ADSR behavior.
    
    Args:
        source_loop_path: Path to the source loop file
        midi_source_pitch: MIDI note number of the source loop
        midi_target_pitch: MIDI note number for the target pitch
        attack_ms: Attack time in milliseconds
        decay_ms: Decay time in milliseconds
        sustain_level: Sustain level (0-127)
        release_ms: Release time in milliseconds
        target_volume: Base/target volume level (0-127)
        duration_ms: Note duration in milliseconds
        output_dir: Directory to save the output file
    """
    # Create output directory
    os.makedirs(output_dir, exist_ok=True)
    
    # Normalize volume and sustain level
    if target_volume <= 0:
        print("Warning: Target volume is zero or negative, no sound will be produced")
        target_volume_normalized = 0
    else:
        target_volume_normalized = min(target_volume, 127) / 127.0
    
    sustain_normalized = max(0, min(sustain_level, 127)) / 127.0
    
    # Calculate final sustain level according to target system formula
    actual_sustain_level = (target_volume_normalized * sustain_level) / 127.0
    
    # Convert milliseconds to seconds for internal processing
    attack = attack_ms / 1000.0
    decay = decay_ms / 1000.0
    release = release_ms / 1000.0
    duration = duration_ms / 1000.0 if duration_ms is not None else None
    
    # Read the source loop
    try:
        loop_audio, sample_rate = sf.read(source_loop_path)
        
        # Convert to mono if stereo
        if len(loop_audio.shape) > 1 and loop_audio.shape[1] > 1:
            loop_audio = np.mean(loop_audio, axis=1)
        
        # Calculate pitch shift ratio
        semitones = midi_target_pitch - midi_source_pitch
        pitch_ratio = 2 ** (semitones / 12.0)
        
        # Calculate timing based on target system's rules
        attack_end_ms = attack_ms
        decay_end_ms = attack_ms + decay_ms
        minimum_duration_ms = decay_end_ms  # According to docs, note always plays at least attack+decay
        
        # Determine actual duration
        if duration_ms is None or duration_ms < minimum_duration_ms:
            actual_duration_ms = minimum_duration_ms
        else:
            actual_duration_ms = duration_ms
        
        # Add release phase to get the total sound duration
        total_duration_ms = actual_duration_ms + release_ms
        total_duration = total_duration_ms / 1000.0
        total_samples = int(total_duration * sample_rate)
        
        # Generate envelope according to target system rules
        envelope = create_target_adsr_envelope(
            total_samples, sample_rate, 
            attack_ms, decay_ms, actual_sustain_level, 
            release_ms, actual_duration_ms, 
            target_volume_normalized
        )
        
        # Resample the loop to the new pitch
        source_samples_needed = int(total_samples / pitch_ratio)
        
        # Create a buffer that repeats the loop as many times as needed
        repeats = int(np.ceil(source_samples_needed / len(loop_audio)))
        source_buffer = np.tile(loop_audio, repeats)[:source_samples_needed]
        
        # Resample the source buffer
        resampled = signal.resample(source_buffer, total_samples)
        
        # Apply envelope
        output_audio = resampled * envelope
        
        # Normalize to a consistent level if target_volume is non-zero
        if target_volume > 0:
            peak = np.max(np.abs(output_audio))
            if peak > 0:
                # Normalize to target volume level
                output_audio = output_audio * target_volume_normalized / peak
        
        # Generate output filename based on target pitch
        target_note_name = midi_to_note_name(midi_target_pitch)
        output_filename = f"{midi_target_pitch:03d}_{target_note_name}.wav"
        output_path = os.path.join(output_dir, output_filename)
        
        # Save as 32-bit float WAV
        sf.write(output_path, output_audio, sample_rate, subtype="FLOAT")
        
        print(f"Generated pitched sample: {output_filename}")
        print(f"  Source pitch: MIDI {midi_source_pitch} ({midi_to_note_name(midi_source_pitch)})")
        print(f"  Target pitch: MIDI {midi_target_pitch} ({target_note_name})")
        print(f"  Semitones shift: {semitones:+.1f}")
        print(f"  Target volume: {target_volume}/127")
        print(f"  Envelope: Attack={attack_ms}ms, Decay={decay_ms}ms, Sustain={sustain_level}/127, Release={release_ms}ms")
        print(f"  Note duration: {actual_duration_ms}ms (actual), {duration_ms}ms (requested)")
        print(f"  Total sound duration: {total_duration_ms}ms")
        print(f"  Saved to: {output_path}")
        
        return {
            "source_file": os.path.basename(source_loop_path),
            "output_file": output_filename,
            "source_pitch": midi_source_pitch,
            "target_pitch": midi_target_pitch,
            "semitones_shift": semitones,
            "target_volume": target_volume,
            "duration_ms": {
                "requested": duration_ms,
                "actual": actual_duration_ms,
                "total": total_duration_ms
            },
            "adsr": {
                "attack_ms": attack_ms, 
                "decay_ms": decay_ms, 
                "sustain": sustain_level, 
                "release_ms": release_ms
            },
            "sample_rate": sample_rate
        }
        
    except Exception as e:
        print(f"Error processing {source_loop_path}: {e}")
        import traceback
        traceback.print_exc()
        return None

def create_target_adsr_envelope(num_samples, sample_rate, attack_ms, decay_ms, 
                               sustain_level, release_ms, duration_ms, peak_level=1.0):
    """
    Create an ADSR envelope with the following behavior:
    - If duration < (attack + decay + release), the phases are proportionally shortened
      but all three phases (attack, decay, release) are always present
    - If duration > (attack + decay + release), the extra time is filled with sustain phase
    """
    # Convert to seconds for sample calculations
    attack = attack_ms / 1000.0
    decay = decay_ms / 1000.0
    release = release_ms / 1000.0
    duration = duration_ms / 1000.0
    
    # Calculate minimum duration (attack + decay + release)
    min_duration = attack + decay + release
    
    # Calculate how many samples we need for the entire envelope
    total_samples = int(duration * sample_rate)
    
    # Calculate number of samples for each phase
    if duration < min_duration and duration > 0:
        # Scale all phases proportionally if duration is less than minimum
        ratio = duration / min_duration
        attack_samples = int(attack * sample_rate * ratio)
        decay_samples = int(decay * sample_rate * ratio)
        release_samples = int(release * sample_rate * ratio)
        sustain_samples = 0
    else:
        # Regular timing - full attack and decay, with sustain filling the remainder
        attack_samples = int(attack * sample_rate)
        decay_samples = int(decay * sample_rate)
        release_samples = int(release * sample_rate)
        sustain_samples = total_samples - attack_samples - decay_samples - release_samples
    
    # Ensure each phase has at least 1 sample if total_samples > 0
    if total_samples > 0:
        if attack_samples <= 0:
            attack_samples = 1
        if decay_samples <= 0:
            decay_samples = 1
        if release_samples <= 0:
            release_samples = 1
        
        # Recalculate sustain samples after ensuring minimums
        sustain_samples = max(0, total_samples - attack_samples - decay_samples - release_samples)
    
    # Create envelope segments
    attack_env = np.linspace(0, peak_level, attack_samples) if attack_samples > 0 else np.array([])
    decay_env = np.linspace(peak_level, sustain_level, decay_samples) if decay_samples > 0 else np.array([])
    sustain_env = np.ones(sustain_samples) * sustain_level if sustain_samples > 0 else np.array([])
    release_env = np.linspace(sustain_level, 0, release_samples) if release_samples > 0 else np.array([])
    
    # Combine segments
    envelope = np.concatenate([attack_env, decay_env, sustain_env, release_env])
    
    # Ensure envelope is exactly the right length
    if len(envelope) < num_samples:
        envelope = np.pad(envelope, (0, num_samples - len(envelope)), 'constant', constant_values=(0, 0))
    elif len(envelope) > num_samples:
        envelope = envelope[:num_samples]
    
    return envelope

def midi_to_note_name(midi_number):
    """Convert MIDI note number to note name (e.g., 60 -> C4)"""
    notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
    octave = (midi_number // 12) - 1
    note = notes[midi_number % 12]
    return f"{note}{octave}"

def find_closest_loop(loops_dir, target_midi_pitch):
    """Find the closest available loop file to the target pitch"""
    if not os.path.exists(loops_dir):
        print(f"Error: Loops directory {loops_dir} not found")
        return None, None
    
    # Get all loop files
    loop_files = [f for f in os.listdir(loops_dir) if f.endswith('_loop.wav')]
    
    if not loop_files:
        print(f"Error: No loop files found in {loops_dir}")
        return None, None
    
    # Extract MIDI numbers from filenames
    loops_with_midi = []
    for file in loop_files:
        try:
            midi_num = int(file.split('_')[0])
            loops_with_midi.append((midi_num, file))
        except (ValueError, IndexError):
            continue
    
    if not loops_with_midi:
        print("Error: Could not extract MIDI numbers from loop filenames")
        return None, None
    
    # Find closest match
    closest = min(loops_with_midi, key=lambda x: abs(x[0] - target_midi_pitch))
    return closest[0], os.path.join(loops_dir, closest[1])

def append_to_log(info, log_path):
    """Append synthesis information to a log file"""
    with open(log_path, "a") as f:
        f.write("\n--- Generated Sample ---\n")
        f.write(f"Source: {info['source_file']}\n")
        f.write(f"Target: {info['output_file']}\n")
        f.write(f"Pitch shift: {info['semitones_shift']:+.1f} semitones\n")
        f.write(f"Volume: {info['target_volume']}/127\n")
        f.write(f"ADSR: A={info['adsr']['attack_ms']}ms, D={info['adsr']['decay_ms']}ms, S={info['adsr']['sustain']}/127, R={info['adsr']['release_ms']}ms\n")
        f.write(f"Duration: {info['duration_ms']['requested']}ms (requested), {info['duration_ms']['actual']}ms (actual), {info['duration_ms']['total']}ms (total)\n")
        f.write("---------------------\n")
    
    print(f"Details added to {log_path}")

if __name__ == "__main__":
    # Set all parameters explicitly to match target system
    
    # Required parameters
    target_pitch = 60  # MIDI note to generate (middle C)
    
    # Source loop parameters - if both are None, the closest loop will be found automatically
    source_loop_path = None  # Path to specific loop file, or None to auto-select
    source_pitch = None      # MIDI note of the source, required if source_loop_path is specified
    
    # Target system parameters
    target_volume = 127       # Base/target volume (0-127)
    
    # ADSR envelope parameters (all matching target system)
    attack_ms = 25     # Attack time in milliseconds
    decay_ms = 300      # Decay time in milliseconds
    sustain_level = 32  # Sustain level (0-127)
    release_ms = 600   # Release time in milliseconds
    
    # Duration
    duration_ms = 2000  # Note duration in milliseconds
    
    # Directories
    loops_dir = "midi/sf2/loops"
    output_dir = "midi/sf2/synth"
    log_path = "midi/sf2/synth_log.txt"
    
    # Create output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)
    
    # Determine source loop
    if source_loop_path is None or source_pitch is None:
        print("Finding closest available loop for target pitch...")
        source_pitch, source_loop_path = find_closest_loop(loops_dir, target_pitch)
        if not source_loop_path:
            print("Error: Could not find a suitable source loop")
            sys.exit(1)
    
    # Generate the pitched sample
    print(f"Generating pitched sample from {os.path.basename(source_loop_path)}...")
    result = generate_pitched_sample(
        source_loop_path, source_pitch, target_pitch,
        attack_ms, decay_ms, sustain_level, release_ms,
        target_volume, duration_ms, output_dir
    )
    
    # Log the result
    if result:
        append_to_log(result, log_path)
        
        # Play the generated sample
        try:
            # Import pydub for audio playback
            from pydub import AudioSegment
            from pydub.playback import play
            
            # Load the generated file
            sound_file = os.path.join(output_dir, result['output_file'])
            print(f"Playing {result['output_file']}...")
            
            # Load and play the audio
            sound = AudioSegment.from_wav(sound_file)
            play(sound)
            
        except ImportError:
            print("Note: Install pydub to enable audio playback (pip install pydub)")
        except Exception as e:
            print(f"Playback error: {e}")
            
        print("Done!")
    else:
        print("Failed to generate pitched sample")
        sys.exit(1)