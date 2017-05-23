//
//  NtOrderInfo.h
//  NtUniSdk
//
//  Created by Huang Quanyong on 14-5-23.
//  Copyright (c) 2014年 Stupid Dumb Kids. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

/**
 *  @brief 订单支付状态
 */
enum NtOrderStatus
{
    NT_OS_PREPARING = 0,                    ///< 订单准备中
    NT_OS_SDK_CHECKING = 1,                 ///< 订单sdk查询中
    NT_OS_SDK_CHECK_OK = 2,                 ///< sdk订单支付成功
    NT_OS_SDK_CHECK_ERR = 3,                ///< sdk订单支付失败
    NT_OS_GS_CHECKING = 4,                  ///< 订单游戏服查询中
    NT_OS_GS_CHECK_OK = 5,                  ///< 订单游戏服支付成功
    NT_OS_GS_CHECK_ERR = 6,                 ///< 订单游戏服支付失败
    NT_OS_WRONG_PRODUCT_ID = 7,             ///< 订单道具id错误
    NT_OS_SDK_INVALIDE_PRICE_LOCALE_ID = 8, //< 订单支付货币有问题
    NT_OS_SDK_INVALID_CURRENCY = 9,         //< 订单支付货币有问题(G4_LINE_兼容安卓)
};


//订单支付失败的描述,对应的文本请不要更改，游戏可能会根据这些文本判断失败的原因
static NSString *const Nt_Another_order_is_checking = @"Another_order_is_checking";
static NSString *const Nt_Can_not_make_payments = @"Can_not_make_payments";
static NSString *const Nt_Receipt_not_exist = @"Receipt_not_exist";
static NSString *const Nt_Illegal_currency = @"Illegal_currency";
static NSString *const Nt_Invalid_product_id = @"Invalid_product_id";
static NSString *const Nt_SKPayment_transaction_failed = @"SKPayment_transaction_failed"; //这个是开头，后面带有苹果返回的失败原因描述
static NSString *const Nt_Query_product_from_jf_failed = @"Query_product_from_jf_failed";//从计费server获取商品信息失败
static NSString *const Nt_Invalid_uid = @"Invalid_uid"; //扫描二维码获取到的账号id不匹配
static NSString *const Nt_Invalid_data_id = @"Invalid_data_id"; //扫描二维码获取到的data_id为空
static NSString *const Nt_Get_orderinfo_from_jf_failed = @"Get_orderinfo_from_jf_failed";//根据索引从计费server获取订单信息失败
static NSString *const Nt_Create_order_id_failed = @"Create_order_id_failed";//从计费server创建订单号失败
/**
 *  @brief 订单信息
 */
@interface NtOrderInfo : NSObject
{
@private
    NSString* orderId;              //订单号，由unisdk生成
    NSString* sdkOrderId;
    NSString* productId;            //商品id
    NSString *_productName;          //商品名称
    float productCurrentPrice;      //当前价格，一般是productPrice的打折价
    int productCount;               //购买数量
    NSString* orderDesc;            //
    int orderStatus;                //订单状态
    NSString* orderErrReason;       //错误信息
    
    //4 APP STORE IAP
    SKPayment* payment;
    NSData *transactionReceipt;     //收据
    id<NSCoding> userData;          //一般存储角色ID信息（分服的情况要传这个值）
    NSString *_userPriceLocaleId;   //玩家付款时的货币币种
    
    

};

/**
 *  允许使用的货币(暂为G18使用)
 *  列表成员为NSString，如：@"CNY", @"USD", @"JPY"
 *  如果不传值，则默认允许所有币种。币种缩写查询：
 *  http://www.easy-forexr.com/zhishi/huobisuoxie.html or http://www.huilvwang.com/
 */
@property (nonatomic, strong) NSArray *arrPriceLocaleId;


//@property (nonatomic, copy) NSString *userPriceLocaleId;

/**
 *  支付完成后获得的收据数据(line渠道特有)
 */
@property (nonatomic, strong) SKPaymentTransaction *paymentTransaction;

/**
 *  订单失败的错误码
 */
@property (nonatomic, copy) NSString *errCode;

/**
 *  @brief  传入userData一样的角色id。这个字段用于applicationUserName,通常跟USERINFO_UID用户角色id一样。
 */
@property (nonatomic, copy) NSString *userName;
/**
 *  @brief  账号ID，表示订单是哪个用户账号充的值,
 */
@property (nonatomic, copy) NSString *uid; //存keychain
/**
 *  @brief  服务器ID，表示订单是给哪个服务器上的角色充值,
 */
@property (nonatomic, copy) NSString *serverId; //扫码支付在创建订单的时候用到
/**
 *  @brief  计费用户ID，在扫码支付时，创建订单的时候需要传这个aid,
 */
@property (nonatomic, copy) NSString *aid; //创建订单的时候需要用到

/**
 *  订单购买的数据(netmarble渠道)
 */
@property (nonatomic, strong) NSDictionary *dictPurchase;
//验证订单返回的数据
@property (nonatomic, copy) NSString *response;

// apple支付完成后，返回的交易流水号
@property (nonatomic, copy) NSString *transactionIdentifier;

/**
 *  订单所处的阶段CODE(GarenaSDK使用)
 */
@property (nonatomic, assign) int orderStage;

@property (nonatomic, copy) NSString *loginChannelIdentifier;// FOR yixin netease

@property (nonatomic, copy)NSString *etc;       //netmarble渠道生成订单用的

/**
 *  从苹果服务端获取到的商品价格和币种（用于给计费发log）
 */
@property (nonatomic, copy)NSString *currencyForLog;
@property (nonatomic, copy)NSString *priceForLog;

/**
 *  订单加密用的key
 */
@property (nonatomic, copy)NSString *cipherKey;

/**
 *  是否网页版支付（是网页版的话订单数据发往unisdk server）
 */
@property (nonatomic, )BOOL webPayment;
@property(nonatomic, strong)NSString *qrCodeDataId; //扫码支付二维码的dataid;

/**
 *  @brief 静态初始化函数，用于初始化某些额外信息
 */
+ (void) initialize;
/**
 *  @brief 注册商品
 *
 *  在SDK中注册商品信息，商品信息将用于填充即将支付的订单信息
 *
 *  @param pId    商品ID，如使用AppStore IAP，商品ID需要与iTunes Connect上填写的ProductID一致
 *  @param pName  商品名称
 *  @param pPrice 商品价格
 *  @param eRatio 虚拟货币兑换比率
 */
+ (void) regProduct:(NSString*) pId Name:(NSString*) pName Price:(float) pPrice Ratio:(int) eRatio;
/**
 *  @brief 注册商品
 *
 *  在SDK中注册商品信息，商品信息将用于填充即将支付的订单信息
 *
 *  @param pId    商品ID，如使用AppStore IAP，商品ID需要与iTunes Connect上填写的ProductID一致
 *  @param pName  商品名称
 *  @param pPrice 商品价格
 *  @param eRatio 虚拟货币兑换比率
 *  @param bid
 */
+ (void) regProduct:(NSString*) pId Name:(NSString*) pName Price:(float) pPrice Ratio:(int) eRatio Bid:(NSString *)bid;

///**
// *  @brief 注册商品, 这个接口用于苹果支付， pId = pId, pName = @"", price = 1.0, ration = 1 bid = @"";
// */
//+ (void)regProduct:(NSString*)pId;

/**
 *  @brief 查询是否存在某种商品
 *
 *  @param pId 商品ID
 *
 *  @return 是否存在对应ID的商品
 */
+ (BOOL) hasProduct:(NSString*) pId;



/**
 根据游戏内商品id（bid/goodsId）索引到苹果的商品id（productId）。私有接口，外部不要调用

 @param bid 游戏内商品id，在计费那边设定的一个商品id，跟苹果商品id有一一对应关系

 @return 苹果的商品id
 */
+ (NSString *)getProductIdFromBid:(NSString *)bid;

/**
 *  @brief 初始化函数
 *
 *  @return 初始化后的NtOrderInfo对象
 */
- (NtOrderInfo*) init;
/**
 *  @brief 初始化函数，使用商品ID对订单进行初始化，该商品ID指示了订单将要购买的商品
 *
 *  @param pId 该订单将要购买的商品
 *
 *  @return 初始化后的NtOrderInfo对象
 */
- (NtOrderInfo*) initWithProductId:(NSString*) pId;
/**
 *  @brief 初始化函数，使用订单信息进行初始化，将初始化出一个与传入订单信息相同的新订单
 *
 *  @param info 用于初始化的订单信息
 *
 *  @return 初始化后的NtOrderInfo对象
 */
- (NtOrderInfo*) initWithNtOrderInfo:(NtOrderInfo*) info;

/**
 *  @brief 获取订单ID
 *
 *  @return 订单ID
 */
- (NSString*) getOrderId;
/**
 *  @brief 设置订单ID
 *
 *  @param orderId 订单ID
 */
- (void) setOrderId:(NSString*) orderId;

/**
 *  @brief 获取SDK订单ID
 *
 *  @return SDK订单ID
 */
- (NSString*) getSdkOrderId;
/**
 *  @brief 设置SDK订单ID
 *
 *  @param sdkOrderId SDK订单ID
 */
- (void) setSdkOrderId:(NSString*) sdkOrderId;

/**
 *  @brief 获取订单中指定购买的商品ID
 *
 *  @return 订单中指定购买的商品ID
 */
- (NSString*) getProductId;

- (NSString*) getBid;

/**
 *  @brief 设置获取订单中指定购买的商品ID
 *
 *  @param productId 订单中指定购买的商品ID
 */
- (void)setProductId:(NSString*) productId;

/**
 *  @brief 获取/设置订单中购买商品的名称
 *
 *  @return 购买商品的名称
 */
- (NSString*)getProductName;
- (void)setProductName:(NSString *)name;

/**
 *  @brief 获取订单中商品当前的单价
 *
 *  @return 商品当前的单价
 */
- (float) getProductCurrentPrice;
/**
 *  @brief 设置订单中商品当前的单价
 *
 *  @param productCurrentPrice 商品当前的单价
 */
- (void) setProductCurrentPrice:(float) productCurrentPrice;

/**
 *  @brief 获取订单中购买商品的数量
 *
 *  @return 购买商品的数量
 */
- (int) getCount;
/**
 *  @brief 设置订单中购买商品的数量
 *
 *  @param count 购买商品的数量
 */
- (void) setCount:(int) count;

/**
 *  @brief 获取订单描述信息
 *
 *  @return 订单描述信息
 */
- (NSString*) getOrderDesc;
/**
 *  @brief 设置订单描述信息
 *
 *  @param orderDesc 订单描述信息
 */
- (void) setOrderDesc:(NSString*) orderDesc;

/**
 *  @brief 获取订单中购买商品的信息
 *
 *  @return 订单中购买商品的信息
 */
- (id) getProductInfo;

/**
 *  @brief 获取订单中购买商品的原价
 *
 *  @return 购买商品的原价
 */
- (float) getProductPrice;
/**
 *  @brief 获取订单中购买商品的兑换比率
 *
 *  @return 购买商品的兑换比率
 */
- (int) getProductExchangeRatio;

/**
 *  @brief 获取订单支付状态
 *
 *  @return 订单支付状态，通用属性已于NtConstProp.h中定义
 */
- (int) getOrderStatus;

/**
 *  @brief 设置订单支付状态
 *
 *  @param orderStatus 订单支付状态，通用属性已于NtConstProp.h中定义
 */
- (void) setOrderStatus:(int) orderStatus;

/**
 *  @brief 获取订单错误描述
 *
 *  @return 订单的错误描述
 */
- (NSString*) getOrderErrReason;
/**
 *  @brief 设置订单错误描述
 *
 *  @param orderErrReason 订单的错误描述
 */
- (void)setOrderErrReason:(NSString*) orderErrReason;


//--- 4 APP STORE IAP --- //

/**
 *  @brief 获取已注册的商品列表
 *
 *  @return 已注册的商品列表
 */
+ (NSMutableDictionary*) getProductList;

/**
 *  @brief 获取订单的TransactionReceipt，仅用于App Store IAP
 *
 *  @return 订单的TransactionReceipt
 */
- (NSData*) getTransactionReceipt;
/**
 *  @brief 设置订单的TransactionReceipt，仅用于App Store IAP
 *
 *  @param receipt 订单的TransactionReceipt
 */
- (void) setTransactionReceipt:(NSData*)receipt;

/**
 *  @brief 获取订单对应的SKPayment信息，仅用于App Store IAP
 *
 *  @return 订单对应的SKPayment信息
 */
- (SKPayment*) getPayment;
/**
 *  @brief 设置订单对应的SKPayment信息，仅用于App Store IAP
 *
 *  @param skpayment 订单对应的SKPayment信息
 */
- (void) setPayment:(SKPayment*)skpayment;

/**
 *  @brief 获取订单对应的userData
 *
 *  @return 订单对应的userData
 */
- (id) getUserData;
/**
 *  @brief 设置订单对应的userData
 *
 *  @param uData 订单对应的userData
 */
- (void) setUserData:(id<NSCoding>) uData;

/**
 *  玩家付款时的货币币种
 *  （玩家支付时会有玩家appstore账号使用的币种）
 */
- (NSString *)getUserPriceLocaleId;
//set接口为内部接口，游戏请不要调用
- (void) setUserPriceLocaleId:(NSString *)currency;

- (NSString *)getUid;
- (void)setUid:(NSString *)uid;
- (NSString *)getUserName;
- (void)setUserName:(NSString *)userName;
- (NSString *)getErrCode;
- (void)setErrCode:(NSString *)errCode;
- (NSString *)getServerId;
- (void)setServerId:(NSString *)serverId;
- (NSString *)getAid;
- (void)setEtc:(NSString *)etc;
- (NSString *)getEtc;
- (NSString *)getPriceForLog;
- (NSString *)getCurrencyForLog;
- (NSString *)getQRCodeDataId;
/**
 *  是否网页支付
 */
- (BOOL)isWebPayment;
- (void)setIsWebPayment:(BOOL)isWebPayment;

/**
 * @brief 游戏开发人员不需要关注此接口。如需获取订单使用的支付渠道，请使用getOrderChannel()接口
 *
 * @return
 */
- (NSString *)getPayChannel;

/**
 * @brief 获取订单使用的支付渠道
 *
 * @return
 */
- (NSString *)getOrderChannel;

/**
 * @brief 获取订单所处的支付阶段(GarenaSDK使用)
 *
 * @return
 */
- (int)getOrderStage;

///**
// *  根据bid索引到对应的pid（NSString，如果不存在则返回空字符串）
// */
//- (NSString *)seakPidFromBid:(NSString *)bid;


@end


/**
 *  @brief 订单支付阶段(GarenaSDK使用)
 */
enum NtOrderStage
{
    Nt_OnNetworkError = 0,                  ///< 网络异常
    Nt_OnIAPPayFail = 1,                    ///< 连接APPLE服务器失败
    Nt_OnIAPPayFinish = 2,                  ///< APPLE支付成功结束
    Nt_OnDistributeGoodsFinish = 3,         ///< 同步APPLE订单到平台服务器
    Nt_OnDistributeGoodsFailure = 4,        ///< 同步APPLE订单到平台服务器失败（需手动调用ntDistributeGoods同步）
    Nt_OnRestoreNonConsumableFinish = 5,    ///< 点卡消费结束（暂不适用）
    Nt_OnRestoreNonConsumableFail = 6,      ///< 点卡消费失败（暂不适用）
};
