//
//  JKAlertManager.h
//  AlertAssemble
//
//  Created by 四威 on 2016/8/1.
//  Copyright © 2016年 JeanKyle. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JKInformView.h"
#import "JKWaitingView.h"
#import "JKAdapterLabel.h"
#import "NSObject+JKAlert.h"

typedef void (^jk_block_fl)(CGFloat num);

//快速引用单例
#define JK_M [JKAlertManager manager]
//默认持续时间
#define DURATION_DEFAULT 3.0

//弹窗管理器
@interface JKAlertManager : NSObject

//可交互视图
@property (nonatomic, strong) UIView *maskView;
//标识视图
@property (nonatomic, strong) JKInformView *informView;
//容器视图
@property (nonatomic, strong) UIView *containView;
//文本视图
@property (nonatomic, strong) JKAdapterLabel *textLabel;
//等待视图
@property (nonatomic, strong) JKWaitingView *waitView;
//主窗口是否存在弹窗
@property (nonatomic, assign) BOOL isAlerted;
//主窗口
@property (nonatomic, strong) UIWindow *mainWindow;
//持续时间
@property (nonatomic, assign) NSTimeInterval duration;

//快速创建
+ (instancetype)manager;
//主窗口移除所有弹窗
- (void)cleanAllAlertViews;
//隐藏所有弹窗
- (void)hideAllAlertViews;
//添加弹性
- (void)elastAllAlertViews;

- (void)dismissNormal;

- (void)dismissDuration:(NSTimeInterval)duration;

- (void)coverEnable:(BOOL)enable;

- (void)containSide:(CGFloat)side block:(jk_block_fl)block;

- (void)containSize:(CGSize)size block:(jk_block_fl)block;

- (void)cleanOldAlertViews:(jk_block_t)block;

@end

