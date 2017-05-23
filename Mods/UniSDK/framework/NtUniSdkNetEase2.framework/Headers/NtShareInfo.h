//
//  NtShareInfo.h
//  NtUniSdkLine
//
//  Created by Huang Quanyong on 14-9-24.
//  Copyright (c) 2014年 Stupid Dumb Kids. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define __NTSHARE_1_0 1.0
#define __NTSHARE_2_0 2.0
#define NT_SHARE_DEPRECATED(_version,__VA_ARGS__) __attribute__((deprecated(__VA_ARGS__)))

/**
 * @defgroup 分享的范围
 * @brief 分享的范围
 * @{
 */
extern NSString * const SCOPE_TOUSER; ///< 指定玩家
extern NSString * const SCOPE_CIRCLE; ///< 朋友圈
extern NSString * const SCOPE_MULTIUSER; ///< 多个好友
/** @} */

/**
 * @defgroup 分享消息的类型
 * @brief 分享的消息类型
 * @{
 */
extern NSString * const TYPE_INVITE; ///< 邀请消息
extern NSString * const TYPE_IMAGE; ///< 图文消息
extern NSString * const TYPE_LINK; ///< 带链接的消息
extern NSString * const TYPE_VIDEO; ///< 带video的消息
extern NSString * const TYPE_AUDIO; ///< 带audio的消息
extern NSString * const TYPE_GIF; ///< 带gif的消息
extern NSString * const TYPE_ATTENTION; ///< 关注的消息
/** @} */

/**
 * @brief {@link ShareInfo} setShareChannel配置的微博分享
 */
extern NSInteger const NT_SHARE_TYPE_WEIBO; //=100
/**
 * @brief {@link ShareInfo} setShareChannel配置的微信好友分享
 */
extern NSInteger const NT_SHARE_TYPE_WEIXIN_FRIEND; //=101
/**
 * @brief {@link ShareInfo} setShareChannel配置的微信朋友分享
 */
extern NSInteger const NT_SHARE_TYPE_WEIXIN_TIMELINE; //=102
/**
 * @brief {@link ShareInfo} setShareChannel配置的易信好友分享
 */
extern NSInteger const NT_SHARE_TYPE_YIXIN_FRIEND; //=103
/**
 * @brief {@link ShareInfo} setShareChannel配置的易信朋友圈分享
 */
extern NSInteger const NT_SHARE_TYPE_YIXIN_TIMELINE; //=104
/**
 * @brief {@link ShareInfo} setShareChannel配置的QQ分享
 */
extern NSInteger const NT_SHARE_TYPE_QQ; //=105
/**
 * @brief {@link ShareInfo} setShareChannel配置的QQ空间分享
 */
extern NSInteger const NT_SHARE_TYPE_QZONE; //=106
/**
 * @brief {@link ShareInfo} setShareChannel配置的Google+分享
 */
extern NSInteger const NT_SHARE_TYPE_PLUS; //=107
/**
 * @brief {@link ShareInfo} setShareChannel配置的facebook分享
 */
extern NSInteger const NT_SHARE_TYPE_FACEBOOK; //=108
/**
 * @brief {@link ShareInfo} setShareChannel配置的garena分享
 */
extern NSInteger const NT_SHARE_TYPE_GARENA; //=109
/**
 * @brief {@link ShareInfo} setShareChannel配置的kakao分享
 */
extern NSInteger const NT_SHARE_TYPE_KAKAO; // = 110;
/**
 * @brief {@link ShareInfo} setShareChannel配置的Line分享
 */
extern NSInteger const NT_SHARE_TYPE_LINE; // = 111;

/**
 * @brief {@link ShareInfo} setShareChannel配置的Zalo分享
 */
extern NSInteger const NT_SHARE_TYPE_ZALO;//112

/**
 * @brief {@link ShareInfo} setShareChannel配置的VK分享
 */
extern NSInteger const NT_SHARE_TYPE_VK;//113
/**
 * @brief {@link ShareInfo} setShareChannel配置的Twitter分享
 */
extern NSInteger const NT_SHARE_TYPE_TWITTER;//114
/**
 * @brief {@link ShareInfo} setShareChannel配置的Facebook Messenger分享
 */
extern NSInteger const NT_SHARE_TYPE_FACEBOOK_MESSENGER;//115
/**
 * @brief {@link ShareInfo} setShareChannel配置的Facebook 点赞分享
 */
extern NSInteger const NT_SHARE_TYPE_FACEBOOK_LIKE;//116
/**
 * @defgroup 分享的范围
 * @brief 分享的范围
 * @{
 */
typedef NS_ENUM(int, NtShareScope) {
    NT_SHARE_SCOPE_TOUSER       = 0,  ///< 指定玩家
    NT_SHARE_SCOPE_CIRCLE       = 1,  ///< 朋友圈
    NT_SHARE_SCOPE_MULTIUSER    = 2,  ///< 多个玩家
} NT_SHARE_DEPRECATED(2_0, "Use SCOPE_TOUSER|SCOPE_CIRCLE|SCOPE_MULTIUSER instead");

typedef NS_ENUM(int, NtShareType) {
    NT_SHARE_TYPE_INVITE    = 0,   ///< 邀请消息
    NT_SHARE_TYPE_IMAGE     = 1,   ///< 图文消息
    NT_SHARE_TYPE_LINK      = 2,   ///< 带链接的消息
    NT_SHARE_TYPE_OPENGRAPH = 3,    ///< Open graph
    NT_SHARE_TYPE_VIDEO     = 4    ///< 视频分享
} NT_SHARE_DEPRECATED(2_0, "Use TYPE_INVITE|TYPE_IMAGE|TYPE_LINK|TYPE_VIDEO instead");

// -- EFUN, Garena
typedef NS_ENUM(int, NtShareCommunity) {
    NT_SHARE_COM_FACEBOOK    = 0,   ///< FB
    NT_SHARE_COM_KAKAO       = 1,   ///< KAKAO
    NT_SHARE_COM_TWITTER     = 2,   ///< TWITTER
    NT_SHARE_COM_VK          = 3,   ///< VK
    NT_SHARE_COM_BEETALK     = 4,   ///< BeeTalk
    NT_SHARE_COM_GARENA      = 5    ///< Garena
} NT_SHARE_DEPRECATED(2_0, "Use NT_SHARE_TYPE_WEIBO|NT_SHARE_TYPE_WEIXIN_FRIEND|... instead");

@interface NtShareInfo : NSObject

@property(nonatomic,strong) NSString *toUser;   ///< 分享消息的接收者
@property(nonatomic,strong) NSString *title;    ///< 分享消息的标题
@property(nonatomic,strong) NSString *subTitle NT_SHARE_DEPRECATED(2_0, "the property has deprecated."); ///< 分享消息的副标题
@property(nonatomic,strong) NSString *desc;     ///< 分享消息的描述
@property(nonatomic,strong) NSString *image;    ///< 分享消息的图片
@property(nonatomic,strong) NSString *text;     ///< 分享消息的文本
@property(nonatomic,strong) NSString *link;     ///< 分享消息的链接
@property(nonatomic,strong) NSString *videoUrl;     ///< 分享视频的链接
@property(nonatomic,strong) NSArray *toUserList;   ///< 分享给多个接收者  仅用于邀请消息
@property(nonatomic,strong) UIImage *shareBitmap;   ///<分享图片内容
@property(nonatomic,strong) UIImage *shareThumb;    ///<分享图片缩略图
@property(nonatomic,strong) NSString *u3dshareThumb;///<分享图片缩略图(u3d使用)
@property(nonatomic,strong) NSString *u3dShareBitmap;///<分享图片内容(u3d使用)
@property(nonatomic,assign) BOOL showShareDialog;///<分享对话框
@property(nonatomic,assign) int shareChannel;///< 分享的渠道

@property(nonatomic) NtShareScope shareScope NT_SHARE_DEPRECATED(2_0, "the property has deprecated. Use scope instead.");   ///< 分享范围
@property(nonatomic) NtShareType shareType NT_SHARE_DEPRECATED(2_0, "the property has deprecated. Use type instead.");    ///< 分享类型
@property(nonatomic) NtShareCommunity shareCommunity NT_SHARE_DEPRECATED(2_0, "the property has deprecated. Use shareChannel instead.");    ///< 分享社区类型

@property(nonatomic,strong) NSString *scope; //分享的范围：对话、公开、收藏等
@property(nonatomic,strong) NSString *type;  //分享的类型：邀请、图片、文字、链接等

// -- line 分享发消息 --
@property(nonatomic, copy) NSString *templateId;
@property(nonatomic, strong) NSDictionary *textMsg;
@property(nonatomic, strong) NSDictionary *subTextMsg;
@property(nonatomic, strong) NSDictionary *altTextMsg;
@property(nonatomic, strong) NSDictionary *linkTextMsg;

// -- funplus open graph --
@property(nonatomic, copy) NSString *ogNamespace;
@property(nonatomic, copy) NSString *ogAction;
@property(nonatomic, copy) NSString *ogObject;
@property(nonatomic, ) BOOL useApiOnly;

// -- Garena
@property(nonatomic,copy) NSString *objectId; ///< FB Open graph objectid
@property(nonatomic,copy) NSString *tag;
@property(nonatomic, strong) NSDictionary *shareData;
@property(nonatomic,assign) int scene;///< 0: Chat. 1: Buzz

@end
