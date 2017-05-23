#import "UnityAppController.h"


#if UNISDK_CRASHHANDLE
#import "IOSCrashHandler/IOSCrashHandler.h"
#import "IOSCrashHandler/MyPostEntity.h"
#import "IOSCrashHandler/MyNetworkUtils.h"
#import "IOSCrashHandler/DeviceInfo.h"
#endif

#if UNISDK_GMFEEBACK
#import "UniSdkGMFeedBack.h"
#endif

#if UNISDK_NGSHARE
#import <NtShareSdkPlatform/NtShareSdkPlatform.h>
#endif

#import "UniHead.h"

#pragma mark __NtNotificationWrapper

static NSString *__GameObject = @"Main Camera";
static char* const __callBackFun = "OnSdkMsgCallback";

static NSString * const __callBackType = @"callbackType";
static NSString * const __code = @"code";
static NSString * const __data = @"data";

static NSString * const CALLBACKTYPE_OnFinishInit               = @"OnFinishInit";
static NSString * const CALLBACKTYPE_OnLoginDone                = @"OnLoginDone";
static NSString * const CALLBACKTYPE_OnLogoutDone               = @"onLogoutDone";
static NSString * const CALLBACKTYPE_OnLeaveSdk                 = @"OnLeaveSdk";
static NSString * const CALLBACKTYPE_OnOrderCheck               = @"OnOrderCheck";

static NSString * const CALLBACKTYPE_OnContinue                 = @"OnContinue";
static NSString * const CALLBACKTYPE_OnExitView                 = @"OnExitView";
static NSString * const CALLBACKTYPE_OnQueryFriendList          = @"OnQueryFriendList";
static NSString * const CALLBACKTYPE_OnQueryAvailablesInvitees  = @"OnQueryAvailablesInvitees";
static NSString * const CALLBACKTYPE_OnQueryMyAccount           = @"OnQueryMyAccount";
static NSString * const CALLBACKTYPE_OnApplyFriend              = @"OnApplyFriend";
static NSString * const CALLBACKTYPE_OnIsDarenUpdated           = @"OnIsDarenUpdated";
static NSString * const CALLBACKTYPE_OnQueryRank                = @"OnQueryRank";
static NSString * const CALLBACKTYPE_OnShare                    = @"OnShare";
static NSString * const CALLBACKTYPE_OnReceivedNotification     = @"OnReceivedNotification";

char* __makeCString(NSString* string);
NSString* __makeNSString(const char* cstring);
NSString* __makeJsonString(id dictionary);
NSDictionary* __makeOrderInfo2Dic(NtOrderInfo* info);

#if defined(__cplusplus)
extern "C"{
#endif
    extern void UnitySendMessage(const char *, const char *, const char *);
#if defined(__cplusplus)
}
#endif

NtOrderInfo *__lastOrder = nil;

@interface __NtNotificationWrapper : NSObject

@end
static __NtNotificationWrapper *__inst = nil;

@implementation __NtNotificationWrapper

+ (void) initialize
{
    if (__inst) {
        return;
    }

    __inst = [[__NtNotificationWrapper alloc] init];

    //初始化通知
    [[NSNotificationCenter defaultCenter] addObserver:__inst selector:@selector(finishInitNotification:) name:NT_NOTIFICATION_FINISH_INIT object:nil];

    //监听注册通知
    [[NSNotificationCenter defaultCenter] addObserver:__inst selector:@selector(registerNotification:) name:NT_NOTIFICATION_REGISTER object:nil];

    //注销通知
    [[NSNotificationCenter defaultCenter] addObserver:__inst selector:@selector(logoutNotification:) name:NT_NOTIFICATION_LOGOUT object:nil];

    //监听登录通知
    [[NSNotificationCenter defaultCenter] addObserver:__inst selector:@selector(loginNotification:) name:NT_NOTIFICATION_LOGIN object:nil];

    //管理视图关闭通知
    [[NSNotificationCenter defaultCenter] addObserver:__inst selector:@selector(closeManagerViewNotification:) name:NT_NOTIFICATION_CLOSE_MANAGERVIEW object:nil];

    //支付页面关闭通知
    [[NSNotificationCenter defaultCenter] addObserver:__inst selector:@selector(closePayViewNotification:) name:NT_NOTIFICATION_CLOSE_PAYVIEW object:nil];

    //暂停页面关闭通知
    [[NSNotificationCenter defaultCenter] addObserver:__inst selector:@selector(closePauseViewNotification:) name:NT_NOTIFICATION_CLOSE_PAUSEVIEW object:nil];

    //分享完成的通知
    [[NSNotificationCenter defaultCenter] addObserver:__inst selector:@selector(shareFinishedNotification:) name:NT_NOTIFICATION_FINSIH_SHARE object:nil];

    //用户界面有新的消息
    [[NSNotificationCenter defaultCenter] addObserver:__inst selector:@selector(userManagerViewHasNewMessage:) name:NT_NOTIFICATION_NEW_MESSAGE object:nil];
}


//初始化完成处理
- (void)finishInitNotification:(NSNotification *)notification
{
    NSLog(@"[NtUniSdk] Notification finishInit.");
    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],"NT_NOTIFICATION_FINISH_INIT","");

    NSMutableDictionary* msg = [NSMutableDictionary dictionary];

    [msg setObject:CALLBACKTYPE_OnFinishInit forKey:__callBackType];
    [msg setObject:[NSNumber numberWithInt:0] forKey:__code];
    [msg setObject:@"" forKey:__data];

    NSString* jsonStr = __makeJsonString(msg);

    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],__callBackFun, __makeCString(jsonStr));
}

//注册通知处理
- (void)registerNotification:(NSNotification *)notification
{
    NSLog(@"[NtUniSdk] Notification register.");
    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],"NT_NOTIFICATION_REGISTER","");

}

//登录通知处理
- (void)loginNotification:(NSNotification *)notification
{
    NSLog(@"[NtUniSdk] Notification login.");
    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],"NT_NOTIFICATION_LOGIN","");

    NSMutableDictionary* msg = [NSMutableDictionary dictionary];

    [msg setObject:CALLBACKTYPE_OnLoginDone forKey:__callBackType];
    [msg setObject:[NSNumber numberWithInt:0] forKey:__code];
    [msg setObject:@"" forKey:__data];

    NSString* jsonStr = __makeJsonString(msg);

    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],__callBackFun, __makeCString(jsonStr));
}

//注销通知处理
- (void)logoutNotification:(NSNotification *)notification
{
    NSLog(@"[NtUniSdk] Notification logout.");
    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],"NT_NOTIFICATION_LOGOUT","");

    NSMutableDictionary* msg = [NSMutableDictionary dictionary];

    [msg setObject:CALLBACKTYPE_OnLogoutDone forKey:__callBackType];
    [msg setObject:[NSNumber numberWithInt:0] forKey:__code];
    [msg setObject:@"" forKey:__data];

    NSString* jsonStr = __makeJsonString(msg);

    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],__callBackFun, __makeCString(jsonStr));
}

//支付视图关闭消息处理
- (void)closePayViewNotification:(NSNotification *)notification
{
    NSLog(@"[NtUniSdk] Notification closePayView.");
    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],"NT_NOTIFICATION_CLOSE_PAYVIEW","");

    // --- leaveSDK
    NSMutableDictionary* msg = [NSMutableDictionary dictionary];

    [msg setObject:CALLBACKTYPE_OnLeaveSdk forKey:__callBackType];
    [msg setObject:[NSNumber numberWithInt:0] forKey:__code];
    [msg setObject:@"" forKey:__data];

    NSString* jsonStr = __makeJsonString(msg);

    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],__callBackFun, __makeCString(jsonStr));

    if (notification.userInfo[NT_NOTIFICATION_INFO_ORDER]) {
       __lastOrder = notification.userInfo[NT_NOTIFICATION_INFO_ORDER];
    }

    // --- Checked
    NSDictionary *dic = [[NtSdkMgr getInst]getCheckedOrders];

    NtOrderInfo* o = [dic objectForKey:[__lastOrder getOrderId]];
    if(o)
    {
        [__lastOrder setTransactionReceipt: [o getTransactionReceipt]];
    }

    msg = [NSMutableDictionary dictionary];

    [msg setObject:CALLBACKTYPE_OnOrderCheck forKey:__callBackType];
    [msg setObject:[NSNumber numberWithInt:0] forKey:__code];
    [msg setObject:__makeOrderInfo2Dic(__lastOrder) forKey:__data];

    jsonStr = __makeJsonString(msg);

    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],__callBackFun, __makeCString(jsonStr));
}

//关闭管理窗口通知处理
- (void)closeManagerViewNotification:(NSNotification *)notification
{
    NSLog(@"[NtUniSdk] Notification closeManagerView.");
    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],"NT_NOTIFICATION_CLOSE_MANAGERVIEW","");

    NSMutableDictionary* msg = [NSMutableDictionary dictionary];

    [msg setObject:CALLBACKTYPE_OnLeaveSdk forKey:__callBackType];
    [msg setObject:[NSNumber numberWithInt:0] forKey:__code];
    [msg setObject:@"" forKey:__data];

    NSString* jsonStr = __makeJsonString(msg);

    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],__callBackFun, __makeCString(jsonStr));
}

//关闭暂停窗口通知处理
- (void)closePauseViewNotification:(NSNotification *)notification
{
    NSLog(@"[NtUniSdk] Notification closePauseView.");
    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],"NT_NOTIFICATION_CLOSE_PAUSEVIEW","");


    NSMutableDictionary* msg = [NSMutableDictionary dictionary];

    [msg setObject:CALLBACKTYPE_OnLeaveSdk forKey:__callBackType];
    [msg setObject:[NSNumber numberWithInt:0] forKey:__code];
    [msg setObject:@"" forKey:__data];

    NSString* jsonStr = __makeJsonString(msg);

    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],__callBackFun, __makeCString(jsonStr));
}

//分享完成的通知
- (void)shareFinishedNotification:(NSNotification *)notification {
    NSLog(@"shareFinishedNotification : \n %@",notification.userInfo);
    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],"NT_NOTIFICATION_FINSIH_SHARE","");

    NSMutableDictionary* msg = [NSMutableDictionary dictionary];
    NSDictionary* response = [notification userInfo];
    
    NSNumber* num = [response objectForKey:@"code"];
    [msg setObject:CALLBACKTYPE_OnShare forKey:__callBackType];
    [msg setObject:num forKey:__code];
    [msg setObject:[NSNumber numberWithBool:YES?num==0:NO] forKey:__data];

    NSString* jsonStr = __makeJsonString(msg);

    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],__callBackFun, __makeCString(jsonStr));
}

//用户界面有新的消息
- (void)userManagerViewHasNewMessage:(NSNotification *)notification {
    NSMutableDictionary* msg = [NSMutableDictionary dictionary];
    [msg setObject:CALLBACKTYPE_OnReceivedNotification forKey:__callBackType];
    [msg setObject:[NSNumber numberWithInt:0] forKey:__code];
    [msg setObject:[NSNumber numberWithBool:YES] forKey:__data];

    NSString* jsonStr = __makeJsonString(msg);

    UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],__callBackFun, __makeCString(jsonStr));
}

+ (void) doNothing{}

@end

struct __NtOrderInfo
{
    char* orderId;
    char* sdkOrderId;
    char* productId;
    float productCurrentPrice;
    int productCount;
    char* orderDesc;
    int orderStatus;
    char* orderErrReason;

    char* orderEtc;

    //--- 4 APP STORE IAP --- //
    char* transactionReceipt;
    char* userData;
};

#pragma mark - __NtSdkMgr_X

#if defined(__cplusplus)
extern "C"{
#endif

    char* __makeCString(NSString* string)
    {
        if (string == nil) {
            return NULL;
        }

        const char* cstring = [string cStringUsingEncoding:NSUTF8StringEncoding];

        if (NULL == cstring) {
            return NULL;
        }
        char* res = (char*)malloc(strlen(cstring)+1);
        strcpy(res, cstring);
        return res;
    }

    NSString* __makeNSString(const char* cstring)
    {
        if (cstring == NULL) {
            return nil;
        }

        NSString* nsstring = [[NSString alloc] initWithCString:cstring encoding:NSUTF8StringEncoding];

        return nsstring;
    }

    NSString* __makeJsonString(id dictionary)
    {
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject: dictionary
                                                           options:NSJSONWritingPrettyPrinted
                                                             error:nil];

        if ([jsonData length] > 0 )
        {
            NSString *jsonString = [[NSString alloc] initWithData:jsonData
                                                         encoding:NSUTF8StringEncoding];
            return jsonString;
        }

        NSLog(@"[NtUniSdk] __makeJsonString JsonError");
        return nil;
    }

    NSDictionary* __makeOrderInfo2Dic(NtOrderInfo* info)
    {
        // --- Checked
        NSMutableDictionary *order = [NSMutableDictionary dictionary];

        [order setObject: [info getOrderId]
                  forKey: @"orderId"];
        [order setObject: [info getSdkOrderId]
                  forKey: @"sdkOrderId"];
        [order setObject: [info getProductId]
                  forKey: @"pid"];
        [order setObject: [NSNumber numberWithFloat:[info getProductCurrentPrice]]
                  forKey: @"productCurrentPrice"];
        [order setObject: [NSNumber numberWithInt:[info getCount]]
                  forKey: @"productCount"];
        [order setObject: [info getOrderDesc]
                  forKey: @"orderDesc"];
        [order setObject: [NSNumber numberWithInt:[info getOrderStatus]]
                  forKey: @"orderStatus"];
        [order setObject: [info getOrderErrReason]?[info getOrderErrReason]:@""
                  forKey: @"orderErrReason"];
        [order setObject: @""
                  forKey: @"orderEtc"];
        [order setObject: [info getUserData]?[info getUserData]:@""
                  forKey: @"userData"];
        [order setObject: [[info getTransactionReceipt] base64Encoding]?[[info getTransactionReceipt] base64Encoding]:@""
                  forKey: @"transactionReceipt"];

        return order;
    }

    void __setCallbackModule(const char* cstring)
    {
        __GameObject = __makeNSString(cstring);
    }

    void __NtSdkMgr_setSdk(const char* cstring)
    {
#ifdef TARGET_NETEASEYIXIN
        [NtSdkMgr setSdk:__makeNSString(cstring)];
#endif
    }

    void __NtSdkMgr_ntInit()
    {
        [__NtNotificationWrapper doNothing];
        [NtSdkMgr ntInit];
    }

    void __NtSdkMgr_setDebugMode(int v)
    {
        [__NtNotificationWrapper doNothing];
        [[NtSdkMgr getInst] setDebugMode:v==1?YES:NO];
    }
    void __NtSdkMgr_ntLogin()
    {
        [__NtNotificationWrapper doNothing];
        [[NtSdkMgr getInst] ntLogin];
    }

    void __ntCheckOrder(const char* pid, const char* orderId, const char* orderEtc, const char* userData)
    {
        [__NtNotificationWrapper doNothing];
        __lastOrder = [NtOrderInfo new];

        [__lastOrder setOrderId:__makeNSString(orderId)];
        [__lastOrder setProductId:__makeNSString(pid)];

        //--- 4 APP STORE IAP --- //
        //[o setTransactionReceipt: __makeNSString(order.transactionReceipt)];
        [__lastOrder setUserData: __makeNSString(userData)];

        [[NtSdkMgr getInst]ntCheckOrder: __lastOrder];
    }

    void __NtSdkMgr_ntCheckOrder(const char* orderStr)
    {
        [__NtNotificationWrapper doNothing];
        __lastOrder = [NtOrderInfo new];

        NSString* orderJson = __makeNSString(orderStr);

        //将字符串写到缓冲区。
        NSData* jsonData = [orderJson dataUsingEncoding:NSUTF8StringEncoding];
        //解析json数据，使用系统方法 JSONObjectWithData:  options: error:
        NSDictionary* order = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableLeaves error:nil];

        if(order[@"orderId"]
           &&![order[@"orderId"] isEqualToString:@""])
        {
            [__lastOrder setOrderId:order[@"orderId"]];
        }
        [__lastOrder setSdkOrderId:order[@"sdkOrderId"]];
        [__lastOrder setProductId:order[@"pid"]];
        [__lastOrder setProductCurrentPrice:[order[@"productCurrentPrice"] floatValue]];
        [__lastOrder setCount:[order[@"productCount"] intValue]];
        [__lastOrder setOrderDesc:order[@"orderDesc"]];
        [__lastOrder setOrderStatus:[order[@"orderStatus"] intValue]];
        [__lastOrder setOrderErrReason:order[@"orderErrReason"]];

        //--- 4 APP STORE IAP --- //
        //[o setTransactionReceipt: __makeNSString(order.transactionReceipt)];
        [__lastOrder setUserData: order[@"userData"]];

        [[NtSdkMgr getInst]ntCheckOrder: __lastOrder];
    }

    void __NtSdkMgr_ntLogout()
    {
        [__NtNotificationWrapper doNothing];
        [[NtSdkMgr getInst] ntLogout];
    }

    void __NtSdkMgr_ntOpenManager()
    {
        [__NtNotificationWrapper doNothing];
        [[NtSdkMgr getInst] ntOpenManager];
    }

    void __NtSdkMgr_ntSetFloatBtnVisible(int v)
    {
        [__NtNotificationWrapper doNothing];
        [[NtSdkMgr getInst] ntSetFloatBtnVisible:v==1?YES:NO];
    }

    void __NtSdkMgr_ntOpenPauseView()
    {
        [__NtNotificationWrapper doNothing];
        [[NtSdkMgr getInst] ntOpenPauseView];
    }

    char* __NtSdkMgr_getPropStr(const char* prop)
    {
        [__NtNotificationWrapper doNothing];
        return __makeCString([[NtSdkMgr getInst] getPropStr: __makeNSString(prop)]);
    }

    void __NtSdkMgr_setPropStr(const char* prop, const char* val)
    {
        [__NtNotificationWrapper doNothing];
        [[NtSdkMgr getInst] setPropStr: __makeNSString(prop)
                                    as: __makeNSString(val)];
    }

    int __NtSdkMgr_getPropInt(const char* prop, int defaultVal)
    {
        [__NtNotificationWrapper doNothing];
        return [[NtSdkMgr getInst] getPropInt: __makeNSString(prop)  default: defaultVal];
    }

    void __NtSdkMgr_setPropInt(const char* prop, int val)
    {
        [__NtNotificationWrapper doNothing];
        [[NtSdkMgr getInst] setPropInt: __makeNSString(prop)
                                    as: val];
    }

    int __NtSdkMgr_hasFeature(const char* feature)
    {
        [__NtNotificationWrapper doNothing];
        return [[NtSdkMgr getInst] hasFeature:__makeNSString(feature)]==YES?1:0;
    }

    int  __NtSdkMgr_hasLogin()
    {
        [__NtNotificationWrapper doNothing];
        return [[NtSdkMgr getInst] hasLogin]==YES?1:0;
    }

    int  __NtSdkMgr_ntHasPlatform(const char* platform)
    {
#if UNISDK_NGSHARE
        [__NtNotificationWrapper doNothing];
        return [[NtShareMgr getInst] isPlatformInstalled:__makeNSString(platform)]==YES?1:0;
#endif
        return 0;
    }

    char* __NtSdkMgr_getChannel()
    {
        [__NtNotificationWrapper doNothing];
        return __makeCString([[NtSdkMgr getInst] getChannel]);
    }

    char* __NtSdkMgr_getPlatform()
    {
        [__NtNotificationWrapper doNothing];
        return __makeCString([[NtSdkMgr getInst] getPlatform]);
    }

    char* __NtSdkMgr_getAppChannel()
    {
        [__NtNotificationWrapper doNothing];
        return __makeCString([[NtSdkMgr getInst] getAppChannel]);
    }

    int __NtSdkMgr_getAuthType()
    {
        return [[NtSdkMgr getInst] getAuthType];
    }

    char* __NtSdkMgr_getUdid()
    {
        [__NtNotificationWrapper doNothing];
        return __makeCString([[NtSdkMgr getInst] getUdid]);
    }

    char* __NtSdkMgr_getSDKVersion(char* channel)
    {
        [__NtNotificationWrapper doNothing];
        return __makeCString([[NtSdkMgr getInst] getSDKVersion:__makeNSString(channel)]);
    }

    void __NtSdkMgr_exit()
    {
        [__NtNotificationWrapper doNothing];
        [[NtSdkMgr getInst] exit];
    }

    char* __NtSdkMgr_getCheckedOrders()
    {
        NSMutableArray* orders = [NSMutableArray array];

        /*
         //Test Case
         NSMutableDictionary *dic = [NSMutableDictionary dictionary];
         for(int i=0;i<4;i++){
         NtOrderInfo* o = [NtOrderInfo new];
         [o setSdkOrderId:__makeNSString("id")];
         [o setProductId:__makeNSString("id")];
         [o setProductCurrentPrice:10];
         [o setCount:1];
         [o setOrderDesc:__makeNSString("id")];
         [o setOrderStatus: 1];
         [o setOrderErrReason:__makeNSString("id")];

         [dic setObject:o forKey:[o getOrderId]];
         }
         */
        NSDictionary *dic = [[NtSdkMgr getInst] getCheckedOrders];

        for (NtOrderInfo* order in [dic allValues])
        {
            [orders addObject:__makeOrderInfo2Dic(order)];
        }

        return __makeCString(__makeJsonString(orders));
    }

    void __NtSdkMgr_removeCheckedOrders(char* OrderID)
    {
        [[NtSdkMgr getInst] removeCheckedOrders: __makeNSString(OrderID)];
    }

    void __NtSdkMgr_ntShowDaren()
    {
        [[NtSdkMgr getInst] ntShowDaren];
    }

    int __NtSdkMgr_ntIsDarenUpdated()
    {
        BOOL re = [[NtSdkMgr getInst] ntIsDarenUpdated];
        NSMutableDictionary* msg = [NSMutableDictionary dictionary];

        [msg setObject:CALLBACKTYPE_OnIsDarenUpdated forKey:__callBackType];
        [msg setObject:[NSNumber numberWithInt:0] forKey:__code];
        [msg setObject:[NSNumber numberWithBool:re] forKey:__data];

        NSString* jsonStr = __makeJsonString(msg);

        UnitySendMessage([__GameObject cStringUsingEncoding:NSUTF8StringEncoding],__callBackFun, __makeCString(jsonStr));
        return re==YES?1:0;
    }

    int __NtSdkMgr_ntHasNotification()
    {
        BOOL re = [[NtSdkMgr getInst] ntHasNotification];
        return re?1:0;
    }

    char* __NtSdkMgr_getPayChannelByPid(char* pid)
    {
        return __makeCString([[NtSdkMgr getInst] getPayChannelByPid: __makeNSString(pid)]);
    }

    void __NtSdkMgr_ntGuestBind()
    {
        [[NtSdkMgr getInst] ntGuestBind];
    }

    void __NtSdkMgr_ntUpLoadUserInfo()
    {
        [[NtSdkMgr getInst] ntUpLoadUserInfo];
    }

    void __NtOrderInfo_regProduct(const char* pId, const char* pName, float pPrice, int eRatio)
    {
        [NtOrderInfo regProduct:__makeNSString(pId) Name: __makeNSString(pName) Price:pPrice Ratio:eRatio];
    }

    int __NtOrderInfo_hasProduct(const char* pId)
    {
        return [NtOrderInfo hasProduct: __makeNSString(pId)]?1:0;
    }

    void __NtSdkMgr_ntShare(const char* shareStr)
    {
        [__NtNotificationWrapper doNothing];

        NSString* shareJson = __makeNSString(shareStr);

        //将字符串写到缓冲区。
        NSData* jsonData = [shareJson dataUsingEncoding:NSUTF8StringEncoding];
        //解析json数据，使用系统方法 JSONObjectWithData:  options: error:
        NSDictionary* share = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableLeaves error:nil];

        //NGSHARE
#if UNISDK_NGSHARE
        if ([NT_SHARE_PLATFORM_YIXIN isEqualToString:share[@"shareCommunity"]]
            || [NT_SHARE_PLATFORM_WEIXIN isEqualToString:share[@"shareCommunity"]]
            || [NT_SHARE_PLATFORM_WEIBO isEqualToString:share[@"shareCommunity"]]) {

            if(![[NtShareMgr getInst] isPlatformInstalled:share[@"shareCommunity"]])
            {
                return;
            }

            NtShareArgs* args = [[NtShareArgs alloc] init];
            if (![share[@"shareScope"] isKindOfClass:[NSNull class]] && [share[@"shareScope"] length]>0) {
                [args setArg: @([share[@"shareScope"] intValue]) forKey:NT_SHARE_SCENE];
            }
            
            if (![share[@"image"] isKindOfClass:[NSNull class]] && [share[@"image"] length]>0) {
                [args setArg: share[@"image"] forKey:NT_SHARE_IMG_URL];
            }
            if (![share[@"localImage"] isKindOfClass:[NSNull class]] && [share[@"localImage"] length]>0) {
                [args setArg: [UIImage imageWithContentsOfFile : share[@"localImage"]] forKey:NT_SHARE_IMG_DATA];
            }
            if (![share[@"shareType"] isKindOfClass:[NSNull class]] && [share[@"shareType"] length]>0) {
                [args setArg: share[@"shareType"] forKey:NT_SHARE_SCENE];
            }
            if (![share[@"text"] isKindOfClass:[NSNull class]] && [share[@"text"] length]>0) {
                [args setArg: share[@"text"] forKey:NT_SHARE_TEXT];
            }
            if (![share[@"title"] isKindOfClass:[NSNull class]] && [share[@"title"] length]>0) {
                [args setArg: share[@"title"] forKey:NT_SHARE_TITLE];
            }
            if (![share[@"desc"] isKindOfClass:[NSNull class]] && [share[@"desc"] length]>0) {
                [args setArg: share[@"desc"] forKey:NT_SHARE_COMMENT];
            }
            if (![share[@"link"] isKindOfClass:[NSNull class]] && [share[@"link"] length]>0) {
                [args setArg: share[@"link"] forKey:NT_SHARE_WEBPAGE_URL];
            }

            [[NtShareMgr getInst]share:args to: share[@"shareCommunity"]];

            return;
        }
#endif

        NtShareInfo* s = [[NtShareInfo alloc] init];
        s.shareType = [share[@"shareType"] intValue];
        s.shareCommunity = [share[@"shareCommunity"] intValue];
        s.toUser = share[@"toUser"];
        s.title = share[@"title"];
        s.text = share[@"text"];
        s.link = share[@"link"];
        s.image = share[@"image"];
        s.desc = share[@"desc"];
        [[NtSdkMgr getInst] ntShare:s];
    }


#if UNISDK_CRASHHANDLE

    // CrashHunter start
    void __NtSdkMgr_startCH()
    {
        IOSCrashHandler *crashHandle = [IOSCrashHandler getInstance];
        MyNetworkUtils *networkUtils = [crashHandle getNetworkUtils];
        MyPostEntity *defaultEntity = [networkUtils getDefaultPostEntity];

        [defaultEntity setParam:@"g1" forKey:@"project"];
        [defaultEntity setParam:@"内服8810(gc)" forKey:@"server_name"];
        [defaultEntity setParam:@"31295825@89" forKey:@"uid"];
        [defaultEntity setParam:@"Ⅲ冉玉坚á" forKey:@"username"];

        CrashCallBackBlock callbackBlock = [^(void) {
            [defaultEntity setFile:[@"ObjC call stack" dataUsingEncoding:NSUTF8StringEncoding]
                      withFileName:[NSString stringWithFormat:@"%@.stack", [crashHandle getCrashIdentity]]
                    withUploadType:@"text/plain"];
        } copy];

        //[[IOSCrashHandler getInstance] setEngineVersion:@"1.6.0"]; // 如第二部分所述，不一致时手动设置，在[crashHandle startCrashHandler];之前设置
        [crashHandle setCrashCallBack:callbackBlock]; // crash时回调函数，可用于上传dump信息之外的额外信息，如无必要可以不设
        [crashHandle startCrashHandler];

        /**
         * 这里可能还拿不到资源版本，但应尽早设置。
         * 如果在程序crash时还未设置，传unknown。
         */
        [[IOSCrashHandler getInstance] setResVersion:@"1.6.14"];
    }

    // CrashHunter setUserInfo
    void __NtSdkMgr_setCHUserInfo()
    {
        IOSCrashHandler *crashHandle = [IOSCrashHandler getInstance];
        MyNetworkUtils *networkUtils = [crashHandle getNetworkUtils];
        MyPostEntity *defaultEntity = [networkUtils getDefaultPostEntity];

        [defaultEntity setParam:[[NtSdkMgr getInst] getPropStr: NT_USERINFO_HOSTNAME] forKey:@"server_name"];
        [defaultEntity setParam:[[NtSdkMgr getInst] getPropStr: NT_UID] forKey:@"uid"];
        [defaultEntity setParam:[[NtSdkMgr getInst] getPropStr: NT_USERINFO_NAME] forKey:@"username"];
    }

    // CrashHunter
    char* __NtSdkMgr_postScriptDump(char* identify, char* content)
    {
        IOSCrashHandler *crashHandle = [IOSCrashHandler getInstance];
        MyNetworkUtils *networkUtils = [crashHandle getNetworkUtils];
        MyPostEntity *newEntity = [[[MyPostEntity alloc] initWithPostEntity:[networkUtils getDefaultPostEntity]] autorelease];
        [newEntity setParam:__makeNSString(identify) forKey:@"identify"];
        [newEntity setFile:[__makeNSString(content) dataUsingEncoding:NSUTF8StringEncoding]
              withFileName:[NSString stringWithFormat:@"%@.script", __makeNSString(identify)] withUploadType:@"text/plain"];
        [networkUtils postScriptError:newEntity];
        return "ok";
    }

    // CrashHunter
    char* __NtSdkMgr_postMessage(char* title, char* msg)
    {
        IOSCrashHandler *crashHandle = [IOSCrashHandler getInstance];
        MyNetworkUtils *networkUtils = [crashHandle getNetworkUtils];
        MyPostEntity *newEntity = [[[MyPostEntity alloc] initWithPostEntity:[networkUtils getDefaultPostEntity]] autorelease];

        [newEntity setParam:__makeNSString(title) forKey:@"identify"]; //不要以为网站显示的就是title，还是MD5码，有需求要可以让网站改下
        [newEntity setParam:@"OTHER" forKey:@"error_type"];
        [newEntity setFile:[__makeNSString(msg) dataUsingEncoding:NSUTF8StringEncoding]
              withFileName:[NSString stringWithFormat:@"%@.other", __makeNSString(title)] withUploadType:@"text/plain"];
        [networkUtils post:newEntity];
        return "ok";
    }
#endif

#if UNISDK_GMFEEBACK
    char* __NtSdkMgr_ntOpenGMView(char* url)
    {
        UniSdkGMFeedBack *GMFeeBack = [UniSdkGMFeedBack sharedInstance];
        [GMFeeBack showWebViewWithUrl:__makeNSString(url)];
        return "ok";
    }
#endif

#if defined(__cplusplus)
}
#endif
