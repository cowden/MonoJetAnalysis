#!/bin/tcsh -f


mkdir  eps_try_mc_data

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"   zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"   zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"        zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"        zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  Jet1Eta  "Leading Jet #eta "                                    zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  Jet1Pt   "Leading Jet p_{T} (GeV)"                              zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  Jet2Eta  "Second Jet #eta "                                     zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  Jet2Pt   "Second Jet p_{T} (GeV)"                               zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  NJet   "Jet Multiplicity"                                       zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  dPhi_MetMu_Jet1  "deltaPhi(Jet1, MET)"                          zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  dPhi_MetMu_Jet2  "deltaPhi(Jet2, MET)"                          zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  dPhi_Jet1_Jet2  "deltaPhi(Jet1, Jet2)"                          zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  MetMu1   "MET (GeV) "                                           zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  MetMuThrs1   "MET Threshold (GeV) "                             zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  MetMu2   "MET (GeV) "                                           zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  MetMuThrs2   "MET Threshold (GeV) "                             zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  TIV   "Track Isolation Veto "                                   zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  MuonPt   "Muon p_{T} (GeV) "                                    zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  PFMuonPt   "PFMuon p_{T} (GeV) "                                zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"
Merge  PFElecPt   "PFElectron p_{T} (GeV) "                            zinv_AnaMonoJetCutEff_0 "Zinv" zinv2_AnaMonoJetCutEff_0 "Data"

mv  *.eps  eps_try_mc_data




mkdir  eps_try_cuteff_all

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"   zinv_AnaMonoJetCutEff_1 "Zinv" zinv2_AnaMonoJetCutEff_1 "Data" 
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"   zinv_AnaMonoJetCutEff_1 "Zinv" zinv2_AnaMonoJetCutEff_1 "Data" 
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"        zinv_AnaMonoJetCutEff_1 "Zinv" zinv2_AnaMonoJetCutEff_1 "Data" 
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"        zinv_AnaMonoJetCutEff_1 "Zinv" zinv2_AnaMonoJetCutEff_1 "Data" 

Merge  Jet1Eta  "Leading Jet #eta "                                    zinv_AnaMonoJetCutEff_2 "Zinv" zinv2_AnaMonoJetCutEff_2  "Data"
Merge  Jet1Pt   "Leading Jet p_{T} (GeV)"                              zinv_AnaMonoJetCutEff_2 "Zinv" zinv2_AnaMonoJetCutEff_2  "Data"
Merge  Jet2Eta  "Second Jet #eta "                                     zinv_AnaMonoJetCutEff_2 "Zinv" zinv2_AnaMonoJetCutEff_2  "Data"
Merge  Jet2Pt   "Second Jet p_{T} (GeV)"                               zinv_AnaMonoJetCutEff_2 "Zinv" zinv2_AnaMonoJetCutEff_2  "Data"

Merge  NJet   "Jet Multiplicity"                                       zinv_AnaMonoJetCutEff_3 "Zinv" zinv2_AnaMonoJetCutEff_3  "Data"
                                                                                                                               
Merge  dPhi_Jet1_Jet2  "deltaPhi(Jet1, Jet2)"                          zinv_AnaMonoJetCutEff_4 "Zinv" zinv2_AnaMonoJetCutEff_4  "Data"
Merge  dPhi_MetMu_Jet2  "deltaPhi(Jet2, MET)"                          zinv_AnaMonoJetCutEff_4 "Zinv" zinv2_AnaMonoJetCutEff_4  "Data"
Merge  dPhi_MetMu_Jet1  "deltaPhi(Jet1, MET)"                          zinv_AnaMonoJetCutEff_4 "Zinv" zinv2_AnaMonoJetCutEff_4  "Data"
                                                                                                          
Merge  MetMu1   "MET (GeV) "                                           zinv_AnaMonoJetCutEff_5 "Zinv" zinv2_AnaMonoJetCutEff_5  "Data"
Merge  MetMuThrs1   "MET Threshold (GeV) "                             zinv_AnaMonoJetCutEff_5 "Zinv" zinv2_AnaMonoJetCutEff_5  "Data"
Merge  MetMu2   "MET (GeV) "                                           zinv_AnaMonoJetCutEff_5 "Zinv" zinv2_AnaMonoJetCutEff_5  "Data"
Merge  MetMuThrs2   "MET Threshold (GeV) "                             zinv_AnaMonoJetCutEff_5 "Zinv" zinv2_AnaMonoJetCutEff_5  "Data"

Merge  TIV      "Track Isolation Veto"                                 zinv_AnaMonoJetCutEff_6 "Zinv" zinv2_AnaMonoJetCutEff_6  "Data"
                                                                                                                               
Merge  PFMuonPt   "PFMuon p_{T} (GeV) "                                zinv_AnaMonoJetCutEff_7 "Zinv" zinv2_AnaMonoJetCutEff_7  "Data"
Merge  PFElecPt   "PFElectron p_{T} (GeV) "                            zinv_AnaMonoJetCutEff_7 "Zinv" zinv2_AnaMonoJetCutEff_7  "Data"
                                                                                                                               
Merge  MuonPt   "Muon p_{T} (GeV) "                                    zinv_AnaMonoJetCutEff_8 "Zinv" zinv2_AnaMonoJetCutEff_8  "Data"
                                                                                                                              
mv  *.eps  eps_try_cuteff_all                                                                                                 



cd  /uscms_data/d2/vergili/may/MONO/CMSSW_3_8_7/src/MonoJetAnalysis/NtupleAnalyzer/results/AnaMonoJetCutEff/eps_cuteff_all1
kcp  -s "Zinvisible  Spring10 vs Fall10" -b "All Cuts was applied"  *.eps lqfai@kbook.fnal.gov:1443

