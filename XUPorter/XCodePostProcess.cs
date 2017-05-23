using UnityEngine;
#if UNITY_EDITOR
using UnityEditor;
using UnityEditor.Callbacks;
using UnityEditor.XCodeEditor;
#endif
using System.IO;

public static class XCodePostProcess
{

#if UNITY_EDITOR
	[PostProcessBuild(999)]
	public static void OnPostProcessBuild( BuildTarget target, string pathToBuiltProject )
	{
		if (target != BuildTarget.iPhone) {
			Debug.LogWarning("Target is not iPhone. XCodePostProcess will not run");
			return;
		}
		pathToBuiltProject = Path.GetFullPath (pathToBuiltProject);
		// Create a new project object from build target
		XCProject project = new XCProject( pathToBuiltProject );

		// Find and run through all projmods files to patch the project.
		// Please pay attention that ALL projmods files in your project folder will be excuted!
		string[] files = Directory.GetFiles(Application.dataPath+@"/../Mods", "*.projmods", SearchOption.AllDirectories );
		foreach( string file in files ) {
			UnityEngine.Debug.Log("ProjMod File: "+file);
			project.ApplyMod( file );
		}


		project.AddOtherLinkerFlags ("-force_load");
		project.AddOtherLinkerFlags ("\'$(SRCROOT)/Libraries/libProudNetClientPlugin.a\'");
		project.AddOtherLinkerFlags ("-ObjC");


		//TODO implement generic settings as a module option
		//project.overwriteBuildSetting("CODE_SIGN_IDENTITY[sdk=iphoneos*]", "iPhone Developer", "Debug");
		//project.overwriteBuildSetting("CODE_SIGN_IDENTITY[sdk=iphoneos*]", "iPhone Developer", "Release");
		project.overwriteBuildSetting("CODE_SIGN_IDENTITY", "iPhone Distribution: ZiYing Ye (JUQFQ433PU)", "Release");
		project.overwriteBuildSetting("CODE_SIGN_IDENTITY", "iPhone Distribution: ZiYing Ye (JUQFQ433PU)", "Debug");

		project.overwriteBuildSetting("PROVISIONING_PROFILE","c19b1f57-8cf5-4d34-890e-0d94c9ed992c");
		//project.overwriteBuildSetting("PROVISIONING_PROFILE","5ed1989c-4b91-42eb-9e2e-6e26d1eec1e2");

		//GCC_PREPROCESSOR_DEFINITIONS
		project.overwriteBuildSetting ("GCC_PREPROCESSOR_DEFINITIONS", "TARGET_FRAMEWORK_NAME=NtUniSdkNetEase2");
		project.overwriteBuildSetting ("GCC_PREPROCESSOR_DEFINITIONS", "UNISDK_NGSHARE=1");

		//ngpush
		project.AddSystemCapabilities (XCProjectSystemCapabilitiesType.XCProjectSystemCapabilitiesTypeApplePush,true);
		project.AddSystemCapabilities (XCProjectSystemCapabilitiesType.XCProjectSystemCapabilitiesTypeGameCenter,false);

		project.AddSystemTargetTeamID ("JUQFQ433PU");

		// Finally save the xcode project
		project.Save();

		//根据需要修改源代码
		EditorCode(pathToBuiltProject);
	}
#endif
	//[MenuItem("TOOL/CodeUpdate")]
	public static void EditorCode(string filePath)
	{
		//string filePath = @"F:\svn\tmp";
		XClass SourceFile;
		//读取UnityAppController.h文件
		SourceFile = new XClass(filePath + "/Classes/UnityAppController.h");

		SourceFile.WriteBelow("	id<RenderPluginDelegate>	_renderDelegate;","#pragma mark -\r#pragma mark Created by CONCOM.\r    bool _isShowKeyboard;\r    CGRect _rootViewRect;");

		SourceFile.WriteBelow("- (void)checkOrientationRequest;","#pragma mark -\r#pragma mark Created by CONCOM.\r- (void)keyboardWillShow:(NSNotification *)notification;\r- (void)keyboardWillHide:(NSNotification *)notification;\r ");

		//读取UnityAppController.mm文件
		SourceFile = new XClass(filePath + "/Classes/UnityAppController.mm");
		SourceFile.WriteBelow("#import <OpenGLES/ES2/glext.h>","#import \"UniHead.h\"\r ");
		SourceFile.WriteBelow("#include \"PluginBase/AppDelegateListener.h\"","#pragma mark Created by CZY. \r#import <AudioToolbox/AudioToolbox.h> \r//#ifdef USING_FRAMEWORK \r#import <UniSdkGMFeedBack/UniSdkGMFeedBack.h> \r//#else \r//#import \"UniSdkGMFeedBack.h\" \r//#endif \r \r#if UNISDK_NGSHARE \r#import <NtShareSdkPlatform/NtShareSdkPlatform.h> \r#endif \r \r#pragma mark Created by CONCOM. \r#define CONCOM \r \r#pragma mark Created by CZY. \r//-----  begin --------- \r@interface UnityAppController () <UniSdkGMFeedBackDelegate,	NtShareDelegate> { \r    BOOL mIsRequesting; \r} \r \r@property (nonatomic, strong) NSString *token; \r \r@property (nonatomic, assign) BOOL shouldHandleAutoStatusBarOriChanged; \r \r@end \r \rvoid interruptionListener(void *inClientData, UInt32 inInterruptionState){ \r//    UnityAppController *vc = (__bridge UnityAppController *)inClientData; \r//    [vc interruptionListener:inInterruptionState]; \r    //录音中断了 \r} \r \rvoid propertyListener( void *inClientData, AudioSessionPropertyID inID, UInt32 inDataSize, const void *inData) { \r//    UnityAppController *vc = (__bridge UnityAppController *)inClientData; \r//    [vc propertyListener:inID dataSize:inDataSize data:inData]; \r    //插上了耳机之类的通知 \r} \r//-----end---------");
		SourceFile.WriteBelow ("static bool	_isAutorotating		= false;", "NSString* _touchType;\r ");
		SourceFile.Replace ("UnitySetPlayerFocus(1); \r}", "	UnitySetPlayerFocus(1); \r    \r#pragma mark - \r#pragma mark Created by CONCOM. \r    _isShowKeyboard = false; \r} \r \r#pragma mark - \r#pragma mark Created by CONCOM.");
		SourceFile.Replace ("- (void)checkOrientationRequest", "/* \r- (void)application:(UIApplication *)application performActionForShortcutItem: \r(UIApplicationShortcutItem *)shortcutItem completionHandler:(void (^)(BOOL))completionHandler \r{ \r    if ([shortcutItem.type length] <= 0) \r        return; \r \r    if (_rootController == NULL || _rootController == nil) \r        return; \r    \r    if (_rootController.traitCollection.forceTouchCapability != UIForceTouchCapabilityAvailable) \r        return; \r    \r    NSLog(@\"A shortcut item was pressed. It was %@.\", shortcutItem.type); \r    if (_touchType == nil) \r        _touchType = [NSString string]; \r    \r    if ([shortcutItem.type isEqualToString:(@\"QuestType\")] == true) \r        _touchType = @\"QuestType\"; \r    \r    if ([shortcutItem.type isEqualToString:(@\"MissionType\")] == true) \r        _touchType = @\"DailyMissionType\"; \r    \r    if ([shortcutItem.type isEqualToString:(@\"StoreType\")] == true) \r        _touchType = @\"StoreType\"; \r    \r    if ([shortcutItem.type isEqualToString:(@\"MailType\")] == true) \r        _touchType = @\"MailType\"; \r    \r    NSLog(@\"A shortcut item was pressed. It was %@.\", _touchType); \r} \r*/ \r \r- (void)checkOrientationRequest");
		SourceFile.Replace ("- (void)onForcedOrientation:(ScreenOrientation)orient", "#pragma mark - \r#pragma mark Created by CONCOM. \r- (void)keyboardWillShow:(NSNotification *)notification \r{ \r    if ([KeyboardDelegate Instance].keyboardAppearance != UIKeyboardAppearanceAlert) \r        return; \r    \r    if (_isShowKeyboard) \r        return; \r    \r    _isShowKeyboard = true; \r    \r    CGRect rectView; \r    CGRect rectKeyboard; \r    \r    [UIView beginAnimations:nil context:NULL]; \r    [UIView setAnimationDuration:0.3]; \r    \r    rectView = [_rootView frame]; \r    \r    _rootViewRect = rectView; \r    \r    [[notification.userInfo valueForKey:UIKeyboardFrameEndUserInfoKey] getValue:&rectKeyboard]; \r    \r    if (rectKeyboard.size.width > rectKeyboard.size.height) \r        rectView.origin.y -= rectKeyboard.size.height; \r    else \r        rectView.origin.x += rectKeyboard.size.width; \r    \r    \r    [_rootView setFrame:rectView]; \r    [UIView commitAnimations]; \r} \r \r \r- (void) keyboardWillHide:(NSNotification *)notification \r{ \r    if (!_isShowKeyboard) \r        return; \r    \r    _isShowKeyboard = false; \r    \r    CGRect rectKeyboard; \r    \r    [UIView beginAnimations:nil context:NULL]; \r    [UIView setAnimationDuration:0.3]; \r    \r    [[notification.userInfo valueForKey:UIKeyboardFrameEndUserInfoKey] getValue:&rectKeyboard]; \r    \r    [_rootView setFrame:_rootViewRect]; \r    [UIView commitAnimations]; \r} \r \r- (void) registerKeyboardEvent \r{ \r    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillShow:) name:UIKeyboardWillShowNotification object:nil]; \r    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillHide:) name:UIKeyboardWillHideNotification object:nil]; \r} \r \r- (void) unregisterKeyboardEvent \r{ \r    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardWillShowNotification object:nil]; \r    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardWillHideNotification object:nil]; \r} \r#pragma mark - \r \r#pragma mark - \r#pragma mark Created by CZY. \r#pragma mark - 客服页面回调 \r- (void)onGMWebviewBack { \r    NSLog(@\"客服页面点击了返回按钮\"); \r} \r \r- (void)onGMWebviewWillClose { \r    NSLog(@\"客服页面点击了关闭按钮\"); \r} \r \r- (void)onInvalidToken { \r    NSLog(@\"客服頁面触发了token无效的通知\"); \r    NSLog(@\"模拟请求token 实际过程应该是 GameClient -> GameServer -> GM Server -> GameServer -> GameClient\"); \r	NSString *token = [UniSdkGMFeedBack sharedInstance].token; \r   	NSError *error = nil; \r    NSData *jsonData = [token 	dataUsingEncoding:NSUTF8StringEncoding]; \r    NSDictionary *jsonDict = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableContainers error:&error]; \r    if (!error && jsonDict) { \r        if ([[jsonDict objectForKey:@\"code\"] intValue] == 200 ) { \r            NSLog(@\"token is %@\", [jsonDict objectForKey:@\"token\"]); \r            NSLog(@\"time is  %@\", [jsonDict objectForKey:@\"expireTime\"]); \r            if ([[NSDate date] timeIntervalSince1970] < [[jsonDict objectForKey:@\"expireTime\"] integerValue]) { \r                NSLog(@\"token正常，没过期\"); \r            } \r            else { \r                NSLog(@\"token过期了\"); \r				UnitySendMessage(\"GMCenterManager\", [@\"CheckForGMInit\" UTF8String], [@\"\" UTF8String]); \r            } \r        } \r        else { \r            NSLog(@\"code 不正确 : %@\", [jsonDict objectForKey:@\"code\"]); \r			UnitySendMessage(\"GMCenterManager\", [@\"CheckForGMInit\" UTF8String], [@\"\" UTF8String]); \r        } \r    }else { \r        NSLog(@\"decode json failed. %@\", error); \r		UnitySendMessage(\"GMCenterManager\", [@\"CheckForGMInit\" UTF8String], [@\"\" UTF8String]); \r    } \r} \r#pragma mark - \r \r#pragma mark ngshare \r \r- (void) didReceiveRequest:(NtShareReq*) request \r{ \r    //[self msg: @\"didReceiveRequest\"]; \r} \r \r//用于处理来自分享平台返回的分享结果 \r- (void) didReceiveResponse:(NtShareResp*)response \r{ \r    //[self msg:[NSString stringWithFormat:@\"didReceiveResponse code:%ld, description: %@\", (long)response.code, response.errDescription]]; \r    \r    NSDictionary *dict = @{@\"code\":[NSNumber numberWithInt:response.code]}; \r    \r    [[NSNotificationCenter defaultCenter]postNotificationName:NT_NOTIFICATION_FINSIH_SHARE object:GetAppController() userInfo:dict]; \r} \r \r#pragma mark ngshare \r \r \r- (void)onForcedOrientation:(ScreenOrientation)orient");
		SourceFile.WriteBelow ("	AppController_SendNotificationWithArg(kUnityOnOpenURL, notifData);", "	 \r#pragma mark Created by CZY. \r	[[UniSdkGMFeedBack sharedInstance] application:application openURL:url sourceApplication:sourceApplication annotation:annotation]; \r    \r    \r#if UNISDK_NGSHARE \r    BOOL isShareCall = NO; \r    if ([[url scheme] hasPrefix:@\"wx\"]) { \r        NSLog(@\"这个是微信app的回调url=%@\", url); \r        isShareCall = YES; \r    } \r    else if ([[url scheme] hasPrefix:@\"wb\"]) { \r        NSLog(@\"这个是微博app的回调url=%@\", url); \r        isShareCall = YES; \r    } \r    //不是微信或者微博的回调 使用登录渠道的处理 \r    if (isShareCall) { \r        //处理微信微博易信QQ等的回调 \r        [[NtShareMgr getInst] handleOpenURL:url sourceApplication:sourceApplication delegate:self]; \r    } \r#endif\r ");
		SourceFile.WriteBelow ("	[self preStartUnity];", "    \r#pragma mark Created by CONCOM. \r    [self performSelector:@selector(registerKeyboardEvent)]; \r    \r    [self transitionToViewController:[self createRootViewController]]; \r    if (_rootController == NULL || _rootController == nil) \r        return YES; \r    \r    if (_rootController.traitCollection.forceTouchCapability != UIForceTouchCapabilityAvailable) \r        return YES; \r    \r    UIApplicationShortcutItem* shortcutItem = [launchOptions objectForKey:UIApplicationLaunchOptionsShortcutItemKey]; \r    if (shortcutItem != nil && shortcutItem.type != nil) \r    { \r        if (_touchType == nil) \r        { \r            _touchType = [NSString string]; \r            \r            if ([shortcutItem.type isEqualToString:(@\"QuestType\")] == true) \r                _touchType = @\"QuestType\"; \r            \r            if ([shortcutItem.type isEqualToString:(@\"MissionType\")] == true) \r                _touchType = @\"DailyMissionType\"; \r            \r            if ([shortcutItem.type isEqualToString:(@\"StoreType\")] == true) \r                _touchType = @\"StoreType\"; \r            \r            if ([shortcutItem.type isEqualToString:(@\"MailType\")] == true) \r                _touchType = @\"MailType\"; \r            \r            NSLog(@\"A shortcut item was pressed. It was %@.\", _touchType); \r        } \r    } \r    \r#pragma mark Created by CZY. \r    [[UniSdkGMFeedBack sharedInstance] createFloatWindowAndShowImmediately:NO]; \r    [[UniSdkGMFeedBack sharedInstance] application:application didFinishLaunchingWithOptions:launchOptions]; \r    [UniSdkGMFeedBack sharedInstance].debugMode = YES; \r    [UniSdkGMFeedBack sharedInstance].language = nil; \r    [UniSdkGMFeedBack sharedInstance].appCode = @\"ma55\"; \r    [UniSdkGMFeedBack sharedInstance].delegate = self;//调用回调的对象 \r    [UniSdkGMFeedBack sharedInstance].rootViewController = self.rootViewController;//游戏主view的viewcontroller，可以仅在页面不能正常显示的传");
		SourceFile.Replace ("	_didResignActive = true;", "	 \r#pragma mark Created by CZY. \r	[[UniSdkGMFeedBack sharedInstance] applicationWillResignActive:application]; \r \r	_didResignActive = true;");
		SourceFile.Replace ("	UnityCleanup();", "	UnityCleanup(); \r    \r#pragma mark Created by CONCOM. \r    [self performSelector:@selector(unregisterKeyboardEvent)];");
		SourceFile.Add (" \rextern \"C\" { \r    void GMInit(const char* uid) \r    {  \r		[UniSdkGMFeedBack sharedInstance].roleID = [NSString stringWithUTF8String: uid];//玩家角色ID \r		UnitySendMessage(\"GMCenterManager\", [@\"CheckForGMInit\" UTF8String], [@\"\" UTF8String]); \r    } \r	 \r	void openGMPage() \r	{ \r		//打开主页 \r		[[UniSdkGMFeedBack sharedInstance] showWebViewWithUrl:nil]; \r	} \r	 \r	void GMRecieveMsg(const char* msg) \r	{ \r		NSString *json = [NSString stringWithUTF8String:msg]; \r		[[UniSdkGMFeedBack sharedInstance] reciveMessage:json]; \r	} \r	 \r	void GMToken(const char* token_v) \r	{ \r		NSString *token = [NSString stringWithUTF8String:token_v]; \r   		NSError *error = nil; \r    	NSData *jsonData = [token 	dataUsingEncoding:NSUTF8StringEncoding]; \r    	NSDictionary *jsonDict = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableContainers error:&error]; \r    	if (!error && jsonDict) { \r        	if ([[jsonDict objectForKey:@\"code\"] intValue] == 200 ) { \r            	NSLog(@\"token is %@\", [jsonDict objectForKey:@\"token\"]); \r            	NSLog(@\"time is  %@\", [jsonDict objectForKey:@\"expireTime\"]); \r            	if ([[NSDate date] timeIntervalSince1970] < [[jsonDict objectForKey:@\"expireTime\"] integerValue]) { \r                	NSLog(@\"token正常，没过期\"); \r					[UniSdkGMFeedBack sharedInstance].token = token; \r            	} \r            	else { \r                	NSLog(@\"token过期了\"); \r					UnitySendMessage(\"GMCenterManager\", [@\"CheckForGMInit\" UTF8String], [@\"\" UTF8String]); \r            	} \r        	} \r        	else { \r            	NSLog(@\"code 不正确 : %@\", [jsonDict objectForKey:@\"code\"]); \r				UnitySendMessage(\"GMCenterManager\", [@\"CheckForGMInit\" UTF8String], [@\"\" UTF8String]); \r        	} \r    	} \r    	else { \r        	NSLog(@\"decode json failed. %@\", error); \r			UnitySendMessage(\"GMCenterManager\", [@\"CheckForGMInit\" UTF8String], [@\"\" UTF8String]); \r    	} \r        NSLog(@\"the token is : %@\", [UniSdkGMFeedBack sharedInstance].token); \r	} \r}");
	
		SourceFile = new XClass(filePath + "/Classes/UI/Keyboard.h");
		SourceFile.WriteBelow("@property (retain, nonatomic, getter=getText, setter=setText:)	NSString*	text;", " \r#pragma mark - \r#pragma mark Created by CONCOM. \r@property (readonly, nonatomic)									UIKeyboardAppearance		keyboardAppearance; \r");

		SourceFile = new XClass(filePath + "/Classes/UI/Keyboard.mm");
		SourceFile.WriteBelow ("	BOOL			_rotating;", "    \r#pragma mark - \r#pragma mark Created by CONCOM. \r    UIKeyboardAppearance	_keyboardAppearance;");
		SourceFile.WriteBelow ("@synthesize text;", "#pragma mark - \r#pragma mark Created by CONCOM. \r@synthesize keyboardAppearance	= _keyboardAppearance; \r");
		SourceFile.Replace ("		textView = [[UITextView alloc] initWithFrame:CGRectMake(0, 0, 0, 30)];", "		textView = [[UITextView alloc] initWithFrame:CGRectMake(0, 0, 0, 0)];");
		SourceFile.WriteBelow ("- (void)show:(KeyboardShowParam)param\n{", "#pragma mark - \r#pragma mark Created by CONCOM. \r    _keyboardAppearance = param.appearance; \r    ");
		SourceFile.Replace ("	else if (inputView != nil)", "	else");
	}

	public static void Log(string message)
	{
		UnityEngine.Debug.Log("PostProcess: "+message);
	}
}
