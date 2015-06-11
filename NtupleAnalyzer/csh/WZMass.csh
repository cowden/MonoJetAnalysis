#!/bin/tcsh -f

rm *_muon*
rm output.root

hadd data_muon_2.root met*_WZAnalysis_2.root 
hadd data_muon_1.root met*_WZAnalysis_1.root 

hadd qcd_muon_2.root    qcd*WZAnalysis_2*

hadd ttbar_muon_2.root  ttbar_WZAnalysis_2.root  qcd*WZAnalysis_2* 

hadd zjets_muon_2.root  zjets_WZAnalysis_2.root  ttbar_WZAnalysis_2.root  qcd*WZAnalysis_2*

hadd wjets_muon_2.root  wjets*_WZAnalysis_2.root  zjets_WZAnalysis_2.root  ttbar_WZAnalysis_2.root  qcd*WZAnalysis_2*


hadd qcd_muon_1.root    qcd*WZAnalysis_1*

hadd ttbar_muon_1.root  ttbar_WZAnalysis_1.root  qcd*WZAnalysis_1*

hadd zjets_muon_1.root  zjets_WZAnalysis_1.root  ttbar_WZAnalysis_1.root  qcd*WZAnalysis_1*

hadd wjets_muon_1.root  wjets*_WZAnalysis_1.root  zjets_WZAnalysis_1.root  ttbar_WZAnalysis_1.root  qcd*WZAnalysis_1*

hadd zinv_muon_1.root   znunu*_WZAnalysis_1.root  wjets*_WZAnalysis_1.root  zjets_WZAnalysis_1.root  ttbar_WZAnalysis_1.root  qcd*WZAnalysis_1*



Merge WlepnuMT          "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2} "  wjets_muon_2 "W#rightarrowl#nu" zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}" qcd_muon_2 "QCD"  data_muon_2  "Data"
Merge WlepnuMT_50_100   "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_2 "W#rightarrowl#nu" zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}" qcd_muon_2 "QCD"  data_muon_2  "Data"

Merge ZleplepMT          "M [GeV/c^{2}]"      "Events / 4 GeV/c^{2}"  zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}" qcd_muon_2 "QCD" data_muon_2  "Data"
Merge ZleplepMT_81_101   "M [GeV/c^{2}]"      "Events / 4 GeV/c^{2}"  zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}" qcd_muon_2 "QCD" data_muon_2  "Data"

Merge WlepnuMT_2        "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_2 "W#rightarrowl#nu" zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}" qcd_muon_2 "QCD" data_muon_2  "Data"

Merge WlepnuMT_210        "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_2 "W#rightarrowl#nu" zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}" qcd_muon_2 "QCD" data_muon_2  "Data"

Merge WlepnuMT_310        "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_2 "W#rightarrowl#nu" zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}" qcd_muon_2 "QCD" data_muon_2  "Data"



Merge WlepnuMT_50_100_2 "M_{T} [GeV/c^{2}]"  "Events / 10 GeV/c^{2}"  wjets_muon_2 "W#rightarrowl#nu" zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}" qcd_muon_2 "QCD" data_muon_2  "Data"

Merge ZleplepMT_2        "M [GeV/c^{2}]"      "Events / 4 GeV/c^{2}"  zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}" qcd_muon_2 "QCD" data_muon_2  "Data"
Merge ZleplepMT_81_101_2 "M [GeV/c^{2}]"      "Events / 4 GeV/c^{2}"  zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}" qcd_muon_2 "QCD" data_muon_2  "Data"

Merge ZleplepMT_60_120    "M [GeV/c^{2}]"      "Events / 2 GeV/c^{2}"  zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}"  data_muon_2  "Data"


Merge  ZleplepPT_60_120  "Z p_{T} [GeV/c]"  "Events / 20 GeV/c"  zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}"   data_muon_2  "Data"

Merge  ZleplepPT          "Z p_{T} [GeV/c]"  "Events / 20 GeV/c"  zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}"   data_muon_2  "Data"


Merge WlepnuPT_50_100    "W p_{T} [GeV/c]"  "Events / 25 GeV/c"  wjets_muon_2 "W#rightarrowl#nu" zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}"  data_muon_2  "Data"
Merge WlepnuPT           "W p_{T} [GeV/c]"  "Events / 20 GeV/c"  wjets_muon_2 "W#rightarrowl#nu" zjets_muon_2 "Z#rightarrowl^{+}l^{-}" ttbar_muon_2 "t#bar{t}"  data_muon_2  "Data"


 
Merge NofLep          "Muon Multiplicity"  "Events  "  zinv_muon_1 "Z#rightarrow#nu#nu" wjets_muon_1 "W#rightarrowl#nu" zjets_muon_1 "Z#rightarrowl^{+}l^{-}" ttbar_muon_1 "t#bar{t}" qcd_muon_1 "QCD" data_muon_1  "Data"
 

