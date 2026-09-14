"""Compatibility entry point for the shared skin compiler."""
from pathlib import Path
import argparse,sys
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'scripts/skin_schema'))
from compile import build
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--output-root',type=Path,default=ROOT)
    a=p.parse_args()
    build(Path(__file__).with_name('skin.json'),a.output_root.resolve())
