#!/usr/bin/env python3
"""Decode the PCM analyzer's bounded post-quit /JSPEC.DAT report."""
import argparse,json
from pathlib import Path

def decode(data):
    if len(data)!=28 or data[:5]!=b'SPM1\x01' or data[7]!=0:
        raise ValueError('Expected a complete28-byte SPM1 version1 report')
    result={'enabled':data[5],'error':data[6]}
    if result['enabled'] not in (0,1):raise ValueError('Invalid enable state')
    names=('windows','slices','columns','uart_bytes','discarded_jobs')
    result.update({name:int.from_bytes(data[8+i*4:12+i*4],'little') for i,name in enumerate(names)})
    return result

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('report',type=Path);p.add_argument('--expect-enabled',action='store_true');a=p.parse_args()
    result=decode(a.report.read_bytes());print(json.dumps(result,indent=2))
    if result['error']:raise SystemExit('Optional analyzer was disabled after an asset/descriptor error')
    if result['uart_bytes']!=(result['columns']*16)&0xffffffff:raise SystemExit('Inconsistent drawing byte counter')
    if a.expect_enabled and result['enabled']!=1:raise SystemExit('Skin did not enable the analyzer')
if __name__=='__main__':main()
