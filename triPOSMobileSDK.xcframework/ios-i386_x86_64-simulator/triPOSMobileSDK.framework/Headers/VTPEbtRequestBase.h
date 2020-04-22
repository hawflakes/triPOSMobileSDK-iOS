///
/// \file VTPEbtRequestBase.h
///

#ifndef VTPEbtRequestBase_h
#define VTPEbtRequestBase_h

#import "VTPCardHolderPresentCode.h"

///
/// \protocol VTPEbtRequestBase
///
/// \brief The base protocol for all EBT requests
///
@protocol VTPEbtRequestBase

///
/// \brief Gets or sets the cardholder present code
///
/// Gets or sets the location of the cardholder at the time of the transaction.
///
@property (nonatomic) VTPCardHolderPresentCode cardholderPresentCode;

///
/// \brief Gets or sets the clerk number
///
/// Gets or sets the identifier for the clerk performing the transaction.
///
@property (retain, nonatomic) NSString *clerkNumber;

///
/// \brief Gets or sets the reference number
///
/// Gets or sets the user assigned reference number.
///
@property (retain, nonatomic) NSString *referenceNumber;

///
/// \brief Gets or sets the shift ID
///
/// Gets or sets the identifier for the shift during which the transaction in performed.
///
@property (retain, nonatomic) NSString *shiftID;

///
/// \brief Gets or sets the ticket number
///
/// Gets or sets the ticket number used for direct marketing, mail/telephone order, and e-commerce transactions. Required when the card number is manually keyed.
///
@property (retain, nonatomic) NSString *ticketNumber;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
-(void)normalizeAmounts;
#endif

@end


#endif /* VTPEbtRequestBase_h */
