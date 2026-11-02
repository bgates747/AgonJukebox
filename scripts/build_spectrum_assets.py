"""Build the optional meter using canonical AGNB writer's pure definitions."""
import ast,hashlib,struct,sys,tempfile,json
from dataclasses import dataclass
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
UTILS=Path.home()/'Agon/mystuff/agon-utils'
WRITER=UTILS/'examples/agnb/images/container/scripts/do_assembly.py'
# The full writer imports an image manifest/Pillow. Only its existing pure
# container definitions are needed for these algorithmically generated pixels.
source=WRITER.read_text();tree=ast.parse(source)
names={'ImageRecord','make_buffer_record','build_container'}
nodes=[n for n in tree.body if isinstance(n,(ast.ClassDef,ast.FunctionDef)) and n.name in names]
assert len(nodes)==3
sys.path.insert(0,str(UTILS/'examples/agnb/api'))
from riff import make_chunk
namespace=dict(dataclass=dataclass,Path=Path,struct=struct,make_chunk=make_chunk,VERSION_MAJOR=0,VERSION_MINOR=1,IMAGE_FORMAT_RGBA2222=1,MAX_U32=0xffffffff)
exec(compile(ast.Module(body=nodes,type_ignores=[]),str(WRITER),'exec'),namespace)

def rgba2(rgb):
 r,g,b=rgb;return 192+r//85+(g//85)*4+(b//85)*16

def main():
 package=ROOT/'skins/runtime/nineties';package.mkdir(parents=True,exist_ok=True)
 records=[]
 with tempfile.TemporaryDirectory() as folder:
  for level in range(7):
   pixels=bytearray([rgba2((0,0,0))]*(26*41))
   for row in range(6):
    y=(5-row)*7
    color=(0,255,85) if row<2 else (255,255,0) if row<4 else (255,0,0)
    value=rgba2(color if row<level else (85,85,85))
    for yy in range(y,y+6):pixels[yy*26:(yy+1)*26]=bytes([value])*26
   path=Path(folder)/f'level{level}.rgba2';path.write_bytes(pixels)
   records.append(namespace['ImageRecord']('AUD-001','meter'+str(level),0x2800+level,26,41,path,len(pixels)))
  container=namespace['build_container'](records)
 (package/'spectrum.agnb').write_bytes(container)
 (package/'spectrum.bin').write_bytes(b'SPC1'+struct.pack('<HH8B',95,6,33,26,41,10,6,0,0,0))
 (package/'spectrum-provenance.json').write_text(json.dumps({'writer':str(WRITER),'writer_sha256':hashlib.sha256(WRITER.read_bytes()).hexdigest(),'container_sha256':hashlib.sha256(container).hexdigest(),'bytes':len(container),'visualization_design_credit':'Nick J. Date (Pollito / SanPollo), agonAMP tag1.1 91ef401, paced incremental rendering approach; independent PCM and bitmap implementation'},indent=2)+'\n')
 print('Optional Nineties assets:',len(container),'AGNB bytes +16-byte descriptor')
if __name__=='__main__':main()
