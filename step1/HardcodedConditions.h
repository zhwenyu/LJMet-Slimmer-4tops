// COMMENT
#ifndef HardcodedConditions_h
#define HardcodedConditions_h

#include <iostream>
#include <vector>
#include <algorithm>
 
class HardcodedConditions{
    
public:
    
    HardcodedConditions();
    ~HardcodedConditions();
    
    double GetEGammaGsfSF(double pt, double eta, int year = 2017);
    double GetElectronIdSF(double pt, double eta, int year = 2017);
    double GetElectronIsoSF(double pt, double eta, int year = 2017);
    double GetElectronTriggerSF(double pt, double eta, int year = 2017);
    double GetMuonIdSF(double pt, double eta, int year = 2017);
    double GetMuonIsoSF(double pt, double eta, int year = 2017);
    double GetMuonTriggerSF(double pt, double eta, int year = 2017);

private:
    
    double GetEGammaGsfSF2016(double pt, double eta);
    double GetEGammaGsfSF2017(double pt, double eta);
    double GetEGammaGsfSF2018(double pt, double eta);

    double GetElectronIdSF2016(double pt, double eta);
    double GetElectronIdSF2017(double pt, double eta);
    double GetElectronIdSF2018(double pt, double eta);

    double GetElectronIsoSF2016(double pt, double eta);
    double GetElectronIsoSF2017(double pt, double eta);
    double GetElectronIsoSF2018(double pt, double eta);

    double GetElectronTriggerSF2016(double pt, double eta);
    double GetElectronTriggerSF2017(double pt, double eta);
    double GetElectronTriggerSF2018(double pt, double eta);

    double GetMuonIdSF2016(double pt, double eta);
    double GetMuonIdSF2017(double pt, double eta);
    double GetMuonIdSF2018(double pt, double eta);

    double GetMuonIsoSF2016(double pt, double eta);
    double GetMuonIsoSF2017(double pt, double eta);
    double GetMuonIsoSF2018(double pt, double eta);

    double GetMuonTriggerSF2016(double pt, double eta);
    double GetMuonTriggerSF2017(double pt, double eta);
    double GetMuonTriggerSF2018(double pt, double eta);
    
};


#endif
