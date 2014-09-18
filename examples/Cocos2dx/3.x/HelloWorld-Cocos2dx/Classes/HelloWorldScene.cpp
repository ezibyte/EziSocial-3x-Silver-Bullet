#include "HelloWorldScene.h"

#include "EziSocialDelegate.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    
    // Dashboard Button
    auto dashboardButton = MenuItemLabel::create(Label::createWithSystemFont("Show Dashboard", "Arial", 25), CC_CALLBACK_1(HelloWorld::showDashboard, this));
    
    dashboardButton->setPosition(Vec2(origin.x + visibleSize.width/2, 90));
    
    // Create the menu
    auto eziMenu = Menu::create(dashboardButton, NULL);
    eziMenu->setPosition(Vec2::ZERO);
    this->addChild(eziMenu, 1);
    
    // Share buttons
    auto tweetButton = MenuItemLabel::create(Label::createWithSystemFont("Tweet Message", "Arial", 25), CC_CALLBACK_1(HelloWorld::tweet, this));
    
    tweetButton->setPosition(Vec2(visibleSize.width/2, 80));
    
    auto fbShareButton = MenuItemLabel::create(Label::createWithSystemFont("Update Facebook Status", "Arial", 25), CC_CALLBACK_1(HelloWorld::fbshare, this));
    
    fbShareButton->setPosition(Vec2(visibleSize.width/2,
                                    100));
    
    auto shareMenu = Menu::create(tweetButton, fbShareButton, NULL);
    shareMenu->alignItemsVertically();
    shareMenu->setPosition(Vec2(visibleSize.width/2, 40));
    this->addChild(shareMenu, 1);
    
    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}

void HelloWorld::showDashboard(Ref* pSender)
{
    EziSocialDelegate::sharedInstance()->showDashboard(CC_CALLBACK_0(HelloWorld::startGame, this));
}

void HelloWorld::startGame()
{
    CCLOG("Please start the game");
}


void HelloWorld::tweet(cocos2d::Ref* pSender)
{
    EziSocialDelegate::sharedInstance()->tweet("This is my first tweet from EziSocial Plugin", CC_CALLBACK_1(HelloWorld::tweetCallback, this    ));
}
void HelloWorld::fbshare(cocos2d::Ref* pSender)
{
    EziSocialDelegate::sharedInstance()->fbShare("This is my first status updated from Cocos2dx", CC_CALLBACK_1(HelloWorld::fbshareCallback, this));
}

void HelloWorld::tweetCallback(bool success)
{
    if (success)
    {
        CCLOG("Tweet success");
    }
    else
    {
        CCLOG("Tweet failed");
    }
}

void HelloWorld::fbshareCallback(bool success)
{
    if (success)
    {
        CCLOG("Facebook status update success");
    }
    else
    {
        CCLOG("Facebook status failed");
    }
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
