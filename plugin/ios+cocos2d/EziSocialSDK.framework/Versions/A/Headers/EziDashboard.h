//
//  EziDashboard.h
//  EziSocialTestProject
//
//  Created by Paras Mendiratta on 11/06/14.
//  Copyright (c) 2014 EziByte Technologies. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GooglePlus/GooglePlus.h>

@interface EziDashboard : UIViewController <GPPSignInDelegate, UIAlertViewDelegate>

@property (nonatomic, strong) IBOutlet UIActivityIndicatorView* imageProgressIndicator;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView* progressIndicator;
@property (nonatomic, strong) IBOutlet UILabel *messageLabel;

@property (nonatomic, strong) IBOutlet UILabel *username;
@property (strong) IBOutlet UIImageView *profilePic;

@property (nonatomic, strong) IBOutlet UIButton* playButton;
@property (nonatomic, strong) IBOutlet UIButton* fbLoginButton;
@property (nonatomic, strong) IBOutlet UIButton* gpLoginButton;
@property (nonatomic, strong) IBOutlet UIButton* twLoginButton;

@property (nonatomic, strong) IBOutlet UIButton* logoutButton;
@property (nonatomic, strong) IBOutlet UIButton* connectionDoctor;
@property (nonatomic, strong) IBOutlet UIButton* friendsButton;
@property (nonatomic, strong) IBOutlet UIButton* settingsButton;
@property (nonatomic, strong) IBOutlet UIButton* logoButton;
@property (nonatomic, strong) IBOutlet UIButton* leaderboardButton;
@property (nonatomic, strong) IBOutlet UIButton* gamestreamButton;

-(IBAction)connectionDoctor:(id)sender;
-(IBAction)connectWithFacebook:(id)sender;
-(IBAction)connectWithTwitter:(id)sender;
-(IBAction)connectWithGPlus:(id)sender;
-(IBAction)openURL:(id)sender;
-(IBAction)logout:(id)sender;
-(IBAction)startGame:(id)sender;

-(IBAction)futureAction:(id)sender;

@property (nonatomic, copy) dispatch_block_t blockStartGame;

@end


