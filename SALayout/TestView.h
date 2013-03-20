//
//  TestView.h
//  LayoutTest
//
//  Created by sagles on 13-3-7.
//  Copyright (c) 2013年 sagles. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SAViewRotationProtocol.h"

@interface TestView : UIView <SAViewRotationProtocol>

/*!
 @brief     <#abstract#>
 */
@property (nonatomic, retain) UIButton *button;

- (void)setSubViews;

@end
