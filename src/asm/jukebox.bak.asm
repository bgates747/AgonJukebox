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
    include "timer.inc"
    include "vdu.inc"
    include "vdu_buffered_api.inc"
    include "vdu_fonts.inc"
    include "vdu_plot.inc"
    include "vdu_sound.inc"

; APPLICATION INCLUDES
    include "music.inc"

; --- MAIN PROGRAM FILE ---
init:
; load sound effects files
    call printInline
    asciz "Loading SFX...\r\n"
    call load_sfx_AFRICA
    call load_sfx_COME_UNDONE
    call load_sfx_EVERY_BREATH_YOU_TAKE
    call load_sfx_RHIANNON
    call load_sfx_SPACE_ADVENTURE
    call printInline
    asciz "SFX loaded.\r\n"
    ret
; end init

main:


@loop:
    call waitKeypress
    cp '\e'
    ret z
    cp '1'
    call z, sfx_play_AFRICA
    cp '2'
    call z, sfx_play_COME_UNDONE
    cp '3'
    call z, sfx_play_EVERY_BREATH_YOU_TAKE
    cp '4'
    call z, sfx_play_RHIANNON
    cp '5'
    call z, sfx_play_SPACE_ADVENTURE
    jp @loop
; end main

