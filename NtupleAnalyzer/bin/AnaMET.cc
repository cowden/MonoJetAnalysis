////////////////////////////////////////////////////////////////////////////
//            nTuple Analysis Macro                                       //
////////////////////////////////////////////////////////////////////////////

#include "EventData.h"
#include "Operation.h"
#include "Histogram01.h"
#include "Histogram02.h"
#include "HistogramMET.h"
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
using namespace HistogramMET;
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
  
  CutAbnormalEvents  CAbnormalEvents(abrun , abevt);  manager.Add(&CAbnormalEvents);
  hMETAna            METAnalysis0(histFile+"_AnaMET_0.root"); manager.Add(&METAnalysis0);  
  
  //CutHLT           CHLT(0); manager.Add(&CHLT);
  CutNoiseClean      CNoiseClean( 0.95 , 0.98, 1,  0.01, 0.99); manager.Add(&CNoiseClean);
  hMETAna            METAnalysis1(histFile+"_AnaMET_1.root"); manager.Add(&METAnalysis1);
  
  CutJet1            CJet1( 110 , 2.4,  0.02, 0.98); manager.Add(&CJet1);
  hMETAna            METAnalysis2(histFile+"_AnaMET_2.root"); manager.Add(&METAnalysis2);
  
  CutNJet            CNJet(3); manager.Add(&CNJet);
  hMETAna            METAnalysis3(histFile+"_AnaMET_3.root"); manager.Add(&METAnalysis3);
  
  CutDeltaPhi3       CDeltaPhi3(2.5);  manager.Add(&CDeltaPhi3);
  hMETAna            METAnalysis4(histFile+"_AnaMET_4.root"); manager.Add(&METAnalysis4);
  
  NoPFMuon           CNoPFMuon(10., 66.);  manager.Add(&CNoPFMuon); // no cut on eta
  hMETAna            METAnalysis5(histFile+"_AnaMET_5.root"); manager.Add(&METAnalysis5);
  
  NoPFElec           CNoPFElec(10., 66.);  manager.Add(&CNoPFElec); // no cut on eta
  hMETAna            METAnalysis6(histFile+"_AnaMET_6.root"); manager.Add(&METAnalysis6);
  
  CutTIV             CTIV(0.01); manager.Add(&CTIV);	
  hMETAna            METAnalysis7(histFile+"_AnaMET_7.root"); manager.Add(&METAnalysis7);

  /*
  CutMet             CMet(200); manager.Add(&CMet);
  hMETAna            METAnalysis8(histFile+"_AnaMET_8.root"); manager.Add(&METAnalysis8);
  
  CutMet             CMet1(250); manager.Add(&CMet1);
  hMETAna            METAnalysis9(histFile+"_AnaMET_9.root"); manager.Add(&METAnalysis9);
  
  CutMet             CMet2(300); manager.Add(&CMet2);
  hMETAna            METAnalysis10(histFile+"_AnaMET_10.root"); manager.Add(&METAnalysis10);
  
  CutMet             CMet3(350); manager.Add(&CMet3);
  ////CutHLT           CHLT(0); manager.Add(&CHLT);
  hMETAna            METAnalysis11(histFile+"_AnaMET_11.root"); manager.Add(&METAnalysis11);
  
  CutMet             CMet4(400); manager.Add(&CMet4);
  hMETAna            METAnalysis12(histFile+"_AnaMET_12.root"); manager.Add(&METAnalysis12);
  
  CutMet             CMet5(450); manager.Add(&CMet5);
  hMETAna            METAnalysis13(histFile+"_AnaMET_13.root"); manager.Add(&METAnalysis13);
  
  CutMet             CMet6(500); manager.Add(&CMet6);
  hMETAna            METAnalysis14(histFile+"_AnaMET_14.root"); manager.Add(&METAnalysis14);
  
  CutMet             CMet7(550); manager.Add(&CMet7);
  hMETAna            METAnalysis15(histFile+"_AnaMET_15.root"); manager.Add(&METAnalysis15);
  */
  
  CutMet             CMet(200,2); manager.Add(&CMet);
  hMETAna            METAnalysis8(histFile+"_AnaMETCorr_8.root"); manager.Add(&METAnalysis8);
  
  CutMet             CMet1(250,2); manager.Add(&CMet1);
  hMETAna            METAnalysis9(histFile+"_AnaMETCorr_9.root"); manager.Add(&METAnalysis9);
  
  CutMet             CMet2(300,2); manager.Add(&CMet2);
  hMETAna            METAnalysis10(histFile+"_AnaMETCorr_10.root"); manager.Add(&METAnalysis10);
  
  CutMet             CMet3(350,2); manager.Add(&CMet3);
  ////CutHLT           CHLT(0); manager.Add(&CHLT);
  hMETAna            METAnalysis11(histFile+"_AnaMETCorr_11.root"); manager.Add(&METAnalysis11);
  
  CutMet             CMet4(400,2); manager.Add(&CMet4);
  hMETAna            METAnalysis12(histFile+"_AnaMETCorr_12.root"); manager.Add(&METAnalysis12);
  
  CutMet             CMet5(450,2); manager.Add(&CMet5);
  hMETAna            METAnalysis13(histFile+"_AnaMETCorr_13.root"); manager.Add(&METAnalysis13);
  
  CutMet             CMet6(500,2); manager.Add(&CMet6);
  hMETAna            METAnalysis14(histFile+"_AnaMETCorr_14.root"); manager.Add(&METAnalysis14);
  
  CutMet             CMet7(550,2); manager.Add(&CMet7);
  hMETAna            METAnalysis15(histFile+"_AnaMETCorr_15.root"); manager.Add(&METAnalysis15);
  
  
  //-------------------------------------------------------------------------------------------------------------------------
  
  cout << "Running over sample " << argv[1] << endl;
  
  
  EventData eventData(argv[1], nev, isMC);
  
  // Loop over events
  manager.Run(eventData);
  
}
