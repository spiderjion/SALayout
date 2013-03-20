//
//  TestView.m
//  LayoutTest
//
//  Created by sagles on 13-3-7.
//  Copyright (c) 2013年 sagles. All rights reserved.
//

#import "TestView.h"

@implementation TestView

@synthesize portraitFrame = _portraitFrame,landscapeFrame = _landscapeFrame;
@synthesize subViewFrameDictionary = _subViewFrameDictionary;
@synthesize viewInterfaceOrientation = _viewInterfaceOrientation;

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
        self.subViewFrameDictionary = [NSMutableDictionary dictionary];
        self.viewInterfaceOrientation = PDViewInterfaceOrientationDefault;
    }
    return self;
}

- (void)awakeFromNib
{
    self.subViewFrameDictionary = [NSMutableDictionary dictionary];
    self.viewInterfaceOrientation = PDViewInterfaceOrientationDefault;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    
    layoutSubViews(self);
    
    NSLog(@"%@",self.subviews.lastObject);
}

- (void)setViewsWithInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    self.viewInterfaceOrientation = (PDViewInterfaceOrientation)interfaceOrientation;
    
    [self setNeedsLayout];
}

- (void)setSubViews
{
    PDViewFrameModel *model = [[[PDViewFrameModel alloc] init] autorelease];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [button setTitle:@"button" forState:0];
    //280 360
    //竖屏
    CGRect frame = CGRectMake(90, 165, 100, 30);
    button.frame = frame;
    model.portraitFrame = frame;
    //440 192
    //横屏
    frame = CGRectMake(170, 76, 100, 40);
    model.landscapeFrame = frame;
    
    [self addSubview:button];
    
    [self.subViewFrameDictionary setObject:model forKey:button.description];
}

@end

//must implementation this class
@implementation PDViewFrameModel

@end
