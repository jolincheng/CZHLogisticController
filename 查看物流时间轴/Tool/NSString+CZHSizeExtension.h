//
//  NSString+CZHSizeExtension.h
//  查看物流时间轴
//
//  Created by 程召华 on 2018/3/9.
//  Copyright © 2018年 程召华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSString (CZHSizeExtension)

- (CGSize)czh_sizeWithFont:(UIFont *)font maxH:(CGFloat)maxH;
- (CGSize)czh_sizeWithFont:(UIFont *)font maxW:(CGFloat)maxW;
- (CGSize)czh_sizeWithFont:(UIFont *)font;

@end
