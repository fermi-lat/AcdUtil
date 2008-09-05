# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/AcdUtil/SConscript,v 1.10 2008/09/03 18:32:09 glastrm Exp $
# Authors: Heather Kelly <heather@slac.stanford.edu>, Eric Charles <echarles@slac.stanford.edu>
# Version: AcdUtil-02-08-08
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('AcdUtilLib', depsOnly = 1)
testAcdUtilObj = libEnv.SharedObject('src/test/TestAcdUtil.cxx')
AcdUtilCommon = libEnv.StaticLibrary('AcdUtilCommon', ['src/AcdTileDim.cxx', 'src/AcdRibbonDim.cxx',
                                                      'src/AcdTileFuncs.cxx', 'src/AcdFrameUtil.cxx',
                                                      'src/AcdCalibFuncs.cxx', 'src/RayDoca.cxx'])
AcdUtil = libEnv.SharedLibrary('AcdUtil', ['src/AcdGeometrySvc.cxx', 'src/AcdDetectorList.cxx', 'src/AcdCalib.cxx',
                                           'src/AcdCalibMgr.cxx', 'src/AcdCalibSvcBase.cxx', 'src/AcdCalibSvc.cxx',
                                           'src/AcdSimCalibSvc.cxx', 'src/IAcdCalibSvc.cxx'] + listFiles(['src/Dll/*.cxx']) + [testAcdUtilObj])

progEnv.Tool('AcdUtilLib')
test_AcdUtil = progEnv.GaudiProgram('test_AcdUtil',[testAcdUtilObj], test = 1)

progEnv.Tool('registerObjects', package = 'AcdUtil', libraries = [AcdUtilCommon, AcdUtil], testApps = [test_AcdUtil], includes = listFiles(['AcdUtil/*.h']))
