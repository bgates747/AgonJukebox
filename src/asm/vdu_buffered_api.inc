; https://agonconsole8.github.io/agon-docs/vdp/Buffered-Commands-API/

; Command 0: Write block to a buffer
; VDU 23, 0, &A0, bufferId; 0, length; <buffer-data>
; inputs: hl = bufferId, bc = length of data, de = pointer to data
vdu_write_block_to_buffer:
; back up input parameters
    push de ; pointer to data
    push bc ; length of data
; set up the vdu command string
    ld (@bufferId),hl
    ld (@length),bc
    xor a ; load buffer
    ld (@bufferId+2),a
    ld hl,@cmd0
    ld bc,@end0-@cmd0
    rst.lil $18
; send the buffer data
    pop bc ; length of data
    pop hl ; pointer to data (was de)
    rst.lil $18 ; send it
    ret
; command string data
@cmd0:      db 23,0,0xA0
@bufferId:  dw 0x0000
            db 0 ; load buffer
@length:    dw 0x0000
@end0:      db 0x00 ; padding
; end vdu_write_block_to_buffer

; Command 1: Call a buffer
; VDU 23, 0, &A0, bufferId; 1
; inputs: hl = bufferId
vdu_call_buffer:
    ld (@bufferId),hl
    ld a,1 ; call buffer
    ld (@bufferId+2),a
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd:      db 23,0,0xA0
@bufferId: dw 0x0000
           db 1 ; call buffer
@end:
; end vdu_call_buffer

; Command 2: Clear a buffer
; VDU 23, 0, &A0, bufferId; 2
; inputs: hl = bufferId
vdu_clear_buffer:
    ld (@bufferId),hl
    ld a,2 ; clear buffer
    ld (@bufferId+2),a
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd:      db 23,0,0xA0
@bufferId: dw 0x0000
           db 2 ; clear buffer
@end:
; end vdu_clear_buffer
