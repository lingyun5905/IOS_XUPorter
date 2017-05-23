//
//  Header.h
//  iOSNtUniSdkFrameworkDemo
//
//  Created by Huang Quanyong on 14-5-30.
//  Copyright (c) 2014年 Stupid Dumb Kids. All rights reserved.
//
#define STRINGIZE_NX(A) #A
#define STRINGIZE(A) STRINGIZE_NX(A)

#define TARGET_FRAMEWORK_HEADER <TARGET_FRAMEWORK_NAME/NtUniSdk.h>
#import TARGET_FRAMEWORK_HEADER

#define BEGIN_IF_TARGET(TARGET) \
if(STRINGIZE(TARGET)==STRINGIZE(TARGET_FARMEWORK_NAME))\
{

#define END_IF_TARGET \
}