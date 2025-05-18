import os
import soundfile as sf
import subprocess

from csv_to_apr import InstrumentDefs, make_single_note_pm, render_sample

def test_render_sample_for_instrument(instrument_defs,midi_pitch,duration_ms,samples_base_dir):
    defs = InstrumentDefs(instrument_defs.strip())
    row    = defs.rows[0]
    sfn    = row['soundfont_name']
    bank   = int(row['bank'])
    preset = int(row['preset'])
    vel    = int(row['velocity'])
    native_sr = int(row['sample_rate'])
    sf2_path  = row['sf2_path']

    duration_s = duration_ms / 1000.0
    pm = make_single_note_pm(midi_pitch,duration_s,vel,preset,bank=bank,is_drum=False)

    wav, sr = render_sample(sf2_path, pm, native_sr)

    out_dir = defs.folder_for_sf(samples_base_dir, sfn)
    os.makedirs(out_dir, exist_ok=True)
    out_path = os.path.join(out_dir, f"{midi_pitch:03d}.wav")
    sf.write(out_path, wav, sr, subtype='PCM_U8')
    print(f"Test sample written to {out_path} (sr={sr}Hz, dur≈{len(wav)/sr:.3f}s)")

    try:
        subprocess.run(['aplay', out_path], check=True)
    except FileNotFoundError:
        print("Playback skipped: 'aplay' not found. You can manually play the file.")



if __name__ == '__main__':
    # ---- Configuration and Metadata ----
    samples_base_dir = 'midi/tgt/Samples_Test'

    instrument_defs = """
instrument_number,instrument_name,bank,preset,soundfont_name,velocity,sample_rate,sf2_path
3,Pizzicato Strings,0,45,Pizzicato Section,127,32000,/home/smith/Agon/mystuff/assets/sound/sf2/FluidR3_GM/FluidR3_GM.sf2
    """

    duration_ms =50
    release_ms=0
    duration_ms += release_ms
    midi_pitch = 60

    test_render_sample_for_instrument(instrument_defs,midi_pitch,duration_ms,samples_base_dir)