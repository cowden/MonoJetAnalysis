#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <TStyle.h>
#include <TROOT.h>

// std includes
#include <fstream>
#include "TH1D.h"
#include <TString.h>
#include <TFile.h>

using namespace std;

int main()
{	
	string k;
	cin>>k;
	if(k=="w")
	{
		string met[8]={"Met200","Met250","Met300","Met350","Met400","Met450","Met500","Met550"};
		double Ndata[8], Nbg[8], Apmu[8], Epmu[8], Amu[8], Emu[8], Ae[8], Ee[8], Atm[8], Etm[8], Ate[8], Ete[8];
		double Allmu[8], Acpmu10[8], Acpmu20[8], Estlostmu[8], Estloste[8], Estlosttm[8], Estlostte[8], Esthad[8], Alle[8], Acpe[8], Alltmu[8], Acptmu[8], Allte[8], Acpte[8];
		for(int i=2; i<10; i++  )
		{
			char file11[200], file12[200], file1[200];
			sprintf(file11,"data_%d.root" , i );
			sprintf(file12,"mc_%d.root" , i );	
			sprintf(file1,"wjets_%d.root" , i);		
			TFile f1( file1 );	
			TFile f11( file11 );	
			TFile f12( file12 );	
			TH1D*  WlepnuMT_50_100_data   = (TH1D*)f11.Get("WlepnuMT_50_100"); 
			TH1D*  WlepnuMT_50_100_mc   = (TH1D*)f12.Get("WlepnuMT_50_100"); 		
			double t1=0, t2=0;
 			Int_t nbinsW = WlepnuMT_50_100_data->GetNbinsX() +2;
			for(int j=0; j<nbinsW; j++  ){  t1= t1+ WlepnuMT_50_100_data->GetBinContent(j); }
			Ndata[i-2]=t1;

 			Int_t nbinsW2 = WlepnuMT_50_100_mc->GetNbinsX() +2;
			for(int j=0; j<nbinsW2; j++  ){  t2= t2+ WlepnuMT_50_100_mc->GetBinContent(j); }
			Nbg[i-2]=t2;
			// Bins definitions
			// 2:GenMuonPt  3:GenMuonPt_10  4:GenMuonPt_20 5:IsoMuonPt_10 6:IsoMuonPt_20  
			// 7:GenElecPt  8:GenElecPt_10  9:GenElecPt_20  10:IsoElecPt_10  11:IsoElecPt_20
			// 12:GenTauPt  13:GenTauElecPt  14:GenTauMuonPt  15:GenTauElecPt_10  16:GenTauMuonPt_10  17:IsoTauElecPt_10  18:IsoTauMuonPt_10  
			// 19: NumOf Iso DiMuon MassWindow   20: NumOf NoMuon 21: NumOf Iso Single Muon   22: NumOf Iso DiMuon 23: NumOf Iso 3Muon 
			TH1D*  WZEstimation      = (TH1D*)f1.Get("WZEstimation");
			Apmu[i-2] = WZEstimation->GetBinContent(4)/ WZEstimation->GetBinContent(2);
			Epmu[i-2] = WZEstimation->GetBinContent(6)/ WZEstimation->GetBinContent(4);
			Amu[i-2]  = WZEstimation->GetBinContent(3)/ WZEstimation->GetBinContent(2);
			Emu[i-2]  = WZEstimation->GetBinContent(5)/ WZEstimation->GetBinContent(3);

			Ae[i-2]   = WZEstimation->GetBinContent(8)/ WZEstimation->GetBinContent(7);
			Ee[i-2]   = WZEstimation->GetBinContent(10)/ WZEstimation->GetBinContent(8); 

			Ate[i-2]  = WZEstimation->GetBinContent(15)/ WZEstimation->GetBinContent(13);
			Ete[i-2]  = WZEstimation->GetBinContent(17)/ WZEstimation->GetBinContent(15);

			Atm[i-2] = WZEstimation->GetBinContent(16)/ WZEstimation->GetBinContent(14);
			Etm[i-2] = WZEstimation->GetBinContent(18)/ WZEstimation->GetBinContent(16);

			Allmu[i-2]=WZEstimation->GetBinContent(2);
			Acpmu10[i-2]=WZEstimation->GetBinContent(3);
			Acpmu20[i-2]=WZEstimation->GetBinContent(4);

			Alle[i-2]=WZEstimation->GetBinContent(7);
			Acpe[i-2]=WZEstimation->GetBinContent(8);

			Alltmu[i-2]=WZEstimation->GetBinContent(14);
			Acptmu[i-2]=WZEstimation->GetBinContent(16);

			Allte[i-2]=WZEstimation->GetBinContent(13);
			Acpte[i-2]=WZEstimation->GetBinContent(15);
			Estlostmu[i-2]  = ((Ndata[i-2] -Nbg[i-2])*(1-Amu[i-2]*Emu[i-2])) / (Apmu[i-2]*Epmu[i-2]);
			double Nt=(Ndata[i-2] -Nbg[i-2])/ (Apmu[i-2]*Epmu[i-2]);
			Estloste[i-2] = (Nt*Alle[i-2]*(1-Ae[i-2]*Ee[i-2]))/Allmu[i-2];
			Estlosttm[i-2]=(Nt*Alltmu[i-2]*(1-Atm[i-2]*Etm[i-2]))/Allmu[i-2];
			Estlostte[i-2]=(Nt*Allte[i-2]*(1-Ate[i-2]*Ete[i-2]))/Allmu[i-2];
			Esthad[i-2]=WZEstimation->GetBinContent(12) - (WZEstimation->GetBinContent(13) +  WZEstimation->GetBinContent(14));
		}

		double deltaApmu[8], deltaEpmu[8], deltaEmu[8], deltaAmu[8], deltaAe[8], deltaEe[8], deltaNt[8];
		double deltaAtm[8], deltaEtm[8], deltaAte[8], deltaEte[8], deltaAhad[8], deltaEhadte[8];
		double Ahadt[8]={0.2, 0.2, 0.2, 0.21, 0.22,0.22, 0.22, 0.23};
		double Ehadt[8]={0.47, 0.47, 0.48, 0.49, 0.51, 0.48, 0.49, 0.38};

		double totalAhad[8]={15162.,15162., 5637., 2323., 1050., 508., 274., 127.};
		double totalEhad[8]={2989., 2923., 1131.,499., 228., 112., 61., 29};
		double Esthad1[8]={4652.,4652., 1653., 676., 289., 143., 78., 37.};

		for(int i=0; i<8; i++)
		{
			//Muon
			double errdata = sqrt(Ndata[i])/pow(Ndata[i]-Nbg[i], 1);
			double   errbg = Nbg[i]/(2*pow(Ndata[i]-Nbg[i], 1));
			deltaApmu[i] = sqrt(pow(sqrt(Apmu[i]*(1-Apmu[i])/Allmu[i]),2)+pow(0.02*Apmu[i],2));
			deltaEpmu[i] = sqrt(pow(sqrt(Epmu[i]*(1-Epmu[i])/Acpmu20[i]),2)+pow(0.02*Epmu[i],2));
			deltaAmu[i] = sqrt(pow(sqrt(Amu[i]*(1-Amu[i])/Allmu[i]),2));
			deltaEmu[i] = sqrt(pow(sqrt(Emu[i]*(1-Emu[i])/Acpmu10[i]),2));
			deltaNt[i]=sqrt(pow(errdata,2)+pow(errbg,2)+pow(deltaApmu[i]/Apmu[i],2)+pow(deltaEpmu[i]/Epmu[i],2));
			double errlostmu=sqrt(pow(deltaNt[i],2)+pow(deltaAmu[i]*Emu[i]/(1-Amu[i]*Emu[i]),2)+pow(deltaEmu[i]*Amu[i]/(1-Amu[i]*Emu[i]),2)+
								  (deltaApmu[i]*deltaAmu[i]*Emu[i])/(Apmu[i]*(1-Amu[i]*Emu[i]))+(deltaEpmu[i]*deltaEmu[i]*Amu[i])/(Epmu[i]*(1-Amu[i]*Emu[i])));
			
			cout.precision(3);
			cout<<"A: "<<deltaApmu[i]/Apmu[i]<<" E: "<<deltaEpmu[i]/Epmu[i]<<" Data: "<<errdata<<" BG: "<<errbg<<endl;
			//Electron
			deltaAe[i] = sqrt(pow(sqrt(Ae[i]*(1-Ae[i])/Alle[i]),2)+pow(0.02*Ae[i],2));
			deltaEe[i] = sqrt(pow(sqrt(Ee[i]*(1-Ee[i])/Acpe[i]),2)+pow(0.02*Ee[i],2));
			double errloste=sqrt(pow(deltaNt[i],2)+pow(Alle[i],-1)+pow(Allmu[i],-1)+pow(deltaAe[i]*Ee[i]/(1-Ae[i]*Ee[i]),2)+pow(deltaEe[i]*Ae[i]/(1-Ae[i]*Ee[i]),2));

			//Tau Decay to muon
			deltaAtm[i] = sqrt(pow(sqrt(Atm[i]*(1-Atm[i])/Alltmu[i]),2)+pow(0.02*Atm[i],2));
			deltaEtm[i] = sqrt(pow(sqrt(Etm[i]*(1-Etm[i])/Acptmu[i]),2)+pow(0.02*Etm[i],2));
			double errlosttmu=sqrt(pow(deltaNt[i],2)+pow(Alltmu[i],-1)+pow(Allmu[i],-1)+pow(deltaAtm[i]*Etm[i]/(1-Atm[i]*Etm[i]),2)+pow(deltaEtm[i]*Atm[i]/(1-Atm[i]*Etm[i]),2));

			//Tau Decay to electron
			deltaAte[i] = sqrt(pow(sqrt(Ate[i]*(1-Ate[i])/Allte[i]),2)+pow(0.02*Ate[i],2));
			deltaEte[i] = sqrt(pow(sqrt(Ete[i]*(1-Ete[i])/Acpte[i]),2)+pow(0.02*Ete[i],2));
			double errlostte=sqrt(pow(deltaNt[i],2)+pow(Allte[i],-1)+pow(Allmu[i],-1)+pow(deltaAte[i]*Ete[i]/(1-Ate[i]*Ete[i]),2)+pow(deltaEte[i]*Ate[i]/(1-Ate[i]*Ete[i]),2));

			//Tau Decay Hadronic

			deltaAhad[i] = sqrt(pow(sqrt(Ahadt[i]*(1-Ahadt[i])/totalAhad[i]),2)+pow(0.02*Ahadt[i],2));
			deltaEhadte[i] = sqrt(pow(sqrt(Ehadt[i]*(1-Ehadt[i])/totalEhad[i]),2)+pow(0.08*Ehadt[i],2));
			double errlosthad=sqrt(pow(deltaNt[i],2)+pow(Esthad[i],-1)+pow(Allmu[i],-1)+pow(deltaAhad[i]*Ehadt[i]/(1-Ahadt[i]*Ehadt[i]),2)+pow(deltaEhadte[i]*Ahadt[i]/(1-Ahadt[i]*Ehadt[i]),2));

			double totalerr=sqrt(pow(errloste*Estloste[i],2)+pow(errlostmu*Estlostmu[i],2)+pow(errlosttmu*Estlosttm[i],2)+pow(errlostte*Estlostte[i],2)+pow(Esthad[i],1));

			cout<<"ErrNobs = "<<errdata<<", ErrNbck = "<<errbg<<endl;
			cout<<"MUON Aprime: "<<deltaApmu[i]<<", EPrime: "<<deltaEpmu[i]<<", A: "<<deltaAmu[i]<<", E: "<<deltaEmu[i]<<", Total Err: "<<errlostmu<<endl;
			cout<<"ELEC A: "<<deltaAe[i]<<", E: "<<deltaEe[i]<<", Total Err: "<<errloste<<endl;
			cout<<"Tau-Elec A: "<<deltaAtm[i]<<", E: "<<deltaEtm[i]<<", Total Err: "<<errlostte<<endl;
			cout<<"Tau-Muon A: "<<deltaAte[i]<<", E: "<<deltaEte[i]<<", Total Err: "<<errlosttmu<<endl;
			cout<<"Tau-Hadronic A: "<<deltaAhad[i]<<", E: "<<deltaEhadte[i]<<endl;
			printf("%8s %10s%2.0f  %10s%1.0f  %10s%1.0f  %10s%1.0f  %10s%1.0f  %10s%1.0f\n",met[i].c_str(),"Muon Err: ",errlostmu*Estlostmu[i],"Elect Err: ",errloste*Estloste[i],"TauMu Err: ",errlosttmu*Estlosttm[i],"TauElec Err: ",errlostte*Estlostte[i],"TauHad Err: ",sqrt(Esthad[i]),"Total Err: ",totalerr);
		}
	}
	if(k=="z")
	{
	  /*
	  double Ndata[8], Nbg[8], NbgErr[8], Alldimu[8], Actdimu[8], A[8], E[8];
	  string met[8]={"Met200","Met250","Met300","Met350","Met400","Met450","Met500","Met550",};
	  for(int i=2;i<10;i++)
	    {
	      char file1[200], file2[200], file3[200], file4[200], file5[200], file6[200];
	      sprintf(file1,"zjets_WZTauAnalysis_%d.root", i);	
	      sprintf(file3,"data_%d.root", i);
	      
	      sprintf(file2,"wjets_%d.root", i);
	      sprintf(file4,"ttbar_WZTauAnalysis_%d.root", i);
	      sprintf(file5,"sint_%d.root", i);
	      sprintf(file6,"qcd_%d.root", i);
	      
	      TFile f1( file1 );
	      TFile f3( file3 );
	      
	      TFile f2( file2 );
	      TFile f4( file4 );
	      TFile f5( file5 );
	      TFile f6( file6 );
	      TH1D*  data = (TH1D*) f3.Get("ZleplepMT_60_120");
	      
	      TH1D*  bg   = (TH1D*) f2.Get("ZleplepMT_60_120");
	      TH1D*  bg1  = (TH1D*) f4.Get("ZleplepMT_60_120");
	      TH1D*  bg2  = (TH1D*) f5.Get("ZleplepMT_60_120");
	      TH1D*  bg3  = (TH1D*) f6.Get("ZleplepMT_60_120");
	      Ndata[i-2]  = data->Integral(); 
	      Nbg[i-2]    = bg->Integral()+bg1->Integral()+bg2->Integral()+bg3->Integral(); 
	      NbgErr[i-2] = sqrt(pow(bg->Integral(),2)+pow(bg1->Integral(),2)+pow(bg2->Integral(),2)+pow(bg3->Integral(),2)); 
	      

	      TH1D*  obs = (TH1D*) f1.Get("ZleplepMT_60_120");
	      TH1D*  alldimu = (TH1D*)f1.Get("WZEstimation");
	      TH1D*  accpt = (TH1D*)f1.Get("WZEstimation");
	      
	      Alldimu[i-2] = 3.9 * alldimu->GetBinContent(2)/2;
	      Actdimu[i-2] = 3.9 * accpt->GetBinContent(4)/2;
	      A[i-2]       = Actdimu[i-2]/Alldimu[i-2];
	      E[i-2]       = 3.9 * obs->Integral()/Actdimu[i-2];
	    }
	  
	  double Nest[8], NestErr[8];
	  for(int i=0; i<8;i++)
	    {
	      //cout<<"A: "<<A[i]<<" E: "<<E[i]<<" Data: "<<Ndata[i]<<" BG: "<<Nbg[i]<<endl;
	      double errdata = sqrt(Ndata[i])/pow(Ndata[i]-Nbg[i], 1);
	      double   errbg = NbgErr[i]/pow(Ndata[i]-Nbg[i], 1);
	      double  deltaA = sqrt(pow(sqrt(A[i]*(1-A[i])/Alldimu[i]),2)+pow(0.02*A[i],2))/A[i];
	      double  deltaE = sqrt(pow(sqrt(E[i]*(1-E[i])/Actdimu[i]),2)+pow(0.02*E[i],2))/E[i];
	      Nest[i]=(Ndata[i]-Nbg[i])*5.942/(A[i]*E[i]);
	      //Nest[i]=1.03*Nest[i];
	      NestErr[i]=sqrt(pow(errdata,2)+pow(errbg,2)+pow(deltaA,2)+pow(deltaE,2)+2*deltaA*deltaE);
	      printf("%7s %10s%1.3f %10s%1.3f %10s%1.5f %10s%1.5f %10s%1.0f %10s%1.3f\n",met[i].c_str(),"Data Err: ",errdata,"BG Err: ",errbg,"Accpt Err: ",deltaA,"Eff Err: ",deltaE,"Est Znunu: ",Nest[i],"Est Err: ",NestErr[i]*Nest[i]);
	    } 
	  */
	  double Ndata[8], Nbg[8], Nbg1[8], Alldimu[8], Actdimu[8], A[8], E[8];
	  string met[8]={"Met200","Met250","Met300","Met350","Met400","Met450","Met500","Met550",};
	  for(int i=2;i<10;i++)
	    {
	      char file1[200], file2[200], file3[200], file4[200], file5[200], file6[200];
	      sprintf(file1,"zjets_WZTauAnalysis_%d.root", i);	
	      sprintf(file3,"data_%d.root", i);
	      sprintf(file2,"wjets_%d.root", i);
	      sprintf(file4,"ttbar_WZTauAnalysis_%d.root", i);
	      sprintf(file5,"sint_%d.root", i);
	      sprintf(file6,"qcd_%d.root", i);

	      TFile f1( file1 );
	      TFile f3( file3 );
	      TFile f2( file2 );
	      TFile f4( file4 );
	      TFile f5( file5 );
	      TFile f6( file6 );
	      TH1D*  data = (TH1D*) f3.Get("ZleplepMT_60_120");
	      TH1D*  bg   = (TH1D*) f2.Get("ZleplepMT_60_120");
	      TH1D*  bg1   = (TH1D*) f4.Get("ZleplepMT_60_120");
	      TH1D*  bg2   = (TH1D*) f5.Get("ZleplepMT_60_120");
	      TH1D*  bg3   = (TH1D*) f6.Get("ZleplepMT_60_120");
	      Ndata[i-2]= data->Integral();  
	      Nbg1[i-2]  = sqrt(pow(bg->Integral(),2)+pow(bg1->Integral(),2)+pow(bg2->Integral(),2)+pow(bg3->Integral(),2)); 
	      Nbg[i-2]  = pow(bg->Integral(),1)+pow(bg1->Integral(),1)+pow(bg2->Integral(),1)+pow(bg3->Integral(),1); 
	      TH1D*  obs = (TH1D*) f1.Get("ZleplepMT_60_120");
	      TH1D*  alldimu = (TH1D*)f1.Get("WZEstimation");
	      TH1D*  accpt = (TH1D*)f1.Get("WZEstimation");
	      Alldimu[i-2]=(3.9*alldimu->GetBinContent(2))/2;
	      Actdimu[i-2]=(3.9*accpt->GetBinContent(4))/2;
	      A[i-2]=(Actdimu[i-2])/Alldimu[i-2];
	      E[i-2]=(3.9*obs->Integral())/Actdimu[i-2];
	    }
	  double Nest[8], NestErr[8];
	  for(int i=0; i<8;i++)
	    {
	      //   cout<<"A: "<<A[i]<<" E: "<<E[i]<<" Data: "<<Ndata[i]<<" BG: "<<Nbg[i]<<endl;
	      double errdata = sqrt(Ndata[i])/pow(Ndata[i]-Nbg[i], 1);
	      double   errbg = Nbg1[i]/pow(Ndata[i]-Nbg[i], 1);
	      double  deltaA = sqrt(pow(sqrt(A[i]*(1-A[i])/Alldimu[i]),2)+pow(0.02*A[i],2))/A[i];
	      double  deltaE = sqrt(pow(sqrt(E[i]*(1-E[i])/Actdimu[i]),2)+pow(0.02*E[i],2))/E[i];
	      Nest[i]=(1.092*Ndata[i]-Nbg[i])*5.942/(A[i]*E[i]);
	      //Nest[i]=1.03*Nest[i];
	      NestErr[i]=sqrt(pow(errdata,2)+pow(errbg,2)+pow(deltaA,2)+pow(deltaE,2)+2*deltaA*deltaE+pow(0.02,2));
	      printf("%7s %10s%1.3f %10s%1.3f %10s%1.5f %10s%1.5f %10s%1.0f %10s%1.3f\n",met[i].c_str(),"Data Err: ",errdata,"BG Err: ",errbg,"Accpt Err: ",deltaA,"Eff Err: ",deltaE,"Est Znunu: ",Nest[i],"Est Err: ",NestErr[i]*Nest[i]);
	    } 
	  cout<<" "<<endl;
	  cout<<"| *Value* | *"
	      <<met[1].c_str()<<"* | *"
	      <<met[2].c_str()<<"* | *"
	      <<met[3].c_str()<<"* | *"
	      <<met[4].c_str()<<"* | *"
	      <<met[5].c_str()<<"* | *"
	      <<met[6].c_str()<<"* | *"
	      <<met[7].c_str()<<"* | "<<endl;
	  cout<<"| Nobs  | "
	      <<Ndata[1]<<" | "
	      <<Ndata[2]<<" | "
	      <<Ndata[3]<<" | "
	      <<Ndata[4]<<" | "
	      <<Ndata[5]<<" | "
	      <<Ndata[6]<<" | "
	      <<Ndata[7]<<" | "
	      <<endl;
	  cout<<"| Nbgb  | "
	      <<(Int_t) (Nbg[1]+0.5)<<" | "
	      <<(Int_t) (Nbg[2]+0.5)<<" | "
	      <<(Int_t) (Nbg[3]+0.5)<<" | "
	      <<(Int_t) (Nbg[4]+0.5)<<" | "
	      <<(Int_t) (Nbg[5]+0.5)<<" | "
	      <<(Int_t) (Nbg[6]+0.5)<<" | "
	      <<(Int_t) (Nbg[7]+0.5)<<" | "<<endl;
	  cout<<"| Acc   | "
	      <<setiosflags(ios::fixed | ios::showpoint | ios::right)<<setprecision(3)
	      <<A[1]<<" | "
	      <<A[2]<<" | "
	      <<A[3]<<" | "
	      <<A[4]<<" | "
	      <<A[5]<<" | "
	      <<A[6]<<" | "
	      <<A[7]<<" | "<<endl;
	  cout<<"| Eff   | "
	      <<E[1]<<" | "
	      <<E[2]<<" | "
	      <<E[3]<<" | "
	      <<E[4]<<" | "
	      <<E[5]<<" | "
	      <<E[6]<<" | "
	      <<E[7]<<" | "<<endl;
	  cout<<"| R     | 5.942 | 5.942 | 5.942 | 5.942 | 5.942 | 5.942 | 5.942 |"<<endl;
	  cout<<"| MC/Data | 1.092 | 1.092 | 1.092 | 1.092 | 1.092 | 1.092 | 1.092 |"<<endl;
	  cout<<"| N(Znunu) | "
	      <<(Int_t) (Nest[1]+0.5)<<" | "
	      <<(Int_t) (Nest[2]+0.5)<<" | "
	      <<(Int_t) (Nest[3]+0.5)<<" | "
	      <<(Int_t) (Nest[4]+0.5)<<" | "
	      <<(Int_t) (Nest[5]+0.5)<<" | "
	      <<(Int_t) (Nest[6]+0.5)<<" | "
	      <<(Int_t) (Nest[7]+0.5)<<" | "<<endl;
	  cout<<"| ErrN(Znunu) | "
	      <<(Int_t) (NestErr[1]*Nest[1])<<" | "
	      <<(Int_t) (NestErr[2]*Nest[2])<<" | "
	      <<(Int_t) (NestErr[3]*Nest[3])<<" | "
	      <<(Int_t) (NestErr[4]*Nest[4])<<" | "
	      <<(Int_t) (NestErr[5]*Nest[5])<<" | "
	      <<(Int_t) (NestErr[6]*Nest[6])<<" | "
	      <<(Int_t) (NestErr[7]*Nest[7])<<" | "<<endl;
	}
}
