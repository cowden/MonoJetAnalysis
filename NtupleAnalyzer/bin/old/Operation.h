#ifndef Operations_h
#define Operations_h

// Using the EventData wrapper
#include "EventData.h"

// Using streams
#include <iostream>
#include <vector>

// ROOT stuff
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TLorentzVector.h"

using namespace std;

namespace Operation 
{
  
  bool    IsIsoMuon(int i , EventData & eventData);
  bool    IsIsoMuonWithoutEta(int i , EventData & eventData);
  bool    LepInJet(double JetEta , double JetPhi , EventData & eventData);
  bool    LepInJet2(int i , EventData & ev);
  bool    LepInJet3(double JetEta , double JetPhi , int pf , EventData & eventData);
  
  double  MetLepPt(double MetPx , double MetPy , EventData & eventData);
  
  double  MetLepPhi(double MetPx , double MetPy , EventData & eventData);

  int     JetIndex(int ind , EventData & eventData); 
  int     WideJetIndex(int ind , EventData & eventData);
  
  int     JetNumber(EventData & eventData);
  int     WideJetNumber(EventData & eventData);
  
  TLorentzVector WideJet1(EventData & eventData);
  
  double  electronWeight(double pt, double eta);
  
  bool    PFLepTightCuts(EventData&  ev , int i, double pt=20., double eta=2.1);
  bool    PFMuonTightCuts(EventData& ev , int i, double pt=20., double eta=2.1);
  bool    PFMuonLooseCuts(EventData& ev , int i, double pt=20., double eta=2.1);
  bool    PFElecTightCuts(EventData& ev , int i, double pt=20., double eta=2.5);
  bool    PFElecVetoCuts(EventData& ev ,  int i, double pt=20., double eta=2.5);
  
  vector<double> generate_flat10_weights(TH1D* data_npu_estimated, int puVersion);
  
  class _Base 
  {
  public:
    _Base();
    virtual ~_Base();
    
  public:
    virtual bool Process(EventData & eventData) = 0; // Update the event
    virtual std::ostream& Description(std::ostream& ostrm) = 0;
  };
  
  std::ostream& operator << (std::ostream& ostrm, _Base& m);
  
  //-----------------------------------------------------------------------------------------------
  class Manager 
  {
  public:
    Manager(const std::string & logFileName);
    ~Manager();
    
  public:
    // Add an operation to the analysis
    void Add(Operation::_Base * aOp);
    void Remove(Operation::_Base * aOp);
    
    // Run the analysis
    void Run(EventData & eventData );
    
  private:
    // Status output helper function
    void OutputResults(const std::string & dataSet, double ng_all, double ng_total );
    
    
    struct OpData 
    { 
      Operation::_Base *op;
      double ng;
    };
    
    std::string mLogFileName;
    std::vector<OpData> mOperations;
  };
  
  //------------------Histogram Class---------------------------------------------------------
  class Histogrammer : public Operation::_Base 
  {
  public:
    Histogrammer(const std::string & fileName);
    ~Histogrammer();
    bool Process(EventData & ev);
    
    std::ostream& Description(std::ostream& ostrm);
    
  private:
    const std::string mFileName;
    
    // Output file
    TFile* fileOut;
    
    //------------------------
    // Declare the histograms
    //------------------------
    map<string, TH1D*> histo1D;
    map<string, TH2D*> histo2D;
  };

  //-----------------------Print events-------------------------------------------------------
  class PrintEvent : public Operation::_Base 
  {
  public:
    PrintEvent(double mRun , double mLumi, double mEvent);
    ~PrintEvent();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mRun;
    double mLumi;
    double mEvent;
  };

  
  //-----------------------NoiseClean Cut---------------------------------------------------
  class CutNoiseClean : public Operation::_Base 
  {
  public:
    CutNoiseClean( double JetfHPD , double JetfRBX, int JetN90Hits,  double  JetEmfMin, double JetEmfMax );
    ~CutNoiseClean();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mJetfHPD;
    double mJetfRBX;
    int    mJetN90Hits;  
    double mJetEmfMin;
    double mJetEmfMax;
  };	
  
  //-----------------------Met Cut-----------------------------------------------------------
  class CutMet : public Operation::_Base 
  {
  public:
    CutMet(double cut, bool nolep);
    ~CutMet();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mCut;
    bool mNoLep;
  };
  
  //-----------------------Met Cut-----------------------------------------------------------
  class CutMetElec : public Operation::_Base 
  {
  public:
    CutMetElec(double cut);
    ~CutMetElec();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mCut;
  };
  
  //-----------------------Met Cut----------------------------------------------------------
  class CutHLT : public Operation::_Base 
  {
  public:
    CutHLT(int bit);
    ~CutHLT();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    int mBit;
  };
  
  //-----------------------NJet Cut----------------------------------------------------------
  class CutNJet : public Operation::_Base 
  {
  public:
    CutNJet(int cut);
    ~CutNJet();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    int mCut;
  };  

  //-----------------------WideNJet Cut----------------------------------------------------------
  class CutWideNJet : public Operation::_Base 
  {
  public:
    CutWideNJet(int cut);
    ~CutWideNJet();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    int mCut;
  };
  
  //-----------------------Jet1 Cut-------------------------------------------------------
  class CutJet1 : public Operation::_Base 
  {
  public:
    CutJet1(double JetPt , double JetEta, double  JetIDEmfMin, double JetIDEmfMax );
    ~CutJet1();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mJetPt;
    double mJetEta;
    double mJetIDEmfMin;
    double mJetIDEmfMax;
  }; 

  //-----------------------Jet2 Cut-------------------------------------------------------
  class CutJet2 : public Operation::_Base 
  {
  public:
    CutJet2(double JetPt , double JetEta);
    ~CutJet2();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mJetPt;
    double mJetEta;
  };

  //-----------------------WideJet1 Cut-------------------------------------------------------
  class CutWideJet1 : public Operation::_Base 
  {
  public:
    CutWideJet1(double JetPt , double JetEta, double  JetIDEmfMin, double JetIDEmfMax );
    ~CutWideJet1();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mJetPt;
    double mJetEta;
    double mJetIDEmfMin;
    double mJetIDEmfMax;
  };
  
  //-----------------------DeltaPhi-1 Cut-----------------------------------------------
  class CutDeltaPhi1 : public Operation::_Base 
  {
  public:
    CutDeltaPhi1(double cut1);
    ~CutDeltaPhi1();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mCut1;
  };
  
  //-----------------------DeltaPhi-2 Cut-------------------------------------------------
  class CutDeltaPhi2 : public Operation::_Base 
  {
  public:
    CutDeltaPhi2(double cut1);
    ~CutDeltaPhi2();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mCut1;
  };
  
  //-----------------------DeltaPhi-3 Cut--------------------------------------------------
  class CutDeltaPhi3 : public Operation::_Base 
  {
  public:
    CutDeltaPhi3(double cut1);
    ~CutDeltaPhi3();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mCut1;
  };	

  //-----------------------Wide DeltaPhi-3 Cut--------------------------------------------------
  class CutWideDeltaPhi3 : public Operation::_Base 
  {
  public:
    CutWideDeltaPhi3(double cut1);
    ~CutWideDeltaPhi3();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mCut1;
  };	
  
  //-----------------------No Iso Muon Cut--------------------------------------------------
  class NoIsoMuon : public Operation::_Base 
  {
  public:
    NoIsoMuon(double pt);
    ~NoIsoMuon();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mPt;  
  };	

  //-----------------------Select Iso Muon Cut-----------------------------------------------
  class IsoMuon : public Operation::_Base 
  {
  public:
    IsoMuon(double pt);
    ~IsoMuon();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mPt;  
  };	
  
  //-----------------------Met Cut-------------------------------------------------------------
  class CutAbnormalEvents : public Operation::_Base 
  {
  public:
    CutAbnormalEvents( vector<int>run ,  vector<int> evt);
    ~CutAbnormalEvents();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    vector<int> mRun;
    vector<int> mEvt;
  };
  
  //-----------------------Cut Elecron and Muon------------------------------------------------
  class CutElecMuon : public Operation::_Base 
  {
  public:
    CutElecMuon(double cut);
    ~CutElecMuon();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mCut;  
  };
  
  //-----------------------TIV  CUT-----------------------------------------------------------
  class CutTIV : public Operation::_Base 
  {
  public:
    CutTIV(double cut);
    ~CutTIV();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mCut;  
  };
  
  //-----------------------Tau  CUT-----------------------------------------------------------
  class CutTau : public Operation::_Base 
  {
  public:
    CutTau(int pf, int againstLepton);
    ~CutTau();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mPF, mAgainstLepton;  
  };
  
  //-----------------------Gen Muon Exist----------------------------------------------------
  class GenParExist : public Operation::_Base 
  {
  public:
    GenParExist(int pdgId );
    ~GenParExist();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    int mPdgId;  
  };	
  
  //-----------------------W +/- Selection---------------------------------------------------
  class WsignSelection : public Operation::_Base 
  {
  public:
    WsignSelection(double charge );
    ~WsignSelection();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mCharge;  
  };
  
  //-----------------------Z Selection--------------------------------------------------------
  class ZSelection : public Operation::_Base 
  {
  public:
    ZSelection(double charge );
    ~ZSelection();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mCharge;
  };	
  
  //-----------------------PF Muon Selection-------------------------------------------------
  class PFLepIso : public Operation::_Base 
  {
  public:
    PFLepIso(double pt, double eta);
    ~PFLepIso();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mPt;
    double mEta;
  };	
  
  //----------------------No PF Muon Cut------------------------------------------------------
  class NoPFMuon : public Operation::_Base 
  {
  public:
    NoPFMuon(double pt, double eta);
    ~NoPFMuon();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mPt;
    double mEta;   
  };	
  
  //----------------------No PF Electron Cut--------------------------------------------------
  class NoPFElec : public Operation::_Base 
  {
  public:
    NoPFElec(double pt, double eta);
    ~NoPFElec();
    bool Process(EventData & eventData);
    std::ostream& Description(std::ostream& ostrm);
  private:
    double mPt;
    double mEta;   
  };	
}

#include "Operation.cc"
#endif //~Operations_h
