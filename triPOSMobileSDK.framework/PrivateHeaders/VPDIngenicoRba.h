///
/// \file VPDIngenicoRba.h
///

#ifndef VPDIngenicoRba_h
#define VPDIngenicoRba_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VPDBarcodeInput.h"
#import "VPDDevicePrivate.h"
#import "VTCTlvUtility.h"

@interface VPDIngenicoRba : VPDDevicePrivate <VPDDevicePrivate>

@property (retain, nonatomic) NSString *idleForm;

@property (nonatomic) BOOL ignoreConnectDisconnectNotifications;

@property (copy, nonatomic) VPDBarcodeInputCompletionHandler barcodeCompletionHandler;

@property (copy, nonatomic) VPDErrorHandler barcodeErrorHandler;

///
/// \brief Checks if the device is connected and calls the error handler if not
///
/// This method checks of the device is connected and calls the handler if not.
///
/// \return YES if not connected, NO otherwise.
///
-(BOOL)errorIfNotConnected:(VPDErrorHandler)errorHandler;

///
/// \brief Checks if the device is initialized and calls the error handler if not
///
/// This method checks of the device is initialized and calls the handler if not.
///
/// \return YES if not initialized, NO otherwise.
///
-(BOOL)errorIfNotInitialized:(VPDErrorHandler)errorHandler;

typedef void (^VPDIngenicoRbaMessageHandler)(NSInteger messageId);

@property (copy, nonatomic) VPDIngenicoRbaMessageHandler messageHandler;

@property (strong, nonatomic) VTCTlvCollection tagsWith33_02EmvTransactionPreparationResponseMessage;
@property (atomic) BOOL emvFlowStepSetPaymentTypeReached;

typedef enum _VPDIngenicoRbaWhatIsEnabled
{
    VPDIngenicoRbaWhatIsEnabledNothing,
    VPDIngenicoRbaWhatIsEnabledCardInput,
    VPDIngenicoRbaWhatIsEnabledChoiceInput,
    VPDIngenicoRbaWhatIsEnabledYesNoInput,
    VPDIngenicoRbaWhatIsEnabledPinInput,
    VPDIngenicoRbaWhatIsEnabledKeyboardNumericInput,
}   VPDIngenicoRbaWhatIsEnabled;

@property (nonatomic) VPDIngenicoRbaWhatIsEnabled whatIsEnabled;

@property (nonatomic) BOOL quickChipEnabled;

@property (atomic) BOOL authorizationResponseMessageWasSent;
@property (atomic) BOOL authorizationConfirmationMessageWasReceived;
@property (atomic) BOOL authorizationRequestMessageWasReceived;

@property (atomic, strong) NSDecimalNumber*  placeHolderAmount;

-(void)setUserInputTimer:(NSInteger) inputTimeout errorHandler:(VPDErrorHandler)errorHandler;

-(void)setNonUserInputTimer:(VPDErrorHandler)errorHandler;

-(void)startInputTimer;

-(void)stopInputTimer;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDIngenicoRba_h */
