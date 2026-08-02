; Normalized WAV state. The reader scans RIFF chunks instead of assuming a
; particular metadata layout or a fixed PCM payload offset.
wav_riff_end:       EQU 0    ; 4 bytes: absolute end of the RIFF container
wav_sample_rate:    EQU 4    ; 4 bytes: PCM sample rate
wav_data_size:      EQU 8    ; 4 bytes: declared PCM payload length
wav_data_offset:    EQU 12   ; 4 bytes: absolute PCM payload offset
wav_fmt_found:      EQU 16   ; 1 byte: a supported fmt chunk was parsed
wav_chunk_size:     EQU 17   ; 4 bytes: current RIFF chunk payload length
wav_chunk_end:      EQU 21   ; 4 bytes: padded end of current RIFF chunk
wav_scratch:        EQU 25   ; scratch for RIFF/chunk headers and fmt payload
wav_state_size:     EQU 76   ; retain the existing RAM allocation

bf_verify_wav:
    push iy ; callers want iy back unmolested
    ld iy,bf_wav_header
    call verify_wav
    jr z,@done ; verify_wav closes files that fail validation
    push af ; save zero flag and a
    FFSCALL ffs_fclose ; browser probes never leave a file open
    pop af ; restore zero flag and a for return
@done:
    pop iy ; send her home how she came in
    ret
; end bf_verify_wav

ps_open_wav:
; get filinfo and fil struct pointers to currently selected file
    call bf_get_filinfo_from_pg_idx ; iy = pointer to filinfo struct
    lea de,iy+filinfo_fname ; de = pointer to filename
    ld hl,ps_fil_struct

; verify a valid .wav file; success leaves it open at the PCM payload
    push iy
    ld iy,ps_wav_header
    call verify_wav
    pop iy
    ret
; end ps_open_wav

; Verify and normalize a RIFF/WAVE file.
; inputs:  hl = pointer to FIL structure, de = pointer to filename
;          iy = pointer to wav_state_size bytes of state
; returns: a = 0 and Z set if the file is not supported (and file is closed)
;          a = 1 and Z reset if valid (file remains open at the data payload)
; accepts: standard PCM, mono, unsigned 8-bit, sample rate 1..65535 Hz
; destroys: af only
verify_wav:
    push bc
    push de
    push hl
    push ix
    push hl
    pop ix ; ix remains the FIL pointer throughout parsing

; clear normalized state without losing the filename
    push de
    xor a
    ld bc,wav_state_size
    lea hl,iy+0
    call clear_mem
    pop de

; open the file
    push ix
    pop hl
    push ix
    ld c,fa_read
    FFSCALL ffs_fopen
    pop ix
    or a
    jp nz,@not_open

; RIFF size and WAVE form type
    ld bc,12
    call wav_read_exact
    jp z,@invalid_open_file

    ld hl,(iy+wav_scratch+0)
    ld de,0x464952 ; "RIF"
    or a
    sbc hl,de
    jp nz,@invalid_open_file
    ld a,(iy+wav_scratch+3)
    cp 'F'
    jp nz,@invalid_open_file

    ld hl,(iy+wav_scratch+8)
    ld de,0x564157 ; "WAV"
    or a
    sbc hl,de
    jp nz,@invalid_open_file
    ld a,(iy+wav_scratch+11)
    cp 'E'
    jp nz,@invalid_open_file

; Convert RIFF's "file size minus eight" field to an absolute end offset.
    ld hl,(iy+wav_scratch+4)
    ld (iy+wav_riff_end),hl
    ld a,(iy+wav_scratch+7)
    ld (iy+wav_riff_end+3),a

; A WAVE RIFF payload must at least contain the four-byte form type.
    ld a,(iy+wav_riff_end+3)
    or (iy+wav_riff_end+2)
    or (iy+wav_riff_end+1)
    jr nz,@riff_size_ok
    ld a,(iy+wav_riff_end)
    cp 4
    jp c,@invalid_open_file
@riff_size_ok:
    ld a,(iy+wav_riff_end)
    add a,8
    ld (iy+wav_riff_end),a
    ld a,(iy+wav_riff_end+1)
    adc a,0
    ld (iy+wav_riff_end+1),a
    ld a,(iy+wav_riff_end+2)
    adc a,0
    ld (iy+wav_riff_end+2),a
    ld a,(iy+wav_riff_end+3)
    adc a,0
    ld (iy+wav_riff_end+3),a
    jp c,@invalid_open_file
    call wav_riff_fits_file
    jp c,@invalid_open_file

@chunk_loop:
; Every RIFF chunk begins with a four-byte ID and four-byte payload size.
; Prove the complete header is still inside RIFF before touching the file.
    ld hl,8
    ld (iy+wav_chunk_size),hl
    xor a
    ld (iy+wav_chunk_size+3),a
    call wav_prepare_chunk_end
    jp c,@invalid_open_file
    ld bc,8
    call wav_read_exact
    jp z,@invalid_open_file
    ld hl,(iy+wav_scratch+4)
    ld (iy+wav_chunk_size),hl
    ld a,(iy+wav_scratch+7)
    ld (iy+wav_chunk_size+3),a

; "fmt " chunk
    ld hl,(iy+wav_scratch)
    ld de,0x746D66 ; "fmt"
    or a
    sbc hl,de
    jr nz,@check_data
    ld a,(iy+wav_scratch+3)
    cp ' '
    jr z,@parse_fmt

@check_data:
; "data" chunk
    ld hl,(iy+wav_scratch)
    ld de,0x746164 ; "dat"
    or a
    sbc hl,de
    jr nz,@skip_chunk
    ld a,(iy+wav_scratch+3)
    cp 'a'
    jr z,@accept_data

@skip_chunk:
; Unknown chunks (LIST, JUNK, bext, fact, and so on) are legal.
    call wav_prepare_chunk_end
    jp c,@invalid_open_file
    call wav_seek_chunk_end
    jp z,@invalid_open_file
    jp @chunk_loop

@parse_fmt:
; Only one format chunk is meaningful, and its common PCM prefix is 16 bytes.
    ld a,(iy+wav_fmt_found)
    or a
    jp nz,@invalid_open_file
    ld a,(iy+wav_chunk_size+3)
    or (iy+wav_chunk_size+2)
    or (iy+wav_chunk_size+1)
    jr nz,@fmt_size_ok
    ld a,(iy+wav_chunk_size)
    cp 16
    jp c,@invalid_open_file
@fmt_size_ok:
; Save the padded chunk end before the header buffer is reused for fmt data.
    call wav_prepare_chunk_end
    jp c,@invalid_open_file
    ld bc,16
    call wav_read_exact
    jp z,@invalid_open_file
    call wav_validate_fmt
    jp z,@invalid_open_file
    ld a,1
    ld (iy+wav_fmt_found),a
; Skip any extension bytes in an 18- or 40-byte fmt chunk.
    call wav_seek_chunk_end
    jp z,@invalid_open_file
    jp @chunk_loop

@accept_data:
; Standard WAVE ordering places fmt before data.
    ld a,(iy+wav_fmt_found)
    or a
    jp z,@invalid_open_file
; Validate the declared payload (and its RIFF pad) before retaining its bounds.
    call wav_prepare_chunk_end
    jp c,@invalid_open_file
    ld hl,(iy+wav_chunk_size)
    ld (iy+wav_data_size),hl
    ld a,(iy+wav_chunk_size+3)
    ld (iy+wav_data_size+3),a
    ld a,(iy+wav_data_size+3)
    or a
    jr nz,@data_not_empty
    ld hl,(iy+wav_data_size)
    ld de,0
    or a
    sbc hl,de
    jp z,@invalid_open_file
@data_not_empty:
; f_read left fptr immediately after the data chunk header.
    ld hl,(ix+fil_fptr)
    ld (iy+wav_data_offset),hl
    ld a,(ix+fil_fptr+3)
    ld (iy+wav_data_offset+3),a
    ld a,1
    or a
    jr @done

@invalid_open_file:
; The open succeeded, so validation owns closing this failure path.
    push ix
    pop hl
    push ix
    FFSCALL ffs_fclose
    pop ix
@not_open:
    xor a
@done:
    pop ix
    pop hl
    pop de
    pop bc
    ret
; end verify_wav

; Read exactly BC bytes into wav_scratch.
; returns: A = 1/NZ on success, A = 0/Z on FRESULT or short-read failure
wav_read_exact:
    push bc
    push ix
    pop hl
    lea de,iy+wav_scratch
    push ix
    FFSCALL ffs_fread
    pop ix
    or a
    jr nz,@failed
    pop hl ; requested length
    or a
    sbc hl,bc
    jr nz,@short
    ld a,1
    or a
    ret
@failed:
    pop hl ; discard requested length
@short:
    xor a
    ret
; end wav_read_exact

; Read exactly BC bytes into wav_scratch+16 (the extensible fmt tail).
; returns: A = 1/NZ on success, A = 0/Z on FRESULT or short-read failure
wav_read_exact_fmt_tail:
    push bc
    push ix
    pop hl
    lea de,iy+wav_scratch+16
    push ix
    FFSCALL ffs_fread
    pop ix
    or a
    jr nz,@failed
    pop hl ; requested length
    or a
    sbc hl,bc
    jr nz,@short
    ld a,1
    or a
    ret
@failed:
    pop hl ; discard requested length
@short:
    xor a
    ret
; end wav_read_exact_fmt_tail

; Check the common fmt payload and, when present, WAVEFORMATEXTENSIBLE's
; PCM subtype. Both representations are emitted by standards-compliant tools.
; returns: A = 1/NZ for supported PCM, A = 0/Z otherwise
wav_validate_fmt:
; Legacy WAVE_FORMAT_PCM = 1
    ld a,(iy+wav_scratch+0)
    cp 1
    jr nz,@check_extensible
    ld a,(iy+wav_scratch+1)
    or a
    jp nz,@invalid
    jp @validate_common

@check_extensible:
; WAVE_FORMAT_EXTENSIBLE = 0xFFFE
    cp 0xFE
    jp nz,@invalid
    ld a,(iy+wav_scratch+1)
    cp 0xFF
    jp nz,@invalid
; Its payload must contain the 16-byte common prefix plus 24 extension bytes.
    ld a,(iy+wav_chunk_size+3)
    or (iy+wav_chunk_size+2)
    or (iy+wav_chunk_size+1)
    jr nz,@read_extensible
    ld a,(iy+wav_chunk_size)
    cp 40
    jp c,@invalid
@read_extensible:
    ld bc,24
    call wav_read_exact_fmt_tail
    jp z,@invalid
; cbSize = 22 and valid bits per sample = 8
    ld a,(iy+wav_scratch+16)
    cp 22
    jp nz,@invalid
    ld a,(iy+wav_scratch+17)
    or a
    jp nz,@invalid
    ld a,(iy+wav_scratch+18)
    cp 8
    jp nz,@invalid
    ld a,(iy+wav_scratch+19)
    or a
    jp nz,@invalid
; KSDATAFORMAT_SUBTYPE_PCM = 00000001-0000-0010-8000-00AA00389B71
    ld hl,(iy+wav_scratch+24)
    ld de,0x000001
    or a
    sbc hl,de
    jp nz,@invalid
    ld a,(iy+wav_scratch+27)
    or a
    jp nz,@invalid
    ld hl,(iy+wav_scratch+28)
    ld de,0x100000
    or a
    sbc hl,de
    jp nz,@invalid
    ld a,(iy+wav_scratch+31)
    or a
    jp nz,@invalid
    ld hl,(iy+wav_scratch+32)
    ld de,0x000080
    or a
    sbc hl,de
    jp nz,@invalid
    ld a,(iy+wav_scratch+35)
    cp 0xAA
    jp nz,@invalid
    ld hl,(iy+wav_scratch+36)
    ld de,0x9B3800
    or a
    sbc hl,de
    jp nz,@invalid
    ld a,(iy+wav_scratch+39)
    cp 0x71
    jp nz,@invalid

@validate_common:
; mono = 1 channel
    ld a,(iy+wav_scratch+2)
    cp 1
    jp nz,@invalid
    ld a,(iy+wav_scratch+3)
    or a
    jp nz,@invalid
; sample rate must fit the VDP's unsigned 16-bit per-sample field and be nonzero
    ld a,(iy+wav_scratch+6)
    or (iy+wav_scratch+7)
    jp nz,@invalid
    ld hl,(iy+wav_scratch+4)
    ld de,0
    or a
    sbc hl,de
    jp z,@invalid
    ld (iy+wav_sample_rate),hl
    xor a
    ld (iy+wav_sample_rate+3),a
; mono unsigned 8-bit PCM has one byte per frame, so byte rate = sample rate
    ld hl,(iy+wav_scratch+8)
    ld de,(iy+wav_sample_rate)
    or a
    sbc hl,de
    jp nz,@invalid
    ld a,(iy+wav_scratch+11)
    or a
    jp nz,@invalid
; block alignment = 1 byte
    ld a,(iy+wav_scratch+12)
    cp 1
    jp nz,@invalid
    ld a,(iy+wav_scratch+13)
    or a
    jp nz,@invalid
; bits per sample = 8
    ld a,(iy+wav_scratch+14)
    cp 8
    jp nz,@invalid
    ld a,(iy+wav_scratch+15)
    or a
    jp nz,@invalid
    ld a,1
    or a
    ret
@invalid:
    xor a
    ret
; end wav_validate_fmt

; Calculate and validate the padded end of the current chunk.
; The FIL fptr must point to the first byte of the chunk payload.
; returns carry set if 32-bit arithmetic overflowed or RIFF bounds are exceeded
wav_prepare_chunk_end:
    ld a,(ix+fil_fptr+0)
    add a,(iy+wav_chunk_size+0)
    ld (iy+wav_chunk_end+0),a
    ld a,(ix+fil_fptr+1)
    adc a,(iy+wav_chunk_size+1)
    ld (iy+wav_chunk_end+1),a
    ld a,(ix+fil_fptr+2)
    adc a,(iy+wav_chunk_size+2)
    ld (iy+wav_chunk_end+2),a
    ld a,(ix+fil_fptr+3)
    adc a,(iy+wav_chunk_size+3)
    ld (iy+wav_chunk_end+3),a
    jr c,@outside

; RIFF chunks are word-aligned; an odd payload has one pad byte.
    ld a,(iy+wav_chunk_size)
    and 1
    jr z,@check_bounds
    ld a,(iy+wav_chunk_end+0)
    inc a
    ld (iy+wav_chunk_end+0),a
    jr nz,@check_bounds
    ld a,(iy+wav_chunk_end+1)
    inc a
    ld (iy+wav_chunk_end+1),a
    jr nz,@check_bounds
    ld a,(iy+wav_chunk_end+2)
    inc a
    ld (iy+wav_chunk_end+2),a
    jr nz,@check_bounds
    ld a,(iy+wav_chunk_end+3)
    inc a
    ld (iy+wav_chunk_end+3),a
    jr z,@outside

@check_bounds:
; Accept target <= RIFF end; reject a chunk that escapes the container.
    ld a,(iy+wav_riff_end+3)
    cp (iy+wav_chunk_end+3)
    jr c,@outside
    jr nz,@inside
    ld a,(iy+wav_riff_end+2)
    cp (iy+wav_chunk_end+2)
    jr c,@outside
    jr nz,@inside
    ld a,(iy+wav_riff_end+1)
    cp (iy+wav_chunk_end+1)
    jr c,@outside
    jr nz,@inside
    ld a,(iy+wav_riff_end+0)
    cp (iy+wav_chunk_end+0)
    jr c,@outside
@inside:
    or a ; clear carry
    ret
@outside:
    scf
    ret
; end wav_prepare_chunk_end

; Reject a RIFF length that exceeds the actual FatFS object size.
; returns carry set if riff_end > file size
wav_riff_fits_file:
    ld a,(ix+ffobjid_objsize+3)
    cp (iy+wav_riff_end+3)
    jr c,@outside
    jr nz,@inside
    ld a,(ix+ffobjid_objsize+2)
    cp (iy+wav_riff_end+2)
    jr c,@outside
    jr nz,@inside
    ld a,(ix+ffobjid_objsize+1)
    cp (iy+wav_riff_end+1)
    jr c,@outside
    jr nz,@inside
    ld a,(ix+ffobjid_objsize+0)
    cp (iy+wav_riff_end+0)
    jr c,@outside
@inside:
    or a ; clear carry
    ret
@outside:
    scf
    ret
; end wav_riff_fits_file

; Seek to the already validated padded chunk end.
; returns: A = 1/NZ on success, A = 0/Z on FRESULT failure
wav_seek_chunk_end:
    ld de,(iy+wav_chunk_end)
    ld a,(iy+wav_chunk_end+3)
    ld c,a
    push ix
    pop hl
    push ix
    FFSCALL ffs_flseek
    pop ix
    or a
    jr nz,@failed
    ld a,1
    or a
    ret
@failed:
    xor a
    ret
; end wav_seek_chunk_end
