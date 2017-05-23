//
//  NtLog.h
//  NtShareSdk
//
//  Created by Huang Quanyong on 14-6-25.
//  Copyright (c) 2014年 Stupid Dumb Kids. All rights reserved.
//

#ifndef NT_SHARE_SDK_LOG
#define NT_SHARE_SDK_LOG

#ifdef DEBUG
#define NtLog(...)   NSLog(@"[NtShareSdk] "__VA_ARGS__)
#define NtAssert(condition, ...)  NSAssert(condition, @"[NtShareSdk] "__VA_ARGS__)
#else
#define NtLog(...)   {} NSLog(@"[NtShareSdk] "__VA_ARGS__)
#define NtAssert(condition, ...)  NSAssert(condition, @"[NtShareSdk] "__VA_ARGS__)
#endif

#endif //NT_SHARE_SDK_LOG
