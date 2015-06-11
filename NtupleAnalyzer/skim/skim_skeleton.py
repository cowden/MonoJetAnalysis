import FWCore.ParameterSet.Config as cms
process = cms.Process("SkimEvents")


process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))
process.source = cms.Source("PoolSource",
  fileNames = cms.untracked.vstring(
 

			 
  ),
  eventsToProcess = cms.untracked.VEventRange(

"143827:147010450",    
	
				   
 )
)

#process.source.skipEvents = cms.untracked.uint32(2000)

process.out = cms.OutputModule("PoolOutputModule",
  outputCommands = cms.untracked.vstring('keep *'),
  fileName = cms.untracked.string('METFwd_148864.root')
)

process.p = cms.EndPath(process.out)

