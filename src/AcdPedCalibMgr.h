#ifndef PedMgr_H
#define PedMgr_H
// $Header: /nfs/slac/g/glast/ground/cvs/CalXtalResponse/src/CalCalib/PedMgr.h,v 1.7 2006/01/09 21:08:21 fewtrell Exp $
// LOCAL
#include "AcdCalibMgr.h"

// GLAST
#include "CalibData/Acd/AcdPed.h"
#include "CalibData/CalibModel.h"

// EXTLIB
// STD


class AcdCalibSvc;

/** @class AcdPedCalibMgr
    @author Eric Charles (from Zachary Fewtrell's CalCalib stuff)
    
    \brief Manage GLAST Acd pedestal calibration data
*/

class AcdPedCalibMgr : public AcdCalibMgr {
public:
  AcdPedCalibMgr() : 
    AcdCalibMgr(CalibData::ACD_Ped)
  {};
  
  /// get pedestal vals for given channel
  StatusCode getPed(idents::AcdId id, unsigned pmt,
		    CalibData::AcdPed*& pedestal) {
    
    // make sure we have valid calib data for this event.
    StatusCode sc;
    sc = updateCalib();
    if (sc.isFailure()) {
      // null and return failure code
      pedestal = 0;
      return sc;
    }
 
    // grab the data we need
    CalibData::RangeBase* base = m_calibBase->getPmt(id,pmt);    
    pedestal = static_cast<CalibData::AcdPed*>(base);

    // make sure that it really exists
    if (!pedestal) return StatusCode::FAILURE;
    
    return StatusCode::SUCCESS;
  }
  
private:
  
};

#endif
