///
/// \file VTPEmvFlowFactory.h
///

#import <Foundation/Foundation.h>

#ifndef VTPEmvFlowFactory_h
#define VTPEmvFlowFactory_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTPEmv.h"
#import "VTPEmvFlow.h"
#import "VTPEmvFinalizeFlow.h"

@interface VTPEmvFlowFactory : NSObject

+(NSObject<VTPFlow> *)processorFlowWithData:(NSObject<VTPFlowData> *)data;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPEmvFlowFactory_h */
