#include <memory>
#include <vector>
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/METReco/interface/METFwd.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Math/interface/LorentzVector.h"

class MuonCorrectedMETProducer : public edm::EDProducer {
    public:
        explicit MuonCorrectedMETProducer(const edm::ParameterSet&);
        ~MuonCorrectedMETProducer();
        
        static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
    
    private:
        virtual void beginJob() ;
        virtual void produce(edm::Event&, const edm::EventSetup&);
        virtual void endJob() ;
        
        virtual void beginRun(edm::Run&, edm::EventSetup const&);
        virtual void endRun(edm::Run&, edm::EventSetup const&);
        virtual void beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
        virtual void endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);

        edm::InputTag metTag;
        edm::InputTag muonsTag;
        bool useuncorrmet;
        bool muptonly;

        edm::EDGetTokenT<edm::View<pat::MET> >   metToken;
        edm::EDGetTokenT<edm::View<reco::Muon> > muonsToken;
};

MuonCorrectedMETProducer::MuonCorrectedMETProducer(const edm::ParameterSet& iConfig): 
    metTag(iConfig.getParameter<edm::InputTag>("met")),
    muonsTag(iConfig.getParameter<edm::InputTag>("muons")),
    useuncorrmet(iConfig.existsAs<bool>("useuncorrmet") ? iConfig.getParameter<bool>("useuncorrmet") : false),
    muptonly(iConfig.existsAs<bool>("muptonly") ? iConfig.getParameter<bool>("muptonly") : false)
{
    produces<reco::METCollection>();
    metToken = consumes<edm::View<pat::MET> > (metTag); 
    muonsToken = consumes<edm::View<reco::Muon> > (muonsTag); 
}


MuonCorrectedMETProducer::~MuonCorrectedMETProducer() {
}

void MuonCorrectedMETProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup) {
    using namespace edm;
    using namespace reco;
    using namespace std;

    Handle<edm::View<pat::MET> > metH;
    iEvent.getByToken(metToken, metH);

    Handle<edm::View<reco::Muon> > muonsH;
    iEvent.getByToken(muonsToken, muonsH);

    std::auto_ptr<METCollection> output(new METCollection);

    double met    = (useuncorrmet ? metH->front().uncorrectedPt()  : metH->front().et());
    double metphi = (useuncorrmet ? metH->front().uncorrectedPhi() : metH->front().phi());
    
    double ccmetx = (muptonly ? 0.0 : met * cos(metphi));
    double ccmety = (muptonly ? 0.0 : met * sin(metphi));

    for (View<Muon>::const_iterator muons_iter = muonsH->begin(); muons_iter != muonsH->end(); ++muons_iter) {
        ccmetx += muons_iter->pfP4().Pt() * cos(muons_iter->pfP4().phi());
        ccmety += muons_iter->pfP4().Pt() * sin(muons_iter->pfP4().phi());
    }
    double ccmet = sqrt(ccmetx*ccmetx + ccmety*ccmety);

    MET* ccmetcand = metH->front().clone();
    ccmetcand->setP4(reco::Candidate::LorentzVector(ccmetx, ccmety, 0., ccmet));
    output->push_back(*ccmetcand);

    iEvent.put(output);
}

void MuonCorrectedMETProducer::beginJob() {
}

void MuonCorrectedMETProducer::endJob() {
}

void MuonCorrectedMETProducer::beginRun(edm::Run&, edm::EventSetup const&) {
}

void MuonCorrectedMETProducer::endRun(edm::Run&, edm::EventSetup const&) {
}

void MuonCorrectedMETProducer::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&) {
}

void MuonCorrectedMETProducer::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&) {
}

void MuonCorrectedMETProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
    edm::ParameterSetDescription desc;
    desc.setUnknown();
    descriptions.addDefault(desc);
}

DEFINE_FWK_MODULE(MuonCorrectedMETProducer);
