#!/bin/tcsh -f


rm  AnaMonoJet_*
rm  data_*
rm -rf  eps*
rm output.root 

hadd  AnaMonoJet_0_0.root     zjets_AnaMonoJet_0.root  
hadd  AnaMonoJet_0_1.root     zjets_AnaMonoJet_0.root    qcd*_AnaMonoJet_0.root 
hadd  AnaMonoJet_0_2.root     zjets_AnaMonoJet_0.root    qcd*_AnaMonoJet_0.root ttbar_AnaMonoJet_0.root 
hadd  AnaMonoJet_0_3.root     zjets_AnaMonoJet_0.root    qcd*_AnaMonoJet_0.root ttbar_AnaMonoJet_0.root  wjets_AnaMonoJet_0.root 
hadd  AnaMonoJet_0_4.root     zjets_AnaMonoJet_0.root    qcd*_AnaMonoJet_0.root ttbar_AnaMonoJet_0.root  wjets_AnaMonoJet_0.root  znunu*_AnaMonoJet_0.root  
hadd  AnaMonoJet_0_5.root     zjets_AnaMonoJet_0.root    qcd*_AnaMonoJet_0.root ttbar_AnaMonoJet_0.root  wjets_AnaMonoJet_0.root  znunu*_AnaMonoJet_0.root  md2d2_AnaMonoJet_0.root 

                
hadd  AnaMonoJet_1_0.root     zjets_AnaMonoJet_1.root  
hadd  AnaMonoJet_1_1.root     zjets_AnaMonoJet_1.root    qcd*_AnaMonoJet_1.root 
hadd  AnaMonoJet_1_2.root     zjets_AnaMonoJet_1.root    qcd*_AnaMonoJet_1.root ttbar_AnaMonoJet_1.root 
hadd  AnaMonoJet_1_3.root     zjets_AnaMonoJet_1.root    qcd*_AnaMonoJet_1.root ttbar_AnaMonoJet_1.root  wjets_AnaMonoJet_1.root 
hadd  AnaMonoJet_1_4.root     zjets_AnaMonoJet_1.root    qcd*_AnaMonoJet_1.root ttbar_AnaMonoJet_1.root  wjets_AnaMonoJet_1.root  znunu*_AnaMonoJet_1.root    
hadd  AnaMonoJet_1_5.root     zjets_AnaMonoJet_1.root    qcd*_AnaMonoJet_1.root ttbar_AnaMonoJet_1.root  wjets_AnaMonoJet_1.root  znunu*_AnaMonoJet_1.root  md2d2_AnaMonoJet_1.root 

              
hadd  AnaMonoJet_2_0.root     zjets_AnaMonoJet_2.root  
hadd  AnaMonoJet_2_1.root     zjets_AnaMonoJet_2.root    qcd*_AnaMonoJet_2.root 
hadd  AnaMonoJet_2_2.root     zjets_AnaMonoJet_2.root    qcd*_AnaMonoJet_2.root ttbar_AnaMonoJet_2.root 
hadd  AnaMonoJet_2_3.root     zjets_AnaMonoJet_2.root    qcd*_AnaMonoJet_2.root ttbar_AnaMonoJet_2.root  wjets_AnaMonoJet_2.root 
hadd  AnaMonoJet_2_4.root     zjets_AnaMonoJet_2.root    qcd*_AnaMonoJet_2.root ttbar_AnaMonoJet_2.root  wjets_AnaMonoJet_2.root  znunu*_AnaMonoJet_2.root 
hadd  AnaMonoJet_2_5.root     zjets_AnaMonoJet_2.root    qcd*_AnaMonoJet_2.root ttbar_AnaMonoJet_2.root  wjets_AnaMonoJet_2.root  znunu*_AnaMonoJet_2.root md2d2_AnaMonoJet_2.root

                 
hadd  AnaMonoJet_3_0.root     zjets_AnaMonoJet_3.root  
hadd  AnaMonoJet_3_1.root     zjets_AnaMonoJet_3.root    qcd*_AnaMonoJet_3.root 
hadd  AnaMonoJet_3_2.root     zjets_AnaMonoJet_3.root    qcd*_AnaMonoJet_3.root ttbar_AnaMonoJet_3.root 
hadd  AnaMonoJet_3_3.root     zjets_AnaMonoJet_3.root    qcd*_AnaMonoJet_3.root ttbar_AnaMonoJet_3.root  wjets_AnaMonoJet_3.root 
hadd  AnaMonoJet_3_4.root     zjets_AnaMonoJet_3.root    qcd*_AnaMonoJet_3.root ttbar_AnaMonoJet_3.root  wjets_AnaMonoJet_3.root  znunu*_AnaMonoJet_3.root  
hadd  AnaMonoJet_3_5.root     zjets_AnaMonoJet_3.root    qcd*_AnaMonoJet_3.root ttbar_AnaMonoJet_3.root  wjets_AnaMonoJet_3.root  znunu*_AnaMonoJet_3.root md2d2_AnaMonoJet_3.root 

                
hadd  AnaMonoJet_4_0.root     zjets_AnaMonoJet_4.root  
hadd  AnaMonoJet_4_1.root     zjets_AnaMonoJet_4.root    qcd*_AnaMonoJet_4.root 
hadd  AnaMonoJet_4_2.root     zjets_AnaMonoJet_4.root    qcd*_AnaMonoJet_4.root ttbar_AnaMonoJet_4.root 
hadd  AnaMonoJet_4_3.root     zjets_AnaMonoJet_4.root    qcd*_AnaMonoJet_4.root ttbar_AnaMonoJet_4.root  wjets_AnaMonoJet_4.root 
hadd  AnaMonoJet_4_4.root     zjets_AnaMonoJet_4.root    qcd*_AnaMonoJet_4.root ttbar_AnaMonoJet_4.root  wjets_AnaMonoJet_4.root  znunu*_AnaMonoJet_4.root 
hadd  AnaMonoJet_4_5.root     zjets_AnaMonoJet_4.root    qcd*_AnaMonoJet_4.root ttbar_AnaMonoJet_4.root  wjets_AnaMonoJet_4.root  znunu*_AnaMonoJet_4.root md2d2_AnaMonoJet_4.root

                 
hadd  AnaMonoJet_5_0.root     zjets_AnaMonoJet_5.root  
hadd  AnaMonoJet_5_1.root     zjets_AnaMonoJet_5.root    qcd*_AnaMonoJet_5.root 
hadd  AnaMonoJet_5_2.root     zjets_AnaMonoJet_5.root    qcd*_AnaMonoJet_5.root ttbar_AnaMonoJet_5.root 
hadd  AnaMonoJet_5_3.root     zjets_AnaMonoJet_5.root    qcd*_AnaMonoJet_5.root ttbar_AnaMonoJet_5.root  wjets_AnaMonoJet_5.root 
hadd  AnaMonoJet_5_4.root     zjets_AnaMonoJet_5.root    qcd*_AnaMonoJet_5.root ttbar_AnaMonoJet_5.root  wjets_AnaMonoJet_5.root  znunu*_AnaMonoJet_5.root  
hadd  AnaMonoJet_5_5.root     zjets_AnaMonoJet_5.root    qcd*_AnaMonoJet_5.root ttbar_AnaMonoJet_5.root  wjets_AnaMonoJet_5.root  znunu*_AnaMonoJet_5.root md2d2_AnaMonoJet_5.root 

                
hadd  AnaMonoJet_6_0.root     zjets_AnaMonoJet_6.root  
hadd  AnaMonoJet_6_1.root     zjets_AnaMonoJet_6.root    qcd*_AnaMonoJet_6.root 
hadd  AnaMonoJet_6_2.root     zjets_AnaMonoJet_6.root    qcd*_AnaMonoJet_6.root ttbar_AnaMonoJet_6.root 
hadd  AnaMonoJet_6_3.root     zjets_AnaMonoJet_6.root    qcd*_AnaMonoJet_6.root ttbar_AnaMonoJet_6.root  wjets_AnaMonoJet_6.root 
hadd  AnaMonoJet_6_4.root     zjets_AnaMonoJet_6.root    qcd*_AnaMonoJet_6.root ttbar_AnaMonoJet_6.root  wjets_AnaMonoJet_6.root  znunu*_AnaMonoJet_6.root   
hadd  AnaMonoJet_6_5.root     zjets_AnaMonoJet_6.root    qcd*_AnaMonoJet_6.root ttbar_AnaMonoJet_6.root  wjets_AnaMonoJet_6.root  znunu*_AnaMonoJet_6.root md2d2_AnaMonoJet_6.root  

               
hadd  AnaMonoJet_7_0.root     zjets_AnaMonoJet_7.root  
hadd  AnaMonoJet_7_1.root     zjets_AnaMonoJet_7.root    qcd*_AnaMonoJet_7.root 
hadd  AnaMonoJet_7_2.root     zjets_AnaMonoJet_7.root    qcd*_AnaMonoJet_7.root ttbar_AnaMonoJet_7.root 
hadd  AnaMonoJet_7_3.root     zjets_AnaMonoJet_7.root    qcd*_AnaMonoJet_7.root ttbar_AnaMonoJet_7.root  wjets_AnaMonoJet_7.root 
hadd  AnaMonoJet_7_4.root     zjets_AnaMonoJet_7.root    qcd*_AnaMonoJet_7.root ttbar_AnaMonoJet_7.root  wjets_AnaMonoJet_7.root  znunu*_AnaMonoJet_7.root   
hadd  AnaMonoJet_7_5.root     zjets_AnaMonoJet_7.root    qcd*_AnaMonoJet_7.root ttbar_AnaMonoJet_7.root  wjets_AnaMonoJet_7.root  znunu*_AnaMonoJet_7.root md2d2_AnaMonoJet_7.root  

               
hadd  AnaMonoJet_8_0.root     zjets_AnaMonoJet_8.root  
hadd  AnaMonoJet_8_1.root     zjets_AnaMonoJet_8.root    qcd*_AnaMonoJet_8.root 
hadd  AnaMonoJet_8_2.root     zjets_AnaMonoJet_8.root    qcd*_AnaMonoJet_8.root ttbar_AnaMonoJet_8.root 
hadd  AnaMonoJet_8_3.root     zjets_AnaMonoJet_8.root    qcd*_AnaMonoJet_8.root ttbar_AnaMonoJet_8.root  wjets_AnaMonoJet_8.root 
hadd  AnaMonoJet_8_4.root     zjets_AnaMonoJet_8.root    qcd*_AnaMonoJet_8.root ttbar_AnaMonoJet_8.root  wjets_AnaMonoJet_8.root  znunu*_AnaMonoJet_8.root  
hadd  AnaMonoJet_8_5.root     zjets_AnaMonoJet_8.root    qcd*_AnaMonoJet_8.root ttbar_AnaMonoJet_8.root  wjets_AnaMonoJet_8.root  znunu*_AnaMonoJet_8.root md2d2_AnaMonoJet_8.root 

               
hadd  AnaMonoJet_9_0.root     zjets_AnaMonoJet_9.root  
hadd  AnaMonoJet_9_1.root     zjets_AnaMonoJet_9.root    qcd*_AnaMonoJet_9.root 
hadd  AnaMonoJet_9_2.root     zjets_AnaMonoJet_9.root    qcd*_AnaMonoJet_9.root ttbar_AnaMonoJet_9.root 
hadd  AnaMonoJet_9_3.root     zjets_AnaMonoJet_9.root    qcd*_AnaMonoJet_9.root ttbar_AnaMonoJet_9.root  wjets_AnaMonoJet_9.root 
hadd  AnaMonoJet_9_4.root     zjets_AnaMonoJet_9.root    qcd*_AnaMonoJet_9.root ttbar_AnaMonoJet_9.root  wjets_AnaMonoJet_9.root  znunu*_AnaMonoJet_9.root  
hadd  AnaMonoJet_9_5.root     zjets_AnaMonoJet_9.root    qcd*_AnaMonoJet_9.root ttbar_AnaMonoJet_9.root  wjets_AnaMonoJet_9.root  znunu*_AnaMonoJet_9.root md2d2_AnaMonoJet_9.root 

  
               
hadd data_0.root   met_AnaMonoJet_0.root   metbtag_AnaMonoJet_0.root  
hadd data_1.root   met_AnaMonoJet_1.root   metbtag_AnaMonoJet_1.root  
hadd data_2.root   met_AnaMonoJet_2.root   metbtag_AnaMonoJet_2.root  
hadd data_3.root   met_AnaMonoJet_3.root   metbtag_AnaMonoJet_3.root  
hadd data_4.root   met_AnaMonoJet_4.root   metbtag_AnaMonoJet_4.root  
hadd data_5.root   met_AnaMonoJet_5.root   metbtag_AnaMonoJet_5.root  
hadd data_6.root   met_AnaMonoJet_6.root   metbtag_AnaMonoJet_6.root  
hadd data_7.root   met_AnaMonoJet_7.root   metbtag_AnaMonoJet_7.root  
hadd data_8.root   met_AnaMonoJet_8.root   metbtag_AnaMonoJet_8.root  
hadd data_9.root   met_AnaMonoJet_9.root   metbtag_AnaMonoJet_9.root  

rm -rf eps*
rm *.eps

mkdir  eps_MC_vs_DATA_0

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  Jet1Eta  "#eta(Jet_{1}) "                                      "Events / 0.02"         AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  Jet1Pt   "p_{T}(Jet_{1}) [GeV/c]"                              "Events / 25 GeV/c"   AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  Jet1Pt2   "p_{T}(Jet_{1}) [GeV/c]"                              "Events / 25 GeV/c"   AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  Jet2Eta  "#eta(Jet_{2}) "                                      "Events / 0.02"         AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  Jet2Pt   "p_{T}(Jet_{2}) [GeV/c]"                              "Events / 25 GeV/c"   AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  NJet   "Jet Multiplicity"                                      "Events"                AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  dPhi_MetLep_Jet1  "#Delta#phi(Jet_{1}, E^{miss}_{T})"                      "Events / 0.1"          AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  dPhi_MetLep_Jet2  "#Delta#phi(Jet_{2}, E^{miss}_{T})"                      "Events / 0.1"          AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet_{1}, Jet_{2})"                      "Events / 0.1"          AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  MetLep1   "E^{miss}_{T} [GeV] "                                       "Events / 25 GeV"   AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 
Merge  MetLepThrs1   "E^{miss}_{T} Threshold [GeV] "                         "Integrated Events / 25 GeV"   AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  MetLep2   "E^{miss}_{T} [GeV] "                                       "Events / 25 GeV"   AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 
Merge  MetLep3   "E^{miss}_{T} [GeV] "                                       "Events / 25 GeV"   AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 
Merge  MetLepThrs2   "E^{miss}_{T} Threshold [GeV] "                         "Integrated Events / 25 GeV"   AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  TIV   "Track Isolation Veto "                                 "Events / 0.005"        AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data"
Merge  MuonPt_2   "p_{T}(#mu) [GeV/c] "                                "Events / 4 GeV/c"    AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 
Merge  PFMuonPt   "p_{T}(#mu) [GeV/c] "                            "Events / 1 GeV/c"    AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 
Merge  PFElecPt   "p_{T}(e) [GeV/c] "                        "Events / 1 GeV/c"    AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 
Merge  NPV        "Number of Primary Vertex "                "Events "    AnaMonoJet_0_5 "ADD M_{D}2#delta2"  AnaMonoJet_0_4 "Z#rightarrow#nu#nu" AnaMonoJet_0_3 "W#rightarrowl#nu" AnaMonoJet_0_2 "t#bar{t}" AnaMonoJet_0_1 "QCD"  AnaMonoJet_0_0 "Z#rightarrowl^{+}l^{-}" data_0 "Data" 

mv  *.eps  eps_MC_vs_DATA_0
mv output.root   eps_MC_vs_DATA_0


mkdir  eps_MC_vs_DATA_2

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  Jet1Eta  "#eta(Jet_{1}) "                                      "Events / 0.02"         AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  Jet1Pt   "p_{T}(Jet_{1}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  Jet1Pt2   "p_{T}(Jet_{1}) [GeV/c]"                             "Events / 25 GeV/c"     AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  Jet2Eta  "#eta(Jet_{2}) "                                      "Events / 0.02"         AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  Jet2Pt   "p_{T}(Jet_{2}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  NJet   "Jet Multiplicity"                                      "Events"                AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  dPhi_MetLep_Jet1  "#Delta#phi(Jet_{1}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  dPhi_MetLep_Jet2  "#Delta#phi(Jet_{2}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet_{1}, Jet_{2})"                 "Events / 0.1"          AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  MetLep1   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data" 
Merge  MetLepThrs1   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  MetLep2   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data" 
Merge  MetLep3   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data" 
Merge  MetLepThrs2   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  TIV   "Track Isolation Veto "                                  "Events / 0.005"        AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data"
Merge  MuonPt_2   "p_{T}(#mu) [GeV/c] "                               "Events / 4 GeV/c"    AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data" 
Merge  PFMuonPt   "p_{T}(#mu) [GeV/c] "                               "Events / 1 GeV/c"    AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data" 
Merge  PFElecPt   "p_{T}(e) [GeV/c] "                                 "Events / 1 GeV/c"    AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data" 
Merge  NPV        "Number of Primary Vertex "                         "Events "    AnaMonoJet_2_5 "ADD M_{D}2#delta2"  AnaMonoJet_2_4 "Z#rightarrow#nu#nu" AnaMonoJet_2_3 "W#rightarrowl#nu" AnaMonoJet_2_2 "t#bar{t}" AnaMonoJet_2_1 "QCD"  AnaMonoJet_2_0 "Z#rightarrowl^{+}l^{-}" data_2 "Data" 

mv  *.eps  eps_MC_vs_DATA_2
mv output.root   eps_MC_vs_DATA_2

mkdir  eps_MC_vs_DATA_3

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  Jet1Eta  "#eta(Jet_{1}) "                                      "Events / 0.02"         AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  Jet1Pt   "p_{T}(Jet_{1}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  Jet1Pt2   "p_{T}(Jet_{1}) [GeV/c]"                             "Events / 25 GeV/c"     AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  Jet2Eta  "#eta(Jet_{2}) "                                      "Events / 0.02"         AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  Jet2Pt   "p_{T}(Jet_{2}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  NJet   "Jet Multiplicity"                                      "Events"                AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  dPhi_MetLep_Jet1  "#Delta#phi(Jet_{1}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  dPhi_MetLep_Jet2  "#Delta#phi(Jet_{2}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet_{1}, Jet_{2})"                 "Events / 0.1"          AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  MetLep1   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data" 
Merge  MetLepThrs1   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  MetLep2   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data" 
Merge  MetLep3   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data" 
Merge  MetLepThrs2   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  TIV   "Track Isolation Veto "                                  "Events / 0.005"        AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data"
Merge  MuonPt_2   "p_{T}(#mu) [GeV/c] "                               "Events / 4 GeV/c"    AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data" 
Merge  PFMuonPt   "p_{T}(#mu) [GeV/c] "                               "Events / 1 GeV/c"    AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data" 
Merge  PFElecPt   "p_{T}(e) [GeV/c] "                                 "Events / 1 GeV/c"    AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data" 
Merge  NPV        "Number of Primary Vertex "                         "Events "    AnaMonoJet_3_5 "ADD M_{D}2#delta2"  AnaMonoJet_3_4 "Z#rightarrow#nu#nu" AnaMonoJet_3_3 "W#rightarrowl#nu" AnaMonoJet_3_2 "t#bar{t}" AnaMonoJet_3_1 "QCD"  AnaMonoJet_3_0 "Z#rightarrowl^{+}l^{-}" data_3 "Data" 

mv  *.eps  eps_MC_vs_DATA_3
mv output.root   eps_MC_vs_DATA_3


mkdir  eps_MC_vs_DATA_4

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  Jet1Eta  "#eta(Jet_{1}) "                                      "Events / 0.02"         AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  Jet1Pt   "p_{T}(Jet_{1}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  Jet1Pt2   "p_{T}(Jet_{1}) [GeV/c]"                             "Events / 25 GeV/c"     AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  Jet2Eta  "#eta(Jet_{2}) "                                      "Events / 0.02"         AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  Jet2Pt   "p_{T}(Jet_{2}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  NJet   "Jet Multiplicity"                                      "Events"                AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  dPhi_MetLep_Jet1  "#Delta#phi(Jet_{1}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  dPhi_MetLep_Jet2  "#Delta#phi(Jet_{2}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet_{1}, Jet_{2})"                 "Events / 0.1"          AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  MetLep1   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data" 
Merge  MetLepThrs1   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  MetLep2   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data" 
Merge  MetLep3   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data" 
Merge  MetLepThrs2   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  TIV   "Track Isolation Veto "                                  "Events / 0.005"        AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data"
Merge  MuonPt_2   "p_{T}(#mu) [GeV/c] "                               "Events / 4 GeV/c"    AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data" 
Merge  PFMuonPt   "p_{T}(#mu) [GeV/c] "                               "Events / 1 GeV/c"    AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data" 
Merge  PFElecPt   "p_{T}(e) [GeV/c] "                                 "Events / 1 GeV/c"    AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data" 
Merge  NPV        "Number of Primary Vertex "                         "Events "    AnaMonoJet_4_5 "ADD M_{D}2#delta2"  AnaMonoJet_4_4 "Z#rightarrow#nu#nu" AnaMonoJet_4_3 "W#rightarrowl#nu" AnaMonoJet_4_2 "t#bar{t}" AnaMonoJet_4_1 "QCD"  AnaMonoJet_4_0 "Z#rightarrowl^{+}l^{-}" data_4 "Data" 

mv  *.eps  eps_MC_vs_DATA_4
mv output.root   eps_MC_vs_DATA_4



mkdir  eps_MC_vs_DATA_5

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  Jet1Eta  "#eta(Jet_{1}) "                                      "Events / 0.02"         AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  Jet1Pt   "p_{T}(Jet_{1}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  Jet1Pt2   "p_{T}(Jet_{1}) [GeV/c]"                             "Events / 25 GeV/c"     AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  Jet2Eta  "#eta(Jet_{2}) "                                      "Events / 0.02"         AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  Jet2Pt   "p_{T}(Jet_{2}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  NJet   "Jet Multiplicity"                                      "Events"                AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  dPhi_MetLep_Jet1  "#Delta#phi(Jet_{1}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  dPhi_MetLep_Jet2  "#Delta#phi(Jet_{2}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet_{1}, Jet_{2})"                 "Events / 0.1"          AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  MetLep1   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data" 
Merge  MetLepThrs1   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  MetLep2   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data" 
Merge  MetLep3   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data" 
Merge  MetLepThrs2   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  TIV   "Track Isolation Veto "                                  "Events / 0.005"        AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data"
Merge  MuonPt_2   "p_{T}(#mu) [GeV/c] "                               "Events / 4 GeV/c"    AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data" 
Merge  PFMuonPt   "p_{T}(#mu) [GeV/c] "                               "Events / 1 GeV/c"    AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data" 
Merge  PFElecPt   "p_{T}(e) [GeV/c] "                                 "Events / 1 GeV/c"    AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data" 
Merge  NPV        "Number of Primary Vertex "                         "Events "    AnaMonoJet_5_5 "ADD M_{D}2#delta2"  AnaMonoJet_5_4 "Z#rightarrow#nu#nu" AnaMonoJet_5_3 "W#rightarrowl#nu" AnaMonoJet_5_2 "t#bar{t}" AnaMonoJet_5_1 "QCD"  AnaMonoJet_5_0 "Z#rightarrowl^{+}l^{-}" data_5 "Data" 

mv  *.eps  eps_MC_vs_DATA_5
mv output.root   eps_MC_vs_DATA_5



mkdir  eps_MC_vs_DATA_6

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  Jet1Eta  "#eta(Jet_{1}) "                                      "Events / 0.02"         AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  Jet1Pt   "p_{T}(Jet_{1}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  Jet1Pt2   "p_{T}(Jet_{1}) [GeV/c]"                             "Events / 25 GeV/c"     AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  Jet2Eta  "#eta(Jet_{2}) "                                      "Events / 0.02"         AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  Jet2Pt   "p_{T}(Jet_{2}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  NJet   "Jet Multiplicity"                                      "Events"                AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  dPhi_MetLep_Jet1  "#Delta#phi(Jet_{1}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  dPhi_MetLep_Jet2  "#Delta#phi(Jet_{2}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet_{1}, Jet_{2})"                 "Events / 0.1"          AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  MetLep1   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data" 
Merge  MetLepThrs1   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  MetLep2   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data" 
Merge  MetLep3   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data" 
Merge  MetLepThrs2   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  TIV   "Track Isolation Veto "                                  "Events / 0.005"        AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data"
Merge  MuonPt_2   "p_{T}(#mu) [GeV/c] "                               "Events / 4 GeV/c"    AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data" 
Merge  PFMuonPt   "p_{T}(#mu) [GeV/c] "                               "Events / 1 GeV/c"    AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data" 
Merge  PFElecPt   "p_{T}(e) [GeV/c] "                                 "Events / 1 GeV/c"    AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data" 
Merge  NPV        "Number of Primary Vertex "                         "Events "    AnaMonoJet_6_5 "ADD M_{D}2#delta2"  AnaMonoJet_6_4 "Z#rightarrow#nu#nu" AnaMonoJet_6_3 "W#rightarrowl#nu" AnaMonoJet_6_2 "t#bar{t}" AnaMonoJet_6_1 "QCD"  AnaMonoJet_6_0 "Z#rightarrowl^{+}l^{-}" data_6 "Data" 

mv  *.eps  eps_MC_vs_DATA_6
mv output.root   eps_MC_vs_DATA_6



mkdir  eps_MC_vs_DATA_7

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  Jet1Eta  "#eta(Jet_{1}) "                                      "Events / 0.02"         AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  Jet1Pt   "p_{T}(Jet_{1}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  Jet1Pt2   "p_{T}(Jet_{1}) [GeV/c]"                             "Events / 25 GeV/c"     AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  Jet2Eta  "#eta(Jet_{2}) "                                      "Events / 0.02"         AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  Jet2Pt   "p_{T}(Jet_{2}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  NJet   "Jet Multiplicity"                                      "Events"                AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  dPhi_MetLep_Jet1  "#Delta#phi(Jet_{1}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  dPhi_MetLep_Jet2  "#Delta#phi(Jet_{2}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet_{1}, Jet_{2})"                 "Events / 0.1"          AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  MetLep1   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data" 
Merge  MetLepThrs1   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  MetLep2   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data" 
Merge  MetLep3   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data" 
Merge  MetLepThrs2   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  TIV   "Track Isolation Veto "                                  "Events / 0.005"        AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data"
Merge  MuonPt_2   "p_{T}(#mu) [GeV/c] "                               "Events / 4 GeV/c"    AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data" 
Merge  PFMuonPt   "p_{T}(#mu) [GeV/c] "                               "Events / 1 GeV/c"    AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data" 
Merge  PFElecPt   "p_{T}(e) [GeV/c] "                                 "Events / 1 GeV/c"    AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data" 
Merge  NPV        "Number of Primary Vertex "                         "Events "    AnaMonoJet_7_5 "ADD M_{D}2#delta2"  AnaMonoJet_7_4 "Z#rightarrow#nu#nu" AnaMonoJet_7_3 "W#rightarrowl#nu" AnaMonoJet_7_2 "t#bar{t}" AnaMonoJet_7_1 "QCD"  AnaMonoJet_7_0 "Z#rightarrowl^{+}l^{-}" data_7 "Data" 

mv  *.eps  eps_MC_vs_DATA_7
mv output.root   eps_MC_vs_DATA_7



mkdir  eps_MC_vs_DATA_8

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  Jet1Eta  "#eta(Jet_{1}) "                                      "Events / 0.02"         AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  Jet1Pt   "p_{T}(Jet_{1}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  Jet1Pt2   "p_{T}(Jet_{1}) [GeV/c]"                             "Events / 25 GeV/c"     AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  Jet2Eta  "#eta(Jet_{2}) "                                      "Events / 0.02"         AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  Jet2Pt   "p_{T}(Jet_{2}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  NJet   "Jet Multiplicity"                                      "Events"                AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  dPhi_MetLep_Jet1  "#Delta#phi(Jet_{1}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  dPhi_MetLep_Jet2  "#Delta#phi(Jet_{2}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet_{1}, Jet_{2})"                 "Events / 0.1"          AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  MetLep1   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data" 
Merge  MetLepThrs1   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  MetLep2   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data" 
Merge  MetLep3   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data" 
Merge  MetLepThrs2   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  TIV   "Track Isolation Veto "                                  "Events / 0.005"        AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data"
Merge  MuonPt_2   "p_{T}(#mu) [GeV/c] "                               "Events / 4 GeV/c"    AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data" 
Merge  PFMuonPt   "p_{T}(#mu) [GeV/c] "                               "Events / 1 GeV/c"    AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data" 
Merge  PFElecPt   "p_{T}(e) [GeV/c] "                                 "Events / 1 GeV/c"    AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data" 
Merge  NPV        "Number of Primary Vertex "                         "Events "    AnaMonoJet_8_5 "ADD M_{D}2#delta2"  AnaMonoJet_8_4 "Z#rightarrow#nu#nu" AnaMonoJet_8_3 "W#rightarrowl#nu" AnaMonoJet_8_2 "t#bar{t}" AnaMonoJet_8_1 "QCD"  AnaMonoJet_8_0 "Z#rightarrowl^{+}l^{-}" data_8 "Data" 

mv  *.eps  eps_MC_vs_DATA_8
mv output.root   eps_MC_vs_DATA_8



mkdir  eps_MC_vs_DATA_9

Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Events / 0.02"         AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Events / 0.02"         AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  Jet1Eta  "#eta(Jet_{1}) "                                      "Events / 0.02"         AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  Jet1Pt   "p_{T}(Jet_{1}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  Jet1Pt2   "p_{T}(Jet_{1}) [GeV/c]"                             "Events / 25 GeV/c"     AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  Jet2Eta  "#eta(Jet_{2}) "                                      "Events / 0.02"         AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  Jet2Pt   "p_{T}(Jet_{2}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  NJet   "Jet Multiplicity"                                      "Events"                AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  dPhi_MetLep_Jet1  "#Delta#phi(Jet_{1}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  dPhi_MetLep_Jet2  "#Delta#phi(Jet_{2}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet_{1}, Jet_{2})"                 "Events / 0.1"          AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  MetLep1   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data" 
Merge  MetLepThrs1   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  MetLep2   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data" 
Merge  MetLep3   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data" 
Merge  MetLepThrs2   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  TIV   "Track Isolation Veto "                                  "Events / 0.005"        AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data"
Merge  MuonPt_2   "p_{T}(#mu) [GeV/c] "                               "Events / 4 GeV/c"    AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data" 
Merge  PFMuonPt   "p_{T}(#mu) [GeV/c] "                               "Events / 1 GeV/c"    AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data" 
Merge  PFElecPt   "p_{T}(e) [GeV/c] "                                 "Events / 1 GeV/c"    AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data" 
Merge  NPV        "Number of Primary Vertex "                         "Events "    AnaMonoJet_9_5 "ADD M_{D}2#delta2"  AnaMonoJet_9_4 "Z#rightarrow#nu#nu" AnaMonoJet_9_3 "W#rightarrowl#nu" AnaMonoJet_9_2 "t#bar{t}" AnaMonoJet_9_1 "QCD"  AnaMonoJet_9_0 "Z#rightarrowl^{+}l^{-}" data_9 "Data" 

mv  *.eps  eps_MC_vs_DATA_9
mv output.root   eps_MC_vs_DATA_9





kcp  -s "Monojet Analysis MC vs Data" -b "All Cuts was applied"  *.eps lqfai@kbook.fnal.gov:1443


