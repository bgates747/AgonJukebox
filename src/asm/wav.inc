; WAV File Structure Offsets and Descriptions
wav_riff:          EQU 0   ; 4 bytes: "RIFF" identifier
wav_file_size:     EQU 4   ; 4 bytes: Total file size minus 8 bytes for RIFF header
wav_wave:          EQU 8   ; 4 bytes: "WAVE" identifier
wav_fmt_marker:    EQU 12  ; 4 bytes: "fmt " subchunk marker
wav_fmt_size:      EQU 16  ; 4 bytes: Format chunk size (16 for PCM)
wav_audio_format:  EQU 20  ; 2 bytes: Audio format (1 = PCM)
wav_num_channels:  EQU 22  ; 2 bytes: Number of channels (1 = mono, 2 = stereo)
wav_sample_rate:   EQU 24  ; 4 bytes: Sample rate in Hz (e.g., 32768)
wav_byte_rate:     EQU 28  ; 4 bytes: Bytes per second (SampleRate * NumChannels * BitsPerSample / 8)
wav_block_align:   EQU 32  ; 2 bytes: Bytes per sample block (NumChannels * BitsPerSample / 8)
wav_bits_per_sample: EQU 34 ; 2 bytes: Bits per sample (e.g., 8 or 16)
wav_data_marker:   EQU 36  ; 4 bytes: "data" subchunk marker
wav_data_size:     EQU 40  ; 4 bytes: Size of the audio data in bytes
wav_data_start:    EQU 44  ; Start of audio data
; Total Header Size: 44 bytes
