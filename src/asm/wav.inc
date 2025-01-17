; WAV File Structure Offsets and Descriptions
wav_riff:          EQU 0    ; 4 bytes: "RIFF" identifier
wav_file_size:     EQU 4    ; 4 bytes: Total file size minus 8 bytes for RIFF header
wav_wave:          EQU 8    ; 4 bytes: "WAVE" identifier
wav_fmt_marker:    EQU 12   ; 4 bytes: "fmt " subchunk marker
wav_fmt_size:      EQU 16   ; 4 bytes: Format chunk size (16 for PCM)
wav_audio_format:  EQU 20   ; 2 bytes: Audio format (1 = PCM)
wav_num_channels:  EQU 22   ; 2 bytes: Number of channels (1 = mono, 2 = stereo)
wav_sample_rate:   EQU 24   ; 4 bytes: Sample rate in Hz (e.g., 32768)
wav_byte_rate:     EQU 28   ; 4 bytes: Bytes per second (SampleRate * NumChannels * BitsPerSample / 8)
wav_block_align:   EQU 32   ; 2 bytes: Bytes per sample block (NumChannels * BitsPerSample / 8)
wav_bits_per_sample: EQU 34 ; 2 bytes: Bits per sample (e.g., 8 or 16)

; LIST Chunk (Extra Metadata)
wav_list_marker:   EQU 36   ; 4 bytes: "LIST" marker
wav_list_size:     EQU 40   ; 4 bytes: Size of the LIST chunk (e.g., 26)
wav_info_marker:   EQU 44   ; 4 bytes: "INFO" marker
wav_isft_marker:   EQU 48   ; 4 bytes: "ISFT" marker (software identifier)
wav_isft_data:     EQU 52   ; 14 bytes: Software info string (e.g., "Lavf59.27.100")
wav_isft_padding:  EQU 66   ; 2 bytes: Padding/NULL terminator for alignment

; Data Chunk
wav_data_marker:   EQU 68   ; 4 bytes: "data" subchunk marker
wav_data_size:     EQU 72   ; 4 bytes: Size of the audio data in bytes
wav_data_start:    EQU 76   ; Start of audio data
wav_header_size:   EQU wav_data_start ; Total Header Size: 76 bytes

; verify that the file is a .wav file
; inputs: none
; prerequisites: ps_read_wav_header called
; returns: zero flag set if not a .wav file we can read
; clobbered: af, hl, de, ix
verify_wav:
    ld ix,ps_wav_header

    ld hl,(ix+wav_riff)
    ld de, 0x464952  ; ascii for "RIF" in little-endian order
    or a ; clear carry
    sbc hl,de
    ret nz ; not a .wav file

    ld hl,(ix+wav_wave)
    ld de, 0x564157  ; ascii for "WAV" in little-endian order
    or a ; clear carry
    sbc hl,de
    ret nz ; not a .wav file

    ld hl,(ix+wav_fmt_marker)
    ld de, 0x746D66  ; ascii for "fmt" in little-endian order
    or a ; clear carry
    sbc hl,de
    ret nz ; not a .wav file

    ld hl,(ix+wav_audio_format)
    ld de, 0x010001  ; PCM format, 1-channel
    or a ; clear carry
    sbc hl,de ; if not zero, not a .wav file we can read

    ret
; end verify_wav