#!/bin/tcsh -f

foreach iCut(`seq 0 1 9`)
    rm *_muon*
    rm output.root 
    rm -rf plots/AnaMuonTau/eps_WZMass_${iCut}
    mkdir -p plots/AnaMuonTau/eps_WZMass_${iCut}

    hadd data_muon_${iCut}.root    Data_WZTauAnalysis_${iCut}.root
    hadd qcd_muon_${iCut}.root     SUMBGD_qcd_WZTauAnalysis_${iCut}.root
    hadd diboson_muon_${iCut}.root SUMBGD_diboson_WZTauAnalysis_${iCut}.root  qcd_muon_${iCut}.root
    hadd sint_muon_${iCut}.root    SUMBGD_sint_WZTauAnalysis_${iCut}.root     diboson_muon_${iCut}.root
    hadd ttbar_muon_${iCut}.root   SUMBGD_ttbar_WZTauAnalysis_${iCut}.root    sint_muon_${iCut}.root
    hadd zjets_muon_${iCut}.root   SUMBGD_zjets_WZTauAnalysis_${iCut}.root    ttbar_muon_${iCut}.root
    hadd wjets_muon_${iCut}.root   SUMBGD_wjets_WZTauAnalysis_${iCut}.root    zjets_muon_${iCut}.root

   
    Merge WlepnuMT "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2} " wjets_muon_${iCut} data_muon_${iCut} wjets_muon_${iCut} "W#rightarrowl#nu" zjets_muon_${iCut} "Z#rightarrowl^{+}l^{-}" ttbar_muon_${iCut} "t#bar{t}" sint_muon_${iCut} "t" diboson_muon_${iCut} "DiBoson" qcd_muon_${iCut} "QCD" data_muon_${iCut}  "Data"

    Merge WlepnuMT_50_100   "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_${iCut} data_muon_${iCut} wjets_muon_${iCut} "W#rightarrowl#nu" zjets_muon_${iCut} "Z#rightarrowl^{+}l^{-}" ttbar_muon_${iCut} "t#bar{t}" sint_muon_${iCut} "t" diboson_muon_${iCut} "DiBoson" qcd_muon_${iCut} "QCD" data_muon_${iCut}  "Data"

    #Merge WlepnuPT_50_100   "P_{T} [GeV/c^{2}]"  "Events / 25 GeV/c^{2}"  wjets_muon_${iCut} data_muon_${iCut} wjets_muon_${iCut} "W#rightarrowl#nu" zjets_muon_${iCut} "Z#rightarrowl^{+}l^{-}" ttbar_muon_${iCut} "t#bar{t}" sint_muon_${iCut} "t" qcd_muon_${iCut} "QCD" data_muon_${iCut}  "Data"

    Merge WlepnuPT2_50_100   "P_{T} [GeV/c^{2}]"  "Events / 25 GeV/c^{2}"  wjets_muon_${iCut} data_muon_${iCut} wjets_muon_${iCut} "W#rightarrowl#nu" zjets_muon_${iCut} "Z#rightarrowl^{+}l^{-}" ttbar_muon_${iCut} "t#bar{t}" sint_muon_${iCut} "t" diboson_muon_${iCut} "DiBoson" qcd_muon_${iCut} "QCD" data_muon_${iCut}  "Data"

    Merge ZleplepMT_60_120   "M_{#mu#mu} [GeV/c^{2}]"  "Events / 2 GeV/c^{2}"  zjets_muon_${iCut} data_muon_${iCut} zjets_muon_${iCut} "Z#rightarrowl^{+}l^{-}" ttbar_muon_${iCut} "t#bar{t}" sint_muon_${iCut} "t" diboson_muon_${iCut} "DiBoson" qcd_muon_${iCut} "QCD" data_muon_${iCut}  "Data"

    Merge ZleplepPT_60_120   "P_{T} Z_{#mu#mu} [GeV/c^{2}]"  "Events / 20 GeV/c^{2}"  zjets_muon_${iCut} data_muon_${iCut} zjets_muon_${iCut} "Z#rightarrowl^{+}l^{-}" ttbar_muon_${iCut} "t#bar{t}" sint_muon_${iCut} "t" diboson_muon_${iCut} "DiBoson" qcd_muon_${iCut} "QCD" data_muon_${iCut}  "Data"

    #Merge ZleplepMT          "M [GeV/c^{2}]"      "Events / 4 GeV/c^{2}"  zjets_muon_${iCut} "Z#rightarrowl^{+}l^{-}" ttbar_muon_${iCut} "t#bar{t}" qcd_muon_${iCut} "QCD" data_muon_${iCut}  "Data"
#Merge ZleplepMT_81_101   "M [GeV/c^{2}]"      "Events / 4 GeV/c^{2}"  zjets_muon_${iCut} "Z#rightarrowl^{+}l^{-}" ttbar_muon_${iCut} "t#bar{t}" qcd_muon_${iCut} "QCD" data_muon_${iCut}  "Data"

    #Merge WlepnuMT_${iCut}        "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_${iCut} "W#rightarrowl#nu" zjets_muon_${iCut} "Z#rightarrowl^{+}l^{-}" ttbar_muon_${iCut} "t#bar{t}" qcd_muon_${iCut} "QCD" data_muon_${iCut}  "Data"

    #Merge WlepnuMT_${iCut}10        "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_${iCut} "W#rightarrowl#nu" zjets_muon_${iCut} "Z#rightarrowl^{+}l^{-}" ttbar_muon_${iCut} "t#bar{t}" qcd_muon_${iCut} "QCD" data_muon_${iCut}  "Data"

    #Merge WlepnuMT_${iCut}10        "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_${iCut} "W#rightarrowl#nu" zjets_muon_${iCut} "Z#rightarrowl^{+}l^{-}" ttbar_muon_${iCut} "t#bar{t}" qcd_muon_${iCut} "QCD" data_muon_${iCut}  "Data"

    mv *.eps output.root plots/AnaMuonTau/eps_WZMass_${iCut}
    
    rm -rf *_muon_${iCut}.root
end
