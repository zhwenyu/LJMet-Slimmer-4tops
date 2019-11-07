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
            else if (fabs(eta) < 0.8) return 0.996
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

