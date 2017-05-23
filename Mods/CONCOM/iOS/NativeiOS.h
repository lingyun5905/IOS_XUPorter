//
//  NativeiOSDownloadThread.h
//  Unity-iPhone
//
//  Created by red on 2015. 6. 7..
//
//

#ifndef Unity_iPhone_NativeiOS_h
#define Unity_iPhone_NativeiOS_h

extern "C" void NativeiOSDownloadThread(const char* url, const char* localPath, const char* type);
extern "C" void NativeiOSGetFilePath(const char* fileName);

extern "C" void NativeiOSQueryPurchaseFinished();
extern "C" void NativeiOSLaunchPurchase(const char* pid);
extern "C" void NativeiOSConsumePurchase(const char* pid);
extern "C" void NativeiOSFinishPurchase();
extern "C" void NativeiOSGet3DTouchType();

#endif
