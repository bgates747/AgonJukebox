; Convert a consolidated buffer to a sample.
; Inputs: HL=bufferId, A=base format (0 signed, 1 unsigned), DE=sample rate.
vdu_buffer_to_sound:
    ld (@bufferId),hl
    add a,8
    ld (@format),a
    ld (@sampleRate),de
    ld hl,@cmd
    ld bc,@end-@cmd
    rst.lil $18
    ret
@cmd:        db 23,0,$85
             db 0,5,2
@bufferId:   dw 0
@format:     db 0
@sampleRate: dw 0
; Native ADL stores three bytes from DE. This excluded byte absorbs DEU.
@end:        db 0
