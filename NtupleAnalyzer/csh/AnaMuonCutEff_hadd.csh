#!/bin/tcsh -f


rm  AnaMuonCutEff_*
rm  data_*

rm output.root

hadd  AnaMuonCutEff_0_0.root     zjets_AnaMuonCutEff_0.root  
hadd  AnaMuonCutEff_0_1.root     zjets_AnaMuonCutEff_0.root    qcd*_AnaMuonCutEff_0.root 
hadd  AnaMuonCutEff_0_2.root     zjets_AnaMuonCutEff_0.root    qcd*_AnaMuonCutEff_0.root ttbar_AnaMuonCutEff_0.root 
hadd  AnaMuonCutEff_0_3.root     zjets_AnaMuonCutEff_0.root    qcd*_AnaMuonCutEff_0.root ttbar_AnaMuonCutEff_0.root  wjets_AnaMuonCutEff_0.root 
hadd  AnaMuonCutEff_0_4.root     zjets_AnaMuonCutEff_0.root    qcd*_AnaMuonCutEff_0.root ttbar_AnaMuonCutEff_0.root  wjets_AnaMuonCutEff_0.root  znunu*_AnaMuonCutEff_0.root                  

hadd  AnaMuonCutEff_1_0.root     zjets_AnaMuonCutEff_1.root 
hadd  AnaMuonCutEff_1_1.root     zjets_AnaMuonCutEff_1.root    qcd*_AnaMuonCutEff_1.root 
hadd  AnaMuonCutEff_1_2.root     zjets_AnaMuonCutEff_1.root    qcd*_AnaMuonCutEff_1.root ttbar_AnaMuonCutEff_1.root 
hadd  AnaMuonCutEff_1_3.root     zjets_AnaMuonCutEff_1.root    qcd*_AnaMuonCutEff_1.root ttbar_AnaMuonCutEff_1.root  wjets_AnaMuonCutEff_1.root 
hadd  AnaMuonCutEff_1_4.root     zjets_AnaMuonCutEff_1.root    qcd*_AnaMuonCutEff_1.root ttbar_AnaMuonCutEff_1.root  wjets_AnaMuonCutEff_1.root  znunu*_AnaMuonCutEff_1.root                  

hadd  AnaMuonCutEff_2_0.root     zjets_AnaMuonCutEff_2.root  
hadd  AnaMuonCutEff_2_1.root     zjets_AnaMuonCutEff_2.root    qcd*_AnaMuonCutEff_2.root 
hadd  AnaMuonCutEff_2_2.root     zjets_AnaMuonCutEff_2.root    qcd*_AnaMuonCutEff_2.root ttbar_AnaMuonCutEff_2.root 
hadd  AnaMuonCutEff_2_3.root     zjets_AnaMuonCutEff_2.root    qcd*_AnaMuonCutEff_2.root ttbar_AnaMuonCutEff_2.root  wjets_AnaMuonCutEff_2.root 
hadd  AnaMuonCutEff_2_4.root     zjets_AnaMuonCutEff_2.root    qcd*_AnaMuonCutEff_2.root ttbar_AnaMuonCutEff_2.root  wjets_AnaMuonCutEff_2.root  znunu*_AnaMuonCutEff_2.root

hadd  AnaMuonCutEff_3_0.root     zjets_AnaMuonCutEff_3.root  
hadd  AnaMuonCutEff_3_1.root     zjets_AnaMuonCutEff_3.root    qcd*_AnaMuonCutEff_3.root 
hadd  AnaMuonCutEff_3_2.root     zjets_AnaMuonCutEff_3.root    qcd*_AnaMuonCutEff_3.root ttbar_AnaMuonCutEff_3.root 
hadd  AnaMuonCutEff_3_3.root     zjets_AnaMuonCutEff_3.root    qcd*_AnaMuonCutEff_3.root ttbar_AnaMuonCutEff_3.root  wjets_AnaMuonCutEff_3.root 
hadd  AnaMuonCutEff_3_4.root     zjets_AnaMuonCutEff_3.root    qcd*_AnaMuonCutEff_3.root ttbar_AnaMuonCutEff_3.root  wjets_AnaMuonCutEff_3.root  znunu*_AnaMuonCutEff_3.root                  

hadd  AnaMuonCutEff_4_0.root     zjets_AnaMuonCutEff_4.root  
hadd  AnaMuonCutEff_4_1.root     zjets_AnaMuonCutEff_4.root    qcd*_AnaMuonCutEff_4.root 
hadd  AnaMuonCutEff_4_2.root     zjets_AnaMuonCutEff_4.root    qcd*_AnaMuonCutEff_4.root ttbar_AnaMuonCutEff_4.root 
hadd  AnaMuonCutEff_4_3.root     zjets_AnaMuonCutEff_4.root    qcd*_AnaMuonCutEff_4.root ttbar_AnaMuonCutEff_4.root  wjets_AnaMuonCutEff_4.root 
hadd  AnaMuonCutEff_4_4.root     zjets_AnaMuonCutEff_4.root    qcd*_AnaMuonCutEff_4.root ttbar_AnaMuonCutEff_4.root  wjets_AnaMuonCutEff_4.root  znunu*_AnaMuonCutEff_4.root                  

hadd  AnaMuonCutEff_5_0.root     zjets_AnaMuonCutEff_5.root  
hadd  AnaMuonCutEff_5_1.root     zjets_AnaMuonCutEff_5.root    qcd*_AnaMuonCutEff_5.root 
hadd  AnaMuonCutEff_5_2.root     zjets_AnaMuonCutEff_5.root    qcd*_AnaMuonCutEff_5.root ttbar_AnaMuonCutEff_5.root 
hadd  AnaMuonCutEff_5_3.root     zjets_AnaMuonCutEff_5.root    qcd*_AnaMuonCutEff_5.root ttbar_AnaMuonCutEff_5.root  wjets_AnaMuonCutEff_5.root 
hadd  AnaMuonCutEff_5_4.root     zjets_AnaMuonCutEff_5.root    qcd*_AnaMuonCutEff_5.root ttbar_AnaMuonCutEff_5.root  wjets_AnaMuonCutEff_5.root  znunu*_AnaMuonCutEff_5.root                  

hadd  AnaMuonCutEff_6_0.root     zjets_AnaMuonCutEff_6.root  
hadd  AnaMuonCutEff_6_1.root     zjets_AnaMuonCutEff_6.root    qcd*_AnaMuonCutEff_6.root 
hadd  AnaMuonCutEff_6_2.root     zjets_AnaMuonCutEff_6.root    qcd*_AnaMuonCutEff_6.root ttbar_AnaMuonCutEff_6.root 
hadd  AnaMuonCutEff_6_3.root     zjets_AnaMuonCutEff_6.root    qcd*_AnaMuonCutEff_6.root ttbar_AnaMuonCutEff_6.root  wjets_AnaMuonCutEff_6.root 
hadd  AnaMuonCutEff_6_4.root     zjets_AnaMuonCutEff_6.root    qcd*_AnaMuonCutEff_6.root ttbar_AnaMuonCutEff_6.root  wjets_AnaMuonCutEff_6.root  znunu*_AnaMuonCutEff_6.root                  

hadd data_0.root   met*_AnaMuonCutEff_0.root    
hadd data_1.root   met*_AnaMuonCutEff_1.root    
hadd data_2.root   met*_AnaMuonCutEff_2.root    
hadd data_3.root   met*_AnaMuonCutEff_3.root   
hadd data_4.root   met*_AnaMuonCutEff_4.root    
hadd data_5.root   met*_AnaMuonCutEff_5.root    
hadd data_6.root   met*_AnaMuonCutEff_6.root  

rm -rf eps*
rm *.eps

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"   "Events / 0.02"          AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"   "Events / 0.02"          AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"        "Events / 0.02"          AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"        "Events / 0.02"          AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  Jet1Eta  "#eta(Jet_{1}) "                                       "Events / 0.02"          AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  Jet1Pt   "p_{T}(Jet_{1}) [GeV/c]"                           "Events / 25 GeV/c"          AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  Jet1Pt2   "p_{T}(Jet_{1}) [GeV/c]"                           "Events / 25 GeV/c"          AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  Jet2Eta  "#eta(Jet_{2}) "                                       "Events / 0.02"          AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  Jet2Pt   "p_{T}(Jet_{2}) [GeV/c]"                           "Events / 25 GeV/c"          AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  NJet   "Jet Multiplicity"                                       "Events"                 AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  dPhi_MetLep_Jet1  "#Delta#phi(Jet_{1}, |#vecE^{miss}_{T}+#vecp_{T}(#mu)|))"   "Events / 0.1"    AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  dPhi_MetLep_Jet2  "#Delta#phi(Jet_{2}, |#vecE^{miss}_{T}+#vecp_{T}(#mu)|))"   "Events / 0.1"    AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet_{1}, Jet_{2})"                  "Events / 0.1"                 AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  MetLep1   "|#vecE^{miss}_{T}+#vecp_{T}(#mu)| [GeV] "             "Events / 25 GeV"              AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 
Merge  MetLepThrs1 "|#vecE^{miss}_{T}+#vecp_{T}(#mu)| Threshold [GeV]"  "Integrated Events / 25 GeV"   AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  MetLep2   "|#vecE^{miss}_{T}+#vecp_{T}(#mu)| [GeV] "             "Events / 25 GeV"              AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 
Merge  MetLep3   "|#vecE^{miss}_{T}+#vecp_{T}(#mu)| [GeV] "             "Events / 25 GeV"              AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 
Merge  MetLepThrs2 "|#vecE^{miss}_{T}+#vecp_{T}(#mu)| Threshold [GeV]"  "Integrated Events / 25 GeV"   AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  TIV   "Track Isolation Veto "                                   "Events / 0.005"               AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"                 
Merge  MuonPt     "p_{T}(#mu) [GeV/c] "                            "Events / 10 GeV/c"                AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 
Merge  PFMuonPt   "p_{T}(#mu) [GeV/c] "                            "Events / 1 GeV/c"                 AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 
Merge  PFElecPt   "p_{T}(e) [GeV/c] "                              "Events / 1 GeV/c"                 AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 
Merge  NPV   "Number of Primary Vertex"                            "Events"                           AnaMuonCutEff_0_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_0_3 "W#rightarrowl#nu" AnaMuonCutEff_0_2 "t#bar{t}" AnaMuonCutEff_0_1 "QCD"  AnaMuonCutEff_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 



mkdir  eps_MC_vs_DATA
mv  *.eps  eps_MC_vs_DATA
mv output.root  eps_MC_vs_DATA

mkdir eps_cuteff_all

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"   "Events / 0.02"          AnaMuonCutEff_1_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_1_3 "W#rightarrowl#nu" AnaMuonCutEff_1_2 "t#bar{t}" AnaMuonCutEff_1_1 "QCD"  AnaMuonCutEff_1_0 "Z#rightarrowl^{+}l^{-}" data_1 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"   "Events / 0.02"          AnaMuonCutEff_1_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_1_3 "W#rightarrowl#nu" AnaMuonCutEff_1_2 "t#bar{t}" AnaMuonCutEff_1_1 "QCD"  AnaMuonCutEff_1_0 "Z#rightarrowl^{+}l^{-}" data_1 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"        "Events / 0.02"          AnaMuonCutEff_1_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_1_3 "W#rightarrowl#nu" AnaMuonCutEff_1_2 "t#bar{t}" AnaMuonCutEff_1_1 "QCD"  AnaMuonCutEff_1_0 "Z#rightarrowl^{+}l^{-}" data_1 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"        "Events / 0.02"          AnaMuonCutEff_1_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_1_3 "W#rightarrowl#nu" AnaMuonCutEff_1_2 "t#bar{t}" AnaMuonCutEff_1_1 "QCD"  AnaMuonCutEff_1_0 "Z#rightarrowl^{+}l^{-}" data_1 "Data"
Merge  Jet1Eta  "#eta(Jet_{1}) "                                       "Events / 0.02"          AnaMuonCutEff_2_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_2_3 "W#rightarrowl#nu" AnaMuonCutEff_2_2 "t#bar{t}" AnaMuonCutEff_2_1 "QCD"  AnaMuonCutEff_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  Jet1Pt   "p_{T}(Jet_{1}) [GeV/c]"                               "Events / 25 GeV/c"    AnaMuonCutEff_2_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_2_3 "W#rightarrowl#nu" AnaMuonCutEff_2_2 "t#bar{t}" AnaMuonCutEff_2_1 "QCD"  AnaMuonCutEff_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  Jet1Pt2   "p_{T}(Jet_{1}) [GeV/c]"                               "Events / 25 GeV/c"    AnaMuonCutEff_2_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_2_3 "W#rightarrowl#nu" AnaMuonCutEff_2_2 "t#bar{t}" AnaMuonCutEff_2_1 "QCD"  AnaMuonCutEff_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  Jet2Eta  "#eta(Jet_{2}) "                                       "Events / 0.02"          AnaMuonCutEff_2_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_2_3 "W#rightarrowl#nu" AnaMuonCutEff_2_2 "t#bar{t}" AnaMuonCutEff_2_1 "QCD"  AnaMuonCutEff_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  Jet2Pt   "p_{T}(Jet_{2}) [GeV/c]"                               "Events / 25 GeV/c"    AnaMuonCutEff_2_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_2_3 "W#rightarrowl#nu" AnaMuonCutEff_2_2 "t#bar{t}" AnaMuonCutEff_2_1 "QCD"  AnaMuonCutEff_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  NJet   "Jet Multiplicity"                                       "Events"                 AnaMuonCutEff_3_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_3_3 "W#rightarrowl#nu" AnaMuonCutEff_3_2 "t#bar{t}" AnaMuonCutEff_3_1 "QCD"  AnaMuonCutEff_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  dPhi_MetLep_Jet1  "#Delta#phi(Jet_{1}, |#vecE^{miss}_{T}+#vecp_{T}(#mu)|)"  "Events / 0.1"        AnaMuonCutEff_4_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_4_3 "W#rightarrowl#nu" AnaMuonCutEff_4_2 "t#bar{t}" AnaMuonCutEff_4_1 "QCD"  AnaMuonCutEff_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  dPhi_MetLep_Jet2 "#Delta#phi(Jet_{2}, |#vecE^{miss}_{T}+#vecp_{T}(#mu)|)" "Events / 0.1"          AnaMuonCutEff_4_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_4_3 "W#rightarrowl#nu" AnaMuonCutEff_4_2 "t#bar{t}" AnaMuonCutEff_4_1 "QCD"  AnaMuonCutEff_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet_{1}, Jet_{2})"                  "Events / 0.1"           AnaMuonCutEff_4_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_4_3 "W#rightarrowl#nu" AnaMuonCutEff_4_2 "t#bar{t}" AnaMuonCutEff_4_1 "QCD"  AnaMuonCutEff_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  MetLep1   "|#vecE^{miss}_{T}+#vecp_{T}(#mu)| [GeV] "             "Events / 25 GeV"    AnaMuonCutEff_5_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_5_3 "W#rightarrowl#nu" AnaMuonCutEff_5_2 "t#bar{t}" AnaMuonCutEff_5_1 "QCD"  AnaMuonCutEff_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data" 
Merge  MetLepThrs1  "|#vecE^{miss}_{T}+#vecp_{T}(#mu)| Threshold [GeV]" "Integrated Events / 25 GeV"    AnaMuonCutEff_5_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_5_3 "W#rightarrowl#nu" AnaMuonCutEff_5_2 "t#bar{t}" AnaMuonCutEff_5_1 "QCD"  AnaMuonCutEff_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  MetLep2   "|#vecE^{miss}_{T}+#vecp_{T}(#mu)| [GeV] "             "Events / 25 GeV"    AnaMuonCutEff_5_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_5_3 "W#rightarrowl#nu" AnaMuonCutEff_5_2 "t#bar{t}" AnaMuonCutEff_5_1 "QCD"  AnaMuonCutEff_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data" 
Merge  MetLep3   "|#vecE^{miss}_{T}+#vecp_{T}(#mu)| [GeV] "             "Events / 25 GeV"    AnaMuonCutEff_5_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_5_3 "W#rightarrowl#nu" AnaMuonCutEff_5_2 "t#bar{t}" AnaMuonCutEff_5_1 "QCD"  AnaMuonCutEff_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data" 
Merge  MetLepThrs2 "|#vecE^{miss}_{T}+#vecp_{T}(#mu)| Threshold [GeV]"  "Integrated Events / 25 GeV"    AnaMuonCutEff_5_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_5_3 "W#rightarrowl#nu" AnaMuonCutEff_5_2 "t#bar{t}" AnaMuonCutEff_5_1 "QCD"  AnaMuonCutEff_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  TIV   "Track Isolation Veto "              "Events / 0.005 " AnaMuonCutEff_6_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_6_3 "W#rightarrowl#nu" AnaMuonCutEff_6_2 "t#bar{t}" AnaMuonCutEff_6_1 "QCD"  AnaMuonCutEff_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data" 
Merge  MuonPt     "p_{T}(#mu) [GeV/c] "                            "Events / 10 GeV/c"    AnaMuonCutEff_6_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_6_3 "W#rightarrowl#nu" AnaMuonCutEff_6_2 "t#bar{t}" AnaMuonCutEff_6_1 "QCD"  AnaMuonCutEff_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data" 
Merge  PFMuonPt   "p_{T}(#mu) [GeV/c] "                            "Events / 1 GeV/c"     AnaMuonCutEff_6_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_6_3 "W#rightarrowl#nu" AnaMuonCutEff_6_2 "t#bar{t}" AnaMuonCutEff_6_1 "QCD"  AnaMuonCutEff_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data" 
Merge  PFElecPt   "p_{T}(e) [GeV/c] "                              "Events / 1 GeV/c"     AnaMuonCutEff_6_4 "Z#rightarrow#nu#nu" AnaMuonCutEff_6_3 "W#rightarrowl#nu" AnaMuonCutEff_6_2 "t#bar{t}" AnaMuonCutEff_6_1 "QCD"  AnaMuonCutEff_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data" 

mv  *.eps  eps_cuteff_all
mv output.root    eps_cuteff_all


