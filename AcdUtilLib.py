# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/AcdUtil/AcdUtilLib.py,v 1.1 2008/07/09 21:13:40 glastrm Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['AcdUtil'])
    env.Tool('addLibrary', library = ['AcdUtilCommon'])
    env.Tool('CalibDataLib')
    env.Tool('geometryLib')
    env.Tool('xmlBaseLib')

def exists(env):
    return 1;
