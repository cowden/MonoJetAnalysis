// ROOT includes
#include <TStyle.h>
#include <TROOT.h>

// std includes
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "tdrStyle.C"

#include "MergePlots.h"

using namespace std;

// Define the output directory
const std::string outputDir = "";

int main(int argc, char ** argv) 
{
	if ( argc < 5 ) 
	{
		cerr << "Insufficient arguments: [histogram name] [dataset1] [dataset2...]" << endl;
		return 1;
	}
	
	cout << "Starting extractor..." << endl;
	// Set up root
	//gROOT->SetStyle("Plain"); 
	//gStyle->SetOptStat(kFALSE);  
	//gStyle->SetPalette(0);
	setTDRStyle();

	// Initialise plot merger class
	MergePlots theMergedPlots(outputDir);
	
	// Get the dataSet names from the input arguments
	std::string dsname;
	for (int i=6; i<argc; i=i+2) 
	{
		dsname = argv[i];
		theMergedPlots.addDataSet(dsname, argv[i+1]);
	}
	
	// Merge the requested histograms into the one plot and produce the graphics file
	//theMergedPlots.mergeHist(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], true);
	theMergedPlots.mergeHist(argv[1], argv[2], argv[3], argv[1], argv[4], argv[5], true, "", true);
	
	gPad->SetTicks();
	gPad->Update();

} // end of main function
