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

    void GetTtaggingSF(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn, int year = 2017);
    void GetTtaggingEff(double pt, double *eff, int year = 2017, std::string sample = "ttbar", int massIndex=-1);
    void GetWtaggingSF(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn, int year = 2017);
    void GetWtaggingEff(double pt, double *eff, int year = 2017, std::string sample = "ttbar", int massIndex=-1);

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

    void GetTtaggingSF2016(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn);
    void GetTtaggingSF2017(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn);
    void GetTtaggingSF2018(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn);
    void GetTtaggingEff2016(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);
    void GetTtaggingEff2017(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);
    void GetTtaggingEff2018(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);

    void GetWtaggingSF2016(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn);
    void GetWtaggingSF2017(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn);
    void GetWtaggingSF2018(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn);
    void GetWtaggingEff2016(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);
    void GetWtaggingEff2017(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);
    void GetWtaggingEff2018(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);
    
};


#endif
