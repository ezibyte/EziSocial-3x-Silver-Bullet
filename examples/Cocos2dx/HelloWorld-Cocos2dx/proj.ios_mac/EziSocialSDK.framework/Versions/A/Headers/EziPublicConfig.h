//
//  EziConfig.h
//  EziSocialTestProject
//
//  Created by Paras Mendiratta on 07/08/14.
//  Copyright (c) 2014 EziByte Technologies. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "EziPlayer.h"


@interface EziPublicConfig : NSObject

/**
 Whether to enable the alerts for normal logging events
 Default Value: NO
 */
+(BOOL) isDisplayAlerts;

/**
 Whether to enable the EziSocial logs for normal logging events
 Default Value: YES
 */
+(BOOL) isDisplayLogs;

/**
 Whether to auto login to social network (if user already logged in once anytime in the past)
 Default Value: YES
 */
+(BOOL) isAutoLogin;

/**
 Whether to enable Facebook social network for user sign in
 Default Value: YES
 */
+(BOOL) isFacebook;


/**
 Whether to enable Google Plus social network for user sign in
 Default Value: YES
 */
+(BOOL) isGooglePlus;


/**
 Whether to enable Twitter social network for user sign in
 Default Value: YES
 */
+(BOOL) isTwitter;


/**
 Whether to enable the alerts for normal logging events
 Default Value: NO
 */
+(void) enableAlerts:(BOOL)toEnable;

/**
 Whether to enable the EziSocial logs for normal logging events
 Default Value: YES
 */
+(void) enableLogs:(BOOL)toEnable;

/**
 Whether to auto login to social network (if user already logged in once anytime in the past)
 Default Value: YES
 */
+(void) enableAutoLogin:(BOOL)toEnable;

/**
 Whether to enable Facebook social network for user sign in
 Default Value: YES
 */
+(void) enableFacebook:(BOOL)toEnable;


/**
 Whether to enable Google Plus social network for user sign in
 Default Value: YES
 */
+(void) enableGooglePlus:(BOOL)toEnable;


/**
 Whether to enable Twitter social network for user sign in
 Default Value: YES
 */
+(void) enableTwitter:(BOOL)toEnable;


@end
