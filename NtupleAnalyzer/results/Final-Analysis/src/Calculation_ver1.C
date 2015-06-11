#include<iomanip>
#include<iostream>

void PrintEvent(double mmm, bool data=false){
  if(data==false){
    if(mmm>10)
      return printf("%8.0f",mmm);
    else
      return printf("%8.1f",mmm);
  }
  else{
    return printf("%8.0f",mmm);
  }
}

void PrintEvent2(double mmm, bool data=false){
  if(data==false){
    if(mmm>10)
      return printf("%.0f",mmm);
    else
      return printf("%.1f",mmm);
  }
  else{
    return printf("%.0f",mmm);
  }
}

void PrintEvent3(double mmm, bool data=false){
  return printf("%.3f",mmm);
}

void Calculation(){
  double mcreweight = 2.8;
  double dyMCReweight = 3.71;
  double zScaleFactor = 1.092;
  double wfactor    = 1;
  bool   isVaryMET  = false;
  int    jet2cut    = 30;
  //
  TFile *file;
  TFile *fwjets;
  TFile *fzjets;
  TFile *fznunu;
  TFile *fdiboson;
  TFile *fttbar;
  TFile *fsint;
  TFile *fqcd;
  TFile *fdata; 
  
  
  //----------------------------------------
  //AnaMonoJet: Cutflow
  cout<<"---++Monojet cutflow"<<endl;
  cout<<"---+++Description"<<endl;
  cout<<"   * Standard monojet"<<endl;
  if(isVaryMET==true)
    cout<<"   * Vary MET"<<endl;
  else{
    cout<<"   * Vary Jet1"<<endl;
    cout<<"   * Jet2 > "<<jet2cut<<" !GeV"<<endl;;
  }
  cout<<"---+++Cutflow"<<endl;
  cout<<"|  *Selection*  |  *WJets*  |  *ZJets*  |  *Znunu*  |  *DiBoson*  |  *TTbar*  |  *SingleT*  |  *QCD*  |  *Total MC*  |  *Data*  |"<<endl;
  for(Int_t i=0; i<16; i++){
    char file1[200], file2[200], file3[200], file4[200], file5[200], file6[200],file7[200],file8[200];
    sprintf(file1,"SUMBGD_wjets_AnaMonoJet_%d.root", i);
    sprintf(file2,"SUMBGD_zjets_AnaMonoJet_%d.root", i);
    sprintf(file3,"SUMBGD_znunu_AnaMonoJet_%d.root", i);
    sprintf(file4,"SUMBGD_diboson_AnaMonoJet_%d.root", i);
    sprintf(file5,"SUMBGD_ttbar_AnaMonoJet_%d.root", i);
    sprintf(file6,"SUMBGD_sint_AnaMonoJet_%d.root", i);
    sprintf(file7,"SUMBGD_qcd_AnaMonoJet_%d.root", i);
    sprintf(file8,"Data_AnaMonoJet_%d.root", i);
    fwjets   = new TFile(file1);
    fzjets   = new TFile(file2); 
    fznunu   = new TFile(file3);
    fdiboson = new TFile(file4);
    fttbar   = new TFile(file5);
    fsint    = new TFile(file6);
    fqcd     = new TFile(file7);
    fdata    = new TFile(file8);
    TH1D *h_wjets   = fwjets->Get("NPV");
    TH1D *h_zjets   = fzjets->Get("NPV");
    TH1D *h_znunu   = fznunu->Get("NPV");
    TH1D *h_diboson = fdiboson->Get("NPV");
    TH1D *h_ttbar   = fttbar->Get("NPV");
    TH1D *h_sint    = fsint->Get("NPV");
    TH1D *h_qcd     = fqcd->Get("NPV");
    TH1D *h_data    = fdata->Get("NPV");
    int overflowBin     = h_data->GetSize()-1;
    if(i==0) std::cout<<"| Pre-selection";
    if(i==1) std::cout<<"| PFMET+MU > 250 !GeV";
    if(i==2) std::cout<<"| Noise cleaning";
    if(i==3) std::cout<<"| Jet1(110 !GeV)";
    if(i==3 && isVaryMET==false) std::cout<<", Jet2("<<jet2cut<<" !GeV)";
    if(i==4) std::cout<<"| NJet<3";
    if(i==5) std::cout<<"| !DeltaPhi(j1,j2)<2.5";
    if(i==6) std::cout<<"| Muon veto";
    if(i==7) std::cout<<"| Electron veto";
    if(i==8) std::cout<<"| Tau veto";
    if(i>8){
      if(isVaryMET==true)
	std::cout<<"| PFMET+MU > "<<200+(i-8)*50<<" !GeV";
      else
	std::cout<<"| Jet1 > "<<200+(i-8)*50<<" !GeV";
    }
    
    std::cout<<"  | ";
    PrintEvent(h_wjets->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_zjets->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_znunu->Integral(0,overflowBin));
    std::cout<<" | ";
    PrintEvent(h_diboson->Integral(0,overflowBin));  
    std::cout<<" | ";
    PrintEvent(h_ttbar->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_sint->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_qcd->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_wjets->Integral(0,overflowBin)
	       + h_zjets->Integral(0,overflowBin)
	       + h_znunu->Integral(0,overflowBin)
	       + h_diboson->Integral(0,overflowBin)
	       + h_ttbar->Integral(0,overflowBin)
	       + h_sint->Integral(0,overflowBin)
	       + h_qcd->Integral(0,overflowBin));  
    std::cout<<" | ";
    PrintEvent(h_data->Integral(0,overflowBin),true);
    std::cout<<" |"<<std::endl;
  }
  
  
  //----------------------------------------
  //AnaMuonTau: ZJets
  cout<<endl;
  cout<<"---++Z Analysis"<<endl;
  cout<<"---+++Z(mu,mu) event yeilds"<<endl;
  cout<<"|  *Selection*  |  *WJets*  |  *ZJets*  |  *Znunu*  |  *DiBoson*  |  *TTbar*  |  *SingleT*  |  *QCD*  |  *Total MC*  |  *Data*  |"<<endl;
  Double_t ZMuMuData[7];
  Double_t ZMuMuMC[7];
  Double_t ZMuMuBGD[7];
  Double_t ZMuMuBGDSqrt[7];
  Double_t AllDiMu[7];
  Double_t AccDiMu[7];
  for(Int_t i=3; i<10; i++){
    char file1[200], file2[200], file3[200], file4[200], file5[200], file6[200],file7[200],file8[200];
    sprintf(file1,"SUMBGD_wjets_WZTauAnalysis_%d.root", i);
    sprintf(file2,"SUMBGD_zjets_WZTauAnalysis_%d.root", i);
    sprintf(file3,"SUMBGD_znunu_WZTauAnalysis_%d.root", i);
    sprintf(file4,"SUMBGD_diboson_WZTauAnalysis_%d.root", i);
    sprintf(file5,"SUMBGD_ttbar_WZTauAnalysis_%d.root", i);
    sprintf(file6,"SUMBGD_sint_WZTauAnalysis_%d.root", i);
    sprintf(file7,"SUMBGD_qcd_WZTauAnalysis_%d.root", i);
    sprintf(file8,"Data_WZTauAnalysis_%d.root", i);
    fwjets   = new TFile(file1);
    fzjets   = new TFile(file2); 
    fznunu   = new TFile(file3);
    fdiboson = new TFile(file4);
    fttbar   = new TFile(file5);
    fsint    = new TFile(file6);
    fqcd     = new TFile(file7);
    fdata    = new TFile(file8);
    TH1D *h_z_wjets   = fwjets->Get("ZleplepMT_60_120");
    TH1D *h_z_zjets   = fzjets->Get("ZleplepMT_60_120");
    TH1D *h_z_znunu   = fznunu->Get("ZleplepMT_60_120");
    TH1D *h_z_diboson = fdiboson->Get("ZleplepMT_60_120");
    TH1D *h_z_ttbar   = fttbar->Get("ZleplepMT_60_120");
    TH1D *h_z_sint    = fsint->Get("ZleplepMT_60_120");
    TH1D *h_z_qcd     = fqcd->Get("ZleplepMT_60_120");
    TH1D *h_z_data    = fdata->Get("ZleplepMT_60_120");
    int overflowBin     = h_z_data->GetSize()-1;
    //
    ZMuMuData[i-3] = h_z_data->Integral(0,overflowBin);
    ZMuMuMC[i-3]   = h_z_zjets->Integral(0,overflowBin);
    ZMuMuBGD[i-3]  = h_z_wjets->Integral(0,overflowBin)
      + h_z_diboson->Integral(0,overflowBin)
      + h_z_ttbar->Integral(0,overflowBin)
      + h_z_sint->Integral(0,overflowBin)
      + h_z_qcd->Integral(0,overflowBin); 
    ZMuMuBGDSqrt[i-3] = sqrt(pow(h_z_wjets->Integral(0,overflowBin),2)
			     + pow(h_z_diboson->Integral(0,overflowBin),2)
			     + pow(h_z_ttbar->Integral(0,overflowBin),2)
			     + pow(h_z_sint->Integral(0,overflowBin),2)
			     + pow(h_z_qcd->Integral(0,overflowBin),2));
    TH1D*  alldimu = (TH1D*) fzjets->Get("WZEstimation");
    TH1D*  accdimu = (TH1D*) fzjets->Get("WZEstimation");
    AllDiMu[i-3] = (alldimu->GetBinContent(2))/2;
    AccDiMu[i-3] = (accdimu->GetBinContent(4))/2;
    //
    if(isVaryMET==true)
      std::cout<<"| PFMET+MU > "<<200+(i-2)*50<<" !GeV";
    else
      std::cout<<"| Jet1 > "<<200+(i-8)*50<<" !GeV";
    std::cout<<"  | ";
    PrintEvent(h_z_wjets->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_z_zjets->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_z_znunu->Integral(0,overflowBin));
    std::cout<<" | ";
    PrintEvent(h_z_diboson->Integral(0,overflowBin));  
    std::cout<<" | ";
    PrintEvent(h_z_ttbar->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_z_sint->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_z_qcd->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_z_wjets->Integral(0,overflowBin)
	       + h_z_zjets->Integral(0,overflowBin)
	       + h_z_znunu->Integral(0,overflowBin)
	       + h_z_diboson->Integral(0,overflowBin)
	       + h_z_ttbar->Integral(0,overflowBin)
	       + h_z_sint->Integral(0,overflowBin)
	       + h_z_qcd->Integral(0,overflowBin));  
    std::cout<<" | ";
    PrintEvent(h_z_data->Integral(0,overflowBin),true);
    std::cout<<" |"<<std::endl;
  }

  Double_t ZNuNu[7];
  Double_t ZAcc[7];
  Double_t ZEff[7];
  Double_t ZMuMuStatErr[7];
  Double_t ZAccErr[7];
  Double_t ZEffErr[7];
  Double_t ZTotalErr[7];
  Double_t ZNuNuError[7];
  for(Int_t i=0; i<7; i++){
    ZAcc[i]  = AccDiMu[i]/AllDiMu[i];
    ZEff[i]  = (ZMuMuMC[i]/AccDiMu[i])/zScaleFactor;
    ZNuNu[i] = (ZMuMuData[i]-ZMuMuBGD[i])*(5.942/(ZAcc[i]*ZEff[i]));
    //
    ZMuMuStatErr[i] = sqrt(ZMuMuData[i]+ZMuMuBGD[i])/(ZMuMuData[i]-ZMuMuBGD[i]);
    ZAccErr[i]      = sqrt(pow(sqrt(ZAcc[i]*(1-ZAcc[i])/AllDiMu[i]),2)+pow(0.02*ZAcc[i],2))/ZAcc[i];
    ZEffErr[i]      = sqrt(pow(sqrt(ZEff[i]*(1-ZEff[i])/AllDiMu[i]),2)+pow(0.02*ZEff[i],2))/ZEff[i];
    ZTotalErr[i]    = sqrt(pow(ZMuMuStatErr[i],2)+pow(ZAccErr[i],2)+pow(ZEffErr[i],2)+2*ZAccErr[i]*ZEffErr[i]+pow(0.02,2));
    ZNuNuError[i]   = ZNuNu[i]*ZTotalErr[i];
  }
  cout<<endl;
  cout<<"---+++Z(nu,nu) prediction"<<endl;
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  cout<<"| Nobs | ";
  for(int i=0;i<7;i++){
    PrintEvent2(ZMuMuData[i]);
    cout<<" | ";
  }
  cout<<endl;
  //
  cout<<"| Nbgd | ";
  for(int i=0;i<7;i++){
    PrintEvent2(ZMuMuBGD[i]);
    cout<<" | ";
  }
  cout<<endl;
  //
  cout<<"| Acc | ";
  for(int i=0;i<7;i++){
    PrintEvent3(ZAcc[i]);
    cout<<" | ";
  }
  cout<<endl;
  //
  cout<<"| Eff | ";
  for(int i=0;i<7;i++){
    PrintEvent3(ZEff[i]);
    cout<<" | ";
  }
  cout<<endl;
  //
  cout<<"| Znunu | ";
  for(int i=0;i<7;i++){
    PrintEvent2(ZNuNu[i]);
    cout<<"+/-";
    PrintEvent2(ZNuNuError[i]);
    cout<<" | ";
  }
  cout<<endl;

  
  //----------------------------------------
  //AnaMuonTau: WJets
  cout<<endl;
  cout<<"---++W Analysis"<<endl;
  cout<<"---+++W(mu,nu) event yeilds"<<endl;
  cout<<"|  *Selection*  |  *WJets*  |  *ZJets*  |  *Znunu*  |  *DiBoson*  |  *TTbar*  |  *SingleT*  |  *QCD*  |  *Total MC*  |  *Data*  |"<<endl;
  for(Int_t i=3; i<10; i++){
    char file1[200], file2[200], file3[200], file4[200], file5[200], file6[200],file7[200],file8[200];
    sprintf(file1,"SUMBGD_wjets_WZTauAnalysis_%d.root", i);
    sprintf(file2,"SUMBGD_zjets_WZTauAnalysis_%d.root", i);
    sprintf(file3,"SUMBGD_znunu_WZTauAnalysis_%d.root", i);
    sprintf(file4,"SUMBGD_diboson_WZTauAnalysis_%d.root", i);
    sprintf(file5,"SUMBGD_ttbar_WZTauAnalysis_%d.root", i);
    sprintf(file6,"SUMBGD_sint_WZTauAnalysis_%d.root", i);
    sprintf(file7,"SUMBGD_qcd_WZTauAnalysis_%d.root", i);
    sprintf(file8,"Data_WZTauAnalysis_%d.root", i);
    fwjets   = new TFile(file1);
    fzjets   = new TFile(file2); 
    fznunu   = new TFile(file3);
    fdiboson = new TFile(file4);
    fttbar   = new TFile(file5);
    fsint    = new TFile(file6);
    fqcd     = new TFile(file7);
    fdata    = new TFile(file8);
    TH1D *h_w_wjets   = fwjets->Get("WlepnuMT_50_100");
    TH1D *h_w_zjets   = fzjets->Get("WlepnuMT_50_100");
    TH1D *h_w_znunu   = fznunu->Get("WlepnuMT_50_100");
    TH1D *h_w_diboson = fdiboson->Get("WlepnuMT_50_100");
    TH1D *h_w_ttbar   = fttbar->Get("WlepnuMT_50_100");
    TH1D *h_w_sint    = fsint->Get("WlepnuMT_50_100");
    TH1D *h_w_qcd     = fqcd->Get("WlepnuMT_50_100");
    TH1D *h_w_data    = fdata->Get("WlepnuMT_50_100");
    int overflowBin     = h_w_data->GetSize()-1;
    if(isVaryMET==true)
      std::cout<<"| PFMET+MU > "<<200+(i-2)*50<<" !GeV";
    else
      std::cout<<"| Jet1 > "<<200+(i-8)*50<<" !GeV";
    std::cout<<"  | ";
    PrintEvent(h_w_wjets->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_w_zjets->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_w_znunu->Integral(0,overflowBin));
    std::cout<<" | ";
    PrintEvent(h_w_diboson->Integral(0,overflowBin));  
    std::cout<<" | ";
    PrintEvent(h_w_ttbar->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_w_sint->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_w_qcd->Integral(0,overflowBin)); 
    std::cout<<" | ";
    PrintEvent(h_w_wjets->Integral(0,overflowBin)
	       + h_w_zjets->Integral(0,overflowBin)
	       + h_w_znunu->Integral(0,overflowBin)
	       + h_w_diboson->Integral(0,overflowBin)
	       + h_w_ttbar->Integral(0,overflowBin)
	       + h_w_sint->Integral(0,overflowBin)
	       + h_w_qcd->Integral(0,overflowBin));  
    std::cout<<" | ";
    PrintEvent(h_w_data->Integral(0,overflowBin),true);
    std::cout<<" |"<<std::endl;
  }
  
  //AnaMuon: Generator ratio
  cout<<endl;
  cout<<"---+++Generator ratio (W+Jets) AnaMuon"<<endl;
  Double_t GenMuon[7];
  Double_t GenElec[7];
  Double_t GenHadT[7];
  for(Int_t i=3; i<10; i++){
    char file1[200];
    sprintf(file1,"SUM_WZAnalysis_%d.root", i);
    fwjets   = new TFile(file1);
    TH1D *h_ratio_wjets   = fwjets->Get("WZEstimation");
    GenMuon[i-3] = h_ratio_wjets->GetBinContent(2)+h_ratio_wjets->GetBinContent(14);
    GenElec[i-3] = h_ratio_wjets->GetBinContent(7)+h_ratio_wjets->GetBinContent(13);
    GenHadT[i-3] = h_ratio_wjets->GetBinContent(12)-h_ratio_wjets->GetBinContent(13)-h_ratio_wjets->GetBinContent(14);
  }
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  cout<<"| All gen muon | ";
  for(int i=0;i<7;i++){
    PrintEvent(GenMuon[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| All gen had. tau | ";
  for(int i=0;i<7;i++){
    PrintEvent(GenHadT[i]);
    cout<<" | ";
  }  
  cout<<endl;
  cout<<"| Ratio | ";
  for(int i=0;i<7;i++){
    PrintEvent3(GenHadT[i]/GenMuon[i]);
    cout<<" | ";
  }
  cout<<endl;

  cout<<endl;
  cout<<"---+++Generator ratio (W+Jets) AnaMuonTau"<<endl;
  Double_t GenMuon2[7];
  Double_t GenElec2[7];
  for(Int_t i=3; i<10; i++){
    char file1[200];
    sprintf(file1,"SUMBGD_wjets_WZTauAnalysis_%d.root", i);
    fwjets   = new TFile(file1);
    TH1D *h2_ratio_wjets   = fwjets->Get("WZEstimation");
    GenMuon2[i-3] = h2_ratio_wjets->GetBinContent(2)+h2_ratio_wjets->GetBinContent(14);
    GenElec2[i-3] = h2_ratio_wjets->GetBinContent(7)+h2_ratio_wjets->GetBinContent(13);
  }
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  cout<<"| All gen muon | ";
  for(int i=0;i<7;i++){
    PrintEvent(GenMuon2[i]);
    cout<<" | ";
  }
  cout<<endl; 
  cout<<"| All gen electron | ";
  for(int i=0;i<7;i++){
    PrintEvent(GenElec2[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Ratio | ";
  for(int i=0;i<7;i++){
    PrintEvent3(GenElec2[i]/GenMuon2[i]);
    cout<<" | ";
  }
  
  //Lost muon 
  Double_t muon[7][4];
  TH1F *MuErr1_total = new TH1F("MuErr1_total","",7,0,7);
  TH1F *MuErr1_pass  = new TH1F("MuErr1_pass","",7,0,7); 
  TH1F *MuErr2_total = new TH1F("MuErr2_total","",7,0,7);
  TH1F *MuErr2_pass  = new TH1F("MuErr2_pass","",7,0,7);
  for(Int_t i=3; i<10; i++){ 
    char file1[200];
    sprintf(file1,"SUMBGD_wjets_WZTauAnalysis_%d.root", i);  
    file  = new TFile(file1);
    //
    TH1D *muonHist2 = file->Get("WZEstimation");
    TH1D *muonHist3 = file->Get("WlepnuMT_50_100");
    Double_t total  = mcreweight * (muonHist2->GetBinContent(2)+muonHist2->GetBinContent(14));
    Double_t pass   = mcreweight * muonHist3->Integral();
    MuErr1_total->SetBinContent(i-2,total);
    MuErr1_pass->SetBinContent(i-2,pass);
    
    // APrimeMu x EPrimeMu
    muon[i-3][0]    = 0.955*pass/total; 
    
    // Error: APrimeMu x EPrimeMu
    muon[i-3][2]    = sqrt(muon[i-3][0]*(1-muon[i-3][0])/(total));
    //muon[i-3][2]    = sqrt(pow(sqrt(muon[i-3][0]*(1-muon[i-3][0])/(total)),2)+pow(0.02*muon[i-3][0],2))/muon[i-3][0];
    //muon[i-3][2]    = sqrt(muon[i-3][0]*(1-muon[i-3][0])/total)/muon[i-3][0];
    
    //
    Double_t total2 = mcreweight * (muonHist2->GetBinContent(2)+muonHist2->GetBinContent(14));
    Double_t pass2  = mcreweight * (muonHist2->GetBinContent(5)+muonHist2->GetBinContent(18)); 
    MuErr2_total->SetBinContent(i-2,total2);
    MuErr2_pass->SetBinContent(i-2,pass2);
    
    // AMu x EMu
    muon[i-3][1]    = pass2/total2; 
    
    //Error AMu x EMu   
    muon[i-3][3]    = sqrt(muon[i-3][1]*(1-muon[i-3][1])/(total2)); 
    //muon[i-3][3]    = sqrt(muon[i-3][1]*(1-muon[i-3][1])/total2)/muon[i-3][1];
  }
  TEfficiency *muonEff1 = new TEfficiency(*MuErr1_pass,*MuErr1_total); 
  TEfficiency *muonEff2 = new TEfficiency(*MuErr2_pass,*MuErr2_total);
  
  //Lost electron
  TH1F *EErr1_total = new TH1F("EErr1_total","",7,0,7);
  TH1F *EErr1_pass  = new TH1F("EErr1_pass","",7,0,7); 
  Double_t elec[7][4];
  Double_t elec2[7][2];
  for(Int_t i=3; i<10; i++){  
    char file1[200];
    sprintf(file1,"SUMBGD_wjets_WZTauAnalysis_%d.root", i);  
    file  = new TFile(file1);
    
    //Muon/Electron ratio
    TH1D *elecHist2 = file->Get("WZEstimation");
    Double_t total  = mcreweight * (elecHist2->GetBinContent(2)+elecHist2->GetBinContent(14));  
    Double_t pass   = mcreweight * (elecHist2->GetBinContent(7)+elecHist2->GetBinContent(13));
    elec[i-3][0]    = pass/total; //Muon/Electron ratio
    elec2[i-3][0]   = total;
    elec2[i-3][1]   = pass;

    //cout<<"DEBUG: "<<elec[i-3][0]<<" | "<<GenElec[i-3]/GenMuon[i-3]<<endl;
    
    Double_t total2 = mcreweight * (elecHist2->GetBinContent(7)+elecHist2->GetBinContent(13));
    Double_t pass2  = mcreweight * (elecHist2->GetBinContent(10)+elecHist2->GetBinContent(17));
    EErr1_total->SetBinContent(i-2,total2);
    EErr1_pass->SetBinContent(i-2,pass2);
    elec[i-3][1]    = pass2/total2; // AE x EE 
    elec[i-3][3]    = sqrt(elec[i-3][1]*(1-elec[i-3][1])/(total2));//Error AE x EE 
    
  }
  TEfficiency *elecEff1 = new TEfficiency(*EErr1_pass,*EErr1_total); 

  //Tau efficiency
  cout<<endl;
  Double_t str1[7][10]; 
  Double_t str2[7][2]; 
  TH1F *TErr1_total = new TH1F("TErr1_total","",7,0,7);
  TH1F *TErr1_pass  = new TH1F("TErr1_pass","",7,0,7);  
  TFile *ftauEff;
  Double_t ratio_ht_m = 0.;
  Double_t AHtau      = 0.;
  Double_t EHtau      = 0.;
  Double_t nht        = 0.;
  Double_t nm         = 0.;
  for(Int_t i=3; i<10; i++){
    char file1[200], file2[200], file3[200], file4[200], file5[200], file6[200],fileEff[200];
    sprintf(file1,"Data_WZTauAnalysis_%d.root", i);
    sprintf(file2,"SUMBGD_zjets_WZTauAnalysis_%d.root", i);
    sprintf(file3,"SUMBGD_ttbar_WZTauAnalysis_%d.root", i);
    sprintf(file4,"SUMBGD_sint_WZTauAnalysis_%d.root", i);
    sprintf(file5,"SUMBGD_diboson_WZTauAnalysis_%d.root", i);
    sprintf(file6,"SUMBGD_qcd_WZTauAnalysis_%d.root", i);
    sprintf(fileEff,"SUM_AnaHadronicTau_%d.root",i+6);
    fdata    = new TFile(file1);
    fzjets   = new TFile(file2);
    fttbar   = new TFile(file3);
    fsint    = new TFile(file4);
    fdiboson = new TFile(file5);
    fqcd     = new TFile(file6);
    ftauEff  = new TFile(fileEff);
    
    TH1D*  data  = (TH1D*) fdata->Get("WlepnuMT_50_100");
    TH1D*  bg1   = (TH1D*) fzjets->Get("WlepnuMT_50_100");
    TH1D*  bg2   = (TH1D*) fttbar->Get("WlepnuMT_50_100");
    TH1D*  bg3   = (TH1D*) fsint->Get("WlepnuMT_50_100");
    TH1D*  bg4   = (TH1D*) fdiboson->Get("WlepnuMT_50_100"); 
    TH1D*  bg5   = (TH1D*) fqcd->Get("WlepnuMT_50_100");
    
    Double_t nobs       = data->Integral();
    Double_t nbck       = bg1->Integral() + bg2->Integral() + bg3->Integral() + bg4->Integral() + bg5->Integral();
    Double_t nbck1      = sqrt(pow(0.5*bg1->Integral(),2)+pow(0.5*bg2->Integral(),2)+pow(0.5*bg3->Integral(),2)+pow(0.5*bg4->Integral(),2)+pow(0.5*bg5->Integral(),2));
     
    ratio_ht_m = GenHadT[i-3]/GenMuon[i-3];
    nm         = GenMuon[i-3];
    nht        = GenHadT[i-3];
    
    TH1D *All3 = ftauEff->Get("GenTauPt3_had");
    TH1D *AAA3 = ftauEff->Get("GenTauPt3_had_A");
    TH1D *AAe3 = ftauEff->Get("TauPt3_HPS");
    int overflowBin = ftauEff->GetSize()-1; 
    str1[i-3][0] = wfactor * nobs;
    str1[i-3][1] = nbck; 
    str1[i-3][2] = ratio_ht_m;
    str1[i-3][3] = AAA3->Integral(0,overflowBin)/All3->Integral(0,overflowBin);
    str1[i-3][4] = AAe3->Integral(0,overflowBin)/AAA3->Integral(0,overflowBin);

    if(i-3==0){
      cout<<endl;
      cout<<"---+++Tau Acceptance/Efficiency"<<endl;
      std::cout<<"|  *Cut*  |  *Acc*  |  *Eff*  |"<<std::endl;
    }
    if(isVaryMET==true)
      std::cout<<"| PFMET+MU > "<<200+(i-3)*50<<" !GeV | ";
    else
      std::cout<<"| Jet1 > "<<200+(i-3)*50<<" !GeV | ";
    PrintEvent3(str1[i-3][3]);
    cout<<" | ";
    PrintEvent3(str1[i-3][4]);
    cout<<" |"<<endl;;
    
    Double_t effHTau = str1[i-3][3]*str1[i-3][4]; // AHT x EHT 
    str1[i-3][5] = sqrt(effHTau*(1-effHTau)/(mcreweight * All3->Integral(0,overflowBin)));
    //cout<<"DEBUG: "<<effHTau<<" | "<<mcreweight * All3->Integral(0,overflowBin)<<" | "<<str1[i-3][5]<<endl;
    
    str2[i-3][0] = nm;
    str2[i-3][1] = nht;
    TErr1_total->SetBinContent(i-2,mcreweight * All3->Integral());
    TErr1_pass->SetBinContent(i-2,mcreweight * AAe3->Integral());
    
    //Nobs-error
    str1[i-3][6] = sqrt(nobs);
    str1[i-3][8] = str1[i-3][6]/(nobs-nbck);

    //Nbck-error
    str1[i-3][7] = nbck1;
    str1[i-3][9] = str1[i-3][7]/(nobs-nbck);
  }
  TEfficiency *tauEff1 = new TEfficiency(*TErr1_pass,*TErr1_total);
   
  cout<<endl; 
  cout<<"---+++Muon table"<<endl;
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  cout<<"| N_{obs} | "
      <<str1[0][0]/wfactor<<" | "
      <<str1[1][0]/wfactor<<" | "
      <<str1[2][0]/wfactor<<" | "
      <<str1[3][0]/wfactor<<" | "
      <<str1[4][0]/wfactor<<" | "
      <<str1[5][0]/wfactor<<" | "
      <<str1[6][0]/wfactor<<" | "<<endl;
  cout<<"| N_{bck} | " 
      <<(Int_t) (str1[0][1]+0.5)<<" | "
      <<(Int_t) (str1[1][1]+0.5)<<" | "
      <<(Int_t) (str1[2][1]+0.5)<<" | "
      <<(Int_t) (str1[3][1]+0.5)<<" | "
      <<(Int_t) (str1[4][1]+0.5)<<" | "
      <<(Int_t) (str1[5][1]+0.5)<<" | "
      <<(Int_t) (str1[6][1]+0.5)<<" | "<<endl;
  cout<<"| A'e'    | "<<setiosflags(ios::fixed | ios::showpoint | ios::right)<<setprecision(3)
      <<muon[0][0]<<" | "
      <<muon[1][0]<<" | "
      <<muon[2][0]<<" | "
      <<muon[3][0]<<" | "
      <<muon[4][0]<<" | "
      <<muon[5][0]<<" | "
      <<muon[6][0]<<" | "
      <<endl;
  cout<<"| Ntot,\mu| "
      <<(Int_t) ((str1[0][0]-str1[0][1])/(muon[0][0])+0.5)<<" | "
      <<(Int_t) ((str1[1][0]-str1[1][1])/(muon[1][0])+0.5)<<" | "
      <<(Int_t) ((str1[2][0]-str1[2][1])/(muon[2][0])+0.5)<<" | "
      <<(Int_t) ((str1[3][0]-str1[3][1])/(muon[3][0])+0.5)<<" | "
      <<(Int_t) ((str1[4][0]-str1[4][1])/(muon[4][0])+0.5)<<" | "
      <<(Int_t) ((str1[5][0]-str1[5][1])/(muon[5][0])+0.5)<<" | "
      <<(Int_t) ((str1[6][0]-str1[6][1])/(muon[6][0])+0.5)<<" | "<<endl;
  cout<<"| Ae      | "<<muon[0][1]<<" | "<<muon[1][1]<<" | "<<muon[2][1]<<" | "<<muon[3][1]<<" | "<<muon[4][1]<<" | "<<muon[5][1]<<" | "<<muon[6][1]<<" | "<<endl;
  cout<<"| Nlost,\mu| "
      <<(Int_t)((str1[0][0]-str1[0][1])*(1-muon[0][1])/(muon[0][0])+0.5)<<" | "
      <<(Int_t)((str1[1][0]-str1[1][1])*(1-muon[1][1])/(muon[1][0])+0.5)<<" | "
      <<(Int_t)((str1[2][0]-str1[2][1])*(1-muon[2][1])/(muon[2][0])+0.5)<<" | "
      <<(Int_t)((str1[3][0]-str1[3][1])*(1-muon[3][1])/(muon[3][0])+0.5)<<" | "
      <<(Int_t)((str1[4][0]-str1[4][1])*(1-muon[4][1])/(muon[4][0])+0.5)<<" | "
      <<(Int_t)((str1[5][0]-str1[5][1])*(1-muon[5][1])/(muon[5][0])+0.5)<<" | "
      <<(Int_t)((str1[6][0]-str1[6][1])*(1-muon[6][1])/(muon[6][0])+0.5)<<" | "<<endl;


  //Electron table
  cout<<endl;
  cout<<"---+++Electron table"<<endl;
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  cout<<"| Ntot,e| "
      <<(Int_t) (elec[0][0]*(str1[0][0]-str1[0][1])/(muon[0][0]) + 0.5)<<" | "
      <<(Int_t) (elec[1][0]*(str1[1][0]-str1[1][1])/(muon[1][0]) + 0.5)<<" | "
      <<(Int_t) (elec[2][0]*(str1[2][0]-str1[2][1])/(muon[2][0]) + 0.5)<<" | "
      <<(Int_t) (elec[3][0]*(str1[3][0]-str1[3][1])/(muon[3][0]) + 0.5)<<" | "
      <<(Int_t) (elec[4][0]*(str1[4][0]-str1[4][1])/(muon[4][0]) + 0.5)<<" | "
      <<(Int_t) (elec[5][0]*(str1[5][0]-str1[5][1])/(muon[5][0]) + 0.5)<<" | "
      <<(Int_t) (elec[6][0]*(str1[6][0]-str1[6][1])/(muon[6][0]) + 0.5)<<" | "<<endl; 
  cout<<"| A_ee_e      | "<<elec[0][1]<<" | "<<elec[1][1]<<" | "<<elec[2][1]<<" | "<<elec[3][1]<<" | "<<elec[4][1]<<" | "<<elec[5][1]<<" | "<<elec[6][1]<<" | "<<endl;
  cout<<"| Ratio | ";
  for(int i=0;i<7;i++){
    PrintEvent3(GenElec2[i]/GenMuon2[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Nlost,e| "
      <<(Int_t) (elec[0][0]*(str1[0][0]-str1[0][1])*(1-elec[0][1])/(muon[0][0]) + 0.5)<<" | "
      <<(Int_t) (elec[1][0]*(str1[1][0]-str1[1][1])*(1-elec[1][1])/(muon[1][0]) + 0.5)<<" | "
      <<(Int_t) (elec[2][0]*(str1[2][0]-str1[2][1])*(1-elec[2][1])/(muon[2][0]) + 0.5)<<" | "
      <<(Int_t) (elec[3][0]*(str1[3][0]-str1[3][1])*(1-elec[3][1])/(muon[3][0]) + 0.5)<<" | "
      <<(Int_t) (elec[4][0]*(str1[4][0]-str1[4][1])*(1-elec[4][1])/(muon[4][0]) + 0.5)<<" | "
      <<(Int_t) (elec[5][0]*(str1[5][0]-str1[5][1])*(1-elec[5][1])/(muon[5][0]) + 0.5)<<" | "
      <<(Int_t) (elec[6][0]*(str1[6][0]-str1[6][1])*(1-elec[6][1])/(muon[6][0]) + 0.5)<<" | "<<endl;

  //Tau table
  cout<<endl;  
  cout<<"---+++Tau table"<<endl;
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  cout<<"| Ntot,ht| "
      <<(Int_t) (str1[0][2]*(str1[0][0]-str1[0][1])/(muon[0][0]) + 0.5)<<" | "
      <<(Int_t) (str1[1][2]*(str1[1][0]-str1[1][1])/(muon[1][0]) + 0.5)<<" | "
      <<(Int_t) (str1[2][2]*(str1[2][0]-str1[2][1])/(muon[2][0]) + 0.5)<<" | "
      <<(Int_t) (str1[3][2]*(str1[3][0]-str1[3][1])/(muon[3][0]) + 0.5)<<" | "
      <<(Int_t) (str1[4][2]*(str1[4][0]-str1[4][1])/(muon[4][0]) + 0.5)<<" | "
      <<(Int_t) (str1[5][2]*(str1[5][0]-str1[5][1])/(muon[5][0]) + 0.5)<<" | "
      <<(Int_t) (str1[6][2]*(str1[6][0]-str1[6][1])/(muon[6][0]) + 0.5)<<" | "<<endl; 
  cout<<"| A_te_t      | "
      <<str1[0][3]*str1[0][4]<<" | "
      <<str1[1][3]*str1[1][4]<<" | "
      <<str1[2][3]*str1[2][4]<<" | " 
      <<str1[3][3]*str1[3][4]<<" | "
      <<str1[4][3]*str1[4][4]<<" | "
      <<str1[5][3]*str1[5][4]<<" | " 
      <<str1[6][3]*str1[6][4]<<" | "<<endl;
  cout<<"| Ratio | ";
  for(int i=0;i<7;i++){
    PrintEvent3(GenHadT[i]/GenMuon[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Nlost,ht| "
      <<(Int_t) (str1[0][2]*(str1[0][0]-str1[0][1])*(1-str1[0][3]*str1[0][4])/(muon[0][0]) + 0.5)<<" | "
      <<(Int_t) (str1[1][2]*(str1[1][0]-str1[1][1])*(1-str1[1][3]*str1[1][4])/(muon[1][0]) + 0.5)<<" | "
      <<(Int_t) (str1[2][2]*(str1[2][0]-str1[2][1])*(1-str1[2][3]*str1[2][4])/(muon[2][0]) + 0.5)<<" | "
      <<(Int_t) (str1[3][2]*(str1[3][0]-str1[3][1])*(1-str1[3][3]*str1[3][4])/(muon[3][0]) + 0.5)<<" | "
      <<(Int_t) (str1[4][2]*(str1[4][0]-str1[4][1])*(1-str1[4][3]*str1[4][4])/(muon[4][0]) + 0.5)<<" | "
      <<(Int_t) (str1[5][2]*(str1[5][0]-str1[5][1])*(1-str1[5][3]*str1[5][4])/(muon[5][0]) + 0.5)<<" | "
      <<(Int_t) (str1[6][2]*(str1[6][0]-str1[6][1])*(1-str1[6][3]*str1[6][4])/(muon[6][0]) + 0.5)<<" | "<<endl;
  
  Double_t totalError[7]; 
  Double_t totalEvent[7];
  for(Int_t i=3; i<10; i++){
    
    double t       = ( 1-muon[i-3][1] + elec[i-3][0]*(1-elec[i-3][1]) + str1[i-3][2]*(1-str1[i-3][3]*str1[i-3][4]));
    /*
      totalError[i-3] = sqrt(
      //dNtot
      pow(str1[i-3][6],2)    //Nobs
      + pow(str1[i-3][7],2)  //Nbck
      + pow(muon[i-3][2]/muon[i-3][0],2)  //APrime * Eprime
      
      + (1/pow(t,2))*(
      pow(muon[i-3][3]/muon[i-3][1],2) * pow(1-muon[i-3][1],2)  //Amu*Emu
      + (pow(elec2[i-3][0],-1)
      + pow(elec2[i-3][1],-1)
      + pow(elec[i-3][3]/elec[i-3][1],2)
      ) * elec[i-3][0] * pow(1-elec[i-3][1],2) //AE * eE
      + (pow(str2[i-3][0],-1)
      + pow(str2[i-3][1],-1)
      + pow(str1[i-3][5]/(str1[i-3][3]*str1[i-3][4]),2)) * str1[i-3][2] * pow(1-str1[i-3][3]*str1[i-3][4],2)             //AHT * eHT
      )
      + pow(0.02,2)
      );
    */
    /*
    totalError[i-3] = sqrt(
    //dNtot
    pow(str1[i-3][6],2)    //Nobs
    + pow(str1[i-3][7],2)  //Nbck
    + pow(muon[i-3][2]/muon[i-3][0],2)  //APrime * Eprime
    + (1/pow(t,2)) *pow((
    -muon[i-3][3]
    -elec[i-3][0]*elec[i-3][3]
    +(1-elec[i-3][3])*sqrt(pow(mcreweight*elec2[i-3][0],-1)+ pow(mcreweight*elec2[i-3][1],-1))
    -str1[i-3][2]*str1[i-3][5]
    +(1-str1[i-3][5])*sqrt(pow(mcreweight*str2[i-3][0],-1)+ pow(mcreweight*str2[i-3][1],-1))
    ),2)
    + pow(0.02,2)
    );
    */
    totalError[i-3] = sqrt(
			   (pow(str1[i-3][0]-str1[i-3][1],-2)*(pow(str1[i-3][6],2)+pow(str1[i-3][7],2) )
			    + pow(muon[i-3][0],-2) * pow(muon[i-3][2],2))
			   + pow(t,-2) * (
					  pow(muon[i-3][3],2)
					  + pow(elec[i-3][0]*elec[i-3][3],2)
					  + pow(str1[i-3][2]*str1[i-3][5],2)
					  + pow(1-elec[i-3][1],2) * pow(elec[i-3][0],2) * (pow(mcreweight*elec2[i-3][0],-1)+ pow(mcreweight*elec2[i-3][1],-1))
					  + pow(1-str1[i-3][3]*str1[i-3][4],2) * pow(str1[i-3][2],2) * (pow(mcreweight*str2[i-3][0],-1)+ pow(mcreweight*str2[i-3][1],-1))
					  )
			   + pow(0.02,2)
			   + pow(0.02,2)
			   );
    //totalError[i-3] = sqrt( pow(totalError[i-3],2) + pow(0.02,2) );
    totalEvent[i-3] = (((str1[i-3][0]-str1[i-3][1])*(1-muon[i-3][1])/(muon[i-3][0]))
		       +(elec[i-3][0]*(str1[i-3][0]-str1[i-3][1])*(1-elec[i-3][1])/(muon[i-3][0]))
		       +(str1[i-3][2]*(str1[i-3][0]-str1[i-3][1])*(1-str1[i-3][3]*str1[i-3][4])/(muon[i-3][0])));
  }

  cout<<endl;
  cout<<"---+++Total Wlost table"<<endl;
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  cout<<"| Nlost,tot | "
      <<(Int_t) (totalEvent[0]+0.5)<<" | "
      <<(Int_t) (totalEvent[1]+0.5)<<" | " 
      <<(Int_t) (totalEvent[2]+0.5)<<" | " 
      <<(Int_t) (totalEvent[3]+0.5)<<" | " 
      <<(Int_t) (totalEvent[4]+0.5)<<" | " 
      <<(Int_t) (totalEvent[5]+0.5)<<" | " 
      <<(Int_t) (totalEvent[6]+0.5)<<" | "<<endl;
  cout<<"| Error Nobs (%) |"
      <<setiosflags(ios::fixed | ios::showpoint | ios::right)
      <<setprecision(3)
      <<str1[0][8]*100<<" | "
      <<str1[1][8]*100<<" | " 
      <<str1[2][8]*100<<" | " 
      <<str1[3][8]*100<<" | " 
      <<str1[4][8]*100<<" | " 
      <<str1[5][8]*100<<" | " 
      <<str1[6][8]*100<<" | "<<endl; 
  cout<<"| Error Nbck (%) |"
      <<str1[0][9]*100<<" | "
      <<str1[1][9]*100<<" | " 
      <<str1[2][9]*100<<" | " 
      <<str1[3][9]*100<<" | " 
      <<str1[4][9]*100<<" | " 
      <<str1[5][9]*100<<" | " 
      <<str1[6][9]*100<<" | "<<endl;
  cout<<"| Error (APrime * Eprime) (%) |"
      <<muon[0][2]*100/muon[0][0]<<" | "
      <<muon[1][2]*100/muon[1][0]<<" | " 
      <<muon[2][2]*100/muon[2][0]<<" | " 
      <<muon[3][2]*100/muon[3][0]<<" | " 
      <<muon[4][2]*100/muon[4][0]<<" | " 
      <<muon[5][2]*100/muon[5][0]<<" | " 
      <<muon[6][2]*100/muon[6][0]<<" | "<<endl;
  cout<<"| Error (Amu * Emu) (%) |"
      <<muon[0][3]*100/muon[0][1]<<" | "
      <<muon[1][3]*100/muon[1][1]<<" | " 
      <<muon[2][3]*100/muon[2][1]<<" | " 
      <<muon[3][3]*100/muon[3][1]<<" | " 
      <<muon[4][3]*100/muon[4][1]<<" | " 
      <<muon[5][3]*100/muon[5][1]<<" | " 
      <<muon[6][3]*100/muon[6][1]<<" | "<<endl;
  cout<<"| Error (Ae * Ee) (%) |"
      <<elec[0][3]*100/elec[0][1]<<" | "
      <<elec[1][3]*100/elec[1][1]<<" | " 
      <<elec[2][3]*100/elec[2][1]<<" | " 
      <<elec[3][3]*100/elec[3][1]<<" | " 
      <<elec[4][3]*100/elec[4][1]<<" | " 
      <<elec[5][3]*100/elec[5][1]<<" | " 
      <<elec[6][3]*100/elec[6][1]<<" | "<<endl;
  cout<<"| Error (At * Et) (%) |"
      <<str1[0][5]*100/(str1[0][3]*str1[0][4])<<" | "
      <<str1[1][5]*100/(str1[1][3]*str1[1][4])<<" | " 
      <<str1[2][5]*100/(str1[2][3]*str1[2][4])<<" | " 
      <<str1[3][5]*100/(str1[3][3]*str1[3][4])<<" | " 
      <<str1[4][5]*100/(str1[4][3]*str1[4][4])<<" | " 
      <<str1[5][5]*100/(str1[5][3]*str1[5][4])<<" | " 
      <<str1[6][5]*100/(str1[6][3]*str1[6][4])<<" | "<<endl;
  cout<<"| Error Acc. unc. PDF (%) | 2.0 | 2.0 | 2.0 | 2.0 | 2.0 | 2.0 | 2.0 |"<<endl;
  //cout<<"| Error MC/Data factor| 0.020 | 0.020 | 0.020 | 0.020 | 0.020 | 0.020 | 0.020 |"<<endl;
  cout<<"| TotalError (%) | "
      <<totalError[0]*100<<" | "
      <<totalError[1]*100<<" | " 
      <<totalError[2]*100<<" | " 
      <<totalError[3]*100<<" | " 
      <<totalError[4]*100<<" | " 
      <<totalError[5]*100<<" | " 
      <<totalError[6]*100<<" | "<<endl; 
  cout<<"| Err(Nlost,tot) | "
      <<(Int_t) (totalEvent[0]*totalError[0]+0.5)<<" | "
      <<(Int_t) (totalEvent[1]*totalError[1]+0.5)<<" | " 
      <<(Int_t) (totalEvent[2]*totalError[2]+0.5)<<" | " 
      <<(Int_t) (totalEvent[3]*totalError[3]+0.5)<<" | " 
      <<(Int_t) (totalEvent[4]*totalError[4]+0.5)<<" | " 
      <<(Int_t) (totalEvent[5]*totalError[5]+0.5)<<" | " 
      <<(Int_t) (totalEvent[6]*totalError[6]+0.5)<<" | "<<endl;  
  
  
  //----------------------------------------
  //Summary
  cout<<""<<endl;
  cout<<"---++Summary"<<endl;   
  Double_t str3[7][9];
  Double_t total_bck_error[7] = 0.;
  for(Int_t i=3; i<10; i++){ 
    char file1[200], file2[200], file3[200], file4[200], file5[200],file6[200];
    sprintf(file1,"Data_AnaMonoJet_%d.root", i+6);
    sprintf(file2,"SUMBGD_zjets_AnaMonoJet_%d.root", i+6);
    sprintf(file3,"SUMBGD_ttbar_AnaMonoJet_%d.root", i+6);
    sprintf(file4,"SUMBGD_sint_AnaMonoJet_%d.root", i+6);
    sprintf(file5,"SUMBGD_diboson_AnaMonoJet_%d.root", i+6);
    sprintf(file6,"SUMBGD_qcd_AnaMonoJet_%d.root", i+6);
    fdata    = new TFile(file1);
    fzjets   = new TFile(file2);
    fttbar   = new TFile(file3);
    fsint    = new TFile(file4);
    fdiboson = new TFile(file5);
    fqcd     = new TFile(file6);
    
    TH1D*  H_data    = (TH1D*) fdata->Get("NPV");
    TH1D*  H_zjets   = (TH1D*) fzjets->Get("NPV");
    TH1D*  H_ttbar   = (TH1D*) fttbar->Get("NPV"); 
    TH1D*  H_qcd     = (TH1D*) fqcd->Get("NPV");
    TH1D*  H_sint    = (TH1D*) fsint->Get("NPV");
    TH1D*  H_diboson = (TH1D*) fdiboson->Get("NPV");
    int overflowBin  = H_data->GetSize()-1;
    
    Double_t wjets      = 0.;
    Double_t znunu      = ZNuNu[i-3]; 
    Double_t znunuerr   = ZNuNuError[i-3];
    Double_t ndata      = H_data->Integral(1,overflowBin);
    Double_t zjets      = H_zjets->Integral(1,overflowBin);
    Double_t ttbar      = H_ttbar->Integral(1,overflowBin);
    Double_t qcd        = H_qcd->Integral(1,overflowBin);
    Double_t singlet    = H_sint->Integral(1,overflowBin);
    Double_t diboson    = H_diboson->Integral(1,overflowBin);
    
    total_bck_error[i-3] = sqrt(pow(zjets/2.,2)+pow(ttbar/2.,2)+pow(qcd/2.,2)+pow(singlet/2.,2)+pow(diboson/2.,2)+pow(znunuerr,2));
    
    str3[i-3][0] = wjets;
    str3[i-3][1] = zjets;
    str3[i-3][2] = znunu;
    str3[i-3][3] = ttbar;
    str3[i-3][4] = qcd;
    str3[i-3][5] = singlet; 
    str3[i-3][6] = diboson;
    str3[i-3][7] = ndata;
    str3[i-3][8] = znunuerr;
  }
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl; 
  cout<<"| Z(nunu)+jets | ";
  for(int i=0; i<7; i++){
    PrintEvent2(str3[i][2]);
    cout<<"+/-";
    PrintEvent2(str3[i][8]);
    cout<<" | ";
  }
  cout<<endl;

  cout<<"| W+jets | ";
  for(int i=0; i<7; i++){
    PrintEvent2(totalEvent[i]);
    cout<<"+/-";
    PrintEvent2(totalEvent[i]*totalError[i]);
    cout<<" | ";
  }
  cout<<endl;

  cout<<"| TTbar | ";
  for(int i=0; i<7; i++){
    PrintEvent2(str3[i][3]);
    cout<<"+/-";
    PrintEvent2((str3[i][3])/2);
    cout<<" | ";
  }
  cout<<endl;

  cout<<"| Z(ll)+jets | ";
  for(int i=0; i<7; i++){
    PrintEvent2(str3[i][1]);
    cout<<"+/-";
    PrintEvent2((str3[i][1])/2);
    cout<<" | ";
  }
  cout<<endl;

  cout<<"| Single t | ";
  for(int i=0; i<7; i++){
    PrintEvent2(str3[i][5]);
    cout<<"+/-";
    PrintEvent2((str3[i][5])/2);
    cout<<" | ";
  }
  cout<<endl;

  cout<<"| QCD Multijets | ";
  for(int i=0; i<7; i++){
    PrintEvent2(str3[i][4]);
    cout<<"+/-";
    PrintEvent2((str3[i][4])/2);
    cout<<" | ";
  }
  cout<<endl;

  cout<<"| DiBoson | ";
  for(int i=0; i<7; i++){
    PrintEvent2(str3[i][6]);
    cout<<"+/-";
    PrintEvent2((str3[i][6])/2);
    cout<<" | ";
  }
  cout<<endl;

  cout<<"| Total SM | ";
  for(int i=0; i<7; i++){
    Double_t total = (str3[i][0]+str3[i][1]+str3[i][2]+str3[i][3]+str3[i][4]+str3[i][5]+str3[i][6]+totalEvent[i]);
    Double_t total_error = sqrt(pow(total_bck_error[i],2)+pow(totalEvent[i]*totalError[i],2));
    PrintEvent2(total);
    cout<<"+/-";
    PrintEvent2(total_error);
    cout<<" | ";
  }
  cout<<endl;

  cout<<"| Data | ";
  for(int i=0; i<7; i++){
    PrintEvent2(str3[i][7],true);
    cout<<" | ";
  }
  cout<<endl;
}
