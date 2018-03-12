//
//  CZHLogisticController.m
//  物流时间轴
//
//  Created by 程召华 on 2018/3/9.
//  Copyright © 2018年 程召华. All rights reserved.
//

#import "CZHLogisticController.h"
#import "CZHGlobalHeader.h"
#import "CZHLogisticCell.h"

@interface CZHLogisticController ()<UITableViewDataSource, UITableViewDelegate>
///
@property (nonatomic, weak) UITableView *tableView;
///<#注释#>
@property (nonatomic, strong) NSMutableArray *logisticArray;
@end

@implementation CZHLogisticController


- (NSMutableArray *)logisticArray {
    if (!_logisticArray) {
        _logisticArray = [NSMutableArray array];
    }
    return _logisticArray;
}


- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = CZHColor(0xdfdfdf);
    self.navigationItem.title = @"查看物流";
    

    [self czh_setUpView];
    
    [self czh_getData];
    
    [self czh_setUpRefresh];
    
}

- (void)czh_setUpRefresh {
    

    CZHWeakSelf(self);
    self.tableView.mj_header = [CZHNormalHeader headerWithRefreshingBlock:^{
        CZHStrongSelf(self);
        [self czh_getData];
    }];
    
}

- (void)czh_getData {
    
    
    NSDictionary *first = @{@"time":@"2018-03-07 14:03:53", @"content":@"[黄石市]快件已在黄石签收 签收人：XXXX,感谢您使用XX快递，期待再次为您服务!哈哈哈哈哈[15912345678]"};
    NSDictionary *second = @{@"time":@"2018-03-07 10:00:00", @"content":@"[黄石市]派件员XXX[0714-5381795]正在派件傻哈哈傻哈哈"};
    NSDictionary *third = @{@"time":@"2018-03-07 8:00:00", @"content":@"[黄石市]快件已到达黄石"};
    NSDictionary *fourth = @{@"time":@"2018-03-06 8:00:00", @"content":@"[武汉市]快件离开武汉中转部已发往黄石"};
    NSDictionary *fifth = @{@"time":@"2018-03-06 5:00:00", @"content":@"[武汉市]快件已到达武汉中转部"};
    NSDictionary *sixth = @{@"time":@"2018-03-06 1:00:00", @"content":@"[深圳市]快件已离开深圳发往武汉中转部"};
    NSDictionary *seventh = @{@"time":@"2018-03-05 19:00:00", @"content":@"[深圳市]XXX已收件[13986600772]"};
    NSDictionary *eighth = @{@"time":@"2018-03-05 17:00:00", @"content":@"您的订单由第三方卖家拣货完毕，正通知快递公司揽件中"};
    NSDictionary *ninth = @{@"time":@"2018-03-05 13:00:00", @"content":@"您提交了订单，请等待第三方卖家系统确认[15988888888]"};
    
    NSArray *array = @[first, second, third, fourth, fifth, sixth, seventh, eighth, ninth];
    
    NSInteger totalCount = array.count;
    
    //清空数组
    [self.logisticArray removeAllObjects];
    
    for (NSInteger i = 0; i < totalCount; i++) {
        
        CZHLogisticFrameModel *frameModel = [[CZHLogisticFrameModel alloc] init];
        
        CZHLogisticModel *model = [CZHLogisticModel czh_parse:array[i]];
        
        model.indexCount = i;
        
        model.totalCount = totalCount;
        
        frameModel.model = model;
        
        [self.logisticArray addObject:frameModel];
        
    }
    
    [self.tableView reloadData];
    
    [self.tableView.mj_header endRefreshing];
}

- (void)czh_setUpView {
    
    UITableView *tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, ScreenWidth, ScreenHeight) style:UITableViewStylePlain];
    tableView.dataSource = self;
    tableView.delegate = self;
    tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    tableView.backgroundColor = CZHColor(0xdfdfdf);
    tableView.rowHeight = CZH_ScaleWidth(30);
    [self.view addSubview:tableView];
    self.tableView = tableView;
    
    
    UILabel *tips = [[UILabel alloc] init];
    tips.text = @"温馨提示:15天内未确认收货,系统将默认收货。";
    tips.textColor = CZHColor(0xff9c00);
    tips.font = CZHGlobelNormalFont(11);
    tips.textAlignment = NSTextAlignmentCenter;
    
    CGFloat tipsX = 0;
    CGFloat tipsY = 0;
    CGFloat tipsW = ScreenWidth ;
    CGFloat tipsH = CZH_ScaleWidth(30);
    tips.frame = CGRectMake(tipsX, tipsY, tipsW, tipsH);
    

    tableView.tableFooterView = tips;
    
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.logisticArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    CZHLogisticCell *cell = [CZHLogisticCell czh_cellWithTableView:tableView];
    
    cell.frameModel = self.logisticArray[indexPath.row];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    CZHLogisticFrameModel *frameModel = self.logisticArray[indexPath.row];
    
    return frameModel.cellHeight;
    
}



@end
