///
/// \file VPDInitializationParameters.h
///

#ifndef VPDInitializationParameters_h
#define VPDInitializationParameters_h

#import <Foundation/Foundation.h>

#import "VTPEmvConfiguration.h"
#import "VTPAidPreference.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface VPDInitializationParameters : NSObject

///
/// \brief Gets or sets the idle prompt
///
/// This property is prompt displayed on the device when idle. This value may be nil.
///
@property (retain, nonatomic) NSString *idlePrompt;

///
/// \brief Gets or sets the terminal ID
///
/// This property gets or sets the terminal ID.
///
@property (retain, nonatomic) NSString *terminalId;

///
/// \brief Gets or sets if contactless entry is allowed
///
/// This property gets or sets if contactless entry is allowed.
///
@property (nonatomic) BOOL isContactlessEntryAllowed;

///
/// \brief Gets or sets if EMV is supported.
///
/// This property gets or sets if EMV is supported.
///
@property (nonatomic) BOOL isEmvAllowed;

///
/// \brief Gets or sets the EMV configuration
///
/// This property gets or sets the EMV configuration.
///
@property (retain, nonatomic) VTPEmvConfiguration *emvConfiguration;

///
/// \brief Gets or sets the device reboot time hour component
///
/// This property gets or sets the device reboot time hour component. This value should be 0-23.
///
@property (nonatomic) int rebootTimeHour;

///
/// \brief Gets or sets the device reboot time minutes component
///
/// This property gets or sets the device reboot time minutes component. This value should be 0-59.
///
@property (nonatomic) int rebootTimeMinutes;

///
/// \brief Gets or sets if Quick Chip is supported.
///
/// This property gets or sets if Quick Chip is supported.
///
@property (nonatomic) BOOL quickChipEnabled;

///
/// \brief Sets the preferred default AID selection.
///
/// This property sets the preferred default AID selection. The default value prompts the card holder if multiple AID's exist on the card. Other values prefer the US Common Debit AID or the global AID.
///
@property (assign, nonatomic) VTPAidPreference aidPreference;

///
/// \brief Specifies if we are connecting certification/test.
///
/// This property lets us know if we are running in a production environment.  If it is NO we are running in a production environment.
///
@property (assign, nonatomic) BOOL testCertification;


@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDInitializationParameters_h */
