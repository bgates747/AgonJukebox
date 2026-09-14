"""Run the shared MOS functional suite in a fresh canonical local Fab profile."""
from pathlib import Path
import argparse,sys,subprocess,os,shutil,time,json,signal
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tests'))
import functional
p=argparse.ArgumentParser();p.add_argument('directory',type=Path);p.add_argument('--skin',default='seventies');a=p.parse_args()
root=a.directory.resolve();root.mkdir(parents=True,exist_ok=False)
functional.prepare(root/'fixture',a.skin)
subprocess.run([str(ROOT/'.venv/bin/python'),str(ROOT.parent/'agon-dev-env/scripts/setup_emulator.py'),'jukebox','--state-root',str(root),'--jukebox-binary',str(ROOT/'tgt/jukebox.bin')],check=True)
profile=root/'jukebox';sd=profile/'sdcard'
for item in ['qualification','jukebox']:shutil.copytree(root/'fixture'/item,sd/item)
for item in (root/'fixture/bin').iterdir():shutil.copy2(item,sd/'bin'/item.name)
shutil.copy2(root/'fixture/autoexec.txt',sd/'autoexec.txt')
log=profile/'functional.log'
with log.open('wb') as out:
 proc=subprocess.Popen(['./fab-agon-emulator','--renderer','sw'],cwd=profile,env=dict(os.environ,SDL_VIDEODRIVER='dummy',SDL_AUDIODRIVER='dummy'),stdin=subprocess.DEVNULL,stdout=out,stderr=subprocess.STDOUT,start_new_session=True)
 try:
  deadline=time.monotonic()+150
  while time.monotonic()<deadline:
   text=log.read_text(errors='replace')
   if 'LIVE_TEST_PASS' in text or 'LIVE_TEST_FAIL' in text:break
   if proc.poll() is not None:break
   time.sleep(.2)
 finally:
  if proc.poll() is None:
   proc.terminate()
   try:proc.wait(timeout=5)
   except subprocess.TimeoutExpired:proc.kill();proc.wait()
print(log.read_text(errors='replace')[-1600:])
functional.check(log,a.skin)
