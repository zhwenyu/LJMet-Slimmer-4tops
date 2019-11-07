#define step1_cxx
#include "step1.h"
#include <fstream>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <TH2.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <sstream>
#include <string>
#include <vector>
#include <TH3.h>
#include "HardcodedConditions.h"

using namespace std;

// ----------------------------------------------------------------------------
// Define functions
// ----------------------------------------------------------------------------

bool comparepair( const std::pair<double,int> a, const std::pair<double,int> b) { return a.first > b.first; }
bool comparefloat( const float a, const float b) { return a < b; }

TRandom3 Rand;

const double MTOP  = 173.5;
const double MW    = 80.4; 

bool step1::applySF(bool& isTagged, float tag_SF, float tag_eff){
  
  bool newTag = isTagged;
  if (tag_SF == 1) return newTag; //no correction needed 

  //throw die
  float coin = Rand.Uniform(1.);    

  if(tag_SF > 1){  // use this if SF>1

    if( !isTagged ) {

      //fraction of jets that need to be upgraded
      float mistagPercent = (1.0 - tag_SF) / (1.0 - (tag_SF/tag_eff) );

      //upgrade to tagged
      if( coin < mistagPercent ) {newTag = true;}
    }

  }else{  // use this if SF<1
      
    //downgrade tagged to untagged
    if( isTagged && coin > tag_SF ) {newTag = false;}

  }

  return newTag;
}

// -------------------------------------
// Function- SAVE Histograms from ljmet
//--------------------------------------
void step1::saveHistograms() 
{ 
TH1D* numhist = (TH1D*)inputFile->Get("mcweightanalyzer/NumTrueHist");
TH1D* wgthist = (TH1D*)inputFile->Get("mcweightanalyzer/weightHist");
outputFile->cd();
numhist->Write();
wgthist->Write();

}


// ----------------------------------------------------------------------------
// MAIN EVENT LOOP
// ----------------------------------------------------------------------------

void step1::Loop(TString inTreeName, TString outTreeName ) 
{
  
  HardcodedConditions hardcodedConditions;
  
  // ----------------------------------------------------------------------------
  // Turn on input tree branches
  // ----------------------------------------------------------------------------
  inputTree=(TTree*)inputFile->Get(inTreeName+"/"+inTreeName);
  if(inputTree->GetEntries()==0) {
    std::cout<<"WARNING! Found 0 events in the tree!!!!"<<std::endl;;
    exit(1);
  }
  Init(inputTree);

   if (inputTree == 0) return;
   
   inputTree->SetBranchStatus("*",0);

   //Event info
   inputTree->SetBranchStatus("event_CommonCalc",1);
   inputTree->SetBranchStatus("run_CommonCalc",1);
   inputTree->SetBranchStatus("lumi_CommonCalc",1);
   //   inputTree->SetBranchStatus("nPV_MultiLepCalc",1);
   inputTree->SetBranchStatus("nTrueInteractions_MultiLepCalc",1);
   inputTree->SetBranchStatus("MCWeight_MultiLepCalc",1);
   inputTree->SetBranchStatus("evtWeightsMC_MultiLepCalc",1);
   inputTree->SetBranchStatus("LHEweightids_MultiLepCalc",1);
   inputTree->SetBranchStatus("LHEweights_MultiLepCalc",1);
   inputTree->SetBranchStatus("NewPDFweights_MultiLepCalc",1);
   inputTree->SetBranchStatus("HTfromHEPUEP_MultiLepCalc",1);
   inputTree->SetBranchStatus("L1NonPrefiringProb_CommonCalc",1);
   inputTree->SetBranchStatus("L1NonPrefiringProbUp_CommonCalc",1);
   inputTree->SetBranchStatus("L1NonPrefiringProbDown_CommonCalc",1);
   
   //triggers
   inputTree->SetBranchStatus("vsSelMCTriggersEl_MultiLepCalc",1);
   inputTree->SetBranchStatus("viSelMCTriggersEl_MultiLepCalc",1);
   inputTree->SetBranchStatus("vsSelMCTriggersMu_MultiLepCalc",1);
   inputTree->SetBranchStatus("viSelMCTriggersMu_MultiLepCalc",1);
   inputTree->SetBranchStatus("vsSelTriggersEl_MultiLepCalc",1);
   inputTree->SetBranchStatus("viSelTriggersEl_MultiLepCalc",1);
   inputTree->SetBranchStatus("vsSelTriggersMu_MultiLepCalc",1);
   inputTree->SetBranchStatus("viSelTriggersMu_MultiLepCalc",1);
   
   //electrons
   inputTree->SetBranchStatus("elPt_MultiLepCalc",1);
   inputTree->SetBranchStatus("elEta_MultiLepCalc",1);
   inputTree->SetBranchStatus("elPhi_MultiLepCalc",1);
   inputTree->SetBranchStatus("elEnergy_MultiLepCalc",1);
   inputTree->SetBranchStatus("elMiniIso_MultiLepCalc",1);  
   inputTree->SetBranchStatus("elRelIso_MultiLepCalc",1);
   inputTree->SetBranchStatus("elMother_id_MultiLepCalc",1);
   inputTree->SetBranchStatus("elNumberOfMothers_MultiLepCalc",1);
     
   //muons
   inputTree->SetBranchStatus("muPt_MultiLepCalc",1);
   inputTree->SetBranchStatus("muEta_MultiLepCalc",1);
   inputTree->SetBranchStatus("muPhi_MultiLepCalc",1);
   inputTree->SetBranchStatus("muEnergy_MultiLepCalc",1);
   inputTree->SetBranchStatus("muMiniIso_MultiLepCalc",1);
   inputTree->SetBranchStatus("muRelIso_MultiLepCalc",1);
   inputTree->SetBranchStatus("muMother_id_MultiLepCalc",1);
   inputTree->SetBranchStatus("muNumberOfMothers_MultiLepCalc",1);
   
   //missing et
   inputTree->SetBranchStatus("corr_met_MultiLepCalc",1);
   inputTree->SetBranchStatus("corr_met_phi_MultiLepCalc",1);
   inputTree->SetBranchStatus("corr_metmod_MultiLepCalc",1);
   inputTree->SetBranchStatus("corr_metmod_phi_MultiLepCalc",1);

   //boosted truth
   inputTree->SetBranchStatus("HadronicVHtPt_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtEta_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtPhi_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtEnergy_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtID_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD0Pt_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD0Eta_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD0Phi_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD0E_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD1Pt_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD1Eta_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD1Phi_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD1E_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD2Pt_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD2Eta_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD2Phi_JetSubCalc",1);
   inputTree->SetBranchStatus("HadronicVHtD2E_JetSubCalc",1);

   //genParticles
   inputTree->SetBranchStatus("genPt_MultiLepCalc",1);
   inputTree->SetBranchStatus("genEta_MultiLepCalc",1);
   inputTree->SetBranchStatus("genPhi_MultiLepCalc",1);
   inputTree->SetBranchStatus("genEnergy_MultiLepCalc",1);
   inputTree->SetBranchStatus("genStatus_MultiLepCalc",1);
   inputTree->SetBranchStatus("genID_MultiLepCalc",1);
   inputTree->SetBranchStatus("genIndex_MultiLepCalc",1);
   inputTree->SetBranchStatus("genMotherID_MultiLepCalc",1);
   inputTree->SetBranchStatus("genMotherIndex_MultiLepCalc",1);
   inputTree->SetBranchStatus("genJetPt_MultiLepCalc",1);
   inputTree->SetBranchStatus("genJetEta_MultiLepCalc",1);
   inputTree->SetBranchStatus("genJetPhi_MultiLepCalc",1);
   inputTree->SetBranchStatus("genJetEnergy_MultiLepCalc",1);
   if(isTT){
   inputTree->SetBranchStatus("genJetPtNoClean_MultiLepCalc",1);
   inputTree->SetBranchStatus("genJetEtaNoClean_MultiLepCalc",1);
   inputTree->SetBranchStatus("genJetPhiNoClean_MultiLepCalc",1);
   inputTree->SetBranchStatus("genJetEnergyNoClean_MultiLepCalc",1);
   }                

   //JetSubCalc
   inputTree->SetBranchStatus("theJetHFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetEta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetPhi_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetEnergy_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetDeepCSVb_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetDeepCSVbb_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetDeepCSVc_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetDeepCSVudsg_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8DoubleB_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_bSFup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_bSFdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_lSFup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_lSFdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetBTag_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Pt_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Eta_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Phi_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Mass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8Energy_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau1_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau2_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8NjettinessTau3_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSTau1_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSTau2_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSTau3_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSPrunedMass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8CHSSoftDropMass_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropRaw_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDropCorr_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDrop_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDrop_JMSup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDrop_JMSdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDrop_JMRup_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SoftDrop_JMRdn_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetNDeepCSVL_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetHFlav_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetIndex_JetSubCalc",1);
   inputTree->SetBranchStatus("theJetAK8SDSubjetSize_JetSubCalc",1);
   inputTree->SetBranchStatus("maxProb_JetSubCalc",1);
   
   //top
   inputTree->SetBranchStatus("ttbarMass_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topEnergy_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topEta_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topMass_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topPhi_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topPt_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topID_TTbarMassCalc",1);

   inputTree->SetBranchStatus("allTopsEnergy_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsEta_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsPhi_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsPt_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsID_TTbarMassCalc",1);
   inputTree->SetBranchStatus("allTopsStatus_TTbarMassCalc",1);

   inputTree->SetBranchStatus("genTtbarIdCategory_TTbarMassCalc",1);

   //top W
   inputTree->SetBranchStatus("topWEnergy_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topWEta_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topWPhi_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topWPt_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topWID_TTbarMassCalc",1);
   
   //top b
   inputTree->SetBranchStatus("topbEnergy_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topbEta_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topbPhi_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topbPt_TTbarMassCalc",1);
   inputTree->SetBranchStatus("topbID_TTbarMassCalc",1);

   //HOTTaggerCalc
   inputTree->SetBranchStatus("topJet1Index_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topJet2Index_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topJet3Index_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topNAK4_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topNtops_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topBestGenEnergy_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topBestGenEta_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topBestGenPhi_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topBestGenPt_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topDRmax_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topDThetaMax_HOTTaggerCalc", 1);
   inputTree->SetBranchStatus("topDThetaMin_HOTTaggerCalc", 1);
   inputTree->SetBranchStatus("topDiscriminator_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topEta_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topMass_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topNconstituents_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topPhi_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topPt_HOTTaggerCalc",1);
   inputTree->SetBranchStatus("topType_HOTTaggerCalc",1);

   
  // ----------------------------------------------------------------------------
  // Create output tree and define branches
  // ----------------------------------------------------------------------------
   
   // OUTPUT FILE
   outputFile->cd();
   TTree *outputTree = new TTree(outTreeName, outTreeName);


   //Common
   outputTree->Branch("event_CommonCalc",&event_CommonCalc,"event_CommonCalc/L");
   outputTree->Branch("run_CommonCalc",&run_CommonCalc,"run_CommonCalc/I");
   outputTree->Branch("lumi_CommonCalc",&lumi_CommonCalc,"lumi_CommonCalc/I");
   outputTree->Branch("nTrueInteractions_MultiLepCalc",&nTrueInteractions_MultiLepCalc,"nTrueInteractions_MultiLepCalc/I");
   outputTree->Branch("isElectron",&isElectron,"isElectron/I");
   outputTree->Branch("isMuon",&isMuon,"isMuon/I");
   outputTree->Branch("MCPastTrigger",&MCPastTrigger,"MCPastTrigger/I");
   outputTree->Branch("DataPastTrigger",&DataPastTrigger,"DataPastTrigger/I");
   outputTree->Branch("L1NonPrefiringProb_CommonCalc",&L1NonPrefiringProb_CommonCalc,"L1NonPrefiringProb_CommonCalc/D");
   outputTree->Branch("L1NonPrefiringProbUp_CommonCalc",&L1NonPrefiringProbUp_CommonCalc,"L1NonPrefiringProbUp_CommonCalc/D");
   outputTree->Branch("L1NonPrefiringProbDown_CommonCalc",&L1NonPrefiringProbDown_CommonCalc,"L1NonPrefiringProbDown_CommonCalc/D");
   
   //weights
   outputTree->Branch("MCWeight_MultiLepCalc",&MCWeight_MultiLepCalc,"MCWeight_MultiLepCalc/D");
   outputTree->Branch("renormWeights",&renormWeights);
   outputTree->Branch("renormPSWeights",&renormPSWeights);
   outputTree->Branch("pdfWeights",&pdfWeights);
   outputTree->Branch("pdfNewWeights",&pdfNewWeights);
   outputTree->Branch("pdfNewNominalWeight",&pdfNewNominalWeight,"pdfNewNominalWeight/F");
   outputTree->Branch("pileupWeight",&pileupWeight,"pileupWeight/F");
   outputTree->Branch("pileupWeightUp",&pileupWeightUp,"pileupWeightUp/F");
   outputTree->Branch("pileupWeightDown",&pileupWeightDown,"pileupWeightDown/F");
   outputTree->Branch("HTSF_Pol",&HTSF_Pol,"HTSF_Pol/F");
   outputTree->Branch("HTSF_PolUp",&HTSF_PolUp,"HTSF_PolUp/F");
   outputTree->Branch("HTSF_PolDn",&HTSF_PolDn,"HTSF_PolDn/F");
   outputTree->Branch("topPtWeight13TeV",&topPtWeight13TeV,"topPtWeight13TeV/F");          
   outputTree->Branch("EGammaGsfSF",&EGammaGsfSF,"EGammaGsfSF/F");
   outputTree->Branch("lepIdSF",&lepIdSF,"lepIdSF/F");
   outputTree->Branch("triggerSF",&triggerSF,"triggerSF/F");
   outputTree->Branch("isoSF",&isoSF,"isoSF/F");
   
   //ttbar generator
   outputTree->Branch("ttbarMass_TTbarMassCalc",&ttbarMass_TTbarMassCalc,"ttbarMass_TTbarMassCalc/D");
   outputTree->Branch("genTopPt",&genTopPt,"genTopPt/F");
   outputTree->Branch("genAntiTopPt",&genAntiTopPt,"genAntiTopPt/F");
   outputTree->Branch("topEnergy_TTbarMassCalc",&topEnergy_TTbarMassCalc);
   outputTree->Branch("topEta_TTbarMassCalc",&topEta_TTbarMassCalc);
   outputTree->Branch("topMass_TTbarMassCalc",&topMass_TTbarMassCalc);
   outputTree->Branch("topPhi_TTbarMassCalc",&topPhi_TTbarMassCalc);   
   outputTree->Branch("topPt_TTbarMassCalc",&topPt_TTbarMassCalc);      
   outputTree->Branch("topID_TTbarMassCalc",&topID_TTbarMassCalc);
   outputTree->Branch("topWEnergy_TTbarMassCalc",&topWEnergy_TTbarMassCalc);
   outputTree->Branch("topWEta_TTbarMassCalc",&topWEta_TTbarMassCalc);
   outputTree->Branch("topWPhi_TTbarMassCalc",&topWPhi_TTbarMassCalc);
   outputTree->Branch("topWPt_TTbarMassCalc",&topWPt_TTbarMassCalc);   
   outputTree->Branch("topWID_TTbarMassCalc",&topWID_TTbarMassCalc);      
   outputTree->Branch("topbEnergy_TTbarMassCalc",&topbEnergy_TTbarMassCalc);
   outputTree->Branch("topbEta_TTbarMassCalc",&topbEta_TTbarMassCalc);
   outputTree->Branch("topbPhi_TTbarMassCalc",&topbPhi_TTbarMassCalc);
   outputTree->Branch("topbPt_TTbarMassCalc",&topbPt_TTbarMassCalc);   
   outputTree->Branch("topbID_TTbarMassCalc",&topbID_TTbarMassCalc);
  
   //leptons
   outputTree->Branch("corr_met_MultiLepCalc",&corr_met_MultiLepCalc,"corr_met_MultiLepCalc/D");
   outputTree->Branch("corr_met_phi_MultiLepCalc",&corr_met_phi_MultiLepCalc,"corr_met_phi_MultiLepCalc/D");
   outputTree->Branch("corr_metmod_MultiLepCalc",&corr_metmod_MultiLepCalc,"corr_metmod_MultiLepCalc/D");
   outputTree->Branch("corr_metmod_phi_MultiLepCalc",&corr_metmod_phi_MultiLepCalc,"corr_metmod_phi_MultiLepCalc/D");
   outputTree->Branch("leptonPt_MultiLepCalc",&leptonPt_MultiLepCalc,"leptonPt_MultiLepCalc/F");
   outputTree->Branch("leptonEta_MultiLepCalc",&leptonEta_MultiLepCalc,"leptonEta_MultiLepCalc/F");
   outputTree->Branch("leptonPhi_MultiLepCalc",&leptonPhi_MultiLepCalc,"leptonPhi_MultiLepCalc/F");
   outputTree->Branch("leptonEnergy_MultiLepCalc",&leptonEnergy_MultiLepCalc,"leptonEnergy_MultiLepCalc/F");
   outputTree->Branch("leptonMVAValue_MultiLepCalc",&leptonMVAValue_MultiLepCalc,"leptonMVAValue_MultiLepCalc/F");
   outputTree->Branch("leptonMiniIso_MultiLepCalc",&leptonMiniIso_MultiLepCalc,"leptonMiniIso_MultiLepCalc/F");
   outputTree->Branch("leptonRelIso_MultiLepCalc",&leptonRelIso_MultiLepCalc,"leptonRelIso_MultiLepCalc/F");
   outputTree->Branch("elMother_id_MultiLepCalc",&elMother_id_MultiLepCalc);
   outputTree->Branch("elNumberOfMothers_MultiLepCalc",&elNumberOfMothers_MultiLepCalc);
   outputTree->Branch("muMother_id_MultiLepCalc",&muMother_id_MultiLepCalc);
   outputTree->Branch("muNumberOfMothers_MultiLepCalc",&theJetPt_JetSubCalc_PtOrdered);   
   outputTree->Branch("MT_lepMet",&MT_lepMet,"MT_lepMet/F");
   outputTree->Branch("MT_lepMetmod",&MT_lepMetmod,"MT_lepMetmod/F");
   outputTree->Branch("minDPhi_MetJet",&minDPhi_MetJet,"minDPhi_MetJet/F");

   // AK4
   outputTree->Branch("theJetPt_JetSubCalc_PtOrdered",&theJetPt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetEta_JetSubCalc_PtOrdered",&theJetEta_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetPhi_JetSubCalc_PtOrdered",&theJetPhi_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetEnergy_JetSubCalc_PtOrdered",&theJetEnergy_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetDeepCSVb_JetSubCalc_PtOrdered",&theJetDeepCSVb_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetDeepCSVbb_JetSubCalc_PtOrdered",&theJetDeepCSVbb_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetDeepCSVc_JetSubCalc_PtOrdered",&theJetDeepCSVc_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetDeepCSVudsg_JetSubCalc_PtOrdered",&theJetDeepCSVudsg_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetHFlav_JetSubCalc_PtOrdered",&theJetHFlav_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetPFlav_JetSubCalc_PtOrdered",&theJetPFlav_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetBTag_JetSubCalc_PtOrdered",&theJetBTag_JetSubCalc_PtOrdered);
   outputTree->Branch("AK4HTpMETpLepPt",&AK4HTpMETpLepPt,"AK4HTpMETpLepPt/F");
   outputTree->Branch("AK4HT",&AK4HT,"AK4HT/F");
   outputTree->Branch("NJets_JetSubCalc",&NJets_JetSubCalc,"NJets_JetSubCalc/I");
   outputTree->Branch("NJetsCSV_JetSubCalc",&NJetsCSV_JetSubCalc,"NJetsCSV_JetSubCalc/I");
   outputTree->Branch("NJetsCSVwithSF_JetSubCalc",&NJetsCSVwithSF_JetSubCalc,"NJetsCSVwithSF_JetSubCalc/I");
   outputTree->Branch("NJetsCSVwithSF_JetSubCalc_bSFup",&NJetsCSVwithSF_JetSubCalc_bSFup,"NJetsCSVwithSF_JetSubCalc_bSFup/I");
   outputTree->Branch("NJetsCSVwithSF_JetSubCalc_bSFdn",&NJetsCSVwithSF_JetSubCalc_bSFdn,"NJetsCSVwithSF_JetSubCalc_bSFdn/I");
   outputTree->Branch("NJetsCSVwithSF_JetSubCalc_lSFup",&NJetsCSVwithSF_JetSubCalc_lSFup,"NJetsCSVwithSF_JetSubCalc_lSFup/I");
   outputTree->Branch("NJetsCSVwithSF_JetSubCalc_lSFdn",&NJetsCSVwithSF_JetSubCalc_lSFdn,"NJetsCSVwithSF_JetSubCalc_lSFdn/I");
   outputTree->Branch("deltaR_lepMinMlb",&deltaR_lepMinMlb,"deltaR_lepMinMlb/F");
   outputTree->Branch("deltaR_lepMinMlb_bSFup",&deltaR_lepMinMlb_bSFup,"deltaR_lepMinMlb_bSFup/F");
   outputTree->Branch("deltaR_lepMinMlb_bSFdn",&deltaR_lepMinMlb_bSFdn,"deltaR_lepMinMlb_bSFdn/F");
   outputTree->Branch("deltaR_lepMinMlb_lSFup",&deltaR_lepMinMlb_lSFup,"deltaR_lepMinMlb_lSFup/F");
   outputTree->Branch("deltaR_lepMinMlb_lSFdn",&deltaR_lepMinMlb_lSFdn,"deltaR_lepMinMlb_lSFdn/F");
   outputTree->Branch("deltaR_lepMinMlj",&deltaR_lepMinMlj,"deltaR_lepMinMlj/F");
   outputTree->Branch("minMleppBjet",&minMleppBjet,"minMleppBjet/F");
   outputTree->Branch("minMleppBjet_bSFup",&minMleppBjet_bSFup,"minMleppBjet_bSFup/F");
   outputTree->Branch("minMleppBjet_bSFdn",&minMleppBjet_bSFdn,"minMleppBjet_bSFdn/F");
   outputTree->Branch("minMleppBjet_lSFup",&minMleppBjet_lSFup,"minMleppBjet_lSFup/F");
   outputTree->Branch("minMleppBjet_lSFdn",&minMleppBjet_lSFdn,"minMleppBjet_lSFdn/F");
   outputTree->Branch("minMleppJet",&minMleppJet,"mixnMleppJet/F");
   outputTree->Branch("minDR_lepJet",&minDR_lepJet,"minDR_lepJet/F");
   outputTree->Branch("ptRel_lepJet",&ptRel_lepJet,"ptRel_lepJet/F");
   outputTree->Branch("deltaR_lepJets",&deltaR_lepJets);
   outputTree->Branch("deltaR_lepBJets",&deltaR_lepBJets);
   outputTree->Branch("deltaR_lepBJets_bSFup",&deltaR_lepBJets_bSFup);
   outputTree->Branch("deltaR_lepBJets_bSFdn",&deltaR_lepBJets_bSFdn);
   outputTree->Branch("deltaR_lepBJets_lSFup",&deltaR_lepBJets_lSFup);
   outputTree->Branch("deltaR_lepBJets_lSFdn",&deltaR_lepBJets_lSFdn);

   // AK4 gen
   outputTree->Branch("genPt_MultiLepCalc",&genPt_MultiLepCalc);
   outputTree->Branch("genEta_MultiLepCalc",&genEta_MultiLepCalc);
   outputTree->Branch("genPhi_MultiLepCalc",&genPhi_MultiLepCalc);
   outputTree->Branch("genEnergy_MultiLepCalc",&genEnergy_MultiLepCalc);
   outputTree->Branch("genStatus_MultiLepCalc",&genStatus_MultiLepCalc);
   outputTree->Branch("genID_MultiLepCalc",&genID_MultiLepCalc);
   outputTree->Branch("genJetPt_MultiLepCalc",&genJetPt_MultiLepCalc);                  
   outputTree->Branch("genJetEta_MultiLepCalc",&genJetEta_MultiLepCalc);                     
   outputTree->Branch("genJetPhi_MultiLepCalc",&genJetPhi_MultiLepCalc);                  
   outputTree->Branch("genJetEnergy_MultiLepCalc",&genJetEnergy_MultiLepCalc);  
   if(isTT){                
   outputTree->Branch("genJetPtNoClean_MultiLepCalc",&genJetPtNoClean_MultiLepCalc);                  
   outputTree->Branch("genJetEtaNoClean_MultiLepCalc",&genJetEtaNoClean_MultiLepCalc);                     
   outputTree->Branch("genJetPhiNoClean_MultiLepCalc",&genJetPhiNoClean_MultiLepCalc);                  
   outputTree->Branch("genJetEnergyNoClean_MultiLepCalc",&genJetEnergyNoClean_MultiLepCalc); 
   }                 
   outputTree->Branch("genIndex_MultiLepCalc",&genIndex_MultiLepCalc);
   outputTree->Branch("genMotherID_MultiLepCalc",&genMotherID_MultiLepCalc);
   outputTree->Branch("genMotherIndex_MultiLepCalc",&genMotherIndex_MultiLepCalc);

   // jet truth
   outputTree->Branch("HadronicVHtID_JetSubCalc",&HadronicVHtID_JetSubCalc);
   outputTree->Branch("HadronicVHtPt_JetSubCalc",&HadronicVHtPt_JetSubCalc);
   outputTree->Branch("HadronicVHtEta_JetSubCalc",&HadronicVHtEta_JetSubCalc);
   outputTree->Branch("HadronicVHtPhi_JetSubCalc",&HadronicVHtPhi_JetSubCalc);
   outputTree->Branch("HadronicVHtEnergy_JetSubCalc",&HadronicVHtEnergy_JetSubCalc);
   outputTree->Branch("theJetAK8Wmatch_JetSubCalc_PtOrdered",&theJetAK8Wmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Tmatch_JetSubCalc_PtOrdered",&theJetAK8Tmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Zmatch_JetSubCalc_PtOrdered",&theJetAK8Zmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Hmatch_JetSubCalc_PtOrdered",&theJetAK8Hmatch_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8MatchedPt_JetSubCalc_PtOrdered",&theJetAK8MatchedPt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Truth_JetSubCalc_PtOrdered",&theJetAK8Truth_JetSubCalc_PtOrdered);

   // AK8
   outputTree->Branch("NJetsAK8_JetSubCalc",&NJetsAK8_JetSubCalc,"NJetsAK8_JetSubCalc/I");
   outputTree->Branch("theJetAK8Pt_JetSubCalc_PtOrdered",&theJetAK8Pt_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Eta_JetSubCalc_PtOrdered",&theJetAK8Eta_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Phi_JetSubCalc_PtOrdered",&theJetAK8Phi_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Mass_JetSubCalc_PtOrdered",&theJetAK8Mass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Energy_JetSubCalc_PtOrdered",&theJetAK8Energy_JetSubCalc_PtOrdered);
   outputTree->Branch("minDR_leadAK8otherAK8",&minDR_leadAK8otherAK8,"minDR_leadAK8otherAK8/F");
   outputTree->Branch("minDR_lepAK8",&minDR_lepAK8,"minDR_lepAK8/F");
   outputTree->Branch("ptRel_lepAK8",&ptRel_lepAK8,"ptRel_lepAK8/F");
   outputTree->Branch("deltaR_lepAK8s",&deltaR_lepAK8s);

   // mass + tau tagging
   outputTree->Branch("maxProb_JetSubCalc_PtOrdered",&maxProb_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered",&theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered",&theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropRaw_JetSubCalc_PtOrdered",&theJetAK8SoftDropRaw_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDropCorr_JetSubCalc_PtOrdered",&theJetAK8SoftDropCorr_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8DoubleB_JetSubCalc_PtOrdered",&theJetAK8DoubleB_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDrop_JetSubCalc_PtOrdered",&theJetAK8SoftDrop_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered",&theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered);
   outputTree->Branch("theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered",&theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered);
   outputTree->Branch("theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered",&theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered);
   outputTree->Branch("theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered",&theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau1_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau1_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau2_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau2_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8NjettinessTau3_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau3_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSTau1_JetSubCalc_PtOrdered",&theJetAK8CHSTau1_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSTau2_JetSubCalc_PtOrdered",&theJetAK8CHSTau2_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8CHSTau3_JetSubCalc_PtOrdered",&theJetAK8CHSTau3_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered",&theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetSize_JetSubCalc_PtOrdered",&theJetAK8SDSubjetSize_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered",&theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered",&theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered);
   outputTree->Branch("theJetAK8Indx_Wtagged",&theJetAK8Indx_Wtagged);
   outputTree->Branch("NJetsWtagged",&NJetsWtagged,"NJetsWtagged/I");
   outputTree->Branch("NJetsWtagged_shifts",&NJetsWtagged_shifts);
   outputTree->Branch("NJetsTtagged",&NJetsTtagged,"NJetsTtagged/I");
   outputTree->Branch("NJetsTtagged_shifts",&NJetsTtagged_shifts);
     
   //HOT tagger
   outputTree->Branch("topJet1Index_HOTTaggerCalc",&topJet1Index_HOTTaggerCalc);
   outputTree->Branch("topJet2Index_HOTTaggerCalc",&topJet2Index_HOTTaggerCalc);
   outputTree->Branch("topJet3Index_HOTTaggerCalc",&topJet3Index_HOTTaggerCalc);
   outputTree->Branch("topNAK4_HOTTaggerCalc",&topNAK4_HOTTaggerCalc,"topNAK4_HOTTaggerCalc/I");
   outputTree->Branch("topNtops_HOTTaggerCalc",&topNtops_HOTTaggerCalc,"topNtops_HOTTaggerCalc/I");
//    outputTree->Branch("topBestGenEnergy_HOTTaggerCalc",&topBestGenEnergy_HOTTaggerCalc);
//    outputTree->Branch("topBestGenEta_HOTTaggerCalc",&topBestGenEta_HOTTaggerCalc);
//    outputTree->Branch("topBestGenPhi_HOTTaggerCalc",&topBestGenPhi_HOTTaggerCalc);
//    outputTree->Branch("topBestGenPt_HOTTaggerCalc",&topBestGenPt_HOTTaggerCalc);
   outputTree->Branch("topDRmax_HOTTaggerCalc",&topDRmax_HOTTaggerCalc);
   outputTree->Branch("topDThetaMax_HOTTaggerCalc",&topDThetaMax_HOTTaggerCalc);
   outputTree->Branch("topDThetaMin_HOTTaggerCalc",&topDThetaMin_HOTTaggerCalc);
   outputTree->Branch("topDiscriminator_HOTTaggerCalc",&topDiscriminator_HOTTaggerCalc);
   outputTree->Branch("topEta_HOTTaggerCalc",&topEta_HOTTaggerCalc);
   outputTree->Branch("topMass_HOTTaggerCalc",&topMass_HOTTaggerCalc);
   outputTree->Branch("topNconstituents_HOTTaggerCalc",&topNconstituents_HOTTaggerCalc);
   outputTree->Branch("topPhi_HOTTaggerCalc",&topPhi_HOTTaggerCalc);
   outputTree->Branch("topPt_HOTTaggerCalc",&topPt_HOTTaggerCalc);
   outputTree->Branch("topType_HOTTaggerCalc",&topType_HOTTaggerCalc);
   outputTree->Branch("NresolvedTops1pFake",&NresolvedTops1pFake,"NresolvedTops1pFake/I");
   outputTree->Branch("NresolvedTops2pFake",&NresolvedTops2pFake,"NresolvedTops2pFake/I");
   outputTree->Branch("NresolvedTops5pFake",&NresolvedTops5pFake,"NresolvedTops5pFake/I");
   outputTree->Branch("NresolvedTops10pFake",&NresolvedTops10pFake,"NresolvedTops10pFake/I");
   outputTree->Branch("NresolvedTops1pFake_shifts",&NresolvedTops1pFake_shifts);
   outputTree->Branch("NresolvedTops2pFake_shifts",&NresolvedTops2pFake_shifts);
   outputTree->Branch("NresolvedTops5pFake_shifts",&NresolvedTops5pFake_shifts);
   outputTree->Branch("NresolvedTops10pFake_shifts",&NresolvedTops10pFake_shifts);

   outputTree->Branch("isHTgt500Njetge9",&isHTgt500Njetge9,"isHTgt500Njetge9/I");
   outputTree->Branch("BJetLeadPt",&BJetLeadPt,"BJetLeadPt/F");
   outputTree->Branch("BJetLeadPt_bSFup",&BJetLeadPt_bSFup,"BJetLeadPt_bSFup/F");
   outputTree->Branch("BJetLeadPt_bSFdn",&BJetLeadPt_bSFdn,"BJetLeadPt_bSFdn/F");
   outputTree->Branch("BJetLeadPt_lSFup",&BJetLeadPt_lSFup,"BJetLeadPt_lSFup/F");
   outputTree->Branch("BJetLeadPt_lSFdn",&BJetLeadPt_lSFdn,"BJetLeadPt_lSFdn/F");
   outputTree->Branch("WJetLeadPt",&WJetLeadPt,"WJetLeadPt/F");
   outputTree->Branch("TJetLeadPt",&TJetLeadPt,"TJetLeadPt/F"); 

   outputTree->Branch("genTtbarIdCategory_TTbarMassCalc",&genTtbarIdCategory_TTbarMassCalc);    
  
  // ----------------------------------------------------------------------------
  // Define and initialize objects / cuts / efficiencies
  // ----------------------------------------------------------------------------

   // basic cuts
   float metCut=20;
   float htCut=0;
   int   nAK8jetsCut=0;
   float lepPtCut=25;
   float elEtaCut=2.1;
   float muEtaCut=2.1;
   int   njetsCut=4;
   float jetPtCut=30;
   float jetEtaCut=2.4;
   float ak8EtaCut=2.4;
   float ak8PtCut=200;

   // counters
   int npass_trigger   = 0;
   int npass_met       = 0;
   int npass_ht        = 0;
   int npass_Njets     = 0;
   int npass_nAK8jets  = 0;
   int npass_lepPt     = 0;
   int npass_ElEta     = 0;
   int npass_MuEta     = 0;
   int npass_all       = 0;
   int Nelectrons      = 0;
   int Nmuons          = 0;
   int NrelIsoFail     = 0;

   // Lorentz vectors
   TLorentzVector jet_lv;
   TLorentzVector bjet_lv;
   TLorentzVector wjet1_lv;
   TLorentzVector tjet1_lv;
   TLorentzVector lepton_lv;
   TLorentzVector ak8_lv;

   // Polynominals for WJets HT scaling
   TF1 *poly2 = new TF1("poly2","max([6],[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x + [5]*x*x*x*x*x)",100,5000);
   poly2->SetParameter(0,    0.998174);  
   poly2->SetParameter(1, 8.40861e-05); 
   poly2->SetParameter(2,-6.63274e-07);
   poly2->SetParameter(3, 4.09272e-10); 
   poly2->SetParameter(4,-9.50233e-14); 
   poly2->SetParameter(5, 7.59648e-18); 
   poly2->SetParameter(6,0.402806);
   
   TF1 *poly2U = new TF1("poly2U","max([6],[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x + [5]*x*x*x*x*x)",100,5000);
   poly2U->SetParameter(0,    0.998164);  
   poly2U->SetParameter(1, 8.51652e-05); 
   poly2U->SetParameter(2,-6.62919e-07);
   poly2U->SetParameter(3,  4.1205e-10); 
   poly2U->SetParameter(4,-9.57795e-14); 
   poly2U->SetParameter(5, 7.67371e-18); 
   poly2U->SetParameter(6,0.454456);
   
   TF1 *poly2D = new TF1("poly2D","max([6],[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x + [5]*x*x*x*x*x)",100,5000);
   poly2D->SetParameter(0,    0.998183);  
   poly2D->SetParameter(1, 8.30069e-05); 
   poly2D->SetParameter(2,-6.63629e-07);
   poly2D->SetParameter(3, 4.06495e-10); 
   poly2D->SetParameter(4,-9.42671e-14); 
   poly2D->SetParameter(5, 7.51924e-18); 
   poly2D->SetParameter(6,0.351156);
  
  // ----------------------------------------------------------------------------
  // RUN THE EVENT LOOP
  // ----------------------------------------------------------------------------

   cout << "RUN CONFIG: YEAR = " << Year << endl;
   cout << "isMC = " << isMC << ", isSig = " << isSig << ", SigMass = " << SigMass << endl;
   cout << "isTTTT = " << isTTTT << ", isXX = " << isXX << ", isTpTp = " << isTpTp << ", isBpBp = " << isBpBp << endl;
   cout << "For W's: isTT = " << isTT << ", isSTt = " << isSTt << ", isSTtW = " << isSTtW << endl;
   cout << "For jets & PDF: isTOP = " << isTOP << ", isMadgraphBkg = " << isMadgraphBkg << endl;
   cout << "Pileup index: " << pileupIndex << endl;
   cout << "isTTincMtt0to700: " << isTTincMtt0to700 << endl;
   cout << "isTTincMtt0to1000: " << isTTincMtt0to1000 << endl;
   cout << "isTTincMtt700to1000: " << isTTincMtt700to1000 << endl;
   cout << "isTTincMtt1000toInf: " << isTTincMtt1000toInf << endl;
   cout << "isTTSemilepIncHT0Njet0: " << isTTSemilepIncHT0Njet0 << endl;
   cout << "isTTSemilepIncHT500Njet9: " << isTTSemilepIncHT500Njet9 << endl;
   cout << "isTTJJ: " << isTTJJ << endl;
   cout << "isTTCC: " << isTTCC << endl;
   cout << "isTTBB: " << isTTBB << endl;
   
   Long64_t nentries = inputTree->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = inputTree->GetEntry(jentry);   nbytes += nb;
      if (Cut(ientry) != 1) continue;
      
      //      if (ientry > 5000) continue;
      
      if(jentry % 1000 ==0) std::cout<<"Completed "<<jentry<<" out of "<<nentries<<" events"<<std::endl;

      // ----------------------------------------------------------------------------
      // Filter input file by mass or decay
      // ----------------------------------------------------------------------------

      if(isTTincMtt0to700 && ttbarMass_TTbarMassCalc >= 700.) continue;
      if(isTTincMtt0to1000 && ttbarMass_TTbarMassCalc >= 1000.) continue;
      if(isTTincMtt700to1000 && (ttbarMass_TTbarMassCalc < 700. || ttbarMass_TTbarMassCalc >= 1000.)) continue;
      if(isTTincMtt1000toInf && ttbarMass_TTbarMassCalc < 1000.) continue;

      // ----------------------------------------------------------------------------
      // Assign bool depending on gen level HT and Jet multiplicity for ttbar sample stitching
      // ----------------------------------------------------------------------------
      // HT calculated from jets with pT>30 and |eta|<2.4 > 500 GeV
      // Jet multiplicity (jet pT>30) >= 9
      isHTgt500Njetge9 = 0;
      if(isTT){
      double genHT = 0;
      int Ngenjet = 0;
      for(unsigned int ijet=0; ijet < genJetPtNoClean_MultiLepCalc->size(); ijet++){
	if(genJetPtNoClean_MultiLepCalc->at(ijet) > 30) Ngenjet+=1;
	if(genJetPtNoClean_MultiLepCalc->at(ijet) > 30 && fabs(genJetEtaNoClean_MultiLepCalc->at(ijet)) < 2.4) genHT+=genJetPtNoClean_MultiLepCalc->at(ijet);
      }
      if(genHT>500 && Ngenjet>=9) {isHTgt500Njetge9 = 1;}
      }
      
      if( isTTSemilepIncHT0Njet0   && isHTgt500Njetge9==1 ) continue;
      if( isTTSemilepIncHT500Njet9 && isHTgt500Njetge9==0 ) continue;
      
      if( isTTJJ && genTtbarIdCategory_TTbarMassCalc->at(0)!=0 ) continue;
      if( isTTCC && genTtbarIdCategory_TTbarMassCalc->at(0)!=1 ) continue;
      if( isTTBB && (genTtbarIdCategory_TTbarMassCalc->at(0)==0 || genTtbarIdCategory_TTbarMassCalc->at(0)==1) ) continue;

      // ----------------------------------------------------------------------------
      // Assign as electron or muon event
      // ----------------------------------------------------------------------------
      // **** If we had saveLooseLeps == True in TTsinglelep_MC_cfg.py then this needs work!
      // **** Choose an electron and muon ID for "tight" and find events with only 1 tight el or mu by that definition
      isElectron = 0;
      isMuon = 0;
      if(elPt_MultiLepCalc->size()==0 && muPt_MultiLepCalc->size()==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}
      if(elPt_MultiLepCalc->size()>0 && muPt_MultiLepCalc->size()>0) std::cout << "got el and mu, something wrong" << std::endl;
      if(elPt_MultiLepCalc->size()>1 || muPt_MultiLepCalc->size()>1) std::cout << "got more than one el or mu, something wrong" << std::endl;
      if(elPt_MultiLepCalc->size()>0 && muPt_MultiLepCalc->size()==0) {isElectron = 1; isMuon = 0;}
      if(elPt_MultiLepCalc->size()==0 && muPt_MultiLepCalc->size()>0) {isElectron = 0; isMuon = 1;}
      if(isElectron==0 && isMuon==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}
      
//       if(isMuon == 1) {
//       	if(muRelIso_MultiLepCalc->at(0) > 0.15) {
//       	  NrelIsoFail++;
//       	  //std::cout << "muRelIso > 0.15, skipping the event ..." << std::endl; 
//       	  continue;
//       	  }
//       	}

      if(isSM && isElectron == 1) continue;
      if(isSE && isMuon == 1) continue;

      double leppt = 0;
      double lepeta = 0;
      if(isElectron){leppt = elPt_MultiLepCalc->at(0); lepeta = elEta_MultiLepCalc->at(0);}
      if(isMuon){leppt = muPt_MultiLepCalc->at(0); lepeta = muEta_MultiLepCalc->at(0);}

      // ----------------------------------------------------------------------------
      // Pileup weight calculation
      // ----------------------------------------------------------------------------

      pileupWeight = 1.0;
      pileupWeightUp = 1.0;
      pileupWeightDown = 1.0;
	
      if(isMC){
	if(nTrueInteractions_MultiLepCalc > 99) nTrueInteractions_MultiLepCalc = 99;
        if(nTrueInteractions_MultiLepCalc > 79 && isSig && Year==2017) nTrueInteractions_MultiLepCalc = 79;
	if(nTrueInteractions_MultiLepCalc < 0) nTrueInteractions_MultiLepCalc = 0;
	if(pileupIndex < 0 || pileupIndex > 60){
	  std::cout << "I don't know this pileup sample, using TTToSemiLeptonic's" << std::endl;
	  pileupIndex = 26;
	}
	hardcodedConditions.GetPileupWeight(nTrueInteractions_MultiLepCalc, pileupIndex, &pileupWeight, &pileupWeightUp, &pileupWeightDown, Year);
      }

      // ----------------------------------------------------------------------------
      // Assign Lepton scale factor or efficiency weights, save trigger pass/fail
      // ----------------------------------------------------------------------------

      DataPastTrigger = 0;
      MCPastTrigger = 0;
      EGammaGsfSF = 1.0;
      lepIdSF = 1.0;
      triggerSF = 1.0;
      isoSF = 1.0;
      std::vector<std::string> eltriggers;
      std::vector<std::string> mutriggers;
//       eltriggers = {"Ele32_WPTight_Gsf","Ele35_WPTight_Gsf"};
//       mutriggers = {"IsoMu24_eta2p1","IsoMu27"};
      eltriggers = {"Ele15_IsoVVVL_PFHT450","Ele50_IsoVVVL_PFHT450","Ele15_IsoVVVL_PFHT600","Ele35_WPTight_Gsf","Ele38_WPTight_Gsf"};
      mutriggers = {"Mu15_IsoVVVL_PFHT450","Mu50_IsoVVVL_PFHT450","Mu15_IsoVVVL_PFHT600","Mu50","TkMu50"};
      if(isMC){ //MC triggers check
	if(isElectron){
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersEl_MultiLepCalc->size(); itrig++){
	    for(unsigned int jtrig=0; jtrig < eltriggers.size(); jtrig++){
	    	if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(eltriggers.at(jtrig)) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    }
	  }
	  
	  EGammaGsfSF = hardcodedConditions.GetEGammaGsfSF(leppt, lepeta, Year);
      lepIdSF = hardcodedConditions.GetElectronIdSF(leppt, lepeta, Year);
      isoSF = hardcodedConditions.GetElectronIsoSF(leppt, lepeta, Year);
	  triggerSF = hardcodedConditions.GetElectronTriggerSF(leppt, lepeta, Year);
	}
	if(isMuon){
	  for(unsigned int itrig=0; itrig < vsSelMCTriggersMu_MultiLepCalc->size(); itrig++){
	    for(unsigned int jtrig=0; jtrig < mutriggers.size(); jtrig++){
	    	if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(mutriggers.at(jtrig)) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTrigger = 1;
	    }
	  }
	  lepIdSF = hardcodedConditions.GetMuonIdSF(leppt, lepeta, Year);
	  isoSF = hardcodedConditions.GetMuonIsoSF(leppt, lepeta, Year);	  
	  triggerSF = hardcodedConditions.GetMuonTriggerSF(leppt, lepeta, Year);
	 
	}
	DataPastTrigger = 1;
        // Trigger SF Muon 
      }

      else{ //Data triggers check
	if(isElectron){
	  for(unsigned int itrig=0; itrig < vsSelTriggersEl_MultiLepCalc->size(); itrig++){
	    for(unsigned int jtrig=0; jtrig < eltriggers.size(); jtrig++){
	    	if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(eltriggers.at(jtrig)) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    }
	  }
	}

	if(isMuon){
	  for(unsigned int itrig=0; itrig < vsSelTriggersMu_MultiLepCalc->size(); itrig++){
	    for(unsigned int jtrig=0; jtrig < mutriggers.size(); jtrig++){
	    	if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(mutriggers.at(jtrig)) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTrigger = 1;
	    }
	  }
	}
	MCPastTrigger = 1;
      }
      
      if(isMC && MCPastTrigger) npass_trigger+=1;
      if(!isMC && DataPastTrigger) npass_trigger+=1;

      // ----------------------------------------------------------------------------
      // Generator-level HT correction
      // ----------------------------------------------------------------------------      

      HTSF_Pol = 1;
      HTSF_PolUp = 1;
      HTSF_PolDn = 1;

      if(isMadgraphBkg){
	// Piece-wise splice with a flat line. Uncertainty from upper/lower error bar fits
	HTSF_Pol = poly2->Eval(HTfromHEPUEP_MultiLepCalc);
	HTSF_PolUp = poly2U->Eval(HTfromHEPUEP_MultiLepCalc);
	HTSF_PolDn = poly2D->Eval(HTfromHEPUEP_MultiLepCalc);
      }

      // ----------------------------------------------------------------------------
      // Lepton 4-vectors, calculate MT and electron trigger presel value
      // ----------------------------------------------------------------------------

      // Set lepton 4-vectors
      double lepM;
      double lepphi;
      if (isMuon){ 
	lepM = 0.105658367;
	lepphi = muPhi_MultiLepCalc->at(0);
	lepton_lv.SetPtEtaPhiM(muPt_MultiLepCalc->at(0),muEta_MultiLepCalc->at(0),muPhi_MultiLepCalc->at(0),lepM);
      }
      else{
	lepM = 0.00051099891;
	lepphi = elPhi_MultiLepCalc->at(0);
	lepton_lv.SetPtEtaPhiM(elPt_MultiLepCalc->at(0),elEta_MultiLepCalc->at(0),elPhi_MultiLepCalc->at(0),lepM);
      }      

      MT_lepMet = sqrt(2*leppt*corr_met_MultiLepCalc*(1 - cos(lepphi - corr_met_phi_MultiLepCalc)));

      // ----------------------------------------------------------------------------
      // Loop over AK4 jets for calculations and pt ordering pair
      // ----------------------------------------------------------------------------

      NJets_JetSubCalc = 0;
      AK4HT = 0;
      vector<pair<double,int>> jetptindpair;

      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc->size(); ijet++){
	// ----------------------------------------------------------------------------
	// Basic cuts
	// ----------------------------------------------------------------------------

	if(theJetPt_JetSubCalc->at(ijet) < jetPtCut || fabs(theJetEta_JetSubCalc->at(ijet)) > jetEtaCut) continue;

	// ----------------------------------------------------------------------------
	// Counts and pt ordering pair
	// ----------------------------------------------------------------------------

	jetptindpair.push_back(std::make_pair(theJetPt_JetSubCalc->at(ijet),ijet));
	NJets_JetSubCalc+=1;
	AK4HT+=theJetPt_JetSubCalc->at(ijet);
      }


      // ----------------------------------------------------------------------------
      // Loop over AK8 jets for calculations and pt ordering pair
      // ----------------------------------------------------------------------------

      NJetsAK8_JetSubCalc = 0;
      vector<pair<double,int>> jetak8ptindpair;      
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc->size(); ijet++){
        // ----------------------------------------------------------------------------                                  
        // Basic cuts                                                                                                    
        // ----------------------------------------------------------------------------                                  
	
        if(fabs(theJetAK8Eta_JetSubCalc->at(ijet)) > ak8EtaCut) continue;
        if(theJetAK8Pt_JetSubCalc->at(ijet) < ak8PtCut) continue;
        if(theJetAK8NjettinessTau1_JetSubCalc->at(ijet)==0) continue;
        if(theJetAK8NjettinessTau2_JetSubCalc->at(ijet)==0) continue;

        // ----------------------------------------------------------------------------                                  
        // Counter and pt ordering pair                                                                                  
        // ----------------------------------------------------------------------------                                  
	
        NJetsAK8_JetSubCalc += 1;
        jetak8ptindpair.push_back(std::make_pair(theJetAK8Pt_JetSubCalc->at(ijet),ijet));
	
      }
 
      // ----------------------------------------------------------------------------
      // Apply kinematic cuts
      // ----------------------------------------------------------------------------
	                
      int isPastHTCut = 0;
      if(AK4HT >= htCut){npass_ht+=1;isPastHTCut=1;}
      
      int isPastNAK8JetsCut = 0;
      if(NJetsAK8_JetSubCalc >= nAK8jetsCut){npass_nAK8jets+=1;isPastNAK8JetsCut=1;}

      int isPastMETcut = 0;
      if(corr_met_MultiLepCalc > metCut){npass_met+=1;isPastMETcut=1;}

      int isPastLepPtCut = 0;
      if(leppt > lepPtCut){npass_lepPt+=1;isPastLepPtCut=1;}
      
      int isPastElEtaCut = 0;
      int isPastMuEtaCut = 0;
      if(isElectron && fabs(lepeta) < elEtaCut){npass_ElEta+=1;isPastElEtaCut=1;}
      if(isMuon && fabs(lepeta) < muEtaCut){npass_MuEta+=1;isPastMuEtaCut=1;}
      if(isElectron){Nelectrons+=1;}
      if(isMuon){Nmuons+=1;}
      
      int isPastNjetsCut = 0;
      if(NJets_JetSubCalc >= njetsCut){npass_Njets+=1;isPastNjetsCut=1;}

      // ----------------------------------------------------------------------------
      // Skip failing events
      // ----------------------------------------------------------------------------
            
      if(!(isPastMETcut && isPastHTCut && isPastNAK8JetsCut && isPastNjetsCut && isPastLepPtCut && (isPastElEtaCut || isPastMuEtaCut))) continue;
      npass_all+=1;
      
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /////////////// ONLY ON SELECTED EVENTS ////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////      

      AK4HTpMETpLepPt = AK4HT + corr_met_MultiLepCalc + leppt; //ST
      
      // ----------------------------------------------------------------------------
      // Combine lepton variables into one set
      // ----------------------------------------------------------------------------

      if(isElectron){
	leptonPt_MultiLepCalc = leppt;
	leptonEta_MultiLepCalc = lepeta;
	leptonPhi_MultiLepCalc = elPhi_MultiLepCalc->at(0);
	leptonEnergy_MultiLepCalc = elEnergy_MultiLepCalc->at(0);
	leptonMiniIso_MultiLepCalc = elMiniIso_MultiLepCalc->at(0);
	leptonRelIso_MultiLepCalc = elRelIso_MultiLepCalc->at(0);
	leptonMVAValue_MultiLepCalc = -99.9; //elMVAValue_MultiLepCalc->at(0);
      }
      if(isMuon){
	leptonPt_MultiLepCalc = leppt;
	leptonEta_MultiLepCalc = lepeta;
	leptonPhi_MultiLepCalc = muPhi_MultiLepCalc->at(0);
	leptonEnergy_MultiLepCalc = muEnergy_MultiLepCalc->at(0);
	leptonMiniIso_MultiLepCalc = muMiniIso_MultiLepCalc->at(0);
	leptonRelIso_MultiLepCalc = muRelIso_MultiLepCalc->at(0);
	leptonMVAValue_MultiLepCalc = -99.9;
     }
   
      // ----------------------------------------------------------------------------
      // Apply pt ordering to AK4 vectors
      // ----------------------------------------------------------------------------

      std::sort(jetptindpair.begin(), jetptindpair.end(), comparepair);
      theJetPt_JetSubCalc_PtOrdered.clear();
      theJetEta_JetSubCalc_PtOrdered.clear();
      theJetPhi_JetSubCalc_PtOrdered.clear();
      theJetEnergy_JetSubCalc_PtOrdered.clear();
      theJetDeepCSVb_JetSubCalc_PtOrdered.clear();
      theJetDeepCSVbb_JetSubCalc_PtOrdered.clear();
      theJetDeepCSVc_JetSubCalc_PtOrdered.clear();
      theJetDeepCSVudsg_JetSubCalc_PtOrdered.clear();
      theJetHFlav_JetSubCalc_PtOrdered.clear();
      theJetPFlav_JetSubCalc_PtOrdered.clear();
      theJetBTag_JetSubCalc_PtOrdered.clear();
      theJetBTag_bSFup_JetSubCalc_PtOrdered.clear();
      theJetBTag_bSFdn_JetSubCalc_PtOrdered.clear();
      theJetBTag_lSFup_JetSubCalc_PtOrdered.clear();
      theJetBTag_lSFdn_JetSubCalc_PtOrdered.clear();
      for(unsigned int ijet=0; ijet < jetptindpair.size(); ijet++){
      	theJetPt_JetSubCalc_PtOrdered.push_back(theJetPt_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetEta_JetSubCalc_PtOrdered.push_back(theJetEta_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetPhi_JetSubCalc_PtOrdered.push_back(theJetPhi_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetEnergy_JetSubCalc_PtOrdered.push_back(theJetEnergy_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetDeepCSVb_JetSubCalc_PtOrdered.push_back(theJetDeepCSVb_JetSubCalc->at(jetptindpair[ijet].second));
		theJetDeepCSVbb_JetSubCalc_PtOrdered.push_back(theJetDeepCSVbb_JetSubCalc->at(jetptindpair[ijet].second));
		theJetDeepCSVc_JetSubCalc_PtOrdered.push_back(theJetDeepCSVc_JetSubCalc->at(jetptindpair[ijet].second));
		theJetDeepCSVudsg_JetSubCalc_PtOrdered.push_back(theJetDeepCSVudsg_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetHFlav_JetSubCalc_PtOrdered.push_back(theJetHFlav_JetSubCalc->at(jetptindpair[ijet].second));
      	theJetPFlav_JetSubCalc_PtOrdered.push_back(theJetPFlav_JetSubCalc->at(jetptindpair[ijet].second));
		theJetBTag_JetSubCalc_PtOrdered.push_back(theJetBTag_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_bSFup_JetSubCalc_PtOrdered.push_back(theJetBTag_bSFup_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_bSFdn_JetSubCalc_PtOrdered.push_back(theJetBTag_bSFdn_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_lSFup_JetSubCalc_PtOrdered.push_back(theJetBTag_lSFup_JetSubCalc->at(jetptindpair[ijet].second));
	theJetBTag_lSFdn_JetSubCalc_PtOrdered.push_back(theJetBTag_lSFdn_JetSubCalc->at(jetptindpair[ijet].second));
      }

      // ----------------------------------------------------------------------------
      // AK4 Jet - lepton associations
      // ----------------------------------------------------------------------------
         
      BJetLeadPt = -99;
      BJetLeadPt_bSFup = -99;
      BJetLeadPt_bSFdn = -99;
      BJetLeadPt_lSFup = -99;
      BJetLeadPt_lSFdn = -99;
      minMleppBjet = 1e8;
      minMleppBjet_bSFup = 1e8;
      minMleppBjet_bSFdn = 1e8;
      minMleppBjet_lSFup = 1e8;
      minMleppBjet_lSFdn = 1e8;
      minMleppJet = 1e8;      
      minDPhi_MetJet = 1e8;
      minDR_lepJet = 1e8;
      ptRel_lepJet = -99;
      deltaR_lepJets.clear();
      deltaR_lepBJets.clear();
      deltaR_lepBJets_bSFup.clear();
      deltaR_lepBJets_bSFdn.clear();
      deltaR_lepBJets_lSFup.clear();
      deltaR_lepBJets_lSFdn.clear();
      deltaR_lepMinMlb = 1e8;
      deltaR_lepMinMlb_bSFup = 1e8;
      deltaR_lepMinMlb_bSFdn = 1e8;
      deltaR_lepMinMlb_lSFup = 1e8;
      deltaR_lepMinMlb_lSFdn = 1e8;
      deltaR_lepMinMlj = 1e8;
      NJetsCSV_JetSubCalc = 0;
      NJetsCSVwithSF_JetSubCalc = 0;
      NJetsCSVwithSF_JetSubCalc_bSFup = 0;
      NJetsCSVwithSF_JetSubCalc_bSFdn = 0;
      NJetsCSVwithSF_JetSubCalc_lSFup = 0;
      NJetsCSVwithSF_JetSubCalc_lSFdn = 0;
      TLorentzVector nu;
      nu.SetPtEtaPhiE(corr_met_MultiLepCalc,0,corr_met_phi_MultiLepCalc,corr_met_MultiLepCalc);

      for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
        jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(ijet),theJetEta_JetSubCalc_PtOrdered.at(ijet),theJetPhi_JetSubCalc_PtOrdered.at(ijet),theJetEnergy_JetSubCalc_PtOrdered.at(ijet));
	if((lepton_lv + jet_lv).M() < minMleppJet) {
	  minMleppJet = fabs((lepton_lv + jet_lv).M());
	  deltaR_lepMinMlj = jet_lv.DeltaR(lepton_lv);
	}

	deltaR_lepJets.push_back(lepton_lv.DeltaR(jet_lv));

   	if(theJetDeepCSVb_JetSubCalc_PtOrdered.at(ijet) + theJetDeepCSVbb_JetSubCalc_PtOrdered.at(ijet) > 0.4941){
          NJetsCSV_JetSubCalc += 1;
        }

	if(theJetBTag_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet) {
            minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb = jet_lv.DeltaR(lepton_lv);
          }
	}
	if(theJetBTag_bSFup_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc_bSFup += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt_bSFup) BJetLeadPt_bSFup = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets_bSFup.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet_bSFup) {
            minMleppBjet_bSFup = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb_bSFup = jet_lv.DeltaR(lepton_lv);
          }
	}
	if(theJetBTag_bSFdn_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc_bSFdn += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt_bSFdn) BJetLeadPt_bSFdn = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets_bSFdn.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet_bSFdn) {
            minMleppBjet_bSFdn = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb_bSFdn = jet_lv.DeltaR(lepton_lv);
          }
	}
	if(theJetBTag_lSFup_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc_lSFup += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt_lSFup) BJetLeadPt_lSFup = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets_lSFup.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet_lSFup) {
            minMleppBjet_lSFup = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb_lSFup = jet_lv.DeltaR(lepton_lv);
          }
	}
	if(theJetBTag_lSFdn_JetSubCalc_PtOrdered.at(ijet) == 1){
	  NJetsCSVwithSF_JetSubCalc_lSFdn += 1;
          if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt_lSFdn) BJetLeadPt_lSFdn = theJetPt_JetSubCalc_PtOrdered.at(ijet);
          deltaR_lepBJets_lSFdn.push_back(lepton_lv.DeltaR(jet_lv));
	  
          if((lepton_lv + jet_lv).M() < minMleppBjet_lSFdn) {
            minMleppBjet_lSFdn = fabs( (lepton_lv + jet_lv).M() );
	    deltaR_lepMinMlb_lSFdn = jet_lv.DeltaR(lepton_lv);
          }
	}
	
	if(jet_lv.DeltaPhi(nu) < minDPhi_MetJet) minDPhi_MetJet = jet_lv.DeltaPhi(nu);	  

 	if(deltaR_lepJets[ijet] < minDR_lepJet) {
	  minDR_lepJet = deltaR_lepJets[ijet];
	  ptRel_lepJet = lepton_lv.P()*(jet_lv.Vect().Cross(lepton_lv.Vect()).Mag()/jet_lv.P()/lepton_lv.P());
	}
      }

      // ----------------------------------------------------------------------------
      // 13TeV Top pT reweighting -- TTbarMassCalc top vectors are the wrong tops....
      // ----------------------------------------------------------------------------
      
      genTopPt = -999;
      genAntiTopPt = -999;
      topPtWeight13TeV = 1.0;
      
      if(isTT){
	int top1index = -1;
	int top2index = -1;
	for(unsigned int itop=0; itop < allTopsStatus_TTbarMassCalc->size(); itop++){
	  if(allTopsStatus_TTbarMassCalc->at(itop) != 62) continue;
	  if(top1index < 0){
	    top1index = itop;
	    continue;
	  }
	  if(top2index < 0){
	    top2index = itop;
	    continue;
	  }
	}

	float SFtop1 = TMath::Exp(0.0615-0.0005*allTopsPt_TTbarMassCalc->at(top1index));
	float SFtop2 = TMath::Exp(0.0615-0.0005*allTopsPt_TTbarMassCalc->at(top2index));
	topPtWeight13TeV = TMath::Sqrt(SFtop1*SFtop2);

	if(allTopsID_TTbarMassCalc->at(top1index) == 6){
	  genTopPt = allTopsPt_TTbarMassCalc->at(top1index);
	  genAntiTopPt = allTopsPt_TTbarMassCalc->at(top2index);
	}
	else{
	  genAntiTopPt = allTopsPt_TTbarMassCalc->at(top1index);
	  genTopPt = allTopsPt_TTbarMassCalc->at(top2index);
	}
      }

      // ----------------------------------------------------------------------------
      // Apply pt ordering to AK8 vectors 
      // ----------------------------------------------------------------------------

      //Pt ordering for AK8
      std::sort(jetak8ptindpair.begin(), jetak8ptindpair.end(), comparepair);
      
      maxProb_JetSubCalc_PtOrdered.clear();
      theJetAK8DoubleB_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.clear();
      theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.clear();
      theJetAK8Pt_JetSubCalc_PtOrdered.clear();
      theJetAK8Eta_JetSubCalc_PtOrdered.clear();
      theJetAK8Phi_JetSubCalc_PtOrdered.clear();
      theJetAK8Energy_JetSubCalc_PtOrdered.clear();
      theJetAK8Mass_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered.clear();
      theJetAK8SoftDropRaw_JetSubCalc_PtOrdered.clear();
      theJetAK8SoftDropCorr_JetSubCalc_PtOrdered.clear();
      theJetAK8SoftDrop_JetSubCalc_PtOrdered.clear();
      theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered.clear();
      theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered.clear();
      theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered.clear();
      theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered.clear();
      theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.clear();
      theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.clear();
      theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSTau1_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSTau2_JetSubCalc_PtOrdered.clear();
      theJetAK8CHSTau3_JetSubCalc_PtOrdered.clear();
      theJetAK8Indx_Wtagged.clear();
      for(unsigned int ijet=0; ijet < jetak8ptindpair.size(); ijet++){
      	maxProb_JetSubCalc_PtOrdered.push_back(maxProb_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8DoubleB_JetSubCalc_PtOrdered.push_back(theJetAK8DoubleB_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetIndex_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetSize_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc->at(jetak8ptindpair[ijet].second));
	theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetNDeepCSVL_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Pt_JetSubCalc_PtOrdered.push_back(theJetAK8Pt_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Eta_JetSubCalc_PtOrdered.push_back(theJetAK8Eta_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Phi_JetSubCalc_PtOrdered.push_back(theJetAK8Phi_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Energy_JetSubCalc_PtOrdered.push_back(theJetAK8Energy_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8Mass_JetSubCalc_PtOrdered.push_back(theJetAK8Mass_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropRaw_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDropRaw_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDropCorr_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDropCorr_JetSubCalc->at(jetak8ptindpair[ijet].second));
		theJetAK8SoftDrop_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDrop_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered.push_back(theJetAK8SoftDrop_JMRup_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered.push_back(theJetAK8SoftDrop_JMRdn_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered.push_back(theJetAK8SoftDrop_JMSup_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered.push_back(theJetAK8SoftDrop_JMSdn_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau1_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau2_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau3_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8CHSTau1_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau1_JetSubCalc->at(jetak8ptindpair[ijet].second));      	
	theJetAK8CHSTau2_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau2_JetSubCalc->at(jetak8ptindpair[ijet].second));
      	theJetAK8CHSTau3_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau3_JetSubCalc->at(jetak8ptindpair[ijet].second));
      }
                        
      // ----------------------------------------------------------------------------
      // AK8 Jet - lepton associations, Top and W taggging
      // ----------------------------------------------------------------------------

      NJetsWtagged = 0;
      NJetsTtagged = 0;
      deltaR_lepAK8s.clear();
      minDR_lepAK8 = 1000;
      minDR_leadAK8otherAK8 = 1000;
      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 1) minDR_lepAK8 = -99.0;      
      if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 2) minDR_leadAK8otherAK8 = -99.0;
      WJetLeadPt = -99.0;
      TJetLeadPt = -99.0;

      theJetAK8Wmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8Tmatch_JetSubCalc_PtOrdered.clear();
      theJetAK8MatchedPt_JetSubCalc_PtOrdered.clear();
      theJetAK8Truth_JetSubCalc_PtOrdered.clear();
      NJetsWtagged_shifts.clear();
      NJetsTtagged_shifts.clear();

      wjet1_lv.SetPtEtaPhiM(0,0,0,0);
      tjet1_lv.SetPtEtaPhiM(0,0,0,0);
      ak8_lv.SetPtEtaPhiM(0,0,0,0);
      TLorentzVector leadak8;
      leadak8.SetPtEtaPhiM(0,0,0,0);

      for(int i = 0; i < 8; i++){
	NJetsWtagged_shifts.push_back(0);
	NJetsTtagged_shifts.push_back(0);
      }
      
      for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){

	// ----------------------------------------------------------------------------
	// AK8 - lepton and AK8 -- AK8 associations
	// ----------------------------------------------------------------------------
	
	ak8_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
	if(ijet == 0) leadak8 = ak8_lv;

	deltaR_lepAK8s.push_back(lepton_lv.DeltaR(ak8_lv));
	if(lepton_lv.DeltaR(ak8_lv) < minDR_lepAK8){
	  minDR_lepAK8 = lepton_lv.DeltaR(ak8_lv);
	  ptRel_lepAK8 = lepton_lv.P()*(ak8_lv.Vect().Cross(lepton_lv.Vect()).Mag()/ak8_lv.P()/lepton_lv.P());
	}
	
	if(ijet > 0){
	  float tempdr = leadak8.DeltaR(ak8_lv);
	  if(tempdr < minDR_leadAK8otherAK8){
	    minDR_leadAK8otherAK8 = tempdr;
	  }
	}

	// ----------------------------------------------------------------------------
	// W & top tagging on MC
	// ----------------------------------------------------------------------------
	
	float tau21WP = 0.45; //WP from https://twiki.cern.ch/twiki/bin/viewauth/CMS/JetTopTagging#13_TeV_Working_Points_and_Scale
	float tau32WP = 0.80; //WP5 from https://twiki.cern.ch/twiki/bin/viewauth/CMS/JetTopTagging#13_TeV_Working_Points_and_Scale

	float tau21 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.at(ijet)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.at(ijet);
	float tau32 = theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.at(ijet)/theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.at(ijet);

	float massSD = theJetAK8SoftDropCorr_JetSubCalc_PtOrdered.at(ijet);
	float massSD_JMSup = theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered.at(ijet);
	float massSD_JMSdn = theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered.at(ijet);
	float massSD_JMRup = theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered.at(ijet);
	float massSD_JMRdn = theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered.at(ijet);

	// ------------------------------------------------------------------------------------------------------------------
	// MC Calculation first
	// ------------------------------------------------------------------------------------------------------------------

	if(isMC){
	  
	  // ------------------------------------------------------------------------------------------------------------------
	  // TRUTH MATCHING
	  // ------------------------------------------------------------------------------------------------------------------
	  float minDR = 1000;
	  float matchedPt= -99;
	  int matchedID = 0;
	  bool isWmatched = false;
	  bool isHmatched = false;
	  bool isZmatched = false;
	  bool isTmatched = false;
	  bool isJmatched = false;
	  bool isBmatched = false;
	  TLorentzVector trueW,d1,d2,d3;

	  for(unsigned int iW = 0; iW < HadronicVHtPt_JetSubCalc->size(); iW++){
	    trueW.SetPtEtaPhiE(HadronicVHtPt_JetSubCalc->at(iW),HadronicVHtEta_JetSubCalc->at(iW),HadronicVHtPhi_JetSubCalc->at(iW),HadronicVHtEnergy_JetSubCalc->at(iW));

	    if(ak8_lv.DeltaR(trueW) < minDR){
	      minDR = ak8_lv.DeltaR(trueW);
	      matchedPt = HadronicVHtPt_JetSubCalc->at(iW);
	      matchedID = abs(HadronicVHtID_JetSubCalc->at(iW));	      
	      d1.SetPtEtaPhiE(HadronicVHtD0Pt_JetSubCalc->at(iW),HadronicVHtD0Eta_JetSubCalc->at(iW),HadronicVHtD0Phi_JetSubCalc->at(iW),HadronicVHtD0E_JetSubCalc->at(iW));
	      d2.SetPtEtaPhiE(HadronicVHtD1Pt_JetSubCalc->at(iW),HadronicVHtD1Eta_JetSubCalc->at(iW),HadronicVHtD1Phi_JetSubCalc->at(iW),HadronicVHtD1E_JetSubCalc->at(iW));
	      d3.SetPtEtaPhiE(HadronicVHtD2Pt_JetSubCalc->at(iW),HadronicVHtD2Eta_JetSubCalc->at(iW),HadronicVHtD2Phi_JetSubCalc->at(iW),HadronicVHtD2E_JetSubCalc->at(iW));
	    }
   	  }	 
	  
	  bool WallDsInJet = false;
	  bool TallDsInJet = false;
	  if(matchedID != 6 && ak8_lv.DeltaR(d1) < 0.8 && ak8_lv.DeltaR(d2) < 0.8) WallDsInJet = true;
	  if(matchedID == 6 && ak8_lv.DeltaR(d1) < 0.8 && ak8_lv.DeltaR(d2) < 0.8 && ak8_lv.DeltaR(d3) < 0.8) TallDsInJet = true;
	  if(minDR < 0.8 && matchedID == 24 && WallDsInJet) isWmatched = true;
	  if(minDR < 0.8 && matchedID == 25 && WallDsInJet) isHmatched = true;
	  if(minDR < 0.8 && matchedID == 23 && WallDsInJet) isZmatched = true;
	  if(minDR < 0.8 && matchedID == 6 && TallDsInJet) isTmatched = true;

	  theJetAK8Wmatch_JetSubCalc_PtOrdered.push_back(isWmatched);
	  theJetAK8Hmatch_JetSubCalc_PtOrdered.push_back(isHmatched);
	  theJetAK8Zmatch_JetSubCalc_PtOrdered.push_back(isZmatched);
	  theJetAK8Tmatch_JetSubCalc_PtOrdered.push_back(isTmatched);
	  if(isWmatched || isZmatched || isHmatched || isTmatched) theJetAK8MatchedPt_JetSubCalc_PtOrdered.push_back(matchedPt);
	  else theJetAK8MatchedPt_JetSubCalc_PtOrdered.push_back(-99.0);

	  if (not (isWmatched && matchedPt > 200) && not (isZmatched && matchedPt > 200) && not (isTmatched && matchedPt > 400) && not (isHmatched && matchedPt > 300)) {
	    int firstsub = theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.at(ijet);
	    int nsubs = theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.at(ijet);
	    for(int isub = firstsub; isub < firstsub + nsubs; isub++){
	      if( theJetAK8SDSubjetHFlav_JetSubCalc->at(isub) == 5 ) isBmatched = true;
	    }
	    if ( not isBmatched ) isJmatched = true;
	  }

	  if(isJmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(0);
	  if(isTmatched && matchedPt > 400) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(1);
	  if(isHmatched && matchedPt > 300) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(2);
	  if(isZmatched && matchedPt > 200) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(3);
	  if(isWmatched && matchedPt > 200) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(4);
	  if(isBmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(5);

	  // ------------------------------------------------------------------------------------------------------------------
	  // TOP TAGGING
	  // ------------------------------------------------------------------------------------------------------------------
	  double tau32SF = 1.0;
	  double tau32SFup = 1.0;
	  double tau32SFdn = 1.0;
	  double tau32eff = 1.0;
	  if(isTmatched && matchedPt >= 400){	    
	    hardcodedConditions.GetTtaggingSF(matchedPt, &tau32SF, &tau32SFup, &tau32SFdn, Year);
	    //THESE ARE SET TO 1 SO AS TO NOT APPLY SF WHILE WAITING FOR EFFICIENCIES!!!!
	    //REMOVE THEM WHEN YOU HAVE THE CORRECT EFFICIENCIES!!!!
	    tau32SF = 1.0;
	    tau32SFup = 1.0;
	    tau32SFdn = 1.0;
	    // Use matched T to find the efficiency -- calculated for TpTp and ttbar, EWK/QCD will almost never pass here (use ttbar eff when they do)
		if(isTTTT) {hardcodedConditions.GetTtaggingEff(matchedPt, &tau32eff, Year, "tttt");}
		else if(isXX) {hardcodedConditions.GetTtaggingEff(matchedPt, &tau32eff, Year, "x53x53",SigMass);}		
		else if(isTT) {hardcodedConditions.GetTtaggingEff(matchedPt, &tau32eff, Year, "ttbar");}
		else {hardcodedConditions.GetTtaggingEff(matchedPt, &tau32eff, Year, "singletop");}
	  }
	  
	  // Set the initial tagged/untagged state
	  bool isTtagged = (massSD > 105) && (massSD < 220) && (tau32 < tau32WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
	  bool isTtagged_JMSup = (massSD_JMSup > 105) && (massSD_JMSup < 220) && (tau32 < tau32WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
	  bool isTtagged_JMSdn = (massSD_JMSdn > 105) && (massSD_JMSdn < 220) && (tau32 < tau32WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
	  bool isTtagged_JMRup = (massSD_JMRup > 105) && (massSD_JMRup < 220) && (tau32 < tau32WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
	  bool isTtagged_JMRdn = (massSD_JMRdn > 105) && (massSD_JMRdn < 220) && (tau32 < tau32WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);

	  // IF THE JET IS NOT TRUTH-MATCHED, THESE IFS WILL DO NOTHING, SF == 1
	  int tag_top = applySF(isTtagged,tau32SF,tau32eff);
	  int tag_top_tau32up = applySF(isTtagged,tau32SFup,tau32eff);
	  int tag_top_tau32dn = applySF(isTtagged,tau32SFdn,tau32eff);
	  int tag_top_JMSup = applySF(isTtagged_JMSup,tau32SF,tau32eff);
	  int tag_top_JMSdn = applySF(isTtagged_JMSdn,tau32SF,tau32eff);
	  int tag_top_JMRup = applySF(isTtagged_JMRup,tau32SF,tau32eff);
	  int tag_top_JMRdn = applySF(isTtagged_JMRdn,tau32SF,tau32eff);
 
	  // Now increase the tag count in the right variable	  
	  NJetsTtagged += tag_top;
	  NJetsTtagged_shifts[0] += tag_top_tau32up;
	  NJetsTtagged_shifts[1] += tag_top_tau32dn;
	  NJetsTtagged_shifts[2] += tag_top_JMSup;
	  NJetsTtagged_shifts[3] += tag_top_JMSdn;
	  NJetsTtagged_shifts[4] += tag_top_JMRup;
	  NJetsTtagged_shifts[5] += tag_top_JMRdn;
	  
	  if(tag_top && theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) > TJetLeadPt){ TJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet); }

	  // ------------------------------------------------------------------------------------------------------------------
	  // W TAGGING
	  // ------------------------------------------------------------------------------------------------------------------

	  double tau21SF = 1.0;
	  double tau21SFup = 1.0;
	  double tau21SFdn = 1.0;
	  double tau21ptSFup = 1.0;
	  double tau21ptSFdn = 1.0;
	  double tau21eff = 1.0;
	  if(isWmatched && matchedPt >= 175 && massSD > 65 && massSD < 105 && theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200){	    
	    hardcodedConditions.GetWtaggingSF(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet), &tau21SF, &tau21SFup, &tau21SFdn, &tau21ptSFup, &tau21ptSFdn, Year);
	    //THESE ARE SET TO 1 SO AS TO NOT APPLY SF WHILE WAITING FOR EFFICIENCIES!!!!
	    tau21SF = 1.0;
	    tau21SFup = 1.0;
	    tau21SFdn = 1.0;
	    tau21ptSFup = 1.0;
	    tau21ptSFdn = 1.0;
	    
	    // Use matched W to find the efficiency -- calculated for TpTp and ttbar, EWK/QCD will almost never pass here (use ttbar eff when they do)
		if(isTTTT) {hardcodedConditions.GetTtaggingEff(matchedPt, &tau32eff, Year, "tttt");}
		else if(isXX) {hardcodedConditions.GetTtaggingEff(matchedPt, &tau32eff, Year, "x53x53",SigMass);}		
		else if(isTT) {hardcodedConditions.GetTtaggingEff(matchedPt, &tau32eff, Year, "ttbar");}
		else {hardcodedConditions.GetTtaggingEff(matchedPt, &tau32eff, Year, "singletop");}

	    if(isXX) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "x53x53",SigMass);}
	    else if(isTpTp) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "TpTp",SigMass);}
	    else if(isBpBp) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "BpBp",SigMass);}
	    else if(isTTTT) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "tttt");}
	    else if(isTT) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "ttbar");}
	    else if(isSTt) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "singletopt");}
	    else if(isSTtW) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "singletoptW");}
	    else {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "WV");}
	    }
	  
	  // Set the initial tagged/untagged state
	  bool isWtagged = (massSD > 65) && (massSD < 105) && (tau21 < tau21WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  bool isWtagged_JMSup = (massSD_JMSup > 65) && (massSD_JMSup < 105) && (tau21 < tau21WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  bool isWtagged_JMSdn = (massSD_JMSdn > 65) && (massSD_JMSdn < 105) && (tau21 < tau21WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  bool isWtagged_JMRup = (massSD_JMRup > 65) && (massSD_JMRup < 105) && (tau21 < tau21WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  bool isWtagged_JMRdn = (massSD_JMRdn > 65) && (massSD_JMRdn < 105) && (tau21 < tau21WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  if(isWtagged) { theJetAK8Indx_Wtagged.push_back(ijet); }
 
	  // IF THE JET IS NOT TRUTH-MATCHED, THESE IFS WILL DO NOTHING, SF == 1
	  int tag_W = applySF(isWtagged,tau21SF,tau21eff);
 	  int tag_W_tau21up = applySF(isWtagged,tau21SFup,tau21eff);
	  int tag_W_tau21dn = applySF(isWtagged,tau21SFdn,tau21eff);
	  int tag_W_JMSup = applySF(isWtagged_JMSup,tau21SF,tau21eff);
	  int tag_W_JMSdn = applySF(isWtagged_JMSdn,tau21SF,tau21eff);
	  int tag_W_JMRup = applySF(isWtagged_JMRup,tau21SF,tau21eff);
	  int tag_W_JMRdn = applySF(isWtagged_JMRdn,tau21SF,tau21eff);
 	  int tag_W_tau21ptup = applySF(isWtagged,tau21ptSFup,tau21eff);
	  int tag_W_tau21ptdn = applySF(isWtagged,tau21ptSFdn,tau21eff);
	  
	  // Now increase the tag count in the right variable	  
	  NJetsWtagged += tag_W;
	  NJetsWtagged_shifts[0] += tag_W_tau21up;
	  NJetsWtagged_shifts[1] += tag_W_tau21dn;
	  NJetsWtagged_shifts[2] += tag_W_JMSup;
	  NJetsWtagged_shifts[3] += tag_W_JMSdn;
	  NJetsWtagged_shifts[4] += tag_W_JMRup;
	  NJetsWtagged_shifts[5] += tag_W_JMRdn;
	  NJetsWtagged_shifts[6] += tag_W_tau21ptup;
	  NJetsWtagged_shifts[7] += tag_W_tau21ptdn;

	  if(tag_W && theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) > WJetLeadPt){ WJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet); }
	  	  
	//
	}//end of isMC
	// ------------------------------------------------------------------------------------------------------------------
	// DATA Calculation second
	// ------------------------------------------------------------------------------------------------------------------
	else{
	  theJetAK8Wmatch_JetSubCalc_PtOrdered.push_back(0);
	  theJetAK8Tmatch_JetSubCalc_PtOrdered.push_back(0);
	  
	  bool isWtagged = (massSD > 65)  && (massSD < 105) && (tau21 < tau21WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
	  bool isTtagged = (massSD > 105) && (massSD < 220) && (tau32 < tau32WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
	  
	  NJetsWtagged += isWtagged;
	  NJetsTtagged += isTtagged;
	  
	  if(isWtagged){
	    theJetAK8Indx_Wtagged.push_back(ijet);
	    if(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) > WJetLeadPt) { WJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet); }
	  }
	  else if(isTtagged){
	    if(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) > TJetLeadPt) { TJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet); }
	  }
	}
      }

    // ----------------------------------------------------------------------------
    // HOT TAGGER -- SCALE FACTORS TO BE ADDED!!!
    // ----------------------------------------------------------------------------
     NresolvedTops1pFake = 0;
     NresolvedTops2pFake = 0;
     NresolvedTops5pFake = 0;
     NresolvedTops10pFake = 0;
     NresolvedTops1pFake_shifts.clear();
     NresolvedTops2pFake_shifts.clear();
     NresolvedTops5pFake_shifts.clear();
     NresolvedTops10pFake_shifts.clear();
     for(int i = 0; i < 2; i++){
     	NresolvedTops1pFake_shifts.push_back(0);
     	NresolvedTops2pFake_shifts.push_back(0);
     	NresolvedTops5pFake_shifts.push_back(0);
     	NresolvedTops10pFake_shifts.push_back(0);
     	}
      
     unsigned int idjet1,idjet2,idjet3;
     TLorentzVector resolvedTop,resolvedTopD1,resolvedTopD2,resolvedTopD3;
     TLorentzVector trueTop,trueTopD1,trueTopD2,trueTopD3;
     std::vector<float> minDRtopDs;
     minDRtopDs.clear();
     for(int i = 0; i < 3; i++){ minDRtopDs.push_back(0); }
     for(unsigned int itop=0; itop < topDiscriminator_HOTTaggerCalc->size(); itop++){
        if(isMC){
  
		    // ------------------------------------------------------------------------------------------------------------------
		    // TRUTH MATCHING
		    // ------------------------------------------------------------------------------------------------------------------
		    float minDRtop = 1000;
		    float minDRtopD1 = 1000;
		    float minDRtopD2 = 1000;
		    float minDRtopD3 = 1000;
		    idjet1 = topJet1Index_HOTTaggerCalc->at(itop);
		    idjet2 = topJet2Index_HOTTaggerCalc->at(itop);
		    idjet3 = topJet3Index_HOTTaggerCalc->at(itop);
		    resolvedTop.SetPtEtaPhiM(topPt_HOTTaggerCalc->at(itop),topEta_HOTTaggerCalc->at(itop),topPhi_HOTTaggerCalc->at(itop),topMass_HOTTaggerCalc->at(itop));
	    	resolvedTopD1.SetPtEtaPhiE(theJetPt_JetSubCalc->at(idjet1),theJetEta_JetSubCalc->at(idjet1),theJetPhi_JetSubCalc->at(idjet1),theJetEnergy_JetSubCalc->at(idjet1));
	    	resolvedTopD2.SetPtEtaPhiE(theJetPt_JetSubCalc->at(idjet2),theJetEta_JetSubCalc->at(idjet2),theJetPhi_JetSubCalc->at(idjet2),theJetEnergy_JetSubCalc->at(idjet2));
	    	resolvedTopD3.SetPtEtaPhiE(theJetPt_JetSubCalc->at(idjet3),theJetEta_JetSubCalc->at(idjet3),theJetPhi_JetSubCalc->at(idjet3),theJetEnergy_JetSubCalc->at(idjet3));
            //cout<<"DEBUGGING: "<<topPt_TTbarMassCalc->size()<<" "<<topbPt_TTbarMassCalc->size()<<" "<<topWPt_TTbarMassCalc->size()<<endl;
            for(unsigned int igtop=0; igtop < topPt_TTbarMassCalc->size(); igtop++){
	    	   trueTop.SetPtEtaPhiE(topPt_TTbarMassCalc->at(igtop),topEta_TTbarMassCalc->at(igtop),topPhi_TTbarMassCalc->at(igtop),topEnergy_TTbarMassCalc->at(igtop));
	    	   if(2*igtop>=topWPt_TTbarMassCalc->size()) continue; // DEBUGGING TEMPORARY EDITION
	    	   if(resolvedTop.DeltaR(trueTop) < minDRtop){
	    	     minDRtop = resolvedTop.DeltaR(trueTop);
	    	     trueTopD1.SetPtEtaPhiE(topbPt_TTbarMassCalc->at(igtop),topbEta_TTbarMassCalc->at(igtop),topbPhi_TTbarMassCalc->at(igtop),topbEnergy_TTbarMassCalc->at(igtop));
	    	     trueTopD2.SetPtEtaPhiE(topWPt_TTbarMassCalc->at(2*igtop),topWEta_TTbarMassCalc->at(2*igtop),topWPhi_TTbarMassCalc->at(2*igtop),topWEnergy_TTbarMassCalc->at(2*igtop));
	    	     trueTopD3.SetPtEtaPhiE(topWPt_TTbarMassCalc->at(2*igtop+1),topWEta_TTbarMassCalc->at(2*igtop+1),topWPhi_TTbarMassCalc->at(2*igtop+1),topWEnergy_TTbarMassCalc->at(2*igtop+1));
	    	     
	    	     minDRtopDs[0] = resolvedTopD1.DeltaR(trueTopD1);
	    	     minDRtopDs[1] = resolvedTopD1.DeltaR(trueTopD2);
	    	     minDRtopDs[2] = resolvedTopD1.DeltaR(trueTopD3);
	    	     std::sort(minDRtopDs.begin(), minDRtopDs.end(), comparefloat);
	    	     minDRtopD1 = minDRtopDs.at(0);
	    	     minDRtopDs[0] = resolvedTopD2.DeltaR(trueTopD1);
	    	     minDRtopDs[1] = resolvedTopD2.DeltaR(trueTopD2);
	    	     minDRtopDs[2] = resolvedTopD2.DeltaR(trueTopD3);
	    	     std::sort(minDRtopDs.begin(), minDRtopDs.end(), comparefloat);
	    	     minDRtopD2 = minDRtopDs.at(0);
	    	     minDRtopDs[0] = resolvedTopD3.DeltaR(trueTopD1);
	    	     minDRtopDs[1] = resolvedTopD3.DeltaR(trueTopD2);
	    	     minDRtopDs[2] = resolvedTopD3.DeltaR(trueTopD3);
	    	     std::sort(minDRtopDs.begin(), minDRtopDs.end(), comparefloat);
	    	     minDRtopD3 = minDRtopDs.at(0);
	    	     }
          	   }
          	
          	float TopTagSF1p = 9.92093861103e-01; // for mistagging; apply to those that ARENT truth matched
          	float TopTagSF2p = 9.60411310196e-01; // for mistagging; apply to those that ARENT truth matched
          	float TopTagSF5p = 9.87441658974e-01; // for mistagging; apply to those that ARENT truth matched
          	float TopTagSF10p = 1.00665986538e+00; // for mistagging; apply to those that ARENT truth matched
          	float TopTagSF1pStat = 2.36706994474e-02; // for mistagging; apply to those that ARENT truth matched
          	if(minDRtop < 0.6 && minDRtopD1 < 0.4 && minDRtopD2 < 0.4 && minDRtopD3 < 0.4){
          	  TopTagSF1p = 9.57049369812e-01; // for tagging; apply to those that ARE truth matched
          	  TopTagSF2p = 1.01395213604e+00; // for tagging; apply to those that ARE truth matched
          	  TopTagSF5p = 1.01192998886e+00; // for tagging; apply to those that ARE truth matched
          	  TopTagSF10p = 1.00117206573e+00; // for tagging; apply to those that ARE truth matched
          	  TopTagSF1pStat = 0.0993947964162e-03; // for tagging; apply to those that ARE truth matched
          	  }
          	float TopTagEff1p = 1.; // TO BE CALCULATED !!!!!!!!!!!!
          	float TopTagEff2p = 1.; // TO BE CALCULATED !!!!!!!!!!!!
          	float TopTagEff5p = 1.; // TO BE CALCULATED !!!!!!!!!!!!
          	float TopTagEff10p = 1.; // TO BE CALCULATED !!!!!!!!!!!!
          	bool isTtagged1p = topDiscriminator_HOTTaggerCalc->at(itop) > 0.95;
          	bool isTtagged2p = topDiscriminator_HOTTaggerCalc->at(itop) > 0.92;
          	bool isTtagged5p = topDiscriminator_HOTTaggerCalc->at(itop) > 0.85;
          	bool isTtagged10p = topDiscriminator_HOTTaggerCalc->at(itop) > 0.75;
          	int tag_top_1p = applySF(isTtagged1p,TopTagSF1p,TopTagEff1p);
          	int tag_top_2p = applySF(isTtagged2p,TopTagSF2p,TopTagEff2p);
          	int tag_top_5p = applySF(isTtagged5p,TopTagSF5p,TopTagEff5p);
          	int tag_top_10p = applySF(isTtagged10p,TopTagSF10p,TopTagEff10p);
          	int tag_top_1p_statup = applySF(isTtagged1p,TopTagSF1p+TopTagSF1pStat,TopTagEff1p);
          	int tag_top_1p_statdn = applySF(isTtagged1p,TopTagSF1p-TopTagSF1pStat,TopTagEff1p);
          	NresolvedTops1pFake += tag_top_1p;
          	NresolvedTops2pFake += tag_top_2p;
          	NresolvedTops5pFake += tag_top_5p;
          	NresolvedTops10pFake += tag_top_10p;
          	NresolvedTops1pFake_shifts[0] += tag_top_1p_statup;
          	NresolvedTops1pFake_shifts[1] += tag_top_1p_statdn;
          	}  

        else{ // Data
        	if(topDiscriminator_HOTTaggerCalc->at(itop) > 0.75) NresolvedTops10pFake+=1;
        	if(topDiscriminator_HOTTaggerCalc->at(itop) > 0.85) NresolvedTops5pFake+=1;
        	if(topDiscriminator_HOTTaggerCalc->at(itop) > 0.92) NresolvedTops2pFake+=1;
        	if(topDiscriminator_HOTTaggerCalc->at(itop) > 0.95) NresolvedTops1pFake+=1;
          	}
        }

      // ----------------------------------------------------------------------------
      // PDF and Matrix Element energy scale weights
      // ----------------------------------------------------------------------------

      std::vector<double> renorm;
      std::vector<double> pdf;
      renormWeights.clear();
      renormPSWeights.clear();
      pdfWeights.clear();
      pdfNewWeights.clear();
      pdfNewNominalWeight = 1.0;

      //PSWEIGHTS
      //https://twiki.cern.ch/twiki/bin/viewauth/CMS/TopModGen
      //https://github.com/cms-sw/cmssw/commits/master/Configuration/Generator/python/PSweightsPythia/PythiaPSweightsSettings_cfi.py
      // 2 = isrRedHi isr:muRfac=0.707, 3 = fsrRedHi fsr:muRfac=0.707, 4 = isrRedLo isr:muRfac=1.414, 5 = fsrRedLo fsr:muRfac=1.414, 
      // 6 = isrDefHi isr:muRfac=0.5, 7 = fsrDefHi fsr:muRfac=0.5,  8 = isrDefLo isr:muRfac=2.0,   9 = fsrDefLo fsr:muRfac=2.0, 
      // 10 = isrConHi isr:muRfac=0.25, 11 = fsrConHi fsr:muRfac=0.25, 12 = isrConLo isr:muRfac=4.0, 13 = fsrConLo fsr:muRfac=4.0
      if (evtWeightsMC_MultiLepCalc->size()>=14)
         for(auto & i: {6,7,8,9})
            renormPSWeights.push_back(evtWeightsMC_MultiLepCalc->at(i)/evtWeightsMC_MultiLepCalc->at(0));
      else renormPSWeights={1,1,1,1};

      //ME-PS
      if(isSig && !isTTTT){
	pdfNewNominalWeight = NewPDFweights_MultiLepCalc->at(0);
	// SEEMS TO APPLY TO ALL B2G MG+PYTHIA SIGNALS. NNLO 4-FLAVOR PDF
	for(unsigned int i = 0; i < LHEweightids_MultiLepCalc->size(); i++){
	  if(i > 0 && i < 101) pdfNewWeights.push_back(NewPDFweights_MultiLepCalc->at(i));
	  if(LHEweightids_MultiLepCalc->at(i) > 1 && LHEweightids_MultiLepCalc->at(i) < 10){
	    if(LHEweightids_MultiLepCalc->at(i) == 6 || LHEweightids_MultiLepCalc->at(i) == 8) continue;
	    renormWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) > 474 && LHEweightids_MultiLepCalc->at(i) < 575){
	    pdfWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	}
      }
      else if(isTTTT){
	// 
	for(unsigned int i = 0; i < LHEweightids_MultiLepCalc->size(); i++){
	  if(LHEweightids_MultiLepCalc->at(i) > 1001 && LHEweightids_MultiLepCalc->at(i) < 1010){
	    if(LHEweightids_MultiLepCalc->at(i) == 1006 || LHEweightids_MultiLepCalc->at(i) == 1008) continue;
	    renorm.push_back(LHEweights_MultiLepCalc->at(i));
	    renormWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) > 1009 && LHEweightids_MultiLepCalc->at(i) < 1111){
	    pdf.push_back(LHEweights_MultiLepCalc->at(i));
	    pdfWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) == 1111 || LHEweightids_MultiLepCalc->at(i) == 1112){
	    alphaSWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	}
      }
      else if(isMadgraphBkg){
	// SEEMS TO APPLY TO OTHER MG+PYTHIA BACKGROUNDS. LEADING ORDER 5-FLAVOR PDF
	for(unsigned int i = 0; i < LHEweightids_MultiLepCalc->size(); i++){
	  if(LHEweightids_MultiLepCalc->at(i) > 1 && LHEweightids_MultiLepCalc->at(i) < 10){
	    if(LHEweightids_MultiLepCalc->at(i) == 6 || LHEweightids_MultiLepCalc->at(i) == 8) continue;
	    renorm.push_back(LHEweights_MultiLepCalc->at(i));
	    renormWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) > 10 && LHEweightids_MultiLepCalc->at(i) < 111){
	    pdf.push_back(LHEweights_MultiLepCalc->at(i));
	    pdfWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) == 111 || LHEweightids_MultiLepCalc->at(i) == 112){
	    alphaSWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	}
      }
      else{
	// SEEMS TO APPLY TO ALL POWHEG AND MC@NLO BACKGROUNDS. NLO PDFs
	for(unsigned int i = 0; i < LHEweightids_MultiLepCalc->size(); i++){
	  if(LHEweightids_MultiLepCalc->at(i) > 1001 && LHEweightids_MultiLepCalc->at(i) < 1010){
	    if(LHEweightids_MultiLepCalc->at(i) == 1006 || LHEweightids_MultiLepCalc->at(i) == 1008) continue;
	    renorm.push_back(LHEweights_MultiLepCalc->at(i));
	    renormWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) > 2000 && LHEweightids_MultiLepCalc->at(i) < 2101){
	    pdf.push_back(LHEweights_MultiLepCalc->at(i));
	    pdfWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	  if(LHEweightids_MultiLepCalc->at(i) == 2101 || LHEweightids_MultiLepCalc->at(i) == 2102){
	    alphaSWeights.push_back(LHEweights_MultiLepCalc->at(i));
	  }
	}
      }

      if(renormWeights.size() == 0){
	if(isVV){
	  renormWeights.push_back(0.85);
	  renormWeights.push_back(1.15);
	  renormWeights.push_back(0.85);
	  renormWeights.push_back(0.85);
	  renormWeights.push_back(1.15);
	  renormWeights.push_back(1.15);
	}else{
	  for(int irn = 0; irn < 6; irn++){
	    renormWeights.push_back(1.0);
	  }
	}
      }
      if(pdfWeights.size() == 0){
	for(int ipdf = 0; ipdf < 100; ipdf++){
	  pdfWeights.push_back(1.0);
	}
      }

      // ----------------------------------------------------------------------------
      // DONE!! Write the tree
      // ----------------------------------------------------------------------------
      
      outputTree->Fill();
   }
   std::cout<<"Nelectrons      = "<<Nelectrons<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_ElEta   = "<<npass_ElEta<<" / "<<nentries<<std::endl;
   std::cout<<"Nmuons          = "<<Nmuons<<" / "<<nentries<<std::endl;
   std::cout<<"NrelIsoFail     = "<<NrelIsoFail<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_MuEta   = "<<npass_MuEta<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_nAK8Jets= "<<npass_nAK8jets<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_Trigger = "<<npass_trigger<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_MET     = "<<npass_met<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_lepPt   = "<<npass_lepPt<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_HT      = "<<npass_ht<<" / "<<nentries<<std::endl;
   std::cout<<"npass_Njets     = "<<npass_Njets<<" / "<<nentries<<std::endl;
   std::cout<<"Npassed_ALL     = "<<npass_all<<" / "<<nentries<<std::endl;

   outputTree->Write();
   delete outputTree;
   delete poly2;
   delete poly2U;
   delete poly2D;

}
