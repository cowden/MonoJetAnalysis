// ROOT includes
#include <TStyle.h>
#include <TROOT.h>
#include <TSystem.h>

// std includes
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include "TH1D.h"


#include <TString.h>
#include <TFile.h>

#include "Histogram01.h"
#include "Histogram02.h"
#include "Constants.h"


using namespace Histogram01;
using namespace Histogram02;
using namespace Constants;
using namespace std;


int main(int argc, char ** argv)
{
	if ( argc < 2 ) 
	{
		cerr << "Program need more than this parameter " << endl;
		cerr << "Example:  Limit  eff  seff  " << endl;
		return 1;
	}

	gSystem->SetIncludePath("-I$ROOFITSYS/include");	
	gROOT->ProcessLine(".L /uscms_data/d2/vergili/jan/CMSSW_4_2_8_patch7/src/StatisticalTools/RooStatsRoutines/root/roostats_cl95.C+");


	float  ilum , slum , eff, seff, bck, sbck, n;

	ilum = 4969.;
	slum = 179.; 
	bck = 1224.6;
	sbck = 101.;
	n = 1142.;

	sscanf(argv[1], "%f", &eff);
	sscanf(argv[2], "%f", &seff);


	
	roostats_limit(ilum, slum, eff, seff, bck, sbck, n, false, 1, "cls", "", 123456); 






}

