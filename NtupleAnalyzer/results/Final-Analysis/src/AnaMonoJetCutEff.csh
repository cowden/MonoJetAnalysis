#!/bin/tcsh -f

rm  -rf ./plots/AnaMonoJetCutEff/plot-summary
mkdir -p ./plots/AnaMonoJetCutEff/plot-summary
foreach x(`seq 1 1 5`)
    rm  -rf AnaMonoJetCutEff_${x}_*.root
    rm  -rf data_${x}.root
    rm  -rf output.root 
    rm  -rf *.eps
    
    hadd AnaMonoJetCutEff_${x}_0.root SUMBGD_zjets_AnaMonoJetCutEff_${x}.root
    hadd AnaMonoJetCutEff_${x}_1.root SUMBGD_diboson_AnaMonoJetCutEff_${x}.root AnaMonoJetCutEff_${x}_0.root
    hadd AnaMonoJetCutEff_${x}_2.root SUMBGD_qcd_AnaMonoJetCutEff_${x}.root     AnaMonoJetCutEff_${x}_1.root
    hadd AnaMonoJetCutEff_${x}_3.root SUMBGD_sint_AnaMonoJetCutEff_${x}.root    AnaMonoJetCutEff_${x}_2.root
    hadd AnaMonoJetCutEff_${x}_4.root SUMBGD_ttbar_AnaMonoJetCutEff_${x}.root   AnaMonoJetCutEff_${x}_3.root
    hadd AnaMonoJetCutEff_${x}_5.root SUMBGD_wjets_AnaMonoJetCutEff_${x}.root   AnaMonoJetCutEff_${x}_4.root
    hadd AnaMonoJetCutEff_${x}_6.root SUMBGD_znunu_AnaMonoJetCutEff_${x}.root   AnaMonoJetCutEff_${x}_5.root 
    hadd data_${x}.root               Data_AnaMonoJetCutEff_${x}.root

    if( $x == "1" ) then
	Merge  PFAK5JetChaHadEngFrac  "PFJet Charged Hadron Energy Fraction"  "Number of Events / 0.02"         AnaMonoJetCutEff_${x}_6 data_${x} AnaMonoJetCutEff_${x}_6   "Z#rightarrow#nu#nu" AnaMonoJetCutEff_${x}_5 "W#rightarrowl#nu" AnaMonoJetCutEff_${x}_4 "t#bar{t}" AnaMonoJetCutEff_${x}_3 "t"  AnaMonoJetCutEff_${x}_2 "QCD" AnaMonoJetCutEff_${x}_1 "DiBoson" AnaMonoJetCutEff_${x}_0 "Z#rightarrowl^{+}l^{-}" data_${x} "Data"
	Merge  PFAK5JetNeuHadEngFrac  "PFJet Neutral Hadron Energy Fraction"  "Number of Events / 0.02"         AnaMonoJetCutEff_${x}_6 data_${x} AnaMonoJetCutEff_${x}_6   "Z#rightarrow#nu#nu" AnaMonoJetCutEff_${x}_5 "W#rightarrowl#nu" AnaMonoJetCutEff_${x}_4 "t#bar{t}" AnaMonoJetCutEff_${x}_3 "t"  AnaMonoJetCutEff_${x}_2 "QCD" AnaMonoJetCutEff_${x}_1 "DiBoson" AnaMonoJetCutEff_${x}_0 "Z#rightarrowl^{+}l^{-}" data_${x} "Data"
	Merge  PFAK5JetChaEmEngFrac  "PFJet Charged EM Energy Fraction"       "Number of Events / 0.02"         AnaMonoJetCutEff_${x}_6 data_${x} AnaMonoJetCutEff_${x}_6   "Z#rightarrow#nu#nu" AnaMonoJetCutEff_${x}_5 "W#rightarrowl#nu" AnaMonoJetCutEff_${x}_4 "t#bar{t}" AnaMonoJetCutEff_${x}_3 "t"  AnaMonoJetCutEff_${x}_2 "QCD" AnaMonoJetCutEff_${x}_1 "DiBoson" AnaMonoJetCutEff_${x}_0 "Z#rightarrowl^{+}l^{-}" data_${x} "Data"
	Merge  PFAK5JetNeuEmEngFrac  "PFJet Neutral EM Energy Fraction"       "Number of Events / 0.02"         AnaMonoJetCutEff_${x}_6 data_${x} AnaMonoJetCutEff_${x}_6   "Z#rightarrow#nu#nu" AnaMonoJetCutEff_${x}_5 "W#rightarrowl#nu" AnaMonoJetCutEff_${x}_4 "t#bar{t}" AnaMonoJetCutEff_${x}_3 "t"  AnaMonoJetCutEff_${x}_2 "QCD" AnaMonoJetCutEff_${x}_1 "DiBoson" AnaMonoJetCutEff_${x}_0 "Z#rightarrowl^{+}l^{-}" data_${x} "Data"
    else if( $x == "2" ) then
	Merge  Jet1Eta  "Leading Jet #eta "                                   "Number of Events / 0.02"         AnaMonoJetCutEff_${x}_6 data_${x} AnaMonoJetCutEff_${x}_6   "Z#rightarrow#nu#nu" AnaMonoJetCutEff_${x}_5 "W#rightarrowl#nu" AnaMonoJetCutEff_${x}_4 "t#bar{t}" AnaMonoJetCutEff_${x}_3 "t"  AnaMonoJetCutEff_${x}_2 "QCD" AnaMonoJetCutEff_${x}_1 "DiBoson" AnaMonoJetCutEff_${x}_0 "Z#rightarrowl^{+}l^{-}" data_${x} "Data"
	Merge  Jet1Pt   "Leading Jet p_{T} [GeV/c]"                           "Number of Events / 25 [GeV/c]"   AnaMonoJetCutEff_${x}_6 data_${x} AnaMonoJetCutEff_${x}_6   "Z#rightarrow#nu#nu" AnaMonoJetCutEff_${x}_5 "W#rightarrowl#nu" AnaMonoJetCutEff_${x}_4 "t#bar{t}" AnaMonoJetCutEff_${x}_3 "t"  AnaMonoJetCutEff_${x}_2 "QCD" AnaMonoJetCutEff_${x}_1 "DiBoson" AnaMonoJetCutEff_${x}_0 "Z#rightarrowl^{+}l^{-}" data_${x} "Data"
    else if( $x == "3" ) then
	Merge  NJet   "Jet Multiplicity"                                      "Number of Events"                AnaMonoJetCutEff_${x}_6 data_${x} AnaMonoJetCutEff_${x}_6   "Z#rightarrow#nu#nu" AnaMonoJetCutEff_${x}_5 "W#rightarrowl#nu" AnaMonoJetCutEff_${x}_4 "t#bar{t}" AnaMonoJetCutEff_${x}_3 "t"  AnaMonoJetCutEff_${x}_2 "QCD" AnaMonoJetCutEff_${x}_1 "DiBoson" AnaMonoJetCutEff_${x}_0 "Z#rightarrowl^{+}l^{-}" data_${x} "Data"
    else if( $x == "4" ) then
	Merge  dPhi_Jet1_Jet2  "#Delta#phi(Jet1, Jet2)"                       "Number of Events / 0.1"          AnaMonoJetCutEff_${x}_6 data_${x} AnaMonoJetCutEff_${x}_6   "Z#rightarrow#nu#nu" AnaMonoJetCutEff_${x}_5 "W#rightarrowl#nu" AnaMonoJetCutEff_${x}_4 "t#bar{t}" AnaMonoJetCutEff_${x}_3 "t"  AnaMonoJetCutEff_${x}_2 "QCD" AnaMonoJetCutEff_${x}_1 "DiBoson" AnaMonoJetCutEff_${x}_0 "Z#rightarrowl^{+}l^{-}" data_${x} "Data"
    else if( $x == "5" ) then
	Merge  MetLep1   "MET [GeV/c] "                                        "Number of Events / 25 [GeV/c]"   AnaMonoJetCutEff_${x}_6 data_${x} AnaMonoJetCutEff_${x}_6   "Z#rightarrow#nu#nu" AnaMonoJetCutEff_${x}_5 "W#rightarrowl#nu" AnaMonoJetCutEff_${x}_4 "t#bar{t}" AnaMonoJetCutEff_${x}_3 "t"  AnaMonoJetCutEff_${x}_2 "QCD" AnaMonoJetCutEff_${x}_1 "DiBoson" AnaMonoJetCutEff_${x}_0 "Z#rightarrowl^{+}l^{-}" data_${x} "Data" 
	Merge  MetLepThrs1   "MET Threshold [GeV/c] "                          "Number of Events / 25 [GeV/c]"   AnaMonoJetCutEff_${x}_6 data_${x} AnaMonoJetCutEff_${x}_6   "Z#rightarrow#nu#nu" AnaMonoJetCutEff_${x}_5 "W#rightarrowl#nu" AnaMonoJetCutEff_${x}_4 "t#bar{t}" AnaMonoJetCutEff_${x}_3 "t"  AnaMonoJetCutEff_${x}_2 "QCD" AnaMonoJetCutEff_${x}_1 "DiBoson" AnaMonoJetCutEff_${x}_0 "Z#rightarrowl^{+}l^{-}" data_${x} "Data"
	Merge  MetLep2   "MET [GeV/c] "                                        "Number of Events / 10 [GeV/c]"   AnaMonoJetCutEff_${x}_6 data_${x} AnaMonoJetCutEff_${x}_6   "Z#rightarrow#nu#nu" AnaMonoJetCutEff_${x}_5 "W#rightarrowl#nu" AnaMonoJetCutEff_${x}_4 "t#bar{t}" AnaMonoJetCutEff_${x}_3 "t"  AnaMonoJetCutEff_${x}_2 "QCD" AnaMonoJetCutEff_${x}_1 "DiBoson" AnaMonoJetCutEff_${x}_0 "Z#rightarrowl^{+}l^{-}" data_${x} "Data" 
	Merge  MetLepThrs2   "MET Threshold [GeV/c] "                          "Number of Events / 10 [GeV/c]"   AnaMonoJetCutEff_${x}_6 data_${x} AnaMonoJetCutEff_${x}_6   "Z#rightarrow#nu#nu" AnaMonoJetCutEff_${x}_5 "W#rightarrowl#nu" AnaMonoJetCutEff_${x}_4 "t#bar{t}" AnaMonoJetCutEff_${x}_3 "t"  AnaMonoJetCutEff_${x}_2 "QCD" AnaMonoJetCutEff_${x}_1 "DiBoson" AnaMonoJetCutEff_${x}_0 "Z#rightarrowl^{+}l^{-}" data_${x} "Data"
    endif
    
    mv  *.eps output.root ./plots/AnaMonoJetCutEff/plot-summary
    rm -rf AnaMonoJetCutEff_${x}_*.root
    rm -rf data_${x}.root
end
