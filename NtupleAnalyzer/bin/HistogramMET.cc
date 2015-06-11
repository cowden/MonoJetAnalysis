#include "Operation.h"
#include "HistogramMET.h"
#include <iostream>
#include <fstream>

#include <TH1D.h>
#include <TH2D.h>
#include <math.h>
#include <TLorentzVector.h>

#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/deltaPhi.h"

using namespace std;
using namespace Operation;

namespace HistogramMET 
{
  //----------------METAnalysis Histograms  Defination--------------------------------------------------------------------
  hMETAna::hMETAna(const std::string & fileName):
    mFileName(fileName)
  {
    fileOut = new TFile(mFileName.c_str(),"recreate");
    histo1D["Met0"]           = new TH1D("Met0","MET (No XY Correction) ",400,0,2000);
    histo1D["Met1"]           = new TH1D("Met1","MET (XY Correction, MET Group)",400,0,2000);
    histo1D["Met2"]           = new TH1D("Met2","MET (XY Correction, Monojet)",400,0,2000); 

    histo1D["MetLep0"]        = new TH1D("MetLep0","MET (No XY Correction) ",400,0,2000);
    histo1D["MetLep1"]        = new TH1D("MetLep1","MET (XY Correction, MET Group)",400,0,2000);
    histo1D["MetLep2"]        = new TH1D("MetLep2","MET (XY Correction, Monojet)",400,0,2000);
    
    histo1D["MetPhi0"]        = new TH1D("MetPhi0","METPhi (No XY Correction) ",100, -4, 4);
    histo1D["MetPhi1"]        = new TH1D("MetPhi1","METPhi (XY Correction, MET Group)",100, -4, 4);
    histo1D["MetPhi2"]        = new TH1D("MetPhi2","METPhi (XY Correction, Monojet)",100, -4, 4);

    histo1D["MetLepPhi0"]     = new TH1D("MetLepPhi0","METnoLepPhi (No XY Correction) ",100, -4, 4);
    histo1D["MetLepPhi1"]     = new TH1D("MetLepPhi1","METnoLepPhi (XY Correction, MET Group)",100, -4, 4);
    histo1D["MetLepPhi2"]     = new TH1D("MetLepPhi2","METnoLepPhi (XY Correction, Monojet)",100, -4, 4);
    
    histo2D["Hist_MetNvtx_X"] = new TH2D("Hist_MetNvtx_X","Nvtx - E^{miss}_{x}", 40, 1, 41, 100, -500., 500.);
    histo2D["Hist_MetNvtx_Y"] = new TH2D("Hist_MetNvtx_Y","Nvty - E^{miss}_{y}", 40, 1, 41, 100, -500., 500.);

    histo2D["Hist_MetLepNvtx_X"] = new TH2D("Hist_MetLepNvtx_X","Nvtx - E^{miss_noMu}_{x}", 40, 1, 41, 100, -500., 500.);
    histo2D["Hist_MetLepNvtx_Y"] = new TH2D("Hist_MetLepNvtx_Y","Nvty - E^{miss_noMu}_{y}", 40, 1, 41, 100, -500., 500.);
    
    histo1D["Hist_MetNvtx_X_Proj"];
    histo1D["Hist_MetNvtx_Y_Proj"];

    histo1D["Hist_MetLepNvtx_X_Proj"];
    histo1D["Hist_MetLepNvtx_Y_Proj"];
  }
  
  
  // ---------------METANalysis Histograms Filling------------------------------------------------------------------------
  bool hMETAna::Process(EventData & ev) 
  {
    // Variables
    double w = ev.Weight();
    int    t = ev.MetType();
    double metTemp_px;
    double metTemp_py; 
    double metLep_px;
    double metLep_py; 
    
    // Count good vertices
    int countNPV = 0;
    for(int i = 0; i<ev.NPV(); i++){
      if(ev.PVndof(i)<4.) continue;
      if(ev.PVchi2(i)<=0.) continue;
      if(ev.PVntracks(i)<=0.) continue;
      if(abs(ev.PVz(i))>=24) continue;
      if(sqrt(ev.PVx(i)*ev.PVx(i) + ev.PVy(i)*ev.PVy(i))>2.) continue;
      countNPV++;
    }
    //std::cout<<"NPV = "<<ev.NPV()<<", Good PV = "<<countNPV<<std::endl;
    

    // MET (Lepton included)
    histo1D["Met0"]->Fill(ev.MetPt(t), w); 
    histo1D["MetPhi0"]->Fill(ev.MetPhi(t), w);
    histo2D["Hist_MetNvtx_X"]->Fill(countNPV, ev.MetPx(t), w);
    histo2D["Hist_MetNvtx_Y"]->Fill(countNPV, ev.MetPy(t), w);
    //
    if(!ev.IsMC()){
      metTemp_px = ev.MetPx(t) - (+0.2661 + 0.3217*countNPV);
      metTemp_py = ev.MetPy(t) - (-0.2251 - 0.1747*countNPV);
    }
    else{
      metTemp_px = ev.MetPx(t) - (+0.1166 + 0.0200*countNPV);
      metTemp_py = ev.MetPy(t) - (+0.2764 - 0.1280*countNPV);
    }
    histo1D["Met1"]->Fill(sqrt(metTemp_px*metTemp_px + metTemp_py*metTemp_py),w);
    histo1D["MetPhi1"]->Fill(atan2(metTemp_py,metTemp_px),w);
    
    
    //METnoLep
    metLep_px = ev.MetPx(t);
    metLep_py = ev.MetPy(t);
    if(ev.MetType()>9){  // pf or tc Met
      for(int i=0; i<ev.NPFLep(); i++ ){
	if(PFLepTightCuts(ev,i)){
	  metLep_px += ev.PFLepPx(i);
	  metLep_py += ev.PFLepPy(i);
	}
      }
    }
    histo1D["MetLep0"]->Fill(sqrt(metLep_px*metLep_px + metLep_py*metLep_py), w);
    histo1D["MetLepPhi0"]->Fill(atan2(metLep_py,metLep_px), w);
    histo2D["Hist_MetLepNvtx_X"]->Fill(countNPV, metLep_px, w);
    histo2D["Hist_MetLepNvtx_Y"]->Fill(countNPV, metLep_py, w);
    //
    if(!ev.IsMC()){
      metTemp_px = metLep_px - (+0.2661 + 0.3217*countNPV);
      metTemp_py = metLep_py - (-0.2251 - 0.1747*countNPV);
    }
    else{
      metTemp_px = metLep_px - (+0.1166 + 0.0200*countNPV);
      metTemp_py = metLep_py - (+0.2764 - 0.1280*countNPV);
    }
    histo1D["MetLep1"]->Fill(sqrt(metTemp_px*metTemp_px + metTemp_py*metTemp_py),w);
    histo1D["MetLepPhi1"]->Fill(atan2(metTemp_py,metTemp_px),w);

    
     
    //
    return true;
  }
  
  std::ostream& hMETAna::Description(std::ostream &ostrm) 
  {
    ostrm << "  METAnalysis (output in " << mFileName << "):";
    return ostrm;
  }
  
  //--------------METAnalysis End Job-----------------------------------------------------------------------------------
  hMETAna::~hMETAna() 
  {
    fileOut->Write();
    delete fileOut;	
  }
  
  ///============================================================================================================================================

}

