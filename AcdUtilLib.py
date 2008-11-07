# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/AcdUtil/AcdUtilLib.py,v 1.2 2008/07/11 00:32:26 glast Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['AcdUtil'])
    env.Tool('addLibrary', library = ['AcdUtilCommon'])
    env.Tool('CalibDataLib')
    env.Tool('geometryLib')
    env.Tool('xmlBaseLib')
    env.Tool('EventLib')
    env.Tool('GlastSvcLib')
def exists(env):
    return 1;
