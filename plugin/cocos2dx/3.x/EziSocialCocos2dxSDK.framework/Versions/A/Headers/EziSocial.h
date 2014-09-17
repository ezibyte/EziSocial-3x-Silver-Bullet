//
//  EziSocial.h
//  EziSocialTestProject
//
//  Created by Paras Mendiratta on 03/06/14.
//  Copyright (c) 2014 EziByte Technologies. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Social/Social.h>
#import <Accounts/Accounts.h>
#import "EziPlayer.h"


@interface EziSocial : NSObject

+(UIViewController*) getRootViewController;
+(void)setRootViewController:(UIViewController*)rootViewController;


/**
 @return The release Version String of the EziSocial client library in use.
 */
+(NSString*) version;

/**
 @param productKey This is your unique product key you received when registering your application.
 */
+(void)initWithProductKey:(NSString*)productKey;

/**
 Launches the EziSocial Dashboard view at the top of your application's keyed window.
 
 @note If Nextpeer::isNextpeerSupported returns NO this method will not execute.
 If the player has not yet authorized your app, they will be prompted to setup an
 account or authorize your application before accessing the Nextpeer dashboard.
 */
+(void)showDashboard:(void (^)(void))blockStartGame;

/** Logout the user */
+(void)logout;

/** Dismiss the dashboard */
+(void)dismissDashboard;

/** Show the dialog box to share the status on facebook with the given message. A block method can be set to receive the callback. */
+(void)fbShare:(NSString*)message onComplete:(void (^)(BOOL success))completionBlock;

/** Show the dialog box to tweet the given message. A block method can be set to receive the callback. */
+(void)tweet:(NSString*)message onComplete:(void (^)(BOOL success))completionBlock;

/** Handles the incoming application URL. Required for Google Plus integration */
+(BOOL)application: (UIApplication *)application
           openURL: (NSURL *)url
 sourceApplication: (NSString *)sourceApplication
        annotation: (id)annotation;

/** Return the Instance of Active EziPlayer */
+(EziPlayer*)getActivePlayer;

/** Tells the facebook ID set for current application or game */
+(NSString*) getFacebookID;

/** Sets the Facebook ID for current application. Also enables Facebook login for current application. */
+(void) setFacebookID:(NSString*)clientID;

/** Sets the Google Plus Client ID for the current application. Also enables Google Plus login for the current application. */
+(void) setGoogleClientID:(NSString*)clientID;

/** Tells the Google Plus client ID set for current application or game */
+(NSString*) getGoogleClientID;

/** Let user to test the network connection by pinging to EziSocial server */
+(void)connectionTest:(void (^)(BOOL success))completionBlock;

/** Enables Alers and Console log messages. By default logs are enabled and Alerts are disabled. */
+(void)enableLogs:(BOOL)logs andAlerts:(BOOL)alerts;

/** (Private Method) Sets the profile dictionary for the current active user */
+(void)updateProfile:(NSDictionary*)profileData;

@end
