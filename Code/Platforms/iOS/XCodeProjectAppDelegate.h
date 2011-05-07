//
//  BadBalls2AppDelegate.h
//  BadBalls2
//
//  Created by Artur Mazurek on 11-03-17.
//  Copyright 2011 none. All rights reserved.
//

#import <UIKit/UIKit.h>

@class XCodeProjectViewController;

@interface XCodeProjectAppDelegate : NSObject <UIApplicationDelegate> {

}

@property (nonatomic, retain) IBOutlet UIWindow *window;

@property (nonatomic, retain) IBOutlet XCodeProjectViewController *viewController;

@end
