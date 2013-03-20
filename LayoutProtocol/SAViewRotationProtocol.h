//
//  PDViewRotationProtocol.h
//  PAD.Views
//
//  Created by sagles on 13-3-7.
//  Copyright (c) 2013年 Paidui, Inc. All rights reserved.
//

typedef enum
{
    PDViewInterfaceOrientationDefault = 998,
    PDViewInterfaceOrientationPortrait = UIInterfaceOrientationPortrait,
    PDViewInterfaceOrientationPortraitUpsideDown = UIInterfaceOrientationPortraitUpsideDown,
    PDViewInterfaceOrientationLandscapeLeft = UIInterfaceOrientationLandscapeLeft,
    PDViewInterfaceOrientationLandscapeRight = UIInterfaceOrientationLandscapeRight
}PDViewInterfaceOrientation;

#import <Foundation/Foundation.h>


@protocol SAViewRotationProtocol <NSObject>

/*!
 @brief     view在竖屏时候的frame
 */
@property (nonatomic, assign) CGRect portraitFrame;

/*!
 @brief     view在横屏时候的frame
 */
@property (nonatomic, assign) CGRect landscapeFrame;

/*!
 @brief     自定义的屏幕方向类型
 */
@property (assign) PDViewInterfaceOrientation viewInterfaceOrientation;

/*!
 @brief     存储子View的frame的字典。frame以NSString的方式存储，该frame是当前屏幕方向显示以外的另外一个frame
 （横屏时候存储竖屏frame，反之亦然），key是该子控件本身，需要设置初始值。
 */
@property (nonatomic, retain) NSMutableDictionary *subViewFrameDictionary;

@required
/*!
 @brief     根据设备屏幕方向来调整UI显示
 @param     interfaceOrientation 屏幕方向
 @return    void
 */
- (void)setViewsWithInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;

//实现视图的frame转换
static void layoutSubViews(UIView<SAViewRotationProtocol> *view);

@end

/*!
 @brief 用于存储view的横竖屏frame的model.
 */
@interface PDViewFrameModel : NSObject

/*!
 @brief     view在竖屏时候的frame
 */
@property (nonatomic, assign) CGRect portraitFrame;

/*!
 @brief     view在横屏时候的frame
 */
@property (nonatomic, assign) CGRect landscapeFrame;

@end

void layoutSubViews(UIView<SAViewRotationProtocol> *view)
{
    switch (view.viewInterfaceOrientation)
    {
        case PDViewInterfaceOrientationPortrait:
        case PDViewInterfaceOrientationPortraitUpsideDown:
        {
            view.frame = view.portraitFrame;
            [view.subviews enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
                if ([obj isKindOfClass:[UIView class]])
                {
                    UIView *subView = (UIView *)obj;
                    PDViewFrameModel *model = [[view.subViewFrameDictionary objectForKey:subView.description] retain];
                    if (model)
                    {
                        [view.subViewFrameDictionary removeObjectForKey:subView.description];
                        subView.frame = model.portraitFrame;
                        [view.subViewFrameDictionary setObject:model forKey:subView.description];
                        [model release];
                    }
                }
            }];
        }
            break;
        case PDViewInterfaceOrientationLandscapeLeft:
        case PDViewInterfaceOrientationLandscapeRight:
        {
            view.frame = view.landscapeFrame;
            [view.subviews enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
                if ([obj isKindOfClass:[UIView class]])
                {
                    UIView *subView = (UIView *)obj;
                    PDViewFrameModel *model = [[view.subViewFrameDictionary objectForKey:subView.description] retain];
                    if (model)
                    {
                        [view.subViewFrameDictionary removeObjectForKey:subView.description];
                        subView.frame = model.landscapeFrame;
                        [view.subViewFrameDictionary setObject:model forKey:subView.description];
                        [model release];
                    }
                }
            }];
        }
            break;
        default:
            break;
    }
    view.viewInterfaceOrientation = PDViewInterfaceOrientationDefault;
}
