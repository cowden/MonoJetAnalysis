
/*****************************************************************************
 * Project: CMS detector at the CERN
 *
 * Package: ElectroWeakAnalysis/VPlusJets
 *
 *
 * Authors:
 *
 *   Chayanit Asawatangtrakuldee chayanit@cern.ch 
 *
 * Description:
 *   - Selects "loose" and "tight" electrons needed for V-boson analysis.
 *   - Saves collection of the reference vectors of electrons passing the 
 *     required electron ID.
 * History:
 *   
 *
 *****************************************************************************/
////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "DataFormats/Common/interface/View.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "MonoJetAnalysis/NtupleAnalyzer/interface/ElectronEffectiveArea.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "RecoEgamma/EgammaTools/interface/ConversionTools.h"
#include "DataFormats/EgammaCandidates/interface/ConversionFwd.h"
#include "DataFormats/EgammaCandidates/interface/Conversion.h"
#include "DataFormats/Common/interface/ValueMap.h"

#include <memory>
#include <vector>
#include <sstream>
#include <cmath>

////////////////////////////////////////////////////////////////////////////////
// class definition
////////////////////////////////////////////////////////////////////////////////
class ElectronIdSelector : public edm::EDProducer
{
public:
  // construction/destruction
  ElectronIdSelector(const edm::ParameterSet& iConfig);
  virtual ~ElectronIdSelector();
  
  // member functions
  void produce(edm::Event& iEvent,const edm::EventSetup& iSetup);
  void endJob();

private:  
  // member data
  edm::InputTag  src_;
  std::string    moduleLabel_;
  std::string    idLabel_;  
  bool           useDetectorIsolation_;
  bool           applyTightID_;
  bool           applyMediumID_;
  bool           applyLooseID_;
  bool           applyVetoID_;

  unsigned int nTot_;
  unsigned int nPassed_;
};



////////////////////////////////////////////////////////////////////////////////
// construction/destruction
////////////////////////////////////////////////////////////////////////////////

//______________________________________________________________________________
ElectronIdSelector::ElectronIdSelector(const edm::ParameterSet& iConfig)
  : src_    (iConfig.getParameter<edm::InputTag>     ("src"))
  , moduleLabel_(iConfig.getParameter<std::string>   ("@module_label"))
  , idLabel_(iConfig.existsAs<std::string>("idLabel") ? iConfig.getParameter<std::string>("idLabel") : "loose")
  , useDetectorIsolation_(iConfig.existsAs<bool>("useDetectorIsolation") ? iConfig.getParameter<bool>("useDetectorIsolation") : false)
  , nTot_(0)
  , nPassed_(0)
{
  produces<std::vector<pat::Electron> >();

  /// ------- Decode the ID criteria --------
  applyTightID_ = false;
  applyMediumID_ = false;
  applyLooseID_ = false;
  applyVetoID_ = false;

  if( (idLabel_.compare("tight")==0) ||
      (idLabel_.compare("Tight")==0) ||
      (idLabel_.compare("TIGHT")==0) ||
      (idLabel_.compare("WP70")==0) ||
      (idLabel_.compare("wp70")==0) )
    applyTightID_ = true;
  else if( (idLabel_.compare("medium")==0) ||
      (idLabel_.compare("Medium")==0) ||
      (idLabel_.compare("MEDIUM")==0) ||
      (idLabel_.compare("WP80")==0) ||
      (idLabel_.compare("wp80")==0) )  applyMediumID_ = true;
  else if( (idLabel_.compare("loose")==0) ||
      (idLabel_.compare("Loose")==0) ||
      (idLabel_.compare("LOOSE")==0) ||
      (idLabel_.compare("WP90")==0) ||
      (idLabel_.compare("wp90")==0) )  applyLooseID_ = true;
  else if( (idLabel_.compare("veto")==0) ||
      (idLabel_.compare("Veto")==0) ||
      (idLabel_.compare("VETO")==0) ||
      (idLabel_.compare("VETOid")==0) ||
      (idLabel_.compare("VetoId")==0) )  applyVetoID_ = true;
}


//______________________________________________________________________________
ElectronIdSelector::~ElectronIdSelector(){}


////////////////////////////////////////////////////////////////////////////////
// implementation of member functions
////////////////////////////////////////////////////////////////////////////////

//______________________________________________________________________________
void ElectronIdSelector::produce(edm::Event& iEvent,const edm::EventSetup& iSetup)
{

  /////// Pileup density "rho" in the event from fastJet pileup calculation /////
  edm::Handle<double> rho;
  const edm::InputTag eventrho("kt6PFJets", "rho");
  iEvent.getByLabel(eventrho,rho);
  double fastJetRho = *rho;

  edm::Handle<reco::VertexCollection> vtxs;
  iEvent.getByLabel("offlinePrimaryVertices", vtxs);

  //edm::Handle<reco::ConversionCollection> conversions;
  //iEvent.getByLabel("allConversions", conversions);

  //edm::Handle<reco::BeamSpot> beamspot_h;
  //iEvent.getByLabel("offlineBeamSpot", beamspot_h);
  //const reco::BeamSpot &beamspot = *(beamspot_h.product());

  std::auto_ptr<std::vector<pat::Electron> > passingElectrons(new std::vector<pat::Electron >);

  edm::Handle<edm::View<pat::Electron> > electrons;
  iEvent.getByLabel(src_,electrons);

  bool* isPassing = new bool[electrons->size()]; 

  for(unsigned int iElec=0; iElec<electrons->size(); iElec++) { 

    isPassing[iElec]=false;
 
    const pat::Electron& ele = electrons->at(iElec);

    // -------- Make sure that the electron is within acceptance ------
    float pt  = ele.pt();
    float eta = ele.superCluster()->eta();
    //bool isEB = ele.isEB();
    //bool isEE = ele.isEE(); 
    bool isEB = (fabs(eta)<1.442);
    bool isEE = (fabs(eta)>1.566 && fabs(eta)<2.5);
    //bool inAcceptance = (isEB || isEE) && (ele.ecalDrivenSeed()==1);
    
    // -------- Compute Detector isolation ------
    const double PI = 4.0*atan(1.0);
    float detector_isolation = (ele.dr03TkSumPt() + 
			       std::max(0.,ele.dr03EcalRecHitSumEt()-1.0) + 
			       ele.dr03HcalTowerSumEt() - 
			       PI*0.3*0.3*fastJetRho) / pt;
 
    float EffArea = ElectronEffectiveArea::GetElectronEffectiveArea( ElectronEffectiveArea::kEleGammaAndNeutralHadronIso03 , eta , ElectronEffectiveArea::kEleEAData2012);
    float pfIso03EA = (ele.chargedHadronIso() + std::max(0.,ele.neutralHadronIso() + ele.photonIso() - EffArea*fastJetRho)) / pt;

    float isolation = 100.;
    if(useDetectorIsolation_) isolation = detector_isolation;
    else isolation = pfIso03EA;

    // -------- Compute ID ------
    double sigmaIEtaIEta   = ele.sigmaIetaIeta();
    double dPhiIn    = fabs(ele.deltaPhiSuperClusterTrackAtVtx());
    double dEtaIn    = fabs(ele.deltaEtaSuperClusterTrackAtVtx());
    double hoe     = ele.hadronicOverEm();
    double ooemoop = fabs((1.0/ele.ecalEnergy() - ele.eSuperClusterOverP()/ele.ecalEnergy()));

    // impact parameter variables
    float d0vtx         = 0.0;
    float dzvtx         = 0.0;
    if (vtxs->size() > 0) {
        reco::VertexRef vtx(vtxs, 0);
        d0vtx = ele.gsfTrack()->dxy(vtx->position());
        dzvtx = ele.gsfTrack()->dz(vtx->position());
    } else {
        d0vtx = ele.gsfTrack()->dxy();
        dzvtx = ele.gsfTrack()->dz();
    }

    // conversion rejection variables
    //bool vtxFitConversion = ConversionTools::hasMatchedConversion(ele, conversions, beamspot.position());
    bool vtxFitConversion = ! (ele.passConversionVeto());
    float mHits = ele.gsfTrack()->trackerExpectedHitsInner().numberOfHits();
 
    bool isTight  = false;  /////// <--- equivalent to WP70
    bool isMedium = false;  /////// <--- equivalent to WP80
    bool isLoose  = false;  /////// <--- equivalent to WP90
    bool isVeto    = false;  /////// <--- the loosest cut for veto
  
    // ---------- cut-based ID -----------------
    isTight = (pt>20.) 
      && (mHits<=0) 
      && (!vtxFitConversion) 
      && ((isEB && sigmaIEtaIEta<0.01 && dPhiIn<0.03 && dEtaIn<0.004 && hoe<0.120 && ooemoop<0.050 && fabs(d0vtx)<0.020 && fabs(dzvtx)<0.100 && isolation<0.10) 
	  || (isEE && sigmaIEtaIEta<0.03 && dPhiIn<0.02 && dEtaIn<0.005 && hoe<0.100 && ooemoop<0.050 && fabs(d0vtx)<0.020 && fabs(dzvtx)<0.100 && isolation<0.10));
    isMedium = (pt>20.) 
      && (mHits<=1) 
      && (!vtxFitConversion) 
      && ((isEB && sigmaIEtaIEta<0.01 && dPhiIn<0.06 && dEtaIn<0.004 && hoe<0.120 && ooemoop<0.050 && fabs(d0vtx)<0.020 && fabs(dzvtx)<0.100 && isolation<0.15) 
	  || (isEE && sigmaIEtaIEta<0.03 && dPhiIn<0.03 && dEtaIn<0.007 && hoe<0.100 && ooemoop<0.050 && fabs(d0vtx)<0.020 && fabs(dzvtx)<0.100 && isolation<0.15));
    isLoose = (pt>20.) 
      && (mHits<=1) 
      && (!vtxFitConversion) 
      && ((isEB && sigmaIEtaIEta<0.01 && dPhiIn<0.15 && dEtaIn<0.007 && hoe<0.120 && ooemoop<0.050 && fabs(d0vtx)<0.020 && fabs(dzvtx)<0.200 && isolation<0.15) 
	  || (isEE && sigmaIEtaIEta<0.03 && dPhiIn<0.10 && dEtaIn<0.009 && hoe<0.100 && ooemoop<0.050 && fabs(d0vtx)<0.020 && fabs(dzvtx)<0.200 && isolation<0.15));
    isVeto = (pt>10.) 
      && (mHits<=999) 
      //&& (!vtxFitConversion)
      && ((isEB && sigmaIEtaIEta<0.01 && dPhiIn<0.800 && dEtaIn<0.007 && hoe<0.150 && ooemoop<999.9 && fabs(d0vtx)<0.040 && fabs(dzvtx)<0.200 && isolation<0.15) 
	  || (isEE && sigmaIEtaIEta<0.03 && dPhiIn<0.700 && dEtaIn<0.010 && hoe<999.9 && ooemoop<999.9 && fabs(d0vtx)<0.040 && fabs(dzvtx)<0.200 && isolation<0.15));
    
    /// ------- Finally apply selection --------
    if(applyTightID_ && isTight)   isPassing[iElec]= true;
    if(applyMediumID_ && isMedium) isPassing[iElec]= true;
    if(applyLooseID_ && isLoose)   isPassing[iElec]= true;
    if(applyVetoID_ && isVeto) isPassing[iElec]= true;

 }

  unsigned int counter=0;
  edm::View<pat::Electron>::const_iterator tIt, endcands = electrons->end();
  for (tIt = electrons->begin(); tIt != endcands; ++tIt, ++counter) {
    if(isPassing[counter]) passingElectrons->push_back( *tIt );  
  }

  nTot_  +=electrons->size();
  nPassed_+=passingElectrons->size();

  delete [] isPassing;  
  iEvent.put(passingElectrons);
}


//______________________________________________________________________________
void ElectronIdSelector::endJob()
{
  std::stringstream ss;
  ss<<"nTot="<<nTot_<<" nPassed="<<nPassed_
    <<" effPassed="<<100.*(nPassed_/(double)nTot_)<<"%\n";
  std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"
	   <<"\n"<<moduleLabel_<<"(ElectronIdSelector) SUMMARY:\n"<<ss.str()
	   <<"++++++++++++++++++++++++++++++++++++++++++++++++++"
	   << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// plugin definition
////////////////////////////////////////////////////////////////////////////////
typedef ElectronIdSelector         		MonojetPATElectronIdSelector;

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(MonojetPATElectronIdSelector);
