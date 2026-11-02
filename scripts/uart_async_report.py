#!/usr/bin/env python3
"""Decode the UART-001 prototype's post-quit /JUART.DAT snapshot."""
from __future__ import annotations
import argparse
import json
from pathlib import Path


def decode(data: bytes) -> dict:
    if len(data)!=49 or data[:5]!=b'JUA1\x01':
        raise ValueError('Expected a complete 49-byte JUA1 version-1 snapshot')
    result=dict(zip(('mode','capable','open_status','error','due_highwater'),data[5:10]))
    if result['mode'] not in (0,1,2):
        raise ValueError('Unknown effective transport mode')
    result['transport']={0:'foreground synchronous fallback',1:'async CTS1',2:'async CTS16 OTIRX'}[result['mode']]
    result['effective_batch']={0:0,1:1,2:16}[result['mode']]
    result['elapsed_sysvar_ticks']=int.from_bytes(data[10:13],'little')
    names=('ticks','served','due_overflows','busy','waits','packets','released','payload_bytes','submitted_bytes')
    result.update({name:int.from_bytes(data[13+4*i:17+4*i],'little') for i,name in enumerate(names)})
    return result


def main() -> None:
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('snapshot',type=Path)
    parser.add_argument('--expect-async',action='store_true')
    parser.add_argument('--expect-batch',type=int,choices=(1,16))
    args=parser.parse_args(); result=decode(args.snapshot.read_bytes())
    print(json.dumps(result,indent=2))
    if result['error'] or result['due_overflows']:
        raise SystemExit('Prototype reports an error or saturated due-work counter')
    if result['packets']!=result['released']:
        raise SystemExit('Snapshot does not show all published packet sources released')
    if args.expect_async and result['mode'] not in (1,2):
        raise SystemExit('This run used synchronous fallback, not async transport')

    if args.expect_batch is not None and result['effective_batch']!=args.expect_batch:
        raise SystemExit('Observed transport differs from requested batch expectation')


if __name__=='__main__':main()
