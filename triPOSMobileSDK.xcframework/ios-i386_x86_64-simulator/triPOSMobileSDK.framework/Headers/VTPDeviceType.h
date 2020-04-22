///
/// \file VTPDeviceType.h
///

#ifndef VTPDeviceType_h
#define VTPDeviceType_h

///
/// \enum VTPDeviceType
///
typedef enum _VTPDeviceType
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPDeviceTypeMinimum,
#endif
    
    /// Null device
    VTPDeviceTypeNull = _VTPDeviceTypeMinimum,
    
    /// Ingenico RBA
    VTPDeviceTypeIngenicoRba,
    
    /// Ingenico RBA TCP/IP
    VTPDeviceTypeIngenicoRbaTcpIp,
    
    /// BBPOS Bluetooth
    VTPDeviceTypeBbPos,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPDeviceTypeMaximum
#endif
}   VTPDeviceType;

#endif /* VTPDeviceType_h */
