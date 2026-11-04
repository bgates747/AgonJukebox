#!/usr/bin/env python3
"""Package the isolated RC2 candidate; no firmware installation or execution."""
import argparse
import hashlib
import json
import zipfile
from pathlib import Path
from package_player import files, ROOT


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, default=ROOT/'dist/AgonJukebox-Eirene-RC2-test.zip')
    parser.add_argument('--mos', type=Path, help='Optional exact published RC2 firmware file to bundle')
    args = parser.parse_args()
    data = files()
    del data['tgt/jukebox.bin']
    del data['scripts/build_player.sh']
    for name in ['tgt/jukebox-rc2.bin', 'scripts/build_rc2_player.sh', 'docs/eirene-rc2-test.md', 'docs/eirene-rc2-debrief.md', 'scripts/decode_rc2_stats.py', 'scripts/pcm_spectrum_report.py']:
        data[name] = (ROOT/name).read_bytes()
    data['README.md'] = data['docs/eirene-rc2-test.md']
    if args.mos:
        firmware = args.mos.read_bytes()
        if len(firmware) != 100950 or hashlib.sha256(firmware).hexdigest() != 'a47130d78b70fa1e0e54aa61e4340831036d766a0c59e2738935bd9d04b94a3a':
            parser.error('Firmware does not match the pinned published RC2 artifact')
        data['mos-eirene-rc2.bin'] = firmware
    manifest = {'status':'experimental; hardware compatibility observed, performance qualification incomplete',
                'source_entry':'src/asm/app_eirene_rc2.asm',
                'branch':'codex/eirene-rc2-player',
                'base_commit':'aca7624',
                'transport':'common RC2 submit42/finish43; published MOS or EMOS native Legacy',
                'in_app_rom_identity_gate':False,
                'diagnostics_version':2,
                'hardware_tested':True,
                'hardware_review':'docs/eirene-rc2-debrief.md; qualitative only',
                'mos_tag':'3.1.0_uart0_rc_2',
                'rom_sha256':'a47130d78b70fa1e0e54aa61e4340831036d766a0c59e2738935bd9d04b94a3a',
                'files':[{'path':name,'bytes':len(content),'sha256':hashlib.sha256(content).hexdigest()}
                         for name,content in sorted(data.items())]}
    data['MANIFEST.json'] = (json.dumps(manifest,indent=2)+'\n').encode()
    assert not any(name.startswith(('.git','.emulator','docs/tasks','docs/agents')) for name in data)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(args.output,'w',zipfile.ZIP_DEFLATED,compresslevel=9) as archive:
        for name,content in sorted(data.items()):
            info=zipfile.ZipInfo('AgonJukebox-RC2/'+name,(1980,1,1,0,0,0))
            info.compress_type=zipfile.ZIP_DEFLATED
            info.external_attr=(0o100755 if name.endswith('.sh') else 0o100644)<<16
            archive.writestr(info,content,compress_type=zipfile.ZIP_DEFLATED,compresslevel=9)
    print(json.dumps({'archive':str(args.output),'zip_bytes':args.output.stat().st_size,
                      'unpacked_bytes':sum(map(len,data.values())),'files':len(data),
                      'sha256':hashlib.sha256(args.output.read_bytes()).hexdigest()},indent=2))

if __name__ == '__main__':
    main()
