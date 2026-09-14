"""Strict v1 authoring-schema and cross-field validation; no device operations."""
import json,re
from pathlib import Path
from PIL import Image
class DefinitionError(ValueError): pass

def require(test,message):
    if not test: raise DefinitionError(message)

def keys(value, required, optional=()):
    require(isinstance(value,dict),'expected object')
    require(set(required)<=value.keys(),f'missing fields: {set(required)-value.keys()}')
    require(value.keys()<=set(required)|set(optional),f'unknown fields: {value.keys()-set(required)-set(optional)}')

def integer(v,lo,hi): require(type(v) is int and lo<=v<=hi,f'expected integer {lo}..{hi}, got {v!r}')
def rgb(v):
    require(isinstance(v,list) and len(v)==3,'RGB requires three channels')
    require(all(type(c) is int and c in (0,85,170,255) for c in v),'color must belong to Agon64')
def box(v):
    require(isinstance(v,list) and len(v)==4,'rectangle needs x,y,width,height')
    x,y,w,h=v
    for n in v: integer(n,0,512)
    require(w>0 and h>0 and x+w<=512 and y+h<=384,'rectangle outside screen')
def _load_definition(path):
    path=Path(path).resolve();d=json.loads(path.read_text(), object_pairs_hook=unique_object);root=path.parent
    keys(d,['schema_version','id','screen','runtime_format','source','backdrop','fonts','palette','assets','widgets','playlist','selection','progress_span','review'])
    require(type(d['schema_version']) is int and d['schema_version']==1,'unsupported authoring version')
    require(isinstance(d['id'],str) and re.fullmatch('[a-z][a-z0-9_]{0,23}',d['id']),'invalid skin id')
    require(d['screen']==[512,384],'v1 requires 512x384')
    expected={'artdeco':'artdeco-test3','seventies':'seventies-test1'}.get(d['id'],'schema-test1')
    require(d['runtime_format']==expected,'runtime profile format mismatch')
    def asset_path(name):
        require(isinstance(name,str) and name and not Path(name).is_absolute(),'input path must be relative')
        p=(root/name).resolve();require(p.is_relative_to(root),'input path escapes skin directory')
        require(p.is_file(),f'missing input {name}');return p
    def image(name,size=None,alpha=False):
        im=Image.open(asset_path(name)).convert('RGBA')
        if size: require(im.size==size,f'{name}: expected {size}')
        require(im.width>0 and im.height>0 and im.width<=512 and im.height<=384,'invalid image dimensions')
        require(all(all(c%85==0 for c in px[:3]) and px[3] in ((0,255) if alpha else (255,)) for px in im.get_flattened_data()),f'{name}: image must use opaque Agon64 (binary alpha allowed only for pointer)')
        return im
    asset_path(d['source']);image(d['backdrop'],(512,384))
    keys(d['fonts'],['small','playlist','normal','selected'])
    require(asset_path(d['fonts']['small']).stat().st_size==2048,'small font must be 256 x 8 bytes')
    require(re.fullmatch(r'[A-Za-z0-9_-]+',Path(d['fonts']['playlist']).stem) is not None,'playlist filename must be assembler-safe')
    require(asset_path(d['fonts']['playlist']).stat().st_size==3072,'playlist font must be 256 x 12 bytes')
    keys(d['palette'],['background','text','selection','selected_text'])
    for v in d['palette'].values():rgb(v)
    for variant,bg in [('normal','background'),('selected','selection')]:
        im=image(d['fonts'][variant],(96,192))
        require(set(im.crop((0,24,6,36)).get_flattened_data())=={tuple(d['palette'][bg])+ (255,)},f'{variant} space glyph must match its row background')
    require(isinstance(d['assets'],list) and len(d['assets'])==22,'v1 requires 22 named control/sprite states')
    required={'idle','play','pause','shuffle_off','shuffle_on','loop_off','loop_on','progress_track','progress_marker','selection_pointer'}|{'volume_'+str(i) for i in range(12)}
    names=set();dims={}
    for a in d['assets']:
        keys(a,['name','file','role']);require(a['name'] in required and a['name'] not in names,'unknown or duplicate state asset');names.add(a['name'])
        require(isinstance(a['role'],str) and bool(a['role']),'asset role required')
        im=image(a['file'],alpha=a['name']=='selection_pointer');dims[a['name']]=im.size
    require(names==required,'missing state assets')
    for group in [('idle','play','pause'),('shuffle_off','shuffle_on'),('loop_off','loop_on'),tuple('volume_'+str(i) for i in range(12))]:
        require(len({dims[n] for n in group})==1,'state variants must have equal dimensions')
    require(dims['selection_pointer']==(10,12),'v1 pointer must be 10x12')
    required_widgets={'w_path','w_page','w_message','w_track','w_elapsed','w_duration','w_detail','w_voltext','w_play','w_shuffle','w_loop','w_volume','w_progress','w_marker'}|{'w_row'+str(i) for i in range(10)}
    seen={}
    require(isinstance(d['widgets'],list),'widgets must be a list')
    for w in d['widgets']:
        require(isinstance(w,dict) and w.get('kind') in ('text','art'),'invalid widget kind')
        if w['kind']=='text':
            keys(w,['name','kind','x','y','n','bg','fg','rect','cell','slot']);integer(w['n'],6,60);rgb(w['bg']);rgb(w['fg']);box(w['rect'])
            require(w['cell'] in ([5,8],[6,12]),'unsupported font cell')
            require(w['slot'] in ('text','digits'),'invalid text slot')
            require(36+w['n']<=96,'widget packet exceeds 96 bytes')
            x,y,rw,rh=w['rect'];width,height=w['cell'];require(x<=w['x'] and y<=w['y'] and w['x']+w['n']*width<=x+rw and w['y']+height<=y+rh,'text exceeds restoration rectangle')
        else:
            keys(w,['name','kind','x','y','asset']);require(w['asset'] in dims,'unknown widget asset');box([w['x'],w['y'],*dims[w['asset']]])
        integer(w['x'],0,511);integer(w['y'],0,383)
        require(w['x']>0 or w['y']>0,'screen origin is reserved for static qualification')
        require(w['name'] in required_widgets|{'w_count'} and w['name'] not in seen,'unknown or duplicate widget role');seen[w['name']]=w
    require(required_widgets<=seen.keys(),'missing required widget roles')
    art_roles={'w_play':'idle','w_shuffle':'shuffle_off','w_loop':'loop_off','w_volume':'volume_11','w_progress':'progress_track','w_marker':'progress_marker'}
    for name,w in seen.items():
        require(w['kind']==('art' if name in art_roles else 'text'),'widget role/type mismatch')
        if name in art_roles:require(w['asset']==art_roles[name],'incorrect initial state binding')
        else:
            require(w['slot']==('digits' if name in ('w_elapsed','w_duration') else 'text'),'widget slot mismatch')
            if name.startswith('w_row'):require(w['cell']==[6,12],'widget font mismatch')
            if w['cell']==[6,12]:
                require(w['bg']==d['palette']['background'] and w['fg']==d['palette']['text'],'6x12 text must match normal glyph colors')
    status_cells={tuple(w['cell']) for name,w in seen.items() if w['kind']=='text' and not name.startswith('w_row')}
    require(len(status_cells)==1,'status widgets must use one common font cell')
    for name,n in [('w_elapsed',8),('w_duration',8),('w_detail',23),('w_voltext',13),('w_message',48)]:require(seen[name]['n']==n,f'{name}: fixed v1 width {n}')
    require(seen['w_page']['n']>=8,'page field too short')
    if 'w_count' in seen:require(seen['w_count']['n']==13,'v1 count field is 13 cells')
    require(seen['w_track']['n']>=14,'track needs status prefix and filename')
    rows=[seen['w_row'+str(i)] for i in range(10)]
    require([w['name'] for w in d['widgets'] if w['name'].startswith('w_row')]==['w_row'+str(i) for i in range(10)],'rows must be ordered')
    for w in rows:
        require(w['n']==58 and w['bg']==d['palette']['background'] and w['fg']==d['palette']['text'],'playlist width/colors mismatch')
        integer(w['y'],0,255)
        require(w['rect'][0]<w['x'],'playlist requires a restored left margin')
    require(all(rows[i]['y']+12<=rows[i+1]['y'] for i in range(9)),'playlist rows overlap')
    keys(d['playlist'],['filename_offset','filename_columns','duration_offset']);p=d['playlist']
    integer(p['filename_offset'],3,40);integer(p['filename_columns'],12,55)
    require(p['filename_offset']+p['filename_columns']<=58,'filename exceeds row')
    if p['duration_offset'] is not None:
        integer(p['duration_offset'],0,50);require(p['filename_offset']+p['filename_columns']<=p['duration_offset'],'filename overlaps duration')
    keys(d['selection'],['enabled','x']);require(type(d['selection']['enabled']) is bool,'selection enabled must be boolean');integer(d['selection']['x'],0,502)
    integer(d['progress_span'],1,255)
    marker,track=seen['w_marker'],seen['w_progress'];mw,mh=dims['progress_marker'];tw,th=dims['progress_track']
    require(track['x']<=marker['x'] and track['y']<=marker['y'] and marker['x']+d['progress_span']+mw<=track['x']+tw and marker['y']+mh<=track['y']+th,'progress marker travel exceeds track')
    keys(d['review'],['example','test','exclude'])
    for fields in (d['review']['example'],d['review']['test']):
        require(isinstance(fields,dict),'review state must be object')
        require(fields.keys()<=seen.keys()|{'selected','active','has_entries','progress'},'unknown preview state')
        integer(fields.get('selected',0),0,9);integer(fields.get('progress',0),0,d['progress_span'])
        for name,value in fields.items():
            if name in seen:
                require(isinstance(value,str) and all(32<=ord(c)<127 for c in value),'preview text must be printable ASCII')
                if seen[name]['kind']=='art':require(value in names and dims[value]==dims[seen[name]['asset']],'invalid preview asset')
    for rect in d['review']['exclude']:
        require(len(rect)==4,'exclusion needs x0,y0,x1,y1');x0,y0,x1,y1=rect;box([x0,y0,x1-x0,y1-y0])
    return d


def unique_object(pairs):
    result={}
    for k,v in pairs:
        require(k not in result,f'duplicate JSON key: {k}')
        result[k]=v
    return result

def load_definition(path):
    try:
        return _load_definition(path)
    except DefinitionError:
        raise
    except (KeyError,TypeError,IndexError,OSError,ValueError) as error:
        raise DefinitionError(f'Invalid skin definition: {error}') from error
