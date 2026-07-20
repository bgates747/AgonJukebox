#!/usr/bin/env python3
import os
import numpy as np
import soundfile as sf
import fluidsynth
from scipy.fft import fft, fftfreq
from pydub import AudioSegment
from pydub.playback import play

# ─── helpers ──────────────────────────────────────────────────────────────
def ensure_dir(path: str):
    os.makedirs(path, exist_ok=True)

def wav_name(tag: str, midi: int, base_dir: str) -> str:
    return os.path.join(base_dir, f"{tag}_{midi}.wav")

def save_wave(wave: np.ndarray, tag: str, midi: int, sr: int, base_dir: str):
    fname = wav_name(tag, midi, base_dir)
    ensure_dir(base_dir)
    sf.write(fname, wave, sr)
    print(f"✓ saved {fname}")

# ─── 1. render full note ─────────────────────────────────────────────────
def render_note_from_sf2(sf2_path: str, midi: int, sr: int, duration_ms: int) -> np.ndarray:
    fs = fluidsynth.Synth(samplerate=sr)
    fs.setting("synth.gain", 0.8)
    sfid = fs.sfload(sf2_path)
    fs.program_select(0, sfid, 0, 0)

    n = int(sr * duration_ms / 1000)
    fs.noteon(0, midi, 127)
    raw = np.array(fs.get_samples(n), dtype=np.float32)
    fs.noteoff(0, midi)
    fs.delete()

    # stereo → mono
    if raw.size == n * 2:
        raw = raw.reshape(-1, 2).mean(axis=1)

    # normalise (helps FFT S/N)
    peak = np.abs(raw).max()
    if peak > 0:
        raw /= peak
    return raw

# ─── 2. take subsample window ──────────────────────────────────────────────
def extract_window(full: np.ndarray, sr: int, start_ms: int, length_ms: int) -> np.ndarray:
    st = int(sr * start_ms  / 1000)
    ed = st + int(sr * length_ms / 1000)
    return full[st:ed]

# ─── 3. additive re-synthesis from top partials ──────────────────────────
def synth_from_fft(seg: np.ndarray, sr: int, top_n: int, out_ms: int) -> np.ndarray:
    N = len(seg)
    yf = np.abs(fft(seg))
    xf = fftfreq(N, 1/sr)

    pos = xf >= 0
    xf, yf = xf[pos], yf[pos]

    idx = np.argsort(yf)[::-1][:top_n]
    freqs = xf[idx]
    mags  = yf[idx]
    base  = mags[0]
    partials = [(m/base, f) for m, f in zip(mags, freqs)]

    t = np.linspace(0, out_ms/1000, int(sr*out_ms/1000), endpoint=False)
    out = np.zeros_like(t, dtype=np.float32)
    for amp, f in partials:
        out += amp * np.sin(2*np.pi*f*t)

    peak = np.abs(out).max()
    if peak > 0:
        out /= peak
    return out


def resynth_harmonic_buckets(
    seg: np.ndarray,
    sr: int,
    max_harmonics: int,
    out_ms: int
) -> np.ndarray:
    """
    Reduce your FFT to the first `max_harmonics` harmonics of the
    strongest fundamental. Prints each harmonic's target freq
    and its averaged magnitude, then returns a normalized sum of
    those harmonics over `out_ms` milliseconds.
    """
    # 1) Compute one-sided spectrum
    N  = len(seg)
    yf = np.abs(fft(seg))
    xf = fftfreq(N, 1/sr)
    pos = xf > 0
    xf, yf = xf[pos], yf[pos]

    # 2) Find fundamental (largest peak)
    idx0    = np.argmax(yf)
    f0      = xf[idx0]
    base_mag= yf[idx0]
    print(f"Fundamental: {f0:.2f} Hz (mag {base_mag:.3f})\n")

    # 3) Bucket into harmonics 1..max_harmonics
    bucket_mags = []
    for k in range(1, max_harmonics+1):
        lo = (k - 0.5) * f0
        hi = (k + 0.5) * f0
        idxs = np.where((xf >= lo) & (xf < hi))[0]
        mags_k = yf[idxs]
        avg_mag = float(np.mean(mags_k)) if mags_k.size else 0.0
        bucket_mags.append(avg_mag)
        print(f"Harmonic {k}: target {k*f0:.2f} Hz → avg_mag = {avg_mag:.3f}")

    # 4) Build relative amplitudes (fundamental → 1.0)
    rel_amps = [
        (m / base_mag) if base_mag > 0 else 0.0
        for m in bucket_mags
    ]

    # 5) Synthesize the 3‐tone waveform
    t   = np.linspace(0, out_ms/1000, int(sr * out_ms/1000), endpoint=False)
    out = np.zeros_like(t, dtype=np.float32)
    for k, amp in enumerate(rel_amps, start=1):
        out += amp * np.sin(2 * np.pi * k * f0 * t)

    # 6) Normalize final output
    peak = np.max(np.abs(out))
    if peak > 0:
        out /= peak

    return out

def resynth_harmonic_buckets_phased(seg: np.ndarray, sr: int,
                                     max_harmonics: int, out_ms: int,
                                     phase_jitter_deg: float = 20.0) -> np.ndarray:
    """
    Like the harmonic bucket version, but adds slight phase variation
    to each harmonic to avoid sawtooth-like artifacts. Phase jitter is
    given in degrees (+/-).
    """
    N = len(seg)
    yf = np.abs(fft(seg))
    xf = fftfreq(N, 1/sr)
    xf, yf = xf[xf > 0], yf[xf > 0]

    idx0 = np.argmax(yf)
    f0 = xf[idx0]
    base_mag = yf[idx0]
    print(f"Fundamental: {f0:.2f} Hz (mag {base_mag:.3f})\n")

    rel_amps = []
    freqs = []
    phases = []

    for k in range(1, max_harmonics + 1):
        lo = (k - 0.5) * f0
        hi = (k + 0.5) * f0
        idxs = np.where((xf >= lo) & (xf < hi))[0]
        mags_k = yf[idxs]
        avg_mag = float(np.mean(mags_k)) if mags_k.size else 0.0
        amp = (avg_mag / base_mag) if base_mag > 0 else 0.0
        phase_deg = np.random.uniform(-phase_jitter_deg, phase_jitter_deg)
        phase_rad = np.deg2rad(phase_deg)

        print(f"H{k:<2} @ {k*f0:.2f} Hz  → amp = {amp:.3f}, phase = {phase_deg:+.1f}°")

        rel_amps.append(amp)
        freqs.append(k * f0)
        phases.append(phase_rad)

    t = np.linspace(0, out_ms / 1000, int(sr * out_ms / 1000), endpoint=False)
    out = np.zeros_like(t, dtype=np.float32)

    for amp, f, phase in zip(rel_amps, freqs, phases):
        out += amp * np.sin(2 * np.pi * f * t + phase)

    peak = np.abs(out).max()
    if peak > 0:
        out /= peak

    return out



# ─── 5. zero-cross alignment ────────────────────────────────────────────
def align_zero_cross(wave: np.ndarray, sr: int, target_ms: int,
                     search_pad: int = 50) -> np.ndarray:
    """
    Trim wave so that:
      start = first positive-going zero crossing
      end   = next positive-going zero crossing ≈ target_ms later
    search_pad (samples) widens the end search window ±pad
    """
    tgt_samples = int(sr * target_ms / 1000)
    N = len(wave)

    # --- find start crossing
    start = 0
    for i in range(min(1024, N-1)):
        if wave[i] <= 0 < wave[i+1]:
            start = i + 1
            break

    # --- search for end crossing near desired length
    desired_end = start + tgt_samples
    low  = max(start + 1, desired_end - search_pad)
    high = min(N-1, desired_end + search_pad)
    end = None
    for i in range(low, high):
        if wave[i] <= 0 < wave[i+1]:
            end = i + 1
            break
    if end is None:                     # fallback: first crossing after desired_end
        for i in range(desired_end, N-1):
            if wave[i] <= 0 < wave[i+1]:
                end = i + 1
                break
    if end is None:                     # still nothing? just slice desired length
        end = start + tgt_samples

    loop = wave[start:end]

    # final sanity normalise (should already be <1)
    pk = np.abs(loop).max()
    if pk > 0:
        loop /= pk
    return loop

if __name__ == "__main__":
    # ─── Individual Parameters ───────────────────────────────
    # sf2_path       = "/home/smith/Agon/mystuff/assets/sound/sf2/Top 18 Free Piano Soundfonts/Full Grand.sf2"
    sf2_path = "/home/smith/Agon/mystuff/assets/sound/sf2/Top 23 Free Strings Soundfonts/Strings.sf2"
    base_dir       = "midi/tgt/sf2"
    midi           = 69               # A4
    sr             = 44000           # Hz
    render_ms      = 1100            # full note render duration
    win_start_ms   = 0             # subsample window start (ms)
    win_len_ms     = 1100             # subsample window length (ms)
    top_partials   = 200              # FFT partials to retain
    loop_len_ms    = 1100             # loop target length (ms)
    preview_db     = -6               # playback preview attenuation

    # ─── Run pipeline ─────────────────────────────────────────
    full = render_note_from_sf2(sf2_path, midi, sr, render_ms)
    save_wave(full, "orig", midi, sr, base_dir)

    subsample = extract_window(full, sr, win_start_ms, win_len_ms)
    save_wave(subsample, "sub", midi, sr, base_dir)

    synth = synth_from_fft(subsample, sr, top_partials, loop_len_ms + 20)
    save_wave(synth, "synth", midi, sr, base_dir)

    # max_harmonics = 20
    # resynth = resynth_harmonic_buckets(subsample, sr, max_harmonics, loop_len_ms + 20)

    # resynth = resynth_harmonic_buckets_phased(
    #     subsample, sr, max_harmonics=20, out_ms=loop_len_ms, phase_jitter_deg=20.0
    # )
    # save_wave(resynth, "resynth", midi, sr, base_dir)


    loop = align_zero_cross(synth, sr, loop_len_ms)
    save_wave(loop, "loop", midi, sr, base_dir)

    # ─── Optional Playback ───────────────────────────────────
    play_path = wav_name("orig", midi, base_dir)
    seg = AudioSegment.from_file(play_path)
    play(seg + preview_db)
