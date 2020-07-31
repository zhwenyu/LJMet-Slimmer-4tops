#include "BtagCSVReshaping.h"
#include "BTagCalibrationStandalone.h"

CSVReshaping::CSVReshaping(int year, TString tagger) {

  startBTVcalibrationReaders(year, tagger);

}

CSVReshaping::~CSVReshaping() {}

double CSVReshaping::getCSVWeight(double jpt, double jeta, double csv, int jhadflav, TString sys) {

  double csvWgtHF(1.), csvWgtLF(1.), csvWgtC(1.);

  double jptForBtag(jpt>1000. ? 999. : jpt), jetaForBtag(fabs(jeta));

  if (abs(jhadflav)==5) {
        std::string sysHF(sys.Contains("cferr") ? "central" : sys);
        double iCSVWgtHF = btvCSVCalibReaders_[BTagEntry::FLAV_B]->eval_auto_bounds(sysHF,BTagEntry::FLAV_B, jetaForBtag, jptForBtag, csv);      
        if( iCSVWgtHF!=0 ) csvWgtHF *= iCSVWgtHF;                
  }
  else if(abs(jhadflav)==4) {
        std::string sysC(sys.Contains("cferr") ? sys : "central");
        double iCSVWgtC = btvCSVCalibReaders_[BTagEntry::FLAV_C]->eval_auto_bounds(sysC, BTagEntry::FLAV_C, jetaForBtag, jptForBtag, csv);
        if( iCSVWgtC!=0 ) csvWgtC *= iCSVWgtC;	   
  }
  else { //LF
        std::string sysLF(sys.Contains("cferr") ? "central" : sys);       
        double iCSVWgtLF = btvCSVCalibReaders_[BTagEntry::FLAV_UDSG]->eval_auto_bounds(sysLF,BTagEntry::FLAV_UDSG, jetaForBtag, jptForBtag, csv);
        if( iCSVWgtLF!=0 ) csvWgtLF *= iCSVWgtLF;
  } 

  double csvWgt = csvWgtHF * csvWgtC * csvWgtLF;
  return csvWgt;

}

void CSVReshaping::startBTVcalibrationReaders(int year, TString tagger)
{
  //start the btag calibration 
  TString btagUncUrl(""); 
  if ( tagger == "DeepCSV" ) {
    btagUncUrl = "data/era2017/DeepCSV_94XSF_V5_B_F.csv"; 
//    if (year == 2016) {}
//    else if (year == 2018) {}
  }

//  gSystem->ExpandPathName(btagUncUrl);
  BTagCalibration btvcalib("DeepCSV",btagUncUrl.Data());

  //start calibration readers for b,c and udsg separately including the up/down variations
//  btvCalibReaders_[BTagEntry::FLAV_B]=new BTagCalibrationReader(btagOP, "central", {"up", "down"});
//  btvCalibReaders_[BTagEntry::FLAV_B]->load(btvcalib,BTagEntry::FLAV_B,"mujets");
//  btvCalibReaders_[BTagEntry::FLAV_C]=new BTagCalibrationReader(btagOP, "central", {"up", "down"});
//  btvCalibReaders_[BTagEntry::FLAV_C]->load(btvcalib,BTagEntry::FLAV_C,"mujets");
//  btvCalibReaders_[BTagEntry::FLAV_UDSG]=new BTagCalibrationReader(btagOP, "central", {"up", "down"});
//  btvCalibReaders_[BTagEntry::FLAV_UDSG]->load(btvcalib,BTagEntry::FLAV_UDSG,"incl");

  //start calibration readers by CSV re-weighting
  btvCSVCalibReaders_[BTagEntry::FLAV_B]=new BTagCalibrationReader(BTagEntry::OP_RESHAPING, 
                                                                   "central", 
                                                                   {"up_jes","down_jes","up_lf","down_lf","up_hf","down_hf", "up_hfstats1", "down_hfstats1","up_hfstats2","down_hfstats2","up_lfstats1","down_lfstats1","up_lfstats2","down_lfstats2"});
  btvCSVCalibReaders_[BTagEntry::FLAV_B]->load(btvcalib,BTagEntry::FLAV_B,"iterativefit");
  btvCSVCalibReaders_[BTagEntry::FLAV_UDSG]=new BTagCalibrationReader(BTagEntry::OP_RESHAPING, 
                                                                   "central",
                                                                   {"up_jes","down_jes","up_lf","down_lf","up_hf","down_hf", "up_hfstats1", "down_hfstats1","up_hfstats2","down_hfstats2","up_lfstats1","down_lfstats1","up_lfstats2","down_lfstats2"});
  btvCSVCalibReaders_[BTagEntry::FLAV_UDSG]->load(btvcalib,BTagEntry::FLAV_UDSG,"iterativefit");
  btvCSVCalibReaders_[BTagEntry::FLAV_C]=new BTagCalibrationReader(BTagEntry::OP_RESHAPING, "central",{"up_cferr1","down_cferr1","up_cferr2","down_cferr2"});
  btvCSVCalibReaders_[BTagEntry::FLAV_C]->load(btvcalib,BTagEntry::FLAV_C,"iterativefit");
}
