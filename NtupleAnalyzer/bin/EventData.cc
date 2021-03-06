//////////////////////////////////////////////////////////////////////
//                                                                  //
//          Author:  Mehmet Vergili   vergili@cern.ch               //
//                                                                  //
//////////////////////////////////////////////////////////////////////
#include "EventData.h"
#include <iostream>
#include "time.h"
#include <TH1D.h>
#include "Operation.h"
#include "string.h"
#include <map>
#include <LHAPDF/LHAPDF.h>

using namespace std;
using namespace Operation;
using namespace LHAPDF;

EventData::EventData(const string &  fileName, UInt_t maxEvents, int isMC) : mDataSet("undefined") 
{
  // CERN
  string fileDirectory = "root://eoscms//eos/cms/store/group/phys_exotica/monojet/ntuple-2012-v6D/";
  //string fileDirectory = "file:/data1/srimanob/Data-Monojet/ntuple-2012-v6D/";
  // FNAL
  //string fileDirectory  = "file:/uscms_data/d2/lpcjm/DATA/2012/ntuple_v6A_temp";
  
  // Pileup - CERN
  //mydataset["pileup"]   = "/afs/cern.ch/user/s/srimanob/public/ForMonoJet/PUHist/pileup_monojet_22JanReReco_pixelLumi.root";
  mydataset["pileup"]   = "/home/sundleeb/DM15ana/Ntuples/pileup_monojet_22JanReReco_pixelLumi.root";
  // Pileup - FNAL
  //mydataset["pileup"]   = "/uscms_data/d3/srimanob/ntuple_v6A/pileup_monojet_20130101_All2012_v6A_69300.root";  
  
  // Check me before run
  mEvent       = 0;
  mMaxEvents   = maxEvents;
  mFileName    = fileName; 
  misMC        = isMC;
  mJetType     = "pf";
  mLepType     = "m";
  mMetType     = 10;
  mEnergyScale = 0.;
  mSecJetCut   = 30;
  
  //
  mydataset["m1avpu20bx25"]       = "file:/afs/cern.ch/work/s/srimanob/Monojet/Production/Ver07B/CMSSW_7_2_3/src/MonoJetAnalysis/NtupleAnalyzer/test/config/M-1_AV_PU20bx25/ntuple_M-1_AV_PU20bx25.root";
  mylumi["m1avpu20bx25"]          = 19712.;
  mydataset["m1avpu40bx25"]       = "file:/afs/cern.ch/work/s/srimanob/Monojet/Production/Ver07B/CMSSW_7_2_3/src/MonoJetAnalysis/NtupleAnalyzer/test/config/M-1_AV_PU40bx25/ntuple_M-1_AV_PU40bx25.root";
  mylumi["m1avpu40bx25"]          = 19712.;


 // W_test
  mydataset["W_test"]        ="file:/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_Wtest.root";

  mylumi["W_test"]         = 4958./3.33;  

// Sync Exercise Added by Sonaina on 17-june 2015 ....
  mydataset["ADD_sync"]      ="file:/media/sf_proj/Monojets/ntuples/ntuple_ADD_Synch.root";

  mylumi["ADD_sync"]     = 1;

  mydataset["TTbar_sync"]   ="file:/media/sf_proj/Monojets/ntuples/ntuple_TTbar_Synch.root";

  mylumi["TTbar_sync"]     =1;



  // NonTh
  mydataset["nonth1TeVrun56"]      = "file:/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_1TeV_run56.root";
  mylumi["nonth1TeVrun56"]         = 1000./3.33;

  mydataset["nonth1TeVrun34"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_1TeV_run34.root";
  mydataset["nonth2TeVrun34"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_2TeV_run34.root";
  mydataset["nonth2TeVrun56"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_2TeV_run56.root";
  mydataset["nonth3TeVrun34"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_3TeV_run34.root";
  mydataset["nonth3TeVrun56"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_3TeV_run56.root";
  mydataset["nonth0.5TeVrun34"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_500GeV_run34.root";
  mydataset["nonth0.5TeVrun56"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_500GeV_run56.root";

  mydataset["nonth1TeV1"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/ntuple_newNtupleAnalyzer/step4_ntuple_NonThDM_1TeV_1.root";
  mydataset["nonth1TeV2"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/ntuple_newNtupleAnalyzer/step4_ntuple_NonThDM_1TeV_2.root";
  mydataset["nonth1TeV3"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/ntuple_newNtupleAnalyzer/step4_ntuple_NonThDM_1TeV_3.root";
  mydataset["nonth1TeV4"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/ntuple_newNtupleAnalyzer/step4_ntuple_NonThDM_1TeV_4.root";

  mydataset["nonth1TeVrun34v2"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_1TeV_run34_v2.root";
  mydataset["nonth1TeVrun56v2"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_1TeV_run56_v2.root";
  mydataset["nonth2TeVrun34v2"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_2TeV_run34_v2.root";
  mydataset["nonth2TeVrun56v2"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_2TeV_run56_v2.root";
  mydataset["nonth3TeVrun34v2"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_3TeV_run34_v2.root";
  mydataset["nonth3TeVrun56v2"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_3TeV_run56_v2.root";
  mydataset["nonth0.5TeVrun34v2"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_500GeV_run34_v2.root";
  mydataset["nonth0.5TeVrun56v2"]="/home/sundleeb/DM15ana/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/step4_ntuple_NonThDM_500GeV_run56_v2.root";

  mydataset["nonTh1TeV_01_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_01_v2.root";
  mydataset["nonTh1TeV_02_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_02_v2.root";
  mydataset["nonTh1TeV_03_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_03_v2.root";
  mydataset["nonTh1TeV_04_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_04_v2.root";
  mydataset["nonTh1TeV_05_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_05_v2.root";
  mydataset["nonTh1TeV_06_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_06_v2.root";
  mydataset["nonTh1TeV_07_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_07_v2.root";
  mydataset["nonTh1TeV_08_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_08_v2.root";
  mydataset["nonTh1TeV_09_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_09_v2.root";
  mydataset["nonTh1TeV_10_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_10_v2.root";
  mydataset["nonTh1TeV_11_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_11_v2.root";
  mydataset["nonTh1TeV_12_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_12_v2.root";
  mydataset["nonTh1TeV_13_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_13_v2.root";
  mydataset["nonTh1TeV_14_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_14_v2.root";
  mydataset["nonTh1TeV_15_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_15_v2.root";
  mydataset["nonTh1TeV_16_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_16_v2.root";
  mydataset["nonTh1TeV_17_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_17_v2.root";
  mydataset["nonTh1TeV_18_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_18_v2.root";
  mydataset["nonTh1TeV_19_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_19_v2.root";
  mydataset["nonTh1TeV_20_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_20_v2.root";
  mydataset["nonTh1TeV_21_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_21_v2.root";
  mydataset["nonTh1TeV_22_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_22_v2.root";
  mydataset["nonTh1TeV_23_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_23_v2.root";
  mydataset["nonTh1TeV_24_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_24_v2.root";
  mydataset["nonTh1TeV_25_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_25_v2.root";
  mydataset["nonTh1TeV_26_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_26_v2.root";
  mydataset["nonTh1TeV_27_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_27_v2.root";
  mydataset["nonTh1TeV_28_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_28_v2.root";
  mydataset["nonTh1TeV_29_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_29_v2.root";
  mydataset["nonTh1TeV_30_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_30_v2.root";
  mydataset["nonTh1TeV_31_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_31_v2.root";
  mydataset["nonTh1TeV_32_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_32_v2.root";
  mydataset["nonTh1TeV_33_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_33_v2.root";
  mydataset["nonTh1TeV_34_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_34_v2.root";
  mydataset["nonTh1TeV_35_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_35_v2.root";
  mydataset["nonTh1TeV_36_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_36_v2.root";
  mydataset["nonTh1TeV_37_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_37_v2.root";
  mydataset["nonTh1TeV_38_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_38_v2.root";
  mydataset["nonTh1TeV_39_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_39_v2.root";
  mydataset["nonTh1TeV_40_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_40_v2.root";
  mydataset["nonTh1TeV_41_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_41_v2.root";
  mydataset["nonTh1TeV_42_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_42_v2.root";
  mydataset["nonTh1TeV_44_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_44_v2.root";
  mydataset["nonTh1TeV_45_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_45_v2.root";
  mydataset["nonTh1TeV_46_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_46_v2.root";
  mydataset["nonTh1TeV_48_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_48_v2.root";
  mydataset["nonTh1TeV_49_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_49_v2.root";
  mydataset["nonTh1TeV_50_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_50_v2.root";
  mydataset["nonTh1TeV_51_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_51_v2.root";
  mydataset["nonTh1TeV_52_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_52_v2.root";
  mydataset["nonTh1TeV_53_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_53_v2.root";
  mydataset["nonTh1TeV_54_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_54_v2.root";
  mydataset["nonTh1TeV_55_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_55_v2.root";
  mydataset["nonTh1TeV_56_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_56_v2.root";
  mydataset["nonTh1TeV_57_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_57_v2.root";
  mydataset["nonTh1TeV_58_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_58_v2.root";
  mydataset["nonTh1TeV_59_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_59_v2.root";
  mydataset["nonTh1TeV_60_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_60_v2.root";
  mydataset["nonTh1TeV_61_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_61_v2.root";
  mydataset["nonTh1TeV_62_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_62_v2.root";
  mydataset["nonTh1TeV_63_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_63_v2.root";
  mydataset["nonTh1TeV_64_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_64_v2.root";
  mydataset["nonTh1TeV_65_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_65_v2.root";
  mydataset["nonTh1TeV_66_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_66_v2.root";
  mydataset["nonTh1TeV_67_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_67_v2.root";
  mydataset["nonTh1TeV_68_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_68_v2.root";
  mydataset["nonTh1TeV_69_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_69_v2.root";
  mydataset["nonTh1TeV_70_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_70_v2.root";
  mydataset["nonTh1TeV_71_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_71_v2.root";
  mydataset["nonTh1TeV_72_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_72_v2.root";
  mydataset["nonTh1TeV_73_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_73_v2.root";
  mydataset["nonTh1TeV_74_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_74_v2.root";
  mydataset["nonTh1TeV_75_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_75_v2.root";
  mydataset["nonTh1TeV_76_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_76_v2.root";
  mydataset["nonTh1TeV_77_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_77_v2.root";
  mydataset["nonTh1TeV_79_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_79_v2.root";
  mydataset["nonTh1TeV_80_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_80_v2.root";
  mydataset["nonTh1TeV_81_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_81_v2.root";
  mydataset["nonTh1TeV_82_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_82_v2.root";
  mydataset["nonTh1TeV_83_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_83_v2.root";
  mydataset["nonTh1TeV_84_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_84_v2.root";
  mydataset["nonTh1TeV_85_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_85_v2.root";
  mydataset["nonTh1TeV_86_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_86_v2.root";
  mydataset["nonTh1TeV_87_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_87_v2.root";
  mydataset["nonTh1TeV_88_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_88_v2.root";
  mydataset["nonTh1TeV_89_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_89_v2.root";
  mydataset["nonTh1TeV_90_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_90_v2.root";
  mydataset["nonTh1TeV_91_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_91_v2.root";
  mydataset["nonTh1TeV_92_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_92_v2.root";
  mydataset["nonTh1TeV_93_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_93_v2.root";
  mydataset["nonTh1TeV_94_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_94_v2.root";
  mydataset["nonTh1TeV_95_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_95_v2.root";
  mydataset["nonTh1TeV_96_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_96_v2.root";
  mydataset["nonTh1TeV_97_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_97_v2.root";
  mydataset["nonTh1TeV_98_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_98_v2.root";
  mydataset["nonTh1TeV_99_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_99_v2.root";
  mydataset["nonTh1TeV_100_v2"]="/lustre/scratch/sundleeb/CMSSW_7_4_0_pre6/src/MonoJetAnalysis/NtupleAnalyzer/test/config/test/data/step4_ntuple_NonThDM_1000_GeV_run_100_v2.root";



  mydataset["DM_MJ_M_100_AV_local"]="/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/DarkMatter_Monojet_M_100_AV_local.root";

  mydataset["DM_MJ_M_1000_AV"]="/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_DarkMatter_Monojet_M-1000_AV.root";

  mydataset["DM_MJ_M_1000_V"]="/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_DarkMatter_Monojet_M-1000_V.root";

  mydataset["DM_MJ_M_100_AV"]="/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_DarkMatter_Monojet_M-100_AV.root";

  mydataset["DM_MJ_M_100_V"]="/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_DarkMatter_Monojet_M-100_V.root";

  mydataset["DM_MonoJet_M_10_AV"]="/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_DarkMatter_Monojet_M-10_AV.root";

  mydataset["DM_MonoJet_M_10_V"]="/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_DarkMatter_Monojet_M-10_V.root";

  mydataset["DM_MonoJet_M_1_AV"]="/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_DarkMatter_Monojet_M-1_AV.root";

    mylumi["DM_MonoJet_M_10_V"] =   189400./100.8;
    mylumi["DM_MonoJet_M_10_AV"] =  191200./100.8;

    mylumi["nonth1TeVrun34"]=1000./0.12579;
    mylumi["nonth2TeVrun34"]=1000./0.004047;
    mylumi["nonth2TeVrun56"]=1000./0.14791;
    mylumi["nonth3TeVrun34"]=1000./0.00036545;
    mylumi["nonth3TeVrun56"]=1000./0.039131;
    mylumi["nonth0.5TeVrun34"]=1000./2.2038;
    mylumi["nonth0.5TeVrun56"]=1000./55.442;
    mylumi["nonth1TeV1"]=1000./0.0050967;
    mylumi["nonth1TeV2"]=1000./0.041742;
    mylumi["nonth1TeV3"]=1000./0.050159;
    mylumi["nonth1TeV4"]=1000./23.387;

    mylumi["nonth1TeVrun34v2"]=1000./0.12567;
    mylumi["nonth1TeVrun56v2"]=1000./3.2919;
    mylumi["nonth2TeVrun34v2"]=1000./0.0004843;
    mylumi["nonth2TeVrun56v2"]=1000./0.015857;
    mylumi["nonth3TeVrun34v2"]=1000./0.00032621;
    mylumi["nonth3TeVrun56v2"]=1000./0.012849;
    mylumi["nonth0.5TeVrun34v2"]=1000./2.2091;
    mylumi["nonth0.5TeVrun56v2"]=1000./55.267;

    mylumi["nonTh1TeV_01_v2"]=1000./0.0014597;
    mylumi["nonTh1TeV_02_v2"]=1000./0.003342;
    mylumi["nonTh1TeV_03_v2"]=1000./0.005098;
    mylumi["nonTh1TeV_04_v2"]=1000./0.005565;
    mylumi["nonTh1TeV_05_v2"]=1000./0.005910;
    mylumi["nonTh1TeV_06_v2"]=1000./0.008296;
    mylumi["nonTh1TeV_07_v2"]=1000./0.028019;
    mylumi["nonTh1TeV_08_v2"]=1000./0.30176;
    mylumi["nonTh1TeV_09_v2"]=1000./7.7655;
    mylumi["nonTh1TeV_10_v2"]=1000./33.838;
    mylumi["nonTh1TeV_11_v2"]=1000./0.0016958;
    mylumi["nonTh1TeV_12_v2"]=1000./0.0052204;
    mylumi["nonTh1TeV_13_v2"]=1000./0.012472;
    mylumi["nonTh1TeV_14_v2"]=1000./0.01561;
    mylumi["nonTh1TeV_15_v2"]=1000./0.01687;
    mylumi["nonTh1TeV_16_v2"]=1000./0.019811;
    mylumi["nonTh1TeV_17_v2"]=1000./0.04037;
    mylumi["nonTh1TeV_18_v2"]=1000./0.31300;
    mylumi["nonTh1TeV_19_v2"]=1000./7.8286;
    mylumi["nonTh1TeV_20_v2"]=1000./34.837;
    mylumi["nonTh1TeV_21_v2"]=1000./0.0018434;
    mylumi["nonTh1TeV_22_v2"]=1000./0.0069735;
    mylumi["nonTh1TeV_23_v2"]=1000./0.031592;
    mylumi["nonTh1TeV_24_v2"]=1000./0.063548;
    mylumi["nonTh1TeV_25_v2"]=1000./0.085514;
    mylumi["nonTh1TeV_26_v2"]=1000./0.098009;
    mylumi["nonTh1TeV_27_v2"]=1000./0.12401;
    mylumi["nonTh1TeV_28_v2"]=1000./0.4106;
    mylumi["nonTh1TeV_29_v2"]=1000./7.9025;
    mylumi["nonTh1TeV_30_v2"]=1000./34.299;
    mylumi["nonTh1TeV_31_v2"]=1000./0.0018729;
    mylumi["nonTh1TeV_32_v2"]=1000./0.0073871;
    mylumi["nonTh1TeV_33_v2"]=1000./0.041908;
    mylumi["nonTh1TeV_34_v2"]=1000./0.12567;
    mylumi["nonTh1TeV_35_v2"]=1000./0.25236;
    mylumi["nonTh1TeV_36_v2"]=1000./0.35828;
    mylumi["nonTh1TeV_37_v2"]=1000./0.41531;
    mylumi["nonTh1TeV_38_v2"]=1000./0.74525;
    mylumi["nonTh1TeV_39_v2"]=1000./8.0081;
    mylumi["nonTh1TeV_40_v2"]=1000./33.682;
    mylumi["nonTh1TeV_41_v2"]=1000./0.0018847;
    mylumi["nonTh1TeV_42_v2"]=1000./0.0074999;
    mylumi["nonTh1TeV_44_v2"]=1000./0.16809;
    mylumi["nonTh1TeV_45_v2"]=1000./0.50567;
    mylumi["nonTh1TeV_46_v2"]=1000./1.1674;
    mylumi["nonTh1TeV_48_v2"]=1000./2.0663;
    mylumi["nonTh1TeV_49_v2"]=1000./8.8381;
    mylumi["nonTh1TeV_50_v2"]=1000./34.491;
    mylumi["nonTh1TeV_51_v2"]=1000./0.0019394;
    mylumi["nonTh1TeV_52_v2"]=1000./0.0077688;
    mylumi["nonTh1TeV_53_v2"]=1000./0.048299;
    mylumi["nonTh1TeV_54_v2"]=1000./0.19080;
    mylumi["nonTh1TeV_55_v2"]=1000./0.72101;
    mylumi["nonTh1TeV_56_v2"]=1000./3.2919;
    mylumi["nonTh1TeV_57_v2"]=1000./6.8721;
    mylumi["nonTh1TeV_58_v2"]=1000./10.452;
    mylumi["nonTh1TeV_59_v2"]=1000./15.930;
    mylumi["nonTh1TeV_60_v2"]=1000./33.595;
    mylumi["nonTh1TeV_61_v2"]=1000./0.0021101;
    mylumi["nonTh1TeV_62_v2"]=1000./0.0084426;
    mylumi["nonTh1TeV_63_v2"]=1000./0.052742;
    mylumi["nonTh1TeV_64_v2"]=1000./0.20995;
    mylumi["nonTh1TeV_65_v2"]=1000./0.82855;
    mylumi["nonTh1TeV_66_v2"]=1000./4.7427;
    mylumi["nonTh1TeV_67_v2"]=1000./14.652;
    mylumi["nonTh1TeV_68_v2"]=1000./31.533;
    mylumi["nonTh1TeV_69_v2"]=1000./37.605;
    mylumi["nonTh1TeV_70_v2"]=1000./44.006;
    mylumi["nonTh1TeV_71_v2"]=1000./0.0023811;    
    mylumi["nonTh1TeV_72_v2"]=1000./0.0095567;
    mylumi["nonTh1TeV_73_v2"]=1000./0.059733;
    mylumi["nonTh1TeV_74_v2"]=1000./0.23862;
    mylumi["nonTh1TeV_75_v2"]=1000./0.94736;
    mylumi["nonTh1TeV_76_v2"]=1000./5.7755;
    mylumi["nonTh1TeV_77_v2"]=1000./21.207;
    mylumi["nonTh1TeV_79_v2"]=1000./92.916;
    mylumi["nonTh1TeV_80_v2"]=1000./66.123;
    mylumi["nonTh1TeV_81_v2"]=1000./0.0010765;
    mylumi["nonTh1TeV_82_v2"]=1000./0.0043000;
    mylumi["nonTh1TeV_83_v2"]=1000./0.026941;
    mylumi["nonTh1TeV_84_v2"]=1000./0.10761;
    mylumi["nonTh1TeV_85_v2"]=1000./0.42813;
    mylumi["nonTh1TeV_86_v2"]=1000./2.6642;
    mylumi["nonTh1TeV_87_v2"]=1000./10.405;
    mylumi["nonTh1TeV_88_v2"]=1000./37.581;
    mylumi["nonTh1TeV_89_v2"]=1000./126.33;
    mylumi["nonTh1TeV_90_v2"]=1000./141.96;
    mylumi["nonTh1TeV_91_v2"]=1000./0.00030219;
    mylumi["nonTh1TeV_92_v2"]=1000./0.0012021;
    mylumi["nonTh1TeV_93_v2"]=1000./0.0076614;
    mylumi["nonTh1TeV_94_v2"]=1000./0.030580;
    mylumi["nonTh1TeV_95_v2"]=1000./0.12239;
    mylumi["nonTh1TeV_96_v2"]=1000./0.75724;
    mylumi["nonTh1TeV_97_v2"]=1000./3.0574;
    mylumi["nonTh1TeV_98_v2"]=1000./11.879;
    mylumi["nonTh1TeV_99_v2"]=1000./61.650;
    mylumi["nonTh1TeV_100_v2"]=1000./138.56;


  // Phys14DR
  mydataset["py14Znunu100"] = "file:/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_ZJetsToNuNu_HT_100to200.root";
  mydataset["py14Znunu200"] = "file:/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_ZJetsToNuNu_HT_200to400.root";
  mydataset["py14Znunu400"] = "file:/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_ZJetsToNuNu_HT_400to600.root";
  mydataset["py14Znunu600"] = "file:/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_ZJetsToNuNu_HT_600toInf.root";
  // mydataset["py14Znunu600"] = "file:
  mylumi["py14Znunu100"] =  4986424./372.6;
  mylumi["py14Znunu200"] =  4546470./100.8;
  mylumi["py14Znunu400"] =  4432800./11.99;
  mylumi["py14Znunu600"] =  4463806./4.113;
  // mylumi["py14Znunu600"] =

  mydataset["py14Wjet100"] = "file:/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_WJetsToLN_HT_100to200.root";
  mydataset["py14Wjet200"] = "file:/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_WJetsToLN_HT_200to400.root";
  mydataset["py14Wjet400"] = "file:/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_WJetsToLN_HT_400to600.root";
  mydataset["py14Wjet600"] = "file:/lustre/hep/ccowden/CMSMonojet/NtupleMaker/ntuples/ntuple_WJetsToLN_HT_600toInf.root";
  mylumi["py14Wjet100"] =  5262265./1817.;
  mylumi["py14Wjet200"] =  4936077./471.6;
  mylumi["py14Wjet400"] =  4640594./55.61;
  mylumi["py14Wjet600"] =  4581841./18.81;






  // Data
  mydataset["met1"]       = fileDirectory + "Data_22Jan13_V6D_2012A_part1.root";
  mydataset["met2"]       = fileDirectory + "Data_22Jan13_V6D_2012A_part2.root";
  mydataset["met3"]       = fileDirectory + "Data_22Jan13_V6D_2012B_part1.root";
  mydataset["met4"]       = fileDirectory + "Data_22Jan13_V6D_2012B_part2.root";
  mydataset["met5"]       = fileDirectory + "Data_22Jan13_V6D_2012B_part3.root";
  mydataset["met6"]       = fileDirectory + "Data_22Jan13_V6D_2012C_part1.root";
  mydataset["met7"]       = fileDirectory + "Data_22Jan13_V6D_2012C_part2.root";
  mydataset["met8"]       = fileDirectory + "Data_22Jan13_V6D_2012C_part3.root";
  mydataset["met9"]       = fileDirectory + "Data_22Jan13_V6D_2012C_part4.root";
  mydataset["met10"]      = fileDirectory + "Data_22Jan13_V6D_2012C_part5.root";
  mydataset["met11"]      = fileDirectory + "Data_22Jan13_V6D_2012C_part6.root";
  mydataset["met12"]      = fileDirectory + "Data_22Jan13_V6D_2012D_part1.root";
  mydataset["met13"]      = fileDirectory + "Data_22Jan13_V6D_2012D_part2.root";
  mydataset["met14"]      = fileDirectory + "Data_22Jan13_V6D_2012D_part3.root";
  mydataset["met15"]      = fileDirectory + "Data_22Jan13_V6D_2012D_part4.root";
  mydataset["met16"]      = fileDirectory + "Data_22Jan13_V6D_2012D_part5.root";
  mylumi["met1"]          = 19712.;
  mylumi["met2"]          = 19712.;
  mylumi["met3"]          = 19712.;
  mylumi["met4"]          = 19712.;
  mylumi["met5"]          = 19712.;
  mylumi["met6"]          = 19712.;
  mylumi["met7"]          = 19712.;   
  mylumi["met8"]          = 19712.;
  mylumi["met9"]          = 19712.;
  mylumi["met10"]         = 19712.;
  mylumi["met11"]         = 19712.;
  mylumi["met12"]         = 19712.;
  mylumi["met13"]         = 19712.;
  mylumi["met14"]         = 19712.;
  mylumi["met15"]         = 19712.;
  mylumi["met16"]         = 19712.;
  
  // Znunu S10
  mydataset["znunu50"]    = fileDirectory + "MC_S10_V6D_ZJetsToNuNu_050_HT_100_10601pb.root";
  mydataset["znunu100"]   = fileDirectory + "MC_S10_V6D_ZJetsToNuNu_100_HT_200_27552pb.root";
  mydataset["znunu200p1"] = fileDirectory + "MC_S10_V6D_ZJetsToNuNu_200_HT_400_part1_121858pb.root"; 
  mydataset["znunu200p2"] = fileDirectory + "MC_S10_V6D_ZJetsToNuNu_200_HT_400_part2_121858pb.root"; 
  mydataset["znunu400"]   = fileDirectory + "MC_S10_V6D_ZJetsToNuNu_400_HT_inf_190923pb.root";
  mylumi["znunu50"]       = 10601.;
  mylumi["znunu100"]      = 27552.;
  mylumi["znunu200p1"]    = 121858.; 
  mylumi["znunu200p2"]    = 121858.;
  mylumi["znunu400"]      = 190923.;
  
  // W+Jets S10
  mydataset["wjets1"]     = fileDirectory + "MC_S10_V6D_WJetsToLNu_PtW-100_part1_55668pb.root";
  mydataset["wjets2"]     = fileDirectory + "MC_S10_V6D_WJetsToLNu_PtW-100_part2_55668pb.root";
  mydataset["wjets3"]     = fileDirectory + "MC_S10_V6D_WJetsToLNu_PtW-100_part3_55668pb.root";
  mydataset["wjets4"]     = fileDirectory + "MC_S10_V6D_WJetsToLNu_PtW-100_part4_55668pb.root";
  mydataset["wjets5"]     = fileDirectory + "MC_S10_V6D_WJetsToLNu_PtW-100_part5_55668pb.root";
  mydataset["w4jets"]     = fileDirectory + "MC_S10_V6D_W4JetsToLNu_50692pb.root";
  mylumi["wjets1"]        = 55668.;
  mylumi["wjets2"]        = 55668.;
  mylumi["wjets3"]        = 55668.;
  mylumi["wjets4"]        = 55668.; 
  mylumi["wjets5"]        = 55668.;
  mylumi["w4jets"]        = 50692.;
  
  // Z+Jets S10
  mydataset["zjets"]      = fileDirectory + "MC_S10_V6D_DYJetsToLL_PtZ-100_65732pb.root";
  mylumi["zjets"]         = 65732.; //NLO
  mydataset["zmumujets"]  = fileDirectory + "MC_S10_V6D_DYJetsToLL_PtZ-100_Zmumu_NoTrig_65732pb.root";
  mylumi["zmumujets"]     = 65732.; //NLO
  
  // TTbar S10 (NNLO)
  mydataset["ttbar"]      = fileDirectory + "MC_S10_V6D_TTbar_MassiveBin_29332pb.root";
  mylumi["ttbar"]         = 29332./0.97;
  
  // QCD S10 (use scale factor 1.6 from Robyn study)
  mydataset["qcd80"]      = fileDirectory + "MC_S10_V6D_QCD_Pt-0080to0120_6p60pb.root";
  mydataset["qcd120"]     = fileDirectory + "MC_S10_V6D_QCD_Pt-0120to0170_44pb.root";
  mydataset["qcd170"]     = fileDirectory + "MC_S10_V6D_QCD_Pt-0170to0300_179pb.root"; 
  mydataset["qcd300"]     = fileDirectory + "MC_S10_V6D_QCD_Pt-0300to0470_3398pb.root"; 
  mydataset["qcd470"]     = fileDirectory + "MC_S10_V6D_QCD_Pt-0470to0600_35080pb.root"; 
  mydataset["qcd600"]     = fileDirectory + "MC_S10_V6D_QCD_Pt-0600to0800_148075pb.root";
  mydataset["qcd800"]     = fileDirectory + "MC_S10_V6D_QCD_Pt-0800to1000_1126344pb.root"; 
  mydataset["qcd1000"]    = fileDirectory + "MC_S10_V6D_QCD_Pt-1000to1400_2661929pb.root";
  mydataset["qcd1400"]    = fileDirectory + "MC_S10_V6D_QCD_Pt-1400to1800_59066921pb.root";
  mydataset["qcd1800"]    = fileDirectory + "MC_S10_V6D_QCD_Pt-1800_534490611pb.root";
  mylumi["qcd80"]         = 6.60/1.6;
  mylumi["qcd120"]        = 44./1.6;
  mylumi["qcd170"]        = 179./1.6;
  mylumi["qcd300"]        = 3398./1.6;
  mylumi["qcd470"]        = 35080./1.6;
  mylumi["qcd600"]        = 148075./1.6;
  mylumi["qcd800"]        = 1126344./1.6;
  mylumi["qcd1000"]       = 2661929./1.6;
  mylumi["qcd1400"]       = 59066921./1.6;
  mylumi["qcd1800"]       = 534490611./1.6;
  
  // Single-t S10 (NLO - No factor need)
  mydataset["sints"]      = fileDirectory + "MC_S10_V6D_SingleT_s_68591pb.root";
  mydataset["sintt"]      = fileDirectory + "MC_S10_V6D_SingleT_t_66635pb.root";
  mydataset["sinttw"]     = fileDirectory + "MC_S10_V6D_SingleT_tw_44834pb.root";
  mydataset["sintbars"]   = fileDirectory + "MC_S10_V6D_SingleTbar_s_79531pb.root";
  mydataset["sintbart"]   = fileDirectory + "MC_S10_V6D_SingleTbar_t_62380pb.root";
  mydataset["sintbartw"]  = fileDirectory + "MC_S10_V6D_SingleTbar_tw_44456pb.root";
  mylumi["sints"]         = 68591.;
  mylumi["sintt"]         = 66635.;
  mylumi["sinttw"]        = 44834.;
  mylumi["sintbars"]      = 79531.;
  mylumi["sintbart"]      = 62380.; 
  mylumi["sintbartw"]     = 44456.;
  
  // Diboson (NLO - No factor need)
  mydataset["dibosonWW"]  = fileDirectory + "MC_S10_V6D_DiBoson_WW_182363pb.root";
  mydataset["dibosonWZ"]  = fileDirectory + "MC_S10_V6D_DiBoson_WZ_301123pb.root";
  mydataset["dibosonZZ"]  = fileDirectory + "MC_S10_V6D_DiBoson_ZZ_555110pb.root";
  mydataset["dibosonWG"]  = fileDirectory + "MC_S10_V6D_DiBoson_WGToLNuG_10404pb.root";
  mydataset["dibosonZG"]  = fileDirectory + "MC_S10_V6D_DiBoson_ZGInclusive_40471pb.root";
  mydataset["dibosonZLLG"]= fileDirectory + "MC_S10_V6D_DiBoson_ZGToLLG_42178pb.root";
  mydataset["dibosonZvvG"]= fileDirectory + "MC_S10_V6D_DiBoson_ZGTovvG_1460804evt.root";
  mylumi["dibosonWW"]     = 182363.;
  mylumi["dibosonWZ"]     = 301123.;
  mylumi["dibosonZZ"]     = 555110.;
  mylumi["dibosonWG"]     = 10404.;
  mylumi["dibosonZG"]     = 40471.;
  mylumi["dibosonZLLG"]   = 42178.;
  mylumi["dibosonZvvG"]   = 1460804/176.;

  /*
  // VBF-Invisible Higgs
  //mydataset["vbf"]    = "file:/data0/srimanob/Data/monojet/ntuple-2012-v2/VBF_InvisibleHiggs.root";
  //mylumi["vbf"]  = 12100.;
  
  // DM-Stop
  mydataset["dmstop"]     = fileDirectory + "Signal_Stop/Signal_S10_V6B_Stop_72096pb.root";
  mylumi["dmstop"]        = 72096.;
  
  // DM-Higgs
  mydataset["dmhigggf"]   = fileDirectory + "Signal_HiggsPortal/Signal_S10_V6B_HiggsPortal_58448pb.root";
  mylumi["dmhigggf"]      = 58448.;
  
  // Unparticles
  mydataset["unp_S0_dU1p5_LU6000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p5_LU6000_8045pb.root";
  mydataset["unp_S0_dU1p5_LU7000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p5_LU7000_9433pb.root";
  mydataset["unp_S0_dU1p5_LU8000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p5_LU8000_10902pb.root";
  mydataset["unp_S0_dU1p5_LU9000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p5_LU9000_12176pb.root";
  mydataset["unp_S0_dU1p6_LU4000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p6_LU4000_15913pb.root";
  mydataset["unp_S0_dU1p6_LU5000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p6_LU5000_21272pb.root";
  mydataset["unp_S0_dU1p6_LU6000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p6_LU6000_27159pb.root";
  mydataset["unp_S0_dU1p6_LU7000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p6_LU7000_33367pb.root";
  mydataset["unp_S0_dU1p7_LU1000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p7_LU1000_2784pb.root";
  mydataset["unp_S0_dU1p7_LU2000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p7_LU2000_13802pb.root";
  mydataset["unp_S0_dU1p7_LU3000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p7_LU3000_29718pb.root"; 
  mydataset["unp_S0_dU1p8_LU1000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p8_LU1000_6139pb.root";
  mydataset["unp_S0_dU1p8_LU2000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p8_LU2000_35561pb.root";
  mydataset["unp_S0_dU1p8_LU3000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p8_LU3000_86132pb.root"; 
  mydataset["unp_S0_dU1p9_LU1000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p9_LU1000_13526pb.root";
  mydataset["unp_S0_dU1p9_LU2000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p9_LU2000_95602pb.root";
  mydataset["unp_S0_dU1p9_LU3000"]   = fileDirectory + "Signal_UNP/Signal_S10_V6A_UNP_dU1p9_LU3000_244798pb.root";
  mylumi["unp_S0_dU1p5_LU6000"]      = 8045.;
  mylumi["unp_S0_dU1p5_LU7000"]      = 9433.;
  mylumi["unp_S0_dU1p5_LU8000"]      = 10902.;
  mylumi["unp_S0_dU1p5_LU9000"]      = 12176.;
  mylumi["unp_S0_dU1p6_LU4000"]      = 15913.;
  mylumi["unp_S0_dU1p6_LU5000"]      = 21272.;
  mylumi["unp_S0_dU1p6_LU6000"]      = 27159.;
  mylumi["unp_S0_dU1p6_LU7000"]      = 33367.;
  mylumi["unp_S0_dU1p7_LU1000"]      = 2784.;
  mylumi["unp_S0_dU1p7_LU2000"]      = 13802.;
  mylumi["unp_S0_dU1p7_LU3000"]      = 29718.;
  mylumi["unp_S0_dU1p8_LU1000"]      = 6139.;
  mylumi["unp_S0_dU1p8_LU2000"]      = 35561.;
  mylumi["unp_S0_dU1p8_LU3000"]      = 86132.;
  mylumi["unp_S0_dU1p9_LU1000"]      = 13526.;
  mylumi["unp_S0_dU1p9_LU2000"]      = 95602.;
  mylumi["unp_S0_dU1p9_LU3000"]      = 244798.; 
  
  // ADD
  mydataset["d2md3"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D2_MD3000_13065pb.root";
  mydataset["d2md4"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D2_MD4000_40866pb.root";
  mydataset["d2md5"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D2_MD5000_101419pb.root";
  mydataset["d2md6"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D2_MD6000_206611pb.root";
  mydataset["d3md2"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D3_MD2000_5219pb.root";
  mydataset["d3md3"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D3_MD3000_37807pb.root";
  mydataset["d3md4"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D3_MD4000_159438pb.root";
  mydataset["d3md5"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D3_MD5000_465116pb.root"; 
  mydataset["d4md2"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D4_MD2000_8045pb.root";
  mydataset["d4md3"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D4_MD3000_77101pb.root"; 
  mydataset["d4md4"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D4_MD4000_408163pb.root";
  mydataset["d4md5"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D4_MD5000_1612903pb.root";
  mydataset["d5md1"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D5_MD1000_298pb.root";
  mydataset["d5md2"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D5_MD2000_11222pb.root";
  mydataset["d5md3"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D5_MD3000_134048pb.root";
  mydataset["d5md4"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D5_MD4000_937207pb.root";
  mydataset["d6md1"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D6_MD1000_283pb.root";
  mydataset["d6md2"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D6_MD2000_12692pb.root"; 
  mydataset["d6md3"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D6_MD3000_190476pb.root";
  mydataset["d6md4"]    = fileDirectory + "Signal_ADD/Signal_S10_V6A_ADD_D6_MD4000_1724137pb.root"; 
  mylumi["d2md3"]       = 13065.;
  mylumi["d2md4"]       = 40866.;
  mylumi["d2md5"]       = 101419.;
  mylumi["d2md6"]       = 206611.;
  mylumi["d3md2"]       = 5219.;
  mylumi["d3md3"]       = 37807.;
  mylumi["d3md4"]       = 159438.;
  mylumi["d3md5"]       = 465116.; 
  mylumi["d4md2"]       = 8045.;
  mylumi["d4md3"]       = 77101.; 
  mylumi["d4md4"]       = 408163.;
  mylumi["d4md5"]       = 1612903.;
  mylumi["d5md1"]       = 298.;
  mylumi["d5md2"]       = 11222.;
  mylumi["d5md3"]       = 134048.;
  mylumi["d5md4"]       = 937207.;
  mylumi["d6md1"]       = 283.;
  mylumi["d6md2"]       = 12692.; 
  mylumi["d6md3"]       = 190476.;
  mylumi["d6md4"]       = 1724137.;
  
  //Dark Matter
  mydataset["dmav01"]    = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_AV_0p1.root";
  mydataset["dmav1"]     = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_AV_1.root";
  mydataset["dmav10"]    = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_AV_10.root";
  mydataset["dmav100"]   = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_AV_100.root";
  mydataset["dmav200"]   = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_AV_200.root";
  mydataset["dmav300"]   = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_AV_300.root";
  mydataset["dmav400"]   = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_AV_400.root";
  mydataset["dmav700"]   = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_AV_700.root";
  mydataset["dmav1000"]  = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_AV_1000.root";
  mydataset["dmv01"]     = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_V_0p1.root";
  mydataset["dmv1"]      = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_V_1.root";
  mydataset["dmv10"]     = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_V_10.root";
  mydataset["dmv100"]    = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_V_100.root";
  mydataset["dmv200"]    = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_V_200.root";
  mydataset["dmv300"]    = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_V_300.root";
  mydataset["dmv400"]    = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_V_400.root";
  mydataset["dmv700"]    = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_V_700.root";
  mydataset["dmv1000"]   = fileDirectory + "Signal_DM/Signal_S10_V6A_DM_40TeV_V_1000.root";
  mylumi["dmav01"]       = 19712.;  
  mylumi["dmav1"]        = 19712.; 
  mylumi["dmav10"]       = 19712.;
  mylumi["dmav100"]      = 19712.;
  mylumi["dmav200"]      = 19712.;
  mylumi["dmav300"]      = 19712.;
  mylumi["dmav400"]      = 19712.;
  mylumi["dmav700"]      = 19712.;
  mylumi["dmav1000"]     = 19712.;
  mylumi["dmv01"]        = 19712.;
  mylumi["dmv1"]         = 19712.;
  mylumi["dmv10"]        = 19712.;
  mylumi["dmv100"]       = 19712.;
  mylumi["dmv200"]       = 19712.;
  mylumi["dmv300"]       = 19712.;
  mylumi["dmv400"]       = 19712.;
  mylumi["dmv700"]       = 19712.;
  mylumi["dmv1000"]      = 19712.;
  */
  mydataset["dmav100old"]       = "file:/afs/cern.ch/work/s/srimanob/Monojet/Matching/CMSSW_5_3_22_patch1/src/ntuple/Signal_S10_DMAV100_oldNoMatching.root"; 
  mydataset["dmav100new"]       = "file:/afs/cern.ch/work/s/srimanob/Monojet/Matching/CMSSW_5_3_22_patch1/src/ntuple/Signal_S10_DMAV100_newMatching.root"; 
  mydataset["dmav100newJet1"]   = "file:/afs/cern.ch/work/s/srimanob/Monojet/Matching/CMSSW_5_3_22_patch1/src/ntuple/Signal_S10_DMAV100_newMatchingJet1.root";
  mylumi["dmav100old"]          = 19712.;  
  mylumi["dmav100new"]          = 19712.;
  mylumi["dmav100newJet1"]      = 19712.;  
  
  /*TFile f1( mydataset["pileup"].c_str()  );
  TH1D *his = (TH1D*) f1.Get("pileup")->Clone();

  std::string myFileName = mydataset[fileName].c_str();
  int puVersion;
  if(myFileName.find("_S10_") != std::string::npos){
    if(misMC == 0){
      cout<<"*** Reset to be MC sample ***"<<endl;
      misMC = 1;
    }
    puVersion = 10;
  }
  else if(myFileName.find("_S7_") != std::string::npos){
    if(misMC == 0){
      cout<<"*** Reset to be MC sample ***"<<endl;
      misMC = 1;
    }
    puVersion = 7;
  }
  else{
    if(misMC == 1){
      cout<<"*** Reset to be DATA sample ***"<<endl;
      misMC = 0;
    }
    puVersion = 0;
  }
  mPileUpWeights = generate_flat10_weights(his,puVersion);*/
  
  //setPDFPath("/uscmst1/prod/sw/cms/slc5_amd64_gcc434/external/lhapdf/5.6.0-cms4/share/lhapdf/PDFsets");
  //initPDFSet(1, "cteq66.LHgrid");
  //initPDFSet(2, "cteq66alphas.LHgrid"); //  alphaS uncert +/-
  
  //initPDFSet(3, "MSTW2008nlo68cl.LHgrid");
  //initPDFSet(2, "MSTW2008nlo68cl_asmz-68cl.LHgrid"); // alphaS uncert +
  //initPDFSet(3, "MSTW2008nlo68cl_asmz+68cl.LHgrid");  // alphaS uncert -
  
  //initPDFSet(1, "NNPDF20_100.LHgrid");
  //initPDFSet(2, "NNPDF20_100.LHgrid");
  //initPDFSet(3, "NNPDF20_100.LHgrid");
  
  ///-------------Ntuple Variables --------------------------------------------------------------------------
  TFile* file = TFile::Open( mydataset[fileName].c_str() );
  TDirectory* myDir = (TDirectory*)file->Get("NtupleAnalyzer");
  mDataTree = (TTree*) myDir->Get("ntuple");
  
  //PDFWeight
  mDataTree->SetBranchAddress("PDFWeights1", &mPDFWeights);
  
  //Event information
  mDataTree->SetBranchAddress("run"                                   ,&mrun                        );
  mDataTree->SetBranchAddress("event"                                 ,&mevent                      );
  mDataTree->SetBranchAddress("lumi"                                  ,&mlumi                       );
  mDataTree->SetBranchAddress("bx"                                    ,&mbx                         );
  mDataTree->SetBranchAddress("npvm1"                                 ,&mnpvm1                      );
  mDataTree->SetBranchAddress("npv0"                                  ,&mnpv0                       );
  mDataTree->SetBranchAddress("npvp1"                                 ,&mnpvp1                      );
  mDataTree->SetBranchAddress("ptHat"                                 ,&mptHat                      );
  mDataTree->SetBranchAddress("fastJetRho"                            ,&mfastJetRho                 );  
  
  //NoiseFlag
  mDataTree->SetBranchAddress("NoiseFlag"                             ,mNoiseFlag                   );
  
  //CaloTower
  mDataTree->SetBranchAddress("CaloTowerdEx"                          ,&mCaloTowerdEx               );
  mDataTree->SetBranchAddress("CaloTowerdEy"                          ,&mCaloTowerdEy               );
  
  //AK4CaloJets
  mDataTree->SetBranchAddress("NCaloAK4Jets"                          ,&mNCaloAK4Jets               );
  mDataTree->SetBranchAddress("CaloAK4JetE"                           ,mCaloAK4JetE                 );
  mDataTree->SetBranchAddress("CaloAK4JetPt"                          ,mCaloAK4JetPt                );
  mDataTree->SetBranchAddress("CaloAK4JetPx"                          ,mCaloAK4JetPx                );
  mDataTree->SetBranchAddress("CaloAK4JetPy"                          ,mCaloAK4JetPy                );
  mDataTree->SetBranchAddress("CaloAK4JetPz"                          ,mCaloAK4JetPz                );
  mDataTree->SetBranchAddress("CaloAK4JetEta"                         ,mCaloAK4JetEta               );
  mDataTree->SetBranchAddress("CaloAK4JetPhi"                         ,mCaloAK4JetPhi               );
  mDataTree->SetBranchAddress("CaloAK4JetEmf"                         ,mCaloAK4JetEmf               );
  mDataTree->SetBranchAddress("CaloAK4JetfHPD"                        ,mCaloAK4JetfHPD              );
  mDataTree->SetBranchAddress("CaloAK4JetfRBX"                        ,mCaloAK4JetfRBX              );
  mDataTree->SetBranchAddress("CaloAK4JetN90Hits"                     ,mCaloAK4JetN90Hits           );
  mDataTree->SetBranchAddress("CaloAK4JetN90"                         ,mCaloAK4JetN90               );
  mDataTree->SetBranchAddress("CaloAK4JetSigEta"                      ,mCaloAK4JetSigEta            );
  mDataTree->SetBranchAddress("CaloAK4JetSigPhi"                      ,mCaloAK4JetSigPhi            );
  mDataTree->SetBranchAddress("CaloAK4JetIDEmf"                       ,mCaloAK4JetIDEmf             );
  mDataTree->SetBranchAddress("CaloAK4JetECor"                        ,mCaloAK4JetECor              );
  mDataTree->SetBranchAddress("CaloAK4JetPtCor"                       ,mCaloAK4JetPtCor             );
  mDataTree->SetBranchAddress("CaloAK4JetPxCor"                       ,mCaloAK4JetPxCor             );
  mDataTree->SetBranchAddress("CaloAK4JetPyCor"                       ,mCaloAK4JetPyCor             );
  mDataTree->SetBranchAddress("CaloAK4JetPzCor"                       ,mCaloAK4JetPzCor             );
  mDataTree->SetBranchAddress("CaloAK4JetBtagTkCountHighEff"          ,mCaloAK4JetBtagTkCountHighEff);
  mDataTree->SetBranchAddress("CaloAK4JetBTagSimpleSecVtx"            ,mCaloAK4JetBTagSimpleSecVtx  );
  mDataTree->SetBranchAddress("CaloAK4JetBTagCombSecVtx"              ,mCaloAK4JetBTagCombSecVtx    );
  mDataTree->SetBranchAddress("CaloAK4TrackPt"                        ,mCaloAK4TrackPt              );
  mDataTree->SetBranchAddress("CaloAK4JetIDLOOSE"                     ,mCaloAK4JetIDLOOSE           );
  mDataTree->SetBranchAddress("CaloAK4JetIDTIGHT"                     ,mCaloAK4JetIDTIGHT           );
  
  //AK4PFJets
  mDataTree->SetBranchAddress("NPFAK4Jets"                            ,&mNPFAK4Jets                ); 
  mDataTree->SetBranchAddress("PFAK4JetE"                             ,mPFAK4JetE                  ); 
  mDataTree->SetBranchAddress("PFAK4JetPt"                            ,mPFAK4JetPt                 ); 
  mDataTree->SetBranchAddress("PFAK4JetPx"                            ,mPFAK4JetPx                 ); 
  mDataTree->SetBranchAddress("PFAK4JetPy"                            ,mPFAK4JetPy                 ); 
  mDataTree->SetBranchAddress("PFAK4JetPz"                            ,mPFAK4JetPz                 ); 
  mDataTree->SetBranchAddress("PFAK4JetEta"                           ,mPFAK4JetEta                ); 
  mDataTree->SetBranchAddress("PFAK4JetPhi"                           ,mPFAK4JetPhi                ); 
  mDataTree->SetBranchAddress("PFAK4JetfHPD"                          ,mPFAK4JetfHPD               ); 
  mDataTree->SetBranchAddress("PFAK4JetfRBX"                          ,mPFAK4JetfRBX               ); 
  mDataTree->SetBranchAddress("PFAK4JetN90Hits"                       ,mPFAK4JetN90Hits            ); 
  mDataTree->SetBranchAddress("PFAK4JetN90"                           ,mPFAK4JetN90                ); 
  mDataTree->SetBranchAddress("PFAK4JetSigEta"                        ,mPFAK4JetSigEta             ); 
  mDataTree->SetBranchAddress("PFAK4JetSigPhi"                        ,mPFAK4JetSigPhi             ); 
  mDataTree->SetBranchAddress("PFAK4JetIDEmf"                         ,mPFAK4JetIDEmf              ); 
  mDataTree->SetBranchAddress("PFAK4JetECor"                          ,mPFAK4JetECor               ); 
  mDataTree->SetBranchAddress("PFAK4JetPtCor"                         ,mPFAK4JetPtCor              ); 
  mDataTree->SetBranchAddress("PFAK4JetPxCor"                         ,mPFAK4JetPxCor              ); 
  mDataTree->SetBranchAddress("PFAK4JetPyCor"                         ,mPFAK4JetPyCor              ); 
  mDataTree->SetBranchAddress("PFAK4JetPzCor"                         ,mPFAK4JetPzCor              ); 
  mDataTree->SetBranchAddress("PFAK4JetBtagTkCountHighEff"            ,mPFAK4JetBtagTkCountHighEff ); 
  mDataTree->SetBranchAddress("PFAK4JetBTagSimpleSecVtx"              ,mPFAK4JetBTagSimpleSecVtx   ); 
  mDataTree->SetBranchAddress("PFAK4JetBTagCombSecVtx"                ,mPFAK4JetBTagCombSecVtx     ); 
  mDataTree->SetBranchAddress("PFAK4JetNeuEmEngFrac"                  ,mPFAK4JetNeuEmEngFrac       ); 
  mDataTree->SetBranchAddress("PFAK4JetChaEmEngFrac"                  ,mPFAK4JetChaEmEngFrac       ); 
  mDataTree->SetBranchAddress("PFAK4JetChaHadEngFrac"                 ,mPFAK4JetChaHadEngFrac      ); 
  mDataTree->SetBranchAddress("PFAK4JetNeuHadEngFrac"                 ,mPFAK4JetNeuHadEngFrac      ); 
  mDataTree->SetBranchAddress("PFAK4JetChaMuEng"                      ,mPFAK4JetChaMuEng           ); 
  mDataTree->SetBranchAddress("PFAK4JetMuonEng"                       ,mPFAK4JetMuonEng            ); 
  mDataTree->SetBranchAddress("PFAK4JetPhotEng"                       ,mPFAK4JetPhotEng            ); 
  mDataTree->SetBranchAddress("PFAK4JetElecEng"                       ,mPFAK4JetElecEng            ); 
  mDataTree->SetBranchAddress("PFAK4JetNumOfChaMu"                    ,mPFAK4JetNumOfChaMu         ); 
  mDataTree->SetBranchAddress("PFAK4JetNumOfMuon"                     ,mPFAK4JetNumOfMuon          ); 
  mDataTree->SetBranchAddress("PFAK4JetNumOfPhot"                     ,mPFAK4JetNumOfPhot          ); 
  mDataTree->SetBranchAddress("PFAK4JetNumOfElec"                     ,mPFAK4JetNumOfElec          ); 
  mDataTree->SetBranchAddress("PFAK4JetNumOfNeu"                      ,mPFAK4JetNumOfNeu           ); 
  mDataTree->SetBranchAddress("PFAK4JetNumOfCha"                      ,mPFAK4JetNumOfCha           ); 
  mDataTree->SetBranchAddress("PFAK4JetNumOfNeuHad"                   ,mPFAK4JetNumOfNeuHad        ); 
  mDataTree->SetBranchAddress("PFAK4JetNumOfChaHad"                   ,mPFAK4JetNumOfChaHad        ); 
  mDataTree->SetBranchAddress("PFAK4JetNumOfDaughters"                ,mPFAK4JetNumOfDaughters     ); 
  mDataTree->SetBranchAddress("PFAK4JetIDLOOSE"                       ,mPFAK4JetIDLOOSE            ); 
  mDataTree->SetBranchAddress("PFAK4JetIDTIGHT"                       ,mPFAK4JetIDTIGHT            ); 
  mDataTree->SetBranchAddress("PFAK4JetPUFullJetId"                   ,mPFAK4JetPUFullJetId        );
  mDataTree->SetBranchAddress("PFAK4uncer"                            ,mPFAK4uncer                 );
  
  //MET
  mDataTree->SetBranchAddress("NMet"                                  ,&mNMet                      ); 
  mDataTree->SetBranchAddress("MetPt"                                 ,mMetPt                      ); 
  mDataTree->SetBranchAddress("MetPx"                                 ,mMetPx                      ); 
  mDataTree->SetBranchAddress("MetPy"                                 ,mMetPy                      ); 
  mDataTree->SetBranchAddress("MetPhi"                                ,mMetPhi                     ); 
  mDataTree->SetBranchAddress("MetSumEt"                              ,mMetSumEt                   ); 
  mDataTree->SetBranchAddress("MetSign"                               ,mMetSign                    ); 
  
  //Muons
  mDataTree->SetBranchAddress("NMuon"                                 ,&mNMuon                     ); 
  mDataTree->SetBranchAddress("MuonPt"                                ,mMuonPt                     ); 
  mDataTree->SetBranchAddress("MuonEt"                                ,mMuonEt                     ); 
  mDataTree->SetBranchAddress("MuonE"                                 ,mMuonE                      ); 
  mDataTree->SetBranchAddress("MuonPx"                                ,mMuonPx                     ); 
  mDataTree->SetBranchAddress("MuonPy"                                ,mMuonPy                     ); 
  mDataTree->SetBranchAddress("MuonPz"                                ,mMuonPz                     ); 
  mDataTree->SetBranchAddress("MuonEta"                               ,mMuonEta                    ); 
  mDataTree->SetBranchAddress("MuonPhi"                               ,mMuonPhi                    ); 
  mDataTree->SetBranchAddress("MuonCharge"                            ,mMuonCharge                 ); 
  mDataTree->SetBranchAddress("MuonIsGlobal"                          ,mMuonIsGlobal               ); 
  mDataTree->SetBranchAddress("MuonIsStandAlone"                      ,mMuonIsStandAlone           ); 
  mDataTree->SetBranchAddress("MuonIsTracker"                         ,mMuonIsTracker              ); 
  mDataTree->SetBranchAddress("MuonSumPtDR03"                         ,mMuonSumPtDR03              ); 
  mDataTree->SetBranchAddress("MuonSumPtDR05"                         ,mMuonSumPtDR05              ); 
  mDataTree->SetBranchAddress("MuonEmEtDR03"                          ,mMuonEmEtDR03               ); 
  mDataTree->SetBranchAddress("MuonHadEtDR03"                         ,mMuonHadEtDR03              ); 
  mDataTree->SetBranchAddress("MuonNumOfMatches"                      ,mMuonNumOfMatches           ); 
  mDataTree->SetBranchAddress("MuonCombChi2Norm"                      ,mMuonCombChi2Norm           ); 
  mDataTree->SetBranchAddress("MuonCombValidHits"                     ,mMuonCombValidHits          ); 
  mDataTree->SetBranchAddress("MuonCombLostHits"                      ,mMuonCombLostHits           ); 
  mDataTree->SetBranchAddress("MuonCombPt"                            ,mMuonCombPt                 ); 
  mDataTree->SetBranchAddress("MuonCombPz"                            ,mMuonCombPz                 ); 
  mDataTree->SetBranchAddress("MuonCombP"                             ,mMuonCombP                  ); 
  mDataTree->SetBranchAddress("MuonCombEta"                           ,mMuonCombEta                ); 
  mDataTree->SetBranchAddress("MuonCombPhi"                           ,mMuonCombPhi                ); 
  mDataTree->SetBranchAddress("MuonCombChi2"                          ,mMuonCombChi2               ); 
  mDataTree->SetBranchAddress("MuonCombCharge"                        ,mMuonCombCharge             ); 
  mDataTree->SetBranchAddress("MuonCombQOverPError"                   ,mMuonCombQOverPError        ); 
  mDataTree->SetBranchAddress("MuonCombNdof"                          ,mMuonCombNdof               ); 
  mDataTree->SetBranchAddress("MuonCombVx"                            ,mMuonCombVx                 ); 
  mDataTree->SetBranchAddress("MuonCombVy"                            ,mMuonCombVy                 ); 
  mDataTree->SetBranchAddress("MuonCombVz"                            ,mMuonCombVz                 ); 
  mDataTree->SetBranchAddress("MuonCombD0"                            ,mMuonCombD0                 ); 
  mDataTree->SetBranchAddress("MuonCombDz"                            ,mMuonCombDz                 ); 
  mDataTree->SetBranchAddress("MuonStandChi2Norm"                     ,mMuonStandChi2Norm          ); 
  mDataTree->SetBranchAddress("MuonStandValidHits"                    ,mMuonStandValidHits         ); 
  mDataTree->SetBranchAddress("MuonStandLostHits"                     ,mMuonStandLostHits          ); 
  mDataTree->SetBranchAddress("MuonStandPt"                           ,mMuonStandPt                ); 
  mDataTree->SetBranchAddress("MuonStandPz"                           ,mMuonStandPz                ); 
  mDataTree->SetBranchAddress("MuonStandP"                            ,mMuonStandP                 ); 
  mDataTree->SetBranchAddress("MuonStandEta"                          ,mMuonStandEta               ); 
  mDataTree->SetBranchAddress("MuonStandPhi"                          ,mMuonStandPhi               ); 
  mDataTree->SetBranchAddress("MuonStandChi2"                         ,mMuonStandChi2              ); 
  mDataTree->SetBranchAddress("MuonStandCharge"                       ,mMuonStandCharge            ); 
  mDataTree->SetBranchAddress("MuonStandQOverPError"                  ,mMuonStandQOverPError       ); 
  mDataTree->SetBranchAddress("MuonTrkChi2Norm"                       ,mMuonTrkChi2Norm            ); 
  mDataTree->SetBranchAddress("MuonTrkValidHits"                      ,mMuonTrkValidHits           ); 
  mDataTree->SetBranchAddress("MuonTrkLostHits"                       ,mMuonTrkLostHits            ); 
  mDataTree->SetBranchAddress("MuonTrkPt"                             ,mMuonTrkPt                  ); 
  mDataTree->SetBranchAddress("MuonTrkPz"                             ,mMuonTrkPz                  ); 
  mDataTree->SetBranchAddress("MuonTrkP"                              ,mMuonTrkP                   ); 
  mDataTree->SetBranchAddress("MuonTrkEta"                            ,mMuonTrkEta                 ); 
  mDataTree->SetBranchAddress("MuonTrkPhi"                            ,mMuonTrkPhi                 ); 
  mDataTree->SetBranchAddress("MuonTrkChi2"                           ,mMuonTrkChi2                ); 
  mDataTree->SetBranchAddress("MuonTrkCharge"                         ,mMuonTrkCharge              ); 
  mDataTree->SetBranchAddress("MuonTrkQOverPError"                    ,mMuonTrkQOverPError         ); 
  mDataTree->SetBranchAddress("MuonTrkDxy"                            ,mMuonTrkDxy                 ); 
  mDataTree->SetBranchAddress("MuonTrkNumOfValidPixHits"              ,mMuonTrkNumOfValidPixHits   ); 
  
  //PFMuons
  mDataTree->SetBranchAddress("NPFMuon"                               ,&mNPFMuon                  );  
  mDataTree->SetBranchAddress("PFMuonPt"                              ,mPFMuonPt                  );  
  mDataTree->SetBranchAddress("PFMuonEt"                              ,mPFMuonEt                  );  
  mDataTree->SetBranchAddress("PFMuonE"                               ,mPFMuonE                   );  
  mDataTree->SetBranchAddress("PFMuonPx"                              ,mPFMuonPx                  );  
  mDataTree->SetBranchAddress("PFMuonPy"                              ,mPFMuonPy                  );  
  mDataTree->SetBranchAddress("PFMuonPz"                              ,mPFMuonPz                  );  
  mDataTree->SetBranchAddress("PFMuonEta"                             ,mPFMuonEta                 );  
  mDataTree->SetBranchAddress("PFMuonPhi"                             ,mPFMuonPhi                 );  
  mDataTree->SetBranchAddress("PFMuonCharge"                          ,mPFMuonCharge              );  
  mDataTree->SetBranchAddress("PFMuonIsGlobal"                        ,mPFMuonIsGlobal            );  
  mDataTree->SetBranchAddress("PFMuonIsStandAlone"                    ,mPFMuonIsStandAlone        );  
  mDataTree->SetBranchAddress("PFMuonIsTracker"                       ,mPFMuonIsTracker           );
  mDataTree->SetBranchAddress("PFMuonIsTight"                         ,mPFMuonIsTight             );     
  mDataTree->SetBranchAddress("PFMuonIsLoose"                         ,mPFMuonIsLoose             );
  mDataTree->SetBranchAddress("PFMuonChargedHadronIso"                ,mPFMuonChargedHadronIso    );  
  mDataTree->SetBranchAddress("PFMuonPhotonIso"                       ,mPFMuonPhotonIso           );  
  mDataTree->SetBranchAddress("PFMuonNeutralHadronIso"                ,mPFMuonNeutralHadronIso    );  
  mDataTree->SetBranchAddress("PFMuonisGMPT"                          ,mPFMuonisGMPT              );  
  mDataTree->SetBranchAddress("PFMuonNumOfMatches"                    ,mPFMuonNumOfMatches        );  
  mDataTree->SetBranchAddress("PFMuoninnertrackPt"                    ,mPFMuoninnertrackPt        );  
  mDataTree->SetBranchAddress("PFMuonnValidHits"                      ,mPFMuonnValidHits          );  
  mDataTree->SetBranchAddress("PFMuonnValidPixelHits"                 ,mPFMuonnValidPixelHits     );  
  mDataTree->SetBranchAddress("PFMuondxy"                             ,mPFMuondxy                 );  
  mDataTree->SetBranchAddress("PFMuondz"                              ,mPFMuondz                  );  
  mDataTree->SetBranchAddress("PFMuonCombChi2Norm"                    ,mPFMuonCombChi2Norm        );  
  mDataTree->SetBranchAddress("PFMuonCombValidHits"                   ,mPFMuonCombValidHits       );  
  mDataTree->SetBranchAddress("PFMuonCombLostHits"                    ,mPFMuonCombLostHits        );  
  mDataTree->SetBranchAddress("PFMuonCombPt"                          ,mPFMuonCombPt              );  
  mDataTree->SetBranchAddress("PFMuonCombPz"                          ,mPFMuonCombPz              );  
  mDataTree->SetBranchAddress("PFMuonCombP"                           ,mPFMuonCombP               );  
  mDataTree->SetBranchAddress("PFMuonCombEta"                         ,mPFMuonCombEta             );  
  mDataTree->SetBranchAddress("PFMuonCombPhi"                         ,mPFMuonCombPhi             );  
  mDataTree->SetBranchAddress("PFMuonCombChi2"                        ,mPFMuonCombChi2            );  
  mDataTree->SetBranchAddress("PFMuonCombCharge"                      ,mPFMuonCombCharge          );  
  mDataTree->SetBranchAddress("PFMuonCombQOverPError"                 ,mPFMuonCombQOverPError     );  
  mDataTree->SetBranchAddress("PFMuonCombNdof"                        ,mPFMuonCombNdof            );  
  mDataTree->SetBranchAddress("PFMuonCombVx"                          ,mPFMuonCombVx              );  
  mDataTree->SetBranchAddress("PFMuonCombVy"                          ,mPFMuonCombVy              );  
  mDataTree->SetBranchAddress("PFMuonCombVz"                          ,mPFMuonCombVz              );  
  mDataTree->SetBranchAddress("PFMuonCombD0"                          ,mPFMuonCombD0              );  
  mDataTree->SetBranchAddress("PFMuonCombDz"                          ,mPFMuonCombDz              );  
  mDataTree->SetBranchAddress("PFMuonStandChi2Norm"                   ,mPFMuonStandChi2Norm       );  
  mDataTree->SetBranchAddress("PFMuonStandValidHits"                  ,mPFMuonStandValidHits      );  
  mDataTree->SetBranchAddress("PFMuonStandLostHits"                   ,mPFMuonStandLostHits       );  
  mDataTree->SetBranchAddress("PFMuonStandPt"                         ,mPFMuonStandPt             );  
  mDataTree->SetBranchAddress("PFMuonStandPz"                         ,mPFMuonStandPz             );  
  mDataTree->SetBranchAddress("PFMuonStandP"                          ,mPFMuonStandP              );  
  mDataTree->SetBranchAddress("PFMuonStandEta"                        ,mPFMuonStandEta            );  
  mDataTree->SetBranchAddress("PFMuonStandPhi"                        ,mPFMuonStandPhi            );  
  mDataTree->SetBranchAddress("PFMuonStandChi2"                       ,mPFMuonStandChi2           );  
  mDataTree->SetBranchAddress("PFMuonStandCharge"                     ,mPFMuonStandCharge         );  
  mDataTree->SetBranchAddress("PFMuonStandQOverPError"                ,mPFMuonStandQOverPError    );  
  mDataTree->SetBranchAddress("PFMuonTrkChi2Norm"                     ,mPFMuonTrkChi2Norm         );  
  mDataTree->SetBranchAddress("PFMuonTrkValidHits"                    ,mPFMuonTrkValidHits        );  
  mDataTree->SetBranchAddress("PFMuonTrkLostHits"                     ,mPFMuonTrkLostHits         );  
  mDataTree->SetBranchAddress("PFMuonTrkPt"                           ,mPFMuonTrkPt               );  
  mDataTree->SetBranchAddress("PFMuonTrkPz"                           ,mPFMuonTrkPz               );  
  mDataTree->SetBranchAddress("PFMuonTrkP"                            ,mPFMuonTrkP                );  
  mDataTree->SetBranchAddress("PFMuonTrkEta"                          ,mPFMuonTrkEta              );  
  mDataTree->SetBranchAddress("PFMuonTrkPhi"                          ,mPFMuonTrkPhi              );  
  mDataTree->SetBranchAddress("PFMuonTrkChi2"                         ,mPFMuonTrkChi2             );  
  mDataTree->SetBranchAddress("PFMuonTrkCharge"                       ,mPFMuonTrkCharge           );  
  mDataTree->SetBranchAddress("PFMuonTrkQOverPError"                  ,mPFMuonTrkQOverPError      );  
  mDataTree->SetBranchAddress("PFMuonTrkDxy"                          ,mPFMuonTrkDxy              );  
  mDataTree->SetBranchAddress("PFMuonTrkNumOfValidPixHits"            ,mPFMuonTrkNumOfValidPixHits);
  mDataTree->SetBranchAddress("PFMuonR04ChargedHadronPt"              ,mPFMuonR04ChargedHadronPt  );
  mDataTree->SetBranchAddress("PFMuonR04NeutralHadronEt"              ,mPFMuonR04NeutralHadronEt  );
  mDataTree->SetBranchAddress("PFMuonR04PhotonEt"                     ,mPFMuonR04PhotonEt         );
  mDataTree->SetBranchAddress("PFMuonR04PUPt"                         ,mPFMuonR04PUPt             ); 
  
  //Electrons
  mDataTree->SetBranchAddress("NElec"                                 ,&mNElec                   );   
  mDataTree->SetBranchAddress("ElecE"                                 ,mElecE                    );   
  mDataTree->SetBranchAddress("ElecPt"                                ,mElecPt                   );   
  mDataTree->SetBranchAddress("ElecPx"                                ,mElecPx                   );   
  mDataTree->SetBranchAddress("ElecPy"                                ,mElecPy                   );   
  mDataTree->SetBranchAddress("ElecPz"                                ,mElecPz                   );   
  mDataTree->SetBranchAddress("ElecEcalseed"                          ,mElecEcalseed             );   
  mDataTree->SetBranchAddress("ElecID80"                              ,mElecID80                 );   
  mDataTree->SetBranchAddress("ElecID95"                              ,mElecID95                 );   
  mDataTree->SetBranchAddress("ElecEta"                               ,mElecEta                  );   
  mDataTree->SetBranchAddress("ElecPhi"                               ,mElecPhi                  );   
  mDataTree->SetBranchAddress("ElecCharge"                            ,mElecCharge               );   
  mDataTree->SetBranchAddress("Elecdr03HcalTowerSumEt"                ,mElecdr03HcalTowerSumEt   );   
  mDataTree->SetBranchAddress("Elecdr03EcalRecHitSumEt"               ,mElecdr03EcalRecHitSumEt  );   
  mDataTree->SetBranchAddress("Elecdr03TkSumPt"                       ,mElecdr03TkSumPt          );   
  mDataTree->SetBranchAddress("ElecNumOfValidHits"                    ,mElecNumOfValidHits       );   
  mDataTree->SetBranchAddress("ElecInnerNumOfHits"                    ,mElecInnerNumOfHits       );   
  mDataTree->SetBranchAddress("Elecdist"                              ,mElecdist                 );   
  mDataTree->SetBranchAddress("Elecdcot"                              ,mElecdcot                 );   
  mDataTree->SetBranchAddress("ElecNormChi2"                          ,mElecNormChi2             );   
  mDataTree->SetBranchAddress("Elecdxy"                               ,mElecdxy                  );   
  mDataTree->SetBranchAddress("Elecdz"                                ,mElecdz                   );   
  mDataTree->SetBranchAddress("ElecdB"                                ,mElecdB                   );   
  mDataTree->SetBranchAddress("ElecIsEB"                              ,mElecIsEB                 );   
  mDataTree->SetBranchAddress("Elecfbrem"                             ,mElecfbrem                );   
  mDataTree->SetBranchAddress("ElecDEtaSuTrAtVtx"                     ,mElecDEtaSuTrAtVtx        );   
  mDataTree->SetBranchAddress("ElecDPhiSuTrAtVtx"                     ,mElecDPhiSuTrAtVtx        );   
  mDataTree->SetBranchAddress("ElecHadronicOverEm"                    ,mElecHadronicOverEm       );   
  mDataTree->SetBranchAddress("ElecHcalOverEcal"                      ,mElecHcalOverEcal         );   
  mDataTree->SetBranchAddress("ElecSuperClusOverP"                    ,mElecSuperClusOverP       );   
  mDataTree->SetBranchAddress("Elecetaeta"                            ,mElecetaeta               );   
  mDataTree->SetBranchAddress("Elecietaieta"                          ,mElecietaieta             );
  
  //PFElectrons
  mDataTree->SetBranchAddress("NPFElec"                               ,&mNPFElec                  );  
  mDataTree->SetBranchAddress("PFElecCharge"                          ,mPFElecCharge              );  
  mDataTree->SetBranchAddress("PFElecIsEB"                            ,mPFElecIsEB                );  
  mDataTree->SetBranchAddress("PFElecPassTight"                       ,mPFElecPassTight           );  
  mDataTree->SetBranchAddress("PFElecE"                               ,mPFElecE                   );  
  mDataTree->SetBranchAddress("PFElecPt"                              ,mPFElecPt                  );  
  mDataTree->SetBranchAddress("PFElecPx"                              ,mPFElecPx                  );  
  mDataTree->SetBranchAddress("PFElecPy"                              ,mPFElecPy                  );  
  mDataTree->SetBranchAddress("PFElecPz"                              ,mPFElecPz                  );  
  mDataTree->SetBranchAddress("PFElecEta"                             ,mPFElecEta                 );  
  mDataTree->SetBranchAddress("PFElecPhi"                             ,mPFElecPhi                 );  
  mDataTree->SetBranchAddress("PFElecCharHadIso"                      ,mPFElecCharHadIso          );  
  mDataTree->SetBranchAddress("PFElecPhoIso"                          ,mPFElecPhoIso              );  
  mDataTree->SetBranchAddress("PFElecNeuHadIso"                       ,mPFElecNeuHadIso           );  
  mDataTree->SetBranchAddress("PFElecMva"                             ,mPFElecMva                 );  
  mDataTree->SetBranchAddress("PFElecdxy"                             ,mPFElecdxy                 );  
  mDataTree->SetBranchAddress("PFElecdz"                              ,mPFElecdz                  );  
  mDataTree->SetBranchAddress("PFElecHadOverEm"                       ,mPFElecHadOverEm           );  
  mDataTree->SetBranchAddress("PFElecHcalOverEm"                      ,mPFElecHcalOverEm          );  
  mDataTree->SetBranchAddress("PFElecSupClusOverP"                    ,mPFElecSupClusOverP        );  
  mDataTree->SetBranchAddress("PFElecInnerHits"                       ,mPFElecInnerHits           );  
  mDataTree->SetBranchAddress("PFElecConvDist"                        ,mPFElecConvDist            );  
  mDataTree->SetBranchAddress("PFElecConvDcot"                        ,mPFElecConvDcot            );
  mDataTree->SetBranchAddress("PFElecDEtaSuTrAtVtx"                   ,mPFElecDEtaSuTrAtVtx       );   
  mDataTree->SetBranchAddress("PFElecDPhiSuTrAtVtx"                   ,mPFElecDPhiSuTrAtVtx       );   
  mDataTree->SetBranchAddress("PFElecHadronicOverEm"                  ,mPFElecHadronicOverEm      );   
  mDataTree->SetBranchAddress("PFElecHcalOverEcal"                    ,mPFElecHcalOverEcal        );   
  mDataTree->SetBranchAddress("PFElecetaeta"                          ,mPFElecetaeta              );   
  mDataTree->SetBranchAddress("PFElecietaieta"                        ,mPFElecietaieta            );
  mDataTree->SetBranchAddress("PFElecIsTight"                         ,mPFElecIsTight             );     
  mDataTree->SetBranchAddress("PFElecIsMedium"                        ,mPFElecIsMedium            );
  mDataTree->SetBranchAddress("PFElecIsLoose"                         ,mPFElecIsLoose             );     
  mDataTree->SetBranchAddress("PFElecIsVeto"                          ,mPFElecIsVeto              );
  mDataTree->SetBranchAddress("PFElecEffArea"                         ,mPFElecEffArea             );  

  //Tau
  mDataTree->SetBranchAddress("NTau"                                               ,&mNTau);
  mDataTree->SetBranchAddress("TauE"                                               ,mTauE);
  mDataTree->SetBranchAddress("TauPt"                                              ,mTauPt);
  mDataTree->SetBranchAddress("TauPx"                                              ,mTauPx);
  mDataTree->SetBranchAddress("TauPy"                                              ,mTauPy);
  mDataTree->SetBranchAddress("TauPz"                                              ,mTauPz);
  mDataTree->SetBranchAddress("TauEta"                                             ,mTauEta);
  mDataTree->SetBranchAddress("TauPhi"                                             ,mTauPhi);
  mDataTree->SetBranchAddress("TauCharge"                                          ,mTauCharge);
  mDataTree->SetBranchAddress("TauEtaEtaMoment"                                    ,mTauEtaEtaMoment);
  mDataTree->SetBranchAddress("TauPhiPhiMoment"                                    ,mTauPhiPhiMoment);
  mDataTree->SetBranchAddress("TauEtaPhiMoment"                                    ,mTauEtaPhiMoment);
  mDataTree->SetBranchAddress("TauLeadPFChargedHadrCandsignedSipt"                 ,mTauLeadPFChargedHadrCandsignedSipt);
  mDataTree->SetBranchAddress("TauIsoPFChargedHadrCandsPtSum"                      ,mTauIsoPFChargedHadrCandsPtSum);
  mDataTree->SetBranchAddress("TauIsoPFGammaCandsEtSum"                            ,mTauIsoPFGammaCandsEtSum);
  mDataTree->SetBranchAddress("TauMaximumHCALPFClusterEt"                          ,mTauMaximumHCALPFClusterEt);
  mDataTree->SetBranchAddress("TauEmFraction"                                      ,mTauEmFraction);
  mDataTree->SetBranchAddress("TauHcalTotOverPLead"                                ,mTauHcalTotOverPLead);
  mDataTree->SetBranchAddress("TauHcalMaxOverPLead"                                ,mTauHcalMaxOverPLead);
  mDataTree->SetBranchAddress("TauHcal3x3OverPLead"                                ,mTauHcal3x3OverPLead);
  mDataTree->SetBranchAddress("TauEcalStripSumEOverPLead"                          ,mTauEcalStripSumEOverPLead);
  mDataTree->SetBranchAddress("TauBremsRecoveryEOverPLead"                         ,mTauBremsRecoveryEOverPLead);
  mDataTree->SetBranchAddress("TauElectronPreIDOutput"                             ,mTauElectronPreIDOutput);
  mDataTree->SetBranchAddress("TauElectronPreIDDecision"                           ,mTauElectronPreIDDecision);
  mDataTree->SetBranchAddress("TauCaloComp"                                        ,mTauCaloComp);
  mDataTree->SetBranchAddress("TauSegComp"                                         ,mTauSegComp);
  mDataTree->SetBranchAddress("TauMuonDecision"                                    ,mTauMuonDecision);
  mDataTree->SetBranchAddress("TausignalPFChargedHadrCands"                        ,mTausignalPFChargedHadrCands);
  mDataTree->SetBranchAddress("TausignalPFGammaCands"                              ,mTausignalPFGammaCands);
  mDataTree->SetBranchAddress("TauDisAgainstElectronDeadECAL"                      ,mTauDisAgainstElectronDeadECAL);
  mDataTree->SetBranchAddress("TauDisAgainstElectronLoose"                         ,mTauDisAgainstElectronLoose);
  mDataTree->SetBranchAddress("TauDisAgainstElectronLooseMVA2"                     ,mTauDisAgainstElectronLooseMVA2);
  mDataTree->SetBranchAddress("TauDisAgainstElectronLooseMVA3"                     ,mTauDisAgainstElectronLooseMVA3);
  mDataTree->SetBranchAddress("TauDisAgainstElectronMVA2category"                  ,mTauDisAgainstElectronMVA2category);
  mDataTree->SetBranchAddress("TauDisAgainstElectronMVA2raw"                       ,mTauDisAgainstElectronMVA2raw);
  mDataTree->SetBranchAddress("TauDisAgainstElectronMVA3category"                  ,mTauDisAgainstElectronMVA3category);
  mDataTree->SetBranchAddress("TauDisAgainstElectronMVA3raw"                       ,mTauDisAgainstElectronMVA3raw);
  mDataTree->SetBranchAddress("TauDisAgainstElectronMVA"                           ,mTauDisAgainstElectronMVA);
  mDataTree->SetBranchAddress("TauDisAgainstElectronMedium"                        ,mTauDisAgainstElectronMedium);
  mDataTree->SetBranchAddress("TauDisAgainstElectronMediumMVA2"                    ,mTauDisAgainstElectronMediumMVA2);
  mDataTree->SetBranchAddress("TauDisAgainstElectronMediumMVA3"                    ,mTauDisAgainstElectronMediumMVA3);
  mDataTree->SetBranchAddress("TauDisAgainstElectronTight"                         ,mTauDisAgainstElectronTight);
  mDataTree->SetBranchAddress("TauDisAgainstElectronTightMVA2"                     ,mTauDisAgainstElectronTightMVA2);
  mDataTree->SetBranchAddress("TauDisAgainstElectronTightMVA3"                     ,mTauDisAgainstElectronTightMVA3);
  mDataTree->SetBranchAddress("TauDisAgainstElectronVLooseMVA2"                    ,mTauDisAgainstElectronVLooseMVA2);
  mDataTree->SetBranchAddress("TauDisAgainstElectronVTightMVA3"                    ,mTauDisAgainstElectronVTightMVA3);
  mDataTree->SetBranchAddress("TauDisAgainstMuonLoose2"                            ,mTauDisAgainstMuonLoose2);
  mDataTree->SetBranchAddress("TauDisAgainstMuonLoose"                             ,mTauDisAgainstMuonLoose);
  mDataTree->SetBranchAddress("TauDisAgainstMuonMedium2"                           ,mTauDisAgainstMuonMedium2);
  mDataTree->SetBranchAddress("TauDisAgainstMuonMedium"                            ,mTauDisAgainstMuonMedium);
  mDataTree->SetBranchAddress("TauDisAgainstMuonTight2"                            ,mTauDisAgainstMuonTight2);
  mDataTree->SetBranchAddress("TauDisAgainstMuonTight"                             ,mTauDisAgainstMuonTight);
  mDataTree->SetBranchAddress("TauDisByCombinedIsolationDeltaBetaCorrRaw3Hits"     ,mTauDisByCombinedIsolationDeltaBetaCorrRaw3Hits);
  mDataTree->SetBranchAddress("TauDisByCombinedIsolationDeltaBetaCorrRaw"          ,mTauDisByCombinedIsolationDeltaBetaCorrRaw);
  mDataTree->SetBranchAddress("TauDisByIsolationMVA2raw"                           ,mTauDisByIsolationMVA2raw);
  mDataTree->SetBranchAddress("TauDisByIsolationMVAraw"                            ,mTauDisByIsolationMVAraw);
  mDataTree->SetBranchAddress("TauDisByLooseCombinedIsolationDeltaBetaCorr3Hits"   ,mTauDisByLooseCombinedIsolationDeltaBetaCorr3Hits);
  mDataTree->SetBranchAddress("TauDisByLooseCombinedIsolationDeltaBetaCorr"        ,mTauDisByLooseCombinedIsolationDeltaBetaCorr);
  mDataTree->SetBranchAddress("TauDisByLooseIsolationMVA2"                         ,mTauDisByLooseIsolationMVA2);
  mDataTree->SetBranchAddress("TauDisByLooseIsolationMVA"                          ,mTauDisByLooseIsolationMVA);
  mDataTree->SetBranchAddress("TauDisByMediumCombinedIsolationDeltaBetaCorr3Hits"  ,mTauDisByMediumCombinedIsolationDeltaBetaCorr3Hits);
  mDataTree->SetBranchAddress("TauDisByMediumCombinedIsolationDeltaBetaCorr"       ,mTauDisByMediumCombinedIsolationDeltaBetaCorr);
  mDataTree->SetBranchAddress("TauDisByMediumIsolationMVA2"                        ,mTauDisByMediumIsolationMVA2);
  mDataTree->SetBranchAddress("TauDisByMediumIsolationMVA"                         ,mTauDisByMediumIsolationMVA);
  mDataTree->SetBranchAddress("TauDisByTightCombinedIsolationDeltaBetaCorr3Hits"   ,mTauDisByTightCombinedIsolationDeltaBetaCorr3Hits);
  mDataTree->SetBranchAddress("TauDisByTightCombinedIsolationDeltaBetaCorr"        ,mTauDisByTightCombinedIsolationDeltaBetaCorr);
  mDataTree->SetBranchAddress("TauDisByTightIsolationMVA2"                         ,mTauDisByTightIsolationMVA2);
  mDataTree->SetBranchAddress("TauDisByTightIsolationMVA"                          ,mTauDisByTightIsolationMVA);
  mDataTree->SetBranchAddress("TauDisByVLooseCombinedIsolationDeltaBetaCorr"       ,mTauDisByVLooseCombinedIsolationDeltaBetaCorr);
  mDataTree->SetBranchAddress("TauDisDecayModeFinding"                             ,mTauDisDecayModeFinding);
  mDataTree->SetBranchAddress("TauJetPt"                                           ,mTauJetPt);
  mDataTree->SetBranchAddress("TauJetEta"                                          ,mTauJetEta);
  mDataTree->SetBranchAddress("TauJetPhi"                                          ,mTauJetPhi);

  //PFTau
  mDataTree->SetBranchAddress("NPFTau"                                             ,&mNPFTau);
  mDataTree->SetBranchAddress("PFTauE"                                             ,mPFTauE);
  mDataTree->SetBranchAddress("PFTauPt"                                            ,mPFTauPt);
  mDataTree->SetBranchAddress("PFTauPx"                                            ,mPFTauPx);
  mDataTree->SetBranchAddress("PFTauPy"                                            ,mPFTauPy);
  mDataTree->SetBranchAddress("PFTauPz"                                            ,mPFTauPz);
  mDataTree->SetBranchAddress("PFTauEta"                                           ,mPFTauEta);
  mDataTree->SetBranchAddress("PFTauPhi"                                           ,mPFTauPhi);
  mDataTree->SetBranchAddress("PFTauCharge"                                        ,mPFTauCharge);
  mDataTree->SetBranchAddress("PFTauEtaEtaMoment"                                  ,mPFTauEtaEtaMoment);
  mDataTree->SetBranchAddress("PFTauPhiPhiMoment"                                  ,mPFTauPhiPhiMoment);
  mDataTree->SetBranchAddress("PFTauEtaPhiMoment"                                  ,mPFTauEtaPhiMoment);
  mDataTree->SetBranchAddress("PFTauLeadPFChargedHadrCandsignedSipt"               ,mPFTauLeadPFChargedHadrCandsignedSipt);
  mDataTree->SetBranchAddress("PFTauIsoPFChargedHadrCandsPtSum"                    ,mPFTauIsoPFChargedHadrCandsPtSum);
  mDataTree->SetBranchAddress("PFTauIsoPFGammaCandsEtSum"                          ,mPFTauIsoPFGammaCandsEtSum);
  mDataTree->SetBranchAddress("PFTauMaximumHCALPFClusterEt"                        ,mPFTauMaximumHCALPFClusterEt);
  mDataTree->SetBranchAddress("PFTauEmFraction"                                    ,mPFTauEmFraction);
  mDataTree->SetBranchAddress("PFTauHcalTotOverPLead"                              ,mPFTauHcalTotOverPLead);
  mDataTree->SetBranchAddress("PFTauHcalMaxOverPLead"                              ,mPFTauHcalMaxOverPLead);
  mDataTree->SetBranchAddress("PFTauHcal3x3OverPLead"                              ,mPFTauHcal3x3OverPLead);
  mDataTree->SetBranchAddress("PFTauEcalStripSumEOverPLead"                        ,mPFTauEcalStripSumEOverPLead);
  mDataTree->SetBranchAddress("PFTauBremsRecoveryEOverPLead"                       ,mPFTauBremsRecoveryEOverPLead);
  mDataTree->SetBranchAddress("PFTauElectronPreIDOutput"                           ,mPFTauElectronPreIDOutput);
  mDataTree->SetBranchAddress("PFTauElectronPreIDDecision"                         ,mPFTauElectronPreIDDecision);
  mDataTree->SetBranchAddress("PFTauCaloComp"                                      ,mPFTauCaloComp);
  mDataTree->SetBranchAddress("PFTauSegComp"                                       ,mPFTauSegComp);
  mDataTree->SetBranchAddress("PFTauMuonDecision"                                  ,mPFTauMuonDecision);
  mDataTree->SetBranchAddress("PFTausignalPFChargedHadrCands"                      ,mPFTausignalPFChargedHadrCands);
  mDataTree->SetBranchAddress("PFTausignalPFGammaCands"                            ,mPFTausignalPFGammaCands);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronDeadECAL"                    ,mPFTauDisAgainstElectronDeadECAL);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronLoose"                       ,mPFTauDisAgainstElectronLoose);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronLooseMVA2"                   ,mPFTauDisAgainstElectronLooseMVA2);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronLooseMVA3"                   ,mPFTauDisAgainstElectronLooseMVA3);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronMVA2category"                ,mPFTauDisAgainstElectronMVA2category);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronMVA2raw"                     ,mPFTauDisAgainstElectronMVA2raw);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronMVA3category"                ,mPFTauDisAgainstElectronMVA3category);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronMVA3raw"                     ,mPFTauDisAgainstElectronMVA3raw);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronMVA"                         ,mPFTauDisAgainstElectronMVA);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronMedium"                      ,mPFTauDisAgainstElectronMedium);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronMediumMVA2"                  ,mPFTauDisAgainstElectronMediumMVA2);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronMediumMVA3"                  ,mPFTauDisAgainstElectronMediumMVA3);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronTight"                       ,mPFTauDisAgainstElectronTight);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronTightMVA2"                   ,mPFTauDisAgainstElectronTightMVA2);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronTightMVA3"                   ,mPFTauDisAgainstElectronTightMVA3);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronVLooseMVA2"                  ,mPFTauDisAgainstElectronVLooseMVA2);
  mDataTree->SetBranchAddress("PFTauDisAgainstElectronVTightMVA3"                  ,mPFTauDisAgainstElectronVTightMVA3);
  mDataTree->SetBranchAddress("PFTauDisAgainstMuonLoose2"                          ,mPFTauDisAgainstMuonLoose2);
  mDataTree->SetBranchAddress("PFTauDisAgainstMuonLoose"                           ,mPFTauDisAgainstMuonLoose);
  mDataTree->SetBranchAddress("PFTauDisAgainstMuonMedium2"                         ,mPFTauDisAgainstMuonMedium2);
  mDataTree->SetBranchAddress("PFTauDisAgainstMuonMedium"                          ,mPFTauDisAgainstMuonMedium);
  mDataTree->SetBranchAddress("PFTauDisAgainstMuonTight2"                          ,mPFTauDisAgainstMuonTight2);
  mDataTree->SetBranchAddress("PFTauDisAgainstMuonTight"                           ,mPFTauDisAgainstMuonTight);
  mDataTree->SetBranchAddress("PFTauDisByCombinedIsolationDeltaBetaCorrRaw3Hits"   ,mPFTauDisByCombinedIsolationDeltaBetaCorrRaw3Hits);
  mDataTree->SetBranchAddress("PFTauDisByCombinedIsolationDeltaBetaCorrRaw"        ,mPFTauDisByCombinedIsolationDeltaBetaCorrRaw);
  mDataTree->SetBranchAddress("PFTauDisByIsolationMVA2raw"                         ,mPFTauDisByIsolationMVA2raw);
  mDataTree->SetBranchAddress("PFTauDisByIsolationMVAraw"                          ,mPFTauDisByIsolationMVAraw);
  mDataTree->SetBranchAddress("PFTauDisByLooseCombinedIsolationDeltaBetaCorr3Hits" ,mPFTauDisByLooseCombinedIsolationDeltaBetaCorr3Hits);
  mDataTree->SetBranchAddress("PFTauDisByLooseCombinedIsolationDeltaBetaCorr"      ,mPFTauDisByLooseCombinedIsolationDeltaBetaCorr);
  mDataTree->SetBranchAddress("PFTauDisByLooseIsolationDeltaBetaCorr"              ,mPFTauDisByLooseIsolationDeltaBetaCorr);
  mDataTree->SetBranchAddress("PFTauDisByLooseIsolation"                           ,mPFTauDisByLooseIsolation);
  mDataTree->SetBranchAddress("PFTauDisByLooseIsolationMVA2"                       ,mPFTauDisByLooseIsolationMVA2);
  mDataTree->SetBranchAddress("PFTauDisByLooseIsolationMVA"                        ,mPFTauDisByLooseIsolationMVA);
  mDataTree->SetBranchAddress("PFTauDisByMediumCombinedIsolationDeltaBetaCorr3Hits",mPFTauDisByMediumCombinedIsolationDeltaBetaCorr3Hits);
  mDataTree->SetBranchAddress("PFTauDisByMediumCombinedIsolationDeltaBetaCorr"     ,mPFTauDisByMediumCombinedIsolationDeltaBetaCorr);
  mDataTree->SetBranchAddress("PFTauDisByMediumIsolationDeltaBetaCorr"             ,mPFTauDisByMediumIsolationDeltaBetaCorr);
  mDataTree->SetBranchAddress("PFTauDisByMediumIsolation"                          ,mPFTauDisByMediumIsolation);
  mDataTree->SetBranchAddress("PFTauDisByMediumIsolationMVA2"                      ,mPFTauDisByMediumIsolationMVA2);
  mDataTree->SetBranchAddress("PFTauDisByMediumIsolationMVA"                       ,mPFTauDisByMediumIsolationMVA);
  mDataTree->SetBranchAddress("PFTauDisByTightCombinedIsolationDeltaBetaCorr3Hits" ,mPFTauDisByTightCombinedIsolationDeltaBetaCorr3Hits);
  mDataTree->SetBranchAddress("PFTauDisByTightCombinedIsolationDeltaBetaCorr"      ,mPFTauDisByTightCombinedIsolationDeltaBetaCorr);
  mDataTree->SetBranchAddress("PFTauDisByTightIsolationDeltaBetaCorr"              ,mPFTauDisByTightIsolationDeltaBetaCorr);
  mDataTree->SetBranchAddress("PFTauDisByTightIsolation"                           ,mPFTauDisByTightIsolation);
  mDataTree->SetBranchAddress("PFTauDisByTightIsolationMVA2"                       ,mPFTauDisByTightIsolationMVA2);
  mDataTree->SetBranchAddress("PFTauDisByTightIsolationMVA"                        ,mPFTauDisByTightIsolationMVA);
  mDataTree->SetBranchAddress("PFTauDisByVLooseCombinedIsolationDeltaBetaCorr"     ,mPFTauDisByVLooseCombinedIsolationDeltaBetaCorr);
  mDataTree->SetBranchAddress("PFTauDisByVLooseIsolationDeltaBetaCorr"             ,mPFTauDisByVLooseIsolationDeltaBetaCorr);
  mDataTree->SetBranchAddress("PFTauDisByVLooseIsolation"                          ,mPFTauDisByVLooseIsolation);
  mDataTree->SetBranchAddress("PFTauDisDecayModeFinding"                           ,mPFTauDisDecayModeFinding);
  mDataTree->SetBranchAddress("PFTauJetPt"                                         ,mPFTauJetPt);
  mDataTree->SetBranchAddress("PFTauJetEta"                                        ,mPFTauJetEta);
  mDataTree->SetBranchAddress("PFTauJetPhi"                                        ,mPFTauJetPhi);
  
  //Gen-daughter of W
  mDataTree->SetBranchAddress("WTauDecayMode"                         ,&mWTauDecayMode            );
  mDataTree->SetBranchAddress("WTauN"                                 ,&mWTauN                    );
  mDataTree->SetBranchAddress("WTauDecayId"                           ,mWTauDecayId               );
  mDataTree->SetBranchAddress("WTauDecayPt"                           ,mWTauDecayPt               );
  mDataTree->SetBranchAddress("WTauDecayEta"                          ,mWTauDecayEta              );
  mDataTree->SetBranchAddress("WTauDecayPhi"                          ,mWTauDecayPhi              ); 
  mDataTree->SetBranchAddress("WTauDecayMass"                         ,mWTauDecayMass             );

  //Photons
  mDataTree->SetBranchAddress("NPhot"                                 ,&mNPhot                    ); 
  mDataTree->SetBranchAddress("PhotE"                                 ,mPhotE                     ); 
  mDataTree->SetBranchAddress("PhotPt"                                ,mPhotPt                    ); 
  mDataTree->SetBranchAddress("PhotPx"                                ,mPhotPx                    ); 
  mDataTree->SetBranchAddress("PhotPy"                                ,mPhotPy                    ); 
  mDataTree->SetBranchAddress("PhotPz"                                ,mPhotPz                    ); 
  mDataTree->SetBranchAddress("PhotEta"                               ,mPhotEta                   ); 
  mDataTree->SetBranchAddress("PhotPhi"                               ,mPhotPhi                   );   
  mDataTree->SetBranchAddress("PhotE1x5"                              ,mPhotE1x5                  ); 
  mDataTree->SetBranchAddress("PhotE2x5"                              ,mPhotE2x5                  ); 
  mDataTree->SetBranchAddress("PhotE5x5"                              ,mPhotE5x5                  ); 
  mDataTree->SetBranchAddress("PhotSigEta"                            ,mPhotSigEta                ); 
  mDataTree->SetBranchAddress("PhotSigPhi"                            ,mPhotSigPhi                ); 
  mDataTree->SetBranchAddress("PhotEcalIso04"                         ,mPhotEcalIso04             ); 
  mDataTree->SetBranchAddress("PhotHcalIso04"                         ,mPhotHcalIso04             ); 
  mDataTree->SetBranchAddress("PhotTrackIso04"                        ,mPhotTrackIso04            ); 
  mDataTree->SetBranchAddress("PhotHasPixSeed"                        ,mPhotHasPixSeed            ); 
  mDataTree->SetBranchAddress("PhotIsPhot"                            ,mPhotIsPhot                ); 
  
  //NPV
  mDataTree->SetBranchAddress("NPV"                                   ,&mNPV                      ); 
  mDataTree->SetBranchAddress("PVx"                                   ,mPVx                       ); 
  mDataTree->SetBranchAddress("PVy"                                   ,mPVy                       ); 
  mDataTree->SetBranchAddress("PVz"                                   ,mPVz                       ); 
  mDataTree->SetBranchAddress("PVchi2"                                ,mPVchi2                    ); 
  mDataTree->SetBranchAddress("PVndof"                                ,mPVndof                    ); 
  mDataTree->SetBranchAddress("PVntracks"                             ,mPVntracks                 ); 
	
  //HLT
  mDataTree->SetBranchAddress("nHLT"                                  ,&mnHLT                     ); 
  mDataTree->SetBranchAddress("HLTArray"                              ,mHLTArray                  ); 
  mDataTree->SetBranchAddress("HLTArray2"                             ,mHLTArray2                 ); 
  mDataTree->SetBranchAddress("HLTNames"                              ,mHLTNames                  ); 
  mDataTree->SetBranchAddress("HLTPreScale2"                          ,mHLTPreScale2              ); 
	
  //L1
  mDataTree->SetBranchAddress("nL1"                                   ,&mnL1                      ); 
  mDataTree->SetBranchAddress("L1Array"                               ,mL1Array                   ); 
  mDataTree->SetBranchAddress("nL1T"                                  ,&mnL1T                     ); 
  mDataTree->SetBranchAddress("L1TArray"                              ,mL1TArray                  ); 
	
  //BeamHalo
  mDataTree->SetBranchAddress("BeamHaloTight"                         ,&mBeamHaloTight            ); 
  mDataTree->SetBranchAddress("BeamHaloLoose"                         ,&mBeamHaloLoose            ); 
	
  //TIV
  mDataTree->SetBranchAddress("TIV_N"                                 ,&mTIV_N                     ); 
  mDataTree->SetBranchAddress("TIV"                                   ,mTIV                       ); 
  mDataTree->SetBranchAddress("TIV_pt"                                ,mTIV_pt                    ); 
  mDataTree->SetBranchAddress("TIV_px"                                ,mTIV_px                    ); 
  mDataTree->SetBranchAddress("TIV_py"                                ,mTIV_py                    ); 
  mDataTree->SetBranchAddress("TIV_pz"                                ,mTIV_pz                    ); 
  mDataTree->SetBranchAddress("TIV_phi"                               ,mTIV_phi                   ); 
  mDataTree->SetBranchAddress("TIV_eta"                               ,mTIV_eta                   ); 
  mDataTree->SetBranchAddress("TIV_dsz"                               ,mTIV_dsz                   ); 
  mDataTree->SetBranchAddress("TIV_dxy"                               ,mTIV_dxy                   ); 
  mDataTree->SetBranchAddress("TIV_d0"                                ,mTIV_d0                    ); 
  mDataTree->SetBranchAddress("TIV_dz"                                ,mTIV_dz                    ); 
  mDataTree->SetBranchAddress("TIV_dsz_corr"                          ,mTIV_dsz_corr              ); 
  mDataTree->SetBranchAddress("TIV_dxy_corr"                          ,mTIV_dxy_corr              ); 
  mDataTree->SetBranchAddress("TIV_d0_corr"                           ,mTIV_d0_corr               ); 
  mDataTree->SetBranchAddress("TIV_dz_corr"                           ,mTIV_dz_corr               ); 
  mDataTree->SetBranchAddress("TIV_dR"                                ,mTIV_dR                    ); 
  mDataTree->SetBranchAddress("TIV_lead"                              ,mTIV_lead                  ); 
  mDataTree->SetBranchAddress("LowTIV"                                ,&mLowTIV                   ); 
	
  //GenPar
  mDataTree->SetBranchAddress("NGenPar"                               ,&mNGenPar                  );
  mDataTree->SetBranchAddress("GenParId"                              ,mGenParId                  );
  mDataTree->SetBranchAddress("GenParStatus"                          ,mGenParStatus              );
  mDataTree->SetBranchAddress("GenParE"                               ,mGenParE                   );
  mDataTree->SetBranchAddress("GenParPx"                              ,mGenParPx                  );
  mDataTree->SetBranchAddress("GenParPy"                              ,mGenParPy                  );
  mDataTree->SetBranchAddress("GenParPz"                              ,mGenParPz                  );
  mDataTree->SetBranchAddress("GenParEta"                             ,mGenParEta                 );
  mDataTree->SetBranchAddress("GenParPhi"                             ,mGenParPhi                 );
  mDataTree->SetBranchAddress("GenParCharge"                          ,mGenParCharge              );
  mDataTree->SetBranchAddress("GenParPt"                              ,mGenParPt                  );
  mDataTree->SetBranchAddress("GenParMass"                            ,mGenParMass                );
  mDataTree->SetBranchAddress("GenParMother1"                         ,mGenParMother1             );
  mDataTree->SetBranchAddress("GenParMother2"                         ,mGenParMother2             );
  mDataTree->SetBranchAddress("GenParDoughterOf"                      ,mGenParDoughterOf          );

  //GenJet
  mDataTree->SetBranchAddress(  "GenAK4JetE"                          ,mGenAK4JetE                );
  mDataTree->SetBranchAddress(  "GenAK4JetPt"                         ,mGenAK4JetPt               );
  mDataTree->SetBranchAddress(  "GenAK4JetPx"                         ,mGenAK4JetPx               );
  mDataTree->SetBranchAddress(  "GenAK4JetPy"                         ,mGenAK4JetPy               );
  mDataTree->SetBranchAddress(  "GenAK4JetPz"                         ,mGenAK4JetPz               );
  mDataTree->SetBranchAddress(  "GenAK4JetEta"                        ,mGenAK4JetEta              );
  mDataTree->SetBranchAddress(  "GenAK4JetPhi"                        ,mGenAK4JetPhi              );
  mDataTree->SetBranchAddress(  "GenAK4JetEmEnergy"                   ,mGenAK4JetEmEnergy         );
  mDataTree->SetBranchAddress(  "GenAK4JetHadEnergy"                  ,mGenAK4JetHadEnergy        );
  
  //PDF
  mDataTree->SetBranchAddress( "GenScale"                             ,&mPDFGenScale              );
  mDataTree->SetBranchAddress( "PDFx1"                                ,&mPDFx1                    );
  mDataTree->SetBranchAddress( "PDFx2"                                ,&mPDFx2                    );
  mDataTree->SetBranchAddress( "PDFf1"                                ,&mPDFf1                    );
  mDataTree->SetBranchAddress( "PDFf2"                                ,&mPDFf2                    );
  mDataTree->SetBranchAddress( "PDFscale"                             ,&mPDFscale                 );
  mDataTree->SetBranchAddress( "PDFpdf1"                              ,&mPDFpdf1                  );
  mDataTree->SetBranchAddress( "PDFpdf2"                              ,&mPDFpdf2                  );
}


EventData::~EventData() 
{
  delete mDataTree;
}


bool EventData::GetNextEvent() 
{
  time_t rawtime;
  time ( &rawtime );
  
  if ( mEvent % 1000000 == 0 ) cout << mEvent << "   time:"<< ctime (&rawtime)  << endl;
  if ( mEvent == mMaxEvents ) return false;
  if ( !mDataTree->GetEntry(mEvent) ) return false;
  mEvent++;
  
  return true;
}


///------------------------------------------------------------------------------------------------------------------------------------
double EventData::Weight()
{   
  double ww = mylumi["met1"] / mylumi[ mFileName.c_str() ] ; 
  double pileup_weight=0.;
  if(misMC==1){
    int mnpv=0;
    //if(mbx ==-1) mnpv= mnpvm1;
    //else if(mbx ==0) mnpv= mnpv0;
    //else if(mbx ==1) mnpv= mnpvp1;
    
    mnpv = mnpv0;
    
    size_t dd = mnpv;
    
    if( dd < mPileUpWeights.size() )
      {
	pileup_weight = mPileUpWeights[ mnpv ];
      }
    else{ //should not happen as we have a weight for all simulated n_pu multiplicities!
			//throw logic_error("n_pu too big");
    }
  }
  else
    {
      pileup_weight = 1;
    }
  
  double www = ww *pileup_weight; 
  //double www = ww; 
  
  return www;
}

/*
Double_t  EventData::PDFWeight( UInt_t id ){	
double  w1,w2;

LHAPDF::usePDFMember(1, id ); 

double basepdf1 = LHAPDF::xfx(1, mPDFx1, mPDFscale, mPDFf1)/mPDFx1;
double basepdf2 = LHAPDF::xfx(1, mPDFx2, mPDFscale, mPDFf2)/mPDFx2;
w1 = basepdf1*basepdf2;

LHAPDF::usePDFMember(3,0 );

double basepdf1_ = LHAPDF::xfx(3, mPDFx1, mPDFscale, mPDFf1)/mPDFx1;
double basepdf2_ = LHAPDF::xfx(3, mPDFx2, mPDFscale, mPDFf2)/mPDFx2;
w2 = basepdf1_*basepdf2_;

return w1/w2 ;
} 

Double_t  EventData::PDFWeightAlphaS( UInt_t id ){
double  w1;

LHAPDF::usePDFMember(2,id );

double basepdf1 = LHAPDF::xfx(2, mPDFx1, mPDFscale, mPDFf1)/mPDFx1;
double basepdf2 = LHAPDF::xfx(2, mPDFx2, mPDFscale, mPDFf2)/mPDFx2;
w1 = basepdf1*basepdf2;

return w1;
}


Double_t  EventData::PDFWeightAlphaSmstw( UInt_t id ){

double  w1;
int usemem =0;

if(id==0) usemem=2;
else if(id==1) usemem=3;

LHAPDF::usePDFMember(usemem,0 );
double basepdf1 = LHAPDF::xfx(usemem, mPDFx1, mPDFscale, mPDFf1)/mPDFx1;
double basepdf2 = LHAPDF::xfx(usemem, mPDFx2, mPDFscale, mPDFf2)/mPDFx2;

w1 = basepdf1*basepdf2;

return w1;
} 
*/


Int_t           EventData::IsMC()                                            {   return misMC;                                    }
string          EventData::JetType()                                         {   return mJetType;                                 }
string          EventData::LepType()                                         {   return mLepType;                                 }

int             EventData::MetType()                                         {   return mMetType;                                 }
float           EventData::SecJetCut()                                       {   return mSecJetCut;                               }
Double_t        EventData::PDFWeights(UInt_t id)                             {   return mPDFWeights[id];                          } 
float           EventData::EnergyScale()                                     {   return mEnergyScale;                             }

Int_t           EventData::run()                                             {   return  mrun;                                     }
Long64_t        EventData::event()                                           {   return  mevent;                                   }
Int_t           EventData::lumi()                                            {   return  mlumi;                                    }
Int_t           EventData::bx()                                              {   return  mbx;                                      }
Int_t           EventData::npvm1()                                           {   return  mnpvm1;                                   }
Int_t           EventData::npv0()                                            {   return  mnpv0;                                    }
Int_t           EventData::npvp1()                                           {   return  mnpvp1;                                   }

Double_t        EventData::ptHat()                                           {   return  mptHat;                                   }
Int_t           EventData::NoiseFlag(UInt_t id)                              {   return  mNoiseFlag[id];                           }

Double_t        EventData::fastJetRho()                                      {   return  mfastJetRho;                              }
										
Int_t           EventData::NCaloAK4Jets()                                    {   return  mNCaloAK4Jets;                            }
Double_t        EventData::CaloAK4JetE(UInt_t id)                            {   return  mCaloAK4JetE[id];                         }
Double_t        EventData::CaloAK4JetPt(UInt_t id)                           {   return  mCaloAK4JetPt[id];                        }
Double_t        EventData::CaloAK4JetPx(UInt_t id)                           {   return  mCaloAK4JetPx[id];                        }
Double_t        EventData::CaloAK4JetPy(UInt_t id)                           {   return  mCaloAK4JetPy[id];                        }
Double_t        EventData::CaloAK4JetPz(UInt_t id)                           {   return  mCaloAK4JetPz[id];                        }
Double_t        EventData::CaloAK4JetEta(UInt_t id)                          {   return  mCaloAK4JetEta[id];                       }
Double_t        EventData::CaloAK4JetPhi(UInt_t id)                          {   return  mCaloAK4JetPhi[id];                       }
Double_t        EventData::CaloAK4JetEmf(UInt_t id)                          {   return  mCaloAK4JetEmf[id];                       }
Double_t        EventData::CaloAK4JetfHPD(UInt_t id)                         {   return  mCaloAK4JetfHPD[id];                      }
Double_t        EventData::CaloAK4JetfRBX(UInt_t id)                         {   return  mCaloAK4JetfRBX[id];                      }
Double_t        EventData::CaloAK4JetN90Hits(UInt_t id)                      {   return  mCaloAK4JetN90Hits[id];                   }
Int_t           EventData::CaloAK4JetN90(UInt_t id)                          {   return  mCaloAK4JetN90[id];                       }
Double_t        EventData::CaloAK4JetSigEta(UInt_t id)                       {   return  mCaloAK4JetSigEta[id];                    }
Double_t        EventData::CaloAK4JetSigPhi(UInt_t id)                       {   return  mCaloAK4JetSigPhi[id];                    }
Double_t        EventData::CaloAK4JetIDEmf(UInt_t id)                        {   return  mCaloAK4JetIDEmf[id];                     }
Double_t        EventData::CaloAK4JetECor(UInt_t id)                         {   return  mCaloAK4JetECor[id];                      }
Double_t        EventData::CaloAK4JetPtCor(UInt_t id)                        {   return  mCaloAK4JetPtCor[id];                     }
Double_t        EventData::CaloAK4JetPxCor(UInt_t id)                        {   return  mCaloAK4JetPxCor[id];                     }
Double_t        EventData::CaloAK4JetPyCor(UInt_t id)                        {   return  mCaloAK4JetPyCor[id];                     }
Double_t        EventData::CaloAK4JetPzCor(UInt_t id)                        {   return  mCaloAK4JetPzCor[id];                     }
Double_t        EventData::CaloAK4JetBtagTkCountHighEff(UInt_t id)           {   return  mCaloAK4JetBtagTkCountHighEff[id];        }
Double_t        EventData::CaloAK4JetBTagSimpleSecVtx(UInt_t id)             {   return  mCaloAK4JetBTagSimpleSecVtx[id];          }
Double_t        EventData::CaloAK4JetBTagCombSecVtx(UInt_t id)               {   return  mCaloAK4JetBTagCombSecVtx[id];            }
Double_t        EventData::CaloAK4TrackPt(UInt_t id)                         {   return  mCaloAK4TrackPt[id];                      }
Int_t           EventData::CaloAK4JetIDLOOSE(UInt_t id)                      {   return  mCaloAK4JetIDLOOSE[id];                   }
Int_t           EventData::CaloAK4JetIDTIGHT(UInt_t id)                      {   return  mCaloAK4JetIDTIGHT[id];                   }							
		
Int_t           EventData::NPFAK4Jets()                                      {   return  mNPFAK4Jets;                              }
Double_t        EventData::PFAK4JetE(UInt_t id)                              {   return  mPFAK4JetE[id];                           }
Double_t        EventData::PFAK4JetPt(UInt_t id)                             {   return  mPFAK4JetPt[id];                          }
Double_t        EventData::PFAK4JetPx(UInt_t id)                             {   return  mPFAK4JetPx[id];                          }
Double_t        EventData::PFAK4JetPy(UInt_t id)                             {   return  mPFAK4JetPy[id];                          }
Double_t        EventData::PFAK4JetPz(UInt_t id)                             {   return  mPFAK4JetPz[id];                          }
Double_t        EventData::PFAK4JetEta(UInt_t id)                            {   return  mPFAK4JetEta[id];                         }
Double_t        EventData::PFAK4JetPhi(UInt_t id)                            {   return  mPFAK4JetPhi[id];                         }
Double_t        EventData::PFAK4JetfHPD(UInt_t id)                           {   return  mPFAK4JetfHPD[id];                        }
Double_t        EventData::PFAK4JetfRBX(UInt_t id)                           {   return  mPFAK4JetfRBX[id];                        }
Double_t        EventData::PFAK4JetN90Hits(UInt_t id)                        {   return  mPFAK4JetN90Hits[id];                     }
Int_t           EventData::PFAK4JetN90(UInt_t id)                            {   return  mPFAK4JetN90[id];                         }
Double_t        EventData::PFAK4JetSigEta(UInt_t id)                         {   return  mPFAK4JetSigEta[id];                      }
Double_t        EventData::PFAK4JetSigPhi(UInt_t id)                         {   return  mPFAK4JetSigPhi[id];                      }
Double_t        EventData::PFAK4JetIDEmf(UInt_t id)                          {   return  mPFAK4JetIDEmf[id];                       }
Double_t        EventData::PFAK4JetECor(UInt_t id)                           {   return  mPFAK4JetECor[id];                        }

 Double_t        EventData::PFAK4JetPtCor(UInt_t id)                          {   return  mPFAK4JetPtCor[id];                       }
 Double_t        EventData::PFAK4JetPxCor(UInt_t id)                          {   return  mPFAK4JetPxCor[id];                       }
 Double_t        EventData::PFAK4JetPyCor(UInt_t id)                          {   return  mPFAK4JetPyCor[id];                       }
 Double_t        EventData::PFAK4JetPzCor(UInt_t id)                          {   return  mPFAK4JetPzCor[id];                       }

//Double_t        EventData::PFAK4JetPtCor(UInt_t id)                     {    return  mPFAK4JetPtCor[id] * (1+ mEnergyScale*mPFAK4uncer[id] );      } 
//Double_t        EventData::PFAK4JetPxCor(UInt_t id)                     {    return  mPFAK4JetPxCor[id] * (1+ mEnergyScale*mPFAK4uncer[id] );      } 
//Double_t        EventData::PFAK4JetPyCor(UInt_t id)                     {    return  mPFAK4JetPyCor[id] * (1+ mEnergyScale*mPFAK4uncer[id] );      }
//Double_t        EventData::PFAK4JetPzCor(UInt_t id)                     {    return  mPFAK4JetPzCor[id] * (1+ mEnergyScale*mPFAK4uncer[id] );      }



Double_t        EventData::PFAK4JetBtagTkCountHighEff(UInt_t id)             {   return  mPFAK4JetBtagTkCountHighEff[id];          }
Double_t        EventData::PFAK4JetBTagSimpleSecVtx(UInt_t id)               {   return  mPFAK4JetBTagSimpleSecVtx[id];            }
Double_t        EventData::PFAK4JetBTagCombSecVtx(UInt_t id)                 {   return  mPFAK4JetBTagCombSecVtx[id];              }
Double_t        EventData::PFAK4JetNeuEmEngFrac(UInt_t id)                   {   return  mPFAK4JetNeuEmEngFrac[id];                }
Double_t        EventData::PFAK4JetChaEmEngFrac(UInt_t id)                   {   return  mPFAK4JetChaEmEngFrac[id];                }
Double_t        EventData::PFAK4JetChaHadEngFrac(UInt_t id)                  {   return  mPFAK4JetChaHadEngFrac[id];               }
Double_t        EventData::PFAK4JetNeuHadEngFrac(UInt_t id)                  {   return  mPFAK4JetNeuHadEngFrac[id];               }
Double_t        EventData::PFAK4JetChaMuEng(UInt_t id)                       {   return  mPFAK4JetChaMuEng[id];                    }
Double_t        EventData::PFAK4JetMuonEng(UInt_t id)                        {   return  mPFAK4JetMuonEng[id];                     }
Double_t        EventData::PFAK4JetPhotEng(UInt_t id)                        {   return  mPFAK4JetPhotEng[id];                     }
Double_t        EventData::PFAK4JetElecEng(UInt_t id)                        {   return  mPFAK4JetElecEng[id];                     }
Int_t           EventData::PFAK4JetNumOfChaMu(UInt_t id)                     {   return  mPFAK4JetNumOfChaMu[id];                  }
Int_t           EventData::PFAK4JetNumOfMuon(UInt_t id)                      {   return  mPFAK4JetNumOfMuon[id];                   }
Int_t           EventData::PFAK4JetNumOfPhot(UInt_t id)                      {   return  mPFAK4JetNumOfPhot[id];                   }
Int_t           EventData::PFAK4JetNumOfElec(UInt_t id)                      {   return  mPFAK4JetNumOfElec[id];                   }
Int_t           EventData::PFAK4JetNumOfNeu(UInt_t id)                       {   return  mPFAK4JetNumOfNeu[id];                    }
Int_t           EventData::PFAK4JetNumOfCha(UInt_t id)                       {   return  mPFAK4JetNumOfCha[id];                    }
Int_t           EventData::PFAK4JetNumOfNeuHad(UInt_t id)                    {   return  mPFAK4JetNumOfNeuHad[id];                 }
Int_t           EventData::PFAK4JetNumOfChaHad(UInt_t id)                    {   return  mPFAK4JetNumOfChaHad[id];                 }
Int_t           EventData::PFAK4JetNumOfDaughters(UInt_t id)                 {   return  mPFAK4JetNumOfDaughters[id];              }
Int_t           EventData::PFAK4JetIDLOOSE(UInt_t id)                        {   return  mPFAK4JetIDLOOSE[id];                     }
Int_t           EventData::PFAK4JetIDTIGHT(UInt_t id)                        {   return  mPFAK4JetIDTIGHT[id];                     }
Double_t           EventData::PFAK4JetPUFullJetId(UInt_t id)                    {   return  mPFAK4JetPUFullJetId[id];                 }
Double_t        EventData::PFAK4uncer(UInt_t id)                             {   return  mPFAK4uncer[id];                          }						
						
Int_t           EventData::NMet()                                            {   return  mNMet;                                    }
Double_t        EventData::MetPt(UInt_t id) 
{   

    Double_t jetx=0.;

    for(int i=0; i<mNPFAK4Jets;  i++)
    {
          jetx = jetx+  ( mEnergyScale*mPFAK4uncer[i]* mPFAK4JetPxCor[i] ) ;
    }
    double metx =  mMetPx[id]+jetx ;                               

    Double_t jety=0.;

      for(int i=0; i<mNPFAK4Jets;  i++)
      {
	   jety = jety+  ( mEnergyScale*mPFAK4uncer[i]* mPFAK4JetPyCor[i] ) ;
      }

      double mety =   mMetPy[id]+jety ;
    

      return  sqrt( metx*metx + mety*mety);
}




//Double_t        EventData::MetPx(UInt_t id)                                  {   return  mMetPx[id];                               }
//Double_t        EventData::MetPy(UInt_t id)                                  {   return  mMetPy[id];                               }
Double_t        EventData::MetPhi(UInt_t id)                                 {   return  mMetPhi[id];                              }
Double_t        EventData::MetSumEt(UInt_t id)                               {   return  mMetSumEt[id];                            }
Double_t        EventData::MetSign(UInt_t id)                                {   return  mMetSign[id];                             }


Double_t  EventData::MetPx(UInt_t id)
{
	Double_t jetx=0.;

	for(int i=0; i<mNPFAK4Jets;  i++)
	{
		jetx = jetx+  ( mEnergyScale*mPFAK4uncer[i]* mPFAK4JetPxCor[i] ) ; 	
	}
	return  mMetPx[id]+jetx  ;
}

Double_t  EventData::MetPy(UInt_t id)
{
	Double_t jety=0.;

	for(int i=0; i<mNPFAK4Jets;  i++)
	{
		jety = jety+  ( mEnergyScale*mPFAK4uncer[i]* mPFAK4JetPyCor[i] ) ; 
	}
	
	return  mMetPy[id]+jety ;
}
	



Int_t  EventData::NPFLep()
{
	Int_t send=0; 
	if(mLepType=="m") send=  mNPFMuon;
	if(mLepType=="e") send=  mNPFElec;
	if(mLepType=="t") send=  mNPFTau;
	return send; 
}

Double_t  EventData::PFLepPt(UInt_t id)
{
	Double_t send=0.; 
	if(mLepType=="m") send=  mPFMuonPt[id];
	if(mLepType=="e") send=  mPFElecPt[id];
	if(mLepType=="t") send=  mPFTauPt[id];
	return send; 
}
Double_t  EventData::PFLepE(UInt_t id)
{ 
	Double_t send=0.; 
	if(mLepType=="m") send=  mPFMuonE[id];
	if(mLepType=="e") send=  mPFElecE[id];
	if(mLepType=="t") send=  mPFTauE[id];
	return send; 
}
Double_t  EventData::PFLepPx(UInt_t id)
{
	Double_t send=0.; 
	if(mLepType=="m") send=  mPFMuonPx[id];
	if(mLepType=="e") send=  mPFElecPx[id];
	if(mLepType=="t") send=  mPFTauPx[id];
	return send; 
}
Double_t  EventData::PFLepPy(UInt_t id)
{
	Double_t send=0.; 
	if(mLepType=="m") send=  mPFMuonPy[id];
	if(mLepType=="e") send=  mPFElecPy[id];
	if(mLepType=="t") send=  mPFTauPy[id];
	return send; 
}
Double_t  EventData::PFLepPz(UInt_t id)
{
	Double_t send=0.; 
	if(mLepType=="m") send=  mPFMuonPz[id];
	if(mLepType=="e") send=  mPFElecPz[id];
	if(mLepType=="t") send=  mPFTauPz[id];
	return send; 
}
Double_t  EventData::PFLepEta(UInt_t id)
{
	Double_t send=0.; 
	if(mLepType=="m") send=  mPFMuonEta[id];
	if(mLepType=="e") send=  mPFElecEta[id];
	if(mLepType=="t") send=  mPFTauEta[id];
	return send; 
}
Double_t  EventData::PFLepPhi(UInt_t id)
{
	Double_t send=0.; 
	if(mLepType=="m") send=  mPFMuonPhi[id];
	if(mLepType=="e") send=  mPFElecPhi[id];
	if(mLepType=="t") send=  mPFTauPhi[id];
	return send; 
}
Int_t  EventData::PFLepCharge(UInt_t id)
{
	Int_t send=0; 
	if(mLepType=="m") send=  mPFMuonCharge[id];
	if(mLepType=="e") send=  mPFElecCharge[id];
	if(mLepType=="t") send=  mPFTauCharge[id]; 
	return send; 
}

Int_t           EventData::NMuon()                                           {   return  mNMuon;                                   }
Double_t        EventData::MuonPt(UInt_t id)                                 {   return  mMuonPt[id];                              }
Double_t        EventData::MuonEt(UInt_t id)                                 {   return  mMuonEt[id];                              }
Double_t        EventData::MuonE(UInt_t id)                                  {   return  mMuonE[id];                               }
Double_t        EventData::MuonPx(UInt_t id)                                 {   return  mMuonPx[id];                              }
Double_t        EventData::MuonPy(UInt_t id)                                 {   return  mMuonPy[id];                              }
Double_t        EventData::MuonPz(UInt_t id)                                 {   return  mMuonPz[id];                              }
Double_t        EventData::MuonEta(UInt_t id)                                {   return  mMuonEta[id];                             }
Double_t        EventData::MuonPhi(UInt_t id)                                {   return  mMuonPhi[id];                             }
Double_t        EventData::MuonCharge(UInt_t id)                             {   return  mMuonCharge[id];                          }
Int_t           EventData::MuonIsGlobal(UInt_t id)                           {   return  mMuonIsGlobal[id];                        }
Int_t           EventData::MuonIsStandAlone(UInt_t id)                       {   return  mMuonIsStandAlone[id];                    }
Int_t           EventData::MuonIsTracker(UInt_t id)                          {   return  mMuonIsTracker[id];                       }
Double_t        EventData::MuonSumPtDR03(UInt_t id)                          {   return  mMuonSumPtDR03[id];                       }
Double_t        EventData::MuonSumPtDR05(UInt_t id)                          {   return  mMuonSumPtDR05[id];                       }
Double_t        EventData::MuonEmEtDR03(UInt_t id)                           {   return  mMuonEmEtDR03[id];                        }
Double_t        EventData::MuonHadEtDR03(UInt_t id)                          {   return  mMuonHadEtDR03[id];                       }
Int_t           EventData::MuonNumOfMatches(UInt_t id)                       {   return  mMuonNumOfMatches[id];                    }
Double_t        EventData::MuonCombChi2Norm(UInt_t id)                       {   return  mMuonCombChi2Norm[id];                    }
Int_t           EventData::MuonCombValidHits(UInt_t id)                      {   return  mMuonCombValidHits[id];                   }
Int_t           EventData::MuonCombLostHits(UInt_t id)                       {   return  mMuonCombLostHits[id];                    }
Double_t        EventData::MuonCombPt(UInt_t id)                             {   return  mMuonCombPt[id];                          }
Double_t        EventData::MuonCombPz(UInt_t id)                             {   return  mMuonCombPz[id];                          }
Double_t        EventData::MuonCombP(UInt_t id)                              {   return  mMuonCombP[id];                           }
Double_t        EventData::MuonCombEta(UInt_t id)                            {   return  mMuonCombEta[id];                         }
Double_t        EventData::MuonCombPhi(UInt_t id)                            {   return  mMuonCombPhi[id];                         }
Double_t        EventData::MuonCombChi2(UInt_t id)                           {   return  mMuonCombChi2[id];                        }
Double_t        EventData::MuonCombCharge(UInt_t id)                         {   return  mMuonCombCharge[id];                      }
Double_t        EventData::MuonCombQOverPError(UInt_t id)                    {   return  mMuonCombQOverPError[id];                 }
Double_t        EventData::MuonCombNdof(UInt_t id)                           {   return  mMuonCombNdof[id];                        }
Double_t        EventData::MuonCombVx(UInt_t id)                             {   return  mMuonCombVx[id];                          }
Double_t        EventData::MuonCombVy(UInt_t id)                             {   return  mMuonCombVy[id];                          }
Double_t        EventData::MuonCombVz(UInt_t id)                             {   return  mMuonCombVz[id];                          }
Double_t        EventData::MuonCombD0(UInt_t id)                             {   return  mMuonCombD0[id];                          }
Double_t        EventData::MuonCombDz(UInt_t id)                             {   return  mMuonCombDz[id];                          }
Double_t        EventData::MuonStandChi2Norm(UInt_t id)                      {   return  mMuonStandChi2Norm[id];                   }
Int_t           EventData::MuonStandValidHits(UInt_t id)                     {   return  mMuonStandValidHits[id];                  }
Int_t           EventData::MuonStandLostHits(UInt_t id)                      {   return  mMuonStandLostHits[id];                   }
Double_t        EventData::MuonStandPt(UInt_t id)                            {   return  mMuonStandPt[id];                         }
Double_t        EventData::MuonStandPz(UInt_t id)                            {   return  mMuonStandPz[id];                         }
Double_t        EventData::MuonStandP(UInt_t id)                             {   return  mMuonStandP[id];                          }
Double_t        EventData::MuonStandEta(UInt_t id)                           {   return  mMuonStandEta[id];                        }
Double_t        EventData::MuonStandPhi(UInt_t id)                           {   return  mMuonStandPhi[id];                        }
Double_t        EventData::MuonStandChi2(UInt_t id)                          {   return  mMuonStandChi2[id];                       }
Double_t        EventData::MuonStandCharge(UInt_t id)                        {   return  mMuonStandCharge[id];                     }
Double_t        EventData::MuonStandQOverPError(UInt_t id)                   {   return  mMuonStandQOverPError[id];                }
Double_t        EventData::MuonTrkChi2Norm(UInt_t id)                        {   return  mMuonTrkChi2Norm[id];                     }
Int_t           EventData::MuonTrkValidHits(UInt_t id)                       {   return  mMuonTrkValidHits[id];                    }
Int_t           EventData::MuonTrkLostHits(UInt_t id)                        {   return  mMuonTrkLostHits[id];                     }
Double_t        EventData::MuonTrkPt(UInt_t id)                              {   return  mMuonTrkPt[id];                           }
Double_t        EventData::MuonTrkPz(UInt_t id)                              {   return  mMuonTrkPz[id];                           }
Double_t        EventData::MuonTrkP(UInt_t id)                               {   return  mMuonTrkP[id];                            }
Double_t        EventData::MuonTrkEta(UInt_t id)                             {   return  mMuonTrkEta[id];                          }
Double_t        EventData::MuonTrkPhi(UInt_t id)                             {   return  mMuonTrkPhi[id];                          }
Double_t        EventData::MuonTrkChi2(UInt_t id)                            {   return  mMuonTrkChi2[id];                         }
Double_t        EventData::MuonTrkCharge(UInt_t id)                          {   return  mMuonTrkCharge[id];                       }
Double_t        EventData::MuonTrkQOverPError(UInt_t id)                     {   return  mMuonTrkQOverPError[id];                  }
Double_t        EventData::MuonTrkDxy(UInt_t id)                             {   return  mMuonTrkDxy[id];                          }
Int_t           EventData::MuonTrkNumOfValidPixHits(UInt_t id)               {   return  mMuonTrkNumOfValidPixHits[id];            }
					
Int_t           EventData::NPFMuon()                                         {   return  mNPFMuon;                                 }
Double_t        EventData::PFMuonPt(UInt_t id)                               {   return  mPFMuonPt[id];                            }
Double_t        EventData::PFMuonEt(UInt_t id)                               {   return  mPFMuonEt[id];                            }
Double_t        EventData::PFMuonE(UInt_t id)                                {   return  mPFMuonE[id];                             }
Double_t        EventData::PFMuonPx(UInt_t id)                               {   return  mPFMuonPx[id];                            }
Double_t        EventData::PFMuonPy(UInt_t id)                               {   return  mPFMuonPy[id];                            }
Double_t        EventData::PFMuonPz(UInt_t id)                               {   return  mPFMuonPz[id];                            }
Double_t        EventData::PFMuonEta(UInt_t id)                              {   return  mPFMuonEta[id];                           }
Double_t        EventData::PFMuonPhi(UInt_t id)                              {   return  mPFMuonPhi[id];                           }
Int_t           EventData::PFMuonCharge(UInt_t id)                           {   return  mPFMuonCharge[id];                        }
Int_t           EventData::PFMuonIsGlobal(UInt_t id)                         {   return  mPFMuonIsGlobal[id];                      }
Int_t           EventData::PFMuonIsStandAlone(UInt_t id)                     {   return  mPFMuonIsStandAlone[id];                  }
Int_t           EventData::PFMuonIsTracker(UInt_t id)                        {   return  mPFMuonIsTracker[id];                     }
Int_t           EventData::PFMuonIsTight(UInt_t id)                          {   return  mPFMuonIsTight[id];                       }
Int_t           EventData::PFMuonIsLoose(UInt_t id)                          {   return  mPFMuonIsLoose[id];                       }
Double_t        EventData::PFMuonChargedHadronIso(UInt_t id)                 {   return  mPFMuonChargedHadronIso[id];              }
Double_t        EventData::PFMuonPhotonIso(UInt_t id)                        {   return  mPFMuonPhotonIso[id];                     }
Double_t        EventData::PFMuonNeutralHadronIso(UInt_t id)                 {   return  mPFMuonNeutralHadronIso[id];              }
Int_t           EventData::PFMuonisGMPT(UInt_t id)                           {   return  mPFMuonisGMPT[id];                        }
Int_t           EventData::PFMuonNumOfMatches(UInt_t id)                     {   return  mPFMuonNumOfMatches[id];                  }
Double_t        EventData::PFMuoninnertrackPt(UInt_t id)                     {   return  mPFMuoninnertrackPt[id];                  }
Int_t           EventData::PFMuonnValidHits(UInt_t id)                       {   return  mPFMuonnValidHits[id];                    }
Int_t           EventData::PFMuonnValidPixelHits(UInt_t id)                  {   return  mPFMuonnValidPixelHits[id];               }
Double_t        EventData::PFMuondxy(UInt_t id)                              {   return  mPFMuondxy[id];                           }
Double_t        EventData::PFMuondz(UInt_t id)                               {   return  mPFMuondz[id];                            }
Double_t        EventData::PFMuonCombChi2Norm(UInt_t id)                     {   return  mPFMuonCombChi2Norm[id];                  }
Int_t           EventData::PFMuonCombValidHits(UInt_t id)                    {   return  mPFMuonCombValidHits[id];                 }
Int_t           EventData::PFMuonCombLostHits(UInt_t id)                     {   return  mPFMuonCombLostHits[id];                  }
Double_t        EventData::PFMuonCombPt(UInt_t id)                           {   return  mPFMuonCombPt[id];                        }
Double_t        EventData::PFMuonCombPz(UInt_t id)                           {   return  mPFMuonCombPz[id];                        }
Double_t        EventData::PFMuonCombP(UInt_t id)                            {   return  mPFMuonCombP[id];                         }
Double_t        EventData::PFMuonCombEta(UInt_t id)                          {   return  mPFMuonCombEta[id];                       }
Double_t        EventData::PFMuonCombPhi(UInt_t id)                          {   return  mPFMuonCombPhi[id];                       }
Double_t        EventData::PFMuonCombChi2(UInt_t id)                         {   return  mPFMuonCombChi2[id];                      }
Double_t        EventData::PFMuonCombCharge(UInt_t id)                       {   return  mPFMuonCombCharge[id];                    }
Double_t        EventData::PFMuonCombQOverPError(UInt_t id)                  {   return  mPFMuonCombQOverPError[id];               }
Double_t        EventData::PFMuonCombNdof(UInt_t id)                         {   return  mPFMuonCombNdof[id];                      }
Double_t        EventData::PFMuonCombVx(UInt_t id)                           {   return  mPFMuonCombVx[id];                        }
Double_t        EventData::PFMuonCombVy(UInt_t id)                           {   return  mPFMuonCombVy[id];                        }
Double_t        EventData::PFMuonCombVz(UInt_t id)                           {   return  mPFMuonCombVz[id];                        }
Double_t        EventData::PFMuonCombD0(UInt_t id)                           {   return  mPFMuonCombD0[id];                        }
Double_t        EventData::PFMuonCombDz(UInt_t id)                           {   return  mPFMuonCombDz[id];                        }
Double_t        EventData::PFMuonStandChi2Norm(UInt_t id)                    {   return  mPFMuonStandChi2Norm[id];                 }
Int_t           EventData::PFMuonStandValidHits(UInt_t id)                   {   return  mPFMuonStandValidHits[id];                }
Int_t           EventData::PFMuonStandLostHits(UInt_t id)                    {   return  mPFMuonStandLostHits[id];                 }
Double_t        EventData::PFMuonStandPt(UInt_t id)                          {   return  mPFMuonStandPt[id];                       }
Double_t        EventData::PFMuonStandPz(UInt_t id)                          {   return  mPFMuonStandPz[id];                       }
Double_t        EventData::PFMuonStandP(UInt_t id)                           {   return  mPFMuonStandP[id];                        }
Double_t        EventData::PFMuonStandEta(UInt_t id)                         {   return  mPFMuonStandEta[id];                      }
Double_t        EventData::PFMuonStandPhi(UInt_t id)                         {   return  mPFMuonStandPhi[id];                      }
Double_t        EventData::PFMuonStandChi2(UInt_t id)                        {   return  mPFMuonStandChi2[id];                     }
Double_t        EventData::PFMuonStandCharge(UInt_t id)                      {   return  mPFMuonStandCharge[id];                   }
Double_t        EventData::PFMuonStandQOverPError(UInt_t id)                 {   return  mPFMuonStandQOverPError[id];              }
Double_t        EventData::PFMuonTrkChi2Norm(UInt_t id)                      {   return  mPFMuonTrkChi2Norm[id];                   }
Int_t           EventData::PFMuonTrkValidHits(UInt_t id)                     {   return  mPFMuonTrkValidHits[id];                  }
Int_t           EventData::PFMuonTrkLostHits(UInt_t id)                      {   return  mPFMuonTrkLostHits[id];                   }
Double_t        EventData::PFMuonTrkPt(UInt_t id)                            {   return  mPFMuonTrkPt[id];                         }
Double_t        EventData::PFMuonTrkPz(UInt_t id)                            {   return  mPFMuonTrkPz[id];                         }
Double_t        EventData::PFMuonTrkP(UInt_t id)                             {   return  mPFMuonTrkP[id];                          }
Double_t        EventData::PFMuonTrkEta(UInt_t id)                           {   return  mPFMuonTrkEta[id];                        }
Double_t        EventData::PFMuonTrkPhi(UInt_t id)                           {   return  mPFMuonTrkPhi[id];                        }
Double_t        EventData::PFMuonTrkChi2(UInt_t id)                          {   return  mPFMuonTrkChi2[id];                       }
Double_t        EventData::PFMuonTrkCharge(UInt_t id)                        {   return  mPFMuonTrkCharge[id];                     }
Double_t        EventData::PFMuonTrkQOverPError(UInt_t id)                   {   return  mPFMuonTrkQOverPError[id];                }
Double_t        EventData::PFMuonTrkDxy(UInt_t id)                           {   return  mPFMuonTrkDxy[id];                        }
Double_t        EventData::PFMuonTrkNumOfValidPixHits(UInt_t id)             {   return  mPFMuonTrkNumOfValidPixHits[id];          }
Double_t        EventData::PFMuonR04ChargedHadronPt(UInt_t id)               {   return  mPFMuonR04ChargedHadronPt[id];            }
Double_t        EventData::PFMuonR04NeutralHadronEt(UInt_t id)               {   return  mPFMuonR04NeutralHadronEt[id];            }
Double_t        EventData::PFMuonR04PhotonEt(UInt_t id)                      {   return  mPFMuonR04PhotonEt[id];                   }
Double_t        EventData::PFMuonR04PUPt(UInt_t id)                          {   return  mPFMuonR04PUPt[id];                       }
						
Int_t           EventData::NElec()                                           {   return  mNElec;                                   }
Double_t        EventData::ElecE(UInt_t id)                                  {   return  mElecE[id];                               }
Double_t        EventData::ElecPt(UInt_t id)                                 {   return  mElecPt[id];                              }
Double_t        EventData::ElecPx(UInt_t id)                                 {   return  mElecPx[id];                              }
Double_t        EventData::ElecPy(UInt_t id)                                 {   return  mElecPy[id];                              }
Double_t        EventData::ElecPz(UInt_t id)                                 {   return  mElecPz[id];                              }
Int_t           EventData::ElecEcalseed(UInt_t id)                           {   return  mElecEcalseed[id];                        }
Int_t           EventData::ElecID80(UInt_t id)                               {   return  mElecID80[id];                            }
Int_t           EventData::ElecID95(UInt_t id)                               {   return  mElecID95[id];                            }
Double_t        EventData::ElecEta(UInt_t id)                                {   return  mElecEta[id];                             }
Double_t        EventData::ElecPhi(UInt_t id)                                {   return  mElecPhi[id];                             }
Int_t           EventData::ElecCharge(UInt_t id)                             {   return  mElecCharge[id];                          }
Double_t        EventData::Elecdr03HcalTowerSumEt(UInt_t id)                 {   return  mElecdr03HcalTowerSumEt[id];              }
Double_t        EventData::Elecdr03EcalRecHitSumEt(UInt_t id)                {   return  mElecdr03EcalRecHitSumEt[id];             }
Double_t        EventData::Elecdr03TkSumPt(UInt_t id)                        {   return  mElecdr03TkSumPt[id];                     }
Int_t           EventData::ElecNumOfValidHits(UInt_t id)                     {   return  mElecNumOfValidHits[id];                  }
Int_t           EventData::ElecInnerNumOfHits(UInt_t id)                     {   return  mElecInnerNumOfHits[id];                  }
Double_t        EventData::Elecdist(UInt_t id)                               {   return  mElecdist[id];                            }
Double_t        EventData::Elecdcot(UInt_t id)                               {   return  mElecdcot[id];                            }
Double_t        EventData::ElecNormChi2(UInt_t id)                           {   return  mElecNormChi2[id];                        }
Double_t        EventData::Elecdxy(UInt_t id)                                {   return  mElecdxy[id];                             }
Double_t        EventData::Elecdz(UInt_t id)                                 {   return  mElecdz[id];                              }
Int_t           EventData::ElecdB(UInt_t id)                                 {   return  mElecdB[id];                              }
Int_t           EventData::ElecIsEB(UInt_t id)                               {   return  mElecIsEB[id];                            }
Double_t        EventData::Elecfbrem(UInt_t id)                              {   return  mElecfbrem[id];                           }
Double_t        EventData::ElecDEtaSuTrAtVtx(UInt_t id)                      {   return  mElecDEtaSuTrAtVtx[id];                   }
Double_t        EventData::ElecDPhiSuTrAtVtx(UInt_t id)                      {   return  mElecDPhiSuTrAtVtx[id];                   }
Double_t        EventData::ElecHadronicOverEm(UInt_t id)                     {   return  mElecHadronicOverEm[id];                  }
Double_t        EventData::ElecHcalOverEcal(UInt_t id)                       {   return  mElecHcalOverEcal[id];                    }
Double_t        EventData::ElecSuperClusOverP(UInt_t id)                     {   return  mElecSuperClusOverP[id];                  }
Double_t        EventData::Elecetaeta(UInt_t id)                             {   return  mElecetaeta[id];                          }
Double_t        EventData::Elecietaieta(UInt_t id)                           {   return  mElecietaieta[id];                        }
					
Int_t           EventData::NPFElec()                                         {   return  mNPFElec;                                 }
Int_t           EventData::PFElecCharge(UInt_t id)                           {   return  mPFElecCharge[id];                        }
Int_t           EventData::PFElecIsEB(UInt_t id)                             {   return  mPFElecIsEB[id];                          }
Double_t        EventData::PFElecPassTight(UInt_t id)                        {   return  mPFElecPassTight[id];                     }
Double_t        EventData::PFElecE(UInt_t id)                                {   return  mPFElecE[id];                             }
Double_t        EventData::PFElecPt(UInt_t id)                               {   return  mPFElecPt[id];                            }
Double_t        EventData::PFElecPx(UInt_t id)                               {   return  mPFElecPx[id];                            }
Double_t        EventData::PFElecPy(UInt_t id)                               {   return  mPFElecPy[id];                            }
Double_t        EventData::PFElecPz(UInt_t id)                               {   return  mPFElecPz[id];                            }
Double_t        EventData::PFElecEta(UInt_t id)                              {   return  mPFElecEta[id];                           }
Double_t        EventData::PFElecPhi(UInt_t id)                              {   return  mPFElecPhi[id];                           }
Double_t        EventData::PFElecCharHadIso(UInt_t id)                       {   return  mPFElecCharHadIso[id];                    }
Double_t        EventData::PFElecPhoIso(UInt_t id)                           {   return  mPFElecPhoIso[id];                        }
Double_t        EventData::PFElecNeuHadIso(UInt_t id)                        {   return  mPFElecNeuHadIso[id];                     }
Double_t        EventData::PFElecMva(UInt_t id)                              {   return  mPFElecMva[id];                           }
Double_t        EventData::PFElecdxy(UInt_t id)                              {   return  mPFElecdxy[id];                           }
Double_t        EventData::PFElecdz(UInt_t id)                               {   return  mPFElecdz[id];                            }
Double_t        EventData::PFElecHadOverEm(UInt_t id)                        {   return  mPFElecHadOverEm[id];                     }
Double_t        EventData::PFElecHcalOverEm(UInt_t id)                       {   return  mPFElecHcalOverEm[id];                    }
Double_t        EventData::PFElecSupClusOverP(UInt_t id)                     {   return  mPFElecSupClusOverP[id];                  }
Double_t        EventData::PFElecInnerHits(UInt_t id)                        {   return  mPFElecInnerHits[id];                     }
Double_t        EventData::PFElecConvDist(UInt_t id)                         {   return  mPFElecConvDist[id];                      }
Double_t        EventData::PFElecConvDcot(UInt_t id)                         {   return  mPFElecConvDcot[id];                      }
Double_t        EventData::PFElecDEtaSuTrAtVtx(UInt_t id)                    {   return  mPFElecDEtaSuTrAtVtx[id];                 }
Double_t        EventData::PFElecDPhiSuTrAtVtx(UInt_t id)                    {   return  mPFElecDPhiSuTrAtVtx[id];                 }
Double_t        EventData::PFElecHadronicOverEm(UInt_t id)                   {   return  mPFElecHadronicOverEm[id];                }
Double_t        EventData::PFElecHcalOverEcal(UInt_t id)                     {   return  mPFElecHcalOverEcal[id];                  }
Double_t        EventData::PFElecetaeta(UInt_t id)                           {   return  mPFElecetaeta[id];                        }
Double_t        EventData::PFElecietaieta(UInt_t id)                         {   return  mPFElecietaieta[id];                      }
Int_t           EventData::PFElecIsTight(UInt_t id)                          {   return  mPFElecIsTight[id];                       }
Int_t           EventData::PFElecIsMedium(UInt_t id)                         {   return  mPFElecIsMedium[id];                      }
Int_t           EventData::PFElecIsLoose(UInt_t id)                          {   return  mPFElecIsLoose[id];                       }
Int_t           EventData::PFElecIsVeto(UInt_t id)                           {   return  mPFElecIsVeto[id];                        }
Double_t        EventData::PFElecEffArea(UInt_t id)                          {   return  mPFElecEffArea[id];                       }

Int_t           EventData::NTau()                                                       {   return  mNTau;                                                 }            
Double_t        EventData::TauE(UInt_t id)                                              {   return  mTauE[id];                                             }            
Double_t        EventData::TauPt(UInt_t id)                                             {   return  mTauPt[id];                                            }            
Double_t        EventData::TauPx(UInt_t id)                                             {   return  mTauPx[id];                                            }
Double_t        EventData::TauPy(UInt_t id)                                             {   return  mTauPy[id];                                            }
Double_t        EventData::TauPz(UInt_t id)                                             {   return  mTauPz[id];                                            }
Double_t        EventData::TauEta(UInt_t id)                                            {   return  mTauEta[id];                                           }
Double_t        EventData::TauPhi(UInt_t id)                                            {   return  mTauPhi[id];                                           }
Int_t           EventData::TauCharge(UInt_t id)                                         {   return  mTauCharge[id];                                        }
Double_t        EventData::TauEtaEtaMoment(UInt_t id)                                   {   return  mTauEtaEtaMoment[id];                                  }
Double_t        EventData::TauPhiPhiMoment(UInt_t id)                                   {   return  mTauPhiPhiMoment[id];                                  }
Double_t        EventData::TauEtaPhiMoment(UInt_t id)                                   {   return  mTauEtaPhiMoment[id];                                  }
Double_t        EventData::TauLeadPFChargedHadrCandsignedSipt(UInt_t id)                {   return  mTauLeadPFChargedHadrCandsignedSipt[id];               }
Double_t        EventData::TauIsoPFChargedHadrCandsPtSum(UInt_t id)                     {   return  mTauIsoPFChargedHadrCandsPtSum[id];                    }
Double_t        EventData::TauIsoPFGammaCandsEtSum(UInt_t id)                           {   return  mTauIsoPFGammaCandsEtSum[id];                          }
Double_t        EventData::TauMaximumHCALPFClusterEt(UInt_t id)                         {   return  mTauMaximumHCALPFClusterEt[id];                        }
Double_t        EventData::TauEmFraction(UInt_t id)                                     {   return  mTauEmFraction[id];                                    }
Double_t        EventData::TauHcalTotOverPLead(UInt_t id)                               {   return  mTauHcalTotOverPLead[id];                              }
Double_t        EventData::TauHcalMaxOverPLead(UInt_t id)                               {   return  mTauHcalMaxOverPLead[id];                              }
Double_t        EventData::TauHcal3x3OverPLead(UInt_t id)                               {   return  mTauHcal3x3OverPLead[id];                              }
Double_t        EventData::TauEcalStripSumEOverPLead(UInt_t id)                         {   return  mTauEcalStripSumEOverPLead[id];                        }
Double_t        EventData::TauBremsRecoveryEOverPLead(UInt_t id)                        {   return  mTauBremsRecoveryEOverPLead[id];                       }
Double_t        EventData::TauElectronPreIDOutput(UInt_t id)                            {   return  mTauElectronPreIDOutput[id];                           }
Double_t        EventData::TauElectronPreIDDecision(UInt_t id)                          {   return  mTauElectronPreIDDecision[id];                         }
Double_t        EventData::TauCaloComp(UInt_t id)                                       {   return  mTauCaloComp[id];                                      }
Double_t        EventData::TauSegComp(UInt_t id)                                        {   return  mTauSegComp[id];                                       }
Double_t        EventData::TauMuonDecision(UInt_t id)                                   {   return  mTauMuonDecision[id];                                  }
Double_t        EventData::TausignalPFChargedHadrCands(UInt_t id)                       {   return  mTausignalPFChargedHadrCands[id];                      }
Double_t        EventData::TausignalPFGammaCands(UInt_t id)                             {   return  mTausignalPFGammaCands[id];                            }
Double_t        EventData::TauDisAgainstElectronDeadECAL(UInt_t id)                     {   return  mTauDisAgainstElectronDeadECAL[id];                    }
Double_t        EventData::TauDisAgainstElectronLoose(UInt_t id)                        {   return  mTauDisAgainstElectronLoose[id];                       }
Double_t        EventData::TauDisAgainstElectronLooseMVA2(UInt_t id)                    {   return  mTauDisAgainstElectronLooseMVA2[id];                   }
Double_t        EventData::TauDisAgainstElectronLooseMVA3(UInt_t id)                    {   return  mTauDisAgainstElectronLooseMVA3[id];                   }
Double_t        EventData::TauDisAgainstElectronMVA2category(UInt_t id)                 {   return  mTauDisAgainstElectronMVA2category[id];                }
Double_t        EventData::TauDisAgainstElectronMVA2raw(UInt_t id)                      {   return  mTauDisAgainstElectronMVA2raw[id];                     }
Double_t        EventData::TauDisAgainstElectronMVA3category(UInt_t id)                 {   return  mTauDisAgainstElectronMVA3category[id];                }
Double_t        EventData::TauDisAgainstElectronMVA3raw(UInt_t id)                      {   return  mTauDisAgainstElectronMVA3raw[id];                     }
Double_t        EventData::TauDisAgainstElectronMVA(UInt_t id)                          {   return  mTauDisAgainstElectronMVA[id];                         }
Double_t        EventData::TauDisAgainstElectronMedium(UInt_t id)                       {   return  mTauDisAgainstElectronMedium[id];                      }
Double_t        EventData::TauDisAgainstElectronMediumMVA2(UInt_t id)                   {   return  mTauDisAgainstElectronMediumMVA2[id];                  }
Double_t        EventData::TauDisAgainstElectronMediumMVA3(UInt_t id)                   {   return  mTauDisAgainstElectronMediumMVA3[id];                  }
Double_t        EventData::TauDisAgainstElectronTight(UInt_t id)                        {   return  mTauDisAgainstElectronTight[id];                       }
Double_t        EventData::TauDisAgainstElectronTightMVA2(UInt_t id)                    {   return  mTauDisAgainstElectronTightMVA2[id];                   }
Double_t        EventData::TauDisAgainstElectronTightMVA3(UInt_t id)                    {   return  mTauDisAgainstElectronTightMVA3[id];                   }
Double_t        EventData::TauDisAgainstElectronVLooseMVA2(UInt_t id)                   {   return  mTauDisAgainstElectronVLooseMVA2[id];                  }
Double_t        EventData::TauDisAgainstElectronVTightMVA3(UInt_t id)                   {   return  mTauDisAgainstElectronVTightMVA3[id];                  }
Double_t        EventData::TauDisAgainstMuonLoose2(UInt_t id)                           {   return  mTauDisAgainstMuonLoose2[id];                          }
Double_t        EventData::TauDisAgainstMuonLoose(UInt_t id)                            {   return  mTauDisAgainstMuonLoose[id];                           }
Double_t        EventData::TauDisAgainstMuonMedium2(UInt_t id)                          {   return  mTauDisAgainstMuonMedium2[id];                         }
Double_t        EventData::TauDisAgainstMuonMedium(UInt_t id)                           {   return  mTauDisAgainstMuonMedium[id];                          }
Double_t        EventData::TauDisAgainstMuonTight2(UInt_t id)                           {   return  mTauDisAgainstMuonTight2[id];                          }
Double_t        EventData::TauDisAgainstMuonTight(UInt_t id)                            {   return  mTauDisAgainstMuonTight[id];                           }            
Double_t        EventData::TauDisByCombinedIsolationDeltaBetaCorrRaw3Hits(UInt_t id)    {   return  mTauDisByCombinedIsolationDeltaBetaCorrRaw3Hits[id];   }
Double_t        EventData::TauDisByCombinedIsolationDeltaBetaCorrRaw(UInt_t id)         {   return  mTauDisByCombinedIsolationDeltaBetaCorrRaw[id];        }
Double_t        EventData::TauDisByIsolationMVA2raw(UInt_t id)                          {   return  mTauDisByIsolationMVA2raw[id];                         }
Double_t        EventData::TauDisByIsolationMVAraw(UInt_t id)                           {   return  mTauDisByIsolationMVAraw[id];                          }
Double_t        EventData::TauDisByLooseCombinedIsolationDeltaBetaCorr3Hits(UInt_t id)  {   return  mTauDisByLooseCombinedIsolationDeltaBetaCorr3Hits[id]; }
Double_t        EventData::TauDisByLooseCombinedIsolationDeltaBetaCorr(UInt_t id)       {   return  mTauDisByLooseCombinedIsolationDeltaBetaCorr[id];      }
Double_t        EventData::TauDisByLooseIsolationMVA2(UInt_t id)                        {   return  mTauDisByLooseIsolationMVA2[id];                       }
Double_t        EventData::TauDisByLooseIsolationMVA(UInt_t id)                         {   return  mTauDisByLooseIsolationMVA[id];                        }
Double_t        EventData::TauDisByMediumCombinedIsolationDeltaBetaCorr3Hits(UInt_t id) {   return  mTauDisByMediumCombinedIsolationDeltaBetaCorr3Hits[id];}
Double_t        EventData::TauDisByMediumCombinedIsolationDeltaBetaCorr(UInt_t id)      {   return  mTauDisByMediumCombinedIsolationDeltaBetaCorr[id];     }
Double_t        EventData::TauDisByMediumIsolationMVA2(UInt_t id)                       {   return  mTauDisByMediumIsolationMVA2[id];                      }
Double_t        EventData::TauDisByMediumIsolationMVA(UInt_t id)                        {   return  mTauDisByMediumIsolationMVA[id];                       }
Double_t        EventData::TauDisByTightCombinedIsolationDeltaBetaCorr3Hits(UInt_t id)  {   return  mTauDisByTightCombinedIsolationDeltaBetaCorr3Hits[id]; }
Double_t        EventData::TauDisByTightCombinedIsolationDeltaBetaCorr(UInt_t id)       {   return  mTauDisByTightCombinedIsolationDeltaBetaCorr[id];      }
Double_t        EventData::TauDisByTightIsolationMVA2(UInt_t id)                        {   return  mTauDisByTightIsolationMVA2[id];                       }
Double_t        EventData::TauDisByTightIsolationMVA(UInt_t id)                         {   return  mTauDisByTightIsolationMVA[id];                        }
Double_t        EventData::TauDisByVLooseCombinedIsolationDeltaBetaCorr(UInt_t id)      {   return  mTauDisByVLooseCombinedIsolationDeltaBetaCorr[id];     }
Double_t        EventData::TauDisDecayModeFinding(UInt_t id)                            {   return  mTauDisDecayModeFinding[id];                           }
Double_t        EventData::TauJetPt(UInt_t id)                                          {   return  mTauJetPt[id];                                         }
Double_t        EventData::TauJetEta(UInt_t id)                                         {   return  mTauJetEta[id];                                        }
Double_t        EventData::TauJetPhi(UInt_t id)                                         {   return  mTauJetPhi[id];                                        }

Int_t           EventData::NPFTau()                                                     {   return  mNPFTau;                                               }
Double_t        EventData::PFTauE(UInt_t id)                                            {   return  mPFTauE[id];                                           }
Double_t        EventData::PFTauPt(UInt_t id)                                           {   return  mPFTauPt[id];                                          }
Double_t        EventData::PFTauPx(UInt_t id)                                           {   return  mPFTauPx[id];                                          }
Double_t        EventData::PFTauPy(UInt_t id)                                           {   return  mPFTauPy[id];                                          }
Double_t        EventData::PFTauPz(UInt_t id)                                           {   return  mPFTauPz[id];                                          }
Double_t        EventData::PFTauEta(UInt_t id)                                          {   return  mPFTauEta[id];                                         }
Double_t        EventData::PFTauPhi(UInt_t id)                                          {   return  mPFTauPhi[id];                                         }
Int_t           EventData::PFTauCharge(UInt_t id)                                       {   return  mPFTauCharge[id];                                      }
Double_t        EventData::PFTauEtaEtaMoment(UInt_t id)                                 {   return  mPFTauEtaEtaMoment[id];                                }
Double_t        EventData::PFTauPhiPhiMoment(UInt_t id)                                 {   return  mPFTauPhiPhiMoment[id];                                }
Double_t        EventData::PFTauEtaPhiMoment(UInt_t id)                                 {   return  mPFTauEtaPhiMoment[id];                                }
Double_t        EventData::PFTauLeadPFChargedHadrCandsignedSipt(UInt_t id)              {   return  mPFTauLeadPFChargedHadrCandsignedSipt[id];             }
Double_t        EventData::PFTauIsoPFChargedHadrCandsPtSum(UInt_t id)                   {   return  mPFTauIsoPFChargedHadrCandsPtSum[id];                  }
Double_t        EventData::PFTauIsoPFGammaCandsEtSum(UInt_t id)                         {   return  mPFTauIsoPFGammaCandsEtSum[id];                        }
Double_t        EventData::PFTauMaximumHCALPFClusterEt(UInt_t id)                       {   return  mPFTauMaximumHCALPFClusterEt[id];                      }
Double_t        EventData::PFTauEmFraction(UInt_t id)                                   {   return  mPFTauEmFraction[id];                                  }
Double_t        EventData::PFTauHcalTotOverPLead(UInt_t id)                             {   return  mPFTauHcalTotOverPLead[id];                            }
Double_t        EventData::PFTauHcalMaxOverPLead(UInt_t id)                             {   return  mPFTauHcalMaxOverPLead[id];                            }
Double_t        EventData::PFTauHcal3x3OverPLead(UInt_t id)                             {   return  mPFTauHcal3x3OverPLead[id];                            }
Double_t        EventData::PFTauEcalStripSumEOverPLead(UInt_t id)                       {   return  mPFTauEcalStripSumEOverPLead[id];                      }
Double_t        EventData::PFTauBremsRecoveryEOverPLead(UInt_t id)                      {   return  mPFTauBremsRecoveryEOverPLead[id];                     }
Double_t        EventData::PFTauElectronPreIDOutput(UInt_t id)                          {   return  mPFTauElectronPreIDOutput[id];                         }
Double_t        EventData::PFTauElectronPreIDDecision(UInt_t id)                        {   return  mPFTauElectronPreIDDecision[id];                       }
Double_t        EventData::PFTauCaloComp(UInt_t id)                                     {   return  mPFTauCaloComp[id];                                    }
Double_t        EventData::PFTauSegComp(UInt_t id)                                      {   return  mPFTauSegComp[id];                                     }
Double_t        EventData::PFTauMuonDecision(UInt_t id)                                 {   return  mPFTauMuonDecision[id];                                }
Double_t        EventData::PFTausignalPFChargedHadrCands(UInt_t id)                     {   return  mPFTausignalPFChargedHadrCands[id];                    }
Double_t        EventData::PFTausignalPFGammaCands(UInt_t id)                           {   return  mPFTausignalPFGammaCands[id];                          }
Double_t        EventData::PFTauDisAgainstElectronDeadECAL(UInt_t id)                   {   return  mPFTauDisAgainstElectronDeadECAL[id];                  }
Double_t        EventData::PFTauDisAgainstElectronLoose(UInt_t id)                      {   return  mPFTauDisAgainstElectronLoose[id];                     }
Double_t        EventData::PFTauDisAgainstElectronLooseMVA2(UInt_t id)                  {   return  mPFTauDisAgainstElectronLooseMVA2[id];                 }
Double_t        EventData::PFTauDisAgainstElectronLooseMVA3(UInt_t id)                  {   return  mPFTauDisAgainstElectronLooseMVA3[id];                 }
Double_t        EventData::PFTauDisAgainstElectronMVA2category(UInt_t id)               {   return  mPFTauDisAgainstElectronMVA2category[id];              }
Double_t        EventData::PFTauDisAgainstElectronMVA2raw(UInt_t id)                    {   return  mPFTauDisAgainstElectronMVA2raw[id];                   }
Double_t        EventData::PFTauDisAgainstElectronMVA3category(UInt_t id)               {   return  mPFTauDisAgainstElectronMVA3category[id];              }
Double_t        EventData::PFTauDisAgainstElectronMVA3raw(UInt_t id)                    {   return  mPFTauDisAgainstElectronMVA3raw[id];                   }
Double_t        EventData::PFTauDisAgainstElectronMVA(UInt_t id)                        {   return  mPFTauDisAgainstElectronMVA[id];                       }
Double_t        EventData::PFTauDisAgainstElectronMedium(UInt_t id)                     {   return  mPFTauDisAgainstElectronMedium[id];                    }
Double_t        EventData::PFTauDisAgainstElectronMediumMVA2(UInt_t id)                 {   return  mPFTauDisAgainstElectronMediumMVA2[id];                }
Double_t        EventData::PFTauDisAgainstElectronMediumMVA3(UInt_t id)                 {   return  mPFTauDisAgainstElectronMediumMVA3[id];                }
Double_t        EventData::PFTauDisAgainstElectronTight(UInt_t id)                      {   return  mPFTauDisAgainstElectronTight[id];                     }
Double_t        EventData::PFTauDisAgainstElectronTightMVA2(UInt_t id)                  {   return  mPFTauDisAgainstElectronTightMVA2[id];                 }
Double_t        EventData::PFTauDisAgainstElectronTightMVA3(UInt_t id)                  {   return  mPFTauDisAgainstElectronTightMVA3[id];                 }
Double_t        EventData::PFTauDisAgainstElectronVLooseMVA2(UInt_t id)                 {   return  mPFTauDisAgainstElectronVLooseMVA2[id];                }
Double_t        EventData::PFTauDisAgainstElectronVTightMVA3(UInt_t id)                 {   return  mPFTauDisAgainstElectronVTightMVA3[id];                }
Double_t        EventData::PFTauDisAgainstMuonLoose2(UInt_t id)                         {   return  mPFTauDisAgainstMuonLoose2[id];                        }
Double_t        EventData::PFTauDisAgainstMuonLoose(UInt_t id)                          {   return  mPFTauDisAgainstMuonLoose[id];                         }
Double_t        EventData::PFTauDisAgainstMuonMedium2(UInt_t id)                        {   return  mPFTauDisAgainstMuonMedium2[id];                       }
Double_t        EventData::PFTauDisAgainstMuonMedium(UInt_t id)                         {   return  mPFTauDisAgainstMuonMedium[id];                        }
Double_t        EventData::PFTauDisAgainstMuonTight2(UInt_t id)                         {   return  mPFTauDisAgainstMuonTight2[id];                        }
Double_t        EventData::PFTauDisAgainstMuonTight(UInt_t id)                          {   return  mPFTauDisAgainstMuonTight[id];                         }
Double_t        EventData::PFTauDisByCombinedIsolationDeltaBetaCorrRaw3Hits(UInt_t id)  {   return  mPFTauDisByCombinedIsolationDeltaBetaCorrRaw3Hits[id]; }
Double_t        EventData::PFTauDisByCombinedIsolationDeltaBetaCorrRaw(UInt_t id)       {   return  mPFTauDisByCombinedIsolationDeltaBetaCorrRaw[id];      }
Double_t        EventData::PFTauDisByIsolationMVA2raw(UInt_t id)                        {   return  mPFTauDisByIsolationMVA2raw[id];                       }
Double_t        EventData::PFTauDisByIsolationMVAraw(UInt_t id)                         {   return  mPFTauDisByIsolationMVAraw[id];                        }
Double_t        EventData::PFTauDisByLooseCombinedIsolationDeltaBetaCorr3Hits(UInt_t id){   return  mPFTauDisByLooseCombinedIsolationDeltaBetaCorr3Hits[id];}
Double_t        EventData::PFTauDisByLooseCombinedIsolationDeltaBetaCorr(UInt_t id)     {   return  mPFTauDisByLooseCombinedIsolationDeltaBetaCorr[id];    }
Double_t        EventData::PFTauDisByLooseIsolationDeltaBetaCorr(UInt_t id)             {   return  mPFTauDisByLooseIsolationDeltaBetaCorr[id];            }
Double_t        EventData::PFTauDisByLooseIsolation(UInt_t id)                          {   return  mPFTauDisByLooseIsolation[id];                         }
Double_t        EventData::PFTauDisByLooseIsolationMVA2(UInt_t id)                      {   return  mPFTauDisByLooseIsolationMVA2[id];                     }
Double_t        EventData::PFTauDisByLooseIsolationMVA(UInt_t id)                       {   return  mPFTauDisByLooseIsolationMVA[id];                      }
Double_t        EventData::PFTauDisByMediumCombinedIsolationDeltaBetaCorr3Hits(UInt_t id){  return  mPFTauDisByMediumCombinedIsolationDeltaBetaCorr3Hits[id];}
Double_t        EventData::PFTauDisByMediumCombinedIsolationDeltaBetaCorr(UInt_t id)    {   return  mPFTauDisByMediumCombinedIsolationDeltaBetaCorr[id];   }
Double_t        EventData::PFTauDisByMediumIsolationDeltaBetaCorr(UInt_t id)            {   return  mPFTauDisByMediumIsolationDeltaBetaCorr[id];           }
Double_t        EventData::PFTauDisByMediumIsolation(UInt_t id)                         {   return  mPFTauDisByMediumIsolation[id];                        }
Double_t        EventData::PFTauDisByMediumIsolationMVA2(UInt_t id)                     {   return  mPFTauDisByMediumIsolationMVA2[id];                    }
Double_t        EventData::PFTauDisByMediumIsolationMVA(UInt_t id)                      {   return  mPFTauDisByMediumIsolationMVA[id];                     }
Double_t        EventData::PFTauDisByTightCombinedIsolationDeltaBetaCorr3Hits(UInt_t id){   return  mPFTauDisByTightCombinedIsolationDeltaBetaCorr3Hits[id]; }
Double_t        EventData::PFTauDisByTightCombinedIsolationDeltaBetaCorr(UInt_t id)     {   return  mPFTauDisByTightCombinedIsolationDeltaBetaCorr[id];      }
Double_t        EventData::PFTauDisByTightIsolationDeltaBetaCorr(UInt_t id)             {   return  mPFTauDisByTightIsolationDeltaBetaCorr[id];              }
Double_t        EventData::PFTauDisByTightIsolation(UInt_t id)                          {   return  mPFTauDisByTightIsolation[id];                           }
Double_t        EventData::PFTauDisByTightIsolationMVA2(UInt_t id)                      {   return  mPFTauDisByTightIsolationMVA2[id];                       }
Double_t        EventData::PFTauDisByTightIsolationMVA(UInt_t id)                       {   return  mPFTauDisByTightIsolationMVA[id];                        }
Double_t        EventData::PFTauDisByVLooseCombinedIsolationDeltaBetaCorr(UInt_t id)    {   return  mPFTauDisByVLooseCombinedIsolationDeltaBetaCorr[id];     }
Double_t        EventData::PFTauDisByVLooseIsolationDeltaBetaCorr(UInt_t id)            {   return  mPFTauDisByVLooseIsolationDeltaBetaCorr[id];             }
Double_t        EventData::PFTauDisByVLooseIsolation(UInt_t id)                         {   return  mPFTauDisByVLooseIsolation[id];                          }
Double_t        EventData::PFTauDisDecayModeFinding(UInt_t id)                          {   return  mPFTauDisDecayModeFinding[id];                           }
Double_t        EventData::PFTauJetPt(UInt_t id)                                        {   return  mPFTauJetPt[id];                                         }
Double_t        EventData::PFTauJetEta(UInt_t id)                                       {   return  mPFTauJetEta[id];                                        }
Double_t        EventData::PFTauJetPhi(UInt_t id)                                       {   return  mPFTauJetPhi[id];                                        }

Int_t           EventData::WTauDecayMode()                                   {   return mWTauDecayMode;         }
Int_t           EventData::WTauN()                                           {   return mWTauN;                 }
Int_t           EventData::WTauDecayId(UInt_t id)                            {   return mWTauDecayId[id];       }
Double_t        EventData::WTauDecayPt(UInt_t id)                            {   return mWTauDecayPt[id];       }
Double_t        EventData::WTauDecayEta(UInt_t id)                           {   return mWTauDecayEta[id];      }
Double_t        EventData::WTauDecayPhi(UInt_t id)                           {   return mWTauDecayPhi[id];      }
Double_t        EventData::WTauDecayMass(UInt_t id)                          {   return mWTauDecayMass[id];     }
						
Int_t           EventData::NPhot()                                           {   return  mNPhot;                                   }
Double_t        EventData::PhotE(UInt_t id)                                  {   return  mPhotE[id];                               }
Double_t        EventData::PhotPt(UInt_t id)                                 {   return  mPhotPt[id];                              }
Double_t        EventData::PhotPx(UInt_t id)                                 {   return  mPhotPx[id];                              }
Double_t        EventData::PhotPy(UInt_t id)                                 {   return  mPhotPy[id];                              }
Double_t        EventData::PhotPz(UInt_t id)                                 {   return  mPhotPz[id];                              }
Double_t        EventData::PhotEta(UInt_t id)                                {   return  mPhotEta[id];                             }
Double_t        EventData::PhotPhi(UInt_t id)                                {   return  mPhotPhi[id];                             }
Double_t        EventData::PhotE1x5(UInt_t id)                               {   return  mPhotE1x5[id];                            }
Double_t        EventData::PhotE2x5(UInt_t id)                               {   return  mPhotE2x5[id];                            }
Double_t        EventData::PhotE5x5(UInt_t id)                               {   return  mPhotE5x5[id];                            }
Double_t        EventData::PhotSigEta(UInt_t id)                             {   return  mPhotSigEta[id];                          }
Double_t        EventData::PhotSigPhi(UInt_t id)                             {   return  mPhotSigPhi[id];                          }
Double_t        EventData::PhotEcalIso04(UInt_t id)                          {   return  mPhotEcalIso04[id];                       }
Double_t        EventData::PhotHcalIso04(UInt_t id)                          {   return  mPhotHcalIso04[id];                       }
Double_t        EventData::PhotTrackIso04(UInt_t id)                         {   return  mPhotTrackIso04[id];                      }
Double_t        EventData::PhotHasPixSeed(UInt_t id)                         {   return  mPhotHasPixSeed[id];                      }
Double_t        EventData::PhotIsPhot(UInt_t id)                             {   return  mPhotIsPhot[id];                          }
						
Int_t           EventData::NPV()                                             {   return  mNPV;                                     }
Double_t        EventData::PVx(UInt_t id)                                    {   return  mPVx[id];                                 }
Double_t        EventData::PVy(UInt_t id)                                    {   return  mPVy[id];                                 }
Double_t        EventData::PVz(UInt_t id)                                    {   return  mPVz[id];                                 }
Double_t        EventData::PVchi2(UInt_t id)                                 {   return  mPVchi2[id];                              }
Double_t        EventData::PVndof(UInt_t id)                                 {   return  mPVndof[id];                              }
Int_t           EventData::PVntracks(UInt_t id)                              {   return  mPVntracks[id];                           }
						
Int_t           EventData::nHLT()                                            {   return  mnHLT;                                    }
Int_t           EventData::HLTArray(UInt_t id)                               {   return  mHLTArray[id];                            }
Int_t           EventData::HLTArray2(UInt_t id)                              {   return  mHLTArray2[id];                           }
string          EventData::HLTNames()                                        {   return  mHLTNames;                                }
Int_t           EventData::HLTPreScale2(UInt_t id)                           {   return  mHLTPreScale2[id];                        }
Int_t           EventData::nL1()                                             {   return  mnL1;                                     }
Int_t           EventData::L1Array(UInt_t id)                                {   return  mL1Array[id];                             }
Int_t           EventData::nL1T()                                            {   return  mnL1T;                                    }
Int_t           EventData::L1TArray(UInt_t id)                               {   return  mL1TArray[id];                            }
							
Int_t           EventData::BeamHaloTight()                                   {   return  mBeamHaloTight;                           }
Int_t           EventData::BeamHaloLoose()                                   {   return  mBeamHaloLoose;                           }

Int_t           EventData::TIV_N()                                           {   return  mTIV_N;                                   }
Float_t         EventData::TIV(UInt_t id)                                    {   return  mTIV[id];                                 }
Float_t         EventData::TIV_pt(UInt_t id)                                 {   return  mTIV_pt[id];                              }
Float_t         EventData::TIV_px(UInt_t id)                                 {   return  mTIV_px[id];                              }
Float_t         EventData::TIV_py(UInt_t id)                                 {   return  mTIV_py[id];                              }
Float_t         EventData::TIV_pz(UInt_t id)                                 {   return  mTIV_pz[id];                              }
Float_t         EventData::TIV_phi(UInt_t id)                                {   return  mTIV_phi[id];                             }
Float_t         EventData::TIV_eta(UInt_t id)                                {   return  mTIV_eta[id];                             }
Float_t         EventData::TIV_dsz(UInt_t id)                                {   return  mTIV_dsz[id];                             }
Float_t         EventData::TIV_dxy(UInt_t id)                                {   return  mTIV_dxy[id];                             }
Float_t         EventData::TIV_d0(UInt_t id)                                 {   return  mTIV_d0[id];                              }
Float_t         EventData::TIV_dz(UInt_t id)                                 {   return  mTIV_dz[id];                              }
Float_t         EventData::TIV_dsz_corr(UInt_t id)                           {   return  mTIV_dsz_corr[id];                        }
Float_t         EventData::TIV_dxy_corr(UInt_t id)                           {   return  mTIV_dxy_corr[id];                        }
Float_t         EventData::TIV_d0_corr(UInt_t id)                            {   return  mTIV_d0_corr[id];                         }
Float_t         EventData::TIV_dz_corr(UInt_t id)                            {   return  mTIV_dz_corr[id];                         }
Float_t         EventData::TIV_dR(UInt_t id)                                 {   return  mTIV_dR[id];                              }
Int_t           EventData::TIV_lead(UInt_t id)                               {   return  mTIV_lead[id];                            }
Float_t         EventData::LowTIV()                                          {   return  mLowTIV;                                  }

Int_t           EventData::NGenPar()                                         {    return  mNGenPar;                                }
Int_t           EventData::GenParId    (UInt_t id)                           {    return  mGenParId    [id];                       }
Int_t           EventData::GenParStatus(UInt_t id)                           {    return  mGenParStatus[id];                       }
Double_t        EventData::GenParE     (UInt_t id)                           {    return  mGenParE     [id];                       }
Double_t        EventData::GenParPx    (UInt_t id)                           {    return  mGenParPx    [id];                       }
Double_t        EventData::GenParPy    (UInt_t id)                           {    return  mGenParPy    [id];                       }
Double_t        EventData::GenParPz    (UInt_t id)                           {    return  mGenParPz    [id];                       }
Double_t        EventData::GenParEta   (UInt_t id)                           {    return  mGenParEta   [id];                       }
Double_t        EventData::GenParPhi   (UInt_t id)                           {    return  mGenParPhi   [id];                       }
Int_t           EventData::GenParCharge(UInt_t id)                           {    return  mGenParCharge[id];                       }
Double_t        EventData::GenParPt    (UInt_t id)                           {    return  mGenParPt    [id];                       }
Double_t        EventData::GenParMass  (UInt_t id)                           {    return  mGenParMass  [id];                       }
Int_t           EventData::GenParMother1(UInt_t id)                          {    return  mGenParMother1[id];                      }
Int_t           EventData::GenParMother2(UInt_t id)                          {    return  mGenParMother2[id];                      }
Int_t           EventData::GenParDoughterOf(UInt_t id)                       {    return  mGenParDoughterOf[id];                   }

Double_t        EventData::GenAK4JetE         (UInt_t id)                    {    return mGenAK4JetE          [id];                } 
Double_t        EventData::GenAK4JetPt        (UInt_t id)                    {    return mGenAK4JetPt         [id];                } 
Double_t        EventData::GenAK4JetPx        (UInt_t id)                    {    return mGenAK4JetPx         [id];                } 
Double_t        EventData::GenAK4JetPy        (UInt_t id)                    {    return mGenAK4JetPy         [id];                } 
Double_t        EventData::GenAK4JetPz        (UInt_t id)                    {    return mGenAK4JetPz         [id];                } 
Double_t        EventData::GenAK4JetEta       (UInt_t id)                    {    return mGenAK4JetEta        [id];                } 
Double_t        EventData::GenAK4JetPhi       (UInt_t id)                    {    return mGenAK4JetPhi        [id];                } 
Double_t        EventData::GenAK4JetEmEnergy  (UInt_t id)                    {    return mGenAK4JetEmEnergy   [id];                } 
Double_t        EventData::GenAK4JetHadEnergy (UInt_t id)                    {    return mGenAK4JetHadEnergy  [id];                } 

Double_t         EventData::PDFGenScale()                                    {   return  mPDFGenScale;                            }
Double_t         EventData::PDFx1()                                          {   return  mPDFx1;                                  }
Double_t         EventData::PDFx2()                                          {   return  mPDFx2;                                  }
Int_t            EventData::PDFf1()                                          {   return  mPDFf1;                                  }
Int_t            EventData::PDFf2()                                          {   return  mPDFf2;                                  }
Double_t         EventData::PDFscale()                                       {   return  mPDFscale;                               }
Double_t         EventData::PDFpdf1()                                        {   return  mPDFpdf1;                                }
Double_t         EventData::PDFpdf2()                                        {   return  mPDFpdf2;                                }



///-----------------------------------------------------------------------------------------------------------------------------------------
const std::string & EventData::DataSet()   { return mDataSet; }
///-----------------------------------------------------------------------------------------------------------------------------------------


