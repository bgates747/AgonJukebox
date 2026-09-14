"""Compare accepted runtime output and assembly against an explicit Git baseline."""
from pathlib import Path
import argparse,hashlib,io,json,os,subprocess,tarfile,tempfile
from PIL import Image
ROOT=Path(__file__).resolve().parents[2]
def check(baseline):
    result={'baseline':baseline,'packages':{},'images':{},'binaries':{}}
    def old(path):return subprocess.check_output(['git','show',f'{baseline}:{path}'],cwd=ROOT)
    for skin in ('artdeco','seventies'):
        for directory in (f'skins/{skin}',f'src/ui/{skin}',f'tests/fixtures/{skin}'):
            files=subprocess.check_output(['git','ls-tree','-r','--name-only',baseline,directory],cwd=ROOT,text=True).splitlines()
            for name in files:
                if name.endswith('.inc'):continue
                data=(ROOT/name).read_bytes();assert data==old(name),name
                result['packages'][name]=hashlib.sha256(data).hexdigest()
        for leaf in ('preview.png','backdrop.png','test-paused.png'):
            name=f'src/skins/{skin}/generated/{leaf}';a=Image.open(ROOT/name).convert('RGBA');b=Image.open(io.BytesIO(old(name))).convert('RGBA')
            assert a.size==b.size and a.tobytes()==b.tobytes(),name
            result['images'][name]='identical pixels'
    with tempfile.TemporaryDirectory(prefix='schema-reg-',dir='/tmp') as temp:
        temp=Path(temp);before=temp/'before';before.mkdir()
        data=subprocess.check_output(['git','archive',baseline,'src/asm','src/ui','tests/asm','tests/fixtures','vendor/agnb'],cwd=ROOT)
        with tarfile.open(fileobj=io.BytesIO(data)) as archive:archive.extractall(before,filter='data')
        for index,source in enumerate(('app.asm','app_base.asm','app_seventies.asm','../../tests/asm/livecheck.asm','../../tests/asm/artdeco_check.asm','../../tests/asm/seventies_check.asm')):
            bins=[]
            for label,root in [('before',before),('after',ROOT)]:
                output=temp/f'{index}-{label}.bin'
                subprocess.run(['ez80asm',source,str(output)],cwd=root/'src/asm',check=True,stdout=subprocess.DEVNULL)
                bins.append(output.read_bytes())
            assert bins[0]==bins[1],source
            assert 0x40000+len(bins[1])<0x6ff00,source
            result['binaries'][source]={'bytes':len(bins[1]),'sha256':hashlib.sha256(bins[1]).hexdigest(),'identical':True}
    return result
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--baseline',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    result=check(a.baseline);a.output.write_text(json.dumps(result,indent=2)+'\n');print(f"PASS: {len(result['packages'])} runtime files, {len(result['images'])} pixel-identical images, {len(result['binaries'])} byte-identical binaries")
