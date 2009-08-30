//
//  ShoutOutAppDelegate.h
//  ShoutOut
//
//  Created by Spookysoft on 9/6/08.
//  Copyright Spookysoft 2008. All rights reserved.
//

#import <UIKit/UIKit.h>

#define NUMBER_OF_AD_PAGES 4

@interface ShoutOutAppDelegate : NSObject <UIApplicationDelegate> {
	
	IBOutlet UIWindow*					window;
	IBOutlet UINavigationController*	navigationController;
	IBOutlet UITabBar*					tabBar;
#ifdef WITH_ADS
	AltAds*	 altAds[NUMBER_OF_AD_PAGES];
#endif
}

- (void)switchToBrowse;
- (void)switchToSaveStates;
//- (void)switchToBookmarks;
- (void)switchToNowPlaying;
- (void)switchToRecent;
- (void)switchToOptions;
#ifdef WITH_ADS
- (AltAds*)getAdViewWithIndex:(int)index;
- (void)pauseAdViews;
- (void)unpauseAdViews;
#endif

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) UINavigationController *navigationController;

@end

