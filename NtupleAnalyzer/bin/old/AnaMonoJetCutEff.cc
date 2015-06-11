
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


int main(int argc, char ** argv) 
{
	if ( argc < 5 ) 
	{
		cerr << "Program need more than this parameter " << endl;
		cerr << "Example:  Analysis  sampleName(ex:wjets or met or ...)   maxEvents  cutNumber  isMC(0 or 1)  Analyis" << endl;
		return 1;
	}
	string anaout = Constants::outputDir; 
	anaout += "results/";
	anaout += argv[5];


	int nev;
	if ( argc >= 5 ) sscanf ( argv[2], "%d", &nev );
	else nev = 100000000;
	
	
	int  sel;
	sscanf(argv[3], "%d", &sel);
	string selName = argv[3];
	

	int  isMC;
	sscanf(argv[4], "%d", &isMC);


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
	
	
	CutAbnormalEvents  CAbnormalEvents(abrun , abevt); 
	CutHLT             CHLT(0);
	CutHLT             CHLT1(1);   //HLT
	CutHLT             CHLT2(2);   //No scraping
	CutHLT             CHLT3(3);   //HBHE
	CutHLT             CHLT4(4);   //CSC Tight Halo
	////CutHLT             CHLT5(5);   //CSC Loose Halo [Don't use]
	CutHLT             CHLT6(6);   //HCAL Laser
	CutHLT             CHLT7(7);   //ECal Dead Cell
	CutHLT             CHLT8(8);   //Tracking failure
	CutHLT             CHLT9(9);   //eeBadSc
	////CutHLT             CHLT10(10); //Muon greedy [Don't use]
	CutHLT             CHLT11(11); //ECal Laser
	CutHLT             CHLT12(12); //Trk POG
	CutHLT             CHLT13(13); //HCal Laser 2012
	
	CutNoiseClean      CNoiseClean(0.95 , 0.98, 1,  0.01, 0.99);
	CutJet1            CJet1(110 , 2.4,  0.02, 0.98);
	CutNJet            CNJet(3);
	CutDeltaPhi3       CDeltaPhi3(2.5); 
	CutMet             CMet(250);
	CutTau             CTau(1,1); 
	NoPFMuon           CNoPFMuon(10., 66.);
	NoPFElec           CNoPFElec(10., 66.);
	
	manager.Add(&CAbnormalEvents);
	manager.Add(&CHLT); 
	/*
	  manager.Add(&CHLT1);  //HLT
	  manager.Add(&CHLT2);  //No scraping
	  manager.Add(&CHLT3);  //HBHE
	  manager.Add(&CHLT4);  //CSC Tight Halo
	  ////manager.Add(&CHLT5); //CSC Loose Halo [Don't use]
	  manager.Add(&CHLT6);  //HCAL Laser
	  manager.Add(&CHLT7);  //ECal Dead Cell
	  manager.Add(&CHLT8);  //Tracking failure
	  manager.Add(&CHLT9);  //eeBadSc
	  ////CutHLT             CHLT10(10); manager.Add(&CHLT10); //Muon greedy [Don't use]
	  manager.Add(&CHLT11); //ECal Laser
	  manager.Add(&CHLT12); //Trk POG
	  manager.Add(&CHLT13); //HCal Laser 2012
	*/
	
	if(sel!=1) manager.Add(&CNoiseClean);
	if(sel!=2) manager.Add(&CJet1);
	if(sel!=3) manager.Add(&CNJet);
	if(sel!=4) manager.Add(&CDeltaPhi3);
	if(sel!=5) manager.Add(&CMet);
	if(sel!=6) manager.Add(&CTau);
	if(sel!=7) manager.Add(&CNoPFMuon);
	if(sel!=8) manager.Add(&CNoPFElec);
	
	hDataMcMatching  DataMcMatching(histFile+"_AnaMonoJetCutEff_" +selName + ".root");   manager.Add(&DataMcMatching);


//-------------------------------------------------------------------------------------------------------------------------

	cout << "Running over sample " << argv[1] << endl;

 
	EventData eventData(argv[1], nev, isMC); 




	// Loop over events
	manager.Run(eventData);

}
