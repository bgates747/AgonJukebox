"""Generate/run target malformed-layout, discovery and repeated lifecycle checks."""
from pathlib import Path
import argparse,json,os,struct,subprocess,sys,shutil,time
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'scripts/skin_schema'))
import runtime as rt

def fixtures(sd):
    # Freeze the legacy 5x8 geometry so malformed cases survive skin redesigns.
    base=(ROOT/'tests/fixtures/runtime-legacy-layout.bin').read_bytes()
    cases=[]
    def add(name,data,error=0x61):cases.append((name,data,error))
    add('valid70',base,0);add('validdeco',(ROOT/'skins/runtime/artdeco/layout.bin').read_bytes(),0)
    large=(ROOT/'skins/runtime/nineties/layout.bin').read_bytes()
    add('valid_nineties_large_status',large,0)
    mixed=(ROOT/'skins/runtime/pcb/layout.bin').read_bytes()
    add('valid_mixed_status',mixed,0)
    b=bytearray(mixed);b[rt.GEOMETRY+18*15:rt.GEOMETRY+19*15]=bytes(15);add('absent_volume_status',bytes(b),0)
    b[rt.GEOMETRY+18*15]=1;add('absent_volume_dirty_geometry',b)
    for name,off,value in [('font_mask_row',23,8),('font_mask_row_middle',24,1),('font_mask_unused',25,8),('detail_too_short',rt.GEOMETRY+17*15+12,12)]:
        b=bytearray(mixed);b[off]=value;add(name,b)
    b=bytearray(mixed);struct.pack_into('<H',b,rt.GEOMETRY+2*15+10,struct.unpack_from('<H',mixed,rt.GEOMETRY+2*15+2)[0]+10);add('mixed_count_short_height',b)
    b=bytearray(mixed);b[rt.GEOMETRY+2*15+14]=1;add('mixed_count_wrong_fg',b)

    b=bytearray(large);b[rt.GEOMETRY+13*15:rt.GEOMETRY+14*15]=bytes(15);add('absent_message',bytes(b),0)
    b[rt.GEOMETRY+13*15]=1;add('absent_message_dirty_geometry',b)
    b=bytearray(large);b[rt.GEOMETRY:rt.GEOMETRY+15]=bytes(15);add('absent_required_path',b)
    for name,off,value in [('large_status_narrow',rt.GEOMETRY+8,60),('large_status_short',rt.GEOMETRY+10,struct.unpack_from('<H',large,rt.GEOMETRY+2)[0]+10)]:
        b=bytearray(large);struct.pack_into('<H',b,off,value);add(name,b)
    b=bytearray(large);b[rt.GEOMETRY+13]=1;add('large_status_wrong_bg',b)
    add('short',base[:-1],0x60);add('long',base+b'\0',0x43);add('magic',b'BADMAGIC'+base[8:],0x60)
    def byte(name,off,value):b=bytearray(base);b[off]=value;add(name,b)
    def word(name,off,value):b=bytearray(base);struct.pack_into('<H',b,off,value);add(name,b)
    for name,off,value in [('noimages',8,0),('too_many_images',8,215),('shortpath',9,5),('shorttrack',10,8),('badnameoffset',11,0),('shortname',12,6),('overlap_duration',13,30),('badpointerflag',14,2),('badpalette',15,64),('zerospan',19,0),('reserved',26,1),('bad_status_font',22,2),('large_font_small_rects',22,1),('badrowwidth',rt.GEOMETRY+3*15+12,57),('rowpalette',rt.GEOMETRY+3*15+13,1),('badpagewidth',rt.GEOMETRY+15+12,7),('badtile',rt.TILES,0),('unloadedtile',rt.TILES,214)]:byte(name,off,value)
    for name,off,value in [('pointeroffscreen',20,503),('textoffscreen',rt.GEOMETRY,512),('textoutside',rt.GEOMETRY+8,62),('row_y_high',rt.GEOMETRY+3*15+2,256),('artoffscreen',rt.ART_START,512),('artclips',rt.ART_START,500),('imagezero',rt.IMAGES,0),('imagewide',rt.IMAGES,513),('imagetall',rt.IMAGES+2,65),('tilewrongsize',rt.IMAGES+22*4,31),('unusedimage',rt.IMAGES+213*4,1),('pointerwrongsize',rt.IMAGES+21*4,11),('statewrongsize',rt.IMAGES+4,90)]:word(name,off,value)
    # Every individual image is bounded, but the sum must also fit the budget.
    b=bytearray(base)
    for i in range(21):struct.pack_into('<HH',b,rt.IMAGES+i*4,512,64)
    add('imagebudget',b)
    # Last referenced tile must be rejected too, proving the entire table scan.
    byte('lasttile',rt.TILES+191,0)
    word('marker_outside_track',rt.ART_START+20,120)
    byte('marker_travel_outside',19,255)
    word('rows_overlap',rt.GEOMETRY+4*15+2,90)
    word('row_without_margin',rt.GEOMETRY+3*15+4,84)
    table=[]
    for i,(name,data,error) in enumerate(cases):
        path=sd/f'contract/{i:02d}';path.mkdir(parents=True);(path/'layout.bin').write_bytes(data)
        table.append(f'    dl case_{i}\n    db {error}')
    strings=[f'case_{i}: asciz "/contract/{i:02d}"' for i in range(len(cases))]
    return cases,'ct_cases:\n'+'\n'.join(table+strings)+'\n'

ASM='''skin_runtime: equ 1
skin_custom: equ 1
skin_artdeco: equ 1
skin_seventies: equ 0
live_test_mode: equ 0
    include "../ui/runtime/profile.inc"
    include "jukebox_modules.inc"
    include "../ui/runtime/widgets.inc"
    include "skin_runtime.inc"
    include "skin_chooser.inc"
live_test_init:
live_test_step:
    ret
start:
    push af
    push bc
    push de
    push ix
    push iy
    ld hl,ct_cases
    ld (ct_cursor),hl
    xor a
    ld (ct_index),a
@case:
    ld ix,(ct_cursor)
    ld hl,(ix)
    ld de,jcfg_skin_dir
    call jcfg_copy_string
    ld a,(ix+3)
    ld (ct_expected),a
    lea ix,ix+4
    ld (ct_cursor),ix
    call rt_load
    ld hl,ct_expected
    cp (hl)
    jp nz,ct_fail
    ld a,(ct_index)
    call sa_debug_hex
    ld hl,ct_newline
    call sa_debug_puts
    ld a,(ct_index)
    inc a
    ld (ct_index),a
    cp CASE_COUNT
    jr c,@case
    ; Fail after mode change and after bitmap loading, then restore MOS safely.
    ld hl,ct_broken_graphics
    call ct_failed_assets
    ld hl,ct_broken_font
    call ct_failed_assets
    ; Discovery must see both packages without changing cwd.
    ld hl,ct_cwd
    FFSCALL ffs_getcwd
    ld hl,ct_root
    ld de,rt_root
    call jcfg_copy_string
    call rt_discover
    jp nz,ct_fail
    ld a,(rt_choice_count)
    cp 2
    jp nz,ct_fail
    ld hl,ct_cwd_after
    FFSCALL ffs_getcwd
    ld hl,ct_cwd
    ld de,ct_cwd_after
@cwd:
    ld a,(de)
    cp (hl)
    jp nz,ct_fail
    inc hl
    inc de
    or a
    jr nz,@cwd
    ; Exercise refresh/select/cancel through the real blocking MOS getkey.
    ld hl,ct_select_keys
    call ct_keys_start
    call rt_choose
    push af
    call ct_keys_stop
    pop af
    jp nz,ct_fail
    ld hl,jcfg_skin_dir
    ld de,rt_choices
@selected_path:
    ld a,(de)
    cp (hl)
    jp nz,ct_fail
    inc de
    inc hl
    or a
    jr nz,@selected_path
    ld hl,ct_cancel_keys
    call ct_keys_start
    call rt_choose
    push af
    call ct_keys_stop
    pop af
    jp z,ct_fail
    ; Root '/' is valid and must not scan before its buffer.
    ld hl,ct_slash
    ld de,jcfg_skin_dir
    call jcfg_copy_string
    call rt_set_root
    ld a,(rt_root)
    cp '/'
    jp nz,ct_fail
    ld a,(rt_root+1)
    or a
    jp nz,ct_fail
    ld hl,ct_empty
    FFSCALL ffs_chdir
    or a
    jp nz,ct_fail
    xor a
    ld (ct_index),a
@cycle:
    ld a,(ct_index)
    ld hl,ct_nineties
    or a
    jr z,@skin
    cp 3
    jr z,@skin
    ld hl,ct_deco
    cp 2
    jr z,@skin
    ld hl,ct_70
@skin:
    ld de,jcfg_skin_dir
    call jcfg_copy_string
    ld a,1
    ld (jcfg_valid),a
    call sa_skin_assets_init
    jp nz,ct_fail
    call bf_get_dir
    xor a
    ld (bf_file_idx),a
    call ui_init
    call ui_flush
    ; Dispatch K through the real input boundary, then perform its teardown.
    xor a
    ld (rt_switch),a
    ld a,'k'
    call input_dispatch
    ld a,(rt_switch)
    cp 1
    jp nz,ct_fail
    call ps_close_file
    call ps_clear_audio_buffers
    call ui_shutdown
    ei
    call sa_restore
    jp nz,ct_fail
    MOSCALL mos_sysvars
    ld a,(sa_old_mode)
    cp (ix+0x27)
    jp nz,ct_fail
    ld a,(sa_small_open)
    or a
    jp nz,ct_fail
    ld a,(ct_index)
    inc a
    ld (ct_index),a
    cp 4
    jp c,@cycle
    ld hl,ct_pass
    call sa_debug_puts
    pop iy
    pop ix
    pop de
    pop bc
    pop af
    ld hl,0
    ret
ct_failed_assets:
    ld de,jcfg_skin_dir
    call jcfg_copy_string
    ld a,1
    ld (jcfg_valid),a
    call sa_skin_assets_init
    jp z,ct_fail
    call sa_restore
    jp nz,ct_fail
    MOSCALL mos_sysvars
    ld a,(sa_old_mode)
    cp (ix+0x27)
    jp nz,ct_fail
    ret
ct_fail:
    call sa_debug_hex
    ld a,(ct_index)
    call sa_debug_hex
    ld hl,ct_failure
    call sa_debug_puts
@halt:
    jr @halt
; Test-only key delivery uses the same MOS sysvars mechanism as livecheck.
ct_keys_start:
    ld (ct_key_cursor),hl
    xor a
    ld (ct_key_ticks),a
    di
    ld hl,ct_key_irq
    ld e,0x0e
    MOSCALL mos_setintvector
    ld (ct_key_vector),hl
    ld hl,7200
    out0 (TMR2_CTL+TMR_RES_LOW),l
    out0 (TMR2_CTL+TMR_RES_HIGH),h
    ld a,IRQ_EN_1|PRT_MODE_1|CLK_DIV_256|RST_EN_1|PRT_EN_1
    out0 (TMR2_CTL),a
    ei
    ret
ct_keys_stop:
    di
    xor a
    out0 (TMR2_CTL),a
    ld hl,(ct_key_vector)
    ld e,0x0e
    MOSCALL mos_setintvector
    ei
    ret
ct_key_irq:
    di
    push af
    push bc
    push de
    push hl
    push ix
    in0 a,(TMR2_CTL)
    ld a,(ct_key_ticks)
    inc a
    ld (ct_key_ticks),a
    cp 5
    jr c,@done
    xor a
    ld (ct_key_ticks),a
    ld hl,(ct_key_cursor)
    ld a,(hl)
    or a
    jr z,@done
    inc hl
    ld (ct_key_cursor),hl
    push af
    MOSCALL mos_sysvars
    pop af
    ld (ix+sysvar_keyascii),a
    ld (ix+sysvar_vkeydown),1
    inc (ix+sysvar_vkeycount)
@done:
    pop ix
    pop hl
    pop de
    pop bc
    pop af
    ei
    reti.l
ct_select_keys: asciz "r0"
ct_cancel_keys: asciz "q"
ct_key_cursor: dl 0
ct_key_vector: dl 0
ct_key_ticks: db 0
ct_index: db 0
ct_expected: db 0
ct_cursor: dl 0
ct_cwd: blkb 256,0
ct_cwd_after: blkb 256,0
ct_root: asciz "/jukebox/skins/"
ct_deco: asciz "/jukebox/skins/artdeco"
ct_70: asciz "/jukebox/skins/seventies"
ct_nineties: asciz "/nineties-test"
ct_broken_graphics: asciz "/broken-graphics"
ct_broken_font: asciz "/broken-font"
ct_empty: asciz "/empty"
ct_slash: asciz "/"
ct_newline: asciz "\\r\\n"
ct_pass: asciz "RUNTIME_CONTRACT_PASS\\r\\n"
ct_failure: asciz "RUNTIME_CONTRACT_FAIL\\r\\n"
TABLE
    include "files.inc"
'''

def main():
    p=argparse.ArgumentParser();p.add_argument('directory',type=Path);a=p.parse_args();root=a.directory.resolve();root.mkdir(parents=True,exist_ok=False)
    sd=root/'fixture';(sd/'bin').mkdir(parents=True);(sd/'empty').mkdir()
    # Keep discovery fixtures stable when unrelated new packages are added.
    for skin in ('artdeco','seventies'):
        shutil.copytree(ROOT/'skins/runtime'/skin,sd/'jukebox/skins'/skin)
    for name,leaf in [('broken-graphics','graphics.agnb'),('broken-font','fonts/neutrino_5x8.font')]:
        shutil.copytree(ROOT/'skins/runtime/seventies',sd/name)
        (sd/name/leaf).unlink()
    shutil.copytree(ROOT/'skins/runtime/nineties',sd/'nineties-test')
    cases,table=fixtures(sd)
    # Assemble from src/asm so all established relative includes resolve.
    source=ROOT/'src/asm/runtime_contract_generated.asm'
    if source.exists():raise FileExistsError(source)
    try:
        source.write_text(ASM.replace('CASE_COUNT',str(len(cases))).replace('TABLE',table))
        subprocess.run(['ez80asm',source.name,os.path.relpath(sd/'bin/contract.bin',source.parent)],cwd=source.parent,check=True)
    finally:source.unlink()
    subprocess.run([str(ROOT/'.venv/bin/python'),str(ROOT.parent/'agon-dev-env/scripts/setup_emulator.py'),'jukebox','--state-root',str(root),'--jukebox-binary',str(ROOT/'tgt/jukebox-runtime.bin')],check=True)
    profile=root/'jukebox';target=profile/'sdcard'
    for f in sd.iterdir():shutil.copytree(f,target/f.name,dirs_exist_ok=True)
    (target/'autoexec.txt').write_bytes(b'SET KEYBOARD 1\r\ncontract\r\n')
    log=profile/'contract.log'
    with log.open('wb') as out:
        proc=subprocess.Popen(['./fab-agon-emulator','--renderer','sw'],cwd=profile,env=dict(os.environ,SDL_VIDEODRIVER='dummy',SDL_AUDIODRIVER='dummy'),stdout=out,stderr=subprocess.STDOUT,stdin=subprocess.DEVNULL)
        try:
            deadline=time.monotonic()+90
            while time.monotonic()<deadline and proc.poll() is None:
                text=log.read_text(errors='replace')
                if 'RUNTIME_CONTRACT_PASS' in text or 'RUNTIME_CONTRACT_FAIL' in text:break
                time.sleep(.2)
        finally:
            proc.terminate()
            try:proc.wait(timeout=5)
            except subprocess.TimeoutExpired:proc.kill();proc.wait()
    text=log.read_text(errors='replace');print(text[-2000:])
    assert 'RUNTIME_CONTRACT_PASS' in text and 'RUNTIME_CONTRACT_FAIL' not in text
    (root/'result.json').write_text(json.dumps({'result':'PASS','layout_cases':[{'name':n,'expected':e} for n,b,e in cases],'skin_load_cycles':4,'cycle_skins':['nineties','seventies','artdeco','nineties'],'partial_asset_failure_cleanup':2,'discovery':True,'cwd_preserved':True,'input_switch':True,'chooser_refresh_select_cancel':True,'mode_restored':True},indent=2)+'\n')
if __name__=='__main__':main()
