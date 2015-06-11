#!/bin/tcsh -f


mkdir  eps_zinv_try_mc_data

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"   zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"   zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"        zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"        zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  Jet1Eta  "Leading Jet #eta "                                    zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  Jet1Pt   "Leading Jet p_{T} (GeV)"                              zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  Jet2Eta  "Second Jet #eta "                                     zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  Jet2Pt   "Second Jet p_{T} (GeV)"                               zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  NJet   "Jet Multiplicity"                                       zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  dPhi_MetMu_Jet1  "deltaPhi(Jet1, MET)"                          zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  dPhi_MetMu_Jet2  "deltaPhi(Jet2, MET)"                          zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  dPhi_Jet1_Jet2  "deltaPhi(Jet1, Jet2)"                          zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  MetMu1   "MET (GeV) "                                           zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  MetMuThrs1   "MET Threshold (GeV) "                             zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  MetMu2   "MET (GeV) "                                           zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  MetMuThrs2   "MET Threshold (GeV) "                             zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  TIV   "Track Isolation Veto "                                   zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  MuonPt   "Muon p_{T} (GeV) "                                    zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  PFMuonPt   "PFMuon p_{T} (GeV) "                                zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"
Merge  PFElecPt   "PFElectron p_{T} (GeV) "                            zinv_AnaMonoJetCutEff_0 "official" zinv2_AnaMonoJetCutEff_0 "our"

mv  *.eps  eps_zinv_try_mc_data




mkdir  eps_zinv_try_cuteff_all

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"   zinv_AnaMonoJetCutEff_1 "official" zinv2_AnaMonoJetCutEff_1 "our" 
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"   zinv_AnaMonoJetCutEff_1 "official" zinv2_AnaMonoJetCutEff_1 "our" 
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"        zinv_AnaMonoJetCutEff_1 "official" zinv2_AnaMonoJetCutEff_1 "our" 
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"        zinv_AnaMonoJetCutEff_1 "official" zinv2_AnaMonoJetCutEff_1 "our" 

Merge  Jet1Eta  "Leading Jet #eta "                                    zinv_AnaMonoJetCutEff_2 "official" zinv2_AnaMonoJetCutEff_2  "our"
Merge  Jet1Pt   "Leading Jet p_{T} (GeV)"                              zinv_AnaMonoJetCutEff_2 "official" zinv2_AnaMonoJetCutEff_2  "our"
Merge  Jet2Eta  "Second Jet #eta "                                     zinv_AnaMonoJetCutEff_2 "official" zinv2_AnaMonoJetCutEff_2  "our"
Merge  Jet2Pt   "Second Jet p_{T} (GeV)"                               zinv_AnaMonoJetCutEff_2 "official" zinv2_AnaMonoJetCutEff_2  "our"

Merge  NJet   "Jet Multiplicity"                                       zinv_AnaMonoJetCutEff_3 "official" zinv2_AnaMonoJetCutEff_3  "our"
                                                                                                                               
Merge  dPhi_Jet1_Jet2  "deltaPhi(Jet1, Jet2)"                          zinv_AnaMonoJetCutEff_4 "official" zinv2_AnaMonoJetCutEff_4  "our"
Merge  dPhi_MetMu_Jet2  "deltaPhi(Jet2, MET)"                          zinv_AnaMonoJetCutEff_4 "official" zinv2_AnaMonoJetCutEff_4  "our"
Merge  dPhi_MetMu_Jet1  "deltaPhi(Jet1, MET)"                          zinv_AnaMonoJetCutEff_4 "official" zinv2_AnaMonoJetCutEff_4  "our"
                                                                                                          
Merge  MetMu1   "MET (GeV) "                                           zinv_AnaMonoJetCutEff_5 "official" zinv2_AnaMonoJetCutEff_5  "our"
Merge  MetMuThrs1   "MET Threshold (GeV) "                             zinv_AnaMonoJetCutEff_5 "official" zinv2_AnaMonoJetCutEff_5  "our"
Merge  MetMu2   "MET (GeV) "                                           zinv_AnaMonoJetCutEff_5 "official" zinv2_AnaMonoJetCutEff_5  "our"
Merge  MetMuThrs2   "MET Threshold (GeV) "                             zinv_AnaMonoJetCutEff_5 "official" zinv2_AnaMonoJetCutEff_5  "our"

Merge  TIV      "Track Isolation Veto"                                 zinv_AnaMonoJetCutEff_6 "official" zinv2_AnaMonoJetCutEff_6  "our"
                                                                                                                               
Merge  PFMuonPt   "PFMuon p_{T} (GeV) "                                zinv_AnaMonoJetCutEff_7 "official" zinv2_AnaMonoJetCutEff_7  "our"
Merge  PFElecPt   "PFElectron p_{T} (GeV) "                            zinv_AnaMonoJetCutEff_7 "official" zinv2_AnaMonoJetCutEff_7  "our"
                                                                                                                               
Merge  MuonPt   "Muon p_{T} (GeV) "                                    zinv_AnaMonoJetCutEff_8 "official" zinv2_AnaMonoJetCutEff_8  "our"
                                                                                                                              
mv  *.eps  eps_zinv_try_cuteff_all                                                                                                 



cd  /uscms_data/d2/vergili/may/MONO/CMSSW_3_8_7/src/MonoJetAnalysis/NtupleAnalyzer/results/AnaMonoJetCutEff/eps_cuteff_all1
kcp  -s "officialisible  our vs official" -b "All Cuts was applied"  *.eps lqfai@kbook.fnal.gov:1443

