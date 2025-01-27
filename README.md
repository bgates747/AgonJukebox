![Image](https://github.com/bgates747/AgonJukebox/blob/main/screenshot.png)
# AgonJukebox

... is an EZ80 assembly language application for the Agon Light family of retro-modern microcomputers. Audio is streamed from the Agon's SD card to the Video Display Processor (VDP) in one-second chunks, resulting in fast response to selecting files for playback and keeping memory requirements on the VDP to a minimum.

The program plays `.wav` files in **8-bit unsigned PCM**, monaural format at sample rates tested up to **48000 Hz**. See the **Utilities** section below for Python scripts which will aid you in preparing compatible files.

The ability to use `.wav` files instead of headerless raw audio, as traditionally done on Agon, eases converting original audio files to a compatible format. As well, because the application can parse `.wav` file header metadata, it can determine whether the file is compatible with the program and set the proper sample rate without any additional configuration information.

# Installation

## Installing a pre-assembled binary
The application binary is located at `tgt/jukebox.bin` in this repository. It has no external file dependences and can be stored in and executed from anywhere. It can also be placed in the `bin` directory of the SD card and invoked from any directory by typing `jukebox`. At present the application does not take any command-line arguments.

## Assembly from source
On any system with `ez80asm`, including the Agon itself, navigate to `src/asm` and enter `ez80asm app.asm ../../tgt/jukebox.bin` (or any other target path of your choice).

# User Interface
The user interface is divided into three main sections:

1. **Directory Display**:
   - Displays the current directory path (e.g., `/jukebox/tgt/music`).
   - Lists the files and directories within the current directory, ten files per page, indexed by numbers `00` to `09`. Only directories or compatible `wav.` files will be shown in the listing.

2. **Playback Information**:
   - Shows the currently playing song (e.g., `(P)laying: Song 0`) when playback is active, or `(P)aused: Song 0` when playback is paused. 

3. **File Browsing and Playback Controls**

## **File and Directory Browsing**
- **Up Arrow (⇑)**: Highlight the previous file in the current directory.
- **Down Arrow (⇓)**: Highlight the next file in the current directory.
- **Left Arrow (⇐)**: Go to the previous page of files in the current directory.
- **Right Arrow (⇒)**: Go to the next page of files in the current directory.
- **`U`**: Go up one directory level.

## File selection
- **Enter (↩)**: Open the highlighted directory or play the highlighted song.
- **Number Keys (0-9)**: Immediately play the sound file, or change to the directory, corresponding to the numbered index.
- **`R`**: Immediately play a random song from the current directory page.

## **Playback controls**
- **`[` and `]`**: move the playhead backward or foreward the number of seconds specified by the seek rate.
- **`-` and `=` **: reduce or increase the playhead seek rate.

## **Playback Settings**
- **`P`**: Toggle between play and pause for the currently active song.
- **`S`**: Toggle shuffle mode. When set to OFF, the next song after the currently *higlighted* (not active) one will automatically play. Otherwise a random song will be chosen from the currently shown directory page.
- **`L`**: Toggle loop mode. When set to ON, the active song will loop back to its beginning when reaching end of file. This setting overrides, but does not modify, the current shuffle mode setting.

## **Quitting the Application**
- **`ESC` or `Q`**: Exit the application and return to the Agon Light command prompt.

# Utilities
The `build/scripts/` directory of the repository contains utilities for analysing and preparing sound files for playback (none of which as yet run natively on Agon).
## Script make_wav.py
The `make_wav.py` script is a Python-based audio processing tool designed to prepare music files for playback. Although these tools support generating output files in many configurations, AgonJukebox is only capable of playing `.wav` files in **8-bit unsigned PCM**, monaural format. Sample rate has been tested up to 48000 Hz (the default rate for audio downloaded from YouTube) with good results. However, the script may be configured to produce target files with sample rates between 1 and 65535 Hz (16-bit integer range), though either extreme is not advised. Agon's default sample playback rate is 16384 Hz, which is reasonable if storage space is a concern.

Two optional pre-processing steps are available which attempt to mitigate the inherent loss of audio quality when downsampling to a bitdepth of 8 from the 32-bit float or 24-bit integer formats commonly seen in high-quality audio files.

### Installation

#### Prerequisites
This script requires Python and `ffmpeg` for audio processing. Follow the instructions below to install the necessary software on your operating system.

#### Linux (Debian-like)
1. **Install Python:**
   ```bash
   sudo apt update
   sudo apt install python3 python3-pip
   ```

2. **Install FFmpeg:**
   ```bash
   sudo apt install ffmpeg
   ```

3. **Clone the Repository:**
Note: this step is optional as the script has no dependencies on any other files in the repository.
   ```bash
   git clone https://github.com/bgates747/AgonJukebox
   cd AgonJukebox
   ```

#### macOS
1. **Install Homebrew (if not installed):**
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. **Install Python and FFmpeg:**
   ```bash
   brew install python ffmpeg
   ```

3. **Clone the Repository:**
Note: this step is optional as the script has no dependencies on any other files in the repository.
   ```bash
   git clone https://github.com/bgates747/AgonJukebox
   cd AgonJukebox
   ```

#### Windows
Note: As of this writing (Jan. 2025), these instructions have not been tested on Windows.
1. **Install Python:**
   - Download and install Python from [python.org](https://www.python.org/downloads/).
   - Make sure to check **"Add Python to PATH"** during installation.

2. **Install FFmpeg:**
   - Download a static build of FFmpeg from [ffmpeg.org](https://ffmpeg.org/download.html).
   - Extract the archive and add the `bin` folder to your system PATH.

3. **Clone the Repository:**
Note: this step is optional as the script has no dependencies on any other files in the repository.
   ```powershell
   git clone https://github.com/bgates747/AgonJukebox
   cd AgonJukebox
   ```

## Usage

### Running the Script
1. Set the `src_dir` parameter to specify the directory containing source audio files, and `tgt_dir` for where to write the converted files. Set pre-procesing options if desired, described below.
2. Set the type of files for the script to convert with this line in the `make_sfx` function:
```python
if filename.lower().endswith(('.wav', '.mp3', '.flac')):
```
2. Run the script. `src_dir` will be scanned non-recursively for all files with the prescribed extensions.

### Options
You can modify the script parameters in the `__main__` section to:
- Change the source and target directories.
- Adjust the sample rate.
- Enable or disable the creation of a compressed archive.

## Pre-Processing Options
Resampling audio down to 8-bit PCM and/or reducing the sample frequency inherently degrades quality, but can be somewhat mitigated with pre-processing. Many techniques are avaialble, but the following two have been found to be most effective. These steps are optional.

### 1. **Dynamic Range Compression**
Dynamic range compression reduces the difference between the loudest and quietest parts of the audio, making it more suitable for playback on systems with limited dynamic range. The compression parameters can be tweaked in this line:
```python
'-af', 'acompressor=threshold=-20dB:ratio=3:attack=5:release=50:makeup=2.5'
```
- `threshold`: The volume level (in dB) at which compression starts.
- `ratio`: How much the volume is reduced for signals above the threshold.
- `attack` and `release`: How quickly the compression starts and stops.
- `makeup`: Boosts the overall volume after compression.

### 2. **Volume Normalization**
Volume normalization ensures all audio files have a consistent loudness level. The normalization filter can be adjusted here:
```python
'-af', 'loudnorm=I=-20:TP=-2:LRA=11'
```
- `I` Integrated loudness target (in LUFS).
- `TP`: True peak limit (in dB).
- `LRA`: Loudness range allowed.

## Making a compatible .wav file
The script's main function is to create a compatible .wav file from source audio files. The script has been tested with `.wav`,`.flac`, and `.mp3` sources. Other formats may also work.

### 1. **Resampling**
Resampling changes the audio's sample rate to a desired setting using the `sample_rate` parameter Specifying `sample_rate = -1` will keep the source file's original sample rate. Optimal sample rates will be evenly divisible by 60 because the application breaks each 1 second of audio into that many chunks for streaming to VDP. 48000 and 41000 Hz are common rates for high quality audio, and both being divisible by 60 make the good choices.

### 2. **Conversion to Unsigned PCM WAV**
The audio is converted to **8-bit unsigned PCM**, as this is the only format supported by `.wav` files at 8-bit depth. This is in contrast to the Agon Light's default which expects **8-bit signed PCM** samples without the `.wav` file metadata headers. Additionally, the audio is converted to mono (`-ac 1`), as stereo is not supported on the target platform.

---

## File Format Requirements
The target `.wav` files must meet the following specifications:
- **Bit Depth:** 8-bit (unsigned PCM).
- **Channels:** Mono.
- **Sample Rate:** As desired. A rate evenly divisible by 60 is best.

---

## Troubleshooting
1. **User Interface** 
   - **Files not visible:** The program only displays subdirectories and *compatible* `.wav` files in the current directory. Even if your `.wav` file is valid for playback on modern software, if it is not encoded in mono 8-bit unsigned PCM, it won't show up in AgonJukebox.

2. **Audio Quality:**
   - **Sounds scratchy:** assuming the source file is not at fault, scratchyness is often the byproduct of quantization error in the conversion to 8-bit PCM. This results in waveforms that are less smooth than the original and thus sound more harsh. Applying dynamic range compression may mitgate some of these effects.
   - **Low volume:** the Agon generally wants audio samples normalised to near the maximum average levels obtainable without clipping, and many source files have levels well below this. A combination of dynamic range compression and volume normalisation done prior to resampling to 8-bit PCM may improve playback levels.
   - **Sounds muddy:** generally caused by selecting too low a sample rate relative to the higher frequencies of the original audio. If not at or already near the sample rate of the original, try the original rate.

---

## License
AgonJukebox is licensed under the UNLICENSE. See `LICENSE` for details.

---

## Contact

I am @BeeGee747, most active on the [Agon & Console 8 Community](https://discord.com/channels/1158535358624039014/1282290921815408681) Discord channel, which has a [forum](https://discord.com/channels/1158535358624039014/1326253731087384727) dedicated to this project.

---

## Acknowledgments
Special thanks to these members of the Agon Light community for making this project possible:

- **Steve Sims (@ss7):** for his tireless efforts developing and documenting the [VDP](https://github.com/AgonConsole8/agon-vdp) and [MOS](https://github.com/AgonConsole8/agon-mos) firmwares, and additionally answering questions, providing technical support and insight on Discord.
- **Jeroen Venema (@evenomator):** for the free and open-source [ez80asm](https://github.com/envenomator/agon-ez80asm) assembler which not only runs natively on Agon, but on all three major OS's, freeing us from the tyranny of Zilog's buggy, outdated, Windows-only proprietary closed-source ZDS II. Also for providing assembly routines compatible with his assembler, some of which provide core functions of this program.
- **Tom Morton (@tomm8086):** for **fab-agon-emulator**, another cross-platform, open-source program which not only brings Agon to prospective hardware owners, but much eases the development process. Also for his sample PRT interrupt timer assembly code, which is at the core of how this thing works, as well as honouring the many Bothans who died to bring some critical emulation bugs to light.
- **Richard Turrnidge (@Richard_Turrnidge):** for his excellent Agon-specific EZ80 assembly language [video tutorials](https://www.youtube.com/@AgonBits) on YouTube, and the attending [sample programs](https://github.com/richardturnnidge/lessons) repository paired to each episode. Also for testing the application and braving the source code on occasion.
- **Shawn Sijnstra (@sijnstra):** for adminstering the largest and most active [Agon Discord server](https://discord.com/channels/1158535358624039014/1158536711148675072) I know of. Also for his [arith24](https://github.com/sijnstra/agon-projects/blob/main/calc24/arith24.asm) functions which get a good workout in this program. Finally for providing user feedback and cheerleading these efforts.
- **@calc84maniac:** for detailed optimisations of various assembly routines, particularly the ones related to sorting filenames, and some core maths functions.
- **@Triplefox:** for many discussions related to digital audio theory and processing, including help with one particularly challenging file that helped me refine my default processing options to their current state.
- **@rafd_electrotux:** for user feedback, feature suggestions, and a nice list of Mexican Mariachi and Chilean folk songs for testing as well as diversifying my own collection.
- **Dean Belfield:** for his [port](https://github.com/breakintoprogram/agon-bbc-basic-adl) of R.T. Russell's Z80 version of BBC BASIC to Agon. This application makes use of its floating point library for the 32-bit maths required to access large audio files, by way of [my own port](https://github.com/bgates747/agon-bbc-basic-adl-ez80asm) from ZDS II to ez80asm-compatible source code.

