
setenv  mydir  /uscms_data/d2/vergili/june/CMSSW_4_2_5/src/MonoJetAnalysis/NtupleAnalyzer



ssh  cmslpc-sl5  "cd $mydir; cmsenv; nice nohup ./csh/cutorder/monojet.csh" &
ssh  cmslpc-sl5  "cd $mydir; cmsenv; nice nohup ./csh/cutorder/muon.csh" &

ssh  cmslpc-sl5  "cd $mydir; cmsenv;  nice nohup ./csh/cuteff/met_muon.csh" &
ssh  cmslpc-sl5  "cd $mydir; cmsenv;  nice nohup ./csh/cuteff/met_mono.csh" &


ssh  cmslpc-sl5  "cd $mydir; cmsenv; nice nohup ./csh/cuteff/metbtag_muon.csh" &
ssh  cmslpc-sl5  "cd $mydir; cmsenv; nice nohup ./csh/cuteff/metbtag_mono.csh" &

ssh  cmslpc-sl5  "cd $mydir; cmsenv;  nice nohup ./csh/cuteff/wjets_muon.csh" &
ssh  cmslpc-sl5  "cd $mydir; cmsenv;  nice nohup ./csh/cuteff/wjets_mono.csh" &

ssh  cmslpc-sl5  "cd $mydir; cmsenv;  nice nohup ./csh/cuteff/ttbar_muon.csh" &
ssh  cmslpc-sl5  "cd $mydir; cmsenv;  nice nohup ./csh/cuteff/ttbar_mono.csh" &

ssh  cmslpc-sl5  "cd $mydir; cmsenv;  nice nohup ./csh/cuteff/zinv_muon.csh" &
ssh  cmslpc-sl5  "cd $mydir; cmsenv;  nice nohup ./csh/cuteff/zinv_mono.csh" &


ssh  cmslpc-sl5  "cd $mydir; cmsenv;  nice nohup ./csh/cuteff/zjets_muon.csh" &
ssh  cmslpc-sl5  "cd $mydir; cmsenv;  nice nohup ./csh/cuteff/zjets_mono.csh" &

ssh  cmslpc-sl5  "cd $mydir; cmsenv;  nice nohup ./csh/cuteff/md2d2_mono.csh" &


