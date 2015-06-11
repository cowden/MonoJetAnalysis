{




	TFile f1("Cert_160404_177515_pileup.root");
	TH1D*  his = (TH1D*) f1.Get("pileup")->Clone();


	TH1D* his2 = new TH1D("his2", "", 35, 0,35); 


	double  a[35];

	for(int i=0; i<35; i++)
	{
		double a[i] = his->GetBinContent( i );


		cout << a[i] <<  "  .  " <<endl;



		
	}


	TFile f2("savehisto.root","recreate") ;

       

	double b[35];

	b[0]= a[0];

	for(int i=1; i<35; i++)
	{
	        b[i]= b[i-1]*0.1 +a[i];

		
		
		his2->SetBinContent( i, b[i] );

		cout << b[i-1] <<  "  .  " <<endl; 

		
		
	}

       
	his2->Write();


}
