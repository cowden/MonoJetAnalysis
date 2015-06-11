////////////////////////////////////////////////////////////////////////////
//            nTuple Analysis Macro                                       //
////////////////////////////////////////////////////////////////////////////

#include "EventData.h"
#include "Operation.h"
#include "Histogram01.h"
#include "Histogram02.h"
#include "Constants.h"

// ROOT includes
#include <TStyle.h>
#include <TROOT.h>

// std includes
#include <fstream>
#include <string>

using namespace Operation;
using namespace Histogram01;
using namespace Histogram02;
using namespace Constants;
using namespace std;

// Define the output directory

int main(int argc, char ** argv) 
{  
  if(argc < 6){
    cerr << "Program need more than this parameter " << endl;
    cerr << "Example:   Analysis  sampleName(ex:wjets or met or ...)   maxEvents   isMC(0 or 1)   cuts(jet,met,jetmet)   folder(./results/...)" << endl;
    return 1;
  }
  
  //cout<<"argc = "<<argc<<" | argv[0] = "<<argv[0]<<", argv[4] = "<<argv[4]<<endl;
  
  string anaout = Constants::outputDir; 
  anaout += "results/";
  anaout += argv[5];
  
  int varycutIndex = 0;
  string varycut = "";
  varycut += argv[4];
  if(varycut.find("met") != std::string::npos || varycut.find("Met") != std::string::npos || varycut.find("MET") != std::string::npos)
    varycutIndex += 1;
  if(varycut.find("jet") != std::string::npos || varycut.find("Jet") != std::string::npos || varycut.find("JET") != std::string::npos)
    varycutIndex += 2;
  if(varycutIndex<=0){
    cerr << "Check the defined cuts. It should be [jet,met,jetmet]" << endl;
    return 1;
  }
  
  int  isMC;
  sscanf(argv[3], "%d", &isMC);
  
  int nev;
  if ( argc >= 3 ) sscanf ( argv[2], "%d", &nev );
  else nev = 100000000;
  
  std::string logFileName = anaout + "/";
  logFileName += argv[1];
  logFileName += ".log";
  
  Manager manager(logFileName);
  
  string histFile = anaout + "/";
  histFile += argv[1];
  
  cout << "Starting to Run ........" << endl;
  cout << "Vary cuts by ";
  if(varycutIndex==1) cout<<"MET"; 
  if(varycutIndex==2) cout<<"Jet";
  if(varycutIndex==3) cout<<"JetMET";
  cout<<endl;
  
  //---------------------------------------CUTS & Fill Hist--------------------------------------------------------------
  
  vector<int> abrun;
  vector<int> abevt;
  
  
  CutHLT CHLT0(0);   // Primary vertex
  CutHLT CHLT1(1);   // HLT
  CutAbnormalEvents CAbnormalEvents(abrun, abevt); 
  manager.Add(&CHLT1);
  manager.Add(&CHLT0);                                          
  manager.Add(&CAbnormalEvents);
  hTauAnalysis TauAnalysis0(histFile+"_AnaTau_0.root"); 
  manager.Add(&TauAnalysis0);   
  
  
  CutMet CMet(250); 
  manager.Add(&CMet);
  hTauAnalysis TauAnalysis1(histFile+"_AnaTau_1.root"); 
  manager.Add(&TauAnalysis1); 
  
  
  CutNoiseClean CNoiseClean( 0.95 , 0.98, 1,  0.01, 0.99); 
  manager.Add(&CNoiseClean); 
  CutHLT CHLT2(2);   // No scraping
  CutHLT CHLT3(3);   // HBHE
  CutHLT CHLT4(4);   // CSC Tight Halo
  CutHLT CHLT5(5);   // CSC Loose Halo [Don't use]
  CutHLT CHLT6(6);   // HCAL Laser
  CutHLT CHLT7(7);   // ECal Dead Cell
  CutHLT CHLT8(8);   // Tracking failure
  CutHLT CHLT9(9);   // eeBadSc
  CutHLT CHLT10(10); // Muon greedy [Don't use]
  CutHLT CHLT11(11); // ECal Laser
  CutHLT CHLT12(12); // Trk POG
  CutHLT CHLT13(13); // HCal Laser 2012
  /*
    manager.Add(&CHLT2);    //No scraping
    manager.Add(&CHLT3);    //HBHE
    manager.Add(&CHLT4);    //CSC Tight Halo
    //manager.Add(&CHLT5);  //CSC Loose Halo [Don't use]
    manager.Add(&CHLT6);    //HCAL Laser
    manager.Add(&CHLT7);    //ECal Dead Cell
    manager.Add(&CHLT8);    //Tracking failure
    manager.Add(&CHLT9);    //eeBadSc
    //manager.Add(&CHLT10); //Muon greedy [Don't use]
    manager.Add(&CHLT11);   //ECal Laser
    manager.Add(&CHLT12);   //Trk POG
    manager.Add(&CHLT13);   //HCal Laser 2012
  */
  hTauAnalysis TauAnalysis2(histFile+"_AnaTau_2.root");
  manager.Add(&TauAnalysis2);
  
  
  CutJet1 CJet1(110 , 2.4,  0.02, 0.98);
  manager.Add(&CJet1);
  //CutJet2 CJet20(30,4.7);
  //manager.Add(&CJet20);
  hTauAnalysis TauAnalysis3(histFile+"_AnaTau_3.root");
  manager.Add(&TauAnalysis3);
  
  
  CutNJet CNJet(3);
  manager.Add(&CNJet);
  hTauAnalysis TauAnalysis4(histFile+"_AnaTau_4.root");
  manager.Add(&TauAnalysis4);
  
  
  CutDeltaPhi3 CDeltaPhi3(2.5);
  manager.Add(&CDeltaPhi3);
  hTauAnalysis TauAnalysis5(histFile+"_AnaTau_5.root");
  manager.Add(&TauAnalysis5);
  
  
  NoPFMuon CNoPFMuon(10., 66.);
  manager.Add(&CNoPFMuon); // no cut on eta
  hTauAnalysis TauAnalysis6(histFile+"_AnaTau_6.root");
  manager.Add(&TauAnalysis6);
  
  
  NoPFElec CNoPFElec(10., 66.);
  manager.Add(&CNoPFElec); // no cut on eta
  hTauAnalysis TauAnalysis7(histFile+"_AnaTau_7.root");
  manager.Add(&TauAnalysis7);
  
  
  //CutTIV  CTIV(0.01); 
  //manager.Add(&CTIV);	
  //CutTau CTau(1,1);
  //manager.Add(&CTau);
  hTauAnalysis TauAnalysis8(histFile+"_AnaTau_8.root");
  manager.Add(&TauAnalysis8);
  
  
  CutMet   CMet2(250);
  CutJet1  CJet2(250, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet2);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet2);
  } 
  hTauAnalysis TauAnalysis9(histFile+"_AnaTau_9.root");
  manager.Add(&TauAnalysis9);
  
  
  CutMet   CMet3(300);
  CutJet1  CJet3(300, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet3);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet3);
  }
  hTauAnalysis TauAnalysis10(histFile+"_AnaTau_10.root");
  manager.Add(&TauAnalysis10);
  
  
  CutMet  CMet4(350);
  CutJet1 CJet4(350 , 2.4,  0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet4);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet4);
  }
  hTauAnalysis TauAnalysis11(histFile+"_AnaTau_11.root");
  manager.Add(&TauAnalysis11);
  
  
  CutMet   CMet5(400);
  CutJet1  CJet5(400, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet5);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet5);
  }
  hTauAnalysis TauAnalysis12(histFile+"_AnaTau_12.root"); 
  manager.Add(&TauAnalysis12);
 
  
  CutMet  CMet6(450);
  CutJet1 CJet6(450, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet6);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet6);
  }
  hTauAnalysis TauAnalysis13(histFile+"_AnaTau_13.root");
  manager.Add(&TauAnalysis13);
  
   
  CutMet  CMet7(500);
  CutJet1 CJet7(500, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet7);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet7);
  }
  hTauAnalysis TauAnalysis14(histFile+"_AnaTau_14.root");
  manager.Add(&TauAnalysis14);
  
  
  CutMet  CMet8(550);
  CutJet1 CJet8(550 , 2.4,  0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet8);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet8);
  }
  hTauAnalysis TauAnalysis15(histFile+"_AnaTau_15.root");
  manager.Add(&TauAnalysis15);
  
  //-------------------------------------------------------------------------------------------------------------------------
  
  cout << "Running over sample " << argv[1] << endl;
  
  EventData eventData(argv[1], nev, isMC);
  
  // Loop over events
  manager.Run(eventData);
}
