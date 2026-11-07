#!/usr/bin/env python3
"""Package the explicitly pinned RFC player; never flashes or runs firmware."""
import argparse,hashlib,json,re,zipfile,zlib
from pathlib import Path
from package_player import files,ROOT

def main():
 p=argparse.ArgumentParser(description=__doc__)
 p.add_argument('--mos',type=Path,help='Optional verified startup-corrected RFC MOS image')
 p.add_argument('--firmware-info',type=Path,help='Required provenance when bundling an optional MOS image')
 p.add_argument('--qualification',type=Path,required=True)
 p.add_argument('--output',type=Path,default=ROOT/'dist/AgonJukebox-RFC-test.zip')
 a=p.parse_args();q=json.loads(a.qualification.read_text())
 public_info={'intended_firmware':'Eirene RC3, fork prerelease 3.1.0_uart0_rc_3','abi':'RFC syscall25h','rfc_base':'ffab9c9c84a31535d1ec976b7e6f23b2579ecb80','startup_correction_required_for_hardware':True,'native_legacy_uart0':True,'in_app_rom_allowlist':False,'bundled_firmware':False}
 rom=None
 if a.mos:
  if not a.firmware_info:p.error('Bundled firmware requires verified provenance')
  info=json.loads(a.firmware_info.read_text());rom=a.mos.read_bytes()
  if hashlib.sha256(rom).hexdigest()!=info['sha256'] or not info.get('startup_check_pass'):p.error('Require verified startup-corrected firmware artifact')
  if len(rom)!=info['bytes'] or f'{zlib.crc32(rom):08X}'!=info['crc32'].upper():p.error('Firmware size/CRC does not match provenance')
  if info['rfc_base']!=public_info['rfc_base'] or not re.fullmatch(r'[0-9a-f]{40}',info['source_commit']):p.error('Firmware source/ABI pin does not match')
  public_info.update({k:info[k] for k in ['source_commit','rfc_base','sha256','bytes','crc32','startup_check_pass']});public_info['bundled_firmware']=True
  public_info.update({k:info[k] for k in ['tag','release_url','map_sha256'] if k in info})
  public_info['filename']='mos-eirene-rc3.bin'
 data=files();del data['tgt/jukebox.bin'];del data['scripts/build_player.sh']
 for name in ['tgt/jukebox-rfc.bin','scripts/build_rfc_player.sh','scripts/decode_rfc_stats.py','scripts/pcm_spectrum_report.py','docs/uart-rfc-test.md']:
  data[name]=(ROOT/name).read_bytes()
 data['README.md']=(ROOT/'docs/uart-rfc-install.md').read_bytes()
 if rom is not None:data['mos-eirene-rc3.bin']=rom
 data['FIRMWARE.json']=(json.dumps(public_info,indent=2)+'\n').encode()
 public_q={k:q[k] for k in ['status','app_sha256','firmware_sha256','firmware_status','passed_cells','supporting_checks','limitations']}
 if hashlib.sha256(data['tgt/jukebox-rfc.bin']).hexdigest()!=q['app_sha256']:p.error('Qualification does not match executable')
 data['QUALIFICATION.json']=(json.dumps(public_q,indent=2)+'\n').encode()
 manifest={'status':'common RFC ABI test package; not a versioned public release','abi':'RFC syscall25h; callback plus foreground TEMT','source_entry':'src/asm/app_uart_rfc.asm','firmware':public_info,'files':[{'path':n,'bytes':len(v),'sha256':hashlib.sha256(v).hexdigest()} for n,v in sorted(data.items())]}
 data['MANIFEST.json']=(json.dumps(manifest,indent=2)+'\n').encode()
 assert not any(n.startswith(('.git','.emulator','docs/tasks','docs/agents')) for n in data)
 for name,content in data.items():
  if name.endswith(('.py','.sh','.md','.json','.cfg')) and (b'/home/smith/' in content or b'/Agon/mystuff/' in content):p.error('Personalized host path in '+name)
 a.output.parent.mkdir(parents=True,exist_ok=True)
 with zipfile.ZipFile(a.output,'w',zipfile.ZIP_DEFLATED,compresslevel=9) as z:
  for name,content in sorted(data.items()):
   entry=zipfile.ZipInfo('AgonJukebox-RFC/'+name,(1980,1,1,0,0,0));entry.compress_type=zipfile.ZIP_DEFLATED;entry.external_attr=(0o100755 if name.endswith('.sh') else 0o100644)<<16
   z.writestr(entry,content,compress_type=zipfile.ZIP_DEFLATED,compresslevel=9)
 print(json.dumps({'archive':str(a.output),'bytes':a.output.stat().st_size,'files':len(data),'sha256':hashlib.sha256(a.output.read_bytes()).hexdigest()},indent=2))
if __name__=='__main__':main()
