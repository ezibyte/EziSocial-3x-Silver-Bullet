//
//  EziSocialDefinitations.h
//  HelloWorld-Cocos2dx
//
//  Created by Paras Mendiratta on 04/09/14.
//
//

#ifndef HelloWorld_Cocos2dx_EziSocialDefinitations_h
#define HelloWorld_Cocos2dx_EziSocialDefinitations_h

#define EZI_CALLBACK_1(__selector__,__target__, ...) std::bind(&__selector__,__target__, std::placeholders::_1, ##__VA_ARGS__)


#include <functional>
#include <iostream>


typedef std::function<void(bool)> eziBoolCallback;
typedef std::function<void(void)> eziVoidCallback;


namespace EziSocialWrapper
{
    
    
    /** Initialize the instance of EziSocial and registers your player with EziSocial */
    void initWithProductKey(const char* productKey);
    
    /** Tells the current version of EziSocial Library */
    const char* getVersion();
    
    /** Slide in the EziSocial Dashboard to allow user to login with any of the given Social Networks */
    void showDashboard(const eziVoidCallback& callback);
    
    /** Slide out the EziSocial Dashboard from the screen */
    void dismissDashboard();
    
    /** Displays the Facebook Share dialog on the screen */
    void fbShare(const char* message, const eziBoolCallback& callback);
    
    /** Displays the Tweet Dialog on the screen */
    void tweet(const char* message, const eziBoolCallback& callback);
    
}



#endif
