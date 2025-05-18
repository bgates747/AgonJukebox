import os
import soundfile as sf
import subprocess
import numpy as np

from csv_to_apr import InstrumentDefs, make_single_note_pm, render_sample, normalize_audio

def envelope_trim(wav, threshold=0.01, window_ms=5, sr=32000):
    window_len = int(window_ms * sr / 1000)
    if window_len < 1:
        window_len = 1
    abs_wav = np.abs(wav)
    env = np.convolve(abs_wav, np.ones(window_len)/window_len, mode='same')
    peak = np.max(env)
    gate = threshold * peak
    idx = np.where(env > gate)[0]
    if len(idx) == 0:
        return wav[:1]  # All silence
    start, end = idx[0], idx[-1]

    # Find nearest zero-crossings
    def find_zero_cross(arr, from_idx, direction):
        i = from_idx
        while 0 < i < len(arr)-1:
            if arr[i-1]*arr[i] <= 0:
                return i
            i += direction
        return from_idx

    start_zc = find_zero_cross(wav, start, -1)
    end_zc   = find_zero_cross(wav, end, +1)
    return wav[start_zc:end_zc+1]

def test_render_sample_for_instrument(instrument_defs, midi_pitch, duration_ms, samples_base_dir, trim=True):
    defs = InstrumentDefs(instrument_defs.strip())
    row = defs.rows[0]
    sfn = row['sf_instrument_name']
    bank = int(row['bank'])
    preset = int(row['preset'])
    vel = int(row['velocity'])
    native_sr = int(row['sample_rate'])
    sf2_path = row['sf2_path']
    is_drum = row.get('is_drum', False)
    if isinstance(is_drum, str):
        is_drum = is_drum.strip().upper() == "TRUE"

    duration_s = duration_ms / 1000.0

    pm = make_single_note_pm(midi_pitch, duration_s, vel, preset, bank=bank, is_drum=is_drum)
    wav, sr = render_sample(sf2_path, pm, native_sr)

    # Normalize before trimming
    wav = normalize_audio(wav)

    # Optional: trim envelope and to zero-crossings
    if trim:
        wav_orig_len = len(wav)
        wav = envelope_trim(wav, threshold=0.01, window_ms=5, sr=sr)
        print(f"Trimmed {midi_pitch}: {wav_orig_len/sr:.3f}s -> {len(wav)/sr:.3f}s")

    out_dir = defs.folder_for_sf(samples_base_dir, sfn)
    os.makedirs(out_dir, exist_ok=True)
    out_path = os.path.join(out_dir, f"{midi_pitch:03d}.wav")
    sf.write(out_path, wav, sr, subtype='PCM_U8')
    print(f"Test sample written to {out_path} (sr={sr}Hz, dur≈{len(wav)/sr:.3f}s, is_drum={is_drum}, size={os.path.getsize(out_path)} bytes)")

    try:
        subprocess.run(['aplay', out_path], check=True)
    except FileNotFoundError:
        print("Playback skipped: 'aplay' not found. You can manually play the file.")

if __name__ == '__main__':
    samples_base_dir = 'midi/tgt/Samples_Test'

    instrument_defs = """
instrument_number,midi_instrument_name,bank,preset,is_drum,sf_instrument_name,velocity,sample_rate,sf2_path
12,Drum Kit,128,0,TRUE,Standard,127,32000,midi/sf2/FluidR3_GM/FluidR3_GM.sf2
    """

    duration_ms = 5000
    midi_pitches = [38,46,48,49,51,57,59]

    for midi_pitch in midi_pitches:
        test_render_sample_for_instrument(instrument_defs, midi_pitch, duration_ms, samples_base_dir, trim=True)
