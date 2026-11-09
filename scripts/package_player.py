#!/usr/bin/env python3
"""Create a deterministic, buildable synchronous-MOS distribution ZIP."""
import argparse,hashlib,json,zipfile
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
INSTRUCTIONS='''# AgonJukebox — runtime skins and PCM analyzer

A WAV-only eZ80 player using synchronous MOS VDU output.
Current test/deployment defaults are EireneRC3 on Alexe/Console8, approved EMOS
on Olimex, and VDPlet v0.1.2-alpha. See docs/firmware-defaults.md and its exact
release checksums. No experimental UART transport is activated by this build.
The analyzer is a coarse PCM filter bank, not a calibrated FFT instrument.

## Install

1. Copy tgt/jukebox.bin to /bin/jukebox.bin on the SD card.
2. Copy config/jukebox.cfg to /bin/jukebox.cfg (preserve your existing settings
   if upgrading). The example selects /jukebox/skins/nineties and /music.
3. Copy the four directories under skins/ to /jukebox/skins/ on the card.
4. Put compatible WAV files in /music, or change music_dir in the config.
5. Run jukebox from MOS. No autoexec or firmware change is required.

Nineties includes the analyzer. Other skins remain usable through K. To retain
an existing skin installation, copy its spectrum.bin and spectrum.agnb into the
Nineties directory named by skin_dir. Assets remain external/dynamically loaded.

## Controls and audio

Arrows select files/pages; Enter opens directories/plays; U goes up. P pauses,
comma/period adjust volume, brackets seek, minus/equals change seek interval,
L/S toggle loop/shuffle, R selects a random track, K chooses a skin, V toggles
analysis, Q/Esc quits. V has an effect only when the skin opts into analysis.
After re-enabling, fresh bars can take up to two seconds to return.

WAV: unsigned8-bit PCM mono,1..65535Hz, legacy PCM or PCM-extensible RIFF.
The existing one-second sample-boundary cue/pop behavior is unchanged.
Analyzer report /JSPEC.DAT is written only on normal quit, not continuously.

## Build

Install ez80asm, then from the extracted directory:

    sh scripts/build_player.sh

Alternatively, from src/asm:

    ez80asm app.asm ../../tgt/jukebox.bin

All required assembly sources, generated UI includes and canonical AGNB code
are included. No Python, Pillow, agon-utils checkout or image regeneration is
needed to build/run. Source artwork and authoring/test tools are omitted.

## Credits

VISUALIZATION DESIGN CREDIT: Pollito / SanPollo — Nick J. Date, agonAMP.
Its paced incremental redraw, desired/displayed state and falling-bar approach
inspired this independently written bitmap visualization. The PCM filter bank
measures actual samples, separately from agonAMP's AY harmonic estimates.
https://github.com/SanPollo/agonAMP/blob/tag1.1/src/spectrum.asm

Copyright and license: LICENSE, vendor/agnb/LICENSE,
vendor/agonamp-visualization/LICENSE. See docs/pcm-spectrum.md for implementation
and limitations. MANIFEST.json records source and executable hashes.
'''

def files():
 result={}
 for folder in ['src/asm','src/ui','vendor/agnb','vendor/agonamp-visualization']:
  for p in sorted((ROOT/folder).rglob('*')):
   if p.is_file() and p.suffix not in ['.lst','.pyc']:result[p.relative_to(ROOT).as_posix()]=p.read_bytes()
 for name in ['LICENSE','config/jukebox.cfg','tgt/jukebox.bin','scripts/build_player.sh','docs/pcm-spectrum.md','docs/firmware-defaults.md','docs/firmware-defaults.json','docs/firmware-compatibility-audit.md']:
  result[name]=(ROOT/name).read_bytes()
 for skin in ['artdeco','nineties','pcb','seventies']:
  for p in sorted((ROOT/'skins/runtime'/skin).rglob('*')):
   if p.is_file() and (p.suffix in ['.cfg','.bin','.agnb','.font']):
    result['skins/'+skin+'/'+p.relative_to(ROOT/'skins/runtime'/skin).as_posix()]=p.read_bytes()
 result['README.md']=INSTRUCTIONS.encode()
 return result

def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,default=ROOT/'dist/AgonJukebox-skins-analyzer.zip');a=p.parse_args()
 data=files()
 assert not any(name.startswith(('.git','.emulator','docs/tasks','docs/agents')) for name in data)
 manifest={'transport':'stock MOS synchronous VDU output only','source_entry':'src/asm/app.asm','branch':'skins','experimental_uart_api':False,'files':[{'path':name,'bytes':len(content),'sha256':hashlib.sha256(content).hexdigest()} for name,content in sorted(data.items())]}
 data['MANIFEST.json']=(json.dumps(manifest,indent=2)+'\n').encode()
 a.output.parent.mkdir(parents=True,exist_ok=True)
 with zipfile.ZipFile(a.output,'w',zipfile.ZIP_DEFLATED,compresslevel=9) as archive:
  for name,content in sorted(data.items()):
   info=zipfile.ZipInfo('AgonJukebox/'+name,(1980,1,1,0,0,0));info.compress_type=zipfile.ZIP_DEFLATED;info.external_attr=(0o100755 if name.endswith('.sh') else 0o100644)<<16
   archive.writestr(info,content,compress_type=zipfile.ZIP_DEFLATED,compresslevel=9)
 print(json.dumps({'archive':str(a.output),'zip_bytes':a.output.stat().st_size,'unpacked_bytes':sum(map(len,data.values())),'files':len(data),'sha256':hashlib.sha256(a.output.read_bytes()).hexdigest()},indent=2))
if __name__=='__main__':main()
