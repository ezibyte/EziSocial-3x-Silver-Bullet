//
//  EziPlayer.h
//  EziSocialTestProject
//
//  Created by Paras Mendiratta on 13/06/14.
//  Copyright (c) 2014 EziByte Technologies. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EziPrivateDefs.h"


@interface EziPlayer : NSObject



/** name of the player */
@property (nonatomic, strong) NSString* name;

/** Email ID of the player if available. In case of twitter it is combination of user_id and user_screen_name */
@property (nonatomic, strong) NSString* email;

/** Profile picture URL of the player. */
@property (nonatomic, strong) NSString* profileImageURL;

/** Player key stored in dictionary and over network */
@property (nonatomic, strong) NSString* key;

/** Social Unique ID of the Player */
@property (nonatomic, strong) NSString* uid;

/** Tells whether profile is synced with network */
@property (nonatomic)         BOOL      sync;

/** Tells whether profile is synced with network */
@property (nonatomic)         BOOL      socialActive;


/** Social Network used by Player */
@property (nonatomic) kPlayerSocialType social;

/** Player's current login time in milliseconds */
@property (nonatomic) long loginAt;

/** Duration of the last session */
@property (nonatomic) long lastSessionDuration;


-(EziPlayer*) init;
-(EziPlayer*) initWithKey:(NSString*)playerKey;

- (void)encodeWithCoder:(NSCoder *)encoder;
- (id)initWithCoder:(NSCoder *)decoder;
- (NSString*) getSocialType;
- (void) setSocialType:(NSString*)type;
- (BOOL) isSocial;

@end
