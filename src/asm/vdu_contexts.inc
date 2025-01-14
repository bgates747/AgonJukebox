; https://agonconsole8.github.io/agon-docs/vdp/Context-Management-API/

; VDU 23, 0, $C8, 0, contextId: Select context stack
; inputs: hl = contextId
; outputs: nothing
; prerequisites: none
; destroys: af, bc, hl
vdu_select_context_stack:
    ld (@contextId),hl
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 0
@contextId: dw 0x0000
@end: db 0x00 ; padding
; end vdu_select_context_stack

; VDU 23, 0, $C8, 1, contextId: Delete context stack
; inputs: hl = contextId
; outputs: nothing
; prerequisites: none
; destroys: af, bc, hl
vdu_delete_context_stack:
    ld (@contextId),hl
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 1
@contextId: dw 0x0000
@end: db 0x00 ; padding
; end vdu_delete_context_stack

; VDU 23, 0, $C8, 2, flags: Reset the current context
; inputs: a = flags
; outputs: nothing
; prerequisites: vdu_select_context_stack
; destroys: af, hl, bc
; flags:
; Bit	Description
; 0	Reset graphics painting options
; 1	Reset graphics positioning settings, including graphics viewport and coordinate system
; 2	Reset text painting options
; 3	Reset text cursor visual settings, including text viewport
; 4	Reset text cursor behaviour
; 5	Reset currently selected fonts
; 6	Reset character to bitmap mappings
; 7	Reserved for future use
vdu_reset_context:
    ld (@flags),a
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 2
@flags: db 0x00
@end:
; end vdu_reset_context

; VDU 23, 0, $C8, 3: Save context
; inputs: none
; outputs: nothing
; prerequisites: vdu_select_context_stack
; destroys: af, bc, hl
vdu_save_context:
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 3
@end:
; end vdu_save_context

; VDU 23, 0, $C8, 4: Restore context
; inputs: none
; outputs: nothing
; prerequisites: vdu_select_context_stack
; destroys: af, bc, hl
vdu_restore_context:
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 4
@end:
; end vdu_restore_context

; VDU 23, 0, $C8, 5, contextId: Save and select a copy of a context
; inputs: hl = contextId
; outputs: nothing
; prerequisites: graphics / text context in the state to save
vdu_select_and_save_context:
    ld (@contextId),hl
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 5
@contextId: dw 0x0000
@end: db 0x00 ; padding
; end vdu_select_and_save_context

; VDU 23, 0, $C8, 6: Restore all contexts
; inputs: none
; outputs: nothing
; prerequisites: none
; destroys: af, bc, hl
vdu_restore_all_contexts:
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 6
@end:
; end vdu_restore_all_contexts

; VDU 23, 0, $C8, 7: Clear stack
; inputs: none
; outputs: nothing
; prerequisites: none
; destroys: af, bc, hl
vdu_clear_context_stack:
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd: db 23, 0, $C8, 7
@end:
; end vdu_clear_context_stack