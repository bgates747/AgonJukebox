#!/usr/bin/env python3
"""Decode the fixed JRFC report; counters are not physical timing measurements."""
import argparse,json,struct
from pathlib import Path
p=argparse.ArgumentParser(description=__doc__);p.add_argument('report',type=Path);a=p.parse_args();d=a.report.read_bytes()
if len(d)!=52 or d[:6]!=b'JRFC\x01\x25':p.error('Expected 52-byte JRFC version1/syscall25h report')
names=['submissions','observed_callbacks','pcm_bytes','pending_polls','compute_service_entries','local_drains','sample_play_barriers','serviced_ticks','sessions','timer_restorations','temt_wait_polls']
print(json.dumps(dict(version=d[4],syscall=d[5],error=d[6],sampled_due_high=d[7],**dict(zip(names,struct.unpack('<11I',d[8:])))),indent=2))
