//
//  HelloWorldScene.m
//  HelloWorld-Cocos2d-ios
//
//  Created by Paras Mendiratta on 02/09/14.
//  Copyright EziByte Technologies 2014. All rights reserved.
//
// -----------------------------------------------------------------------

#import "HelloWorldScene.h"
#import "IntroScene.h"

#import <EziSocialSDK/EziSocial.h>

// -----------------------------------------------------------------------
#pragma mark - HelloWorldScene
// -----------------------------------------------------------------------

@implementation HelloWorldScene
{
    CCSprite *_sprite;
}

// -----------------------------------------------------------------------
#pragma mark - Create & Destroy
// -----------------------------------------------------------------------

+ (HelloWorldScene *)scene
{
    return [[self alloc] init];
}

// -----------------------------------------------------------------------

- (id)init
{
    // Apple recommend assigning self with supers return value
    self = [super init];
    if (!self) return(nil);
    
    // Enable touch handling on scene node
    self.userInteractionEnabled = YES;
    
    // Create a colored background (Dark Grey)
    CCNodeColor *background = [CCNodeColor nodeWithColor:[CCColor colorWithRed:0.2f green:0.2f blue:0.2f alpha:1.0f]];
    [self addChild:background];
    
    // Add a sprite
    _sprite = [CCSprite spriteWithImageNamed:@"Icon-72.png"];
    _sprite.position  = ccp(self.contentSize.width/2,self.contentSize.height/2);
    [self addChild:_sprite];
    
    // Animate sprite with action
    CCActionRotateBy* actionSpin = [CCActionRotateBy actionWithDuration:1.5f angle:360];
    [_sprite runAction:[CCActionRepeatForever actionWithAction:actionSpin]];
    
    // Create a back button
    CCButton *backButton = [CCButton buttonWithTitle:@"[ Menu ]" fontName:@"Verdana-Bold" fontSize:18.0f];
    backButton.positionType = CCPositionTypeNormalized;
    backButton.position = ccp(0.85f, 0.95f); // Top Right of screen
    [backButton setTarget:self selector:@selector(onBackClicked:)];
    [self addChild:backButton];
    
    // Create a fbshare button
    CCButton *fbShareButton = [CCButton buttonWithTitle:@"[ FbShare ]" fontName:@"Verdana-Bold" fontSize:18.0f];
    fbShareButton.positionType = CCPositionTypeNormalized;
    fbShareButton.position = ccp(0.85f, 0.85f); // Top Right of screen
    [fbShareButton setTarget:self selector:@selector(onFacebookShareClick:)];
    [self addChild:fbShareButton];
    
    // Create a fbshare button
    CCButton *tweetButton = [CCButton buttonWithTitle:@"[ Tweet ]" fontName:@"Verdana-Bold" fontSize:18.0f];
    tweetButton.positionType = CCPositionTypeNormalized;
    tweetButton.position = ccp(0.85f, 0.75f); // Top Right of screen
    [tweetButton setTarget:self selector:@selector(onTweetClicked:)];
    [self addChild:tweetButton];

    // done
	return self;
}

// -----------------------------------------------------------------------

- (void)dealloc
{
    // clean up code goes here
}

// -----------------------------------------------------------------------
#pragma mark - Enter & Exit
// -----------------------------------------------------------------------

- (void)onEnter
{
    // always call super onEnter first
    [super onEnter];
    
    // In pre-v3, touch enable and scheduleUpdate was called here
    // In v3, touch is enabled by setting userInteractionEnabled for the individual nodes
    // Per frame update is automatically enabled, if update is overridden
    
}

// -----------------------------------------------------------------------

- (void)onExit
{
    // always call super onExit last
    [super onExit];
}

// -----------------------------------------------------------------------
#pragma mark - Touch Handler
// -----------------------------------------------------------------------

-(void) touchBegan:(UITouch *)touch withEvent:(UIEvent *)event {
    CGPoint touchLoc = [touch locationInNode:self];
    
    // Log touch location
    CCLOG(@"Move sprite to @ %@",NSStringFromCGPoint(touchLoc));
    
    // Move our sprite to touch location
    CCActionMoveTo *actionMove = [CCActionMoveTo actionWithDuration:1.0f position:touchLoc];
    [_sprite runAction:actionMove];
}

// -----------------------------------------------------------------------
#pragma mark - Button Callbacks
// -----------------------------------------------------------------------

- (void)onBackClicked:(id)sender
{
    // back to intro scene with transition
    [[CCDirector sharedDirector] replaceScene:[IntroScene scene]
                               withTransition:[CCTransition transitionPushWithDirection:CCTransitionDirectionRight duration:1.0f]];
}

- (void) onFacebookShareClick:(id)sender
{
    CCLOG(@"Share status on Facebook clicked.");
 
    [EziSocial fbShare:@"Hello World..." onComplete:^(BOOL success) {
       
        if (success)
        {
            CCLOG(@"Message posted on facebook wall successfully");
        }
        else
        {
            CCLOG(@"Connot post message on facebook wall.");
        }
        
    }];
}

- (void) onTweetClicked:(id)sender
{
    CCLOG(@"Share status on Twitter clicked.");
    
    [EziSocial tweet:@"Hello World...." onComplete:^(BOOL success) {
        if (success)
        {
            CCLOG(@"Tweet successful");
        }
        else
        {
            CCLOG(@"Cannot tweet message");
        }
    }];
}

// -----------------------------------------------------------------------
@end
