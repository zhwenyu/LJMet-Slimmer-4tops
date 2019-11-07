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
    // Top tagging efficiencies TO-BE-UPDATED !!!!!!!
    const int Nbin = 9;
    double ptMins[Nbin] = {400,450,500,550,600,700,800,1000,1200};
    double ttbarEff[Nbin] = {0.710731908673,0.911246812099,0.946258231276,0.950948087531,0.952308954524,0.947643078335,0.94133549608,0.929334428924,0.924661246612};
    double STEff[Nbin] = {0.691643703728,0.906228313671,0.941468696261,0.948002294016,0.947021636542,0.941775836972,0.933049300061,0.936046511628,0.933862433862};
    double ttttEff[Nbin] = {0.710731908673,0.911246812099,0.946258231276,0.950948087531,0.952308954524,0.947643078335,0.94133549608,0.929334428924,0.924661246612};
    double x53x53Eff[12][Nbin] = {//X53X53
     {0.724620303757,0.899211846191,0.936291859515,0.944579091937,0.94692371772,0.945789586458,0.935492651062,0.913173652695,0.90977443609},//700
     {0.720768101761,0.907892004154,0.937210055022,0.945094294581,0.944494920294,0.941136208077,0.93661971831,0.924356223176,0.930051813472},//800
     {0.724299065421,0.904784643301,0.937938576506,0.940539456533,0.944067043362,0.943750614613,0.939160329201,0.925230671333,0.920143884892},//900
     {0.723555888972,0.891038887845,0.93702487906,0.943868050013,0.9433296466,0.941325202647,0.933387610095,0.930462184874,0.920435510888},//1000
     {0.706017891027,0.891839315242,0.929181103693,0.945251210149,0.946220930233,0.943065231159,0.936117240989,0.930840845279,0.918595371109},//1100
     {0.706572416905,0.885974797664,0.923103809857,0.938941876579,0.943281477238,0.942451135188,0.935289623871,0.926310160428,0.918116871222},//1200
     {0.703368526898,0.873433303491,0.920978890342,0.936481121716,0.942840429532,0.941648216482,0.935452396142,0.926339285714,0.913049112349},//1300
     {0.687741686002,0.876234529316,0.917185109638,0.93502800517,0.93907257226,0.941280976676,0.929876038507,0.923884514436,0.91489965922},//1400
     {0.675073181716,0.87130710477,0.909954158481,0.928911723494,0.937305146274,0.940579646213,0.932647997164,0.921526157947,0.91551008728},//1500
     {0.679444301518,0.863857374392,0.909068746953,0.920785999386,0.932639746077,0.937310063385,0.933625327818,0.923361250175,0.914409413854},//1600
     {0.679444301518,0.863857374392,0.909068746953,0.920785999386,0.932639746077,0.937310063385,0.933625327818,0.923361250175,0.914409413854},//1700
     {0.679444301518,0.863857374392,0.909068746953,0.920785999386,0.932639746077,0.937310063385,0.933625327818,0.923361250175,0.914409413854}//1800
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
    // W TAGGING EFFICIENCIES NEED TO BE UPDATED!!!!!
    // W tagging efficiencies. Assumes each signal mass uses the same pT bins but has unique values.
    const int NbinB = 12;
    const int NbinS = 14;
    double ptMinsB[NbinB] = {175,200,250,300,350,400,450,500,550,600,700,800};
    double ptMinsS[NbinS] = {175,200,250,300,350,400,450,500,550,600,700,800,1000,1200};
    double ttbarEff[NbinB]= {0.562, 0.905, 0.944, 0.934, 0.923, 0.912, 0.899, 0.888, 0.883, 0.872, 0.841, 0.816}; // ttbar
    double STtEff[NbinB]  = {0.520, 0.901, 0.946, 0.933, 0.923, 0.906, 0.889, 0.869, 0.882, 0.855, 0.841, 0.875}; // single top (s and t channel had 0 boosted tops)
    double STtWEff[NbinB] = {0.543, 0.909, 0.952, 0.945, 0.940, 0.938, 0.932, 0.929, 0.933, 0.924, 0.916, 0.900}; // single top (s and t channel had 0 boosted tops)
    double WVEff[NbinB]   = {0.527, 0.909, 0.954, 0.946, 0.939, 0.939, 0.922, 0.929, 0.910, 0.928, 0.901, 0.914}; // WW, WZ, etc. 
    double ttttEff[NbinB] = {0.562, 0.905, 0.944, 0.934, 0.923, 0.912, 0.899, 0.888, 0.883, 0.872, 0.841, 0.816}; // tttt

    double x53x53Eff[12][NbinS] = {//X53X53
       {0.619, 0.915, 0.940, 0.936, 0.931, 0.928, 0.926, 0.916, 0.914, 0.906, 0.890, 0.864, 0.816, 0.772},//700
       {0.629, 0.920, 0.946, 0.939, 0.932, 0.931, 0.927, 0.925, 0.918, 0.914, 0.899, 0.878, 0.868, 0.833},//800
       {0.629, 0.917, 0.945, 0.939, 0.937, 0.933, 0.929, 0.924, 0.915, 0.916, 0.905, 0.889, 0.869, 0.839},//900
       {0.626, 0.919, 0.943, 0.939, 0.935, 0.935, 0.930, 0.927, 0.926, 0.917, 0.915, 0.899, 0.883, 0.869},//1000
       {0.638, 0.919, 0.945, 0.940, 0.936, 0.936, 0.932, 0.928, 0.923, 0.922, 0.913, 0.904, 0.890, 0.870},//1100
       {0.619, 0.916, 0.946, 0.939, 0.937, 0.934, 0.935, 0.931, 0.927, 0.920, 0.916, 0.905, 0.900, 0.872},//1200
       {0.619, 0.915, 0.948, 0.943, 0.938, 0.932, 0.935, 0.931, 0.927, 0.923, 0.917, 0.907, 0.895, 0.872},//1300
       {0.625, 0.920, 0.944, 0.941, 0.939, 0.937, 0.932, 0.933, 0.927, 0.925, 0.918, 0.909, 0.897, 0.884},//1400
       {0.653, 0.922, 0.950, 0.942, 0.936, 0.936, 0.933, 0.932, 0.929, 0.925, 0.919, 0.914, 0.897, 0.883},//1500
       {0.651, 0.924, 0.944, 0.939, 0.937, 0.935, 0.934, 0.930, 0.928, 0.927, 0.920, 0.913, 0.899, 0.890},//1600
       {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//1700
       {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000}//1800
       };     
    double TpTpEff[12][NbinS] = {//TpTp
       {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//700
       {0.626, 0.911, 0.936, 0.930, 0.925, 0.920, 0.914, 0.915, 0.909, 0.907, 0.898, 0.890, 0.878, 0.866},//800
       {0.622, 0.914, 0.940, 0.932, 0.925, 0.919, 0.914, 0.907, 0.908, 0.905, 0.899, 0.888, 0.878, 0.859},//900
       {0.619, 0.914, 0.938, 0.930, 0.927, 0.920, 0.918, 0.914, 0.908, 0.899, 0.900, 0.888, 0.884, 0.862},//1000
       {0.618, 0.911, 0.937, 0.930, 0.925, 0.920, 0.918, 0.918, 0.910, 0.906, 0.899, 0.886, 0.872, 0.877},//1100
       {0.637, 0.911, 0.943, 0.931, 0.922, 0.920, 0.918, 0.912, 0.906, 0.905, 0.898, 0.892, 0.877, 0.868},//1200
       {0.621, 0.909, 0.938, 0.930, 0.927, 0.923, 0.916, 0.912, 0.912, 0.904, 0.901, 0.891, 0.881, 0.873},//1300
       {0.641, 0.918, 0.935, 0.937, 0.924, 0.926, 0.917, 0.916, 0.914, 0.908, 0.903, 0.892, 0.884, 0.872},//1400
       {0.606, 0.917, 0.940, 0.936, 0.925, 0.925, 0.916, 0.915, 0.911, 0.910, 0.903, 0.895, 0.883, 0.876},//1500
       {0.650, 0.920, 0.935, 0.932, 0.929, 0.919, 0.918, 0.912, 0.911, 0.908, 0.900, 0.896, 0.887, 0.876},//1600
       {0.615, 0.915, 0.940, 0.934, 0.925, 0.921, 0.918, 0.912, 0.909, 0.910, 0.902, 0.895, 0.887, 0.872},//1700
       {0.627, 0.915, 0.938, 0.934, 0.929, 0.916, 0.912, 0.912, 0.911, 0.906, 0.901, 0.898, 0.887, 0.879}//1800
       };
    double BpBpEff[12][NbinS] = {//BpBp
       {1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000},//700
       {0.616, 0.919, 0.940, 0.933, 0.933, 0.924, 0.915, 0.915, 0.909, 0.903, 0.892, 0.871, 0.831, 0.795},//800
       {0.604, 0.919, 0.944, 0.937, 0.928, 0.926, 0.921, 0.916, 0.912, 0.909, 0.894, 0.876, 0.858, 0.830},//900
       {0.633, 0.915, 0.944, 0.935, 0.932, 0.930, 0.919, 0.917, 0.912, 0.905, 0.902, 0.890, 0.863, 0.839},//1000
       {0.619, 0.918, 0.944, 0.938, 0.933, 0.927, 0.926, 0.919, 0.916, 0.909, 0.899, 0.893, 0.869, 0.856},//1100
       {0.600, 0.914, 0.943, 0.937, 0.932, 0.927, 0.925, 0.918, 0.917, 0.914, 0.906, 0.892, 0.880, 0.857},//1200
       {0.613, 0.912, 0.943, 0.940, 0.934, 0.925, 0.923, 0.920, 0.918, 0.914, 0.909, 0.897, 0.888, 0.864},//1300
       {0.610, 0.919, 0.944, 0.938, 0.933, 0.927, 0.927, 0.921, 0.920, 0.913, 0.908, 0.900, 0.882, 0.873},//1400
       {0.626, 0.911, 0.959, 0.935, 0.936, 0.929, 0.927, 0.922, 0.915, 0.911, 0.903, 0.902, 0.882, 0.870},//1500
       {0.619, 0.925, 0.943, 0.941, 0.936, 0.927, 0.927, 0.920, 0.920, 0.914, 0.909, 0.900, 0.890, 0.880},//1600
       {0.653, 0.924, 0.945, 0.934, 0.932, 0.934, 0.925, 0.923, 0.918, 0.912, 0.911, 0.901, 0.889, 0.877},//1700
       {0.629, 0.924, 0.944, 0.945, 0.928, 0.929, 0.924, 0.923, 0.918, 0.915, 0.911, 0.902, 0.888, 0.886}//1800
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

