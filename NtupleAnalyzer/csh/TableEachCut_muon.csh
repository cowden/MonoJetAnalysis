
rm data_table_*
rm qcd_table_*
rm singlet_table_*
rm znunu_table_*

hadd  qcd_table_0.root  qcd*_0.root
hadd  qcd_table_1.root  qcd*_1.root
hadd  qcd_table_2.root  qcd*_2.root
hadd  qcd_table_3.root  qcd*_3.root
hadd  qcd_table_4.root  qcd*_4.root
hadd  qcd_table_5.root  qcd*_5.root
hadd  qcd_table_6.root  qcd*_6.root
hadd  qcd_table_7.root  qcd*_7.root
hadd  qcd_table_8.root  qcd*_8.root
hadd  qcd_table_9.root  qcd*_9.root
hadd  qcd_table_10.root  qcd*_10.root

hadd  singlet_table_0.root  sint*_0.root 
hadd  singlet_table_1.root  sint*_1.root 
hadd  singlet_table_2.root  sint*_2.root 
hadd  singlet_table_3.root  sint*_3.root 
hadd  singlet_table_4.root  sint*_4.root 
hadd  singlet_table_5.root  sint*_5.root 
hadd  singlet_table_6.root  sint*_6.root 
hadd  singlet_table_7.root  sint*_7.root 
hadd  singlet_table_8.root  sint*_8.root 
hadd  singlet_table_9.root  sint*_9.root 
hadd  singlet_table_10.root sint*_10.root 

hadd  znunu_table_0.root  znunu*_0.root 
hadd  znunu_table_1.root  znunu*_1.root 
hadd  znunu_table_2.root  znunu*_2.root 
hadd  znunu_table_3.root  znunu*_3.root 
hadd  znunu_table_4.root  znunu*_4.root 
hadd  znunu_table_5.root  znunu*_5.root 
hadd  znunu_table_6.root  znunu*_6.root 
hadd  znunu_table_7.root  znunu*_7.root 
hadd  znunu_table_8.root  znunu*_8.root 
hadd  znunu_table_9.root  znunu*_9.root 
hadd  znunu_table_10.root znunu*_10.root 


hadd data_table_0.root   met*_AnaMuon_0.root  
hadd data_table_1.root   met*_AnaMuon_1.root  
hadd data_table_2.root   met*_AnaMuon_2.root  
hadd data_table_3.root   met*_AnaMuon_3.root  
hadd data_table_4.root   met*_AnaMuon_4.root  
hadd data_table_5.root   met*_AnaMuon_5.root  
hadd data_table_6.root   met*_AnaMuon_6.root  
hadd data_table_7.root   met*_AnaMuon_7.root  
hadd data_table_8.root   met*_AnaMuon_8.root  
hadd data_table_9.root   met*_AnaMuon_9.root  
hadd data_table_10.root  met*_AnaMuon_10.root 



echo "|   *Selection*       |  *WJets*  |  *Zinv*  |  *ZJets*  |  *TTbar*  | *SingleT* | *QCD*  |  *Total Bckg*  |  *Data*  |"


echo -n "|Pre Selection        "
Table MetLep1 2  wjets_AnaMuon_0  znunu_table_0  zjets_AnaMuon_0  ttbar_AnaMuon_0  singlet_table_0  qcd_table_0    data_table_0  
echo "  "
echo -n "|PFMet+mu >200 GeV    "
Table MetLep1 2  wjets_AnaMuon_1  znunu_table_1  zjets_AnaMuon_1  ttbar_AnaMuon_1  singlet_table_1  qcd_table_1    data_table_1 
echo "  "
echo -n "|Noise Clean          " 
Table MetLep1 2  wjets_AnaMuon_2  znunu_table_2  zjets_AnaMuon_2  ttbar_AnaMuon_2  singlet_table_2  qcd_table_2    data_table_2 
echo "  "
echo -n "|Leading Jet Cut      " 
Table MetLep1 2  wjets_AnaMuon_3  znunu_table_3  zjets_AnaMuon_3  ttbar_AnaMuon_3  singlet_table_3  qcd_table_3    data_table_3 
echo "  "
echo -n "|NJet Cut             "
Table MetLep1 2  wjets_AnaMuon_4  znunu_table_4  zjets_AnaMuon_4  ttbar_AnaMuon_4  singlet_table_4  qcd_table_4    data_table_4 
echo "  "
echo -n "|DPhi(jet1, jet2)<2.5 "
Table MetLep1 2  wjets_AnaMuon_5  znunu_table_5  zjets_AnaMuon_5  ttbar_AnaMuon_5  singlet_table_5  qcd_table_5    data_table_5 
echo "  "
echo -n "|Muon Isolation       "
Table MetLep1 2  wjets_AnaMuon_6  znunu_table_6  zjets_AnaMuon_6  ttbar_AnaMuon_6  singlet_table_6  qcd_table_6    data_table_6 
echo "  "
echo -n "|PFMet+mu >250 GeV    "
Table MetLep1 2  wjets_AnaMuon_7  znunu_table_7  zjets_AnaMuon_7  ttbar_AnaMuon_7  singlet_table_7  qcd_table_7    data_table_7 
echo "  "
echo -n "|PFMet+mu >300 GeV    "
Table MetLep1 2  wjets_AnaMuon_8  znunu_table_8  zjets_AnaMuon_8  ttbar_AnaMuon_8  singlet_table_8  qcd_table_8    data_table_8 
echo "  "
echo -n "|PFMet+mu >350 GeV    "
Table MetLep1 2  wjets_AnaMuon_9  znunu_table_9  zjets_AnaMuon_9  ttbar_AnaMuon_9  singlet_table_9  qcd_table_9    data_table_9 
echo "  "
echo -n "|PFMet+mu >400 GeV    "
Table MetLep1 2  wjets_AnaMuon_10 znunu_table_10 zjets_AnaMuon_10 ttbar_AnaMuon_10 singlet_table_10 qcd_table_10   data_table_10




