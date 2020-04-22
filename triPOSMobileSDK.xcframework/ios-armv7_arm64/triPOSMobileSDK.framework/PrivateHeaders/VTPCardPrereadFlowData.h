///
///  \file VTPCardPrereadFlowData.h
///

#ifndef VTPCardPrereadFlowData_h
#define VTPCardPrereadFlowData_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import <Foundation/Foundation.h>

#import "VTPFlowData.h"
#import "VTPCardFlowData.h"
#import "VTPFinancialFlowData.h"
#import "VTPEmvFlowData.h"

@interface VTPCardPrereadFlowData : NSObject <VTPFlowData, VTPCardFlowData, VTPFinancialFlowData, VTPEmvFlowData>

@property (retain, nonatomic) VTPConfiguration *configuration;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPCardPrereadFlowData_h */
