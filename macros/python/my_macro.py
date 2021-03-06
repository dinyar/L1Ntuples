#!/usr/bin/env python 
from L1Analysis import L1Ana, L1Ntuple
from ToolBox import parse_options

def analyse(evt):
    # USER HOOK
    # do what you want to do with the ntuples here
    # example:
    print evt.gmt.N
    print evt.recoMuon.nMuons
    

def main():
    L1Ana.init_l1_analysis()
    print ""
    opts, args = parse_options()
    
    ntuple = L1Ntuple(opts.nevents)

    if opts.flist:
        ntuple.open_with_file_list(opts.flist)
    if opts.fname:
        ntuple.open_with_file(opts.fname)

    for i, event in enumerate(ntuple):
        if (i+1) % 1000 == 0: L1Ana.log.info("Processing event: {n}".format(n=i))
        analyse(event)
    
if __name__ == "__main__":
    main()