//
//  EziDefs.h
//  EziSocialTestProject
//
//  Created by Paras Mendiratta on 07/08/14.
//  Copyright (c) 2014 EziByte Technologies. All rights reserved.
//

#ifndef EziSocialTestProject_EziDefs_h
#define EziSocialTestProject_EziDefs_h

typedef enum playerSocialTypes
{
    SOCIAL_FACEBOOK,
    SOCIAL_GOOGLE_PLUS,
    SOCIAL_TWITTER,
    SOCIAL_NONE
    
} kPlayerSocialType;


#define kSocialFacebook     @"facebook"
#define kSocialGooglePlus   @"gplus"
#define kSocialTwitter      @"twitter"
#define kSocialNone         @"others"

#define kSocialTypeArray kSocialFacebook, kSocialGooglePlus, kSocialTwitter, kSocialNone, nil


#endif
