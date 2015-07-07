#include <memory>
#include <vector>
#include <string>
#include <map>

#include <TPRegexp.h>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"

class HLTCheckFilter : public edm::EDFilter {
    public:
        explicit HLTCheckFilter(const edm::ParameterSet&);
        ~HLTCheckFilter();
        
        static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
    
    private:
        virtual void beginJob() override;
        virtual bool filter(edm::Event&, const edm::EventSetup&) override;
        virtual void endJob() override;
        
        virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
        virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
        virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
        virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

        edm::InputTag triggerResultsTag;
        std::vector<std::string> triggerPathsVector;
        std::map<std::string, int> triggerPathsMap;

        edm::EDGetTokenT<edm::TriggerResults> triggerToken;
};

HLTCheckFilter::HLTCheckFilter(const edm::ParameterSet& iConfig):
    triggerResultsTag(iConfig.getParameter<edm::InputTag>("triggerResults")),
    triggerPathsVector(iConfig.getParameter<std::vector<std::string> >("triggerPaths"))
{
    triggerToken = consumes<edm::TriggerResults> (triggerResultsTag);
}


HLTCheckFilter::~HLTCheckFilter() {
}

bool HLTCheckFilter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup) {
    using namespace edm;
    using namespace std;

    Handle<edm::TriggerResults> triggerResultsH;
    iEvent.getByToken(triggerToken, triggerResultsH);

    for (size_t i = 0; i < triggerPathsVector.size(); i++) {
        if (triggerPathsMap[triggerPathsVector[i]] == -1) continue;
        if (triggerResultsH->accept(triggerPathsMap[triggerPathsVector[i]])) return true;
    }

    return false;
}

void HLTCheckFilter::beginJob() {
}

void HLTCheckFilter::endJob() {
}

void HLTCheckFilter::beginRun(edm::Run const& iRun , edm::EventSetup const& iSetup) { 
    HLTConfigProvider hltConfig;
    bool changedConfig = false;
    hltConfig.init(iRun, iSetup, triggerResultsTag.process(), changedConfig);

    for (size_t i = 0; i < triggerPathsVector.size(); i++) {
        triggerPathsMap[triggerPathsVector[i]] = -1;
    }

    for(size_t i = 0; i < triggerPathsVector.size(); i++){
        TPRegexp pattern(triggerPathsVector[i]);
        for(size_t j = 0; j < hltConfig.triggerNames().size(); j++){
            std::string pathName = hltConfig.triggerNames()[j];
            if(TString(pathName).Contains(pattern)){
                triggerPathsMap[triggerPathsVector[i]] = j;
            }
        }
    }
}

void HLTCheckFilter::endRun(edm::Run const&, edm::EventSetup const&) {
}

void HLTCheckFilter::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) {
}

void HLTCheckFilter::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) {
}

void HLTCheckFilter::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
    edm::ParameterSetDescription desc;
    desc.setUnknown();
    descriptions.addDefault(desc);
}

DEFINE_FWK_MODULE(HLTCheckFilter);
