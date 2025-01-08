ps_prt_reload: equ [72000/2]+1 ; 2 ticks per second at 18.432 MHz with a 256 clock divider

; start PRT timer
ps_prt_start:
    ld hl,0
    ld (ps_prt_irq_counter),hl
    ld hl,ps_prt_reload
    out0 (TMR1_CTL+TMR_RES_LOW),l
	out0 (TMR1_CTL+TMR_RES_HIGH),h
; disable timer (in effect, reset it)
    ld a,PRT_IRQ_0 | IRQ_EN_0 | PRT_MODE_0 | CLK_DIV_256 | RST_EN_1 | PRT_EN_0
	out0 (TMR1_CTL+TMR_REG_CTL),a
; enable timer,with interrupt and CONTINUOUS mode,clock divider 256
    ld a,PRT_IRQ_0 | IRQ_EN_1 | PRT_MODE_1 | CLK_DIV_256 | RST_EN_1 | PRT_EN_1
	out0 (TMR1_CTL+TMR_REG_CTL),a
    ret

; stop PRT timer
ps_prt_stop:
    ld a,PRT_IRQ_0 | IRQ_EN_0 | PRT_MODE_0 | CLK_DIV_256 | RST_EN_1 | PRT_EN_0
	out0 (TMR1_CTL+TMR_REG_CTL),a
    ret

; ===============================================
; PRT Timer Interrupt Handling
; https://github.com/tomm/agon-cpu-emulator/blob/main/sdcard/regression_suite/timerirq.asm
; -----------------------------------------------
ps_prt_irq_init:
    ; set up interrupt vector table 2
	ld hl,0
	ld a,($10c)
	ld l,a
	ld a,($10d)
	ld h,a

	; skip over CALL ($c3)
	inc hl
	; load address of jump into vector table 2 (in ram)
	ld hl,(hl)

	; write CALL ps_prt_irq_handler to vector table 2
	ld a,$c3
	ld (hl),a
	inc hl
	ld de,ps_prt_irq_handler
	ld (hl),de

    ret
; end ps_prt_irq_init

; interrupt routine for playing the next sample
ps_prt_irq_counter:
	db 0
ps_prt_irq_handler:
	di
	ex af,af'
    exx
	in0 a,(TMR1_CTL+TMR_REG_CTL)
    ld a,(ps_prt_irq_counter)
    inc a
    and 1 ; modulo 2
    ld (ps_prt_irq_counter),a
    call z,ps_play_sample
    exx
    ex af,af'
	ei
	reti.l
; end ps_prt_irq_handler