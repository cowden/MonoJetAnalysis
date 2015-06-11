#include "MergePlots.h"
#include "DrawOptions.h"

#include <TCanvas.h>
#include <TPaveStats.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TF1.h>
#include <TH1D.h>
#include <TLatex.h>
#include <TPaveLabel.h>
#include <TPaveText.h>
#include <TGaxis.h>
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"

#include <iostream>
#include <vector>
//#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

MergePlots::MergePlots(std::string dirname) : dirname_(dirname) {}
MergePlots::~MergePlots() {}

void MergePlots::addDataSet(std::string dataSet, string dataName ){
  cout<<"dataSet = "<<dataSet<<", dataName = "<<dataName<<endl;
  
  // Get the draw options for the dataset from the DrawOptions class
  DrawOptions* myOptions = new DrawOptions(dataName);
  
  // Create vector of ROOT files, one entry for each dataset
  TString dsRootFileName = dirname_ + dataSet + ".root";
  cout << "Adding " << dsRootFileName << endl;
  TFile* rootFile = new TFile(dsRootFileName, "read");
  
  //rootFile->Print();
  dataFileVec.push_back(rootFile);
  
  // Add dataset variables to other vectors
  drawOptVec.push_back(myOptions->drawOpt);
  colorVec.push_back(myOptions->color);
  linewidthVec.push_back(myOptions->linewidth);
  fillcolorVec.push_back(myOptions->fillcolor); 
  linestyleVec.push_back(myOptions->linestyle);
  dataNameVec.push_back(dataSet);
  reweightVec.push_back(myOptions->reweight);
  legendVec.push_back(dataName);
}

void MergePlots::mergeHist(char* histname, string titlex, string titley, TString kind, TString mc, TString data, bool legend, TString drawOpt, bool withScale){
  TCanvas *myCanvas = new TCanvas ("", "");
  //if(withScale){
  myCanvas->Divide(1, 2, 0,0,0);
  //}
  //else{
  //myCanvas->Divide(1, 1, 0,0,0);
  //}
  myCanvas->cd(1);
  TPad* p11_1 = (TPad*) myCanvas->GetPad(1); 
  //if(withScale){
  p11_1->SetPad(0.01,0.3,0.99,0.98);
  //}
  TLegend myLegend(0.55, 0.67, 0.92, 0.97);
  
  myLegend.SetNColumns(2);
  myLegend.SetBorderSize(0);
  //L[id]->SetFillColor(0);
  //L[id]->SetLineColor(1);
  myLegend.SetLineStyle(0);
  myLegend.SetTextFont(42);
  myLegend.SetFillStyle(0);
  
  
  p11_1->SetLogy();
  //myCanvas->SetGridx();
  //myCanvas->SetGridy();
  
  //gPad->RedrawAxis();
  
  int it = 0;
  //Double_t maxsize=0;
  
  for (vector<TFile*>::iterator tfileIt = dataFileVec.begin();tfileIt!=dataFileVec.end();tfileIt++){
    (*tfileIt)->GetListOfKeys()->Print();
    cout << " still alive, Weight = "<<reweightVec[it]<< endl;
    if( fillcolorVec[it]!=111 && fillcolorVec[it]!=112  && fillcolorVec[it]!=113 && fillcolorVec[it]!=114 && fillcolorVec[it]!=115 && fillcolorVec[it]!=116 ){
      ((TH1D*)(*tfileIt)->Get(histname))->SetFillColor(fillcolorVec[it]);
      if(legend==true)  myLegend.AddEntry(((TH1D*)(*tfileIt)->Get(histname)),legendVec[it], "F");
    }
    if( fillcolorVec[it]==111  ){
      ((TH1D*)(*tfileIt)->Get(histname))->Sumw2();
      ((TH1D*)(*tfileIt)->Get(histname))->SetMarkerStyle(8);
      ((TH1D*)(*tfileIt)->Get(histname))->SetMarkerSize(1.4);
      if(legend==true)  myLegend.AddEntry(((TH1D*)(*tfileIt)->Get(histname)),legendVec[it], "lp");
    }
    if(  fillcolorVec[it]==112  ){
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineStyle(2);
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineWidth(3);
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineColor(2);
      if(legend==true)  myLegend.AddEntry(((TH1D*)(*tfileIt)->Get(histname)),legendVec[it], "lp");
    }
    if(  fillcolorVec[it]==113  ){
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineStyle(2);
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineWidth(3);
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineColor(4);
      if(legend==true)  myLegend.AddEntry(((TH1D*)(*tfileIt)->Get(histname)),legendVec[it], "lp");
    }
    if(  fillcolorVec[it]==114  ){
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineStyle(2);
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineWidth(3);
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineColor(7);
      if(legend==true)  myLegend.AddEntry(((TH1D*)(*tfileIt)->Get(histname)),legendVec[it], "lp");
    }
    if(  fillcolorVec[it]==115  ){
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineStyle(2);
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineWidth(3);
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineColor(9);
      if(legend==true)  myLegend.AddEntry(((TH1D*)(*tfileIt)->Get(histname)),legendVec[it], "lp");
    }
    if(  fillcolorVec[it]==116  ){
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineStyle(2);
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineWidth(3);
      ((TH1D*)(*tfileIt)->Get(histname))->SetLineColor(kGreen+3);
      if(legend==true)  myLegend.AddEntry(((TH1D*)(*tfileIt)->Get(histname)),legendVec[it], "lp");
    }
    
    
    if(it==0) 
      {
	(*tfileIt)->Get(histname)->Draw();
      }
    else
      {
	((TH1D*)(*tfileIt)->Get(histname))->Scale(reweightVec[it]);
	((TH1D*)(*tfileIt)->Get(histname))->Draw("sames");
      }
      
    ///Adjust stat location
    
    if(legend ==false)
      {
	p11_1->Update();
	TPaveStats *st = (TPaveStats*)((TH1D*)(*tfileIt)->Get(histname))->FindObject("stats");
	
	st->SetTextColor( fillcolorVec[it] );
	
	double y = it*0.18;
	st->SetX1NDC(0.75);
	st->SetX2NDC(0.92);
	st->SetY1NDC( 0.8-y);
	st->SetY2NDC( 0.97-y );
      }
    
    //((TH1D*)(*tfileIt)->Get(histname))->SetTitle("MMMM");
    ((TH1D*)(*tfileIt)->Get(histname))->GetXaxis()->SetTitle( titlex.c_str() );
    ((TH1D*)(*tfileIt)->Get(histname))->GetYaxis()->SetTitle( titley.c_str() ); 
    
    ((TH1D*)(*tfileIt)->Get(histname))->GetXaxis()->SetTitleFont(42);
    ((TH1D*)(*tfileIt)->Get(histname))->GetXaxis()->SetTitleSize(0.05);
    ((TH1D*)(*tfileIt)->Get(histname))->GetXaxis()->SetTitleOffset(1.1);
    ((TH1D*)(*tfileIt)->Get(histname))->GetXaxis()->SetLabelSize(0.05);
    
    ((TH1D*)(*tfileIt)->Get(histname))->GetYaxis()->SetTitleFont(42);
    ((TH1D*)(*tfileIt)->Get(histname))->GetYaxis()->SetTitleSize(0.05);
    ((TH1D*)(*tfileIt)->Get(histname))->GetYaxis()->SetTitleOffset(1.25);
    ((TH1D*)(*tfileIt)->Get(histname))->GetYaxis()->SetLabelSize(0.05);
    
    //((TH1D*)(*tfileIt)->Get(histname))->GetYaxis()->SetTitleFont(42);
    //((TH1D*)(*tfileIt)->Get(histname))->GetYaxis()->SetTitleSize(0.04);
    
    //Float_t labelSize = 0.05;
    
    //((TH1D*)(*tfileIt)->Get(histname))->GetXaxis()->SetLabelSize( labelSize );
    //((TH1D*)(*tfileIt)->Get(histname))->GetYaxis()->SetLabelSize( labelSize );
    //
    //((TH1D*)(*tfileIt)->Get(histname))->GetXaxis()->SetLabelFont( 42 );
    //
    /*((TH1D*)(*tfileIt)->Get("NJet"))->GetXaxis()->CenterLabels(kTRUE);
      ((TH1D*)(*tfileIt)->Get("NJet"))->SetNdivisions(10);
      
      ((TH1D*)(*tfileIt)->Get("NJet5"))->GetXaxis()->CenterLabels(kTRUE);
      ((TH1D*)(*tfileIt)->Get("NJet5"))->SetNdivisions(5);
      
      ((TH1D*)(*tfileIt)->Get("NJet6"))->GetXaxis()->CenterLabels(kTRUE);
      ((TH1D*)(*tfileIt)->Get("NJet6"))->SetNdivisions(6);
      
      
      
      ((TH1D*)(*tfileIt)->Get("MetLep2"))->GetXaxis()->SetNdivisions(8,4,0, kFALSE);
      ((TH1D*)(*tfileIt)->Get("MetLep3"))->GetXaxis()->SetNdivisions(8,4,0, kFALSE);
      ((TH1D*)(*tfileIt)->Get("MetLep5"))->GetXaxis()->SetNdivisions(13,2,0, kFALSE);
      
      ((TH1D*)(*tfileIt)->Get("Jet1Pt"))->GetXaxis()->SetNdivisions(10,4,0, kFALSE);
      ((TH1D*)(*tfileIt)->Get("Jet1Pt2"))->GetXaxis()->SetNdivisions(10,4,0, kFALSE);
      ((TH1D*)(*tfileIt)->Get("Jet2Pt"))->GetXaxis()->SetNdivisions(6,4,0, kFALSE);
      ((TH1D*)(*tfileIt)->Get("MuonPt_2"))->GetXaxis()->SetNdivisions(6,5,0, kFALSE);
      
      ((TH1D*)(*tfileIt)->Get("PFElecPt"))->GetXaxis()->SetNdivisions(8,10,0, kFALSE);
      ((TH1D*)(*tfileIt)->Get("PFMuonPt"))->GetXaxis()->SetNdivisions(8,10,0, kFALSE);
    */
    
    //((TH1D*)(*tfileIt)->Get("NofMuon"))->GetXaxis()->CenterLabels(kTRUE);
    //((TH1D*)(*tfileIt)->Get("NofMuon"))->SetNdivisions(10);
    
    
    
    //((TH1D*)(*tfileIt)->Get("WlepnuPT_50_100"))->GetXaxis()->SetNdivisions(11,2,0, kFALSE);
    //((TH1D*)(*tfileIt)->Get("ZleplepPT_60_120"))->GetXaxis()->SetNdivisions(4,5,0, kFALSE);
    
    
    
    //((TH1D*)(*tfileIt)->Get("WmunuMT"))->GetXaxis()->SetNdivisions(5,10,0, kFALSE);
    //((TH1D*)(*tfileIt)->Get("ZmumuMT"))->GetXaxis()->SetNdivisions(10,10,0, kFALSE);
    //((TH1D*)(*tfileIt)->Get("ZmumuMT_2"))->GetXaxis()->SetNdivisions(5,10,0, kFALSE);
    
    
    ((TH1D*)(*tfileIt)->Get(histname))->GetYaxis()->SetLabelFont( 42 );
    
    vector<Float_t> ent;
    
    for(int i=1; i<((TH1D*)(*tfileIt)->Get(histname))->GetNbinsX(); i++ )
      {
	ent.push_back( (((TH1D*)(*tfileIt)->Get(histname))->GetBinContent(i)) ); 
      }
    sort(ent.begin(), ent.end());
    reverse(ent.begin(), ent.end());
    
    
    ((TH1D*)(*tfileIt)->Get(histname))->SetMinimum(0.02);
    ((TH1D*)(*tfileIt)->Get(histname))->SetMaximum(ent[0]*1500 );
    
    //cout  << ent[0] << "................" <<  endl;
    
    it++;
  }
  
  p11_1->RedrawAxis(); 
  
  if(legend==true) myLegend.Draw();
  TString filename = histname;
  
  p11_1->SetRightMargin(0.04);
  
  TLatex *text1, *text2, *text3;
  
  text1 = new TLatex(3.570061,23.08044,"CMS Preliminary");
  text1->SetNDC();
  text1->SetTextAlign(13);
  text1->SetX(0.25);
  text1->SetY(0.92);
  //text1->SetX(0.25);
  //text1->SetY(0.99);
  //text1->SetLineWidth(2);
  text1->SetTextFont(42);
  text1->SetTextSizePixels(24);// dflt=28
  text1->Draw();
  
  text2 = new TLatex(3.570061,23.08044,"#sqrt{s} = 8 TeV");
  text2->SetNDC();
  text2->SetTextAlign(13);
  text2->SetX(0.25);
  text2->SetY(0.86);
  //text2->SetLineWidth(2);
  text2->SetTextFont(42);
  text2->SetTextSize(0.040);// dflt=28
  text2->Draw();
  
  
  text3 = new TLatex(3.570061,23.08044,"#intL dt = 19.6 fb^{-1}");
  text3->SetNDC();
  text3->SetTextAlign(13);
  text3->SetX(0.25);
  text3->SetY(0.79);
  //text3->SetLineWidth(2);
  text3->SetTextFont(42);
  text3->SetTextSize(0.040);// dflt=28
  text3->Draw(); 
  
  p11_1->Update();
  
  //if(withScale){
  myCanvas->cd(2);
  TPad* p11_2 = (TPad*) myCanvas->GetPad(2);
  p11_2->SetPad(0.01,0.01,0.99,0.29);
  p11_2->SetBottomMargin(0.3);
  
  char mchis[300], dthis[300];
  sprintf(mchis,mc+".root");
  sprintf(dthis,data+".root");
  TFile f1(mchis);
  TFile f2(dthis);
  TH1D* h1 =(TH1D*) f1.Get(kind);
  TH1D* h2 =(TH1D*) f2.Get(kind);
  Int_t nbinsW = h1->GetNbinsX();
  
  TF1 *h4 =(TF1*) f2.Get(kind);
  double binminX = h4->GetXaxis()->GetXmin();
  double binmaxX = h4->GetXaxis()->GetXmax();
  cout<<binminX<<" "<<binmaxX<<endl;
  TH1D* h3= new TH1D("h3",kind,nbinsW,binminX,binmaxX);

  cout<<binminX<<" | "<<binmaxX<<" | "<<nbinsW<<endl;
  
  for(int j=1; j<nbinsW+1; j++  ){  
    double  t1=0. , t2=0.;
    t1= t1+ h1->GetBinContent(j); 
    t2= t2+ h2->GetBinContent(j);
    /* 
       if(t2!=0&&t1!=0){
       if(t2/t1 < 2.)
       {
       h3->SetBinContent(j,t2/t1);
       h3->SetBinError(j,(t2/t1)*sqrt(pow(t2,-1.)+pow(t1,-1)));
       }
       else if(t2/t1 > 2.)
       {
       h3->SetBinContent(j,0.0);
       h3->SetBinError(j,0.0);
       }
       }
       else if(t2==0||t1==0)
       {
       h3->SetBinContent(j,0.0);
       h3->SetBinError(j,0.0);
       }
    */
    if(t1==0){
      h3->SetBinContent(j,-99.);
      h3->SetBinError(j,-99.);
    }
    else{
      h3->SetBinContent(j,(t2-t1)/t1);
      h3->SetBinError(j,((t2-t1)/t1)*sqrt(pow(t2,-1.)+pow(t1,-1)));
    }
  } 
  //h3->SetMarkerSize(0.7);
  //h3->SetFillColor(kRed);
  
  Double_t x[200],y[200],dx[200],dy[200];
  for(Int_t i=0; i<nbinsW; i++){
    x[i]  = binminX+((i+0.5)*(binmaxX-binminX)/nbinsW);
    dx[i] = 0.5*(binmaxX-binminX)/nbinsW;
    y[i]  = h3->GetBinContent(i+1);
    dy[i] = h3->GetBinError(i+1);
  }
  TGraph *gr    = new TGraphErrors(nbinsW,x,y);
  gr->SetMarkerSize(0.7);
  TGraphErrors *grErr = new TGraphErrors(nbinsW,x,y,dx,dy);
  grErr->SetFillColor(kGray);
  grErr->SetFillStyle(3001);
  grErr->SetMarkerSize(0.);
  
  h3->GetXaxis()->SetTitle(titlex.c_str());
  h3->GetXaxis()->SetTitleSize(0.11);
  h3->GetXaxis()->SetLabelSize(0.11);
  h3->GetXaxis()->SetTitleOffset(1.20);
  h3->GetXaxis()->SetLabelOffset(0.02);
  
  h3->GetYaxis()->SetTitle("#frac{Data - MC}{MC}");
  h3->GetYaxis()->CenterTitle();
  h3->GetYaxis()->SetTitleSize(0.10);
  h3->GetYaxis()->SetLabelSize(0.08);
  h3->GetYaxis()->SetTitleOffset(0.6);
  h3->GetYaxis()->SetRangeUser(-2.5,2.5);
  h3->GetYaxis()->SetNdivisions(6);
  //h3->SetTickLength(-0.08, "x"); 
  h3->SetStats(0); 
  h3->SetTitle("");
  TH1D* h3Axis = (TH1D*) h3->Clone("h3Axis");
  h3Axis->Draw("AXIS");
  TF1 *fa1 = new TF1("fa1","0",binminX,binmaxX);
  grErr->Draw("e2");
  fa1->Draw("same");
  gr->Draw("p");
  //h3->Draw("p,same");
  
  p11_2->SetGridx();
  p11_2->SetGridy();
  p11_2->SetRightMargin(0.04);
  //p11_2->RedrawAxis(); 
  p11_2->Update();
  //}
  
  TString outFileName = "output.root";
  
  TFile* rootFile = new TFile(outFileName,"update");
  rootFile->cd();
  
  myCanvas->Write();
  myCanvas->SaveAs(dirname_+ filename+".eps");
  
  //myCanvas->SaveAs("/afs/fnal.gov/files/home/room2/vergili/public_html/ANALYSIS/MET/"+filename+".gif");
  
}

