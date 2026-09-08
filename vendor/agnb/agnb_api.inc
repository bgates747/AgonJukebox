; Canonical AGNB image/audio loader API
; =====================================
;
; Public entry points:
;   agnb_load_images: DE -> zero-terminated AGNB 0.1 image filename
;   agnb_load_images_with_callback:
;                     DE -> filename, HL -> completed-image callback
;   agnb_load_audio:  DE -> zero-terminated AGNB 0.2 audio filename
;   agnb_load_audio_with_callback:
;                     DE -> filename, HL -> completed-audio callback
;
; Applications own plotting, playback, input, timing, and debug behavior.
; External dependencies and reference implementations are documented in
; README.md and agnb_dependencies.inc.
;
; AGNB 0.1 image-container layout
; ===============================
;
; AGNB is a RIFF container. All integer fields are unsigned little-endian.
; Every chunk begins with a four-byte ID and a u32 payload size. The payload
; follows immediately and is padded with zero bytes to a four-byte boundary.
; The stored chunk size excludes its eight-byte header and alignment padding.
;
;     RIFF  u32(file size - 8)  AGNB
;       VERS  size=2
;         u8 major=0
;         u8 minor=1
;       LIST  type=BUFR
;         BHDR  size=2
;           u16 bufferId
;         IMAG  size=5
;           u16 width
;           u16 height
;           u8  format=1        ; RGBA2222
;         DATA  size=width*height
;           u8 pixels[]         ; row-major, no row padding
;
; VERS occurs once before the LIST records. Each version 0.1 LIST BUFR record
; contains exactly BHDR, IMAG, and DATA in that order. The LIST payload starts
; with its four-byte BUFR type, followed by those nested chunks. Readers must
; validate the enclosing RIFF/LIST bounds and the BHDR/IMAG metadata before
; reading or uploading DATA. Chunk traversal advances by:
;
;     8 + ((payload_size + 3) & ~3)
;
; The offsets below are indices from the beginning of the named header or
; payload. RIFF and chunk sizes are u32 values even though ADL registers are
; 24-bit, so their high byte must not be silently discarded during validation.

; RIFF file header: "RIFF", u32 size, "AGNB"
agnb_riff_id:              equ 0
agnb_riff_size:            equ 4
agnb_riff_form:            equ 8
agnb_riff_header_size:     equ 12

; Generic RIFF chunk header: FourCC ID, u32 payload size
agnb_chunk_id:             equ 0
agnb_chunk_size:           equ 4
agnb_chunk_data:           equ 8
agnb_chunk_header_size:    equ 8

; VERS payload
agnb_vers_major:           equ 0
agnb_vers_minor:           equ 1
agnb_vers_payload_size:    equ 2

; LIST BUFR payload
agnb_list_type:            equ 0
agnb_list_chunks:          equ 4
agnb_list_type_size:       equ 4

; BHDR payload
agnb_bhdr_bufferId:        equ 0
agnb_bhdr_payload_size:    equ 2

; IMAG payload
agnb_imag_width:           equ 0
agnb_imag_height:          equ 2
agnb_imag_format:          equ 4
agnb_imag_payload_size:    equ 5

; DATA payload
agnb_data_pixels:          equ 0

; Values supported by the version 0.1 image loader
agnb_version_major:        equ 0
agnb_version_minor:        equ 1
agnb_image_rgba2222:       equ 1


; FourCC constants
; ----------------
; Store each identifier exactly as it appears on disk. agnb_compare_fourcc
; compares one of these tables with four bytes read from the container.

agnb_id_riff:              db "RIFF"
agnb_id_agnb:              db "AGNB"
agnb_id_vers:              db "VERS"
agnb_id_list:              db "LIST"
agnb_id_bufr:              db "BUFR"
agnb_id_bhdr:              db "BHDR"
agnb_id_imag:              db "IMAG"
agnb_id_data:              db "DATA"


; Reader result codes
; -------------------
; Public routines will return A=0 with Z set on success, or one of these
; nonzero values with NZ set on failure. The same value is stored in
; agnb_last_error.

agnb_error_ok:             equ 0
agnb_error_open:           equ 1
agnb_error_read:           equ 2
agnb_error_seek:           equ 3
agnb_error_riff_id:        equ 4
agnb_error_riff_form:      equ 5
agnb_error_version:        equ 6
agnb_error_chunk:          equ 7
agnb_error_bounds:         equ 8
agnb_error_bufferId:       equ 9
agnb_error_metadata:       equ 10
agnb_error_data_size:      equ 11
agnb_error_vdp:            equ 12
agnb_error_eof:            equ 13
agnb_error_not_implemented: equ 255


; FatFS file structure
; --------------------
; The direct ffs_* API needs one caller-owned FIL. Its field indices come from
; mos_api.inc. No FILINFO is needed for opening, reading, seeking, or closing
; the single known container filename.

agnb_fil_size:             equ fil_dir_ptr+3
agnb_fil:
    blkb agnb_fil_size,0


; Reader-state structure
; ----------------------
; RIFF sizes and offsets are u32 and are kept as four bytes even though most
; eZ80 arithmetic is 24-bit. The byte at offset +3 must participate in bounds
; checks and FatFS seeks.

agnb_state_file_size:      equ 0  ; u32 physical size from FIL object
agnb_state_riff_end:       equ 4  ; u32 first byte after RIFF contents
agnb_state_list_end:       equ 8  ; u32 first byte after current LIST payload
agnb_state_chunk_size:     equ 12 ; u32 current chunk payload size
agnb_state_chunk_end:      equ 16 ; u32 first byte after current payload
agnb_state_file_offset:    equ 20 ; u32 current logical read position
agnb_state_bytes_read:     equ 24 ; u32 last read count (high byte normally 0)
agnb_state_size:           equ 28

agnb_state:
    blkb agnb_state_size,0


; Normalized image metadata
; -------------------------
; BHDR and IMAG are copied here and validated completely before DATA is read.

agnb_meta_bufferId:        equ 0  ; u16 writer-specified VDP bufferId
agnb_meta_width:           equ 2  ; u16 pixels
agnb_meta_height:          equ 4  ; u16 pixels
agnb_meta_format:          equ 6  ; u8, version 0.1 requires RGBA2222
agnb_meta_data_size:       equ 7  ; u32 DATA payload size
agnb_meta_size:            equ 11

agnb_metadata:
    blkb agnb_meta_size,0

; Retained u32 result from agnb_calculate_image_data_size for validation and
; temporary test inspection. The high byte is zero for the 24-bit product.
agnb_expected_data_size:
    blkb 4,0

; Working counters used by agnb_stream_data. DATA sizes accepted by the image
; loader have already been constrained to 24 bits.
agnb_stream_remaining:
    blkb 3,0
agnb_stream_block_size:
    blkb 3,0
agnb_padding_size:
    db 0

; Record-validation flags. These are reset at the start of each LIST BUFR.
agnb_record_has_bhdr:      equ 0
agnb_record_has_imag:      equ 1
agnb_record_has_data:      equ 2

agnb_record_flags:         db 0
agnb_last_error:           db agnb_error_ok
agnb_file_is_open:         db 0


; Reusable I/O storage
; --------------------
; The 12-byte buffer is large enough for either the RIFF file header or a
; generic chunk header plus the four-byte LIST type. DATA is streamed through
; the application's existing 8 KiB SRAM filedata area.

agnb_header:
    blkb agnb_riff_header_size,0

; Loader-owned transfer window. Wolf3D's fixed SRAM is occupied by map and
; sprite state, so the API cannot assume the harness's 0xB7E000 scratch area.
agnb_io_buffer:            blkb 8192,0
agnb_io_buffer_size:       equ 8192

; Application callback invoked after each image has been finalized.
agnb_image_callback:       dl 0

; Reader subroutine interface
; ---------------------------
; These labels establish the intended decomposition and calling contracts.
; They deliberately fail with agnb_error_not_implemented until replaced with
; real code, preventing an incomplete loader from reporting false success.

; Compare two FourCC values.
; inputs:  HL = pointer to first FourCC, DE = pointer to second FourCC
; outputs: Z set when all four bytes match, Z reset when any byte differs
; preserves: BC, DE, HL
; destroys: A
agnb_compare_fourcc:
    push bc
    push de
    push hl
    ld b,4
@loop:
    ld a,(de)
    cp (hl)
    jr nz,@done ; exit with Z reset if any byte differs, indicating a mismatch
    inc de
    inc hl
    djnz @loop ; if we fall throgh at the end of the loop Z is set, indicating a match
@done:
    pop hl
    pop de
    pop bc
    ret

; Open a container for reading.
; inputs:  DE = zero-terminated filename (normally agnb_filename)
; outputs: A=0 and Z set on success; A=agnb_error_open and NZ set on failure
;          agnb_fil initialized and agnb_file_is_open set on success
; destroys: AF, BC, HL
agnb_open:
; begin fail-closed: do not leave stale success state if ffs_fopen fails
    xor a
    ld (agnb_file_is_open),a
    ld (agnb_last_error),a

; Each newly opened container starts at physical and logical offset zero.
; The original single-container caller received this state from BSS
; initialization; consecutive container loads must establish it explicitly.
    ld hl,0
    ld (agnb_state+agnb_state_file_offset),hl
    ld (agnb_state+agnb_state_bytes_read),hl
    ld (agnb_state+agnb_state_file_offset+3),a
    ld (agnb_state+agnb_state_bytes_read+3),a

; open the caller-supplied filename into our single reader-owned FIL
    ld hl,agnb_fil
    ld c,fa_read
    FFSCALL ffs_fopen
    or a
    jr nz,@error

; ffs_fopen succeeded
    ld a,1
    ld (agnb_file_is_open),a
    xor a
    ret

@error:
    ld a,agnb_error_open
    ld (agnb_last_error),a
    or a
    ret

; Close agnb_fil if open and clear agnb_file_is_open.
; outputs: A=0 and Z set if closed or already closed
;          nonzero FatFS result and NZ set if ffs_fclose fails
; destroys: HL
agnb_close:
; An unopened file is already in the requested state.
    ld a,(agnb_file_is_open)
    or a
    jr z,@success

; Close our single reader-owned FIL.
    ld hl,agnb_fil
    FFSCALL ffs_fclose
    or a
    jr nz,agnb_error_close

; Only clear the open flag after FatFS confirms the close.
    xor a
    ld (agnb_file_is_open),a
@success:
    xor a
    ld (agnb_last_error),a
    ret

agnb_error_close:
; Placeholder in case we determine that close failures need a dedicated AGNB
; error code or recovery path. For now retain and return the nonzero FRESULT,
; and leave agnb_file_is_open set because FatFS did not confirm the close.
    ld (agnb_last_error),a
    or a
    ret

; Top-level image load operation.
; inputs:  DE = zero-terminated container filename
; outputs: A=0 and Z set after all valid LIST BUFR image records are uploaded
;          and finalized at their explicit IDs; nonzero error and NZ otherwise
; destroys: AF, BC, DE, HL, IX
agnb_load_images:
    ld hl,agnb_image_callback_noop

; Callback-enabled image loader.
; inputs: DE = filename; HL = callback whose result is ignored
agnb_load_images_with_callback:
    ld (agnb_image_callback),hl
    call agnb_open
    ret nz

    call agnb_read_riff_header
    jr nz,@load_error
    call agnb_read_vers
    jr nz,@load_error

@next_record:
; End only at the exact declared RIFF boundary. A position beyond it is an
; internal bounds failure; a position before it must begin another LIST BUFR.
    ld a,(agnb_state+agnb_state_file_offset+3)
    ld hl,agnb_state+agnb_state_riff_end+3
    cp (hl)
    jr c,@read_record
    jr nz,@bad_bounds
    ld hl,(agnb_state+agnb_state_file_offset)
    ld de,(agnb_state+agnb_state_riff_end)
    or a
    sbc hl,de
    jr z,@success
    jr nc,@bad_bounds

@read_record:
    call agnb_read_buffer_list
    jr nz,@load_error
    call agnb_stream_data
    jr nz,@load_error
    call agnb_finalize_image
    jr nz,@load_error

; Give the application one completed-bitmap boundary per record.
; Metadata remains valid for the duration of the callback.
    call agnb_call_image_callback

    call agnb_finish_buffer_list
    jr nz,@load_error
    jr @next_record

@bad_bounds:
    ld a,agnb_error_bounds
    ld (agnb_last_error),a
@load_error:
; Preserve the parser/transport error while still closing the open file.
    push af
    call agnb_close
    pop af
    ld (agnb_last_error),a
    or a
    ret

@success:
    jp agnb_close

; The CALL above has already stacked the continuation address. Tail-jump to
; the selected callback so its RET resumes the loader without clobbering BC.
agnb_call_image_callback:
    ld hl,(agnb_image_callback)
    jp (hl)

agnb_image_callback_noop:
    xor a
    ret

; Read exactly BC bytes from agnb_fil into DE.
; inputs:  BC = requested u24 length, DE = destination
; outputs: A=0 and Z set after the complete request is satisfied
;          nonzero error code and NZ set on FatFS error or premature EOF
;          state offset/count updated after every successful FatFS read
; destroys: BC, DE, HL
agnb_read_exact:
; A zero-length request is already complete.
    ld hl,0
    or a
    sbc hl,bc
    jr z,@success

@read:
; ffs_fread replaces BC with the number of bytes actually read, so retain the
; remaining request on the stack. It preserves DE, our current destination.
    push bc
    ld hl,agnb_fil
    FFSCALL ffs_fread
    or a
    jr nz,@fatfs_error

; Advance the u32 logical position by the returned u24 byte count.
    ld hl,(agnb_state+agnb_state_file_offset)
    add hl,bc
    ld (agnb_state+agnb_state_file_offset),hl
    ld a,(agnb_state+agnb_state_file_offset+3)
    adc a,0
    jr c,@offset_overflow
    ld (agnb_state+agnb_state_file_offset+3),a

; Retain the count returned by this individual FatFS read.
    ld (agnb_state+agnb_state_bytes_read),bc
    xor a
    ld (agnb_state+agnb_state_bytes_read+3),a

; Recover the remaining request and reject zero bytes as premature EOF.
    pop hl
    push hl
    ld hl,0
    or a
    sbc hl,bc
    pop hl
    jr z,@eof

; Subtract the returned count from the remaining request. FatFS must never
; report more bytes than were requested.
    or a
    sbc hl,bc
    jr c,@read_error

; Advance the destination by the returned byte count.
    ex de,hl
    add hl,bc
    ex de,hl

; Continue after a short read, or return once the request is satisfied.
    ld bc,0
    or a
    sbc hl,bc
    jr z,@success
    push hl
    pop bc
    jr @read

@fatfs_error:
    pop bc
@read_error:
    ld a,agnb_error_read
    jr @error
@offset_overflow:
    pop bc
    ld a,agnb_error_bounds
    jr @error
@eof:
    ld a,agnb_error_eof
@error:
    ld (agnb_last_error),a
    or a
    ret

@success:
    xor a
    ld (agnb_last_error),a
    ret

; Seek to a u32 absolute file offset.
; inputs:  C = most-significant byte, DE = low 24 bits
; outputs: agnb_state_file_offset updated on success
agnb_seek_absolute:
    jp agnb_not_implemented

; Read and validate RIFF size/form, establishing physical and RIFF bounds.
; inputs:  agnb_fil is open and positioned at byte zero
; outputs: A=0 and Z set on success; nonzero error code and NZ set on failure
;          file size and RIFF end stored in agnb_state
; destroys: BC, DE, HL
agnb_read_riff_header:
; retain the physical u32 file size recorded by FatFS in the FIL object
    ld hl,(agnb_fil+fil_obj+ffobjid_objsize)
    ld (agnb_state+agnb_state_file_size),hl
    ld a,(agnb_fil+fil_obj+ffobjid_objsize+3)
    ld (agnb_state+agnb_state_file_size+3),a

; read the complete fixed-size RIFF header before inspecting any field
    ld bc,agnb_riff_header_size
    ld de,agnb_header
    call agnb_read_exact
    ret nz

; validate the RIFF container identifier
    ld hl,agnb_header+agnb_riff_id
    ld de,agnb_id_riff
    call agnb_compare_fourcc
    jr nz,@bad_riff_id

; validate that this RIFF contains the AGNB form
    ld hl,agnb_header+agnb_riff_form
    ld de,agnb_id_agnb
    call agnb_compare_fourcc
    jr nz,@bad_riff_form

; RIFF stores file size minus eight. Add the omitted bytes as u32, using the
; native 24-bit ALU for the low three bytes and A for the high byte.
    ld hl,(agnb_header+agnb_riff_size)
    ld a,(agnb_header+agnb_riff_size+3)
    ld de,8
    add hl,de
    jr nc,@riff_end_ready
    inc a
    jr z,@bad_bounds             ; u32 addition overflowed
@riff_end_ready:
    ld (agnb_state+agnb_state_riff_end),hl
    ld (agnb_state+agnb_state_riff_end+3),a

; Version 0.1 requires RIFF size to equal the physical file size minus eight.
    ld de,(agnb_state+agnb_state_file_size)
    or a
    sbc hl,de
    jr nz,@bad_bounds
    ld a,(agnb_state+agnb_state_riff_end+3)
    ld hl,agnb_state+agnb_state_file_size+3
    cp (hl)
    jr nz,@bad_bounds

; valid RIFF/AGNB header
    xor a
    ld (agnb_last_error),a
    ret

@bad_riff_id:
    ld a,agnb_error_riff_id
    jr @error
@bad_riff_form:
    ld a,agnb_error_riff_form
    jr @error
@bad_bounds:
    ld a,agnb_error_bounds
@error:
    ld (agnb_last_error),a
    or a
    ret

; Read a generic eight-byte chunk header into agnb_header and compute its
; aligned payload end without crossing the active RIFF/LIST boundary.
; inputs:  IX = pointer to the enclosing u32 end offset
; outputs: chunk size/end stored in agnb_state; file positioned at payload
; destroys: AF, BC, DE, HL
agnb_read_chunk_header:
    ld bc,agnb_chunk_header_size
    ld de,agnb_header
    call agnb_read_exact
    ret nz

; Retain the complete u32 payload size.
    ld hl,(agnb_header+agnb_chunk_size)
    ld (agnb_state+agnb_state_chunk_size),hl
    ld a,(agnb_header+agnb_chunk_size+3)
    ld (agnb_state+agnb_state_chunk_size+3),a

; The first byte after the payload is current file position + payload size.
    ld de,(agnb_state+agnb_state_file_offset)
    add hl,de
    ld (agnb_state+agnb_state_chunk_end),hl
    ld a,(agnb_header+agnb_chunk_size+3)
    ld b,a
    ld a,(agnb_state+agnb_state_file_offset+3)
    adc a,b
    jr c,@bad_bounds
    ld (agnb_state+agnb_state_chunk_end+3),a

; Reject a payload end beyond its enclosing RIFF or LIST boundary.
    cp (ix+3)
    jr c,@success
    jr nz,@bad_bounds
    ld de,(ix)
    or a
    sbc hl,de
    jr c,@success
    jr z,@success
@bad_bounds:
    ld a,agnb_error_bounds
    ld (agnb_last_error),a
    or a
    ret
@success:
    xor a
    ld (agnb_last_error),a
    ret

; Validate the single VERS payload and supported version.
; inputs:  file positioned at the VERS chunk header
; outputs: file positioned at the following top-level chunk
agnb_read_vers:
    ld ix,agnb_state+agnb_state_riff_end
    call agnb_read_chunk_header
    ret nz

    ld hl,agnb_header+agnb_chunk_id
    ld de,agnb_id_vers
    call agnb_compare_fourcc
    jp nz,@bad_chunk

    ld hl,(agnb_state+agnb_state_chunk_size)
    ld de,agnb_vers_payload_size
    or a
    sbc hl,de
    jr nz,@bad_version
    ld a,(agnb_state+agnb_state_chunk_size+3)
    or a
    jr nz,@bad_version

; Read the two-byte payload and its two required zero padding bytes together.
    ld bc,4
    ld de,agnb_header
    call agnb_read_exact
    ret nz
    ld a,(agnb_header+agnb_vers_major)
    cp agnb_version_major
    jr nz,@bad_version
    ld a,(agnb_header+agnb_vers_minor)
    cp agnb_version_minor
    jr nz,@bad_version
    ld a,(agnb_header+2)
    or a
    jr nz,@bad_chunk
    ld a,(agnb_header+3)
    or a
    jr nz,@bad_chunk
    xor a
    ld (agnb_last_error),a
    ret
@bad_version:
    ld a,agnb_error_version
    jr @error
@bad_chunk:
    ld a,agnb_error_chunk
@error:
    ld (agnb_last_error),a
    or a
    ret

; Parse one LIST BUFR and require BHDR, IMAG, DATA in that order.
; inputs:  file positioned at a LIST chunk header
; outputs: normalized metadata and DATA size retained; file positioned at DATA
agnb_read_buffer_list:
    xor a
    ld (agnb_record_flags),a

    ld ix,agnb_state+agnb_state_riff_end
    call agnb_read_chunk_header
    ret nz
    ld hl,agnb_header+agnb_chunk_id
    ld de,agnb_id_list
    call agnb_compare_fourcc
    jr nz,@bad_chunk

; LIST payload must at least contain its type and three nested chunk headers.
    ld hl,(agnb_state+agnb_state_chunk_size)
    ld de,3*agnb_chunk_header_size+agnb_list_type_size
    or a
    sbc hl,de
    jr c,@bad_chunk
    ld hl,(agnb_state+agnb_state_chunk_end)
    ld (agnb_state+agnb_state_list_end),hl
    ld a,(agnb_state+agnb_state_chunk_end+3)
    ld (agnb_state+agnb_state_list_end+3),a

    ld bc,agnb_list_type_size
    ld de,agnb_header
    call agnb_read_exact
    ret nz
    ld hl,agnb_header
    ld de,agnb_id_bufr
    call agnb_compare_fourcc
    jr nz,@bad_chunk

    call agnb_read_bhdr
    ret nz
    call agnb_read_imag
    ret nz

; Read and validate the DATA header, but deliberately leave its payload unread.
    ld ix,agnb_state+agnb_state_list_end
    call agnb_read_chunk_header
    ret nz
    ld hl,agnb_header+agnb_chunk_id
    ld de,agnb_id_data
    call agnb_compare_fourcc
    jr nz,@bad_chunk
    ld hl,(agnb_state+agnb_state_chunk_size)
    ld (agnb_metadata+agnb_meta_data_size),hl
    ld a,(agnb_state+agnb_state_chunk_size+3)
    ld (agnb_metadata+agnb_meta_data_size+3),a
    call agnb_validate_image_data_size
    ret nz
    ld a,(agnb_record_flags)
    or 1<<agnb_record_has_data
    ld (agnb_record_flags),a
    xor a
    ld (agnb_last_error),a
    ret
@bad_chunk:
    ld a,agnb_error_chunk
    ld (agnb_last_error),a
    or a
    ret

; Read and validate BHDR into agnb_metadata.
agnb_read_bhdr:
    ld ix,agnb_state+agnb_state_list_end
    call agnb_read_chunk_header
    ret nz
    ld hl,agnb_header+agnb_chunk_id
    ld de,agnb_id_bhdr
    call agnb_compare_fourcc
    jr nz,@bad_chunk
    ld hl,(agnb_state+agnb_state_chunk_size)
    ld de,agnb_bhdr_payload_size
    or a
    sbc hl,de
    jp nz,@bad_metadata
    ld a,(agnb_state+agnb_state_chunk_size+3)
    or a
    jp nz,@bad_metadata

; Read two payload bytes plus two zero padding bytes.
    ld bc,4
    ld de,agnb_header
    call agnb_read_exact
    ret nz
    ld a,(agnb_header+agnb_bhdr_bufferId)
    cp $FF
    jr nz,@store_bufferId
    ld a,(agnb_header+agnb_bhdr_bufferId+1)
    cp $FF
    jr z,@bad_bufferId
@store_bufferId:
    ld a,(agnb_header+agnb_bhdr_bufferId)
    ld (agnb_metadata+agnb_meta_bufferId),a
    ld a,(agnb_header+agnb_bhdr_bufferId+1)
    ld (agnb_metadata+agnb_meta_bufferId+1),a
    ld a,(agnb_header+2)
    or a
    jr nz,@bad_chunk
    ld a,(agnb_header+3)
    or a
    jr nz,@bad_chunk
    ld a,(agnb_record_flags)
    or 1<<agnb_record_has_bhdr
    ld (agnb_record_flags),a
    xor a
    ld (agnb_last_error),a
    ret
@bad_bufferId:
    ld a,agnb_error_bufferId
    jr @error
@bad_metadata:
    ld a,agnb_error_metadata
    jr @error
@bad_chunk:
    ld a,agnb_error_chunk
@error:
    ld (agnb_last_error),a
    or a
    ret

; Read and validate IMAG into agnb_metadata.
agnb_read_imag:
    ld ix,agnb_state+agnb_state_list_end
    call agnb_read_chunk_header
    ret nz
    ld hl,agnb_header+agnb_chunk_id
    ld de,agnb_id_imag
    call agnb_compare_fourcc
    jp nz,@bad_chunk
    ld hl,(agnb_state+agnb_state_chunk_size)
    ld de,agnb_imag_payload_size
    or a
    sbc hl,de
    jp nz,@bad_metadata
    ld a,(agnb_state+agnb_state_chunk_size+3)
    or a
    jp nz,@bad_metadata

; Read five payload bytes plus three zero padding bytes.
    ld bc,8
    ld de,agnb_header
    call agnb_read_exact
    ret nz
    ld a,(agnb_header+agnb_imag_width)
    ld hl,agnb_header+agnb_imag_width+1
    or (hl)
    jp z,@bad_metadata
    ld a,(agnb_header+agnb_imag_width)
    ld (agnb_metadata+agnb_meta_width),a
    ld a,(agnb_header+agnb_imag_width+1)
    ld (agnb_metadata+agnb_meta_width+1),a
    ld a,(agnb_header+agnb_imag_height)
    ld hl,agnb_header+agnb_imag_height+1
    or (hl)
    jp z,@bad_metadata
    ld a,(agnb_header+agnb_imag_height)
    ld (agnb_metadata+agnb_meta_height),a
    ld a,(agnb_header+agnb_imag_height+1)
    ld (agnb_metadata+agnb_meta_height+1),a
    ld a,(agnb_header+agnb_imag_format)
    cp agnb_image_rgba2222
    jr nz,@bad_metadata
    ld (agnb_metadata+agnb_meta_format),a
    ld hl,(agnb_header+5)
    ld de,0
    or a
    sbc hl,de
    jr nz,@bad_chunk
    ld a,(agnb_record_flags)
    or 1<<agnb_record_has_imag
    ld (agnb_record_flags),a
    xor a
    ld (agnb_last_error),a
    ret
@bad_metadata:
    ld a,agnb_error_metadata
    jr @error
@bad_chunk:
    ld a,agnb_error_chunk
@error:
    ld (agnb_last_error),a
    or a
    ret

; Calculate the expected RGBA2222 payload size.
; inputs:  width and height in agnb_metadata
; outputs: HL = width * height (unsigned 24-bit)
;          u32 result retained in agnb_expected_data_size
; destroys: AF, HL
;
; IMPORTANT: umul24 discards product bits above bit 23. That theoretical limit
; is 16,777,215 bytes/pixels--orders of magnitude larger than any conceivable
; bitmap on the Agon. The initial image loader therefore deliberately uses the
; smaller native-ADL result instead of carrying a general u16*u16=u32 routine.
agnb_calculate_image_data_size:
; Load each contiguous u16 field as UHL, then use the established eZ80 idiom
; to discard the accidentally loaded following byte.
    ld hl,(agnb_metadata+agnb_meta_height)
    dec hl
    inc.s hl ; undocumented: preserves HL and clears HLU
    ex de,hl
    ld hl,(agnb_metadata+agnb_meta_width)
    dec hl
    inc.s hl ; undocumented: preserves HL and clears HLU
    call umul24
    ld (agnb_expected_data_size),hl
    xor a
    ld (agnb_expected_data_size+3),a
    ret

; Validate the current RGBA2222 DATA size against width * height.
; inputs:  normalized IMAG metadata and DATA size in agnb_metadata
; outputs: A=0 and Z set on success
;          A=agnb_error_data_size and NZ set on mismatch
; destroys: AF, DE, HL
agnb_validate_image_data_size:
    call agnb_calculate_image_data_size

; A 24-bit calculated size can match only a declared u32 whose high byte is 0.
    ld a,(agnb_metadata+agnb_meta_data_size+3)
    or a
    jr nz,@bad_size

; Compare the native 24-bit product with the low three declared size bytes.
    ld de,(agnb_metadata+agnb_meta_data_size)
    or a
    sbc hl,de
    jr nz,@bad_size
    xor a
    ld (agnb_last_error),a
    ret
@bad_size:
    ld a,agnb_error_data_size
    ld (agnb_last_error),a
    or a
    ret

; Stream the current DATA payload into agnb_meta_bufferId in bounded blocks,
; then consolidate the completed VDP buffer. This routine is form-agnostic;
; callers perform image-, audio-, or other form-specific finalization.
agnb_stream_data:
; Retain the complete 24-bit transfer count. The image metadata gate has
; already required the declared DATA high byte to be zero.
    ld hl,(agnb_metadata+agnb_meta_data_size)
    ld (agnb_stream_remaining),hl

; Clear the exact writer-specified destination before appending any blocks.
    ld hl,(agnb_metadata+agnb_meta_bufferId)
    dec hl
    inc.s hl ; undocumented: preserves bufferId in HL and clears HLU
    call vdu_clear_buffer

@next_block:
; A zero remaining count means every declared payload byte was transferred.
    ld hl,(agnb_stream_remaining)
    ld de,0
    or a
    sbc hl,de
    jr z,@complete

; Select min(remaining, agnb_io_buffer_size) without truncating the final block.
    ld hl,(agnb_stream_remaining)
    ld de,agnb_io_buffer_size
    or a
    sbc hl,de
    jr c,@use_remaining
    ld bc,agnb_io_buffer_size
    jr @read_block
@use_remaining:
    ld bc,(agnb_stream_remaining)
@read_block:
    ld (agnb_stream_block_size),bc

; Read exactly this block from the DATA payload into the shared 8 KiB SRAM.
    ld de,agnb_io_buffer
    call agnb_read_exact
    ret nz

; Append the complete block to the same writer-specified VDP buffer.
    ld bc,(agnb_stream_block_size)
    ld de,agnb_io_buffer
    ld hl,(agnb_metadata+agnb_meta_bufferId)
    dec hl
    inc.s hl ; undocumented: preserves bufferId in HL and clears HLU
    call vdu_load_buffer

; Account for the uploaded block and continue until no bytes remain.
    ld hl,(agnb_stream_remaining)
    ld de,(agnb_stream_block_size)
    or a
    sbc hl,de
    jr c,@bad_bounds
    ld (agnb_stream_remaining),hl
    jr @next_block

@complete:
; Exact accounting should place the logical reader at the first byte after the
; DATA payload. Check all four offset bytes before reporting success.
    ld hl,(agnb_state+agnb_state_file_offset)
    ld de,(agnb_state+agnb_state_chunk_end)
    or a
    sbc hl,de
    jr nz,@bad_bounds
    ld a,(agnb_state+agnb_state_file_offset+3)
    ld hl,agnb_state+agnb_state_chunk_end+3
    cp (hl)
    jr nz,@bad_bounds

; Only a complete, exactly bounded transfer may be consolidated.
    ld hl,(agnb_metadata+agnb_meta_bufferId)
    dec hl
    inc.s hl ; undocumented: preserves bufferId in HL and clears HLU
    call vdu_consolidate_buffer

    xor a
    ld (agnb_last_error),a
    ret

@bad_bounds:
    ld a,agnb_error_bounds
    ld (agnb_last_error),a
    or a
    ret

; Create an image bitmap from the successfully streamed and consolidated
; buffer using the retained IMAG metadata.
; outputs: A=0 and Z set
; destroys: AF, BC, DE, HL
agnb_finalize_image:
; Select the exact writer-specified buffer as the bitmap source.
    ld hl,(agnb_metadata+agnb_meta_bufferId)
    dec hl
    inc.s hl ; undocumented: preserves bufferId in HL and clears HLU
    call vdu_buff_select

; The five retained IMAG bytes already have the VDP's width/height/format
; ordering. Load their fields into the existing vdu_bmp_create contract.
    ld bc,(agnb_metadata+agnb_meta_width)
    dec bc
    inc.s bc ; preserve width in BC and clear BCU
    ld de,(agnb_metadata+agnb_meta_height)
    dec de
    inc.s de ; preserve height in DE and clear DEU
    ld a,(agnb_metadata+agnb_meta_format)
    call vdu_bmp_create
    xor a
    ld (agnb_last_error),a
    ret

; Consume the current DATA chunk's zero alignment padding and require the
; resulting position to equal the enclosing LIST payload end exactly.
; outputs: A=0 and Z set on success; error code and NZ on failure
; destroys: AF, BC, DE, HL
agnb_finish_buffer_list:
; padding = (-payload_size) & 3
    ld a,(agnb_metadata+agnb_meta_data_size)
    neg
    and 3
    ld (agnb_padding_size),a
    jr z,@check_list_end

    ld bc,0
    ld c,a
    ld de,agnb_header
    call agnb_read_exact
    ret nz

; Version 0.1 writers emit only zero-valued alignment padding.
    ld a,(agnb_padding_size)
    ld b,a
    ld hl,agnb_header
@check_padding:
    ld a,(hl)
    or a
    jr nz,@bad_chunk
    inc hl
    djnz @check_padding

@check_list_end:
    ld hl,(agnb_state+agnb_state_file_offset)
    ld de,(agnb_state+agnb_state_list_end)
    or a
    sbc hl,de
    jr nz,@bad_bounds
    ld a,(agnb_state+agnb_state_file_offset+3)
    ld hl,agnb_state+agnb_state_list_end+3
    cp (hl)
    jr nz,@bad_bounds
    xor a
    ld (agnb_last_error),a
    ret

@bad_chunk:
    ld a,agnb_error_chunk
    jr @error
@bad_bounds:
    ld a,agnb_error_bounds
@error:
    ld (agnb_last_error),a
    or a
    ret

; Skip an unknown or deliberately ignored chunk, including alignment padding,
; without crossing the active enclosing boundary.
agnb_skip_chunk:
    jp agnb_not_implemented

; Round a u32 size or offset up to the next four-byte boundary.
; Calling convention will be finalized with the 32-bit arithmetic helper.
agnb_align4:
    jp agnb_not_implemented

; Common fail-closed body used by every scaffolded routine.
agnb_not_implemented:
    ld a,agnb_error_not_implemented
    ld (agnb_last_error),a
    or a ; return NZ
    ret
; AGNB 0.2 audio loader
; =====================
;
; The generic RIFF/AGNB file, chunk, bounds, streaming, buffer-clear, buffer-
; load, and buffer-consolidation routines remain in agnb_api.inc. This file adds
; the audio-specific record path for:
;
;     LIST BUFR
;       BHDR  u16 bufferId
;       AUDI  u8 vdpFormat=0x09; u16 sampleRate
;       DATA  unsigned 8-bit mono PCM bytes
;
; AUDI format 0x09 means VDP base format 1 (unsigned 8-bit mono) with bit 3
; set to record that an explicit u16 sample rate follows. vdu_buffer_to_sound
; accepts the base format and adds bit 3 itself, so finalization masks it off.

agnb_audio_version_major:  equ 0
agnb_audio_version_minor:  equ 2

agnb_audi_format:          equ 0 ; u8 VDP sample format byte
agnb_audi_sample_rate:     equ 1 ; u16 Hz
agnb_audi_payload_size:    equ 3

agnb_audio_vdp_format:     equ 0x09 ; unsigned 8-bit mono + sample rate follows

agnb_id_audi:              db "AUDI"

; Normalized metadata retained until DATA has been validated and streamed.
agnb_audio_meta_bufferId:  equ 0 ; u16 writer-specified VDP bufferId
agnb_audio_meta_format:    equ 2 ; u8 VDP format; version 0.2 requires 0x09
agnb_audio_meta_rate:      equ 3 ; u16 sample rate in Hz
agnb_audio_meta_data_size: equ 5 ; u32 DATA payload size
agnb_audio_meta_size:      equ 9

agnb_audio_metadata:
    blkb agnb_audio_meta_size,0

; Application callback invoked after each audio sample has been finalized.
agnb_audio_callback:       dl 0

; Load every valid audio record at its explicit bufferId. Playback remains the
; application's responsibility.
; inputs:  DE = zero-terminated container filename
; outputs: A=0/Z after the complete container; error code/NZ on failure
; destroys: AF, BC, DE, HL, IX
agnb_load_audio:
    ld hl,agnb_audio_callback_noop

; Callback-enabled audio loader.
; inputs: DE = filename; HL = callback whose result is ignored
agnb_load_audio_with_callback:
    ld (agnb_audio_callback),hl
    call agnb_open
    ret nz

    call agnb_read_riff_header
    jr nz,@load_error
    call agnb_read_audio_vers
    jr nz,@load_error

@next_record:
; Stop only at the exact declared RIFF boundary.
    ld a,(agnb_state+agnb_state_file_offset+3)
    ld hl,agnb_state+agnb_state_riff_end+3
    cp (hl)
    jr c,@read_record
    jr nz,@bad_bounds
    ld hl,(agnb_state+agnb_state_file_offset)
    ld de,(agnb_state+agnb_state_riff_end)
    or a
    sbc hl,de
    jr z,@success
    jr nc,@bad_bounds

@read_record:
    call agnb_read_audio_buffer_list
    jr nz,@load_error
    call agnb_stream_data
    jr nz,@load_error
    call agnb_finalize_audio
    jr nz,@load_error

; Give the application one completed-sample boundary per record.
; Metadata remains valid for the duration of the callback.
    call agnb_call_audio_callback

    call agnb_finish_buffer_list
    jr nz,@load_error
    jr @next_record

@bad_bounds:
    ld a,agnb_error_bounds
    ld (agnb_last_error),a
@load_error:
; Preserve the parser/transport error while still closing the file.
    push af
    call agnb_close
    pop af
    ld (agnb_last_error),a
    or a
    ret

@success:
    jp agnb_close

; Tail-jump to the selected callback so its RET resumes the loader without
; clobbering BC.
agnb_call_audio_callback:
    ld hl,(agnb_audio_callback)
    jp (hl)

agnb_audio_callback_noop:
    xor a
    ret

; Read and validate the single VERS chunk for the provisional audio layout.
agnb_read_audio_vers:
    ld ix,agnb_state+agnb_state_riff_end
    call agnb_read_chunk_header
    ret nz

    ld hl,agnb_header+agnb_chunk_id
    ld de,agnb_id_vers
    call agnb_compare_fourcc
    jp nz,@bad_chunk

    ld hl,(agnb_state+agnb_state_chunk_size)
    ld de,agnb_vers_payload_size
    or a
    sbc hl,de
    jr nz,@bad_version
    ld a,(agnb_state+agnb_state_chunk_size+3)
    or a
    jr nz,@bad_version

; Read the two-byte payload and two required zero padding bytes.
    ld bc,4
    ld de,agnb_header
    call agnb_read_exact
    ret nz
    ld a,(agnb_header+agnb_vers_major)
    cp agnb_audio_version_major
    jr nz,@bad_version
    ld a,(agnb_header+agnb_vers_minor)
    cp agnb_audio_version_minor
    jr nz,@bad_version
    ld a,(agnb_header+2)
    or a
    jr nz,@bad_chunk
    ld a,(agnb_header+3)
    or a
    jr nz,@bad_chunk
    xor a
    ld (agnb_last_error),a
    ret

@bad_version:
    ld a,agnb_error_version
    jr @error
@bad_chunk:
    ld a,agnb_error_chunk
@error:
    ld (agnb_last_error),a
    or a
    ret

; Parse one LIST BUFR and require BHDR, AUDI, DATA in that order. All metadata,
; DATA size, and enclosing bounds validate before any PCM payload is read.
agnb_read_audio_buffer_list:
    xor a
    ld (agnb_record_flags),a

    ld ix,agnb_state+agnb_state_riff_end
    call agnb_read_chunk_header
    ret nz
    ld hl,agnb_header+agnb_chunk_id
    ld de,agnb_id_list
    call agnb_compare_fourcc
    jp nz,@bad_chunk

; LIST must contain its type and three nested chunk headers at minimum.
    ld hl,(agnb_state+agnb_state_chunk_size)
    ld de,3*agnb_chunk_header_size+agnb_list_type_size
    or a
    sbc hl,de
    jp c,@bad_chunk
    ld hl,(agnb_state+agnb_state_chunk_end)
    ld (agnb_state+agnb_state_list_end),hl
    ld a,(agnb_state+agnb_state_chunk_end+3)
    ld (agnb_state+agnb_state_list_end+3),a

    ld bc,agnb_list_type_size
    ld de,agnb_header
    call agnb_read_exact
    ret nz
    ld hl,agnb_header
    ld de,agnb_id_bufr
    call agnb_compare_fourcc
    jp nz,@bad_chunk

; Reuse the proven BHDR reader and mirror its normalized bufferId.
    call agnb_read_bhdr
    ret nz
    ld a,(agnb_metadata+agnb_meta_bufferId)
    ld (agnb_audio_metadata+agnb_audio_meta_bufferId),a
    ld a,(agnb_metadata+agnb_meta_bufferId+1)
    ld (agnb_audio_metadata+agnb_audio_meta_bufferId+1),a

    call agnb_read_audi
    ret nz

; Read and validate DATA header, leaving the PCM payload unread for streaming.
    ld ix,agnb_state+agnb_state_list_end
    call agnb_read_chunk_header
    ret nz
    ld hl,agnb_header+agnb_chunk_id
    ld de,agnb_id_data
    call agnb_compare_fourcc
    jp nz,@bad_chunk

    ld hl,(agnb_state+agnb_state_chunk_size)
    ld (agnb_metadata+agnb_meta_data_size),hl
    ld (agnb_audio_metadata+agnb_audio_meta_data_size),hl
    ld a,(agnb_state+agnb_state_chunk_size+3)
    ld (agnb_metadata+agnb_meta_data_size+3),a
    ld (agnb_audio_metadata+agnb_audio_meta_data_size+3),a
    call agnb_validate_audio_data
    ret nz

    ld a,(agnb_record_flags)
    or 1<<agnb_record_has_data
    ld (agnb_record_flags),a
    xor a
    ld (agnb_last_error),a
    ret

@bad_chunk:
    ld a,agnb_error_chunk
    ld (agnb_last_error),a
    or a
    ret

; Read the three-byte AUDI payload plus its required zero padding byte.
agnb_read_audi:
    ld ix,agnb_state+agnb_state_list_end
    call agnb_read_chunk_header
    ret nz
    ld hl,agnb_header+agnb_chunk_id
    ld de,agnb_id_audi
    call agnb_compare_fourcc
    jr nz,@bad_chunk

    ld hl,(agnb_state+agnb_state_chunk_size)
    ld de,agnb_audi_payload_size
    or a
    sbc hl,de
    jr nz,@bad_metadata
    ld a,(agnb_state+agnb_state_chunk_size+3)
    or a
    jr nz,@bad_metadata

    ld bc,4
    ld de,agnb_header
    call agnb_read_exact
    ret nz
    ld a,(agnb_header+agnb_audi_format)
    cp agnb_audio_vdp_format
    jr nz,@bad_metadata
    ld (agnb_audio_metadata+agnb_audio_meta_format),a

; Sample rate must be nonzero. Its u16 storage already enforces the VDP limit.
    ld a,(agnb_header+agnb_audi_sample_rate)
    ld hl,agnb_header+agnb_audi_sample_rate+1
    or (hl)
    jr z,@bad_metadata
    ld a,(agnb_header+agnb_audi_sample_rate)
    ld (agnb_audio_metadata+agnb_audio_meta_rate),a
    ld a,(agnb_header+agnb_audi_sample_rate+1)
    ld (agnb_audio_metadata+agnb_audio_meta_rate+1),a

    ld a,(agnb_header+3)
    or a
    jr nz,@bad_chunk
    ld a,(agnb_record_flags)
    or 1<<agnb_record_has_imag ; descriptor-present bit is shared with IMAG
    ld (agnb_record_flags),a
    xor a
    ld (agnb_last_error),a
    ret

@bad_metadata:
    ld a,agnb_error_metadata
    jr @error
@bad_chunk:
    ld a,agnb_error_chunk
@error:
    ld (agnb_last_error),a
    or a
    ret

; Audio DATA must be nonempty and fit the generic loader's u24 stream counter.
agnb_validate_audio_data:
    ld a,(agnb_audio_metadata+agnb_audio_meta_data_size+3)
    or a
    jr nz,@bad_size
    ld hl,(agnb_audio_metadata+agnb_audio_meta_data_size)
    ld de,0
    or a
    sbc hl,de
    jr z,@bad_size
    xor a
    ld (agnb_last_error),a
    ret
@bad_size:
    ld a,agnb_error_data_size
    ld (agnb_last_error),a
    or a
    ret

; Convert the consolidated buffer to a VDP audio sample using the retained
; writer-specified bufferId, unsigned base format, and explicit sample rate.
agnb_finalize_audio:
    ld hl,(agnb_audio_metadata+agnb_audio_meta_bufferId)
    dec hl
    inc.s hl ; preserve u16 bufferId and clear HLU
    ld de,(agnb_audio_metadata+agnb_audio_meta_rate)
    dec de
    inc.s de ; preserve u16 sample rate and clear DEU
    ld a,(agnb_audio_metadata+agnb_audio_meta_format)
    and $07 ; vdu_buffer_to_sound adds the sample-rate-present bit itself
    call vdu_buffer_to_sound
    xor a
    ld (agnb_last_error),a
    ret
