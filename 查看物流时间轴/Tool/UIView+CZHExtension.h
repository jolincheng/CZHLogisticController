//
//  UIView+CZHExtension.h
//  CZHDatePickerView
//
//  Created by 程召华 on 2017/11/20.
//  Copyright © 2017年 程召华. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (CZHExtension)
@property (nonatomic, assign) CGFloat czh_top;
@property (nonatomic, assign) CGFloat czh_bottom;
@property (nonatomic, assign) CGFloat czh_left;
@property (nonatomic, assign) CGFloat czh_right;
@property (nonatomic, assign) CGFloat czh_x;
@property (nonatomic, assign) CGFloat czh_y;
@property (nonatomic, assign) CGFloat czh_centerX;
@property (nonatomic, assign) CGFloat czh_centerY;
@property (nonatomic, assign) CGFloat czh_width;
@property (nonatomic, assign) CGFloat czh_height;
@property (nonatomic, assign) CGSize czh_size;
@property (nonatomic, assign) CGPoint czh_origin;

- (instancetype)czh_cornerAllCornersWithCornerRadius:(CGFloat)cornerRadius;
@end
