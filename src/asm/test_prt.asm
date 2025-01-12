    assume adl=1 
    org 0x040000 
    jp start 
    align 64 
    db "MOS" 
    db 00h 
    db 01h 

start: 
    push af
    push bc
    push de
    push ix
    push iy

    call init
    call main

exit:
    pop iy
    pop ix
    pop de
    pop bc
    pop af
    ld hl,0

    ret

; API INCLUDES
    include "mos_api.inc"
    include "macros.inc"
    include "functions.inc"
    include "arith24.inc"
    include "maths.inc"
    include "files.inc"
    include "fixed168.inc"
    include "timer_test.inc" ; DEBUG
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    include "vdu_fonts.inc"
    include "vdu_plot.inc"
    include "vdu_sound.inc"

; APPLICATION INCLUDES
    include "debug.inc"

; --- MAIN PROGRAM FILE ---
init:
; initialize play sample timer interrupt handler
    call prt_irq_init
    call printNewLine
    ret
; end init

main:
; set a loop counter for multiple tests
    ld b,10
@start:
    push bc
; synchronise MOS timer with VBLANK
    call vdu_vblank
; set a MOS timer
    ld iy,tmr_test
    ld hl,[120*1] ; 120 ticks per second
    call tmr_set
; start the PRT timer
    call prt_start
@loop:
; check MOS timer
    call tmr_get
    jp z,@F
    jp m,@F
    jp @loop
@@: ; stop the PRT timer
    call prt_stop
; display the interrupt count
    ld hl,(prt_irq_counter)
    call printDec
    call printNewLine
; decrement the loop counter
    pop bc
    djnz @start
    ret
; end main