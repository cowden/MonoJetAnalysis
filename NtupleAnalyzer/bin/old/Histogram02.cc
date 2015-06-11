#include "Operation.h"
#include "Histogram02.h"
#include <iostream>
#include <fstream>

#include <TH1D.h>
#include <math.h>
#include <TLorentzVector.h>

#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/deltaPhi.h"

using namespace std;
using namespace Operation;

namespace Histogram02 
{
	//----------------MuonAnalysis Histograms  Defination--------------------------------------------------------------------

	hMuonAna::hMuonAna(const std::string & fileName):
	mFileName(fileName)
	{
		fileOut = new TFile(mFileName.c_str(),"recreate");
		histo1D["Met"]              = new TH1D("Met"             , "MET "                , 400, 0, 2000);

		
	}


	// ---------------MuonANalysis Histograms Filling------------------------------------------------------------------------

	bool hMuonAna::Process(EventData & ev) 
	{

		double w= ev.Weight();
		int  t= ev.MetType(); 
		
		
		histo1D["Met"]->Fill(  MetLepPt( ev.MetPx(t) , ev.MetPy(t) , ev ) , w );
	

		return true;
	}
	
	std::ostream& hMuonAna::Description(std::ostream &ostrm) 
	{
		ostrm << "  MuonAnalysis (output in " << mFileName << "):";
		return ostrm;
	}

	//--------------MuonAnalysis End Job-----------------------------------------------------------------------------------
	hMuonAna::~hMuonAna() 
	{	
		fileOut->Write();
		delete fileOut;	
	}
	
	


///============================================================================================================================================



}

