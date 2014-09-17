//
//  EziSocialDelegate.h
//  HelloWorld-Cocos2dx
//
//  Created by Paras Mendiratta on 04/09/14.
//
//

#ifndef __HelloWorld_Cocos2dx__EziSocialDelegate__
#define __HelloWorld_Cocos2dx__EziSocialDelegate__

#include <iostream>
#include "EziSocialDefinitations.h"


class EziSocialDelegate
{
    private:
    
    // Constructor
    EziSocialDelegate();
    
    
    public:
    
    // Destructor
    ~EziSocialDelegate();
    
    /** Returns the shared instance of EziSocial Delegate. */
    static EziSocialDelegate* sharedInstance();
    
    /** Initialize the instance of EziSocial and registers your player with EziSocial */
    void initWithProductKey(const char* productKey);
    
    /** Tells the current version of EziSocial Library */
    const char* version();
    
    /** Slide in the EziSocial Dashboard to allow user to login with any of the given Social Networks */
    void showDashboard(const eziVoidCallback& callback);
    
    /** Slide out the EziSocial Dashboard from the screen */
    void dismissDashboard();
    
    /** Displays the Facebook Share dialog on the screen */
    void fbShare(const char* message, const eziBoolCallback& callback);
    
    /** Displays the Tweet Dialog on the screen */
    void tweet(const char* message, const eziBoolCallback& callback);
    
    
    /** Set the Facebook application ID */
    void setFacebookID(const char* clientID);
    
    /** Set the Google Plus Client ID */
    void setGoogleClientID(const char* clientID);
    
    /** Enable/Disable logs and alerts */
    void enableLogsAndAlerts(bool logs, bool alerts);
    
    /**
     Whether to enable Facebook social network for user sign in
     Default Value: YES
     */
    void enableFacebook (bool toEnable);
    
    
    /**
     Whether to enable Google Plus social network for user sign in
     Default Value: YES
     */
    void enableGooglePlus (bool toEnable);
    
    
    /**
     Whether to enable Twitter social network for user sign in
     Default Value: YES
     */
    void enableTwitter (bool toEnable);
    
    
};


#endif /* defined(__HelloWorld_Cocos2dx__EziSocialDelegate__) */
