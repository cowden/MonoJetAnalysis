######################################################################
#                                                                    #
#                  NtupleAnalyzer_cfi                                #
#                                                                    #
######################################################################


import FWCore.ParameterSet.Config as cms

NtupleAnalyzerTemplate = cms.EDAnalyzer(
    'NtupleAnalyzer',
    debugMode               = cms.bool(False),
    includeNonPFCollection  = cms.bool(False),
    #
    TriggerTag              = cms.untracked.InputTag('TriggerResults::HLT'),
    triggerUsed             = cms.double(0), #Use to skip noTrig
    hltPath1Name            = cms.untracked.string("HLT_MET120_HBHENoiseCleaned_v"),
    hltPath2Name            = cms.untracked.string("HLT_MonoCentralPFJet80_PFMETnoMu"),
    #
    jetPtCut                = cms.double(15),
    jetEtaCut               = cms.double(4.7),
    METThreshold            = cms.double(0),
    #
    isMC                    = cms.bool(False),
    isSignal                = cms.double(0),
    chooseOnlyGenZmumu      = cms.bool(False),
    chooseOnlyGenZnunu      = cms.bool(False),
    weight                  = cms.double(1),
    #
    Tracks                  = cms.untracked.InputTag("generalTracks"),
    TIV_ltrack_thr          = cms.double(5),
    TIV_strack_thr          = cms.double(1),
    TIV_dz_thr              = cms.double(1),
    TIV_dxy_thr             = cms.double(1),
    TIV_cone_thr            = cms.double(0.35),
    TIV_inner_cone_thr      = cms.double(0.015),
    #
    PFElectronTag           = cms.untracked.InputTag("selectedPatElectronsPF"),
    PFMuonTag               = cms.untracked.InputTag("selectedPatMuonsPF"),
    PFTauTag                = cms.untracked.InputTag("selectedPatTausPF"),
    PFJetTag                = cms.untracked.InputTag("selectedPatJetsPF"),
    PFMETTag                = cms.untracked.InputTag("patMETsPF"),
    #
    ElectronTag             = cms.untracked.InputTag("selectedPatElectrons"),
    MuonTag                 = cms.untracked.InputTag("selectedPatMuons"),
    TauTag                  = cms.untracked.InputTag("selectedPatTaus"),
    JetTag                  = cms.untracked.InputTag("selectedPatJets"),
    METTag                  = cms.untracked.InputTag("patMETs"),
    #
    puJetIdTag              = cms.untracked.InputTag("puJetMva","full53xId")
)

