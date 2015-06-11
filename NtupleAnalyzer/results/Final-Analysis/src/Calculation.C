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
  double mcreweight   = 2.8;
  double dyMCReweight = 3.294;
  double wMCReweight  = 2.834;
  double zScaleFactor = 1.092;
  double wScaleFactor = 1.045;
  double wfactor      = 1;
  bool   isVaryMET    = false;
  int    jet2cut      = 80;
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
  TFile *ftauEff;
  
  //----------------------------------------
  //AnaMonoJet: Cutflow
  cout<<"---++Monojet cutflow"<<endl;
  cout<<"---+++Description"<<endl;
  cout<<"   * Standard monojet"<<endl;
  if(isVaryMET==true){
    cout<<"   * Vary MET"<<endl;
    cout<<"   * Count jet only JetPT > 30 !GeV";
  }
  else{
    cout<<"   * Vary Jet1"<<endl;
    cout<<"   * Count jet only JetPT > "<<jet2cut<<" !GeV";
  }
  cout<<endl;
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
  cout<<endl;
  
  //----------------------------------------
  //AnaMuonTau: ZJets
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
    int overflowBin   = h_z_data->GetSize()-1;
    //
    ZMuMuData[i-3] = h_z_data->Integral(0,overflowBin);
    ZMuMuMC[i-3]   = h_z_zjets->Integral(0,overflowBin);
    ZMuMuBGD[i-3]  = h_z_wjets->Integral(0,overflowBin)
      + h_z_diboson->Integral(0,overflowBin)
      + h_z_ttbar->Integral(0,overflowBin)
      + h_z_sint->Integral(0,overflowBin)
      + h_z_qcd->Integral(0,overflowBin);
    //Assign 50% error on each background
    ZMuMuBGDSqrt[i-3] = sqrt(pow(h_z_wjets->Integral(0,overflowBin)/2,2)
			     + pow(h_z_diboson->Integral(0,overflowBin)/2,2)
			     + pow(h_z_ttbar->Integral(0,overflowBin)/2,2)
			     + pow(h_z_sint->Integral(0,overflowBin)/2,2)
			     + pow(h_z_qcd->Integral(0,overflowBin)/2,2));
    TH1D*  alldimu = (TH1D*) fzjets->Get("WZEstimation");
    TH1D*  accdimu = (TH1D*) fzjets->Get("WZEstimation");
    AllDiMu[i-3] = (alldimu->GetBinContent(2))/2;
    AccDiMu[i-3] = (accdimu->GetBinContent(4))/2;
    //
    if(isVaryMET==true)
      std::cout<<"| PFMET+MU > "<<200+(i-2)*50<<" !GeV";
    else
      std::cout<<"| Jet1 > "<<200+(i-2)*50<<" !GeV";
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
  cout<<endl;

  Double_t ZNuNu[7];
  Double_t ZAcc[7];
  Double_t ZEff[7];
  Double_t ZMuMuDataErr[7];
  Double_t ZMuMuBgdErr[7];
  Double_t ZAccErr[7];
  Double_t ZEffErr[7];
  Double_t ZTotalErr[7];
  Double_t ZNuNuError[7];
  for(Int_t i=0; i<7; i++){
    ZAcc[i]  = AccDiMu[i]/AllDiMu[i];
    ZEff[i]  = (ZMuMuMC[i]/AccDiMu[i])/zScaleFactor;
    ZNuNu[i] = (ZMuMuData[i]-ZMuMuBGD[i])*(5.942/(ZAcc[i]*ZEff[i]));
    //
    ZMuMuDataErr[i] = sqrt(ZMuMuData[i])/(ZMuMuData[i]-ZMuMuBGD[i]);
    //ZMuMuBgdErr[i]  = sqrt(ZMuMuBGD[i])/(ZMuMuData[i]-ZMuMuBGD[i]); //Statistical error on each background
    ZMuMuBgdErr[i]  = ZMuMuBGDSqrt[i]/(ZMuMuData[i]-ZMuMuBGD[i]); //50% on each background
    ZAccErr[i]      = sqrt(pow(sqrt(ZAcc[i]*(1-ZAcc[i])/(dyMCReweight*AllDiMu[i])),2)+pow(0.02*ZAcc[i],2))/ZAcc[i];
    ZEffErr[i]      = sqrt(pow(sqrt(ZEff[i]*(1-ZEff[i])/(dyMCReweight*AccDiMu[i])),2)+pow(0.02*ZEff[i],2))/ZEff[i];
    ZTotalErr[i]    = sqrt(pow(ZMuMuDataErr[i],2)
			   + pow(ZMuMuBgdErr[i],2)
			   + pow(ZAccErr[i],2)
			   + pow(ZEffErr[i],2)
			   + 2*ZAccErr[i]*ZEffErr[i]//);
			   + pow(0.02,2));//<---Need confirmation from Evrim, what is it?
    ZNuNuError[i]   = ZNuNu[i]*ZTotalErr[i];
  }
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
  cout<<endl;
  
  cout<<"---+++Systematic uncertainty (in percent) of Z(nu,nu) prediction"<<endl; 
  cout<<"   * Error in PDF (2%) and hadronization (2%) are absorbed to Acc, and Eff uncertainty term, respectively."<<endl; 
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  cout<<"| Nobs | ";
  for(int i=0;i<7;i++){
    PrintEvent2(ZMuMuDataErr[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Nbgd | ";
  for(int i=0;i<7;i++){
    PrintEvent2(ZMuMuBgdErr[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Acc | ";
  for(int i=0;i<7;i++){
    PrintEvent2(ZAccErr[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Eff | ";
  for(int i=0;i<7;i++){
    PrintEvent2(ZEffErr[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Data/MC Scale factor | ";
  for(int i=0;i<7;i++){
    PrintEvent2(2.0);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Total | ";
  for(int i=0;i<7;i++){
    PrintEvent2(ZTotalErr[i]*100);
    cout<<" | ";
  }
  cout<<endl; 
  cout<<endl;
  
  //----------------------------------------
  //AnaMuonTau: WJets
  cout<<"---++W Analysis"<<endl;
  cout<<"---+++W(mu,nu) event yeilds"<<endl;
  cout<<"|  *Selection*  |  *WJets*  |  *ZJets*  |  *Znunu*  |  *DiBoson*  |  *TTbar*  |  *SingleT*  |  *QCD*  |  *Total MC*  |  *Data*  |"<<endl; 
  Double_t WMuData[7];
  Double_t WMuMC[7];
  Double_t WMuBGD[7];
  Double_t WMuBGDSqrt[7];
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
    int overflowBin   = h_w_data->GetSize()-1;
    WMuData[i-3] = h_w_data->Integral(0,overflowBin);
    WMuMC[i-3]   = h_w_wjets->Integral(0,overflowBin);
    WMuBGD[i-3]  = h_w_zjets->Integral(0,overflowBin)
      + h_w_diboson->Integral(0,overflowBin)
      + h_w_ttbar->Integral(0,overflowBin)
      + h_w_sint->Integral(0,overflowBin)
      + h_w_qcd->Integral(0,overflowBin);
    //Assign 50% error on each background
    WMuBGDSqrt[i-3] = sqrt(pow(h_w_zjets->Integral(0,overflowBin)/2,2)
			   + pow(h_w_diboson->Integral(0,overflowBin)/2,2)
			   + pow(h_w_ttbar->Integral(0,overflowBin)/2,2)
			   + pow(h_w_sint->Integral(0,overflowBin)/2,2)
			   + pow(h_w_qcd->Integral(0,overflowBin)/2,2));
    if(isVaryMET==true)
      std::cout<<"| PFMET+MU > "<<200+(i-2)*50<<" !GeV";
    else
      std::cout<<"| Jet1 > "<<200+(i-2)*50<<" !GeV";
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
  cout<<endl;
  
  //AnaMuon: Generator ratio
  cout<<"---+++Generator ratio (W+Jets) AnaMuon"<<endl;
  Double_t GenMuon[7];
  Double_t GenHadT[7];
  Double_t GenHadTF[7];
  for(Int_t i=3; i<10; i++){
    char file1[200];
    sprintf(file1,"SUM_WZAnalysis_%d.root", i);
    fwjets   = new TFile(file1);
    TH1D *h_ratio_wjets   = fwjets->Get("WZEstimation");
    GenMuon[i-3]  = h_ratio_wjets->GetBinContent(2)+h_ratio_wjets->GetBinContent(14);
    GenHadT[i-3]  = h_ratio_wjets->GetBinContent(12)-h_ratio_wjets->GetBinContent(13)-h_ratio_wjets->GetBinContent(14);
    GenHadTF[i-3] = GenHadT[i-3]/GenMuon[i-3];
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
    PrintEvent3(GenHadTF[i]);
    cout<<" | ";
  }
  cout<<endl;

  cout<<endl;
  cout<<"---+++Generator ratio (W+Jets) AnaMuonTau"<<endl;
  Double_t GenMuon2[7];
  Double_t GenElec2[7];
  Double_t GenElecF[7];
  for(Int_t i=3; i<10; i++){
    char file1[200];
    sprintf(file1,"SUMBGD_wjets_WZTauAnalysis_%d.root", i);
    fwjets   = new TFile(file1);
    TH1D *h2_ratio_wjets   = fwjets->Get("WZEstimation");
    GenMuon2[i-3] = h2_ratio_wjets->GetBinContent(2)+h2_ratio_wjets->GetBinContent(14);
    GenElec2[i-3] = h2_ratio_wjets->GetBinContent(7)+h2_ratio_wjets->GetBinContent(13);
    GenElecF[i-3] = GenElec2[i-3]/GenMuon2[i-3];
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
    PrintEvent3(GenElecF[i]);
    cout<<" | ";
  }
  cout<<endl;
  
  //Muon, Electron efficiencies
  //Selection efficiency
  Double_t WMuAccPrime[7];
  Double_t WMuEffPrime[7]; 
  Double_t WMuAccPrimeError[7];
  Double_t WMuEffPrimeError[7];
  //Veto efficiency (muon)
  Double_t AllSingleMuVeto[7];
  Double_t AccSingleMuVeto[7];
  Double_t EffSingleMuVeto[7];
  Double_t WMuAcc[7];
  Double_t WMuEff[7];
  //Veto efficiency (electron)
  Double_t AllSingleElVeto[7];
  Double_t AccSingleElVeto[7];
  Double_t EffSingleElVeto[7];
  Double_t WEAcc[7];
  Double_t WEEff[7];
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
    //
    TH1D *muonHist2 = fwjets->Get("WZEstimation");
    TH1D *muonHist3 = fwjets->Get("WlepnuMT_50_100");

    // APrimeMu x EPrimeMu (Selection efficiency)
    double AllSingleMu = muonHist2->GetBinContent(2)+muonHist2->GetBinContent(14);
    double AccSingleMu = muonHist2->GetBinContent(4)+muonHist2->GetBinContent(16);
    double EffSingleMu = muonHist2->GetBinContent(6)+muonHist2->GetBinContent(37);
    WMuAccPrime[i-3]      = AccSingleMu/AllSingleMu;
    WMuEffPrime[i-3]      = (EffSingleMu/AccSingleMu)/wScaleFactor;
    WMuAccPrimeError[i-3] = sqrt(pow(sqrt(WMuAccPrime[i-3]*(1-WMuAccPrime[i-3])/(wMCReweight*AllSingleMu)),2)+pow(0.02*WMuAccPrime[i-3],2))/WMuAccPrime[i-3];
    WMuEffPrimeError[i-3] = sqrt(pow(sqrt(WMuEffPrime[i-3]*(1-WMuEffPrime[i-3])/(wMCReweight*AccSingleMu)),2)+pow(0.02*WMuEffPrime[i-3],2))/WMuEffPrime[i-3];
    
    // AMu x EMu (Veto efficiency)
    AllSingleMuVeto[i-3] = muonHist2->GetBinContent(2)+muonHist2->GetBinContent(14);
    AccSingleMuVeto[i-3] = muonHist2->GetBinContent(3)+muonHist2->GetBinContent(16);
    EffSingleMuVeto[i-3] = muonHist2->GetBinContent(5)+muonHist2->GetBinContent(18);
    WMuAcc[i-3]          = AccSingleMuVeto[i-3]/AllSingleMuVeto[i-3];
    WMuEff[i-3]          = (EffSingleMuVeto[i-3]/AccSingleMuVeto[i-3]);

    // AE x EE (Veto efficiency)
    AllSingleElVeto[i-3] = muonHist2->GetBinContent(7)+muonHist2->GetBinContent(13);
    AccSingleElVeto[i-3] = muonHist2->GetBinContent(8)+muonHist2->GetBinContent(15);
    EffSingleElVeto[i-3] = muonHist2->GetBinContent(10)+muonHist2->GetBinContent(17);
    WEAcc[i-3]           = AccSingleElVeto[i-3]/AllSingleElVeto[i-3];
    WEEff[i-3]           = (EffSingleElVeto[i-3]/AccSingleElVeto[i-3]);
  }

  //Tau acceptance
  Double_t AllSingleTauVeto[7];
  Double_t AccSingleTauVeto[7];
  Double_t EffSingleTauVeto[7];
  Double_t WHTauAcc[7];
  Double_t WHTauEff[7];
  for(Int_t i=3; i<10; i++){
    char fileEff[200];
    sprintf(fileEff,"SUM_AnaHadronicTau_%d.root",i+6);
    ftauEff  = new TFile(fileEff);
    TH1D *All3 = ftauEff->Get("GenTauPt3_had");
    TH1D *AAA3 = ftauEff->Get("GenTauPt3_had_A");
    TH1D *AAe3 = ftauEff->Get("TauPt3_HPS");
    int overflowBin = ftauEff->GetSize()-1;
    AllSingleTauVeto[i-3] = All3->Integral(0,overflowBin);
    AccSingleTauVeto[i-3] = AAA3->Integral(0,overflowBin);
    EffSingleTauVeto[i-3] = AAe3->Integral(0,overflowBin);
    WHTauAcc[i-3] = AccSingleTauVeto[i-3]/AllSingleTauVeto[i-3];
    WHTauEff[i-3] = EffSingleTauVeto[i-3]/AccSingleTauVeto[i-3];
    if(i-3==0){
      cout<<endl;
      cout<<"---+++Tau Acceptance/Efficiency"<<endl;
      std::cout<<"|  *Cut*  |  *Acc*  |  *Eff*  |"<<std::endl;
    }
    if(isVaryMET==true)
      std::cout<<"| PFMET+MU > "<<200+(i-2)*50<<" !GeV | ";
    else
      std::cout<<"| Jet1 > "<<200+(i-2)*50<<" !GeV | ";
    PrintEvent3(WHTauAcc[i-3]);
    cout<<" | ";
    PrintEvent3(WHTauEff[i-3]);
    cout<<" |"<<endl;;
  }
  cout<<endl;
  
  Double_t TotalLostFactor[7]; 
  Double_t WMuDataErr[7];
  Double_t WMuBgdErr[7];
  Double_t WMuAccError[7];
  Double_t WMuEffError[7];
  Double_t WEAccError[7];
  Double_t WEEffError[7];
  Double_t WHTauAccError[7];
  Double_t WHTauEffError[7];
  Double_t WTotalMu[7];
  Double_t WLostMu[7];
  Double_t WLostEl[7];
  Double_t WLostHT[7];
  Double_t WLostTotal[7]; 
  Double_t WLostTotalUnc[7];
  Double_t WLostTotalErr[7];
  for(Int_t i=0; i<7; i++){
    TotalLostFactor[i] = (1-WMuAcc[i]*WMuEff[i]) + GenElecF[i]*(1-WEAcc[7]*WEEff[7]) + GenHadTF[i]*(1-WHTauAcc[i]*WHTauEff[i]);
    //
    WMuDataErr[i] = sqrt(WMuData[i])/(WMuData[i]-WMuBGD[i]);
    //WMuBgdErr[i]  = sqrt(WMuBGD[i])/(WMuData[i]-WMuBGD[i]); //Statistical error on each background
    WMuBgdErr[i]  = WMuBGDSqrt[i]/(WMuData[i]-WMuBGD[i]); //50% on each background
    //
    WMuAccError[i]    = WMuEff[i]*sqrt(pow(sqrt(WMuAcc[i]*(1-WMuAcc[i])/(wMCReweight*AllSingleMuVeto[i])),2)/*+pow(0.02*WMuAcc[i-3],2)*/)/TotalLostFactor[i];
    WMuEffError[i]    = WMuAcc[i]*sqrt(pow(sqrt(WMuEff[i]*(1-WMuEff[i])/(wMCReweight*AccSingleMuVeto[i])),2)/*+pow(0.02*WMuEff[i-3],2)*/)/TotalLostFactor[i];
    //
    WEAccError[i]     = GenElecF[i]*WEEff[i]*sqrt(pow(sqrt(WEAcc[i]*(1-WEAcc[i])/(wMCReweight*AllSingleElVeto[i])),2)+pow(0.02*WEAcc[i],2))/TotalLostFactor[i];
    WEEffError[i]     = GenElecF[i]*WEAcc[i]*sqrt(pow(sqrt(WEEff[i]*(1-WEEff[i])/(wMCReweight*AccSingleElVeto[i])),2)+pow(0.02*WEEff[i],2))/TotalLostFactor[i];
    //
    WHTauAccError[i]  = GenHadTF[i]*WHTauEff[i]*sqrt(pow(sqrt(WHTauAcc[i]*(1-WHTauAcc[i])/(wMCReweight*AllSingleTauVeto[i])),2)+pow(0.02*WHTauAcc[i],2))/TotalLostFactor[i];
    WHTauEffError[i]  = GenHadTF[i]*WHTauAcc[i]*sqrt(pow(sqrt(WHTauEff[i]*(1-WHTauEff[i])/(wMCReweight*AccSingleTauVeto[i])),2)+pow(0.02*WHTauEff[i],2))/TotalLostFactor[i];
    //
    WTotalMu[i]       = (WMuData[i]-WMuBGD[i])/(WMuAccPrime[i]*WMuEffPrime[i]);
    WLostMu[i]        = WTotalMu[i]*(1-WMuAcc[i]*WMuEff[i]);
    WLostEl[i]        = WTotalMu[i]*(GenElecF[i]*(1-WEAcc[i]*WEEff[i]));
    WLostHT[i]        = WTotalMu[i]*(GenHadTF[i]*(1-WHTauAcc[i]*WHTauEff[i]));
    WLostTotal[i]     = WLostMu[i]+WLostEl[i]+WLostHT[i];
    //
    WLostTotalUnc[i]  = sqrt(pow(WMuDataErr[i],2)
			     + pow(WMuBgdErr[i],2)
			     //
			     + pow(WMuAccPrimeError[i],2)
			     + pow(WMuEffPrimeError[i],2)
			     + 2*WMuAccPrimeError[i]*WMuEffPrimeError[i]
			     //
			     + pow(WMuAccError[i],2)
			     + pow(WMuEffError[i],2)
			     + 2*WMuAccError[i]*WMuEffError[i]
			     //
			     + pow(WEAccError[i],2)
			     + pow(WEEffError[i],2)
			     + 2*WEAccError[i]*WEEffError[i]/GenElecF[i]
			     //
			     + pow(WHTauAccError[i],2)
			     + pow(WHTauEffError[i],2)
			     + 2*WHTauAccError[i]*WHTauEffError[i]/GenHadTF[i]
			     //
			     + pow(0.02,2)
			     );
    WLostTotalErr[i]     = WLostTotalUnc[i]*WLostTotal[i];
  } 
  //Muon table
  cout<<"---+++W(mu) table"<<endl;
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  //Double_t WMuData[7];
  //Double_t WMuMC[7];
  //Double_t WMuBGD[7];
  //Double_t WMuBGDSqrt[7];
  cout<<"| N_{obs} | ";
  for(int i=0;i<7;i++){
    PrintEvent(WMuData[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| N_{bck} | ";
  for(int i=0;i<7;i++){
    PrintEvent(WMuBGD[i]);
    cout<<" | ";
  }
  cout<<endl;   
  cout<<"| A'e'    | ";
  for(int i=0;i<7;i++){
    PrintEvent3(WMuAccPrime[i]*WMuEffPrime[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Ntot,\mu| ";
  for(int i=0;i<7;i++){
    PrintEvent(WTotalMu[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Ae      | ";
  for(int i=0;i<7;i++){
    PrintEvent3(WMuAcc[i]*WMuEff[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Nlost,\mu| ";
  for(int i=0;i<7;i++){
    PrintEvent(WLostMu[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<endl;
  
  //Electron table
  cout<<"---+++W(e) table"<<endl;
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  cout<<"| Ae      | ";
  for(int i=0;i<7;i++){
    PrintEvent3(WEAcc[i]*WEEff[i]);
    cout<<" | ";
  }
  cout<<endl; 
  cout<<"| fe  | ";
  for(int i=0;i<7;i++){
    PrintEvent3(GenElecF[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Nlost,e  | ";
  for(int i=0;i<7;i++){
    PrintEvent(WLostEl[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<endl;

  //Tau table  
  cout<<"---+++W(hadronic tau) table"<<endl;
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  cout<<"| Ae      | ";
  for(int i=0;i<7;i++){
    PrintEvent3(WHTauAcc[i]*WHTauEff[i]);
    cout<<" | ";
  }
  cout<<endl; 
  cout<<"| f(had. tau)  | ";
  for(int i=0;i<7;i++){
    PrintEvent3(GenHadTF[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Nlost,had. tau  | ";
  for(int i=0;i<7;i++){
    PrintEvent(WLostHT[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<endl;
  
  //W uncertainty table
  cout<<"---+++Systematic uncertainty (in percent) of Z(nu,nu) prediction"<<endl; 
  cout<<"   * Error in PDF (2%) and hadronization (2%) are absorbed to Acc, and Eff uncertainty term, respectively."<<endl; 
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  cout<<"| Nobs | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WMuDataErr[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Nbgd | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WMuBgdErr[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| WMuAccPrimeError | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WMuAccPrimeError[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| WMuEffPrimeError | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WMuEffPrimeError[i]*100);
    cout<<" | ";
  }
  cout<<endl; 
  cout<<"| WMuAccError | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WMuAccError[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| WMuEffError | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WMuEffError[i]*100);
    cout<<" | ";
  }
  cout<<endl; 
  cout<<"| WEAccError | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WEAccError[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| WEEffError | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WEEffError[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| WHTauAccError | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WHTauAccError[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| WHTauAccError | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WHTauAccError[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Data/MC Scale factor | ";
  for(int i=0;i<7;i++){
    PrintEvent2(2.0);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| WLostTotalUnc | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WLostTotalUnc[i]*100);
    cout<<" | ";
  }
  cout<<endl;
  cout<<"| Total WLost | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WLostTotal[i]);
    cout<<" | ";
  }
  cout<<endl; 
  cout<<"| WLost Error | ";
  for(int i=0;i<7;i++){
    PrintEvent2(WLostTotalErr[i]);
    cout<<" | ";
  }
  cout<<endl;
  cout<<endl;

  
  //----------------------------------------
  //Summary
  cout<<"---++Summary"<<endl;   
  Double_t str3[7][10];
  Double_t total_bck_error = 0.;
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
    
    Double_t wjets      = WLostTotal[i-3];
    Double_t wjetserr   = WLostTotalErr[i-3];
    Double_t znunu      = ZNuNu[i-3]; 
    Double_t znunuerr   = ZNuNuError[i-3];
    Double_t ndata      = H_data->Integral(1,overflowBin);
    Double_t zjets      = H_zjets->Integral(1,overflowBin);
    Double_t ttbar      = H_ttbar->Integral(1,overflowBin);
    Double_t qcd        = H_qcd->Integral(1,overflowBin);
    Double_t singlet    = H_sint->Integral(1,overflowBin);
    Double_t diboson    = H_diboson->Integral(1,overflowBin);
    
    total_bck_error     = sqrt(pow(wjetserr,2)+pow(znunuerr,2)+pow(zjets/2.,2)+pow(ttbar/2.,2)+pow(qcd/2.,2)+pow(singlet/2.,2)+pow(diboson/2.,2));
    
    str3[i-3][0] = wjets;
    str3[i-3][1] = zjets;
    str3[i-3][2] = znunu;
    str3[i-3][3] = ttbar;
    str3[i-3][4] = qcd;
    str3[i-3][5] = singlet; 
    str3[i-3][6] = diboson;
    str3[i-3][7] = ndata;
    str3[i-3][8] = wjets+zjets+znunu+ttbar+qcd+singlet+diboson;
    str3[i-3][9] = total_bck_error;
  }
  if(isVaryMET==true)
    cout<<"|  *MET (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl;
  else
    cout<<"|  *Jet1Pt (!GeV)*  |  *>250*  |  *>300*  |  *>350*  |  *>400*  |  *>450*  |  *>500*  |  *>550*  |"<<endl; 
  cout<<"| Z(nunu)+jets | ";
  for(int i=0; i<7; i++){
    PrintEvent2(ZNuNu[i]);
    cout<<"+/-";
    PrintEvent2(ZNuNuError[i]);
    cout<<" | ";
  }
  cout<<endl;

  cout<<"| W+jets | ";
  for(int i=0; i<7; i++){
    PrintEvent2(WLostTotal[i]);
    cout<<"+/-";
    PrintEvent2(WLostTotalErr[i]);
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
    PrintEvent2(str3[i][8]);
    cout<<"+/-";
    PrintEvent2(str3[i][9]);
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
