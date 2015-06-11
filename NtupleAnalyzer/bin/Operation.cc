#include "Operation.h"
#include "Histogram01.h"
#include "Histogram02.h"
#include <iostream>
#include <fstream>

#include <TH1D.h>
#include <math.h>
#include <TLorentzVector.h>

#include <memory>

#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/deltaPhi.h"

using namespace std;

namespace Operation 
{
  
  /// ----------------------------------------------
  /// PU Reweighting factor
  vector<double> generate_flat10_weights(TH1D* data_npu_estimated, int puVersion){
    
    /*
    //Array for 1D  reweight
    //S7 - Modify
      const double npu_probs[60] = {
      3.0066e-05, 6.16847e-05, 0.000128875, 0.000269747, 0.000450567, 0.000716926, 0.0010533,   0.00157797,  0.00225834, 0.00316597,
      0.00436889, 0.0059542,   0.00781646,  0.0101815,   0.0126519,   0.0156465,   0.0186337,   0.021965,    0.0251456,  0.0283688,
      0.0313802,  0.0342184,   0.0365446,   0.0386875,   0.0402083,   0.0413358,   0.042339,    0.0426038,   0.0426671,  0.0420323,
      0.0411957,  0.0398011,   0.0384753,   0.036454,    0.034453,    0.0321174,   0.02968,     0.0270858,   0.0245988,  0.0219999,
      0.0194784,  0.0170617,   0.0149901,   0.0127694,   0.0109517,   0.0091755,   0.00765088,  0.00629721,  0.00516557, 0.00422096,
      0.00337558, 0.00266176,  0.00209516,  0.0016254,   0.00125981,  0.000948703, 0.000712127, 0.000533284, 0.00040568, 0.000297272
      }; 
    */
    double npu_probs[60];
    
    //Official Pileup 
    if(puVersion==7){ //S7
      cout<<"S7 PU condition"<<endl;
      double npu_probs_temp[60] = {
	2.344E-05, 2.344E-05, 2.344E-05, 2.344E-05, 4.687E-04, 4.687E-04, 7.032E-04, 9.414E-04, 1.234E-03, 1.603E-03,
	2.464E-03, 3.250E-03, 5.021E-03, 6.644E-03, 8.502E-03, 1.121E-02, 1.518E-02, 2.033E-02, 2.608E-02, 3.171E-02,
	3.667E-02, 4.060E-02, 4.338E-02, 4.520E-02, 4.641E-02, 4.735E-02, 4.816E-02, 4.881E-02, 4.917E-02, 4.909E-02,
	4.842E-02, 4.707E-02, 4.501E-02, 4.228E-02, 3.896E-02, 3.521E-02, 3.118E-02, 2.702E-02, 2.287E-02, 1.885E-02,
	1.508E-02, 1.166E-02, 8.673E-03, 6.190E-03, 4.222E-03, 2.746E-03, 1.698E-03, 9.971E-04, 5.549E-04, 2.924E-04,
	1.457E-04, 6.864E-05, 3.054E-05, 1.282E-05, 5.081E-06, 1.898E-06, 6.688E-07, 2.221E-07, 6.947E-08, 2.047E-08
      };
      for(int i=0; i<60; i++)
	npu_probs[i] = npu_probs_temp[i];
    }
    else if(puVersion==10){ //S10 
      cout<<"S10 PU condition"<<endl;
      double npu_probs_temp[60] = {
	2.56e-06, 5.239e-06, 1.42e-05, 5.005e-05, 0.0001001, 0.0002705, 0.001999,  0.006097,  0.01046,   0.01383,
	0.01685,  0.02055,   0.02572,  0.03262,   0.04121,   0.04977,   0.05539,   0.05725,   0.05607,   0.05312,
	0.05008,  0.04763,   0.04558,  0.04363,   0.04159,   0.03933,   0.03681,   0.03406,   0.03116,   0.02818,
	0.02519,  0.02226,   0.01946,  0.01682,   0.01437,   0.01215,   0.01016,   0.0084,    0.006873,  0.005564,
	0.004457, 0.003533,  0.002772, 0.002154,  0.001656,  0.001261,  0.0009513, 0.0007107, 0.0005259, 0.0003856,
	0.0002801,0.0002017, 0.0001439,0.0001017, 7.126e-05, 4.948e-05, 3.405e-05, 2.322e-05, 1.57e-05,  5.005e-06,
      };
      for(int i=0; i<60; i++)
	npu_probs[i] = npu_probs_temp[i];
    }
    else{
      cout<<"Data"<<endl;
      double npu_probs_temp[60] = {
	1., 1., 1., 1., 1., 1., 1., 1., 1., 1.,
	1., 1., 1., 1., 1., 1., 1., 1., 1., 1.,
	1., 1., 1., 1., 1., 1., 1., 1., 1., 1.,
	1., 1., 1., 1., 1., 1., 1., 1., 1., 1.,
	1., 1., 1., 1., 1., 1., 1., 1., 1., 1.,
	1., 1., 1., 1., 1., 1., 1., 1., 1., 1.
      };
      for(int i=0; i<60; i++)
	npu_probs[i] = npu_probs_temp[i];
    }
    
    vector<double> result(60);
    double s = 0.0;
    for(int npu=0; npu<60; ++npu){
      double npu_estimated = data_npu_estimated->GetBinContent(data_npu_estimated->GetXaxis()->FindBin(npu));
      result[npu] = npu_estimated / npu_probs[npu];
      s += npu_estimated;
    }
    // normalize weights such that the total sum of weights over thw whole sample is 1.0, i.e., sum_i  result[i] * npu_probs[i] should be 1.0 (!)
    for(int npu=0; npu<60; ++npu){
      result[npu] /= s;
    }
    return result;
  }
  
  
  /// ----------------------------------------------
  /// PFMuon Tight Selection
  bool PFMuonTightCuts(EventData& ev , int i, double pt, double eta){
    /*
      bool  pass    = false;
      bool  passIso = false;
      bool  passKin = false;
      //bool  passVtx = false;
      bool  passID  = false;
      
      float Iso = 0.0;
      Iso = (ev.PFMuonNeutralHadronIso(i) + ev.PFMuonChargedHadronIso(i) + ev.PFMuonPhotonIso(i))/ev.PFMuonPt(i);
      
      if(Iso <  0.2 ) 
      passIso = true;
      if(ev.PFMuonPt(i) > pt && fabs(ev.PFMuonEta(i)) < eta )  
      passKin = true;
      
      //float dxy     = ev.PFMuondxy(i);
      //float dz      = ev.PFMuondz(i);
      //if(fabs(dxy) < 0.02  && fabs(dz) < 1.0 ) passVtx = true;
      //if(ev.PFMuonisGMPT(i) && ev.PFMuonnValidHits(i) >= 11 ) passID = true;
      
      if( ev.PFMuonIsTracker(i)==1 && 
      ev.PFMuonIsGlobal(i)==1 && 
      ev.PFMuonNumOfMatches(i)>1  && 
      ev.PFMuonCombChi2Norm(i) < 10.0  &&
      ev.PFMuonTrkDxy(i)< 0.2 && 
      ev.PFMuonTrkValidHits(i) > 10 && 
      ev.PFMuonTrkNumOfValidPixHits(i) > 0  &&  
      ev.PFMuonStandValidHits(i) >0 )  
      passID = true; 
      
      if(passKin && passIso && passID) 
      pass = true;
      
      return pass;
    */
    bool  pass    = false;
    bool  passID  = false;
    bool  passKin = false;
    bool  passIso = false;
    
    if(ev.PFMuonIsTight(i)>0)
      passID = true;
    
    if(ev.PFMuonPt(i)>pt && fabs(ev.PFMuonEta(i))<eta)
      passKin = true;
    
    float Iso = (ev.PFMuonR04ChargedHadronPt(i) + std::max(0., ev.PFMuonR04NeutralHadronEt(i) + ev.PFMuonR04PhotonEt(i) - 0.5*ev.PFMuonR04PUPt(i)))/ev.PFMuonPt(i);
    if(Iso <  0.12)
      passIso = true;
    
    if(passID && passKin && passIso) 
      pass = true;
    
    return pass;
  }
  
  
  /// ----------------------------------------------
  /// PFMuon Loose Selection 
  bool PFMuonLooseCuts(EventData& ev , int i, double pt, double eta){
    /*
      bool  pass    = false;
      bool  passKin = false;
      bool  passID  = false;
      
      if(ev.PFMuonPt(i) > pt && fabs(ev.PFMuonEta(i)) < eta )  
      passKin = true;
      
      if( ev.PFMuonIsTracker(i)==1 || ev.PFMuonIsGlobal(i)==1 )  
      passID = true; 
      
      if(passKin && passID) 
      pass = true;
      
      return pass;
    */
    bool  pass    = false;
    bool  passID  = false;
    bool  passKin = false;
    bool  passIso = false;
    
    if(ev.PFMuonIsLoose(i)>0)
      passID = true;
    
    if(ev.PFMuonPt(i)>pt && fabs(ev.PFMuonEta(i))<eta)
      passKin = true;
    
    float Iso = (ev.PFMuonR04ChargedHadronPt(i) + std::max(0., ev.PFMuonR04NeutralHadronEt(i) + ev.PFMuonR04PhotonEt(i) - 0.5*ev.PFMuonR04PUPt(i)))/ev.PFMuonPt(i);
    if(Iso <  0.20)
      passIso = true;
    
    if(passID && passKin && passIso) 
      pass = true;
    
    return pass;
  }
  
  
  /// ----------------------------------------------
  /// PFElectron Tight Selection 
  bool PFElecTightCuts(EventData& ev , int i, double pt, double eta){
    
    bool  pass    = false;
    bool  passID  = false;
    bool  passKin = false;
    bool  passIso = false;
    
    if(ev.PFElecIsTight(i)>0){
      passID  = true;
      passIso = true; //Already calculated in EGammaTools
    }
    
    if(ev.PFElecPt(i)>pt && fabs(ev.PFElecEta(i))<eta)
      passKin = true;
    
    if(passID && passKin && passIso) 
      pass = true;
    
    return pass;
    
    /*
    // kinematic and fiducial
    float cutE_pt              = pt;
    float cutE_eta             = eta;
    float cutE_etagap[2]       = {1.4442,1.5666};
    
    //WP80 ID
    float cutE_EB_hadem        = 0.12;
    float cutE_EE_hadem        = 0.10;
    
    //float cutE_EB_combiso      = 0.07;
    //float cutE_EE_combiso      = 0.06;
    
    float cutE_EB_ietaieta     = 0.01;
    float cutE_EE_ietaieta     = 0.03;
    
    float cutE_EB_deta         = 0.004;
    float cutE_EE_deta         = 0.007;
    
    float cutE_EB_dphi         = 0.06;
    float cutE_EE_dphi         = 0.03;
    
    float cutE_dxy             = 0.02;
    float cutE_dz              = 0.10;
    
    //conversion rejection
    int cutE_innerhits         = 0;
    float cutE_dcot            = 0.02;
    float cutE_dist            = 0.02;
    
    //PF ID
    float cutE_EB_combiso_PF   = 0.2;
    //float cutE_EE_combiso_PF   = 0.11;
    
    //float cutE_EB_MVA_PF       = 0.34;
    //float cutE_EE_MVA_PF       = 0.32;
    
    bool useWP95ID = false;
    
    //if(useWP95ID){
    //
    //float cutE_EB_hadem        = 0.15;
    //float cutE_EE_hadem        = 0.07;
    //
    //float cutE_EB_ietaieta     = 0.01;
    //float cutE_EE_ietaieta     = 0.03;
    //
    //float cutE_EB_deta         = 0.007;
    //float cutE_EE_deta         = 0.01;
    //
    //float cutE_EB_dphi         = 0.8;
    //float cutE_EE_dphi         = 0.7;
    //
    //float cutE_dxy             = 0.02;
    //float cutE_dz              = 1.0;
    //
    ////conversion rejection
    //int cutE_innerhits         = 1;
    //float cutE_dcot            = 0.02;
    //float cutE_dist            = 0.02;
      
    ////PF ID
    //float cutE_EB_combiso_PF   = 0.2;
    ////float cutE_EE_combiso_PF   = 0.11;
    //}

    bool pass      = false;
    bool passID    = false;
    bool passIso   = false;
    bool passKin   = false;
    bool passCR    = false;
    //bool conv      = false;
    bool passVtx   = false;
    float Iso      = 0.0;
    float dxy      = ev.PFElecdxy(i);
    float dz       = ev.PFElecdz(i);
    int innerhits  = ev.PFElecInnerHits(i);
    float ietaieta = ev.PFElecietaieta(i);
    float deltaphi = ev.PFElecDPhiSuTrAtVtx(i);
    float deltaeta = ev.PFElecDEtaSuTrAtVtx(i);
    float hadEm    = ev.PFElecHcalOverEcal(i);
    
    Iso = (ev.PFElecNeuHadIso(i) + ev.PFElecCharHadIso(i) + ev.PFElecPhoIso(i) )/ev.PFElecPt(i);
    if(Iso < cutE_EB_combiso_PF) passIso = true;
    if(ev.PFElecPt(i) > cutE_pt && fabs(ev.PFElecEta(i) ) < cutE_eta && (fabs(ev.PFElecEta(i)) < cutE_etagap[0] || 
									 fabs(ev.PFElecEta(i)) > cutE_etagap[1]))
      passKin = true;
    
    //		if(ev.PFElecIsEB(i) == 1 && ev.PFElecMva(i) > cutE_EB_MVA_PF) passID =true;
    //		if(ev.PFElecIsEB(i) != 1 && ev.PFElecMva(i) > cutE_EE_MVA_PF) passID =true;
    
    if((ev.PFElecIsEB(i) == 1 && 
	ietaieta < cutE_EB_ietaieta && 
	fabs(deltaphi) <  cutE_EB_dphi &&
	fabs(deltaeta) < cutE_EB_deta && 
	hadEm < cutE_EB_hadem) ||
       (ev.PFElecIsEB(i) != 1 && 
	ietaieta < cutE_EE_ietaieta && 
	fabs(deltaphi) < cutE_EE_dphi &&
	fabs(deltaeta) <  cutE_EE_deta && 
	hadEm <  cutE_EE_hadem))
      passID = true;
    
    if(!useWP95ID){
      if(innerhits <= cutE_innerhits && !(fabs(ev.PFElecConvDcot(i)) < cutE_dcot && fabs(ev.PFElecConvDist(i) ) < cutE_dist))
	passCR = true;
    }
    else{
      if(innerhits <= cutE_innerhits)
	passCR = true;
    }
    
    if(fabs(dxy) < cutE_dxy && fabs(dz) < cutE_dz)
      passVtx = true;
    
    if(passIso && passID && passCR && passKin && passVtx) pass = true;
    
    return pass;
    */
  }
  
  
  /// ----------------------------------------------
  /// PFElectron Loose Selection
  bool PFElecVetoCuts(EventData& ev , int i, double pt, double eta){

    bool  pass    = false;
    bool  passID  = false;
    bool  passKin = false;
    bool  passIso = false;
    
    if(ev.PFElecIsVeto(i)>0){
      passID  = true;
      passIso = true; //Already calculated in EGammaTools
    }
    
    if(ev.PFElecPt(i)>pt && fabs(ev.PFElecEta(i))<eta)
      passKin = true;
    
    if(passID && passKin && passIso) 
      pass = true;
    
    return pass;
    /*
    // kinematic and fiducial
    float cutE_pt              = pt;
    float cutE_eta             = eta;
    float cutE_etagap[2]       = {1.4442,1.5666};
    
    // Veto WP95
    float cutE_EB_hadem        = 0.15;
    float cutE_EE_hadem        = 999.; //N/A for endcap
    
    float cutE_EB_ietaieta     = 0.01;
    float cutE_EE_ietaieta     = 0.03;
    
    float cutE_EB_deta         = 0.007;
    float cutE_EE_deta         = 0.01;
    
    float cutE_EB_dphi         = 0.8;
    float cutE_EE_dphi         = 0.7;
    
    float cutE_dxy             = 0.04;
    float cutE_dz              = 0.2;
    
    //PF ID
    float cutE_EB_combiso_PF   = 0.2;
    //float cutE_EE_combiso_PF   = 0.11;
    
    //float cutE_EB_MVA_PF       = 0.34;
    //float cutE_EE_MVA_PF       = 0.32;	
    
    bool pass      = false;
    bool passID    = false;
    bool passIso   = false;
    bool passKin   = false;
    
    //bool conv      = false;
    bool passVtx   = false;
    float Iso      = 0.0;
    float dxy      = ev.PFElecdxy(i);
    float dz       = ev.PFElecdz(i);
    //int innerhits  = ev.PFElecInnerHits(i);
    float ietaieta = ev.PFElecietaieta(i);
    float deltaphi = ev.PFElecDPhiSuTrAtVtx(i);
    float deltaeta = ev.PFElecDEtaSuTrAtVtx(i);
    float hadEm    = ev.PFElecHcalOverEcal(i);
    
    Iso = (ev.PFElecNeuHadIso(i) + ev.PFElecCharHadIso(i) + ev.PFElecPhoIso(i) )/ev.PFElecPt(i);
    if(Iso < cutE_EB_combiso_PF) 
      passIso = true;
    
    if(ev.PFElecPt(i) > cutE_pt && fabs(ev.PFElecEta(i) ) < cutE_eta && (fabs(ev.PFElecEta(i)) < cutE_etagap[0] || 
									 fabs(ev.PFElecEta(i)) > cutE_etagap[1]))
      passKin = true;
    
    if((ev.PFElecIsEB(i) == 1 && 
	ietaieta < cutE_EB_ietaieta && 
	fabs(deltaphi) <  cutE_EB_dphi &&
	fabs(deltaeta) < cutE_EB_deta && 
	hadEm < cutE_EB_hadem) ||
       (ev.PFElecIsEB(i) != 1 && 
	ietaieta < cutE_EE_ietaieta && 
	fabs(deltaphi) < cutE_EE_dphi &&
	fabs(deltaeta) <  cutE_EE_deta && 
	hadEm <  cutE_EE_hadem))
      passID = true;
    
    if(fabs(dxy) < cutE_dxy && fabs(dz) < cutE_dz)
      passVtx = true;
    
    if(passIso && passID && passKin && passVtx) 
      pass = true;
    
    return pass;
    */
  }
  
  
  /// ----------------------------------------------
  /// PFLepton Tight Selection 
  bool PFLepTightCuts(EventData& ev , int i, double pt, double eta){
    bool send=false;
    if(ev.LepType()=="m" ){
      send = PFMuonTightCuts( ev , i, pt, eta);  
    }
    else if(ev.LepType()=="e"){
      send = PFElecTightCuts( ev , i, pt,eta);
    }
    return send;
  } 

  
  /// ----------------------------------------------
  /// PFLepton Loose Selection 
  bool PFLepLooseCuts(EventData& ev , int i, double pt, double eta){
    bool send=false;
    if(ev.LepType()=="m" ){
      send = PFMuonLooseCuts( ev , i, pt, eta);  
    }
    else if(ev.LepType()=="e"){
      send = PFElecVetoCuts( ev , i, pt,eta);
    }
    return send;
  }

  
  /// ----------------------------------------------
  /// Isolated Muon Selection
  bool IsIsoMuon(int i , EventData & ev){
    if(ev.MuonIsTracker(i)==0 || ev.MuonIsGlobal(i)==0 || ev.MuonNumOfMatches(i)<2  || ev.MuonCombChi2Norm(i) >10.0  || 
       ev.MuonTrkDxy(i)>0.2 || ev.MuonTrkValidHits(i) < 10 || ev.MuonTrkNumOfValidPixHits(i) < 1  ||  ev.MuonStandValidHits(i) <1  || 
       ev.MuonPt(i)<20.0 || 
       abs( ev.MuonEta(i) ) > 2.1 ||
       (ev.MuonHadEtDR03(i)+ ev.MuonEmEtDR03(i)+ev.MuonSumPtDR03(i))/ev.MuonPt(i) > 0.15  )
      {
	return false;
      }
    else
      {
	return true;   // this is isolated muon 
      } 
  }
  
  
  /// ----------------------------------------------
  /// Isolated Muon Selection without Eta
  bool IsIsoMuonWithoutEta(int i , EventData & ev){
    if(ev.MuonIsTracker(i)==0 || ev.MuonIsGlobal(i)==0 || ev.MuonNumOfMatches(i)<2  || ev.MuonCombChi2Norm(i) >10.0  || 
       ev.MuonTrkDxy(i)>0.2 || ev.MuonTrkValidHits(i) < 10 || ev.MuonTrkNumOfValidPixHits(i) < 1  ||  ev.MuonStandValidHits(i) <1  || 
       ev.MuonPt(i)<20.0 ||
       (ev.MuonHadEtDR03(i)+ ev.MuonEmEtDR03(i)+ev.MuonSumPtDR03(i))/ev.MuonPt(i) > 0.15  )
      {
	return false;
      }
    else
      {
	return true;   // this is isolated muon 
      } 
  }
  
  
  /// ----------------------------------------------
  /// Leptons in Jet (1)
  bool LepInJet(double JetEta , double JetPhi ,   EventData & ev){
    bool send=false;
    for(int i=0; i<ev.NPFMuon(); i++ ){
      if( PFMuonTightCuts(ev ,i) &&  deltaR( JetEta , JetPhi , ev.PFMuonEta(i) , ev.PFMuonPhi(i) ) < 0.3){	
	send= true;  // this jet has iso muon
      }
    }
    for(int i=0; i<ev.NPFElec(); i++ ){
      if( PFElecTightCuts(ev ,i) &&  deltaR( JetEta , JetPhi , ev.PFElecEta(i) , ev.PFElecPhi(i) ) < 0.3){	
	send= true;  // this jet has iso elec
      }
    } 
    
    return send;
  }
  
  
  /// ----------------------------------------------
  /// Leptons in Jet (2) 
  bool LepInJet2(int i , EventData & ev){
    bool send=false;
    float muonFrac=ev.PFAK4JetMuonEng(i)/ev.PFAK4JetE(i);
    if(muonFrac>0.5) send=true; // this jet has iso muon
    
    float electFrac=ev.PFAK4JetElecEng(i)/ev.PFAK4JetE(i);
    if(electFrac>0.5) send=true; // this jet has iso elec
    
    return send;
  }
  
  
  /// ----------------------------------------------
  /// MET exclude all muons
  double  MetLepPt(double MetPx , double MetPy , EventData & ev){
    double Metx = MetPx;
    double Mety = MetPy;
    if( ev.MetType()>9){  // pf or tc Met
      for(int i=0; i<ev.NPFLep(); i++ ){
	//if( PFLepTightCuts(ev ,i ) )
	//{
	Metx =  Metx + ev.PFLepPx(i);
	Mety =  Mety + ev.PFLepPy(i);
	//}
      }
    }	
    return sqrt( Metx*Metx + Mety*Mety );
  }

  
  /// ----------------------------------------------
  /// MET exclude tight muons
  double  MetTightLepPt(double MetPx , double MetPy , EventData & ev){
    double Metx = MetPx;
    double Mety = MetPy;
    if( ev.MetType()>9){  // pf or tc Met
      for(int i=0; i<ev.NPFLep(); i++ ){
	if( PFLepTightCuts(ev ,i, 20, 2.1) ){
	  Metx =  Metx + ev.PFLepPx(i);
	  Mety =  Mety + ev.PFLepPy(i);
	}
      }
    }	
    return sqrt( Metx*Metx + Mety*Mety );
  }
  
  
  /// ----------------------------------------------
  /// MET+mu Phi
  double  MetLepPhi(double MetPx , double MetPy , EventData & ev){
    double Metx = MetPx;
    double Mety = MetPy;
    if( ev.MetType()>9){  // pf or tc Met 
      for(int i=0; i<ev.NPFLep(); i++ ){
	//if( PFLepTightCuts(ev ,i) )
	//{  
	Metx =  Metx + ev.PFLepPx(i);
	Mety =  Mety + ev.PFLepPy(i);
	//}
      }
    }
    return atan2( Mety,Metx);  
  }

  
  /// ----------------------------------------------
  /// JetIndex Selection
  int JetIndex(int ind, EventData & ev){
    int send= 99;
    if( ev.JetType()=="calo"){
      int njets=0;
      for (int i=0; i<ev.NCaloAK4Jets(); i++){
	if( ev.CaloAK4JetPtCor(i)>ev.SecJetCut()){
	  if(njets==ind)send=i;
	  njets++ ;
	}
      }
    }
    else if(ev.JetType()=="pf" || (ev.JetType()=="widepf" && ind==0)){
      int njets=0;
      for (int i=0; i<ev.NPFAK4Jets(); i++){
	if( ev.PFAK4JetPtCor(i)>ev.SecJetCut() 
	    && abs(ev.PFAK4JetEta(i))< 4.5
	    && LepInJet2(i , ev )==false 
	    //&& ev.PFAK4JetIDLOOSE(i) > 0
	    ){
	  if(njets==ind)send=i;
	  njets++ ;
	}
      }
    }
    else if(ev.JetType()=="widepf" && ind>0){
      int ixjet1 = JetIndex(0, ev);
      int njets=1;
      if(ixjet1>=0 && ixjet1<99){
	TLorentzVector leadJet;
	TLorentzVector radJet;
	leadJet.SetPtEtaPhiE(ev.PFAK4JetPtCor(ixjet1), ev.PFAK4JetEta(ixjet1) , ev.PFAK4JetPhi(ixjet1) , ev.PFAK4JetE(ixjet1));
	for (int i=0; i<ev.NPFAK4Jets(); i++){
	  if(i<=ixjet1) continue;
	  radJet.SetPtEtaPhiE(ev.PFAK4JetPtCor(i), ev.PFAK4JetEta(i), ev.PFAK4JetPhi(i), ev.PFAK4JetE(i));
	  if(ev.PFAK4JetPtCor(i)>30.0 && abs(ev.PFAK4JetEta(i))<2.5 && radJet.DeltaR(leadJet)<1.1){
	    leadJet+=radJet;
	    continue;
	  }
	  if(ev.PFAK4JetPtCor(i)>ev.SecJetCut() && abs(ev.PFAK4JetEta(i))<4.5 && LepInJet2(i,ev)==false){
	    if(njets==ind){
	      send=i;
	    }
	    njets++ ;
	  }
	}
      }
      else send = 99;
    }
    else send = 99;
    
    return send; 
  } 


  /// ----------------------------------------------
  /// WideJetIndex Selection
  int WideJetIndex(int ind, EventData & ev){
    int send= 99;
    if(ind==0){
      send = JetIndex(0, ev);
    }
    else{
      int ixjet1 = JetIndex(0, ev);
      int njets  = 1;
      if(ixjet1>=0 && ixjet1<99){
	TLorentzVector leadJet;
	TLorentzVector radJet;
	leadJet.SetPtEtaPhiE(ev.PFAK4JetPtCor(ixjet1), ev.PFAK4JetEta(ixjet1) , ev.PFAK4JetPhi(ixjet1) , ev.PFAK4JetE(ixjet1));
	for(int i=0; i<ev.NPFAK4Jets(); i++){
	  if(i==ixjet1) continue;
	  radJet.SetPtEtaPhiE(ev.PFAK4JetPtCor(i), ev.PFAK4JetEta(i), ev.PFAK4JetPhi(i), ev.PFAK4JetE(i));
	  if(ev.PFAK4JetPtCor(i)>30.0 && abs(ev.PFAK4JetEta(i))<2.5 && radJet.DeltaR(leadJet)<1.1){
	    leadJet+=radJet;
	    continue;
	  }
	  if(ev.PFAK4JetPtCor(i)>ev.SecJetCut() && abs(ev.PFAK4JetEta(i))<4.5 && LepInJet2(i,ev)==false){
	    if(njets==ind){
	      send=i;
	      break;
	    }
	    njets++ ;
	  }
	}
      }
      else send = 99;
    }
    return send; 
  }

  
  /// ----------------------------------------------
  /// Find Number of Jets
  int JetNumber(EventData & ev){
    int njets=0;
    if( ev.JetType()=="calo"){
      for (int i=0; i<ev.NCaloAK4Jets(); i++){
	if( ev.CaloAK4JetPtCor(i)>ev.SecJetCut()){
	  njets++ ;
	}
      }
    }
    else if(ev.JetType()=="pf"){
      for (int i=0; i<ev.NPFAK4Jets(); i++){
	if( ev.PFAK4JetPtCor(i)>ev.SecJetCut() 
	    && abs(ev.PFAK4JetEta(i)) < 4.5
	    && LepInJet2(i,ev)==false
	    //&& ev.PFAK4JetIDLOOSE(i) > 0
	    ){
	  njets++ ;
	}
      }
    }
    else if(ev.JetType()=="widepf"){
      int useAlgo = 0;
      
      if(useAlgo == 0){ //Phat's method
	//First - count normal NJet
	for (int i=0; i<ev.NPFAK4Jets(); i++){
	  if(ev.PFAK4JetPtCor(i)>ev.SecJetCut() && abs(ev.PFAK4JetEta(i)) < 4.5 && LepInJet2(i,ev)==false){
	    njets++ ;
	  }
	}
	//Remove if jets are in wideJet
	int ixjet1= JetIndex(0, ev);
	TLorentzVector leadJet;
	TLorentzVector fatJet;
	TLorentzVector radJet;
	if(ixjet1<99){
	  leadJet.SetPtEtaPhiE( ev.PFAK4JetPtCor(ixjet1), ev.PFAK4JetEta(ixjet1) , ev.PFAK4JetPhi(ixjet1) , ev.PFAK4JetE(ixjet1) );
	  fatJet = leadJet; //wide leading jet (require jets in event to have Pt>30, |eta|<2.5)
	  bool checkWideJet = false;
	  for (int i=0; i<ev.NPFAK4Jets(); i++){
	    checkWideJet = false;
	    if(i<=ixjet1) continue;
	    radJet.SetPtEtaPhiE(ev.PFAK4JetPtCor(i), ev.PFAK4JetEta(i), ev.PFAK4JetPhi(i), ev.PFAK4JetE(i));
	    if(ev.PFAK4JetPtCor(i)>30.0 && abs(ev.PFAK4JetEta(i))<2.5 && radJet.DeltaR(leadJet)<1.1){
	      fatJet+=radJet;
	      checkWideJet=true;
	    }
	    //Remove from NJet count
	    if(checkWideJet==true && ev.PFAK4JetPtCor(i)>ev.SecJetCut() && abs(ev.PFAK4JetEta(i))<4.5 && LepInJet2(i,ev)==false) 
	      njets--;
	  }
	}
      }
      else{ //Robyn's method
	int ixjet1= JetIndex(0, ev);
	//select second jet dependant on if it is within the cone of the fat leading jet
	//int njets(0);
	TLorentzVector leadJet;
	TLorentzVector fatJet;
	if( ixjet1<99 ){
	  leadJet.SetPtEtaPhiE( ev.PFAK4JetPtCor(ixjet1), ev.PFAK4JetEta(ixjet1) , ev.PFAK4JetPhi(ixjet1) , ev.PFAK4JetE(ixjet1) );
	  //cout<<"first jet: "<< leadJet.Pt()<< " "<< leadJet.Eta() <<" "<< leadJet.Phi() <<endl;
	  njets++;
	  //fat leading jet
	  for (int i=1; i<ev.NPFAK4Jets(); i++){
	    if( i==ixjet1) continue;
	    //skip jet if within wide jet cone
	    TLorentzVector radJet;
	    if( ev.PFAK4JetPtCor(i) > 30.0 && abs(ev.PFAK4JetEta(i))<2.5 ){
	      radJet.SetPtEtaPhiE(ev.PFAK4JetPtCor(i), ev.PFAK4JetEta(i) , ev.PFAK4JetPhi(i) , ev.PFAK4JetE(i)  );
	      if( radJet.DeltaR(leadJet) < 1.1 ){
		leadJet+=radJet;
		continue;
	      }
	    }
	    //all jet conditions
	    if(ev.PFAK4JetPtCor(i)<=ev.SecJetCut()) continue;
	    if(abs(ev.PFAK4JetEta(i)) >= 4.5) continue;
	    if(LepInJet2(i,ev)) continue;
	    //cout<<"jet > 60GeV and not in leading jet: "<<  ev.PFAK4JetPtCor(i) << " "<<ev.PFAK4JetEta(i)<<" "<<ev.PFAK4JetPhi(i)<<endl;
	    njets++;       
	  }
	}
      }
    }
    else njets=0;
    
    return njets;
  }

  
  /// ----------------------------------------------
  /// Find Number of Jets in WideJet1 system
  int WideJetNumber(EventData & ev){
    int njets   = 0;
    int useAlgo = 0;
    
    if(useAlgo == 0){ //Phat's method
      //First - count normal NJet
      for (int i=0; i<ev.NPFAK4Jets(); i++){
	if(ev.PFAK4JetPtCor(i)>ev.SecJetCut() && abs(ev.PFAK4JetEta(i)) < 4.5 && LepInJet2(i,ev)==false){
	  njets++;
	}
      }
      //Remove if jets are in wideJet
      int ixjet1= JetIndex(0, ev);
      TLorentzVector leadJet;
      TLorentzVector radJet;
      bool checkWideJet = false;
      if(ixjet1<99){
	leadJet.SetPtEtaPhiE(ev.PFAK4JetPtCor(ixjet1), ev.PFAK4JetEta(ixjet1), ev.PFAK4JetPhi(ixjet1), ev.PFAK4JetE(ixjet1));
	for (int i=0; i<ev.NPFAK4Jets(); i++){
	  checkWideJet = false;
	  if(i==ixjet1) continue;
	  radJet.SetPtEtaPhiE(ev.PFAK4JetPtCor(i), ev.PFAK4JetEta(i), ev.PFAK4JetPhi(i), ev.PFAK4JetE(i));
	  if(ev.PFAK4JetPtCor(i)>30.0 && abs(ev.PFAK4JetEta(i))<2.5 && radJet.DeltaR(leadJet)<1.1 && LepInJet2(i,ev)==false){
	    leadJet+=radJet;
	    if(ev.PFAK4JetPtCor(i)>ev.SecJetCut())
	      checkWideJet=true;
	  }
	  //Remove from NJet count
	  if(checkWideJet==true) 
	    njets--;
	}
      }
    }
    else{ //Robyn's method
      int ixjet1= JetIndex(0, ev);
      //select second jet dependant on if it is within the cone of the fat leading jet
      //int njets(0);
      TLorentzVector leadJet;
      TLorentzVector fatJet;
      if( ixjet1<99 ){
	leadJet.SetPtEtaPhiE( ev.PFAK4JetPtCor(ixjet1), ev.PFAK4JetEta(ixjet1) , ev.PFAK4JetPhi(ixjet1) , ev.PFAK4JetE(ixjet1) );
	//cout<<"first jet: "<< leadJet.Pt()<< " "<< leadJet.Eta() <<" "<< leadJet.Phi() <<endl;
	njets++;
	//fat leading jet
	for (int i=1; i<ev.NPFAK4Jets(); i++){
	  if( i==ixjet1) continue;
	  //skip jet if within wide jet cone
	  TLorentzVector radJet;
	  if( ev.PFAK4JetPtCor(i) > 30.0 && abs(ev.PFAK4JetEta(i))<2.5 ){
	    radJet.SetPtEtaPhiE(ev.PFAK4JetPtCor(i), ev.PFAK4JetEta(i) , ev.PFAK4JetPhi(i) , ev.PFAK4JetE(i)  );
	    if( radJet.DeltaR(leadJet) < 1.1 ){
	      leadJet+=radJet;
	      continue;
	    }
	  }
	  //all jet conditions
	  if(ev.PFAK4JetPtCor(i)<=ev.SecJetCut()) continue;
	  if(abs(ev.PFAK4JetEta(i)) >= 4.5) continue;
	  if(LepInJet2(i,ev)) continue;
	  //cout<<"jet > 60GeV and not in leading jet: "<<  ev.PFAK4JetPtCor(i) << " "<<ev.PFAK4JetEta(i)<<" "<<ev.PFAK4JetPhi(i)<<endl;
	  njets++;       
	}
      }
    }
    return njets;
  }
  
  /// ----------------------------------------------
  /// WideJet1 LorentzVector
  TLorentzVector WideJet1(EventData & ev){
    int ixjet1= JetIndex(0, ev);
    TLorentzVector leadJet;
    TLorentzVector radJet;
    if(ixjet1<99){
      leadJet.SetPtEtaPhiE(ev.PFAK4JetPtCor(ixjet1), ev.PFAK4JetEta(ixjet1), ev.PFAK4JetPhi(ixjet1), ev.PFAK4JetE(ixjet1));
      for (int i=0; i<ev.NPFAK4Jets(); i++){
	if(i==ixjet1) continue;
	radJet.SetPtEtaPhiE(ev.PFAK4JetPtCor(i), ev.PFAK4JetEta(i), ev.PFAK4JetPhi(i), ev.PFAK4JetE(i));
	if(ev.PFAK4JetPtCor(i)>30.0 && abs(ev.PFAK4JetEta(i))<2.5 && radJet.DeltaR(leadJet)<1.1 && LepInJet2(i,ev)==false){
	  leadJet+=radJet;
	}
      }
    }
    else{
      leadJet.SetPtEtaPhiE(0.,0.,0.,0.);
    }
    return leadJet;
  }
  
  
  /// ----------------------------------------------
  /// Manager
  Manager::Manager(const std::string & logFileName) : mLogFileName(logFileName){}
  Manager::~Manager() {}
  void Manager::Add(Operation::_Base * aOp){
    Manager::OpData tempData;
    tempData.op = aOp;
    tempData.ng = 0.0;
    mOperations.push_back(tempData);
  }
  
  
  /// ----------------------------------------------
  /// Run
  void Manager::Run(EventData & ev) {
    // Clear counters
    double ng_all = 0.0;
    double ng_total = 0.0;
    std::vector<Manager::OpData>::iterator i = mOperations.begin();
    
    while ( i != mOperations.end() ){
      i->ng = 0.0;
      ++i;
    }

    // Main event loop
    // Just keep going until max events is hit or we finish the file
    while ( ev.GetNextEvent() ){
      // Sum the total event weight
      ng_all += ev.Weight();
      
      // Loop over the operations
      i = mOperations.begin();
      while ( i != mOperations.end() ){
	// Call the filter
	
	if ( !i->op->Process(ev) ) 
	  break; // break on failure
	
	// Filter passed, save weight
	i->ng += ev.Weight();

	++i;
      }
      
      // If we aren't at the end continue without adding total
      if ( i != mOperations.end() ) continue;
      
      // Sum the total that passes all the operations
      ng_total += ev.Weight();
      
      // 			int flg_trg80=0;
      // 			string strtrg = ev.HLTNames();
      //			if (strtrg.find("HLT_CentralJet80_MET80")!=string::npos ) flg_trg80=1;
      
      
      
      //int ixjet1= JetIndex(0, ev);
      //int ixjet2= JetIndex(1, ev);
      
      //if(flg_trg80==0) cout << "\"" << ev.run()  <<  ":"  << ev.event() <<  "\",    " <<  ev.run() <<  "," << ev.lumi() <<   endl;
      //else cout << "..............\"" << ev.run()  <<  ":"  << ev.event() <<  "\",    " <<  ev.run() <<  "," << ev.lumi() <<   endl;
      
      //cout << ev.run()  <<  "    "  << ev.lumi() << "    "  <<   ev.event() <<   endl;
      
      
      //cout << "CALO:" << ev.MetPt(0)  <<  "   PF:"  << ev.MetPt(10) <<  "  TC:" <<  ev.MetPt(20)  <<   endl;
      
      //cout<< MetMuPt( ev.MetPx(10) , ev.MetPy(10) , ev )  << "  Tiv: " << ev.LowTIV()  <<  " DeltaPhi:  "  
      //<<  deltaPhi( ev.PFAK4JetPhi(ixjet1) ,  ev.PFAK4JetPhi(ixjet2) )  << "  jetPt: "  <<  ev.PFAK4JetPtCor(ixjet1) 
      //<<  "   "    << ev.PFAK4JetPtCor(ixjet2)   <<endl; 
      
      //cout << ev.PFLepPy(1) << " " << ev.PFMuonPy(1) <<  " "  <<  ev.NPFLep() <<  " " <<  ev.NPFMuon() <<   endl; 
      
      /*
	for(int i=0; i<100; i++){
	double w = ev.PDFWeight(i) * ev.PDFWeights(0) /ev.PDFWeight(0);
	//double w = ev.PDFWeightAlphaS(i) * ev.PDFWeights(0) / ev.PDFWeightAlphaS(0);
	//cout <<  w <<  "   " << ev.PDFWeight(i)  <<  "   " << ev.PDFWeight(i) <<  "   ..."  << ev.PDFWeights(i)  <<  endl;
	
	
	//cout << "----------------------------" <<  endl;
	}
	cout << "----------------------------" <<  endl;  
      */
      
      
      //cout << ev.PFLepPt(0)  <<  "  " <<  ev.LepType()  <<  "  " <<   PFElecTightCuts(ev , 0)  << endl;
      
      
      /*
	for(int i=0; i<ev.NGenPar(); i++){
	//if( ( abs(ev.GenParId(i) )>10 || abs(ev.GenParId(i) ) <17 ) && ev.GenParStatus(i)==1){
	cout <<   ev.GenParId(i)  << "   mother:" <<  ev.GenParDoughterOf(i)  <<  "  pt:" << ev.GenParPt(i) << endl;
	}
	}*/
      
    }
    
    // Output the information about the run to the log file
    OutputResults(mLogFileName.c_str(), ng_all, ng_total);  
  }

  
  /// ----------------------------------------------
  /// OutputResults
  void Manager::OutputResults(const std::string & dataSet, double ng_all, double ng_total){
    ofstream outfile(mLogFileName.c_str(), ios::app);
    
    // 		cout << "Dataset info recorded in: " << dataSet << endl;
    // 		cout << "Total events processed by all operations: " << ng_all << endl;
    // 		cout << "Total events passing all operations: " << ng_total << endl;
    // 
    // 		outfile << "Dataset info recorded in: " << dataSet << endl;
    // 		outfile << "Total events processed by all operations: " << ng_all << endl;
    // 		outfile << "Total events passing all operations: " << ng_total << endl;
    
    std::vector<Manager::OpData>::iterator i = mOperations.begin();
    while ( i != mOperations.end() ){
      cout << "Events surviving " << *(i->op) << ": " << i->ng  << endl;
      outfile << "Events surviving " << *(i->op)  << ": " << i->ng << endl;
      
      ++i;
    }
  }
  
  
  /// ----------------------------------------------
  /// Base
  _Base::_Base() {}
  _Base::~_Base(){}
  
  // Just definition of the operator
  std::ostream& operator << (std::ostream& ostrm, _Base& m){
    return m.Description(ostrm);
  }
  
  // CUTS STARTING FROM HERE-----------------------------------------------------

  /// ----------------------------------------------
  /// Print events
  PrintEvent::PrintEvent(double run, double lumi, double event) : mRun(run), mLumi(lumi), mEvent(event) {} 
  PrintEvent::~PrintEvent() {}
  
  bool PrintEvent::Process(EventData & ev){
    //int ixjet1 = JetIndex(0, ev);
    //int ixjet2 = JetIndex(1, ev);
    /*
    //if(ev.run()==mRun && ev.lumi()==mLumi && ev.event()==mEvent)
    {
    
    if(ixjet1<99 && ixjet2<99){
    cout<<"----------------------------"<<endl;
    cout<<"Run: "<<ev.run()<<", Lumi: "<<ev.lumi()<<", Event: "<<ev.event()<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"Jet-1: ind= "<<ixjet1<<" pt= "<<ev.PFAK4JetPtCor(ixjet1)<<" eta= "<<ev.PFAK4JetEta(ixjet1)<<" phi= "<<ev.PFAK4JetPhi(ixjet1)<<endl;
    cout<<"       CHEF= "<<ev.PFAK4JetChaHadEngFrac(ixjet1)<<" NHEF= "<<ev.PFAK4JetNeuHadEngFrac(ixjet1)
    <<" CEMF= "<<ev.PFAK4JetChaEmEngFrac(ixjet1)<<" NEMF= "<<ev.PFAK4JetNeuEmEngFrac(ixjet1)<<endl;
    cout<<"       MuEF= "<<ev.PFAK4JetMuonEng(ixjet1)/ev.PFAK4JetE(ixjet1)
    <<" ElecEF= "<<ev.PFAK4JetElecEng(ixjet1)/ev.PFAK4JetE(ixjet1)
    <<" PhotEF= "<<ev.PFAK4JetPhotEng(ixjet1)/ev.PFAK4JetE(ixjet1)<<endl;
    cout<<"Jet-2: ind= "<<ixjet2<<" pt= "<<ev.PFAK4JetPtCor(ixjet2)<<" eta= "<<ev.PFAK4JetEta(ixjet2)<<" phi= "<<ev.PFAK4JetPhi(ixjet2)<<endl;
    cout<<"       CHEF= "<<ev.PFAK4JetChaHadEngFrac(ixjet2)<<" NHEF= "<<ev.PFAK4JetNeuHadEngFrac(ixjet2)
    <<" CEMF= "<<ev.PFAK4JetChaEmEngFrac(ixjet2)<<" NEMF= "<<ev.PFAK4JetNeuEmEngFrac(ixjet2)<<endl;
    cout<<"       MuEF= "<<ev.PFAK4JetMuonEng(ixjet2)/ev.PFAK4JetE(ixjet2)
    <<" ElecEF= "<<ev.PFAK4JetElecEng(ixjet2)/ev.PFAK4JetE(ixjet2)
    <<" PhotEF= "<<ev.PFAK4JetPhotEng(ixjet2)/ev.PFAK4JetE(ixjet2)<<endl;	
    }
    }
    */ 

    Double_t genpt = 0.0;
    for(int i=0; i<ev.NGenPar(); i++){
      if(abs(ev.GenParId(i))!=23 || ev.GenParStatus(i)!=3) continue;
      genpt = ev.GenParPt(i);
      break;
    }
    if(MetLepPt(ev.MetPx(10), ev.MetPy(10), ev) < 0.7*genpt){
      std::cout<<"MetLepPt = "<<MetLepPt(ev.MetPx(10), ev.MetPy(10), ev)<<", GenPt = "<<genpt<<std::endl;
      std::cout<<"if(run=="<<ev.run()<<" && lumi=="<<ev.lumi()<<" && event=="<<ev.event()<<") return true;"<<std::endl;
    }
    return true;
  }
  
  std::ostream& PrintEvent::Description(std::ostream &ostrm){
    ostrm << "  Select Event: Run = " << mRun << ", Event = "<< mEvent << " :............";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// ABnormal Events
  CutAbnormalEvents::CutAbnormalEvents(vector<int> run ,vector<int> evt ) : mRun(run) , mEvt(evt) {} 
  CutAbnormalEvents::~CutAbnormalEvents() {}
  
  bool CutAbnormalEvents::Process(EventData & ev){
    if(  abs(ev.MetPt(10) - ev.MetPt(0))< 2.0*ev.MetPt(0)){
      return true;
    } 
    else{
      return false;
    } 
  }
  
  std::ostream& CutAbnormalEvents::Description(std::ostream &ostrm) 
  {
    ostrm << "  Abnormal Events"   << "" << ":............";
    return ostrm;
  }
  
  
  /// ----------------------------------------------
  /// HLT Cut
  CutHLT::CutHLT(int bit) : mBit(bit) {} 
  CutHLT::~CutHLT() {}
  
  bool CutHLT::Process(EventData & ev){ 
    bool check;
    if(ev.NoiseFlag(mBit)==0){
      check = false;
      if(mBit==12){
	std::cout<<"NoiseBit-"<<mBit
		 <<": Run= "<<ev.run()
		 <<" ,LS= "<<ev.lumi()
		 <<" ,Event= "<<ev.event()
		 <<" ,CaloMET= "<<ev.MetPt(0)
		 <<" ,TCMET= "<<ev.MetPt(20)
		 <<" ,PCMET= "<<ev.MetPt(10)
		 <<std::endl;
      }
    }
    else{
      check = true;
    }
    
    return check;
  }
  std::ostream& CutHLT::Description(std::ostream &ostrm){
    ostrm << "  HLT Bit-" << mBit << ":............";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// MET Cut
  CutMet::CutMet(double cut, bool nolep = 0) : mCut(cut), mNoLep(nolep) {} 
  CutMet::~CutMet() {}
  
  bool CutMet::Process(EventData & ev){
    if( (mNoLep == 0 && MetLepPt( ev.MetPx(ev.MetType()) , ev.MetPy(ev.MetType()) , ev )  > mCut ) || 
	(mNoLep == 1 && ev.MetPt( ev.MetType() ) > mCut) ){
      return true;
    } 
    else{
      return false;
    }
  }
  std::ostream& CutMet::Description(std::ostream &ostrm){
    ostrm << "  Met"   << "Cut met >" << mCut << " GeV :............";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// NOISE CLEAN Cut
  CutNoiseClean::CutNoiseClean(double JetfHPD , double JetfRBX, int JetN90Hits,  double  JetEmfMin, double JetEmfMax ) : 
    mJetfHPD(JetfHPD) , mJetfRBX(JetfRBX), mJetN90Hits(JetN90Hits),  mJetEmfMin(JetEmfMin), mJetEmfMax(JetEmfMax) {} 
  CutNoiseClean::~CutNoiseClean() {}
  
  bool CutNoiseClean::Process(EventData & ev){
    bool send=false;
    
    if( ev.JetType()=="calo"){
      if(ev.CaloAK4JetIDTIGHT(0)==1){
	send=true;
      }
    }
    else if(ev.JetType()=="pf"){
      int ixjet1= JetIndex(0, ev);
      int ixjet2= JetIndex(1, ev);
      
      //cout<<"PFJet-0: CHEF="<<ev.PFAK4JetChaHadEngFrac(ixjet1)<<endl;

      if( JetNumber(ev)==1 
	  && ev.PFAK4JetChaHadEngFrac(ixjet1) > 0.2
	  && ev.PFAK4JetNeuHadEngFrac(ixjet1)< 0.7
	  && ev.PFAK4JetChaEmEngFrac(ixjet1) < 0.7
	  && ev.PFAK4JetNeuEmEngFrac(ixjet1) < 0.7
	  ){
	send=true;
      }
      
      if( ixjet2<99 && ixjet1<99 &&  JetNumber(ev)>1 
	  && ev.PFAK4JetChaHadEngFrac(ixjet1) > 0.2
	  && ev.PFAK4JetNeuHadEngFrac(ixjet1)< 0.7
	  && ev.PFAK4JetChaEmEngFrac(ixjet1) < 0.7
	  && ev.PFAK4JetNeuEmEngFrac(ixjet1) < 0.7
	  && ev.PFAK4JetNeuHadEngFrac(ixjet2)< 0.7
	  && ev.PFAK4JetNeuEmEngFrac(ixjet2) < 0.9
	  ){
	send=true;
      }
    }
    else if(ev.JetType()=="widepf"){ 
      int ixjet1 = 99;
      int ixjet2 = 99;
      int njets  = 0;
      for(int i=0; i<ev.NPFAK4Jets(); i++){
	if(ev.PFAK4JetPtCor(i)>ev.SecJetCut() && abs(ev.PFAK4JetEta(i))< 4.5 && LepInJet2(i , ev )==false){
	  if(njets==0) ixjet1=i;
	  if(njets==1) ixjet2=i;
	  njets++;
	  if(njets>1) break;
	}
      }
      if(njets>=1
	 && ev.PFAK4JetChaHadEngFrac(ixjet1) > 0.2
	 && ev.PFAK4JetNeuHadEngFrac(ixjet1)< 0.7
	 && ev.PFAK4JetChaEmEngFrac(ixjet1) < 0.7
	 && ev.PFAK4JetNeuEmEngFrac(ixjet1) < 0.7
	 ){
	if(njets==1)
	  send=true;
	else{
	  if(ev.PFAK4JetNeuHadEngFrac(ixjet2)< 0.7)
	    send=true;
	}
      }
    }
    else send=false;
    
    return send;
  }
  std::ostream& CutNoiseClean::Description(std::ostream &ostrm){
    ostrm << "  NoiseClean Cut "  << " :............";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// NJet Cut 
  CutNJet::CutNJet(int cut) : mCut(cut) {} 
  CutNJet::~CutNJet() {}
  
  bool CutNJet::Process(EventData & ev){
    bool send=false;
    if (JetNumber(ev)>0 && JetNumber(ev)< mCut){
      send=true;
    } 
    return send; 
  }
  std::ostream& CutNJet::Description(std::ostream &ostrm){
    ostrm << "  NJet"   <<  " Cut  njet<" << mCut << " :............";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// NJet: exclude jets within fat jet cone Cut
  CutWideNJet::CutWideNJet(int cut) : mCut(cut) {} 
  CutWideNJet::~CutWideNJet() {}
  
  bool CutWideNJet::Process(EventData & ev) {		
    bool send=false;
    if (WideJetNumber(ev)>0 && WideJetNumber(ev)< mCut){
      send=true;
    } 
    return send;
  }
  std::ostream& CutWideNJet::Description(std::ostream &ostrm) {
    ostrm << "  Wide NJet"   <<  " Cut  njet<" << mCut << " :............";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// Jet1 Cut
  CutJet1::CutJet1(double JetPt , double JetEta, double  JetIDEmfMin, double JetIDEmfMax ) : 
    mJetPt(JetPt) , mJetEta(JetEta), mJetIDEmfMin(JetIDEmfMin),  mJetIDEmfMax(JetIDEmfMax) {} 
  CutJet1::~CutJet1() {}
  
  bool CutJet1::Process(EventData & ev){
    bool send=false;
    if( ev.JetType()=="calo"){
      if( ev.CaloAK4JetPtCor(0)>mJetPt &&  abs(ev.CaloAK4JetEta(0))<mJetEta ){
	send=true;
      }
    }
    else if(ev.JetType()=="pf"){
      int ixjet1= JetIndex(0, ev);
      if( ixjet1<99 &&  ev.PFAK4JetPtCor(ixjet1)>mJetPt && abs(ev.PFAK4JetEta(ixjet1))<mJetEta ){
	send=true;
      }
    }
    else if(ev.JetType()=="widepf"){
      TLorentzVector leadJet = WideJet1(ev);    
      if(leadJet.Pt()>mJetPt && fabs(leadJet.Eta())<mJetEta)
	send=true;
    }
    else
      send = false;
    
    return send;
  }
  std::ostream& CutJet1::Description(std::ostream &ostrm){
    ostrm << "  Jet1Cut...  Jet1Pt>" << mJetPt << "  |Jet1Eta|<"<<  mJetEta <<"  " << mJetIDEmfMin <<  "<JetIDEmf<" << mJetIDEmfMax  << " :............";
    return ostrm;
  }    

  /// ----------------------------------------------
  /// Jet1-BTag Cut
  CutJet1BTag::CutJet1BTag(double CombinedSecondaryVertex) : 
    mCombinedSecondaryVertex(CombinedSecondaryVertex) {} 
  CutJet1BTag::~CutJet1BTag() {}
  
  bool CutJet1BTag::Process(EventData & ev){
    bool send=false;
    if(ev.JetType()=="pf"){
      int ixjet1= JetIndex(0, ev);
      if( ixjet1<99 &&  ev.PFAK4JetBTagCombSecVtx(ixjet1)>mCombinedSecondaryVertex ){
	send=true;
      }
    }
    else
      send = false;
    
    return send;
  }
  std::ostream& CutJet1BTag::Description(std::ostream &ostrm){
    ostrm << "  Jet1 BTag Cut... CSV > "<< mCombinedSecondaryVertex <<" :............";
    return ostrm;
  }  
  

  /// ----------------------------------------------
  /// Jet2 Cut
  CutJet2::CutJet2(double JetPt , double JetEta) : 
    mJetPt(JetPt) , mJetEta(JetEta) {} 
  CutJet2::~CutJet2() {}
  
  bool CutJet2::Process(EventData & ev){
    bool send=false;
    if(ev.JetType()=="pf" || ev.JetType()=="widepf"){
      if(JetNumber(ev)==1)
	send = true;
      else if(JetNumber(ev)>1){
	int ixjet1 = JetIndex(0, ev);
	int ixjet2 = JetIndex(1, ev);
	if( ixjet1<99 && ixjet2<99 && ev.PFAK4JetPtCor(ixjet2)>mJetPt && fabs(ev.PFAK4JetEta(ixjet2))<mJetEta ){
	  send=true;
	}
      }
      else
	send = false;
    }
    //
    return send;
  }
  std::ostream& CutJet2::Description(std::ostream &ostrm){
    ostrm << "  Jet2Cut...  Jet2Pt>" << mJetPt << "  |Jet2Eta|<"<<  mJetEta << " :............";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// WideJet1 Cut
  CutWideJet1::CutWideJet1(double JetPt , double JetEta, double  JetIDEmfMin, double JetIDEmfMax) : 
    mJetPt(JetPt) , mJetEta(JetEta), mJetIDEmfMin(JetIDEmfMin),  mJetIDEmfMax(JetIDEmfMax) {} 
  CutWideJet1::~CutWideJet1() {}
  
  bool CutWideJet1::Process(EventData & ev){
    bool send=false;
    TLorentzVector leadJet = WideJet1(ev);    
    if(leadJet.Pt()>mJetPt && fabs(leadJet.Eta())<mJetEta)
      send=true;
    
    return send;
  }
  std::ostream& CutWideJet1::Description(std::ostream &ostrm){
    ostrm << "  WideJet1Cut...  WideJet1Pt>" << mJetPt << "  |Jet1Eta|<"<<  mJetEta <<"  " << mJetIDEmfMin <<  "<JetIDEmf<" << mJetIDEmfMax  << " :............";
    return ostrm;
  }
  
  
  /// ----------------------------------------------
  /// DeltaPhi-1 Cut
  CutDeltaPhi1::CutDeltaPhi1(double cut1) : 
    mCut1(cut1){} 
  CutDeltaPhi1::~CutDeltaPhi1() {}
  
  bool CutDeltaPhi1::Process(EventData & ev){
    bool send=false;
    if( ev.JetType()=="calo"){
      if( abs( deltaPhi( ev.CaloAK4JetPhi(0), MetLepPhi( ev.MetPx(ev.MetType()) , ev.MetPy(ev.MetType()) , ev ) ) ) >mCut1  ){
	send=true;
      }
    }
    if( ev.JetType()=="pf"){
      int ixjet1= JetIndex(0, ev);
      if(ixjet1<99 &&   abs( deltaPhi( ev.PFAK4JetPhi(ixjet1), MetLepPhi( ev.MetPx(ev.MetType()) , ev.MetPy(ev.MetType()) , ev ) ) ) <mCut1  ){
	send=true;
      }  
    }

    return send;
  }
  std::ostream& CutDeltaPhi1::Description(std::ostream &ostrm){
    ostrm << "  DeltaPhi-1 Cut   dPhi(Jet1,Met)>" <<  mCut1 --<< " :............";
    return ostrm;
  }
  
  
  /// ----------------------------------------------
  /// DeltaPhi-2 Cut
  CutDeltaPhi2::CutDeltaPhi2(double cut1) : 
    mCut1(cut1) {} 
  CutDeltaPhi2::~CutDeltaPhi2() {}
  
  bool CutDeltaPhi2::Process(EventData & ev){
    bool  send=false;
    if( ev.JetType()=="calo"){
      bool  accept =false;
      if(JetNumber(ev)==1) accept =true;
      if(JetNumber(ev)==2 && abs( deltaPhi( ev.CaloAK4JetPhi(1), MetLepPhi( ev.MetPx(ev.MetType()) , ev.MetPy(ev.MetType()) , ev ) ) ) >mCut1 ) accept=true;
      if(accept) send=true;
    }
    if( ev.JetType()=="pf"){
      bool  accept =false;
      int ixjet2= JetIndex(1, ev);
      if(JetNumber(ev)==1) accept =true;
      if(ixjet2<99 &&  JetNumber(ev)>1 && abs( deltaPhi( ev.PFAK4JetPhi(ixjet2), 
							 MetLepPhi( ev.MetPx(ev.MetType()) , ev.MetPy(ev.MetType()) , ev ) ) ) >mCut1 ) accept=true;
      if(accept) send=true;
    }
    
    return send;
  }
  std::ostream& CutDeltaPhi2::Description(std::ostream &ostrm){
    ostrm << "  DeltaPhi-2 Cut   dPhi(Jet2, Met)>"  << mCut1 << " :............";
    return ostrm;
  }
  
  
  /// ----------------------------------------------
  /// DeltaPhi-3 Cut
  CutDeltaPhi3::CutDeltaPhi3(double cut1) : 
    mCut1(cut1) {} 
  CutDeltaPhi3::~CutDeltaPhi3() {}
  
  bool CutDeltaPhi3::Process(EventData & ev){
    bool  send=false;
    if( ev.JetType()=="calo"){
      bool accept = false;
      if(JetNumber(ev)==1) accept =true;
      if(JetNumber(ev)>1 && abs( deltaPhi( ev.CaloAK4JetPhi(1) , ev.CaloAK4JetPhi(2) ) )  >mCut1 ) accept=true;
      if(accept) send=true;
    }
    else if(ev.JetType()=="pf"){
      bool accept = false;
      int  ixjet1 = JetIndex(0, ev);
      int  ixjet2 = JetIndex(1, ev);			
      
      if(JetNumber(ev)==1) accept =true;
      if(ixjet2<99 && ixjet1<99 &&   JetNumber(ev)>1 && abs( deltaPhi( ev.PFAK4JetPhi(ixjet1),  ev.PFAK4JetPhi(ixjet2)  ) ) < mCut1 ) accept=true;
      if(accept) send=true;
    }
    else if(ev.JetType()=="widepf"){
      bool accept = false;
      TLorentzVector leadJet = WideJet1(ev);
      int ixjet1 = WideJetIndex(0, ev);
      int ixjet2 = WideJetIndex(1, ev);
      if(ixjet2<99 && ixjet1<99 && abs(deltaPhi(leadJet.Phi(), ev.PFAK4JetPhi(ixjet2)))<mCut1)
	accept=true;
      else 
	accept=false; 
      
      if(accept) send=true;
    }
    else
      send = false;
    return send;
  }
  std::ostream& CutDeltaPhi3::Description(std::ostream &ostrm){
    ostrm << "  DeltaPhi-3 Cut   dPhi(Jet1, Jet2)>"  << mCut1 << " :............";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// Wide DeltaPhi-3 Cut
  CutWideDeltaPhi3::CutWideDeltaPhi3(double cut1) : 
    mCut1(cut1) {} 
  CutWideDeltaPhi3::~CutWideDeltaPhi3() {}

  bool CutWideDeltaPhi3::Process(EventData & ev) {
    bool  send=false;
    if(ev.JetType()=="pf" || ev.JetType()=="widepf"){
      bool accept = false;
      TLorentzVector leadJet = WideJet1(ev); 
      int ixjet1 = WideJetIndex(0, ev);
      int ixjet2 = WideJetIndex(1, ev);
      if(ixjet2<99 && ixjet1<99 && abs(deltaPhi(leadJet.Phi(), ev.PFAK4JetPhi(ixjet2)))<mCut1)
	accept=true;
      else 
	accept=false;
      
      if(accept) send=true;
    }
    return send;
  }
  std::ostream& CutWideDeltaPhi3::Description(std::ostream &ostrm){
    ostrm << "  Wide DeltaPhi-3 Cut   dPhi(Wide Jet1, Jet2)>"  << mCut1 << " :............";
    return ostrm;
  }

	
  /// ----------------------------------------------
  /// MuonIsolation Cut
  NoIsoMuon::NoIsoMuon(double pt) : mPt(pt) {} 
  NoIsoMuon::~NoIsoMuon() {}
  bool NoIsoMuon::Process(EventData & ev){
    bool  send=true;
    for(int i=0; i<ev.NMuon(); i++ ){
      if( IsIsoMuonWithoutEta(i,ev) ){
	send=false;
      }
    }
    return send;
  }
  std::ostream& NoIsoMuon::Description(std::ostream &ostrm){
    ostrm << "  Muon Iso  muon pt>" <<  mPt << " GeV :............";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// MuonIsolation for WZ analysis 
  IsoMuon::IsoMuon(double pt) : mPt(pt) {} 
  IsoMuon::~IsoMuon() {}
  
  bool IsoMuon::Process(EventData & ev){
    bool  send=false;
    for(int i=0; i<ev.NMuon(); i++ ){
      if( IsIsoMuon(i,ev) ){
	send=true;
      }
    }
    return send;  
  }
  std::ostream& IsoMuon::Description(std::ostream &ostrm){
    ostrm << "  Muon Iso for WZ analysis  muon pt>" <<  mPt << " GeV :............";
    return ostrm;
  }
  
  
  /// ----------------------------------------------
  /// TIV Cut
  CutTIV::CutTIV(double cut) : mCut(cut){} 
  CutTIV::~CutTIV() {}
  bool CutTIV::Process(EventData & ev){
    //double LowTIV=0;
    float Lower_TIV = 100;
    float ILV_isoPT;
    
    float TIV_pt_l_thr = 10;
    float TIV_pt_s_thr = 1;
    //float TIV_dxy_thr = 100;
    //float TIV_dz_thr = 100;
    float TIV_dR_inner_thr = 0.02;
    float TIV_dR_outer_thr = 0.3;
    
    for(int tl=0; tl<ev.TIV_N(); tl++){
      ILV_isoPT = 100.;
      
      bool isMuon=false;
      for(int mu=0; mu<ev.NMuon(); mu++){
	if( ev.MuonPt(mu) > 20 ){
	  if( ev.MuonSumPtDR03(mu) >= 0 && ev.MuonSumPtDR03(mu) < 100){
	    float dPhi = deltaPhi( ev.MuonPhi(mu), ev.TIV_phi(tl) );
	    float dEta = ev.MuonEta(mu) - ev.TIV_eta(tl);
	    if( sqrt(dPhi*dPhi + dEta*dEta) < 0.3) {isMuon=true; break;}
	  }
	}
      }
      if(isMuon) continue;
      
      if( ev.TIV_lead(tl)==1 && ev.TIV_pt(tl) > TIV_pt_l_thr  ){ 
	ILV_isoPT = 0.;
	for(int ts = tl+1; ts< ev.TIV_N() && ev.TIV_lead(ts) !=1 ;ts++ ){
	  if( ev.TIV_dR(ts) < TIV_dR_outer_thr  && ev.TIV_dR(ts) > TIV_dR_inner_thr && ev.TIV_pt(ts) > TIV_pt_s_thr ){
	    ILV_isoPT+= ev.TIV_pt(ts);
	  }
	}
	if( ILV_isoPT / ev.TIV_pt(tl) < Lower_TIV ) Lower_TIV = ILV_isoPT / ev.TIV_pt(tl);
      }
    }
    //LowTIV = Lower_TIV;
    
    if ( ev.LowTIV()  > mCut )
      //if ( LowTIV  > mCut )
      {
	return true;
      } 
    else{
      return false;
    }
  }
  std::ostream& CutTIV::Description(std::ostream &ostrm){
    ostrm << "  TIV Cut" << "  TIV>" << mCut << " :.................";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// GenPar Selection
  GenParExist::GenParExist(int pdgId) : mPdgId(pdgId){} 
  GenParExist::~GenParExist() {}
  
  bool GenParExist::Process(EventData & ev){
    bool send = false; 
    for(int i=0; i<ev.NGenPar(); i++){
      if(abs(ev.GenParId(i))==mPdgId && ev.GenParStatus(i)==3){
	send=true;
	break;
      }
    }
    return send;
  }
  std::ostream& GenParExist::Description(std::ostream &ostrm){
    ostrm << "  Gen PdgID:" << mPdgId << " Exist  :.................";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// GenPar Selection Mass window
  GenParMassWindow::GenParMassWindow(int pdgId, double lowM, double highM) :  mPdgId(pdgId),  mLowM(lowM), mHighM(highM){} 
  GenParMassWindow::~GenParMassWindow() {}
  
  bool GenParMassWindow::Process(EventData & ev){
    bool send = false; 
    for(int i=0; i<ev.NGenPar(); i++){
      if(abs(ev.GenParId(i))==mPdgId && ev.GenParStatus(i)==3){
        if(ev.GenParMass(i) > mLowM && ev.GenParMass(i) < mHighM){
          send=true;
	  break;
        }
      }
    }
    return send;
  }
  std::ostream& GenParMassWindow::Description(std::ostream &ostrm){
    ostrm << "  Gen PdgID:" << mPdgId << " mass window "<< mLowM << " - "<< mHighM << ":.................";
    return ostrm;
  }
  
  
  /// ----------------------------------------------
  /// GenParZ->mumu
  GenZmumu::GenZmumu(int pdgId) :  mPdgId(pdgId){} 
  GenZmumu::~GenZmumu() {}
  
  bool GenZmumu::Process(EventData & ev){
    bool send  = false; 
    bool posMu = false;
    bool negMu = false;
    for(int i=0; i<ev.NGenPar(); i++){
      if(abs(ev.GenParId(i))==13 && abs(ev.GenParDoughterOf(i))==23){
	//cout<<"muon :"<<ev.GenParCharge(i)  <<endl;
	if(ev.GenParCharge(i)>0) posMu = true;
	if(ev.GenParCharge(i)<0) negMu = true;
      }
    }
    if(posMu && negMu) send=true;
    return send;
  }
  std::ostream& GenZmumu::Description(std::ostream &ostrm){
    ostrm << "  Gen Zmumu :" << ":.................";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// Gen Z PT
  GenParPt::GenParPt(int pdgId ,  double pt) : mPdgId(pdgId) ,  mPt(pt) {} 
  GenParPt::~GenParPt() {}
  
  bool GenParPt::Process(EventData & ev){
    bool send = false;	
    for(int i=0; i<ev.NGenPar(); i++){
      if(abs(ev.GenParId(i))==mPdgId && ev.GenParStatus(i)==3 && ev.GenParPt(i) > mPt ){
        send=true;
	break;
      }
    }
    return send;
  }
  std::ostream& GenParPt::Description(std::ostream &ostrm){
    ostrm << "  Gen pT > :" << mPt << " :.................";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// Gen Z PT AND MET
  GenParPtAndMET::GenParPtAndMET(int pdgId , double genpt , double met) : mPdgId(pdgId) ,  mGenPt(genpt) , mMet(met) {} 
  GenParPtAndMET::~GenParPtAndMET() {}
  
  bool GenParPtAndMET::Process(EventData & ev){
    bool send = false;	
    for(int i=0; i<ev.NGenPar(); i++){
      if(abs(ev.GenParId(i))==mPdgId 
	 && ev.GenParStatus(i)==3 && ev.GenParPt(i) > mGenPt 
	 && MetLepPt(ev.MetPx(ev.MetType()), ev.MetPy(ev.MetType()), ev)> mMet
	 ){
        send=true;
	break;
      }
    }
    return send;
  }
  std::ostream& GenParPtAndMET::Description(std::ostream &ostrm){
    ostrm << "  Gen pT > " << mGenPt << " & METNoMuon > "<< mMet << " :.................";
    return ostrm;
  }


  /// ----------------------------------------------
  /// Gen Z PT OR MET
  GenParPtOrMET::GenParPtOrMET(int pdgId , double genpt , double met) : mPdgId(pdgId) ,  mGenPt(genpt) , mMet(met) {} 
  GenParPtOrMET::~GenParPtOrMET() {}
  
  bool GenParPtOrMET::Process(EventData & ev){
    bool send = false;	
    for(int i=0; i<ev.NGenPar(); i++){
      if((abs(ev.GenParId(i))==mPdgId && ev.GenParStatus(i)==3 && ev.GenParPt(i) > mGenPt) 
	 || MetLepPt(ev.MetPx(ev.MetType()), ev.MetPy(ev.MetType()), ev)> mMet
	 ){
        send=true;
	break;
      }
    }
    return send;
  }
  std::ostream& GenParPtOrMET::Description(std::ostream &ostrm){
    ostrm << "  Gen pT > " << mGenPt << " OR METNoMuon > "<< mMet << " :.................";
    return ostrm;
  }
  
  
  /// ----------------------------------------------
  /// W +/- Selection
  WsignSelection::WsignSelection(double charge) : mCharge(charge){} 
  WsignSelection::~WsignSelection() {}
  
  bool WsignSelection::Process(EventData & ev){
    bool send = false; 
    int t = ev.MetType();
    
    int IsoLepIndex=0; 
    int LepCharge=0;
    
    for(int i=0; i<ev.NPFLep(); i++ ){
      if( PFLepTightCuts(ev ,i, 20, 2.1) ){
	IsoLepIndex++;
	LepCharge = ev.PFLepCharge(i);
      }
    }
    
    if(IsoLepIndex==1){
      double WmunuMT=0;
      double MTPt=0;
      
      for(int i=0; i<ev.NPFLep(); i++ ){
	if( PFLepTightCuts(ev ,i, 20, 2.1) ){  
	  double MTEn= ev.PFLepPt(i)+ ev.MetPt(t);
	  double MTPx= ev.PFLepPx(i)+ ev.MetPx(t);
	  double MTPy= ev.PFLepPy(i)+ ev.MetPy(t);
	  //double MTPz= ev.PFMuonPz(i);
	  
	  MTPt=sqrt(MTPx*MTPx+MTPy*MTPy);
	  WmunuMT=sqrt((MTEn*MTEn)-(MTPt*MTPt));	
	}	
      } 
      
      if( WmunuMT>50. && WmunuMT<100. && LepCharge == mCharge ) send =true;
      
      //if( WmunuMT>50. && WmunuMT<100. ) send =true;
    }
    
    return send;
    
  }
  std::ostream& WsignSelection::Description(std::ostream &ostrm){
    ostrm << "  W Selection  Sign:" << mCharge << " :.................";
    return ostrm;
  }

  
  /// ----------------------------------------------
  /// Z Selection
  ZSelection::ZSelection(double charge) : mCharge(charge){} 
  ZSelection::~ZSelection() {}
  
  bool ZSelection::Process(EventData & ev){
    bool send = false; 
    
    //int t = ev.MetType();
    
    int IsoLepIndex=0; 
    //int  LepCharge=0;
    
    int isoLepPseq[20], isoLepMseq[20], isoLepPnum=0,isoLepMnum=0; //=0 for isoMuPnum,isoMuMnum
    
    for (int i=0; i<20; i++){
      isoLepPseq[i]=0; isoLepMseq[i]=0;
    }
    
    bool  check2=true;
    for(int i=0; i<ev.NPFLep(); i++ ){
      bool  check1=true;
      if( PFLepTightCuts(ev ,i, 20, 2.1) ){
	check1=false;
	IsoLepIndex++;
	//LepCharge = ev.PFLepCharge(i);
	
	if(ev.PFLepCharge(i)<0){
	  isoLepMseq[isoLepMnum]=i;
	  isoLepMnum++;
	}
	else if(ev.PFLepCharge(i)>0){
	  isoLepPseq[isoLepPnum]=i;
	  isoLepPnum++;
	}
      }
      if(check1 && check2){
	check2=false;
	if(ev.PFLepCharge(i)<0){
	  isoLepMseq[isoLepMnum]=i;
	  isoLepMnum++;
	}
	else if(ev.PFLepCharge(i)>0){
	  isoLepPseq[isoLepPnum]=i;
	  isoLepPnum++;
	}
      }
    }
    
    //if( (isoLepPnum==1 && isoLepMnum==1) || (isoLepPnum==0 && isoLepMnum==1) || (isoLepPnum==1 && isoLepMnum==0) )
    if(isoLepPnum==1 && isoLepMnum==1){
      //double dimuPhi =0;
      double ZmumuMT=0;
      double ZPt=0;
      for(int i=0; i<isoLepMnum ; i++ ){
	int ixmum=isoLepMseq[i];
	for(int j=0; j<isoLepPnum ; j++ ){
	  int ixmup=isoLepPseq[j] ;
	  
	  double ZEn= ev.PFLepE(ixmup)  + ev.PFLepE(ixmum) ;
	  double ZPx= ev.PFLepPx(ixmup) + ev.PFLepPx(ixmum);
	  double ZPy= ev.PFLepPy(ixmup) + ev.PFLepPy(ixmum);
	  double ZPz= ev.PFLepPz(ixmup) + ev.PFLepPz(ixmum);
	  
	  ZPt=sqrt(ZPx*ZPx + ZPy*ZPy);
	  
	  ZmumuMT=sqrt((ZEn*ZEn)-(ZPt*ZPt)-(ZPz*ZPz));
	  
	  //dimuPhi = atan2( ZPy, ZPx);
	}
      }
      
      if( ZmumuMT>60 && ZmumuMT<120 ) send =true;
      //if( ZmumuMT>0 && ZmumuMT<12000 ) send =true;
      
    }
    
    return send;  
  }
  std::ostream& ZSelection::Description(std::ostream &ostrm){
    ostrm << "  Z Selection  Sign:" << mCharge << " :.................";
    return ostrm;
  }
  
  
  /// ----------------------------------------------
  /// PF Lep Iso
  PFLepIso::PFLepIso(double pt, double eta) : mPt(pt) , mEta(eta) {} 
  PFLepIso::~PFLepIso() {}
  
  bool PFLepIso::Process(EventData & ev){
    bool send = false;	
    for(int i=0; i<ev.NPFLep(); i++ ){
      if(  PFLepTightCuts(ev , i, mPt, mEta )  ) send =true ;
    }
    
    return send;
  }
  std::ostream& PFLepIso::Description(std::ostream &ostrm){
    ostrm << "  PF Lepton Iso:"  << " :.................";
    return ostrm;
  }
   
  
  /// ----------------------------------------------
  /// No PF  Muon for monojet 
  NoPFMuon::NoPFMuon(double pt, double eta) : mPt(pt), mEta(eta) {} 
  NoPFMuon::~NoPFMuon() {}
  
  bool NoPFMuon::Process(EventData & ev){
    bool  send=true;
    for(int i=0; i<ev.NPFMuon(); i++ ){
      if(PFMuonLooseCuts(ev, i, mPt, mEta) == true) send=false;
    }
    return send;
  }
  std::ostream& NoPFMuon::Description(std::ostream &ostrm) 
  {
    ostrm << "  No PFMuon   pt>" <<  mPt << " GeV :............";
    return ostrm;
  }
  
  
  /// ----------------------------------------------
  /// No PFElectron for monojet 
  NoPFElec::NoPFElec(double pt , double eta) : mPt(pt), mEta(eta) {} 
  NoPFElec::~NoPFElec() {}
  
  bool NoPFElec::Process(EventData & ev){
    bool  send=true;
    for(int i=0; i<ev.NPFElec(); i++ ){
      if(PFElecVetoCuts(ev , i,  mPt, mEta) == true) send=false ;
    }
    return send;
  }
  std::ostream& NoPFElec::Description(std::ostream &ostrm) 
  {
    ostrm << "  No PFElectron   pt>" <<  mPt << " GeV :............";
    return ostrm;
  }		
  
  
  /// ----------------------------------------------
  /// Electron Weight
  double  electronWeight(double pt, double eta){
    double weight;
    if(pt>=10.00      && pt<15.00  && std::fabs(eta)>=0.00 && std::fabs(eta)<0.80) weight = 0.853;
    else if(pt>=15.00 && pt<20.00  && std::fabs(eta)>=0.00 && std::fabs(eta)<0.80) weight = 0.949;
    else if(pt>=20.00 && pt<30.00  && std::fabs(eta)>=0.00 && std::fabs(eta)<0.80) weight = 1.017;
    else if(pt>=30.00 && pt<40.00  && std::fabs(eta)>=0.00 && std::fabs(eta)<0.80) weight = 1.023;
    else if(pt>=40.00 && pt<50.00  && std::fabs(eta)>=0.00 && std::fabs(eta)<0.80) weight = 1.018;
    else if(pt>=50.00 && pt<200.00 && std::fabs(eta)>=0.00 && std::fabs(eta)<0.80) weight = 1.008;
    else if(pt>=10.00 && pt<15.00  && std::fabs(eta)>=0.80 && std::fabs(eta)<1.44) weight = 0.841;
    else if(pt>=15.00 && pt<20.00  && std::fabs(eta)>=0.80 && std::fabs(eta)<1.44) weight = 0.971;
    else if(pt>=20.00 && pt<30.00  && std::fabs(eta)>=0.80 && std::fabs(eta)<1.44) weight = 1.001;
    else if(pt>=30.00 && pt<40.00  && std::fabs(eta)>=0.80 && std::fabs(eta)<1.44) weight = 1.009;
    else if(pt>=40.00 && pt<50.00  && std::fabs(eta)>=0.80 && std::fabs(eta)<1.44) weight = 1.004;
    else if(pt>=50.00 && pt<200.00 && std::fabs(eta)>=0.80 && std::fabs(eta)<1.44) weight = 0.995;
    else if(pt>=10.00 && pt<15.00  && std::fabs(eta)>=1.44 && std::fabs(eta)<1.56) weight = 1.089;
    else if(pt>=15.00 && pt<20.00  && std::fabs(eta)>=1.44 && std::fabs(eta)<1.56) weight = 1.146;
    else if(pt>=20.00 && pt<30.00  && std::fabs(eta)>=1.44 && std::fabs(eta)<1.56) weight = 1.144;
    else if(pt>=30.00 && pt<40.00  && std::fabs(eta)>=1.44 && std::fabs(eta)<1.56) weight = 1.018;
    else if(pt>=40.00 && pt<50.00  && std::fabs(eta)>=1.44 && std::fabs(eta)<1.56) weight = 0.988;
    else if(pt>=50.00 && pt<200.00 && std::fabs(eta)>=1.44 && std::fabs(eta)<1.56) weight = 0.999;
    else if(pt>=10.00 && pt<15.00  && std::fabs(eta)>=1.56 && std::fabs(eta)<2.00) weight = 0.817;
    else if(pt>=15.00 && pt<20.00  && std::fabs(eta)>=1.56 && std::fabs(eta)<2.00) weight = 0.924;
    else if(pt>=20.00 && pt<30.00  && std::fabs(eta)>=1.56 && std::fabs(eta)<2.00) weight = 0.997;
    else if(pt>=30.00 && pt<40.00  && std::fabs(eta)>=1.56 && std::fabs(eta)<2.00) weight = 1.007;
    else if(pt>=40.00 && pt<50.00  && std::fabs(eta)>=1.56 && std::fabs(eta)<2.00) weight = 1.002;
    else if(pt>=50.00 && pt<200.00 && std::fabs(eta)>=1.56 && std::fabs(eta)<2.00) weight = 0.990;
    else if(pt>=10.00 && pt<15.00  && std::fabs(eta)>=2.00 && std::fabs(eta)<2.50) weight = 1.124;
    else if(pt>=15.00 && pt<20.00  && std::fabs(eta)>=2.00 && std::fabs(eta)<2.50) weight = 1.150;
    else if(pt>=20.00 && pt<30.00  && std::fabs(eta)>=2.00 && std::fabs(eta)<2.50) weight = 1.078;
    else if(pt>=30.00 && pt<40.00  && std::fabs(eta)>=2.00 && std::fabs(eta)<2.50) weight = 1.042;
    else if(pt>=40.00 && pt<50.00  && std::fabs(eta)>=2.00 && std::fabs(eta)<2.50) weight = 1.026;
    else if(pt>=50.00 && pt<200.00 && std::fabs(eta)>=2.00 && std::fabs(eta)<2.50) weight = 1.004;
    else weight = 1.;
    return weight;
  }


  /// ----------------------------------------------
  /// Tight Muon Weight
  double  muonWeight(double pt, double eta){
    double weight;
    if(pt>=20.00 && std::fabs(eta)<=2.40){
      if(std::fabs(eta)>=0.00 && std::fabs(eta)<0.90) weight = 0.9925*0.9959; 
      if(std::fabs(eta)>=0.90 && std::fabs(eta)<1.20) weight = 0.9928*0.9878;
      if(std::fabs(eta)>=1.20 && std::fabs(eta)<2.10) weight = 0.9960*1.0027; 
      if(std::fabs(eta)>=2.10 && std::fabs(eta)<=2.40) weight = 0.9952*1.0633;
    }
    else weight = 0.;
    return weight;
  }

  
  /// ----------------------------------------------
  /// Loose Muon Weight
  double  muonWeightLoose(double pt, double eta){
    double weight;
    if(pt>=20.00 && std::fabs(eta)<=2.40){
      if(std::fabs(eta)>=0.00 && std::fabs(eta)<0.90) weight = 0.9984*0.9990; 
      if(std::fabs(eta)>=0.90 && std::fabs(eta)<1.20) weight = 0.9990*1.0011;
      if(std::fabs(eta)>=1.20 && std::fabs(eta)<2.10) weight = 0.9986*1.0013; 
      if(std::fabs(eta)>=2.10 && std::fabs(eta)<=2.40) weight = 1.0000*1.0242;
    }
    else weight = 0.;
    return weight;
  }
  
  
  /// ----------------------------------------------
  /// Tau Cut 
  CutTau::CutTau(int pf, int againstLepton) : mPF(pf), mAgainstLepton(againstLepton) {} 
  CutTau::~CutTau() {}
  
  bool CutTau::Process(EventData & ev){	
    bool send=false;
    int ntaus = 0;
    if(mPF==1){
      for(int i = 0; i < ev.NPFTau(); i++){
	if(ev.PFTauPt(i) < 20.0) continue;
	if(fabs(ev.PFTauEta(i)) > 2.3) continue;
	if(ev.PFTauDisByLooseCombinedIsolationDeltaBetaCorr(i) < 0.5) continue; 
	if(ev.PFTauDisDecayModeFinding(i) < 0.5) continue;
	if(mAgainstLepton==1 && ev.PFTauDisAgainstElectronLoose(i)<0.5) continue;
	if(mAgainstLepton==1 && ev.PFTauDisAgainstMuonTight2(i)<0.5) continue;
	ntaus++;
      }
    }
    else{
      for(int i = 0; i < ev.NTau(); i++){
	if(ev.TauPt(i) < 20.0) continue;
	if(fabs(ev.TauEta(i)) > 2.3) continue;
	if(ev.TauDisByLooseCombinedIsolationDeltaBetaCorr(i) < 0.5) continue; 
	if(ev.TauDisDecayModeFinding(i) < 0.5) continue;
	if(mAgainstLepton==1 && ev.TauDisAgainstElectronLoose(i)<0.5) continue;
	if(mAgainstLepton==1 && ev.TauDisAgainstMuonTight2(i)<0.5) continue;
	ntaus++;
      }
    }

    if(ntaus < 1) send = true;
    
    return send; 
  }
  std::ostream& CutTau::Description(std::ostream &ostrm){
    ostrm << "  Cut Tau :............";
    return ostrm;
  }
}
