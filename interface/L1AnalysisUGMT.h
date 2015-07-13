#ifndef __L1Analysis_L1AnalysisUGMT_H__
#define __L1Analysis_L1AnalysisUGMT_H__

#include "DataFormats/L1Trigger/interface/Muon.h"
#include "DataFormats/L1TMuon/interface/L1TRegionalMuonCandidateFwd.h"
#include "L1AnalysisUGMTDataFormat.h"

namespace L1Analysis
{
  typedef l1t::L1TRegionalMuonCandidateCollection L1TRegionalMuonColl;
  class L1AnalysisUGMT
  {
  public:
    L1AnalysisUGMT();
    ~L1AnalysisUGMT() {};

    void Set(const l1t::MuonBxCollection&, const L1TRegionalMuonColl&, const L1TRegionalMuonColl&, const L1TRegionalMuonColl&, bool);
    L1AnalysisUGMTDataFormat * getData() { return &ugmt_; }
    void Reset() { ugmt_.Reset(); }

  private :
    void fillTrackFinder(const L1TRegionalMuonColl&, tftype, int&, int);
    L1AnalysisUGMTDataFormat ugmt_;

  };
}
#endif

