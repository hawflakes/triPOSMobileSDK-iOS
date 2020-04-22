//
//  VTPEbtVoucherFlow.h
//  triPOSMobileSDK
//
//  Copyright © 2018 Worldpay, LLC. and/or its affiliates. All rights reserved.
//

#ifndef VTPEbtVoucherFlow_h
#define VTPEbtVoucherFlow_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTPFlow.h"
#import "VTPBaseFlow.h"
#import "VTPCardFlow.h"


@interface VTPEbtVoucherFlow : VTPBaseFlow <VTPFlow>

-(void)checkPrerequisites:(VTPFlowStepCompletionHandler)flowStepCompletionHandler;

-(void)runCardFlow:(VTPFlowStepCompletionHandler)flowStepCompletionHandler;

-(void)processCardData:(VTPFlowStepCompletionHandler)flowStepCompletionHandler;

-(void)getPaymentType:(VTPFlowStepCompletionHandler)flowStepCompletionHandler;

-(void)getEbtType:(VTPFlowStepCompletionHandler)flowStepCompletionHandler;

-(void)runTransactionSpecificFlow:(VTPFlowStepCompletionHandler)flowStepCompletionHandler;

-(void)runExpressFlow:(VTPFlowStepCompletionHandler)flowStepCompletionHandler;

-(void)finalize:(VTPFlowStepCompletionHandler)flowStepCompletionHandler;

-(void)cleanUp;

@end


#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPEbtVoucherFlow_h */
