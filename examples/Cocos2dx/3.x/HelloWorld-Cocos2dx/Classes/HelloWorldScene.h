#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // dashboard button callback
    void showDashboard(cocos2d::Ref* pSender);
    
    // startGameCallback
    void startGame();
    
    // Share Events
    void tweet(cocos2d::Ref* pSender);
    void fbshare(cocos2d::Ref* pSender);
    
    // Share Event Callbacks
    void tweetCallback(bool success);
    void fbshareCallback(bool success);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
