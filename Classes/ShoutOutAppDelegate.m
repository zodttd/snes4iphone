//
//  snes4iphone
//
//  Created by Spookysoft on 9/6/08.
//  Copyright Spookysoft 2008. All rights reserved.
//

#import "SOApplication.h"

extern unsigned long gp2x_pad_status;

@implementation ShoutOutAppDelegate

@synthesize window;
@synthesize navigationController;


- (id)init {
	if (self = [super init]) {
		// 
	}
	return self;
}


- (void)applicationDidFinishLaunching:(UIApplication *)application {
  int i;
  
	[[UIApplication sharedApplication] setStatusBarHidden:NO animated:NO];
	[[UIApplication sharedApplication] setIdleTimerDisabled:YES];
	application.delegate = self;

#ifdef WITH_ADS
  //MainScreenWindow = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
  //Blocked = [AltAds isAdBlockingEnabled];
  for(i = 0; i < NUMBER_OF_AD_PAGES; i++)
  {
    altAds[i] = [[AltAds alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 320.0f, 55.0f) andWindow:nil];
  }
#endif

	CGRect frame = window.frame;
	frame.origin.y = window.frame.origin.y+window.frame.size.height-49;
	frame.size.height = 49;
	tabBar.frame = frame;
	[window addSubview:tabBar];
	CGRect navFrame = [navigationController view].frame;
	navFrame.origin.y = 20;
	navFrame.size.height = 460 - 49;
	[navigationController view].frame = navFrame;

  
  [self switchToBrowse];
  
//	tabBar.selectedItem = 0;
	// Configure and show the window
	//[SOApp.nowPlayingView startEmu:"/var/mobile/Media/ROMs/GBA/Pokemon - Emerald Version (U) [f1] (Save Type).gba"];
	//[window addSubview:[SOApp.nowPlayingView view]];
	//[window makeKeyAndVisible];
	
	[window addSubview:[navigationController view]];

	[window makeKeyAndVisible];

  //[self switchToBrowse];

	// Load ROMs
  [SOApp.romView startRootData:2.0f];

	// Load Saves
  [SOApp.saveStatesView startSaveData:4.0f];
}

#ifdef WITH_ADS
- (AltAds*)getAdViewWithIndex:(int)index {
  if(index < NUMBER_OF_AD_PAGES)
  {
    return altAds[index];
  }
  return altAds[0];
}

- (void)pauseAdViews {
  int i;
  
  for(i = 0; i < NUMBER_OF_AD_PAGES; i++)
  {
    [altAds[i] stopAdTimers];
  }
}

- (void)unpauseAdViews {
  int i;
  
  for(i = 0; i < NUMBER_OF_AD_PAGES; i++)
  {
    [altAds[i] RefreshAd];
  }
}
#endif

#pragma mark TabBar Actions
- (void)switchToBrowse {
	[[UIApplication sharedApplication] setStatusBarHidden:NO animated:NO];
	[tabBar setHidden:NO];
	CGRect navFrame = [navigationController view].frame;
	navFrame.origin.y = 20;
	navFrame.size.height = 460 - 49;
	[navigationController view].frame = navFrame;
	navigationController.navigationBarHidden = FALSE;
	navigationController.navigationBar.hidden = FALSE;
	
	if ([[[self navigationController] viewControllers] containsObject:SOApp.romView]) {
		[[self navigationController] popToViewController:SOApp.romView animated:NO];
	} else {
		[[self navigationController] pushViewController:SOApp.romView animated:NO];
	}
}
- (void)switchToSaveStates {
	[[UIApplication sharedApplication] setStatusBarHidden:NO animated:NO];
	[tabBar setHidden:NO];
	CGRect navFrame = [navigationController view].frame;
	navFrame.origin.y = 20;
	navFrame.size.height = 460 - 49;
	[navigationController view].frame = navFrame;
	navigationController.navigationBarHidden = FALSE;
	navigationController.navigationBar.hidden = FALSE;
	
	if ([[[self navigationController] viewControllers] containsObject:SOApp.saveStatesView]) {
		[[self navigationController] popToViewController:SOApp.saveStatesView animated:NO];
	} else {
		[[self navigationController] pushViewController:SOApp.saveStatesView animated:NO];
	}
}
- (void)switchToNowPlaying {
	[[UIApplication sharedApplication] setStatusBarHidden:YES animated:NO];
	[tabBar setHidden:YES];
	CGRect navFrame = [navigationController view].frame;
	navFrame.origin.y = 0;
	navFrame.size.height = 480;
	[navigationController view].frame = navFrame;
	navigationController.navigationBarHidden = TRUE;
	navigationController.navigationBar.hidden = TRUE;

	gp2x_pad_status = 0;
	
	if ([[[self navigationController] viewControllers] containsObject:SOApp.nowPlayingView]) {
		[[self navigationController] popToViewController:SOApp.nowPlayingView animated:NO];
	} else {
		[[self navigationController] pushViewController:SOApp.nowPlayingView animated:NO];
	}
}
- (void)switchToRecent {
	[[UIApplication sharedApplication] setStatusBarHidden:NO animated:NO];
	[tabBar setHidden:NO];
	CGRect navFrame = [navigationController view].frame;
	navFrame.origin.y = 20;
	navFrame.size.height = 460 - 49;
	[navigationController view].frame = navFrame;
	navigationController.navigationBarHidden = FALSE;
	navigationController.navigationBar.hidden = FALSE;
	
	if ([[[self navigationController] viewControllers] containsObject:SOApp.recentView]) {
		[[self navigationController] popToViewController:SOApp.recentView animated:NO];
	} else {
		[[self navigationController] pushViewController:SOApp.recentView animated:NO];
	}
}
- (void)switchToOptions {
	[[UIApplication sharedApplication] setStatusBarHidden:NO animated:NO];
	[tabBar setHidden:NO];
	CGRect navFrame = [navigationController view].frame;
	navFrame.origin.y = 20;
	navFrame.size.height = 460 - 49;
	[navigationController view].frame = navFrame;
	navigationController.navigationBarHidden = FALSE;
	navigationController.navigationBar.hidden = FALSE;
	
	if ([[[self navigationController] viewControllers] containsObject:SOApp.optionsView]) {
		[[self navigationController] popToViewController:SOApp.optionsView animated:NO];
	} else {
		[[self navigationController] pushViewController:SOApp.optionsView animated:NO];
	}
}

- (void)switchToWebBrowserView
{
	[[UIApplication sharedApplication] setStatusBarHidden:NO animated:NO];
	[tabBar setHidden:NO];
	CGRect navFrame = [navigationController view].frame;
	navFrame.origin.y = 20;
	navFrame.size.height = 460 - 49;
	[navigationController view].frame = navFrame;
	navigationController.navigationBarHidden = FALSE;
	navigationController.navigationBar.hidden = FALSE;
	
	if ([[[self navigationController] viewControllers] containsObject:SOApp.webBrowserView]) 
	{
		[[self navigationController] popToViewController:SOApp.webBrowserView animated:NO];
	} 
	else
	{
		[[self navigationController] pushViewController:SOApp.webBrowserView animated:NO];
	}
}

- (void)reloadROMs
{
  [SOApp.romView startRootData:2.0f];
}

- (void)applicationWillTerminate:(UIApplication *)application {
}

- (void)dealloc {
#ifdef WITH_ADS
  int i;
  for(i = 0; i < NUMBER_OF_AD_PAGES; i++)
  {
    [altAds[i] release];
  }
#endif

	[ navigationController release ];
	[ window release ];
	[ super dealloc ];
}

@end
