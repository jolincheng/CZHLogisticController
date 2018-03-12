//
//  CZHDialyChecjInHeader.h
//  每日签到
//
//  Created by 程召华 on 2018/3/7.
//  Copyright © 2018年 程召华. All rights reserved.
//

#ifndef CZHDialyChecjInHeader_h
#define CZHDialyChecjInHeader_h

#import "UIView+CZHExtension.h"
#import "MJRefresh.h"
#import "MJExtension.h"
#import "NSObject+Parse.h"
#import "CZHNormalHeader.h"


///weakSelf
#define CZHWeakSelf(type)  __weak typeof(type) weak##type = type;
#define CZHStrongSelf(type)  __strong typeof(type) type = weak##type;

/**屏幕宽度*/
#define ScreenWidth ([UIScreen mainScreen].bounds.size.width)
/**屏幕高度*/
#define ScreenHeight ([UIScreen mainScreen].bounds.size.height)

/**全局字体*/
#define CZHGlobelNormalFont(__VA_ARGS__) ([UIFont systemFontOfSize:CZH_ScaleFont(__VA_ARGS__)])

/**宽度比例*/
#define CZH_ScaleWidth(__VA_ARGS__)  ([UIScreen mainScreen].bounds.size.width/375)*(__VA_ARGS__)

/**高度比例*/
#define CZH_ScaleHeight(__VA_ARGS__)  ([UIScreen mainScreen].bounds.size.height/667)*(__VA_ARGS__)

/**字体比例*/
#define CZH_ScaleFont(__VA_ARGS__)  ([UIScreen mainScreen].bounds.size.width/375)*(__VA_ARGS__)

/**颜色*/
#define CZHColor(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define CZHRGBColor(rgbValue, a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:a]


/**yes:是iphoneX*/
#define CZHIsiPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
//状态栏高度
#define CZHStatusHeight [[UIApplication sharedApplication] statusBarFrame].size.height
/**导航栏高度*/
#define CZHNavigationBarHeight (CZHIsiPhoneX ? 88 : 64)

#define CZHTabbarHeight (CZHIsiPhoneX ? 83 : 49)
//
#define CZHSafeAreaBottomHeight (CZHIsiPhoneX ? 34 : 0)

#endif /* CZHDialyChecjInHeader_h */
