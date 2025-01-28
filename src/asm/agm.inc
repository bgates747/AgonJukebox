; AGON Movie (.agm) Header Structure Offsets and Descriptions
agm_magic:         EQU 0    ; 6 bytes: "AGNMOV" identifier
agm_version:       EQU 6    ; 1 byte: File format version (e.g., 0x01)
agm_width:         EQU 7    ; 1 byte: Video width in pixels (e.g., 128)
agm_height:        EQU 8    ; 1 byte: Video height in pixels (e.g., 96)
agm_frame_rate:    EQU 9    ; 1 byte: Frames per second (e.g., 4)
agm_total_frames:  EQU 10   ; 4 bytes: Total number of frames (32-bit integer)
agm_audio_seconds: EQU 14   ; 4 bytes: Total seconds of audio (32-bit float or int)
agm_reserved:      EQU 18   ; 52 bytes: Reserved for future features (compression, metadata, etc.)
agm_header_size:   EQU 68   ; Total AGN Header Size: 68 bytes

; WAV Header Section (immediately follows AGN header)
agm_wav_start:     EQU agm_header_size        ; Start of WAV header
agm_wav_size:      EQU 76                     ; Total WAV Header Size: 76 bytes
agm_total_header_size: EQU agm_header_size + agm_wav_size ; Total Header Size: 144 bytes
