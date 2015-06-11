{




	TFile f1("data.root");
	TH1D*  his1 = (TH1D*) f1.Get("NPV")->Clone();

	
	TFile f2("pudist.root");
	TH1D*  his2 = (TH1D*) f2.Get("pileup")->Clone();


	double t=0;

	for(int i=1; i<25; i++)
	{
		double a1 = his1->GetBinContent( i );
		double a2 = his2->GetBinContent( i );

		if(a1>0.) cout << a2/a1   <<endl; 


		
	}





}
