def load_samples(samples_dir, inc_file):
    """
    Scan 'samples_dir' for .wav files named *_PPP.wav, where PPP is pitch.
    Returns two lists of assembly lines: sample_dictionary and sample_filenames.
    """
    import os, re

    files = sorted(f for f in os.listdir(samples_dir) if f.lower().endswith('.wav'))
    sample_dictionary = []
    sample_filenames = []
    for fname in files:
        m = re.search(r'_(\d{3})\.wav$', fname)
        if not m:
            continue
        ppp = m.group(1)
        # dictionary entry: dl fn_PPP, db PPP
        sample_dictionary.append(f"    dl fn_{ppp}")
        sample_dictionary.append(f"    db {int(ppp)}")
        # filename entry with label: fn_PPP: asciz "samples/<fname>"
        sample_filenames.append(f"    fn_{ppp}:    asciz \"samples/{fname}\"")

    # Open output file for writing
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
    samples_dir = 'midi/tgt/samples'
    inc_file = f"midi/src/asm/samples.inc"

    load_samples(samples_dir, inc_file)