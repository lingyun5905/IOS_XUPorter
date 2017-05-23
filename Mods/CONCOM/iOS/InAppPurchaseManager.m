//
//  InAppPurchaseManager.m
//  Unity-iPhone
//
//  Created by red on 2015. 6. 11..
//
//

#import <Foundation/Foundation.h>
#import "InAppPurchaseManager.h"

//#ifdef _DEBUG
//#define NSLog(...) NSLog(__VA_ARGS__)
//#else
//#define NSLog(...)
//#endif

#ifdef DEBUG
#define NSLog( s, ... ) NSLog( @"[%@ %s(%d)] %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __PRETTY_FUNCTION__, __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )
#else
#define NSLog( s, ... )
#endif

@implementation InAppPurchaseManager

#pragma mark -
#pragma mark - Init

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.operationQueue = [[NSOperationQueue alloc] init];
    }
    return self;
}

+ (instancetype)sharedInstance
{
    static dispatch_once_t onceToken;
    static id sharedManager = nil;
    dispatch_once(&onceToken, ^{
        sharedManager = [[[self class] alloc] init];
        [sharedManager setOperationQueueName:@"InAppPurchaseManager_SharedInstance_Queue"];
    });
    return sharedManager;
}

- (void)setOperationQueueName:(NSString *)name
{
    [self.operationQueue setName:name];
}

- (NSString*)base64forData:(NSData*)theData
{
    const uint8_t* input = (const uint8_t*)[theData bytes];
    NSInteger length = [theData length];
    
    static char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    
    NSMutableData* data = [NSMutableData dataWithLength:((length + 2) / 3) * 4];
    uint8_t* output = (uint8_t*)data.mutableBytes;
    
    NSInteger i;
    for (i=0; i < length; i += 3) {
        NSInteger value = 0;
        NSInteger j;
        for (j = i; j < (i + 3); j++) {
            value <<= 8;
            
            if (j < length) {
                value |= (0xFF & input[j]);
            }
        }
        
        NSInteger theIndex = (i / 3) * 4;
        output[theIndex + 0] =                    table[(value >> 18) & 0x3F];
        output[theIndex + 1] =                    table[(value >> 12) & 0x3F];
        output[theIndex + 2] = (i + 1) < length ? table[(value >> 6)  & 0x3F] : '=';
        output[theIndex + 3] = (i + 2) < length ? table[(value >> 0)  & 0x3F] : '=';
    }
    
    return [[[NSString alloc] initWithData:data encoding:NSASCIIStringEncoding] autorelease];
}


#pragma -
#pragma Public methods

- (void)loadStore
{
    [[SKPaymentQueue defaultQueue] addTransactionObserver:self];
    [[SKPaymentQueue defaultQueue] transactions];
    
    paymentTransaction = nil;
    isRestore = true;
}

- (void)UnloadStore
{
    [[SKPaymentQueue defaultQueue] removeTransactionObserver:self];
}

- (BOOL)canMakePurchases
{
    return [SKPaymentQueue canMakePayments];
}

- (void)launchPurchase:(NSString *)pid
{
    NSLog(@"HxH launchPurchase : %@", pid);
    
    SKPayment *payment = [SKPayment paymentWithProductIdentifier:pid];
    [[SKPaymentQueue defaultQueue] addPayment:payment];
    
    isRestore = false;
}

#pragma -
#pragma Purchase helpers

- (void)recordTransaction:(SKPaymentTransaction *)transaction
{
    NSLog(@"HxH called with function : recordTransaction (%@)", transaction.description);
    
    paymentTransaction = transaction;
}

- (void)finishTransaction:(SKPaymentTransaction *)transaction wasSuccessful:(BOOL)wasSuccessful
{
    NSLog(@"HxH called with function : finishTransaction (%@)", transaction.description);
    
    if (wasSuccessful)
    {
        NSLog(@"HxH called with function : finishTransaction (wasSuccessful is true)");
        
#if 0
        NSURL *receiptUrl = [[NSBundle mainBundle] appStoreReceiptURL];
        NSData *receiptData = [NSData dataWithContentsOfURL:receiptUrl];
        NSString *receiptBase64 = [receiptData base64EncodedStringWithOptions:0];
#else
        NSString* receiptBase64 = [self base64forData:transaction.transactionReceipt];
#endif
        NSMutableString *strJson = [NSMutableString stringWithCapacity: 1000];
        [strJson appendString:@"{ "];
        [strJson appendString:@"\"hxh_pid\" : "];
        [strJson appendString:@"\""];
        [strJson appendString:[[transaction payment] productIdentifier]];
        [strJson appendString:@"\", "];
        [strJson appendString:@"\"hxh_signedData\" : "];
        [strJson appendString:@"\""];
        [strJson appendString:receiptBase64];
        [strJson appendString:@"\""];
        [strJson appendString:@" }"];
        
        UnitySendMessage("PurchaseManager", "OnLaunchFinished", [strJson UTF8String]);
        
        NSLog(@"HxH called with function : finishTransaction ([strJson UTF8String] is %s)", [strJson UTF8String]);
    }
    else
    {
        NSLog(@"HxH called with function : finishTransaction (wasSuccessful is false)");
        
        [[SKPaymentQueue defaultQueue] finishTransaction:transaction];
        UnitySendMessage("PurchaseManager", "OnLaunchFinished", "failure");
    }
}

- (void)consumeTransaction:(NSString*)pid
{
    if (paymentTransaction != nil)
    {
        NSLog(@"HxH called with function : consumeTransaction (%@)", paymentTransaction.description);
        
        [[SKPaymentQueue defaultQueue] finishTransaction:paymentTransaction];
        UnitySendMessage("PurchaseManager", "OnConsumeFinished", "success");
        
        paymentTransaction = nil;
    }
    else
    {
        NSLog(@"HxH called with function : consumeTransaction (paymentTransaction == null)");
        
        UnitySendMessage("PurchaseManager", "OnConsumeFinished", "failure");
    }
}

- (void)finishUncompletedPurchase:(SKPaymentTransaction *)transaction
{
    NSString* receiptBase64 = [self base64forData:transaction.transactionReceipt];
    
    NSMutableString *strJson = [NSMutableString stringWithCapacity: 1000];
    [strJson appendString:@"{ "];
    [strJson appendString:@"\"hxh_pid\" : "];
    [strJson appendString:@"\""];
    [strJson appendString:[[transaction payment] productIdentifier]];
    [strJson appendString:@"\", "];
    [strJson appendString:@"\"hxh_signedData\" : "];
    [strJson appendString:@"\""];
    [strJson appendString:receiptBase64];
    [strJson appendString:@"\""];
    [strJson appendString:@" }"];
    
    UnitySendMessage("PurchaseManager", "OnUncompletedPurchase", [strJson UTF8String]);
    
    NSLog(@"HxH called with function : finishUncompletedPurchase (%s)", [strJson UTF8String]);
    
    [self recordTransaction:transaction];
}

- (void)completeTransaction:(SKPaymentTransaction *)transaction
{
    NSLog(@"HxH called with function : completeTransaction (%@)", transaction.description);
    
    [self recordTransaction:transaction];
    [self finishTransaction:transaction wasSuccessful:YES];
}

//- (void)restoreTransaction:(SKPaymentTransaction *)transaction
//{
//    [self recordTransaction:transaction];
//    [self finishTransaction:transaction wasSuccessful:YES];
//}

- (void)failedTransaction:(SKPaymentTransaction *)transaction
{
    NSLog(@"HxH called with function : failedTransaction (%@)", transaction.description);
    
    if (transaction.error.code != SKErrorPaymentCancelled)
    {
        NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> failedTransaction : transaction.error.code != SKErrorPaymentCancelled");
        
        // error!
        [self finishTransaction:transaction wasSuccessful:NO];
    }
    else
    {
        NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> failedTransaction : transaction.error.code == SKErrorPaymentCancelled");
        
        UnitySendMessage("PurchaseManager", "OnLaunchFinished", "cancel");
    }
}

#pragma mark -
#pragma mark SKPaymentTransactionObserver methods

//
// called when the transaction status is updated
//
- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions
{
    NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> updatedTransactions : transaction.description : %zd", transactions.count);
    
    for (SKPaymentTransaction *transaction in transactions)
    {
        switch (transaction.transactionState)
        {
            case SKPaymentTransactionStatePurchasing:
                NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SKPaymentTransactionStatePurchasing : transaction.error : %@", [transaction.error localizedDescription]);
                NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SKPaymentTransactionStatePurchasing : transaction.description : %@", transaction.description);
                break;
                
            case SKPaymentTransactionStatePurchased:
                if (isRestore)
                {
                    NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SKPaymentTransactionStatePurchased : isRestore is true");
                    
                    [self recordTransaction:transaction];
                    [self finishUncompletedPurchase:transaction];
                }
                else
                {
                    NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SKPaymentTransactionStatePurchased : isRestore is false");
                    
                    [self completeTransaction:transaction];
                }
                isRestore = true;
                break;
                
            case SKPaymentTransactionStateFailed:
                NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SKPaymentTransactionStateFailed : transaction.error : %@", [transaction.error localizedDescription]);
                NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SKPaymentTransactionStateFailed : transaction.description : %@", transaction.description);
                
                [[SKPaymentQueue defaultQueue] finishTransaction:transaction];
                [self failedTransaction:transaction];
                break;
                
            case SKPaymentTransactionStateRestored:
                NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SKPaymentTransactionStateRestored : transaction.error : %@", [transaction.error localizedDescription]);
                NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SKPaymentTransactionStateRestored : transaction.description : %@", transaction.description);
//                [self restoreTransaction:transaction];
                break;
                
            default:
                NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> default : transaction.error : %@", [transaction.error localizedDescription]);
                NSLog(@"HxH =>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> default : transaction.description : %@", transaction.description);
                break;
        }
    }
}

@end
