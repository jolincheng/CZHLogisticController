//
//  CZHLogisticCell.m
//  查看物流时间轴
//
//  Created by 程召华 on 2018/3/9.
//  Copyright © 2018年 程召华. All rights reserved.
//

#import "CZHLogisticCell.h"
#import "CZHGlobalHeader.h"
#import "NSMutableAttributedString+CZHExtention.h"
#import "YYText.h"

@interface CZHLogisticCell ()
///左边的远
@property (nonatomic, weak) UIView *leftRoundView;
///左边的线
@property (nonatomic, weak) UIView *leftLineView;
///内容
@property (nonatomic, weak) YYLabel *contentLabel;
///时间
@property (nonatomic, weak) UILabel *timeLabel;
///底部线
@property (nonatomic, weak) UIView *bottomLine;
@end

static NSString *const reuseId = @"CZHLogisticCell";
@implementation CZHLogisticCell

+ (instancetype)czh_cellWithTableView:(UITableView *)tableView {
    
    CZHLogisticCell *cell = [tableView dequeueReusableCellWithIdentifier:reuseId];
    
    if (!cell) {
        cell = [[CZHLogisticCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:reuseId];
    }
    
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    
    return cell;
    
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        
        [self czh_setUpCell];
        
    }
    return self;
}

- (void)czh_setUpCell {
    
    UIView *leftLineView = [[UIView alloc] init];
    leftLineView.backgroundColor = CZHColor(0xdfdfdf);
    [self.contentView addSubview:leftLineView];
    self.leftLineView = leftLineView;
    
    YYLabel *contentLabel = [[YYLabel alloc] init];
    contentLabel.font = CZHGlobelNormalFont(14);
    contentLabel.numberOfLines = 0;
    [self.contentView addSubview:contentLabel];
    self.contentLabel = contentLabel;
    
    UILabel *timeLabel = [[UILabel alloc] init];
    timeLabel.font = CZHGlobelNormalFont(11);
    [self.contentView addSubview:timeLabel];
    self.timeLabel = timeLabel;
    
    UIView *leftRoundView= [[UIView alloc] init];
    leftRoundView.backgroundColor = CZHColor(0xdfdfdf);
    [self.contentView addSubview:leftRoundView];
    self.leftRoundView = leftRoundView;
    
    
    UIView *bottomLine = [[UIView alloc] init];
    bottomLine.backgroundColor = CZHColor(0xdfdfdf);
    [self.contentView addSubview:bottomLine];
    self.bottomLine = bottomLine;
    
}

- (void)setFrameModel:(CZHLogisticFrameModel *)frameModel {
    _frameModel = frameModel;
    
    [self czh_setData];
    
}

- (void)czh_setData {
    

    self.timeLabel.text = _frameModel.timeString;
    

    self.contentLabel.textColor = _frameModel.contentColor;
    self.timeLabel.textColor = _frameModel.timeColor;
    self.leftRoundView.backgroundColor = _frameModel.leftRoundColor;
   
    self.contentLabel.attributedText = _frameModel.contentAttributedString;
    
}



- (void)layoutSubviews {
    [super layoutSubviews];
    
    self.leftRoundView.frame = _frameModel.leftRoundViewF;
    [self.leftRoundView czh_cornerAllCornersWithCornerRadius:self.leftRoundView.czh_height * 0.5];
    
    self.leftLineView.frame = _frameModel.leftLineViewF;
    
    self.contentLabel.frame = _frameModel.contentLabelF;
    
    self.timeLabel.frame = _frameModel.timeLabelF;
    
    self.bottomLine.frame = _frameModel.bottomLineF;
}

@end
