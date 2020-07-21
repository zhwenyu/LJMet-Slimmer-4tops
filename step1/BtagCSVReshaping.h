#ifndef CSVReshaping_h
#define CSVReshaping_h

#include "BTagCalibrationStandalone.h"

class CSVReshaping {

public:

  CSVReshaping(int year=2017, TString tagger="DeepCSV");
  ~CSVReshaping();

  double getCSVWeight(double jpt, double jeta, double csv, int jhadflav, TString sys);

private:
  
  void startBTVcalibrationReaders(int year, TString tagger);
  std::map<BTagEntry::JetFlavor, BTagCalibrationReader *> btvCalibReaders_,btvCSVCalibReaders_;

};

#endif
