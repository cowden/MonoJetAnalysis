
echo "|     **          |   **       |   *DATA* |    **       |      **    | *MD2D2*  |  **         | **         | *Backg*  |  **         |"
echo "|*Selection Cut*|*Before Cut*|*Rejected*|*Efficiency%*|*Before Cut*|*Rejected*|*Efficiency%*|*Before Cut*|*Rejected*|*Efficiency%*|"


echo "| PFMet+mu >150 GeV    " 
Table MetLep1 1  data_0 data_5 md2d3_AnaMonoJetCutEff_0 md2d3_AnaMonoJetCutEff_5 AnaMonoJetCutEff_0_4 AnaMonoJetCutEff_5_4 

echo "| Noise Clean          "
Table PFAK5JetNeuHadEngFrac 1  data_0 data_1 md2d3_AnaMonoJetCutEff_0 md2d3_AnaMonoJetCutEff_1  AnaMonoJetCutEff_0_4 AnaMonoJetCutEff_1_4 

echo "| Leading Jet Cut      "
Table Jet1Pt 1  data_0 data_2 md2d3_AnaMonoJetCutEff_0 md2d3_AnaMonoJetCutEff_2 AnaMonoJetCutEff_0_4 AnaMonoJetCutEff_2_4 

echo "| NJet Cut             "
Table NJet 1  data_0 data_3 md2d3_AnaMonoJetCutEff_0 md2d3_AnaMonoJetCutEff_3 AnaMonoJetCutEff_0_4 AnaMonoJetCutEff_3_4

echo "| DPhi(jet1, jet2)<2.5 "
Table dPhi_Jet1_Jet2 1  data_0 data_4 md2d3_AnaMonoJetCutEff_0 md2d3_AnaMonoJetCutEff_4 AnaMonoJetCutEff_0_4 AnaMonoJetCutEff_4_4 

echo "| Muon Isolation       "
Table MuonPt 1  data_0 data_8 md2d3_AnaMonoJetCutEff_0 md2d3_AnaMonoJetCutEff_8 AnaMonoJetCutEff_0_4 AnaMonoJetCutEff_8_4 

echo "| TIV>0.01             "
Table TIV 1  data_0 data_6 md2d3_AnaMonoJetCutEff_0 md2d3_AnaMonoJetCutEff_6 AnaMonoJetCutEff_0_4 AnaMonoJetCutEff_6_4  

echo "| PF e, mu pt<10 GeV   "
Table  PFElecPt 1 data_0 data_7 md2d3_AnaMonoJetCutEff_0 md2d3_AnaMonoJetCutEff_7 AnaMonoJetCutEff_0_4 AnaMonoJetCutEff_7_4 

