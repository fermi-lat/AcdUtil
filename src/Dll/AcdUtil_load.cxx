/** 
* @file AcdUtil_load.cxx
* @brief This is needed for forcing the linker to load all components
* of the library.
*
*  $Header: /nfs/slac/g/glast/ground/cvs/AcdUtil/src/Dll/AcdUtil_load.cxx,v 1.1.1.1 2005/11/08 17:28:16 heather Exp $
*/

#include "GaudiKernel/DeclareFactoryEntries.h"

DECLARE_FACTORY_ENTRIES(AcdUtil) {
    DECLARE_SERVICE( AcdGeometrySvc );
    DECLARE_SERVICE( AcdCalibSvc );
    DECLARE_ALGORITHM( TestAcdUtil );
} 

