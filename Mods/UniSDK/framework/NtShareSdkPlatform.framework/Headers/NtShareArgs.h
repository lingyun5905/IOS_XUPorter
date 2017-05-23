//
//  NtShareArgs.h
//  NtShareSdk
//
//  Created by Huang Quanyong on 14-6-26.
//  Copyright (c) 2014年 Stupid Dumb Kids. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>

#define NT_SHARE_THUMB_HEIGHT    200
#define NT_SHARE_THUMB_WIDTH     200
#define NT_SHARE_THUMB_QUALITY   .3f

/**
 *  @brief args字典里用来存储标题的key
 */
extern NSString * const NT_SHARE_TITLE;
/**
 *  @brief args字典里用来存储文本内容的key
 */
extern NSString * const NT_SHARE_TEXT;

/**
 * @brief args字典里涌来存储评论文本内容的key
 */
extern NSString * const NT_SHARE_COMMENT;

/**
 *  @brief args字典里用来存储图片缩略图的key
 */
extern NSString * const NT_SHARE_THUMB;

/**
 *  @brief args字典里用来存储图片url的key
 */
extern NSString * const NT_SHARE_IMG_URL;

/**
 *  @brief args字典里用来存储图片数据的key
 */
extern NSString * const NT_SHARE_IMG_DATA;

/**
 *  @brief args字典里用来存储分享场景的key
 */
extern NSString * const NT_SHARE_SCENE;

/**
 *  @brief args字典里用来存储分享网页链接的key
 */
extern NSString * const NT_SHARE_WEBPAGE_URL;

/**
 *  @brief args字典里用来关注某用户ID的key
 */
extern NSString * const NT_SHARE_FOLLOW;

/**
 *  @brief 分享场景，用于易信和微信，默认不设置的话是发送至朋友圈
 */
enum NtShareScene
{
    /**
     *  @brief 会话
     */
    NtShareSceneSession   = 0,
    /**
     *  @brief 朋友圈
     */
    NtShareSceneTimeline  = 1,
    /**
     *  @brief 收藏
     */
    NtShareSceneFavorite  = 2,
};

/**
 *  @brief 分享内容参数，目前支持的分享类型仅有：文本和图片类型
 *  
 *  当分享内容参数存在NT_SHARE_IMG_URL、NT_SHARE_IMG_DATA等key时，分享类型为图片类型分享，
 *  否则为文本类型分享。
 *  NT_SHARE_IMG_DATA可传入的类型有UIImage、NSData。
 *  当使用NT_SHARE_IMG_URL时分享图片内容时，必须设置NT_SHARE_THUMB图片缩略图。
 *  使用NT_SHARE_IMG_DATA时, 可不设置缩略图。
 */
@interface NtShareArgs : NSObject
{
@private
    NSMutableDictionary* args;
}

/**
 *  @brief 初始化NtShareArgs
 *
 *  @return 返回初始化完成后的对象
 */
- (NtShareArgs*) init;

/**
 *  @brief 获取分享内容参数
 *
 *  @param key args参数的key
 *
 *  @return 返回key对应的参数
 */
- (id) getArg: (NSString*) key;

/**
 *  @brief 设置分享内容参数
 *
 *  @param value args参数的值
 *
 *  @param key   参数对应的key
 */
- (void) setArg:(id)value forKey:(NSString *)key;

/**
 *  @brief args中是否有key对应的参数
 *
 *  @param key 相应参数的key
 *
 *  @return 是否存在该参数
 */
- (BOOL) isContain:(NSString*) key;

/**
 *  @brief 设置缩略图
 *
 *  该函数将自动对图片进行压缩处理。
 *
 *  @param image 缩略图对象
 */
- (void) setThumb: (UIImage*) image;

@end
