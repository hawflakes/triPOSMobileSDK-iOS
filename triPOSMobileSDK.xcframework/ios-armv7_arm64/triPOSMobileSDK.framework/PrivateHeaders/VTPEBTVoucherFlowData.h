///
/// \file VTPEBTVoucherFlowData.h
///

#ifndef VTPEBTVoucherFlowData_h
#define VTPEBTVoucherFlowData_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTPFinancialRequestBase.h"
#import "VTPPaymentType.h"
#import "VTPEbtType.h"
#import "VTPTransactionStatus.h"
#import "VTPTransactionType.h"
#import "VXP.h"

@protocol VTPEBTVoucherFlowData

@property (retain, nonatomic) NSString *approvalNumber;

@property (retain, nonatomic) NSString *voucherNumber;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPEBTVoucherFlowData_h */
