////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "DataFormats/Common/interface/View.h"

#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonPFIsolation.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "DataFormats/Common/interface/ValueMap.h"

#include <memory>
#include <vector>
#include <sstream>
#include <cmath>

////////////////////////////////////////////////////////////////////////////////
// class definition
////////////////////////////////////////////////////////////////////////////////
class MuonIdSelector : public edm::EDProducer
{
public:
  // construction/destruction
  MuonIdSelector(const edm::ParameterSet& iConfig);
  virtual ~MuonIdSelector();
  
  // member functions
  void produce(edm::Event& iEvent,const edm::EventSetup& iSetup);
  void endJob();
  
private:  
  // member data
  edm::InputTag  src_;
  std::string    moduleLabel_;
  std::string    idLabel_;  
  bool           applyTightID_;
  bool           applyLooseID_;

  unsigned int nTot_;
  unsigned int nPassed_;
};



////////////////////////////////////////////////////////////////////////////////
// construction/destruction
////////////////////////////////////////////////////////////////////////////////

//______________________________________________________________________________
MuonIdSelector::MuonIdSelector(const edm::ParameterSet& iConfig)
  : src_    (iConfig.getParameter<edm::InputTag>     ("src"))
  , moduleLabel_(iConfig.getParameter<std::string>   ("@module_label"))
  , idLabel_(iConfig.existsAs<std::string>("idLabel") ? iConfig.getParameter<std::string>("idLabel") : "loose")
  , nTot_(0)
  , nPassed_(0)
{
  produces<std::vector<pat::Muon> >();

  /// ------- Decode the ID criteria --------
  applyTightID_ = false;
  applyLooseID_ = false;

  if( (idLabel_.compare("tight")==0) ||
      (idLabel_.compare("Tight")==0) ||
      (idLabel_.compare("TIGHT")==0) )
    applyTightID_ = true;
  else if( (idLabel_.compare("loose")==0) ||
      (idLabel_.compare("Loose")==0) ||
      (idLabel_.compare("LOOSE")==0) )  
    applyLooseID_ = true;
  else
    applyLooseID_ = true;
}


//______________________________________________________________________________
MuonIdSelector::~MuonIdSelector(){}


////////////////////////////////////////////////////////////////////////////////
// implementation of member functions
////////////////////////////////////////////////////////////////////////////////

//______________________________________________________________________________
void MuonIdSelector::produce(edm::Event& iEvent,const edm::EventSetup& iSetup)
{
  edm::Handle<reco::VertexCollection> vtxs;
  iEvent.getByLabel("offlinePrimaryVertices", vtxs);
  
  std::auto_ptr<std::vector<pat::Muon> > passingMuons(new std::vector<pat::Muon >);
  
  edm::Handle<edm::View<pat::Muon> > muons;
  iEvent.getByLabel(src_,muons);
  
  bool* isPassing = new bool[muons->size()]; 
  
  for(unsigned int iMuon=0; iMuon<muons->size(); iMuon++) { 
    
    isPassing[iMuon]=false;
    
    const pat::Muon& muon = muons->at(iMuon);
    
    // impact parameter variables
    float dxy = 99.;
    float dz  = 99.;
    if (vtxs->size() > 0) {
      reco::VertexRef vtx(vtxs, 0);
      dxy = fabs(muon.muonBestTrack()->dxy(vtx->position()));
      dz  = fabs(muon.muonBestTrack()->dz(vtx->position()));
    }
    //Isolation
    //float pfIsolation = 0.0;
    float pfIsolation = (muon.pfIsolationR04().sumChargedHadronPt
			 +std::max(0.,muon.pfIsolationR04().sumNeutralHadronEt
				   + muon.pfIsolationR04().sumPhotonEt 
				   - 0.5*muon.pfIsolationR04().sumPUPt))/muon.pt();
    
    bool isTight = (muon.pt() > 20) 
      && (fabs(muon.eta()) < 2.1) 
      && (muon.isGlobalMuon())
      && (muon.isPFMuon())
      && (muon.globalTrack()->normalizedChi2() < 10)
      && (muon.globalTrack()->hitPattern().numberOfValidMuonHits() > 0)
      && (muon.numberOfMatchedStations() > 1)
      && (muon.innerTrack()->hitPattern().numberOfValidPixelHits() > 0)
      && (muon.track()->hitPattern().trackerLayersWithMeasurement() > 5)
      && (dxy < 0.2)
      && (dz  < 0.5)
      && (pfIsolation < 0.12);
    
    bool isLoose = (muon.pt() > 10) 
      && (fabs(muon.eta()) < 2.1) 
      && (muon.isGlobalMuon() || muon.isTrackerMuon())
      && (muon.isPFMuon())
      && (dxy < 0.2)
      && (dz  < 0.5)
      && (pfIsolation < 0.20);
    
    ///
    if(applyTightID_ && isTight)   isPassing[iMuon]= true;
    if(applyLooseID_ && isLoose)   isPassing[iMuon]= true;
  }

  unsigned int counter=0;
  edm::View<pat::Muon>::const_iterator tIt, endcands = muons->end();
  for (tIt = muons->begin(); tIt != endcands; ++tIt, ++counter) {
    if(isPassing[counter]) passingMuons->push_back( *tIt );  
  }

  nTot_  +=muons->size();
  nPassed_+=passingMuons->size();

  delete [] isPassing;  
  iEvent.put(passingMuons);
}


//______________________________________________________________________________
void MuonIdSelector::endJob()
{
  std::stringstream ss;
  ss<<"nTot="<<nTot_<<" nPassed="<<nPassed_
    <<" effPassed="<<100.*(nPassed_/(double)nTot_)<<"%\n";
  std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"
	   <<"\n"<<moduleLabel_<<"(MuonIdSelector) SUMMARY:\n"<<ss.str()
	   <<"++++++++++++++++++++++++++++++++++++++++++++++++++"
	   << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// plugin definition
////////////////////////////////////////////////////////////////////////////////
typedef MuonIdSelector         		MonojetPATMuonIdSelector;

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(MonojetPATMuonIdSelector);
