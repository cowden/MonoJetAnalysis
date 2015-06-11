{

	//Settings:
	gROOT->Reset();
	gROOT->ProcessLine(".L ../bin/tdrStyle.C");
	gROOT->ProcessLine("setTDRStyle()");
	
	TLatex l; l.SetTextSize(0.05);
	TCanvas *c1 = new TCanvas("ADD xsec", "ADD xsec");
	c1->SetGrid();
	c1->SetLogy();
	
	
	//-----------------------
	
	Float_t kf=1.5;
	
	Double_t  MD[4]={1., 2., 3., 4.};
	Double_t  dMD[4]={0. 0.,0.,0.};
	
	// Theo XSEC :
	
	Double_t  Theo_XS_d2_k[4]={210.5*kf, 9.894*kf, 1.356*kf, 0.3241*kf};
	Double_t  Theo_XS_d2[4]={210.5, 9.894, 1.356, 0.3241};
	Double_t  dTheo_XS_d2[4]={0.5  , 0.052 , 0.005 , 0.0012};
	
	TGraphErrors *Theo_vs_MD_d2 = new TGraphErrors(4, MD, Theo_XS_d2, dMD, dTheo_XS_d2);
	TGraphErrors *Theo_vs_MD_d2_k = new TGraphErrors(4, MD, Theo_XS_d2_k, dMD, dTheo_XS_d2);
	
	Theo_vs_MD_d2->SetLineWidth(4); Theo_vs_MD_d2->SetLineStyle(1);
	
	Theo_vs_MD_d2->SetLineColor(kBlue);
	Theo_vs_MD_d2_k->SetLineWidth(4); Theo_vs_MD_d2_k->SetLineStyle(2);
	Theo_vs_MD_d2_k->SetLineColor(kBlue);
	
	
	Theo_vs_MD_d2->GetYaxis()->SetRangeUser(0.11,1000.); 
	Theo_vs_MD_d2->GetXaxis()->SetRangeUser(0.,5.);
	Theo_vs_MD_d2->GetXaxis()->SetTitleSize(0.06); 
	Theo_vs_MD_d2->GetXaxis()->SetLabelSize(0.04); 
	Theo_vs_MD_d2->GetXaxis()->SetTitle("M_{D} (TeV)");
	Theo_vs_MD_d2->GetYaxis()->SetTitleSize(0.06); 
	Theo_vs_MD_d2->GetYaxis()->SetLabelSize(0.04); 
	Theo_vs_MD_d2->GetYaxis()->SetTitle("#sigma (pb)");
	
	Theo_vs_MD_d2->GetYaxis()->SetNdivisions(-3);
	
	Theo_vs_MD_d2->SetMinimum(0.03);
	Theo_vs_MD_d2->SetMaximum(400.);
	Theo_vs_MD_d2->GetXaxis()->SetNdivisions(4);
	
	Theo_vs_MD_d2->Draw("AC"); 
	
	
	
	l.SetTextFont(42.);
	l.DrawLatex(3,20.,"ADD, #delta=3");
	
	
	//-----------------------

  
	const Int_t n = 4;
	
	Double_t  M_D[n]={1.,2.,3.,4.};
	
	Double_t  Expect_2_2sUp[n]={5.43071, 2.85392, 2.7572, 2.79513};
	Double_t  Expect_2_2sDown[n]={0.801409, 0.43381, 0.462267, 0.461408};
	
	Double_t  Expect_2_1sUp[n]={3.74821, 2.05917, 1.98255, 2.00118};
	Double_t  Expect_2_1sDown[n]={1.71486, 1.01171, 0.964327, 0.962047};
	
	Double_t  Expect_2[n]={2.52747, 1.4121, 1.35276, 1.34978};
	
	
	TGraph *Expect_vs_MD_2_2sDown = new TGraph(n,M_D,Expect_2_2sDown);
	TGraph *Expect_vs_MD_2_2sUp   = new TGraph(n,M_D,Expect_2_2sUp);
	TGraph *Expect_vs_MD_2_1sDown = new TGraph(n,M_D,Expect_2_1sDown);
	TGraph *Expect_vs_MD_2_1sUp   = new TGraph(n,M_D,Expect_2_1sUp);
	TGraph *Expect_vs_MD_2        = new TGraph(n,M_D,Expect_2);

	TGraph *grshade_2 = new TGraph(2*n);
	TGraph *grshade_1 = new TGraph(2*n);


	for (int i=0;i<n;i++)
	{
		grshade_2->SetPoint(i, M_D[i],Expect_2_2sUp[i] );
		grshade_2->SetPoint(n+i,M_D[n-i-1],Expect_2_2sDown[n-i-1]);

		grshade_1->SetPoint(i, M_D[i], Expect_2_1sUp[i] );
		grshade_1->SetPoint(n+i, M_D[n-i-1], Expect_2_1sDown[n-i-1]);
	}


	grshade_2->SetFillColor(kYellow);
	grshade_2->Draw("f");
	Expect_vs_MD_2_2sDown->SetLineColor(kYellow); Expect_vs_MD_2_2sUp->SetLineColor(kYellow);
	//Expect_vs_MD_2_2sDown->Draw("C"); Expect_vs_MD_2_2sUp->Draw("C");
	grshade_1->SetFillColor(kGreen);
	grshade_1->Draw("f");
	Expect_vs_MD_2_1sDown->SetLineColor(kGreen); Expect_vs_MD_2_1sUp->SetLineColor(kGreen);
	//Expect_vs_MD_2_1sDown->Draw("C"); Expect_vs_MD_2_1sUp->Draw("C");
	Expect_vs_MD_2->SetLineWidth(4); Expect_vs_MD_2->SetLineStyle(2); Expect_vs_MD_2->SetLineColor(kRed);
	Expect_vs_MD_2->Draw("C");

	// Observed Limit :
	
	Double_t  Obser_2[n]={2.71652, 1.50567, 1.45114, 1.45399};
	
	TGraph *Obser_vs_MD_2 = new TGraph(n, M_D, Obser_2);
	
	Obser_vs_MD_2->SetLineWidth(5); Obser_vs_MD_2->SetLineStyle(1); 
	Obser_vs_MD_2->SetMarkerStyle(8); Obser_vs_MD_2->SetMarkerSize(1.4);
	Obser_vs_MD_2->SetLineColor(kBlack);
	Obser_vs_MD_2->Draw("CP"); //Expected Limit
	
	
	Theo_vs_MD_d2->Draw("C");  Theo_vs_MD_d2_k->Draw("C"); 

	//-----------------------


	TLegend *l2 = new TLegend(0.2,0.15,0.6,0.32);
	l2->AddEntry(Expect_vs_MD_2,"95% CL Expected limits","l");
	l2->AddEntry(Obser_vs_MD_2,"95% CL Observed limits","l");
	l2->AddEntry(Theo_vs_MD_d2,"Theor. prediction (LO)","l");
	l2->AddEntry(Theo_vs_MD_d2_k,"Theor. prediction (NLO)","l");
	l2->SetFillColor(0); 
	l2->SetShadowColor(0);
	l2->SetBorderSize(0); 
	l2->SetTextFont(42.);
	l2->Draw(); 
	


	TLatex *text1, *text2;

	text1 = new TLatex(3.570061,23.08044,"CMS Preliminary");
	text1->SetNDC();
	text1->SetTextAlign(13);
	text1->SetX(0.5);
	text1->SetY(0.92);
	//text1->SetLineWidth(2);
	text1->SetTextFont(72);
	text1->SetTextSizePixels(24);// dflt=28
	text1->Draw();

	text2 = new TLatex(3.570061,23.08044,"#intL dt = 1.1 fb^{-1} at #sqrt{s}=7 TeV");
	text2->SetNDC();
	text2->SetTextAlign(13);
	text2->SetX(0.5);
	text2->SetY(0.86);
	//text2->SetLineWidth(2);
	text2->SetTextFont(42);
	text2->SetTextSize(0.040);// dflt=28
	text2->Draw();


	//c1->SaveAs("LimitsXsec_ADD_d2_2011_MET200.eps");
	//c1->SaveAs("LimitsXsec_ADD_d2_2011_MET200.gif");
	/*
	*/

}