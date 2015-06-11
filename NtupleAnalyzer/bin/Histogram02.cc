#include "Operation.h"
#include "Histogram02.h"
#include <iostream>
#include <fstream>

#include <TH1D.h>
#include <math.h>
#include <TLorentzVector.h>

#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/deltaPhi.h"

using namespace std;
using namespace Operation;

namespace Histogram02 
{
  //----------------MuonAnalysis Histograms  Defination--------------------------------------------------------------------
  hMuonAna::hMuonAna(const std::string & fileName):
    mFileName(fileName)
  {
    fileOut = new TFile(mFileName.c_str(),"recreate");
    
    //
    histo1D["Met"]                = new TH1D("Met", "MET", 40, 0, 2000);
    histo1D["MetNoAllMuons"]      = new TH1D("MetNoAllMuons", "MET (exclude all muons)", 40, 0, 2000);
    histo1D["MetNoAllTightMuons"] = new TH1D("MetNoAllTightMuons", "MET (exclude all tight muons)", 40, 0, 2000);

    //
    histo1D["NPFMuon"]         = new TH1D("NPFMuon", "N(PFMuons)", 10, 0, 10);
    histo1D["NPFMuonTightIso"] = new TH1D("NPFMuonTightIso", "N(PFMuon, Tight+Iso)", 10, 0, 10);
    histo1D["NPFMuonLooseIso"] = new TH1D("NPFMuonLooseIso", "N(PFMuon, Loose+Iso)", 10, 0, 10);
    
    //
    histo1D["ZleplepM_60_120_TT_TT_Iso"]  = new TH1D("ZleplepM_60_120_TT_TT_Iso" , "Zleplep m  60<m<120", 30, 60, 120);
    histo1D["ZleplepM_60_120_TT_TL_Iso"]  = new TH1D("ZleplepM_60_120_TT_TL_Iso" , "Zleplep m  60<m<120", 30, 60, 120); 
    histo1D["ZleplepM_60_120_TT_TL_Iso2"] = new TH1D("ZleplepM_60_120_TT_TL_Iso2", "Zleplep m  60<m<120", 30, 60, 120);
    histo1D["ZleplepM_60_120_TL_TL_Iso"]  = new TH1D("ZleplepM_60_120_TL_TL_Iso" , "Zleplep m  60<m<120", 30, 60, 120); 
    histo1D["ZleplepM_60_120_TL_TL_Iso2"] = new TH1D("ZleplepM_60_120_TL_TL_Iso2", "Zleplep m  60<m<120", 30, 60, 120);   
  }
  
  
  // ---------------MuonANalysis Histograms Filling------------------------------------------------------------------------
  bool hMuonAna::Process(EventData & ev) 
  {
    int  t   = ev.MetType(); 
    
    double w = ev.Weight();
    Double_t leptonWeight = 1.;
    bool useOnlyTight = false;
    if(ev.IsMC()>0){
      for(int i=0; i<ev.NPFLep(); i++ ){
	if(useOnlyTight){
	  if(PFLepTightCuts(ev ,i, 20., 2.1)) leptonWeight *= muonWeight(ev.PFLepPt(i),ev.PFLepEta(i));
	}
	else{
	  if(PFLepTightCuts(ev ,i, 20., 2.1) || PFLepLooseCuts(ev ,i, 20., 2.1)) leptonWeight *= muonWeight(ev.PFLepPt(i),ev.PFLepEta(i));
	}
      }
      w *= leptonWeight;
    }
    
    histo1D["Met"]->Fill(ev.MetPt(t));
    histo1D["MetNoAllMuons"]->Fill(MetLepPt(ev.MetPx(t), ev.MetPy(t), ev), w);
    histo1D["MetNoAllTightMuons"]->Fill(MetTightLepPt(ev.MetPx(t), ev.MetPy(t), ev), w);
    
    Int_t countTightIsoMuon = 0;
    Int_t IndexTightIsoMuon[2] = {-99,-99};
    //
    Int_t countLooseIsoMuon = 0;
    Int_t IndexLooseIsoMuon[2] = {-99,-99};
    //
    bool checkAdditional2ndLooseLepton = false;
    
    for(int i=0; i<ev.NPFMuon(); i++){
      if(PFMuonTightCuts(ev, i, 20, 2.1)){
	countTightIsoMuon++;
	if(countTightIsoMuon>2) continue;
	IndexTightIsoMuon[countTightIsoMuon-1]=i;
      }
      if(PFMuonLooseCuts(ev, i, 20, 2.1)){
	countLooseIsoMuon++;
	if(countLooseIsoMuon>2) continue;
	IndexLooseIsoMuon[countLooseIsoMuon-1]=i;
      }
      if(!PFMuonLooseCuts(ev, i, 20, 2.1) && PFMuonLooseCuts(ev, i, 10, 99.)){
	checkAdditional2ndLooseLepton = true;
      }
    }
    histo1D["NPFMuon"]->Fill(ev.NPFMuon(), w);
    histo1D["NPFMuonTightIso"]->Fill(countTightIsoMuon, w);
    histo1D["NPFMuonLooseIso"]->Fill(countLooseIsoMuon, w);
    
    double ZEn,ZPx,ZPy,ZPz,ZPt,ZleplepMT;
    
    // Isolation + Tight/Loose
    if(countTightIsoMuon==2 && countLooseIsoMuon==2 && !checkAdditional2ndLooseLepton){
      ZEn = ev.PFMuonE(IndexTightIsoMuon[0])  + ev.PFMuonE(IndexTightIsoMuon[1]) ;
      ZPx = ev.PFMuonPx(IndexTightIsoMuon[0]) + ev.PFMuonPx(IndexTightIsoMuon[1]);
      ZPy = ev.PFMuonPy(IndexTightIsoMuon[0]) + ev.PFMuonPy(IndexTightIsoMuon[1]);
      ZPz = ev.PFMuonPz(IndexTightIsoMuon[0]) + ev.PFMuonPz(IndexTightIsoMuon[1]);
      ZPt = sqrt(ZPx*ZPx + ZPy*ZPy);	
      ZleplepMT = sqrt((ZEn*ZEn)-(ZPt*ZPt)-(ZPz*ZPz));
      //cout<<"Indices = "<<IndexTightIsoMuon[0]<<", "<<IndexTightIsoMuon[1]<<", Zmass = "<<ZleplepMT<<endl;
      if( ZleplepMT>60 && ZleplepMT<120 ){
	histo1D["ZleplepM_60_120_TT_TT_Iso"]->Fill(ZleplepMT,w);
      }
    }
    if(countTightIsoMuon==1 && countLooseIsoMuon==2 && !checkAdditional2ndLooseLepton){
      ZEn = ev.PFMuonE(IndexLooseIsoMuon[0])  + ev.PFMuonE(IndexLooseIsoMuon[1]) ;
      ZPx = ev.PFMuonPx(IndexLooseIsoMuon[0]) + ev.PFMuonPx(IndexLooseIsoMuon[1]);
      ZPy = ev.PFMuonPy(IndexLooseIsoMuon[0]) + ev.PFMuonPy(IndexLooseIsoMuon[1]);
      ZPz = ev.PFMuonPz(IndexLooseIsoMuon[0]) + ev.PFMuonPz(IndexLooseIsoMuon[1]);
      ZPt = sqrt(ZPx*ZPx + ZPy*ZPy);	
      ZleplepMT = sqrt((ZEn*ZEn)-(ZPt*ZPt)-(ZPz*ZPz)); 
      //cout<<"Indices = "<<IndexLooseIsoMuon[0]<<", "<<IndexLooseIsoMuon[1]<<", Zmass = "<<ZleplepMT<<endl;
      if( ZleplepMT>60 && ZleplepMT<120 ){
	histo1D["ZleplepM_60_120_TT_TL_Iso"]->Fill(ZleplepMT,w);
      }
    }
    //if(countTightIsoMuon==1 && countLooseIsoMuon>2){
    //ZEn = ev.PFMuonE(IndexLooseIsoMuon[0])  + ev.PFMuonE(IndexLooseIsoMuon[1]) ;
    //ZPx = ev.PFMuonPx(IndexLooseIsoMuon[0]) + ev.PFMuonPx(IndexLooseIsoMuon[1]);
    //ZPy = ev.PFMuonPy(IndexLooseIsoMuon[0]) + ev.PFMuonPy(IndexLooseIsoMuon[1]);
    //ZPz = ev.PFMuonPz(IndexLooseIsoMuon[0]) + ev.PFMuonPz(IndexLooseIsoMuon[1]);
    //ZPt = sqrt(ZPx*ZPx + ZPy*ZPy);	
    //ZleplepMT = sqrt((ZEn*ZEn)-(ZPt*ZPt)-(ZPz*ZPz)); 
    ////cout<<"Indices = "<<IndexLooseIsoMuon[0]<<", "<<IndexLooseIsoMuon[1]<<", Zmass = "<<ZleplepMT<<endl;
    //if( ZleplepMT>60 && ZleplepMT<120 ){
    //histo1D["ZleplepM_60_120_TT_TL_Iso2"]->Fill(ZleplepMT,w);
    //}
    //}
    if(countTightIsoMuon==0 && countLooseIsoMuon==2 && !checkAdditional2ndLooseLepton){
      ZEn = ev.PFMuonE(IndexLooseIsoMuon[0])  + ev.PFMuonE(IndexLooseIsoMuon[1]) ;
      ZPx = ev.PFMuonPx(IndexLooseIsoMuon[0]) + ev.PFMuonPx(IndexLooseIsoMuon[1]);
      ZPy = ev.PFMuonPy(IndexLooseIsoMuon[0]) + ev.PFMuonPy(IndexLooseIsoMuon[1]);
      ZPz = ev.PFMuonPz(IndexLooseIsoMuon[0]) + ev.PFMuonPz(IndexLooseIsoMuon[1]);
      ZPt = sqrt(ZPx*ZPx + ZPy*ZPy);	
      ZleplepMT = sqrt((ZEn*ZEn)-(ZPt*ZPt)-(ZPz*ZPz)); 
      //cout<<"Indices = "<<IndexLooseIsoMuon[0]<<", "<<IndexLooseIsoMuon[1]<<", Zmass = "<<ZleplepMT<<endl;
      if( ZleplepMT>60 && ZleplepMT<120 ){
	histo1D["ZleplepM_60_120_TL_TL_Iso"]->Fill(ZleplepMT,w);
      }
    }
    //if(countTightIsoMuon==0 && countLooseIsoMuon>2){
    //ZEn = ev.PFMuonE(IndexLooseIsoMuon[0])  + ev.PFMuonE(IndexLooseIsoMuon[1]) ;
    //ZPx = ev.PFMuonPx(IndexLooseIsoMuon[0]) + ev.PFMuonPx(IndexLooseIsoMuon[1]);
    //ZPy = ev.PFMuonPy(IndexLooseIsoMuon[0]) + ev.PFMuonPy(IndexLooseIsoMuon[1]);
    //ZPz = ev.PFMuonPz(IndexLooseIsoMuon[0]) + ev.PFMuonPz(IndexLooseIsoMuon[1]);
    //ZPt = sqrt(ZPx*ZPx + ZPy*ZPy);	
    //ZleplepMT = sqrt((ZEn*ZEn)-(ZPt*ZPt)-(ZPz*ZPz)); 
    ////cout<<"Indices = "<<IndexLooseIsoMuon[0]<<", "<<IndexLooseIsoMuon[1]<<", Zmass = "<<ZleplepMT<<endl;
    //if( ZleplepMT>60 && ZleplepMT<120 ){
    //histo1D["ZleplepM_60_120_TL_TL_Iso2"]->Fill(ZleplepMT,w);
    //}
    //}
    
    return true;
  }
  
  std::ostream& hMuonAna::Description(std::ostream &ostrm) 
  {
    ostrm << "  MuonAnalysis (output in " << mFileName << "):";
    return ostrm;
  }
  
  
  //--------------MuonAnalysis End Job-----------------------------------------------------------------------------------
  hMuonAna::~hMuonAna() 
  {	
    fileOut->Write();
    delete fileOut;	
  }
}

