
#ifndef ACDGEOMETRYSVC_H
#define ACDGEOMETRYSVC_H 1

/** 
 * @class AcdGeometrySvc
 *
 * @brief Supplies the geometry constants and calculations for ACD 
 *
 * The constants all flow from GlastDetSvc.
 * 
 * @author Heather Kelly 
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/AcdUtil/src/AcdGeometrySvc.h,v 1.2.2.1 2006/02/13 22:18:55 usher Exp $
 */

#include "GaudiKernel/Service.h"

#include "AcdUtil/IAcdGeometrySvc.h"

#include "GlastSvc/GlastDetSvc/IGlastDetSvc.h"
#include "idents/VolumeIdentifier.h"
#include "idents/AcdId.h"

#include "geometry/Ray.h"
#include "geometry/Point.h"
#include "geometry/Vector.h"

#include "AcdUtil/AcdDetectorList.h"

class AcdGeometrySvc : public Service,
        virtual public IAcdGeometrySvc
{
public:
    
    AcdGeometrySvc(const std::string& name, ISvcLocator* pSvcLocator); 
    virtual ~AcdGeometrySvc() {}
    
    StatusCode initialize();
    StatusCode finalize();
    
    StatusCode queryInterface(const InterfaceID& riid, void** ppvUnknown);

    static const InterfaceID& interfaceID() {
        return IAcdGeometrySvc::interfaceID(); 
    }
    /// return the service type
    const InterfaceID& type() const;

    StatusCode getConstants();
    StatusCode getDetectorListFromGeometry();

    const AcdUtil::AcdDetectorList& getDetectorList() const { 
        return m_detectorCol; };

    bool findDetector(const idents::VolumeIdentifier &volId) const;

    int numTiles() const { return m_numTiles; };
    int numRibbons() const {return m_numRibbons; };
  
    StatusCode getCorners(const std::vector<double> &dim,
                          const HepPoint3D &center, HepPoint3D *corner);

    StatusCode getDimensions(const idents::VolumeIdentifier &volIId, 
                                    std::vector<double> &dims, 
                                    HepPoint3D &xT) const;

    StatusCode getDetectorDimensions(const idents::VolumeIdentifier &volIId, 
                                    std::vector<double> &dims, 
                                    HepPoint3D &xT) const;

    StatusCode findCornerGaps();
    const Ray getCornerGapRay(unsigned int index) const;

private:

    void clear();
    
    /// pointer to the detector service
    IGlastDetSvc *m_glastDetSvc;

    int m_numTiles, m_numRibbons;
    int m_numXtowers, m_numYtowers;

    Point m_cornerGapStartPoint[4], m_cornerGapEndPoint[4];
    Vector m_cornerGapVec[4];

    AcdUtil::AcdDetectorList m_detectorCol;
};

#endif // ACDGEOMETRYSVC_H
