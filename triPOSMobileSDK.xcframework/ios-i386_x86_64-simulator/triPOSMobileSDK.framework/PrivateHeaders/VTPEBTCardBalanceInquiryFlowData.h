///
/// \file VTPEBTCardBalanceInquiryFlowData.h
///

#ifndef VTPEBTCardBalanceInquiryFlowData_h
#define VTPEBTCardBalanceInquiryFlowData_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTPFlowData.h"
#import "VTPCardFlowData.h"
#import "VTPFinancialFlowData.h"

@interface VTPEBTCardBalanceInquiryFlowData : NSObject <VTPFlowData, VTPCardFlowData, VTPFinancialFlowData>

@property (retain, nonatomic) VTPConfiguration *configuration;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPEBTCardBalanceInquiryFlowData_h */
