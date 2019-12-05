#include "step1.cc"
#include "HardcodedConditions.cc"
#include<vector>
using namespace std;

void testStep1(){
  TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/FWLJMET102X_1lep2017_Oct2019/TTTT_TuneCP5_PSweights_13TeV-amcatnlo-pythia8/singleLep2017/191029_235508/0000/TTTT_TuneCP5_PSweights_13TeV-amcatnlo-pythia8_59.root";
  //TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/FWLJMET102X_1lep2018_Oct2019/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/singleLep2018/191110_033632/0000/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_99.root";
  TString outputFile="/uscms_data/d3/ssagir/CMSSW_10_2_10/src/LJMet-Slimmer-4tops/step1/test/test.root";
  Int_t Year=2017;
  
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  
  if ( inputFile.Contains("Run2017") || inputFile.Contains("Run2018") || inputFile.Contains("Single") || inputFile.Contains("Double") || inputFile.Contains("MuonEG") || inputFile.Contains("EGamma") ) { 
    step1 t(inputFile,outputFile.ReplaceAll(".root","nominal.root"),Year);
    t.Loop("ljmet", "ljmet"); 
    }

  else {
    vector<TString> shifts = { "nominal" };//, "JECup", "JECdown", "JERup", "JERdown" };
    for (size_t i =0; i<shifts.size(); ++i) {
      cout << endl << "Running shift " << shifts[i] << endl;
      TString tName = "ljmet";
      if ( !shifts[i].Contains("nominal") ) { tName.Append("_"); tName.Append(shifts[i]); }
      step1 t(inputFile,outputFile.ReplaceAll(".root",shifts[i].Append(".root")),Year); //"shifts[i]" is now changed to "shifts[i].root"
      t.saveHistograms();
      t.Loop(tName, "ljmet");
      outputFile.ReplaceAll(shifts[i],".root"); //Change outputFile back to its original name.
      }
    }
}
