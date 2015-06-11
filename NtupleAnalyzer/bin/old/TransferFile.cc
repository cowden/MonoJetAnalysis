// ROOT includes
#include <TStyle.h>
#include <TROOT.h>

// std includes
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include "TH1D.h"

#include <TString.h>
#include <TFile.h>

using namespace std;


const std::string outputDir = "";

int main(int argc, char ** argv)
{

	char myls[255];
	char mymkdir[255];
	//char mycd[255];

       

	sprintf(mymkdir,"mkdir %s" , argv[1] );

	sprintf(myls,"ls /pnfs/cms/WAX/resilient/vergili/%s/nt*  > %s.txt" , argv[1], argv[1] );

	system(mymkdir);

	system(myls);

	string  mytxt = argv[1];
	mytxt += ".txt";


	ifstream file;

	file.open( mytxt.c_str()  ,ios::in);

	char line1[255], line2[255], myhadd[255];

	while (!file.eof())
	{
		file >> line1;
		
		sprintf(line2 ,"dc_dccp %s  %s", line1, argv[1]);	

		system(line2);
		
	}

	sprintf(myhadd ,"hadd  %s.root  %s/nt* ",argv[1], argv[1]);

	system(myhadd);
	
}

