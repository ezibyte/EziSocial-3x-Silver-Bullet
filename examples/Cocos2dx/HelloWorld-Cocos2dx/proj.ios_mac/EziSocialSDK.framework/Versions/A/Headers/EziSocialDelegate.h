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
    
    
    
};


#endif /* defined(__HelloWorld_Cocos2dx__EziSocialDelegate__) */
