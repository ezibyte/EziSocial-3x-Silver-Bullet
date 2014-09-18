#include "AppDelegate.h"
#include "HelloWorldScene.h"

#include "EziSocialDelegate.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);
    
    EziSocialDelegate::sharedInstance()->initWithProductKey("dsyDlKXj6OserNDf");
    EziSocialDelegate::sharedInstance()->enableLogsAndAlerts(true, false);
    
    // Setup Facebook and Google Plus
    EziSocialDelegate::sharedInstance()->setFacebookID("526458254152479");
    EziSocialDelegate::sharedInstance()->setGoogleClientID("2730952540-ms7tmc6edel1vq1sca1e1mue262vptl8.apps.googleusercontent.com");
    

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
