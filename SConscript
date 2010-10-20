# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/AcdUtil/SConscript,v 1.25.2.1 2010/10/08 04:04:24 heather Exp $
# Authors: Heather Kelly <heather@slac.stanford.edu>, Eric Charles <echarles@slac.stanford.edu>
# Version: AcdUtil-03-01-03-gr01
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()
cmpLibEnv = baseEnv.Clone()

testAcdUtilObj = libEnv.SharedObject('src/test/TestAcdUtil.cxx')
AcdUtilCommon = libEnv.StaticLibrary('AcdUtilCommon',
                                     ['src/AcdTileDim.cxx', 'src/AcdRibbonDim.cxx',
                                      'src/AcdTileFuncs.cxx', 'src/AcdFrameUtil.cxx',
                                      'src/AcdCalibFuncs.cxx', 'src/RayDoca.cxx'])

cmpLibEnv.Tool('addLinkDeps', package='AcdUtil', toBuild='component')
AcdUtil = cmpLibEnv.ComponentLibrary('AcdUtil',
                                     ['src/AcdGeometrySvc.cxx',
                                      'src/AcdDetectorList.cxx',
                                      'src/AcdCalib.cxx', 'src/AcdCalibMgr.cxx',
                                      'src/AcdCalibSvcBase.cxx','src/AcdCalibSvc.cxx',
                                      'src/AcdSimCalibSvc.cxx', 'src/IAcdCalibSvc.cxx',
                                      'src/AcdFailureModeSvc.cxx'] + [testAcdUtilObj])

progEnv.Tool('AcdUtilLib')
test_AcdUtil = progEnv.GaudiProgram('test_AcdUtil',[testAcdUtilObj], test = 1,
                                    package='AcdUtil')

progEnv.Tool('registerTargets', package = 'AcdUtil',
             staticLibraryCxts = [[AcdUtilCommon, libEnv]],
             libraryCxts = [[AcdUtil, cmpLibEnv]],
             testAppCxts = [[test_AcdUtil, progEnv]],
             includes = listFiles(['AcdUtil/*.h']),
             jo = listFiles(['src/*.txt']) + ['src/test/jobOptions.txt'])





