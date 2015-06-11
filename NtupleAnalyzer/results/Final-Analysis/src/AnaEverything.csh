#!/bin/tcsh

foreach x (`seq 0 1 15`)
 rm -rf Data_AnaMonoJet_${x}.root
 rm -rf SUMBGD_wjets_AnaMonoJet_${x}.root
 rm -rf SUMBGD_zjets_AnaMonoJet_${x}.root
 rm -rf SUMBGD_znunu_AnaMonoJet_${x}.root
 rm -rf SUMBGD_diboson_AnaMonoJet_${x}.root
 rm -rf SUMBGD_ttbar_AnaMonoJet_${x}.root
 rm -rf SUMBGD_sint_AnaMonoJet_${x}.root
 rm -rf SUMBGD_qcd_AnaMonoJet_${x}.root
 hadd Data_AnaMonoJet_${x}.root            ../../AnaMonoJet/$1/met*_AnaMonoJet_${x}.root
 hadd SUMBGD_znunu_AnaMonoJet_${x}.root    ../../AnaMonoJet/$1/znunu*_AnaMonoJet_${x}.root
 hadd SUMBGD_wjets_AnaMonoJet_${x}.root    ../../AnaMonoJet/$1/w*_AnaMonoJet_${x}.root
 hadd SUMBGD_zjets_AnaMonoJet_${x}.root    ../../AnaMonoJet/$1/zjets_AnaMonoJet_${x}.root
 hadd SUMBGD_diboson_AnaMonoJet_${x}.root  ../../AnaMonoJet/$1/diboson*_AnaMonoJet_${x}.root
 hadd SUMBGD_ttbar_AnaMonoJet_${x}.root    ../../AnaMonoJet/$1/ttbar_AnaMonoJet_${x}.root
 hadd SUMBGD_sint_AnaMonoJet_${x}.root     ../../AnaMonoJet/$1/sint*_AnaMonoJet_${x}.root
 hadd SUMBGD_qcd_AnaMonoJet_${x}.root      ../../AnaMonoJet/$1/qcd*_AnaMonoJet_${x}.root
end

foreach x (`seq 1 1 5`)
 rm -rf Data_AnaMonoJetCutEff_${x}.root
 rm -rf SUMBGD_wjets_AnaMonoJetCutEff_${x}.root
 rm -rf SUMBGD_zjets_AnaMonoJetCutEff_${x}.root
 rm -rf SUMBGD_znunu_AnaMonoJetCutEff_${x}.root
 rm -rf SUMBGD_diboson_AnaMonoJetCutEff_${x}.root
 rm -rf SUMBGD_ttbar_AnaMonoJetCutEff_${x}.root
 rm -rf SUMBGD_sint_AnaMonoJetCutEff_${x}.root
 rm -rf SUMBGD_qcd_AnaMonoJetCutEff_${x}.root
 hadd Data_AnaMonoJetCutEff_${x}.root            ../../AnaMonoJetCutEff/$1/met*_AnaMonoJetCutEff_${x}.root
 hadd SUMBGD_znunu_AnaMonoJetCutEff_${x}.root    ../../AnaMonoJetCutEff/$1/znunu*_AnaMonoJetCutEff_${x}.root
 hadd SUMBGD_wjets_AnaMonoJetCutEff_${x}.root    ../../AnaMonoJetCutEff/$1/w*_AnaMonoJetCutEff_${x}.root
 hadd SUMBGD_zjets_AnaMonoJetCutEff_${x}.root    ../../AnaMonoJetCutEff/$1/zjets_AnaMonoJetCutEff_${x}.root
 hadd SUMBGD_diboson_AnaMonoJetCutEff_${x}.root  ../../AnaMonoJetCutEff/$1/diboson*_AnaMonoJetCutEff_${x}.root
 hadd SUMBGD_ttbar_AnaMonoJetCutEff_${x}.root    ../../AnaMonoJetCutEff/$1/ttbar_AnaMonoJetCutEff_${x}.root
 hadd SUMBGD_sint_AnaMonoJetCutEff_${x}.root     ../../AnaMonoJetCutEff/$1/sint*_AnaMonoJetCutEff_${x}.root
 hadd SUMBGD_qcd_AnaMonoJetCutEff_${x}.root      ../../AnaMonoJetCutEff/$1/qcd*_AnaMonoJetCutEff_${x}.root
end

foreach x (`seq 0 1 9`)
 rm -rf Data_WZTauAnalysis_${x}.root
 rm -rf SUMBGD_wjets_WZTauAnalysis_${x}.root
 rm -rf SUMBGD_zjets_WZTauAnalysis_${x}.root 
 rm -rf SUMBGD_znunu_WZTauAnalysis_${x}.root
 rm -rf SUMBGD_diboson_WZTauAnalysis_${x}.root
 rm -rf SUMBGD_ttbar_WZTauAnalysis_${x}.root
 rm -rf SUMBGD_sint_WZTauAnalysis_${x}.root
 rm -rf SUMBGD_qcd_WZTauAnalysis_${x}.root
 hadd Data_WZTauAnalysis_${x}.root            ../../AnaMuonTau/$1/met*_WZTauAnalysis_${x}.root
 hadd SUMBGD_wjets_WZTauAnalysis_${x}.root    ../../AnaMuonTau/$1/w*_WZTauAnalysis_${x}.root
 hadd SUMBGD_zjets_WZTauAnalysis_${x}.root    ../../AnaMuonTau/$1/zjets_WZTauAnalysis_${x}.root 
 hadd SUMBGD_znunu_WZTauAnalysis_${x}.root    ../../AnaMuonTau/$1/znunu*_WZTauAnalysis_${x}.root
 hadd SUMBGD_diboson_WZTauAnalysis_${x}.root  ../../AnaMuonTau/$1/diboson*_WZTauAnalysis_${x}.root
 hadd SUMBGD_ttbar_WZTauAnalysis_${x}.root    ../../AnaMuonTau/$1/ttbar_WZTauAnalysis_${x}.root
 hadd SUMBGD_sint_WZTauAnalysis_${x}.root     ../../AnaMuonTau/$1/sint*_WZTauAnalysis_${x}.root 
 hadd SUMBGD_qcd_WZTauAnalysis_${x}.root      ../../AnaMuonTau/$1/qcd*_WZTauAnalysis_${x}.root
end

foreach x (`seq 0 1 9`)
 rm -rf SUM_WZAnalysis_${x}.root
 hadd SUM_WZAnalysis_${x}.root ../../AnaMuon/$1/w*_WZAnalysis_${x}.root
end

foreach x (`seq 9 1 15`)
 rm -rf SUM_AnaHadronicTau_${x}.root
 hadd SUM_AnaHadronicTau_${x}.root ../../AnaTau/$1/w*_AnaTau_${x}.root
end

root.exe <<EOF
 .x Calculation.C
EOF
