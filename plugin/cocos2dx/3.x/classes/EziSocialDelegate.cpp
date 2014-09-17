//
//  EziSocialDelegate.cpp
//  HelloWorld-Cocos2dx
//
//  Created by Paras Mendiratta on 04/09/14.
//
//

#include "EziSocialDelegate.h"
#include "EziSocialDefinitations.h"


static EziSocialDelegate* _sharedInstance = NULL;


// Constructor
EziSocialDelegate::EziSocialDelegate()
{
}

// Destructor
EziSocialDelegate::~EziSocialDelegate()
{
    _sharedInstance = NULL;
}

/** Returns the shared instance of EziSocial Delegate. */
EziSocialDelegate* EziSocialDelegate::sharedInstance()
{
    if (_sharedInstance == NULL)
    {
        _sharedInstance = new EziSocialDelegate();
    }
    
    return _sharedInstance;
}

/** Initialize the instance of EziSocial and registers your player with EziSocial */
void EziSocialDelegate::initWithProductKey(const char* productKey)
{
    EziSocialWrapper::initWithProductKey(productKey);
}


/** Tells the current version of EziSocial Library */
const char* EziSocialDelegate::version()
{
    return EziSocialWrapper::getVersion();
}

/** Slide in the EziSocial Dashboard to allow user to login with any of the given Social Networks */
void EziSocialDelegate::showDashboard(const eziVoidCallback& callback)
{
    EziSocialWrapper::showDashboard(callback);
}

/** Slide out the EziSocial Dashboard from the screen */
void EziSocialDelegate::dismissDashboard()
{
    EziSocialWrapper::dismissDashboard();
}

/** Displays the Facebook Share dialog on the screen */
void EziSocialDelegate::fbShare(const char* message, const eziBoolCallback& callback)
{
    EziSocialWrapper::fbShare(message, callback);
}

/** Displays the Tweet Dialog on the screen */
void EziSocialDelegate::tweet(const char* message, const eziBoolCallback& callback)
{
    EziSocialWrapper::tweet(message, callback);
}

/** Set the Facebook application ID */
void EziSocialDelegate::setFacebookID(const char* clientID)
{
    EziSocialWrapper::setFacebookID(clientID);
}

/** Set the Google Plus Client ID */
void EziSocialDelegate::setGoogleClientID(const char* clientID)
{
    EziSocialWrapper::setGoogleClientID(clientID);
}

/** Enable/Disable logs and alerts */
void EziSocialDelegate::enableLogsAndAlerts(bool logs, bool alerts)
{
    EziSocialWrapper::enableLogsAndAlerts(logs, alerts);
}

/**
 Whether to enable Facebook social network for user sign in
 Default Value: YES
 */
void EziSocialDelegate::enableFacebook (bool toEnable)
{
    EziSocialWrapper::enableFacebook(toEnable);
}

/**
 Whether to enable Google Plus social network for user sign in
 Default Value: YES
 */
void EziSocialDelegate::enableGooglePlus (bool toEnable)
{
    EziSocialWrapper::enableGooglePlus(toEnable);
}


/**
 Whether to enable Twitter social network for user sign in
 Default Value: YES
 */
void EziSocialDelegate::enableTwitter (bool toEnable)
{
    EziSocialWrapper::enableTwitter(toEnable);
}
