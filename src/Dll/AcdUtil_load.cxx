/** 
* @file AcdUtil_load.cxx
* @brief This is needed for forcing the linker to load all components
* of the library.
*
*  $Header: /nfs/slac/g/glast/ground/cvs/AcdUtil/src/Dll/AcdUtil_load.cxx,v 1.3 2007/10/29 21:57:32 heather Exp $
*/

#include "GaudiKernel/DeclareFactoryEntries.h"

DECLARE_FACTORY_ENTRIES(AcdUtil) {
    DECLARE_SERVICE( AcdGeometrySvc );
    DECLARE_SERVICE( AcdCalibSvc );
    DECLARE_SERVICE( AcdSimCalibSvc );
    DECLARE_SERVICE( AcdFailureModeSvc );
    DECLARE_ALGORITHM( TestAcdUtil );
} 

