//
//  CZHLogisticFrameModel.h
//  查看物流时间轴
//
//  Created by 程召华 on 2018/3/9.
//  Copyright © 2018年 程召华. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "CZHLogisticModel.h"


@interface CZHLogisticFrameModel : NSObject

///左边的远
@property (nonatomic, assign, readonly) CGRect leftRoundViewF;
///左边的线
@property (nonatomic, assign, readonly) CGRect leftLineViewF;
///内容
@property (nonatomic, assign, readonly) CGRect contentLabelF;
///时间
@property (nonatomic, assign, readonly) CGRect timeLabelF;
///底部线
@property (nonatomic, assign, readonly) CGRect bottomLineF;


///物流文本
@property (nonatomic, copy, readonly) NSString *contentString;
///时间文本
@property (nonatomic, copy, readonly) NSString *timeString;
///内容富文本
@property (nonatomic, strong, readonly) NSMutableAttributedString *contentAttributedString;
///物流文本颜色
@property (nonatomic, strong, readonly) UIColor *contentColor;
///时间文本颜色
@property (nonatomic, strong, readonly) UIColor *timeColor;
///左边圆圈颜色
@property (nonatomic, strong, readonly) UIColor *leftRoundColor;

///cell高度
@property (nonatomic, assign, readonly) CGFloat cellHeight;



///模型
@property (nonatomic, strong) CZHLogisticModel *model;
@end
