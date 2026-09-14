"""Create a data-only third-skin proof; no player assembly edits or hardware I/O."""
from pathlib import Path
import json,shutil,argparse
ROOT=Path(__file__).resolve().parents[2]
def create(destination):
    destination=Path(destination)
    destination.mkdir(parents=True,exist_ok=False)
    source=ROOT/'src/skins/seventies'
    shutil.copytree(source/'prepared',destination/'prepared')
    shutil.copy2(source/'source.png',destination/'source.png')
    d=json.loads((source/'skin.json').read_text());d['id']='schema_proof';d['runtime_format']='schema-test1'
    d['widgets']=[w for w in d['widgets'] if w['name']!='w_count']
    for w in d['widgets']:
        if w['name']=='w_path':w.update(x=61,n=16,rect=[61,357,80,8])
        if w['name']=='w_track':w.update(x=183,n=28,rect=[183,256,140,8])
        if w['name'].startswith('w_row'):w['y']+=1;w['rect'][1]+=1
    d['playlist']={'filename_offset':4,'filename_columns':46,'duration_offset':None}
    d['selection']['enabled']=False;d['progress_span']=200
    for state in ('example','test'):
        f=d['review'][state];f.pop('w_count',None)
        for name in list(f):
            if name.startswith('w_row'):
                old=f[name];filename=old[5:47].rstrip();f[name]=old[:2]+'  '+filename
    text='/qualification/Play';d['review']['test']['w_path']=text[:13]+'...'
    (destination/'skin.json').write_text(json.dumps(d,indent=2)+'\n')
    return destination/'skin.json'
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('destination',type=Path);a=p.parse_args();print(create(a.destination))
