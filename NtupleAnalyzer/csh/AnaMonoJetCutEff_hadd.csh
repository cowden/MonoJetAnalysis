#!/bin/tcsh -f


rm  AnaMonoJetCutEff_*
rm  data_*

rm output.root

hadd  AnaMonoJetCutEff_0_0.root     zjets_AnaMonoJetCutEff_0.root  
hadd  AnaMonoJetCutEff_0_1.root     zjets_AnaMonoJetCutEff_0.root    qcd*_AnaMonoJetCutEff_0.root 
hadd  AnaMonoJetCutEff_0_2.root     zjets_AnaMonoJetCutEff_0.root    qcd*_AnaMonoJetCutEff_0.root ttbar_AnaMonoJetCutEff_0.root 
hadd  AnaMonoJetCutEff_0_3.root     zjets_AnaMonoJetCutEff_0.root    qcd*_AnaMonoJetCutEff_0.root ttbar_AnaMonoJetCutEff_0.root  wjets_AnaMonoJetCutEff_0.root 
hadd  AnaMonoJetCutEff_0_4.root     zjets_AnaMonoJetCutEff_0.root    qcd*_AnaMonoJetCutEff_0.root ttbar_AnaMonoJetCutEff_0.root  wjets_AnaMonoJetCutEff_0.root  zinv_AnaMonoJetCutEff_0.root                  
hadd  AnaMonoJetCutEff_1_0.root     zjets_AnaMonoJetCutEff_1.root  
hadd  AnaMonoJetCutEff_1_1.root     zjets_AnaMonoJetCutEff_1.root    qcd*_AnaMonoJetCutEff_1.root 
hadd  AnaMonoJetCutEff_1_2.root     zjets_AnaMonoJetCutEff_1.root    qcd*_AnaMonoJetCutEff_1.root ttbar_AnaMonoJetCutEff_1.root 
hadd  AnaMonoJetCutEff_1_3.root     zjets_AnaMonoJetCutEff_1.root    qcd*_AnaMonoJetCutEff_1.root ttbar_AnaMonoJetCutEff_1.root  wjets_AnaMonoJetCutEff_1.root 
hadd  AnaMonoJetCutEff_1_4.root     zjets_AnaMonoJetCutEff_1.root    qcd*_AnaMonoJetCutEff_1.root ttbar_AnaMonoJetCutEff_1.root  wjets_AnaMonoJetCutEff_1.root  zinv_AnaMonoJetCutEff_1.root                  
hadd  AnaMonoJetCutEff_2_0.root     zjets_AnaMonoJetCutEff_2.root  
hadd  AnaMonoJetCutEff_2_1.root     zjets_AnaMonoJetCutEff_2.root    qcd*_AnaMonoJetCutEff_2.root 
hadd  AnaMonoJetCutEff_2_2.root     zjets_AnaMonoJetCutEff_2.root    qcd*_AnaMonoJetCutEff_2.root ttbar_AnaMonoJetCutEff_2.root 
hadd  AnaMonoJetCutEff_2_3.root     zjets_AnaMonoJetCutEff_2.root    qcd*_AnaMonoJetCutEff_2.root ttbar_AnaMonoJetCutEff_2.root  wjets_AnaMonoJetCutEff_2.root 
hadd  AnaMonoJetCutEff_2_4.root     zjets_AnaMonoJetCutEff_2.root    qcd*_AnaMonoJetCutEff_2.root ttbar_AnaMonoJetCutEff_2.root  wjets_AnaMonoJetCutEff_2.root  zinv_AnaMonoJetCutEff_2.root                  
hadd  AnaMonoJetCutEff_3_0.root     zjets_AnaMonoJetCutEff_3.root  
hadd  AnaMonoJetCutEff_3_1.root     zjets_AnaMonoJetCutEff_3.root    qcd*_AnaMonoJetCutEff_3.root 
hadd  AnaMonoJetCutEff_3_2.root     zjets_AnaMonoJetCutEff_3.root    qcd*_AnaMonoJetCutEff_3.root ttbar_AnaMonoJetCutEff_3.root 
hadd  AnaMonoJetCutEff_3_3.root     zjets_AnaMonoJetCutEff_3.root    qcd*_AnaMonoJetCutEff_3.root ttbar_AnaMonoJetCutEff_3.root  wjets_AnaMonoJetCutEff_3.root 
hadd  AnaMonoJetCutEff_3_4.root     zjets_AnaMonoJetCutEff_3.root    qcd*_AnaMonoJetCutEff_3.root ttbar_AnaMonoJetCutEff_3.root  wjets_AnaMonoJetCutEff_3.root  zinv_AnaMonoJetCutEff_3.root                  
hadd  AnaMonoJetCutEff_4_0.root     zjets_AnaMonoJetCutEff_4.root  
hadd  AnaMonoJetCutEff_4_1.root     zjets_AnaMonoJetCutEff_4.root    qcd*_AnaMonoJetCutEff_4.root 
hadd  AnaMonoJetCutEff_4_2.root     zjets_AnaMonoJetCutEff_4.root    qcd*_AnaMonoJetCutEff_4.root ttbar_AnaMonoJetCutEff_4.root 
hadd  AnaMonoJetCutEff_4_3.root     zjets_AnaMonoJetCutEff_4.root    qcd*_AnaMonoJetCutEff_4.root ttbar_AnaMonoJetCutEff_4.root  wjets_AnaMonoJetCutEff_4.root 
hadd  AnaMonoJetCutEff_4_4.root     zjets_AnaMonoJetCutEff_4.root    qcd*_AnaMonoJetCutEff_4.root ttbar_AnaMonoJetCutEff_4.root  wjets_AnaMonoJetCutEff_4.root  zinv_AnaMonoJetCutEff_4.root                  
hadd  AnaMonoJetCutEff_5_0.root     zjets_AnaMonoJetCutEff_5.root  
hadd  AnaMonoJetCutEff_5_1.root     zjets_AnaMonoJetCutEff_5.root    qcd*_AnaMonoJetCutEff_5.root 
hadd  AnaMonoJetCutEff_5_2.root     zjets_AnaMonoJetCutEff_5.root    qcd*_AnaMonoJetCutEff_5.root ttbar_AnaMonoJetCutEff_5.root 
hadd  AnaMonoJetCutEff_5_3.root     zjets_AnaMonoJetCutEff_5.root    qcd*_AnaMonoJetCutEff_5.root ttbar_AnaMonoJetCutEff_5.root  wjets_AnaMonoJetCutEff_5.root 
hadd  AnaMonoJetCutEff_5_4.root     zjets_AnaMonoJetCutEff_5.root    qcd*_AnaMonoJetCutEff_5.root ttbar_AnaMonoJetCutEff_5.root  wjets_AnaMonoJetCutEff_5.root  zinv_AnaMonoJetCutEff_5.root                  
hadd  AnaMonoJetCutEff_6_0.root     zjets_AnaMonoJetCutEff_6.root  
hadd  AnaMonoJetCutEff_6_1.root     zjets_AnaMonoJetCutEff_6.root    qcd*_AnaMonoJetCutEff_6.root 
hadd  AnaMonoJetCutEff_6_2.root     zjets_AnaMonoJetCutEff_6.root    qcd*_AnaMonoJetCutEff_6.root ttbar_AnaMonoJetCutEff_6.root 
hadd  AnaMonoJetCutEff_6_3.root     zjets_AnaMonoJetCutEff_6.root    qcd*_AnaMonoJetCutEff_6.root ttbar_AnaMonoJetCutEff_6.root  wjets_AnaMonoJetCutEff_6.root 
hadd  AnaMonoJetCutEff_6_4.root     zjets_AnaMonoJetCutEff_6.root    qcd*_AnaMonoJetCutEff_6.root ttbar_AnaMonoJetCutEff_6.root  wjets_AnaMonoJetCutEff_6.root  zinv_AnaMonoJetCutEff_6.root                  
hadd  AnaMonoJetCutEff_7_0.root     zjets_AnaMonoJetCutEff_7.root  
hadd  AnaMonoJetCutEff_7_1.root     zjets_AnaMonoJetCutEff_7.root    qcd*_AnaMonoJetCutEff_7.root 
hadd  AnaMonoJetCutEff_7_2.root     zjets_AnaMonoJetCutEff_7.root    qcd*_AnaMonoJetCutEff_7.root ttbar_AnaMonoJetCutEff_7.root 
hadd  AnaMonoJetCutEff_7_3.root     zjets_AnaMonoJetCutEff_7.root    qcd*_AnaMonoJetCutEff_7.root ttbar_AnaMonoJetCutEff_7.root  wjets_AnaMonoJetCutEff_7.root 
hadd  AnaMonoJetCutEff_7_4.root     zjets_AnaMonoJetCutEff_7.root    qcd*_AnaMonoJetCutEff_7.root ttbar_AnaMonoJetCutEff_7.root  wjets_AnaMonoJetCutEff_7.root  zinv_AnaMonoJetCutEff_7.root                  
hadd  AnaMonoJetCutEff_8_0.root     zjets_AnaMonoJetCutEff_8.root  
hadd  AnaMonoJetCutEff_8_1.root     zjets_AnaMonoJetCutEff_8.root    qcd*_AnaMonoJetCutEff_8.root 
hadd  AnaMonoJetCutEff_8_2.root     zjets_AnaMonoJetCutEff_8.root    qcd*_AnaMonoJetCutEff_8.root ttbar_AnaMonoJetCutEff_8.root 
hadd  AnaMonoJetCutEff_8_3.root     zjets_AnaMonoJetCutEff_8.root    qcd*_AnaMonoJetCutEff_8.root ttbar_AnaMonoJetCutEff_8.root  wjets_AnaMonoJetCutEff_8.root 
hadd  AnaMonoJetCutEff_8_4.root     zjets_AnaMonoJetCutEff_8.root    qcd*_AnaMonoJetCutEff_8.root ttbar_AnaMonoJetCutEff_8.root  wjets_AnaMonoJetCutEff_8.root  zinv_AnaMonoJetCutEff_8.root   
               
hadd data_0.root   met_AnaMonoJetCutEff_0.root  jetmet_AnaMonoJetCutEff_0.root jetmettau_AnaMonoJetCutEff_0.root
hadd data_1.root   met_AnaMonoJetCutEff_1.root  jetmet_AnaMonoJetCutEff_1.root jetmettau_AnaMonoJetCutEff_1.root
hadd data_2.root   met_AnaMonoJetCutEff_2.root  jetmet_AnaMonoJetCutEff_2.root jetmettau_AnaMonoJetCutEff_2.root
hadd data_3.root   met_AnaMonoJetCutEff_3.root  jetmet_AnaMonoJetCutEff_3.root jetmettau_AnaMonoJetCutEff_3.root
hadd data_4.root   met_AnaMonoJetCutEff_4.root  jetmet_AnaMonoJetCutEff_4.root jetmettau_AnaMonoJetCutEff_4.root
hadd data_5.root   met_AnaMonoJetCutEff_5.root  jetmet_AnaMonoJetCutEff_5.root jetmettau_AnaMonoJetCutEff_5.root
hadd data_6.root   met_AnaMonoJetCutEff_6.root  jetmet_AnaMonoJetCutEff_6.root jetmettau_AnaMonoJetCutEff_6.root
hadd data_7.root   met_AnaMonoJetCutEff_7.root  jetmet_AnaMonoJetCutEff_7.root jetmettau_AnaMonoJetCutEff_7.root
hadd data_8.root   met_AnaMonoJetCutEff_8.root  jetmet_AnaMonoJetCutEff_8.root jetmettau_AnaMonoJetCutEff_8.root

rm -rf eps*
rm *.eps

mkdir  eps_MC_vs_DATA

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Number of Events / 0.02"         AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Number of Events / 0.02"         AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Number of Events / 0.02"         AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Number of Events / 0.02"         AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  Jet1Eta  "Leading Jet #eta "                                   "Number of Events / 0.02"         AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  Jet1Pt   "Leading Jet p_{T} [GeV/c]"                           "Number of Events / 25 [GeV/c]"   AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  Jet2Eta  "Second Jet #eta "                                    "Number of Events / 0.02"         AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  Jet2Pt   "Second Jet p_{T} [GeV/c]"                            "Number of Events / 25 [GeV/c]"   AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  NJet   "Jet Multiplicity"                                      "Number of Events"                AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  dPhi_MetMu_Jet1  "#Delta#phi(Jet1, MET)"                       "Number of Events / 0.1"          AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  dPhi_MetMu_Jet2  "#Delta#phi(Jet2, MET)"                       "Number of Events / 0.1"          AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet1, Jet2)"                       "Number of Events / 0.1"          AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  MetMu1   "MET [GeV/c] "                                        "Number of Events / 25 [GeV/c]"   AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data" 
Merge  MetMuThrs1   "MET Threshold [GeV/c] "                          "Number of Events / 25 [GeV/c]"   AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  MetMu2   "MET [GeV/c] "                                        "Number of Events / 10 [GeV/c]"   AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data" 
Merge  MetMuThrs2   "MET Threshold [GeV/c] "                          "Number of Events / 10 [GeV/c]"   AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  TIV   "Track Isolation Veto "                                  "Number of Events / 0.005"        AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data"
Merge  MuonPt   "Muon p_{T} [GeV/c] "                                 "Number of Events / f [GeV/c]"    AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data" 
Merge  PFMuonPt   "PFMuon p_{T} [GeV/c] "                             "Number of Events / 1 [GeV/c]"    AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data" 
Merge  PFElecPt   "PFElectron p_{T} [GeV/c] "                         "Number of Events / 1 [GeV/c]"    AnaMonoJetCutEff_0_4 "Zinv" AnaMonoJetCutEff_0_3 "WJets" AnaMonoJetCutEff_0_2 "TTbar" AnaMonoJetCutEff_0_1 "QCD"  AnaMonoJetCutEff_0_0 "ZJets" data_0 "Data" 

mv  *.eps  eps_MC_vs_DATA
mv output.root   eps_MC_vs_DATA


mkdir  eps_cuteff_all

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Number of Events / 0.02"          AnaMonoJetCutEff_1_4 "Zinv" AnaMonoJetCutEff_1_3 "WJets" AnaMonoJetCutEff_1_2 "TTbar" AnaMonoJetCutEff_1_1 "QCD"  AnaMonoJetCutEff_1_0 "ZJets" data_1 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Number of Events / 0.02"          AnaMonoJetCutEff_1_4 "Zinv" AnaMonoJetCutEff_1_3 "WJets" AnaMonoJetCutEff_1_2 "TTbar" AnaMonoJetCutEff_1_1 "QCD"  AnaMonoJetCutEff_1_0 "ZJets" data_1 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Number of Events / 0.02"          AnaMonoJetCutEff_1_4 "Zinv" AnaMonoJetCutEff_1_3 "WJets" AnaMonoJetCutEff_1_2 "TTbar" AnaMonoJetCutEff_1_1 "QCD"  AnaMonoJetCutEff_1_0 "ZJets" data_1 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Number of Events / 0.02"          AnaMonoJetCutEff_1_4 "Zinv" AnaMonoJetCutEff_1_3 "WJets" AnaMonoJetCutEff_1_2 "TTbar" AnaMonoJetCutEff_1_1 "QCD"  AnaMonoJetCutEff_1_0 "ZJets" data_1 "Data"
Merge  Jet1Eta  "Leading Jet #eta "                                   "Number of Events / 0.02"          AnaMonoJetCutEff_2_4 "Zinv" AnaMonoJetCutEff_2_3 "WJets" AnaMonoJetCutEff_2_2 "TTbar" AnaMonoJetCutEff_2_1 "QCD"  AnaMonoJetCutEff_2_0 "ZJets" data_2 "Data"
Merge  Jet1Pt   "Leading Jet p_{T} [GeV/c]"                           "Number of Events / 25 [GeV/c]"    AnaMonoJetCutEff_2_4 "Zinv" AnaMonoJetCutEff_2_3 "WJets" AnaMonoJetCutEff_2_2 "TTbar" AnaMonoJetCutEff_2_1 "QCD"  AnaMonoJetCutEff_2_0 "ZJets" data_2 "Data"
Merge  Jet2Eta  "Second Jet #eta "                                    "Number of Events / 0.02"          AnaMonoJetCutEff_2_4 "Zinv" AnaMonoJetCutEff_2_3 "WJets" AnaMonoJetCutEff_2_2 "TTbar" AnaMonoJetCutEff_2_1 "QCD"  AnaMonoJetCutEff_2_0 "ZJets" data_2 "Data"
Merge  Jet2Pt   "Second Jet p_{T} [GeV/c]"                            "Number of Events / 25 [GeV/c]"    AnaMonoJetCutEff_2_4 "Zinv" AnaMonoJetCutEff_2_3 "WJets" AnaMonoJetCutEff_2_2 "TTbar" AnaMonoJetCutEff_2_1 "QCD"  AnaMonoJetCutEff_2_0 "ZJets" data_2 "Data"
Merge  NJet   "Jet Multiplicity"                                      "Number of Events"                 AnaMonoJetCutEff_3_4 "Zinv" AnaMonoJetCutEff_3_3 "WJets" AnaMonoJetCutEff_3_2 "TTbar" AnaMonoJetCutEff_3_1 "QCD"  AnaMonoJetCutEff_3_0 "ZJets" data_3 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet1, Jet2)"                       "Number of Events / 0.1"           AnaMonoJetCutEff_4_4 "Zinv" AnaMonoJetCutEff_4_3 "WJets" AnaMonoJetCutEff_4_2 "TTbar" AnaMonoJetCutEff_4_1 "QCD"  AnaMonoJetCutEff_4_0 "ZJets" data_4 "Data"
Merge  dPhi_MetMu_Jet2  "#Delta#phi(Jet2, MET)"                       "Number of Events / 0.1"           AnaMonoJetCutEff_4_4 "Zinv" AnaMonoJetCutEff_4_3 "WJets" AnaMonoJetCutEff_4_2 "TTbar" AnaMonoJetCutEff_4_1 "QCD"  AnaMonoJetCutEff_4_0 "ZJets" data_4 "Data"
Merge  dPhi_MetMu_Jet1  "#Delta#phi(Jet1, MET)"                       "Number of Events / 0.1"           AnaMonoJetCutEff_4_4 "Zinv" AnaMonoJetCutEff_4_3 "WJets" AnaMonoJetCutEff_4_2 "TTbar" AnaMonoJetCutEff_4_1 "QCD"  AnaMonoJetCutEff_4_0 "ZJets" data_4 "Data"
Merge  MetMu1   "MET [GeV/c] "                                        "Number of Events / 25 [GeV/c]"    AnaMonoJetCutEff_5_4 "Zinv" AnaMonoJetCutEff_5_3 "WJets" AnaMonoJetCutEff_5_2 "TTbar" AnaMonoJetCutEff_5_1 "QCD"  AnaMonoJetCutEff_5_0 "ZJets" data_5 "Data" 
Merge  MetMuThrs1   "MET Threshold [GeV/c] "                          "Number of Events / 25 [GeV/c]"    AnaMonoJetCutEff_5_4 "Zinv" AnaMonoJetCutEff_5_3 "WJets" AnaMonoJetCutEff_5_2 "TTbar" AnaMonoJetCutEff_5_1 "QCD"  AnaMonoJetCutEff_5_0 "ZJets" data_5 "Data"
Merge  MetMu2   "MET [GeV/c] "                                        "Number of Events / 10 [GeV/c]"    AnaMonoJetCutEff_5_4 "Zinv" AnaMonoJetCutEff_5_3 "WJets" AnaMonoJetCutEff_5_2 "TTbar" AnaMonoJetCutEff_5_1 "QCD"  AnaMonoJetCutEff_5_0 "ZJets" data_5 "Data" 
Merge  MetMuThrs2   "MET Threshold [GeV/c] "                          "Number of Events / 10 [GeV/c]"    AnaMonoJetCutEff_5_4 "Zinv" AnaMonoJetCutEff_5_3 "WJets" AnaMonoJetCutEff_5_2 "TTbar" AnaMonoJetCutEff_5_1 "QCD"  AnaMonoJetCutEff_5_0 "ZJets" data_5 "Data"
Merge  TIV      "Track Isolation Veto"                                "Number of Events / 0.005"         AnaMonoJetCutEff_6_4 "Zinv" AnaMonoJetCutEff_6_3 "WJets" AnaMonoJetCutEff_6_2 "TTbar" AnaMonoJetCutEff_6_1 "QCD"  AnaMonoJetCutEff_6_0 "ZJets" data_6 "Data" 
Merge  PFMuonPt   "PFMuon p_{T} [GeV/c] "                             "Number of Events / f [GeV/c]"     AnaMonoJetCutEff_7_4 "Zinv" AnaMonoJetCutEff_7_3 "WJets" AnaMonoJetCutEff_7_2 "TTbar" AnaMonoJetCutEff_7_1 "QCD"  AnaMonoJetCutEff_7_0 "ZJets" data_7 "Data" 
Merge  PFElecPt   "PFElectron p_{T} [GeV/c] "                         "Number of Events / 1 [GeV/c]"     AnaMonoJetCutEff_7_4 "Zinv" AnaMonoJetCutEff_7_3 "WJets" AnaMonoJetCutEff_7_2 "TTbar" AnaMonoJetCutEff_7_1 "QCD"  AnaMonoJetCutEff_7_0 "ZJets" data_7 "Data" 
Merge  MuonPt   "Muon p_{T} [GeV/c] "                                 "Number of Events / 1 [GeV/c]"     AnaMonoJetCutEff_8_4 "Zinv" AnaMonoJetCutEff_8_3 "WJets" AnaMonoJetCutEff_8_2 "TTbar" AnaMonoJetCutEff_8_1 "QCD"  AnaMonoJetCutEff_8_0 "ZJets" data_8 "Data" 

mv  *.eps  eps_cuteff_all
mv output.root  eps_cuteff_all


mkdir  eps_cuteff_bck

Merge2  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"   "Number of Events / 0.02"         AnaMonoJetCutEff_1_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"   "Number of Events / 0.02"         AnaMonoJetCutEff_1_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"        "Number of Events / 0.02"         AnaMonoJetCutEff_1_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"        "Number of Events / 0.02"         AnaMonoJetCutEff_1_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  Jet1Eta  "Leading Jet #eta "                                    "Number of Events / 0.02"         AnaMonoJetCutEff_2_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  Jet1Pt   "Leading Jet p_{T} [GeV/c]"                            "Number of Events / 25 [GeV/c]"   AnaMonoJetCutEff_2_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  Jet2Eta  "Second Jet #eta "                                     "Number of Events / 0.02"         AnaMonoJetCutEff_2_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  Jet2Pt   "Second Jet p_{T} [GeV/c]"                             "Number of Events / 25 [GeV/c]"   AnaMonoJetCutEff_2_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  NJet   "Jet Multiplicity"                                       "Number of Events"                AnaMonoJetCutEff_3_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  dPhi_Jet1_Jet2  "#Delta#phi(Jet1, Jet2)"                        "Number of Events / 0.1"          AnaMonoJetCutEff_4_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  dPhi_MetMu_Jet2  "#Delta#phi(Jet2, MET)"                        "Number of Events / 0.1"          AnaMonoJetCutEff_4_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  dPhi_MetMu_Jet1  "#Delta#phi(Jet1, MET)"                        "Number of Events / 0.1"          AnaMonoJetCutEff_4_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  MetMu1   "MET [GeV/c] "                                         "Number of Events / 25 [GeV/c]"   AnaMonoJetCutEff_5_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  MetMuThrs1   "MET Threshold [GeV/c] "                           "Number of Events / 25 [GeV/c]"   AnaMonoJetCutEff_5_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  MetMu2   "MET [GeV/c] "                                         "Number of Events / 10 [GeV/c]"   AnaMonoJetCutEff_5_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  MetMuThrs2   "MET Threshold [GeV/c] "                           "Number of Events / 10 [GeV/c]"   AnaMonoJetCutEff_5_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  TIV      "Track Isolation Veto"                                 "Number of Events / 0.005"        AnaMonoJetCutEff_6_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  PFMuonPt   "PFMuon p_{T} [GeV/c] "                              "Number of Events / f [GeV/c]"    AnaMonoJetCutEff_7_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  PFElecPt   "PFElectron p_{T} [GeV/c] "                          "Number of Events / 1 [GeV/c]"    AnaMonoJetCutEff_7_4 "Before" AnaMonoJetCutEff_0_4 "After" 
Merge2  MuonPt   "Muon p_{T} [GeV/c] "                                  "Number of Events / 1 [GeV/c]"    AnaMonoJetCutEff_8_4 "Before" AnaMonoJetCutEff_0_4 "After" 

mv  *.eps  eps_cuteff_bck
mv output.root  eps_cuteff_bck


mkdir  eps_cuteff_data

Merge2  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Number of Events / 0.02"          data_1 "Before" data_0 "After" 
Merge2  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Number of Events / 0.02"          data_1 "Before" data_0 "After" 
Merge2  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Number of Events / 0.02"          data_1 "Before" data_0 "After" 
Merge2  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Number of Events / 0.02"          data_1 "Before" data_0 "After" 
Merge2  Jet1Eta  "Leading Jet #eta "                                   "Number of Events / 0.02"          data_2 "Before" data_0 "After" 
Merge2  Jet1Pt   "Leading Jet p_{T} [GeV/c]"                           "Number of Events / 25 [GeV/c]"    data_2 "Before" data_0 "After" 
Merge2  Jet2Eta  "Second Jet #eta "                                    "Number of Events / 0.02"          data_2 "Before" data_0 "After" 
Merge2  Jet2Pt   "Second Jet p_{T} [GeV/c]"                            "Number of Events / 25 [GeV/c]"    data_2 "Before" data_0 "After" 
Merge2  NJet   "Jet Multiplicity"                                      "Number of Events"                 data_3 "Before" data_0 "After" 
Merge2  dPhi_Jet1_Jet2  "#Delta#phi(Jet1, Jet2)"                       "Number of Events / 0.1"           data_4 "Before" data_0 "After" 
Merge2  dPhi_MetMu_Jet2  "#Delta#phi(Jet2, MET)"                       "Number of Events / 0.1"           data_4 "Before" data_0 "After" 
Merge2  dPhi_MetMu_Jet1  "#Delta#phi(Jet1, MET)"                       "Number of Events / 0.1"           data_4 "Before" data_0 "After" 
Merge2  MetMu1   "MET [GeV/c] "                                        "Number of Events / 25 [GeV/c]"    data_5 "Before" data_0 "After" 
Merge2  MetMuThrs1   "MET Threshold [GeV/c] "                          "Number of Events / 25 [GeV/c]"    data_5 "Before" data_0 "After" 
Merge2  MetMu2   "MET [GeV/c] "                                        "Number of Events / 10 [GeV/c]"    data_5 "Before" data_0 "After" 
Merge2  MetMuThrs2   "MET Threshold [GeV/c] "                          "Number of Events / 10 [GeV/c]"    data_5 "Before" data_0 "After" 
Merge2  TIV      "Track Isolation Veto"                                "Number of Events / 0.005"         data_6 "Before" data_0 "After" 
Merge2  PFMuonPt   "PFMuon p_{T} [GeV/c] "                             "Number of Events / f [GeV/c]"     data_7 "Before" data_0 "After" 
Merge2  PFElecPt   "PFElectron p_{T} [GeV/c] "                         "Number of Events / 1 [GeV/c]"     data_7 "Before" data_0 "After" 
Merge2  MuonPt   "Muon p_{T} [GeV/c] "                                 "Number of Events / 1 [GeV/c]"     data_8 "Before" data_0 "After" 

mv  *.eps  eps_cuteff_data
mv output.root    eps_cuteff_data

mkdir  eps_cuteff_sig

Merge2  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Number of Events / 0.02"         md2d2_AnaMonoJetCutEff_1 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Number of Events / 0.02"         md2d2_AnaMonoJetCutEff_1 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Number of Events / 0.02"         md2d2_AnaMonoJetCutEff_1 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Number of Events / 0.02"         md2d2_AnaMonoJetCutEff_1 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  Jet1Eta  "Leading Jet #eta "                                   "Number of Events / 0.02"         md2d2_AnaMonoJetCutEff_2 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  Jet1Pt   "Leading Jet p_{T} [GeV/c]"                           "Number of Events / 25 [GeV/c]"   md2d2_AnaMonoJetCutEff_2 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  Jet2Eta  "Second Jet #eta "                                    "Number of Events / 0.02"         md2d2_AnaMonoJetCutEff_2 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  Jet2Pt   "Second Jet p_{T} [GeV/c]"                            "Number of Events / 25 [GeV/c]"   md2d2_AnaMonoJetCutEff_2 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  NJet   "Jet Multiplicity"                                      "Number of Events"                md2d2_AnaMonoJetCutEff_3 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  dPhi_Jet1_Jet2  "#Delta#phi(Jet1, Jet2)"                       "Number of Events / 0.1"          md2d2_AnaMonoJetCutEff_4 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  dPhi_MetMu_Jet2  "#Delta#phi(Jet2, MET)"                       "Number of Events / 0.1"          md2d2_AnaMonoJetCutEff_4 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  dPhi_MetMu_Jet1  "#Delta#phi(Jet1, MET)"                       "Number of Events / 0.1"          md2d2_AnaMonoJetCutEff_4 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  MetMu1   "MET [GeV/c] "                                        "Number of Events / 25 [GeV/c]"   md2d2_AnaMonoJetCutEff_5 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  MetMuThrs1   "MET Threshold [GeV/c] "                          "Number of Events / 25 [GeV/c]"   md2d2_AnaMonoJetCutEff_5 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  MetMu2   "MET [GeV/c] "                                        "Number of Events / 10 [GeV/c]"   md2d2_AnaMonoJetCutEff_5 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  MetMuThrs2   "MET Threshold [GeV/c] "                          "Number of Events / 10 [GeV/c]"   md2d2_AnaMonoJetCutEff_5 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  TIV      "Track Isolation Veto"                                "Number of Events / 0.005"        md2d2_AnaMonoJetCutEff_6 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  PFMuonPt   "PFMuon p_{T} [GeV/c] "                             "Number of Events / f [GeV/c]"    md2d2_AnaMonoJetCutEff_7 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  PFElecPt   "PFElectron p_{T} [GeV/c] "                         "Number of Events / 1 [GeV/c]"    md2d2_AnaMonoJetCutEff_7 "Before" md2d2_AnaMonoJetCutEff_0 "After" 
Merge2  MuonPt   "Muon p_{T} [GeV/c] "                                 "Number of Events / 1 [GeV/c]"    md2d2_AnaMonoJetCutEff_8 "Before" md2d2_AnaMonoJetCutEff_0 "After" 

mv  *.eps  eps_cuteff_sig
mv output.root   eps_cuteff_sig




cd  /uscms_data/d2/vergili/may/MONO/CMSSW_3_8_7/src/MonoJetAnalysis/NtupleAnalyzer/results/AnaMonoJetCutEff/eps_cuteff_all1
kcp  -s "Monojet Analysis MC vs Data" -b "All Cuts was applied"  *.* lqfai@kbook.fnal.gov:1443


cd  /uscms_data/d2/vergili/may/MONO/CMSSW_3_8_7/src/MonoJetAnalysis/NtupleAnalyzer/results/AnaMonoJetCutEff/eps_cuteff_all2
kcp  -s "Monojet Analysis Cut Effciency" -b "Checkign of  cut effect " *.* lqfai@kbook.fnal.gov:1443


