//
//  CZHLogisticModel.h
//  查看物流时间轴
//
//  Created by 程召华 on 2018/3/9.
//  Copyright © 2018年 程召华. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CZHLogisticModel : NSObject

///时间
@property (nonatomic, copy) NSString *time;
///物流
@property (nonatomic, copy) NSString *content;
///模型下标
@property (nonatomic, assign) NSInteger indexCount;
///模型总数量
@property (nonatomic, assign) NSInteger totalCount;
@end
