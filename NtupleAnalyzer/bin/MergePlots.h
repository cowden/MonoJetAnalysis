#ifndef MergePlots_h
#define MergePlots_h

//#include "Operation.hh"
#include <iostream>
#include <TString.h>
#include <TFile.h>
#include <TGraphErrors.h>
#include <vector>

class MergePlots 
{

public:

  MergePlots(std::string name = "");
  ~MergePlots();

  /**
   * \brief Adds a dataset to the histogram to be plotted
   */
  void addDataSet(std::string dataSet, std::string dataName);

  /**
   * \brief This method plots histograms named "histname" into a Canvas (name=histname) and writes to the outFile
   */
  void mergeHist(char* histname, std::string titlex, std::string titley, TString kind="", TString mc="", TString data="", bool legend=false, TString drawOpt="", bool withScale=false);

  void mergeCanvas(char* histname,  bool legend=false, TString drawOpt="");

private:

  std::string dirname_; //!< Output directory (hardcoded...)
  std::vector<TFile*> dataFileVec; //!< Vector of ROOT files from the datasets

  // Plot drawing options (one vector entry for each dataset)
  std::vector<int> colorVec;
  std::vector<int> linewidthVec;
  std::vector<int> fillcolorVec;
  std::vector<int> linestyleVec;
  std::vector<double> reweightVec;
  std::vector<TString> dataNameVec;
  std::vector<TString> drawOptVec;
  std::vector<TString> legendVec;
  std::vector<TString> data;

};

#include "MergePlots.cc"

#endif
