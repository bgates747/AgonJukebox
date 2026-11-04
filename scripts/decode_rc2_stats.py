#!/usr/bin/env python3
"""Read the fixed JRC2.DAT report saved by a normal RC2 player session."""
import argparse
import json


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('report',type=argparse.FileType('rb'))
    args=parser.parse_args()
    data=args.report.read()
    if len(data)!=48 or (data[:4]!=b'JRC2' or data[4] not in (1,2)):
        parser.error('Expected a48-byte JRC2 version1/2 report')
    names=['submitted','callbacks','pcm_bytes','finish_busy_polls','compute_service_entries',
           'finished','sample_play_barriers','serviced_ticks','sessions','timer_restorations']
    result={'version':data[4], 'rom_verified':data[4]==1 and data[5]==1,
            'rc2_transport_selected':data[5]==1,'error':data[6],'sampled_due_highwater':data[7]}
    result.update({name:int.from_bytes(data[8+4*i:12+4*i],'little') for i,name in enumerate(names)})
    result['counts_agree']=result['submitted']==result['callbacks']==result['finished']
    result['timers_restored']=result['sessions']==result['timer_restorations']
    print(json.dumps(result,indent=2))
    raise SystemExit(0 if result['rc2_transport_selected'] and not result['error'] and result['counts_agree'] and result['timers_restored'] else 1)

if __name__=='__main__':
    main()
