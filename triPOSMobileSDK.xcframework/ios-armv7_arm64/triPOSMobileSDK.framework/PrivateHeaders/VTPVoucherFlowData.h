///
/// \file VTPVoucherFlowData.h
///

#ifndef VTPVoucherFlowData_h
#define VTPVoucherFlowData_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import <Foundation/Foundation.h>

#import "VTPFlowData.h"
#import "VTPCardFlowData.h"
#import "VTPFinancialFlowData.h"
#import "VTPEBTVoucherFlowData.h"

@interface VTPVoucherFlowData : NSObject <VTPFlowData, VTPCardFlowData, VTPFinancialFlowData, VTPEBTVoucherFlowData>

@property (retain, nonatomic) VTPConfiguration *configuration;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPVoucherFlowData_h */
