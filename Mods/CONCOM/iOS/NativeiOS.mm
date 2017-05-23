//
//  NativeiOSDownloadThread.m
//  Unity-iPhone
//
//  Created by red on 2015. 6. 7..
//
//

#import <Foundation/Foundation.h>
#import "NativeiOS.h"
#import "TCBlobDownloadManager.h"
#import "InAppPurchaseManager.h"

#include "UnityAppController.h"

NSString* CreateNSString(const char* string)
{
    if (string)
        return [NSString stringWithUTF8String: string];
    else
        return [NSString stringWithUTF8String: ""];
}

extern "C" void NativeiOSGet3DTouchType()
{
    extern NSString* _touchType;
    if (_touchType == NULL || _touchType == nil)
        return;

    NSLog(@"Call iOS Native3DTouchType() %@.", _touchType);
    UnitySendMessage("NativeManager", "Receive3DTouchType", [_touchType UTF8String]);
}

extern "C" void NativeiOSGetFilePath(const char* fileName)
{
    NSString *strFileName = CreateNSString(fileName);
    NSString *path = [[NSBundle mainBundle] pathForResource:strFileName ofType:@"dat"];
    if (path != nil)
        UnitySendMessage("AssetBundleManager", "SetNativeBundleFilePath", [path UTF8String]);
    else
        UnitySendMessage("AssetBundleManager", "SetNativeBundleFilePath", "failure");
}

extern "C" void NativeiOSDownloadThread(const char* url, const char* localPath, const char* type)
{
    NSString *strUrl = CreateNSString(url);
    NSString *strLocalPath = CreateNSString(localPath);
    
    NSRange range1 = [strLocalPath rangeOfString:@"/" options:NSBackwardsSearch range:NSMakeRange(0, strLocalPath.length)];
    if (range1.location != NSNotFound)
    {
        strLocalPath = [strLocalPath stringByReplacingCharactersInRange:NSMakeRange(range1.location, strLocalPath.length - range1.location) withString:@""];
    }
    
    TCBlobDownloadManager *sharedManager = [TCBlobDownloadManager sharedInstance];

    [sharedManager startDownloadWithURL:[NSURL URLWithString:strUrl]
        customPath:strLocalPath
        firstResponse:^(NSURLResponse *response) {

        }
        progress:^(uint64_t receivedLength, uint64_t totalLength, NSInteger remainingTime, float progress) {
            NSString *result = [NSString stringWithFormat:@"%@/%@", [[NSNumber numberWithInt:receivedLength] stringValue], [[NSNumber numberWithInt:totalLength] stringValue]];
            
            UnitySendMessage("NativeManager", "ReceiveProgressChanged", [result UTF8String]);
        }
        error:^(NSError *error) {

        }
        complete:^(BOOL downloadFinished, NSString *pathToFile) {
            UnitySendMessage("NativeManager", "ReceiveCompleted", "1");
        }];
}

#pragma mark -
#pragma mark In-App Purchase methods

extern "C" void NativeiOSQueryPurchaseFinished()
{
    InAppPurchaseManager *inAppPurchaseManager = [InAppPurchaseManager sharedInstance];
    if ([inAppPurchaseManager canMakePurchases] == false)
    {
        UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"App 내 구입 차단" message:@"App 내 구입이 차단 되어 있습니다.\n 설정 -> 일반 -> 차단" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil] autorelease];
        [alert show];
        
        UnitySendMessage("PurchaseManager", "OnUncompletedPurchase", "cancel");
        return;
    }
    
    [inAppPurchaseManager loadStore];
    
    //[inAppPurchaseManager queryPurchaseFinished];
    
    UnitySendMessage("PurchaseManager", "OnUncompletedPurchase", "ok");
}

extern "C" void NativeiOSLaunchPurchase(const char* pid)
{
    InAppPurchaseManager *inAppPurchaseManager = [InAppPurchaseManager sharedInstance];
    [inAppPurchaseManager launchPurchase:CreateNSString(pid)];
}

extern "C" void NativeiOSConsumePurchase(const char* pid)
{
    InAppPurchaseManager *inAppPurchaseManager = [InAppPurchaseManager sharedInstance];
    [inAppPurchaseManager consumeTransaction:CreateNSString(pid)];
}

extern "C" void NativeiOSFinishPurchase()
{
    InAppPurchaseManager *inAppPurchaseManager = [InAppPurchaseManager sharedInstance];
    [inAppPurchaseManager UnloadStore];
}