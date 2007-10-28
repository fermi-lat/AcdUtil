/** 
* @file AcdUtil_load.cxx
* @brief This is needed for forcing the linker to load all components
* of the library.
*
*  $Header: /nfs/slac/g/glast/ground/cvs/AcdUtil/src/Dll/AcdUtil_load.cxx,v 1.2 2006/04/17 19:05:55 echarles Exp $
*/

#include "GaudiKernel/DeclareFactoryEntries.h"

DECLARE_FACTORY_ENTRIES(AcdUtil) {
    DECLARE_SERVICE( AcdGeometrySvc );
    DECLARE_SERVICE( AcdCalibSvc );
    DECLARE_SERVICE( AcdSimCalibSvc );
    DECLARE_ALGORITHM( TestAcdUtil );
} 

