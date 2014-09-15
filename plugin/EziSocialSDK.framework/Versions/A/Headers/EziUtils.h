//
//  EziUtils.h
//  EziSocialTestProject
//
//  Created by Paras Mendiratta on 07/08/14.
//  Copyright (c) 2014 EziByte Technologies. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EziPrivateDefs.h"
#import <UIKit/UIKit.h>

@interface EziUtils : NSObject

/** Logging and Alerts */
+(void) enableLogs:(BOOL)logs andAlerts:(BOOL)alerts;

/** display an alert box with title and message. It automatically uses main queue to display the alert message. */
+(void) displayAlertWithTitle:(NSString*)title andMessage:(NSString*)message;

/** Log an information on the console. Alerts are also displayed if enabled. */
+(void) logInfo:(NSString*)message;

/** Log an error on the console. Alerts are also displayed if enabled. */
+(void) logError:(NSString*)message;

/** Returns current time in milliseconds. Useful for TIMESTAMP. */
+(double) currentTimeInMills;

/** Returns current time (milliseconds) in NSNumber format. */
+(NSNumber*) currentTimeAsObject;

/** Generates a random alpha numeric string of given length. */
+(NSString*) generateRandomString:(int)length;

/** Downloads an image from the given URL */
+ (void)downloadImageWithURL:(NSURL *)url completionBlock:(void (^)(BOOL succeeded, UIImage *image))completionBlock;

+(NSString*) socialTypeEnumToString:(kPlayerSocialType)enumVal;

+ (void)showWithAnim:(UIView*)element duration:(float)duration;
+ (void)hideWithAnim:(UIView*)element duration:(float)duration;
+ (void)moveByWithAnim:(UIView*)element duration:(float)duration position:(CGPoint)position;
+ (void)moveToWithAnim:(UIView*)element duration:(float)duration position:(CGPoint)position;

+ (void)pushViewToRootViewController:(UIViewController*)viewController;
+ (void)addSubViewToRootViewController:(UIView*)view;

/** Tells whether user is using iPad device */
+ (BOOL) isIPad;

/** Tells whether device current orientation is in Portrait Mode */
+ (BOOL) isInPortrait;

/** Tells whether device current orientation is in Landscape Mode */
+ (BOOL) isInLandscape;

@end
