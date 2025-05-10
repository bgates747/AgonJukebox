; Table 32. Timer Control Registers
TMR0_CTL: equ 80h 
TMR1_CTL: equ 83h
TMR2_CTL: equ 86h 
TMR3_CTL: equ 89h 
TMR4_CTL: equ 8Ch
TMR5_CTL: equ 8Fh

; each timer register takes three bytes:
;   0: control register
;   1: low byte of timer reset value
;   2: high byte of timer reset value
; note that the value is only 8-bits,so we use in0/out0 i/o calls,
; which correctly force the high and upper bytes of the address bus to zero

TMR_REG_CTL: equ 0
TMR_RES_LOW: equ 1
TMR_RES_HIGH: equ 2

; Timer Control Register Bit Definitions
PRT_IRQ_0:    equ %00000000 ; The timer does not reach its end-of-count value. 
                            ; This bit is reset to 0 every time the TMRx_CTL register is read.
PRT_IRQ_1:    equ %10000000 ; The timer reaches its end-of-count value. If IRQ_EN is set to 1,
                            ; an interrupt signal is sent to the CPU. This bit remains 1 until 
                            ; the TMRx_CTL register is read.

IRQ_EN_0:     equ %00000000 ; Timer interrupt requests are disabled.
IRQ_EN_1:     equ %01000000 ; Timer interrupt requests are enabled.

PRT_MODE_0:   equ %00000000 ; The timer operates in SINGLE PASS mode. PRT_EN (bit 0) is reset to
                            ;  0,and counting stops when the end-of-count value is reached.
PRT_MODE_1:   equ %00010000 ; The timer operates in CONTINUOUS mode. The timer reload value is
                            ; written to the counter when the end-of-count value is reached.

; CLK_DIV is a 2-bit mask that sets the timer input source clock divider
CLK_DIV_256:  equ %00001100 ; 
CLK_DIV_64:   equ %00001000 ; 
CLK_DIV_16:   equ %00000100 ;
CLK_DIV_4:    equ %00000000 ;

RST_EN_0:     equ %00000000 ; The reload and restart function is disabled. 
RST_EN_1:     equ %00000010 ; The reload and restart function is enabled. 
                            ; When a 1 is written to this bit,the values in the reload registers
                            ;  are loaded into the downcounter when the timer restarts. The 
                            ; programmer must ensure that this bit is set to 1 each time 
                            ; SINGLE-PASS mode is used.

; disable/enable the programmable reload timer
PRT_EN_0:     equ %00000000 ;
PRT_EN_1:     equ %00000001 ;

; Table 37. Timer Input Source Select Register
; Each of the 4 timers are allocated two bits of the 8-bit register
; in little-endian order,with TMR0 using bits 0 and 1,TMR1 using bits 2 and 3,etc.
;   00: System clock / CLK_DIV
;   01: RTC / CLK_DIV
;   NOTE: these are the values given in the manual,but it may be a typo
;   10: GPIO port B pin 1.
;   11: GPIO port B pin 1.
TMR_ISS:   equ 92h ; register address

; Table 51. Real-Time Clock Control Register
RTC_CTRL: equ EDh ; register address

; alarm interrupt disable/enable
RTC_ALARM_0:    equ %00000000
RTC_ALARM_1:    equ %10000000

; interrupt on alarm disable/enable
RTC_INT_ENT_0:  equ %00000000
RTC_INT_ENT_1:  equ %01000000

RTC_BCD_EN_0:   equ %00000000   ; RTC count and alarm registers are binary
RTC_BCD_EN_1:   equ %00100000   ; RTC count and alarm registers are BCD

RTC_CLK_SEL_0:  equ %00000000   ; RTC clock source is crystal oscillator output (32768 Hz). 
                                ; On-chip 32768 Hz oscillator is enabled.
RTC_CLK_SEL_1:  equ %00010000   ; RTC clock source is power line frequency input as set by FREQ_SEL.
                                ; On-chip 32768 Hz oscillator is disabled.

RTC_FREQ_SEL_0: equ %00000000   ; 60 Hz power line frequency.
RTC_FREQ_SEL_1: equ %00001000   ; 50 Hz power line frequency.

RTC_SLP_WAKE_0: equ %00000000   ; RTC does not generate a sleep-mode recovery reset.
RTC_SLP_WAKE_1: equ %00000010   ; RTC generates a sleep-mode recovery reset.

RTC_UNLOCK_0:   equ %00000000   ; RTC count registers are locked to prevent Write access.
                                ; RTC counter is enabled.
RTC_UNLOCK_1:   equ %00000001   ; RTC count registers are unlocked to allow Write access. 
                                ; RTC counter is disabled.

; 72000 = 1 tick per second at 18.432 MHz with a 256 clock divider
; but since max is 65536, intervals > 65536/72000 = 0.91 seconds require an additional counter
prt_reload: equ 72 ; 1 millisecond

; start PRT timer
prt_start:
    ld hl,prt_reload
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
prt_stop:
    ld a,PRT_IRQ_0 | IRQ_EN_0 | PRT_MODE_0 | CLK_DIV_256 | RST_EN_1 | PRT_EN_0
	out0 (TMR1_CTL+TMR_REG_CTL),a
    ret

; ===============================================
; PRT Timer Interrupt Handling
; https://github.com/tomm/agon-cpu-emulator/blob/main/sdcard/regression_suite/timerirq.asm
; -----------------------------------------------
prt_irq_init:
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

	; write CALL prt_irq_handler to vector table 2
	ld a,$c3
	ld (hl),a
	inc hl
	ld de,prt_irq_handler
	ld (hl),de

    ret
; end prt_irq_init

; interrupt routine for playing the next sample
prt_irq_handler:
    di
    ex af,af'
    exx

; clear sysvar_keyascii
	MOSCALL mos_sysvars
	xor a
	ld (IX+sysvar_keyascii),a

; read the timer interrupt 
    in0 a,(TMR1_CTL+TMR_REG_CTL)

; decrement the next note counter
    ld hl,(note_counter)
    dec hl
    ld (note_counter),hl
    
; if timer expired, play the next note
    SIGN_UHL
    call z,play_note
    jp p,@done
    ld hl,1
    ld (note_counter),hl

@done:
; restore regular registers and enable interrupts
    exx
    ex af,af'
    ei
    reti.l
; end prt_irq_handler