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
  
  
  
  string logFileName = anaout + "/";
  logFileName += argv[1];
  logFileName += ".log";
  
  Manager manager(logFileName);
  
  
  
  string histFile = anaout + "/";
  histFile += argv[1];
  
  
  
  cout << "Starting to Run ........" << endl;
  
  
  //---------------------------------------CUTS & Fill Hist--------------------------------------------------------------
  
  vector<int> abrun;
  vector<int> abevt;
  
  
  CutHLT             CHLT(0);  manager.Add(&CHLT);
  CutAbnormalEvents  CAbnormalEvents(abrun , abevt);  manager.Add(&CAbnormalEvents);
  hTauAnalysis       TauAnalysis0(histFile+"_AnaTau_0.root"); manager.Add(&TauAnalysis0);   

  
  CutMet             CMet(250); manager.Add(&CMet);
  hTauAnalysis       TauAnalysis1(histFile+"_AnaTau_1.root"); manager.Add(&TauAnalysis1); 
  
  
  CutNoiseClean      CNoiseClean( 0.95 , 0.98, 1,  0.01, 0.99); manager.Add(&CNoiseClean);
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
  hTauAnalysis       TauAnalysis2(histFile+"_AnaTau_2.root"); manager.Add(&TauAnalysis2);
  
  
  CutJet1            CJet1(110 , 2.4,  0.02, 0.98); manager.Add(&CJet1);
  //CutJet2            CJet20(30,4.7); manager.Add(&CJet20);
  hTauAnalysis       TauAnalysis3(histFile+"_AnaTau_3.root"); manager.Add(&TauAnalysis3);
  
  
  CutNJet            CNJet(3); manager.Add(&CNJet);
  hTauAnalysis       TauAnalysis4(histFile+"_AnaTau_4.root"); manager.Add(&TauAnalysis4);
  
  
  CutDeltaPhi3       CDeltaPhi3(2.5);  manager.Add(&CDeltaPhi3);
  hTauAnalysis       TauAnalysis5(histFile+"_AnaTau_5.root"); manager.Add(&TauAnalysis5);
  
  
  NoPFMuon           CNoPFMuon(10., 66.);  manager.Add(&CNoPFMuon); // no cut on eta
  hTauAnalysis       TauAnalysis6(histFile+"_AnaTau_6.root"); manager.Add(&TauAnalysis6);
  
  
  NoPFElec           CNoPFElec(10., 66.);  manager.Add(&CNoPFElec); // no cut on eta
  hTauAnalysis       TauAnalysis7(histFile+"_AnaTau_7.root"); manager.Add(&TauAnalysis7);
  
  
  //CutTIV             CTIV(0.01); manager.Add(&CTIV);	
  //CutTau             CTau(1,1); manager.Add(&CTau);
  hTauAnalysis       TauAnalysis8(histFile+"_AnaTau_8.root"); manager.Add(&TauAnalysis8);
  
  
  CutMet             CMet2(250); manager.Add(&CMet2);
  //CutJet1            CJet2(250 , 2.4,  0.02, 0.98); manager.Add(&CJet2);
  hTauAnalysis       TauAnalysis9(histFile+"_AnaTau_9.root"); manager.Add(&TauAnalysis9);

  
  CutMet             CMet3(300); manager.Add(&CMet3);
  //CutJet1            CJet3(300 , 2.4,  0.02, 0.98); manager.Add(&CJet3);
  hTauAnalysis       TauAnalysis10(histFile+"_AnaTau_10.root"); manager.Add(&TauAnalysis10);
  
  
  CutMet             CMet4(350); manager.Add(&CMet4);
  //CutJet1            CJet4(350 , 2.4,  0.02, 0.98); manager.Add(&CJet4);
  hTauAnalysis       TauAnalysis11(histFile+"_AnaTau_11.root"); manager.Add(&TauAnalysis11);
  
  
  CutMet             CMet5(400); manager.Add(&CMet5); 
  //CutJet1            CJet5(400 , 2.4,  0.02, 0.98); manager.Add(&CJet5);
  hTauAnalysis       TauAnalysis12(histFile+"_AnaTau_12.root"); manager.Add(&TauAnalysis12);
 
  
  CutMet             CMet6(450); manager.Add(&CMet6);
  //CutJet1            CJet6(450 , 2.4,  0.02, 0.98); manager.Add(&CJet6);
  hTauAnalysis       TauAnalysis13(histFile+"_AnaTau_13.root"); manager.Add(&TauAnalysis13);
  
  
  CutMet             CMet7(500); manager.Add(&CMet7); 
  //CutJet1            CJet7(500 , 2.4,  0.02, 0.98); manager.Add(&CJet7);
  hTauAnalysis       TauAnalysis14(histFile+"_AnaTau_14.root"); manager.Add(&TauAnalysis14);
  
  
  CutMet             CMet8(550); manager.Add(&CMet8);
  //CutJet1            CJet8(550 , 2.4,  0.02, 0.98); manager.Add(&CJet8);
  hTauAnalysis       TauAnalysis15(histFile+"_AnaTau_15.root"); manager.Add(&TauAnalysis15);
  
  //-------------------------------------------------------------------------------------------------------------------------
  
  cout << "Running over sample " << argv[1] << endl;
  
  
  EventData eventData(argv[1], nev, isMC);
  
  // Loop over events
  manager.Run(eventData);
}
