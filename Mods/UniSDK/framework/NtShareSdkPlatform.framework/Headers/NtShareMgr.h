//
//  NtShareMgr.h
//  NtShareSdk
//
//  Created by Huang Quanyong on 14-7-2.
//  Copyright (c) 2014年 Stupid Dumb Kids. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NtLog.h"

#import "NtSharePlatform.h"
#import "NtShareArgs.h"

/**
 *  @brief ShareSdk管理类
 */
@interface NtShareMgr : NSObject
{
@private
    NSMutableDictionary* platforms;
    NtSharePlatform* lastPlatform;
}

/**
 *  @brief 获取单例
 *
 *  @return 单例对象
 */
+ (NtShareMgr*) getInst;

/**
 *  @brief 指定平台app是否已安装
 *
 *  @param platformName 指定分享平台
 *
 *  @return 是否已安装
 */
- (BOOL) isPlatformInstalled:(NSString*) platformName;

/**
 *  @brief 将内容分享至某平台
 *
 *  @param args         分享内容参数
 *  @param platformName 分享平台
 */
- (void) share:(NtShareArgs*) args to:(NSString*) platformName;

/**
 *  @brief 处理App Scheme URL，来自应用外的调用
 *
 *  @param url               外部应用调用的url
 *  @param sourceApplication 外部来源应用
 *  @param delegate          处理结果响应代理
 *
 *  @return  处理结果
 */
- (BOOL) handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication delegate:(id<NtShareDelegate>)delegate;

/**
 *  @brief 注册新的分享平台
 *
 *  @param newPlatform 新的分享平台
 *  @param key         新平台对应的key
 */
- (void) registerPlatform: (NtSharePlatform*) newPlatform forKey: (NSString*) key;

@end
