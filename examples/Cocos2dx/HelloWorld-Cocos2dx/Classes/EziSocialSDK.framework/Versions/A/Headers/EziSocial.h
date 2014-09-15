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

+(void)logout;

+(void)dismissDashboard;

+(void) setGoogleClientID:(NSString*)clientID;
+(NSString*) getGoogleClientID;

+(void)fbShare:(NSString*)message onComplete:(void (^)(BOOL success))completionBlock;
+(void)tweet:(NSString*)message onComplete:(void (^)(BOOL success))completionBlock;

// Player
+(EziPlayer*)getActivePlayer;

+(NSString*) getFacebookID;
+(void) setFacebookID:(NSString*)clientID;


// Friends

+(void)getAllFriends;
+(void)getFriendsWithFilter:(NSString*)filterString;

// Network Test
+(void)connectionTest:(void (^)(BOOL success))completionBlock;

// Logging and Alerts
+(void)enableLogs:(BOOL)logs andAlerts:(BOOL)alerts;

+(void)updateProfile:(NSDictionary*)profileData;

@end
