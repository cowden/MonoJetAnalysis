{

	//Settings:
	gROOT->Reset();
	gROOT->ProcessLine(".L ../bin/tdrStyle.C");
	gROOT->ProcessLine("setTDRStyle()");
	
	TLatex l; l.SetTextSize(0.05);
	TCanvas *c1 = new TCanvas("Excl Limits", "Excl Limits");
	c1->SetGrid();
	c1->SetLogy();
	
	Double_t  M_D[4]={1., 2., 3., 4.};
	
	// Theo XSEC :
	
	double kk=1.;

	//Dimension 2 xsec
 	Double_t  Theo_XS_2_0[4]={302.4*kk ,     22.37*kk,       4.456*kk ,       1.411*kk};
    Double_t  Theo_XS_2_1[4]={302.4*kk+0.4,  22.37*kk+0.04,  4.456*kk+0.009,  1.411*kk+0.003};
 	Double_t  Theo_XS_2_2[4]={302.4*kk-0.4,  22.37*kk-0.04,  4.456*kk-0.009,  1.411*kk-0.003};

	//Dimension 3 xsec
 	//Double_t  Theo_XS_2_0[4]={210.5*kk,       9.992*kk ,          1.372*kk       , 0.32248*kk };
 	//Double_t  Theo_XS_2_1[4]={210.5*kk+0.5,   9.992*kk +0.052 ,   1.372*kk+0.005, 0.32248*kk +0.0012 };
 	//Double_t  Theo_XS_2_2[4]={210.5*kk-0.5,   9.992*kk -0.052 ,   1.372*kk-0.005, 0.32248*kk -0.0012 };

	//Dimension 4 xsec
 	//Double_t  Theo_XS_2_0[4]={178.4*kk,       5.889*kk     ,   0.5719*kk,         0.1032*kk   };
 	//Double_t  Theo_XS_2_1[4]={178.4*kk+0.6,   5.889*kk+0.03,   0.5719*kk+0.0027,  0.1032*kk+0.0005  };
 	//Double_t  Theo_XS_2_2[4]={178.4*kk-0.6,   5.889*kk-0.03,   0.5719*kk-0.0027,  0.1032*kk-0.0005  };


	//Dimension 5 xsec
 	//Double_t  Theo_XS_2_0[4]={166.3*kk,      4.053*kk ,          0.2875*kk       , 0.03939*kk };
 	//Double_t  Theo_XS_2_1[4]={166.3*kk+1.,  4.053*kk +0.018 ,   0.2875*kk+0.0014, 0.03939*kk +0.00019 };
 	//Double_t  Theo_XS_2_2[4]={166.3*kk-1.,  4.053*kk -0.018 ,   0.2875*kk-0.0014, 0.03939*kk -0.00019 };

	//Dimension 6 xsec
 	//Double_t  Theo_XS_2_0[4]={177.5*kk,       3.107*kk ,          0.1693*kk       , 0.01778*kk };
 	//Double_t  Theo_XS_2_1[4]={177.5*kk+1.1,   3.107*kk +0.012 ,   0.1693*kk+0.0008, 0.01778*kk +0.00006 };
 	//Double_t  Theo_XS_2_2[4]={177.5*kk-1.1,   3.107*kk -0.012 ,   0.1693*kk-0.0008, 0.01778*kk -0.00006 };



	
	TGraph *Theo_vs_MD_2_0 = new TGraph(4, M_D, Theo_XS_2_0);
	TGraph *Theo_vs_MD_2_1 = new TGraph(4, M_D, Theo_XS_2_1);
	TGraph *Theo_vs_MD_2_2 = new TGraph(4, M_D, Theo_XS_2_1);
	
	Theo_vs_MD_2_0->SetLineWidth(2); Theo_vs_MD_2_0->SetLineStyle(1);
	Theo_vs_MD_2_0->SetLineColor(kBlue);Theo_vs_MD_2_1->SetLineColor(kBlue);Theo_vs_MD_2_2->SetLineColor(kBlue);
	Theo_vs_MD_2_0->Draw("AC"); //theor. xsec error his thinner that the line width
	Theo_vs_MD_2_1->Draw("C");
	Theo_vs_MD_2_2->Draw("C");
	
	// TF1 *fitFunc_1 = new TF1("fitFunc_1","expo");
	// Sign_vs_MD_1->Fit("fitFunc_1");
	// TF1 *fitFunc_2 = new TF1("fitFunc_2","expo");
	// Sign_vs_MD_2->Fit("fitFunc_2");
	
	
	
	
	//Theo_vs_MD_2_0->GetYaxis()->SetRangeUser(0.1.,600.); 
	//Theo_vs_MD_2_0->GetXaxis()->SetRangeUser(0.,12.);
	Theo_vs_MD_2_0->GetXaxis()->SetTitle("M_{D} (TeV)");
	Theo_vs_MD_2_0->GetYaxis()->SetTitle("#sigma (pb)");
	
	



	// Expect Limit :
	

	Double_t  Expect_2[4]={  3.44584, 1.60577, 1.65853, 1.7069   }; //d2
// 	Double_t  Expect_2[4]={  2.25238, 1.28656, 1.22565, 1.22232  }; //d3
// 	Double_t  Expect_2[4]={  2.57067, 1.16687, 1.07838, 1.04924  }; //d4
// 	Double_t  Expect_2[4]={  2.3756,  1.23881, 1.03952, 0.95677  }; //d5
// 	Double_t  Expect_2[4]={  2.51778, 1.27077, 1.04951, 1.01318  }; //d6


    
	TGraph *Expect_vs_MD_2 = new TGraph(4, M_D, Expect_2);
	
	Expect_vs_MD_2->SetLineWidth(4); Expect_vs_MD_2->SetLineStyle(1);
	Expect_vs_MD_2->SetLineColor(kRed);
	Expect_vs_MD_2->Draw("L"); //Expected Limit
	
	// TF1 *fitFunc_1 = new TF1("fitFunc_1","expo");
	// Sign_vs_MD_1->Fit("fitFunc_1");
	// TF1 *fitFunc_2 = new TF1("fitFunc_2","expo");
	// Sign_vs_MD_2->Fit("fitFunc_2");
	


	
	// Observed Limit :


	Double_t  Obser_2[4]={ 4.04, 1.88, 1.94, 2.00  };  //d2
// 	Double_t  Obser_2[4]={ 2.64, 1.51, 1.44, 1.43  };  //d3
// 	Double_t  Obser_2[4]={ 3.01, 1.37, 1.26, 1.23  };  //d4
// 	Double_t  Obser_2[4]={ 2.78, 1.45, 1.22, 1.12  };  //d5
// 	Double_t  Obser_2[4]={ 2.95, 1.49, 1.23, 1.19  };  //d6
// 

	
	TGraph *Obser_vs_MD_2 = new TGraph(4, M_D, Obser_2);
	
	Obser_vs_MD_2->SetLineWidth(4); Obser_vs_MD_2->SetLineStyle(1);
	Obser_vs_MD_2->SetLineColor(kGreen);
	Obser_vs_MD_2->Draw("L"); //Expected Limit
	
	// TF1 *fitFunc_1 = new TF1("fitFunc_1","expo");
	// Sign_vs_MD_1->Fit("fitFunc_1");
	// TF1 *fitFunc_2 = new TF1("fitFunc_2","expo");
	// Sign_vs_MD_2->Fit("fitFunc_2");
	
	
	TLegend *l1 = new TLegend(0.45,0.6,0.95,0.95);

	l1.SetBorderSize(0);
	l1.SetLineStyle(0);
	l1.SetTextFont(42);
	l1.SetFillStyle(0);


	l1->AddEntry(Theo_vs_MD_2_0,"Theor. prediction","l");
	l1->AddEntry(Expect_vs_MD_2,"95% CL Expected limits","l");
	l1->AddEntry(Obser_vs_MD_2,"Observed limits","l");
	l1->Draw(); 
	
	l.DrawLatex(2.,5.,"ADD #delta=2");

	TLatex *text1, *text2;

	text1 = new TLatex(3.570061,23.08044,"CMS Preliminary");
	text1->SetNDC();
	text1->SetTextAlign(13);
	text1->SetX(0.19);
	text1->SetY(0.92);
	//text1->SetLineWidth(2);
	text1->SetTextFont(72);
	text1->SetTextSizePixels(24);// dflt=28
	text1->Draw();

	text2 = new TLatex(3.570061,23.08044,"#intL dt = 1.1 fb^{-1} at #sqrt{s}=7 TeV");
	text2->SetNDC();
	text2->SetTextAlign(13);
	text2->SetX(0.19);
	text2->SetY(0.86);
	//text2->SetLineWidth(2);
	text2->SetTextFont(42);
	text2->SetTextSize(0.040);// dflt=28
	text2->Draw();

	
	c1->SaveAs("Exclusion_7TeV_d2_350_kfac1.eps");

}
