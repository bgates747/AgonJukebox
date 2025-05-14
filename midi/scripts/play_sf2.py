#!/usr/bin/env python3
import time
import fluidsynth

# 1) Instantiate Synth (not FluidSynth)
fs = fluidsynth.Synth()

# 2) Start audio output (default ALSA on Linux)
fs.start(driver="alsa")

# 3) Load your SoundFont
sfid = fs.sfload(
    "/home/smith/Agon/mystuff/assets/sound/sf2/"
    "Top 18 Free Piano Soundfonts/Piano.sf2"
)

# 4) Select bank=0, preset=0 on channel 0
fs.program_select(0, sfid, bank=0, preset=0)

# 5) Play a note (middle C = 60) at velocity 100
fs.noteon(0, 60, 100)
time.sleep(1.0)
fs.noteoff(0, 60)

# 6) Shut down cleanly
fs.delete()
