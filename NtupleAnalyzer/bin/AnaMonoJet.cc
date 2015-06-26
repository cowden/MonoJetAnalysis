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
  
  
  //PrintEvent         CPrintEvent(0,0,0); manager.Add(&CPrintEvent);
  
  //  no cut on HLT and Noise events  (s.kunori  11-Feb-2015)

  // CutHLT CHLT0(0);   // Primary vertex
  // CutHLT CHLT1(1);   // HLT
  // CutAbnormalEvents CAbnormalEvents(abrun, abevt); 
  // manager.Add(&CHLT1);
  // manager.Add(&CHLT0);                                          
  // manager.Add(&CAbnormalEvents);
  hDataMcMatching DataMcMatching0(histFile+"_AnaMonoJet_0.root"); 
  manager.Add(&DataMcMatching0);
  
  
/*  CutMet CMet(200); 
  manager.Add(&CMet);
  hDataMcMatching DataMcMatching1(histFile+"_AnaMonoJet_1.root"); 
  manager.Add(&DataMcMatching1);
*/
  
  //    drop noise cleaning    s.kunori  11-Feb-2015
  // CutNoiseClean CNoiseClean( 0.95 , 0.98, 1,  0.01, 0.99); 
  // manager.Add(&CNoiseClean); 
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
  hDataMcMatching DataMcMatching2(histFile+"_AnaMonoJet_2.root"); 
  manager.Add(&DataMcMatching2);

  // ------------------------------------------------------------
  // Beginning of the analysis cuts
  GoodVertexCut gvc;
  manager.Add(&gvc);
  hDataMcMatching DataMcMatchingGV(histFile+"_AnaMonoJet_GV.root");
  manager.Add(&DataMcMatchingGV); 
  
  CutJet1 CJet1(110 , 2.5,  0.02, 0.98); 
  manager.Add(&CJet1);
  //CutJet2 CJet20(30,4.7);
  //manager.Add(&CJet20);
  hDataMcMatching DataMcMatching3(histFile+"_AnaMonoJet_3.root"); 
  manager.Add(&DataMcMatching3);
  hHLTEff  HLTEff1(histFile+"_HLTEff1.root"); 
  manager.Add(&HLTEff1);
  
  
/*  CutNJet CNJet(3);
  //manager.Add(&CNJet);
  hDataMcMatching DataMcMatching4(histFile+"_AnaMonoJet_4.root"); 
  manager.Add(&DataMcMatching4);
*/  
  
  CutDeltaPhi3 CDeltaPhi3(2.5);
  manager.Add(&CDeltaPhi3);
  hDataMcMatching DataMcMatching5(histFile+"_AnaMonoJet_5.root"); 
  manager.Add(&DataMcMatching5);
  hHLTEff  HLTEff2(histFile+"_HLTEff2.root");
  manager.Add(&HLTEff2);


  CutMet CMet(200);
  manager.Add(&CMet);
  hDataMcMatching DataMcMatching1(histFile+"_AnaMonoJet_1.root");
  manager.Add(&DataMcMatching1);  


  CutNJet CNJet(3);
  manager.Add(&CNJet);
  hDataMcMatching DataMcMatching4(histFile+"_AnaMonoJet_4.root");
  manager.Add(&DataMcMatching4);
  
  NoPFMuon CNoPFMuon(10., 66.);
  manager.Add(&CNoPFMuon); // no cut on eta
  hDataMcMatching DataMcMatching6(histFile+"_AnaMonoJet_6.root");
  manager.Add(&DataMcMatching6);
  
  
  NoPFElec CNoPFElec(10., 66.);
  manager.Add(&CNoPFElec); // no cut on eta
  hDataMcMatching DataMcMatching7(histFile+"_AnaMonoJet_7.root");
  manager.Add(&DataMcMatching7);
  
  
  CutTau CTau(1,1);
  manager.Add(&CTau);
  hDataMcMatching DataMcMatching8(histFile+"_AnaMonoJet_8.root");
  manager.Add(&DataMcMatching8);  

  
  CutMet   CMet2(250);
  CutJet1  CJet2(250, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet2);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CMet2);
    manager.Add(&CJet2);
  }
  hDataMcMatching DataMcMatching9(histFile+"_AnaMonoJet_9.root"); 
  manager.Add(&DataMcMatching9); 


  CutMet   CMet3(300);
  CutJet1  CJet3(300, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet3);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet3);
  }
  hDataMcMatching DataMcMatching10(histFile+"_AnaMonoJet_10.root"); 
  manager.Add(&DataMcMatching10);
  //PrintEvent CPrintEvent1(0,0,0);
  //manager.Add(&CPrintEvent1);
  
  
  CutMet  CMet4(350);
  CutJet1 CJet4(350 , 2.4,  0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet4);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet4);
  }   
  hDataMcMatching DataMcMatching11(histFile+"_AnaMonoJet_11.root"); 
  manager.Add(&DataMcMatching11);
  
  
  CutMet   CMet5(400);
  CutJet1  CJet5(400, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet5);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet5);
  }
  hDataMcMatching DataMcMatching12(histFile+"_AnaMonoJet_12.root"); 
  manager.Add(&DataMcMatching12);
  
  
  CutMet  CMet6(450);
  CutJet1 CJet6(450, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet6);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet6);
  }     
  hDataMcMatching DataMcMatching13(histFile+"_AnaMonoJet_13.root");
  manager.Add(&DataMcMatching13);
  
  
  CutMet  CMet7(500);
  CutJet1 CJet7(500, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet7);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet7);
  }
  hDataMcMatching DataMcMatching14(histFile+"_AnaMonoJet_14.root");
  manager.Add(&DataMcMatching14);
  
  
  CutMet  CMet8(550);
  CutJet1 CJet8(550 , 2.4,  0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    manager.Add(&CMet8);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet8);
  }
  hDataMcMatching DataMcMatching15(histFile+"_AnaMonoJet_15.root"); 
  manager.Add(&DataMcMatching15);  
  
  //-------------------------------------------------------------------------------------------------------------------------
  
  cout << "Running over sample " << argv[1] << endl;
  
  EventData eventData(argv[1], nev, isMC); 
  
  // Loop over events
  manager.Run(eventData);
}
