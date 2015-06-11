//////////////////////////////////////////////////////////////////////
//                                                                  //
//          Author:  Mehmet Vergili   vergili@cern.ch               //
//                                                                  //
//////////////////////////////////////////////////////////////////////
#include "Operation.h"
#include "Histogram01.h"
#include <iostream>
#include <fstream>

#include <TH1D.h>
#include <math.h>

#include "TStyle.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TLegend.h>
#include "TLorentzVector.h"

#include "TTree.h"
#include "TDirectory.h"
#include "TKey.h"
#include "TH1F.h"
#include "TF1.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TProfile.h"
#include "Constants.h"
#include <memory>
#include <TLorentzVector.h>

#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/deltaPhi.h"

using namespace std;
using namespace Operation;
using namespace Constants;

namespace Histogram01 
{
  ///----------------HLT Histograms  Defination--------------------------------------------------------------------------------
  hHLTEff::hHLTEff(const std::string & fileName):
    mFileName(fileName)
  {
    fileOut = new TFile(mFileName.c_str(),"recreate");
    //
    histo1D["MET_80"]       = new TH1D("MET_80"      ,"MET80"     , 50, 0, 1000);
    histo1D["MET_All"]      = new TH1D("MET_All"     ,"MET"       , 50, 0, 1000);
    histo1D["Jet1Pt_80"]    = new TH1D("Jet1Pt_80"   ,"Jet1Pt80"  , 50, 0, 1000);
    histo1D["Jet1Pt_All"]   = new TH1D("Jet1Pt_All"  ,"Jet1Pt"    , 50, 0, 1000);
    //
    histo1D["MET_80_Eff"]       = new TH1D("MET_80_Eff"      ,"MET80"     , 50, 0, 1000);
    histo1D["Jet1Pt_80_Eff"]    = new TH1D("Jet1Pt_80_Eff"   ,"Jet1Pt80"  , 50, 0, 1000);
  }
  
  /// ---------------HLT Eff Histograms Filling----------------------------------------------------------------------------
  bool hHLTEff::Process(EventData & ev){
    int t = ev.MetType();
    //int njets = JetNumber(ev);
    int ixjet1= JetIndex(0, ev);
    //int ixjet2= JetIndex(1, ev);	
    double w= ev.Weight();
    if(ev.run() < 1000000000){
      int flg_trg80=0;
      string strtrg = ev.HLTNames();
      if(strtrg.find("HLT_MET120_HBHENoiseCleaned")!=string::npos) flg_trg80=1;
      if(strtrg.find("HLT_MonoCentralPFJet80*")!=string::npos) flg_trg80=1;
      if(flg_trg80==1){
	histo1D["Jet1Pt_80"]->Fill( ev.PFAK5JetPtCor(ixjet1) ,w );
	histo1D["MET_80"]->Fill( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ),w );
      }
      histo1D["Jet1Pt_All"]->Fill( ev.PFAK5JetPtCor(ixjet1),w );
      histo1D["MET_All"]->Fill( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) ,w );
    }
    return true;
  }
  
  std::ostream& hHLTEff::Description(std::ostream &ostrm){
    ostrm << "  HLTEff (output in " << mFileName << "):";
    return ostrm;
  }
  
  hHLTEff::~hHLTEff(){  
    histo1D["MET_80_Eff"]->Divide( histo1D["MET_80"], histo1D["MET_All"] , 1.0, 1.0 );
    histo1D["Jet1Pt_80_Eff"]->Divide( histo1D["Jet1Pt_80"], histo1D["Jet1Pt_All"] , 1.0, 1.0 ); 
    fileOut->Write();
    delete fileOut;
  }
  
  ///===========================================================================================================
  ///----------------Data MC Matching Histograms Defination -------------------------------------------------
  hDataMcMatching::hDataMcMatching(const std::string & fileName):
    mFileName(fileName)
  {
    fileOut = new TFile(mFileName.c_str(),"recreate");

    ///---------------------- 
    /// Primary vertices
    histo1D["NPV"]                        = new TH1D("NPV"            , "NPV "                , 70, 0, 70);
    histo1D["PVx"]                        = new TH1D("PVx"            , "PV x"                , 100, -1, 1);
    histo1D["PVy"]                        = new TH1D("PVy"            , "PV y"                , 200, -2, 2);
    histo1D["PVz"]                        = new TH1D("PVz"            , "PV z"                , 1000, -10, 10);
    histo1D["PVR"]                        = new TH1D("PVR"            , "PV R"                , 300, 0, 30);
    histo1D["PVndof"]                     = new TH1D("PVndof"         , "PV ndof"             , 300, 0, 30);
    histo1D["PVchi2"]                     = new TH1D("PVchi2"         , "PV chi2"             , 300, 0, 30);
    histo1D["PVntracks"]                  = new TH1D("PVntracks"      , "PV nTracks"          , 70, 0, 70);
    
    ///---------------------- 
    /// Jet1
    histo1D["Jet1Pt"]                     = new TH1D("Jet1Pt"         , "Jet1Pt "             , 40, 0, 1000);
    histo1D["Jet1PtThrs"]                 = new TH1D("Jet1PtThrs"     , "Jet1Pt "             , 40, 0, 1000);
    histo1D["Jet1Emf"]                    = new TH1D("Jet1Emf"        , "Jet1Emf"             , 300,-1, 2);
    histo1D["Jet1Pt_1"]                   = new TH1D("Jet1Pt_1"       , "Jet1Pt "             , 40, 0, 1000);
    histo1D["Jet1Pt_2"]                   = new TH1D("Jet1Pt_2"       , "Jet1Pt "             , 40, 0, 1000);
    histo1D["Jet1Pt_3"]                   = new TH1D("Jet1Pt_3"       , "Jet1Pt "             , 40, 0, 1000);
    histo1D["Jet1Eta_1"]                  = new TH1D("Jet1Eta_1"      , "Jet1Eta "            , 36, -3.6, 3.6);
    histo1D["Jet1Eta_2"]                  = new TH1D("Jet1Eta_2"      , "Jet1Eta "            , 36, -3.6, 3.6);
    histo1D["Jet1Eta_3"]                  = new TH1D("Jet1Eta_3"      , "Jet1Eta "            , 36, -3.6, 3.6);
    //for overflow
    histo1D["Jet1Pt2"]                    = new TH1D("Jet1Pt2"        , "Jet1Pt "             , 40, 0, 1000);
    histo1D["Jet1Pt3"]                    = new TH1D("Jet1Pt3"        , "Jet1Pt "             , 39, 0, 975);
    //
    histo1D["Jet1Eta"]                    = new TH1D("Jet1Eta"        , "Jet1Eta "            , 36, -3.6, 3.6);
    histo1D["Jet1Phi"]                    = new TH1D("Jet1Phi"        , "Jet1Phi "            , 80, -4, 4);
    //
    //histo1D["Jet1Eta_uncor"]              = new TH1D("Jet1Eta_uncor"  , "Jet1Eta "            , 36, -3.6, 3.6);
    histo1D["Jet1Phi_uncor"]              = new TH1D("Jet1Phi_uncor"  , "Jet1Phi "            , 80, -4, 4);
    histo1D["Jet1Pt_uncor"]               = new TH1D("Jet1Pt_uncor"   , "Jet1Pt "             , 28, 0, 700);
    //
    histo2D["Jet1PhivsEta"]               = new TH2D("Jet1PhivsEta"   , "Jet1Phi vs Eta"      , 40, -4, 4 , 40, -4,4);
    //
    histo1D["CaloJet1Emf_1"]              = new TH1D("CaloJet1Emf_1"   , "CaloJet1Emf_1"      , 60, -1, 2 );
    histo1D["CaloJet1Emf_2"]              = new TH1D("CaloJet1Emf_2"   , "CaloJet1Emf_2"      , 60, -1, 2 );
    histo1D["CaloJet1Emf_3"]              = new TH1D("CaloJet1Emf_3"   , "CaloJet1Emf_3"      , 60, -1, 2 );
    //
    histo1D["CaloJet1Eta"]                = new TH1D("CaloJet1Eta"    , "CaloJet1Eta "        , 36, -3.6, 3.6);	
    //
    histo1D["Jet1PUJetID"]                = new TH1D("Jet1PUJetID"    , "Jet1PUJetID"         , 4, 0, 4);	
    //
    //pf noise clean for leading jet
    histo1D["PFAK5JetChaHadEngFrac"]      = new TH1D("PFAK5JetChaHadEngFrac"    , "PFAK5JetChaHadEngFrac" , 60,  0., 1.2);
    histo1D["PFAK5JetNeuHadEngFrac"]      = new TH1D("PFAK5JetNeuHadEngFrac"    , "PFAK5JetNeuHadEngFrac" , 60, -0.1, 1.1);
    histo1D["PFAK5JetChaEmEngFrac"]       = new TH1D("PFAK5JetChaEmEngFrac"     , "PFAK5JetChaEmEngFrac " , 60, -0.1, 1.1);
    histo1D["PFAK5JetNeuEmEngFrac"]       = new TH1D("PFAK5JetNeuEmEngFrac"     , "PFAK5JetNeuEmEngFrac " , 60, -0.1, 1.1);
    //
    //pf noise clean for leading jet
    histo1D["PFAK5JetChaHadEngFrac150"]   = new TH1D("PFAK5JetChaHadEngFrac150" , "PFAK5JetChaHadEngFrac" , 60,  0., 1.2);
    histo1D["PFAK5JetNeuHadEngFrac150"]   = new TH1D("PFAK5JetNeuHadEngFrac150" , "PFAK5JetNeuHadEngFrac" , 60, -0.1, 1.1);
    histo1D["PFAK5JetChaEmEngFrac150"]    = new TH1D("PFAK5JetChaEmEngFrac150"  , "PFAK5JetChaEmEngFrac " , 60, -0.1, 1.1);
    histo1D["PFAK5JetNeuEmEngFrac150"]    = new TH1D("PFAK5JetNeuEmEngFrac150"  , "PFAK5JetNeuEmEngFrac " , 60, -0.1, 1.1);
    //
    //pf noise clean for leading jet
    histo1D["PFAK5JetChaHadEngFrac300"]   = new TH1D("PFAK5JetChaHadEngFrac300" , "PFAK5JetChaHadEngFrac" , 60,  0., 1.2);
    histo1D["PFAK5JetNeuHadEngFrac300"]   = new TH1D("PFAK5JetNeuHadEngFrac300" , "PFAK5JetNeuHadEngFrac" , 60, -0.1, 1.1);
    histo1D["PFAK5JetChaEmEngFrac300"]    = new TH1D("PFAK5JetChaEmEngFrac300"  , "PFAK5JetChaEmEngFrac " , 60, -0.1, 1.1);
    histo1D["PFAK5JetNeuEmEngFrac300"]    = new TH1D("PFAK5JetNeuEmEngFrac300"  , "PFAK5JetNeuEmEngFrac " , 60, -0.1, 1.1);
    
    ///---------------------- 
    /// Jet2
    histo1D["Jet2Pt"]                     = new TH1D("Jet2Pt"         , "Jet2Pt "             , 24, 0, 600);
    histo1D["Jet2Eta"]                    = new TH1D("Jet2Eta"        , "Jet2Eta "            , 52, -5.2, 5.2);
    histo1D["Jet2Phi"]                    = new TH1D("Jet2Phi"        , "Jet2Phi "            , 80, -4, 4); 
    histo1D["Jet2PUJetID"]                = new TH1D("Jet2PUJetID"    , "Jet2PUJetID"         , 4, 0, 4);
    histo1D["Jet2PUJetIDHighNEMF"]        = new TH1D("Jet2PUJetIDHighNEMF"    , "Jet2PUJetIDHighNEMF"         , 4, 0, 4);
    //
    //pf noise clean  for second jet
    histo1D["PFAK5JetChaHadEngFrac2"]     = new TH1D("PFAK5JetChaHadEngFrac2"   , "PFAK5JetChaHadEngFrac-2" , 60,  0., 1.2);
    histo1D["PFAK5JetNeuHadEngFrac2"]     = new TH1D("PFAK5JetNeuHadEngFrac2"   , "PFAK5JetNeuHadEngFrac-2" , 60, -0.1, 1.1);
    histo1D["PFAK5JetChaEmEngFrac2"]      = new TH1D("PFAK5JetChaEmEngFrac2"    , "PFAK5JetChaEmEngFrac-2"  , 60, -0.1, 1.1);
    histo1D["PFAK5JetNeuEmEngFrac2"]      = new TH1D("PFAK5JetNeuEmEngFrac2"    , "PFAK5JetNeuEmEngFrac-2"  , 60, -0.1, 1.1);
    histo1D["PFAK5JetMuonEngFrac2"]       = new TH1D("PFAK5JetMuonEngFrac2"     , "PFAK5JetMuonEngFrac2"    , 60, -0.1, 1.1);
    histo1D["PFAK5JetElecEngFrac2"]       = new TH1D("PFAK5JetElecEngFrac2"     , "PFAK5JetElecEngFrac2"    , 60, -0.1, 1.1);
    histo1D["PFAK5JetPhotEngFrac2"]       = new TH1D("PFAK5JetPhotEngFrac2"     , "PFAK5JetPhotEngFrac2"    , 60, -0.1, 1.1);

    ///---------------------- 
    /// Jet1-Jet2
    histo2D["Jet1Jet2Pt"]                 = new TH2D("Jet1Jet2Pt"     , "Jet1Jet2Pt "         , 56, 100, 1500, 56, 100, 1500);
    histo2D["Jet1Jet2Eta"]                = new TH2D("Jet1Jet2Eta"    , "Jet1Jet2Eta "        , 52, -5.2, 5.2, 52, -5.2, 5.2);
    histo2D["Jet1Jet2Phi"]                = new TH2D("Jet1Jet2Phi"    , "Jet1Jet2Phi "        , 80, -4, 4, 80, -4, 4);
    histo1D["Jet1Jet2MCor"]               = new TH1D("Jet1Jet2MCor"   , "M(Jet1,Jet2) "       , 600, 0, 3000); 
    histo1D["Jet1Jet2MRaw"]               = new TH1D("Jet1Jet2MRaw"   , "M(Jet1,Jet2) "       , 600, 0, 3000);
    
    ///---------------------- 
    /// Jet3
    histo1D["Jet3Pt"]                     = new TH1D("Jet3Pt"         , "Jet3Pt "             , 24, 0, 600);
    histo1D["Jet3Eta"]                    = new TH1D("Jet3Eta"        , "Jet3Eta "            , 52, -5.2, 5.2);
    histo1D["Jet3Phi"]                    = new TH1D("Jet3Phi"        , "Jet3Phi "            , 80, -4, 4);

    ///---------------------- 
    /// Njet
    histo1D["NJet"]             = new TH1D("NJet"            , "NJet "               , 10, 0, 10);
    histo1D["NJet5"]            = new TH1D("NJet5"           , "NJet "               , 5, 0, 5);
    histo1D["NJet6"]            = new TH1D("NJet6"           , "NJet "               , 6, 0, 6);
    histo1D["NJet55"]           = new TH1D("NJet55"          , "NJet "               , 5, 0, 5);
    histo1D["NJet66"]           = new TH1D("NJet66"          , "NJet "               , 6, 0, 6);
    histo1D["NJetExclusive4"]   = new TH1D("NJetExclusive4"  , "NJet "               , 4, 1, 5);
    histo1D["NJetInclusive4"]   = new TH1D("NJetInclusive4"  , "NJet "               , 4, 1, 5);
    
    ///---------------------- 
    //deltaPhi
    histo1D["dPhi_MetLep_Jet1"] = new TH1D("dPhi_MetLep_Jet1", "dPhi MetLep Jet1 "   , 35, 0, 3.5);
    histo1D["dPhi_Met_Jet1"]    = new TH1D("dPhi_Met_Jet1"   , "dPhi Met Jet1 "      , 35, 0, 3.5 );
    //
    histo1D["dPhi_MetLep_Jet2"] = new TH1D("dPhi_MetLep_Jet2", "dPhi MetLep Jet2 "   , 35, 0., 3.5);
    histo1D["dPhi_Met_Jet2"]    = new TH1D("dPhi_Met_Jet2"   , "dPhi Met Jet2 "      , 35, 0., 3.5);
    //
    histo1D["dPhi_Jet1_Jet2"]   = new TH1D("dPhi_Jet1_Jet2"  , "dPhi Jet1 Jet2 "     , 35, 0, 3.5);
    histo1D["dPhi_Jet1_muon"]   = new TH1D("dPhi_Jet1_muon"  , "dPhi Jet1 muon "     , 35, 0, 3.5);
     
    ///---------------------- 
    /// Met
    histo1D["Met"]              = new TH1D("Met"             , "MET "                ,  40, 0, 1000);
    histo1D["MetLep1"]          = new TH1D("MetLep1"         , "MET+Lep"              , 40, 0, 1000);
    histo1D["MetLep2"]          = new TH1D("MetLep2"         , "MET+Lep"              , 32, 200, 1000);
    histo1D["MetLep5"]          = new TH1D("MetLep5"         , "MET+Lep"              , 26, 350, 1000);
    //
    //for overflow 
    histo1D["MetLep3"]          = new TH1D("MetLep3"         , "MET+Lep"             , 32, 200, 1000); 
    histo1D["MetLep4"]          = new TH1D("MetLep4"         , "MET+Lep"             , 31, 200, 975); 
    //
    histo1D["MetLepPhi"]        = new TH1D("MetLepPhi"       , "MET+Lep Phi "        , 80, -4, 4);
    histo1D["MetPhi"]           = new TH1D("MetPhi"          , "MET Phi "            , 80, -4, 4);
    //
    histo1D["MetLepThrs1"]      = new TH1D("MetLepThrs1"     , "METLep Threshold"    , 40, 0, 1000  );
    histo1D["MetLepThrs2"]      = new TH1D("MetLepThrs2"     , "METLep Threshold"    , 32, 200, 1000);
    //
    histo1D["MetSumEt"]         = new TH1D("MetSumEt"        , "SumEt"               , 150, 0, 1500);
     
    ///---------------------- 
    /// TIV
    histo1D["TIV"]              = new TH1D("TIV"             , "TIV "                , 70, -0.05, 0.3);		
    histo1D["TIV_e"]            = new TH1D("TIV_e"           , "TIV "                , 70, -0.05, 0.3);
    histo1D["TIV_m"]            = new TH1D("TIV_m"           , "TIV "                , 70, -0.05, 0.3);
    histo1D["TIV_t"]            = new TH1D("TIV_t"           , "TIV "                , 70, -0.05, 0.3);
     
    ///---------------------- 
    /// Muon ISo
    histo1D["MuonPt"]           = new TH1D("MuonPt"         , "MuonPt "               ,40, 0,400);
    histo1D["MuonPt_2"]         = new TH1D("MuonPt_2"       , "MuonPt "               ,30, 0,120);
    
    ///---------------------- 
    /// PF Electron & Muon
    histo1D["PFElecPt"]         = new TH1D("PFElecPt"       , "PF ElecPt "            ,80, 0,80);
    histo1D["PFMuonPt"]         = new TH1D("PFMuonPt"       , "PF MuonPt "            ,80, 0,80);
    
    histo1D["NJet_met100"]      = new TH1D("NJet_met100"     , "NJet  Met>100 GeV"    , 10, 0, 10);
    histo1D["NJet_met150"]      = new TH1D("NJet_met150"     , "NJet  Met>150 GeV"    , 10, 0, 10);
    histo1D["NJet_met200"]      = new TH1D("NJet_met200"     , "NJet  Met>200 GeV"    , 10, 0, 10);
    histo1D["NJet_met250"]      = new TH1D("NJet_met250"     , "NJet  Met>250 GeV"    , 10, 0, 10);
    
    histo1D["EnergyScale"]      = new TH1D("EnergyScale"     , "Energy Scale "        , 10, 0,10);
    histo2D["UncerVsJetPt"]     = new TH2D("UncerVsJetPt"    , "Uncertinity vs JetPt" , 100, 0 ,800, 100, 0, 0.1);
    histo2D["UncerVsJetEta"]    = new TH2D("UncerVsJetEta"   , "Uncertinity vs JetEta", 100,-5 ,5  , 100, 0, 0.1);
    
    histo1D["GenJet1Pt"]        = new TH1D("GenJet1Pt"         , "Leading GenJet p_{T}"    , 24, 0, 600);
    histo1D["GenWPt"]           = new TH1D("GenWPt"            , "Gen W p_{T}"             , 24, 0, 600);
    histo1D["GenZPt"]           = new TH1D("GenZPt"            , "Gen Z p_{T}"             , 24, 0, 600);
    
    histo1D["GenJet1PtThrs"]    = new TH1D("GenJet1PtThrs"    , "Leading GenJet p_{T}"    , 24, 0, 600);
    histo1D["GenWPtThrs"]       = new TH1D("GenWPtThrs"       , "Gen W p_{T}"             , 24, 0, 600);
    histo1D["GenZPtThrs"]       = new TH1D("GenZPtThrs"       , "Gen Z p_{T}"             , 24, 0, 600);
    
    histo2D["GenJet1ptvsWpt"]   = new TH2D("GenJet1ptvsWpt"   , "GenJet1pt vs Wpt", 48, 0,600, 48, 0,600);
    histo2D["RecJet1ptvsWpt"]   = new TH2D("RecJet1ptvsWpt"   , "RecJet1pt vs Wpt", 48, 0,600, 48, 0,600);
    
    histo2D["GenJet1ptvsZpt"]   = new TH2D("GenJet1ptvsZpt"   , "GenJet1pt vs Zpt", 48, 0,600, 48, 0,600);
    histo2D["RecJet1ptvsZpt"]   = new TH2D("RecJet1ptvsZpt"   , "RecJet1pt vs Zpt", 48, 0,600, 48, 0,600);
    
    histo2D["METmuvsWpt"]       = new TH2D("METmuvsWpt"       , "METmu vs Wpt", 48, 0,600, 48, 0,600);
    histo2D["METmuvsZpt"]       = new TH2D("METmuvsZpt"       , "Metmu vs Wpt", 48, 0,600, 48, 0,600);
    
    histo1D["METoverWpt"]       = new TH1D("METoverWpt"       , "MET over  W p_{T}"   , 50, 0, 2);
    histo1D["METoverZpt"]       = new TH1D("METoverZpt"       , "MET over  Z p_{T}"   , 50, 0, 2);
    
    histo1D["numofPileup"]      = new TH1D("numofPileup"      , "numofPileup"   , 30, 0, 30);
    
    histo1D["Met_Wenu"]         = new TH1D("Met_Wenu"         , "MET W->enu"    , 32, 0, 800);
    histo1D["Met_Wmnu"]         = new TH1D("Met_Wmnu"         , "MET W->munu"    , 32, 0, 800);
    histo1D["Met_Wtnu"]         = new TH1D("Met_Wtnu"         , "MET W->tnu"    , 32, 0, 800);
    
    histo1D["GenElecPt"]        = new TH1D("GenElecPt"         , "Gen Elec p_{T}"     , 100, 0, 800);
    histo1D["GenMuonPt"]        = new TH1D("GenMuonPt"         , "Gen Muon p_{T}"     , 100, 0, 800);
    histo1D["GenTauPt"]         = new TH1D("GenTauPt"          , "Gen Tau p_{T}"      , 100, 0, 800);
    
    histo1D["PFMuonPt1"]           = new TH1D("PFMuonPt1"           , "PFMuonPt1"          , 80, 0, 800);
    histo1D["PFMuonEta1"]          = new TH1D("PFMuonEta1"          , "PFMuonEta1"         , 100, -5, 5);
    histo1D["PFMuonIso1"]          = new TH1D("PFMuonIso1"          , "PFMuonIso1"         , 100, -1, 3);
    histo1D["PFMuonisGMPT1"]       = new TH1D("PFMuonisGMPT1"       , "PFMuonisGMPT1"      , 50, 0, 50);
    histo1D["PFMuonnValidHits1"]   = new TH1D("PFMuonnValidHits1"   , "PFMuonnValidHits1"  , 100, 0, 100);
    histo1D["PFMuondxy1"]          = new TH1D("PFMuondxy1"          , "PFMuondxy1"         , 100, -1, 5);
    histo1D["PFMuondz1"]           = new TH1D("PFMuondz1"           , "PFMuondz1"          , 100, -1, 5);
    
    histo1D["PFMuonPt2"]           = new TH1D("PFMuonPt2"           , "PFMuonPt2"          , 80, 0, 800);
    histo1D["PFMuonEta2"]          = new TH1D("PFMuonEta2"          , "PFMuonEta2"         , 100, -5, 5);
    histo1D["PFMuonIso2"]          = new TH1D("PFMuonIso2"          , "PFMuonIso2"         , 100, -1, 3);
    histo1D["PFMuonisGMPT2"]       = new TH1D("PFMuonisGMPT2"       , "PFMuonisGMPT2"      , 50, 0, 50);
    histo1D["PFMuonnValidHits2"]   = new TH1D("PFMuonnValidHits2"   , "PFMuonnValidHits2"  , 100, 0, 100);
    histo1D["PFMuondxy2"]          = new TH1D("PFMuondxy2"          , "PFMuondxy2"         , 100, -1, 5);
    histo1D["PFMuondz2"]           = new TH1D("PFMuondz2"           , "PFMuondz2"          , 100, -1, 5);
    histo1D["CaloJetEMF"]          = new TH1D("CaloJetEMF"           , "CaloJetEMF"        , 300, -1, 2);
    
    ///---------------------- 
    /// PF Tau
    histo1D["NPFTau"]                                = new TH1D("NPFTau"                               , "NPFTau"                                , 10, 0, 10);
    histo1D["PFTauE"]                                = new TH1D("PFTauE"                               , "PFTauE"                                , 100, 0, 500);
    histo1D["PFTauPt"]                               = new TH1D("PFTauPt"                              , "PFTauPt"                               , 100, 0, 500);
    histo1D["PFTauPx"]                               = new TH1D("PFTauPx"                              , "PFTauPx"                               , 100, -100, 100);
    histo1D["PFTauPy"]                               = new TH1D("PFTauPy"                              , "PFTauPy"                               , 100, -100, 100);
    histo1D["PFTauPz"]                               = new TH1D("PFTauPz"                              , "PFTauPz"                               , 100, -100, 100);
    histo1D["PFTauEta"]                              = new TH1D("PFTauEta"                             , "PFTauEta"                              , 100, -5, 5);
    histo1D["PFTauPhi"]                              = new TH1D("PFTauPhi"                             , "PFTauPhi"                              , 100, -4, 4);
    histo1D["PFTauEtaEtaMoment"]                     = new TH1D("PFTauEtaEtaMoment"                    , "PFTauEtaEtaMoment"                     , 100, -0.01, 0.1);
    histo1D["PFTauPhiPhiMoment"]                     = new TH1D("PFTauPhiPhiMoment"                    , "PFTauPhiPhiMoment"                     , 100, -0.01, 0.1);
    histo1D["PFTauLeadPFChargedHadrCandsignedSipt"]  = new TH1D("PFTauLeadPFChargedHadrCandsignedSipt" , "PFTauLeadPFChargedHadrCandsignedSipt"  , 200, -1, 3);
    histo1D["PFTauIsoPFChargedHadrCandsPtSum"]       = new TH1D("PFTauIsoPFChargedHadrCandsPtSum"      , "PFTauIsoPFChargedHadrCandsPtSum"       , 100, 0, 50);
    histo1D["PFTauIsoPFGammaCandsEtSum"]             = new TH1D("PFTauIsoPFGammaCandsEtSum"            , "PFTauIsoPFGammaCandsEtSum"             , 30, 0, 15);
    
    histo1D["PFTauMaximumHCALPFClusterEt"]           = new TH1D("PFTauMaximumHCALPFClusterEt"    , "PFTauMaximumHCALPFClusterEt"         , 100, 0, 500);
    histo1D["PFTauEmFraction"]                       = new TH1D("PFTauEmFraction"                , "PFTauEmFraction"                     , 70, -0.2, 1.2);
    histo1D["PFTauHcalTotOverPLead"]                 = new TH1D("PFTauHcalTotOverPLead"          , "PFTauHcalTotOverPLead"               , 100, 0, 200);
    histo1D["PFTauHcalMaxOverPLead"]                 = new TH1D("PFTauHcalMaxOverPLead"          , "PFTauHcalMaxOverPLead"               , 100, 0, 200);
    histo1D["PFTauHcal3x3OverPLead"]                 = new TH1D("PFTauHcal3x3OverPLead"          , "PFTauHcal3x3OverPLead"               , 50, 0, 100);
    histo1D["PFTauEcalStripSumEOverPLead"]           = new TH1D("PFTauEcalStripSumEOverPLead"    , "PFTauEcalStripSumEOverPLead"         , 75, 0, 150);
    histo1D["PFTauBremsRecoveryEOverPLead"]          = new TH1D("PFTauBremsRecoveryEOverPLead"   , "PFTauBremsRecoveryEOverPLead"        , 10, 0, 10);
    histo1D["PFTauElectronPreIDOutput"]              = new TH1D("PFTauElectronPreIDOutput"       , "PFTauElectronPreIDOutput"            , 10, 0, 10);
    histo1D["PFTauElectronPreIDDecision"]            = new TH1D("PFTauElectronPreIDDecision"     , "PFTauElectronPreIDDecision"          , 10, 0, 10);
    histo1D["PFTauMuonDecision"]                     = new TH1D("PFTauMuonDecision"              , "PFTauMuonDecision"                   , 10, 0, 10);
    
    ///---------------------- 
    histo1D["MetLep1_cm"]       = new TH1D("MetLep1_cm"      , "MET+Lep"              , 40, 0, 1000);
    histo1D["MetLep1_eff"]      = new TH1D("MetLep1_eff"     , "MET+Lep"              , 32, 0, 800);
    
    ///---------------------- 
    histo1D["GravitonPt"]         = new TH1D("GravitonPt"        , "GravitonPt"                 , 50, 0, 1000);
    histo1D["GravitonPt_gg"]      = new TH1D("GravitonPt_gg"     , "GravitonPt_gg"              , 50, 0, 1000);
    histo1D["GravitonPt_qg"]      = new TH1D("GravitonPt_qg"     , "GravitonPt_qg"              , 50, 0, 1000);
    histo1D["GravitonPt_qq"]      = new TH1D("GravitonPt_qq"     , "GravitonPt_qq"              , 50, 0, 1000);
    
    ///---------------------- 
    histo2D["SumETvsNPV"]         = new TH2D("SumETvsNPV"       , "SumETvsNPV"        ,1500,0,1500, 70, 0, 70);
    profile1D["SumETprNPV"]       = new TProfile("SumETprNPV"   , "<SumET> vs NPV"    ,70,0,70,0,1500);
    
    ///---------------------- 
    histo2D["PileUpETvsNPV"]      = new TH2D("PileUpETvsNPV"    , "SumETvsNPV"        ,1500,0,1500, 70, 0, 70);
    profile1D["PileUpETprNPV"]    = new TProfile("PileUpETprNPV", "<PileUpET> vs NPV"    ,70,0,70,0,1500);
    
    ///----------------------
    histo2D["NPVvsnpv0"]	      = new TH2D("NPVvsnpv0"    , "NPVvsnpv0"        ,70,0,70, 70, 0, 70);
    profile1D["NPVprnpv0"]	      = new TProfile("NPVprnpv0"    , "NPVprnpv0"    ,70,0,70,0,70);
   
    ///---------------------- 
    /// PDF
    for(int i=0; i<100; i++ ){
      char his[100];
      sprintf(his,"PDF%d", i);
      histo1D[his]           = new TH1D(his , "PDF"  , 10, 0, 10);
    }		
    //
    histo1D["nnpdf20_p"]      = new TH1D("nnpdf20_p"     , "nnpdf20 plus"              , 300, -3, 3);
    histo1D["nnpdf20_m"]      = new TH1D("nnpdf20_m"     , "nnpdf20 minus"             , 300, -3, 3);
    histo1D["nnpdf20"]        = new TH1D("nnpdf20"       , "nnpdf20"             , 300, -3, 3);
    //
    histo1D["alphas_m"]      = new TH1D("alphas_m"     , "alphas minus"              , 10, 0, 10);
    histo1D["alphas"]        = new TH1D("alphas"       , "alphas"                    , 10, 0, 10);
    histo1D["alphas_p"]      = new TH1D("alphas_p"     , "alphas plus"               , 10, 0, 10);
    
    ///---------------------- 
    histo1D["GenZnunuEta"]      = new TH1D("GenZnunuEta"     , "GenZEta"               , 100, -5, 5);
    histo1D["GenZnunuPt"]       = new TH1D("GenZnunuPt"     , "GenZPt"               , 100, 0, 1000);
    //
    histo1D["GenElecTIV"]       = new TH1D("GenElecTIV"     , "GenElecTIV"               , 100, 0, 1000);
    histo1D["GenMuonTIV"]       = new TH1D("GenMuonTIV"     , "GenMuonTIV"               , 100, 0, 1000);
    histo1D["GenTauTIV"]        = new TH1D("GenTauTIV"      , "GenTauTIV"                , 2000, -1000, 1000);
    
    
    histo1D["ISRWeight"]        = new TH1D("ISRWeight"      , "ISRWeight"                , 10, 0, 10);
    histo1D["dRTIVGenMuon"]     = new TH1D("dRTIVGenMuon"   , "dRTIVGenMuon"             , 1000,  -1, 9);
    
    histo1D["NoiseFlag"]        = new TH1D("NoiseFlag"      , "NoiseFlag"                , 20,  0, 20);
    histo1D["JetPhotEng"]       = new TH1D("JetPhotEng"     , "JetPhotEng"               , 140,  -0.5, 3.5 );
     
    ///---------------------- 
    /// Abnormal events
    histo1D["AbNormalEvents"]     = new TH1D("AbNormalEvents"     , "(PFMET-CALOMET)/CALOMET"             , 200,  -10, 10 );
    histo1D["AbNormalEventsTc"]   = new TH1D("AbNormalEventsTc"     , "(PFMET-TcMET)/TcMET"               , 200,  -10, 10 );

    histo1D["MetPF"]              = new TH1D("MetPF"             , "PF MET"                ,  40, 0, 1000);
    histo1D["MetCalo"]            = new TH1D("MetCalo"           , "Calo MET"              ,  40, 0, 1000);
    histo1D["MetTc"]              = new TH1D("MetTc"             , "TC MET"                ,  40, 0, 1000);

    histo2D["MetPF-Calo"]         = new TH2D("MetPF-Calo"    , "MetPF-Calo" , 200, 0 ,2000, 200, 0, 2000);
    histo2D["MetPF-Tc"]           = new TH2D("MetPF-Tc"      , "MetPF-Tc" ,   200, 0 ,2000, 200, 0, 2000);
    histo2D["MetTc-Calo"]         = new TH2D("MetTc-Calo"    , "MetTc-Calo" , 200, 0 ,2000, 200, 0, 2000);

    ///---------------------- 
    /// WideJet
    histo1D["WideJet1Pt"]           = new TH1D("WideJet1Pt"          , "Wide Jet1Pt "              , 40, 0, 1000); 
    histo1D["WideJet1Pt2"]          = new TH1D("WideJet1Pt2"         , "Wide Jet1Pt "              , 40, 0, 1000);
    histo1D["WideJet1Pt3"]          = new TH1D("WideJet1Pt3"         , "Wide Jet1Pt "              , 39, 0, 975);
    histo1D["WideJet1Eta"]          = new TH1D("WideJet1Eta"         , "Wide Jet1Eta "             , 36, -3.6, 3.6);
    histo1D["WideJet2Pt"]           = new TH1D("WideJet2Pt"          , "Wide Jet2Pt (Normal AK5) " , 40, 0, 1000); 
    histo1D["WideJet2Eta"]          = new TH1D("WideJet2Eta"         , "Wide Jet2Eta (Normal AK5) ", 36, -3.6, 3.6);
    histo1D["NWideJet"]             = new TH1D("NWideJet"            , "NWideJet "                 , 10, 0, 10);
    histo1D["dPhi_WideJet1_Jet2"]   = new TH1D("dPhi_WideJet1_Jet2"  , "dPhi WideJet1 Jet2 "       , 35, 0, 3.5);
    
  }
  
  ///---------------------- Data MC Matching Histograms Filling -----------------------------------------------------------------
  bool hDataMcMatching::Process(EventData & ev){
    
    int t      = ev.MetType();
    double w   = ev.Weight();
    int njets  = JetNumber(ev);
    int ixjet1 = JetIndex(0, ev);
    int ixjet2 = JetIndex(1, ev);
    int ixjet3 = JetIndex(2, ev);
    
    histo2D["SumETvsNPV"]->Fill( ev.MetSumEt(t), ev.NPV(), w );
    profile1D["SumETprNPV"]->Fill( ev.NPV() , ev.MetSumEt(t) );
    
    histo2D["NPVvsnpv0"]->Fill( ev.NPV() , ev.npv0() , w );
    profile1D["NPVprnpv0"]->Fill( ev.NPV() , ev.npv0()  );
    
    for(int i=0; i<20; i++){
      if(ev.NoiseFlag(i)==0 ) histo1D["NoiseFlag"]->Fill( i, 1 );
    }
    
    histo1D["AbNormalEvents"]->Fill((ev.MetPt(10)-ev.MetPt(0))/ev.MetPt(0), w);
    histo1D["AbNormalEventsTc"]->Fill((ev.MetPt(10)-ev.MetPt(20))/ev.MetPt(20), w);
    
    double  pileupET = ev.MetSumEt(t) - (ev.PFAK5JetPtCor(ixjet1)+ ev.PFAK5JetPtCor(ixjet2));
    histo2D["PileUpETvsNPV"]->Fill(pileupET, ev.NPV(), w);
    
    profile1D["PileUpETprNPV"]->Fill(ev.NPV(), pileupET);
    
    histo2D["Jet1PhivsEta"]->Fill(ev.PFAK5JetEta(ixjet1), ev.PFAK5JetPhi(ixjet1), w);
    
    histo1D["Jet1Phi_uncor"]->Fill( atan2( ev.PFAK5JetPy(ixjet1) ,  ev.PFAK5JetPx(ixjet1)  )  , w);
    histo1D["Jet1Pt_uncor"]->Fill(  ev.PFAK5JetPt(ixjet1) , w);
    
    histo1D["JetPhotEng"]->Fill(  ev.PFAK5JetPhotEng(ixjet1)/ev.PFAK5JetE(ixjet1) , w);
      
    double countTau = 0;
    for(Int_t i = 0; i<ev.NPFTau(); i++){
      if(ev.PFTauPt(i)<20.) continue;
      if(fabs(ev.PFTauEta(i)) > 2.3) continue;
      if(ev.PFTauDisByLooseCombinedIsolationDeltaBetaCorr(i) < 0.5) continue;
      if(ev.PFTauDisDecayModeFinding(i) < 0.5) continue;
      if(ev.PFTauDisAgainstElectronLoose(i) < 0.5) continue;
      if(ev.PFTauDisAgainstMuonTight2(i) < 0.5) continue;
      countTau+=1.;
      if(countTau==1.){
	histo1D["PFTauE"]->Fill(ev.PFTauE(i),w );          
	histo1D["PFTauPt"]->Fill(ev.PFTauPt(i),w );        
	histo1D["PFTauPx"]->Fill(ev.PFTauPx(i),w );        
	histo1D["PFTauPy"]->Fill(ev.PFTauPy(i),w );          
	histo1D["PFTauPz"]->Fill(ev.PFTauPz(i),w );         
	histo1D["PFTauEta"]->Fill(ev.PFTauEta(i),w );        
	histo1D["PFTauPhi"]->Fill(ev.PFTauPhi(i),w );          
	histo1D["PFTauEtaEtaMoment"]->Fill(ev.PFTauEtaEtaMoment(i),w );
	histo1D["PFTauPhiPhiMoment"]->Fill(ev.PFTauPhiPhiMoment(i),w );
	histo1D["PFTauLeadPFChargedHadrCandsignedSipt"]->Fill(ev.PFTauLeadPFChargedHadrCandsignedSipt(i),w );
	histo1D["PFTauIsoPFChargedHadrCandsPtSum"]->Fill(ev.PFTauIsoPFChargedHadrCandsPtSum(i),w );
	histo1D["PFTauIsoPFGammaCandsEtSum"]->Fill(ev.PFTauIsoPFGammaCandsEtSum(i),w );
	histo1D["PFTauMaximumHCALPFClusterEt"]->Fill(ev.PFTauMaximumHCALPFClusterEt(i),w );            
	histo1D["PFTauEmFraction"]->Fill(ev.PFTauEmFraction(i),w );           
	histo1D["PFTauHcalTotOverPLead"]->Fill(ev.PFTauHcalTotOverPLead(i),w );           
	histo1D["PFTauHcalMaxOverPLead"]->Fill(ev.PFTauHcalMaxOverPLead(i),w );           
	histo1D["PFTauHcal3x3OverPLead"]->Fill(ev.PFTauHcal3x3OverPLead(i),w );            
	histo1D["PFTauEcalStripSumEOverPLead"]->Fill(ev.PFTauEcalStripSumEOverPLead(i),w );            
	histo1D["PFTauBremsRecoveryEOverPLead"]->Fill(ev.PFTauBremsRecoveryEOverPLead(i),w );          
	histo1D["PFTauElectronPreIDOutput"]->Fill(ev.PFTauElectronPreIDOutput(i),w );         
	histo1D["PFTauElectronPreIDDecision"]->Fill(ev.PFTauElectronPreIDDecision(i),w );      
	histo1D["PFTauMuonDecision"]->Fill(ev.PFTauMuonDecision(i),w );
      }
    }
    histo1D["NPFTau"]->Fill(countTau,w);   

    float Iso = 0.0;
    Iso = (ev.PFMuonNeutralHadronIso(0) + ev.PFMuonChargedHadronIso(0) + ev.PFMuonPhotonIso(0))/ev.PFMuonPt(0);
    
    histo1D["PFMuonPt1"]->Fill( ev.PFMuonPt(0) );
    histo1D["PFMuonEta1"]->Fill( ev.PFMuonEta(0) );
    histo1D["PFMuonIso1"]->Fill( Iso );
    histo1D["PFMuonisGMPT1"]->Fill( ev.PFMuonisGMPT(0) );
    histo1D["PFMuonnValidHits1"]->Fill( ev.PFMuonnValidHits(0) );
    histo1D["PFMuondxy1"]->Fill(  ev.PFMuondxy(0) );
    histo1D["PFMuondz1"]->Fill( ev.PFMuondz(0) );
    
    Iso = 0.0;
    Iso = (ev.PFMuonNeutralHadronIso(1) + ev.PFMuonChargedHadronIso(1) + ev.PFMuonPhotonIso(1))/ev.PFMuonPt(1);
    
    histo1D["PFMuonPt2"]->Fill( ev.PFMuonPt(1) );
    histo1D["PFMuonEta2"]->Fill( ev.PFMuonEta(1) );
    histo1D["PFMuonIso2"]->Fill( Iso );
    histo1D["PFMuonisGMPT2"]->Fill( ev.PFMuonisGMPT(1) );
    histo1D["PFMuonnValidHits2"]->Fill( ev.PFMuonnValidHits(1) );
    histo1D["PFMuondxy2"]->Fill(  ev.PFMuondxy(1) );
    histo1D["PFMuondz2"]->Fill( ev.PFMuondz(1) );
    
    if(ev.CaloAK5JetEmf(0) >0.03 && ev.CaloAK5JetEmf(0)<0.98 ) histo1D["CaloJetEMF"]->Fill( ev.CaloAK5JetEmf(0) , w);
    
    //pf noise clean  for leading jet
    histo1D["PFAK5JetChaHadEngFrac"]->Fill( ev.PFAK5JetChaHadEngFrac(ixjet1) , w );
    histo1D["PFAK5JetNeuHadEngFrac"]->Fill( ev.PFAK5JetNeuHadEngFrac(ixjet1) , w );
    histo1D["PFAK5JetChaEmEngFrac"]->Fill( ev.PFAK5JetChaEmEngFrac(ixjet1) , w );
    histo1D["PFAK5JetNeuEmEngFrac"]->Fill( ev.PFAK5JetNeuEmEngFrac(ixjet1) , w ); 
    
    
    histo1D["NPV"]->Fill( ev.NPV() , w );
    histo1D["numofPileup"]->Fill( ev.npv0() , w );
    for(int i=0; i<ev.NPV(); i++){
      histo1D["PVx"]->Fill( ev.PVx(i) , w  );
      histo1D["PVy"]->Fill( ev.PVy(i) , w  );
      histo1D["PVz"]->Fill( ev.PVz(i) , w  );              
      histo1D["PVR"]->Fill( sqrt(ev.PVx(i)*ev.PVx(i) + ev.PVz(i)*ev.PVz(i) ) , w  );              
      histo1D["PVndof"]->Fill( ev.PVndof(i) , w  );           
      histo1D["PVchi2"]->Fill( ev.PVchi2(i) , w  );           
      histo1D["PVntracks"]->Fill( ev.PVntracks(i) , w  );    
    }
    
    //jet1 cut
    histo1D["Jet1Pt"]->Fill( ev.PFAK5JetPtCor( ixjet1  ) , w ); 
    histo1D["Jet1Pt3"]->Fill( ev.PFAK5JetPtCor( ixjet1  ) , w ); 
    
    histo1D["Jet1Eta"]->Fill( ev.PFAK5JetEta( ixjet1 ) , w ); 
    histo1D["Jet1Emf"]->Fill( ev.CaloAK5JetEmf(0) , w );  
    
    histo1D["Jet1Phi"]->Fill( ev.PFAK5JetPhi(ixjet1) , w ); 
    
    histo1D["CaloJet1Eta"]->Fill( ev.CaloAK5JetEta(0) , w );  
    histo1D["Jet1PUJetID"]->Fill( ev.PFAK5JetPUFullJetId(ixjet1),w);
    
    if( ev.PFAK5JetPhi(ixjet1)< -1.5 )
      {  
	histo1D["Jet1Pt_1"]->Fill( ev.PFAK5JetPtCor( ixjet1  ) , w ); 
	histo1D["Jet1Eta_1"]->Fill( ev.PFAK5JetEta( ixjet1  ) , w ); 
	
	histo1D["CaloJet1Emf_1"]->Fill( ev.CaloAK5JetEmf( ixjet1  ) , w );
      }
    
    else if( ev.PFAK5JetPhi(ixjet1) > -1.5  && ev.PFAK5JetPhi(ixjet1)< 0.5)
      {
	histo1D["Jet1Pt_2"]->Fill( ev.PFAK5JetPtCor( ixjet1  ) , w ); 
	histo1D["Jet1Eta_2"]->Fill( ev.PFAK5JetEta( ixjet1  ) , w ); 
	histo1D["CaloJet1Emf_2"]->Fill( ev.CaloAK5JetEmf( ixjet1  ) , w );
      }
    else if( ev.PFAK5JetPhi(ixjet1) > 0.5 )  
      {
	histo1D["Jet1Pt_3"]->Fill( ev.PFAK5JetPtCor( ixjet1  ) , w );
	histo1D["Jet1Eta_3"]->Fill( ev.PFAK5JetEta( ixjet1  ) , w ); 
	histo1D["CaloJet1Emf_3"]->Fill( ev.CaloAK5JetEmf( ixjet1  ) , w );
      }
    
    //njet
    histo1D["NJet"]->Fill( njets , w );
    histo1D["NJet55"]->Fill( njets , w );
    histo1D["NJet66"]->Fill( njets , w ); 


    histo1D["NJetExclusive4"]->Fill( njets, w );
    if(njets<4){
      histo1D["NJetInclusive4"]->Fill( njets, w );
    }
    else{
      histo1D["NJetInclusive4"]->Fill( 4, w ); 
    }
    
    
    //deltaPhi
    histo1D["dPhi_MetLep_Jet1"]->Fill( fabs( deltaPhi( ev.PFAK5JetPhi(ixjet1) , MetLepPhi( ev.MetPx(t) , ev.MetPy(t) ,ev) ) ), w );
    histo1D["dPhi_Met_Jet1"]->Fill( fabs( deltaPhi( ev.PFAK5JetPhi(ixjet1) , ev.MetPhi(t) ) ), w );
    
    if(njets>=2){  
      histo1D["dPhi_MetLep_Jet2"]->Fill(  fabs( deltaPhi( ev.PFAK5JetPhi(ixjet2) , MetLepPhi( ev.MetPx(t) , ev.MetPy(t) ,ev) ) ), w );
      histo1D["dPhi_Met_Jet2"]->Fill(  fabs( deltaPhi( ev.PFAK5JetPhi(ixjet2) , ev.MetPhi(t) ) ) , w );			
      histo1D["dPhi_Jet1_Jet2"]->Fill(  fabs( deltaPhi( ev.PFAK5JetPhi(ixjet1) ,  ev.PFAK5JetPhi(ixjet2) ) ), w );		
      histo1D["dPhi_Jet1_muon"]->Fill(  fabs( deltaPhi( ev.PFAK5JetPhi(ixjet1) ,  ev.PFMuonPhi(0) ) ), w );
      
      histo1D["Jet2Pt"]->Fill( ev.PFAK5JetPtCor(ixjet2) , w ); 
      histo1D["Jet2Eta"]->Fill( ev.PFAK5JetEta(ixjet2) , w ); 
      histo1D["Jet2Phi"]->Fill( ev.PFAK5JetPhi(ixjet2) , w );
      histo1D["PFAK5JetChaHadEngFrac2"]->Fill( ev.PFAK5JetChaHadEngFrac(ixjet2) , w );
      histo1D["PFAK5JetNeuHadEngFrac2"]->Fill( ev.PFAK5JetNeuHadEngFrac(ixjet2) , w );
      histo1D["PFAK5JetChaEmEngFrac2"]->Fill( ev.PFAK5JetChaEmEngFrac(ixjet2) , w );
      histo1D["PFAK5JetNeuEmEngFrac2"]->Fill( ev.PFAK5JetNeuEmEngFrac(ixjet2) , w );
      histo1D["PFAK5JetMuonEngFrac2"]->Fill( ev.PFAK5JetMuonEng(ixjet2)/ev.PFAK5JetE(ixjet2) , w );
      histo1D["PFAK5JetElecEngFrac2"]->Fill( ev.PFAK5JetElecEng(ixjet2)/ev.PFAK5JetE(ixjet2) , w );
      histo1D["PFAK5JetPhotEngFrac2"]->Fill( ev.PFAK5JetPhotEng(ixjet2)/ev.PFAK5JetE(ixjet2) , w ); 
      histo1D["Jet2PUJetID"]->Fill( ev.PFAK5JetPUFullJetId(ixjet2),w);
      if(ev.PFAK5JetNeuEmEngFrac(ixjet2)>0.7){ 
	histo1D["Jet2PUJetIDHighNEMF"]->Fill( ev.PFAK5JetPUFullJetId(ixjet2),w);
      }
      
      histo2D["Jet1Jet2Pt"]->Fill(ev.PFAK5JetPtCor(ixjet1),ev.PFAK5JetPtCor(ixjet2),w);
      histo2D["Jet1Jet2Eta"]->Fill(ev.PFAK5JetEta(ixjet1),ev.PFAK5JetEta(ixjet2),w);
      histo2D["Jet1Jet2Phi"]->Fill(ev.PFAK5JetPhi(ixjet1),ev.PFAK5JetPhi(ixjet2),w);
      
      TLorentzVector jet1Cor,jet2Cor,jet1Raw,jet2Raw;
      jet1Cor.SetPxPyPzE(ev.PFAK5JetPxCor(ixjet1),ev.PFAK5JetPyCor(ixjet1),ev.PFAK5JetPzCor(ixjet1),ev.PFAK5JetECor(ixjet1)); 
      jet2Cor.SetPxPyPzE(ev.PFAK5JetPxCor(ixjet2),ev.PFAK5JetPyCor(ixjet2),ev.PFAK5JetPzCor(ixjet2),ev.PFAK5JetECor(ixjet2));
      jet1Raw.SetPxPyPzE(ev.PFAK5JetPx(ixjet1),ev.PFAK5JetPy(ixjet1),ev.PFAK5JetPz(ixjet1),ev.PFAK5JetE(ixjet1)); 
      jet2Raw.SetPxPyPzE(ev.PFAK5JetPx(ixjet2),ev.PFAK5JetPy(ixjet2),ev.PFAK5JetPz(ixjet2),ev.PFAK5JetE(ixjet2));
      //if((jet1Cor+jet2Cor).M()>1000 || (jet1Raw+jet2Raw).M()>1000){
      //cout<<(jet1Cor+jet2Cor).M()<<" | "<<(jet1Raw+jet2Raw).M()<<endl;
      //}
      histo1D["Jet1Jet2MCor"]->Fill((jet1Cor+jet2Cor).M(),w);
      histo1D["Jet1Jet2MRaw"]->Fill((jet1Raw+jet2Raw).M(),w);
      
      if(njets>2){
	histo1D["Jet3Pt"]->Fill( ev.PFAK5JetPtCor(ixjet3), w);
	histo1D["Jet3Eta"]->Fill( ev.PFAK5JetEta(ixjet3), w);
	histo1D["Jet3Phi"]->Fill( ev.PFAK5JetPhi(ixjet3), w);
      }
    }
    
    //Met
    histo1D["Met"]->Fill( ev.MetPt( t) , w );
    histo1D["MetLep1"]->Fill( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) , w ); 
    histo1D["MetLep2"]->Fill( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) , w );
    histo1D["MetLep5"]->Fill( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) , w );
    histo1D["MetLep4"]->Fill( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) , w );
    
    if(ev.MetPt(0) >95. ) histo1D["MetLep1_cm"]->Fill( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) , w ); 
    
    
    histo1D["MetLepPhi"]->Fill( fabs( MetLepPhi( ev.MetPx(t) , ev.MetPy(t) , ev) ), w );
    histo1D["MetPhi"]->Fill(   ev.MetPhi(t)  , w ); 
    
    histo1D["MetSumEt"]->Fill(   ev.MetSumEt(t)  , w ); 
    
    //TIV
    histo1D["TIV"]->Fill( ev.LowTIV()  , w );
    
    for(int i=0; i<ev.NGenPar(); i++)
      {
	if(abs(ev.GenParId(i) )==11 && ev.GenParStatus(i)==3 )
	  {
	    histo1D["TIV_e"]->Fill( ev.LowTIV()  , w );
	  }
	else if(abs(ev.GenParId(i) )==13 && ev.GenParStatus(i)==3 )
	  {
	    histo1D["TIV_m"]->Fill( ev.LowTIV()  , w );
	    
	  }
	else if(abs(ev.GenParId(i) )==15 && ev.GenParStatus(i)==3 )
	  {
	    histo1D["TIV_t"]->Fill( ev.LowTIV()  , w );
	  }
      }
    
    
    for(int i=0; i<ev.TIV_N(); i++){
      for(int j=0; j<ev.NGenPar(); j++){
	if( deltaR(  ev.TIV_eta(i), ev.TIV_phi(i) , ev.GenParEta(j), ev.GenParPhi(j) ) <1110.2 ){
	  if( abs(ev.GenParId(i) )==11 && ev.GenParStatus(i)==2) histo1D["GenElecTIV"]->Fill( ev.GenParPt(i)  , w ); 
	  if( abs(ev.GenParId(i) )==13 && ev.GenParStatus(i)==3){  
	    histo1D["GenMuonTIV"]->Fill( ev.GenParPt(i)  , w );
	    histo1D["dRTIVGenMuon"]->Fill( deltaR(ev.TIV_eta(i), ev.TIV_phi(i) , ev.GenParEta(j), ev.GenParPhi(j) ) , w );
	  }
	  if( abs(ev.GenParId(i) )==211 && ev.GenParDoughterOf(i)==15 ) histo1D["GenTauTIV"]->Fill( ev.GenParDoughterOf(i)  , w ); 
	}
      }
    }
    
    //MuonIso
    if(ev.NMuon() >0 )histo1D["MuonPt"]->Fill( ev.MuonPt(0)  , w );
    if(ev.NMuon() >0 )histo1D["MuonPt_2"]->Fill( ev.MuonPt(0)  , w );
    if(ev.NPFMuon() >0 )histo1D["PFMuonPt"]->Fill( ev.PFMuonPt(0)  , w ); 
    
    //ELectron
    if(ev.NPFElec() >0 )histo1D["PFElecPt"]->Fill( ev.PFElecPt(0)  , w ); 
    
    if( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) > 100.  ) histo1D["NJet_met100"]->Fill( njets , w );  
    if( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) > 150.  ) histo1D["NJet_met150"]->Fill( njets , w );  
    if( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) > 200.  ) histo1D["NJet_met200"]->Fill( njets , w );  
    if( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) > 250.  ) histo1D["NJet_met250"]->Fill( njets , w );  
    
    if(MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) > 150. && MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) < 200.){
	histo1D["PFAK5JetChaHadEngFrac150"]->Fill( ev.PFAK5JetChaHadEngFrac(ixjet1) , w );
	histo1D["PFAK5JetNeuHadEngFrac150"]->Fill( ev.PFAK5JetNeuHadEngFrac(ixjet1) , w );
	histo1D["PFAK5JetChaEmEngFrac150"]->Fill( ev.PFAK5JetChaEmEngFrac(ixjet1) , w );
	histo1D["PFAK5JetNeuEmEngFrac150"]->Fill( ev.PFAK5JetNeuEmEngFrac(ixjet1) , w ); 
    }
    
    if(MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) > 300.){
      histo1D["PFAK5JetChaHadEngFrac300"]->Fill( ev.PFAK5JetChaHadEngFrac(ixjet1) , w );
      histo1D["PFAK5JetNeuHadEngFrac300"]->Fill( ev.PFAK5JetNeuHadEngFrac(ixjet1) , w );
      histo1D["PFAK5JetChaEmEngFrac300"]->Fill( ev.PFAK5JetChaEmEngFrac(ixjet1) , w );
      histo1D["PFAK5JetNeuEmEngFrac300"]->Fill( ev.PFAK5JetNeuEmEngFrac(ixjet1) , w ); 
    }
    
    histo1D["EnergyScale"]->Fill(ev.EnergyScale());
    histo2D["UncerVsJetPt"]->Fill(ev.PFAK5JetPtCor(ixjet1) ,ev.PFAK5uncer(ixjet1), w);  
    histo2D["UncerVsJetEta"]->Fill(ev.PFAK5JetEta(ixjet1) , ev.PFAK5uncer(ixjet1), w);  
     
    histo1D["GenJet1Pt"] ->Fill( ev.GenAK5JetPt(0),  w );  
    
    double  METplusMuPt=0,METplusMuPx=ev.MetPx(t) ,METplusMuPy=ev.MetPy(t) ;
    for(int i=0; i<ev.NPFMuon(); i++){
      METplusMuPx =  METplusMuPx+ ev.PFMuonPx(i);
      METplusMuPy =  METplusMuPy + ev.PFMuonPy(i);
    }
    METplusMuPt= sqrt( METplusMuPx*METplusMuPx + METplusMuPy*METplusMuPy );
    
    for(int i=0; i<ev.NGenPar(); i++){
      if( ( abs(ev.GenParId(i) )==12 ||  abs(ev.GenParId(i)) ==14 || abs(ev.GenParId(i)) ==16 ) && ev.GenParStatus(i)==3  ){      
	histo1D["GenZnunuEta"]->Fill( ev.GenParEta(i), w );
	histo1D["GenZnunuPt"]->Fill( ev.GenParPt(i) , w );  
      }
      if(abs(ev.GenParId(i) )==24 && ev.GenParStatus(i)==2 ){
	histo1D["GenWPt"]->Fill( ev.GenParPt(i), w );
	histo2D["GenJet1ptvsWpt"]->Fill( ev.GenAK5JetPt(0), ev.GenParPt(i), w );
	histo2D["RecJet1ptvsWpt"]->Fill( ev.PFAK5JetPtCor(ixjet1), ev.GenParPt(i), w );
	histo2D["METmuvsWpt"]->Fill( METplusMuPt, ev.GenParPt(i), w );   
	histo1D["METoverWpt"]->Fill( METplusMuPt/ ev.GenParPt(i), w ); 
      }
      if(abs(ev.GenParId(i) )==23 && ev.GenParStatus(i)==2 ){
	histo1D["GenZPt"]->Fill( ev.GenParPt(i), w );
	histo2D["GenJet1ptvsZpt"]->Fill( ev.GenAK5JetPt(0), ev.GenParPt(i), w );
	histo2D["RecJet1ptvsZpt"]->Fill( ev.PFAK5JetPtCor(ixjet1), ev.GenParPt(i), w );
	histo2D["METmuvsZpt"]->Fill( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ), ev.GenParPt(i), w );   
	histo1D["METoverZpt"]->Fill( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev )/ ev.GenParPt(i), w ); 
      }
      if( abs(ev.GenParId(i) )==11 && ev.GenParStatus(i)==3 )  histo1D["Met_Wenu"]->Fill( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) ,w );
      if( abs(ev.GenParId(i) )==13 && ev.GenParStatus(i)==3 )  histo1D["Met_Wmnu"]->Fill( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) ,w );
      if( abs(ev.GenParId(i) )==15 && ev.GenParStatus(i)==3 )  histo1D["Met_Wtnu"]->Fill( MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) ,w );
    }
    
    /*for(int i=0; i<ev.NGenPar(); i++)
      {
      if(abs(ev.GenParId(i) )==11 && ev.GenParStatus(i)==3 )
      {
      histo1D["GenElecPt"]->Fill( ev.GenParPt(i), w );
      }
      else if(abs(ev.GenParId(i) )==13 && ev.GenParStatus(i)==3 )
      {
      histo1D["GenMuonPt"]->Fill( ev.GenParPt(i), w );
      
      }
      else if(abs(ev.GenParId(i) )==15 && ev.GenParStatus(i)==3 )
      {
      histo1D["GenTauPt"]->Fill( ev.GenParPt(i), w );
      }
      }*/
    
    
    /*
      
    for(int i=0; i<45; i++ )
    {
    char his[100];
    sprintf(his,"PDF%d", i);
    
    //double w = ev.PDFWeight(i) * ev.PDFWeights(0) / ev.PDFWeight(0);
    //if(ev.PDFWeight(0) >0) histo1D[his]->Fill( 5 , w );
    
    histo1D[his]->Fill( 5 , ev.PDFWeight(i) );
    
    //histo1D["nnpdf20"]->Fill(w);
    //double delta= ( ev.PDFWeight(i) * ev.PDFWeights(0) / ev.PDFWeight(0) ) - ev.PDFWeights(0); 
    //if (delta>0)   histo1D["nnpdf20_p"]->Fill(delta);
    //else           histo1D["nnpdf20_m"]->Fill(delta);
    }
    
    
    if(ev.PDFWeight(0)>0)
    {
    
    //use these ones if  you used  CTEQ  for  alphaS  uncert..
    histo1D["alphas_m"]->Fill( 5 , ev.PDFWeightAlphaS(1) * ev.PDFWeights(0) / ev.PDFWeight(0) );
    histo1D["alphas"]->Fill( 5 , ev.PDFWeightAlphaS(2) * ev.PDFWeights(0) / ev.PDFWeight(0) );
    histo1D["alphas_p"]->Fill( 5 , ev.PDFWeightAlphaS(3) * ev.PDFWeights(0) / ev.PDFWeight(0) );
    
    //use these ones if you used  MSTW  for  alphaS  uncert..
    //histo1D["alphas_m"]->Fill( 5 , ev.PDFWeightAlphaSmstw(0) * ev.PDFWeights(0) / ev.PDFWeight(0) );
    //histo1D["alphas"]->Fill( 5 , ev.PDFWeights(0) );
    //histo1D["alphas_p"]->Fill( 5 , ev.PDFWeightAlphaSmstw(1) * ev.PDFWeights(0) / ev.PDFWeight(0) );
    
    //for now  there is no  nnpdf  alphas  uncert
    
    
    } 
    
    
    for(int i=0; i<ev.NGenPar(); i++)
    {
    histo1D["GravitonPt"]->Fill( ev.GenParPt(i), w );
    
    if( ev.GenParMother1(i)==21 &&  ev.GenParMother2(i)==21  ) histo1D["GravitonPt_gg"]->Fill( ev.GenParPt(i), w );
    
    if( (ev.GenParMother1(i)==21 ||  ev.GenParMother2(i)==21 )  && 
    (  ( abs(ev.GenParMother1(i))>0 && abs(ev.GenParMother1(i))<9  )  ||  ( abs(ev.GenParMother2(i))>0 && abs(ev.GenParMother2(i))<9  )  ) )
    {
    histo1D["GravitonPt_qg"]->Fill( ev.GenParPt(i) , w);
    }
    if(   ( abs(ev.GenParMother1(i))>0 && abs(ev.GenParMother1(i))<9  )  &&  ( abs(ev.GenParMother2(i))>0 && abs(ev.GenParMother2(i))<9   ) )
    {
    histo1D["GravitonPt_qq"]->Fill( ev.GenParPt(i) , w );
    }
    }*/
    
    // Abnormal events
    histo1D["MetPF"]->Fill(ev.MetPt(10),w);
    histo1D["MetCalo"]->Fill(ev.MetPt(0),w);
    histo1D["MetTc"]->Fill(ev.MetPt(20),w);
    
    histo2D["MetPF-Calo"]->Fill(ev.MetPt(10), ev.MetPt(0), w);
    histo2D["MetPF-Tc"]->Fill(ev.MetPt(10),   ev.MetPt(20),w);           
    histo2D["MetTc-Calo"]->Fill(ev.MetPt(20), ev.MetPt(0), w);
    
    
    // WideJet
    int ixwjet1 = WideJetIndex(0, ev); 
    int ixwjet2 = WideJetIndex(1, ev);
    int nwjets = WideJetNumber(ev);
    TLorentzVector leadJet = WideJet1(ev);
    //plots
    if(ixwjet1<99){
      histo1D["WideJet1Pt"]->Fill(leadJet.Pt(),w); 
      histo1D["WideJet1Pt3"]->Fill(leadJet.Pt(),w); 
      histo1D["WideJet1Eta"]->Fill(leadJet.Eta(),w);
      if(ixwjet2!=99){
	histo1D["WideJet2Pt"]->Fill(ev.PFAK5JetPtCor(ixwjet2),w);
	histo1D["WideJet2Eta"]->Fill(ev.PFAK5JetEta(ixwjet2),w);
	histo1D["dPhi_WideJet1_Jet2"]->Fill(fabs(deltaPhi(leadJet.Phi(), ev.PFAK5JetPhi(ixwjet2))),w);
      }  
    }
    histo1D["NWideJet"]->Fill(nwjets);
    
    return true;
  }
  
  std::ostream& hDataMcMatching::Description(std::ostream &ostrm){
    ostrm << "  DataMcMatching (output in " << mFileName << "):";
    return ostrm;
  }
  
  hDataMcMatching::~hDataMcMatching(){  
    double a1=0, a2=0;
    for(int i=41; i>0; i--){		
      
      a1=a1+histo1D["MetLep1"]->GetBinContent(i);
      histo1D["MetLepThrs1"]->SetBinContent( i , a1 );
      
      a2=a2+histo1D["Jet1Pt"]->GetBinContent(i);
      histo1D["Jet1PtThrs"]->SetBinContent( i , a2 );
    }
    
    double a5=0;
    for(int i=33; i>0; i--){
      a5=a5+histo1D["MetLep2"]->GetBinContent(i);
      histo1D["MetLepThrs2"]->SetBinContent( i , a5 );  
    }
    for(int i=1; i<33 ; i++){	
      double a6= histo1D["MetLep4"]->GetBinContent(i);
      histo1D["MetLep3"]->SetBinContent( i , a6 );
    }
    for(int i=1; i<41 ; i++){	
      double a7= histo1D["Jet1Pt3"]->GetBinContent(i);
      histo1D["Jet1Pt2"]->SetBinContent( i , a7 );
    }
    for(int i=1; i<41 ; i++){	
      double a8= histo1D["WideJet1Pt3"]->GetBinContent(i);
      histo1D["WideJet1Pt2"]->SetBinContent( i , a8 );
    }
    
    histo1D["NJet5"]->SetBinContent( 1 , histo1D["NJet55"]->GetBinContent(1) );
    histo1D["NJet5"]->SetBinContent( 2 , histo1D["NJet55"]->GetBinContent(2) );
    histo1D["NJet5"]->SetBinContent( 3 , histo1D["NJet55"]->GetBinContent(3) );
    histo1D["NJet5"]->SetBinContent( 4 , histo1D["NJet55"]->GetBinContent(4) );
    histo1D["NJet5"]->SetBinContent( 5 , histo1D["NJet55"]->GetBinContent(5) + histo1D["NJet55"]->GetBinContent(6) );
    
    histo1D["NJet6"]->SetBinContent( 1 , histo1D["NJet66"]->GetBinContent(1) );
    histo1D["NJet6"]->SetBinContent( 2 , histo1D["NJet66"]->GetBinContent(2) );
    histo1D["NJet6"]->SetBinContent( 3 , histo1D["NJet66"]->GetBinContent(3) );
    histo1D["NJet6"]->SetBinContent( 4 , histo1D["NJet66"]->GetBinContent(4) );
    histo1D["NJet6"]->SetBinContent( 5 , histo1D["NJet66"]->GetBinContent(5) );
    histo1D["NJet6"]->SetBinContent( 6 , histo1D["NJet66"]->GetBinContent(6) + histo1D["NJet55"]->GetBinContent(7) );
    
    //histo1D["MetLep1_eff"]->Divide( histo1D["MetLep1_cm"], histo1D["MetLep1"] , 1.0, 1.0 ); 	  
    
    fileOut->Write();
    delete fileOut;	
  }
  
  
  ///============================================================================================================================================
  
  
  ///---------------------------WZ Analysis---------------------------------------------------------------------------------------
  hWZAnalysis::hWZAnalysis(const std::string & fileName):
    mFileName(fileName)
  {
    fileOut = new TFile(mFileName.c_str(),"recreate");
    
    histo1D["NofLep"]             = new TH1D("NofLep"             , "Number of Lep"                , 10, 0, 10);
    histo1D["NofLep2"]            = new TH1D("NofLep2"            , "Number of Lep"                , 10, 0, 10);
    histo1D["NofLepSign"]         = new TH1D("NofLepSign"         , "Number of Lep Sign"           , 40, 0, 40);
    
    histo1D["WlepnuMT"]           = new TH1D("WlepnuMT"           , "Wlepnu m_{T}"                 , 50, 0, 500);
    histo1D["WlepnuMT_50_100"]    = new TH1D("WlepnuMT_50_100"    , "Wlepnu m_{T}   50<m_{T}<100"  , 40, 0, 400);
    
    histo1D["WlepnuPT"]           = new TH1D("WlepnuPT"           , "Wlepnu p_{T}"                 , 22, 350, 900);
    histo1D["WlepnuPT_50_100"]    = new TH1D("WlepnuPT_50_100"    , "Wlepnu p_{T}   50<m_{T}<100"  , 22, 350, 900);
    histo1D["WlepnuPT2_50_100"]   = new TH1D("WlepnuPT2_50_100"   , "Wlepnu p_{T}   50<m_{T}<100"  , 26, 250, 900);
    histo1D["WlepnuPT3_50_100"]   = new TH1D("WlepnuPT3_50_100"   , "Wlepnu p_{T}   50<m_{T}<100"  , 30, 150, 900);
    histo1D["WlepnuPT4_50_100"]   = new TH1D("WlepnuPT4_50_100"   , "Wlepnu p_{T}   50<m_{T}<100"  , 36, 0, 900);
    
    histo1D["ZleplepMT"]          = new TH1D("ZleplepMT"          , "Zleplep m_{T}"                , 100, 0, 400);
    histo1D["ZleplepMT_81_101"]   = new TH1D("ZleplepMT_81_101"   , "Zleplep m_{T}  81<m_{T}<101"  , 100, 0, 400);
    
    histo1D["WlepnuMT_2"]         = new TH1D("WlepnuMT_2"         , "Wlepnu m_{T}"                 , 20, 0, 200);
    histo1D["WlepnuMT_50_100_2"]  = new TH1D("WlepnuMT_50_100_2"  , "Wlepnu m_{T}   50<m_{T}<100"  , 20, 0, 200);
    
    histo1D["ZleplepMT_2"]        = new TH1D("ZleplepMT_2"        , "Zleplep m_{T}"                , 50, 0, 200);
    histo1D["ZleplepMT_81_101_2"] = new TH1D("ZleplepMT_81_101_2" , "Zleplep m_{T}  81<m_{T}<101"  , 50, 0, 200);
    histo1D["ZleplepMT_60_120"]   = new TH1D("ZleplepMT_60_120"   , "Zleplep m_{T}  60<m_{T}<120"  , 30, 60,120);
    
    histo1D["ZleplepPT"]          = new TH1D("ZleplepPT"          , "Zleplep p_{T}  "              , 40, 0,800);
    histo1D["ZleplepPT_60_120"]   = new TH1D("ZleplepPT_60_120"   , "Zleplep p_{T}  60<m_{T}<120"  , 40, 0,800);
    
    histo1D["WlepnuMT_300"]      = new TH1D("WlepnuMT_300"        , "Wlepnu m_{T}"                 , 30, 0, 300);
    
    histo1D["WlepnuMT_210"]      = new TH1D("WlepnuMT_210"        , "Wlepnu m_{T}"                 , 21, 0, 210);
    histo1D["WlepnuMT_310"]      = new TH1D("WlepnuMT_310"        , "Wlepnu m_{T}"                 , 31, 0, 310);
    
    histo1D["WlepnuMT_e"]        = new TH1D("WlepnuMT_e"          , "Wlepnu m_{T} for e"           , 80, 0, 400);
    histo1D["WlepnuMT_m"]        = new TH1D("WlepnuMT_m"          , "Wlepnu m_{T} for lep"         , 80, 0, 400);
    histo1D["WlepnuMT_t"]        = new TH1D("WlepnuMT_t"          , "Wlepnu m_{T} for tau"         , 80, 0, 400);
    
    histo1D["WlepnuMT_50_100_e"] = new TH1D("WlepnuMT_50_100_e"   , "Wlepnu m_{T} for e  50<m_{T}<100"      , 80, 0, 400);
    histo1D["WlepnuMT_50_100_m"] = new TH1D("WlepnuMT_50_100_m"   , "Wlepnu m_{T} for mu  50<m_{T}<100"     , 80, 0, 400);
    histo1D["WlepnuMT_50_100_t"] = new TH1D("WlepnuMT_50_100_t"   , "Wlepnu m_{T} for tau  50<m_{T}<100"    , 80, 0, 400);
    
    histo1D["njets_1"]           = new TH1D("njets_1"              , "NJet for  Wlepnu "                 , 10, 0, 10);
    histo1D["njets_2"]           = new TH1D("njets_2"              , "NJet for  Wlepnu  50<m_{T}<100 "   , 10, 0, 10);
    
    histo1D["njets_3"]           = new TH1D("njets_3"              , "NJet for  Zleplep "                , 10, 0, 10);
    histo1D["njets_4"]           = new TH1D("njets_4"              , "NJet for  Zleplep  81<m_{T}<101 "  , 10, 0, 10);
    
    histo1D["dPhiJ1J2"]          = new TH1D("dPhiJ1J2"             , "dPhi(Jet1,Jet2)"    , 80, -4, 4);
    
    histo2D["dPhi1_vs_dPhi2"]    = new TH2D("dPhi1_vs_dPhi2"       , "dPhi1 vs dPhi2"     , 40, 0, 4 , 40, 0,4 ); 
    
    histo1D["ZleplepPFMET"]      = new TH1D("ZleplepPFMET"         , "PFMET for Z #lep #lep "      , 100, 0, 800);
    
    
    histo1D["METparalle"]        = new TH1D("METparalle"           , "PFMET Paralle "         , 100, -100, 100);
    histo1D["METperpendicular"]  = new TH1D("METperpendicular"     , "PFMET Perpendicular"    , 100, -100, 100);
    histo1D["DPhiPFMetDiLep"]    = new TH1D("DPhiPFMetDiLep"       , "DPhi PFMET DiLep"       , 100, -4, 4);
    
    histo1D["PhiDiLep"]          = new TH1D("PhiDiLep"             , "Phi DiLep"            , 100, -4, 4);
    
    histo1D["DPhiPFMetDiLep2"]   = new TH1D("DPhiPFMetDiLep2"      , "DPhi PFMET DiLep"     , 100, -4, 4);
    
    histo1D["METPar1"]   = new TH1D("METPar1"     , "MET Paralelle"        , 100, -100, 100);
    histo1D["METPar2"]   = new TH1D("METPar2"     , "MET Paralelle"        , 100, -100, 100);
    histo1D["METPar3"]   = new TH1D("METPar3"     , "MET Paralelle"        , 100, -100, 100);	
    
    histo1D["dRPFMuonRegMuon"]   = new TH1D("dRPFMuonRegMuon"     , "dRPFMuonRegMuon"        ,700, -1, 6);	
    
    //hprof  = new TProfile("hprof","Profile of pz versus px",100,-4,4,0,20);
    
    histo1D["GenMuonPt"]         = new TH1D("GenMuonPt"          , "Gen Muon p_{T}"                   , 10, 0, 10);
    histo1D["GenMuonPt_10"]      = new TH1D("GenMuonPt_10"       , "Gen Muon p_{T}>10 |#eta|<2.4"     , 10, 0, 10);
    histo1D["GenMuonPt_20"]      = new TH1D("GenMuonPt_20"       , "Gen Muon p_{T}>20 |#eta|<2.1"     , 10, 0, 10);
    histo1D["IsoMuonPt_10"]      = new TH1D("IsoMuonPt_10"       , "Iso Muon pt>10 |eta|<2.4"              , 10, 0, 10);
    histo1D["IsoMuonPt_20"]      = new TH1D("IsoMuonPt_20"       , "Iso Muon pt>20 |eta|<2.1  50<WMT<100"  , 10, 0, 10);
    
    histo1D["GenElecPt"]         = new TH1D("GenElecPt"          , "Gen Elec p_{T}"                   , 10, 0, 10);
    histo1D["GenElecPt_10"]      = new TH1D("GenElecPt_10"       , "Gen Elec p_{T}>10"                , 10, 0, 10);
    histo1D["GenElecPt_20"]      = new TH1D("GenElecPt_20"       , "Gen Elec p_{T}>20 |#eta|<2.5"     , 10, 0, 10);
    histo1D["IsoElecPt_10"]      = new TH1D("IsoElecPt_10"       , "Iso Elec pt>10"                       , 10, 0, 10);
    histo1D["IsoElecPt_20"]      = new TH1D("IsoElecPt_20"       , "Iso Elec pt>20 |eta|<2.5 50<WMT<100"  , 10, 0, 10);
    
    
    histo1D["GenTauPt"]          = new TH1D("GenTauPt"           , "Gen Tau p_{T}"                    , 10, 0, 10);			
    histo1D["GenTauElecPt"]      = new TH1D("GenTauElecPt"       , "Gen Elec from Tau p_{T}"          , 10, 0, 10);
    histo1D["GenTauMuonPt"]      = new TH1D("GenTauMuonPt"       , "Gen Muon from Tau p_{T}"          , 10, 0, 10);
    histo1D["GenTauElecPt_10"]   = new TH1D("GenTauElecPt_10"    , "Iso Elec from Tau p_{T}>10"       , 10, 0, 10);
    histo1D["GenTauMuonPt_10"]   = new TH1D("GenTauMuonPt_10"    , "Iso Muon from Tau p_{T}>10"       , 10, 0, 10);
    histo1D["IsoTauElecPt_10"]   = new TH1D("IsoTauElecPt_10"    , "Iso Elec from Tau p_{T}>10"       , 10, 0, 10);
    histo1D["IsoTauMuonPt_10"]   = new TH1D("IsoTauMuonPt_10"    , "Iso Muon from Tau p_{T}>10"       , 10, 0, 10);
    
    
    // Bins definitions
    // 2:GenMuonPt  3:GenMuonPt_10  4:GenMuonPt_20 5:IsoMuonPt_10 6:IsoMuonPt_20  
    // 7:GenElecPt  8:GenElecPt_10  9:GenElecPt_20  10:IsoElecPt_10  11:IsoElecPt_20
    // 12:GenTauPt  13:GenTauElecPt  14:GenTauMuonPt  15:GenTauElecPt_10  16:GenTauMuonPt_10  17:IsoTauElecPt_10  18:IsoTauMuonPt_10  
    // 19: NumOf Iso DiMuon MassWindow   20: NumOf NoMuon 21: NumOf Iso Single Muon   22: NumOf Iso DiMuon 23: NumOf Iso 3Muon 
      
    histo1D["WZEstimation"]      = new TH1D("WZEstimation"    ,"All variable for WZ estimation" , 40, 0, 40); 
    histo2D["ElectronPtEta"]     = new TH2D("ElectronPtEta"   ,"dPhi1 vs dPhi2"     , 40, 0, 200, 25, 0,2.5); 

  }
	
  // --------------- Histograms Filling------------------------------------------------------------------------
  bool hWZAnalysis::Process(EventData & ev) 
  {
    int  t= ev.MetType(); 
    double w= ev.Weight(); 
    int njets= JetNumber(ev);
    int ixjet1= JetIndex(0, ev);
    int ixjet2= JetIndex(1, ev);	
    
    double dPhi1= fabs( deltaPhi( ev.PFAK5JetPhi(ixjet1), MetLepPhi( ev.MetPx(t) , ev.MetPy(t) , ev ) ) );
    double dPhi2= fabs( deltaPhi( ev.PFAK5JetPhi(ixjet2), MetLepPhi( ev.MetPx(t) , ev.MetPy(t) , ev ) ) ); 
    
    if(njets==2)
      {
	histo1D["dPhiJ1J2"]->Fill( deltaPhi( ev.PFAK5JetPhi(ixjet1) , ev.PFAK5JetPhi(ixjet2)  ) , w );
	histo2D["dPhi1_vs_dPhi2"]->Fill( dPhi1, dPhi2 , w );
      }
    
    int IsoLepIndex=0;	
    
    int isoLepPseq[20], isoLepMseq[20], isoLepPnum=0,isoLepMnum=0; //=0 for isoMuPnum,isoMuMnum 
    
    for (int i=0; i<20; i++) 
      {
	isoLepPseq[i]=0; isoLepMseq[i]=0;
      }
    
    //---------- IsoMuon index counting for Zmumu---------------------------- 
    
    
    bool check2=true;
    for(int i=0; i<ev.NPFLep(); i++ )
      {
	bool check1=true;	
	if( PFLepTightCuts(ev ,i ) )
	  {
	    check1=false;
	    IsoLepIndex++;
	    //LepCharge = ev.PFLepCharge(i);
	    
	    if(ev.PFLepCharge(i)<0)
	      {
		isoLepMseq[isoLepMnum]=i;
		isoLepMnum++;
	      }
	    else if(ev.PFLepCharge(i)>0)
	      {
		isoLepPseq[isoLepPnum]=i;
		isoLepPnum++;
	      }
	  }
	if(check1 && check2)
	  {
	    check2=false;
	    //IsoLepIndex++;
	    if(ev.PFLepCharge(i)<0)
	      {
		isoLepMseq[isoLepMnum]=i;
		isoLepMnum++;
	      }
	    else if(ev.PFLepCharge(i)>0)
	      {
		isoLepPseq[isoLepPnum]=i;
		isoLepPnum++;
	      }
	  }
      }
    histo1D["NofLep"]->Fill(IsoLepIndex , w );
    histo1D["NofLep2"]->Fill(ev.NPFMuon() , w ); 
    
    
    // ------------Lost mu, e, tau estimation------------------------------
    bool  checkMuonStatus=false, checkElecStatus=false;
    bool  checkTauMuonStatus = false, checkTauElecStatus=false;
    
    for(int i=0; i<ev.NGenPar(); i++)
      {
	if( abs(ev.GenParId(i))==11 && ev.GenParStatus(i)==3   )
	  {
	    double_t eWeight = electronWeight(ev.GenParPt(i),ev.GenParEta(i));
	    if( ev.GenParPt(i)>10 ) histo1D["WZEstimation"]->Fill(  7 , w );
	    if( ev.GenParPt(i)>20 && abs(ev.GenParEta(i))<2.5 ) histo1D["WZEstimation"]->Fill( 8 , w );
	    histo1D["WZEstimation"]->Fill( 6, w*eWeight );
	    checkElecStatus=true;
	  }
	if( abs(ev.GenParId(i))==13 && ev.GenParStatus(i)==3  )
	  {
	    if( ev.GenParPt(i)>10 ) histo1D["WZEstimation"]->Fill( 2 , w );
	    if( ev.GenParPt(i)>20 && abs(ev.GenParEta(i))<2.1 ) histo1D["WZEstimation"]->Fill( 3 , w );
	    if( ev.GenParPt(i)>0 ) histo1D["WZEstimation"]->Fill( 1 , w );	  
	    checkMuonStatus=true;
	  }
	if(abs(ev.GenParId(i) )==15 && ev.GenParStatus(i)==3 )
	  {
	    histo1D["WZEstimation"]->Fill( 11 , w );
	  }		
	if( abs(ev.GenParId(i))==11 && ev.GenParStatus(i)==1 && abs(ev.GenParDoughterOf(i)) ==15 )
	  {
	    double_t eWeight = electronWeight(ev.GenParPt(i),ev.GenParEta(i));
	    histo1D["WZEstimation"]->Fill( 12, w*eWeight );
	    if( ev.GenParPt(i)>10 ) histo1D["WZEstimation"]->Fill( 14 , w ); 
	    if( ev.GenParPt(i)>20 && abs(ev.GenParEta(i))<2.5 ) histo1D["WZEstimation"]->Fill( 35 , w );
	    checkTauElecStatus = true;
	  }
	if( abs(ev.GenParId(i))==13 && ev.GenParStatus(i)==1 && abs(ev.GenParDoughterOf(i)) ==15 )
	  {
	    histo1D["WZEstimation"]->Fill( 13 ,  w );
	    if( ev.GenParPt(i)>10 ) histo1D["WZEstimation"]->Fill( 15 , w );
	    if( ev.GenParPt(i)>20 && abs(ev.GenParEta(i))<2.1 ) histo1D["WZEstimation"]->Fill( 37 , w );
	    checkTauMuonStatus = true;
	  }
      }
    
    for(int i=0; i<ev.NPFMuon(); i++ ){
      //if( PFMuonTightCuts(ev ,i, 10., 66.)  )//66  means  no eta cut
      if( PFMuonLooseCuts(ev ,i, 10., 66.)  )//66  means  no eta cut   
	{
	  if(checkMuonStatus) histo1D["WZEstimation"]->Fill( 4 , w );	
	  if(checkTauMuonStatus)  histo1D["WZEstimation"]->Fill( 17 , w );	
	  
	}
    }
    
    for(int i=0; i<ev.NPFElec(); i++ )
      {
	//if( PFElecTightCuts(ev ,i, 10., 66.) )  //66  means  no eta cut
	if( PFElecVetoCuts(ev ,i, 10., 66.)  )//66  means  no eta cut 
	  {  
	    double_t eWeight = electronWeight(ev.PFElecPt(i),ev.PFElecEta(i));
	    //std::cout<<"Electron Weight = "<<eWeight<<endl;
	    if(checkElecStatus) histo1D["WZEstimation"]->Fill( 9 , w*eWeight );	
	    if(checkTauElecStatus)  histo1D["WZEstimation"]->Fill( 16 , w*eWeight ); 
	    histo2D["ElectronPtEta"]->Fill(ev.PFElecPt(i),ev.PFElecEta(i)); 	
	  }
      }
    
    //------------------------------------------------------------------------
    
    
    //----------deltaR between PFMuon and Regular Muon-------------------------
    for(int i=0; i<ev.NPFMuon(); i++ ){
      for(int j=0; j<ev.NMuon(); j++ ){
	double dr = deltaR( ev.PFMuonEta(i), ev.PFMuonPhi(i), ev.MuonEta(j), ev.MuonPhi(j) );
	if( PFMuonTightCuts(ev, i) && IsIsoMuon(j, ev) ) histo1D["dRPFMuonRegMuon"]->Fill( dr );
      }
    }
    
    double WlepnuMT=0;
    if(IsoLepIndex==1){
      double MTPt=0;
      for(int i=0; i<ev.NPFLep(); i++ ){
	if( PFLepTightCuts(ev ,i) )
	  {  
	    double MTEn= ev.PFLepPt(i)+ ev.MetPt(t);
	    double MTPx= ev.PFLepPx(i)+ ev.MetPx(t);
	    double MTPy= ev.PFLepPy(i)+ ev.MetPy(t);
	    
	    MTPt=sqrt(MTPx*MTPx+MTPy*MTPy);
	    WlepnuMT=sqrt((MTEn*MTEn)-(MTPt*MTPt));
	  }
      } 
      
      if(WlepnuMT>0)
	{
	  histo1D["WlepnuPT"]->Fill( MTPt, w );
	  histo1D["WlepnuMT"]->Fill( WlepnuMT, w );
	  histo1D["WlepnuMT_2"]->Fill( WlepnuMT, w );
	  histo1D["WlepnuMT_300"]->Fill( WlepnuMT, w );
	  
	  histo1D["njets_1"]->Fill( njets, w );
	  
	  for(int i=0; i<ev.NGenPar(); i++)
	    {
	      if(abs(ev.GenParId(i) )==11 && ev.GenParStatus(i)==3 )
		{
		  histo1D["WlepnuMT_e"]->Fill( WlepnuMT, w );
		}
	      else if(abs(ev.GenParId(i) )==13 && ev.GenParStatus(i)==3 )
		{
		  histo1D["WlepnuMT_m"]->Fill( WlepnuMT, w );
		  
		}
	      else if(abs(ev.GenParId(i) )==15 && ev.GenParStatus(i)==3 )
		{
		  histo1D["WlepnuMT_t"]->Fill( WlepnuMT, w );
		}
	    }
	}
      
      if( WlepnuMT>50 && WlepnuMT<100 )
	{
	  if(checkMuonStatus) histo1D["WZEstimation"]->Fill( 5 , w ); 
	  if(checkTauMuonStatus) histo1D["WZEstimation"]->Fill( 36 , w );
	  
	  if(checkElecStatus) histo1D["WZEstimation"]->Fill( 10 , w );
	  if(checkTauElecStatus) histo1D["WZEstimation"]->Fill( 38 , w );
	  
	  histo1D["WlepnuPT_50_100"]->Fill( MTPt, w );
	  histo1D["WlepnuPT2_50_100"]->Fill( MTPt, w ); 
	  histo1D["WlepnuPT3_50_100"]->Fill( MTPt, w );
	  histo1D["WlepnuPT4_50_100"]->Fill( MTPt, w );		  
	  
	  histo1D["WlepnuMT_50_100"]->Fill( WlepnuMT, w );
	  histo1D["WlepnuMT_50_100_2"]->Fill( WlepnuMT, w );
	  
	  histo1D["njets_2"]->Fill( njets, w );
	  
	  for(int i=0; i<ev.NGenPar(); i++){
	    if(abs(ev.GenParId(i) )==11 && ev.GenParStatus(i)==3 )
	      {
		histo1D["WlepnuMT_50_100_e"]->Fill( WlepnuMT, w );
	      }
	    else if(abs(ev.GenParId(i) )==13 && ev.GenParStatus(i)==3 )
	      {
		histo1D["WlepnuMT_50_100_m"]->Fill( WlepnuMT, w );
	      }
	    else if(abs(ev.GenParId(i) )==15 && ev.GenParStatus(i)==3 )
	      {
		histo1D["WlepnuMT_50_100_t"]->Fill( WlepnuMT, w );
	      }
	    
	  }
	} 
    }
    
    //-------------Zmumu  identification------------------------------------	
    if( isoLepPnum==1 &&  isoLepMnum==1)
      //if( (isoLepPnum==1 && isoLepMnum==1) || (isoLepPnum==0 && isoLepMnum==1) || (isoLepPnum==1 && isoLepMnum==0) )
      {
	
	double dilepPhi =0;
	double ZleplepMT=0;
	double ZPt=0;
	
	for(int i=0; i<isoLepMnum ; i++ )
	  {
	    int ixmum=isoLepMseq[i];
	    
	    for(int j=0; j<isoLepPnum ; j++ )
	      {  
		int ixmup=isoLepPseq[j] ;
		
		double ZEn= ev.PFLepE(ixmup)  + ev.PFLepE(ixmum) ;
		double ZPx= ev.PFLepPx(ixmup) + ev.PFLepPx(ixmum);
		double ZPy= ev.PFLepPy(ixmup) + ev.PFLepPy(ixmum);
		double ZPz= ev.PFLepPz(ixmup) + ev.PFLepPz(ixmum);
		
		ZPt=sqrt(ZPx*ZPx + ZPy*ZPy);
		
		ZleplepMT=sqrt((ZEn*ZEn)-(ZPt*ZPt)-(ZPz*ZPz));
		
		dilepPhi = atan2( ZPy, ZPx);
	      }
	  } 
	
	if(ZleplepMT>0)
	  {
	    histo1D["ZleplepPT"]->Fill( ZPt, w );
	    histo1D["ZleplepMT"]->Fill( ZleplepMT, w );
	    histo1D["ZleplepMT_2"]->Fill( ZleplepMT, w );
	    histo1D["njets_3"]->Fill( njets, w );
	  }
	
	if( ZleplepMT>81 && ZleplepMT<101 )
	  {
	    histo1D["ZleplepMT_81_101"]->Fill( ZleplepMT, w );
	    histo1D["ZleplepMT_81_101_2"]->Fill( ZleplepMT, w );
	    
	  }
	if( ZleplepMT>60 && ZleplepMT<120 )
	  {
	    histo1D["WZEstimation"]->Fill( 18, w );
	    
	    histo1D["ZleplepMT_60_120"]->Fill( ZleplepMT, w );
	    histo1D["ZleplepPT_60_120"]->Fill( ZPt, w );
	    
	    double  METparalle = ev.MetPt(t) * cos( deltaPhi( ev.MetPhi(t), dilepPhi ) );
	    double  METperpendicular = ev.MetPt(t) * sin( deltaPhi( ev.MetPhi(t), dilepPhi ) );
	    
	    histo1D["METparalle"]->Fill(  METparalle , w ); 
	    histo1D["METperpendicular"] ->Fill( METperpendicular , w );
	    histo1D["DPhiPFMetDiLep"]->Fill(  deltaPhi( ev.MetPhi(t), dilepPhi )  , w );
	    
	    histo1D["DPhiPFMetDiLep2"]->Fill(  ev.MetPhi(t)- dilepPhi  , w );
	    
	    
	    histo1D["PhiDiLep"]->Fill(  dilepPhi  , w );
	    
	    if(ev.NPV()>1 && ev.NPV()<4) histo1D["METPar1"]->Fill(  METparalle , w ); 
	    if(ev.NPV()>3 && ev.NPV()<9) histo1D["METPar2"]->Fill(  METparalle , w ); 
	    if(ev.NPV()>8 ) histo1D["METPar3"]->Fill(  METparalle , w ); 
	    
	    histo1D["njets_4"]->Fill( njets, w );
	    histo1D["ZleplepPFMET"]->Fill( ev.MetPt(t), w );
	    
	  }
      }  
    return true;
  }
  
  std::ostream& hWZAnalysis::Description(std::ostream &ostrm) 
  {
    ostrm << "  WZ Analysis (output in " << mFileName << "):";
    return ostrm;
  }
  
  //-------------- End Job-----------------------------------------------------------------------------------
  hWZAnalysis::~hWZAnalysis() 
  {	
    // Bins definitions
    // 2:GenMuonPt  3:GenMuonPt_10  4:GenMuonPt_20 5:IsoMuonPt_10 6:IsoMuonPt_20  
    // 7:GenElecPt  8:GenElecPt_10  9:GenElecPt_20  10:IsoElecPt_10  11:IsoElecPt_20
    // 12:GenTauPt  13:GenTauElecPt  14:GenTauMuonPt  15:GenTauElecPt_10  16:GenTauMuonPt_10  17:IsoTauElecPt_10  18:IsoTauMuonPt_10  
    // 19: NumOf Iso DiMuon MassWindow   20: NumOf NoMuon 21: NumOf Iso Single Muon   22: NumOf Iso DiMuon 23: NumOf Iso 3Muon 
    
    histo1D["WZEstimation"]->SetBinContent( 20 , histo1D["NofLep"]->GetBinContent(1)  );
    histo1D["WZEstimation"]->SetBinContent( 21 , histo1D["NofLep"]->GetBinContent(2)  );
    histo1D["WZEstimation"]->SetBinContent( 22 , histo1D["NofLep"]->GetBinContent(3)  );
    histo1D["WZEstimation"]->SetBinContent( 23 , histo1D["NofLep"]->GetBinContent(4)  );
    
    
    for(int i=1; i<22; i++)
      {
	double a1= histo1D["WlepnuMT_2"]->GetBinContent(i);
	histo1D["WlepnuMT_210"]->SetBinContent( i , a1 );
	
      }
    for(int i=1; i<32; i++)
      {
	double a1= histo1D["WlepnuMT_300"]->GetBinContent(i);
	histo1D["WlepnuMT_310"]->SetBinContent( i , a1 );
	
      }
    
    
    fileOut->Write();
    delete fileOut;	
  }
  
  
  ///============================================================================================================================================
  
  
  
  ///---------------------------Source of W after Monojet Cuts Analysis -----------------------------------------------------------------------
  
  //----------------MuonAnalysis Histograms  Defination--------------------------------------------------------------------
  
  hWSourceAnalysis::hWSourceAnalysis(const std::string & fileName):
    mFileName(fileName)
  {
    fileOut = new TFile(mFileName.c_str(),"recreate");
    histo1D["WplusPT"]              = new TH1D("WplusPT"         , "WplusPT"           , 100, 0, 1000);
    histo1D["WminusPT"]             = new TH1D("WminusPT"        , "WminusPT"          , 100, 0, 1000);
    
    histo1D["WPT"]                  = new TH1D("WPT"             , "WPT"               , 100, 0, 1000);
    
    histo1D["WplusRminus"]          = new TH1D("WplusRminus"     , "WplusRminus"       , 100, 0, 1000);
    
    
    histo1D["PFMuonIsTracker"]        = new TH1D("PFMuonIsTracker"     , "WplusRminus"       , 10, 0, 10); 
    histo1D["PFMuonIsGlobal"]         = new TH1D("PFMuonIsGlobal"      , "WplusRminus"       , 10, 0, 10);
    histo1D["PFMuonCombChi2Norm"]     = new TH1D("PFMuonCombChi2Norm"  , "WplusRminus"       , 100, 0, 100);
    histo1D["PFMuonNumOfMatches"]     = new TH1D("PFMuonNumOfMatches"  , "WplusRminus"       , 100, 0, 100);
    histo1D["PFMuonTrkDxy"]           = new TH1D("PFMuonTrkDxy"        , "WplusRminus"       , 100, 0, 2);
    histo1D["PFMuonTrkValidHits"]          = new TH1D("PFMuonTrkValidHits"            , "WplusRminus"       , 100, 0, 100);
    histo1D["PFMuonTrkNumOfValidPixHits"]  = new TH1D("PFMuonTrkNumOfValidPixHits"    , "WplusRminus"       , 100, 0, 100);     
    histo1D["PFMuonStandValidHits"]        = new TH1D("PFMuonStandValidHits"          , "WplusRminus"       , 100, 0, 100);     
    histo1D["PFMuonPt"]                    = new TH1D("PFMuonPt"  , "WplusRminus"       , 100, 0, 1000);     
    histo1D["PFMuonEta"]                   = new TH1D("PFMuonEta" , "WplusRminus"       , 100, -4, 4);  
    
    histo1D["PFMuonIso"]                   = new TH1D("PFMuonIso" , "WplusRminus"       , 300, -1, 2);    
    
  }
  
  
  // ---------------MuonANalysis Histograms Filling------------------------------------------------------------------------
  
  bool hWSourceAnalysis::Process(EventData & ev) 
  {
    
    //double w= ev.Weight();
    //int  t= ev.MetType(); 
    
    
    /*for(int i=0; i<ev.NGenPar(); i++)
      {
      
      if(abs(ev.GenParId(i) )==24 && ev.GenParStatus(i)==3 )
      {
      histo1D["WPT"]->Fill( ev.GenParPt(i) );
      }
      if(abs(ev.GenParId(i) )==24 && ev.GenParStatus(i)==3 && ev.GenParCharge(i)==-1 )
      {
      histo1D["WminusPT"]->Fill( ev.GenParPt(i) );
      
      }
      if(abs(ev.GenParId(i) )==24 && ev.GenParStatus(i)==3 && ev.GenParCharge(i)== 1 )
      {
      histo1D["WplusPT"]->Fill( ev.GenParPt(i) );
      }
      }*/
    
    for(int i=0; i<ev.NPFMuon(); i++){
      histo1D["PFMuonIsTracker"]->Fill(ev.PFMuonIsTracker(i)  );
      histo1D["PFMuonIsGlobal"]->Fill(ev.PFMuonIsGlobal(i)  );
      histo1D["PFMuonNumOfMatches"]->Fill(ev.PFMuonNumOfMatches(i)  );
      histo1D["PFMuonCombChi2Norm"]->Fill(ev.PFMuonCombChi2Norm(i)  );
      histo1D["PFMuonTrkDxy"]->Fill(ev.PFMuonTrkDxy(i)  );
      histo1D["PFMuonTrkValidHits"]->Fill(ev.PFMuonTrkValidHits(i)  );
      histo1D["PFMuonTrkNumOfValidPixHits"]->Fill(ev.PFMuonTrkNumOfValidPixHits(i) );
      histo1D["PFMuonStandValidHits"]->Fill(ev.PFMuonStandValidHits(i) );
      histo1D["PFMuonPt"]->Fill(ev.PFMuonPt(i)  );
      histo1D["PFMuonEta"]->Fill(abs( ev.PFMuonEta(i) )  );
      
      float Iso = 0.0;
      Iso = (ev.PFMuonNeutralHadronIso(i) + ev.PFMuonChargedHadronIso(i) + ev.PFMuonPhotonIso(i))/ev.PFMuonPt(i);
      histo1D["PFMuonIso"]->Fill( Iso );
    }
    return true;
  }
  
  std::ostream& hWSourceAnalysis::Description(std::ostream &ostrm) 
  {
    ostrm << "  Source of W Analysis (output in " << mFileName << "):";
    return ostrm;
  }
  
  //--------------MuonAnalysis End Job-----------------------------------------------------------------------------------
  hWSourceAnalysis::~hWSourceAnalysis() 
  {
    histo1D["WplusRminus"]->Divide( histo1D["WplusPT"], histo1D["WminusPT"] );  
    fileOut->Write();
    delete fileOut;	
  }
  
  
  ///---------------------------Hadronic Tau Analysis -----------------------------------------------------------------------
  hTauAnalysis::hTauAnalysis(const std::string & fileName):
    mFileName(fileName)
  {
    fileOut = new TFile(mFileName.c_str(),"recreate");

    histo1D["GenTauPt_eChan"]               = new TH1D("GenTauPt_eChan",         "GenTauPt",          100, 0, 1000);
    histo1D["GenTauPt_mChan"]               = new TH1D("GenTauPt_mChan",         "GenTauPt",          100, 0, 1000);
    histo1D["GenTauPt_etChan"]              = new TH1D("GenTauPt_etChan",        "GenTauPt",          100, 0, 1000);
    histo1D["GenTauPt_mtChan"]              = new TH1D("GenTauPt_mtChan",        "GenTauPt",          100, 0, 1000);
    histo1D["GenTauPt_htChan"]              = new TH1D("GenTauPt_htChan",        "GenTauPt",          100, 0, 1000);

    histo1D["GenTauPt_eFakePt"]             = new TH1D("GenTauPt_eFakePt",         "ElectronPt",      100, 0, 1000);
    histo1D["GenTauPt_eChanFake"]           = new TH1D("GenTauPt_eChanFake",       "TauPt",           100, 0, 1000);
    histo1D["GenTauPt_eChanFakePF"]         = new TH1D("GenTauPt_eChanFakePF",     "TauPt",           100, 0, 1000); 
    histo1D["GenTauPt_eChanFakeNAL"]        = new TH1D("GenTauPt_eChanFakeNAL",    "TauPt",           100, 0, 1000);
    histo1D["GenTauPt_eChanFakePFNAL"]      = new TH1D("GenTauPt_eChanFakePFNAL",  "TauPt",           100, 0, 1000);
    histo1D["GenTauPt_ePtChanFake"]         = new TH1D("GenTauPt_ePtChanFake",     "ElectronPt",      100, 0, 1000);
    histo1D["GenTauPt_ePtChanFakePF"]       = new TH1D("GenTauPt_ePtChanFakePF",   "ElectronPt",      100, 0, 1000); 
    histo1D["GenTauPt_ePtChanFakeNAL"]      = new TH1D("GenTauPt_ePtChanFakeNAL",  "ElectronPt",      100, 0, 1000);
    histo1D["GenTauPt_ePtChanFakePFNAL"]    = new TH1D("GenTauPt_ePtChanFakePFNAL","ElectronPt",      100, 0, 1000);
    
    histo1D["GenTauPt_mFakePt"]             = new TH1D("GenTauPt_mFakePt",         "MuonPt",          100, 0, 1000);
    histo1D["GenTauPt_mChanFake"]           = new TH1D("GenTauPt_mChanFake",       "TauPt",           100, 0, 1000);
    histo1D["GenTauPt_mChanFakePF"]         = new TH1D("GenTauPt_mChanFakePF",     "TauPt",           100, 0, 1000);
    histo1D["GenTauPt_mChanFakeNAL"]        = new TH1D("GenTauPt_mChanFakeNAL",    "TauPt",           100, 0, 1000);
    histo1D["GenTauPt_mChanFakePFNAL"]      = new TH1D("GenTauPt_mChanFakePFNAL",  "TauPt",           100, 0, 1000); 
    histo1D["GenTauPt_mPtChanFake"]         = new TH1D("GenTauPt_mPtChanFake",     "MuonPt",          100, 0, 1000);
    histo1D["GenTauPt_mPtChanFakePF"]       = new TH1D("GenTauPt_mPtChanFakePF",   "MuonPt",          100, 0, 1000); 
    histo1D["GenTauPt_mPtChanFakeNAL"]      = new TH1D("GenTauPt_mPtChanFakeNAL",  "MuonPt",          100, 0, 1000);
    histo1D["GenTauPt_mPtChanFakePFNAL"]    = new TH1D("GenTauPt_mPtChanFakePFNAL","MuonPt",          100, 0, 1000);
    
    histo1D["GenTauPt1_had"]                = new TH1D("GenTauPt1_had",         "GenTauPt_had",       100, 0, 1000);
    histo1D["GenTauPt1_had_A"]              = new TH1D("GenTauPt1_had_A",       "GenTauPt_had_A",     100, 0, 1000);
    histo1D["TauPt1_HPS"]                   = new TH1D("TauPt1_HPS",            "TauPt_HPS",          100, 0, 1000);
    histo1D["TauPt1PF_HPS"]                 = new TH1D("TauPt1PF_HPS",          "TauPt_HPS",          100, 0, 1000);
    histo1D["TauPt1_HPS_NoAgainstLepton"]   = new TH1D("TauPt1_HPS_NoAgainstLepton",   "TauPt_HPS",   100, 0, 1000);
    histo1D["TauPt1PF_HPS_NoAgainstLepton"] = new TH1D("TauPt1PF_HPS_NoAgainstLepton", "TauPt_HPS",   100, 0, 1000);

    histo1D["GenTauPt2_had"]                = new TH1D("GenTauPt2_had",         "GenTauPt_had",       100, 0, 1000);
    histo1D["GenTauPt2_had_A"]              = new TH1D("GenTauPt2_had_A",       "GenTauPt_had_A",     100, 0, 1000);
    histo1D["TauPt2_HPS"]                   = new TH1D("TauPt2_HPS",            "TauPt_HPS",          100, 0, 1000);
    histo1D["TauPt2_HPS_NoAgainstLepton"]   = new TH1D("TauPt2_HPS_NoAgainstLepton",    "TauPt_HPS",  100, 0, 1000);

    histo1D["GenTauPt3_had"]                = new TH1D("GenTauPt3_had",         "GenTauPt_had",       100, 0, 1000);
    histo1D["GenTauPt3_had_A"]              = new TH1D("GenTauPt3_had_A",       "GenTauPt_had_A",     100, 0, 1000);
    histo1D["TauPt3_HPS"]                   = new TH1D("TauPt3_HPS",            "TauPt_HPS",          100, 0, 1000);
    histo1D["TauPt3_HPS_NoAgainstLepton"]   = new TH1D("TauPt3_HPS_NoAgainstLepton",    "TauPt_HPS",  100, 0, 1000);
  }
  
  bool hTauAnalysis::Process(EventData & ev) 
  {
    
    double w     = ev.Weight();
    //int    njets = JetNumber(ev);
    //int    t = ev.MetType(); 
    
    //Gen Tau
    double_t tau_pt = -99.;
    for(Int_t i = 0; i<ev.NGenPar(); i++){
      if(std::abs(ev.GenParId(i))!=15) continue;
      if(std::abs(ev.GenParStatus(i))!=3) continue;
      tau_pt = ev.GenParPt(i);
      break;
    }
    //if(tau_pt==-99) return true;
    
    //Electron Channel
    if(ev.WTauDecayMode()==1 || ev.WTauDecayMode()==11){
      if(ev.WTauDecayMode()==1) histo1D["GenTauPt_eChan"]->Fill(tau_pt,w);
      if(ev.WTauDecayMode()==11) histo1D["GenTauPt_etChan"]->Fill(tau_pt,w); 
      bool check = false;
      for(int i=0; i<ev.NGenPar(); i++){
	if(std::abs(ev.GenParId(i))!=11) continue;
	histo1D["GenTauPt_eFakePt"]->Fill(ev.GenParPt(i),w);
	//
	check = false;
	for(Int_t j=0; j<ev.NTau(); j++){
	  if(ev.TauPt(j)<20.) continue;
	  if(fabs(ev.TauEta(j)) > 2.3) continue;
	  if(ev.TauDisByLooseCombinedIsolationDeltaBetaCorr(j) < 0.5) continue;
	  if(ev.TauDisDecayModeFinding(j) < 0.5) continue;
	  if(deltaR(ev.GenParEta(i), ev.GenParPhi(i), ev.TauEta(j), ev.TauPhi(j))>0.5) continue;
	  if(check==false){
	    histo1D["GenTauPt_eChanFakeNAL"]->Fill(ev.TauPt(j),w);
	    histo1D["GenTauPt_ePtChanFakeNAL"]->Fill(ev.GenParPt(i),w);
	    check=true;
	  }
	  if(ev.TauDisAgainstElectronLoose(j) < 0.5) continue;
	  if(ev.TauDisAgainstMuonTight2(j) < 0.5) continue;
	  histo1D["GenTauPt_eChanFake"]->Fill(ev.TauPt(j),w);
	  histo1D["GenTauPt_ePtChanFake"]->Fill(ev.GenParPt(i),w);
	  break;
	}
	//
	check = false;
	for(Int_t j=0; j<ev.NPFTau(); j++){
	  if(ev.PFTauPt(j)<20.) continue;
	  if(fabs(ev.PFTauEta(j)) > 2.3) continue;
	  if(ev.PFTauDisByLooseCombinedIsolationDeltaBetaCorr(j) < 0.5) continue;
	  if(ev.PFTauDisDecayModeFinding(j) < 0.5) continue;
	  if(deltaR(ev.GenParEta(i), ev.GenParPhi(i), ev.PFTauEta(j), ev.PFTauPhi(j))>0.5) continue;
	  if(check==false){
	    histo1D["GenTauPt_eChanFakePFNAL"]->Fill(ev.PFTauPt(j),w);
	    histo1D["GenTauPt_ePtChanFakePFNAL"]->Fill(ev.GenParPt(i),w);
	    check=true;
	  }
	  if(ev.PFTauDisAgainstElectronLoose(j) < 0.5) continue;
	  if(ev.PFTauDisAgainstMuonTight2(j) < 0.5) continue;
	  histo1D["GenTauPt_eChanFakePF"]->Fill(ev.PFTauPt(j),w);
	  histo1D["GenTauPt_ePtChanFakePF"]->Fill(ev.GenParPt(i),w);
	  break;
	}
      }
    }
    //Muon Channel
    else if(ev.WTauDecayMode()==2 || ev.WTauDecayMode()==12){ 
      if(ev.WTauDecayMode()==2) histo1D["GenTauPt_mChan"]->Fill(tau_pt,w);
      if(ev.WTauDecayMode()==12) histo1D["GenTauPt_mtChan"]->Fill(tau_pt,w);
      bool check = false;
      for(int i=0; i<ev.NGenPar(); i++){
	if(std::abs(ev.GenParId(i))!=13) continue;
	histo1D["GenTauPt_mFakePt"]->Fill(ev.GenParPt(i),w);
	//
	check = false;
	for(Int_t j=0; j<ev.NTau(); j++){
	  if(ev.TauPt(j)<20.) continue;
	  if(fabs(ev.TauEta(j)) > 2.3) continue;
	  if(ev.TauDisByLooseCombinedIsolationDeltaBetaCorr(j) < 0.5) continue;
	  if(ev.TauDisDecayModeFinding(j) < 0.5) continue;
	  if(deltaR(ev.GenParEta(i), ev.GenParPhi(i), ev.TauEta(j), ev.TauPhi(j))>0.5) continue;
	  if(check==false){
	    histo1D["GenTauPt_mChanFakeNAL"]->Fill(ev.TauPt(j),w);
	    histo1D["GenTauPt_mPtChanFakeNAL"]->Fill(ev.GenParPt(i),w);
	    check=true;
	  }
	  if(ev.TauDisAgainstElectronLoose(j) < 0.5) continue;
	  if(ev.TauDisAgainstMuonTight2(j) < 0.5) continue;
	  histo1D["GenTauPt_mChanFake"]->Fill(ev.TauPt(j),w);
	  histo1D["GenTauPt_mPtChanFake"]->Fill(ev.GenParPt(i),w);
	  break;
	}
	//
	check = false;
	for(Int_t j=0; j<ev.NPFTau(); j++){
	  if(ev.PFTauPt(j)<20.) continue;
	  if(fabs(ev.PFTauEta(j)) > 2.3) continue;
	  if(ev.PFTauDisByLooseCombinedIsolationDeltaBetaCorr(j) < 0.5) continue;
	  if(ev.PFTauDisDecayModeFinding(j) < 0.5) continue;
	  if(deltaR(ev.GenParEta(i), ev.GenParPhi(i), ev.PFTauEta(j), ev.PFTauPhi(j))>0.5) continue;
	  if(check==false){
	    histo1D["GenTauPt_mChanFakePFNAL"]->Fill(ev.PFTauPt(j),w);
	    histo1D["GenTauPt_mPtChanFakePFNAL"]->Fill(ev.GenParPt(i),w);
	    check=true;
	  }
	  if(ev.PFTauDisAgainstElectronLoose(j) < 0.5) continue;
	  if(ev.PFTauDisAgainstMuonTight2(j) < 0.5) continue;
	  histo1D["GenTauPt_mChanFakePF"]->Fill(ev.PFTauPt(j),w);
	  histo1D["GenTauPt_mPtChanFakePF"]->Fill(ev.GenParPt(i),w);
	  break;
	}
      }
    }
    //Hadronic Tau Channel
    else if(ev.WTauDecayMode()>=13 || ev.WTauDecayMode()==-10 || ev.WTauDecayMode()==-20){ 

      histo1D["GenTauPt_htChan"]->Fill(tau_pt,w);

      //Calculate tau from each step:  
      //Visible Tau (from GEN)
      TLorentzVector visTau(0.,0.,0.,0.);
      TLorentzVector comTau(0.,0.,0.,0.);
      //double_t tau_pt_vis = -99.;
      for(Int_t i = 0; i<ev.WTauN(); i++){
	if(std::abs(ev.WTauDecayId(i))==16) continue;
	comTau.SetPtEtaPhiM(ev.WTauDecayPt(i),ev.WTauDecayEta(i),ev.WTauDecayPhi(i),ev.WTauDecayMass(i));
	visTau += comTau;
      }
      //if(visTau.Pt()>0) tau_pt_vis = visTau.Pt();
      
      //Visible Tau (from GENJet, patTaus)
      double_t genJetTau_pt_vis = -99.;
      for(Int_t i = 0; i<ev.NTau(); i++){
	if(ev.TauJetPt(i)<20.) continue;
	if(fabs(ev.TauJetEta(i)) > 2.3) continue;
	genJetTau_pt_vis = ev.TauJetPt(i);
	break;
      }
      
      //Visible Tau (from GENJet, patTausPF)
      double_t genJetTauPF_pt_vis = -99.;
      for(Int_t i = 0; i<ev.NPFTau(); i++){
	if(ev.PFTauJetPt(i)<20.) continue;
	if(fabs(ev.PFTauJetEta(i)) > 2.3) continue;
	genJetTauPF_pt_vis = ev.PFTauJetPt(i);
	break;
      }
      
      //RecoTau
      double recoTau_pt = -99;
      for(Int_t i = 0; i<ev.NTau(); i++){
	if(ev.TauPt(i)<20.) continue;
	if(fabs(ev.TauEta(i)) > 2.3) continue;
	if(ev.TauDisByLooseCombinedIsolationDeltaBetaCorr(i) < 0.5) continue;
	if(ev.TauDisDecayModeFinding(i) < 0.5) continue;
	if(ev.TauDisAgainstElectronLoose(i) < 0.5) continue;
	if(ev.TauDisAgainstMuonTight2(i) < 0.5) continue;
	recoTau_pt = ev.TauPt(i);
	break;
      }
      double recoTau_pt_noAgainstLepton = -99;
      for(Int_t i = 0; i<ev.NTau(); i++){
	if(ev.TauPt(i)<20.) continue;
	if(fabs(ev.TauEta(i)) > 2.3) continue;
	if(ev.TauDisByLooseCombinedIsolationDeltaBetaCorr(i) < 0.5) continue;
	if(ev.TauDisDecayModeFinding(i) < 0.5) continue;
	recoTau_pt_noAgainstLepton = ev.TauPt(i);
	break;
      }
      
      //RecoTauPF
      double recoTauPF_pt = -99;
      for(Int_t i = 0; i<ev.NPFTau(); i++){
	if(ev.PFTauPt(i)<20.) continue;
	if(fabs(ev.PFTauEta(i)) > 2.3) continue;
	if(ev.PFTauDisByLooseCombinedIsolationDeltaBetaCorr(i) < 0.5) continue;
	if(ev.PFTauDisDecayModeFinding(i) < 0.5) continue;
	if(ev.PFTauDisAgainstElectronLoose(i) < 0.5) continue;
	if(ev.PFTauDisAgainstMuonTight2(i) < 0.5) continue;
	recoTauPF_pt = ev.PFTauPt(i);
	break;
      }
      double recoTauPF_pt_noAgainstLepton = -99;
      for(Int_t i = 0; i<ev.NPFTau(); i++){
	if(ev.PFTauPt(i)<20.) continue;
	if(fabs(ev.PFTauEta(i)) > 2.3) continue;
	if(ev.PFTauDisByLooseCombinedIsolationDeltaBetaCorr(i) < 0.5) continue;
	if(ev.PFTauDisDecayModeFinding(i) < 0.5) continue;
	recoTauPF_pt_noAgainstLepton = ev.PFTauPt(i);
	break;
      }
      
      if(tau_pt>0.){
	//Using visible GEN daughter of tau
	histo1D["GenTauPt1_had"]->Fill(tau_pt, w);
	if(std::fabs(visTau.Eta())<2.3 && visTau.Pt()>20.){
	  histo1D["GenTauPt1_had_A"]->Fill(tau_pt, w);
	  if(recoTau_pt>0.)                   histo1D["TauPt1_HPS"]->Fill(recoTau_pt,w);
	  if(recoTau_pt_noAgainstLepton>0.)   histo1D["TauPt1_HPS_NoAgainstLepton"]->Fill(recoTau_pt_noAgainstLepton,w);
	  if(recoTauPF_pt>0.)                 histo1D["TauPt1PF_HPS"]->Fill(recoTauPF_pt,w);
	  if(recoTauPF_pt_noAgainstLepton>0.) histo1D["TauPt1PF_HPS_NoAgainstLepton"]->Fill(recoTauPF_pt_noAgainstLepton,w);
	}
	
	//Using matched GENJet, patTaus
	histo1D["GenTauPt2_had"]->Fill(tau_pt, w);
	if(genJetTau_pt_vis>0.){
	  histo1D["GenTauPt2_had_A"]->Fill(tau_pt, w);
	  if(recoTau_pt>0.)                   histo1D["TauPt2_HPS"]->Fill(recoTau_pt,w);
	  if(recoTau_pt_noAgainstLepton>0.)   histo1D["TauPt2_HPS_NoAgainstLepton"]->Fill(recoTau_pt_noAgainstLepton,w);
	}
	
	//Using matched GENJet, patTausPF
	histo1D["GenTauPt3_had"]->Fill(tau_pt, w);
	if(genJetTauPF_pt_vis>0.){
	  histo1D["GenTauPt3_had_A"]->Fill(tau_pt, w);
	  if(recoTauPF_pt>0.)                 histo1D["TauPt3_HPS"]->Fill(recoTauPF_pt,w);
	  if(recoTauPF_pt_noAgainstLepton>0.) histo1D["TauPt3_HPS_NoAgainstLepton"]->Fill(recoTauPF_pt_noAgainstLepton,w);
	}
	
      }//End of if(tau_pt>0.)
    }//End of Hadronic decay 
    else{}
    
    return true;
  }
  
  std::ostream& hTauAnalysis::Description(std::ostream &ostrm) 
  {
    ostrm << "  Tau Analysis (output in " << mFileName << "):";
    return ostrm;
  }
  
  //--------------MuonAnalysis End Job-----------------------------------------------------------------------------------
  hTauAnalysis::~hTauAnalysis() 
  {	
    
    //histo1D["WplusRminus"]->Divide( histo1D["WplusPT"], histo1D["WminusPT"] );
    
    fileOut->Write();
    delete fileOut;	
  }
  
  
  ///============================================================================================================================================
  
  void  OutputEPS( map<string,TH1D*> histos_ , string dirName)
  {
    std::map<std::string, TH1D*>::iterator histo1Diter;
    
    char dir[150],str[255], rm[255];
    sprintf(dir,"%s_eps" , dirName.c_str() );
    sprintf(str,"mkdir %s",dir);
    sprintf(rm,"rm -rf  %s",dir);
    system(rm);
    system(str);
    gROOT->Reset();
    gROOT->SetBatch(true);
    gStyle->SetCanvasColor(0);
    gStyle->SetPadColor(0);
    gStyle->SetOptStat(1111);
    
    for(histo1Diter = histos_.begin(); histo1Diter != histos_.end(); histo1Diter++){
      TCanvas *can=new TCanvas("MonoJet","MonoJet",0,0,550,410);
      can->cd();
      can->SetLogy();
      //TPaveStats *ptstats;
      //ptstats = new TPaveStats(0.75,0.8,0.99,1.0,"brNDC");
      
      //histo1Diter->second->GetListOfFunctions()->Add(ptstats);
      
      //ptstats->SetParent( histo1Diter->second->GetListOfFunctions());
      
      histo1Diter->second->Draw();
      
      histo1Diter->second->SetStats(1);
      
      //ptstats->SetOptStat(1111);
      
      
      std::string filename = dir;
      filename += '/';
      filename +=  histo1Diter->first;
      
      filename  += ".eps";
      can->SaveAs( filename.c_str() );
      
    } 
  }
}

