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
#include <math.h>
using namespace std;


const std::string outputDir = "";

int main(int argc, char ** argv)
{

	if ( argc < 3 ) {
		cerr << "Insufficient arguments: [histogram name] [options] [dataset1] [dataset2...]" << endl;
		return 1;
	}


	vector<double>  t,terr, tbin;
	Double_t a1[45], a2[45];
	Double_t alphas0[3]={0,0,0} , alphas1[3]={0,0,0};

	//cout << argc   <<  "  "  <<  argv[0] <<  "  "  << argv[1]<<  "  "  << endl;

	float selection;
	sscanf ( argv[2], "%f", &selection );

	for(int i=3; i<argc; i++  )
	{
		char file1[200];
		sprintf(file1,"%s.root" , argv[i] );
	
	
		string  histo = argv[1];
		
		TFile f1( file1 );
	
	
		TH1D*  histo1  = (TH1D*)f1.Get( histo.c_str() )->Clone();
		
	
		Int_t nbins1 = histo1->GetNbinsX() +2;
	
		terr.push_back( histo1->GetEntries() );
	
		double  t1=0.;
	
		for(int j=0; j<nbins1; j++  ){  t1= t1+ histo1->GetBinContent(j); }
	
		t.push_back(t1);

		for(int j=0; j<nbins1; j++  ){  tbin.push_back( histo1->GetBinContent(j) ) ; }
	

		
		if(selection!=6) continue; 
		
		if(i==4)
		{
			for(int k=0; k<45; k++ )
			{
				char his[100];

				sprintf(his,"PDF%d", k);

				TH1D*  hist1  = (TH1D*)f1.Get( his )->Clone();
				TH1D*  histm  = (TH1D*)f1.Get( "alphas_m" )->Clone();
				TH1D*  hist0  = (TH1D*)f1.Get( "alphas" )->Clone();
				TH1D*  histp  = (TH1D*)f1.Get( "alphas_p" )->Clone();

				Int_t nbins1 = hist1->GetNbinsX() +2;

				Double_t  t1=0. , a0=0., am=0., ap=0.;

				for(int j=0; j<10; j++  ){ am = am+ histm->GetBinContent(j); }
				for(int j=0; j<10; j++  ){ a0 = a0+ hist0->GetBinContent(j); }
				for(int j=0; j<10; j++  ){ ap = ap+ histp->GetBinContent(j); }


				for(int j=0; j<nbins1; j++  ){  t1= t1+ hist1->GetBinContent(j); }

				a1[k]=t1;  alphas0[0]= am; alphas0[1]= a0; alphas0[2]= ap;

			}
		}

		if(i==7)
		{
			
			for(int k=0; k<45; k++ )
			{
				char his[100];

				sprintf(his,"PDF%d", k);

				TH1D*  hist1  = (TH1D*)f1.Get( his )->Clone();
				TH1D*  histm  = (TH1D*)f1.Get( "alphas_m" )->Clone();
				TH1D*  hist0  = (TH1D*)f1.Get( "alphas" )->Clone();
				TH1D*  histp  = (TH1D*)f1.Get( "alphas_p" )->Clone();

				Int_t nbins1 = hist1->GetNbinsX() +2;

				Double_t  t1=0. , a0=0., am=0., ap=0.;

				for(int j=0; j<10; j++  ){ am = am+ histm->GetBinContent(j); }
                                for(int j=0; j<10; j++  ){ a0 = a0+ hist0->GetBinContent(j); }
				for(int j=0; j<10; j++  ){ ap = ap+ histp->GetBinContent(j); }


				for(int j=0; j<nbins1; j++  ){  t1= t1+ hist1->GetBinContent(j); }

				a2[k]=t1; alphas1[0]= am; alphas1[1]= a0; alphas1[2]= ap;
			}	
		}

	}
	//for cut efficiency
	if(selection==1.)
	{
	       printf( "|  %7.1f  |  %7.1f  |*%7.1f*",     t[1], t[1]-t[0] , (t[1]-t[0])*100./t[1] );		
	       printf( "|  %7.1f  |  %7.1f  |*%7.1f*",     t[3], t[3]-t[2] , (t[3]-t[2])*100./t[3] );
	       printf( "|  %7.1f  |  %7.1f  |*%7.1f*",     t[5], t[5]-t[4] , (t[5]-t[4])*100./t[5] );
	}
	//for data and background
	else if(selection==2.)
	{
	       printf( "| %7.1f | %7.1f | %7.1f | %7.1f | %7.1f | %7.1f | %7.1f |  %7.1f | ",     t[0], t[1], t[2] , t[3], t[4],t[5], t[0]+t[1]+t[2]+t[3]+t[4]+t[5] , t[6] );

	    


	}
	//for data and background
	else if(selection==2.5)
	{

	  printf( "| %10.2f | %10.0f | %10.0f | %10.0f | %10.0f | %10.0f | %10.0f | %10.0f |",  t[0], t[1], t[2] , t[3], t[4],t[5], t[0]+t[1]+t[2]+t[3]+t[4]+t[5] , t[6]  ) ;


	  /*   float a0= sqrt(terr[0])/terr[0]*t[0];
	  float a1= sqrt(terr[1])/terr[1]*t[1];
          float a2= sqrt(terr[2])/terr[2]*t[2];
          float a3= sqrt(terr[3])/terr[3]*t[3];
          float a4= sqrt(terr[4])/terr[4]*t[4];
          float a5= sqrt(terr[5])/terr[5]*t[5];
	  float a6= sqrt(terr[6])/terr[6]*t[6];
          float a7= sqrt(terr[7])/terr[7]*t[7];
          float a8= sqrt(terr[8])/terr[8]*t[8];
          


	      printf( "| %7.0f | %7.0f | %7.0f | %7.0f | %7.0f | %7.0f | %7.0f |  %7.0f | %7.0f | %7.0f |",     
		      a0, a1, a2, a3, a4, a5, 
		      sqrt( a0*a0 + a1*a1 + a2*a2 + a3*a3 + a4*a4 + a5*a5) ,
		      
		      a6, a7, a8  ) ;  */

	}
	else if(selection==2.6)
	{
	       printf( "|   %7.1f   |",   t[0] );
	}

	//for add
	else if(selection==3.)
	{  

	        printf( "| %6.1f | %6.1f | %6.1f | %6.1f | %6.1f | %6.1f |  %6.1f | %6.1f |  %6.1f |",     t[0], t[1], t[2] , t[3], t[4], t[5] , t[6] , t[7], t[8] );


	}
	//for unparticle
	else if(selection==4.)
	{

	    printf( "| %6.1f | %6.1f | %6.1f | %6.1f | %6.1f | %6.1f |  %6.1f | %6.1f |  %6.1f |   %6.1f | ",     t[0], t[1], t[2] , t[3], t[4], t[5] , t[6] , t[7], t[8], t[9] );


	}

	else if(selection==5.)
	{

	    printf( "| %6.2f | %6.2f | %6.2f |  ",     tbin[2], tbin[3], tbin[2]+tbin[3] );


	}

	else if(selection==6.)
	{
	  
	    
		Double_t  tds=0, tdsp=0 , tdsm=0; 

		//cout <<  "  0"   <<  "  "  << a1[0] <<  "  "  <<  a2[0]  <<    "  "  <<  a2[0]/a1[0]  <<  endl;

		for(size_t i=1; i<45; i+=2 )
		{


			double_t ds  =  (a2[i]/a1[i] -  a2[i+1]/a1[i+1]  ) / 2.; 
			
			Double_t dsp =  a2[i]/a1[i]  -  a2[0]/a1[0] ;

			Double_t dsm =  a2[0]/a1[0]  -  a2[i+1]/a1[i+1];

			tds = tds +  (ds*ds);

			tdsp = tdsp +  (dsp*dsp);
			tdsm = tdsm +  (dsm*dsm);




			//cout <<  "  +" << (i+1)/2  <<  "  "   << a1[i] <<  "  "  <<  a2[i]     <<  "  " <<  a2[i]/a1[i]   <<  "  ..." <<   a2[0]/a1[0] << endl;
			//cout <<  "  -" << (i+1)/2  <<  "  "   << a1[i+1] <<  "  "  <<  a2[i+1]  <<  "  " <<  a2[i+1]/a1[i+1]   <<endl;
			
			//cout <<  "" << i <<  "  " <<  ds <<  "  "<< dsp   <<  "  "  <<  dsm  << endl<< endl;
		
			//cout <<  ds << endl;
		}
		  
		//cout  << " avarage: "  <<  sqrt(tds)  <<  "   +" <<  sqrt(tdsp)  <<  "   -" <<  sqrt(tdsm)   <<  "   -+" <<  (sqrt(tdsm)+  sqrt(tdsp)) /2 <<   endl;
		      
		double  acc = t[4]*100/t[1];
		
		double  jesm = (t[4]- t[3])*100 / t[4];
		double  jesp = (t[4] - t[5])*100 / t[4];
		
		double  pdfm = sqrt(tdsm) *100 / ( t[4]/t[1])  ; 
		double  pdfp = sqrt(tdsp) *100 / ( t[4]/t[1])  ; 
		

		// these is for cteq66
		double asmm =  ( (alphas1[1]/alphas0[1]) -  (alphas1[0]/alphas0[0]) )/0.83 *100 / ( t[4]/t[1]) ;
		double aspp =  ( (alphas1[2]/alphas0[2]) -  (alphas1[1]/alphas0[1]) )/0.83 *100 / ( t[4]/t[1]) ; // C59 = 0.83 see LHC4PDF 
		
		// these is for  mstw
		//double asmm =  ( (alphas1[1]/alphas0[1]) -  (alphas1[0]/alphas0[0]) )/1.25 *100 / ( t[4]/t[1]) ;
		//double aspp =  ( (alphas1[2]/alphas0[2]) -  (alphas1[1]/alphas0[1]) )/1.25 *100 / ( t[4]/t[1]) ; // C79 = 1.25 see LHC4PDF



		double  totm = sqrt( jesm*jesm + pdfm*pdfm + asmm*asmm);
		double  totp = sqrt( jesp*jesp + pdfp*pdfp + aspp*aspp);


		
		printf( "| %6.3f | %6.3f / %6.3f | -%6.3f / +%6.3f |  -%6.3f / +%6.3f  | -%6.3f / +%6.3f |",  
			acc , jesm, jesp , fabs(pdfm)/1.64485 ,fabs(pdfp)/1.64485, asmm, aspp, totm, totp  );      
		
	}
}


