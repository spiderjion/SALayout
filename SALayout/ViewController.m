//
//  ViewController.m
//  SALayout
//
//  Created by sagles on 13-3-20.
//  Copyright (c) 2013年 sagles. All rights reserved.
//

#import "ViewController.h"
#import "TestView.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)dealloc {
    [_testView release];
    [super dealloc];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.title = @"LayoutTest";
    
    //设置横竖屏的frame(非必要)
//    _testView.portraitFrame = _testView.frame;
//    _testView.landscapeFrame = CGRectMake(20, 38, 440, 192);
    
    [_testView setSubViews];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
    return YES;
}

- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
                                         duration:(NSTimeInterval)duration
{
    NSLog(@"will");
    [self.testView setViewsWithInterfaceOrientation:toInterfaceOrientation];
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
    NSLog(@"did");
}

@end
