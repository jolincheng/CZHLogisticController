//
//  NSMutableAttributedString+CZHExtention.h
//  查看物流时间轴
//
//  Created by 程召华 on 2018/3/9.
//  Copyright © 2018年 程召华. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableAttributedString (CZHExtention)

/*
 *  简单的修改一段文字的富文本
 *  dictionary:字典
 *  text:控件的文本
 *  rangString:需要设置的字符串
 */
+ (NSMutableAttributedString *)czh_setAttributesWithDictionry:(NSDictionary *)dictionary text:(NSString *)text rangString:(NSString *)rangString;

@end
