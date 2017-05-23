//
//  UniImagePicker.h
//  UniImagePicker
//
//  Created by ZYN1176 on 16/5/26.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for UniImagePicker.
FOUNDATION_EXPORT double UniImagePickerVersionNumber;

//! Project version string for UniImagePicker.
FOUNDATION_EXPORT const unsigned char UniImagePickerVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <UniImagePicker/PublicHeader.h>


//
//  UniImagePicker.h
//  UniImagePicker
//
//  Created by HuangZizhu on 11/10/14.
//  Copyright (c) 2014 HuangZizhu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 *  Const
 */
extern NSString * CAMERA_NOT_AVAILABLE_CODE;       // = @"10002";
extern NSString * CAMERA_NOT_AVAILABLE_MSG;        // = @"系统找不到摄像头";
extern NSString * CREATE_IMGFILE_FAILED_CODE;      // = @"10003";
extern NSString * CREATE_IMGFILE_FAILED_MSG;       // = @"保存图片文件失败";
extern NSString * ISNOT_IMAGE_FILE_CODE;           // = @"10004";
extern NSString * ISNOT_IMAGE_FILE_MSG;            // = @"选择内容不是图片";
extern NSString * PHOTOLIBRARY_NOT_AVAILABLE_CODE; // = @"10005";
extern NSString * PHOTOLIBRARY_NOT_AVAILABLE_MSG;  // = @"不允许访问相册";
extern NSString * ASButtonTitleCancel;              // =@"取消";
extern NSString * ASButtonTitleCamera;              // = @"拍照";
extern NSString * ASButtonTitleLibrary;             // = @"从相册选择";


/**
 *  回调callback
 */
@protocol UniImagePickerDelegate <NSObject>

@optional
- (void)pickerDidSelectImage:(UIImage *)image withPath:(NSString *)imagePath;
- (void)pickerFailedToSelectImageWithCode:(NSString *)code andMsg:(NSString *)message;

@end

@interface UniImagePicker : NSObject

/**
 *  回调委托
 */
@property (nonatomic, weak)id<UniImagePickerDelegate> delegate;

/**
 *  app的rootviewcontroller
 * （只有在iOS 5.x 的系统才需要设置这个变量，通常传入window的根控制器）
 */
@property (nonatomic, weak)UIViewController           *rootViewController;


/**
 * 在摄像的时候是不允许旋转的，否则录像的界面方向表现的会异常诡异（调用的是APP的接口抱歉， SDK这边并不能做些什么）
 */
@property (nonatomic, assign) BOOL isShooting;

@property (nonatomic, strong, readonly) UIWindow *displayWindow;

/**
 *  单例
 */
+ (UniImagePicker *)getInst;


/**
 *  显示选择菜单（拍照、从相册选择）控制器添加在rootViewController上
 */
- (void)showSelectSheet;

/**
 * （20141210）
 *  不建议后续使用该接口，请设置rootViewController后调用showSelectSheet作为替代。
 *
 * （20141208）
 *  在window的rootviewcontroller不存在时使用这个接口
 *  如果存在则直接使用 - (void)showSelectSheet
 *
 *  @param controller 要显示菜单的控制器
 */
- (void)showSelectSheetFrom:(UIViewController *)controller;

@end

