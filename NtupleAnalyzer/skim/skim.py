import FWCore.ParameterSet.Config as cms  
process = cms.Process("SkimEvents") 
process.load("FWCore.MessageService.MessageLogger_cfi") 
process.MessageLogger.cerr.FwkReport.reportEvery = 1
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1)) 
process.source = cms.Source("PoolSource", 
  fileNames = cms.untracked.vstring( 
"/store/data/Run2011B/MET/RECO/PromptReco-v1/000/177/790/E415E291-AFF0-E011-B513-003048F24A04.root",  
"/store/data/Run2011B/MET/RECO/PromptReco-v1/000/177/875/9C53FA2E-13F1-E011-B6B5-BCAEC518FF8C.root",  
"/store/data/Run2011B/MET/RECO/PromptReco-v1/000/177/875/9C53FA2E-13F1-E011-B6B5-BCAEC518FF8C.root",  
 ), 
 eventsToProcess = cms.untracked.VEventRange(  
 "177790:294197826", 
 "177875:565907606", 
     ) 
 ) 
process.out = cms.OutputModule("PoolOutputModule", 
  outputCommands = cms.untracked.vstring('keep *'), 
  fileName = cms.untracked.string('WMT.root') 
) 
process.p = cms.EndPath(process.out) 
