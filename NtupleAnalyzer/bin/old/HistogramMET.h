#ifndef HistogramsMET_h
#define HistogramsMET_h

// Using the EventData wrapper
#include "EventData.h"
#include "Operation.h"

// Using streams
#include <iostream>
#include <vector>

// ROOT stuff
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TLorentzVector.h"

using namespace std;

namespace HistogramMET 
{
  
  class hMETAna : public Operation::_Base 
  {
  public:
    hMETAna(const std::string & fileName);
    ~hMETAna();
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

#include "HistogramMET.cc"
#endif 
