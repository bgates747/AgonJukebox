def load_samples(samples_dir, inc_file, instrument):
    """
    Scan 'samples_dir' for .wav files named *_PPP.wav or PPP.wav.
    Writes sample_dictionary and sample_filenames tables to 'inc_file'.
    Emits paths like 'instrument/PPP.wav' (e.g., 'harpsichord/048.wav').
    """
    import os, re

    files = sorted(f for f in os.listdir(samples_dir) if f.lower().endswith('.wav'))
    sample_dictionary = []
    sample_filenames = []

    for fname in files:
        m = re.search(r'(\d{3})\.wav$', fname)
        if not m:
            continue
        ppp = m.group(1)
        sample_dictionary.append(f"    dl fn_{ppp}")
        sample_dictionary.append(f"    db {int(ppp)}")
        sample_filenames.append(f"    fn_{ppp}:    asciz \"{instrument}/{fname}\"")

    with open(inc_file, 'w') as f:
        f.write(f"\nnum_samples:    equ {len(sample_filenames)}\n\n")

        f.write("; Sample dictionary (pointer, bufferId)\n")
        f.write("sample_dictionary:\n")
        for line in sample_dictionary:
            f.write(f"{line}\n")

        f.write("\n; Sample filename strings\n")
        f.write("sample_filenames:\n")
        for line in sample_filenames:
            f.write(f"{line}\n")

if __name__ == '__main__':
    instrument   = 'piano_yamaha'
    samples_dir  = f"midi/tgt/{instrument}"
    inc_file     = f"midi/src/asm/samples_{instrument}.inc"

    load_samples(samples_dir, inc_file, instrument)
