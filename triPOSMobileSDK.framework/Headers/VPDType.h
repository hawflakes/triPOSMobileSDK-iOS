///
/// \file VPDType.h
///

#ifndef VPDType_h
#define VPDType_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

typedef enum _VPDType
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VPDTypeMinimum,
#endif
    
    /// Null
    VPDTypeNull = _VPDTypeMinimum,
    
    /// Ingenico RBA
    VPDTypeIngenicoRba,
    
    /// Ingenico RBA, TCP/IP
    VPDTypeIngenicoRbaTcpIp,
    
    /// BBPOS Bluetooth
    VPDTypeBbPos,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VPDTypeMaximum
#endif
}   VPDType;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDType_h */
