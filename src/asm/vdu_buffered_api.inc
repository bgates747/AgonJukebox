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
@bufferId:	dw 0x0000
            db 0 ; load buffer
@length:	dw 0x0000
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
@cmd:     db 23,0,0xA0
@bufferId: dw 0x0000
           db 1 ; call buffer
@end:
; end vdu_call_buffer

; Command 2: Clear a buffer
; VDU 23, 0 &A0, bufferId; 2
; inputs: hl = bufferId
vdu_clear_buffer:
    ld (@bufferId),hl
    ld a,2 ; clear buffer
    ld (@bufferId+2),a
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd:     db 23,0,0xA0
@bufferId: dw 0x0000
           db 2 ; clear buffer
@end: 
; end vdu_clear_buffer

; Clear all buffers
; inputs: none
vdu_clear_all_buffers:
; clear all buffers
    ld hl,@beg
    ld bc,@end-@beg
    rst.lil $18
    ret
@beg: db 23,0,$A0
      dw -1 ; bufferId -1 (65535) means clear all buffers
      db 2  ; command 2: clear a buffer
@end:
; end vdu_clear_all_buffers

; Command 3: Create a writeable buffer
; VDU 23, 0 &A0, bufferId; 3, length;
; inputs: hl = bufferId, bc = length
vdu_create_writeable_buffer:
    ld (@bufferId),hl
    ld (@length),bc
    ld a,3 ; create writeable buffer
    ld (@bufferId+2),a
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd:     db 23,0,0xA0
@bufferId: dw 0x0000
           db 3 ; create writeable buffer
@length: dw 0x0000
@end:     db 0x00 ; padding
; end vdu_create_writeable_buffer

; Command 4: Set output stream to a buffer
; VDU 23, 0 &A0, bufferId; 4
; inputs: hl = bufferId
vdu_set_output_stream_buffer:
    ld (@bufferId),hl
    ld a,4 ; set output stream to buffer
    ld (@bufferId+2),a
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd:     db 23,0,0xA0
@bufferId: dw 0x0000
           db 4 ; set output stream to buffer
@end:     db 0x00 ; padding
; end vdu_set_output_stream_buffer

; Command 5: Adjust buffer contents
; VDU 23, 0, &A0, bufferId; 5, operation, offset; [count;] <operand>, [arguments]
vdu_adjust_buffer:
    ret ; TODO: implement
; end vdu_adjust_buffer

; Command 6: Conditionally call a buffer
; VDU 23, 0, &A0, bufferId; 6, operation, checkBufferId; checkOffset; [arguments]
vdu_call_buffer_conditional:
    ret ; TODO: implement
; end vdu_call_buffer_conditional

; Command 7: Jump to a buffer
; VDU 23, 0, &A0, bufferId; 7
; inputs: hl = bufferId
vdu_jump_to_buffer:
    ld (@bufferId),hl
    ld a,7 ; jump to buffer
    ld (@bufferId+2),a
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd:     db 23,0,0xA0
@bufferId: dw 0x0000
           db 7 ; jump to buffer
@end:     db 0x00 ; padding
; end vdu_jump_to_buffer

; Command 8: Conditional Jump to a buffer
; VDU 23, 0, &A0, bufferId; 8, operation, checkBufferId; checkOffset; [arguments]
vdu_jump_to_buffer_conditional:
    ret ; TODO: implement
; end vdu_jump_to_buffer_conditional

; Command 9: Jump to an offset in a buffer
; VDU 23, 0, &A0, bufferId; 9, offset; offsetHighByte, [blockNumber;]
vdu_jump_to_buffer_offset:
    ret ; TODO: implement
; end vdu_jump_to_buffer_offset

; Command 10: Conditional jump to an offset in a buffer
; VDU 23, 0, &A0, bufferId; 10, offset; offsetHighByte, [blockNumber;] [arguments]
vdu_jump_to_buffer_offset_conditional:
    ret ; TODO: implement
; end vdu_jump_to_buffer_offset_conditional

; Command 11: Call buffer with an offset
; VDU 23, 0, &A0, bufferId; 11, offset; offsetHighByte, [blockNumber;]
vdu_call_buffer_offset:
    ret ; TODO: implement
; end vdu_call_buffer_offset

