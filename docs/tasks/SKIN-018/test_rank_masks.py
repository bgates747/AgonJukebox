import tempfile,unittest
from pathlib import Path
import numpy as np
from PIL import Image
from rank_masks import calibrate,components,measure,run,load
class Checks(unittest.TestCase):
 def test_exact_threshold_recovery(self):
  with tempfile.TemporaryDirectory() as d:
   p=Path(d);ramp=np.tile(np.arange(256,dtype='uint8'),(24,1))
   Image.fromarray(ramp).convert('RGB').save(p/'source.png')
   Image.fromarray(np.uint8(ramp>91)*255).save(p/'mask.png')
   result=calibrate(p/'source.png',p/'mask.png')
   fit=next(r for r in result['fits'] if r['method']=='pillow-luma')
   self.assertEqual((fit['threshold'],fit['mismatch_pixels']),(91,0))
 def test_separate_regions_and_noise(self):
  gray=np.zeros((100,100),dtype='uint8');gray[10:35,10:35]=180;gray[55:80,55:80]=200
  clean=measure(gray,100);gray[90,5]=210
  noisy=measure(gray,100)
  self.assertEqual(clean['useful_components'],2)
  self.assertEqual(noisy['tiny_components'],1)
  self.assertLess(noisy['score'],clean['score'])
  self.assertIsNone(measure(np.zeros((10,10),dtype='uint8'),100))
  self.assertEqual(len(components(np.eye(2,dtype=bool))[1]),2)
 def test_guards(self):
  with tempfile.TemporaryDirectory() as d:
   p=Path(d);Image.new('RGBA',(10,10),(255,0,0,0)).save(p/'alpha.png')
   with self.assertRaises(ValueError):load(p/'alpha.png')
   with self.assertRaisesRegex(ValueError,'Output exists'):run(p/'missing',p)
if __name__=='__main__':unittest.main()
