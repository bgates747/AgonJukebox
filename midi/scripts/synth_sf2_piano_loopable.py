import os, numpy as np, soundfile as sf, fluidsynth

SAMPLE_RATE   = 44000
NOTE          = 69      # A4
DURATION      = 5.0     # seconds
LOOP_START_SEC= 2.0
LOOP_LEN_SEC  = 1.0

SF2_PATH = (
    "/home/smith/Agon/mystuff/assets/sound/sf2/"
    "Top 18 Free Piano Soundfonts/Full Grand.sf2"
)
OUTPUT_WAV    = "midi/tgt/sf2/A4.wav"

def get_loopable_wav(sf2_path, outfile):
    fs = fluidsynth.Synth(samplerate=SAMPLE_RATE)
    fs.setting('synth.gain', 0.8)
    sfid = fs.sfload(sf2_path)
    fs.program_select(0, sfid, 0, 0)

    num_samples = int(SAMPLE_RATE * DURATION)
    fs.noteon(0, NOTE, 127)
    audio = np.array(fs.get_samples(num_samples), dtype=np.float32)
    fs.noteoff(0, NOTE)
    fs.delete()

    # mono
    if audio.size == num_samples * 2:
        audio = audio.reshape(-1,2).mean(axis=1)

    # extract loop
    start = int(SAMPLE_RATE * LOOP_START_SEC)
    end   = start + int(SAMPLE_RATE * LOOP_LEN_SEC)
    loop  = audio[start:end]

    # normalize loop
    peak = np.max(np.abs(loop))
    if peak > 0:
        loop /= peak

    os.makedirs(os.path.dirname(outfile), exist_ok=True)
    sf.write(outfile, loop, SAMPLE_RATE, subtype='PCM_U8')
    print(f"Saved: {outfile}")

get_loopable_wav(SF2_PATH, OUTPUT_WAV)
