//
//  NtConstProp.h
//  NtUniSdk
//
//  Created by Huang Quanyong on 14-5-23.
//  Copyright (c) 2014年 Stupid Dumb Kids. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  @brief PAY_UID用于支付用uid，jinliuSDK支付不使用LINE mid，使用和jinliu交换后的uid
 */
extern NSString* const NT_PAY_UID;

/**
 *  @brief 用于管理是否打开SDK充值，默认为打开充值(PP)
 */
extern NSString* const NT_CLOSE_RECHARGER;

/**
 *  @brief 支付时传入的ROLE_ID(LINE)
 */
extern NSString* const NT_ROLE_ID;

/**
 *  @brief 支付时传入的ROLE_LEVEL(LINE)
 */
extern NSString* const NT_ROLE_LEVEL;

/**
 * @brief 跟平台申请的CHANNEL_ID(LINE)
 */
extern NSString* const NT_CHANNEL_ID;

/**
 * @brief 跟平台申请的MERUHANT_ID(DownJoy)
 */
extern NSString* const NT_MERUHANT_ID;
/**
 * @brief APP Scheme URL
 */
extern NSString* const NT_APP_URL_SCHEME;

/**
 * @brief 游戏代号
 */
extern NSString* const NT_GAMEID;

/**
 * @brief APP的名字
 */
extern NSString* const NT_APP_NAME;
/**
 * @brief 跟平台申请的id
 */
extern NSString* const NT_APPID;
/**
 * @brief 跟平台申请的key
 */
extern NSString* const NT_APP_KEY;
/**
 * @brief 跟平台申请的secret
 */
extern NSString* const NT_APP_SECRET;

/**
 *  @brief  app群组，方便各个app之间共享Keychain
 */
extern NSString *const NT_APP_GROUP;

/**
 * @brief 跟微信申请的APP KEY, 登录授权用的
 */
extern NSString* const NT_WECHAT_APP_KEY;
extern NSString* const NT_WECHAT_APP_DESC;//描述信息

/**
 * @brief 跟QQ申请的APP ID, 登录授权用的
 */
extern NSString* const NT_QQ_APP_ID;

/**
 * @brief 跟WEIBO申请的APP KEY, 微博登录授权用的
 */
extern NSString* const NT_WEIBO_APP_KEY;
extern NSString* const NT_WEIBO_REDIRECT_URI; //调转的地址
/**
 * @brief 跟GOOGLE申请的Client ID
 */
extern NSString* const NT_GOOGLE_CLIENT_ID;
/**
 * @brief 跟FACEBOOK申请的Client ID
 */
extern NSString* const NT_FACEBOOK_CLIENT_ID;
/**
 * @brief 跟TWITTER申请的consumer key and consumer secrect
 */
extern NSString* const NT_TWITTER_CONSUMER_KEY;
extern NSString* const NT_TWITTER_CONSUMER_SECRET;
/**
 * @brief 跟平台申请的服务器大区ID
 */
extern NSString* const NT_SERVER_ID;
/**
 * @brief 屏幕方向属性名
 */
extern NSString* const NT_SCR_ORIENTATION;
/**
 * @defgroup ScreenOrietation 屏幕方向
 * @brief 屏幕方向
 * @{
 */

/* iOS */

extern const int NT_E_SO_PORTRAIT;      //竖向
extern const int NT_E_SO_PORTRAIT_UD;   //竖向反转
extern const int NT_E_SO_LANDSCAPE_L;   //横向
extern const int NT_E_SO_LANDSCAPE_R;   //横向反转

/** @} */

/**
 * @brief sdk检查更新失败就禁止游戏开启，默认不禁止，设置为1可开启
 * 必须在ntInit调用之前就设置好，可放在xxxx.data中设置
 * 目前为 91\同步助手 设置，用于单机或者弱联网游戏
 */
extern NSString* const NT_SDK_UPDATE_CHECK_STRICT;

/**
 * @brief Kuaiyong Downjoy 要求游戏自带闪屏，UniSDK已经实现闪屏功能，默认不开启
 * 必须在ntInit调用之前就设置好，可放在xxxx_data中设置
 * 目前为 Kuaiyong Downjoy 设置
 */
extern NSString* const NT_SDK_LOAD_SPLASH_VIEW;

/**
 * @brief 是否打开网易游戏logo的闪屏，为了与安卓统一，使用了“SPLASH_SECOND”
 * 必须在ntInit调用之前就设置好，可放在xxxx_data中设置
 */
extern NSString* const NT_SPLASH_SECOND;
extern NSString* const NT_SPLASH_SECOND_MAXTIME;

/**
 * @brief 本当前登录状态
 */
extern NSString* const NT_LOGIN_STAT;
/**
 * @defgroup LoginStatus 登录状态
 * @brief 登录状态
 * @{
 */
extern const int NT_E_LS_NOT_LOGIN;         ///< 未登录
extern const int NT_E_LS_LOGIN_OK;          ///< 已经登录
/** @} */

/**
 * @getAuthType 登录账户类型 （对应的整形跟Android可能不同，建议使用 getAuthTypeName 来获取登录账户类型）
 * @brief 登录账户类型
 * @{
 */
extern const int NT_AUTH_UNLOGIN;  //未登录
extern const int NT_AUTH_NATIVE;   //本SDK默认的账户
extern const int NT_AUTH_GUEST;    //游客
extern const int NT_AUTH_WEIBO;    //微博
extern const int NT_AUTH_FACEBOOK; //Facebook
extern const int NT_AUTH_GameCenter; //Apple GameCenters
extern const int NT_AUTH_WECHAT;    //微信
extern const int NT_AUTH_GARENA;    // Garena
extern const int NT_AUTH_BEETALK;   // BeeTalk
extern const int NT_AUTH_QQ;        //QQ
extern const int NT_AUTH_GOOGLE;    //GOOGLE+
extern const int NT_AUTH_JOYBOMB;   //JOYBOMB
extern const int NT_AUTH_MOBILE;    //mobile
extern const int NT_AUTH_KAKAO;     //Kakao talk
extern const int NT_AUTH_TWITTER;     //Twitter

/**
 * @getAuthTypeName 登录账户类型的名称
 * @brief 登录账户类型
 * @{
 */
extern NSString* const NT_AUTH_NAME_UNLOGIN;// = @"unlogin";  //未登录
extern NSString* const NT_AUTH_NAME_NATIVE;// = @"native";   //本SDK默认的账户
extern NSString* const NT_AUTH_NAME_GUEST;// = @"guest";    //游客
extern NSString* const NT_AUTH_NAME_WEIBO;// = @"weibo";    //微博
extern NSString* const NT_AUTH_NAME_FACEBOOK;// = @"facebook"; //facebook
extern NSString* const NT_AUTH_NAME_TWITTER;// = @"twitter"; //twitter
extern NSString* const NT_AUTH_NAME_GAMECENTER;// = @"gamecenter";   //Apple GameCenters
extern NSString* const NT_AUTH_NAME_WECHAT;// = @"wechat"; //微信
extern NSString* const NT_AUTH_NAME_GARENA;// = @"garena"; // Garena
extern NSString* const NT_AUTH_NAME_BEETALK;// = @"beetalk"; // BeeTalk
extern NSString* const NT_AUTH_NAME_QQ;// = @"qq";
extern NSString* const NT_AUTH_NAME_GOOGLE;// = @"google"; //Google
extern NSString* const NT_AUTH_NAME_JOYBOMB;// = @"joybomb";

extern NSString* const NT_AUTH_NAME_MOBILE;// = @"mobile"; ///< 手机号
extern NSString* const NT_AUTH_NAME_DUOKU;// = @"duoku";///< 多酷登陆
extern NSString* const NT_AUTH_NAME_91;// = @"91";///< 91登陆
extern NSString* const NT_AUTH_NAME_KAKAO;// = @"kakao";///< kakao talk

extern NSString* const LOGIN_TYPE; //登录的渠道（NetMarble允许G+\FB\GameCenter登录）

extern NSString* const EXTEND_FUNC_RETURN; //扩展函数返回值
/**
 *  使用的渠道SDK
 */
extern NSString* const NT_SDK_NETEASE;  //网易SDK
extern NSString* const NT_SDK_YIXIN;  //易信SDK

/**
 * @brief 未登录时如果调用获取session会得到的值
 */
extern NSString* const NT_S_NOT_LOGIN_SESSION;

/**
 * @brief 本未登录时如果调用获取TIMESTAMP会得到的值
 */
extern NSString* const NT_S_NOT_TIMESTAMP;

/**
 * @brief 本未登录时如果调用获取APP_CHANNEL会得到的值
 */
extern NSString* const NT_S_NOT_APP_CHANNEL;

/**
 * @brief 无效device id
 */
extern NSString* const NT_INVALID_DEVICE_ID;

/**
 * @brief 道具付费单价上限
 */
extern const float NT_C_MAX_PRICE;

/**
 * @brief 无效uid标志
 */
extern NSString* const NT_INVALID_UID;

/**
 * @brief 用户的ID字段 注意，本字段需在用户登录成功后，在UI线程中设置上
 */
extern NSString* const NT_UID;
/**
 * @brief 用户的完整ID字段 格式是 xxx@ad.yyyy.win.163.com
 * xxx是平台返回的UID，yyyy是渠道字符串
 */
extern NSString* const NT_FULL_UID;

/**
 * @brief 用户的设备ID字段 注意，本字段需在用户登录成功后，在UI线程中设置上
 */
extern NSString* const NT_DEVICE_ID;

/**
 * @brief udid 在ios6及以上版本为IDFA，在ios5及以下为mac地址
 */
extern NSString* const NT_UDID;

/**
 * @brief cpid 
 */
extern NSString* const NT_CPID; //Line IAP支付的cpid

/**
 * @brief username
 */
extern NSString* const NT_USR_NAME;

/**
 *  @brief  user key
 */
extern NSString* const NT_USER_KEY;
/**
 * @brief 用户的SESSION字段 注意，本字段需在用户登录成功后，在UI线程中设置上
 *        部分SDK的SESSION字段可能有有效期，所以要注意更新本字段内容
 */
extern NSString* const NT_SESSION;
/**
 * @brief 用户登陆的timestamp字段 注意，本字段需在用户登录成功后，在UI线程中设置上
 *        部分SDK的TIMESTAMP字段可能有有效期，所以要注意更新本字段内容
 */
extern NSString* const NT_TIMESTAMP;

/**
 * @brief NT_APP_CHANNEL  通过.data文件读取，默认please_input_appchannel
 */
extern NSString* const NT_APP_CHANNEL;

/**
 * @brief NT_LOGIN_CHANNEL  通过.data文件读取，默认为nil
 */
extern NSString* const NT_LOGIN_CHANNEL;

/**
 * @defgroup SdkFeature Sdk功能点
 * @brief 每个sdk具备的功能点不一样，在调用之前请先用hasFeature查询一下
 * @{
 */
extern NSString* const NT_MODE_HAS_LOGOUT;          ///< 登出功能
extern NSString* const NT_MODE_HAS_MANAGER;         ///< 账户管理功能
extern NSString* const NT_MODE_HAS_PAUSE_VIEW;      ///< 暂停页，目前91有这个功能
extern NSString* const NT_MODE_NEED_UNITED_LOGIN;   ///< 登录了SDK就自动直接进入游戏，目前是UC有此功能
extern NSString* const NT_MODE_EXIT_VIEW;           ///< 退出页面功能，目前只有91有这个功能
extern NSString* const NT_MODE_HAS_GUEST;           ///< 游客功能，目前只有网易有此功能
extern NSString* const NT_MODE_USE_IAP;             ///< 使用IAP内付
extern NSString* const NT_MODE_MULTI_SDK;           ///< 多SDK
extern NSString* const NT_MODE_HAS_CONVERSATION;    ///< 会话界面
extern NSString* const NT_MODE_HAS_FAQS;            ///< FAQ界面
/** @} */

/**
 * @defgroup AttachGameEngine 游戏引擎类型
 * @brief 使用本sdk的引擎类型
 * @{
 */
extern NSString* const NT_GAME_ENGINE;
extern const int NT_ENGINE_COCOS;                   ///< cocos2d-x引擎
extern const int NT_ENGINE_UNITY3D;                 ///< Unity3D引擎
extern const int NT_ENGINE_NEOX;                    ///< NeoX引擎
/** @} */

/**
 * @brief 是否Debug Mode
 */
extern NSString* const NT_ENABLE_DEBUG_MODE;

/**
 * @brief 打印Debug Log
 */
extern NSString* const NT_ENABLE_DEBUG_LOG;

/**
 * @brief 是否开放游客登录，目前支持的渠道：网易 网易海外版
 */
extern NSString* const NT_ENABLE_EXLOGIN_GUEST;

/**
 * @brief 是否开放新浪微博第三方登录，目前支持的渠道：网易
 */
extern NSString* const NT_ENABLE_EXLOGIN_WEIBO;

/**
 * @brief 是否开放新浪微博SSO第三方登录，目前支持的渠道：网易
 */
extern NSString* const NT_ENABLE_EXLOGIN_WEIBO_SSO;

/**
 * @brief 是否开放易信第三方登录，目前支持的渠道：网易
 */
extern NSString* const NT_ENABLE_EXLOGIN_YIXIN;
//
/**
 * @brief 是否开放微信第三方登录，目前支持的渠道：网易
 */
extern NSString* const NT_ENABLE_EXLOGIN_WECHAT;

/**
 * @brief 是否开放QQ第三方登录，目前支持的渠道：网易
 */
extern NSString* const NT_ENABLE_EXLOGIN_QQ;

/**
 * @brief 是否开放FACEBOOK第三方登录，目前支持的渠道：网易海外版
 */
extern NSString* const NT_ENABLE_EXLOGIN_FACEBOOK;

/**
 * @brief 是否开放GOOGLE第三方登录，目前支持的渠道：网易海外版
 */
extern NSString* const NT_ENABLE_EXLOGIN_GOOGLE;

/**
 * @brief 游戏发行的区域 0:亚洲地区，主要是香港, 1:北美地区，目前支持的渠道：网易海外版
 */
extern NSString* const NT_GAME_REGION;

/**
 * @brief 游戏语言 目前支持的渠道：网易海外版
 
 Default = 0,             // System Language
 English = 1,             // English
 ChineseSimplified = 2,   // Chinese Simplified
 ChineseTraditional = 3,  // Chinese Traditional
 Spanish = 4,             // Spanish
 Portuguese = 5,          // Portuguese
 
 */
extern NSString* const NT_GAME_LANGUAGE;

/**
 * @brief 用于绑定游客，用于：网易
 */
extern NSString* const NT_ORIGIN_GUEST_UID;

/**
 * @brief 玩家角色ID
 */
extern NSString* const NT_USERINFO_UID;

/**
 * @brief 计费玩家ID
 */
extern NSString* const NT_USERINFO_AID;

/**
 * @brief 玩家角色昵称
 */
extern NSString* const NT_USERINFO_NAME;

/**
 * @brief 玩家角色等级
 */
extern NSString* const NT_USERINFO_GRADE;

/**
 * @brief 玩家角色所属服务器ID
 */
extern NSString* const NT_USERINFO_HOSTID;

/**
 * @brief 玩家角色所属服务器名称
 */
extern NSString* const NT_USERINFO_HOSTNAME;

/**
 * @brief 玩家VIP等级
 */
extern NSString* const NT_USERINFO_VIP;

/**
 * @brief 玩家帮派
 */
extern NSString* const NT_USERINFO_ORG;

/**
 * @brief 玩家帮派名称
 */
extern NSString* const NT_USERINFO_ORGNAME;


/**
 * @brief 玩家职业（门派）名称
 */
extern NSString* const NT_USERINFO_CAREERNAME;

/**
 * @brief 玩家经验值
 */
extern NSString* const NT_USERINFO_EXP;

/**
 * @brief 玩家钻石数量
 */
extern NSString* const NT_USERINFO_DIAMOND;

/**
 * @brief 玩家自定信息
 */
extern NSString* const NT_USERINFO_CUSTOMDATA;

/**
 * @brief Oauth Access Token
 */
extern NSString* const NT_OAUTH_ACCESS_TOKEN;

/**
 * @brief Oauth Refresh Token
 */
extern NSString* const NT_OAUTH_REFRESH_TOKEN;

/**
 * @brief Oauth Access Token 有效时间
 */
extern NSString* const NT_OAUTH_ACCESS_EXPIRES;

/**
 * @brief cdn server 服务器 line渠道
 */
extern NSString* const NT_CDN_SERVER;

/**
 * @brief cdn server 支付的服务器IP
 */
extern NSString* const NT_PURCHASE_REG_SERVER; //预约register
extern NSString* const NT_PURCHASE_VRF_SERVER; //验证verify

/**
 * @brief 所有错误状态返回字典的KEY 状态码及内容
 */
extern NSString * const NT_ERROR_CODE;
extern NSString * const NT_ERROR_MSG;

/**
 * @brief 是否打开币种限制的功能(乱斗Line渠道特有)
 * 赋值“0”则不走限制流程，“1”则打开币种限制（如果NtOrderInfo币种字段赋值就会起效）
 */
extern NSString * const NT_IS_CURRENCY_RESTRICT_OPEN;
extern NSString * const NT_PRODUCT_LIST;//获取币种要用到的商品Id列表
extern NSString * const NT_CURRENCY;//AppleID对应的币种
//extern NSString * const NT_PRODUCT_INFO;//对应的价格

/**
 *  @brief 获取好友列表的参数：开始的序号，每次获取的最大人数。
 */
extern NSString* const NT_QUERY_FRIENDS_START_INDEX;
extern NSString* const NT_QUERY_FRIENDS_COUNT;
extern NSString* const NT_QUERY_FRIENDS_IN_GAME_START_INDEX;
extern NSString* const NT_QUERY_FRIENDS_IN_GAME_COUNT;
extern NSString* const NT_QUERY_FRIENDS_TOTAL; //存储line返回的好友数
extern NSString* const NT_QUERY_FRIENDS_IN_GAME_TOTAL; //存储line返回的游戏好友数
/**
 *  @brief NetMarble 弹出页面
 */
extern NSString* const NT_WEB_NOTICE_INTRO; //公示-游戏开始页面自动进行时显示
extern NSString* const NT_WEB_NOTICE_INGAME; //公示-点击游戏内公告事项按钮时显示
extern NSString* const NT_WEB_PROMOTION_MAIN; //活动推广-在游戏开始页面显示
extern NSString* const NT_WEB_PROMOTION_EVENT; //活动推广-指定活动菜单显示
extern NSString* const NT_WEB_PROMOTION_ETC; //活动推广-其他菜单显示
extern NSString* const NT_WEB_COUPON; //商品券
extern NSString* const NT_WEB_CUSTOMER_SUPPORT_HOME;//客服-中心主页
extern NSString* const NT_WEB_CUSTOMER_SUPPORT_FAQ;//客服-经常咨询的内容
extern NSString* const NT_WEB_CUSTOMER_SUPPORT_INQUIRY;//客服-咨询
extern NSString* const NT_WEB_CUSTOMER_SUPPORT_GUIDE;//客服-帮助指南
extern NSString* const NT_WEB_CUSTOMER_SUPPORT_HISTORY;//客服-咨询历史
extern NSString* const NT_WEB_GAME_REVIEW;//游戏评价
extern NSString* const NT_WEB_FREE_CHARGEVIEW;//交叉推荐页

extern NSString* const NT_WEB_INFO_STATE; //状态回调
extern NSString* const NT_WEB_OPENED;
extern NSString* const NT_WEB_CLOSED;
extern NSString* const NT_WEB_FAILED;
extern NSString* const NT_WEB_REWARDED;

/**
 *  @brief Entermate 弹出页面
 */
extern NSString* const NT_WEB_SERVICE_RULE; //服务条款
extern NSString* const NT_WEB_PRIVACY_RULE; //隐私条款

/**
 *  @brief NetMarble 关联渠道ID结果 
 *  0:OK        // 关联成功
 *  1:FAILED    // 关联失败
 *  2:NEWID     // 新关联，可供三种关联类型更新：Cancel, Update or Create
 *  3:USEDID    // 频道已经关联过，可供三种关联类型更新：Cancel, Update or Load
 *  4:MODIFIED  // 关联变更，可供两种关联类型更新：Cancel or Update
 */
extern NSString* const NT_CONNECT_RESULT; //关联或者取消关联的结果
extern NSString* const NT_DISCONNECT_RESULT; //取消关联的结果
/**
 *  @brief  NetMarble 关联的选择
 *  0:Cancel    // 取消绑定
 *  1:Update    // 更新绑定关系
 *  2:Load      // 加载旧的绑定关系
 *  3:Create    // 建立一个新的PID跟渠道ID绑定
 */
extern NSString* const NT_CONNECT_OPTION; //关联的选择


typedef NS_ENUM(int, DRPFCode) {
    DRPF_SUCCESS                = 0,
    DRPF_ERR_NO_PROJECT         = 1,
    DRPF_ERR_NO_SOURCE          = 2,
    DRPF_ERR_NO_TYPE            = 3,
    DRPF_ERR_JSON               = 4,
    DRPF_ERR_INVALID_INPUT_JSON = 5,
};

/**
 * @brief 游客服务端URL
 */
extern NSString* const UNISDK_GUEST_SERVER_URL;
/**
 * @brief 游客是否开启解绑功能
 */
extern NSString* const ENABLE_UNISDK_GUEST_DISCONNECT;

/**
 * @brief 游客是否开启UI功能
 */
extern NSString* const ENABLE_UNISDK_GUEST_UI;

/**
 * @brief 是否请求unisdk 服务端(申请订单号，访问mpay_result接口)
 */
extern NSString* const REQUEST_UNISDK_SERVER;

/**
 * @brief unisdk请求订单url
 */
extern NSString* const UNISDK_QUERYPRODUCT_URL;

/**
 * @brief unisdk根据索引请求订单详情
 */
extern NSString* const UNISDK_GETORDERINFO_URL;
/**
 * @brief unisdk请求订单url
 */
extern NSString* const UNISDK_CREATEORDER_URL;

/**
 * @brief unisdk mpay_resutl 通知url
 */
extern NSString* const UNISDK_QUERYORDER_URL;

/**
 * @brief unisdk consume_resutl 通知url
 */
extern NSString* const UNISDK_CONSUMEORDER_URL;

/**
 * @brief unisdk 公钥
 */
extern NSString* const UNISDK_PUBLIC_KEY;

/**
 * @brief unisdk Log 服务器地址
 */
extern NSString* const UNISDK_LOG_SERVER;

/**
 * @brief unisdk Log 开关状态
 */
extern NSString* const UNISDK_LOG_STATUS;

/**
 * @brief 普通支付是否使用Gas3计费系统
 */
extern NSString* const UNISDK_JF_GAS3;

/**
 * @brief 扫码支付是否使用Gas3计费系统
 */
extern NSString* const UNISDK_JF_GAS3_WEB;

/**
 * @brief 计费Gas3系统的域名URL
 */
extern NSString* const UNISDK_JF_GAS3_URL;

/**
 * @brief 设置一些额外的信息
 */
extern NSString* const UNISDK_EXT_INFO;

/**
 * @brief 是否启用WEB支付方式 (Mobithink使用)
 */
extern NSString* const NT_WEBPAY_MODE;

/**
 * @brief WEB支付URL (Mobithink使用)
 */
extern NSString* const NT_WEBPAY_URL;

/**
 *  @brief  收费凭证（@"0"表示用旧的Receipt接口,@"1"表示用新的Receipt接口）
 */
extern NSString* const NT_RECEIPT_TYPE;

/**
 *  @brief  publicKeyUrl （GameCenter功能）
 */
extern NSString* const NT_PUBLICKEY_URL;

/**
 *  @brief  salt （GameCenter功能）
 */
extern NSString* const NT_SALT;

/**
 *  @brief  玩家角色类型ID (网易SDK)
 */
extern NSString* const NT_USERINFO_TYPEID;
extern NSString* const NT_USERINFO_ROLE_TYPE_ID; //兼容安卓

/**
 *  @brief  玩家角色类型名称（以梦幻西游为例，剑侠客、骨精灵等等，用于区分不同的角色形象） (网易SDK)
 */
extern NSString* const NT_USERINFO_TYPENAME;
extern NSString* const NT_USERINFO_ROLE_TYPE_NAME; //兼容安卓

/**
 *  @brief  玩家角色门派ID (网易SDK)
 */
extern NSString* const NT_USERINFO_MENPAIID;
extern NSString* const NT_USERINFO_MENPAI_ID; //兼容安卓

/**
 *  @brief  玩家角色门派名称（以梦幻西游为例，大唐官府、龙宫等等，用于区分不同的门派） (网易SDK)
 */
extern NSString* const NT_USERINFO_MENPAINAME;
extern NSString* const NT_USERINFO_MENPAI_NAME; //兼容安卓

/**
 *  @brief  玩家角色战力 (网易SDK)
 */
extern NSString* const NT_USERINFO_CAPABILITY;

/**
 *  @brief  玩家角色帮派ID (网易SDK)
 */
extern NSString* const NT_USERINFO_GANDID;
extern NSString* const NT_USERINFO_GANG_ID;  //兼容安卓

/**
 *  @brief  玩家角色帮派名称 (网易SDK)
 */
extern NSString* const NT_USERINFO_GAND;

/**
 *  @brief  玩家角色服务器区域ID (网易SDK)
 */
extern NSString* const NT_USERINFO_REGION_ID;

/**
 *  @brief  玩家角色服务器区域名字 (网易SDK)
 */
extern NSString* const NT_USERINFO_REGION;
extern NSString* const NT_USERINFO_REGION_NAME;

/**
 *  @brief  玩家角色信息，自定义部分 (网易SDK)
 */
extern NSString* const NT_USERINFO_OTHERS;


/**
 *  @brief  IAP支付的ReceiptData的Key值 ! 请不要修改值的内容!
 *  key是跟计费协商定好的。
 */
extern NSString* const NT_KEY_RECEIPTDATA;
extern NSString* const NT_KEY_TRANSACTIONID;
extern NSString* const NT_KEY_PRODUCTID;
extern NSString* const NT_KEY_VERSION;

/**
 *  @brief  域名 (Helpshift SDK)
 */
extern NSString* const NT_DOMAIN;

/**
 * @brief 用户邮箱(Helpshift SDK)
 */
extern NSString* const NT_EMAIL;

/**
 * @brief 用户邮箱(Facebook SDK)
 */
extern NSString* const NT_UEMAIL;

/**
 * @brief 用户性别(Facebook SDK)
 */
extern NSString* const NT_UGENDER;

/**
 * @brief 用户生日(Facebook SDK)
 */
extern NSString* const NT_UBIRTHDAY;

/**
 * @brief 用户地区(Facebook SDK)
 */
extern NSString* const NT_UHOMETOWN;

/**
 * @brief 用户age(Facebook SDK)
 */
extern NSString* const NT_UAGE;

/**
 * @brief 获取渠道原生UID(Joybomb SDK)
 */
extern NSString* const CHANNEL_UID;//建议使用带NT开头的变量名
extern NSString* const NT_CHANNEL_UID;
extern NSString* const NT_FB_UID; // Facebook UID
extern NSString* const NT_USER_ID;// G+ UID

/**
 * @brief 为支持未接入计费系统的游戏的支付对账, 上传首次打开游戏日志到计费指定的地址 （以后游戏不用设置这个值，底层直接写死这个URL。20161122）
 */
extern NSString* const NT_JF_OPEN_LOG_URL;

/**
 * @brief 为支持未接入计费系统的游戏的支付对账, 上传单机版充值日志到计费指定的地址 （以后游戏不用设置这个值，底层直接写死这个URL。20161122）
 */
extern NSString* const NT_JF_PAY_LOG_URL;

/**
 * @brief 为支持未接入计费系统的游戏的支付对账, 上传单机版充值日志和首次打开游戏日志到计费时需要的AES key
 */
extern NSString* const NT_JF_LOG_KEY;

/**
 * @brief 计费为手游分配的ID
 */
extern NSString* const NT_JF_GAMEID;

/**
 * @brief 游戏是否在计费配置有支付回调
 */
extern NSString* const NT_HAS_PAY_CB;

/**
 * @brief 游戏配置支付回调
 */
extern NSString* const NT_PAY_CB_URL;

/**
 * @defgroup Swrve相关
 * @brief Swrve相关
 * @{
 */
extern NSString* const NT_SWRVE_FUNC;

extern NSString* const NT_SWRVE_FUNC_EVENT;
extern NSString* const NT_SWRVE_EVENT_NAME;
extern NSString* const NT_SWRVE_EVENT_PAYLOAD;

extern NSString* const NT_SWRVE_FUNC_PURCHASE;
extern NSString* const NT_SWRVE_PURCHASE_ITEM;
extern NSString* const NT_SWRVE_PURCHASE_CURRENCY;
extern NSString* const NT_SWRVE_PURCHASE_COST;
extern NSString* const NT_SWRVE_PURCHASE_QUANTITY;

extern NSString* const NT_SWRVE_FUNC_CURRENCYGIVEN;
extern NSString* const NT_SWRVE_CURRENCYGIVEN_CURRENCY;
extern NSString* const NT_SWRVE_CURRENCYGIVEN_AMOUNT;

extern NSString* const NT_SWRVE_FUNC_IAP;
extern NSString* const NT_SWRVE_IAP_QUANTITY;
extern NSString* const NT_SWRVE_IAP_PRODUCTID;
extern NSString* const NT_SWRVE_IAP_PRODUCTPRICE;
extern NSString* const NT_SWRVE_IAP_CURRENCY;
extern NSString* const NT_SWRVE_IAP_REWARDS;

extern NSString* const NT_SWRVE_FUNC_USERUPDATE;
extern NSString* const NT_SWRVE_USERUPDATE_ATTRIBUTES;

extern NSString* const NT_SWRVE_RESOURCE;
/** @} */

/**
 * @defgroup 回调是传递，与Android统一
 * @{
 */

extern NSString* const NT_CALLBACK_MESSAGE;

/**
 * @defgroup 用户协议配置的URL，与Android统一
 * @brief
 * @{
 */
extern NSString* const NT_COMPACT_URL;// = @"COMPACT_URL";
extern NSString* const NT_COMPACT_LAN;// = @"COMPACT_LAN";

/**
 *  计费登录的字符串参数
 */
extern NSString* const NT_SAUTH_STR;
extern NSString* const NT_SAUTH_JSON;


/**
 * @brief SDK服务端URL
 */
extern NSString* const NT_SDK_SERVER_URL;


/**
 * @brief SDK渠道的CHANNEL ID （7rd渠道用到）
 */
extern NSString* const NT_SDK_CHANNEL_ID;

/**
 * @brief NT_SDK_NEW_ROLE标识此角色是否为新创建 0不是 1是 （7rd渠道用到）
 */
extern NSString* const NT_SDK_NEW_ROLE;


/**
 * @defgroup SDC_LOG_XXX
 * @brief 返回通过UNISDK可以获取的SDC所需要的参数
 * @{
 */
extern NSString* const NT_SDC_LOG_DEVICE_HEIGHT ;//= @"SDC_LOG_DEVICE_HEIGHT";
extern NSString* const NT_SDC_LOG_DEVICE_WIDTH ;//= @"SDC_LOG_DEVICE_WIDTH";
/**
 * @brief 操作系统，直接通过系统提供API返回的字符串，如ios, android, windows, ubuntu, symbian等
 * */
extern NSString* const NT_SDC_LOG_OS_NAME ;//= @"SDC_LOG_OS_NAME";
/**
 * @brief 操作系统版本，设备操作系统版本号 如：6.1, 2.3等
 * */
extern NSString* const NT_SDC_LOG_OS_VER ;//= @"SDC_LOG_OS_VER";
/**
 * @brief 设备mac地址   如08:00:20:0A:8C:6D
 * */
extern NSString* const NT_SDC_LOG_MAC_ADDR ;//= @"SDC_LOG_MAC_ADDR";
/**
 * 直接获取通过系统提供API返回的设备制造商, 设备型号, CPU名称, CPU核心数, CPU频率,
 * GPU名称字符串，并使用分割符号#进行拼接。
 */
extern NSString* const NT_SDC_LOG_DEVICE_MODEL ;//= @"SDC_LOG_DEVICE_MODEL";
/**
 * @brief 设备UDID号, 具体参见关于UDID说明章节，用于统计设备数
 * */
extern NSString* const NT_SDC_LOG_UDID ;//= @"SDC_LOG_UDID";
/**
 * @brief 运营渠道，如app_store/ 91_assistant/netease等，目前直接取已有的APP_CHANNEL字段
 * */
extern NSString* const NT_SDC_LOG_APP_CHANNEL ;//= @"SDC_LOG_APP_CHANNEL";
/**
 * @brief 客户端版本号，安卓目前从manifest里面读取, iOS则是读info.plist中的设置
 * */
extern NSString* const NT_SDC_LOG_APP_VER ;//= @"SDC_LOG_APP_VER";
/**
 * @brief 网络连接，例如有  3g, 2.5g, 4g, wifi几种
 * */
extern NSString* const NT_SDC_LOG_APP_NETWORK ;//= @"SDC_LOG_APP_NETWORK";
/**
 * @brief 网络运营商，如果可以获取IMSI（安卓或越狱IOS）则记录IMSI编码即可。
 *	非越狱IOS记录mobile country code (MCC)+ mobile network code (MNC)
 *	（IOS见CTCarrier Class）MCC是固定3位 MNC是2位或者3位，如果MCC=480 MNC=20，则记录为48020
 */
extern NSString* const NT_SDC_LOG_APP_ISP ;//= @"SDC_LOG_APP_ISP";

/**
 * @brief 用户协议用到
 */
extern NSString* const NT_SDK_COMPACT_MODE;

/**
 * @brief 网易SDK主题资源文件名
 */
extern NSString* const NT_SKIN_TYPE;

/**
 * @brief 调查问卷用到，打开的webview的背景颜色
 * 0 白色 (默认)
 * 1 透明
 */
extern NSString* const NT_WEBVIEW_BKCOLOR;//@"WEBVIEW_BKCOLOR";

