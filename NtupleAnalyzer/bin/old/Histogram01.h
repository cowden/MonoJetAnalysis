#ifndef Histograms01_h
#define Histograms01_h

// Using the EventData wrapper
#include "EventData.h"
#include "Operation.h"

// Using streams
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
// ROOT stuff
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TLorentzVector.h"

using namespace std;

namespace Histogram01 
{
  
	void  OutputEPS( map<string,TH1D*> histos_ , string dirName);

	class hHLTEff : public Operation::_Base 
	{
		public:
			hHLTEff(const std::string & fileName);
			~hHLTEff();
			bool Process(EventData & ev);

			std::ostream& Description(std::ostream& ostrm);

		private:
			const std::string mFileName;

			// Output file
			TFile* fileOut;

			//------------------------
			// Declare the histograms
			//------------------------
			map<string, TH1D*> histo1D;
			map<string, TH2D*> histo2D;
	};
	
	
	
	class hDataMcMatching : public Operation::_Base 
	{
		public:
			hDataMcMatching(const std::string & fileName);
			~hDataMcMatching();
			bool Process(EventData & ev);

			std::ostream& Description(std::ostream& ostrm);

		private:
			const std::string mFileName;

			// Output file
			TFile* fileOut;

			//------------------------
			// Declare the histograms
			//------------------------
			map<string, TH1D*> histo1D;
			map<string, TH2D*> histo2D;
		
			map<string, TProfile*> profile1D;
	};
	
	class hWZAnalysis : public Operation::_Base 
	{
		public:
			hWZAnalysis(const std::string & fileName);
			~hWZAnalysis();
			bool Process(EventData & ev);

			std::ostream& Description(std::ostream& ostrm);

		private:
			const std::string mFileName;

			// Output file
			TFile* fileOut;

			ofstream myfile;

			//------------------------
			// Declare the histograms
			//------------------------
			map<string, TH1D*> histo1D;
			map<string, TH2D*> histo2D;

			//TProfile hprof ;
	};

	class hWSourceAnalysis : public Operation::_Base 
	{
		public:
			hWSourceAnalysis(const std::string & fileName);
			~hWSourceAnalysis();
			bool Process(EventData & ev);

			std::ostream& Description(std::ostream& ostrm);

		private:
			const std::string mFileName;

			// Output file
			TFile* fileOut;

			//------------------------
			// Declare the histograms
			//------------------------
			map<string, TH1D*> histo1D;
			map<string, TH2D*> histo2D;
	};

	//--- hTauAnalysis ---
	class hTauAnalysis : public Operation::_Base 
	{
	public:
	  hTauAnalysis(const std::string & fileName);
	  ~hTauAnalysis();
	  bool Process(EventData & ev);
	  
	  std::ostream& Description(std::ostream& ostrm);
	  
	private:
	  const std::string mFileName;
	  
	  // Output file
	  TFile* fileOut;
	  
	  //------------------------
	  // Declare the histograms
	  //------------------------
	  map<string, TH1D*> histo1D;
	  map<string, TH2D*> histo2D;
	};
}

#include "Histogram01.cc"
#endif 
