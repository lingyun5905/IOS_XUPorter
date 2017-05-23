//
//  NtShareDelegate.h
//  NtShareSdk
//
//  Created by Huang Quanyong on 14-7-2.
//  Copyright (c) 2014年 Stupid Dumb Kids. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  @brief 相应返回码
 */
enum  NtShareResponseCode
{
    NtShareSuccess       =  0,    /**< 成功*/
    NtShareErrCommon     = -1,    /**< 普通错误类型*/
    NtShareErrUserCancel = -2,    /**< 用户点击取消并返回*/
    NtShareErrSentFail   = -3,    /**< 发送失败*/
    NtShareErrAuthDeny   = -4,    /**< 授权失败*/
    NtShareErrUnsupport  = -5,    /**< 微信不支持*/
};

/**
 *  @brief 请求类
 */
@interface NtShareReq : NSObject
    /**
     *  @brief 请求类型，预留参数
     */
    @property (nonatomic,assign) NSInteger type;
@end

/**
 *  brief 响应类
 */
@interface NtShareResp : NSObject
    /**
     *  @brief 响应类型，预留参数
     */
    @property (nonatomic,assign) NSInteger type;
    /**
     *  @brief 错误码
     */
    @property (nonatomic,assign) NSInteger code;
    /**
     *  @brief 错误提示字符串
     */
    @property (nonatomic,retain) NSString *errDescription;
@end

/**
 *  @brief 接收处理与分享平台间的通讯交互
 */
@protocol NtShareDelegate <NSObject>

    /**
     *  @brief 收到一个来自分享平台客户端程序的请求
     *
     *  收到请求后，第三方应用应该按照请求类型进行处理
     *
     *  @param request 具体的请求对象
     */
    - (void) didReceiveRequest:(NtShareReq*)request;

    /**
     *  @brief 收到一个来自分享平台客户端程序的响应
     *
     *  收到响应后，第三方应用可以通过响应类型、响应的数据完成自己的功能
     *
     *  @param response 具体的响应对象
     */
    - (void) didReceiveResponse:(NtShareResp*)response;

@end
