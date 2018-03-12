//
//  CZHNormalHeader.m
//  查看物流时间轴
//
//  Created by 程召华 on 2018/3/9.
//  Copyright © 2018年 程召华. All rights reserved.
//

#import "CZHNormalHeader.h"

@implementation CZHNormalHeader

- (void)prepare
{
    [super prepare];
    
    //    self.stateLabel.text = YES;
    
    self.lastUpdatedTimeLabel.hidden = YES;
    
    if (self.state == MJRefreshStateWillRefresh) {
        self.stateLabel.hidden = YES;
    }
    
}

@end
