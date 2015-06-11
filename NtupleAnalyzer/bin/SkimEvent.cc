//////////////////////////////////////////
//                                      //
//        Mehmet Vergili Nov 2011       //
//      CMS data Skim Event             //
//////////////////////////////////////////

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


	ifstream file1;
	file1.open("SkimList.txt" ,ios::in);
	
	string   run, lumi, event; 

    while (!file1.eof())
	{
		file1 >> run  >>  lumi   >> event;
		
		cout  << "run:"  << run <<  "  lumi:"<< lumi <<  "  evt:" << event  <<  endl; 

		string  line1 = " dbs search --query \"find file  where dataset=";
		line1 += argv[1];
		line1 +=  " and run=";

		line1 += run; 
 		line1 += " and lumi=";
	  	line1 += lumi; 
		line1 += " \"  | grep '^/' >> output"; 

		//file2   << line1 <<  endl; 

		system(line1.c_str() ); 
	}
	file1.close();


	ifstream file3;
	file3.open("output" ,ios::in);

	ofstream file2;
	file2.open("skim.py");

	file2 << "import FWCore.ParameterSet.Config as cms  \n";
	file2 << "process = cms.Process(\"SkimEvents\") \n";
	file2 << "process.load(\"FWCore.MessageService.MessageLogger_cfi\") \n";
	file2 << "process.MessageLogger.cerr.FwkReport.reportEvery = 1\n";
	file2 << "process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1)) \n";
	file2 << "process.source = cms.Source(\"PoolSource\", \n"; 
	file2 << "  fileNames = cms.untracked.vstring( \n"; 
	

	string datam;

	while (!file3.eof())
	{
		file3 >> datam ;

		file2 <<  "\""<<  datam << "\",  \n" ;
		
	}
	file3.close();
	


  	file2 << " ), \n";

  	file2 << " eventsToProcess = cms.untracked.VEventRange(  \n";


	ifstream file11;
	file11.open("SkimList.txt" ,ios::in);
	
	string run1, lumi1, event1;
	while (!file11.eof())
	{
		file11 >> run1  >>  lumi1   >> event1;

		file2 << " \"" << run1 << ":" << event1 << "\", \n"; 
		

	}
	file11.close();

				   
 	file2 << "     ) \n"; 
	file2 << " ) \n";



	file2 << "process.out = cms.OutputModule(\"PoolOutputModule\", \n";
	file2 << "  outputCommands = cms.untracked.vstring('keep *'), \n";
	file2 << "  fileName = cms.untracked.string('WMT.root') \n";
	file2 << ") \n";

	file2 << "process.p = cms.EndPath(process.out) \n";



	file2.close();


}
