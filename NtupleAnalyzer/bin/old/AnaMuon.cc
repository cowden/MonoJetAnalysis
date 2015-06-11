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
  if ( argc < 3 ) 
    {
      cerr << "Program need more than this parameter " << endl;
      cerr << "Example:   Analysis  sampleName(ex:wjets or met or ...)   maxEvents   isMC(0 or 1)" << endl;
      return 1;
    }
  
  string anaout = Constants::outputDir; 
  anaout += "results/";
  anaout += argv[4];
  
  
  int nev;
  if ( argc >= 3 ) sscanf ( argv[2], "%d", &nev );
  else nev = 100000000;
  
  
  int  isMC;
  sscanf(argv[3], "%d", &isMC);
  
  
  std::string logFileName = anaout + "/";
  logFileName += argv[1];
  logFileName += ".log";
  
  
  Manager manager(logFileName);
  
  
  string histFile = anaout + "/";
  histFile += argv[1];
  
  
  cout << "Starting to Run ........" << endl;
  
  //---------------------------------------CUTS & Fill Hist--------------------------------------------------------------
  
  vector<int> abrun;
  vector<int> abevt;
  
  
  //hWSourceAnalysis WSourceAnalysis(histFile+"_WSource.root"); manager.Add(&WSourceAnalysis);
  //GenParExist CGenParExist(13);     manager.Add(&CGenParExist);
  
  
  CutHLT             CHLT(0);                                            manager.Add(&CHLT);
  CutAbnormalEvents  CAbnormalEvents(abrun , abevt);                     manager.Add(&CAbnormalEvents);
  hDataMcMatching    DataMcMatching0(histFile+"_AnaMuon_0.root");        manager.Add(&DataMcMatching0);
  
  
  CutMet             CMet(250);                                          manager.Add(&CMet);
  hDataMcMatching    DataMcMatching1(histFile+"_AnaMuon_1.root");        manager.Add(&DataMcMatching1);
  
  
  CutNoiseClean      CNoiseClean(0.95 , 0.98, 1,  0.01, 0.99);          manager.Add(&CNoiseClean);
  /*
    CutHLT             CHLT1(1);   manager.Add(&CHLT1);  //HLT
    CutHLT             CHLT2(2);   manager.Add(&CHLT2);  //No scraping
    CutHLT             CHLT3(3);   manager.Add(&CHLT3);  //HBHE
    CutHLT             CHLT4(4);   manager.Add(&CHLT4);  //CSC Tight Halo
    ////CutHLT             CHLT5(5);   manager.Add(&CHLT5); //CSC Loose Halo [Don't use]
    CutHLT             CHLT6(6);   manager.Add(&CHLT6);  //HCAL Laser
    CutHLT             CHLT7(7);   manager.Add(&CHLT7);  //ECal Dead Cell
    CutHLT             CHLT8(8);   manager.Add(&CHLT8);  //Tracking failure
    CutHLT             CHLT9(9);   manager.Add(&CHLT9);  //eeBadSc
    ////CutHLT             CHLT10(10); manager.Add(&CHLT10); //Muon greedy [Don't use]
    CutHLT             CHLT11(11); manager.Add(&CHLT11); //ECal Laser
    CutHLT             CHLT12(12); manager.Add(&CHLT12); //Trk POG
    CutHLT             CHLT13(13); manager.Add(&CHLT13); //HCal Laser 2012
  */
  hWZAnalysis        WZAnalysis0(histFile+"_WZAnalysis_0.root");         manager.Add(&WZAnalysis0);
  hDataMcMatching    DataMcMatching2(histFile+"_AnaMuon_2.root");        manager.Add(&DataMcMatching2);
  
  
  CutJet1            CJet1(110 , 2.4,  0.02, 0.98);                     manager.Add(&CJet1);
  //CutJet2            CJet20(30,4.7); manager.Add(&CJet20);
  hDataMcMatching    DataMcMatching3(histFile+"_AnaMuon_3.root");        manager.Add(&DataMcMatching3);
  
  
  CutNJet            CNJet(3);                                           manager.Add(&CNJet);
  hDataMcMatching    DataMcMatching4(histFile+"_AnaMuon_4.root");        manager.Add(&DataMcMatching4);
  
  
  CutDeltaPhi3       CDeltaPhi3(2.5);                                    manager.Add(&CDeltaPhi3);
  hWSourceAnalysis   WSourceAnalysis(histFile+"_hWSourceAnalysis.root"); manager.Add(&WSourceAnalysis);
  hWZAnalysis        WZAnalysis1(histFile+"_WZAnalysis_1.root");         manager.Add(&WZAnalysis1);
  hDataMcMatching    DataMcMatching5(histFile+"_AnaMuon_5.root");        manager.Add(&DataMcMatching5);
  
  
  //PFLepIso           CPFLepIso(20.);                                     manager.Add( &CPFLepIso );	
  //WsignSelection     CWsignSelection(1.0);                               manager.Add( & CWsignSelection );
  //CutTIV             CTIV(0.01);                                         manager.Add(&CTIV);
  //CutTau             CTau(1,1);                                          manager.Add(&CTau); 
  hWZAnalysis        WZAnalysis2(histFile+"_WZAnalysis_2.root");         manager.Add(&WZAnalysis2);
  hDataMcMatching    DataMcMatching6(histFile+"_AnaMuon_6.root");        manager.Add(&DataMcMatching6);
 
  
  CutMet             CMet2(250);                                         manager.Add(&CMet2);
  //CutJet1            CJet2(250 , 2.4,  0.02, 0.98);                      manager.Add(&CJet2); 
  hWZAnalysis        WZAnalysis3(histFile+"_WZAnalysis_3.root");         manager.Add(&WZAnalysis3);
  hDataMcMatching    DataMcMatching7(histFile+"_AnaMuon_7.root");        manager.Add(&DataMcMatching7);
 
  
  CutMet             CMet3(300);                                         manager.Add(&CMet3);
  //CutJet1            CJet3(300 , 2.4,  0.02, 0.98);                      manager.Add(&CJet3); 
  hWZAnalysis        WZAnalysis4(histFile+"_WZAnalysis_4.root");         manager.Add(&WZAnalysis4);
  hDataMcMatching    DataMcMatching8(histFile+"_AnaMuon_8.root");        manager.Add(&DataMcMatching8);
  
  
  CutMet             CMet4(350);                                         manager.Add(&CMet4);
  //CutJet1            CJet4(350 , 2.4,  0.02, 0.98);                      manager.Add(&CJet4);
  hWZAnalysis        WZAnalysis5(histFile+"_WZAnalysis_5.root");         manager.Add(&WZAnalysis5);
  hDataMcMatching    DataMcMatching9(histFile+"_AnaMuon_9.root");        manager.Add(&DataMcMatching9);
  
  
  CutMet             CMet5(400);                                         manager.Add(&CMet5);
  //CutJet1            CJet5(400 , 2.4,  0.02, 0.98);                      manager.Add(&CJet5);
  hWZAnalysis        WZAnalysis6(histFile+"_WZAnalysis_6.root");         manager.Add(&WZAnalysis6);
  hDataMcMatching    DataMcMatching10(histFile+"_AnaMuon_10.root");      manager.Add(&DataMcMatching10);
  
  
  CutMet             CMet6(450);                                         manager.Add(&CMet6);
  //CutJet1            CJet6(450 , 2.4,  0.02, 0.98);                      manager.Add(&CJet6);
  hWZAnalysis        WZAnalysis7(histFile+"_WZAnalysis_7.root");         manager.Add(&WZAnalysis7);
  hDataMcMatching    DataMcMatching11(histFile+"_AnaMuon_11.root");      manager.Add(&DataMcMatching11);
  
  
  CutMet             CMet7(500);                                         manager.Add(&CMet7);
  //CutJet1            CJet7(500 , 2.4,  0.02, 0.98);                      manager.Add(&CJet7); 
  hWZAnalysis        WZAnalysis8(histFile+"_WZAnalysis_8.root");         manager.Add(&WZAnalysis8);
  hDataMcMatching    DataMcMatching12(histFile+"_AnaMuon_12.root");      manager.Add(&DataMcMatching12);
  
  
  CutMet             CMet8(550);                                         manager.Add(&CMet8);
  //CutJet1            CJet8(550 , 2.4,  0.02, 0.98);                      manager.Add(&CJet8); 
  hWZAnalysis        WZAnalysis9(histFile+"_WZAnalysis_9.root");         manager.Add(&WZAnalysis9);
  hDataMcMatching    DataMcMatching13(histFile+"_AnaMuon_13.root");      manager.Add(&DataMcMatching13);
  
  //-------------------------------------------------------------------------------------------------------------------------
  
  cout << "Running over sample " << argv[1] << endl;
  
  EventData eventData(argv[1], nev, isMC); 
  
  // Loop over events
  manager.Run(eventData);
  
}
