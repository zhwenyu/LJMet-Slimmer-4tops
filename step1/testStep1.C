#include "step1.cc"
#include "HardcodedConditions.cc"
#include<vector>
using namespace std;

void testStep1(){
  
  //TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/FWLJMET102X_1lep2017_052219/SingleElectron/singleLep2017/190610_165959/0000/SingleElectronRun2017C_1-27.root" ;
//  TString inputFile="/uscms/home/wzhang/nobackup/work/fwljmet_201905/CMSSW_10_2_10/src/FWLJMET/LJMet/JetHTC_hadtrg.root";
   TString inputFile= "/uscms/home/wzhang/nobackup/work/fwljmet_201905/CMSSW_10_2_16_UL/src/FWLJMET/LJMet/TTToSemileptonic_erdON.root";
  TString outputFile="test1_h20l10.root";
  
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  
  if ( inputFile.Contains("JetHT") || inputFile.Contains("Run2017") || inputFile.Contains("Run2018") || inputFile.Contains("Single") || inputFile.Contains("Double") || inputFile.Contains("MuonEG") || inputFile.Contains("EGamma") ) { 
    step1 t(inputFile,outputFile.ReplaceAll(".root","nominal.root"));
    t.Loop("ljmet", "ljmet"); 
    }

  else {
    vector<TString> shifts = { "nominal", "JECup", "JECdown", "JERup", "JERdown" };
    for (size_t i =0; i<shifts.size(); ++i) {
      cout << endl << "Running shift " << shifts[i] << endl;
      TString tName = "ljmet";
      if ( !shifts[i].Contains("nominal") ) { tName.Append("_"); tName.Append(shifts[i]); }
      step1 t(inputFile,outputFile.ReplaceAll(".root",shifts[i].Append(".root"))); //"shifts[i]" is now changed to "shifts[i].root"
      t.saveHistograms();
      t.Loop(tName, "ljmet");
      outputFile.ReplaceAll(shifts[i],".root"); //Change outputFile back to its original name.
	break;  // only run nominal -wz
      }
    }
}

// void testStep1(){
//   
//   //TString inputFile="root://cmseos.fnal.gov//store/user/lpcljm/FWLJMET102X_1lep2017_052219/SingleElectron/singleLep2017/190610_165959/0000/SingleElectronRun2017C_1-27.root" ;
//   TString inputFile="/uscms_data/d3/ssagir/CMSSW_9_4_13/src/cmsRun_FWLJMET_MC_1Lep.root";
//   TString outputFile="test.root";
//   
//   gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
//   
//   step1 t(inputFile,outputFile);
//   
//   if ( inputFile.Contains("Run2017") || inputFile.Contains("Run2018") || inputFile.Contains("Single") || inputFile.Contains("Double") || inputFile.Contains("MuonEG") || inputFile.Contains("EGamma") ) 
//     { t.Loop("ljmet", "ljmet"); }
// 
//   else {
//     t.saveHistograms();
//     vector<TString> shifts = { "ljmet", "ljmet_JECup", "ljmet_JECdown", "ljmet_JERup", "ljmet_JERdown" };
//     for (size_t i =0; i<shifts.size(); ++i) {
//       cout << endl << "Running shift " << shifts[i] << endl;
//       t.Loop(shifts[i], shifts[i]);
//     }
//   }
// }
