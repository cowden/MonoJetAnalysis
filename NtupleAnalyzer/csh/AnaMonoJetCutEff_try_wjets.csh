#!/bin/tcsh -f


mkdir  eps_try_mc_data

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"   wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"   wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"        wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"        wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  Jet1Eta  "Leading Jet #eta "                                    wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  Jet1Pt   "Leading Jet p_{T} (GeV)"                              wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  Jet2Eta  "Second Jet #eta "                                     wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  Jet2Pt   "Second Jet p_{T} (GeV)"                               wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  NJet   "Jet Multiplicity"                                       wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  dPhi_MetMu_Jet1  "deltaPhi(Jet1, MET)"                          wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  dPhi_MetMu_Jet2  "deltaPhi(Jet2, MET)"                          wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  dPhi_Jet1_Jet2  "deltaPhi(Jet1, Jet2)"                          wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  MetMu1   "MET (GeV) "                                           wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  MetMuThrs1   "MET Threshold (GeV) "                             wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  MetMu2   "MET (GeV) "                                           wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  MetMuThrs2   "MET Threshold (GeV) "                             wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  TIV   "Track Isolation Veto "                                   wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  MuonPt   "Muon p_{T} (GeV) "                                    wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  PFMuonPt   "PFMuon p_{T} (GeV) "                                wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"
Merge  PFElecPt   "PFElectron p_{T} (GeV) "                            wjets_AnaMonoJetCutEff_0 "Fall10" wjets2_AnaMonoJetCutEff_0 "Spring10"

mv  *.eps  eps_try_mc_data




mkdir  eps_try_cuteff_all

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"   wjets_AnaMonoJetCutEff_1 "Fall10" wjets2_AnaMonoJetCutEff_1 "Spring10" 
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"   wjets_AnaMonoJetCutEff_1 "Fall10" wjets2_AnaMonoJetCutEff_1 "Spring10" 
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"        wjets_AnaMonoJetCutEff_1 "Fall10" wjets2_AnaMonoJetCutEff_1 "Spring10" 
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"        wjets_AnaMonoJetCutEff_1 "Fall10" wjets2_AnaMonoJetCutEff_1 "Spring10" 

Merge  Jet1Eta  "Leading Jet #eta "                                    wjets_AnaMonoJetCutEff_2 "Fall10" wjets2_AnaMonoJetCutEff_2  "Spring10"
Merge  Jet1Pt   "Leading Jet p_{T} (GeV)"                              wjets_AnaMonoJetCutEff_2 "Fall10" wjets2_AnaMonoJetCutEff_2  "Spring10"
Merge  Jet2Eta  "Second Jet #eta "                                     wjets_AnaMonoJetCutEff_2 "Fall10" wjets2_AnaMonoJetCutEff_2  "Spring10"
Merge  Jet2Pt   "Second Jet p_{T} (GeV)"                               wjets_AnaMonoJetCutEff_2 "Fall10" wjets2_AnaMonoJetCutEff_2  "Spring10"

Merge  NJet   "Jet Multiplicity"                                       wjets_AnaMonoJetCutEff_3 "Fall10" wjets2_AnaMonoJetCutEff_3  "Spring10"
                                                                                                                               
Merge  dPhi_Jet1_Jet2  "deltaPhi(Jet1, Jet2)"                          wjets_AnaMonoJetCutEff_4 "Fall10" wjets2_AnaMonoJetCutEff_4  "Spring10"
Merge  dPhi_MetMu_Jet2  "deltaPhi(Jet2, MET)"                          wjets_AnaMonoJetCutEff_4 "Fall10" wjets2_AnaMonoJetCutEff_4  "Spring10"
Merge  dPhi_MetMu_Jet1  "deltaPhi(Jet1, MET)"                          wjets_AnaMonoJetCutEff_4 "Fall10" wjets2_AnaMonoJetCutEff_4  "Spring10"
                                                                                                          
Merge  MetMu1   "MET (GeV) "                                           wjets_AnaMonoJetCutEff_5 "Fall10" wjets2_AnaMonoJetCutEff_5  "Spring10"
Merge  MetMuThrs1   "MET Threshold (GeV) "                             wjets_AnaMonoJetCutEff_5 "Fall10" wjets2_AnaMonoJetCutEff_5  "Spring10"
Merge  MetMu2   "MET (GeV) "                                           wjets_AnaMonoJetCutEff_5 "Fall10" wjets2_AnaMonoJetCutEff_5  "Spring10"
Merge  MetMuThrs2   "MET Threshold (GeV) "                             wjets_AnaMonoJetCutEff_5 "Fall10" wjets2_AnaMonoJetCutEff_5  "Spring10"

Merge  TIV      "Track Isolation Veto"                                 wjets_AnaMonoJetCutEff_6 "Fall10" wjets2_AnaMonoJetCutEff_6  "Spring10"
                                                                                                                               
Merge  PFMuonPt   "PFMuon p_{T} (GeV) "                                wjets_AnaMonoJetCutEff_7 "Fall10" wjets2_AnaMonoJetCutEff_7  "Spring10"
Merge  PFElecPt   "PFElectron p_{T} (GeV) "                            wjets_AnaMonoJetCutEff_7 "Fall10" wjets2_AnaMonoJetCutEff_7  "Spring10"
                                                                                                                               
Merge  MuonPt   "Muon p_{T} (GeV) "                                    wjets_AnaMonoJetCutEff_8 "Fall10" wjets2_AnaMonoJetCutEff_8  "Spring10"
                                                                                                                              
mv  *.eps  eps_try_cuteff_all                                                                                                 



cd  /uscms_data/d2/vergili/may/MONO/CMSSW_3_8_7/src/MonoJetAnalysis/NtupleAnalyzer/results/AnaMonoJetCutEff/eps_cuteff_all1
kcp  -s "Fall10isible  Fall10 vs Fall10" -b "All Cuts was applied"  *.eps lqfai@kbook.fnal.gov:1443

