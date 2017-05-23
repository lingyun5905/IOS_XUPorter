//
//  UniSdkGMFeedBack.h
//  UniSdkGMFeedBack
//
//  Created by HuangZizhu on 12/8/14.
//  Copyright (c) 2014 HuangZizhu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "UniImagePicker.h"

//! Project version number for UniSdkGMFeedBack.
FOUNDATION_EXPORT double UniSdkGMFeedBackVersionNumber;

//! Project version string for UniSdkGMFeedBack.
FOUNDATION_EXPORT const unsigned char UniSdkGMFeedBackVersionString[];

#define theGMInst [UniSdkGMFeedBack sharedInstance]

//=====================================================================================
//          Delegate, SDK的回调，
//=====================================================================================
@protocol UniSdkGMFeedBackDelegate <NSObject>
//客服页面关闭
- (void)onGMWebviewWillClose;

//客服页面回退
- (void)onGMWebviewBack;

//token过期（或者没有token）需要请求新, 在更新token之前必须先设置角色的roleID
- (void)onInvalidToken;
@end




//=====================================================================================
//          Interface, 客服SDK的Public接口，
//=====================================================================================
@interface UniSdkGMFeedBack : NSObject
@property (nonatomic, weak) id<UniSdkGMFeedBackDelegate> delegate;//接收客服SDK回调的对象
@property (nonatomic, strong) NSString *appCode;//游戏公司内ID， 向客服后台咨询。
@property (nonatomic, strong) NSString *language;//SDK提示的语言（页面上的语言需要联系客服后台）
@property (nonatomic, weak) UIViewController *rootViewController;//请在不能正常显示web窗口时设置这个值（有一些特殊情况【有其他悬浮窗etc】时内部取不到正确的值）
@property (nonatomic, strong) NSString *roleID; //角色名，游戏内角色ID改变了这个值要重新设置。
@property (nonatomic, strong) NSString *token;  //token[geter只能拿到token串(若过期了是nil)，setter设置进去的应该是一个包含过期时间、menu等其他信息的json]；
@property (nonatomic, assign) BOOL floatButtonVisible; //显示隐藏悬浮按钮(置NO一定不显示，置YES不一定立即显示[玩家关了、或者不能显示]，取得的值是当前实际状态)
@property (nonatomic, assign) BOOL debugMode;   //是否打印日志
@property (nonatomic, strong, readonly) NSString *refer;    //主页地址
@property (nonatomic, strong, readonly) NSString *version;  //客服SDK版本

+ (UniSdkGMFeedBack *)sharedInstance;

/**
 *  AppDelegate 调用
 */
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

/**
 *  @brief  创建悬浮球
 *  强烈建议此参数填nil, sdk会校验token是否过期，token过期你会收到一个token无效的通知，你在此设置有效的token时，会自己打开主页。
 *  @param show, 是否立即显示，相当于 floatButtonVisible = YES / NO;
 */
- (void)createFloatWindowAndShowImmediately:(BOOL)show;

/**
 *  @brief  显示GM页面，客户或者精灵页面，需要指定url，如: http://gm.163.com/xxxx url拼接规则参见使用文档, 为nil打开主页
 *  强烈建议此参数填nil, sdk会校验token是否过期，token过期游戏会收到一个token无效的通知，你在此设置有效的token时，会自己打开主页。
 *  @param stringUrl
 */
- (void)showWebViewWithUrl:(nullable NSString *)stringUrl;

/**
 *收到游戏服推过来的message
 * 1. json格式。
 * 2. 在设置之前请确保设置过token。
 * 3. 请向客服后台确定，他们发过来的token串里包括，浮标的信息，和主页地址
 *
 * -1. Warning：切换手机之后，用户卸载重装之后，越狱用户手动删除文件之后，之前的未读消息就看不到红点了，策划说不用管，求不喷。
 * -2. 当前的是逐条推消息的格式如下（目前只是用来显示红点，还没消息预览的需求）{"code":200, "gmsdk_type":"red_menu", "menu_id":"xxxx", "show_msg":"xxxx"}
 * -3. 往下【*】是写给维护客服SDK的同学看的，虽然策划说这个以后不会再改，但是以防万一。
 * -*. 一次刷多条（服务端不支持）{"msgs":[{"gmsdk_type":"red_menu", "menu_id":"xxxx", "show_msg":"xxxx"}, {...}], "code":200} 防止-2
 */
- (void)reciveMessage:(NSString *)message;


//=====================================================================================
//          分隔线, 4.1 以后以下接口均为空函数，
//=====================================================================================

/**
 *  使用token登录,方块西游专用接口
 *  @param token
 */
- (void)loginWithToken:(NSString *)token andAppCode:(NSString *)appCode;
/**
 *  使用token登录,请不要调用这个接口
 *  @param token
 */
- (void)loginWithToken:(NSString *)token andAppCode:(NSString *)appCode fromeOuterNet:(BOOL)outer;

/**
 *  显示上传图片的页面（测试用，产品不需要调用这个接口）
 */
- (void)showUploadPicView:(NSString *)appCode;

/**
 *  是否是指定的uri
 *  @param uri 字符串
 *  @return YES\NO
 */
- (BOOL)isCustomUri:(NSString *)uri;

/**
 *  在ios8.0以下，用于设置默认的屏幕方向
 */
- (void)setOrientation:(UIInterfaceOrientation)aOrientation;

//- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;
//- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id <UIViewControllerTransitionCoordinator>)coordinator;

- (void)applicationWillResignActive:(UIApplication *)application;
@end
