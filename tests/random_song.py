"""Run production directory-wide random or sequential selection in isolated Fab.

No audio or graphical review session is started. A deterministic PRNG stub visits
all eligible ranks, while real selection, division and page helpers execute.
"""
from pathlib import Path
import argparse,subprocess,sys,tempfile,os,time,json
R=Path(__file__).resolve().parents[1]
p=argparse.ArgumentParser();p.add_argument('--sequential',action='store_true');p.add_argument('--emulator',type=Path,required=True);args=p.parse_args()
work=Path(tempfile.mkdtemp(prefix='jukebox-random-'));asm=R/'src/asm'
cases=[]
for name,flags,current in [('empty',[],0),('directories',[1]*13,4),('single',[0],0),('one_after_dirs',[1]*12+[0],2),('selected_only',[1]*12+[0],12),('multi_page',[0]*25,3),('partial_last',[1]*10+[0]*13,21),('selected_directory',[1]*12+[0]*13,1),('interleaved',[int(i%3==0) for i in range(31)],17),('wide_count',[0]*256,255)]:
 eligible=[i for i,f in enumerate(flags) if not f]
 if len(eligible)>1 and current in eligible:eligible.remove(current)
 for rank in range(max(1,len(eligible))):cases.append((name,flags,current,rank,eligible[rank] if eligible else None))
if args.sequential:
 cases=[]
 for name,flags in [('empty',[]),('directories',[1]*23),('single',[0]),('mixed',[1]*12+[0]*13),('directory_page',[0]*10+[1]*10+[0]*3),('all_files',[0]*25),('exact_pages',[0]*20),('wide_count',[0]*256)]:
  for current in range(max(1,len(flags))):
   expected=next(((current+step)%len(flags) for step in range(1,len(flags)+1) if not flags[(current+step)%len(flags)]),None)
   cases.append((name,flags,current,0,expected))
lines=[(asm/'macros.inc').read_text(),'assume adl=1','org 0x40000','jp start','align 64','db "MOS",0,1','start:','push af','push bc','push de','push ix','push iy']
for num,(name,flags,current,rank,expected) in enumerate(cases):
 n=len(flags);pages=max(1,(n+9)//10);last=n%10 or (10 if n else 0);page=current//10;row=current%10;cur=last if page==pages-1 else 10
 lines += [f'ld hl,{num}', 'ld (case_number),hl',f'ld hl,{n}','ld (bf_dir_num_files),hl',f'ld hl,{pages}','ld (bf_dir_num_pages),hl',f'ld hl,{last}','ld (bf_files_last_pg),hl',f'ld hl,{page}','ld (bf_page_cur),hl',f'ld a,{row}','ld (bf_file_idx),a',f'ld a,{cur}','ld (bf_files_cur_pg),a',f'ld hl,{rank}','ld (sample),hl']
 # Assemble a pointer table, using the case's immutable attributes.
 lines += [f'ld hl,attrs_{num}','ld ix,bf_filinfo_ptrs',f'ld bc,{n}']
 if n:lines += [f'fill_{num}:','ld (ix),hl','inc hl','lea ix,ix+3','dec bc','push hl','ld hl,0','add hl,bc','SIGN_UHL','pop hl',f'jp nz,fill_{num}']
 lines += ['call '+('bf_select_next_song' if args.sequential else 'bf_select_random_song'),'jp '+('nz' if expected is None else 'z')+',failed']
 ep=page if expected is None else expected//10;er=row if expected is None else expected%10;ec=cur if expected is None else last if ep==pages-1 else 10
 lines += ['ld hl,(bf_page_cur)',f'ld de,{ep}','or a','sbc hl,de','jp nz,failed','ld a,(bf_file_idx)',f'cp {er}','jp nz,failed','ld a,(bf_files_cur_pg)',f'cp {ec}','jp nz,failed']
lines += ['ld hl,passed','jr report','failed:','ld hl,failure','report:','ld a,(hl)','or a','jr z,done','out0 (0x30),a','inc hl','jr report','done:','pop iy','pop ix','pop de','pop bc','pop af','ld hl,0','ret','passed: db "RANDOM_DIRECTORY_PASS",13,10,0','failure: db "RANDOM_DIRECTORY_FAIL",13,10,0','case_number: dl 0','sample: dl 0','prng24:','ld hl,(sample)','ret','bf_files_per_pg: equ 10','AM_DIR: equ 4','filinfo_fattrib: equ 0']
for label in ['bf_dir_num_files','bf_dir_num_pages','bf_files_last_pg','bf_page_cur','bf_file_idx','bf_files_cur_pg']:lines += [label+': dl 0']
lines+=['bf_filinfo_ptrs: blkb 768,0']
for num,(_,flags,_,_,_) in enumerate(cases):
 lines += [f'attrs_{num}:']
 values=flags or [0]
 for offset in range(0,len(values),32):lines += ['db '+','.join(str(16 if f else 0) for f in values[offset:offset+32])]
lines += [(asm/'arith24.inc').read_text().split('neg24:')[0],(asm/'random_song.inc').read_text(),(asm/'next_song.inc').read_text()]
for filename,label,end in [('input.inc','bf_get_filinfo_from_pg_idx:','; end bf_get_filinfo_from_pg_idx'),('browse.inc','bf_get_page_num_files:','; end bf_get_page_num_files')]:
 text=(asm/filename).read_text();lines += [text[text.index(label):text.index(end)]]
(work/'test.asm').write_text('\n'.join(lines)+'\n');subprocess.run(['ez80asm',str(work/'test.asm'),str(work/'test.bin')],check=True)
subprocess.run([sys.executable,str(R.parent/'agon-dev-env/scripts/setup_emulator.py'),'jukebox','--emulator',str(args.emulator.resolve()),'--state-root',str(work/'emu'),'--jukebox-binary',str(work/'test.bin')],check=True)
profile=work/'emu/jukebox';(profile/'sdcard/autoexec.txt').write_bytes(b'jukebox\r\n');log=profile/'random-test.log'
with log.open('wb') as out:
 proc=subprocess.Popen(['./fab-agon-emulator','--renderer','sw'],cwd=profile,env=dict(os.environ,SDL_VIDEODRIVER='dummy',SDL_AUDIODRIVER='dummy'),stdin=subprocess.DEVNULL,stdout=out,stderr=subprocess.STDOUT,start_new_session=True)
 try:
  deadline=time.monotonic()+45
  while time.monotonic()<deadline:
   text=log.read_text(errors='replace')
   if 'RANDOM_DIRECTORY_' in text or proc.poll() is not None:break
   time.sleep(.2)
 finally:
  if proc.poll() is None:
   proc.terminate()
   try:proc.wait(timeout=5)
   except subprocess.TimeoutExpired:proc.kill();proc.wait()
text=log.read_text(errors='replace');assert 'RANDOM_DIRECTORY_PASS' in text,text[-2000:]
print(json.dumps({'result':'PASS','mode':'sequential' if args.sequential else 'random','cases':len(cases),'evidence':str(work),'scope':'Production selector and page helpers; deterministic PRNG for random mode; no audio or hardware qualification'},indent=2))
