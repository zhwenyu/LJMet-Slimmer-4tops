// -*- C++ -*-
//
// Helper class, provides jet tagging eff, scale factors, etc.
// 
// Inspired from BtagHardcodedConditions in LJMET
// 
// by
//
// Sinan Sagir, November 2019
//

#include <cmath>
#include "HardcodedConditions.h"
#include <unordered_map>

using namespace std;


HardcodedConditions::HardcodedConditions() {
}

HardcodedConditions::~HardcodedConditions() {
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|           T TAGGING SCALE FACTOR SECTION            |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetTtaggingSF(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn, int year)
{
  //The main getter for GetTtaggingSF Scale Factors
  *tau32sf   = 1.000;
  *tau32sfup = 1.000;
  *tau32sfdn = 1.000;
  if      (year==2016) GetTtaggingSF2016(pt, tau32sf, tau32sfup, tau32sfdn);
  else if (year==2017) GetTtaggingSF2017(pt, tau32sf, tau32sfup, tau32sfdn);
  else if (year==2018) GetTtaggingSF2018(pt, tau32sf, tau32sfup, tau32sfdn);
}//end GetTtaggingSF

void HardcodedConditions::GetTtaggingSF2016(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	*tau32sf   = 1.000;
	*tau32sfup = 1.000;
	*tau32sfdn = 1.000;

}

void HardcodedConditions::GetTtaggingSF2017(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn)
{
	// VALUES from the githup repository linked from https://twiki.cern.ch/twiki/bin/viewauth/CMS/JetTopTagging#13_TeV_Working_Points_and_Scale
    const int Nbin = 5;
    double ptMins[Nbin]= {300,400,480,600,1100};
    double SFs[Nbin]   = {0.98331112,0.96821666,0.95967776,1.02111010,1.02111010};
    double SFsUp[Nbin] = {1.02416270,0.99713147,0.99533176,1.06593850,1.11076690};
    double SFsDn[Nbin] = {0.94245958,0.93930185,0.92402375,0.97628158,0.93145317};

    for(int ibin = Nbin-1; ibin >= 0; ibin--){
    	if (pt > ptMins[ibin]){*tau32sf=SFs[ibin];*tau32sfup=SFsUp[ibin];*tau32sfdn=SFsDn[ibin];break;}
    	}
   
}

void HardcodedConditions::GetTtaggingSF2018(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	*tau32sf   = 1.000;
	*tau32sfup = 1.000;
	*tau32sfdn = 1.000;

}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|            T TAGGING EFFICIENCY SECTION             |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetTtaggingEff(double pt, double *eff, int year, std::string sample, int massIndex)
{
  //The main getter for GetTtaggingEff Efficiencies
  *eff = 1.000;
  if      (year==2016) GetTtaggingEff2016(pt, eff, sample, massIndex);
  else if (year==2017) GetTtaggingEff2017(pt, eff, sample, massIndex);
  else if (year==2018) GetTtaggingEff2018(pt, eff, sample, massIndex);
}//end GetTtaggingEff

void HardcodedConditions::GetTtaggingEff2016(double pt, double *eff, std::string sample, int massIndex)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	*eff = 1.000;

}

void HardcodedConditions::GetTtaggingEff2017(double pt, double *eff, std::string sample, int massIndex)
{
    // Top tagging efficiencies updated
    const int Nbin = 9;
    double ptMins[Nbin] = {400,450,500,550,600,700,800,1000,1200};
    double ttbarEff[Nbin] = {0.553, 0.761, 0.812, 0.815, 0.794, 0.762, 0.726, 0.694, 0.672};
    double STEff[Nbin] = {0.546, 0.760, 0.810, 0.820, 0.805, 0.774, 0.742, 0.734, 0.715};
    double ttttEff[Nbin] = {0.515, 0.657, 0.715, 0.724, 0.702, 0.674, 0.685, 0.650, 0.688};
    double x53x53Eff[12][Nbin] = {//X53X53
     {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//700
     {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//800
     {0.513, 0.685, 0.742, 0.743, 0.738, 0.734, 0.715, 0.710, 0.710},//900R
     {0.491, 0.653, 0.714, 0.729, 0.724, 0.718, 0.711, 0.701, 0.678},//1000R
     {0.456, 0.621, 0.683, 0.698, 0.705, 0.697, 0.702, 0.706, 0.707},//1100LR
     {0.443, 0.597, 0.656, 0.676, 0.686, 0.679, 0.685, 0.693, 0.703},//1200LR
     {0.440, 0.594, 0.642, 0.656, 0.659, 0.665, 0.659, 0.666, 0.693},//1300R
     {0.415, 0.567, 0.617, 0.640, 0.646, 0.650, 0.652, 0.657, 0.677},//1400LR
     {0.403, 0.547, 0.593, 0.620, 0.622, 0.632, 0.640, 0.649, 0.661},//1500LR
     {0.413, 0.549, 0.599, 0.599, 0.612, 0.620, 0.623, 0.631, 0.655},//1600R
     {0.396, 0.530, 0.580, 0.591, 0.595, 0.606, 0.618, 0.626, 0.647},//1700LR
     {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//1800
     };

    for(int ibin = Nbin-1; ibin >= 0; ibin--){
    	if (pt > ptMins[ibin]){
    		if (sample=="tttt") {*eff=ttttEff[ibin];}
    		else if (sample=="ttbar") {*eff=ttbarEff[ibin];}
    		else if (sample=="singletop") {*eff=STEff[ibin];}
    		else if (sample=="x53x53") {*eff=x53x53Eff[massIndex][ibin];}
    		else *eff=1.000;
    		break;
    		}
    	}
   
}

void HardcodedConditions::GetTtaggingEff2018(double pt, double *eff, std::string sample, int massIndex)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	*eff = 1.000;

}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|           W TAGGING SCALE FACTOR SECTION            |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetWtaggingSF(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn, int year)
{
  //The main getter for GetWtaggingSF Scale Factors
  *tau21sf   = 1.000;
  *tau21sfup = 1.000;
  *tau21sfdn = 1.000;
  *tau21ptsfup = 1.000;
  *tau21ptsfdn = 1.000;
  if      (year==2016) GetWtaggingSF2016(pt, tau21sf, tau21sfup, tau21sfdn, tau21ptsfup, tau21ptsfdn);
  else if (year==2017) GetWtaggingSF2017(pt, tau21sf, tau21sfup, tau21sfdn, tau21ptsfup, tau21ptsfdn);
  else if (year==2018) GetWtaggingSF2018(pt, tau21sf, tau21sfup, tau21sfdn, tau21ptsfup, tau21ptsfdn);
}//end GetWtaggingSF

void HardcodedConditions::GetWtaggingSF2016(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	*tau21sf   = 1.000;
	*tau21sfup = 1.000;
	*tau21sfdn = 1.000;
	*tau21ptsfup = 1.000;
	*tau21ptsfdn = 1.000;

}

void HardcodedConditions::GetWtaggingSF2017(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn)
{
	// VALUES from https://twiki.cern.ch/twiki/bin/view/CMS/JetWtagging#2017_scale_factors_and_correctio
	*tau21sf = 0.97;
	*tau21sfup = 0.97+0.06;
	*tau21sfdn = 0.97-0.06;
	*tau21ptsfup = 0.97+0.041*log(pt/200);
	*tau21ptsfdn = 0.97-0.041*log(pt/200);
   
}

void HardcodedConditions::GetWtaggingSF2018(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	*tau21sf   = 1.000;
	*tau21sfup = 1.000;
	*tau21sfdn = 1.000;
	*tau21ptsfup = 1.000;
	*tau21ptsfdn = 1.000;

}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|            W TAGGING EFFICIENCY SECTION             |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetWtaggingEff(double pt, double *eff, int year, std::string sample, int massIndex)
{
  //The main getter for GetTtaggingEff Efficiencies
  *eff = 1.000;
  if      (year==2016) GetWtaggingEff2016(pt, eff, sample, massIndex);
  else if (year==2017) GetWtaggingEff2017(pt, eff, sample, massIndex);
  else if (year==2018) GetWtaggingEff2018(pt, eff, sample, massIndex);
}//end GetTtaggingEff

void HardcodedConditions::GetWtaggingEff2016(double pt, double *eff, std::string sample, int massIndex)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	*eff = 1.000;

}

void HardcodedConditions::GetWtaggingEff2017(double pt, double *eff, std::string sample, int massIndex)
{
    // W TAGGING EFFICIENCIES UPDATED
    // W tagging efficiencies. Assumes each signal mass uses the same pT bins but has unique values.
    const int NbinB = 12;
    const int NbinS = 14;
    double ptMinsB[NbinB] = {175,200,250,300,350,400,450,500,550,600,700,800};
    double ptMinsS[NbinS] = {175,200,250,300,350,400,450,500,550,600,700,800,1000,1200};
    double ttbarEff[NbinB]= {0.721, 0.851, 0.860, 0.837, 0.815, 0.793, 0.773, 0.753, 0.735, 0.716, 0.685, 0.657}; // ttbar
    double STtEff[NbinB]  = {0.726, 0.854, 0.863, 0.837, 0.815, 0.783, 0.767, 0.743, 0.722, 0.698, 0.717, 0.583}; // single top (s and t channel had 0 boosted tops)
    double STtWEff[NbinB] = {0.718, 0.857, 0.873, 0.857, 0.847, 0.834, 0.828, 0.821, 0.814, 0.811, 0.805, 0.777}; // single top (s and t channel had 0 boosted tops)
    double WVEff[NbinB]   = {0.744, 0.865, 0.874, 0.853, 0.836, 0.832, 0.818, 0.809, 0.804, 0.784, 0.787, 0.720}; // WW, WZ, etc. 
    double ttttEff[NbinB] = {0.591, 0.768, 0.785, 0.763, 0.728, 0.705, 0.706, 0.622, 0.679, 0.652, 0.509, 0.549}; // tttt

    double x53x53Eff[12][NbinS] = {//X53X53
       {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//700
       {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//800
       {0.731, 0.859, 0.867, 0.855, 0.843, 0.831, 0.822, 0.812, 0.804, 0.796, 0.775, 0.759, 0.718, 0.680},//900R
       {0.730, 0.866, 0.869, 0.856, 0.844, 0.835, 0.825, 0.823, 0.817, 0.804, 0.790, 0.763, 0.733, 0.721},//1000R
       {0.729, 0.868, 0.867, 0.854, 0.843, 0.836, 0.828, 0.820, 0.816, 0.806, 0.792, 0.774, 0.747, 0.710},//1100LR
       {0.752, 0.870, 0.869, 0.854, 0.843, 0.836, 0.828, 0.824, 0.815, 0.810, 0.795, 0.779, 0.758, 0.734},//1200LR
       {0.756, 0.865, 0.871, 0.857, 0.843, 0.825, 0.826, 0.826, 0.820, 0.807, 0.796, 0.773, 0.762, 0.737},//1300R
       {0.765, 0.875, 0.871, 0.858, 0.845, 0.837, 0.827, 0.819, 0.819, 0.812, 0.801, 0.783, 0.761, 0.761},//1400LR
       {0.757, 0.862, 0.862, 0.840, 0.830, 0.823, 0.816, 0.809, 0.807, 0.802, 0.793, 0.774, 0.754, 0.738},//1500LR
       {0.759, 0.876, 0.882, 0.853, 0.845, 0.838, 0.818, 0.821, 0.818, 0.811, 0.800, 0.786, 0.769, 0.758},//1600R
       {0.757, 0.874, 0.873, 0.857, 0.841, 0.839, 0.829, 0.813, 0.812, 0.816, 0.806, 0.792, 0.773, 0.768},//1700LR
       {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//1800

      };     
    double TpTpEff[12][NbinS] = {//TpTp
       {0.710, 0.850, 0.855, 0.834, 0.818, 0.805, 0.799, 0.784, 0.787, 0.775, 0.760, 0.737, 0.724, 0.724},//700 
       {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//800
       {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//900
       {0.710, 0.851, 0.857, 0.837, 0.820, 0.807, 0.802, 0.785, 0.773, 0.770, 0.756, 0.746, 0.719, 0.695},//1000
       {0.705, 0.858, 0.853, 0.831, 0.818, 0.808, 0.798, 0.792, 0.782, 0.770, 0.763, 0.751, 0.729, 0.691},//1100
       {0.732, 0.858, 0.858, 0.837, 0.824, 0.808, 0.794, 0.784, 0.784, 0.775, 0.762, 0.752, 0.731, 0.719},//1200
       {0.727, 0.854, 0.856, 0.835, 0.819, 0.804, 0.798, 0.787, 0.778, 0.777, 0.765, 0.745, 0.727, 0.728},//1300
       {0.715, 0.861, 0.855, 0.831, 0.824, 0.806, 0.794, 0.789, 0.779, 0.776, 0.761, 0.746, 0.726, 0.715},//1400
       {0.694, 0.871, 0.866, 0.834, 0.820, 0.811, 0.794, 0.784, 0.789, 0.779, 0.766, 0.746, 0.727, 0.731},//1500
       {0.796, 0.867, 0.851, 0.841, 0.813, 0.804, 0.802, 0.787, 0.779, 0.777, 0.764, 0.751, 0.733, 0.729},//1600
       {0.672, 0.865, 0.856, 0.843, 0.821, 0.793, 0.788, 0.786, 0.775, 0.779, 0.767, 0.750, 0.737, 0.729},//1700
       {0.807, 0.867, 0.858, 0.839, 0.828, 0.812, 0.788, 0.774, 0.773, 0.770, 0.761, 0.757, 0.735, 0.729},//1800

       };
    double BpBpEff[12][NbinS] = {//BpBp
       {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//700
       {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//800
       {0.696, 0.859, 0.859, 0.843, 0.826, 0.818, 0.802, 0.796, 0.785, 0.777, 0.756, 0.733, 0.691, 0.619},//900 
       {0.706, 0.857, 0.865, 0.848, 0.833, 0.816, 0.809, 0.797, 0.784, 0.780, 0.767, 0.750, 0.700, 0.667},//1000
       {0.725, 0.859, 0.862, 0.850, 0.830, 0.817, 0.808, 0.794, 0.794, 0.784, 0.771, 0.750, 0.711, 0.709},//1100
       {0.751, 0.857, 0.865, 0.846, 0.829, 0.819, 0.806, 0.806, 0.792, 0.783, 0.772, 0.753, 0.737, 0.711},//1200
       {0.738, 0.863, 0.857, 0.846, 0.833, 0.816, 0.804, 0.805, 0.794, 0.786, 0.771, 0.761, 0.740, 0.708},//1300
       {0.738, 0.864, 0.860, 0.839, 0.835, 0.817, 0.811, 0.793, 0.796, 0.792, 0.774, 0.756, 0.737, 0.715},//1400
       {0.762, 0.873, 0.850, 0.844, 0.824, 0.821, 0.805, 0.802, 0.791, 0.786, 0.778, 0.765, 0.743, 0.738},//1500
       {0.795, 0.878, 0.857, 0.834, 0.830, 0.807, 0.811, 0.797, 0.788, 0.786, 0.780, 0.764, 0.745, 0.729},//1600
       {0.791, 0.881, 0.863, 0.850, 0.815, 0.813, 0.791, 0.798, 0.794, 0.785, 0.776, 0.768, 0.749, 0.740},//1700
       {0.795, 0.900, 0.862, 0.843, 0.826, 0.795, 0.800, 0.795, 0.788, 0.784, 0.780, 0.763, 0.754, 0.736},//1800

            };

    if(sample=="x53x53" || sample=="TpTp" || sample=="BpBp"){
    	for(int ibin = NbinS-1; ibin >= 0; ibin--){
    		if(pt > ptMinsS[ibin]){
    			if(sample=="x53x53") {*eff=x53x53Eff[massIndex][ibin];}
    			else if(sample=="TpTp") {*eff=TpTpEff[massIndex][ibin];}
    			else if(sample=="BpBp") {*eff=BpBpEff[massIndex][ibin];}
    			else *eff=1.000;
    			break;
    			}
    		}
    	}
    else{
    	for(int ibin = NbinB-1; ibin >= 0; ibin--){
    		if(pt > ptMinsB[ibin]){
    			if(sample=="tttt") {*eff=ttttEff[ibin];}
    			else if(sample=="ttbar") {*eff=ttbarEff[ibin];}
    			else if(sample=="singletopt") {*eff=STtEff[ibin];}
    			else if(sample=="singletoptW") {*eff=STtWEff[ibin];}
    			else if(sample=="WV") {*eff=WVEff[ibin];}
    			else *eff=1.000;
    			break;
    			}
    		}
    	}
   
}

void HardcodedConditions::GetWtaggingEff2018(double pt, double *eff, std::string sample, int massIndex)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	*eff = 1.000;

}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|           EGammaGsf SCALE FACTOR SECTION            |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetEGammaGsfSF(double pt, double eta, int year)
{
  //The main getter for EGammaGsf Scale Factors
  if      (year==2016) return GetEGammaGsfSF2016(pt, eta);
  else if (year==2017) return GetEGammaGsfSF2017(pt, eta);
  else if (year==2018) return GetEGammaGsfSF2018(pt, eta);
  else return 0.;
}//end GetEGammaGsfSF

double HardcodedConditions::GetEGammaGsfSF2016(double pt, double eta)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	return 1.000;

}

double HardcodedConditions::GetEGammaGsfSF2017(double pt, double eta)
{
	// Gsf Tracking scale factor: http://fcouderc.web.cern.ch/fcouderc/EGamma/scaleFactors/Moriond17/approval/RECO/passingRECO/egammaEffi.txt_egammaPlots.pdf
	if (pt < 45) {
	    if (eta < -2.0) return 0.977;
	    else if (eta < -1.566) return 0.982;
	    else if (eta < -1.442) return 0.948;
	    else if (eta < -1.0) return 0.969;
	    else if (eta < -0.5) return 0.977;
	    else if (eta < 0.5) return 0.970;
	    else if (eta < 1.0) return 0.972;
	    else if (eta < 1.442) return 0.970;
	    else if (eta < 1.566) return 0.958;
	    else return 0.980; }
	else if (pt < 75) {
	    if (eta < -2.0) return 0.984;
	    else if (eta < -1.566) return 0.982;
	    else if (eta < -1.442) return 0.971;
	    else if (eta < -1.0) return 0.976;
	    else if (eta < 0.0) return 0.980;
	    else if (eta < 0.5) return 0.978;
	    else if (eta < 1.0) return 0.979;
	    else if (eta < 1.442) return 0.977;
	    else if (eta < 1.566) return 0.964;
	    else if (eta < 2.0) return 0.983;
	    else return 0.984; }
	else if (pt < 100) {
	    if (eta < -1.566) return 0.997;
	    else if (eta < -1.442) return 1.003;
	    else if (eta < -1.0) return 0.996;
	    else if (eta < 1.0) return 0.992;
	    else if (eta < 1.442) return 0.996;
	    else if (eta < 1.566) return 1.003;
	    else return 0.997; }
	else {
	    if (eta < -1.566) return 0.990;
	    else if (eta < -1.442) return 1.010;
	    else if (eta < -1.0) return 0.985;
	    else if (eta < -0.5) return 0.988;
	    else if (eta < 0.5) return 0.994;
	    else if (eta < 1.0) return 0.988;
	    else if (eta < 1.442) return 0.985;
	    else if (eta < 1.566) return 1.010;
	    else return 0.990; }

}

double HardcodedConditions::GetEGammaGsfSF2018(double pt, double eta)
{
	// Gsf Tracking scale factor: https://twiki.cern.ch/twiki/pub/CMS/EgammaIDRecipesRun2/egammaEffi.txt_egammaPlots.pdf
	if (pt < 45) {
	    if (eta < -2.0) return 0.989;
	    else if (eta < -1.566) return 0.991;
	    else if (eta < -1.442) return 0.982;
	    else if (eta < -1.0) return 0.988;
	    else if (eta < -0.5) return 0.990;
        else if (eta < 0.0) return 0.986;
	    else if (eta < 0.5) return 0.983;
	    else if (eta < 1.0) return 0.987;
	    else if (eta < 1.442) return 0.984;
	    else if (eta < 1.556) return 0.985;
	    else if (eta < 2.0) return 0.989;
	    else return 0.992; }
	else if (pt < 75) {
	    if (eta < -2.0) return 0.985;
	    else if (eta < -1.556) return 0.991;
	    else if (eta < -1.442) return 0.959;
	    else if (eta < -1.0) return 0.989;
        else if (eta < -0.5) return 0.991;
	    else if (eta < 0.0) return 0.989;
	    else if (eta < 0.5) return 0.987;
	    else if (eta < 1.0) return 0.989;
	    else if (eta < 1.442) return 0.982;
	    else if (eta < 1.566) return 0.973;
	    else if (eta < 2.0) return 0.991;
	    else return 0.986; }
	else if (pt < 100) {
        if (eta < -2.0) return 1.001;
	    else if (eta < -1.566) return 1.006;
	    else if (eta < -1.442) return 1.047;
	    else if (eta < -1.0) return 1.005;
        else if (eta < -0.5) return 1.002;
        else if (eta < 0.0) return 1.006;
        else if (eta < 0.5) return 1.006;
	    else if (eta < 1.0) return 1.002;
	    else if (eta < 1.442) return 1.005;
	    else if (eta < 1.566) return 1.047;
        else if (eta < 2.0) return 1.006;
	    else return 1.001; }
	else {
        if (eta < -2.0) return 1.007;
	    else if (eta < -1.566) return 0.992;
	    else if (eta < -1.442) return 0.984;
	    else if (eta < -1.0) return 1.001;
	    else if (eta < -0.5) return 1.001;
        else if (eta < 0.0) return 0.987;
	    else if (eta < 0.5) return 0.987;
	    else if (eta < 1.0) return 1.001;
	    else if (eta < 1.442) return 1.001;
	    else if (eta < 1.566) return 0.984;
	    else if (eta < 2.0) return 0.992;
	    else return 1.007; }
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|          ELECTRON ID SCALE FACTOR SECTION           |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetElectronIdSF(double pt, double eta, int year)
{
  //The main getter for Electron Id Scale Factors
  if      (year==2016) return GetElectronIdSF2016(pt, eta);
  else if (year==2017) return GetElectronIdSF2017(pt, eta);
  else if (year==2018) return GetElectronIdSF2018(pt, eta);
  else return 0.;
}//end GetElectronIdSF

double HardcodedConditions::GetElectronIdSF2016(double pt, double eta)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	return 1.000;

}

double HardcodedConditions::GetElectronIdSF2017(double pt, double eta)
{
	//Scale Factor 2: https://twiki.cern.ch/twiki/pub/CMS/EgammaIDRecipesRun2/2017_ElectronMVA90noiso_2D.pdf
	if (pt < 20) {
	    if (eta < -2.0) return 0.943;
	    else if (eta < -1.566) return 0.957;
	    else if (eta < -1.442) return 1.000;
	    else if (eta < -0.8) return 1.008;
	    else if (eta < 0.0) return 0.993;
	    else if (eta < 0.8) return 0.992;
	    else if (eta < 1.442) return 0.999;
	    else if (eta < 1.566) return 1.000;
	    else if (eta < 2.0) return 0.978;
	    else return 0.930; }
	else if (pt < 35) {
	    if (eta < -2.0) return 0.926;
	    else if (eta < -1.566) return 0.937;
	    else if (eta < -1.442) return 1.000;
	    else if (eta < -0.8) return 0.964;
	    else if (eta < 0.0) return 0.981;
	    else if (eta < 0.8) return 0.981;
	    else if (eta < 1.442) return 0.963;
	    else if (eta < 1.566) return 1.000;
	    else if (eta < 2.0) return 0.943;
	    else return 0.918; }
	else if (pt < 50) {
	    if (eta < -2.0) return 0.941;
	    else if (eta < -1.566) return 0.953;
	    else if (eta < -1.442) return 1.000;
	    else if (eta < -0.8) return 0.962;
	    else if (eta < 0.0) return 0.972;
	    else if (eta < 0.8) return 0.974;
	    else if (eta < 1.442) return 0.965;
	    else if (eta < 1.566) return 1.000;
	    else if (eta < 2.0) return 0.955;
	    else return 0.933; }
	else if (pt < 100) {
	    if (eta < -2.0) return 0.948;
	    else if (eta < -1.566) return 0.967;
	    else if (eta < -1.442) return 1.000;
	    else if (eta < -0.8) return 0.968;
	    else if (eta < 0.0) return 0.979;
	    else if (eta < 0.8) return 0.975;
	    else if (eta < 1.442) return 0.970;
	    else if (eta < 1.566) return 1.000;
	    else if (eta < 2.0) return 0.971;
	    else return 0.938; }
	else if (pt < 200) {
	    if (eta < -2.0) return 0.983;
	    else if (eta < -1.566) return 0.969;
	    else if (eta < -1.442) return 1.000;
	    else if (eta < -0.8) return 0.979;
	    else if (eta < 0.0) return 0.983;
	    else if (eta < 0.8) return 0.988;
	    else if (eta < 1.442) return 0.993;
	    else if (eta < 1.566) return 1.000;
	    else if (eta < 2.0) return 0.990;
	    else return 0.939; }
	else {
	    if (eta < -2.0) return 0.922;
	    else if (eta < -1.566) return 0.985;
	    else if (eta < -1.442) return 1.000;
	    else if (eta < -0.8) return 1.007;
	    else if (eta < 0.0) return 0.993;
	    else if (eta < 0.8) return 0.959;
	    else if (eta < 1.442) return 1.013;
	    else if (eta < 1.566) return 1.000;
	    else if (eta < 2.0) return 0.949;
	    else return 1.057; }

}

double HardcodedConditions::GetElectronIdSF2018(double pt, double eta)
{
    //Scale factor 2: https://twiki.cern.ch/twiki/pub/CMS/EgammaIDRecipesRun2/2018_ElectronMVA90noiso_2D.pdf 
	if (pt < 20) {
	    if (eta < -2.0) return 1.000;
	    else if (eta < -1.566) return 0.973;
	    else if (eta < -1.442) return 1.000;
	    else if (eta < -0.8) return 1.016;
	    else if (eta < 0.0) return 0.958;
	    else if (eta < 0.8) return 0.990;
	    else if (eta < 1.442) return 1.012;
	    else if (eta < 1.566) return 1.000;
	    else if (eta < 2.0) return 0.978;
	    else return 0.995; }
	else if (pt < 35) {
	    if (eta < -2.0) return 0.973;
	    else if (eta < -1.566) return 0.951;
	    else if (eta < -1.442) return 1.000;
	    else if (eta < -0.8) return 0.965;
	    else if (eta < 0.0) return 0.970;
	    else if (eta < 0.8) return 0.973;
	    else if (eta < 1.442) return 0.965;
	    else if (eta < 1.566) return 1.000;
	    else if (eta < 2.0) return 0.948;
	    else return 0.963; }
	else if (pt < 50) {
	    if (eta < -2.0) return 0.975;
	    else if (eta < -1.566) return 0.966;
	    else if (eta < -1.442) return 1.000;
	    else if (eta < -0.8) return 0.972;
	    else if (eta < 0.0) return 0.977;
	    else if (eta < 0.8) return 0.977;
	    else if (eta < 1.442) return 0.972;
	    else if (eta < 1.566) return 1.000;
	    else if (eta < 2.0) return 0.963;
	    else return 0.968; }
	else if (pt < 100) {
	    if (eta < -2.0) return 0.978;
	    else if (eta < -1.566) return 0.978;
	    else if (eta < -1.442) return 1.000;
	    else if (eta < -0.8) return 0.974;
	    else if (eta < 0.0) return 0.978;
	    else if (eta < 0.8) return 0.982;
	    else if (eta < 1.442) return 0.976;
	    else if (eta < 1.566) return 1.000;
	    else if (eta < 2.0) return 0.976;
	    else return 0.953; }
	else if (pt < 200) {
	    if (eta < -2.0) return 0.974;
	    else if (eta < -1.566) return 0.997;
	    else if (eta < -1.442) return 1.000;
	    else if (eta < -0.8) return 0.981;
	    else if (eta < 0.0) return 0.980;
	    else if (eta < 0.8) return 0.991;
	    else if (eta < 1.442) return 0.987;
	    else if (eta < 1.566) return 1.000;
	    else if (eta < 2.0) return 0.962;
	    else return 0.956; }
	else {
	    if (eta < -2.0) return 1.071;
	    else if (eta < -1.566) return 1.046;
	    else if (eta < -1.442) return 1.000;
	    else if (eta < -0.8) return 0.979;
	    else if (eta < 0.0) return 0.999;
	    else if (eta < 0.8) return 0.960;
	    else if (eta < 1.442) return 0.979;
	    else if (eta < 1.566) return 1.000;
	    else if (eta < 2.0) return 0.912;
	    else return 0.885; }

}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|          ELECTRON ISO SCALE FACTOR SECTION          |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetElectronIsoSF(double pt, double eta, int year)
{
  //The main getter for Electron Iso Scale Factors
  if      (year==2016) return GetElectronIsoSF2016(pt, eta);
  else if (year==2017) return GetElectronIsoSF2017(pt, eta);
  else if (year==2018) return GetElectronIsoSF2018(pt, eta);
  else return 0.;
}//end GetElectronIsoSF

double HardcodedConditions::GetElectronIsoSF2016(double pt, double eta)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	return 1.000;

}

double HardcodedConditions::GetElectronIsoSF2017(double pt, double eta)
{
	// mini isolation scale factors: https://wiwong.web.cern.ch/wiwong/Ele_Eff_Plots/2017passingMiniIsoTight/
	if (pt < 50){
            if (fabs(eta) < 0.8) return 0.997;
            else if (fabs(eta) < 1.442) return 0.999;
            else if (fabs(eta) < 1.566) return 1.009;
            else if (fabs(eta) < 2) return 0.998;
            else return 0.997;}
	else if (pt < 60){
            if (fabs(eta) < 0.8) return 0.998;
            else if (fabs(eta) < 1.442) return 0.999;
            else if (fabs(eta) < 1.566) return 1.022;
            else if (fabs(eta) < 2) return 0.999;
            else return 1.000;}
	else if (pt < 100){
            if (fabs(eta) < 0.8) return 0.998;
            else if (fabs(eta) < 1.442) return 1.001;
            else if (fabs(eta) < 1.566) return 1.024;
            else if (fabs(eta) < 2) return 1.001;
            else return 1.001;}
	else if (pt < 200){
            if (fabs(eta) < 0.8) return 0.999;
            else if (fabs(eta) < 1.442) return 1.001;
            else if (fabs(eta) < 1.566) return 1.021;
            else if (fabs(eta) < 2) return 1.003;
            else return 1.000;}
	else{
            if (fabs(eta) < 0.8) return 1.000;
            else if (fabs(eta) < 1.442) return 1.001;
            else if (fabs(eta) < 1.566) return 1.008;
            else if (fabs(eta) < 2) return 1.000;
            else return 0.999;}
            
}

double HardcodedConditions::GetElectronIsoSF2018(double pt, double eta)
{
	// mini isolation scale factors: https://wiwong.web.cern.ch/wiwong/Ele_Eff_Plots/2018passingMiniIsoTight_updated/egammaEffi.txt_egammaPlots.pdf
	if (pt < 20){
            if (fabs(eta) < -2.0) return 1.039;
            else if (fabs(eta) < -1.566) return 1.026;
            else if (fabs(eta) < -1.442) return 1.115;
            else if (fabs(eta) < -0.8) return 0.998;
            else if (fabs(eta) < 0.0) return 0.996;
            else if (fabs(eta) < 0.8) return 0.996;
            else if (fabs(eta) < 1.442) return 0.998;
            else if (fabs(eta) < 1.566) return 1.115;
            else if (fabs(eta) < 2.0) return 1.026;
            else return 1.039;}
    else if (pt < 40){
            if (fabs(eta) < -2.0) return 1.019;
            else if (fabs(eta) < -1.566) return 1.011;
            else if (fabs(eta) < -1.442) return 1.045;
            else if (fabs(eta) < -0.8) return 1.000;
            else if (fabs(eta) < 0.0) return 0.997;
            else if (fabs(eta) < 0.8) return 0.997;
            else if (fabs(eta) < 1.442) return 1.000;
            else if (fabs(eta) < 1.566) return 1.045;
            else if (fabs(eta) < 2.0) return 1.011;
            else return 1.019;}
    else if (pt < 50){
            if (fabs(eta) < -2.0) return 1.010;
            else if (fabs(eta) < -1.566) return 1.006;
            else if (fabs(eta) < -1.442) return 1.024;
            else if (fabs(eta) < -0.8) return 0.998;
            else if (fabs(eta) < 0.0) return 0.998;
            else if (fabs(eta) < 0.8) return 0.998;
            else if (fabs(eta) < 1.442) return 0.998;
            else if (fabs(eta) < 1.566) return 1.024;
            else if (fabs(eta) < 2.0) return 1.006;
            else return 1.010;}
    else if (pt < 60){
            if (fabs(eta) < -2.0) return 1.008;
            else if (fabs(eta) < -1.566) return 1.003;
            else if (fabs(eta) < -1.442) return 1.035;
            else if (fabs(eta) < -0.8) return 0.999;
            else if (fabs(eta) < 0.0) return 0.999;
            else if (fabs(eta) < 0.8) return 0.999;
            else if (fabs(eta) < 1.442) return 0.999;
            else if (fabs(eta) < 1.566) return 1.035;
            else if (fabs(eta) < 2.0) return 1.003;
            else return 1.008;}
    else if (pt < 100){
            if (fabs(eta) < -2.0) return 1.001;
            else if (fabs(eta) < -1.566) return 1.000;
            else if (fabs(eta) < -1.442) return 1.032;
            else if (fabs(eta) < -0.8) return 1.000;
            else if (fabs(eta) < 0.0) return 1.000;
            else if (fabs(eta) < 0.8) return 1.000;
            else if (fabs(eta) < 1.442) return 1.000;
            else if (fabs(eta) < 1.566) return 1.032;
            else if (fabs(eta) < 2.0) return 1.000;
            else return 1.001;}
    else if (pt < 200){
            if (fabs(eta) < -2.0) return 1.003;
            else if (fabs(eta) < -1.566) return 1.001;
            else if (fabs(eta) < -1.442) return 1.018;
            else if (fabs(eta) < -0.8) return 1.002;
            else if (fabs(eta) < 0.0) return 1.001;
            else if (fabs(eta) < 0.8) return 1.001;
            else if (fabs(eta) < 1.442) return 1.002;
            else if (fabs(eta) < 1.566) return 1.018;
            else if (fabs(eta) < 2.0) return 1.001;
            else return 1.003;}
    else{
            if (fabs(eta) < -2.0) return 1.003;
            else if (fabs(eta) < -1.566) return 1.001;
            else if (fabs(eta) < -1.442) return 0.999;
            else if (fabs(eta) < -0.8) return 0.999;
            else if (fabs(eta) < 0.0) return 1.000;
            else if (fabs(eta) < 0.8) return 1.000;
            else if (fabs(eta) < 1.442) return 0.999;
            else if (fabs(eta) < 1.566) return 0.999;
            else if (fabs(eta) < 2) return 1.001;
            else return 1.003;}

}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|        ELECTRON TRIGGER SCALE FACTOR SECTION        |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetElectronTriggerSF(double pt, double eta, int year)
{
  //The main getter for Electron Trigger Scale Factors
  if      (year==2016) return GetElectronTriggerSF2016(pt, eta);
  else if (year==2017) return GetElectronTriggerSF2017(pt, eta);
  else if (year==2018) return GetElectronTriggerSF2018(pt, eta);
  else return 0.;
}//end GetElectronTriggerSF

double HardcodedConditions::GetElectronTriggerSF2016(double pt, double eta)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	return 1.000;

}

double HardcodedConditions::GetElectronTriggerSF2017(double pt, double eta)
{
	// Trigger Scale Factors, SF2017B_Bkg_LepPtEta_EOR.png & SF2017CDEF_Bkg_LepPtEta_EOR.png
	float triggerSFB = 1.0;
	float triggerSFCDEF = 1.0;
	if (fabs(eta) < 0.8){
	    if (pt < 50) {triggerSFB = 1.0; triggerSFCDEF = 1.0;}
	    else if (pt < 55) {triggerSFB = 0.800; triggerSFCDEF = 1.009;}
	    else if (pt < 60) {triggerSFB = 0.797; triggerSFCDEF = 1.000;}
	    else if (pt < 70) {triggerSFB = 0.796; triggerSFCDEF = 1.003;}
	    else if (pt < 100) {triggerSFB = 0.795; triggerSFCDEF = 1.016;}
	    else if (pt < 200) {triggerSFB = 0.780; triggerSFCDEF = 1.006;}
	    else {triggerSFB = 0.785; triggerSFCDEF = 0.988;}
	}else if (fabs(eta) < 1.442){
        if (pt < 50) {triggerSFB = 1.0; triggerSFCDEF = 1.0;}
        else if (pt < 55) {triggerSFB = 0.824; triggerSFCDEF = 1.007;}
        else if (pt < 60) {triggerSFB = 0.795; triggerSFCDEF = 1.024;}
        else if (pt < 70) {triggerSFB = 0.727; triggerSFCDEF = 1.015;}
        else if (pt < 100) {triggerSFB = 0.764; triggerSFCDEF = 0.991;}
        else if (pt < 200) {triggerSFB = 0.783; triggerSFCDEF = 0.999;}
        else {triggerSFB = 0.756; triggerSFCDEF = 0.962;}
	}else if (fabs(eta) < 1.566) {triggerSFB = 1.0; triggerSFCDEF = 1.0;}
	else if (fabs(eta) < 2.0){
        if (pt < 50) {triggerSFB = 1.0; triggerSFCDEF = 1.0;}
        else if (pt < 55) {triggerSFB = 0.764; triggerSFCDEF = 0.952;}
        else if (pt < 60) {triggerSFB = 0.685; triggerSFCDEF = 0.984;}
        else if (pt < 70) {triggerSFB = 0.764; triggerSFCDEF = 0.972;}
        else if (pt < 100) {triggerSFB = 0.780; triggerSFCDEF = 0.940;}
        else if (pt < 200) {triggerSFB = 0.693; triggerSFCDEF = 0.938;}
        else {triggerSFB = 0.562; triggerSFCDEF = 0.726;}
	}else {
        if (pt < 50) {triggerSFB = 1.0; triggerSFCDEF = 1.0;}
        else if (pt < 55) {triggerSFB = 0.713; triggerSFCDEF = 1.022;}
        else if (pt < 60) {triggerSFB = 0.773; triggerSFCDEF = 1.027;}
        else if (pt < 70) {triggerSFB = 0.670; triggerSFCDEF = 1.031;}
        else if (pt < 100) {triggerSFB = 0.868; triggerSFCDEF = 1.088;}
        else if (pt < 200) {triggerSFB = 0.828; triggerSFCDEF = 1.041;}
        else {triggerSFB = 0.562; triggerSFCDEF = 0.814;}
	}
	return (4.823*triggerSFB + 36.734*triggerSFCDEF)/41.557;

}

double HardcodedConditions::GetElectronTriggerSF2018(double pt, double eta)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	return 1.000;

}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|            MUON ID SCALE FACTOR SECTION             |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetMuonIdSF(double pt, double eta, int year)
{
  //The main getter for Muon Id Scale Factors
  if      (year==2016) return GetMuonIdSF2016(pt, eta);
  else if (year==2017) return GetMuonIdSF2017(pt, eta);
  else if (year==2018) return GetMuonIdSF2018(pt, eta);
  else return 0.;
}//end GetMuonIdSF

double HardcodedConditions::GetMuonIdSF2016(double pt, double eta)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	return 1.000;

}

double HardcodedConditions::GetMuonIdSF2017(double pt, double eta)
{
	// Cut based tight id
	// Scale Factor 3: https://twiki.cern.ch/twiki/pub/CMS/MuonReferenceEffs2017/RunBCDEF_SF_ID.json
	if (fabs(eta) < 0.90) {
	    if (pt < 25.0) return 0.9910777627756951;
	    else if (pt < 30.0) return 0.987410468262084;
	    else if (pt < 40.0) return 0.9907753279135898;
	    else if (pt < 50.0) return 0.9892483588952047;
	    else if (pt < 60.0) return 0.9855545160334763;
	    else return 0.9898057377093389; }
	else if (fabs(eta) < 1.20) {
	    if (pt < 25.0) return 0.9927389275515244;
	    else if (pt < 30.0) return 0.985063939762512;
	    else if (pt < 40.0) return 0.9865359464182247;
	    else if (pt < 50.0) return 0.984913093101493;
	    else if (pt < 60.0) return 0.9839056384760008;
	    else return 0.984060403143468; }  
	else if (fabs(eta) < 2.10) {
	    if (pt < 25.0) return 0.9924252719877384;
	    else if (pt < 30.0) return 0.9890884461284933;
	    else if (pt < 40.0) return 0.9946469069883841;
	    else if (pt < 50.0) return 0.9926528825155183;
	    else if (pt < 60.0) return 0.9906364222943529;
	    else return 0.9920464322143979; }
	else {
	    if (pt < 25.0) return 0.9758095839531763;
	    else if (pt < 30.0) return 0.9745153594179884;
	    else if (pt < 40.0) return 0.9787410500158746;
	    else if (pt < 50.0) return 0.978189122919501;
	    else if (pt < 60.0) return 0.9673568416097894;
	    else return 0.9766311856731202; }

}

double HardcodedConditions::GetMuonIdSF2018(double pt, double eta)
{
    //cut based tight id: https://gitlab.cern.ch/cms-muonPOG/MuonReferenceEfficiencies/blob/master/EfficienciesStudies/2018/jsonfiles/RunABCD_SF_ID.json
	if (fabs(eta) > 0.00 && fabs(eta) < 0.90) {
	    if (pt >20.00 && pt < 25.00) return 0.9913892461286353;
        else if (pt > 25.00 && pt < 30.00) return 0.991434774563006;
        else if (pt > 30.00 && pt < 40.00) return 0.99137555469275;
        else if (pt > 40.00 && pt < 50.00) return 0.9914412620030336;
        else if (pt > 50.00 && pt < 60.00) return 0.9916861853024751;
        else {return 0.9905799448514033;}  
        }
    else if (fabs(eta) > 0.90 && fabs(eta) < 1.20) {
        if (pt >20.00 && pt < 25.00) return 0.985987369423937;
        else if (pt > 25.00 && pt < 30.00) return 0.983987818122965;
        else if (pt > 30.00 && pt < 40.00) return 0.983823809537526;
        else if (pt > 40.00 && pt < 50.00) return 0.9842166496308641;
        else if (pt > 50.00 && pt < 60.00) return 0.9830003119378048;
        else {return 0.9816888807775153;}
        }
    else if (fabs(eta) > 1.20 && fabs(eta) < 2.10) {
        if (pt >20.00 && pt < 25.00) return 0.991472765372932;
        else if (pt > 25.00 && pt < 30.00) return 0.991184702552688;
        else if (pt > 30.00 && pt < 40.00) return 0.9907979966866818;
        else if (pt > 40.00 && pt < 50.00) return 0.98999331286624;
        else if (pt > 50.00 && pt < 60.00) return 0.9907796746368196;
        else {return 0.9886366722532979;}
        }
    else{
        if (pt >20.00 && pt < 25.00) return 0.9762336613870103;
        else if (pt > 25.00 && pt < 30.00) return 0.9735941110201962;
        else if (pt > 30.00 && pt < 40.00) return 0.973964994647057;
        else if (pt > 40.00 && pt < 50.00) return 0.9738877279555861;
        else if (pt > 50.00 && pt < 60.00) return 0.9737076412350453;
        else {return 0.9677501192438909;}
        }
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|            MUON ISO SCALE FACTOR SECTION            |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetMuonIsoSF(double pt, double eta, int year)
{
  //The main getter for Muon Iso Scale Factors
  if      (year==2016) return GetMuonIsoSF2016(pt, eta);
  else if (year==2017) return GetMuonIsoSF2017(pt, eta);
  else if (year==2018) return GetMuonIsoSF2018(pt, eta);
  else return 0.;
}//end GetMuonIsoSF

double HardcodedConditions::GetMuonIsoSF2016(double pt, double eta)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	return 1.000;

}

double HardcodedConditions::GetMuonIsoSF2017(double pt, double eta)
{
	// MiniIsoTight/Tight
	// Jess Wong, approved in MUO 8/26/19, slide 37 upper left
	if(pt < 30){
        if(fabs(eta) < 0.9) return 0.9961;
        else if(fabs(eta) <  1.2) return 0.9921;
        else if(fabs(eta) <  2.1) return 0.9973;
        else if(fabs(eta) <  2.4) return 0.9990;}
    else if(pt < 40){
        if(fabs(eta) < 0.9) return 0.9968;
        else if(fabs(eta) <  1.2) return 0.9962;
        else if(fabs(eta) <  2.1) return 0.9978;
        else if(fabs(eta) <  2.4) return 0.9988;}
    else if(pt < 50){
        if(fabs(eta) < 0.9) return 0.9984;
        else if(fabs(eta) <  1.2) return 0.9976;
        else if(fabs(eta) <  2.1) return 0.9984;
        else if(fabs(eta) <  2.4) return 0.9996;}
    else if(pt < 60){
        if(fabs(eta) < 0.9) return 0.9992;
        else if(fabs(eta) <  1.2) return 0.9989;
        else if(fabs(eta) <  2.1) return 0.9993;
        else if(fabs(eta) <  2.4) return 0.9988;}
    else if(pt < 120){
        if(fabs(eta) < 0.9) return 0.9996;
        else if(fabs(eta) <  1.2) return 1.0000;
        else if(fabs(eta) <  2.1) return 1.0004;
        else if(fabs(eta) <  2.4) return 0.9987;}
	else{ // ignoring the 200-300, low stats, using 120+
	    if(fabs(eta) < 0.9) return 0.9999;
        else if(fabs(eta) <  1.2) return 0.9992;
        else if(fabs(eta) <  2.1) return 1.0005;
        else if(fabs(eta) <  2.4) return 0.9964;}
}

double HardcodedConditions::GetMuonIsoSF2018(double pt, double eta)
{
	//Miniisolation SF, Jess Wong approved in MUO 8/26/19, slide 38 upper left
    if(pt < 30){ // 25-30
        if(fabs(eta) < 0.9) return 0.9925;
        else if(fabs(eta) <  1.2) return 0.9932;
        else if(fabs(eta) <  2.1) return 1.0124;
        else return 1.0202;}
    else if(pt < 40){
        if(fabs(eta) < 0.9) return 0.9959;
        else if(fabs(eta) <  1.2) return 0.9957;
        else if(fabs(eta) <  2.1) return 1.0076;
        else return 1.0101;}
    else if(pt < 50){
        if(fabs(eta) < 0.9) return 0.9981;
        else if(fabs(eta) <  1.2) return 0.9978;
        else if(fabs(eta) <  2.1) return 1.0040;
        else return 1.0059;}
    else if(pt < 60){
        if(fabs(eta) < 0.9) return 0.9989;
        else if(fabs(eta) <  1.2) return 0.9982;
        else if(fabs(eta) <  2.1) return 1.0019;
        else return 1.0029;}
    else if(pt < 120){
        if(fabs(eta) < 0.9) return 0.9997;
        else if(fabs(eta) <  1.2) return 0.9995;
        else if(fabs(eta) <  2.1) return 1.0001;
        else return 1.0003;}
    else{ //120-200, ignoring 200-300 for low stats
        if(fabs(eta) < 0.9) return 1.0000;
        else if(fabs(eta) <  1.2) return 1.0016;
        else if(fabs(eta) <  2.1) return 0.9983;
        else return 1.0000;}

}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|          MUON TRIGGER SCALE FACTOR SECTION          |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetMuonTriggerSF(double pt, double eta, int year)
{
  //The main getter for Muon Trigger Scale Factors
  if      (year==2016) return GetMuonTriggerSF2016(pt, eta);
  else if (year==2017) return GetMuonTriggerSF2017(pt, eta);
  else if (year==2018) return GetMuonTriggerSF2018(pt, eta);
  else return 0.;
}//end GetMuonTriggerSF

double HardcodedConditions::GetMuonTriggerSF2016(double pt, double eta)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	return 1.000;

}

double HardcodedConditions::GetMuonTriggerSF2017(double pt, double eta)
{
	float triggerSFB = 1.0;
    float triggerSFCDEF = 1.0;
	if (fabs(eta) < 0.90){
	    if (pt < 50.0){triggerSFB = 1.0;triggerSFCDEF = 1.027;}
	    else if (pt < 55.0){triggerSFB = 0.872;triggerSFCDEF = 1.014;}
	    else if (pt < 60.0){triggerSFB = 0.978;triggerSFCDEF = 1.026;}
	    else if (pt < 70.0){triggerSFB = 1.003;triggerSFCDEF = 1.021;}
	    else if (pt < 100){triggerSFB = 0.990;triggerSFCDEF = 1.013;}
	    else if (pt < 200){triggerSFB = 0.979;triggerSFCDEF = 1.014;}
	    else{triggerSFB = 0.949;triggerSFCDEF = 1.006;}
	}else if (fabs(eta) < 1.20){
	    if (pt < 50.0){triggerSFB = 1.0;triggerSFCDEF = 1.020;}
	    else if (pt < 55.0){triggerSFB = 0.897;triggerSFCDEF = 1.015;}
	    else if (pt < 60.0){triggerSFB = 1.024;triggerSFCDEF = 0.995;}
	    else if (pt < 70.0){triggerSFB = 0.958;triggerSFCDEF = 0.995;}
	    else if (pt < 100){triggerSFB = 0.990;triggerSFCDEF = 1.004;}
	    else if (pt < 200){triggerSFB = 0.951;triggerSFCDEF = 1.000;}
	    else{triggerSFB = 0.884;triggerSFCDEF = 0.994;}
	}else if (fabs(eta) < 2.10){
	    if (pt < 50.0){triggerSFB = 1.0;triggerSFCDEF = 1.052;}
	    else if (pt < 55.0){triggerSFB = 0.800;triggerSFCDEF = 1.064;}
	    else if (pt < 60.0){triggerSFB = 0.936;triggerSFCDEF = 1.052;}
	    else if (pt < 70.0){triggerSFB = 0.993;triggerSFCDEF = 1.038;}
	    else if (pt < 100){triggerSFB = 0.984;triggerSFCDEF = 1.041;}
	    else if (pt < 200){triggerSFB = 0.963;triggerSFCDEF = 1.024;}
	    else{triggerSFB = 0.991;triggerSFCDEF = 1.018;}
	}else{
	    if (pt < 50.0){triggerSFB = 1.0;triggerSFCDEF = 1.109;}
	    else  if (pt < 55.0){triggerSFB = 1.0;triggerSFCDEF = 1.061;}
	    else if (pt < 60.0){triggerSFB = 0.751;triggerSFCDEF = 1.086;}
	    else if (pt < 70.0){triggerSFB = 0.804;triggerSFCDEF = 1.113;}
	    else if (pt < 100){triggerSFB = 0.915;triggerSFCDEF = 1.105;}
	    else if (pt < 200){triggerSFB = 1.032;triggerSFCDEF = 1.146;}
	    else{triggerSFB = 0.835;triggerSFCDEF = 1.136;}
	}
	return (4.823*triggerSFB+36.734*triggerSFCDEF)/41.557;

}

double HardcodedConditions::GetMuonTriggerSF2018(double pt, double eta)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	return 1.000;

}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|                PILEUP WEIGHT SECTION                |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetPileupWeight(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn, int year, std::string sample)
{
  //The main getter for Pileup Weight Factors
  *pileupweight   = 1.000;
  *pileupweightup = 1.000;
  *pileupweightdn = 1.000;
  if      (year==2016) GetPileupWeight2016(nTrueInt, pileupweight, pileupweightup, pileupweightdn, sample);
  else if (year==2017) GetPileupWeight2017(nTrueInt, pileupweight, pileupweightup, pileupweightdn, sample);
  else if (year==2018) GetPileupWeight2018(nTrueInt, pileupweight, pileupweightup, pileupweightdn, sample);
}//end GetPileupWeight

void HardcodedConditions::GetPileupWeight2016(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn, std::string sample)
{
	// TO-BE-IMPLEMENTED!!!!!!!
	*pileupweight   = 1.000;
	*pileupweightup = 1.000;
	*pileupweightdn = 1.000;

}

void HardcodedConditions::GetPileupWeight2017(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn, std::string sample)
{
    // Pileup distributions -- 31Mar2018 Data vs RunIIFall17MC
    std::unordered_map<std::string, std::vector<float>> pileupweights = { // 69.2 mb
{"DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8",{5.202e-04, 1.732e-01, 6.524e-02, 1.051e-01, 7.782e-02, 7.074e-02, 5.636e-02, 1.578e-01, 1.041e-01, 2.976e-01, 4.844e-01, 8.430e-01, 6.433e-01, 6.391e-01, 6.185e-01, 6.598e-01, 7.822e-01, 9.093e-01, 1.069e+00, 1.086e+00, 1.211e+00, 1.252e+00, 1.298e+00, 1.322e+00, 1.355e+00, 1.372e+00, 1.174e+00, 1.383e+00, 1.413e+00, 1.396e+00, 1.341e+00, 1.287e+00, 1.197e+00, 1.112e+00, 1.062e+00, 1.003e+00, 9.522e-01, 9.235e-01, 8.274e-01, 8.367e-01, 7.672e-01, 8.866e-01, 9.070e-01, 1.072e+00, 1.230e+00, 1.408e+00, 1.541e+00, 1.679e+00, 1.737e+00, 1.642e+00, 1.427e+00, 1.265e+00, 1.031e+00, 8.213e-01, 6.221e-01, 4.057e-01, 3.109e-01, 2.122e-01, 1.497e-01, 9.110e-02, 7.505e-02, 5.398e-02, 4.104e-02, 2.899e-02, 2.612e-02, 1.903e-02, 1.301e-02, 1.146e-02, 1.055e-02, 1.017e-02, 9.379e-03, 7.285e-03, 1.100e-03, 8.660e-03, 4.736e-04, 6.339e-03, 5.531e-03, 5.185e-03, 2.455e-04, 1.158e-04, 9.824e-03, 1.564e-03, 7.432e-03, 2.421e-03, 1.253e-02, 4.023e-03, 0.000e+00, 3.241e-03, 1.472e-05, 0.000e+00, 7.774e-04, 0.000e+00, 0.000e+00, 1.716e-04, 0.000e+00, 0.000e+00, 3.470e-05, 1.996e-05, 0.000e+00, 1.942e-07, 0.000e+0}},
{"DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8",{1.768e-01, 4.107e+00, 3.478e+00, 2.368e+00, 1.552e+00, 1.556e+00, 1.295e+00, 1.254e+00, 6.272e-01, 1.463e+00, 1.473e+00, 1.480e+00, 1.325e+00, 1.167e+00, 1.079e+00, 1.053e+00, 1.087e+00, 1.126e+00, 1.163e+00, 1.189e+00, 1.209e+00, 1.236e+00, 1.262e+00, 1.271e+00, 1.275e+00, 1.273e+00, 1.272e+00, 1.265e+00, 1.274e+00, 1.250e+00, 1.225e+00, 1.171e+00, 1.109e+00, 1.040e+00, 9.681e-01, 9.124e-01, 8.668e-01, 8.337e-01, 7.864e-01, 7.501e-01, 7.585e-01, 7.938e-01, 8.590e-01, 9.606e-01, 1.090e+00, 1.254e+00, 1.419e+00, 1.496e+00, 1.530e+00, 1.464e+00, 1.337e+00, 1.156e+00, 9.501e-01, 7.507e-01, 5.714e-01, 4.116e-01, 2.893e-01, 1.983e-01, 1.380e-01, 9.645e-02, 6.933e-02, 5.061e-02, 3.844e-02, 3.011e-02, 2.407e-02, 1.715e-02, 1.241e-02, 1.070e-02, 9.663e-03, 8.949e-03, 8.231e-03, 8.094e-03, 7.946e-03, 7.974e-03, 6.490e-03, 5.392e-03, 5.367e-03, 5.789e-03, 5.517e-03, 6.496e-03, 6.447e-03, 6.003e-03, 7.472e-03, 5.167e-03, 4.724e-03, 6.645e-03, 3.867e-03, 6.246e-03, 5.034e-03, 5.474e-03, 1.348e-02, 4.113e-03, 9.943e-04, 2.976e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8",{2.500e-01, 3.492e+00, 4.860e+00, 4.056e+00, 1.567e+00, 1.494e+00, 1.133e+00, 1.246e+00, 7.152e-01, 1.517e+00, 1.398e+00, 1.490e+00, 1.296e+00, 1.144e+00, 1.087e+00, 1.079e+00, 1.105e+00, 1.119e+00, 1.147e+00, 1.176e+00, 1.207e+00, 1.223e+00, 1.251e+00, 1.276e+00, 1.283e+00, 1.282e+00, 1.271e+00, 1.286e+00, 1.273e+00, 1.237e+00, 1.246e+00, 1.154e+00, 1.122e+00, 1.047e+00, 9.742e-01, 9.220e-01, 8.832e-01, 8.296e-01, 7.859e-01, 7.315e-01, 7.527e-01, 7.973e-01, 8.528e-01, 9.597e-01, 1.111e+00, 1.247e+00, 1.429e+00, 1.496e+00, 1.505e+00, 1.470e+00, 1.311e+00, 1.135e+00, 9.619e-01, 7.553e-01, 5.713e-01, 4.166e-01, 2.828e-01, 1.963e-01, 1.396e-01, 9.582e-02, 6.930e-02, 5.052e-02, 3.820e-02, 3.023e-02, 2.362e-02, 1.661e-02, 1.264e-02, 1.092e-02, 9.747e-03, 8.866e-03, 8.610e-03, 8.709e-03, 8.045e-03, 7.947e-03, 6.080e-03, 4.973e-03, 4.198e-03, 4.600e-03, 4.225e-03, 6.136e-03, 6.391e-03, 4.917e-03, 6.447e-03, 3.150e-03, 2.717e-03, 0.000e+00, 3.336e-03, 2.109e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8",{1.927e-01, 5.011e+00, 3.624e+00, 2.585e+00, 1.535e+00, 1.512e+00, 1.265e+00, 1.241e+00, 6.101e-01, 1.460e+00, 1.474e+00, 1.481e+00, 1.338e+00, 1.168e+00, 1.077e+00, 1.056e+00, 1.087e+00, 1.126e+00, 1.165e+00, 1.187e+00, 1.210e+00, 1.238e+00, 1.257e+00, 1.270e+00, 1.271e+00, 1.270e+00, 1.271e+00, 1.263e+00, 1.275e+00, 1.253e+00, 1.224e+00, 1.170e+00, 1.112e+00, 1.039e+00, 9.682e-01, 9.138e-01, 8.670e-01, 8.355e-01, 7.879e-01, 7.524e-01, 7.599e-01, 7.932e-01, 8.584e-01, 9.590e-01, 1.097e+00, 1.263e+00, 1.421e+00, 1.479e+00, 1.529e+00, 1.465e+00, 1.335e+00, 1.150e+00, 9.494e-01, 7.483e-01, 5.690e-01, 4.105e-01, 2.896e-01, 2.000e-01, 1.376e-01, 9.723e-02, 6.903e-02, 5.082e-02, 3.845e-02, 2.976e-02, 2.415e-02, 1.709e-02, 1.252e-02, 1.073e-02, 9.586e-03, 8.949e-03, 8.293e-03, 7.967e-03, 8.087e-03, 8.015e-03, 6.300e-03, 5.234e-03, 5.574e-03, 5.610e-03, 5.790e-03, 5.574e-03, 5.847e-03, 6.031e-03, 6.626e-03, 5.603e-03, 4.217e-03, 4.281e-03, 6.041e-03, 4.455e-03, 4.189e-03, 3.470e-03, 2.564e-03, 1.956e-03, 1.576e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8",{2.036e-01, 3.719e+00, 3.315e+00, 2.794e+00, 1.757e+00, 1.489e+00, 1.262e+00, 1.287e+00, 6.035e-01, 1.444e+00, 1.509e+00, 1.485e+00, 1.336e+00, 1.165e+00, 1.081e+00, 1.048e+00, 1.081e+00, 1.126e+00, 1.165e+00, 1.194e+00, 1.217e+00, 1.240e+00, 1.263e+00, 1.265e+00, 1.272e+00, 1.269e+00, 1.272e+00, 1.263e+00, 1.270e+00, 1.250e+00, 1.225e+00, 1.169e+00, 1.110e+00, 1.041e+00, 9.702e-01, 9.123e-01, 8.658e-01, 8.345e-01, 7.881e-01, 7.513e-01, 7.580e-01, 7.945e-01, 8.608e-01, 9.598e-01, 1.097e+00, 1.258e+00, 1.421e+00, 1.495e+00, 1.527e+00, 1.456e+00, 1.334e+00, 1.154e+00, 9.500e-01, 7.479e-01, 5.703e-01, 4.109e-01, 2.894e-01, 1.988e-01, 1.375e-01, 9.674e-02, 6.941e-02, 5.087e-02, 3.824e-02, 2.989e-02, 2.419e-02, 1.714e-02, 1.251e-02, 1.072e-02, 9.610e-03, 8.944e-03, 8.300e-03, 8.145e-03, 7.606e-03, 7.887e-03, 6.196e-03, 5.502e-03, 5.342e-03, 5.697e-03, 6.310e-03, 5.414e-03, 6.132e-03, 7.429e-03, 6.981e-03, 4.787e-03, 3.756e-03, 4.929e-03, 4.250e-03, 3.806e-03, 5.725e-03, 3.557e-03, 1.095e-02, 6.682e-03, 4.039e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8",{1.925e-01, 6.204e+00, 4.276e+00, 2.532e+00, 1.764e+00, 1.482e+00, 1.395e+00, 1.478e+00, 6.245e-01, 1.488e+00, 1.518e+00, 1.483e+00, 1.299e+00, 1.175e+00, 1.079e+00, 1.047e+00, 1.069e+00, 1.132e+00, 1.165e+00, 1.186e+00, 1.214e+00, 1.235e+00, 1.261e+00, 1.275e+00, 1.276e+00, 1.270e+00, 1.272e+00, 1.256e+00, 1.276e+00, 1.256e+00, 1.220e+00, 1.168e+00, 1.111e+00, 1.042e+00, 9.694e-01, 9.133e-01, 8.702e-01, 8.306e-01, 7.877e-01, 7.505e-01, 7.537e-01, 8.003e-01, 8.602e-01, 9.598e-01, 1.098e+00, 1.255e+00, 1.421e+00, 1.484e+00, 1.528e+00, 1.457e+00, 1.349e+00, 1.157e+00, 9.466e-01, 7.544e-01, 5.640e-01, 4.091e-01, 2.895e-01, 2.006e-01, 1.374e-01, 9.694e-02, 6.937e-02, 5.080e-02, 3.882e-02, 2.971e-02, 2.425e-02, 1.701e-02, 1.242e-02, 1.096e-02, 9.670e-03, 8.692e-03, 8.242e-03, 8.000e-03, 8.012e-03, 8.072e-03, 5.896e-03, 5.085e-03, 5.798e-03, 5.538e-03, 5.657e-03, 5.095e-03, 6.150e-03, 5.407e-03, 7.090e-03, 5.105e-03, 2.728e-03, 3.664e-03, 8.561e-03, 5.411e-03, 5.088e-03, 6.323e-03, 3.893e-03, 7.918e-04, 7.179e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT1000to1500_TuneCP5_13TeV-madgraph-pythia8",{1.957e-01, 4.016e+00, 3.198e+00, 2.581e+00, 1.609e+00, 1.488e+00, 1.311e+00, 1.285e+00, 6.157e-01, 1.497e+00, 1.491e+00, 1.485e+00, 1.332e+00, 1.162e+00, 1.082e+00, 1.050e+00, 1.082e+00, 1.129e+00, 1.164e+00, 1.188e+00, 1.211e+00, 1.238e+00, 1.259e+00, 1.273e+00, 1.270e+00, 1.266e+00, 1.273e+00, 1.267e+00, 1.274e+00, 1.253e+00, 1.224e+00, 1.167e+00, 1.111e+00, 1.039e+00, 9.689e-01, 9.114e-01, 8.672e-01, 8.349e-01, 7.884e-01, 7.513e-01, 7.584e-01, 7.940e-01, 8.597e-01, 9.612e-01, 1.096e+00, 1.257e+00, 1.422e+00, 1.502e+00, 1.528e+00, 1.468e+00, 1.335e+00, 1.156e+00, 9.493e-01, 7.492e-01, 5.713e-01, 4.111e-01, 2.901e-01, 1.981e-01, 1.378e-01, 9.664e-02, 6.912e-02, 5.065e-02, 3.833e-02, 2.985e-02, 2.404e-02, 1.705e-02, 1.252e-02, 1.077e-02, 9.567e-03, 8.751e-03, 8.326e-03, 7.909e-03, 7.754e-03, 7.791e-03, 6.346e-03, 5.424e-03, 5.444e-03, 5.321e-03, 6.079e-03, 5.542e-03, 6.050e-03, 6.164e-03, 6.122e-03, 4.578e-03, 4.423e-03, 4.051e-03, 4.979e-03, 4.005e-03, 4.603e-03, 3.813e-03, 2.642e-03, 6.447e-03, 1.559e-03, 4.665e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT1500to2000_TuneCP5_13TeV-madgraph-pythia8",{1.749e-01, 4.172e+00, 3.462e+00, 2.677e+00, 1.657e+00, 1.475e+00, 1.255e+00, 1.247e+00, 6.001e-01, 1.423e+00, 1.498e+00, 1.492e+00, 1.325e+00, 1.164e+00, 1.082e+00, 1.052e+00, 1.083e+00, 1.127e+00, 1.163e+00, 1.191e+00, 1.212e+00, 1.241e+00, 1.255e+00, 1.270e+00, 1.274e+00, 1.273e+00, 1.272e+00, 1.268e+00, 1.278e+00, 1.250e+00, 1.223e+00, 1.171e+00, 1.111e+00, 1.036e+00, 9.706e-01, 9.105e-01, 8.681e-01, 8.332e-01, 7.863e-01, 7.510e-01, 7.603e-01, 7.926e-01, 8.584e-01, 9.578e-01, 1.096e+00, 1.256e+00, 1.416e+00, 1.494e+00, 1.526e+00, 1.468e+00, 1.336e+00, 1.152e+00, 9.529e-01, 7.485e-01, 5.702e-01, 4.122e-01, 2.880e-01, 1.984e-01, 1.374e-01, 9.694e-02, 6.917e-02, 5.072e-02, 3.858e-02, 2.990e-02, 2.407e-02, 1.711e-02, 1.255e-02, 1.081e-02, 9.625e-03, 8.906e-03, 8.153e-03, 8.132e-03, 7.846e-03, 7.748e-03, 6.233e-03, 5.267e-03, 5.609e-03, 6.071e-03, 6.121e-03, 6.164e-03, 6.168e-03, 6.767e-03, 6.302e-03, 3.970e-03, 5.435e-03, 5.004e-03, 3.543e-03, 5.497e-03, 4.211e-03, 2.944e-03, 3.626e-03, 2.949e-03, 5.348e-03, 3.201e-03, 9.489e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT2000toInf_TuneCP5_13TeV-madgraph-pythia8",{1.673e-01, 4.002e+00, 3.617e+00, 2.548e+00, 1.509e+00, 1.493e+00, 1.296e+00, 1.240e+00, 6.044e-01, 1.455e+00, 1.499e+00, 1.488e+00, 1.340e+00, 1.174e+00, 1.086e+00, 1.052e+00, 1.083e+00, 1.128e+00, 1.168e+00, 1.181e+00, 1.205e+00, 1.236e+00, 1.259e+00, 1.272e+00, 1.271e+00, 1.272e+00, 1.271e+00, 1.267e+00, 1.278e+00, 1.251e+00, 1.219e+00, 1.164e+00, 1.109e+00, 1.038e+00, 9.690e-01, 9.157e-01, 8.645e-01, 8.360e-01, 7.876e-01, 7.518e-01, 7.621e-01, 7.940e-01, 8.594e-01, 9.634e-01, 1.096e+00, 1.255e+00, 1.424e+00, 1.511e+00, 1.535e+00, 1.457e+00, 1.342e+00, 1.153e+00, 9.464e-01, 7.538e-01, 5.673e-01, 4.094e-01, 2.882e-01, 1.995e-01, 1.377e-01, 9.630e-02, 6.900e-02, 5.090e-02, 3.856e-02, 2.996e-02, 2.428e-02, 1.692e-02, 1.250e-02, 1.082e-02, 9.818e-03, 8.680e-03, 8.325e-03, 8.296e-03, 7.673e-03, 7.873e-03, 6.039e-03, 5.129e-03, 5.625e-03, 5.495e-03, 6.660e-03, 5.474e-03, 5.696e-03, 6.031e-03, 5.399e-03, 4.689e-03, 3.380e-03, 4.749e-03, 6.917e-03, 1.020e-02, 2.398e-03, 2.980e-03, 2.447e-03, 4.479e-03, 1.353e-03, 5.401e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT200to300_TuneCP5_13TeV-madgraph-pythia8",{1.809e-01, 4.000e+00, 3.698e+00, 2.549e+00, 1.633e+00, 1.551e+00, 1.271e+00, 1.249e+00, 6.178e-01, 1.456e+00, 1.491e+00, 1.487e+00, 1.335e+00, 1.167e+00, 1.080e+00, 1.055e+00, 1.082e+00, 1.129e+00, 1.166e+00, 1.189e+00, 1.212e+00, 1.239e+00, 1.260e+00, 1.270e+00, 1.273e+00, 1.271e+00, 1.270e+00, 1.266e+00, 1.274e+00, 1.253e+00, 1.225e+00, 1.171e+00, 1.110e+00, 1.038e+00, 9.680e-01, 9.116e-01, 8.658e-01, 8.344e-01, 7.895e-01, 7.502e-01, 7.581e-01, 7.934e-01, 8.596e-01, 9.603e-01, 1.094e+00, 1.256e+00, 1.420e+00, 1.494e+00, 1.527e+00, 1.463e+00, 1.340e+00, 1.153e+00, 9.533e-01, 7.507e-01, 5.701e-01, 4.092e-01, 2.900e-01, 1.986e-01, 1.377e-01, 9.651e-02, 6.932e-02, 5.073e-02, 3.841e-02, 2.995e-02, 2.408e-02, 1.705e-02, 1.251e-02, 1.072e-02, 9.619e-03, 8.788e-03, 8.250e-03, 7.996e-03, 7.891e-03, 7.873e-03, 6.430e-03, 5.389e-03, 5.500e-03, 5.553e-03, 5.844e-03, 6.347e-03, 6.023e-03, 5.760e-03, 6.569e-03, 4.950e-03, 4.052e-03, 4.399e-03, 4.184e-03, 4.983e-03, 5.131e-03, 4.617e-03, 5.154e-03, 2.959e-03, 1.789e-03, 6.067e-03, 1.079e-02, 1.056e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT300to500_TuneCP5_13TeV-madgraph-pythia8",{1.857e-01, 4.045e+00, 3.641e+00, 2.530e+00, 1.581e+00, 1.497e+00, 1.295e+00, 1.279e+00, 6.177e-01, 1.454e+00, 1.500e+00, 1.481e+00, 1.327e+00, 1.166e+00, 1.076e+00, 1.055e+00, 1.082e+00, 1.128e+00, 1.165e+00, 1.188e+00, 1.212e+00, 1.239e+00, 1.261e+00, 1.269e+00, 1.272e+00, 1.271e+00, 1.272e+00, 1.266e+00, 1.275e+00, 1.252e+00, 1.221e+00, 1.170e+00, 1.110e+00, 1.037e+00, 9.681e-01, 9.120e-01, 8.670e-01, 8.341e-01, 7.886e-01, 7.513e-01, 7.581e-01, 7.927e-01, 8.606e-01, 9.609e-01, 1.093e+00, 1.258e+00, 1.421e+00, 1.493e+00, 1.528e+00, 1.463e+00, 1.337e+00, 1.152e+00, 9.533e-01, 7.506e-01, 5.696e-01, 4.108e-01, 2.902e-01, 1.987e-01, 1.375e-01, 9.668e-02, 6.935e-02, 5.089e-02, 3.841e-02, 2.998e-02, 2.406e-02, 1.712e-02, 1.249e-02, 1.072e-02, 9.597e-03, 8.794e-03, 8.246e-03, 8.079e-03, 7.878e-03, 7.878e-03, 6.210e-03, 5.385e-03, 5.520e-03, 5.676e-03, 5.731e-03, 5.892e-03, 6.284e-03, 6.447e-03, 6.131e-03, 4.915e-03, 4.189e-03, 4.261e-03, 3.924e-03, 5.040e-03, 4.146e-03, 3.989e-03, 2.456e-03, 2.904e-03, 1.652e-03, 2.101e-03, 9.965e-03, 2.925e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT500to700_TuneCP5_13TeV-madgraph-pythia8",{1.834e-01, 3.830e+00, 3.431e+00, 2.566e+00, 1.607e+00, 1.516e+00, 1.322e+00, 1.286e+00, 6.178e-01, 1.451e+00, 1.510e+00, 1.489e+00, 1.334e+00, 1.166e+00, 1.079e+00, 1.051e+00, 1.080e+00, 1.129e+00, 1.168e+00, 1.188e+00, 1.212e+00, 1.236e+00, 1.259e+00, 1.270e+00, 1.275e+00, 1.273e+00, 1.272e+00, 1.266e+00, 1.275e+00, 1.251e+00, 1.222e+00, 1.170e+00, 1.108e+00, 1.038e+00, 9.692e-01, 9.114e-01, 8.675e-01, 8.339e-01, 7.873e-01, 7.504e-01, 7.585e-01, 7.925e-01, 8.606e-01, 9.600e-01, 1.097e+00, 1.258e+00, 1.417e+00, 1.495e+00, 1.532e+00, 1.461e+00, 1.339e+00, 1.155e+00, 9.511e-01, 7.497e-01, 5.697e-01, 4.110e-01, 2.903e-01, 1.985e-01, 1.376e-01, 9.636e-02, 6.920e-02, 5.083e-02, 3.837e-02, 2.997e-02, 2.407e-02, 1.708e-02, 1.248e-02, 1.079e-02, 9.597e-03, 8.774e-03, 8.342e-03, 8.039e-03, 7.871e-03, 7.898e-03, 6.371e-03, 5.334e-03, 5.530e-03, 5.678e-03, 5.844e-03, 6.165e-03, 6.247e-03, 6.308e-03, 6.138e-03, 5.205e-03, 4.022e-03, 4.512e-03, 3.981e-03, 4.461e-03, 3.549e-03, 3.699e-03, 3.210e-03, 3.590e-03, 2.367e-03, 1.732e-03, 4.620e-03, 2.712e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT700to1000_TuneCP5_13TeV-madgraph-pythia8",{1.879e-01, 3.816e+00, 3.218e+00, 2.454e+00, 1.641e+00, 1.494e+00, 1.304e+00, 1.240e+00, 6.218e-01, 1.457e+00, 1.500e+00, 1.489e+00, 1.328e+00, 1.166e+00, 1.081e+00, 1.054e+00, 1.079e+00, 1.130e+00, 1.166e+00, 1.190e+00, 1.211e+00, 1.241e+00, 1.258e+00, 1.270e+00, 1.270e+00, 1.272e+00, 1.273e+00, 1.266e+00, 1.275e+00, 1.250e+00, 1.221e+00, 1.170e+00, 1.110e+00, 1.038e+00, 9.694e-01, 9.114e-01, 8.672e-01, 8.367e-01, 7.879e-01, 7.498e-01, 7.579e-01, 7.935e-01, 8.617e-01, 9.591e-01, 1.097e+00, 1.255e+00, 1.422e+00, 1.495e+00, 1.530e+00, 1.462e+00, 1.341e+00, 1.155e+00, 9.510e-01, 7.488e-01, 5.689e-01, 4.108e-01, 2.892e-01, 1.990e-01, 1.375e-01, 9.631e-02, 6.932e-02, 5.092e-02, 3.836e-02, 2.995e-02, 2.401e-02, 1.709e-02, 1.245e-02, 1.070e-02, 9.656e-03, 8.801e-03, 8.344e-03, 8.060e-03, 7.939e-03, 7.699e-03, 6.254e-03, 5.278e-03, 5.482e-03, 5.668e-03, 5.810e-03, 6.086e-03, 6.095e-03, 6.078e-03, 6.937e-03, 5.137e-03, 4.083e-03, 4.345e-03, 3.657e-03, 4.376e-03, 4.655e-03, 3.409e-03, 2.351e-03, 2.758e-03, 1.445e-03, 1.081e-03, 2.564e-03, 1.505e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia",{1.803e-01, 5.928e+00, 2.750e+00, 2.419e+00, 1.593e+00, 1.440e+00, 1.337e+00, 1.229e+00, 6.134e-01, 1.448e+00, 1.581e+00, 1.476e+00, 1.342e+00, 1.168e+00, 1.082e+00, 1.055e+00, 1.092e+00, 1.129e+00, 1.163e+00, 1.186e+00, 1.217e+00, 1.233e+00, 1.255e+00, 1.266e+00, 1.277e+00, 1.273e+00, 1.272e+00, 1.266e+00, 1.271e+00, 1.248e+00, 1.223e+00, 1.169e+00, 1.115e+00, 1.039e+00, 9.698e-01, 9.093e-01, 8.651e-01, 8.358e-01, 7.850e-01, 7.509e-01, 7.577e-01, 7.946e-01, 8.607e-01, 9.629e-01, 1.096e+00, 1.257e+00, 1.420e+00, 1.510e+00, 1.519e+00, 1.460e+00, 1.342e+00, 1.159e+00, 9.444e-01, 7.466e-01, 5.680e-01, 4.106e-01, 2.915e-01, 1.987e-01, 1.379e-01, 9.649e-02, 6.923e-02, 5.152e-02, 3.845e-02, 2.990e-02, 2.394e-02, 1.698e-02, 1.234e-02, 1.050e-02, 9.671e-03, 8.746e-03, 8.200e-03, 8.309e-03, 7.932e-03, 7.767e-03, 6.096e-03, 5.745e-03, 5.503e-03, 6.036e-03, 6.486e-03, 5.339e-03, 7.313e-03, 5.293e-03, 9.484e-03, 4.413e-03, 6.662e-03, 3.851e-03, 4.908e-03, 3.878e-03, 4.861e-03, 1.510e-03, 3.720e-03, 1.135e-03, 1.372e-03, 8.212e-04, 0.000e+00, 2.857e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia",{1.746e-01, 3.830e+00, 3.553e+00, 2.403e+00, 1.599e+00, 1.559e+00, 1.322e+00, 1.260e+00, 6.069e-01, 1.461e+00, 1.501e+00, 1.472e+00, 1.320e+00, 1.158e+00, 1.080e+00, 1.055e+00, 1.084e+00, 1.121e+00, 1.171e+00, 1.191e+00, 1.209e+00, 1.237e+00, 1.260e+00, 1.273e+00, 1.272e+00, 1.267e+00, 1.272e+00, 1.269e+00, 1.271e+00, 1.252e+00, 1.223e+00, 1.171e+00, 1.111e+00, 1.044e+00, 9.695e-01, 9.127e-01, 8.670e-01, 8.365e-01, 7.866e-01, 7.524e-01, 7.567e-01, 7.963e-01, 8.596e-01, 9.551e-01, 1.093e+00, 1.260e+00, 1.425e+00, 1.487e+00, 1.521e+00, 1.463e+00, 1.343e+00, 1.156e+00, 9.445e-01, 7.558e-01, 5.707e-01, 4.089e-01, 2.878e-01, 1.986e-01, 1.374e-01, 9.582e-02, 6.921e-02, 5.063e-02, 3.820e-02, 3.022e-02, 2.411e-02, 1.709e-02, 1.256e-02, 1.082e-02, 9.682e-03, 8.739e-03, 8.479e-03, 8.119e-03, 8.084e-03, 7.948e-03, 6.203e-03, 5.410e-03, 5.892e-03, 5.502e-03, 5.216e-03, 5.742e-03, 6.863e-03, 6.583e-03, 7.384e-03, 6.367e-03, 4.829e-03, 4.283e-03, 3.582e-03, 5.176e-03, 3.785e-03, 2.822e-03, 8.689e-03, 2.651e-03, 3.204e-03, 9.591e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.852e-01, 3.872e+00, 3.527e+00, 2.555e+00, 1.599e+00, 1.529e+00, 1.308e+00, 1.270e+00, 6.120e-01, 1.461e+00, 1.499e+00, 1.481e+00, 1.335e+00, 1.168e+00, 1.079e+00, 1.051e+00, 1.078e+00, 1.128e+00, 1.167e+00, 1.190e+00, 1.212e+00, 1.238e+00, 1.260e+00, 1.272e+00, 1.272e+00, 1.271e+00, 1.270e+00, 1.267e+00, 1.278e+00, 1.253e+00, 1.222e+00, 1.170e+00, 1.109e+00, 1.038e+00, 9.688e-01, 9.125e-01, 8.665e-01, 8.339e-01, 7.873e-01, 7.505e-01, 7.585e-01, 7.922e-01, 8.598e-01, 9.591e-01, 1.096e+00, 1.256e+00, 1.419e+00, 1.497e+00, 1.529e+00, 1.464e+00, 1.338e+00, 1.158e+00, 9.496e-01, 7.484e-01, 5.695e-01, 4.107e-01, 2.897e-01, 1.987e-01, 1.375e-01, 9.643e-02, 6.918e-02, 5.080e-02, 3.835e-02, 3.004e-02, 2.410e-02, 1.712e-02, 1.248e-02, 1.078e-02, 9.636e-03, 8.782e-03, 8.289e-03, 8.057e-03, 7.851e-03, 7.971e-03, 6.259e-03, 5.394e-03, 5.467e-03, 5.733e-03, 5.734e-03, 5.922e-03, 6.267e-03, 6.286e-03, 6.323e-03, 4.593e-03, 3.965e-03, 4.804e-03, 4.310e-03, 4.481e-03, 4.186e-03, 3.790e-03, 2.723e-03, 2.931e-03, 1.882e-03, 2.003e-03, 1.069e-02, 8.963e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_t-channel_top_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.825e-01, 3.909e+00, 3.371e+00, 2.523e+00, 1.643e+00, 1.508e+00, 1.285e+00, 1.257e+00, 6.197e-01, 1.460e+00, 1.502e+00, 1.487e+00, 1.334e+00, 1.168e+00, 1.080e+00, 1.053e+00, 1.081e+00, 1.128e+00, 1.166e+00, 1.189e+00, 1.214e+00, 1.238e+00, 1.260e+00, 1.270e+00, 1.273e+00, 1.272e+00, 1.271e+00, 1.267e+00, 1.275e+00, 1.252e+00, 1.221e+00, 1.170e+00, 1.109e+00, 1.038e+00, 9.690e-01, 9.118e-01, 8.668e-01, 8.344e-01, 7.886e-01, 7.506e-01, 7.584e-01, 7.925e-01, 8.602e-01, 9.579e-01, 1.094e+00, 1.256e+00, 1.420e+00, 1.496e+00, 1.530e+00, 1.462e+00, 1.337e+00, 1.153e+00, 9.504e-01, 7.509e-01, 5.697e-01, 4.111e-01, 2.900e-01, 1.986e-01, 1.377e-01, 9.650e-02, 6.921e-02, 5.083e-02, 3.841e-02, 3.001e-02, 2.415e-02, 1.713e-02, 1.248e-02, 1.077e-02, 9.577e-03, 8.775e-03, 8.270e-03, 8.056e-03, 7.813e-03, 7.842e-03, 6.354e-03, 5.325e-03, 5.540e-03, 5.616e-03, 5.825e-03, 6.069e-03, 6.155e-03, 6.495e-03, 6.770e-03, 4.718e-03, 4.354e-03, 4.733e-03, 4.094e-03, 4.475e-03, 3.960e-03, 4.563e-03, 2.711e-03, 2.947e-03, 1.628e-03, 1.795e-03, 6.741e-03, 1.696e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_tW_antitop_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.923e-01, 3.858e+00, 3.294e+00, 2.403e+00, 1.686e+00, 1.567e+00, 1.329e+00, 1.244e+00, 6.014e-01, 1.447e+00, 1.506e+00, 1.487e+00, 1.325e+00, 1.173e+00, 1.079e+00, 1.053e+00, 1.079e+00, 1.127e+00, 1.171e+00, 1.188e+00, 1.213e+00, 1.238e+00, 1.255e+00, 1.271e+00, 1.274e+00, 1.271e+00, 1.271e+00, 1.267e+00, 1.271e+00, 1.255e+00, 1.224e+00, 1.167e+00, 1.110e+00, 1.039e+00, 9.678e-01, 9.130e-01, 8.656e-01, 8.348e-01, 7.886e-01, 7.502e-01, 7.614e-01, 7.936e-01, 8.597e-01, 9.614e-01, 1.090e+00, 1.261e+00, 1.414e+00, 1.498e+00, 1.524e+00, 1.460e+00, 1.328e+00, 1.158e+00, 9.470e-01, 7.491e-01, 5.716e-01, 4.128e-01, 2.892e-01, 1.986e-01, 1.370e-01, 9.649e-02, 6.938e-02, 5.098e-02, 3.854e-02, 3.016e-02, 2.394e-02, 1.713e-02, 1.252e-02, 1.078e-02, 9.578e-03, 8.740e-03, 8.257e-03, 7.846e-03, 7.829e-03, 8.136e-03, 6.325e-03, 5.530e-03, 5.481e-03, 5.873e-03, 5.533e-03, 6.041e-03, 6.394e-03, 6.647e-03, 6.734e-03, 5.885e-03, 4.336e-03, 4.177e-03, 3.758e-03, 6.731e-03, 4.219e-03, 2.621e-03, 2.421e-03, 5.909e-03, 1.190e-03, 2.138e-03, 0.000e+00, 3.720e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.706e-01, 4.036e+00, 4.062e+00, 2.813e+00, 1.666e+00, 1.506e+00, 1.243e+00, 1.212e+00, 6.098e-01, 1.456e+00, 1.456e+00, 1.476e+00, 1.333e+00, 1.172e+00, 1.073e+00, 1.053e+00, 1.082e+00, 1.124e+00, 1.171e+00, 1.194e+00, 1.215e+00, 1.233e+00, 1.264e+00, 1.270e+00, 1.273e+00, 1.275e+00, 1.272e+00, 1.266e+00, 1.273e+00, 1.249e+00, 1.221e+00, 1.168e+00, 1.105e+00, 1.037e+00, 9.676e-01, 9.107e-01, 8.676e-01, 8.343e-01, 7.912e-01, 7.511e-01, 7.582e-01, 7.948e-01, 8.562e-01, 9.601e-01, 1.099e+00, 1.257e+00, 1.423e+00, 1.487e+00, 1.521e+00, 1.465e+00, 1.342e+00, 1.157e+00, 9.496e-01, 7.494e-01, 5.700e-01, 4.126e-01, 2.901e-01, 1.984e-01, 1.380e-01, 9.621e-02, 6.949e-02, 5.070e-02, 3.833e-02, 3.015e-02, 2.417e-02, 1.718e-02, 1.252e-02, 1.094e-02, 9.618e-03, 8.845e-03, 8.205e-03, 7.989e-03, 7.797e-03, 7.889e-03, 6.438e-03, 5.379e-03, 5.799e-03, 5.502e-03, 6.000e-03, 5.766e-03, 6.608e-03, 6.037e-03, 5.066e-03, 4.670e-03, 5.930e-03, 5.713e-03, 4.681e-03, 5.178e-03, 3.246e-03, 3.227e-03, 1.656e-03, 6.062e-03, 9.159e-04, 2.193e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTHH_TuneCP5_13TeV-madgraph-pythia8",{1.196e-04, 5.204e-01, 4.023e-01, 2.879e-01, 2.163e-01, 1.576e-01, 1.475e-01, 1.344e-01, 6.983e-02, 3.851e-01, 5.166e-01, 5.361e-01, 7.230e-01, 3.607e-01, 7.524e-01, 7.334e-01, 7.852e-01, 9.504e-01, 8.686e-01, 1.200e+00, 1.238e+00, 1.309e+00, 1.392e+00, 1.441e+00, 1.436e+00, 1.369e+00, 1.420e+00, 1.404e+00, 1.421e+00, 1.387e+00, 1.349e+00, 1.289e+00, 1.261e+00, 1.153e+00, 1.115e+00, 1.035e+00, 9.963e-01, 9.319e-01, 8.792e-01, 8.314e-01, 8.832e-01, 8.983e-01, 9.666e-01, 1.054e+00, 1.235e+00, 1.399e+00, 1.609e+00, 1.718e+00, 1.716e+00, 1.680e+00, 1.450e+00, 1.254e+00, 1.053e+00, 8.634e-01, 6.589e-01, 4.735e-01, 3.268e-01, 2.292e-01, 1.535e-01, 1.054e-01, 7.915e-02, 5.845e-02, 3.508e-02, 3.221e-02, 2.534e-02, 2.050e-02, 1.364e-02, 1.160e-02, 1.077e-02, 1.017e-02, 8.554e-03, 9.067e-03, 1.006e-02, 8.524e-03, 7.597e-03, 5.249e-03, 6.624e-03, 5.027e-03, 1.259e-02, 1.677e-02, 5.556e-03, 4.885e-03, 9.607e-03, 2.086e-03, 0.000e+00, 2.600e-03, 1.657e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 5.607e-06, 0.000e+00, 0.000e+00, 1.479e-07, 0.000e+0}},
{"TTTJ_TuneCP5_13TeV-madgraph-pythia8",{1.374e-01, 0.000e+00, 4.808e+00, 2.580e+00, 3.231e+00, 1.756e+00, 1.468e+00, 1.089e+00, 6.318e-01, 1.449e+00, 1.492e+00, 1.421e+00, 1.218e+00, 1.156e+00, 1.103e+00, 1.046e+00, 1.100e+00, 1.149e+00, 1.178e+00, 1.214e+00, 1.215e+00, 1.226e+00, 1.255e+00, 1.278e+00, 1.249e+00, 1.262e+00, 1.260e+00, 1.258e+00, 1.278e+00, 1.257e+00, 1.224e+00, 1.172e+00, 1.109e+00, 1.027e+00, 9.588e-01, 9.063e-01, 8.598e-01, 8.457e-01, 8.045e-01, 7.557e-01, 7.739e-01, 7.953e-01, 8.771e-01, 9.409e-01, 1.128e+00, 1.215e+00, 1.418e+00, 1.511e+00, 1.522e+00, 1.437e+00, 1.357e+00, 1.172e+00, 9.472e-01, 7.288e-01, 5.542e-01, 4.123e-01, 2.807e-01, 2.046e-01, 1.358e-01, 9.633e-02, 7.233e-02, 5.112e-02, 3.930e-02, 2.868e-02, 2.438e-02, 1.681e-02, 1.328e-02, 1.063e-02, 9.811e-03, 7.983e-03, 8.093e-03, 8.161e-03, 8.634e-03, 9.577e-03, 5.548e-03, 4.920e-03, 5.340e-03, 5.776e-03, 4.560e-03, 4.174e-03, 5.533e-03, 0.000e+00, 9.568e-03, 2.078e-03, 0.000e+00, 0.000e+00, 1.650e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTTT_TuneCP5_13TeV-amcatnlo-pythia8",{1.503e-01, 2.250e+00, 2.922e+00, 2.287e+00, 1.841e+00, 9.179e-01, 7.874e-01, 8.202e-01, 9.332e-01, 1.343e+00, 1.293e+00, 1.631e+00, 1.278e+00, 1.115e+00, 1.072e+00, 1.053e+00, 1.066e+00, 1.161e+00, 1.218e+00, 1.171e+00, 1.245e+00, 1.187e+00, 1.233e+00, 1.250e+00, 1.289e+00, 1.233e+00, 1.278e+00, 1.275e+00, 1.248e+00, 1.274e+00, 1.187e+00, 1.165e+00, 1.094e+00, 1.052e+00, 9.833e-01, 9.331e-01, 8.964e-01, 8.474e-01, 7.690e-01, 7.452e-01, 7.399e-01, 7.868e-01, 8.684e-01, 9.558e-01, 1.101e+00, 1.326e+00, 1.447e+00, 1.501e+00, 1.613e+00, 1.487e+00, 1.324e+00, 1.155e+00, 9.510e-01, 7.847e-01, 5.405e-01, 4.072e-01, 3.035e-01, 1.982e-01, 1.431e-01, 9.851e-02, 6.585e-02, 4.937e-02, 3.788e-02, 3.128e-02, 2.360e-02, 1.687e-02, 1.200e-02, 9.873e-03, 9.357e-03, 8.688e-03, 8.214e-03, 7.563e-03, 6.484e-03, 6.005e-03, 5.620e-03, 7.475e-03, 4.868e-03, 6.167e-03, 8.022e-03, 2.537e-02, 5.173e-03, 3.167e-03, 4.153e-03, 4.735e-03, 2.450e-03, 0.000e+00, 1.254e-03, -7.925e-04, 0.000e+00, 0.000e+00, 0.000e+00, -4.638e-04, 0.000e+00, -8.391e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTTW_TuneCP5_13TeV-madgraph-pythia8",{1.822e-03, 4.739e-01, 5.690e-01, 2.711e-01, 2.349e-01, 1.976e-01, 1.814e-01, 1.785e-01, 9.210e-02, 1.979e-01, 5.709e-01, 6.113e-01, 6.835e-01, 1.001e+00, 1.049e+00, 1.019e+00, 1.057e+00, 9.561e-01, 1.063e+00, 1.097e+00, 1.129e+00, 1.175e+00, 1.246e+00, 1.283e+00, 1.280e+00, 1.309e+00, 1.316e+00, 1.270e+00, 1.314e+00, 1.319e+00, 1.259e+00, 1.227e+00, 1.110e+00, 1.084e+00, 1.037e+00, 9.790e-01, 8.646e-01, 8.969e-01, 8.425e-01, 8.139e-01, 8.230e-01, 8.539e-01, 9.129e-01, 1.061e+00, 1.152e+00, 1.363e+00, 1.531e+00, 1.673e+00, 1.684e+00, 1.584e+00, 1.396e+00, 1.236e+00, 8.211e-01, 7.984e-01, 6.256e-01, 4.464e-01, 3.063e-01, 1.624e-01, 1.482e-01, 1.041e-01, 7.243e-02, 5.495e-02, 4.163e-02, 3.149e-02, 2.467e-02, 1.878e-02, 1.324e-02, 1.179e-02, 9.596e-03, 9.792e-03, 9.045e-03, 8.131e-03, 1.065e-02, 6.261e-03, 5.979e-03, 6.232e-03, 5.937e-03, 6.294e-03, 3.604e-03, 3.015e-05, 7.420e-03, 1.468e-02, 9.623e-03, 2.090e-03, 4.056e-03, 2.605e-03, 4.150e-04, 1.778e-06, 6.577e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 1.123e-05, 0.000e+00, 0.000e+00, 4.148e-07, 0.000e+0}},
{"TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.788e-01, 3.918e+00, 3.422e+00, 2.558e+00, 1.640e+00, 1.547e+00, 1.294e+00, 1.245e+00, 6.140e-01, 1.462e+00, 1.487e+00, 1.493e+00, 1.332e+00, 1.172e+00, 1.079e+00, 1.054e+00, 1.082e+00, 1.126e+00, 1.165e+00, 1.190e+00, 1.212e+00, 1.238e+00, 1.260e+00, 1.269e+00, 1.271e+00, 1.272e+00, 1.271e+00, 1.266e+00, 1.275e+00, 1.251e+00, 1.223e+00, 1.171e+00, 1.110e+00, 1.039e+00, 9.682e-01, 9.119e-01, 8.664e-01, 8.355e-01, 7.881e-01, 7.501e-01, 7.599e-01, 7.924e-01, 8.597e-01, 9.594e-01, 1.094e+00, 1.259e+00, 1.422e+00, 1.495e+00, 1.531e+00, 1.461e+00, 1.339e+00, 1.156e+00, 9.484e-01, 7.504e-01, 5.701e-01, 4.114e-01, 2.895e-01, 1.988e-01, 1.375e-01, 9.635e-02, 6.927e-02, 5.070e-02, 3.840e-02, 3.003e-02, 2.402e-02, 1.707e-02, 1.246e-02, 1.077e-02, 9.651e-03, 8.821e-03, 8.296e-03, 8.108e-03, 7.676e-03, 7.829e-03, 6.228e-03, 5.362e-03, 5.526e-03, 5.500e-03, 5.669e-03, 5.859e-03, 6.026e-03, 6.557e-03, 6.010e-03, 4.681e-03, 4.003e-03, 4.407e-03, 3.879e-03, 4.291e-03, 3.963e-03, 3.509e-03, 3.201e-03, 3.102e-03, 2.125e-03, 2.120e-03, 5.656e-03, 2.213e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.864e-01, 3.667e+00, 3.369e+00, 2.529e+00, 1.611e+00, 1.512e+00, 1.281e+00, 1.273e+00, 6.152e-01, 1.451e+00, 1.487e+00, 1.485e+00, 1.334e+00, 1.169e+00, 1.077e+00, 1.054e+00, 1.081e+00, 1.128e+00, 1.164e+00, 1.188e+00, 1.213e+00, 1.238e+00, 1.261e+00, 1.271e+00, 1.272e+00, 1.271e+00, 1.271e+00, 1.267e+00, 1.274e+00, 1.251e+00, 1.222e+00, 1.169e+00, 1.110e+00, 1.038e+00, 9.684e-01, 9.112e-01, 8.669e-01, 8.359e-01, 7.887e-01, 7.499e-01, 7.593e-01, 7.939e-01, 8.595e-01, 9.585e-01, 1.094e+00, 1.257e+00, 1.418e+00, 1.494e+00, 1.531e+00, 1.462e+00, 1.337e+00, 1.155e+00, 9.514e-01, 7.501e-01, 5.697e-01, 4.109e-01, 2.898e-01, 1.986e-01, 1.374e-01, 9.662e-02, 6.931e-02, 5.093e-02, 3.845e-02, 2.997e-02, 2.409e-02, 1.708e-02, 1.250e-02, 1.079e-02, 9.602e-03, 8.834e-03, 8.264e-03, 8.024e-03, 7.804e-03, 7.872e-03, 6.320e-03, 5.380e-03, 5.496e-03, 5.494e-03, 5.879e-03, 5.870e-03, 6.121e-03, 6.425e-03, 6.407e-03, 4.853e-03, 4.312e-03, 4.588e-03, 4.065e-03, 4.433e-03, 4.088e-03, 4.064e-03, 3.536e-03, 3.817e-03, 1.935e-03, 1.890e-03, 7.096e-03, 2.499e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTToSemiLepton_HT500Njet9_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.811e-01, 3.462e+00, 3.211e+00, 2.535e+00, 1.791e+00, 1.512e+00, 1.317e+00, 1.248e+00, 6.201e-01, 1.475e+00, 1.504e+00, 1.491e+00, 1.319e+00, 1.162e+00, 1.075e+00, 1.048e+00, 1.080e+00, 1.129e+00, 1.169e+00, 1.189e+00, 1.214e+00, 1.238e+00, 1.259e+00, 1.275e+00, 1.272e+00, 1.274e+00, 1.273e+00, 1.264e+00, 1.278e+00, 1.253e+00, 1.220e+00, 1.170e+00, 1.109e+00, 1.039e+00, 9.645e-01, 9.131e-01, 8.659e-01, 8.357e-01, 7.867e-01, 7.525e-01, 7.610e-01, 7.934e-01, 8.610e-01, 9.587e-01, 1.097e+00, 1.252e+00, 1.421e+00, 1.496e+00, 1.528e+00, 1.464e+00, 1.340e+00, 1.153e+00, 9.468e-01, 7.495e-01, 5.696e-01, 4.099e-01, 2.905e-01, 1.983e-01, 1.372e-01, 9.646e-02, 6.899e-02, 5.074e-02, 3.830e-02, 2.981e-02, 2.427e-02, 1.683e-02, 1.256e-02, 1.085e-02, 9.632e-03, 8.763e-03, 8.381e-03, 7.930e-03, 7.709e-03, 8.051e-03, 6.293e-03, 5.565e-03, 5.650e-03, 5.678e-03, 5.556e-03, 6.456e-03, 5.985e-03, 6.993e-03, 7.668e-03, 4.995e-03, 3.950e-03, 3.567e-03, 7.275e-03, 4.181e-03, 9.608e-03, 2.559e-03, 2.757e-03, 0.000e+00, 4.519e-04, 1.217e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.802e-01, 3.818e+00, 3.486e+00, 2.560e+00, 1.644e+00, 1.521e+00, 1.281e+00, 1.246e+00, 6.131e-01, 1.454e+00, 1.494e+00, 1.485e+00, 1.335e+00, 1.169e+00, 1.078e+00, 1.054e+00, 1.081e+00, 1.128e+00, 1.166e+00, 1.189e+00, 1.212e+00, 1.238e+00, 1.260e+00, 1.271e+00, 1.273e+00, 1.272e+00, 1.271e+00, 1.267e+00, 1.275e+00, 1.252e+00, 1.222e+00, 1.170e+00, 1.111e+00, 1.037e+00, 9.690e-01, 9.110e-01, 8.666e-01, 8.345e-01, 7.878e-01, 7.509e-01, 7.581e-01, 7.934e-01, 8.582e-01, 9.589e-01, 1.096e+00, 1.258e+00, 1.420e+00, 1.496e+00, 1.530e+00, 1.462e+00, 1.337e+00, 1.155e+00, 9.500e-01, 7.497e-01, 5.697e-01, 4.111e-01, 2.902e-01, 1.988e-01, 1.375e-01, 9.667e-02, 6.919e-02, 5.097e-02, 3.840e-02, 3.001e-02, 2.409e-02, 1.705e-02, 1.247e-02, 1.077e-02, 9.649e-03, 8.840e-03, 8.295e-03, 8.003e-03, 7.891e-03, 7.831e-03, 6.270e-03, 5.289e-03, 5.419e-03, 5.406e-03, 5.901e-03, 5.930e-03, 6.144e-03, 6.537e-03, 6.476e-03, 4.929e-03, 4.254e-03, 4.667e-03, 3.827e-03, 4.901e-03, 4.923e-03, 4.466e-03, 3.354e-03, 4.661e-03, 1.636e-03, 1.786e-03, 4.499e-03, 3.521e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTWH_TuneCP5_13TeV-madgraph-pythia8",{2.554e-04, 3.020e-02, 4.190e-02, 2.967e-01, 2.159e-01, 1.828e-01, 1.515e-01, 1.461e-01, 7.338e-02, 1.834e-01, 5.735e-01, 7.585e-01, 7.385e-01, 6.286e-01, 6.018e-01, 3.906e-01, 7.894e-01, 1.070e+00, 1.173e+00, 1.229e+00, 1.229e+00, 1.193e+00, 1.307e+00, 1.321e+00, 1.359e+00, 1.415e+00, 1.433e+00, 1.368e+00, 1.461e+00, 1.425e+00, 1.353e+00, 1.288e+00, 1.243e+00, 1.157e+00, 1.070e+00, 1.026e+00, 9.708e-01, 8.998e-01, 8.974e-01, 8.384e-01, 8.284e-01, 8.681e-01, 1.006e+00, 1.074e+00, 1.263e+00, 1.383e+00, 1.542e+00, 1.628e+00, 1.672e+00, 1.617e+00, 1.381e+00, 1.176e+00, 6.075e-01, 8.045e-01, 6.090e-01, 4.314e-01, 3.180e-01, 2.192e-01, 1.486e-01, 1.036e-01, 7.456e-02, 5.292e-02, 4.359e-02, 3.150e-02, 2.504e-02, 1.768e-02, 1.322e-02, 1.147e-02, 1.005e-02, 4.843e-03, 8.162e-03, 8.592e-03, 4.017e-03, 2.241e-03, 8.628e-03, 4.299e-03, 3.406e-03, 2.595e-03, 5.586e-03, 1.673e-02, 1.109e-02, 1.463e-02, 4.794e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 6.553e-04, 0.000e+00, 0.000e+00, 0.000e+00, 9.246e-05, 0.000e+00, 0.000e+00, 0.000e+00, 5.596e-06, 6.439e-06, 3.667e-06, 2.296e-07, 0.000e+0}},
{"TTWJetsToLNu_TuneCP5_PSweights_13TeV-amcatnloFXFX-madspin-pythia8",{1.942e-01, 2.753e+00, 2.952e+00, 2.626e+00, 1.424e+00, 1.487e+00, 1.406e+00, 1.178e+00, 6.317e-01, 1.473e+00, 1.549e+00, 1.461e+00, 1.353e+00, 1.154e+00, 1.081e+00, 1.066e+00, 1.091e+00, 1.125e+00, 1.170e+00, 1.181e+00, 1.214e+00, 1.239e+00, 1.253e+00, 1.261e+00, 1.275e+00, 1.270e+00, 1.285e+00, 1.263e+00, 1.280e+00, 1.263e+00, 1.226e+00, 1.162e+00, 1.111e+00, 1.044e+00, 9.655e-01, 9.063e-01, 8.640e-01, 8.284e-01, 7.845e-01, 7.472e-01, 7.625e-01, 7.901e-01, 8.609e-01, 9.676e-01, 1.097e+00, 1.249e+00, 1.414e+00, 1.494e+00, 1.527e+00, 1.456e+00, 1.341e+00, 1.145e+00, 9.444e-01, 7.433e-01, 5.678e-01, 4.124e-01, 2.912e-01, 2.001e-01, 1.415e-01, 9.657e-02, 6.951e-02, 5.019e-02, 3.902e-02, 3.056e-02, 2.366e-02, 1.696e-02, 1.266e-02, 1.087e-02, 9.641e-03, 8.947e-03, 8.189e-03, 7.520e-03, 7.446e-03, 7.509e-03, 6.657e-03, 5.850e-03, 5.653e-03, 4.963e-03, 5.588e-03, 9.609e-03, 4.931e-03, 7.466e-03, 6.293e-03, 1.076e-02, 6.962e-03, 3.974e-03, 3.256e-03, 7.205e-03, 3.011e-03, 1.403e-03, -3.456e-03, 0.000e+00, 0.000e+00, 3.814e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8",{1.196e-01, 3.842e+00, 2.673e+00, 2.114e+00, 1.391e+00, 1.689e+00, 9.939e-01, 1.172e+00, 6.387e-01, 1.589e+00, 1.447e+00, 1.528e+00, 1.426e+00, 1.172e+00, 1.126e+00, 1.049e+00, 1.076e+00, 1.127e+00, 1.194e+00, 1.170e+00, 1.208e+00, 1.247e+00, 1.263e+00, 1.271e+00, 1.291e+00, 1.281e+00, 1.271e+00, 1.269e+00, 1.277e+00, 1.255e+00, 1.208e+00, 1.175e+00, 1.121e+00, 1.037e+00, 9.857e-01, 8.943e-01, 8.604e-01, 8.540e-01, 7.981e-01, 7.348e-01, 7.543e-01, 7.774e-01, 8.580e-01, 9.335e-01, 1.098e+00, 1.266e+00, 1.443e+00, 1.484e+00, 1.544e+00, 1.459e+00, 1.309e+00, 1.143e+00, 9.758e-01, 7.455e-01, 5.578e-01, 3.962e-01, 2.868e-01, 1.953e-01, 1.395e-01, 9.678e-02, 7.154e-02, 5.207e-02, 3.726e-02, 2.936e-02, 2.574e-02, 1.781e-02, 1.253e-02, 1.115e-02, 8.425e-03, 8.174e-03, 7.346e-03, 7.581e-03, 8.104e-03, 9.333e-03, 4.828e-03, 4.895e-03, 5.668e-03, 5.061e-03, 5.312e-03, 3.909e-03, 4.922e-03, 4.637e-03, 5.319e-03, 1.386e-02, 2.989e-03, 2.880e-03, 3.670e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTWW_TuneCP5_13TeV-madgraph-pythia8",{7.033e-04, 5.772e-01, 6.426e-01, 4.893e-01, 2.429e-01, 2.166e-01, 3.724e-01, 4.252e-01, 2.228e-01, 5.841e-01, 6.034e-01, 5.884e-01, 5.759e-01, 5.445e-01, 6.798e-01, 7.602e-01, 9.141e-01, 1.032e+00, 1.148e+00, 1.115e+00, 1.188e+00, 1.227e+00, 1.278e+00, 1.247e+00, 1.374e+00, 1.363e+00, 1.380e+00, 1.412e+00, 1.377e+00, 1.374e+00, 1.234e+00, 1.303e+00, 1.201e+00, 1.150e+00, 1.064e+00, 1.027e+00, 9.396e-01, 9.283e-01, 8.592e-01, 8.035e-01, 8.355e-01, 8.667e-01, 9.533e-01, 1.042e+00, 1.185e+00, 1.099e+00, 1.582e+00, 1.644e+00, 1.724e+00, 1.585e+00, 1.331e+00, 1.133e+00, 9.544e-01, 7.582e-01, 5.949e-01, 2.526e-01, 2.960e-01, 2.041e-01, 1.431e-01, 1.000e-01, 7.121e-02, 5.312e-02, 4.084e-02, 3.141e-02, 2.601e-02, 1.844e-02, 1.410e-02, 1.106e-02, 5.710e-03, 9.571e-03, 8.653e-03, 8.180e-03, 1.172e-02, 9.131e-03, 6.104e-03, 5.988e-03, 4.163e-03, 5.790e-03, 3.591e-03, 6.845e-05, 7.395e-03, 4.876e-03, 4.795e-03, 2.062e-05, 1.347e-03, 3.032e-06, 0.000e+00, 1.046e-03, 0.000e+00, 1.113e-06, 0.000e+00, 1.530e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 2.584e-07, 0.000e+0}},
{"TTWZ_TuneCP5_13TeV-madgraph-pythia8",{2.264e-03, 2.731e-01, 2.006e-01, 1.755e-01, 5.545e-01, 4.849e-01, 4.229e-01, 3.478e-01, 2.282e-01, 4.834e-01, 5.215e-01, 4.925e-01, 4.540e-01, 7.166e-01, 7.775e-01, 9.475e-01, 9.996e-01, 1.105e+00, 1.142e+00, 1.153e+00, 1.249e+00, 1.275e+00, 1.250e+00, 1.314e+00, 1.342e+00, 1.290e+00, 1.300e+00, 1.322e+00, 1.346e+00, 1.305e+00, 1.279e+00, 1.186e+00, 1.142e+00, 1.075e+00, 1.031e+00, 9.884e-01, 9.079e-01, 8.905e-01, 8.238e-01, 7.990e-01, 8.009e-01, 8.148e-01, 9.196e-01, 9.914e-01, 1.063e+00, 1.358e+00, 1.567e+00, 1.606e+00, 1.608e+00, 1.430e+00, 1.408e+00, 1.003e+00, 9.926e-01, 7.812e-01, 5.951e-01, 4.188e-01, 2.975e-01, 1.208e-01, 1.416e-01, 9.715e-02, 7.189e-02, 5.105e-02, 3.734e-02, 3.128e-02, 2.533e-02, 1.742e-02, 1.244e-02, 1.095e-02, 9.884e-03, 8.801e-03, 9.065e-03, 8.944e-03, 7.912e-03, 7.190e-03, 5.812e-03, 4.785e-03, 5.908e-03, 5.370e-03, 6.277e-03, 5.571e-03, 4.431e-03, 7.305e-03, 0.000e+00, 1.560e-03, 2.018e-03, 1.296e-03, 0.000e+00, 5.274e-06, 6.546e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 2.236e-06, 3.216e-06, 0.000e+00, 2.949e-07, 0.000e+0}},
{"TTZH_TuneCP5_13TeV-madgraph-pythia8",{2.303e-03, 1.734e+00, 1.379e+00, 1.066e+00, 6.949e-01, 9.400e-01, 8.145e-01, 7.805e-01, 3.441e-01, 1.176e+00, 1.171e+00, 1.287e+00, 1.034e+00, 9.583e-01, 8.984e-01, 8.627e-01, 8.913e-01, 9.552e-01, 9.954e-01, 1.079e+00, 1.126e+00, 1.123e+00, 1.206e+00, 1.221e+00, 1.314e+00, 1.291e+00, 1.258e+00, 1.278e+00, 1.361e+00, 1.328e+00, 1.222e+00, 1.221e+00, 1.164e+00, 1.115e+00, 1.043e+00, 9.468e-01, 9.185e-01, 8.947e-01, 8.459e-01, 8.025e-01, 8.345e-01, 8.395e-01, 9.202e-01, 7.704e-01, 1.183e+00, 1.414e+00, 1.535e+00, 1.615e+00, 1.651e+00, 1.586e+00, 1.400e+00, 7.774e-01, 9.911e-01, 7.694e-01, 6.107e-01, 4.293e-01, 2.968e-01, 2.113e-01, 1.419e-01, 1.032e-01, 7.320e-02, 5.125e-02, 3.969e-02, 3.295e-02, 2.468e-02, 1.727e-02, 1.441e-02, 1.095e-02, 1.048e-02, 8.983e-03, 9.487e-03, 7.220e-03, 8.047e-03, 8.520e-03, 6.265e-03, 6.458e-03, 5.360e-03, 5.384e-03, 6.294e-03, 8.379e-03, 4.347e-05, 3.662e-03, 4.802e-03, 2.085e-03, 2.024e-03, 0.000e+00, 0.000e+00, 1.047e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 1.121e-05, 2.150e-06, 0.000e+00, 2.957e-07, 0.000e+0}},
{"TTZToLLNuNu_M-10_TuneCP5_PSweights_13TeV-amcatnlo-pythia8",{1.909e-01, 3.419e+00, 3.339e+00, 2.336e+00, 1.564e+00, 1.778e+00, 1.310e+00, 1.249e+00, 6.491e-01, 1.471e+00, 1.485e+00, 1.484e+00, 1.312e+00, 1.177e+00, 1.075e+00, 1.056e+00, 1.089e+00, 1.131e+00, 1.162e+00, 1.192e+00, 1.216e+00, 1.246e+00, 1.259e+00, 1.280e+00, 1.274e+00, 1.277e+00, 1.267e+00, 1.269e+00, 1.268e+00, 1.254e+00, 1.224e+00, 1.172e+00, 1.107e+00, 1.035e+00, 9.686e-01, 9.117e-01, 8.680e-01, 8.377e-01, 7.833e-01, 7.461e-01, 7.584e-01, 7.940e-01, 8.556e-01, 9.610e-01, 1.104e+00, 1.255e+00, 1.416e+00, 1.495e+00, 1.523e+00, 1.457e+00, 1.317e+00, 1.148e+00, 9.458e-01, 7.459e-01, 5.699e-01, 4.125e-01, 2.889e-01, 1.985e-01, 1.372e-01, 9.581e-02, 6.918e-02, 5.162e-02, 3.844e-02, 3.025e-02, 2.414e-02, 1.708e-02, 1.244e-02, 1.111e-02, 9.695e-03, 8.772e-03, 8.088e-03, 8.092e-03, 7.848e-03, 7.564e-03, 6.635e-03, 5.332e-03, 6.230e-03, 5.662e-03, 6.334e-03, 6.250e-03, 7.893e-03, 5.664e-03, 6.824e-03, 4.217e-03, 3.433e-03, 5.257e-03, 4.839e-03, 3.059e-03, 4.314e-03, 2.680e-03, 1.320e-03, 0.000e+00, 2.435e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTZZ_TuneCP5_13TeV-madgraph-pythia8",{2.030e-04, 3.061e-01, 1.637e-01, 1.486e-01, 9.636e-02, 1.621e-01, 2.382e-01, 3.280e-01, 1.991e-01, 4.761e-01, 5.700e-01, 5.404e-01, 5.790e-01, 9.805e-01, 8.808e-01, 6.118e-01, 9.211e-01, 9.485e-01, 9.354e-01, 1.038e+00, 1.148e+00, 1.239e+00, 1.182e+00, 1.331e+00, 1.325e+00, 1.320e+00, 1.295e+00, 1.306e+00, 1.407e+00, 1.386e+00, 1.393e+00, 1.302e+00, 1.254e+00, 1.167e+00, 1.096e+00, 1.044e+00, 9.903e-01, 7.137e-01, 8.838e-01, 8.566e-01, 8.420e-01, 9.136e-01, 1.001e+00, 8.963e-01, 1.243e+00, 1.398e+00, 1.678e+00, 1.758e+00, 1.775e+00, 1.709e+00, 1.076e+00, 1.311e+00, 1.081e+00, 8.328e-01, 6.199e-01, 4.474e-01, 3.084e-01, 2.273e-01, 1.529e-01, 1.060e-01, 7.840e-02, 5.577e-02, 4.271e-02, 3.296e-02, 2.693e-02, 1.881e-02, 1.053e-02, 1.166e-02, 1.014e-02, 1.012e-02, 7.739e-03, 8.971e-03, 9.089e-03, 6.945e-03, 5.571e-03, 4.666e-03, 6.256e-03, 5.800e-03, 3.875e-03, 3.726e-03, 7.408e-03, 7.327e-03, 9.607e-03, 2.086e-03, 2.024e-03, 1.734e-04, 1.657e-03, 1.048e-03, 0.000e+00, 0.000e+00, 0.000e+00, 1.533e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 5.607e-06, 0.000e+00, 0.000e+00, 3.451e-07, 0.000e+0}},
{"WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8",{1.878e-01, 4.700e+00, 3.198e+00, 2.393e+00, 1.807e+00, 1.486e+00, 1.327e+00, 1.211e+00, 6.100e-01, 1.495e+00, 1.517e+00, 1.479e+00, 1.319e+00, 1.164e+00, 1.076e+00, 1.050e+00, 1.080e+00, 1.130e+00, 1.165e+00, 1.189e+00, 1.212e+00, 1.237e+00, 1.259e+00, 1.271e+00, 1.271e+00, 1.272e+00, 1.272e+00, 1.268e+00, 1.276e+00, 1.253e+00, 1.221e+00, 1.169e+00, 1.110e+00, 1.039e+00, 9.690e-01, 9.132e-01, 8.658e-01, 8.373e-01, 7.900e-01, 7.510e-01, 7.588e-01, 7.925e-01, 8.575e-01, 9.589e-01, 1.093e+00, 1.257e+00, 1.420e+00, 1.494e+00, 1.528e+00, 1.462e+00, 1.338e+00, 1.155e+00, 9.496e-01, 7.493e-01, 5.704e-01, 4.108e-01, 2.901e-01, 1.994e-01, 1.375e-01, 9.653e-02, 6.896e-02, 5.074e-02, 3.839e-02, 3.000e-02, 2.413e-02, 1.700e-02, 1.244e-02, 1.072e-02, 9.636e-03, 8.831e-03, 8.326e-03, 8.101e-03, 7.730e-03, 7.915e-03, 6.286e-03, 5.303e-03, 5.503e-03, 5.776e-03, 5.860e-03, 6.285e-03, 6.690e-03, 6.442e-03, 6.628e-03, 4.505e-03, 3.409e-03, 3.690e-03, 4.449e-03, 6.122e-03, 3.433e-03, 1.930e-03, 3.565e-03, 5.076e-03, 3.068e-03, 1.102e-03, 0.000e+00, 1.917e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8",{1.913e-01, 4.255e+00, 3.444e+00, 2.481e+00, 1.640e+00, 1.532e+00, 1.288e+00, 1.270e+00, 5.997e-01, 1.442e+00, 1.477e+00, 1.476e+00, 1.330e+00, 1.169e+00, 1.083e+00, 1.051e+00, 1.078e+00, 1.126e+00, 1.166e+00, 1.188e+00, 1.211e+00, 1.239e+00, 1.256e+00, 1.271e+00, 1.274e+00, 1.274e+00, 1.271e+00, 1.267e+00, 1.274e+00, 1.254e+00, 1.220e+00, 1.167e+00, 1.113e+00, 1.037e+00, 9.689e-01, 9.130e-01, 8.681e-01, 8.336e-01, 7.865e-01, 7.516e-01, 7.577e-01, 7.949e-01, 8.594e-01, 9.562e-01, 1.097e+00, 1.258e+00, 1.421e+00, 1.493e+00, 1.534e+00, 1.461e+00, 1.341e+00, 1.156e+00, 9.519e-01, 7.507e-01, 5.693e-01, 4.101e-01, 2.896e-01, 1.981e-01, 1.374e-01, 9.659e-02, 6.938e-02, 5.074e-02, 3.867e-02, 2.989e-02, 2.413e-02, 1.713e-02, 1.251e-02, 1.076e-02, 9.503e-03, 8.768e-03, 8.259e-03, 8.064e-03, 7.856e-03, 7.777e-03, 6.306e-03, 5.442e-03, 5.529e-03, 5.516e-03, 6.169e-03, 5.712e-03, 6.266e-03, 7.418e-03, 7.192e-03, 4.264e-03, 4.179e-03, 5.316e-03, 3.595e-03, 6.186e-03, 2.908e-03, 3.336e-03, 3.338e-03, 5.431e-03, 1.969e-03, 1.179e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8",{1.893e-01, 4.111e+00, 3.265e+00, 2.650e+00, 1.614e+00, 1.489e+00, 1.286e+00, 1.242e+00, 6.233e-01, 1.437e+00, 1.485e+00, 1.483e+00, 1.338e+00, 1.164e+00, 1.076e+00, 1.050e+00, 1.080e+00, 1.130e+00, 1.168e+00, 1.188e+00, 1.213e+00, 1.239e+00, 1.262e+00, 1.272e+00, 1.272e+00, 1.269e+00, 1.273e+00, 1.266e+00, 1.276e+00, 1.250e+00, 1.221e+00, 1.171e+00, 1.110e+00, 1.038e+00, 9.688e-01, 9.133e-01, 8.687e-01, 8.352e-01, 7.870e-01, 7.480e-01, 7.603e-01, 7.925e-01, 8.593e-01, 9.609e-01, 1.091e+00, 1.256e+00, 1.416e+00, 1.495e+00, 1.528e+00, 1.461e+00, 1.340e+00, 1.154e+00, 9.491e-01, 7.498e-01, 5.704e-01, 4.106e-01, 2.895e-01, 1.986e-01, 1.373e-01, 9.674e-02, 6.937e-02, 5.068e-02, 3.836e-02, 3.009e-02, 2.404e-02, 1.719e-02, 1.254e-02, 1.088e-02, 9.526e-03, 8.853e-03, 8.373e-03, 8.004e-03, 7.929e-03, 7.867e-03, 6.149e-03, 5.388e-03, 5.507e-03, 5.840e-03, 5.703e-03, 6.378e-03, 6.406e-03, 6.041e-03, 6.583e-03, 5.059e-03, 4.319e-03, 4.639e-03, 5.043e-03, 5.162e-03, 3.576e-03, 1.055e-02, 5.199e-03, 3.965e-03, 3.195e-03, 1.913e-03, 3.402e-03, 6.656e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8",{1.899e-01, 3.953e+00, 3.873e+00, 2.681e+00, 1.643e+00, 1.482e+00, 1.303e+00, 1.283e+00, 6.122e-01, 1.433e+00, 1.499e+00, 1.483e+00, 1.326e+00, 1.166e+00, 1.080e+00, 1.051e+00, 1.074e+00, 1.126e+00, 1.163e+00, 1.187e+00, 1.212e+00, 1.238e+00, 1.261e+00, 1.268e+00, 1.274e+00, 1.274e+00, 1.270e+00, 1.269e+00, 1.277e+00, 1.252e+00, 1.224e+00, 1.171e+00, 1.110e+00, 1.038e+00, 9.698e-01, 9.114e-01, 8.653e-01, 8.348e-01, 7.896e-01, 7.499e-01, 7.574e-01, 7.922e-01, 8.594e-01, 9.566e-01, 1.096e+00, 1.260e+00, 1.419e+00, 1.496e+00, 1.534e+00, 1.466e+00, 1.340e+00, 1.157e+00, 9.516e-01, 7.506e-01, 5.693e-01, 4.110e-01, 2.895e-01, 1.974e-01, 1.380e-01, 9.661e-02, 6.949e-02, 5.089e-02, 3.837e-02, 2.965e-02, 2.417e-02, 1.699e-02, 1.248e-02, 1.080e-02, 9.541e-03, 8.778e-03, 8.269e-03, 8.060e-03, 7.843e-03, 7.899e-03, 6.202e-03, 5.430e-03, 5.553e-03, 5.352e-03, 5.700e-03, 6.046e-03, 5.834e-03, 6.622e-03, 6.070e-03, 4.560e-03, 4.739e-03, 6.189e-03, 3.287e-03, 4.675e-03, 2.605e-03, 5.826e-03, 4.484e-03, 3.648e-03, 6.615e-03, 1.320e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8",{1.899e-01, 3.543e+00, 3.520e+00, 2.642e+00, 1.581e+00, 1.495e+00, 1.296e+00, 1.289e+00, 6.150e-01, 1.486e+00, 1.474e+00, 1.479e+00, 1.324e+00, 1.167e+00, 1.074e+00, 1.054e+00, 1.080e+00, 1.133e+00, 1.165e+00, 1.186e+00, 1.215e+00, 1.238e+00, 1.261e+00, 1.271e+00, 1.273e+00, 1.274e+00, 1.268e+00, 1.265e+00, 1.275e+00, 1.254e+00, 1.223e+00, 1.171e+00, 1.109e+00, 1.036e+00, 9.683e-01, 9.107e-01, 8.671e-01, 8.344e-01, 7.894e-01, 7.523e-01, 7.561e-01, 7.949e-01, 8.589e-01, 9.589e-01, 1.095e+00, 1.253e+00, 1.420e+00, 1.494e+00, 1.534e+00, 1.461e+00, 1.336e+00, 1.154e+00, 9.528e-01, 7.531e-01, 5.698e-01, 4.117e-01, 2.903e-01, 1.985e-01, 1.375e-01, 9.617e-02, 6.911e-02, 5.079e-02, 3.843e-02, 2.984e-02, 2.402e-02, 1.707e-02, 1.242e-02, 1.086e-02, 9.660e-03, 8.759e-03, 8.298e-03, 8.004e-03, 7.673e-03, 7.920e-03, 6.424e-03, 5.314e-03, 5.516e-03, 5.349e-03, 5.832e-03, 5.663e-03, 5.797e-03, 6.295e-03, 7.324e-03, 5.018e-03, 4.021e-03, 5.118e-03, 4.375e-03, 3.544e-03, 3.741e-03, 3.680e-03, 3.885e-03, 2.074e-03, 2.006e-03, 1.501e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8",{1.711e-01, 3.594e+00, 3.093e+00, 2.601e+00, 1.589e+00, 1.441e+00, 1.296e+00, 1.252e+00, 6.094e-01, 1.446e+00, 1.500e+00, 1.471e+00, 1.332e+00, 1.165e+00, 1.075e+00, 1.055e+00, 1.081e+00, 1.127e+00, 1.166e+00, 1.190e+00, 1.212e+00, 1.240e+00, 1.261e+00, 1.271e+00, 1.275e+00, 1.275e+00, 1.271e+00, 1.265e+00, 1.274e+00, 1.250e+00, 1.222e+00, 1.170e+00, 1.106e+00, 1.039e+00, 9.693e-01, 9.130e-01, 8.675e-01, 8.347e-01, 7.890e-01, 7.505e-01, 7.590e-01, 7.920e-01, 8.588e-01, 9.599e-01, 1.092e+00, 1.260e+00, 1.418e+00, 1.489e+00, 1.528e+00, 1.462e+00, 1.335e+00, 1.156e+00, 9.475e-01, 7.490e-01, 5.692e-01, 4.120e-01, 2.903e-01, 1.986e-01, 1.383e-01, 9.633e-02, 6.924e-02, 5.100e-02, 3.853e-02, 2.984e-02, 2.411e-02, 1.705e-02, 1.249e-02, 1.076e-02, 9.660e-03, 8.825e-03, 8.295e-03, 7.969e-03, 7.927e-03, 8.048e-03, 6.381e-03, 5.146e-03, 5.648e-03, 5.484e-03, 5.505e-03, 6.079e-03, 6.374e-03, 5.975e-03, 6.869e-03, 4.352e-03, 4.725e-03, 4.714e-03, 4.314e-03, 4.431e-03, 3.030e-03, 4.142e-03, 2.834e-03, 3.890e-03, 3.135e-03, 0.000e+00, 1.669e-03, 1.959e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WW_TuneCP5_13TeV-pythia8",{1.747e-01, 3.754e+00, 3.329e+00, 2.355e+00, 1.696e+00, 1.497e+00, 1.243e+00, 1.161e+00, 6.304e-01, 1.463e+00, 1.500e+00, 1.485e+00, 1.340e+00, 1.163e+00, 1.075e+00, 1.056e+00, 1.083e+00, 1.133e+00, 1.161e+00, 1.192e+00, 1.211e+00, 1.240e+00, 1.261e+00, 1.273e+00, 1.272e+00, 1.270e+00, 1.272e+00, 1.263e+00, 1.272e+00, 1.254e+00, 1.220e+00, 1.169e+00, 1.111e+00, 1.037e+00, 9.708e-01, 9.098e-01, 8.665e-01, 8.359e-01, 7.902e-01, 7.517e-01, 7.575e-01, 7.910e-01, 8.594e-01, 9.547e-01, 1.092e+00, 1.255e+00, 1.425e+00, 1.496e+00, 1.535e+00, 1.463e+00, 1.344e+00, 1.154e+00, 9.460e-01, 7.464e-01, 5.712e-01, 4.131e-01, 2.907e-01, 1.988e-01, 1.374e-01, 9.660e-02, 6.931e-02, 5.074e-02, 3.861e-02, 2.972e-02, 2.417e-02, 1.708e-02, 1.251e-02, 1.077e-02, 9.748e-03, 8.891e-03, 8.086e-03, 8.099e-03, 7.509e-03, 7.948e-03, 6.661e-03, 5.426e-03, 5.356e-03, 5.449e-03, 5.574e-03, 5.704e-03, 5.771e-03, 5.596e-03, 5.198e-03, 4.780e-03, 5.257e-03, 6.753e-03, 3.397e-03, 4.534e-03, 8.525e-03, 3.973e-03, 3.262e-03, 5.971e-03, 9.021e-04, 7.201e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WZ_TuneCP5_13TeV-pythia8",{2.885e-04, 9.426e-03, 3.709e-02, 6.739e-02, 9.283e-02, 1.810e-01, 1.933e-01, 2.232e-01, 1.095e-01, 4.127e-01, 4.222e-01, 6.463e-01, 7.086e-01, 7.589e-01, 7.401e-01, 7.535e-01, 8.487e-01, 1.014e+00, 1.090e+00, 1.144e+00, 1.238e+00, 1.270e+00, 1.304e+00, 1.329e+00, 1.353e+00, 1.354e+00, 1.340e+00, 1.366e+00, 1.392e+00, 1.375e+00, 1.305e+00, 1.262e+00, 1.203e+00, 1.138e+00, 1.076e+00, 1.014e+00, 9.526e-01, 9.096e-01, 8.524e-01, 8.366e-01, 8.149e-01, 8.498e-01, 9.367e-01, 1.070e+00, 1.217e+00, 1.370e+00, 1.555e+00, 1.651e+00, 1.661e+00, 1.619e+00, 1.441e+00, 1.254e+00, 1.031e+00, 7.733e-01, 6.002e-01, 4.269e-01, 3.139e-01, 2.145e-01, 1.491e-01, 1.047e-01, 7.117e-02, 5.268e-02, 3.779e-02, 2.871e-02, 2.464e-02, 1.834e-02, 1.201e-02, 1.115e-02, 7.759e-03, 8.828e-03, 4.914e-03, 4.979e-03, 4.248e-03, 8.633e-03, 3.551e-03, 1.225e-03, 8.479e-04, 5.544e-03, 2.923e-04, 2.167e-04, 4.406e-04, 9.199e-05, 1.197e-04, 2.637e-05, 4.199e-03, 3.283e-05, 2.446e-05, 3.924e-05, 2.652e-06, 1.347e-05, 3.182e-06, 2.517e-04, 6.085e-04, 5.464e-04, 2.159e-04, 9.482e-07, 3.683e-05, 1.271e-04, 2.586e-07, 2.874e-07, 0.000e+0}},
{"ZZ_TuneCP5_13TeV-pythia8",{2.034e-01, 4.570e+00, 3.455e+00, 2.433e+00, 2.113e+00, 1.497e+00, 1.226e+00, 1.242e+00, 6.374e-01, 1.528e+00, 1.536e+00, 1.507e+00, 1.329e+00, 1.159e+00, 1.065e+00, 1.041e+00, 1.082e+00, 1.144e+00, 1.158e+00, 1.193e+00, 1.211e+00, 1.235e+00, 1.258e+00, 1.277e+00, 1.272e+00, 1.264e+00, 1.269e+00, 1.273e+00, 1.269e+00, 1.264e+00, 1.223e+00, 1.173e+00, 1.104e+00, 1.033e+00, 9.748e-01, 9.112e-01, 8.653e-01, 8.366e-01, 7.900e-01, 7.484e-01, 7.577e-01, 7.925e-01, 8.630e-01, 9.599e-01, 1.088e+00, 1.262e+00, 1.443e+00, 1.488e+00, 1.536e+00, 1.452e+00, 1.325e+00, 1.154e+00, 9.670e-01, 7.471e-01, 5.738e-01, 4.083e-01, 2.878e-01, 1.975e-01, 1.365e-01, 9.673e-02, 6.975e-02, 5.090e-02, 3.868e-02, 3.004e-02, 2.368e-02, 1.673e-02, 1.234e-02, 1.077e-02, 9.694e-03, 8.566e-03, 8.172e-03, 7.909e-03, 7.901e-03, 7.859e-03, 6.528e-03, 5.654e-03, 5.522e-03, 6.173e-03, 6.403e-03, 7.198e-03, 7.156e-03, 5.899e-03, 3.712e-03, 4.030e-03, 2.445e-03, 6.280e-03, 8.004e-03, 1.687e-03, 3.171e-03, 3.941e-03, 1.213e-03, 1.481e-03, 8.949e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8",{1.803e-01, 3.458e+00, 3.320e+00, 2.672e+00, 1.673e+00, 1.617e+00, 1.216e+00, 1.254e+00, 5.875e-01, 1.508e+00, 1.485e+00, 1.469e+00, 1.337e+00, 1.158e+00, 1.083e+00, 1.052e+00, 1.077e+00, 1.128e+00, 1.165e+00, 1.185e+00, 1.215e+00, 1.238e+00, 1.267e+00, 1.269e+00, 1.272e+00, 1.267e+00, 1.272e+00, 1.268e+00, 1.274e+00, 1.250e+00, 1.219e+00, 1.169e+00, 1.112e+00, 1.039e+00, 9.677e-01, 9.125e-01, 8.686e-01, 8.354e-01, 7.882e-01, 7.527e-01, 7.564e-01, 7.919e-01, 8.570e-01, 9.614e-01, 1.101e+00, 1.253e+00, 1.426e+00, 1.490e+00, 1.537e+00, 1.467e+00, 1.327e+00, 1.145e+00, 9.504e-01, 7.503e-01, 5.704e-01, 4.090e-01, 2.908e-01, 1.991e-01, 1.382e-01, 9.642e-02, 6.952e-02, 5.087e-02, 3.848e-02, 2.981e-02, 2.406e-02, 1.711e-02, 1.247e-02, 1.064e-02, 9.808e-03, 8.913e-03, 8.170e-03, 8.021e-03, 8.009e-03, 7.519e-03, 6.414e-03, 5.711e-03, 5.312e-03, 5.423e-03, 5.859e-03, 5.321e-03, 5.620e-03, 5.984e-03, 6.974e-03, 4.543e-03, 4.534e-03, 7.841e-03, 4.640e-03, 2.737e-03, 3.677e-03, 7.996e-03, 1.641e-03, 0.000e+00, 1.816e-03, 7.246e-04, 0.000e+00, 7.564e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8",{1.814e-01, 4.869e+00, 3.328e+00, 2.649e+00, 1.539e+00, 1.459e+00, 1.240e+00, 1.245e+00, 6.164e-01, 1.457e+00, 1.487e+00, 1.486e+00, 1.338e+00, 1.172e+00, 1.080e+00, 1.049e+00, 1.083e+00, 1.127e+00, 1.162e+00, 1.192e+00, 1.214e+00, 1.236e+00, 1.264e+00, 1.269e+00, 1.270e+00, 1.271e+00, 1.270e+00, 1.267e+00, 1.275e+00, 1.251e+00, 1.224e+00, 1.169e+00, 1.110e+00, 1.040e+00, 9.670e-01, 9.113e-01, 8.653e-01, 8.359e-01, 7.899e-01, 7.515e-01, 7.573e-01, 7.931e-01, 8.636e-01, 9.604e-01, 1.094e+00, 1.256e+00, 1.421e+00, 1.503e+00, 1.522e+00, 1.462e+00, 1.344e+00, 1.151e+00, 9.522e-01, 7.464e-01, 5.692e-01, 4.098e-01, 2.902e-01, 1.990e-01, 1.377e-01, 9.661e-02, 6.950e-02, 5.084e-02, 3.821e-02, 3.001e-02, 2.393e-02, 1.717e-02, 1.241e-02, 1.069e-02, 9.439e-03, 8.829e-03, 8.278e-03, 7.919e-03, 8.173e-03, 8.321e-03, 6.351e-03, 5.280e-03, 5.702e-03, 5.654e-03, 5.687e-03, 6.971e-03, 6.876e-03, 7.289e-03, 5.101e-03, 4.640e-03, 4.187e-03, 4.087e-03, 5.009e-03, 4.116e-03, 4.300e-03, 1.781e-03, 3.290e-03, 6.023e-03, 9.100e-04, 2.179e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}}
};

    std::unordered_map<std::string, std::vector<float>> pileupweightsDn = { // 69.2 - 4.6%
{"DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8",{5.442e-04, 1.917e-01, 8.522e-02, 1.016e-01, 8.975e-02, 7.892e-02, 5.881e-02, 1.769e-01, 1.507e-01, 4.431e-01, 7.086e-01, 1.173e+00, 8.420e-01, 8.414e-01, 8.254e-01, 8.910e-01, 1.038e+00, 1.155e+00, 1.307e+00, 1.285e+00, 1.392e+00, 1.404e+00, 1.433e+00, 1.450e+00, 1.482e+00, 1.490e+00, 1.257e+00, 1.452e+00, 1.450e+00, 1.402e+00, 1.319e+00, 1.238e+00, 1.125e+00, 1.023e+00, 9.612e-01, 8.986e-01, 8.495e-01, 8.262e-01, 7.515e-01, 7.846e-01, 7.553e-01, 9.243e-01, 9.966e-01, 1.218e+00, 1.403e+00, 1.561e+00, 1.610e+00, 1.611e+00, 1.502e+00, 1.262e+00, 9.683e-01, 7.556e-01, 5.432e-01, 3.836e-01, 2.596e-01, 1.528e-01, 1.069e-01, 6.729e-02, 4.427e-02, 2.538e-02, 1.990e-02, 1.376e-02, 1.016e-02, 7.047e-03, 6.298e-03, 4.594e-03, 3.170e-03, 2.830e-03, 2.643e-03, 2.578e-03, 2.397e-03, 1.865e-03, 2.800e-04, 2.177e-03, 1.168e-04, 1.525e-03, 1.291e-03, 1.170e-03, 5.334e-05, 2.415e-05, 1.960e-03, 2.975e-04, 1.345e-03, 4.157e-04, 2.037e-03, 6.177e-04, 0.000e+00, 4.410e-04, 1.880e-06, 0.000e+00, 8.695e-05, 0.000e+00, 0.000e+00, 1.554e-05, 0.000e+00, 0.000e+00, 2.511e-06, 1.336e-06, 0.000e+00, 1.109e-08, 0.000e+0}},
{"DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8",{1.849e-01, 4.546e+00, 4.543e+00, 2.289e+00, 1.790e+00, 1.736e+00, 1.351e+00, 1.406e+00, 9.077e-01, 2.178e+00, 2.154e+00, 2.059e+00, 1.735e+00, 1.537e+00, 1.440e+00, 1.422e+00, 1.442e+00, 1.430e+00, 1.421e+00, 1.408e+00, 1.390e+00, 1.387e+00, 1.394e+00, 1.394e+00, 1.394e+00, 1.383e+00, 1.362e+00, 1.328e+00, 1.308e+00, 1.255e+00, 1.205e+00, 1.126e+00, 1.042e+00, 9.563e-01, 8.764e-01, 8.178e-01, 7.734e-01, 7.459e-01, 7.142e-01, 7.034e-01, 7.467e-01, 8.275e-01, 9.439e-01, 1.091e+00, 1.244e+00, 1.390e+00, 1.483e+00, 1.436e+00, 1.323e+00, 1.126e+00, 9.070e-01, 6.905e-01, 5.005e-01, 3.506e-01, 2.385e-01, 1.551e-01, 9.946e-02, 6.288e-02, 4.082e-02, 2.687e-02, 1.838e-02, 1.290e-02, 9.519e-03, 7.319e-03, 5.804e-03, 4.141e-03, 3.024e-03, 2.641e-03, 2.421e-03, 2.270e-03, 2.104e-03, 2.072e-03, 2.022e-03, 2.004e-03, 1.600e-03, 1.297e-03, 1.253e-03, 1.307e-03, 1.199e-03, 1.355e-03, 1.286e-03, 1.142e-03, 1.352e-03, 8.874e-04, 7.679e-04, 1.020e-03, 5.594e-04, 8.497e-04, 6.427e-04, 6.547e-04, 1.508e-03, 4.294e-04, 9.676e-05, 2.695e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8",{2.615e-01, 3.865e+00, 6.348e+00, 3.921e+00, 1.808e+00, 1.667e+00, 1.183e+00, 1.396e+00, 1.035e+00, 2.259e+00, 2.045e+00, 2.073e+00, 1.697e+00, 1.506e+00, 1.451e+00, 1.457e+00, 1.465e+00, 1.422e+00, 1.401e+00, 1.392e+00, 1.387e+00, 1.372e+00, 1.381e+00, 1.399e+00, 1.403e+00, 1.392e+00, 1.361e+00, 1.350e+00, 1.307e+00, 1.242e+00, 1.225e+00, 1.110e+00, 1.055e+00, 9.634e-01, 8.820e-01, 8.264e-01, 7.880e-01, 7.423e-01, 7.137e-01, 6.859e-01, 7.409e-01, 8.312e-01, 9.370e-01, 1.090e+00, 1.267e+00, 1.383e+00, 1.493e+00, 1.436e+00, 1.301e+00, 1.130e+00, 8.897e-01, 6.779e-01, 5.067e-01, 3.527e-01, 2.385e-01, 1.569e-01, 9.719e-02, 6.225e-02, 4.128e-02, 2.670e-02, 1.838e-02, 1.288e-02, 9.458e-03, 7.347e-03, 5.697e-03, 4.012e-03, 3.080e-03, 2.696e-03, 2.442e-03, 2.249e-03, 2.201e-03, 2.229e-03, 2.048e-03, 1.997e-03, 1.499e-03, 1.196e-03, 9.802e-04, 1.038e-03, 9.181e-04, 1.280e-03, 1.275e-03, 9.355e-04, 1.167e-03, 5.409e-04, 4.417e-04, 0.000e+00, 4.826e-04, 2.869e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8",{2.015e-01, 5.547e+00, 4.734e+00, 2.499e+00, 1.771e+00, 1.687e+00, 1.320e+00, 1.391e+00, 8.830e-01, 2.174e+00, 2.157e+00, 2.061e+00, 1.752e+00, 1.538e+00, 1.437e+00, 1.426e+00, 1.442e+00, 1.430e+00, 1.424e+00, 1.406e+00, 1.391e+00, 1.388e+00, 1.388e+00, 1.392e+00, 1.390e+00, 1.379e+00, 1.360e+00, 1.325e+00, 1.309e+00, 1.258e+00, 1.203e+00, 1.125e+00, 1.045e+00, 9.559e-01, 8.765e-01, 8.190e-01, 7.735e-01, 7.475e-01, 7.156e-01, 7.055e-01, 7.481e-01, 8.270e-01, 9.431e-01, 1.089e+00, 1.252e+00, 1.400e+00, 1.485e+00, 1.419e+00, 1.322e+00, 1.126e+00, 9.058e-01, 6.869e-01, 5.001e-01, 3.495e-01, 2.375e-01, 1.547e-01, 9.955e-02, 6.342e-02, 4.070e-02, 2.709e-02, 1.830e-02, 1.295e-02, 9.521e-03, 7.234e-03, 5.824e-03, 4.128e-03, 3.050e-03, 2.650e-03, 2.401e-03, 2.270e-03, 2.120e-03, 2.039e-03, 2.059e-03, 2.015e-03, 1.553e-03, 1.259e-03, 1.302e-03, 1.266e-03, 1.258e-03, 1.162e-03, 1.166e-03, 1.148e-03, 1.199e-03, 9.624e-04, 6.856e-04, 6.572e-04, 8.739e-04, 6.061e-04, 5.348e-04, 4.151e-04, 2.868e-04, 2.042e-04, 1.534e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8",{2.129e-01, 4.117e+00, 4.330e+00, 2.700e+00, 2.026e+00, 1.661e+00, 1.316e+00, 1.443e+00, 8.735e-01, 2.150e+00, 2.207e+00, 2.067e+00, 1.749e+00, 1.534e+00, 1.442e+00, 1.416e+00, 1.433e+00, 1.431e+00, 1.424e+00, 1.414e+00, 1.398e+00, 1.392e+00, 1.394e+00, 1.387e+00, 1.391e+00, 1.379e+00, 1.362e+00, 1.326e+00, 1.304e+00, 1.255e+00, 1.205e+00, 1.124e+00, 1.043e+00, 9.580e-01, 8.783e-01, 8.177e-01, 7.725e-01, 7.466e-01, 7.158e-01, 7.045e-01, 7.462e-01, 8.283e-01, 9.458e-01, 1.090e+00, 1.251e+00, 1.395e+00, 1.485e+00, 1.435e+00, 1.320e+00, 1.119e+00, 9.050e-01, 6.895e-01, 5.004e-01, 3.493e-01, 2.380e-01, 1.548e-01, 9.949e-02, 6.305e-02, 4.065e-02, 2.695e-02, 1.841e-02, 1.297e-02, 9.470e-03, 7.265e-03, 5.832e-03, 4.139e-03, 3.047e-03, 2.647e-03, 2.407e-03, 2.269e-03, 2.121e-03, 2.085e-03, 1.936e-03, 1.982e-03, 1.528e-03, 1.324e-03, 1.247e-03, 1.286e-03, 1.371e-03, 1.129e-03, 1.223e-03, 1.413e-03, 1.263e-03, 8.221e-04, 6.106e-04, 7.567e-04, 6.148e-04, 5.177e-04, 7.310e-04, 4.255e-04, 1.225e-03, 6.977e-04, 3.930e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8",{2.014e-01, 6.867e+00, 5.585e+00, 2.447e+00, 2.035e+00, 1.653e+00, 1.456e+00, 1.656e+00, 9.039e-01, 2.215e+00, 2.221e+00, 2.063e+00, 1.700e+00, 1.547e+00, 1.440e+00, 1.414e+00, 1.418e+00, 1.439e+00, 1.424e+00, 1.404e+00, 1.395e+00, 1.386e+00, 1.393e+00, 1.398e+00, 1.396e+00, 1.379e+00, 1.362e+00, 1.318e+00, 1.310e+00, 1.261e+00, 1.200e+00, 1.123e+00, 1.044e+00, 9.583e-01, 8.776e-01, 8.186e-01, 7.764e-01, 7.431e-01, 7.154e-01, 7.037e-01, 7.419e-01, 8.343e-01, 9.451e-01, 1.090e+00, 1.252e+00, 1.391e+00, 1.485e+00, 1.424e+00, 1.321e+00, 1.120e+00, 9.150e-01, 6.909e-01, 4.986e-01, 3.523e-01, 2.354e-01, 1.541e-01, 9.951e-02, 6.362e-02, 4.062e-02, 2.701e-02, 1.840e-02, 1.295e-02, 9.612e-03, 7.223e-03, 5.847e-03, 4.108e-03, 3.025e-03, 2.707e-03, 2.422e-03, 2.205e-03, 2.107e-03, 2.048e-03, 2.039e-03, 2.029e-03, 1.454e-03, 1.223e-03, 1.354e-03, 1.250e-03, 1.229e-03, 1.062e-03, 1.227e-03, 1.029e-03, 1.283e-03, 8.767e-04, 4.435e-04, 5.625e-04, 1.238e-03, 7.362e-04, 6.496e-04, 7.562e-04, 4.355e-04, 8.268e-05, 6.986e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT1000to1500_TuneCP5_13TeV-madgraph-pythia8",{2.047e-01, 4.445e+00, 4.178e+00, 2.495e+00, 1.855e+00, 1.660e+00, 1.368e+00, 1.440e+00, 8.912e-01, 2.230e+00, 2.181e+00, 2.066e+00, 1.744e+00, 1.530e+00, 1.444e+00, 1.418e+00, 1.435e+00, 1.434e+00, 1.422e+00, 1.406e+00, 1.393e+00, 1.389e+00, 1.390e+00, 1.395e+00, 1.390e+00, 1.375e+00, 1.362e+00, 1.330e+00, 1.307e+00, 1.258e+00, 1.203e+00, 1.123e+00, 1.044e+00, 9.555e-01, 8.772e-01, 8.168e-01, 7.737e-01, 7.470e-01, 7.161e-01, 7.045e-01, 7.466e-01, 8.278e-01, 9.446e-01, 1.092e+00, 1.251e+00, 1.394e+00, 1.486e+00, 1.442e+00, 1.321e+00, 1.128e+00, 9.060e-01, 6.908e-01, 5.000e-01, 3.499e-01, 2.385e-01, 1.549e-01, 9.973e-02, 6.280e-02, 4.075e-02, 2.693e-02, 1.833e-02, 1.291e-02, 9.491e-03, 7.256e-03, 5.796e-03, 4.117e-03, 3.050e-03, 2.660e-03, 2.397e-03, 2.220e-03, 2.128e-03, 2.024e-03, 1.974e-03, 1.958e-03, 1.565e-03, 1.305e-03, 1.271e-03, 1.201e-03, 1.321e-03, 1.156e-03, 1.207e-03, 1.173e-03, 1.108e-03, 7.862e-04, 7.191e-04, 6.219e-04, 7.202e-04, 5.449e-04, 5.877e-04, 4.561e-04, 2.955e-04, 6.731e-04, 1.517e-04, 4.225e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT1500to2000_TuneCP5_13TeV-madgraph-pythia8",{1.829e-01, 4.618e+00, 4.523e+00, 2.588e+00, 1.911e+00, 1.646e+00, 1.310e+00, 1.398e+00, 8.685e-01, 2.119e+00, 2.192e+00, 2.076e+00, 1.735e+00, 1.532e+00, 1.443e+00, 1.420e+00, 1.437e+00, 1.432e+00, 1.421e+00, 1.410e+00, 1.394e+00, 1.392e+00, 1.385e+00, 1.393e+00, 1.394e+00, 1.383e+00, 1.362e+00, 1.330e+00, 1.312e+00, 1.256e+00, 1.202e+00, 1.126e+00, 1.044e+00, 9.529e-01, 8.787e-01, 8.160e-01, 7.746e-01, 7.455e-01, 7.141e-01, 7.043e-01, 7.484e-01, 8.263e-01, 9.432e-01, 1.088e+00, 1.250e+00, 1.393e+00, 1.479e+00, 1.433e+00, 1.319e+00, 1.129e+00, 9.066e-01, 6.883e-01, 5.019e-01, 3.495e-01, 2.380e-01, 1.553e-01, 9.900e-02, 6.291e-02, 4.064e-02, 2.701e-02, 1.834e-02, 1.293e-02, 9.552e-03, 7.268e-03, 5.805e-03, 4.131e-03, 3.057e-03, 2.669e-03, 2.411e-03, 2.259e-03, 2.084e-03, 2.082e-03, 1.997e-03, 1.948e-03, 1.537e-03, 1.267e-03, 1.310e-03, 1.370e-03, 1.330e-03, 1.285e-03, 1.230e-03, 1.288e-03, 1.141e-03, 6.818e-04, 8.836e-04, 7.682e-04, 5.126e-04, 7.479e-04, 5.377e-04, 3.521e-04, 4.055e-04, 3.079e-04, 5.204e-04, 2.899e-04, 7.985e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT2000toInf_TuneCP5_13TeV-madgraph-pythia8",{1.750e-01, 4.429e+00, 4.725e+00, 2.462e+00, 1.740e+00, 1.666e+00, 1.353e+00, 1.390e+00, 8.748e-01, 2.167e+00, 2.192e+00, 2.071e+00, 1.754e+00, 1.546e+00, 1.449e+00, 1.421e+00, 1.437e+00, 1.433e+00, 1.428e+00, 1.399e+00, 1.385e+00, 1.386e+00, 1.391e+00, 1.395e+00, 1.390e+00, 1.382e+00, 1.361e+00, 1.329e+00, 1.312e+00, 1.256e+00, 1.198e+00, 1.119e+00, 1.042e+00, 9.544e-01, 8.772e-01, 8.207e-01, 7.713e-01, 7.479e-01, 7.153e-01, 7.050e-01, 7.503e-01, 8.277e-01, 9.443e-01, 1.095e+00, 1.250e+00, 1.392e+00, 1.487e+00, 1.450e+00, 1.327e+00, 1.120e+00, 9.107e-01, 6.889e-01, 4.985e-01, 3.520e-01, 2.368e-01, 1.542e-01, 9.906e-02, 6.327e-02, 4.071e-02, 2.683e-02, 1.830e-02, 1.298e-02, 9.548e-03, 7.284e-03, 5.854e-03, 4.086e-03, 3.046e-03, 2.670e-03, 2.459e-03, 2.202e-03, 2.128e-03, 2.124e-03, 1.953e-03, 1.979e-03, 1.489e-03, 1.234e-03, 1.313e-03, 1.240e-03, 1.447e-03, 1.141e-03, 1.136e-03, 1.148e-03, 9.771e-04, 8.053e-04, 5.495e-04, 7.291e-04, 1.001e-03, 1.388e-03, 3.062e-04, 3.565e-04, 2.737e-04, 4.676e-04, 1.317e-04, 4.892e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT200to300_TuneCP5_13TeV-madgraph-pythia8",{1.893e-01, 4.428e+00, 4.831e+00, 2.464e+00, 1.884e+00, 1.731e+00, 1.326e+00, 1.400e+00, 8.941e-01, 2.168e+00, 2.181e+00, 2.069e+00, 1.748e+00, 1.537e+00, 1.442e+00, 1.425e+00, 1.435e+00, 1.434e+00, 1.424e+00, 1.408e+00, 1.394e+00, 1.390e+00, 1.392e+00, 1.393e+00, 1.392e+00, 1.381e+00, 1.360e+00, 1.328e+00, 1.307e+00, 1.258e+00, 1.204e+00, 1.126e+00, 1.043e+00, 9.545e-01, 8.763e-01, 8.170e-01, 7.725e-01, 7.465e-01, 7.171e-01, 7.035e-01, 7.463e-01, 8.272e-01, 9.445e-01, 1.091e+00, 1.248e+00, 1.392e+00, 1.484e+00, 1.434e+00, 1.320e+00, 1.124e+00, 9.090e-01, 6.888e-01, 5.021e-01, 3.506e-01, 2.380e-01, 1.542e-01, 9.967e-02, 6.297e-02, 4.072e-02, 2.689e-02, 1.838e-02, 1.293e-02, 9.511e-03, 7.280e-03, 5.806e-03, 4.118e-03, 3.047e-03, 2.647e-03, 2.410e-03, 2.229e-03, 2.109e-03, 2.047e-03, 2.009e-03, 1.979e-03, 1.586e-03, 1.296e-03, 1.284e-03, 1.253e-03, 1.270e-03, 1.323e-03, 1.202e-03, 1.096e-03, 1.189e-03, 8.501e-04, 6.587e-04, 6.754e-04, 6.053e-04, 6.779e-04, 6.551e-04, 5.523e-04, 5.764e-04, 3.090e-04, 1.741e-04, 5.495e-04, 9.080e-04, 8.242e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT300to500_TuneCP5_13TeV-madgraph-pythia8",{1.942e-01, 4.477e+00, 4.756e+00, 2.445e+00, 1.824e+00, 1.670e+00, 1.351e+00, 1.434e+00, 8.940e-01, 2.165e+00, 2.194e+00, 2.061e+00, 1.737e+00, 1.536e+00, 1.436e+00, 1.425e+00, 1.435e+00, 1.433e+00, 1.424e+00, 1.406e+00, 1.393e+00, 1.390e+00, 1.393e+00, 1.392e+00, 1.391e+00, 1.380e+00, 1.362e+00, 1.329e+00, 1.309e+00, 1.257e+00, 1.201e+00, 1.125e+00, 1.043e+00, 9.541e-01, 8.764e-01, 8.174e-01, 7.735e-01, 7.463e-01, 7.162e-01, 7.046e-01, 7.463e-01, 8.264e-01, 9.456e-01, 1.092e+00, 1.247e+00, 1.395e+00, 1.485e+00, 1.433e+00, 1.321e+00, 1.124e+00, 9.072e-01, 6.883e-01, 5.021e-01, 3.505e-01, 2.378e-01, 1.548e-01, 9.974e-02, 6.302e-02, 4.066e-02, 2.694e-02, 1.839e-02, 1.297e-02, 9.510e-03, 7.288e-03, 5.802e-03, 4.133e-03, 3.043e-03, 2.647e-03, 2.404e-03, 2.231e-03, 2.108e-03, 2.068e-03, 2.005e-03, 1.980e-03, 1.531e-03, 1.295e-03, 1.289e-03, 1.281e-03, 1.245e-03, 1.229e-03, 1.254e-03, 1.227e-03, 1.110e-03, 8.441e-04, 6.810e-04, 6.541e-04, 5.677e-04, 6.857e-04, 5.294e-04, 4.771e-04, 2.747e-04, 3.032e-04, 1.608e-04, 1.903e-04, 8.386e-04, 2.284e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT500to700_TuneCP5_13TeV-madgraph-pythia8",{1.918e-01, 4.239e+00, 4.483e+00, 2.480e+00, 1.854e+00, 1.692e+00, 1.379e+00, 1.441e+00, 8.941e-01, 2.161e+00, 2.208e+00, 2.072e+00, 1.746e+00, 1.535e+00, 1.440e+00, 1.419e+00, 1.432e+00, 1.434e+00, 1.428e+00, 1.407e+00, 1.393e+00, 1.387e+00, 1.390e+00, 1.393e+00, 1.395e+00, 1.383e+00, 1.361e+00, 1.329e+00, 1.309e+00, 1.256e+00, 1.201e+00, 1.126e+00, 1.041e+00, 9.551e-01, 8.774e-01, 8.169e-01, 7.739e-01, 7.461e-01, 7.151e-01, 7.037e-01, 7.467e-01, 8.262e-01, 9.456e-01, 1.091e+00, 1.251e+00, 1.395e+00, 1.480e+00, 1.435e+00, 1.325e+00, 1.123e+00, 9.082e-01, 6.897e-01, 5.010e-01, 3.501e-01, 2.378e-01, 1.548e-01, 9.977e-02, 6.294e-02, 4.068e-02, 2.685e-02, 1.835e-02, 1.296e-02, 9.501e-03, 7.286e-03, 5.804e-03, 4.125e-03, 3.039e-03, 2.665e-03, 2.404e-03, 2.226e-03, 2.132e-03, 2.058e-03, 2.003e-03, 1.985e-03, 1.571e-03, 1.283e-03, 1.291e-03, 1.281e-03, 1.270e-03, 1.285e-03, 1.246e-03, 1.200e-03, 1.111e-03, 8.939e-04, 6.538e-04, 6.927e-04, 5.760e-04, 6.069e-04, 4.532e-04, 4.425e-04, 3.590e-04, 3.749e-04, 2.304e-04, 1.569e-04, 3.888e-04, 2.118e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT700to1000_TuneCP5_13TeV-madgraph-pythia8",{1.966e-01, 4.224e+00, 4.203e+00, 2.372e+00, 1.893e+00, 1.666e+00, 1.360e+00, 1.390e+00, 8.999e-01, 2.170e+00, 2.194e+00, 2.073e+00, 1.738e+00, 1.535e+00, 1.442e+00, 1.423e+00, 1.431e+00, 1.436e+00, 1.425e+00, 1.409e+00, 1.393e+00, 1.393e+00, 1.389e+00, 1.392e+00, 1.389e+00, 1.381e+00, 1.363e+00, 1.329e+00, 1.308e+00, 1.255e+00, 1.201e+00, 1.125e+00, 1.043e+00, 9.549e-01, 8.776e-01, 8.168e-01, 7.737e-01, 7.485e-01, 7.156e-01, 7.031e-01, 7.461e-01, 8.273e-01, 9.468e-01, 1.090e+00, 1.252e+00, 1.391e+00, 1.486e+00, 1.435e+00, 1.322e+00, 1.124e+00, 9.096e-01, 6.901e-01, 5.010e-01, 3.497e-01, 2.375e-01, 1.548e-01, 9.942e-02, 6.312e-02, 4.066e-02, 2.684e-02, 1.838e-02, 1.298e-02, 9.500e-03, 7.280e-03, 5.790e-03, 4.127e-03, 3.032e-03, 2.641e-03, 2.419e-03, 2.232e-03, 2.133e-03, 2.063e-03, 2.021e-03, 1.935e-03, 1.542e-03, 1.270e-03, 1.280e-03, 1.279e-03, 1.263e-03, 1.269e-03, 1.216e-03, 1.157e-03, 1.256e-03, 8.823e-04, 6.637e-04, 6.671e-04, 5.291e-04, 5.953e-04, 5.943e-04, 4.077e-04, 2.629e-04, 2.880e-04, 1.406e-04, 9.791e-05, 2.157e-04, 1.175e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia",{1.886e-01, 6.561e+00, 3.592e+00, 2.338e+00, 1.837e+00, 1.607e+00, 1.395e+00, 1.378e+00, 8.878e-01, 2.156e+00, 2.312e+00, 2.054e+00, 1.756e+00, 1.538e+00, 1.444e+00, 1.424e+00, 1.449e+00, 1.434e+00, 1.422e+00, 1.405e+00, 1.399e+00, 1.383e+00, 1.386e+00, 1.388e+00, 1.397e+00, 1.382e+00, 1.362e+00, 1.329e+00, 1.304e+00, 1.253e+00, 1.203e+00, 1.124e+00, 1.047e+00, 9.556e-01, 8.779e-01, 8.150e-01, 7.719e-01, 7.478e-01, 7.130e-01, 7.041e-01, 7.459e-01, 8.284e-01, 9.457e-01, 1.094e+00, 1.250e+00, 1.394e+00, 1.484e+00, 1.449e+00, 1.314e+00, 1.122e+00, 9.105e-01, 6.921e-01, 4.975e-01, 3.487e-01, 2.371e-01, 1.547e-01, 1.002e-01, 6.301e-02, 4.078e-02, 2.688e-02, 1.836e-02, 1.313e-02, 9.521e-03, 7.269e-03, 5.773e-03, 4.099e-03, 3.007e-03, 2.591e-03, 2.423e-03, 2.218e-03, 2.096e-03, 2.127e-03, 2.019e-03, 1.952e-03, 1.503e-03, 1.382e-03, 1.285e-03, 1.362e-03, 1.409e-03, 1.113e-03, 1.459e-03, 1.007e-03, 1.717e-03, 7.579e-04, 1.083e-03, 5.912e-04, 7.100e-04, 5.276e-04, 6.207e-04, 1.806e-04, 4.161e-04, 1.185e-04, 1.335e-04, 7.437e-05, 0.000e+00, 2.231e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia",{1.827e-01, 4.239e+00, 4.641e+00, 2.323e+00, 1.844e+00, 1.739e+00, 1.380e+00, 1.413e+00, 8.784e-01, 2.175e+00, 2.196e+00, 2.049e+00, 1.728e+00, 1.525e+00, 1.442e+00, 1.424e+00, 1.439e+00, 1.425e+00, 1.431e+00, 1.411e+00, 1.390e+00, 1.388e+00, 1.391e+00, 1.395e+00, 1.391e+00, 1.377e+00, 1.362e+00, 1.331e+00, 1.304e+00, 1.257e+00, 1.202e+00, 1.126e+00, 1.044e+00, 9.607e-01, 8.777e-01, 8.180e-01, 7.735e-01, 7.484e-01, 7.144e-01, 7.056e-01, 7.449e-01, 8.301e-01, 9.445e-01, 1.085e+00, 1.247e+00, 1.396e+00, 1.489e+00, 1.427e+00, 1.315e+00, 1.125e+00, 9.113e-01, 6.905e-01, 4.975e-01, 3.530e-01, 2.382e-01, 1.540e-01, 9.892e-02, 6.298e-02, 4.062e-02, 2.670e-02, 1.835e-02, 1.291e-02, 9.459e-03, 7.347e-03, 5.813e-03, 4.126e-03, 3.059e-03, 2.672e-03, 2.425e-03, 2.216e-03, 2.167e-03, 2.078e-03, 2.058e-03, 1.998e-03, 1.530e-03, 1.301e-03, 1.376e-03, 1.242e-03, 1.133e-03, 1.197e-03, 1.369e-03, 1.252e-03, 1.337e-03, 1.093e-03, 7.851e-04, 6.575e-04, 5.183e-04, 7.042e-04, 4.833e-04, 3.376e-04, 9.719e-04, 2.768e-04, 3.118e-04, 8.686e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.937e-01, 4.285e+00, 4.608e+00, 2.469e+00, 1.844e+00, 1.705e+00, 1.365e+00, 1.423e+00, 8.858e-01, 2.176e+00, 2.193e+00, 2.060e+00, 1.747e+00, 1.538e+00, 1.440e+00, 1.420e+00, 1.430e+00, 1.433e+00, 1.426e+00, 1.409e+00, 1.393e+00, 1.389e+00, 1.392e+00, 1.394e+00, 1.392e+00, 1.381e+00, 1.360e+00, 1.329e+00, 1.311e+00, 1.258e+00, 1.201e+00, 1.125e+00, 1.042e+00, 9.546e-01, 8.770e-01, 8.178e-01, 7.731e-01, 7.461e-01, 7.151e-01, 7.038e-01, 7.467e-01, 8.259e-01, 9.447e-01, 1.090e+00, 1.251e+00, 1.393e+00, 1.483e+00, 1.436e+00, 1.322e+00, 1.126e+00, 9.080e-01, 6.916e-01, 5.002e-01, 3.495e-01, 2.377e-01, 1.547e-01, 9.960e-02, 6.302e-02, 4.066e-02, 2.687e-02, 1.834e-02, 1.295e-02, 9.497e-03, 7.302e-03, 5.810e-03, 4.134e-03, 3.040e-03, 2.661e-03, 2.414e-03, 2.228e-03, 2.119e-03, 2.062e-03, 1.998e-03, 2.004e-03, 1.543e-03, 1.298e-03, 1.277e-03, 1.294e-03, 1.246e-03, 1.235e-03, 1.250e-03, 1.196e-03, 1.144e-03, 7.888e-04, 6.446e-04, 7.375e-04, 6.236e-04, 6.096e-04, 5.344e-04, 4.533e-04, 3.045e-04, 3.061e-04, 1.832e-04, 1.814e-04, 8.995e-04, 6.998e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_t-channel_top_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.909e-01, 4.326e+00, 4.404e+00, 2.438e+00, 1.895e+00, 1.683e+00, 1.341e+00, 1.409e+00, 8.969e-01, 2.174e+00, 2.197e+00, 2.069e+00, 1.746e+00, 1.538e+00, 1.441e+00, 1.422e+00, 1.434e+00, 1.433e+00, 1.424e+00, 1.407e+00, 1.395e+00, 1.389e+00, 1.392e+00, 1.393e+00, 1.392e+00, 1.381e+00, 1.361e+00, 1.329e+00, 1.308e+00, 1.257e+00, 1.201e+00, 1.126e+00, 1.042e+00, 9.550e-01, 8.772e-01, 8.172e-01, 7.734e-01, 7.465e-01, 7.162e-01, 7.039e-01, 7.466e-01, 8.262e-01, 9.452e-01, 1.088e+00, 1.248e+00, 1.393e+00, 1.483e+00, 1.436e+00, 1.323e+00, 1.124e+00, 9.072e-01, 6.888e-01, 5.006e-01, 3.507e-01, 2.378e-01, 1.549e-01, 9.968e-02, 6.299e-02, 4.072e-02, 2.689e-02, 1.835e-02, 1.296e-02, 9.511e-03, 7.295e-03, 5.823e-03, 4.136e-03, 3.040e-03, 2.658e-03, 2.399e-03, 2.226e-03, 2.114e-03, 2.062e-03, 1.989e-03, 1.971e-03, 1.567e-03, 1.281e-03, 1.294e-03, 1.268e-03, 1.266e-03, 1.265e-03, 1.228e-03, 1.236e-03, 1.225e-03, 8.103e-04, 7.079e-04, 7.266e-04, 5.923e-04, 6.088e-04, 5.056e-04, 5.458e-04, 3.032e-04, 3.077e-04, 1.585e-04, 1.626e-04, 5.673e-04, 1.324e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_tW_antitop_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",{2.012e-01, 4.270e+00, 4.304e+00, 2.322e+00, 1.945e+00, 1.748e+00, 1.387e+00, 1.395e+00, 8.704e-01, 2.155e+00, 2.203e+00, 2.069e+00, 1.735e+00, 1.544e+00, 1.441e+00, 1.422e+00, 1.431e+00, 1.432e+00, 1.431e+00, 1.407e+00, 1.395e+00, 1.389e+00, 1.386e+00, 1.393e+00, 1.394e+00, 1.381e+00, 1.361e+00, 1.330e+00, 1.305e+00, 1.260e+00, 1.203e+00, 1.122e+00, 1.043e+00, 9.561e-01, 8.762e-01, 8.183e-01, 7.723e-01, 7.469e-01, 7.162e-01, 7.035e-01, 7.495e-01, 8.273e-01, 9.446e-01, 1.092e+00, 1.243e+00, 1.398e+00, 1.478e+00, 1.437e+00, 1.318e+00, 1.123e+00, 9.013e-01, 6.919e-01, 4.988e-01, 3.498e-01, 2.386e-01, 1.555e-01, 9.940e-02, 6.298e-02, 4.051e-02, 2.688e-02, 1.840e-02, 1.299e-02, 9.542e-03, 7.331e-03, 5.774e-03, 4.136e-03, 3.049e-03, 2.662e-03, 2.399e-03, 2.217e-03, 2.111e-03, 2.008e-03, 1.993e-03, 2.045e-03, 1.560e-03, 1.330e-03, 1.280e-03, 1.325e-03, 1.202e-03, 1.260e-03, 1.275e-03, 1.265e-03, 1.219e-03, 1.011e-03, 7.049e-04, 6.413e-04, 5.437e-04, 9.157e-04, 5.387e-04, 3.135e-04, 2.708e-04, 6.170e-04, 1.159e-04, 1.936e-04, 0.000e+00, 2.904e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.784e-01, 4.467e+00, 5.307e+00, 2.718e+00, 1.922e+00, 1.680e+00, 1.297e+00, 1.359e+00, 8.826e-01, 2.168e+00, 2.130e+00, 2.054e+00, 1.745e+00, 1.543e+00, 1.432e+00, 1.422e+00, 1.435e+00, 1.428e+00, 1.431e+00, 1.414e+00, 1.396e+00, 1.383e+00, 1.395e+00, 1.392e+00, 1.392e+00, 1.385e+00, 1.362e+00, 1.328e+00, 1.307e+00, 1.254e+00, 1.201e+00, 1.123e+00, 1.038e+00, 9.542e-01, 8.759e-01, 8.162e-01, 7.741e-01, 7.464e-01, 7.186e-01, 7.044e-01, 7.464e-01, 8.286e-01, 9.407e-01, 1.091e+00, 1.254e+00, 1.394e+00, 1.486e+00, 1.427e+00, 1.315e+00, 1.126e+00, 9.108e-01, 6.908e-01, 5.002e-01, 3.500e-01, 2.379e-01, 1.554e-01, 9.973e-02, 6.290e-02, 4.081e-02, 2.681e-02, 1.843e-02, 1.292e-02, 9.491e-03, 7.328e-03, 5.827e-03, 4.150e-03, 3.050e-03, 2.700e-03, 2.409e-03, 2.243e-03, 2.097e-03, 2.045e-03, 1.985e-03, 1.983e-03, 1.588e-03, 1.294e-03, 1.354e-03, 1.242e-03, 1.304e-03, 1.202e-03, 1.318e-03, 1.149e-03, 9.169e-04, 8.020e-04, 9.641e-04, 8.771e-04, 6.772e-04, 7.045e-04, 4.144e-04, 3.860e-04, 1.852e-04, 6.329e-04, 8.913e-05, 1.986e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTHH_TuneCP5_13TeV-madgraph-pythia8",{1.251e-04, 5.760e-01, 5.256e-01, 2.782e-01, 2.495e-01, 1.758e-01, 1.539e-01, 1.507e-01, 1.011e-01, 5.734e-01, 7.558e-01, 7.460e-01, 9.463e-01, 4.749e-01, 1.004e+00, 9.904e-01, 1.042e+00, 1.208e+00, 1.061e+00, 1.421e+00, 1.423e+00, 1.469e+00, 1.537e+00, 1.580e+00, 1.571e+00, 1.487e+00, 1.520e+00, 1.473e+00, 1.458e+00, 1.392e+00, 1.326e+00, 1.239e+00, 1.185e+00, 1.061e+00, 1.009e+00, 9.272e-01, 8.889e-01, 8.338e-01, 7.985e-01, 7.797e-01, 8.695e-01, 9.365e-01, 1.062e+00, 1.197e+00, 1.409e+00, 1.552e+00, 1.681e+00, 1.649e+00, 1.483e+00, 1.291e+00, 9.837e-01, 7.490e-01, 5.545e-01, 4.032e-01, 2.750e-01, 1.784e-01, 1.123e-01, 7.269e-02, 4.541e-02, 2.936e-02, 2.099e-02, 1.490e-02, 8.686e-03, 7.830e-03, 6.111e-03, 4.949e-03, 3.322e-03, 2.865e-03, 2.698e-03, 2.580e-03, 2.187e-03, 2.321e-03, 2.561e-03, 2.142e-03, 1.873e-03, 1.263e-03, 1.547e-03, 1.135e-03, 2.736e-03, 3.496e-03, 1.108e-03, 9.294e-04, 1.739e-03, 3.583e-04, 0.000e+00, 3.992e-04, 2.397e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 4.057e-07, 0.000e+00, 0.000e+00, 8.444e-09, 0.000e+0}},
{"TTTJ_TuneCP5_13TeV-madgraph-pythia8",{1.438e-01, 0.000e+00, 6.281e+00, 2.494e+00, 3.726e+00, 1.959e+00, 1.532e+00, 1.220e+00, 9.144e-01, 2.157e+00, 2.183e+00, 1.977e+00, 1.594e+00, 1.521e+00, 1.472e+00, 1.412e+00, 1.459e+00, 1.459e+00, 1.440e+00, 1.438e+00, 1.396e+00, 1.375e+00, 1.386e+00, 1.402e+00, 1.366e+00, 1.371e+00, 1.349e+00, 1.320e+00, 1.311e+00, 1.262e+00, 1.204e+00, 1.127e+00, 1.042e+00, 9.448e-01, 8.680e-01, 8.123e-01, 7.671e-01, 7.567e-01, 7.307e-01, 7.087e-01, 7.618e-01, 8.291e-01, 9.637e-01, 1.069e+00, 1.287e+00, 1.347e+00, 1.481e+00, 1.450e+00, 1.316e+00, 1.105e+00, 9.209e-01, 6.998e-01, 4.989e-01, 3.403e-01, 2.313e-01, 1.553e-01, 9.649e-02, 6.488e-02, 4.017e-02, 2.684e-02, 1.918e-02, 1.303e-02, 9.731e-03, 6.971e-03, 5.879e-03, 4.060e-03, 3.235e-03, 2.624e-03, 2.458e-03, 2.025e-03, 2.069e-03, 2.089e-03, 2.198e-03, 2.407e-03, 1.368e-03, 1.184e-03, 1.247e-03, 1.304e-03, 9.910e-04, 8.704e-04, 1.104e-03, 0.000e+00, 1.732e-03, 3.568e-04, 0.000e+00, 0.000e+00, 2.388e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTTT_TuneCP5_13TeV-amcatnlo-pythia8",{1.573e-01, 2.490e+00, 3.817e+00, 2.210e+00, 2.123e+00, 1.024e+00, 8.216e-01, 9.194e-01, 1.351e+00, 2.000e+00, 1.891e+00, 2.270e+00, 1.672e+00, 1.468e+00, 1.430e+00, 1.422e+00, 1.414e+00, 1.475e+00, 1.488e+00, 1.387e+00, 1.432e+00, 1.332e+00, 1.362e+00, 1.370e+00, 1.410e+00, 1.339e+00, 1.368e+00, 1.338e+00, 1.281e+00, 1.279e+00, 1.167e+00, 1.121e+00, 1.028e+00, 9.681e-01, 8.901e-01, 8.363e-01, 7.997e-01, 7.582e-01, 6.984e-01, 6.988e-01, 7.284e-01, 8.203e-01, 9.542e-01, 1.086e+00, 1.256e+00, 1.471e+00, 1.512e+00, 1.440e+00, 1.395e+00, 1.143e+00, 8.980e-01, 6.901e-01, 5.010e-01, 3.665e-01, 2.256e-01, 1.534e-01, 1.043e-01, 6.284e-02, 4.232e-02, 2.745e-02, 1.746e-02, 1.259e-02, 9.379e-03, 7.603e-03, 5.690e-03, 4.074e-03, 2.923e-03, 2.438e-03, 2.344e-03, 2.204e-03, 2.100e-03, 1.936e-03, 1.650e-03, 1.509e-03, 1.386e-03, 1.798e-03, 1.137e-03, 1.392e-03, 1.743e-03, 5.289e-03, 1.032e-03, 6.027e-04, 7.517e-04, 8.131e-04, 3.984e-04, 0.000e+00, 1.814e-04, -1.078e-04, 0.000e+00, 0.000e+00, 0.000e+00, -4.843e-05, 0.000e+00, -7.599e-06, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTTW_TuneCP5_13TeV-madgraph-pythia8",{1.905e-03, 5.245e-01, 7.432e-01, 2.621e-01, 2.709e-01, 2.205e-01, 1.893e-01, 2.001e-01, 1.333e-01, 2.948e-01, 8.352e-01, 8.506e-01, 8.946e-01, 1.317e+00, 1.400e+00, 1.377e+00, 1.402e+00, 1.215e+00, 1.299e+00, 1.299e+00, 1.298e+00, 1.318e+00, 1.376e+00, 1.407e+00, 1.399e+00, 1.422e+00, 1.409e+00, 1.332e+00, 1.348e+00, 1.325e+00, 1.238e+00, 1.180e+00, 1.043e+00, 9.976e-01, 9.392e-01, 8.775e-01, 7.714e-01, 8.024e-01, 7.652e-01, 7.632e-01, 8.102e-01, 8.902e-01, 1.003e+00, 1.205e+00, 1.314e+00, 1.511e+00, 1.600e+00, 1.606e+00, 1.456e+00, 1.217e+00, 9.474e-01, 7.386e-01, 4.325e-01, 3.729e-01, 2.611e-01, 1.682e-01, 1.053e-01, 5.149e-02, 4.383e-02, 2.900e-02, 1.921e-02, 1.401e-02, 1.031e-02, 7.654e-03, 5.949e-03, 4.535e-03, 3.226e-03, 2.911e-03, 2.404e-03, 2.484e-03, 2.312e-03, 2.081e-03, 2.711e-03, 1.574e-03, 1.474e-03, 1.499e-03, 1.386e-03, 1.420e-03, 7.831e-04, 6.287e-06, 1.480e-03, 2.793e-03, 1.742e-03, 3.589e-04, 6.593e-04, 3.999e-04, 6.003e-05, 2.419e-07, 8.397e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 8.127e-07, 0.000e+00, 0.000e+00, 2.368e-08, 0.000e+0}},
{"TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.870e-01, 4.337e+00, 4.470e+00, 2.473e+00, 1.891e+00, 1.726e+00, 1.350e+00, 1.395e+00, 8.887e-01, 2.177e+00, 2.175e+00, 2.077e+00, 1.744e+00, 1.544e+00, 1.439e+00, 1.423e+00, 1.436e+00, 1.431e+00, 1.423e+00, 1.409e+00, 1.393e+00, 1.389e+00, 1.392e+00, 1.392e+00, 1.390e+00, 1.382e+00, 1.361e+00, 1.329e+00, 1.308e+00, 1.256e+00, 1.202e+00, 1.126e+00, 1.043e+00, 9.555e-01, 8.765e-01, 8.173e-01, 7.730e-01, 7.475e-01, 7.158e-01, 7.034e-01, 7.481e-01, 8.260e-01, 9.445e-01, 1.090e+00, 1.249e+00, 1.396e+00, 1.486e+00, 1.435e+00, 1.324e+00, 1.123e+00, 9.082e-01, 6.907e-01, 4.996e-01, 3.504e-01, 2.379e-01, 1.550e-01, 9.952e-02, 6.304e-02, 4.067e-02, 2.685e-02, 1.837e-02, 1.293e-02, 9.508e-03, 7.300e-03, 5.792e-03, 4.121e-03, 3.035e-03, 2.660e-03, 2.418e-03, 2.237e-03, 2.121e-03, 2.075e-03, 1.954e-03, 1.968e-03, 1.536e-03, 1.290e-03, 1.290e-03, 1.241e-03, 1.232e-03, 1.222e-03, 1.202e-03, 1.248e-03, 1.088e-03, 8.040e-04, 6.508e-04, 6.766e-04, 5.611e-04, 5.837e-04, 5.060e-04, 4.197e-04, 3.581e-04, 3.239e-04, 2.068e-04, 1.920e-04, 4.759e-04, 1.728e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.950e-01, 4.059e+00, 4.401e+00, 2.445e+00, 1.859e+00, 1.687e+00, 1.337e+00, 1.427e+00, 8.903e-01, 2.160e+00, 2.175e+00, 2.066e+00, 1.746e+00, 1.539e+00, 1.437e+00, 1.424e+00, 1.433e+00, 1.433e+00, 1.422e+00, 1.407e+00, 1.394e+00, 1.389e+00, 1.392e+00, 1.394e+00, 1.391e+00, 1.381e+00, 1.361e+00, 1.329e+00, 1.308e+00, 1.256e+00, 1.202e+00, 1.125e+00, 1.043e+00, 9.551e-01, 8.766e-01, 8.166e-01, 7.735e-01, 7.479e-01, 7.163e-01, 7.032e-01, 7.475e-01, 8.276e-01, 9.443e-01, 1.089e+00, 1.248e+00, 1.393e+00, 1.482e+00, 1.434e+00, 1.324e+00, 1.124e+00, 9.073e-01, 6.900e-01, 5.012e-01, 3.503e-01, 2.378e-01, 1.548e-01, 9.962e-02, 6.299e-02, 4.064e-02, 2.692e-02, 1.838e-02, 1.298e-02, 9.520e-03, 7.286e-03, 5.810e-03, 4.125e-03, 3.045e-03, 2.665e-03, 2.405e-03, 2.241e-03, 2.112e-03, 2.054e-03, 1.986e-03, 1.979e-03, 1.558e-03, 1.294e-03, 1.283e-03, 1.240e-03, 1.278e-03, 1.224e-03, 1.221e-03, 1.222e-03, 1.160e-03, 8.335e-04, 7.010e-04, 7.044e-04, 5.880e-04, 6.031e-04, 5.220e-04, 4.861e-04, 3.955e-04, 3.986e-04, 1.883e-04, 1.712e-04, 5.971e-04, 1.951e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTToSemiLepton_HT500Njet9_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.895e-01, 3.831e+00, 4.195e+00, 2.451e+00, 2.066e+00, 1.687e+00, 1.374e+00, 1.398e+00, 8.974e-01, 2.196e+00, 2.201e+00, 2.075e+00, 1.727e+00, 1.531e+00, 1.435e+00, 1.415e+00, 1.433e+00, 1.435e+00, 1.428e+00, 1.408e+00, 1.396e+00, 1.389e+00, 1.390e+00, 1.398e+00, 1.392e+00, 1.384e+00, 1.362e+00, 1.326e+00, 1.311e+00, 1.258e+00, 1.200e+00, 1.125e+00, 1.042e+00, 9.555e-01, 8.732e-01, 8.184e-01, 7.726e-01, 7.477e-01, 7.145e-01, 7.056e-01, 7.492e-01, 8.272e-01, 9.460e-01, 1.089e+00, 1.252e+00, 1.388e+00, 1.485e+00, 1.436e+00, 1.321e+00, 1.125e+00, 9.091e-01, 6.889e-01, 4.987e-01, 3.500e-01, 2.378e-01, 1.544e-01, 9.984e-02, 6.290e-02, 4.057e-02, 2.688e-02, 1.829e-02, 1.294e-02, 9.484e-03, 7.247e-03, 5.852e-03, 4.065e-03, 3.059e-03, 2.678e-03, 2.413e-03, 2.223e-03, 2.142e-03, 2.030e-03, 1.962e-03, 2.024e-03, 1.552e-03, 1.339e-03, 1.319e-03, 1.281e-03, 1.207e-03, 1.346e-03, 1.194e-03, 1.330e-03, 1.388e-03, 8.579e-04, 6.421e-04, 5.477e-04, 1.052e-03, 5.687e-04, 1.227e-03, 3.060e-04, 3.084e-04, 0.000e+00, 4.397e-05, 1.102e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.885e-01, 4.226e+00, 4.554e+00, 2.475e+00, 1.896e+00, 1.697e+00, 1.336e+00, 1.397e+00, 8.874e-01, 2.165e+00, 2.186e+00, 2.067e+00, 1.748e+00, 1.540e+00, 1.439e+00, 1.423e+00, 1.433e+00, 1.433e+00, 1.425e+00, 1.408e+00, 1.393e+00, 1.389e+00, 1.391e+00, 1.393e+00, 1.392e+00, 1.382e+00, 1.361e+00, 1.330e+00, 1.309e+00, 1.257e+00, 1.201e+00, 1.125e+00, 1.044e+00, 9.542e-01, 8.772e-01, 8.165e-01, 7.732e-01, 7.466e-01, 7.155e-01, 7.042e-01, 7.463e-01, 8.271e-01, 9.429e-01, 1.089e+00, 1.250e+00, 1.394e+00, 1.484e+00, 1.436e+00, 1.323e+00, 1.123e+00, 9.069e-01, 6.897e-01, 5.004e-01, 3.501e-01, 2.378e-01, 1.549e-01, 9.976e-02, 6.303e-02, 4.067e-02, 2.693e-02, 1.835e-02, 1.299e-02, 9.509e-03, 7.294e-03, 5.808e-03, 4.118e-03, 3.039e-03, 2.659e-03, 2.417e-03, 2.242e-03, 2.120e-03, 2.049e-03, 2.009e-03, 1.968e-03, 1.546e-03, 1.272e-03, 1.265e-03, 1.220e-03, 1.282e-03, 1.237e-03, 1.225e-03, 1.244e-03, 1.172e-03, 8.465e-04, 6.915e-04, 7.164e-04, 5.537e-04, 6.667e-04, 6.286e-04, 5.342e-04, 3.751e-04, 4.867e-04, 1.592e-04, 1.617e-04, 3.786e-04, 2.749e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTWH_TuneCP5_13TeV-madgraph-pythia8",{2.671e-04, 3.342e-02, 5.474e-02, 2.868e-01, 2.490e-01, 2.040e-01, 1.581e-01, 1.638e-01, 1.062e-01, 2.731e-01, 8.390e-01, 1.055e+00, 9.666e-01, 8.276e-01, 8.032e-01, 5.275e-01, 1.047e+00, 1.360e+00, 1.433e+00, 1.456e+00, 1.413e+00, 1.339e+00, 1.444e+00, 1.448e+00, 1.486e+00, 1.537e+00, 1.534e+00, 1.436e+00, 1.500e+00, 1.431e+00, 1.330e+00, 1.239e+00, 1.168e+00, 1.064e+00, 9.688e-01, 9.196e-01, 8.662e-01, 8.051e-01, 8.150e-01, 7.862e-01, 8.155e-01, 9.051e-01, 1.106e+00, 1.221e+00, 1.440e+00, 1.534e+00, 1.611e+00, 1.562e+00, 1.445e+00, 1.243e+00, 9.372e-01, 7.025e-01, 3.200e-01, 3.757e-01, 2.542e-01, 1.625e-01, 1.093e-01, 6.953e-02, 4.395e-02, 2.885e-02, 1.977e-02, 1.349e-02, 1.079e-02, 7.656e-03, 6.038e-03, 4.270e-03, 3.220e-03, 2.833e-03, 2.519e-03, 1.228e-03, 2.086e-03, 2.199e-03, 1.023e-03, 5.633e-04, 2.128e-03, 1.034e-03, 7.952e-04, 5.857e-04, 1.214e-03, 3.489e-03, 2.212e-03, 2.783e-03, 8.678e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 8.367e-05, 0.000e+00, 0.000e+00, 0.000e+00, 8.998e-06, 0.000e+00, 0.000e+00, 0.000e+00, 4.049e-07, 4.311e-07, 2.268e-07, 1.311e-08, 0.000e+0}},
{"TTWJetsToLNu_TuneCP5_PSweights_13TeV-amcatnloFXFX-madspin-pythia8",{2.031e-01, 3.047e+00, 3.856e+00, 2.538e+00, 1.643e+00, 1.659e+00, 1.467e+00, 1.320e+00, 9.143e-01, 2.194e+00, 2.266e+00, 2.033e+00, 1.771e+00, 1.520e+00, 1.442e+00, 1.440e+00, 1.447e+00, 1.429e+00, 1.430e+00, 1.398e+00, 1.396e+00, 1.390e+00, 1.384e+00, 1.383e+00, 1.394e+00, 1.380e+00, 1.375e+00, 1.326e+00, 1.313e+00, 1.268e+00, 1.205e+00, 1.117e+00, 1.044e+00, 9.606e-01, 8.740e-01, 8.123e-01, 7.709e-01, 7.412e-01, 7.125e-01, 7.007e-01, 7.506e-01, 8.236e-01, 9.460e-01, 1.099e+00, 1.252e+00, 1.384e+00, 1.477e+00, 1.434e+00, 1.320e+00, 1.119e+00, 9.096e-01, 6.837e-01, 4.975e-01, 3.471e-01, 2.370e-01, 1.554e-01, 1.001e-01, 6.346e-02, 4.185e-02, 2.691e-02, 1.843e-02, 1.280e-02, 9.662e-03, 7.430e-03, 5.706e-03, 4.096e-03, 3.084e-03, 2.683e-03, 2.415e-03, 2.269e-03, 2.093e-03, 1.925e-03, 1.895e-03, 1.887e-03, 1.642e-03, 1.407e-03, 1.320e-03, 1.120e-03, 1.214e-03, 2.004e-03, 9.836e-04, 1.421e-03, 1.139e-03, 1.848e-03, 1.132e-03, 6.102e-04, 4.711e-04, 9.801e-04, 3.844e-04, 1.678e-04, -3.865e-04, 0.000e+00, 0.000e+00, 3.454e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8",{1.251e-01, 4.253e+00, 3.492e+00, 2.043e+00, 1.604e+00, 1.884e+00, 1.037e+00, 1.313e+00, 9.244e-01, 2.366e+00, 2.117e+00, 2.126e+00, 1.867e+00, 1.542e+00, 1.503e+00, 1.417e+00, 1.427e+00, 1.431e+00, 1.460e+00, 1.385e+00, 1.389e+00, 1.399e+00, 1.395e+00, 1.393e+00, 1.412e+00, 1.391e+00, 1.361e+00, 1.332e+00, 1.311e+00, 1.260e+00, 1.188e+00, 1.130e+00, 1.054e+00, 9.543e-01, 8.923e-01, 8.015e-01, 7.676e-01, 7.641e-01, 7.249e-01, 6.891e-01, 7.425e-01, 8.105e-01, 9.428e-01, 1.061e+00, 1.253e+00, 1.403e+00, 1.508e+00, 1.425e+00, 1.334e+00, 1.121e+00, 8.885e-01, 6.830e-01, 5.140e-01, 3.482e-01, 2.328e-01, 1.493e-01, 9.857e-02, 6.193e-02, 4.124e-02, 2.697e-02, 1.897e-02, 1.327e-02, 9.227e-03, 7.136e-03, 6.207e-03, 4.300e-03, 3.053e-03, 2.754e-03, 2.110e-03, 2.073e-03, 1.878e-03, 1.941e-03, 2.063e-03, 2.346e-03, 1.191e-03, 1.178e-03, 1.324e-03, 1.142e-03, 1.154e-03, 8.150e-04, 9.818e-04, 8.822e-04, 9.628e-04, 2.381e-03, 4.859e-04, 4.421e-04, 5.310e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTWW_TuneCP5_13TeV-madgraph-pythia8",{7.356e-04, 6.389e-01, 8.394e-01, 4.729e-01, 2.801e-01, 2.417e-01, 3.886e-01, 4.766e-01, 3.224e-01, 8.697e-01, 8.827e-01, 8.187e-01, 7.538e-01, 7.170e-01, 9.072e-01, 1.027e+00, 1.212e+00, 1.311e+00, 1.403e+00, 1.320e+00, 1.366e+00, 1.376e+00, 1.411e+00, 1.367e+00, 1.503e+00, 1.480e+00, 1.478e+00, 1.482e+00, 1.413e+00, 1.379e+00, 1.213e+00, 1.253e+00, 1.129e+00, 1.058e+00, 9.632e-01, 9.203e-01, 8.383e-01, 8.306e-01, 7.804e-01, 7.535e-01, 8.225e-01, 9.036e-01, 1.047e+00, 1.184e+00, 1.351e+00, 1.218e+00, 1.653e+00, 1.578e+00, 1.491e+00, 1.218e+00, 9.032e-01, 6.766e-01, 5.027e-01, 3.541e-01, 2.483e-01, 9.517e-02, 1.017e-01, 6.473e-02, 4.231e-02, 2.787e-02, 1.888e-02, 1.354e-02, 1.011e-02, 7.635e-03, 6.273e-03, 4.453e-03, 3.436e-03, 2.731e-03, 1.430e-03, 2.428e-03, 2.212e-03, 2.094e-03, 2.983e-03, 2.295e-03, 1.505e-03, 1.441e-03, 9.721e-04, 1.307e-03, 7.804e-04, 1.427e-05, 1.475e-03, 9.278e-04, 8.679e-04, 3.541e-06, 2.190e-04, 4.655e-07, 0.000e+00, 1.423e-04, 0.000e+00, 1.331e-07, 0.000e+00, 1.598e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 1.475e-08, 0.000e+0}},
{"TTWZ_TuneCP5_13TeV-madgraph-pythia8",{2.368e-03, 3.022e-01, 2.620e-01, 1.697e-01, 6.395e-01, 5.410e-01, 4.412e-01, 3.899e-01, 3.303e-01, 7.198e-01, 7.629e-01, 6.853e-01, 5.942e-01, 9.435e-01, 1.038e+00, 1.280e+00, 1.326e+00, 1.404e+00, 1.396e+00, 1.365e+00, 1.435e+00, 1.431e+00, 1.381e+00, 1.441e+00, 1.467e+00, 1.401e+00, 1.391e+00, 1.387e+00, 1.382e+00, 1.311e+00, 1.258e+00, 1.141e+00, 1.073e+00, 9.892e-01, 9.331e-01, 8.859e-01, 8.100e-01, 7.967e-01, 7.482e-01, 7.493e-01, 7.884e-01, 8.494e-01, 1.010e+00, 1.126e+00, 1.212e+00, 1.506e+00, 1.637e+00, 1.541e+00, 1.390e+00, 1.099e+00, 9.551e-01, 5.990e-01, 5.229e-01, 3.648e-01, 2.484e-01, 1.578e-01, 1.022e-01, 3.832e-02, 4.188e-02, 2.707e-02, 1.906e-02, 1.301e-02, 9.247e-03, 7.603e-03, 6.107e-03, 4.206e-03, 3.032e-03, 2.703e-03, 2.476e-03, 2.232e-03, 2.317e-03, 2.289e-03, 2.014e-03, 1.807e-03, 1.433e-03, 1.151e-03, 1.380e-03, 1.212e-03, 1.364e-03, 1.162e-03, 8.839e-04, 1.390e-03, 0.000e+00, 2.679e-04, 3.281e-04, 1.990e-04, 0.000e+00, 7.175e-07, 8.358e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 1.618e-07, 2.153e-07, 0.000e+00, 1.684e-08, 0.000e+0}},
{"TTZH_TuneCP5_13TeV-madgraph-pythia8",{2.409e-03, 1.919e+00, 1.801e+00, 1.031e+00, 8.015e-01, 1.049e+00, 8.499e-01, 8.749e-01, 4.980e-01, 1.752e+00, 1.714e+00, 1.791e+00, 1.354e+00, 1.262e+00, 1.199e+00, 1.165e+00, 1.182e+00, 1.214e+00, 1.216e+00, 1.277e+00, 1.295e+00, 1.260e+00, 1.332e+00, 1.339e+00, 1.437e+00, 1.402e+00, 1.346e+00, 1.342e+00, 1.397e+00, 1.333e+00, 1.202e+00, 1.175e+00, 1.094e+00, 1.026e+00, 9.439e-01, 8.486e-01, 8.195e-01, 8.004e-01, 7.682e-01, 7.525e-01, 8.215e-01, 8.752e-01, 1.011e+00, 8.753e-01, 1.350e+00, 1.567e+00, 1.603e+00, 1.550e+00, 1.427e+00, 1.219e+00, 9.499e-01, 4.644e-01, 5.221e-01, 3.593e-01, 2.549e-01, 1.617e-01, 1.020e-01, 6.699e-02, 4.198e-02, 2.875e-02, 1.941e-02, 1.306e-02, 9.827e-03, 8.009e-03, 5.952e-03, 4.170e-03, 3.510e-03, 2.704e-03, 2.624e-03, 2.278e-03, 2.425e-03, 1.848e-03, 2.048e-03, 2.141e-03, 1.545e-03, 1.554e-03, 1.252e-03, 1.215e-03, 1.368e-03, 1.747e-03, 8.672e-06, 6.968e-04, 8.691e-04, 3.581e-04, 3.290e-04, 0.000e+00, 0.000e+00, 1.424e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 8.110e-07, 1.439e-07, 0.000e+00, 1.688e-08, 0.000e+0}},
{"TTZToLLNuNu_M-10_TuneCP5_PSweights_13TeV-amcatnlo-pythia8",{1.997e-01, 3.784e+00, 4.362e+00, 2.258e+00, 1.804e+00, 1.983e+00, 1.367e+00, 1.400e+00, 9.395e-01, 2.191e+00, 2.173e+00, 2.065e+00, 1.718e+00, 1.550e+00, 1.435e+00, 1.426e+00, 1.445e+00, 1.437e+00, 1.420e+00, 1.411e+00, 1.397e+00, 1.397e+00, 1.391e+00, 1.403e+00, 1.393e+00, 1.387e+00, 1.357e+00, 1.332e+00, 1.302e+00, 1.259e+00, 1.204e+00, 1.128e+00, 1.041e+00, 9.517e-01, 8.769e-01, 8.171e-01, 7.745e-01, 7.495e-01, 7.114e-01, 6.997e-01, 7.466e-01, 8.277e-01, 9.401e-01, 1.092e+00, 1.259e+00, 1.392e+00, 1.480e+00, 1.435e+00, 1.316e+00, 1.120e+00, 8.938e-01, 6.857e-01, 4.982e-01, 3.483e-01, 2.379e-01, 1.554e-01, 9.930e-02, 6.293e-02, 4.058e-02, 2.670e-02, 1.834e-02, 1.316e-02, 9.518e-03, 7.353e-03, 5.821e-03, 4.125e-03, 3.031e-03, 2.742e-03, 2.429e-03, 2.225e-03, 2.067e-03, 2.071e-03, 1.998e-03, 1.901e-03, 1.636e-03, 1.283e-03, 1.455e-03, 1.278e-03, 1.376e-03, 1.303e-03, 1.574e-03, 1.078e-03, 1.235e-03, 7.243e-04, 5.580e-04, 8.071e-04, 7.001e-04, 4.161e-04, 5.508e-04, 3.206e-04, 1.477e-04, 0.000e+00, 2.369e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTZZ_TuneCP5_13TeV-madgraph-pythia8",{2.123e-04, 3.388e-01, 2.138e-01, 1.437e-01, 1.111e-01, 1.809e-01, 2.485e-01, 3.676e-01, 2.882e-01, 7.089e-01, 8.338e-01, 7.520e-01, 7.579e-01, 1.291e+00, 1.175e+00, 8.262e-01, 1.222e+00, 1.205e+00, 1.143e+00, 1.230e+00, 1.319e+00, 1.390e+00, 1.305e+00, 1.460e+00, 1.450e+00, 1.434e+00, 1.387e+00, 1.371e+00, 1.444e+00, 1.391e+00, 1.370e+00, 1.252e+00, 1.178e+00, 1.074e+00, 9.918e-01, 9.355e-01, 8.835e-01, 6.386e-01, 8.027e-01, 8.032e-01, 8.288e-01, 9.525e-01, 1.099e+00, 1.018e+00, 1.419e+00, 1.550e+00, 1.753e+00, 1.688e+00, 1.535e+00, 1.314e+00, 7.303e-01, 7.831e-01, 5.692e-01, 3.889e-01, 2.587e-01, 1.686e-01, 1.060e-01, 7.208e-02, 4.521e-02, 2.952e-02, 2.079e-02, 1.422e-02, 1.058e-02, 8.012e-03, 6.494e-03, 4.541e-03, 2.566e-03, 2.878e-03, 2.540e-03, 2.567e-03, 1.978e-03, 2.296e-03, 2.313e-03, 1.746e-03, 1.374e-03, 1.122e-03, 1.461e-03, 1.309e-03, 8.420e-04, 7.769e-04, 1.478e-03, 1.394e-03, 1.739e-03, 3.583e-04, 3.291e-04, 2.661e-05, 2.397e-04, 1.425e-04, 0.000e+00, 0.000e+00, 0.000e+00, 1.600e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 4.057e-07, 0.000e+00, 0.000e+00, 1.970e-08, 0.000e+0}},
{"WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8",{1.965e-01, 5.202e+00, 4.177e+00, 2.313e+00, 2.084e+00, 1.658e+00, 1.385e+00, 1.358e+00, 8.829e-01, 2.226e+00, 2.219e+00, 2.058e+00, 1.727e+00, 1.532e+00, 1.436e+00, 1.417e+00, 1.433e+00, 1.436e+00, 1.423e+00, 1.408e+00, 1.393e+00, 1.387e+00, 1.390e+00, 1.393e+00, 1.391e+00, 1.382e+00, 1.362e+00, 1.331e+00, 1.310e+00, 1.258e+00, 1.200e+00, 1.124e+00, 1.043e+00, 9.556e-01, 8.772e-01, 8.185e-01, 7.725e-01, 7.491e-01, 7.175e-01, 7.042e-01, 7.470e-01, 8.261e-01, 9.421e-01, 1.089e+00, 1.247e+00, 1.394e+00, 1.484e+00, 1.434e+00, 1.321e+00, 1.124e+00, 9.079e-01, 6.900e-01, 5.002e-01, 3.499e-01, 2.381e-01, 1.548e-01, 9.972e-02, 6.322e-02, 4.067e-02, 2.690e-02, 1.829e-02, 1.293e-02, 9.505e-03, 7.294e-03, 5.818e-03, 4.106e-03, 3.032e-03, 2.647e-03, 2.414e-03, 2.240e-03, 2.128e-03, 2.074e-03, 1.968e-03, 1.989e-03, 1.550e-03, 1.276e-03, 1.285e-03, 1.303e-03, 1.273e-03, 1.311e-03, 1.335e-03, 1.226e-03, 1.200e-03, 7.738e-04, 5.542e-04, 5.666e-04, 6.437e-04, 8.328e-04, 4.383e-04, 2.308e-04, 3.988e-04, 5.300e-04, 2.985e-04, 9.979e-05, 0.000e+00, 1.497e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8",{2.002e-01, 4.710e+00, 4.499e+00, 2.398e+00, 1.891e+00, 1.709e+00, 1.344e+00, 1.424e+00, 8.680e-01, 2.147e+00, 2.161e+00, 2.054e+00, 1.741e+00, 1.539e+00, 1.446e+00, 1.420e+00, 1.430e+00, 1.431e+00, 1.425e+00, 1.407e+00, 1.392e+00, 1.390e+00, 1.387e+00, 1.393e+00, 1.393e+00, 1.384e+00, 1.361e+00, 1.330e+00, 1.307e+00, 1.260e+00, 1.200e+00, 1.123e+00, 1.046e+00, 9.542e-01, 8.771e-01, 8.183e-01, 7.745e-01, 7.458e-01, 7.144e-01, 7.048e-01, 7.459e-01, 8.286e-01, 9.442e-01, 1.086e+00, 1.251e+00, 1.395e+00, 1.485e+00, 1.432e+00, 1.327e+00, 1.123e+00, 9.097e-01, 6.906e-01, 5.014e-01, 3.506e-01, 2.376e-01, 1.545e-01, 9.954e-02, 6.282e-02, 4.064e-02, 2.691e-02, 1.840e-02, 1.294e-02, 9.575e-03, 7.267e-03, 5.819e-03, 4.135e-03, 3.046e-03, 2.656e-03, 2.380e-03, 2.224e-03, 2.111e-03, 2.064e-03, 2.000e-03, 1.955e-03, 1.555e-03, 1.309e-03, 1.291e-03, 1.245e-03, 1.340e-03, 1.191e-03, 1.250e-03, 1.411e-03, 1.302e-03, 7.324e-04, 6.793e-04, 8.161e-04, 5.201e-04, 8.416e-04, 3.713e-04, 3.990e-04, 3.733e-04, 5.671e-04, 1.917e-04, 1.068e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8",{1.980e-01, 4.550e+00, 4.265e+00, 2.562e+00, 1.861e+00, 1.661e+00, 1.342e+00, 1.392e+00, 9.020e-01, 2.140e+00, 2.172e+00, 2.063e+00, 1.752e+00, 1.533e+00, 1.435e+00, 1.418e+00, 1.433e+00, 1.435e+00, 1.427e+00, 1.407e+00, 1.394e+00, 1.390e+00, 1.394e+00, 1.394e+00, 1.392e+00, 1.378e+00, 1.363e+00, 1.329e+00, 1.309e+00, 1.256e+00, 1.201e+00, 1.126e+00, 1.043e+00, 9.545e-01, 8.770e-01, 8.185e-01, 7.750e-01, 7.473e-01, 7.148e-01, 7.015e-01, 7.485e-01, 8.262e-01, 9.442e-01, 1.092e+00, 1.244e+00, 1.393e+00, 1.480e+00, 1.435e+00, 1.321e+00, 1.123e+00, 9.089e-01, 6.890e-01, 4.999e-01, 3.502e-01, 2.381e-01, 1.547e-01, 9.950e-02, 6.297e-02, 4.061e-02, 2.695e-02, 1.839e-02, 1.292e-02, 9.498e-03, 7.314e-03, 5.797e-03, 4.151e-03, 3.056e-03, 2.686e-03, 2.386e-03, 2.245e-03, 2.140e-03, 2.049e-03, 2.018e-03, 1.977e-03, 1.516e-03, 1.296e-03, 1.286e-03, 1.318e-03, 1.239e-03, 1.330e-03, 1.278e-03, 1.149e-03, 1.192e-03, 8.689e-04, 7.022e-04, 7.122e-04, 7.296e-04, 7.022e-04, 4.566e-04, 1.262e-03, 5.815e-04, 4.140e-04, 3.110e-04, 1.732e-04, 2.863e-04, 5.197e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8",{1.986e-01, 4.375e+00, 5.060e+00, 2.591e+00, 1.895e+00, 1.654e+00, 1.359e+00, 1.438e+00, 8.861e-01, 2.134e+00, 2.192e+00, 2.063e+00, 1.736e+00, 1.535e+00, 1.441e+00, 1.420e+00, 1.425e+00, 1.430e+00, 1.422e+00, 1.405e+00, 1.393e+00, 1.389e+00, 1.392e+00, 1.391e+00, 1.394e+00, 1.383e+00, 1.360e+00, 1.332e+00, 1.311e+00, 1.257e+00, 1.203e+00, 1.127e+00, 1.043e+00, 9.544e-01, 8.780e-01, 8.169e-01, 7.720e-01, 7.469e-01, 7.172e-01, 7.032e-01, 7.456e-01, 8.258e-01, 9.443e-01, 1.087e+00, 1.250e+00, 1.397e+00, 1.483e+00, 1.436e+00, 1.326e+00, 1.127e+00, 9.090e-01, 6.912e-01, 5.013e-01, 3.505e-01, 2.376e-01, 1.548e-01, 9.950e-02, 6.260e-02, 4.080e-02, 2.692e-02, 1.843e-02, 1.297e-02, 9.502e-03, 7.208e-03, 5.828e-03, 4.103e-03, 3.041e-03, 2.666e-03, 2.390e-03, 2.226e-03, 2.114e-03, 2.063e-03, 1.996e-03, 1.985e-03, 1.530e-03, 1.306e-03, 1.297e-03, 1.208e-03, 1.239e-03, 1.261e-03, 1.164e-03, 1.260e-03, 1.099e-03, 7.831e-04, 7.705e-04, 9.502e-04, 4.755e-04, 6.359e-04, 3.325e-04, 6.968e-04, 5.016e-04, 3.809e-04, 6.437e-04, 1.195e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8",{1.987e-01, 3.922e+00, 4.598e+00, 2.554e+00, 1.823e+00, 1.668e+00, 1.352e+00, 1.445e+00, 8.901e-01, 2.212e+00, 2.157e+00, 2.058e+00, 1.733e+00, 1.536e+00, 1.433e+00, 1.423e+00, 1.433e+00, 1.440e+00, 1.424e+00, 1.404e+00, 1.397e+00, 1.389e+00, 1.393e+00, 1.394e+00, 1.392e+00, 1.384e+00, 1.357e+00, 1.328e+00, 1.308e+00, 1.259e+00, 1.203e+00, 1.126e+00, 1.042e+00, 9.533e-01, 8.766e-01, 8.162e-01, 7.737e-01, 7.465e-01, 7.170e-01, 7.055e-01, 7.443e-01, 8.287e-01, 9.437e-01, 1.089e+00, 1.249e+00, 1.389e+00, 1.484e+00, 1.434e+00, 1.326e+00, 1.123e+00, 9.064e-01, 6.894e-01, 5.019e-01, 3.517e-01, 2.378e-01, 1.551e-01, 9.978e-02, 6.294e-02, 4.066e-02, 2.680e-02, 1.833e-02, 1.295e-02, 9.515e-03, 7.253e-03, 5.793e-03, 4.122e-03, 3.027e-03, 2.681e-03, 2.420e-03, 2.222e-03, 2.121e-03, 2.049e-03, 1.953e-03, 1.991e-03, 1.584e-03, 1.278e-03, 1.288e-03, 1.207e-03, 1.267e-03, 1.181e-03, 1.156e-03, 1.198e-03, 1.326e-03, 8.619e-04, 6.537e-04, 7.858e-04, 6.330e-04, 4.821e-04, 4.776e-04, 4.402e-04, 4.345e-04, 2.166e-04, 1.952e-04, 1.359e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8",{1.790e-01, 3.978e+00, 4.040e+00, 2.514e+00, 1.832e+00, 1.607e+00, 1.352e+00, 1.403e+00, 8.819e-01, 2.153e+00, 2.194e+00, 2.047e+00, 1.743e+00, 1.534e+00, 1.435e+00, 1.424e+00, 1.433e+00, 1.432e+00, 1.425e+00, 1.409e+00, 1.393e+00, 1.391e+00, 1.392e+00, 1.393e+00, 1.395e+00, 1.385e+00, 1.361e+00, 1.328e+00, 1.308e+00, 1.255e+00, 1.202e+00, 1.125e+00, 1.040e+00, 9.554e-01, 8.775e-01, 8.183e-01, 7.740e-01, 7.468e-01, 7.166e-01, 7.038e-01, 7.472e-01, 8.257e-01, 9.436e-01, 1.090e+00, 1.246e+00, 1.397e+00, 1.481e+00, 1.429e+00, 1.321e+00, 1.124e+00, 9.056e-01, 6.905e-01, 4.991e-01, 3.498e-01, 2.376e-01, 1.552e-01, 9.979e-02, 6.298e-02, 4.089e-02, 2.684e-02, 1.836e-02, 1.300e-02, 9.542e-03, 7.253e-03, 5.813e-03, 4.117e-03, 3.043e-03, 2.657e-03, 2.420e-03, 2.238e-03, 2.120e-03, 2.040e-03, 2.018e-03, 2.023e-03, 1.573e-03, 1.238e-03, 1.319e-03, 1.238e-03, 1.196e-03, 1.268e-03, 1.271e-03, 1.137e-03, 1.243e-03, 7.474e-04, 7.681e-04, 7.238e-04, 6.241e-04, 6.028e-04, 3.869e-04, 4.954e-04, 3.170e-04, 4.062e-04, 3.051e-04, 0.000e+00, 1.404e-04, 1.530e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WW_TuneCP5_13TeV-pythia8",{1.827e-01, 4.155e+00, 4.348e+00, 2.276e+00, 1.956e+00, 1.670e+00, 1.297e+00, 1.302e+00, 9.124e-01, 2.178e+00, 2.194e+00, 2.067e+00, 1.753e+00, 1.531e+00, 1.434e+00, 1.426e+00, 1.436e+00, 1.439e+00, 1.418e+00, 1.411e+00, 1.392e+00, 1.391e+00, 1.393e+00, 1.395e+00, 1.392e+00, 1.379e+00, 1.362e+00, 1.326e+00, 1.306e+00, 1.259e+00, 1.199e+00, 1.124e+00, 1.044e+00, 9.542e-01, 8.789e-01, 8.155e-01, 7.731e-01, 7.479e-01, 7.177e-01, 7.049e-01, 7.457e-01, 8.246e-01, 9.442e-01, 1.085e+00, 1.245e+00, 1.392e+00, 1.488e+00, 1.435e+00, 1.327e+00, 1.125e+00, 9.117e-01, 6.896e-01, 4.983e-01, 3.486e-01, 2.384e-01, 1.556e-01, 9.993e-02, 6.303e-02, 4.062e-02, 2.692e-02, 1.838e-02, 1.294e-02, 9.562e-03, 7.224e-03, 5.827e-03, 4.125e-03, 3.048e-03, 2.660e-03, 2.442e-03, 2.255e-03, 2.067e-03, 2.073e-03, 1.911e-03, 1.998e-03, 1.643e-03, 1.305e-03, 1.251e-03, 1.230e-03, 1.211e-03, 1.189e-03, 1.151e-03, 1.065e-03, 9.408e-04, 8.209e-04, 8.546e-04, 1.037e-03, 4.915e-04, 6.168e-04, 1.089e-03, 4.752e-04, 3.648e-04, 6.234e-04, 8.779e-05, 6.521e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WZ_TuneCP5_13TeV-pythia8",{3.018e-04, 1.043e-02, 4.845e-02, 6.513e-02, 1.071e-01, 2.019e-01, 2.017e-01, 2.501e-01, 1.584e-01, 6.145e-01, 6.177e-01, 8.993e-01, 9.275e-01, 9.992e-01, 9.877e-01, 1.018e+00, 1.126e+00, 1.289e+00, 1.331e+00, 1.355e+00, 1.423e+00, 1.425e+00, 1.440e+00, 1.457e+00, 1.480e+00, 1.471e+00, 1.434e+00, 1.434e+00, 1.429e+00, 1.381e+00, 1.283e+00, 1.213e+00, 1.131e+00, 1.047e+00, 9.739e-01, 9.086e-01, 8.499e-01, 8.138e-01, 7.742e-01, 7.845e-01, 8.022e-01, 8.859e-01, 1.029e+00, 1.216e+00, 1.389e+00, 1.519e+00, 1.625e+00, 1.584e+00, 1.436e+00, 1.245e+00, 9.776e-01, 7.491e-01, 5.429e-01, 3.611e-01, 2.505e-01, 1.608e-01, 1.079e-01, 6.801e-02, 4.409e-02, 2.918e-02, 1.887e-02, 1.343e-02, 9.357e-03, 6.979e-03, 5.942e-03, 4.430e-03, 2.926e-03, 2.752e-03, 1.944e-03, 2.239e-03, 1.256e-03, 1.275e-03, 1.081e-03, 2.170e-03, 8.758e-04, 2.946e-04, 1.980e-04, 1.251e-03, 6.351e-05, 4.519e-05, 8.788e-05, 1.750e-05, 2.166e-05, 4.529e-06, 6.827e-04, 5.040e-06, 3.539e-06, 5.339e-06, 3.386e-07, 1.611e-06, 3.558e-07, 2.628e-05, 5.922e-05, 4.948e-05, 1.817e-05, 7.404e-08, 2.665e-06, 8.511e-06, 1.599e-08, 1.641e-08, 0.000e+0}},
{"ZZ_TuneCP5_13TeV-pythia8",{2.127e-01, 5.059e+00, 4.513e+00, 2.352e+00, 2.437e+00, 1.670e+00, 1.279e+00, 1.393e+00, 9.226e-01, 2.276e+00, 2.247e+00, 2.097e+00, 1.739e+00, 1.526e+00, 1.422e+00, 1.405e+00, 1.435e+00, 1.454e+00, 1.415e+00, 1.413e+00, 1.392e+00, 1.385e+00, 1.389e+00, 1.400e+00, 1.391e+00, 1.373e+00, 1.358e+00, 1.336e+00, 1.303e+00, 1.270e+00, 1.203e+00, 1.128e+00, 1.038e+00, 9.504e-01, 8.825e-01, 8.167e-01, 7.721e-01, 7.485e-01, 7.175e-01, 7.018e-01, 7.459e-01, 8.262e-01, 9.482e-01, 1.091e+00, 1.241e+00, 1.400e+00, 1.508e+00, 1.428e+00, 1.328e+00, 1.116e+00, 8.987e-01, 6.891e-01, 5.094e-01, 3.489e-01, 2.395e-01, 1.538e-01, 9.893e-02, 6.262e-02, 4.037e-02, 2.695e-02, 1.850e-02, 1.297e-02, 9.579e-03, 7.301e-03, 5.711e-03, 4.039e-03, 3.006e-03, 2.658e-03, 2.428e-03, 2.173e-03, 2.089e-03, 2.024e-03, 2.011e-03, 1.975e-03, 1.610e-03, 1.360e-03, 1.289e-03, 1.393e-03, 1.391e-03, 1.501e-03, 1.427e-03, 1.122e-03, 6.719e-04, 6.922e-04, 3.974e-04, 9.641e-04, 1.158e-03, 2.294e-04, 4.049e-04, 4.714e-04, 1.357e-04, 1.546e-04, 8.709e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8",{1.886e-01, 3.827e+00, 4.337e+00, 2.583e+00, 1.930e+00, 1.804e+00, 1.269e+00, 1.406e+00, 8.503e-01, 2.245e+00, 2.172e+00, 2.044e+00, 1.751e+00, 1.525e+00, 1.445e+00, 1.421e+00, 1.429e+00, 1.433e+00, 1.424e+00, 1.403e+00, 1.397e+00, 1.389e+00, 1.399e+00, 1.392e+00, 1.391e+00, 1.377e+00, 1.362e+00, 1.331e+00, 1.308e+00, 1.255e+00, 1.199e+00, 1.124e+00, 1.044e+00, 9.561e-01, 8.761e-01, 8.178e-01, 7.750e-01, 7.474e-01, 7.159e-01, 7.058e-01, 7.446e-01, 8.256e-01, 9.417e-01, 1.092e+00, 1.257e+00, 1.390e+00, 1.490e+00, 1.430e+00, 1.329e+00, 1.128e+00, 9.002e-01, 6.841e-01, 5.006e-01, 3.504e-01, 2.381e-01, 1.541e-01, 9.996e-02, 6.314e-02, 4.088e-02, 2.686e-02, 1.844e-02, 1.297e-02, 9.528e-03, 7.247e-03, 5.801e-03, 4.132e-03, 3.039e-03, 2.626e-03, 2.457e-03, 2.261e-03, 2.088e-03, 2.053e-03, 2.039e-03, 1.890e-03, 1.582e-03, 1.374e-03, 1.240e-03, 1.224e-03, 1.273e-03, 1.110e-03, 1.121e-03, 1.138e-03, 1.262e-03, 7.802e-04, 7.372e-04, 1.204e-03, 6.712e-04, 3.724e-04, 4.694e-04, 9.564e-04, 1.836e-04, 0.000e+00, 1.767e-04, 6.562e-05, 0.000e+00, 5.906e-05, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8",{1.898e-01, 5.389e+00, 4.348e+00, 2.560e+00, 1.775e+00, 1.627e+00, 1.294e+00, 1.396e+00, 8.921e-01, 2.170e+00, 2.176e+00, 2.068e+00, 1.751e+00, 1.543e+00, 1.442e+00, 1.417e+00, 1.437e+00, 1.432e+00, 1.420e+00, 1.412e+00, 1.395e+00, 1.386e+00, 1.396e+00, 1.391e+00, 1.389e+00, 1.380e+00, 1.359e+00, 1.330e+00, 1.308e+00, 1.256e+00, 1.203e+00, 1.124e+00, 1.043e+00, 9.569e-01, 8.754e-01, 8.168e-01, 7.720e-01, 7.478e-01, 7.174e-01, 7.047e-01, 7.455e-01, 8.268e-01, 9.489e-01, 1.091e+00, 1.248e+00, 1.392e+00, 1.485e+00, 1.443e+00, 1.316e+00, 1.124e+00, 9.119e-01, 6.876e-01, 5.016e-01, 3.486e-01, 2.376e-01, 1.544e-01, 9.974e-02, 6.310e-02, 4.072e-02, 2.692e-02, 1.843e-02, 1.296e-02, 9.461e-03, 7.294e-03, 5.771e-03, 4.147e-03, 3.024e-03, 2.640e-03, 2.364e-03, 2.239e-03, 2.116e-03, 2.027e-03, 2.080e-03, 2.091e-03, 1.566e-03, 1.270e-03, 1.331e-03, 1.276e-03, 1.236e-03, 1.454e-03, 1.372e-03, 1.387e-03, 9.233e-04, 7.969e-04, 6.806e-04, 6.275e-04, 7.246e-04, 5.600e-04, 5.490e-04, 2.130e-04, 3.680e-04, 6.289e-04, 8.856e-05, 1.973e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}}
};

    std::unordered_map<std::string, std::vector<float>> pileupweightsUp = { // 69.2 + 4.6%
{"DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8",{5.039e-04, 1.494e-01, 5.339e-02, 1.056e-01, 6.698e-02, 6.264e-02, 5.444e-02, 1.444e-01, 8.380e-02, 1.927e-01, 3.448e-01, 5.859e-01, 4.878e-01, 4.942e-01, 4.739e-01, 4.986e-01, 5.874e-01, 6.995e-01, 8.566e-01, 8.998e-01, 1.033e+00, 1.097e+00, 1.162e+00, 1.202e+00, 1.241e+00, 1.259e+00, 1.083e+00, 1.291e+00, 1.341e+00, 1.352e+00, 1.326e+00, 1.297e+00, 1.230e+00, 1.166e+00, 1.137e+00, 1.093e+00, 1.051e+00, 1.027e+00, 9.228e-01, 9.289e-01, 8.380e-01, 9.384e-01, 9.171e-01, 1.028e+00, 1.125e+00, 1.247e+00, 1.356e+00, 1.511e+00, 1.643e+00, 1.671e+00, 1.591e+00, 1.566e+00, 1.428e+00, 1.277e+00, 1.086e+00, 7.924e-01, 6.757e-01, 5.091e-01, 3.928e-01, 2.590e-01, 2.290e-01, 1.752e-01, 1.403e-01, 1.036e-01, 9.661e-02, 7.223e-02, 5.024e-02, 4.459e-02, 4.100e-02, 3.921e-02, 3.575e-02, 2.740e-02, 4.088e-03, 3.190e-02, 1.739e-03, 2.333e-02, 2.054e-02, 1.954e-02, 9.435e-04, 4.563e-04, 3.984e-02, 6.548e-03, 3.225e-02, 1.091e-02, 5.885e-02, 1.974e-02, 0.000e+00, 1.747e-02, 8.341e-05, 0.000e+00, 4.898e-03, 0.000e+00, 0.000e+00, 1.285e-03, 0.000e+00, 0.000e+00, 3.131e-04, 1.923e-04, 0.000e+00, 2.138e-06, 0.000e+0}},
{"DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8",{1.713e-01, 3.545e+00, 2.846e+00, 2.380e+00, 1.336e+00, 1.378e+00, 1.251e+00, 1.148e+00, 5.048e-01, 9.470e-01, 1.048e+00, 1.028e+00, 1.005e+00, 9.025e-01, 8.265e-01, 7.959e-01, 8.164e-01, 8.660e-01, 9.318e-01, 9.855e-01, 1.031e+00, 1.083e+00, 1.131e+00, 1.155e+00, 1.167e+00, 1.168e+00, 1.173e+00, 1.180e+00, 1.210e+00, 1.211e+00, 1.211e+00, 1.180e+00, 1.139e+00, 1.091e+00, 1.037e+00, 9.949e-01, 9.570e-01, 9.275e-01, 8.771e-01, 8.328e-01, 8.285e-01, 8.401e-01, 8.685e-01, 9.214e-01, 9.967e-01, 1.111e+00, 1.249e+00, 1.347e+00, 1.448e+00, 1.490e+00, 1.491e+00, 1.431e+00, 1.315e+00, 1.167e+00, 9.974e-01, 8.041e-01, 6.288e-01, 4.757e-01, 3.622e-01, 2.742e-01, 2.116e-01, 1.642e-01, 1.314e-01, 1.076e-01, 8.905e-02, 6.510e-02, 4.791e-02, 4.161e-02, 3.756e-02, 3.452e-02, 3.138e-02, 3.044e-02, 2.952e-02, 2.937e-02, 2.383e-02, 1.984e-02, 1.993e-02, 2.181e-02, 2.121e-02, 2.560e-02, 2.614e-02, 2.514e-02, 3.242e-02, 2.330e-02, 2.219e-02, 3.260e-02, 1.986e-02, 3.366e-02, 2.852e-02, 3.267e-02, 8.494e-02, 2.740e-02, 7.017e-03, 2.228e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8",{2.422e-01, 3.014e+00, 3.977e+00, 4.078e+00, 1.349e+00, 1.323e+00, 1.095e+00, 1.140e+00, 5.757e-01, 9.821e-01, 9.954e-01, 1.035e+00, 9.831e-01, 8.844e-01, 8.331e-01, 8.155e-01, 8.296e-01, 8.611e-01, 9.186e-01, 9.746e-01, 1.029e+00, 1.071e+00, 1.120e+00, 1.160e+00, 1.175e+00, 1.176e+00, 1.172e+00, 1.200e+00, 1.209e+00, 1.198e+00, 1.231e+00, 1.163e+00, 1.153e+00, 1.099e+00, 1.044e+00, 1.005e+00, 9.751e-01, 9.229e-01, 8.765e-01, 8.121e-01, 8.221e-01, 8.438e-01, 8.623e-01, 9.205e-01, 1.016e+00, 1.105e+00, 1.258e+00, 1.347e+00, 1.424e+00, 1.495e+00, 1.462e+00, 1.405e+00, 1.332e+00, 1.174e+00, 9.972e-01, 8.138e-01, 6.145e-01, 4.709e-01, 3.664e-01, 2.725e-01, 2.115e-01, 1.639e-01, 1.306e-01, 1.080e-01, 8.739e-02, 6.307e-02, 4.881e-02, 4.247e-02, 3.788e-02, 3.420e-02, 3.282e-02, 3.276e-02, 2.989e-02, 2.927e-02, 2.232e-02, 1.830e-02, 1.559e-02, 1.733e-02, 1.624e-02, 2.418e-02, 2.592e-02, 2.059e-02, 2.797e-02, 1.420e-02, 1.276e-02, 0.000e+00, 1.713e-02, 1.136e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8",{1.866e-01, 4.325e+00, 2.965e+00, 2.599e+00, 1.322e+00, 1.339e+00, 1.222e+00, 1.135e+00, 4.911e-01, 9.451e-01, 1.050e+00, 1.029e+00, 1.015e+00, 9.035e-01, 8.252e-01, 7.978e-01, 8.163e-01, 8.662e-01, 9.333e-01, 9.841e-01, 1.032e+00, 1.084e+00, 1.126e+00, 1.155e+00, 1.163e+00, 1.165e+00, 1.172e+00, 1.179e+00, 1.211e+00, 1.214e+00, 1.210e+00, 1.179e+00, 1.143e+00, 1.090e+00, 1.037e+00, 9.964e-01, 9.572e-01, 9.294e-01, 8.787e-01, 8.353e-01, 8.300e-01, 8.395e-01, 8.679e-01, 9.199e-01, 1.003e+00, 1.119e+00, 1.251e+00, 1.331e+00, 1.447e+00, 1.491e+00, 1.488e+00, 1.423e+00, 1.314e+00, 1.163e+00, 9.932e-01, 8.020e-01, 6.294e-01, 4.798e-01, 3.612e-01, 2.765e-01, 2.107e-01, 1.649e-01, 1.315e-01, 1.063e-01, 8.934e-02, 6.489e-02, 4.832e-02, 4.175e-02, 3.726e-02, 3.452e-02, 3.161e-02, 2.996e-02, 3.005e-02, 2.953e-02, 2.313e-02, 1.926e-02, 2.070e-02, 2.114e-02, 2.226e-02, 2.196e-02, 2.371e-02, 2.526e-02, 2.875e-02, 2.526e-02, 1.981e-02, 2.100e-02, 3.103e-02, 2.401e-02, 2.373e-02, 2.071e-02, 1.616e-02, 1.303e-02, 1.112e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8",{1.972e-01, 3.210e+00, 2.712e+00, 2.808e+00, 1.512e+00, 1.318e+00, 1.219e+00, 1.177e+00, 4.858e-01, 9.347e-01, 1.074e+00, 1.032e+00, 1.013e+00, 9.009e-01, 8.281e-01, 7.922e-01, 8.116e-01, 8.663e-01, 9.334e-01, 9.899e-01, 1.037e+00, 1.087e+00, 1.131e+00, 1.150e+00, 1.164e+00, 1.165e+00, 1.173e+00, 1.179e+00, 1.206e+00, 1.210e+00, 1.211e+00, 1.178e+00, 1.140e+00, 1.093e+00, 1.039e+00, 9.948e-01, 9.559e-01, 9.283e-01, 8.790e-01, 8.341e-01, 8.279e-01, 8.408e-01, 8.703e-01, 9.206e-01, 1.003e+00, 1.115e+00, 1.251e+00, 1.346e+00, 1.445e+00, 1.481e+00, 1.487e+00, 1.429e+00, 1.315e+00, 1.162e+00, 9.954e-01, 8.026e-01, 6.291e-01, 4.770e-01, 3.608e-01, 2.751e-01, 2.118e-01, 1.650e-01, 1.308e-01, 1.068e-01, 8.947e-02, 6.508e-02, 4.828e-02, 4.171e-02, 3.735e-02, 3.450e-02, 3.164e-02, 3.064e-02, 2.826e-02, 2.905e-02, 2.275e-02, 2.025e-02, 1.984e-02, 2.147e-02, 2.426e-02, 2.133e-02, 2.486e-02, 3.111e-02, 3.029e-02, 2.158e-02, 1.764e-02, 2.418e-02, 2.183e-02, 2.051e-02, 3.244e-02, 2.123e-02, 6.900e-02, 4.452e-02, 2.850e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8",{1.865e-01, 5.354e+00, 3.499e+00, 2.545e+00, 1.518e+00, 1.312e+00, 1.347e+00, 1.352e+00, 5.027e-01, 9.633e-01, 1.081e+00, 1.030e+00, 9.848e-01, 9.086e-01, 8.266e-01, 7.914e-01, 8.031e-01, 8.712e-01, 9.336e-01, 9.830e-01, 1.035e+00, 1.082e+00, 1.130e+00, 1.159e+00, 1.168e+00, 1.165e+00, 1.173e+00, 1.172e+00, 1.212e+00, 1.216e+00, 1.206e+00, 1.177e+00, 1.141e+00, 1.093e+00, 1.038e+00, 9.959e-01, 9.608e-01, 9.240e-01, 8.785e-01, 8.332e-01, 8.232e-01, 8.469e-01, 8.697e-01, 9.207e-01, 1.003e+00, 1.112e+00, 1.251e+00, 1.336e+00, 1.446e+00, 1.483e+00, 1.504e+00, 1.431e+00, 1.310e+00, 1.173e+00, 9.843e-01, 7.992e-01, 6.291e-01, 4.813e-01, 3.605e-01, 2.756e-01, 2.117e-01, 1.648e-01, 1.327e-01, 1.061e-01, 8.969e-02, 6.459e-02, 4.793e-02, 4.264e-02, 3.758e-02, 3.353e-02, 3.142e-02, 3.009e-02, 2.977e-02, 2.974e-02, 2.164e-02, 1.871e-02, 2.153e-02, 2.087e-02, 2.174e-02, 2.007e-02, 2.494e-02, 2.265e-02, 3.076e-02, 2.302e-02, 1.282e-02, 1.797e-02, 4.397e-02, 2.916e-02, 2.883e-02, 3.774e-02, 2.453e-02, 5.275e-03, 5.066e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT1000to1500_TuneCP5_13TeV-madgraph-pythia8",{1.895e-01, 3.466e+00, 2.617e+00, 2.595e+00, 1.384e+00, 1.317e+00, 1.266e+00, 1.175e+00, 4.957e-01, 9.695e-01, 1.061e+00, 1.032e+00, 1.010e+00, 8.984e-01, 8.290e-01, 7.935e-01, 8.126e-01, 8.684e-01, 9.323e-01, 9.843e-01, 1.033e+00, 1.085e+00, 1.128e+00, 1.157e+00, 1.163e+00, 1.161e+00, 1.174e+00, 1.183e+00, 1.209e+00, 1.213e+00, 1.209e+00, 1.177e+00, 1.142e+00, 1.090e+00, 1.038e+00, 9.938e-01, 9.574e-01, 9.288e-01, 8.794e-01, 8.341e-01, 8.284e-01, 8.403e-01, 8.692e-01, 9.220e-01, 1.002e+00, 1.114e+00, 1.252e+00, 1.352e+00, 1.446e+00, 1.494e+00, 1.489e+00, 1.431e+00, 1.314e+00, 1.164e+00, 9.972e-01, 8.030e-01, 6.306e-01, 4.751e-01, 3.616e-01, 2.748e-01, 2.109e-01, 1.643e-01, 1.311e-01, 1.066e-01, 8.892e-02, 6.473e-02, 4.833e-02, 4.190e-02, 3.718e-02, 3.376e-02, 3.174e-02, 2.975e-02, 2.881e-02, 2.870e-02, 2.330e-02, 1.997e-02, 2.021e-02, 2.005e-02, 2.337e-02, 2.183e-02, 2.453e-02, 2.581e-02, 2.657e-02, 2.064e-02, 2.078e-02, 1.987e-02, 2.557e-02, 2.158e-02, 2.608e-02, 2.276e-02, 1.664e-02, 4.295e-02, 1.100e-02, 3.493e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT1500to2000_TuneCP5_13TeV-madgraph-pythia8",{1.694e-01, 3.601e+00, 2.833e+00, 2.691e+00, 1.426e+00, 1.306e+00, 1.212e+00, 1.141e+00, 4.830e-01, 9.215e-01, 1.067e+00, 1.037e+00, 1.005e+00, 9.000e-01, 8.288e-01, 7.948e-01, 8.136e-01, 8.674e-01, 9.318e-01, 9.872e-01, 1.034e+00, 1.087e+00, 1.124e+00, 1.155e+00, 1.167e+00, 1.168e+00, 1.173e+00, 1.183e+00, 1.213e+00, 1.211e+00, 1.209e+00, 1.180e+00, 1.142e+00, 1.087e+00, 1.040e+00, 9.928e-01, 9.585e-01, 9.269e-01, 8.769e-01, 8.338e-01, 8.304e-01, 8.389e-01, 8.680e-01, 9.187e-01, 1.002e+00, 1.113e+00, 1.246e+00, 1.345e+00, 1.444e+00, 1.494e+00, 1.490e+00, 1.426e+00, 1.319e+00, 1.163e+00, 9.951e-01, 8.053e-01, 6.260e-01, 4.760e-01, 3.607e-01, 2.757e-01, 2.111e-01, 1.646e-01, 1.319e-01, 1.068e-01, 8.906e-02, 6.495e-02, 4.843e-02, 4.205e-02, 3.741e-02, 3.436e-02, 3.108e-02, 3.059e-02, 2.915e-02, 2.854e-02, 2.288e-02, 1.939e-02, 2.083e-02, 2.287e-02, 2.353e-02, 2.429e-02, 2.501e-02, 2.834e-02, 2.735e-02, 1.790e-02, 2.553e-02, 2.455e-02, 1.820e-02, 2.962e-02, 2.386e-02, 1.757e-02, 2.284e-02, 1.965e-02, 3.774e-02, 2.397e-02, 7.550e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT2000toInf_TuneCP5_13TeV-madgraph-pythia8",{1.620e-01, 3.454e+00, 2.960e+00, 2.561e+00, 1.299e+00, 1.322e+00, 1.252e+00, 1.134e+00, 4.865e-01, 9.423e-01, 1.067e+00, 1.034e+00, 1.016e+00, 9.080e-01, 8.318e-01, 7.951e-01, 8.135e-01, 8.676e-01, 9.358e-01, 9.792e-01, 1.028e+00, 1.083e+00, 1.128e+00, 1.156e+00, 1.163e+00, 1.167e+00, 1.172e+00, 1.182e+00, 1.214e+00, 1.212e+00, 1.205e+00, 1.173e+00, 1.140e+00, 1.089e+00, 1.038e+00, 9.985e-01, 9.545e-01, 9.299e-01, 8.784e-01, 8.347e-01, 8.324e-01, 8.403e-01, 8.690e-01, 9.242e-01, 1.002e+00, 1.112e+00, 1.253e+00, 1.360e+00, 1.452e+00, 1.483e+00, 1.497e+00, 1.427e+00, 1.310e+00, 1.172e+00, 9.902e-01, 7.997e-01, 6.263e-01, 4.786e-01, 3.613e-01, 2.738e-01, 2.106e-01, 1.652e-01, 1.318e-01, 1.070e-01, 8.981e-02, 6.424e-02, 4.827e-02, 4.207e-02, 3.816e-02, 3.348e-02, 3.173e-02, 3.120e-02, 2.851e-02, 2.900e-02, 2.217e-02, 1.888e-02, 2.088e-02, 2.070e-02, 2.560e-02, 2.157e-02, 2.310e-02, 2.526e-02, 2.343e-02, 2.114e-02, 1.588e-02, 2.330e-02, 3.553e-02, 5.498e-02, 1.359e-02, 1.779e-02, 1.542e-02, 2.984e-02, 9.552e-03, 4.044e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT200to300_TuneCP5_13TeV-madgraph-pythia8",{1.753e-01, 3.453e+00, 3.026e+00, 2.563e+00, 1.406e+00, 1.374e+00, 1.227e+00, 1.143e+00, 4.973e-01, 9.426e-01, 1.062e+00, 1.033e+00, 1.013e+00, 9.025e-01, 8.279e-01, 7.973e-01, 8.126e-01, 8.686e-01, 9.337e-01, 9.855e-01, 1.034e+00, 1.085e+00, 1.129e+00, 1.155e+00, 1.165e+00, 1.167e+00, 1.171e+00, 1.181e+00, 1.209e+00, 1.213e+00, 1.210e+00, 1.180e+00, 1.140e+00, 1.089e+00, 1.037e+00, 9.940e-01, 9.560e-01, 9.282e-01, 8.806e-01, 8.329e-01, 8.281e-01, 8.397e-01, 8.691e-01, 9.211e-01, 9.999e-01, 1.113e+00, 1.250e+00, 1.345e+00, 1.444e+00, 1.488e+00, 1.494e+00, 1.427e+00, 1.320e+00, 1.167e+00, 9.951e-01, 7.993e-01, 6.302e-01, 4.764e-01, 3.614e-01, 2.744e-01, 2.115e-01, 1.646e-01, 1.313e-01, 1.070e-01, 8.906e-02, 6.474e-02, 4.829e-02, 4.170e-02, 3.739e-02, 3.390e-02, 3.145e-02, 3.008e-02, 2.932e-02, 2.900e-02, 2.360e-02, 1.983e-02, 2.042e-02, 2.092e-02, 2.246e-02, 2.501e-02, 2.442e-02, 2.412e-02, 2.851e-02, 2.232e-02, 1.903e-02, 2.158e-02, 2.149e-02, 2.685e-02, 2.907e-02, 2.756e-02, 3.247e-02, 1.972e-02, 1.262e-02, 4.543e-02, 8.585e-02, 8.938e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT300to500_TuneCP5_13TeV-madgraph-pythia8",{1.798e-01, 3.491e+00, 2.979e+00, 2.543e+00, 1.361e+00, 1.325e+00, 1.251e+00, 1.170e+00, 4.972e-01, 9.413e-01, 1.068e+00, 1.030e+00, 1.006e+00, 9.020e-01, 8.245e-01, 7.976e-01, 8.126e-01, 8.677e-01, 9.334e-01, 9.843e-01, 1.034e+00, 1.086e+00, 1.130e+00, 1.154e+00, 1.165e+00, 1.166e+00, 1.173e+00, 1.181e+00, 1.211e+00, 1.212e+00, 1.207e+00, 1.179e+00, 1.141e+00, 1.088e+00, 1.037e+00, 9.944e-01, 9.572e-01, 9.279e-01, 8.795e-01, 8.341e-01, 8.280e-01, 8.390e-01, 8.702e-01, 9.218e-01, 9.992e-01, 1.114e+00, 1.251e+00, 1.344e+00, 1.446e+00, 1.488e+00, 1.491e+00, 1.426e+00, 1.320e+00, 1.167e+00, 9.943e-01, 8.025e-01, 6.306e-01, 4.768e-01, 3.609e-01, 2.749e-01, 2.116e-01, 1.651e-01, 1.313e-01, 1.071e-01, 8.901e-02, 6.498e-02, 4.822e-02, 4.169e-02, 3.730e-02, 3.392e-02, 3.143e-02, 3.039e-02, 2.927e-02, 2.902e-02, 2.280e-02, 1.982e-02, 2.050e-02, 2.139e-02, 2.203e-02, 2.322e-02, 2.548e-02, 2.700e-02, 2.660e-02, 2.216e-02, 1.968e-02, 2.090e-02, 2.016e-02, 2.716e-02, 2.349e-02, 2.381e-02, 1.548e-02, 1.935e-02, 1.166e-02, 1.573e-02, 7.929e-02, 2.476e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT500to700_TuneCP5_13TeV-madgraph-pythia8",{1.776e-01, 3.305e+00, 2.808e+00, 2.579e+00, 1.384e+00, 1.343e+00, 1.277e+00, 1.176e+00, 4.973e-01, 9.395e-01, 1.075e+00, 1.035e+00, 1.011e+00, 9.015e-01, 8.271e-01, 7.941e-01, 8.110e-01, 8.684e-01, 9.360e-01, 9.846e-01, 1.034e+00, 1.083e+00, 1.128e+00, 1.155e+00, 1.168e+00, 1.168e+00, 1.173e+00, 1.181e+00, 1.211e+00, 1.212e+00, 1.208e+00, 1.179e+00, 1.138e+00, 1.089e+00, 1.038e+00, 9.938e-01, 9.578e-01, 9.277e-01, 8.782e-01, 8.331e-01, 8.284e-01, 8.388e-01, 8.702e-01, 9.208e-01, 1.003e+00, 1.115e+00, 1.247e+00, 1.346e+00, 1.450e+00, 1.487e+00, 1.492e+00, 1.429e+00, 1.317e+00, 1.165e+00, 9.944e-01, 8.028e-01, 6.308e-01, 4.762e-01, 3.610e-01, 2.740e-01, 2.112e-01, 1.649e-01, 1.312e-01, 1.071e-01, 8.903e-02, 6.484e-02, 4.816e-02, 4.199e-02, 3.730e-02, 3.385e-02, 3.180e-02, 3.024e-02, 2.925e-02, 2.910e-02, 2.339e-02, 1.963e-02, 2.053e-02, 2.139e-02, 2.246e-02, 2.429e-02, 2.533e-02, 2.642e-02, 2.663e-02, 2.347e-02, 1.889e-02, 2.214e-02, 2.045e-02, 2.404e-02, 2.011e-02, 2.208e-02, 2.022e-02, 2.392e-02, 1.671e-02, 1.297e-02, 3.676e-02, 2.297e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"QCD_HT700to1000_TuneCP5_13TeV-madgraph-pythia8",{1.821e-01, 3.294e+00, 2.633e+00, 2.467e+00, 1.412e+00, 1.323e+00, 1.259e+00, 1.134e+00, 5.005e-01, 9.435e-01, 1.068e+00, 1.035e+00, 1.007e+00, 9.015e-01, 8.280e-01, 7.965e-01, 8.102e-01, 8.695e-01, 9.340e-01, 9.863e-01, 1.033e+00, 1.088e+00, 1.127e+00, 1.154e+00, 1.163e+00, 1.167e+00, 1.174e+00, 1.181e+00, 1.210e+00, 1.211e+00, 1.207e+00, 1.179e+00, 1.141e+00, 1.089e+00, 1.039e+00, 9.938e-01, 9.575e-01, 9.307e-01, 8.787e-01, 8.325e-01, 8.278e-01, 8.398e-01, 8.713e-01, 9.200e-01, 1.003e+00, 1.112e+00, 1.252e+00, 1.346e+00, 1.447e+00, 1.488e+00, 1.495e+00, 1.430e+00, 1.317e+00, 1.164e+00, 9.930e-01, 8.024e-01, 6.286e-01, 4.775e-01, 3.609e-01, 2.739e-01, 2.115e-01, 1.652e-01, 1.312e-01, 1.070e-01, 8.883e-02, 6.489e-02, 4.804e-02, 4.161e-02, 3.753e-02, 3.395e-02, 3.181e-02, 3.032e-02, 2.950e-02, 2.836e-02, 2.296e-02, 1.943e-02, 2.036e-02, 2.136e-02, 2.234e-02, 2.398e-02, 2.471e-02, 2.546e-02, 3.010e-02, 2.316e-02, 1.918e-02, 2.132e-02, 1.878e-02, 2.358e-02, 2.637e-02, 2.035e-02, 1.481e-02, 1.838e-02, 1.020e-02, 8.095e-03, 2.040e-02, 1.274e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_s-channel_antitop_leptonDecays_13TeV-PSweights_powheg-pythia",{1.747e-01, 5.116e+00, 2.250e+00, 2.432e+00, 1.371e+00, 1.276e+00, 1.291e+00, 1.125e+00, 4.938e-01, 9.376e-01, 1.125e+00, 1.026e+00, 1.018e+00, 9.031e-01, 8.293e-01, 7.971e-01, 8.202e-01, 8.686e-01, 9.318e-01, 9.833e-01, 1.038e+00, 1.080e+00, 1.124e+00, 1.151e+00, 1.169e+00, 1.168e+00, 1.173e+00, 1.182e+00, 1.207e+00, 1.209e+00, 1.209e+00, 1.178e+00, 1.145e+00, 1.090e+00, 1.039e+00, 9.915e-01, 9.552e-01, 9.298e-01, 8.755e-01, 8.336e-01, 8.276e-01, 8.410e-01, 8.703e-01, 9.237e-01, 1.002e+00, 1.114e+00, 1.250e+00, 1.359e+00, 1.437e+00, 1.486e+00, 1.496e+00, 1.434e+00, 1.307e+00, 1.160e+00, 9.914e-01, 8.021e-01, 6.335e-01, 4.767e-01, 3.619e-01, 2.744e-01, 2.113e-01, 1.672e-01, 1.315e-01, 1.068e-01, 8.856e-02, 6.445e-02, 4.765e-02, 4.082e-02, 3.759e-02, 3.374e-02, 3.126e-02, 3.125e-02, 2.947e-02, 2.861e-02, 2.238e-02, 2.114e-02, 2.043e-02, 2.274e-02, 2.493e-02, 2.104e-02, 2.965e-02, 2.217e-02, 4.115e-02, 1.990e-02, 3.129e-02, 1.889e-02, 2.521e-02, 2.090e-02, 2.754e-02, 9.015e-03, 2.344e-02, 7.561e-03, 9.681e-03, 6.149e-03, 0.000e+00, 2.420e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_s-channel_top_leptonDecays_13TeV-PSweights_powheg-pythia",{1.692e-01, 3.305e+00, 2.908e+00, 2.416e+00, 1.376e+00, 1.380e+00, 1.277e+00, 1.153e+00, 4.885e-01, 9.458e-01, 1.069e+00, 1.023e+00, 1.001e+00, 8.954e-01, 8.278e-01, 7.969e-01, 8.144e-01, 8.628e-01, 9.383e-01, 9.874e-01, 1.031e+00, 1.084e+00, 1.129e+00, 1.157e+00, 1.165e+00, 1.163e+00, 1.173e+00, 1.184e+00, 1.206e+00, 1.212e+00, 1.208e+00, 1.180e+00, 1.142e+00, 1.096e+00, 1.039e+00, 9.952e-01, 9.573e-01, 9.305e-01, 8.773e-01, 8.353e-01, 8.265e-01, 8.427e-01, 8.691e-01, 9.161e-01, 9.991e-01, 1.116e+00, 1.254e+00, 1.339e+00, 1.439e+00, 1.489e+00, 1.498e+00, 1.431e+00, 1.307e+00, 1.175e+00, 9.960e-01, 7.987e-01, 6.254e-01, 4.765e-01, 3.605e-01, 2.725e-01, 2.112e-01, 1.643e-01, 1.306e-01, 1.080e-01, 8.918e-02, 6.487e-02, 4.847e-02, 4.210e-02, 3.763e-02, 3.371e-02, 3.232e-02, 3.054e-02, 3.004e-02, 2.928e-02, 2.277e-02, 1.991e-02, 2.188e-02, 2.073e-02, 2.005e-02, 2.262e-02, 2.783e-02, 2.757e-02, 3.204e-02, 2.871e-02, 2.268e-02, 2.101e-02, 1.840e-02, 2.789e-02, 2.144e-02, 1.685e-02, 5.475e-02, 1.766e-02, 2.261e-02, 7.181e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.793e-01, 3.342e+00, 2.887e+00, 2.568e+00, 1.376e+00, 1.354e+00, 1.263e+00, 1.162e+00, 4.927e-01, 9.461e-01, 1.067e+00, 1.029e+00, 1.012e+00, 9.031e-01, 8.271e-01, 7.946e-01, 8.098e-01, 8.675e-01, 9.350e-01, 9.860e-01, 1.034e+00, 1.085e+00, 1.129e+00, 1.156e+00, 1.165e+00, 1.166e+00, 1.171e+00, 1.182e+00, 1.213e+00, 1.213e+00, 1.208e+00, 1.179e+00, 1.140e+00, 1.089e+00, 1.038e+00, 9.950e-01, 9.567e-01, 9.276e-01, 8.781e-01, 8.332e-01, 8.285e-01, 8.384e-01, 8.694e-01, 9.200e-01, 1.002e+00, 1.113e+00, 1.249e+00, 1.347e+00, 1.446e+00, 1.490e+00, 1.492e+00, 1.433e+00, 1.315e+00, 1.163e+00, 9.939e-01, 8.023e-01, 6.297e-01, 4.768e-01, 3.608e-01, 2.742e-01, 2.111e-01, 1.648e-01, 1.311e-01, 1.073e-01, 8.913e-02, 6.499e-02, 4.818e-02, 4.192e-02, 3.745e-02, 3.388e-02, 3.160e-02, 3.030e-02, 2.917e-02, 2.937e-02, 2.298e-02, 1.985e-02, 2.030e-02, 2.160e-02, 2.204e-02, 2.333e-02, 2.541e-02, 2.632e-02, 2.744e-02, 2.071e-02, 1.863e-02, 2.357e-02, 2.214e-02, 2.415e-02, 2.372e-02, 2.262e-02, 1.715e-02, 1.953e-02, 1.328e-02, 1.500e-02, 8.504e-02, 7.589e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_t-channel_top_4f_InclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.768e-01, 3.374e+00, 2.759e+00, 2.536e+00, 1.414e+00, 1.336e+00, 1.241e+00, 1.150e+00, 4.988e-01, 9.453e-01, 1.069e+00, 1.033e+00, 1.012e+00, 9.035e-01, 8.272e-01, 7.957e-01, 8.121e-01, 8.678e-01, 9.337e-01, 9.853e-01, 1.035e+00, 1.084e+00, 1.129e+00, 1.155e+00, 1.165e+00, 1.167e+00, 1.172e+00, 1.182e+00, 1.210e+00, 1.212e+00, 1.207e+00, 1.179e+00, 1.140e+00, 1.089e+00, 1.038e+00, 9.942e-01, 9.570e-01, 9.282e-01, 8.796e-01, 8.334e-01, 8.283e-01, 8.387e-01, 8.698e-01, 9.188e-01, 1.000e+00, 1.113e+00, 1.250e+00, 1.347e+00, 1.447e+00, 1.488e+00, 1.491e+00, 1.427e+00, 1.316e+00, 1.167e+00, 9.943e-01, 8.031e-01, 6.303e-01, 4.766e-01, 3.613e-01, 2.744e-01, 2.112e-01, 1.649e-01, 1.313e-01, 1.072e-01, 8.932e-02, 6.502e-02, 4.817e-02, 4.188e-02, 3.722e-02, 3.385e-02, 3.153e-02, 3.030e-02, 2.903e-02, 2.889e-02, 2.333e-02, 1.960e-02, 2.057e-02, 2.116e-02, 2.239e-02, 2.391e-02, 2.496e-02, 2.720e-02, 2.937e-02, 2.127e-02, 2.045e-02, 2.322e-02, 2.103e-02, 2.411e-02, 2.244e-02, 2.724e-02, 1.708e-02, 1.963e-02, 1.149e-02, 1.344e-02, 5.363e-02, 1.436e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_tW_antitop_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.863e-01, 3.330e+00, 2.696e+00, 2.415e+00, 1.451e+00, 1.388e+00, 1.284e+00, 1.138e+00, 4.841e-01, 9.371e-01, 1.072e+00, 1.033e+00, 1.005e+00, 9.067e-01, 8.271e-01, 7.960e-01, 8.104e-01, 8.670e-01, 9.379e-01, 9.847e-01, 1.035e+00, 1.085e+00, 1.124e+00, 1.155e+00, 1.167e+00, 1.166e+00, 1.172e+00, 1.183e+00, 1.207e+00, 1.215e+00, 1.210e+00, 1.176e+00, 1.141e+00, 1.090e+00, 1.037e+00, 9.956e-01, 9.558e-01, 9.287e-01, 8.795e-01, 8.329e-01, 8.316e-01, 8.399e-01, 8.692e-01, 9.222e-01, 9.963e-01, 1.117e+00, 1.245e+00, 1.348e+00, 1.442e+00, 1.486e+00, 1.481e+00, 1.433e+00, 1.311e+00, 1.164e+00, 9.976e-01, 8.064e-01, 6.285e-01, 4.764e-01, 3.595e-01, 2.744e-01, 2.117e-01, 1.654e-01, 1.318e-01, 1.077e-01, 8.857e-02, 6.503e-02, 4.831e-02, 4.194e-02, 3.723e-02, 3.371e-02, 3.148e-02, 2.951e-02, 2.909e-02, 2.997e-02, 2.322e-02, 2.036e-02, 2.035e-02, 2.213e-02, 2.127e-02, 2.380e-02, 2.593e-02, 2.784e-02, 2.922e-02, 2.653e-02, 2.037e-02, 2.049e-02, 1.930e-02, 3.627e-02, 2.390e-02, 1.565e-02, 1.525e-02, 3.937e-02, 8.401e-03, 1.601e-02, 0.000e+00, 3.150e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.652e-01, 3.483e+00, 3.324e+00, 2.827e+00, 1.434e+00, 1.333e+00, 1.201e+00, 1.109e+00, 4.909e-01, 9.427e-01, 1.037e+00, 1.026e+00, 1.011e+00, 9.062e-01, 8.225e-01, 7.959e-01, 8.123e-01, 8.647e-01, 9.383e-01, 9.896e-01, 1.036e+00, 1.080e+00, 1.132e+00, 1.154e+00, 1.165e+00, 1.170e+00, 1.173e+00, 1.181e+00, 1.209e+00, 1.209e+00, 1.207e+00, 1.177e+00, 1.135e+00, 1.088e+00, 1.037e+00, 9.930e-01, 9.579e-01, 9.280e-01, 8.824e-01, 8.339e-01, 8.281e-01, 8.412e-01, 8.657e-01, 9.209e-01, 1.005e+00, 1.113e+00, 1.252e+00, 1.338e+00, 1.439e+00, 1.491e+00, 1.497e+00, 1.431e+00, 1.315e+00, 1.165e+00, 9.948e-01, 8.060e-01, 6.306e-01, 4.759e-01, 3.622e-01, 2.736e-01, 2.121e-01, 1.645e-01, 1.311e-01, 1.077e-01, 8.939e-02, 6.524e-02, 4.833e-02, 4.253e-02, 3.738e-02, 3.412e-02, 3.128e-02, 3.005e-02, 2.897e-02, 2.906e-02, 2.363e-02, 1.980e-02, 2.153e-02, 2.073e-02, 2.306e-02, 2.272e-02, 2.680e-02, 2.528e-02, 2.198e-02, 2.106e-02, 2.786e-02, 2.803e-02, 2.404e-02, 2.790e-02, 1.839e-02, 1.926e-02, 1.043e-02, 4.038e-02, 6.464e-03, 1.642e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTHH_TuneCP5_13TeV-madgraph-pythia8",{1.158e-04, 4.492e-01, 3.292e-01, 2.894e-01, 1.862e-01, 1.396e-01, 1.424e-01, 1.230e-01, 5.621e-02, 2.493e-01, 3.678e-01, 3.726e-01, 5.482e-01, 2.789e-01, 5.765e-01, 5.542e-01, 5.897e-01, 7.312e-01, 6.958e-01, 9.945e-01, 1.056e+00, 1.147e+00, 1.246e+00, 1.310e+00, 1.315e+00, 1.256e+00, 1.310e+00, 1.310e+00, 1.349e+00, 1.343e+00, 1.333e+00, 1.299e+00, 1.295e+00, 1.210e+00, 1.194e+00, 1.128e+00, 1.100e+00, 1.037e+00, 9.806e-01, 9.231e-01, 9.647e-01, 9.507e-01, 9.773e-01, 1.011e+00, 1.129e+00, 1.240e+00, 1.416e+00, 1.547e+00, 1.623e+00, 1.710e+00, 1.617e+00, 1.552e+00, 1.457e+00, 1.342e+00, 1.150e+00, 9.249e-01, 7.102e-01, 5.499e-01, 4.030e-01, 2.997e-01, 2.415e-01, 1.897e-01, 1.199e-01, 1.151e-01, 9.375e-02, 7.781e-02, 5.264e-02, 4.514e-02, 4.185e-02, 3.924e-02, 3.261e-02, 3.410e-02, 3.739e-02, 3.140e-02, 2.789e-02, 1.932e-02, 2.460e-02, 1.894e-02, 4.841e-02, 6.606e-02, 2.253e-02, 2.046e-02, 4.169e-02, 9.406e-03, 0.000e+00, 1.276e-02, 8.511e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 5.060e-05, 0.000e+00, 0.000e+00, 1.629e-06, 0.000e+0}},
{"TTTJ_TuneCP5_13TeV-madgraph-pythia8",{1.331e-01, 0.000e+00, 3.935e+00, 2.594e+00, 2.781e+00, 1.555e+00, 1.418e+00, 9.959e-01, 5.086e-01, 9.380e-01, 1.062e+00, 9.876e-01, 9.237e-01, 8.936e-01, 8.450e-01, 7.904e-01, 8.260e-01, 8.837e-01, 9.439e-01, 1.007e+00, 1.036e+00, 1.074e+00, 1.124e+00, 1.162e+00, 1.144e+00, 1.158e+00, 1.162e+00, 1.174e+00, 1.213e+00, 1.217e+00, 1.210e+00, 1.181e+00, 1.139e+00, 1.078e+00, 1.027e+00, 9.883e-01, 9.493e-01, 9.408e-01, 8.973e-01, 8.390e-01, 8.453e-01, 8.416e-01, 8.868e-01, 9.026e-01, 1.031e+00, 1.076e+00, 1.248e+00, 1.360e+00, 1.440e+00, 1.463e+00, 1.513e+00, 1.450e+00, 1.311e+00, 1.133e+00, 9.673e-01, 8.053e-01, 6.101e-01, 4.908e-01, 3.565e-01, 2.739e-01, 2.207e-01, 1.659e-01, 1.344e-01, 1.024e-01, 9.019e-02, 6.383e-02, 5.126e-02, 4.134e-02, 3.813e-02, 3.079e-02, 3.085e-02, 3.070e-02, 3.208e-02, 3.528e-02, 2.037e-02, 1.811e-02, 1.983e-02, 2.177e-02, 1.753e-02, 1.645e-02, 2.244e-02, 0.000e+00, 4.152e-02, 9.367e-03, 0.000e+00, 0.000e+00, 8.476e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTTT_TuneCP5_13TeV-amcatnlo-pythia8",{1.456e-01, 1.942e+00, 2.391e+00, 2.299e+00, 1.584e+00, 8.128e-01, 7.605e-01, 7.503e-01, 7.512e-01, 8.695e-01, 9.203e-01, 1.133e+00, 9.687e-01, 8.623e-01, 8.210e-01, 7.956e-01, 8.005e-01, 8.931e-01, 9.754e-01, 9.708e-01, 1.062e+00, 1.040e+00, 1.105e+00, 1.136e+00, 1.180e+00, 1.131e+00, 1.179e+00, 1.190e+00, 1.185e+00, 1.233e+00, 1.173e+00, 1.174e+00, 1.124e+00, 1.104e+00, 1.053e+00, 1.017e+00, 9.897e-01, 9.427e-01, 8.577e-01, 8.273e-01, 8.081e-01, 8.327e-01, 8.781e-01, 9.168e-01, 1.007e+00, 1.175e+00, 1.274e+00, 1.351e+00, 1.526e+00, 1.513e+00, 1.476e+00, 1.430e+00, 1.317e+00, 1.220e+00, 9.433e-01, 7.954e-01, 6.596e-01, 4.754e-01, 3.756e-01, 2.801e-01, 2.010e-01, 1.602e-01, 1.295e-01, 1.117e-01, 8.730e-02, 6.405e-02, 4.631e-02, 3.840e-02, 3.637e-02, 3.351e-02, 3.131e-02, 2.845e-02, 2.409e-02, 2.212e-02, 2.063e-02, 2.751e-02, 1.808e-02, 2.324e-02, 3.084e-02, 9.995e-02, 2.098e-02, 1.327e-02, 1.802e-02, 2.135e-02, 1.151e-02, 0.000e+00, 6.439e-03, -4.270e-03, 0.000e+00, 0.000e+00, 0.000e+00, -3.090e-03, 0.000e+00, -6.282e-04, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTTW_TuneCP5_13TeV-madgraph-pythia8",{1.764e-03, 4.090e-01, 4.656e-01, 2.725e-01, 2.022e-01, 1.750e-01, 1.752e-01, 1.633e-01, 7.414e-02, 1.282e-01, 4.065e-01, 4.248e-01, 5.183e-01, 7.738e-01, 8.040e-01, 7.703e-01, 7.935e-01, 7.356e-01, 8.513e-01, 9.095e-01, 9.632e-01, 1.029e+00, 1.116e+00, 1.167e+00, 1.172e+00, 1.201e+00, 1.214e+00, 1.185e+00, 1.247e+00, 1.278e+00, 1.244e+00, 1.236e+00, 1.140e+00, 1.138e+00, 1.111e+00, 1.068e+00, 9.546e-01, 9.977e-01, 9.396e-01, 9.036e-01, 8.989e-01, 9.037e-01, 9.230e-01, 1.018e+00, 1.053e+00, 1.207e+00, 1.348e+00, 1.506e+00, 1.593e+00, 1.612e+00, 1.557e+00, 1.530e+00, 1.137e+00, 1.241e+00, 1.092e+00, 8.721e-01, 6.657e-01, 3.895e-01, 3.889e-01, 2.960e-01, 2.210e-01, 1.783e-01, 1.423e-01, 1.125e-01, 9.127e-02, 7.130e-02, 5.112e-02, 4.586e-02, 3.729e-02, 3.777e-02, 3.448e-02, 3.058e-02, 3.957e-02, 2.306e-02, 2.195e-02, 2.294e-02, 2.204e-02, 2.372e-02, 1.385e-02, 1.188e-04, 3.009e-02, 6.147e-02, 4.176e-02, 9.422e-03, 1.905e-02, 1.278e-02, 2.131e-03, 9.583e-06, 3.726e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 1.014e-04, 0.000e+00, 0.000e+00, 4.568e-06, 0.000e+0}},
{"TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.732e-01, 3.382e+00, 2.800e+00, 2.572e+00, 1.412e+00, 1.370e+00, 1.250e+00, 1.138e+00, 4.943e-01, 9.468e-01, 1.058e+00, 1.037e+00, 1.010e+00, 9.067e-01, 8.265e-01, 7.962e-01, 8.128e-01, 8.662e-01, 9.331e-01, 9.862e-01, 1.034e+00, 1.085e+00, 1.129e+00, 1.154e+00, 1.163e+00, 1.167e+00, 1.173e+00, 1.182e+00, 1.210e+00, 1.211e+00, 1.208e+00, 1.180e+00, 1.140e+00, 1.090e+00, 1.037e+00, 9.944e-01, 9.566e-01, 9.294e-01, 8.790e-01, 8.327e-01, 8.300e-01, 8.386e-01, 8.692e-01, 9.203e-01, 1.001e+00, 1.115e+00, 1.252e+00, 1.346e+00, 1.449e+00, 1.487e+00, 1.492e+00, 1.431e+00, 1.313e+00, 1.166e+00, 9.950e-01, 8.037e-01, 6.292e-01, 4.769e-01, 3.609e-01, 2.740e-01, 2.114e-01, 1.645e-01, 1.313e-01, 1.073e-01, 8.885e-02, 6.479e-02, 4.809e-02, 4.190e-02, 3.751e-02, 3.403e-02, 3.162e-02, 3.050e-02, 2.852e-02, 2.884e-02, 2.286e-02, 1.974e-02, 2.052e-02, 2.072e-02, 2.179e-02, 2.309e-02, 2.443e-02, 2.746e-02, 2.608e-02, 2.111e-02, 1.880e-02, 2.162e-02, 1.992e-02, 2.312e-02, 2.246e-02, 2.095e-02, 2.017e-02, 2.067e-02, 1.500e-02, 1.587e-02, 4.500e-02, 1.874e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.806e-01, 3.165e+00, 2.757e+00, 2.542e+00, 1.387e+00, 1.339e+00, 1.237e+00, 1.164e+00, 4.952e-01, 9.393e-01, 1.058e+00, 1.032e+00, 1.011e+00, 9.039e-01, 8.250e-01, 7.967e-01, 8.115e-01, 8.675e-01, 9.322e-01, 9.849e-01, 1.034e+00, 1.085e+00, 1.129e+00, 1.155e+00, 1.165e+00, 1.167e+00, 1.172e+00, 1.182e+00, 1.210e+00, 1.212e+00, 1.208e+00, 1.178e+00, 1.141e+00, 1.089e+00, 1.037e+00, 9.935e-01, 9.572e-01, 9.299e-01, 8.797e-01, 8.326e-01, 8.294e-01, 8.402e-01, 8.690e-01, 9.194e-01, 1.000e+00, 1.113e+00, 1.248e+00, 1.345e+00, 1.448e+00, 1.488e+00, 1.491e+00, 1.430e+00, 1.317e+00, 1.166e+00, 9.943e-01, 8.027e-01, 6.298e-01, 4.765e-01, 3.607e-01, 2.748e-01, 2.115e-01, 1.653e-01, 1.315e-01, 1.071e-01, 8.913e-02, 6.485e-02, 4.825e-02, 4.198e-02, 3.732e-02, 3.408e-02, 3.150e-02, 3.018e-02, 2.900e-02, 2.900e-02, 2.320e-02, 1.980e-02, 2.041e-02, 2.070e-02, 2.260e-02, 2.313e-02, 2.482e-02, 2.691e-02, 2.780e-02, 2.188e-02, 2.026e-02, 2.251e-02, 2.088e-02, 2.389e-02, 2.316e-02, 2.426e-02, 2.228e-02, 2.543e-02, 1.366e-02, 1.415e-02, 5.646e-02, 2.116e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTToSemiLepton_HT500Njet9_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.755e-01, 2.988e+00, 2.628e+00, 2.549e+00, 1.542e+00, 1.339e+00, 1.272e+00, 1.141e+00, 4.991e-01, 9.551e-01, 1.071e+00, 1.036e+00, 1.000e+00, 8.989e-01, 8.239e-01, 7.918e-01, 8.111e-01, 8.688e-01, 9.363e-01, 9.858e-01, 1.035e+00, 1.085e+00, 1.127e+00, 1.159e+00, 1.165e+00, 1.169e+00, 1.174e+00, 1.179e+00, 1.213e+00, 1.214e+00, 1.206e+00, 1.179e+00, 1.140e+00, 1.090e+00, 1.033e+00, 9.956e-01, 9.561e-01, 9.297e-01, 8.775e-01, 8.354e-01, 8.312e-01, 8.397e-01, 8.706e-01, 9.196e-01, 1.003e+00, 1.109e+00, 1.251e+00, 1.347e+00, 1.445e+00, 1.489e+00, 1.494e+00, 1.427e+00, 1.311e+00, 1.165e+00, 9.942e-01, 8.007e-01, 6.313e-01, 4.758e-01, 3.601e-01, 2.743e-01, 2.105e-01, 1.646e-01, 1.310e-01, 1.065e-01, 8.977e-02, 6.391e-02, 4.847e-02, 4.219e-02, 3.743e-02, 3.380e-02, 3.195e-02, 2.983e-02, 2.864e-02, 2.966e-02, 2.310e-02, 2.048e-02, 2.098e-02, 2.139e-02, 2.136e-02, 2.544e-02, 2.427e-02, 2.928e-02, 3.327e-02, 2.252e-02, 1.855e-02, 1.750e-02, 3.736e-02, 2.253e-02, 5.444e-02, 1.527e-02, 1.737e-02, 0.000e+00, 3.189e-03, 9.114e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8",{1.746e-01, 3.296e+00, 2.853e+00, 2.574e+00, 1.415e+00, 1.347e+00, 1.237e+00, 1.140e+00, 4.936e-01, 9.416e-01, 1.064e+00, 1.032e+00, 1.013e+00, 9.043e-01, 8.262e-01, 7.965e-01, 8.115e-01, 8.675e-01, 9.341e-01, 9.858e-01, 1.034e+00, 1.084e+00, 1.128e+00, 1.155e+00, 1.165e+00, 1.168e+00, 1.172e+00, 1.182e+00, 1.210e+00, 1.212e+00, 1.208e+00, 1.179e+00, 1.141e+00, 1.088e+00, 1.038e+00, 9.934e-01, 9.568e-01, 9.283e-01, 8.787e-01, 8.337e-01, 8.280e-01, 8.396e-01, 8.677e-01, 9.198e-01, 1.002e+00, 1.114e+00, 1.250e+00, 1.347e+00, 1.447e+00, 1.487e+00, 1.490e+00, 1.429e+00, 1.315e+00, 1.165e+00, 9.943e-01, 8.030e-01, 6.307e-01, 4.768e-01, 3.609e-01, 2.749e-01, 2.111e-01, 1.654e-01, 1.313e-01, 1.072e-01, 8.910e-02, 6.473e-02, 4.815e-02, 4.188e-02, 3.750e-02, 3.410e-02, 3.162e-02, 3.010e-02, 2.932e-02, 2.885e-02, 2.302e-02, 1.947e-02, 2.012e-02, 2.037e-02, 2.268e-02, 2.336e-02, 2.491e-02, 2.738e-02, 2.810e-02, 2.222e-02, 1.998e-02, 2.289e-02, 1.966e-02, 2.641e-02, 2.789e-02, 2.666e-02, 2.113e-02, 3.105e-02, 1.154e-02, 1.337e-02, 3.579e-02, 2.981e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTWH_TuneCP5_13TeV-madgraph-pythia8",{2.474e-04, 2.606e-02, 3.429e-02, 2.983e-01, 1.858e-01, 1.619e-01, 1.463e-01, 1.337e-01, 5.907e-02, 1.187e-01, 4.083e-01, 5.271e-01, 5.600e-01, 4.861e-01, 4.612e-01, 2.952e-01, 5.928e-01, 8.235e-01, 9.393e-01, 1.019e+00, 1.048e+00, 1.046e+00, 1.171e+00, 1.201e+00, 1.244e+00, 1.298e+00, 1.321e+00, 1.277e+00, 1.387e+00, 1.380e+00, 1.337e+00, 1.298e+00, 1.277e+00, 1.214e+00, 1.146e+00, 1.119e+00, 1.072e+00, 1.001e+00, 1.001e+00, 9.308e-01, 9.048e-01, 9.188e-01, 1.018e+00, 1.031e+00, 1.154e+00, 1.226e+00, 1.357e+00, 1.465e+00, 1.581e+00, 1.646e+00, 1.540e+00, 1.455e+00, 8.410e-01, 1.250e+00, 1.063e+00, 8.427e-01, 6.911e-01, 5.260e-01, 3.901e-01, 2.945e-01, 2.275e-01, 1.717e-01, 1.490e-01, 1.125e-01, 9.263e-02, 6.713e-02, 5.102e-02, 4.463e-02, 3.908e-02, 1.868e-02, 3.111e-02, 3.232e-02, 1.493e-02, 8.257e-03, 3.167e-02, 1.582e-02, 1.265e-02, 9.778e-03, 2.147e-02, 6.593e-02, 4.497e-02, 6.125e-02, 2.080e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 3.713e-03, 0.000e+00, 0.000e+00, 0.000e+00, 6.525e-04, 0.000e+00, 0.000e+00, 0.000e+00, 5.050e-05, 6.201e-05, 3.774e-05, 2.529e-06, 0.000e+0}},
{"TTWJetsToLNu_TuneCP5_PSweights_13TeV-amcatnloFXFX-madspin-pythia8",{1.881e-01, 2.376e+00, 2.415e+00, 2.640e+00, 1.226e+00, 1.317e+00, 1.358e+00, 1.078e+00, 5.085e-01, 9.538e-01, 1.103e+00, 1.015e+00, 1.026e+00, 8.925e-01, 8.281e-01, 8.059e-01, 8.194e-01, 8.652e-01, 9.376e-01, 9.786e-01, 1.035e+00, 1.085e+00, 1.122e+00, 1.147e+00, 1.167e+00, 1.165e+00, 1.185e+00, 1.179e+00, 1.215e+00, 1.223e+00, 1.211e+00, 1.171e+00, 1.142e+00, 1.096e+00, 1.034e+00, 9.883e-01, 9.540e-01, 9.215e-01, 8.750e-01, 8.295e-01, 8.328e-01, 8.361e-01, 8.705e-01, 9.281e-01, 1.003e+00, 1.106e+00, 1.244e+00, 1.345e+00, 1.444e+00, 1.481e+00, 1.495e+00, 1.416e+00, 1.307e+00, 1.155e+00, 9.911e-01, 8.056e-01, 6.329e-01, 4.801e-01, 3.714e-01, 2.746e-01, 2.121e-01, 1.629e-01, 1.334e-01, 1.092e-01, 8.754e-02, 6.440e-02, 4.887e-02, 4.226e-02, 3.747e-02, 3.451e-02, 3.122e-02, 2.829e-02, 2.767e-02, 2.766e-02, 2.444e-02, 2.153e-02, 2.099e-02, 1.870e-02, 2.148e-02, 3.786e-02, 1.999e-02, 3.127e-02, 2.731e-02, 4.852e-02, 3.270e-02, 1.950e-02, 1.673e-02, 3.882e-02, 1.706e-02, 8.374e-03, -2.177e-02, 0.000e+00, 0.000e+00, 2.856e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8",{1.159e-01, 3.316e+00, 2.188e+00, 2.125e+00, 1.197e+00, 1.495e+00, 9.600e-01, 1.072e+00, 5.141e-01, 1.029e+00, 1.030e+00, 1.062e+00, 1.082e+00, 9.059e-01, 8.631e-01, 7.931e-01, 8.078e-01, 8.667e-01, 9.568e-01, 9.698e-01, 1.030e+00, 1.093e+00, 1.132e+00, 1.155e+00, 1.182e+00, 1.175e+00, 1.172e+00, 1.185e+00, 1.212e+00, 1.215e+00, 1.194e+00, 1.184e+00, 1.152e+00, 1.088e+00, 1.056e+00, 9.751e-01, 9.499e-01, 9.500e-01, 8.902e-01, 8.158e-01, 8.238e-01, 8.228e-01, 8.676e-01, 8.954e-01, 1.004e+00, 1.121e+00, 1.270e+00, 1.336e+00, 1.460e+00, 1.484e+00, 1.460e+00, 1.415e+00, 1.351e+00, 1.159e+00, 9.735e-01, 7.739e-01, 6.232e-01, 4.685e-01, 3.660e-01, 2.752e-01, 2.183e-01, 1.689e-01, 1.274e-01, 1.049e-01, 9.521e-02, 6.761e-02, 4.838e-02, 4.338e-02, 3.274e-02, 3.153e-02, 2.801e-02, 2.851e-02, 3.011e-02, 3.438e-02, 1.773e-02, 1.802e-02, 2.105e-02, 1.907e-02, 2.042e-02, 1.540e-02, 1.996e-02, 1.942e-02, 2.308e-02, 6.250e-02, 1.404e-02, 1.413e-02, 1.885e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTWW_TuneCP5_13TeV-madgraph-pythia8",{6.812e-04, 4.982e-01, 5.258e-01, 4.918e-01, 2.091e-01, 1.918e-01, 3.597e-01, 3.889e-01, 1.793e-01, 3.782e-01, 4.296e-01, 4.089e-01, 4.367e-01, 4.211e-01, 5.209e-01, 5.745e-01, 6.864e-01, 7.936e-01, 9.198e-01, 9.240e-01, 1.013e+00, 1.075e+00, 1.144e+00, 1.134e+00, 1.258e+00, 1.251e+00, 1.273e+00, 1.317e+00, 1.307e+00, 1.330e+00, 1.219e+00, 1.313e+00, 1.235e+00, 1.206e+00, 1.140e+00, 1.120e+00, 1.037e+00, 1.033e+00, 9.583e-01, 8.921e-01, 9.126e-01, 9.173e-01, 9.638e-01, 9.997e-01, 1.083e+00, 9.733e-01, 1.392e+00, 1.480e+00, 1.631e+00, 1.613e+00, 1.484e+00, 1.402e+00, 1.321e+00, 1.179e+00, 1.038e+00, 4.935e-01, 6.432e-01, 4.897e-01, 3.755e-01, 2.844e-01, 2.173e-01, 1.724e-01, 1.396e-01, 1.122e-01, 9.623e-02, 7.001e-02, 5.444e-02, 4.302e-02, 2.219e-02, 3.692e-02, 3.298e-02, 3.077e-02, 4.354e-02, 3.364e-02, 2.241e-02, 2.204e-02, 1.546e-02, 2.182e-02, 1.381e-02, 2.697e-04, 2.998e-02, 2.042e-02, 2.081e-02, 9.296e-05, 6.328e-03, 1.488e-05, 0.000e+00, 5.635e-03, 0.000e+00, 6.641e-06, 0.000e+00, 1.019e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 2.845e-06, 0.000e+0}},
{"TTWZ_TuneCP5_13TeV-madgraph-pythia8",{2.193e-03, 2.357e-01, 1.641e-01, 1.765e-01, 4.772e-01, 4.294e-01, 4.084e-01, 3.182e-01, 1.837e-01, 3.130e-01, 3.712e-01, 3.423e-01, 3.443e-01, 5.542e-01, 5.957e-01, 7.160e-01, 7.507e-01, 8.501e-01, 9.148e-01, 9.556e-01, 1.065e+00, 1.117e+00, 1.120e+00, 1.194e+00, 1.228e+00, 1.183e+00, 1.199e+00, 1.233e+00, 1.278e+00, 1.264e+00, 1.264e+00, 1.195e+00, 1.174e+00, 1.128e+00, 1.104e+00, 1.078e+00, 1.002e+00, 9.906e-01, 9.188e-01, 8.871e-01, 8.747e-01, 8.623e-01, 9.298e-01, 9.510e-01, 9.716e-01, 1.203e+00, 1.379e+00, 1.446e+00, 1.521e+00, 1.455e+00, 1.569e+00, 1.241e+00, 1.374e+00, 1.214e+00, 1.039e+00, 8.182e-01, 6.465e-01, 2.899e-01, 3.717e-01, 2.762e-01, 2.194e-01, 1.656e-01, 1.277e-01, 1.117e-01, 9.369e-02, 6.612e-02, 4.804e-02, 4.259e-02, 3.841e-02, 3.395e-02, 3.456e-02, 3.364e-02, 2.940e-02, 2.649e-02, 2.134e-02, 1.761e-02, 2.194e-02, 2.023e-02, 2.413e-02, 2.195e-02, 1.797e-02, 3.059e-02, 0.000e+00, 7.033e-03, 9.481e-03, 6.359e-03, 0.000e+00, 2.842e-05, 3.709e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 2.018e-05, 3.097e-05, 0.000e+00, 3.248e-06, 0.000e+0}},
{"TTZH_TuneCP5_13TeV-madgraph-pythia8",{2.231e-03, 1.497e+00, 1.128e+00, 1.072e+00, 5.981e-01, 8.323e-01, 7.867e-01, 7.140e-01, 2.770e-01, 7.616e-01, 8.339e-01, 8.947e-01, 7.843e-01, 7.411e-01, 6.884e-01, 6.519e-01, 6.694e-01, 7.349e-01, 7.974e-01, 8.940e-01, 9.605e-01, 9.842e-01, 1.080e+00, 1.110e+00, 1.203e+00, 1.185e+00, 1.160e+00, 1.193e+00, 1.292e+00, 1.286e+00, 1.208e+00, 1.231e+00, 1.196e+00, 1.170e+00, 1.117e+00, 1.032e+00, 1.014e+00, 9.952e-01, 9.434e-01, 8.909e-01, 9.115e-01, 8.885e-01, 9.305e-01, 7.390e-01, 1.081e+00, 1.252e+00, 1.351e+00, 1.454e+00, 1.562e+00, 1.614e+00, 1.561e+00, 9.621e-01, 1.372e+00, 1.196e+00, 1.066e+00, 8.387e-01, 6.449e-01, 5.068e-01, 3.725e-01, 2.934e-01, 2.234e-01, 1.663e-01, 1.357e-01, 1.177e-01, 9.130e-02, 6.557e-02, 5.562e-02, 4.260e-02, 4.071e-02, 3.465e-02, 3.617e-02, 2.716e-02, 2.990e-02, 3.139e-02, 2.300e-02, 2.377e-02, 1.990e-02, 2.029e-02, 2.419e-02, 3.301e-02, 1.763e-04, 1.534e-02, 2.084e-02, 9.402e-03, 9.506e-03, 0.000e+00, 0.000e+00, 5.642e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 1.012e-04, 2.070e-05, 0.000e+00, 3.256e-06, 0.000e+0}},
{"TTZToLLNuNu_M-10_TuneCP5_PSweights_13TeV-amcatnlo-pythia8",{1.849e-01, 2.951e+00, 2.732e+00, 2.349e+00, 1.347e+00, 1.574e+00, 1.266e+00, 1.143e+00, 5.225e-01, 9.525e-01, 1.058e+00, 1.031e+00, 9.952e-01, 9.102e-01, 8.238e-01, 7.977e-01, 8.181e-01, 8.702e-01, 9.308e-01, 9.879e-01, 1.037e+00, 1.091e+00, 1.128e+00, 1.163e+00, 1.166e+00, 1.172e+00, 1.169e+00, 1.184e+00, 1.204e+00, 1.214e+00, 1.210e+00, 1.182e+00, 1.138e+00, 1.085e+00, 1.038e+00, 9.941e-01, 9.584e-01, 9.318e-01, 8.736e-01, 8.283e-01, 8.283e-01, 8.403e-01, 8.651e-01, 9.219e-01, 1.009e+00, 1.112e+00, 1.247e+00, 1.346e+00, 1.441e+00, 1.482e+00, 1.469e+00, 1.421e+00, 1.309e+00, 1.159e+00, 9.946e-01, 8.058e-01, 6.278e-01, 4.761e-01, 3.601e-01, 2.725e-01, 2.111e-01, 1.675e-01, 1.314e-01, 1.080e-01, 8.931e-02, 6.485e-02, 4.803e-02, 4.320e-02, 3.768e-02, 3.384e-02, 3.083e-02, 3.044e-02, 2.916e-02, 2.786e-02, 2.436e-02, 1.962e-02, 2.313e-02, 2.133e-02, 2.435e-02, 2.462e-02, 3.200e-02, 2.372e-02, 2.961e-02, 1.901e-02, 1.612e-02, 2.579e-02, 2.485e-02, 1.648e-02, 2.444e-02, 1.600e-02, 8.319e-03, 0.000e+00, 1.718e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"TTZZ_TuneCP5_13TeV-madgraph-pythia8",{1.966e-04, 2.642e-01, 1.339e-01, 1.494e-01, 8.294e-02, 1.436e-01, 2.301e-01, 3.000e-01, 1.603e-01, 3.082e-01, 4.058e-01, 3.756e-01, 4.391e-01, 7.582e-01, 6.749e-01, 4.623e-01, 6.917e-01, 7.297e-01, 7.493e-01, 8.607e-01, 9.787e-01, 1.086e+00, 1.059e+00, 1.210e+00, 1.214e+00, 1.211e+00, 1.194e+00, 1.219e+00, 1.336e+00, 1.342e+00, 1.377e+00, 1.312e+00, 1.288e+00, 1.225e+00, 1.174e+00, 1.138e+00, 1.093e+00, 7.940e-01, 9.857e-01, 9.510e-01, 9.196e-01, 9.669e-01, 1.012e+00, 8.598e-01, 1.137e+00, 1.239e+00, 1.477e+00, 1.583e+00, 1.680e+00, 1.739e+00, 1.200e+00, 1.622e+00, 1.496e+00, 1.294e+00, 1.082e+00, 8.740e-01, 6.703e-01, 5.453e-01, 4.012e-01, 3.013e-01, 2.393e-01, 1.809e-01, 1.460e-01, 1.177e-01, 9.962e-02, 7.139e-02, 4.066e-02, 4.535e-02, 3.941e-02, 3.904e-02, 2.950e-02, 3.374e-02, 3.377e-02, 2.558e-02, 2.045e-02, 1.717e-02, 2.323e-02, 2.185e-02, 1.489e-02, 1.468e-02, 3.004e-02, 3.069e-02, 4.169e-02, 9.406e-03, 9.510e-03, 8.505e-04, 8.511e-03, 5.645e-03, 0.000e+00, 0.000e+00, 0.000e+00, 1.021e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 5.060e-05, 0.000e+00, 0.000e+00, 3.800e-06, 0.000e+0}},
{"WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8",{1.819e-01, 4.056e+00, 2.617e+00, 2.405e+00, 1.556e+00, 1.316e+00, 1.282e+00, 1.108e+00, 4.911e-01, 9.681e-01, 1.080e+00, 1.028e+00, 1.000e+00, 8.999e-01, 8.246e-01, 7.932e-01, 8.111e-01, 8.694e-01, 9.329e-01, 9.856e-01, 1.033e+00, 1.083e+00, 1.127e+00, 1.155e+00, 1.164e+00, 1.167e+00, 1.173e+00, 1.184e+00, 1.212e+00, 1.214e+00, 1.207e+00, 1.178e+00, 1.140e+00, 1.090e+00, 1.038e+00, 9.958e-01, 9.560e-01, 9.314e-01, 8.812e-01, 8.337e-01, 8.288e-01, 8.387e-01, 8.670e-01, 9.198e-01, 9.993e-01, 1.113e+00, 1.250e+00, 1.345e+00, 1.445e+00, 1.488e+00, 1.492e+00, 1.430e+00, 1.315e+00, 1.165e+00, 9.955e-01, 8.024e-01, 6.305e-01, 4.783e-01, 3.609e-01, 2.745e-01, 2.105e-01, 1.646e-01, 1.313e-01, 1.072e-01, 8.925e-02, 6.455e-02, 4.804e-02, 4.171e-02, 3.745e-02, 3.407e-02, 3.174e-02, 3.047e-02, 2.872e-02, 2.916e-02, 2.308e-02, 1.952e-02, 2.043e-02, 2.176e-02, 2.252e-02, 2.476e-02, 2.713e-02, 2.698e-02, 2.876e-02, 2.031e-02, 1.601e-02, 1.811e-02, 2.285e-02, 3.299e-02, 1.945e-02, 1.152e-02, 2.246e-02, 3.382e-02, 2.165e-02, 8.250e-03, 0.000e+00, 1.623e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8",{1.853e-01, 3.673e+00, 2.819e+00, 2.494e+00, 1.411e+00, 1.356e+00, 1.244e+00, 1.162e+00, 4.828e-01, 9.335e-01, 1.052e+00, 1.026e+00, 1.009e+00, 9.039e-01, 8.301e-01, 7.946e-01, 8.098e-01, 8.666e-01, 9.340e-01, 9.849e-01, 1.033e+00, 1.085e+00, 1.125e+00, 1.155e+00, 1.166e+00, 1.169e+00, 1.173e+00, 1.183e+00, 1.209e+00, 1.215e+00, 1.206e+00, 1.176e+00, 1.143e+00, 1.088e+00, 1.038e+00, 9.955e-01, 9.585e-01, 9.273e-01, 8.773e-01, 8.345e-01, 8.276e-01, 8.412e-01, 8.689e-01, 9.172e-01, 1.003e+00, 1.114e+00, 1.251e+00, 1.344e+00, 1.452e+00, 1.487e+00, 1.495e+00, 1.431e+00, 1.318e+00, 1.167e+00, 9.937e-01, 8.011e-01, 6.293e-01, 4.753e-01, 3.607e-01, 2.747e-01, 2.117e-01, 1.646e-01, 1.322e-01, 1.068e-01, 8.927e-02, 6.502e-02, 4.827e-02, 4.185e-02, 3.693e-02, 3.382e-02, 3.148e-02, 3.033e-02, 2.919e-02, 2.865e-02, 2.315e-02, 2.003e-02, 2.053e-02, 2.079e-02, 2.371e-02, 2.251e-02, 2.541e-02, 3.107e-02, 3.121e-02, 1.923e-02, 1.963e-02, 2.608e-02, 1.846e-02, 3.333e-02, 1.648e-02, 1.991e-02, 2.103e-02, 3.618e-02, 1.390e-02, 8.827e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8",{1.833e-01, 3.548e+00, 2.672e+00, 2.664e+00, 1.389e+00, 1.318e+00, 1.242e+00, 1.136e+00, 5.017e-01, 9.307e-01, 1.057e+00, 1.030e+00, 1.015e+00, 9.003e-01, 8.242e-01, 7.936e-01, 8.110e-01, 8.690e-01, 9.355e-01, 9.848e-01, 1.034e+00, 1.086e+00, 1.130e+00, 1.156e+00, 1.165e+00, 1.164e+00, 1.174e+00, 1.182e+00, 1.211e+00, 1.211e+00, 1.207e+00, 1.180e+00, 1.140e+00, 1.089e+00, 1.038e+00, 9.958e-01, 9.591e-01, 9.291e-01, 8.777e-01, 8.305e-01, 8.305e-01, 8.387e-01, 8.688e-01, 9.217e-01, 9.970e-01, 1.113e+00, 1.247e+00, 1.346e+00, 1.446e+00, 1.486e+00, 1.494e+00, 1.428e+00, 1.314e+00, 1.165e+00, 9.955e-01, 8.020e-01, 6.291e-01, 4.764e-01, 3.604e-01, 2.751e-01, 2.117e-01, 1.644e-01, 1.312e-01, 1.075e-01, 8.893e-02, 6.525e-02, 4.842e-02, 4.231e-02, 3.702e-02, 3.415e-02, 3.192e-02, 3.011e-02, 2.946e-02, 2.898e-02, 2.257e-02, 1.983e-02, 2.045e-02, 2.201e-02, 2.192e-02, 2.513e-02, 2.597e-02, 2.530e-02, 2.857e-02, 2.281e-02, 2.029e-02, 2.276e-02, 2.590e-02, 2.781e-02, 2.026e-02, 6.299e-02, 3.276e-02, 2.642e-02, 2.255e-02, 1.432e-02, 2.707e-02, 5.636e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8",{1.839e-01, 3.412e+00, 3.170e+00, 2.695e+00, 1.414e+00, 1.312e+00, 1.258e+00, 1.174e+00, 4.928e-01, 9.279e-01, 1.067e+00, 1.030e+00, 1.006e+00, 9.016e-01, 8.276e-01, 7.945e-01, 8.067e-01, 8.662e-01, 9.320e-01, 9.837e-01, 1.033e+00, 1.085e+00, 1.129e+00, 1.153e+00, 1.167e+00, 1.169e+00, 1.172e+00, 1.184e+00, 1.212e+00, 1.213e+00, 1.209e+00, 1.181e+00, 1.141e+00, 1.089e+00, 1.039e+00, 9.938e-01, 9.553e-01, 9.286e-01, 8.807e-01, 8.325e-01, 8.272e-01, 8.384e-01, 8.690e-01, 9.176e-01, 1.002e+00, 1.116e+00, 1.250e+00, 1.346e+00, 1.451e+00, 1.492e+00, 1.494e+00, 1.432e+00, 1.317e+00, 1.167e+00, 9.937e-01, 8.028e-01, 6.291e-01, 4.736e-01, 3.621e-01, 2.747e-01, 2.120e-01, 1.651e-01, 1.312e-01, 1.059e-01, 8.941e-02, 6.451e-02, 4.819e-02, 4.201e-02, 3.708e-02, 3.386e-02, 3.152e-02, 3.032e-02, 2.914e-02, 2.910e-02, 2.277e-02, 1.998e-02, 2.062e-02, 2.017e-02, 2.191e-02, 2.382e-02, 2.366e-02, 2.773e-02, 2.634e-02, 2.056e-02, 2.226e-02, 3.036e-02, 1.688e-02, 2.519e-02, 1.476e-02, 3.477e-02, 2.825e-02, 2.430e-02, 4.668e-02, 9.882e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8",{1.840e-01, 3.058e+00, 2.880e+00, 2.656e+00, 1.361e+00, 1.324e+00, 1.251e+00, 1.179e+00, 4.951e-01, 9.619e-01, 1.050e+00, 1.028e+00, 1.004e+00, 9.024e-01, 8.226e-01, 7.965e-01, 8.113e-01, 8.720e-01, 9.336e-01, 9.831e-01, 1.037e+00, 1.085e+00, 1.130e+00, 1.156e+00, 1.165e+00, 1.169e+00, 1.169e+00, 1.181e+00, 1.210e+00, 1.214e+00, 1.209e+00, 1.180e+00, 1.140e+00, 1.087e+00, 1.037e+00, 9.930e-01, 9.574e-01, 9.281e-01, 8.805e-01, 8.352e-01, 8.259e-01, 8.413e-01, 8.684e-01, 9.198e-01, 1.001e+00, 1.110e+00, 1.250e+00, 1.345e+00, 1.451e+00, 1.487e+00, 1.490e+00, 1.428e+00, 1.319e+00, 1.171e+00, 9.945e-01, 8.043e-01, 6.309e-01, 4.762e-01, 3.609e-01, 2.735e-01, 2.109e-01, 1.648e-01, 1.314e-01, 1.066e-01, 8.887e-02, 6.481e-02, 4.796e-02, 4.223e-02, 3.754e-02, 3.379e-02, 3.163e-02, 3.010e-02, 2.851e-02, 2.918e-02, 2.358e-02, 1.956e-02, 2.048e-02, 2.016e-02, 2.242e-02, 2.231e-02, 2.351e-02, 2.636e-02, 3.178e-02, 2.263e-02, 1.889e-02, 2.511e-02, 2.247e-02, 1.910e-02, 2.120e-02, 2.197e-02, 2.448e-02, 1.382e-02, 1.415e-02, 1.124e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8",{1.657e-01, 3.102e+00, 2.531e+00, 2.614e+00, 1.367e+00, 1.276e+00, 1.252e+00, 1.145e+00, 4.905e-01, 9.360e-01, 1.068e+00, 1.022e+00, 1.010e+00, 9.010e-01, 8.237e-01, 7.969e-01, 8.116e-01, 8.674e-01, 9.339e-01, 9.865e-01, 1.033e+00, 1.086e+00, 1.129e+00, 1.155e+00, 1.167e+00, 1.170e+00, 1.172e+00, 1.181e+00, 1.210e+00, 1.210e+00, 1.208e+00, 1.179e+00, 1.137e+00, 1.090e+00, 1.038e+00, 9.956e-01, 9.578e-01, 9.285e-01, 8.800e-01, 8.333e-01, 8.291e-01, 8.382e-01, 8.683e-01, 9.207e-01, 9.987e-01, 1.116e+00, 1.248e+00, 1.341e+00, 1.445e+00, 1.488e+00, 1.488e+00, 1.431e+00, 1.312e+00, 1.164e+00, 9.935e-01, 8.048e-01, 6.309e-01, 4.764e-01, 3.629e-01, 2.739e-01, 2.113e-01, 1.655e-01, 1.318e-01, 1.066e-01, 8.918e-02, 6.473e-02, 4.822e-02, 4.186e-02, 3.754e-02, 3.404e-02, 3.162e-02, 2.997e-02, 2.946e-02, 2.965e-02, 2.342e-02, 1.894e-02, 2.097e-02, 2.066e-02, 2.116e-02, 2.395e-02, 2.584e-02, 2.502e-02, 2.981e-02, 1.962e-02, 2.220e-02, 2.313e-02, 2.216e-02, 2.388e-02, 1.717e-02, 2.472e-02, 1.785e-02, 2.592e-02, 2.212e-02, 0.000e+00, 1.328e-02, 1.659e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WW_TuneCP5_13TeV-pythia8",{1.692e-01, 3.240e+00, 2.724e+00, 2.367e+00, 1.460e+00, 1.326e+00, 1.201e+00, 1.062e+00, 5.075e-01, 9.471e-01, 1.068e+00, 1.032e+00, 1.016e+00, 8.993e-01, 8.235e-01, 7.977e-01, 8.132e-01, 8.716e-01, 9.297e-01, 9.878e-01, 1.033e+00, 1.086e+00, 1.130e+00, 1.157e+00, 1.165e+00, 1.165e+00, 1.173e+00, 1.179e+00, 1.208e+00, 1.214e+00, 1.206e+00, 1.178e+00, 1.141e+00, 1.088e+00, 1.040e+00, 9.921e-01, 9.568e-01, 9.299e-01, 8.814e-01, 8.345e-01, 8.274e-01, 8.371e-01, 8.689e-01, 9.158e-01, 9.980e-01, 1.112e+00, 1.254e+00, 1.346e+00, 1.452e+00, 1.489e+00, 1.498e+00, 1.429e+00, 1.310e+00, 1.160e+00, 9.970e-01, 8.069e-01, 6.318e-01, 4.768e-01, 3.605e-01, 2.747e-01, 2.115e-01, 1.646e-01, 1.320e-01, 1.062e-01, 8.940e-02, 6.485e-02, 4.829e-02, 4.191e-02, 3.788e-02, 3.430e-02, 3.082e-02, 3.046e-02, 2.790e-02, 2.928e-02, 2.445e-02, 1.997e-02, 1.989e-02, 2.053e-02, 2.143e-02, 2.247e-02, 2.340e-02, 2.344e-02, 2.255e-02, 2.155e-02, 2.470e-02, 3.313e-02, 1.745e-02, 2.443e-02, 4.830e-02, 2.371e-02, 2.055e-02, 3.978e-02, 6.366e-03, 5.391e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"WZ_TuneCP5_13TeV-pythia8",{2.795e-04, 8.136e-03, 3.035e-02, 6.774e-02, 7.990e-02, 1.602e-01, 1.867e-01, 2.041e-01, 8.812e-02, 2.672e-01, 3.006e-01, 4.491e-01, 5.373e-01, 5.869e-01, 5.671e-01, 5.694e-01, 6.374e-01, 7.804e-01, 8.728e-01, 9.482e-01, 1.056e+00, 1.113e+00, 1.168e+00, 1.208e+00, 1.239e+00, 1.243e+00, 1.236e+00, 1.275e+00, 1.322e+00, 1.332e+00, 1.290e+00, 1.272e+00, 1.237e+00, 1.194e+00, 1.153e+00, 1.105e+00, 1.052e+00, 1.012e+00, 9.507e-01, 9.288e-01, 8.900e-01, 8.994e-01, 9.471e-01, 1.026e+00, 1.113e+00, 1.214e+00, 1.369e+00, 1.486e+00, 1.571e+00, 1.648e+00, 1.606e+00, 1.552e+00, 1.427e+00, 1.202e+00, 1.048e+00, 8.340e-01, 6.822e-01, 5.145e-01, 3.913e-01, 2.978e-01, 2.172e-01, 1.709e-01, 1.292e-01, 1.026e-01, 9.116e-02, 6.964e-02, 4.636e-02, 4.335e-02, 3.016e-02, 3.406e-02, 1.873e-02, 1.873e-02, 1.578e-02, 3.180e-02, 1.304e-02, 4.507e-03, 3.148e-03, 2.089e-02, 1.124e-03, 8.538e-04, 1.786e-03, 3.853e-04, 5.193e-04, 1.189e-04, 1.973e-02, 1.610e-04, 1.256e-04, 2.115e-04, 1.502e-05, 8.038e-05, 2.004e-05, 1.677e-03, 4.294e-03, 4.091e-03, 1.718e-03, 8.029e-06, 3.324e-04, 1.224e-03, 2.661e-06, 3.164e-06, 0.000e+0}},
{"ZZ_TuneCP5_13TeV-pythia8",{1.970e-01, 3.944e+00, 2.827e+00, 2.446e+00, 1.819e+00, 1.326e+00, 1.184e+00, 1.137e+00, 5.131e-01, 9.896e-01, 1.094e+00, 1.047e+00, 1.008e+00, 8.963e-01, 8.164e-01, 7.864e-01, 8.124e-01, 8.802e-01, 9.277e-01, 9.891e-01, 1.033e+00, 1.082e+00, 1.126e+00, 1.161e+00, 1.164e+00, 1.160e+00, 1.170e+00, 1.188e+00, 1.205e+00, 1.224e+00, 1.209e+00, 1.182e+00, 1.135e+00, 1.084e+00, 1.044e+00, 9.936e-01, 9.554e-01, 9.307e-01, 8.811e-01, 8.309e-01, 8.276e-01, 8.387e-01, 8.725e-01, 9.208e-01, 9.946e-01, 1.118e+00, 1.270e+00, 1.340e+00, 1.453e+00, 1.478e+00, 1.477e+00, 1.428e+00, 1.339e+00, 1.161e+00, 1.002e+00, 7.975e-01, 6.255e-01, 4.737e-01, 3.583e-01, 2.751e-01, 2.129e-01, 1.651e-01, 1.323e-01, 1.073e-01, 8.761e-02, 6.351e-02, 4.763e-02, 4.187e-02, 3.768e-02, 3.304e-02, 3.115e-02, 2.975e-02, 2.936e-02, 2.895e-02, 2.396e-02, 2.081e-02, 2.050e-02, 2.326e-02, 2.461e-02, 2.836e-02, 2.902e-02, 2.470e-02, 1.611e-02, 1.817e-02, 1.148e-02, 3.081e-02, 4.111e-02, 9.088e-03, 1.797e-02, 2.352e-02, 7.645e-03, 9.865e-03, 6.315e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8",{1.747e-01, 2.984e+00, 2.717e+00, 2.686e+00, 1.440e+00, 1.432e+00, 1.175e+00, 1.147e+00, 4.729e-01, 9.762e-01, 1.057e+00, 1.021e+00, 1.014e+00, 8.959e-01, 8.300e-01, 7.950e-01, 8.088e-01, 8.677e-01, 9.335e-01, 9.819e-01, 1.036e+00, 1.085e+00, 1.134e+00, 1.154e+00, 1.165e+00, 1.163e+00, 1.174e+00, 1.183e+00, 1.209e+00, 1.211e+00, 1.205e+00, 1.178e+00, 1.142e+00, 1.090e+00, 1.037e+00, 9.950e-01, 9.591e-01, 9.293e-01, 8.791e-01, 8.356e-01, 8.262e-01, 8.381e-01, 8.665e-01, 9.222e-01, 1.007e+00, 1.110e+00, 1.255e+00, 1.342e+00, 1.454e+00, 1.493e+00, 1.479e+00, 1.417e+00, 1.316e+00, 1.166e+00, 9.955e-01, 7.989e-01, 6.320e-01, 4.777e-01, 3.628e-01, 2.742e-01, 2.122e-01, 1.651e-01, 1.316e-01, 1.065e-01, 8.899e-02, 6.496e-02, 4.815e-02, 4.137e-02, 3.812e-02, 3.438e-02, 3.115e-02, 3.017e-02, 2.976e-02, 2.770e-02, 2.355e-02, 2.102e-02, 1.972e-02, 2.043e-02, 2.252e-02, 2.097e-02, 2.279e-02, 2.506e-02, 3.026e-02, 2.048e-02, 2.130e-02, 3.847e-02, 2.383e-02, 1.475e-02, 2.083e-02, 4.773e-02, 1.034e-02, 0.000e+00, 1.281e-02, 5.425e-03, 0.000e+00, 6.405e-03, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
{"ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8",{1.757e-01, 4.202e+00, 2.724e+00, 2.663e+00, 1.325e+00, 1.292e+00, 1.198e+00, 1.139e+00, 4.962e-01, 9.436e-01, 1.059e+00, 1.033e+00, 1.014e+00, 9.063e-01, 8.277e-01, 7.931e-01, 8.135e-01, 8.669e-01, 9.307e-01, 9.881e-01, 1.035e+00, 1.082e+00, 1.132e+00, 1.153e+00, 1.163e+00, 1.166e+00, 1.171e+00, 1.182e+00, 1.210e+00, 1.211e+00, 1.210e+00, 1.178e+00, 1.141e+00, 1.091e+00, 1.036e+00, 9.937e-01, 9.554e-01, 9.298e-01, 8.810e-01, 8.343e-01, 8.271e-01, 8.393e-01, 8.732e-01, 9.213e-01, 1.000e+00, 1.113e+00, 1.251e+00, 1.353e+00, 1.440e+00, 1.488e+00, 1.498e+00, 1.425e+00, 1.318e+00, 1.160e+00, 9.935e-01, 8.006e-01, 6.306e-01, 4.774e-01, 3.614e-01, 2.747e-01, 2.121e-01, 1.650e-01, 1.306e-01, 1.072e-01, 8.853e-02, 6.520e-02, 4.792e-02, 4.159e-02, 3.668e-02, 3.406e-02, 3.156e-02, 2.979e-02, 3.037e-02, 3.065e-02, 2.332e-02, 1.944e-02, 2.117e-02, 2.131e-02, 2.186e-02, 2.747e-02, 2.788e-02, 3.053e-02, 2.214e-02, 2.092e-02, 1.967e-02, 2.005e-02, 2.573e-02, 2.218e-02, 2.436e-02, 1.063e-02, 2.073e-02, 4.012e-02, 6.422e-03, 1.632e-02, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+00, 0.000e+0}},
};

	*pileupweight = pileupweights.at(sample)[nTrueInt];
	*pileupweightup = pileupweightsUp.at(sample)[nTrueInt];
	*pileupweightdn = pileupweightsDn.at(sample)[nTrueInt];

}

void HardcodedConditions::GetPileupWeight2018(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn, std::string sample)
{
   // Pileup distributions -- Centrally-stored data PU hists 2018 vs 2018 TTToSemiLeptonic
   std::vector<float> pileupweights;
   std::vector<float> pileupweightsUp;
   std::vector<float> pileupweightsDn;

   pileupweights = { 0.000e+00,  1.250e+01,  5.025e+01,  1.900e+01,  1.197e+01,  9.118e+00,  6.647e+00,  4.832e+00,  3.633e+00,  2.747e+00,  
		    2.238e+00,  1.904e+00,  1.694e+00,  1.572e+00,  1.502e+00,  1.468e+00,  1.451e+00,  1.452e+00,  1.461e+00,  1.467e+00,  
		    1.458e+00,  1.436e+00,  1.401e+00,  1.352e+00,  1.302e+00,  1.250e+00,  1.205e+00,  1.167e+00,  1.138e+00,  1.116e+00,  
		    1.100e+00,  1.089e+00,  1.081e+00,  1.077e+00,  1.074e+00,  1.069e+00,  1.063e+00,  1.052e+00,  1.035e+00,  1.012e+00,  
		    9.794e-01,  9.367e-01,  8.867e-01,  8.272e-01,  7.609e-01,  6.925e-01,  6.209e-01,  5.505e-01,  4.824e-01,  4.193e-01,  
		    3.621e-01,  3.103e-01,  2.658e-01,  2.276e-01,  1.948e-01,  1.679e-01,  1.455e-01,  1.262e-01,  1.098e-01,  9.584e-02,  
		    8.398e-02,  7.342e-02,  6.469e-02,  5.654e-02,  4.900e-02,  4.233e-02,  3.634e-02,  3.081e-02,  2.661e-02,  2.266e-02,  
		    1.889e-02,  1.652e-02,  1.344e-02,  1.173e-02,  9.423e-03,  8.155e-03,  6.671e-03,  5.637e-03,  4.504e-03,  3.920e-03,  
		    3.007e-03,  2.567e-03,  1.909e-03,  1.425e-03,  1.084e-03,  8.974e-04,  8.267e-04,  4.805e-04,  2.814e-04,  1.588e-04,  
		    1.206e-04,  6.816e-05,  2.870e-05,  1.436e-05,  7.136e-06,  4.702e-06,  1.107e-06,  1.723e-06,  1.079e-06,  1.269e-07,  0.000e+00,  }; // TTToSemiLeptonic
   pileupweightsUp = { 0.000e+00,  1.447e+01,  5.931e+01,  2.226e+01,  1.397e+01,  1.063e+01,  7.865e+00,  5.773e+00,  4.367e+00,  3.362e+00,  
			2.793e+00,  2.408e+00,  2.153e+00,  1.999e+00,  1.907e+00,  1.857e+00,  1.824e+00,  1.805e+00,  1.789e+00,  1.761e+00,  
			1.710e+00,  1.645e+00,  1.572e+00,  1.493e+00,  1.423e+00,  1.358e+00,  1.306e+00,  1.264e+00,  1.232e+00,  1.206e+00,  
			1.185e+00,  1.166e+00,  1.148e+00,  1.131e+00,  1.111e+00,  1.085e+00,  1.054e+00,  1.014e+00,  9.643e-01,  9.065e-01,  
			8.402e-01,  7.663e-01,  6.892e-01,  6.091e-01,  5.296e-01,  4.550e-01,  3.850e-01,  3.223e-01,  2.671e-01,  2.202e-01,  
			1.810e-01,  1.482e-01,  1.217e-01,  1.003e-01,  8.289e-02,  6.902e-02,  5.780e-02,  4.834e-02,  4.046e-02,  3.384e-02,  
			2.830e-02,  2.351e-02,  1.962e-02,  1.619e-02,  1.322e-02,  1.075e-02,  8.680e-03,  6.919e-03,  5.624e-03,  4.508e-03,  
			3.538e-03,  2.915e-03,  2.233e-03,  1.832e-03,  1.382e-03,  1.121e-03,  8.562e-04,  6.734e-04,  4.991e-04,  4.012e-04,  
			2.833e-04,  2.218e-04,  1.506e-04,  1.023e-04,  7.060e-05,  5.282e-05,  4.385e-05,  2.290e-05,  1.202e-05,  6.059e-06,  
			4.098e-06,  2.061e-06,  7.699e-07,  3.418e-07,  1.507e-07,  8.865e-08,  1.895e-08,  2.792e-08,  1.816e-08,  2.615e-09,  0.000e+00,  }; // TTToSemiLeptonic
   pileupweightsDn = { 0.000e+00,  1.091e+01,  4.288e+01,  1.632e+01,  1.032e+01,  7.892e+00,  5.683e+00,  4.086e+00,  3.057e+00,  2.285e+00,  
		      1.826e+00,  1.531e+00,  1.349e+00,  1.249e+00,  1.194e+00,  1.169e+00,  1.161e+00,  1.169e+00,  1.188e+00,  1.211e+00,  
		      1.226e+00,  1.233e+00,  1.230e+00,  1.210e+00,  1.183e+00,  1.147e+00,  1.112e+00,  1.080e+00,  1.053e+00,  1.034e+00,  
		      1.020e+00,  1.013e+00,  1.010e+00,  1.013e+00,  1.018e+00,  1.026e+00,  1.035e+00,  1.044e+00,  1.051e+00,  1.055e+00,  
		      1.054e+00,  1.045e+00,  1.030e+00,  1.004e+00,  9.672e-01,  9.247e-01,  8.727e-01,  8.155e-01,  7.534e-01,  6.903e-01,  
		      6.275e-01,  5.648e-01,  5.067e-01,  4.529e-01,  4.034e-01,  3.604e-01,  3.231e-01,  2.891e-01,  2.595e-01,  2.338e-01,  
		      2.119e-01,  1.921e-01,  1.761e-01,  1.607e-01,  1.459e-01,  1.325e-01,  1.199e-01,  1.073e-01,  9.796e-02,  8.821e-02,  
		      7.775e-02,  7.190e-02,  6.182e-02,  5.697e-02,  4.835e-02,  4.420e-02,  3.822e-02,  3.417e-02,  2.895e-02,  2.677e-02,  
		      2.188e-02,  1.996e-02,  1.591e-02,  1.278e-02,  1.049e-02,  9.408e-03,  9.417e-03,  5.965e-03,  3.820e-03,  2.364e-03,  
		      1.972e-03,  1.229e-03,  5.718e-04,  3.170e-04,  1.748e-04,  1.282e-04,  3.363e-05,  5.837e-05,  4.079e-05,  5.342e-06,  0.000e+00,  }; // TTToSemiLeptonic

	*pileupweight = pileupweights[nTrueInt];
	*pileupweightup = pileupweightsUp[nTrueInt];
	*pileupweightdn = pileupweightsDn[nTrueInt];

}


