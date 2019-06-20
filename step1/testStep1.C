#include "step1.cc"
#include<vector>
using namespace std;

void testStep1(){
  
 //TString inputFile="root://cmsxrootd.fnal.gov//store/user/lpcljm/FWLJMET_crab_TTTT_singlelep_May092019_wenyu/TTToSemiLepton_HT500Njet9_TuneCP5_PSweights_13TeV-powheg-pythia8/crab_FWLJMET_TTTT_May092019_wenyu/190509_182010/0000/TTTT_TuneCP5_PSweights_13TeV-amcatnlo-pythia8_FWLJMET_MC_1.root";
//  TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/FWLJMET102X_1lep2017_052219/TTToSemiLepton_HT500Njet9_TuneCP5_PSweights_13TeV-powheg-pythia8/singleLep2017/190610_195506/0000/TTToSemiLepton_HT500Njet9_TuneCP5_PSweights_13TeV-powheg-pythia8_10.root" ;
  TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/FWLJMET102X_1lep2017_052219/SingleElectron/singleLep2017/190610_165959/0000/SingleElectronRun2017C_1-27.root" ;
  TString outputFile="test.root";
  
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  
  step1 t(inputFile,outputFile);
  
  if ( inputFile.Contains("Run2017") || inputFile.Contains("Run2018") || inputFile.Contains("Single") || inputFile.Contains("Double") || inputFile.Contains("MuonEG") || inputFile.Contains("EGamma") ) 
    { t.Loop("ljmet", "ljmet"); }

  else {
    t.saveHistograms();
    vector<TString> shifts = { "ljmet", "ljmet_JECup", "ljmet_JECdown", "ljmet_JERup", "ljmet_JERdown" };
    for (size_t i =0; i<shifts.size(); ++i) {
      cout << endl << "Running shift " << shifts[i] << endl;
      t.Loop(shifts[i], shifts[i]);
    }
  }
}


