#!/bin/bash

infilename=${1}
outfilename=${2}
inputDir=${3}
outputDir=${4}

macroDir=${PWD}

source /cvmfs/cms.cern.ch/cmsset_default.sh
#export SCRAM_ARCH=slc7_amd64_gcc630
#
#scramv1 project CMSSW CMSSW_9_4_6_patch1
#cd CMSSW_9_4_6_patch1
export SCRAM_ARCH=slc6_amd64_gcc700
scramv1 project CMSSW CMSSW_10_2_10
cd CMSSW_10_2_10

eval `scramv1 runtime -sh`
cd -

export PATH=$PATH:$macroDir

echo " Make step2 start --- "
xrdDir=root://cmsxrootd.fnal.gov/${inputDir}
root -l -b -q makeStep2.C\(\"$macroDir\",\"$xrdDir/$infilename\",\"$outfilename\"\)

xrdcp $outfilename root://cmseos.fnal.gov/$outputDir/$outfilename
rm $outfilename
