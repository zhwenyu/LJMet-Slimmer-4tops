#include "step2.cc"
#include "Davismt2.cc"

using namespace std;

void testStep2(){
  TString inputFile= "/mnt/hadoop/store/group/bruxljm/FWLJMET102X_1lep2017_4t_12022019_step1/nominal/TTTT_TuneCP5_PSweights_13TeV-amcatnlo-pythia8/TTTT_TuneCP5_PSweights_13TeV-amcatnlo-pythia8_3.root"; 
//  TString inputFile="/mnt/hadoop/store/group/bruxljm/FWLJMET102X_1lep2017_Oct2019_4t_120419_step1hadds/nominal//TTTT_TuneCP5_13TeV-amcatnlo-pythia8_hadd.root";
  TString outputFile="step2test.root";

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  step2 t(inputFile,outputFile);
  t.Loop();
}

