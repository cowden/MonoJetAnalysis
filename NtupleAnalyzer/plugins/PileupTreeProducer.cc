#include <memory>
#include <vector>

#include <TTree.h>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h" 
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "DataFormats/VertexReco/interface/Vertex.h"

class PileupTreeProducer : public edm::EDFilter {
    public:
        explicit PileupTreeProducer(const edm::ParameterSet&);
        ~PileupTreeProducer();
        
        static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
    
    private:
        virtual void beginJob() ;
        virtual bool filter(edm::Event&, const edm::EventSetup&);
        virtual void endJob() ;
        
        virtual bool beginRun(edm::Run&, edm::EventSetup const&);
        virtual bool endRun(edm::Run&, edm::EventSetup const&);
        virtual bool beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
        virtual bool endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);

        edm::InputTag pileupInfoTag;
        edm::InputTag verticesTag;
        edm::EDGetTokenT<std::vector<PileupSummaryInfo> >  pileupInfoToken;
        edm::EDGetTokenT<std::vector<reco::Vertex> > verticesToken;

        bool filter_;
        TTree* tree;
        uint32_t event, run, lumi;
        uint32_t nvtx;
        int32_t puobs, putrue; 
};

PileupTreeProducer::PileupTreeProducer(const edm::ParameterSet& iConfig):
    pileupInfoTag(iConfig.getParameter<edm::InputTag>("src")),
    verticesTag(iConfig.getParameter<edm::InputTag>("vertices")),
    filter_(iConfig.existsAs<bool>("filter") ? iConfig.getParameter<bool>("filter") : false)
{
    pileupInfoToken = consumes<std::vector<PileupSummaryInfo> > (pileupInfoTag);
    verticesToken = consumes<std::vector<reco::Vertex> > (verticesTag);
}


PileupTreeProducer::~PileupTreeProducer() {
}

bool PileupTreeProducer::filter(edm::Event& iEvent, const edm::EventSetup& iSetup) {
    using namespace edm;
    using namespace reco;
    using namespace std;

    bool return_val = !filter_;

    Handle<std::vector<PileupSummaryInfo> > pileupInfoH;
    iEvent.getByToken(pileupInfoToken, pileupInfoH);
    if (!pileupInfoH.isValid()) return return_val;

    Handle<std::vector<reco::Vertex> > verticesH;
    iEvent.getByToken(verticesToken, verticesH);
    if (!verticesH.isValid()) return return_val;

    event = iEvent.id().event();
    run   = iEvent.id().run();
    lumi  = iEvent.luminosityBlock();

    nvtx = verticesH->size();

    for (vector<PileupSummaryInfo>::const_iterator pileupInfo_iter = pileupInfoH->begin(); pileupInfo_iter != pileupInfoH->end(); ++pileupInfo_iter) {
        if (pileupInfo_iter->getBunchCrossing() == 0) {
            puobs  = pileupInfo_iter->getPU_NumInteractions();
            putrue = pileupInfo_iter->getTrueNumInteractions();
            return_val = true;
        }
    }

    tree->Fill();

    return return_val;
}

void PileupTreeProducer::beginJob() {
    edm::Service<TFileService> fs;
    tree = fs->make<TTree>("pileup_tree", "pileup_tree");
    tree->Branch("event"  , &event  , "event/i");
    tree->Branch("run"    , &run    , "run/i");
    tree->Branch("lumi"   , &lumi   , "lumi/i");
    tree->Branch("nvtx"   , &nvtx   , "nvtx/i");
    tree->Branch("puobs"  , &puobs  , "puobs/I");
    tree->Branch("putrue" , &putrue , "putrue/I");
}

void PileupTreeProducer::endJob() {
}

bool PileupTreeProducer::beginRun(edm::Run& iRun, edm::EventSetup const& iSetup) { 
    return true;
}

bool PileupTreeProducer::endRun(edm::Run&, edm::EventSetup const&) {
    return true;
}

bool PileupTreeProducer::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&) {
    return true;
}

bool PileupTreeProducer::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&) {
    return true;
}

void PileupTreeProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
    edm::ParameterSetDescription desc;
    desc.setUnknown();
    descriptions.addDefault(desc);
}

DEFINE_FWK_MODULE(PileupTreeProducer);
