function NeteaseMpay_loadURL(url) {
    var iFrame;
    iFrame = document.createElement("iframe");
    iFrame.setAttribute("src", url);
    iFrame.setAttribute("style", "display:none;");
    iFrame.setAttribute("height", "0px");
    iFrame.setAttribute("width", "0px");
    iFrame.setAttribute("frameborder", "0");
    document.body.appendChild(iFrame);
    iFrame.parentNode.removeChild(iFrame);
    iFrame = null;
}

function connectWebViewJavascriptBridge(callback) {
    if (window.WebViewJavascriptBridge) {
        callback(window.WebViewJavascriptBridge);
    } else {
        document.addEventListener('WebViewJavascriptBridgeReady', function() {
            callback(window.WebViewJavascriptBridge);
        }, false);
    }
}

if (typeof(NeteaseMpayJSBridge) == "undefined") {
    var NeteaseMpayJSBridge = {};
    connectWebViewJavascriptBridge(function(bridge) {
        bridge.init(function(message, responseCallback) {
        });

        NeteaseMpayJSBridge.RelatedAccount = {
    // 手机号增加关联帐号(用于二次验证)
    'onMobileBindRelatedAccount': function(res) {
        bridge.callHandler('NeteaseMpayJSBridge.RelatedAccount.onMobileBindRelatedAccount', res);
    },

    // 验证关联手机结果回调
    'onVerifyRelatedMoible': function(res) {
        bridge.callHandler('NeteaseMpayJSBridge.RelatedAccount.onVerifyRelatedMoible', res);
    },

    // 跳转到移动帐号换号的界面
    'jumpToMobileChangePage': function() {
        bridge.callHandler('NeteaseMpayJSBridge.RelatedAccount.jumpToMobileChangePage');
    }};

    NeteaseMpayJSBridge.Common = {
    // 关闭窗口
    'closeWindow': function() {
        bridge.callHandler('NeteaseMpayJSBridge.Common.closeWindow');
    },
    // 登录游戏
    'onUserLogin': function(user) {
        bridge.callHandler('NeteaseMpayJSBridge.Common.onUserLogin', user);
    },
    // 修改导航栏标题；
    'changeNavigationTitle': function(title) {
        bridge.callHandler('NeteaseMpayJSBridge.Common.changeNavigationTitle', title);
    },

    // 二次验证
    'onVerify': function(res) {
        bridge.callHandler('NeteaseMpayJSBridge.Common.onVerify', res);
    },

    // 错误提示
    'toast': function(msg) {
        bridge.callHandler('NeteaseMpayJSBridge.Common.toast', msg);
    },

    'alert': function(msg) {
        bridge.callHandler('NeteaseMpayJSBridge.Common.alert', msg);
    },

    // 通过Safari打开url
    'setUrlPrefixForNativeBrowser': function(urlPrefixList) {
        bridge.callHandler('NeteaseMpayJSBridge.Common.setUrlPrefixForNativeBrowser', urlPrefixList);
    },
                                   
    // 使用原生的浏览器打开某个url
    'openLinkInNativeBrowser': function(url) {
        bridge.callHandler('NeteaseMpayJSBridge.Common.openLinkInNativeBrowser', url);
    },

    // 获取配置信息
    'getConfig': function(params) {
        bridge.callHandler('NeteaseMpayJSBridge.Common.getConfig', null, function(response) {
            params.success(response);
        });
    }};
    
    // 移动帐号安全中心的API
    NeteaseMpayJSBridge.MobileCenter = {
        'onUserLogin': function(user) {
            bridge.callHandler('NeteaseMpayJSBridge.MobileCenter.onUserLogin', user);
        }
    };

    // 发送事件
    var evt = document.createEvent("Events");
    evt.initEvent("NeteaseMpayJSBridgeReady", true, true);
    document.dispatchEvent(evt);
    });
}