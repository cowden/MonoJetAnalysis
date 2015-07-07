#ifndef Constants_h
#define Constants_h

// Using the EventData wrapper
#include "EventData.h"
#include "Operation.h"

// Using streams
#include <iostream>
#include <vector>

// ROOT stuff
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TLorentzVector.h"

using namespace std;

namespace Constants 
{
  // string outputDir    = "/afs/cern.ch/work/s/srimanob/Monojet/Production/Ver07B/CMSSW_7_2_3/src/MonoJetAnalysis/NtupleAnalyzer/";
  string outputDir    = "/media/sf_proj/Monojets/cmsdev/CMSSW_7_4_1/src/MonoJetAnalysis/NtupleAnalyzer/";
  string condorOutDir = "/uscmst1b_scratch/lpc1/DayLifetime/vergili/condor/"; 
  string condorBin    = "/uscms_data/d2/vergili/sep/CMSSW_5_3_4_cand1/bin/slc5_amd64_gcc462/"; 
}

#include "Constants.cc"
#endif 
