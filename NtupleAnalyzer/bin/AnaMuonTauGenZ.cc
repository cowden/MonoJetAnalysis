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
  if (argc < 6){
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
  
  
  //hWSourceAnalysis WSourceAnalysis(histFile+"_WSource.root"); manager.Add(&WSourceAnalysis);
  //GenParExist CGenParExist(13);     manager.Add(&CGenParExist);

  
  CutHLT CHLT0(0);   // Primary vertex
  CutHLT CHLT1(1);   // HLT
  CutAbnormalEvents CAbnormalEvents(abrun, abevt); 
  manager.Add(&CHLT1);
  manager.Add(&CHLT0);                                          
  manager.Add(&CAbnormalEvents);
  hDataMcMatching DataMcMatching0(histFile+"_AnaMuonTauGenZ_0.root");
  manager.Add(&DataMcMatching0);
  hMuonAna MuonAnalysis0(histFile+"_MuonAnalysis_0.root");
  manager.Add(&MuonAnalysis0);
  
  
  GenParExist CGenParExist(23);
  GenParMassWindow CGenParMassWindow(23,60,120);
  GenZmumu CGenZmumu(23);
  manager.Add(&CGenParExist);
  manager.Add(&CGenParMassWindow);
  manager.Add(&CGenZmumu);
  CutMet CMet(250);
  GenParPt CGenZPt(23,250);
  //manager.Add(&CMet);
  manager.Add(&CGenZPt);
  hDataMcMatching DataMcMatching1(histFile+"_AnaMuonTauGenZ_1.root");
  manager.Add(&DataMcMatching1);
  hMuonAna MuonAnalysis1(histFile+"_MuonAnalysis_1.root");
  manager.Add(&MuonAnalysis1);
  
  
  CutNoiseClean CNoiseClean(0.95 , 0.98, 1,  0.01, 0.99);
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
  hWZAnalysis WZAnalysis0(histFile+"_WZTauAnalysis_0.root");
  manager.Add(&WZAnalysis0); 
  hDataMcMatching DataMcMatching2(histFile+"_AnaMuonTauGenZ_2.root");    
  manager.Add(&DataMcMatching2);
  hMuonAna MuonAnalysis2(histFile+"_MuonAnalysis_2.root");    
  manager.Add(&MuonAnalysis2);
  
  
  CutJet1 CJet1(110 , 2.4,  0.02, 0.98);
  manager.Add(&CJet1);
  //CutJet2 CJet20(30,4.7);
  //manager.Add(&CJet20);
  hDataMcMatching DataMcMatching3(histFile+"_AnaMuonTauGenZ_3.root");    
  manager.Add(&DataMcMatching3);
  hMuonAna MuonAnalysis3(histFile+"_MuonAnalysis_3.root");
  manager.Add(&MuonAnalysis3);
  
  
  CutNJet CNJet(3);
  manager.Add(&CNJet);
  hDataMcMatching DataMcMatching4(histFile+"_AnaMuonTauGenZ_4.root");
  manager.Add(&DataMcMatching4);
  hMuonAna MuonAnalysis4(histFile+"_MuonAnalysis_4.root");
  manager.Add(&MuonAnalysis4);
  
  
  CutDeltaPhi3 CDeltaPhi3(2.5);
  manager.Add(&CDeltaPhi3); 
  hWSourceAnalysis WSourceAnalysis(histFile+"_hWSourceAnalysis.root");
  manager.Add(&WSourceAnalysis);
  hWZAnalysis WZAnalysis1(histFile+"_WZTauAnalysis_1.root");
  manager.Add(&WZAnalysis1);
  hDataMcMatching DataMcMatching5(histFile+"_AnaMuonTauGenZ_5.root");
  manager.Add(&DataMcMatching5);
  hMuonAna MuonAnalysis5(histFile+"_MuonAnalysis_5.root");
  manager.Add(&MuonAnalysis5);
  
  
  //PFLepIso CPFLepIso(20.);
  //manager.Add( &CPFLepIso );	
  //WsignSelection CWsignSelection(1.0);
  //manager.Add( & CWsignSelection );
  CutTau CTau(1,1);
  manager.Add(&CTau);
  hWZAnalysis WZAnalysis2(histFile+"_WZTauAnalysis_2.root");
  manager.Add(&WZAnalysis2); 
  hDataMcMatching DataMcMatching6(histFile+"_AnaMuonTauGenZ_6.root");
  manager.Add(&DataMcMatching6);
  hMuonAna MuonAnalysis6(histFile+"_MuonAnalysis_6.root");
  manager.Add(&MuonAnalysis6);
  
  
  CutMet   CMet2(250);
  GenParPt CGenZPt2(23,250);
  CutJet1  CJet2(250, 2.4, 0.02, 0.98);
  //PrintEvent CPrintEvent(0,0,0);
  if(varycutIndex==1 || varycutIndex==3){
    //manager.Add(&CMet2);
    manager.Add(&CGenZPt2);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet2);
  }
  //manager.Add(&CPrintEvent);
  hWZAnalysis WZAnalysis3(histFile+"_WZTauAnalysis_3.root");
  manager.Add(&WZAnalysis3);
  hDataMcMatching DataMcMatching7(histFile+"_AnaMuonTauGenZ_7.root");
  manager.Add(&DataMcMatching7);
  hMuonAna MuonAnalysis7(histFile+"_MuonAnalysis_7.root");
  manager.Add(&MuonAnalysis7);
  
  
  CutMet   CMet3(300); 
  GenParPt CGenZPt3(23,300);
  CutJet1  CJet3(300, 2.4, 0.02, 0.98);  
  if(varycutIndex==1 || varycutIndex==3){
    //manager.Add(&CMet3);
    manager.Add(&CGenZPt3);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet3);
  }
  hWZAnalysis WZAnalysis4(histFile+"_WZTauAnalysis_4.root");
  manager.Add(&WZAnalysis4);
  hDataMcMatching DataMcMatching8(histFile+"_AnaMuonTauGenZ_8.root");
  manager.Add(&DataMcMatching8);
  hMuonAna MuonAnalysis8(histFile+"_MuonAnalysis_8.root");
  manager.Add(&MuonAnalysis8);
  
  
  CutMet   CMet4(350); 
  GenParPt CGenZPt4(23,350);                                      
  CutJet1  CJet4(350, 2.4, 0.02, 0.98); 
  if(varycutIndex==1 || varycutIndex==3){
    //manager.Add(&CMet4);
    manager.Add(&CGenZPt4);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet4);
  }                  
  hWZAnalysis WZAnalysis5(histFile+"_WZTauAnalysis_5.root");
  manager.Add(&WZAnalysis5);
  hDataMcMatching DataMcMatching9(histFile+"_AnaMuonTauGenZ_9.root");   
  manager.Add(&DataMcMatching9);
  hMuonAna MuonAnalysis9(histFile+"_MuonAnalysis_9.root");
  manager.Add(&MuonAnalysis9);
  
  
  CutMet   CMet5(400);
  GenParPt CGenZPt5(23,400);
  CutJet1  CJet5(400, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    //manager.Add(&CMet5);
    manager.Add(&CGenZPt5);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet5);
  }
  hWZAnalysis WZAnalysis6(histFile+"_WZTauAnalysis_6.root");
  manager.Add(&WZAnalysis6);
  hDataMcMatching DataMcMatching10(histFile+"_AnaMuonTauGenZ_10.root");
  manager.Add(&DataMcMatching10);
  hMuonAna MuonAnalysis10(histFile+"_MuonAnalysis_10.root");
  manager.Add(&MuonAnalysis10);
  
  
  CutMet   CMet6(450);  
  GenParPt CGenZPt6(23,450);                                      
  CutJet1  CJet6(450, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    //manager.Add(&CMet6);
    manager.Add(&CGenZPt6);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet6);
  }                
  hWZAnalysis WZAnalysis7(histFile+"_WZTauAnalysis_7.root");
  manager.Add(&WZAnalysis7);
  hDataMcMatching DataMcMatching11(histFile+"_AnaMuonTauGenZ_11.root");
  manager.Add(&DataMcMatching11);
  hMuonAna MuonAnalysis11(histFile+"_MuonAnalysis_11.root");  
  manager.Add(&MuonAnalysis11);
  
  
  CutMet   CMet7(500);
  GenParPt CGenZPt7(23,500);
  CutJet1  CJet7(500, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    //manager.Add(&CMet7);
    manager.Add(&CGenZPt7);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet7);
  }             
  hWZAnalysis WZAnalysis8(histFile+"_WZTauAnalysis_8.root");
  manager.Add(&WZAnalysis8);
  hDataMcMatching DataMcMatching12(histFile+"_AnaMuonTauGenZ_12.root");  
  manager.Add(&DataMcMatching12);
  hMuonAna MuonAnalysis12(histFile+"_MuonAnalysis_12.root");  
  manager.Add(&MuonAnalysis12);
  
  
  CutMet   CMet8(550);
  GenParPt CGenZPt8(23,550);
  CutJet1  CJet8(550, 2.4, 0.02, 0.98);
  if(varycutIndex==1 || varycutIndex==3){
    //manager.Add(&CMet8);
    manager.Add(&CGenZPt8);
  }
  if(varycutIndex==2 || varycutIndex==3){
    manager.Add(&CJet8);
  }
  hWZAnalysis WZAnalysis9(histFile+"_WZTauAnalysis_9.root");
  manager.Add(&WZAnalysis9);
  hDataMcMatching DataMcMatching13(histFile+"_AnaMuonTauGenZ_13.root");
  manager.Add(&DataMcMatching13); 
  hMuonAna MuonAnalysis13(histFile+"_MuonAnalysis_13.root");
  manager.Add(&MuonAnalysis13);
  
  //-------------------------------------------------------------------------------------------------------------------------
  
  cout << "Running over sample " << argv[1] << endl;
  
  EventData eventData(argv[1], nev, isMC); 
  
  // Loop over events
  manager.Run(eventData);
}
