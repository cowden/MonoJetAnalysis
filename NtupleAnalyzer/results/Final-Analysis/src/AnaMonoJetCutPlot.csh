#!/bin/tcsh -f

foreach iCut(`seq 8 1 15`) 
    rm  AnaMonoJet_${iCut}_*.root
    rm  data_${iCut}.root
    rm  output.root
    rm -rf ./plots/AnaMonoJet/eps_MC_vs_DATA_${iCut}/
    rm *.eps
         
    hadd  AnaMonoJet_${iCut}_0.root     SUMBGD_zjets_AnaMonoJet_${iCut}.root
    hadd  AnaMonoJet_${iCut}_1.root     SUMBGD_diboson_AnaMonoJet_${iCut}.root   AnaMonoJet_${iCut}_0.root
    hadd  AnaMonoJet_${iCut}_2.root     SUMBGD_qcd_AnaMonoJet_${iCut}.root       AnaMonoJet_${iCut}_1.root
    hadd  AnaMonoJet_${iCut}_3.root     SUMBGD_sint_AnaMonoJet_${iCut}.root      AnaMonoJet_${iCut}_2.root
    hadd  AnaMonoJet_${iCut}_4.root     SUMBGD_ttbar_AnaMonoJet_${iCut}.root     AnaMonoJet_${iCut}_3.root
    hadd  AnaMonoJet_${iCut}_5.root     SUMBGD_wjets_AnaMonoJet_${iCut}.root     AnaMonoJet_${iCut}_4.root
    hadd  AnaMonoJet_${iCut}_6.root     SUMBGD_znunu_AnaMonoJet_${iCut}.root     AnaMonoJet_${iCut}_5.root
    hadd  data_${iCut}.root             Data_AnaMonoJet_${iCut}.root 
    
    mkdir -p ./plots/AnaMonoJet/eps_MC_vs_DATA_${iCut}

    #Jet-1
    Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Events / 0.02"  AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Events / 0.02"  AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Events / 0.02"  AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Events / 0.02"   AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  Jet1Eta  "#eta(Jet_{1}) "                                      "Events / 0.02"   AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  Jet1Pt   "p_{T}(Jet_{1}) [GeV/c]"                              "Events / 25 GeV/c" AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  Jet1Pt2   "p_{T}(Jet_{1}) [GeV/c]"                             "Events / 25 GeV/c" AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"

    #Jet-2
    Merge  PFAK5JetChaHadEngFrac2  "PFJet_{2} Charged Hadron Energy Fraction"  "Events / 0.02"  AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  PFAK5JetNeuHadEngFrac2  "PFJet_{2} Neutral Hadron Energy Fraction"  "Events / 0.02"  AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  PFAK5JetChaEmEngFrac2  "PFJet_{2} Charged EM Energy Fraction"       "Events / 0.02"  AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  PFAK5JetNeuEmEngFrac2  "PFJet_{2} Neutral EM Energy Fraction"       "Events / 0.02"   AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  Jet2Eta  "#eta(Jet_{2}) "                                      "Events / 0.02"     AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  Jet2Pt   "p_{T}(Jet_{2}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"

    #Jet-3
    Merge  Jet3Eta  "#eta(Jet_{3}) "                                      "Events / 0.02"     AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  Jet3Pt   "p_{T}(Jet_{3}) [GeV/c]"                              "Events / 25 GeV/c"     AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"

    #NJets
    Merge  NJet   "Jet Multiplicity"                                      "Events"                AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    #Merge  NJetInclusive4   "Jet Multiplicity"                                      "Events"                AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    #Merge  NJetExclusive4   "Jet Multiplicity"                                      "Events"                AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data" 

    #dPhi
    Merge  dPhi_MetLep_Jet1  "#Delta#phi(Jet_{1}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  dPhi_MetLep_Jet2  "#Delta#phi(Jet_{2}, E^{miss}_{T})"          "Events / 0.1"          AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet_{1}, Jet_{2})"                 "Events / 0.1"          AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"


    #MET
    Merge  MetLep1   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data" 
    Merge  MetLepThrs1   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  MetLep2   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    Merge  MetLep3   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    #Merge  MetLep3   "E^{miss}_{T} [GeV] "                                "Events / 25 GeV"   AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "DiBoson"  AnaMonoJet_${iCut}_5 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_4 "W#rightarrowl#nu" AnaMonoJet_${iCut}_3 "t#bar{t}" AnaMonoJet_${iCut}_2 "t" AnaMonoJet_${iCut}_1 "QCD"  AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}"  d2md3_AnaMonoJet_${iCut} "ADD M_{D}= 2 TeV, #delta = 3" dmv1_AnaMonoJet_${iCut}  "DM #Lambda = 0.9 TeV, M_{#chi} = 1 GeV" unp_S0_dU1p7_LU2000_AnaMonoJet_${iCut} "UNP d_{U}=1.7, #Lambda_{U} = 2 TeV" data_${iCut} "Data"
    Merge  MetLepThrs2   "E^{miss}_{T} Threshold [GeV] "                  "Integrated Events / 25 GeV"   AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    
    #NPV
    Merge  NPV        "Number of Primary Vertex "                         "Events "    AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data" 

    #Lepton
    #Merge  MuonPt_2   "p_{T}(#mu) [GeV/c] "                               "Events / 4 GeV/c"    AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data" 
    #Merge  PFMuonPt   "p_{T}(#mu) [GeV/c] "                               "Events / 1 GeV/c"    AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data" 
    #Merge  PFElecPt   "p_{T}(e) [GeV/c] "                                 "Events / 1 GeV/c"    AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data" 
    
    #Tau/TIV
    #Merge  TIV   "Track Isolation Veto "                                  "Events / 0.005"        AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    #Merge  NPFTau        "Number of PFTau"                         "Events "    AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    #Merge  PFTauPt        "p_T(#tau) [GeV/c]"                      "Events / 1 GeV/c"    AnaMonoJet_${iCut}_6  data_${iCut} AnaMonoJet_${iCut}_6 "Z#rightarrow#nu#nu"  AnaMonoJet_${iCut}_5 "W#rightarrowl#nu" AnaMonoJet_${iCut}_4 "t#bar{t}" AnaMonoJet_${iCut}_3 "t" AnaMonoJet_${iCut}_2 "QCD" AnaMonoJet_${iCut}_1 "DiBoson" AnaMonoJet_${iCut}_0 "Z#rightarrowl^{+}l^{-}" data_${iCut} "Data"
    
    mv  *.eps        ./plots/AnaMonoJet/eps_MC_vs_DATA_${iCut}/
    mv output.root   ./plots/AnaMonoJet/eps_MC_vs_DATA_${iCut}/ 

    rm -rf AnaMonoJet_${iCut}_*.root
    rm -rf data_${iCut}.root
end
