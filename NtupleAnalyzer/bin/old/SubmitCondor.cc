// ROOT includes
#include <TStyle.h>
#include <TROOT.h>

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
	if ( argc < 4 ) 
	{
		cerr << "Program need more than this parameter " << endl;
		cerr << "Example:  SubmitCondor  wjets   AnaMonoJet   isMC(0 or 1)   mode(cuteff or cutorder) " << endl;
		return 1;
	}

	string conout    = Constants::condorOutDir;
	string conbin    = Constants::condorBin; 

	string mode = argv[4];
	
	if( mode =="cutorder")
	{

		ofstream file1;
		file1.open( argv[1] );


		file1 << "universe = vanilla"  << endl;
		file1 << "Executable =" << conbin << argv[2]  << endl;
		file1 << "Arguments =" << argv[1]   << "  1000000000  "  << argv[3] << " " << argv[2]  <<  endl;  
		file1 << "Requirements = Memory >= 199 &&OpSys == \"LINUX\"&& (Arch != \"DUMMY\" )" << endl;
		file1 << "Should_Transfer_Files = YES"<< endl;
		file1 << "WhenToTransferOutput = ON_EXIT"<< endl;
		file1 << "getenv = true"<< endl;
		file1 << "initialdir =" <<  conout   << endl;
		file1 << "Output     =" <<  conout << argv[1]  << "_$(Cluster)_$(Process).out"<< endl;
		file1 << "Error      =" <<  conout << argv[1]  << "_$(Cluster)_$(Process).err"<< endl;
		file1 << "Log        =" <<  conout << argv[1]  << "_$(Cluster)_$(Process).log"<< endl;
		file1 << "notify_user = "<< endl;
		file1 << "Queue 1"<< endl;
		
	
		file1.close();
	
		string cmd = "condor_submit ";
		cmd += argv[1];
	
	
		system( cmd.c_str() );


	}
	else if( mode== "cuteff")
	{

		for(int i=0; i<9; i++)
		{
			ofstream file1;
			file1.open( argv[1] );
	
			file1 << "universe = vanilla"  << endl;
			file1 << "Executable =" << conbin << argv[2]  << endl;
			file1 << "Arguments ="  <<  argv[1]   << "  1000000000  "  << i << " " <<  argv[3]  << " " << argv[2]  <<  endl;  
			file1 << "Requirements = Memory >= 199 &&OpSys == \"LINUX\"&& (Arch != \"DUMMY\" )" << endl;
			file1 << "Should_Transfer_Files = YES"<< endl;
			file1 << "WhenToTransferOutput = ON_EXIT"<< endl;
			file1 << "getenv = true"<< endl;
			file1 << "initialdir =" <<  conout   << endl;
			file1 << "Output     =" <<  conout  << argv[1]  << "_$(Cluster)_$(Process).out"<< endl;
			file1 << "Error      =" <<  conout  << argv[1]  << "_$(Cluster)_$(Process).err"<< endl;
			file1 << "Log        =" <<  conout  << argv[1]  << "_$(Cluster)_$(Process).log"<< endl;
			file1 << "notify_user = "<< endl;
			file1 << "Queue 1"<< endl;	
		
			file1.close();
		
			string cmd = "condor_submit ";
			cmd += argv[1];
		
		
			system( cmd.c_str() );

		}
	}


}

