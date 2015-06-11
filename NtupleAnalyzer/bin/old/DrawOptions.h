#ifndef DrawOptions_h
#define DrawOptions_h

#include <TROOT.h>

class DrawOptions
{
public:
  DrawOptions(TString dataSet_);

  Double_t reweight;
  int color;
  int linewidth;
  int fillcolor;
  int linestyle;
  TString drawOpt;
  int search;
};

#include "DrawOptions.cc"
#endif
