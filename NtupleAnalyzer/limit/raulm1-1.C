/* --------------------------------------------------------------------------------
   Computes Bayesian Reference Analysis Upper Limits for cross section measurements
   using numerical implementations of the Method-1 formula given in section III.A.1 
   of http://arxiv.org/abs/1002.1111 (published as Phys. Rev. D 82, 034002 (2010)).

   Usage: invoke ROOT command line interpreter, then type
           --------------------------------------------------------
             root[] .L raulm1.C
             root[] raulm1( acc, dacc, bgd, dbgd, nobs, credib );
           --------------------------------------------------------

   Inputs: acc    = Nominal integrated luminosity times signal efficiency times
                    signal acceptance, in the inverse of the units in which one
                    wants the upper limit on the cross section;
           dacc   = Absolute uncertainty on acc;
           bgd    = Expected number of background events;
	   dbgd   = Absolute uncertainty on bgd;
           nobs   = Total number of events observed;
           credib = Credibility level of upper limit (a number between 0 and 1).

   Note 1: The calculation requires a mapping from the prior acceptance and 
           background information (acc+/-dacc,bgd+/-dbgd) to the parameters 
           (aval,xval,bval,yval) of the evidence-based prior (a product of two 
           gamma distributions).  There are several options.  Taking the 
           acceptance as example:
           - Option 1: identify acc with the prior mean (xval+0.5)/aval;
           - Option 2: identify acc with the prior mode, which is (xval-0.5)/aval 
                       when xval>0.5, and 0 otherwise;
           - Option 3: assume that the prior is actually the posterior from a 
                       subsidiary measurement with Poisson likelihood and identify 
                       acc with the maximum likelihood estimate, which is 
                       xval/aval for xval>0, and 0 otherwise.
           - Option 4: identify acc with the prior median, for which there is no 
                       simple closed form;
           In order to determine both parameters of the acceptance prior, xval and 
           aval, one also needs to identify dacc with something; a natural choice 
           is the standard deviation of the prior, which is sqrt(xval+0.5)/aval.
           Option 4 above cannot be handled analytically, so only the first three 
           options are implemented.  In addition, note that option 1 does not 
           specify a valid gamma distribution if acc=0 and dacc!=0 (or if bgd=0 
           and dbgd!=0); however, options 2 and 3 still work in this case.  In
           general, upper limits are more conservative (larger) with option 1 than
           with option 3, and with option 3 than with option 2.  Large acceptance
           uncertainties lead to high sensitivity to the choice of option.

           In the code below, the integer array pr_opt allows the user to set the 
           mapping option separately for acceptance (pr_opt[0]) and for background 
           (pr_opt[1]).  The default for both acceptance and background is option 2.

   Note 2: To obtain upper limits on the number of events rather than on the cross
           section, set acc=1 and dacc=0.

   History: v1.0, 5 May 2010, creation -Luc Demortier
                                       -Supriya Jain
                                       -Harrison Prosper
            v1.1, 20 December 2010, corrected initialization of x1 (Luc)
            v1.2, 21 December 2010, added prior mapping options for acceptance 
                                    and background (Luc)
-------------------------------------------------------------------------------- */
#include <iostream>
#include <stdlib.h>
#include "TMath.h"
#include "TF1.h"
using namespace std;

static Double_t acc1, dacc1, bgd1, dbgd1, nobs1, tcred, epsilon=1.0e-8;
static Int_t    pr_opt[2]={2,2};

Double_t PTailInt( Double_t *uval, Double_t *fpar );

Double_t raulm1( Double_t acc, Double_t dacc, Double_t bgd, Double_t dbgd, Int_t nobs, Double_t credib )
{
   Double_t x1, x2, delta, fpar[1];
   acc1  = acc;
   dacc1 = dacc;
   bgd1  = bgd;
   dbgd1 = dbgd;
   nobs1 = nobs;
   tcred = 1.0-credib;
   if(acc1==0 && dacc1!=0 && pr_opt[0]==1)
   {
     cout << "Prior option 1 is not available when acc=0 and dacc!=0." << endl;
     fpar[0] = -1.0;
     return fpar[0];
   }
   if(bgd1==0 && dbgd1!=0 && pr_opt[1]==1)
   {
     cout << "Prior option 1 is not available when bgd=0 and dbgd!=0." << endl;
     fpar[0] = -1.0;
     return fpar[0];
   }
//
   TF1 pti("PTailInt",PTailInt,0.0,1.0,1);
//
   if(nobs>0) fpar[0] = (nobs1+sqrt(2*nobs1)*TMath::ErfInverse(credib))/acc1;
   else fpar[0] = 1.0;
   delta   = pti.Integral(0.0,1.0,fpar,epsilon) - tcred;
   x1      = 0.0;
   while (delta > 0)
   {
     x1      = fpar[0];
     fpar[0] = 2*x1;
     delta   = pti.Integral(0.0,1.0,fpar,epsilon) - tcred;
   }
   x2      = fpar[0];
   fpar[0] = 0.5*(x1 + x2);
//
   delta   = pti.Integral(0.0,1.0,fpar,epsilon) - tcred;
   while (fabs(delta) > epsilon) 
   {
     if (delta < 0) x2 = fpar[0];
     else x1 = fpar[0];
     fpar[0] = 0.5*(x1 + x2);
     delta = pti.Integral(0.0,1.0,fpar,epsilon) - tcred;
   }
   cout << "Upper limit on signal = " << fpar[0] << endl;
//
   return fpar[0];
}
Double_t PTailInt(Double_t *uval, Double_t *fpar)
{
/* -----------------------------------------------------------------------------
The integral of PTailInt from 0 to 1 is equal to one minus the cumulative
Method-1 reference posterior, i.e. the integral of the reference posterior from 
sigma to infinity, where sigma=fpar[0] is the signal cross section.
----------------------------------------------------------------------------- */
   Double_t xval, yval, aval, bval, tmp1, tmp2, tmp3, tmp4;
   Double_t retval;
//
/* -----------------------------------------------------------------------------
First map input acceptance and background info into parameters of the prior.
----------------------------------------------------------------------------- */
   if(dacc1!=0.0)
   {
     tmp1   = acc1/dacc1;
     if(pr_opt[0]==1)
     {
       aval   = tmp1/dacc1;
       xval   = aval*acc1 - 0.5;
     }
     if(pr_opt[0]==2)
     {
       aval   = 0.5*tmp1/dacc1 + 0.5*sqrt(4.0+tmp1*tmp1)/dacc1;
       xval   = aval*acc1 + 0.5;
     }
     if(pr_opt[0]==3)
     {
       aval   = 0.5*tmp1/dacc1 + 0.5*sqrt(2.0+tmp1*tmp1)/dacc1;
       xval   = aval*acc1;
     }
   }
   if(dbgd1!=0.0)
   {
     tmp1   = bgd1/dbgd1;
     if(pr_opt[1]==1)
     {
       bval   = tmp1/dbgd1;
       yval   = bval*bgd1 - 0.5;
     }
     if(pr_opt[1]==2)
     {
       bval   = 0.5*tmp1/dbgd1 + 0.5*sqrt(4.0+tmp1*tmp1)/dbgd1;
       yval   = bval*bgd1 + 0.5;
     }
     if(pr_opt[1]==3)
     {
       bval   = 0.5*tmp1/dbgd1 + 0.5*sqrt(2.0+tmp1*tmp1)/dbgd1;
       yval   = bval*bgd1;
     }
   }
/* ---------------------------------------------------------
Case 1: No acceptance uncertainty, no background uncertainty
--------------------------------------------------------- */
   if(dacc1==0.0 && dbgd1==0.0)
   {
     if(uval[0]==1.0)
     {
       retval = 0.0;
     } else {
       tmp1   = acc1*fpar[0]+bgd1;
       tmp2   = (nobs1+0.5)*log(tmp1)-tmp1/(1.0-uval[0])
                -(nobs1+1.5)*log(1.0-uval[0])-TMath::LnGamma(nobs1+0.5);
       tmp3   = 1.0 - TMath::Gamma(nobs1+0.5,bgd1);
       retval = exp(tmp2) / tmp3;
     }
   }
/* -------------------------------------------------------------
Case 2: Finite acceptance uncertainty, no background uncertainty
------------------------------------------------------------- */
   if(dacc1!=0.0 && dbgd1==0.0)
   {
     if(bgd1!=0.0)
     {
       if(uval[0]==0.0 || uval[0]==1.0)
       {
         retval = 0.0;
       } else {
         tmp1   = 1.0 - uval[0];
         tmp2   = (nobs1+0.5)*log(bgd1) - bgd1/tmp1
                  -(nobs1+1.5)*log(tmp1)-TMath::LnGamma(nobs1+0.5);
	 if(fpar[0]!=0.0) tmp3 = TMath::Gamma(xval+0.5,(aval/fpar[0])*(uval[0]*bgd1/tmp1));
         else tmp3 = 1.0;
         tmp4   = 1.0 - TMath::Gamma(nobs1+0.5,bgd1);
         retval = exp(tmp2) * (tmp3/tmp4);
       }
     } else {
       if(uval[0]==1.0)
       {
	 retval = 0.0;
       } else {
         tmp1   = (nobs1-0.5)*log(aval*uval[0]+fpar[0])+(xval-0.5)*log(1.0-uval[0])
                  +(xval+0.5)*log(aval)-(nobs1+xval)*log(aval+fpar[0]);
         tmp2   = TMath::Beta(nobs1+0.5,xval+0.5);
         retval = exp(tmp1)/tmp2;
       }
     }
   }
/* -------------------------------------------------------------
Case 3: No acceptance uncertainty, finite background uncertainty
------------------------------------------------------------- */
   if(dacc1==0.0 && dbgd1!=0.0)
   {
     if(uval[0]==0.0 || uval[0]==1.0)
     {
       retval = 0.0;
     } else {
       tmp1   = (nobs1+yval)*log(uval[0]+acc1*fpar[0])-(nobs1+yval+2.0)*log(1.0-uval[0])
                -(uval[0]+acc1*fpar[0])/(1.0-uval[0])-TMath::LnGamma(nobs1+yval+1);
       tmp2   = bval / (1.0+bval);
       tmp3   = TMath::BetaIncomplete(tmp2,yval+0.5,nobs1+0.5);
       tmp2   = tmp2 * uval[0] * (1.0+acc1*fpar[0])/(uval[0]+acc1*fpar[0]);
       tmp4   = TMath::BetaIncomplete(tmp2,yval+0.5,nobs1+0.5);
       retval = (1.0+acc1*fpar[0]) * exp(tmp1) * (tmp4/tmp3);
     }
   }
/* -----------------------------------------------------------------
Case 4: Finite acceptance uncertainty, finite background uncertainty
----------------------------------------------------------------- */
   if(dacc1!=0.0 && dbgd1!=0.0)
   {
     if(uval[0]==0.0 || uval[0]==1.0)
     {
       retval = 0.0;
     } else {
       tmp1   = bval / (1.0+bval);
       tmp2   = TMath::BetaIncomplete(tmp1,yval+0.5,nobs1+0.5);
       tmp1   = tmp1 * ((aval+fpar[0])*uval[0])/(aval*uval[0]+fpar[0]);
       tmp3   = TMath::BetaIncomplete(tmp1,yval+0.5,nobs1+0.5);
       tmp1   = TMath::Beta(nobs1+yval+1.0,xval+0.5);
       tmp4   = (xval+0.5)*log(aval)+(nobs1+yval)*log(aval*uval[0]+fpar[0])
                +(xval-0.5)*log(1.0-uval[0])-(nobs1+xval+yval+0.5)*log(aval+fpar[0]);
       retval = (exp(tmp4)/tmp1) * (tmp3/tmp2);
     }
   }
   return retval;
}
