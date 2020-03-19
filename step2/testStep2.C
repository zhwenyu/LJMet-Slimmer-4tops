#include "step2.cc"
#include "Davismt2.cc"

using namespace std;

void testStep2(){
  TString inputFile=
    "/mnt/hadoop/store/group/bruxljm/FWLJMET102X_1lep2017_Oct2019_4t_031520_step1hadds/nominal/TTTT_TuneCP5_PSweights_13TeV-amcatnlo-pythia8_hadd.root"; 
//   "/mnt/hadoop/store/group/bruxljm/FWLJMET102X_1lep2017_Oct2019_4t_121919_step1hadds/nominal/TTToSemiLepton_HT500Njet9_TuneCP5_PSweights_13TeV-powheg-pythia8_ttjj_hadd.root";
//  TString inputFile="/mnt/hadoop/store/group/bruxljm/FWLJMET102X_1lep2017_Oct2019_4t_121919_step1hadds/nominal/TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_HT0Njet0_ttbb_hadd.root";
  TString outputFile="step2test_4t.root";

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  step2 t(inputFile,outputFile);
  t.Loop();
}

