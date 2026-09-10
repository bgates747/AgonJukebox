"""Extract semantic regions, exact repeated strips and deduplicated patches."""

import hashlib
import numpy as np

from refine import mode_rgb


class Extractor:
    def __init__(self, max_patch=64, repeat=8):
        self.max_patch=max_patch; self.repeat=repeat
        self.assets=[]; self.operations=[]; self.dictionary={}

    def asset(self,a,kind):
        key=(a.shape, a.tobytes())
        if key in self.dictionary:
            return self.dictionary[key]
        name=f'part-{len(self.assets):03d}'
        mirrored=self.dictionary.get((a.shape,a[:,::-1].tobytes()))
        self.dictionary[key]=name
        self.assets.append({'name':name,'pixels':a.copy(),'kind':kind,
                            'rgb_sha256':hashlib.sha256(a.tobytes()).hexdigest()})
        if mirrored:
            self.assets[-1]['derive']={'op':'mirror-x','source':mirrored}
        return name

    def fill(self,a,x,y,region):
        self.operations.append({'op':'fill','box':[x,y,x+a.shape[1],y+a.shape[0]],
                                'color':a[0,0].tolist(),'region':region})

    def bitmap(self,a,x,y,region,kind='patch'):
        self.operations.append({'op':'bitmap','asset':self.asset(a,kind),'at':[x,y],'region':region})

    def repeat_strip(self,a,x,y,axis,region):
        length=a.shape[axis]
        step=self.repeat if length>=2*self.repeat else length
        count,tail=divmod(length,step)
        tile=a[:step] if axis==0 else a[:,:step]
        self.operations.append({'op':'repeat','asset':self.asset(tile,'vertical-strip' if axis==0 else 'horizontal-strip'),
                                'at':[x,y],'step':[0,step] if axis==0 else [step,0],'count':count,'region':region})
        if tail:
            tile=a[-tail:] if axis==0 else a[:,-tail:]
            self.bitmap(tile,x+(count*step if axis==1 else 0),y+(count*step if axis==0 else 0),region,'end-strip')

    @staticmethod
    def repeated_run(a,axis):
        rows=a if axis==0 else a.transpose(1,0,2)
        equal=np.all(rows[1:]==rows[:-1],axis=(1,2))
        starts=np.r_[0,np.flatnonzero(~equal)+1,len(rows)]
        i=int(np.argmax(np.diff(starts)))
        return int(starts[i]),int(starts[i+1])

    def rect(self,a,x,y,region):
        h,w=a.shape[:2]
        if not h or not w: return
        if np.all(a==a[0,0]):
            self.fill(a,x,y,region);return
        # A fill plus a tight non-background crop can save large empty margins.
        # Require room for the extra fill and record overhead before splitting.
        background=mode_rgb(a.reshape(-1,3))
        yy,xx=np.nonzero(np.any(a!=background,axis=2))
        x0,x1=int(xx.min()),int(xx.max())+1;y0,y1=int(yy.min()),int(yy.max())+1
        if h*w-(x1-x0)*(y1-y0)>48:
            self.fill(np.broadcast_to(background,a.shape),x,y,region)
            self.rect(a[y0:y1,x0:x1],x+x0,y+y0,region)
            return
        for axis in (0,1):
            if np.all(a==(a[0:1] if axis==0 else a[:,0:1])):
                # Cut the long constant center out of a repeated frame section;
                # otherwise an 8-row strip would store hundreds of black pixels.
                start,end=self.repeated_run(a,1-axis)
                if end-start>=16:
                    if axis==0:
                        self.rect(a[:,:start],x,y,region)
                        self.rect(a[:,start:end],x+start,y,region)
                        self.rect(a[:,end:],x+end,y,region)
                    else:
                        self.rect(a[:start],x,y,region)
                        self.rect(a[start:end],x,y+start,region)
                        self.rect(a[end:],x,y+end,region)
                    return
                self.repeat_strip(a,x,y,axis,region);return
        for axis in (0,1):
            start,end=self.repeated_run(a,axis)
            if end-start>=16:
                if axis==0:
                    self.rect(a[:start],x,y,region)
                    self.rect(a[start:end],x,y+start,region)
                    self.rect(a[end:],x,y+end,region)
                else:
                    self.rect(a[:,:start],x,y,region)
                    self.rect(a[:,start:end],x+start,y,region)
                    self.rect(a[:,end:],x+end,y,region)
                return
        if max(h,w)>self.max_patch:
            if w>=h:
                cut=w//2;self.rect(a[:,:cut],x,y,region);self.rect(a[:,cut:],x+cut,y,region)
            else:
                cut=h//2;self.rect(a[:cut],x,y,region);self.rect(a[cut:],x,y+cut,region)
            return
        self.bitmap(a,x,y,region)


def separate_demo(candidate,parameters):
    static=candidate.copy()
    overlay=np.zeros((*candidate.shape[:2],4),dtype=np.uint8)
    for r in parameters['demo_regions']:
        x0,y0,x1,y1=r['box']
        overlay[y0:y1,x0:x1,:3]=candidate[y0:y1,x0:x1]
        overlay[y0:y1,x0:x1,3]=255
        if r['background']=='left-border':
            # Preserve the frame cross-section hidden by the selection arrow.
            static[y0:y1,x0:x1]=candidate[145:146,x0:x1]
        else:
            static[y0:y1,x0:x1]=r['background']
    return static,overlay


def extract(candidate,parameters):
    static,overlay=separate_demo(candidate,parameters)
    original_static=static.copy()
    icons=[]
    for r in parameters.get('icons',[])+parameters.get('parts',[]):
        x0,y0,x1,y1=r['box']
        icons.append((static[y0:y1,x0:x1].copy(),x0,y0,r['name'], 'ornament' if r in parameters.get('parts',[]) else 'icon'))
        static[y0:y1,x0:x1]=r['background']
    frames=[]
    for r in parameters.get('frames',[]):
        x0,y0,x1,y1=r['box'];l,t,right,b=r['insets']
        xs=[x0,x0+l,x1-right,x1];ys=[y0,y0+t,y1-b,y1]
        if parameters.get('frame_strategy')=='whole':
            icons.append((static[y0:y1,x0:x1].copy(),x0,y0,r['name'],'frame'))
            static[y0:y1,x0:x1]=r['background']
            continue
        for j in range(3):
            for i in range(3):
                name=r['name']+'/'+['top','middle','bottom'][j]+'-'+['left','center','right'][i]
                frames.append((static[ys[j]:ys[j+1],xs[i]:xs[i+1]].copy(),xs[i],ys[j],name))
        static[y0:y1,x0:x1]=r['background']
    ex=Extractor(parameters['patch_max'],parameters['repeat_height'])
    regions=[('central-panels',[68,0,444,384])]
    for side,x in [('left',0),('right',444)]:
        regions += [(side+'-upper',[x,0,x+68,135]),(side+'-lower',[x,236,x+68,384]),
                    (side+'-shaft-outer',[x,135,x+6,236]),
                    (side+'-shaft-profile',[x+6,135,x+62,236]),
                    (side+'-shaft-inner',[x+62,135,x+68,236])]
    for name,(x0,y0,x1,y1) in regions:
        ex.rect(static[y0:y1,x0:x1],x0,y0,name)
    for a,x,y,name in frames:
        ex.rect(a,x,y,name)
    # Whole surrounds must be restored before their separately extracted icons.
    icons.sort(key=lambda item: 0 if item[4]=='frame' else 1)
    for a,x,y,name,kind in icons:
        ex.bitmap(a,x,y,name,kind)
    return ex,original_static,overlay
