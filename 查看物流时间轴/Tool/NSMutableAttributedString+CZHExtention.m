//
//  NSMutableAttributedString+CZHExtention.m
//  查看物流时间轴
//
//  Created by 程召华 on 2018/3/9.
//  Copyright © 2018年 程召华. All rights reserved.
//

#import "NSMutableAttributedString+CZHExtention.h"

@implementation NSMutableAttributedString (CZHExtention)

+ (NSMutableAttributedString *)czh_setAttributesWithDictionry:(NSDictionary *)dictionary text:(NSString *)text rangString:(NSString *)rangString{
    NSMutableAttributedString *rateLabelAttr = [[NSMutableAttributedString alloc] initWithString:text];
    if (rangString.length <= 0 || text.length <= 0) {
        return rateLabelAttr;
    }
    
    
    [rateLabelAttr setAttributes:dictionary range:[text rangeOfString:rangString]];
    //赋值
    return rateLabelAttr;
    
}

@end
