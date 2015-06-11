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

    //Argument for running of cude
	//TableLep  1 wjets_2  zjets_WZAnalysis_2  znunu_2   ttbar_WZAnalysis_2  sint_2  qcd_2  data_2


	float selection;
	sscanf ( argv[1], "%f", &selection );

	double t[10][10], t2[30][30] ;

	if(selection==1. )
	{

		for(int i=2; i<argc; i++  )
		{
			char file1[200];
			sprintf(file1,"%s.root" , argv[i] );		
			TFile f1( file1 );
			TH1D*  NofLep           = (TH1D*)f1.Get("NofLep")->Clone();
			TH1D*  WlepnuMT_50_100  = (TH1D*)f1.Get("WlepnuMT_50_100")->Clone(); 
			TH1D*  ZleplepMT_60_120 = (TH1D*)f1.Get("ZleplepMT_60_120")->Clone();


			Int_t nbinsW = WlepnuMT_50_100->GetNbinsX() +2;
			Int_t nbinsZ = ZleplepMT_60_120->GetNbinsX() +2;
 
 
			double  t1=0. , t2=0.;
 
			for(int j=0; j<nbinsW; j++  ){  t1= t1+ WlepnuMT_50_100->GetBinContent(j); }
			for(int j=0; j<nbinsZ; j++  ){  t2= t2+ ZleplepMT_60_120->GetBinContent(j); } 


			t[i-2][0] = NofLep->GetBinContent(1);
			t[i-2][1] = NofLep->GetBinContent(2);
			t[i-2][2] = NofLep->GetBinContent(3);
			t[i-2][3] = t1;
			t[i-2][4] = t2;
			t[i-2][5] = NofLep->GetBinContent(4);
 
		}

		string titles[7]={"0 lep","1 lep","2 opposite sign lep","1 lep in Mt(W)= 50-100GeV","2 OSleps in M(leplep)= 60-120GeV","3 lep"};

		for(int i=0; i<6; i++)
		{
			printf( "| %33s | %6.1f |  %6.1f  | %6.1f | %6.1f | %6.1f | %6.1f | %6.1f | %6.1f |\n",  
			titles[i].c_str(),
			t[0][i], t[1][i],t[2][i], t[3][i],t[4][i], t[5][i],
			(t[0][i]) +t[1][i]+ (t[2][i])+ t[3][i]+t[4][i]+ t[5][i] ,  
			t[6][i] ); 
		}

	
	}
	if(selection==2. )
	{

		// Bins definitions
		// 2:GenMuonPt  3:GenMuonPt_10  4:GenMuonPt_20 5:IsoMuonPt_10 6:IsoMuonPt_20  
		// 7:GenElecPt  8:GenElecPt_10  9:GenElecPt_20  10:IsoElecPt_10  11:IsoElecPt_20
		// 12:GenTauPt  13:GenTauElecPt  14:GenTauMuonPt  15:GenTauElecPt_10  16:GenTauMuonPt_10  17:IsoTauElecPt_10  18:IsoTauMuonPt_10  
		// 19: NumOf Iso DiMuon MassWindow   20: NumOf NoMuon 21: NumOf Iso Single Muon   22: NumOf Iso DiMuon 23: NumOf Iso 3Muon 

		int index=0;
		for(int i=2; i<argc; i++  )
		{
			char file1[200];
			sprintf(file1,"%s.root" , argv[i] );		
			TFile f1( file1 );	
			TH1D*  WZEstimation      = (TH1D*)f1.Get("WZEstimation")->Clone();

			t2[0] [i-2] = WZEstimation->GetBinContent(2);
			t2[1] [i-2] = WZEstimation->GetBinContent(3);
			t2[2] [i-2] = WZEstimation->GetBinContent(4);
			t2[3] [i-2] = WZEstimation->GetBinContent(5);
			t2[4] [i-2] = WZEstimation->GetBinContent(6);
			t2[5] [i-2] = WZEstimation->GetBinContent(7);
			t2[6] [i-2] = WZEstimation->GetBinContent(8);
			t2[7] [i-2] = WZEstimation->GetBinContent(9);
			t2[8] [i-2] = WZEstimation->GetBinContent(10);
			t2[9] [i-2] = WZEstimation->GetBinContent(11);
			t2[10][i-2] = WZEstimation->GetBinContent(12);
			t2[11][i-2] = WZEstimation->GetBinContent(13);
			t2[12][i-2] = WZEstimation->GetBinContent(14);
			t2[13][i-2] = WZEstimation->GetBinContent(15);
			t2[14][i-2] = WZEstimation->GetBinContent(16);
			t2[15][i-2] = WZEstimation->GetBinContent(17);
			t2[16][i-2] = WZEstimation->GetBinContent(18);
			t2[17][i-2] = WZEstimation->GetBinContent(19);
			t2[18][i-2] = WZEstimation->GetBinContent(20);
			t2[19][i-2] = WZEstimation->GetBinContent(21);
			t2[20][i-2] = WZEstimation->GetBinContent(22);
			t2[21][i-2] = WZEstimation->GetBinContent(23);


			index++;
		}
				

		string titles[30]={ "All GenMuon", "GenMuonPt>10", "GenMuonPt>20", "IsoMuonPt>10",  "IsoMuonPt>20",  
		                   "All GenElec", "GenElecPt>10", "GenElecPt>20", "IsoElecPt>10",  "IsoElecPt>20",
		                   "All GenTau" , "All GenTauElec" , "All GenTauMuon",  "GenTauElecPt>10",  "GenTauMuonPt>10", "IsoTauElecPt>10",  "IsoTauMuonPt>10"  
						   }; 

		for(int i=0; i<17; i++)
		{
			printf( "| %31s ", titles[i].c_str() );
			for(int k=0; k<index; k++)
			{
				printf( "| %6.1f " , t2[i][k] ); 

			}
			printf("|\n");
		}
	}

	if(selection==3. )
	{


		double  NobsNbck[10][10];
		for(int i=2; i<argc; i++  )
		{
			char file11[200];
			sprintf(file11,"data_%d.root" , i );	
			TFile f11( file11 );	
			TH1D*  WlepnuMT_50_100_data   = (TH1D*)f11.Get("WlepnuMT_50_100")->Clone(); 
					
			double t1=0;
 			Int_t nbinsW = WlepnuMT_50_100_data->GetNbinsX() +2;
			for(int j=0; j<nbinsW; j++  ){  t1= t1+ WlepnuMT_50_100_data->GetBinContent(j); }
			NobsNbck[0][i-2]=t1;

			char file12[200];
			sprintf(file12,"mc_%d.root" , i );	
			TFile f12( file12 );	
			TH1D*  WlepnuMT_50_100_mc   = (TH1D*)f12.Get("WlepnuMT_50_100")->Clone(); 

			double t2=0;
 			Int_t nbinsW2 = WlepnuMT_50_100_mc->GetNbinsX() +2;
			for(int j=0; j<nbinsW2; j++  ){  t2= t2+ WlepnuMT_50_100_mc->GetBinContent(j); }
			NobsNbck[1][i-2]=t2;
		}


		// Bins definitions
		// 2:GenMuonPt  3:GenMuonPt_10  4:GenMuonPt_20 5:IsoMuonPt_10 6:IsoMuonPt_20  
		// 7:GenElecPt  8:GenElecPt_10  9:GenElecPt_20  10:IsoElecPt_10  11:IsoElecPt_20
		// 12:GenTauPt  13:GenTauElecPt  14:GenTauMuonPt  15:GenTauElecPt_10  16:GenTauMuonPt_10  17:IsoTauElecPt_10  18:IsoTauMuonPt_10  
		// 19: NumOf Iso DiMuon MassWindow   20: NumOf NoMuon 21: NumOf Iso Single Muon   22: NumOf Iso DiMuon 23: NumOf Iso 3Muon 

		double  t3[40][40];

		int index=0;
		for(int i=2; i<argc; i++  )
		{
			char file1[200];
			sprintf(file1,"%s.root" , argv[i] );		
			TFile f1( file1 );	
			TH1D*  WZEstimation      = (TH1D*)f1.Get("WZEstimation")->Clone();



			double  APmu=0,  EPmu=0, Amu=0,   Emu=0; 
			double  APe=0,   EPe=0,  Ae=0,    Ee=0; 
			double  Ate=0,   Ete=0,  Atmu=0,  Etmu=0;
			double  NTmu=0,  NTe=0,  NTtmu=0, NTte=0;

			APmu = WZEstimation->GetBinContent(4)/ WZEstimation->GetBinContent(2);
			EPmu = WZEstimation->GetBinContent(6)/ WZEstimation->GetBinContent(4);
			Amu  = WZEstimation->GetBinContent(3)/ WZEstimation->GetBinContent(2);
			Emu  = WZEstimation->GetBinContent(5)/ WZEstimation->GetBinContent(3);

			APe  = WZEstimation->GetBinContent(9)/ WZEstimation->GetBinContent(7);
			EPe  = WZEstimation->GetBinContent(11)/ WZEstimation->GetBinContent(9);
			Ae   = WZEstimation->GetBinContent(8)/ WZEstimation->GetBinContent(7);
			Ee   = WZEstimation->GetBinContent(10)/ WZEstimation->GetBinContent(8); 

			Ate  = WZEstimation->GetBinContent(15)/ WZEstimation->GetBinContent(13);
			Ete  = WZEstimation->GetBinContent(17)/ WZEstimation->GetBinContent(15);

			Atmu = WZEstimation->GetBinContent(16)/ WZEstimation->GetBinContent(14);
			Etmu = WZEstimation->GetBinContent(18)/ WZEstimation->GetBinContent(16);

			double NTthad= WZEstimation->GetBinContent(12) - (WZEstimation->GetBinContent(13) +  WZEstimation->GetBinContent(14));

			// if you run muon
			NTmu  = (NobsNbck[0][i-2] -NobsNbck[1][i-2]) / (APmu*EPmu);
			NTe   = NTmu * ( WZEstimation->GetBinContent(7) / WZEstimation->GetBinContent(2) ); 
			NTte  = NTmu * ( WZEstimation->GetBinContent(13)/ WZEstimation->GetBinContent(2) );
			NTtmu = NTmu * ( WZEstimation->GetBinContent(14)/ WZEstimation->GetBinContent(2) );
			
			/*			//if you run  electron 
			NTe  = (NobsNbck[0][i-2] -NobsNbck[1][i-2]) / (APe*EPe);
			NTmu  = NTe * ( WZEstimation->GetBinContent(2) / WZEstimation->GetBinContent(7) ); 
			NTte  = NTe * ( WZEstimation->GetBinContent(13)/ WZEstimation->GetBinContent(7) );
			NTtmu = NTe * ( WZEstimation->GetBinContent(14)/ WZEstimation->GetBinContent(7) );
			*/

			t3[0] [i-2] = NobsNbck[0][i-2];
			t3[1] [i-2] = NobsNbck[1][i-2];
			t3[2] [i-2] = APmu;
			t3[3] [i-2] = EPmu;
			t3[4] [i-2] = NTmu;
			t3[5] [i-2] = Amu;
			t3[6] [i-2] = Emu;
			t3[7] [i-2] = NTmu*(1-Amu); 
			t3[8] [i-2] = NTmu*Amu*(1-Emu);
			t3[9] [i-2] = NTmu*(1- (Amu*Emu));

			double NTmulep = NTmu*(1- (Amu*Emu));
			
			t3[10][i-2] = APe;
			t3[11][i-2] = EPe;
			t3[12][i-2] = NTe;
			t3[13][i-2] = Ae;
			t3[14][i-2] = Ee;
			t3[15][i-2] = NTe*(1-Ae);
			t3[16][i-2] = NTe*Ae*(1-Ee);
			t3[17][i-2] = NTe*(1- (Ae*Ee));

			double NTelep = NTe*(1- (Ae*Ee));

			t3[18][i-2] = NTte;
			t3[19][i-2] = Ate;
			t3[20][i-2] = Ete;
			t3[21][i-2] = NTte*(1-Ate);;
			t3[22][i-2] = NTte*Ate*(1-Ete);
			t3[23][i-2] = NTte*(1- (Ate*Ete));

			t3[24][i-2] = NTtmu;
			t3[25][i-2] = Atmu;
			t3[26][i-2] = Etmu;
			t3[27][i-2] = NTtmu*(1-Atmu);;
			t3[28][i-2] = NTtmu*Atmu*(1-Etmu);
			t3[29][i-2] = NTtmu*(1- (Atmu*Etmu));

			t3[30][i-2] = (NTte*(1- (Ate*Ete))) + (NTtmu*(1- (Atmu*Etmu)));
			t3[31][i-2] =  NTthad ;

			double  NTtlep = (NTte*(1- (Ate*Ete))) + (NTtmu*(1- (Atmu*Etmu)));

			t3[32][i-2] =  NTthad + NTtlep + NTmulep + NTelep;

			index++;
		}

		string titles[40]={"Nobs","Nbck",
				    "Aprime mu","Eprime mu","Ntot mu","A mu", "E mu", "Nlost from A mu", "Nlost from E mu", "Nlost mu",  
					"Aprime e" ,"Eprime e" ,"Ntot e" ,"A e" , "E e" , "Nlost from A e" , "Nlost from E e" , "Nlost e" ,
					"Ntot taue"  ,"A taue"  , "E taue"  , "Nlost from A taue"  , "Nlost from E taue"  , "Nlost taue" ,
					"Ntot taumu" ,"A taumu" , "E taumu" , "Nlost from A taumu" , "Nlost from E taumu" , "Nlost taumu",
			        "Nlost tau leptonic",  "Ntot hadronic", "Wjets Tot" };

		for(int i=0; i<34; i++)
		{
			printf( "| %31s ", titles[i].c_str() );
			for(int k=0; k<index; k++)
			{
				printf( "| %9.3f " , t3[i][k] ); 

			}
			printf("|\n");
		}

	}

}


