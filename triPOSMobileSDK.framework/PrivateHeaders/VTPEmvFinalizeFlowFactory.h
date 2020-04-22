///
/// \file VTPEmvFinalizeFlowFactory.h
///

#import <Foundation/Foundation.h>

#ifndef VTPEmvFinalizeFlowFactory_h
#define VTPEmvFinalizeFlowFactory_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTPEmv.h"
#import "VTPEmvFinalizeFlow.h"

@interface VTPEmvFinalizeFlowFactory : NSObject

+(NSObject<VTPFlow> *)processorFlowWithData:(NSObject<VTPFlowData> *)data;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPEmvFinalizeFlowFactory_h */
