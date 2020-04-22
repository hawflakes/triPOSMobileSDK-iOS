//
//  VTPDeviceInteractionDelegate.h
//  triPOSMobileSDK
//
//  Created by Eric Mattison on 7/12/18.
//  Copyright © 2018 Vantiv Inc. All rights reserved.
//

#ifndef VTPDeviceInteractionDelegate_h
#define VTPDeviceInteractionDelegate_h

#import "VTPSelectionType.h"
#import "VTPNumericInputType.h"
#import "VPDChoiceInput.h"
#import "VPDYesNoInput.h"
#import "VPDKeyboardNumericInput.h"

@protocol VTPDeviceInteractionDelegate<NSObject>

-(void) onSelectionWith:(NSArray *) choices for:(VTPSelectionType) selectionType completionHandler:(VPDChoiceInputCompletionHandler)completionHandler;

-(void) onAmountConfirmation:(NSDecimalNumber *) amount completionHandler:(VPDYesNoInputCompletionHandler)completionHandler;

-(void)onNumericInput:(VTPNumericInputType) numericInputType completionHandler:(VPDKeyboardNumericInputCompletionHandler) completionHandler;

-(void)onDisplayText:(NSString *) text;

-(void)onSelectApplication:(NSArray *) applications completionHandler:(VPDChoiceInputCompletionHandler)completionHandler;

-(void)onRemoveCard;

@end

#endif /* VTPDeviceInteractionDelegate_h */
