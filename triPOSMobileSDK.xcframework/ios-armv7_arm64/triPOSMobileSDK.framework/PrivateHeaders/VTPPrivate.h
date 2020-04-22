///
/// \file VTPPrivate.h
///

#ifndef VTPPrivate_h
#define VTPPrivate_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTP.h"
#import "VTPConfiguration.h"
#import "VTPFlow.h"
#import "VTPStatus.h"
#import "VTPStoreDatabase.h"
#import "VTPCardPrereadFlowData.h"

@interface VTP()

@property (retain, nonatomic) NSObject<VTPFlow> *runningFlow;

@property (retain, nonatomic) NSObject<VTPStoreDatabase> *storeDatabase;

@property (retain, nonatomic) VTPCardPrereadFlowData *cardFlowData;

@property (nonatomic, strong) NSTimer * prereadDataTimer;

-(void)sendStatusChange:(VTPStatus)status;

-(void)sendSelectionWith:(NSArray *) choices for:(VTPSelectionType) selectionType completionHandler:(VPDChoiceInputCompletionHandler)completionHandler;

-(void)sendAmountConfirmation:(NSDecimalNumber *) amount completionHandler:(VPDYesNoInputCompletionHandler)completionHandler;

-(void)sendNumericInput:(VTPNumericInputType) numericInputType completionHandler:(VPDKeyboardNumericInputCompletionHandler) completionHandler;

-(void)sendDisplayText:(NSString *) text;

-(void)sendSelectionApplication:(NSArray *) applications completionHandler:(VPDChoiceInputCompletionHandler)completionHandler;

-(void)sendRemoveCard;

-(void)sendBatteryLow;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPPrivate_h */
