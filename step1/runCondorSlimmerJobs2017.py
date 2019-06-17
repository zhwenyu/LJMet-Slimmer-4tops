import os,shutil,datetime,time,sys
import getpass
from glob import glob
from ROOT import *
execfile("./EOSSafeUtils.py")

start_time = time.time()

finalStateYear = 'singleLep2017' # CHANGE HERE
#IO directories must be full paths
relbase   = '/uscms_data/d3/wzhang/work/fwljmet_201905/CMSSW_10_2_10/' # CHANGE HERE
inputDir  = '/eos/uscms/store/user/lpcljm/FWLJMET102X_1lep2017_052219/' # CHANGE HERE
outputDir = '/eos/uscms/store/user/lpcljm/FWLJMET102X_1lep2017_4tops_06132019_step1/' # CHANGE HERE
condorDir = '/uscms_data/d3/wzhang/work/fwljmet_201905/CMSSW_10_2_10/src/LJMet-Slimmer-4tops/step1/logs/'+ finalStateYear +'/' # CHANGE HERE


runDir=os.getcwd()
# Can change the file directory if needed
#if '' not in shift: runDirPost = ''
#else: runDirPost = shift+'Files'
runDirPost = ''
print 'Files from',runDirPost

gROOT.ProcessLine('.x compileStep1.C')

cTime=datetime.datetime.now()
date='%i_%i_%i_%i_%i_%i'%(cTime.year,cTime.month,cTime.day,cTime.hour,cTime.minute,cTime.second)

inDir=inputDir[10:]
outDir=outputDir[10:]

print 'Getting proxy'
proxyPath=os.popen('voms-proxy-info -path')
proxyPath=proxyPath.readline().strip()

print 'Starting submission'
count=0

dirList = [
#'TT_Mtt-700to1000_TuneCP5_PSweights_13TeV-powheg-pythia8',
#'TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8'
]


for sample in dirList:
  os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir+sample)
  os.system('mkdir -p '+condorDir+sample)
  tmpcount = 0
  runlist = EOSlistdir(inputDir+sample+'/'+finalStateYear+'/')
  if len(runlist)>1: 
    print "Please check this sample %s! Or put it into special MC list. "%(sample)
    continue 
    
  for run in runlist :
    numlist = EOSlistdir(inputDir+sample+'/'+finalStateYear+ '/'+ run +'/')

    for num in numlist :
      numpath = inputDir+sample+'/'+finalStateYear+ '/'+ run +'/'+ num
      pathsuffix = numpath.split('/')[-3:]
      pathsuffix = '/'.join(pathsuffix)
      rootfiles = EOSlist_root_files(numpath)

      for i in range(0,len(rootfiles),20):
        count += 1
        tmpcount += 1
        idlist = (rootfiles[i].split('.')[0]).split('_')[-1]+' '
        for j in range(i+1,i+20):
            if j >= len(rootfiles): continue
            idlist += (rootfiles[j].split('.')[0]).split('_')[-1]+' '
        idlist = idlist.strip()
        print idlist

        dict={'RUNDIR':runDir, 'POST':runDirPost, 'INPATHSUFFIX':pathsuffix, 'CONDORDIR':condorDir, 'INPUTDIR':inDir, 'FILENAME':sample, 'CMSSWBASE':relbase, 'OUTPUTDIR':outDir, 'LIST':idlist, 'ID':tmpcount}
        jdfName=condorDir+'/%(FILENAME)s/%(FILENAME)s_%(ID)s.job'%dict
        print jdfName
        jdf=open(jdfName,'w')
        jdf.write(
            """use_x509userproxy = true
universe = vanilla
Executable = %(RUNDIR)s/makeStep1.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = %(RUNDIR)s/makeStep1.C, %(RUNDIR)s/%(POST)s/step1.cc, %(RUNDIR)s/%(POST)s/step1.h, %(RUNDIR)s/%(POST)s/step1_cc.d, %(RUNDIR)s/%(POST)s/step1_cc.so
Output = %(FILENAME)s_%(ID)s.out
Error = %(FILENAME)s_%(ID)s.err
Log = %(FILENAME)s_%(ID)s.log
Notification = Never
Arguments = "%(FILENAME)s %(FILENAME)s %(INPUTDIR)s/%(FILENAME)s/%(INPATHSUFFIX)s %(OUTPUTDIR)s/%(FILENAME)s '%(LIST)s'"
Queue 1"""%dict)
        jdf.close()
        os.chdir('%s/%s'%(condorDir,sample))
        os.system('condor_submit %(FILENAME)s_%(ID)s.job'%dict)
        os.system('sleep 0.5')                                
        os.chdir('%s'%(runDir))
        print count, "jobs submitted!!!"
#        break

# special MC which have ext
spdirList = [
#'TTWW_TuneCP5_13TeV-madgraph-pythia8'
]

for sample in spdirList:
  os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir+sample)
  os.system('mkdir -p '+condorDir+sample)
  tmpcount = 0
  runlist = EOSlistdir(inputDir+sample+'/'+finalStateYear+'/')

  for run in runlist :
    numlist = EOSlistdir(inputDir+sample+'/'+finalStateYear+ '/'+ run +'/')

    for num in numlist :
      numpath = inputDir+sample+'/'+finalStateYear+ '/'+ run +'/'+ num
      pathsuffix = numpath.split('/')[-3:]
      pathsuffix = '/'.join(pathsuffix)
      rootfiles = EOSlist_root_files(numpath)

      for i in range(0,len(rootfiles),20):
        count += 1
        tmpcount += 1
        idlist = (rootfiles[i].split('.')[0]).split('_')[-1]+' '
        for j in range(i+1,i+20):
            if j >= len(rootfiles): continue
            idlist += (rootfiles[j].split('.')[0]).split('_')[-1]+' '
        idlist = idlist.strip()
        print idlist

        dict={'RUNDIR':runDir, 'POST':runDirPost, 'DATETIME':run, 'INPATHSUFFIX':pathsuffix, 'CONDORDIR':condorDir, 'INPUTDIR':inDir, 'FILENAME':sample, 'CMSSWBASE':relbase, 'OUTPUTDIR':outDir, 'LIST':idlist, 'ID':tmpcount}
        jdfName=condorDir+'/%(FILENAME)s/%(FILENAME)s_%(ID)s.job'%dict
        print jdfName
        jdf=open(jdfName,'w')
        jdf.write(
            """use_x509userproxy = true
universe = vanilla
Executable = %(RUNDIR)s/makeStep1.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = %(RUNDIR)s/makeStep1.C, %(RUNDIR)s/%(POST)s/step1.cc, %(RUNDIR)s/%(POST)s/step1.h, %(RUNDIR)s/%(POST)s/step1_cc.d, %(RUNDIR)s/%(POST)s/step1_cc.so
Output = %(FILENAME)s_%(ID)s.out
Error = %(FILENAME)s_%(ID)s.err
Log = %(FILENAME)s_%(ID)s.log
Notification = Never
Arguments = "%(FILENAME)s %(FILENAME)s_%(DATETIME)s %(INPUTDIR)s/%(FILENAME)s/%(INPATHSUFFIX)s %(OUTPUTDIR)s/%(FILENAME)s '%(LIST)s'"
Queue 1"""%dict)
        jdf.close()
        os.chdir('%s/%s'%(condorDir,sample))
        os.system('condor_submit %(FILENAME)s_%(ID)s.job'%dict)
        os.system('sleep 0.5')                                
        os.chdir('%s'%(runDir))
        print count, "jobs submitted!!!"
#        break

# data
datadirList = [
'SingleElectron'
]


for sample in datadirList:
  os.system('eos root://cmseos.fnal.gov/ mkdir -p '+outDir+sample)
  os.system('mkdir -p '+condorDir+sample)
  tmpcount = 0 
  runlist = EOSlistdir(inputDir+sample+'/'+finalStateYear+'/')

  for run in runlist :
    numlist = EOSlistdir(inputDir+sample+'/'+finalStateYear+ '/'+ run +'/')
    
    for num in numlist :
      numpath = inputDir+sample+'/'+finalStateYear+ '/'+ run +'/'+ num
      pathsuffix = numpath.split('/')[-3:]
      pathsuffix = '/'.join(pathsuffix)
      rootfiles = EOSlist_root_files(numpath)
      print numpath

      for i in range(0,len(rootfiles),20):
        count += 1
        tmpcount += 1
        era = (rootfiles[i].split('_')[0])[-1]
        idlist = (rootfiles[i].split('.')[0]).split('_')[-1]+' '
        for j in range(i+1,i+20):
            if j >= len(rootfiles): continue
	    idlist += (rootfiles[j].split('.')[0]).split('_')[-1]+' '
        idlist = idlist.strip()
        print idlist
        dict={'RUNDIR':runDir, 'POST':runDirPost, 'ERA': era, 'INPATHSUFFIX':pathsuffix, 'CONDORDIR':condorDir, 'INPUTDIR':inDir, 'FILENAME':sample, 'CMSSWBASE':relbase, 'OUTPUTDIR':outDir, 'LIST':idlist, 'ID':tmpcount}
        jdfName=condorDir+'/%(FILENAME)s/%(FILENAME)s_%(ID)s.job'%dict
        print jdfName
        jdf=open(jdfName,'w')
        jdf.write(
            """use_x509userproxy = true
universe = vanilla
Executable = %(RUNDIR)s/makeStep1.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = %(RUNDIR)s/makeStep1.C, %(RUNDIR)s/%(POST)s/step1.cc, %(RUNDIR)s/%(POST)s/step1.h, %(RUNDIR)s/%(POST)s/step1_cc.d, %(RUNDIR)s/%(POST)s/step1_cc.so
Output = %(FILENAME)s_%(ID)s.out
Error = %(FILENAME)s_%(ID)s.err
Log = %(FILENAME)s_%(ID)s.log
Notification = Never
Arguments = "%(FILENAME)sRun2017%(ERA)s %(FILENAME)s%(ERA)s %(INPUTDIR)s/%(FILENAME)s/%(INPATHSUFFIX)s %(OUTPUTDIR)s/%(FILENAME)s '%(LIST)s'"
Queue 1"""%dict)
        jdf.close()
        os.chdir('%s/%s'%(condorDir,sample))
        os.system('condor_submit %(FILENAME)s_%(ID)s.job'%dict)
        os.system('sleep 0.5')
        os.chdir('%s'%(runDir))
        print count, "jobs submitted!!!"
#        break



print("--- %s minutes ---" % (round(time.time() - start_time, 2)/60))



