//
//  NSObject+Parse.m
//  查看物流时间轴
//
//  Created by 程召华 on 2018/3/9.
//  Copyright © 2018年 程召华. All rights reserved.
//

#import "NSObject+Parse.h"
#import "MJExtension.h"

@implementation NSObject (Parse)
+(id)czh_parse:(id)responseObj{
    if ([responseObj isKindOfClass:[NSArray class]]) {
        return [self mj_objectArrayWithKeyValuesArray:responseObj];
    }
    if ([responseObj isKindOfClass:[NSDictionary class]]) {
        return [self mj_objectWithKeyValues:responseObj];
    }
    return  responseObj;
}
@end
