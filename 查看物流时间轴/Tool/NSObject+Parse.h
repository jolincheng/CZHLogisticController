//
//  NSObject+Parse.h
//  查看物流时间轴
//
//  Created by 程召华 on 2018/3/9.
//  Copyright © 2018年 程召华. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (Parse)
/** 对MJExtension的封装，自动判断参数类型。来解析 */
+(id)czh_parse:(id)responseObj;
@end
