//
//  NtSharePlatform.h
//  NtShareSdk
//
//  Created by Huang Quanyong on 14-6-26.
//  Copyright (c) 2014年 Stupid Dumb Kids. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NtShareDelegate.h"

@class NtShareArgs;

/**
 *  @brief 分享平台基类
 */
@interface NtSharePlatform : NSObject
{
@protected
    NSString * sourceApplication;
}

/**
 *  @brief 注册平台
 */
+ (void) register;

/**
 *  @brief 在该平台上分享内容
 *
 *  @param args 分享的内容
 */
- (void) share:(NtShareArgs*) args;

/**
 *  @brief 平台应用是否已在设备上安装
 *
 *  @return 是否已安装
 */
- (BOOL) isAppInstalled;

/**
 *  @brief 打开平台应用
 *
 *  @return 打开应用结果
 */
- (BOOL) openApp;

/**
 *  @brief 处理
 *
 *  @param url      处理App Scheme URL，来自应用外的调用
 *  @param delegate 处理结果响应代理
 *
 *  @return 处理结果
 */
- (BOOL) handleOpenURL:(NSURL *) url delegate:(id<NtShareDelegate>) delegate;

/**
 *  @brief 获取平台的SourceApplication参数
 *
 *  @return SourceApplication
 */
- (NSString*) getSourceApplication;

@end
