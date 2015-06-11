#!/bin/tcsh -f

rm data.root  mc.root 


hadd data.root metbtag_AnaMuon_6.root  met_AnaMuon_6.root  
hadd mc.root  zjets_AnaMuon_6.root wjets_AnaMuon_6.root ttbar_AnaMuon_6.root zinv_AnaMuon_6.root  qcd*_AnaMuon_6.root


Table  NJet  5  data  
Table  NJet  5  mc 



