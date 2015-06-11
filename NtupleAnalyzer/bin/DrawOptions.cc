#include "DrawOptions.h"

DrawOptions::DrawOptions(TString dataSet_)
{


  if(dataSet_ == "Z#rightarrowl^{+}l^{-}")
    {
      reweight=1;
      color=1;
      linewidth=1;
      fillcolor=kPink+6;
      linestyle=1;
      drawOpt="zjets";
      search= -1;
    }
  else if(dataSet_ == "QCD")
    {
      reweight=1;
      color=1;
      linewidth=1;
      fillcolor=kYellow;
      linestyle=1;
      drawOpt="qcd";
      search=-1;
    }
  else if(dataSet_ == "DiBoson")
    {
      reweight=1;
      color=1;
      linewidth=1;
      fillcolor=kRed;
      linestyle=1;
      drawOpt="diboson";
      search=-1;
    }
  else if(dataSet_ == "t#bar{t}")
    {
      reweight=1;
      color=107;
      linewidth=1;
      fillcolor=kMagenta+2;
      linestyle=1;
      drawOpt="ttbar";
      search=-1;
    }

  else if(dataSet_ == "t")
    {
      reweight=1;
      color=107;
      linewidth=1;
      fillcolor=kOrange-3;
      linestyle=1;
      drawOpt="t";
      search=-1;
    }
  else if(dataSet_ == "W#rightarrowl#nu")
    {
      reweight=1;
      color=104;
      linewidth=1;
      fillcolor= kSpring-9;
      linestyle=1;
      drawOpt="wjets";
      search=-1;
    }
  else if(dataSet_ == "Z#rightarrow#nu#nu")
    {
      reweight=1;
      color=102;
      linewidth=1;
      fillcolor=kAzure+8 ;
      linestyle=1;
      drawOpt="zinv";
      search=-1;
    }
    
   else if(dataSet_ == "ADD M_{D}= 2 TeV, #delta = 3")
    {
      reweight=1;
      color=102;
      linewidth=1;
      fillcolor=112;
      linestyle=2;
      drawOpt="signal";
      search=1;
    } 
   else if(dataSet_ == "DM #Lambda = 0.9 TeV, M_{#chi} = 1 GeV")
    {
      reweight=0.1682;
      color=102;
      linewidth=1;
      fillcolor=113;
      linestyle=2;
      drawOpt="signal";
      search=1;
    } 
   else if(dataSet_ == "DM STop")
     {
       reweight=1;
       color=102;
       linewidth=1;
       fillcolor=114;
       linestyle=2;
       drawOpt="signal";
       search=1;
     }
   else if(dataSet_ == "DM Higgs VBF")
     {
       reweight=1;
       color=102;
       linewidth=1;
       fillcolor=115;
       linestyle=2;
       drawOpt="signal";
       search=1;
     }
   else if(dataSet_ == "UNP d_{U}=1.7, #Lambda_{U} = 2 TeV")
     {
      reweight=1;
      color=102;
      linewidth=1;
      fillcolor=116;
      linestyle=2;
      drawOpt="signal";
      search=1;
     } 
   else if(dataSet_ == "Data")
     {
      reweight=1;
      color=4;
      linewidth=1;
      fillcolor=111;
      linestyle=1;
      drawOpt="data";
      search=-1;
    }
    
    
  else if(dataSet_ == "Spring10")
    {
      reweight=1;
      color=108;
      linewidth=1;
      fillcolor=111;
      linestyle=1;
      drawOpt="spring10";
      search=-1;
    }
  else if(dataSet_ == "Fall10")
    {
      reweight=1;
      color=107;
      linewidth=1;
      fillcolor=5;
      linestyle=1;
      drawOpt="fall10";
      search=-1;
    }
  else if(dataSet_ == "our")
    {
      reweight=1;
      color=104;
      linewidth=1;
      fillcolor=kRed-4;
      linestyle=1;
      drawOpt="before";
      search=-1;
    }

  else if(dataSet_ == "official")
    {
      reweight=1;
      color=107;
      linewidth=1;
      fillcolor= kAzure+8;
      linestyle=1;
      drawOpt="after";
      search=-1;
    }

  /*else
    {
      reweight=1;
      color=1;
      linewidth=1;
      fillcolor=50;
      linestyle=1;
      drawOpt="";
      search=-1;
      }*/
}
