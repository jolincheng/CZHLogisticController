//
//  CZHLogisticCell.h
//  查看物流时间轴
//
//  Created by 程召华 on 2018/3/9.
//  Copyright © 2018年 程召华. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CZHLogisticFrameModel.h"

@interface CZHLogisticCell : UITableViewCell

+ (instancetype)czh_cellWithTableView:(UITableView *)tableView;
///<#注释#>
@property (nonatomic, strong) CZHLogisticFrameModel *frameModel;
@end
