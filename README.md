# CZHLogisticController
ios 物流时间轴,自动匹配电话号码,可点击拨打

![QQ20180312-100810.gif](https://upload-images.jianshu.io/upload_images/6709174-31fdf011524f0d09.gif?imageMogr2/auto-orient/strip)


![1.png](https://upload-images.jianshu.io/upload_images/6709174-57e1e6d0e2987823.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

本demo使用MJRefresh来做上拉刷新，MJExtension来做模型解析，YYit做富文本点击事件，话不多说上代码

```
///控制器内数组添加模型

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
    

```

```
frameModel实现，计算各个空间的frame以及各控件赋值判断
- (void)setModel:(CZHLogisticModel *)model {
    _model = model;
    
    _contentString = model.content;
    _timeString = model.time;
    
    ///判断颜色
    if (model.indexCount == 0) {
        _contentColor = CZHColor(0xff0000);
        _timeColor = CZHColor(0xff0000);
        _leftRoundColor = CZHColor(0xff0000);
    } else {
        _contentColor = CZHColor(0x999999);
        _timeColor = CZHColor(0x999999);
        _leftRoundColor = CZHColor(0xdfdfdf);
    }
    

    _contentAttributedString = [[NSMutableAttributedString alloc] initWithString:_contentString];
    
    _contentAttributedString.yy_font = CZHGlobelNormalFont(14);
    
    _contentAttributedString.yy_color = _contentColor;
    
    _contentAttributedString.yy_lineSpacing = 10;
    
    
    
    ///匹配电话号码
    NSString *string = _contentString;
    NSError *error = nil;
    NSDataDetector * detector = [NSDataDetector dataDetectorWithTypes:NSTextCheckingTypePhoneNumber error:&error];
    
    
    __block NSUInteger count = 0;
    __block NSString *phoneNumber;
    [detector enumerateMatchesInString:string options:0 range:NSMakeRange(0, [string length]) usingBlock:^(NSTextCheckingResult * _Nullable match, NSMatchingFlags flags, BOOL * _Nonnull stop) {

        if (count == 0) *stop = YES;
        
        if ([match resultType] == NSTextCheckingTypePhoneNumber) {
            phoneNumber = [match phoneNumber];
//            NSLog(@"phoneNumber:%@", phoneNumber);
        }
    }];
    
    if (phoneNumber.length > 0) {
        [_contentAttributedString yy_setTextHighlightRange:[_contentString rangeOfString:phoneNumber]
                                                     color:[UIColor blueColor]
                                           backgroundColor:nil
                                                 tapAction:^(UIView *containerView, NSAttributedString *text, NSRange range, CGRect rect){
                                                     
                                                     NSLog(@"----拨打电话--%@", phoneNumber);
                                                     
                                                     NSMutableString *str=[[NSMutableString alloc]initWithFormat:@"tel:%@",phoneNumber];
                                                     
                                                     [[UIApplication sharedApplication] openURL:[NSURL URLWithString:str]];
                                                     
                                                 }];
    }

    ///计算控件frame
    
    CGSize maxSize = CGSizeMake(ScreenWidth - CZH_ScaleWidth(60), MAXFLOAT);
    CGSize contentLabelSize = [YYTextLayout layoutWithContainerSize:maxSize text:_contentAttributedString].textBoundingSize;
    

    CGFloat contentLabelX = MARGIN_LEFT;
    CGFloat contentLabelY = CZH_ScaleWidth(15);
    CGFloat contentLabelW = contentLabelSize.width;
    CGFloat contentLabelH = contentLabelSize.height;
    _contentLabelF = CGRectMake(contentLabelX, contentLabelY, contentLabelW, contentLabelH);
    
    

    CGSize timeLabelSize = [_timeString czh_sizeWithFont:CZHGlobelNormalFont(11) maxW:MAX_WIDTH];
    CGFloat timeLabelX = MARGIN_LEFT;
    CGFloat timeLabelY = CGRectGetMaxY(_contentLabelF) + CZH_ScaleWidth(10);
    CGFloat timeLabelW = timeLabelSize.width;
    CGFloat timeLabelH = timeLabelSize.height;
    _timeLabelF = CGRectMake(timeLabelX, timeLabelY, timeLabelW, timeLabelH);
    
    
    
    CGFloat leftRoundViewX = 0;
    CGFloat leftRoundViewY = 0;
    CGFloat leftRoundViewW = 0;
    CGFloat leftRoundViewH = 0;
    
    if (model.indexCount == 0) {
        
        leftRoundViewY = CZH_ScaleWidth(15);
        leftRoundViewW = CZH_ScaleWidth(15);
        leftRoundViewH = CZH_ScaleWidth(15);
        
    } else {
        leftRoundViewY = CZH_ScaleWidth(19);
        leftRoundViewW = CZH_ScaleWidth(7);
        leftRoundViewH = CZH_ScaleWidth(7);
        
    }
    leftRoundViewX = (MARGIN_LEFT - leftRoundViewW) * 0.5;
    
    _leftRoundViewF = CGRectMake(leftRoundViewX, leftRoundViewY, leftRoundViewW, leftRoundViewH);
    
    
    _cellHeight = CGRectGetMaxY(_timeLabelF) + CZH_ScaleWidth(15);
    
    
    if (model.indexCount == model.totalCount - 1) {
        _bottomLineF = CGRectZero;
    } else {
        CGFloat bottomLineX = MARGIN_LEFT;
        CGFloat bottomLineY = _cellHeight - 0.5;
        CGFloat bottomLineW = ScreenWidth - bottomLineX;
        CGFloat bottomLineH = 0.5;
        _bottomLineF = CGRectMake(bottomLineX, bottomLineY, bottomLineW, bottomLineH);
    }
    
    
    CGFloat leftLineViewW = 1;
    CGFloat leftLineViewX = (MARGIN_LEFT - leftLineViewW) * 0.5;
    CGFloat leftLineViewY = 0;
    CGFloat leftLineViewH = 0;
    
    if (model.indexCount == 0) {//第一个
        leftLineViewY = CGRectGetMaxY(_leftRoundViewF);
        leftLineViewH = _cellHeight - leftLineViewY;
    } else if (model.indexCount == model.totalCount - 1) {//最后一个
        leftLineViewY = 0;
        leftLineViewH = CGRectGetMinY(_leftRoundViewF);
    } else {
        leftLineViewY = 0;
        leftLineViewH = _cellHeight;
    }
    _leftLineViewF = CGRectMake(leftLineViewX, leftLineViewY, leftLineViewW, leftLineViewH);
}
```

```
cell赋值
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

```

[简书地址](https://www.jianshu.com/u/2add458bf239)
[博客地址](http://blog.csdn.net/HurryUpCheng)
