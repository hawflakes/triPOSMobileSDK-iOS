///
/// \file VXPTransactionSetup.h
///

#ifndef VXPTransactionSetup_h
#define VXPTransactionSetup_h

#import "VXPBase.h"
#import "VXPTransactionSetupDevice.h"
#import "VXPTransactionSetupMethod.h"

///
/// \class VXPTransactionSetup
/// \brief Transaction setup class
///
/// The transaction setup class is used to initiate a HostedPayments transaction.
///
@interface VXPTransactionSetup : VXPBase

///
/// \brief Transaction setup ID
///
/// Unique GUID generated by Express that identifies the tranaction setup ID. 
///
@property (retain, nonatomic) NSString *TransactionSetupID;

///
/// \brief Transaction setup methods
///
/// Specifies the transaction method used for the transaction.
///
@property (nonatomic) VXPTransactionSetupMethod TransactionSetupMethod;

///
/// \brief Device
///
/// Entry device used.
///
@property (nonatomic) VXPTransactionSetupDevice Device;

///
/// \brief Embedded
///
/// Specifies if the card entry page will be embedded in a application.
///
@property (nonatomic) VXPBooleanType Embedded;

///
/// \brief CVV required
///
/// Requires use to enter CVV2, CVC2, or CID values.
///
@property (nonatomic) VXPBooleanType CVVRequired;

///
/// \brief Auto return
///
/// Specifies if the approval page will be automatically returned to the ReturnURL.
///
@property (nonatomic) VXPBooleanType AutoReturn;

///
/// \brief Company name
///
/// Name of the merchant.
///
@property (retain, nonatomic) NSString *CompanyName;

///
/// \brief Logo URL
///
/// HTTPS URL of the merchant logo.
///
@property (retain, nonatomic) NSString *LogoURL;

///
/// \brief Tag line
///
/// Text displayed next to the logo.
///
@property (retain, nonatomic) NSString *Tagline;

///
/// \brief Welcome message
///
/// Text to display to customer. If not provided, a generic message will be displayed.
///
@property (retain, nonatomic) NSString *WelcomeMessage;

///
/// \brief Return URL
///
/// Return URL link displayed after the transaction is completed or cancelled.
///
@property (retain, nonatomic) NSString *ReturnURL;

///
/// \brief Return URL title
///
/// Text to diplay for return URL. If not provided, "Return to merchant" will be displayed.
///
@property (retain, nonatomic) NSString *ReturnURLTitle;

///
/// \brief Order details
///
/// Text to describe purchase or detail information.
///
@property (retain, nonatomic) NSString *OrderDetails;

///
/// \brief Process transaction title
///
/// Text to describe submit button.
///
@property (retain, nonatomic) NSString *ProcessTransactionTitle;

///
/// \brief Validation code
///
/// Unique coded returned from a TransactionSetup request and as part of the query string redirect during a successful Hosted Payments request.
///
@property (retain, nonatomic) NSString *ValidationCode;

///
/// \enum VXPDeviceInputCode
///
typedef enum _VXPDeviceInputCode
    {
    /// This field is not used
    VXPDeviceInputCodeNotSet = VXPEnumNotSet,
    /// Not used
    VXPDeviceInputCodeNotUsed = 0,
    /// Unknown
    VXPDeviceInputCodeUnknown,
    /// Terminal
    VXPDeviceInputCodeTerminal,
    /// Keyboard
    VXPDeviceInputCodeKeyboard,
    }   VXPDeviceInputCode;

///
/// \brief Device input code
///
/// Specifies the entry device input type used for the transaction.
///
@property (nonatomic) VXPDeviceInputCode DeviceInputCode;

@end

#endif /* VXPTransactionSetup_h */
