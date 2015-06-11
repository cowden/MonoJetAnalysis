#!/bin/tcsh -f

rm *_muon*
rm output.root

hadd data_muon_3.root met_WZAnalysis_3.root metbtag_WZAnalysis_3.root 
hadd data_muon_2.root met_WZAnalysis_2.root metbtag_WZAnalysis_2.root 


hadd ttbar_muon_3.root  ttbar_WZAnalysis_3.root  

hadd zjets_muon_3.root  zjets_WZAnalysis_3.root  ttbar_WZAnalysis_3.root  

hadd wjets_muon_3.root  wjets_WZAnalysis_3.root  zjets_WZAnalysis_3.root  ttbar_WZAnalysis_3.root 



hadd ttbar_muon_2.root  ttbar_WZAnalysis_2.root  

hadd zjets_muon_2.root  zjets_WZAnalysis_2.root  ttbar_WZAnalysis_2.root  

hadd wjets_muon_2.root  wjets_WZAnalysis_2.root  zjets_WZAnalysis_2.root  ttbar_WZAnalysis_2.root  

hadd zinv_muon_2.root   zinv_WZAnalysis_2.root   wjets_WZAnalysis_2.root  zjets_WZAnalysis_2.root  ttbar_WZAnalysis_2.root 



Merge WmunuMT          "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2} "  wjets_muon_3 "W#rightarrowl#nu" zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}"  data_muon_3  "Data"
Merge WmunuMT_50_100   "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_3 "W#rightarrowl#nu" zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}"   data_muon_3  "Data"

Merge ZmumuMT          "M [GeV/c^{2}]"      "Events / 4 GeV/c^{2}"  zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}" data_muon_3  "Data"
Merge ZmumuMT_81_101   "M [GeV/c^{2}]"      "Events / 4 GeV/c^{2}"  zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}" data_muon_3  "Data"

Merge WmunuMT_2        "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_3 "W#rightarrowl#nu" zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}"  data_muon_3  "Data"

Merge WmunuMT_210        "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_3 "W#rightarrowl#nu" zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}" data_muon_3  "Data"

Merge WmunuMT_310        "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_3 "W#rightarrowl#nu" zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}" data_muon_3  "Data"



Merge WmunuMT_50_100_2 "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_3 "W#rightarrowl#nu" zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}"  data_muon_3  "Data"

Merge ZmumuMT_2        "M [GeV/c^{2}]"      "Events / 4 GeV/c^{2}"  zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}"  data_muon_3  "Data"
Merge ZmumuMT_81_101_2 "M [GeV/c^{2}]"      "Events / 4 GeV/c^{2}"  zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}"  data_muon_3  "Data"

Merge ZmumuMT_60_120    "M [GeV/c^{2}]"      "Events / 2 GeV/c^{2}"  zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}"  data_muon_3  "Data"


Merge  ZmumuPT_60_120  "Z p_{T} [GeV/c]"  "Events / 20 GeV/c"  zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}"   data_muon_3  "Data"

Merge  ZmumuPT          "Z p_{T} [GeV/c]"  "Events / 20 GeV/c"  zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}"   data_muon_3  "Data"


Merge WmunuPT_50_100    "W p_{T} [GeV/c]"  "Events / 20 GeV/c"  wjets_muon_3 "W#rightarrowl#nu" zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}"  data_muon_3  "Data"
Merge WmunuPT           "W p_{T} [GeV/c]"  "Events / 20 GeV/c"  wjets_muon_3 "W#rightarrowl#nu" zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}"  data_muon_3  "Data"


Merge DPhiMetMu        "#Delta#phi(Met,Mu)" "Events / "  wjets_muon_3 "W#rightarrowl#nu" zjets_muon_3 "Z#rightarrowl^{+}l^{-}" ttbar_muon_3 "t#bar{t}"   data_muon_3  "Data" 

 
Merge NofMuon          "Muon Multiplicity"  "Events  "  zinv_muon_2 "Z#rightarrow#nu#nu" wjets_muon_2 "W#rightarrowl#nu" zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}"  data_muon_2  "Data"
 

