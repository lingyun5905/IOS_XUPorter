//
//  InAppPurchaseManager.h
//  Unity-iPhone
//
//  Created by red on 2015. 6. 11..
//
//

#ifndef Unity_iPhone_InAppPurchaseManager_h
#define Unity_iPhone_InAppPurchaseManager_h

#import <StoreKit/StoreKit.h>

#define kInAppPurchaseProductId_01 @"com.nexon.hxh_iap01"
#define kInAppPurchaseProductId_02 @"com.nexon.hxh_iap02"
#define kInAppPurchaseProductId_03 @"com.nexon.hxh_iap03"
#define kInAppPurchaseProductId_04 @"com.nexon.hxh_iap04"
#define kInAppPurchaseProductId_05 @"com.nexon.hxh_iap05"
#define kInAppPurchaseProductId_06 @"com.nexon.hxh_iap06"
#define kInAppPurchaseProductId_07 @"com.nexon.hxh_iap07"
#define kInAppPurchaseProductId_08 @"com.nexon.hxh_iap08"
#define kInAppPurchaseProductId_09 @"com.nexon.hxh_iap09"
#define kInAppPurchaseProductId_10 @"com.nexon.hxh_iap10"
#define kInAppPurchaseProductId_11 @"com.nexon.hxh_iap11"
#define kInAppPurchaseProductId_12 @"com.nexon.hxh_iap12"

@interface InAppPurchaseManager : NSObject <SKProductsRequestDelegate, SKPaymentTransactionObserver>
{
    SKProduct *proUpgradeProduct;
    SKProductsRequest *productsRequest;
    SKPaymentTransaction *paymentTransaction;
    BOOL isRestore;
}

@property (nonatomic, strong) NSOperationQueue *operationQueue;
+ (instancetype)sharedInstance;

- (void)loadStore;
- (void)UnloadStore;
- (BOOL)canMakePurchases;
- (void)launchPurchase:(NSString *)pid;
- (void)consumeTransaction:(NSString*)pid;

@end

#endif
