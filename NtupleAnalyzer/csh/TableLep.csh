

rm znunu_*.root  
rm sint_*.root  
rm qcd_*.root  
rm data_*.root     
rm wjets_*.root 
rm mc_*.root

hadd  wjets_2.root wjets*_WZ*_2.root
hadd  wjets_3.root wjets*_WZ*_3.root
hadd  wjets_4.root wjets*_WZ*_4.root
hadd  wjets_5.root wjets*_WZ*_5.root
hadd  wjets_6.root wjets*_WZ*_6.root
hadd  wjets_7.root wjets*_WZ*_7.root
hadd  wjets_8.root wjets*_WZ*_8.root
hadd  wjets_9.root wjets*_WZ*_9.root

hadd  znunu_2.root  znunu*_WZAnalysis_2.root  
hadd  znunu_3.root  znunu*_WZAnalysis_3.root  
hadd  znunu_4.root  znunu*_WZAnalysis_4.root  
hadd  znunu_5.root  znunu*_WZAnalysis_5.root  
hadd  znunu_6.root  znunu*_WZAnalysis_6.root  
hadd  znunu_7.root  znunu*_WZAnalysis_7.root 
hadd  znunu_8.root  znunu*_WZAnalysis_8.root 
hadd  znunu_9.root  znunu*_WZAnalysis_9.root 


hadd  sint_2.root  sint*_WZ*_2.root
hadd  sint_3.root  sint*_WZ*_3.root
hadd  sint_4.root  sint*_WZ*_4.root
hadd  sint_5.root  sint*_WZ*_5.root
hadd  sint_6.root  sint*_WZ*_6.root
hadd  sint_7.root  sint*_WZ*_7.root
hadd  sint_8.root  sint*_WZ*_8.root
hadd  sint_9.root  sint*_WZ*_9.root



hadd qcd_2.root  qcd*_WZ*_2.root
hadd qcd_3.root  qcd*_WZ*_3.root 
hadd qcd_4.root  qcd*_WZ*_4.root 
hadd qcd_5.root  qcd*_WZ*_5.root 
hadd qcd_6.root  qcd*_WZ*_6.root 
hadd qcd_7.root  qcd*_WZ*_7.root
hadd qcd_8.root  qcd*_WZ*_8.root
hadd qcd_9.root  qcd*_WZ*_9.root


hadd  data_2.root met*_WZ*_2.root
hadd  data_3.root met*_WZ*_3.root 
hadd  data_4.root met*_WZ*_4.root 
hadd  data_5.root met*_WZ*_5.root 
hadd  data_6.root met*_WZ*_6.root 
hadd  data_7.root met*_WZ*_7.root 
hadd  data_8.root met*_WZ*_8.root 
hadd  data_9.root met*_WZ*_9.root 


hadd  mc_2.root    znunu*_WZAnalysis_2.root zjets_WZ*_2.root  ttbar_WZ*_2.root   sint*_WZ*_2.root  qcd*_WZ*_2.root  
hadd  mc_3.root    znunu*_WZAnalysis_3.root zjets_WZ*_3.root  ttbar_WZ*_3.root   sint*_WZ*_3.root  qcd*_WZ*_3.root 
hadd  mc_4.root    znunu*_WZAnalysis_4.root zjets_WZ*_4.root  ttbar_WZ*_4.root   sint*_WZ*_4.root  qcd*_WZ*_4.root 
hadd  mc_5.root    znunu*_WZAnalysis_5.root zjets_WZ*_5.root  ttbar_WZ*_5.root   sint*_WZ*_5.root  qcd*_WZ*_5.root 
hadd  mc_6.root    znunu*_WZAnalysis_6.root zjets_WZ*_6.root  ttbar_WZ*_6.root   sint*_WZ*_6.root  qcd*_WZ*_6.root 
hadd  mc_7.root    znunu*_WZAnalysis_7.root zjets_WZ*_7.root  ttbar_WZ*_7.root   sint*_WZ*_7.root  qcd*_WZ*_7.root 
hadd  mc_8.root    znunu*_WZAnalysis_8.root zjets_WZ*_8.root  ttbar_WZ*_8.root   sint*_WZ*_8.root  qcd*_WZ*_8.root 
hadd  mc_9.root    znunu*_WZAnalysis_9.root zjets_WZ*_9.root  ttbar_WZ*_9.root   sint*_WZ*_9.root  qcd*_WZ*_9.root 

rm mc1_*.root
hadd  mc1_2.root    znunu*_WZAnalysis_2.root wjets*_WZ*_2.root  ttbar_WZ*_2.root   sint*_WZ*_2.root  qcd*_WZ*_2.root  
hadd  mc1_3.root    znunu*_WZAnalysis_3.root wjets*_WZ*_3.root  ttbar_WZ*_3.root   sint*_WZ*_3.root  qcd*_WZ*_3.root 
hadd  mc1_4.root    znunu*_WZAnalysis_4.root wjets*_WZ*_4.root  ttbar_WZ*_4.root   sint*_WZ*_4.root  qcd*_WZ*_4.root 
hadd  mc1_5.root    znunu*_WZAnalysis_5.root wjets*_WZ*_5.root  ttbar_WZ*_5.root   sint*_WZ*_5.root  qcd*_WZ*_5.root 
hadd  mc1_6.root    znunu*_WZAnalysis_6.root wjets*_WZ*_6.root  ttbar_WZ*_6.root   sint*_WZ*_6.root  qcd*_WZ*_6.root 
hadd  mc1_7.root    znunu*_WZAnalysis_7.root wjets*_WZ*_7.root  ttbar_WZ*_7.root   sint*_WZ*_7.root  qcd*_WZ*_7.root 
hadd  mc1_8.root    znunu*_WZAnalysis_8.root wjets*_WZ*_8.root  ttbar_WZ*_8.root   sint*_WZ*_8.root  qcd*_WZ*_8.root 
hadd  mc1_9.root    znunu*_WZAnalysis_9.root wjets*_WZ*_9.root  ttbar_WZ*_9.root   sint*_WZ*_9.root  qcd*_WZ*_9.root 

echo "|   *Selection*       |  *WJets*  |  *ZJets*   |  *Zinv*  |  *TTbar*  |  *SingleT*  | *QCD*  |  *Total Bckg*  |  *Data* | "


TableLep 1 wjets_2 zjets_WZAnalysis_2 znunu_2  ttbar_WZAnalysis_2 sint_2 qcd_2 data_2
TableLep 1 wjets_3 zjets_WZAnalysis_3 znunu_3  ttbar_WZAnalysis_3 sint_3 qcd_3 data_3
TableLep 1 wjets_4 zjets_WZAnalysis_4 znunu_4  ttbar_WZAnalysis_4 sint_4 qcd_4 data_4
TableLep 1 wjets_5 zjets_WZAnalysis_5 znunu_5  ttbar_WZAnalysis_5 sint_5 qcd_5 data_5
TableLep 1 wjets_6 zjets_WZAnalysis_6 znunu_6  ttbar_WZAnalysis_6 sint_6 qcd_6 data_6
TableLep 1 wjets_7 zjets_WZAnalysis_7 znunu_7  ttbar_WZAnalysis_7 sint_7 qcd_7 data_7
TableLep 1 wjets_8 zjets_WZAnalysis_8 znunu_8  ttbar_WZAnalysis_8 sint_8 qcd_8 data_8
TableLep 1 wjets_9 zjets_WZAnalysis_9 znunu_9  ttbar_WZAnalysis_9 sint_9 qcd_9 data_9

echo -n "  "  
echo -n "  " 

TableLep 2  wjets_2  wjets_3  wjets_4  wjets_5 wjets_6  wjets_7  wjets_8  wjets_9

echo -n "  "  
echo -n "  " 

TableLep 3  wjets_2  wjets_3  wjets_4  wjets_5 wjets_6  wjets_7  wjets_8  wjets_9

echo -n "  "  
echo -n "  " 

