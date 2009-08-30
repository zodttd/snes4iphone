#import <UIKit/UIKit.h>
#import <CoreFoundation/CoreFoundation.h>
#import "CoreSurface/CoreSurface.h"
#import "helpers.h"
#import "TabBar.h"
#import "AltAds.h"
#import "RomController.h"
#import "ShoutOutAppDelegate.h"
#import "NowPlayingController.h"
#import "SaveStatesController.h"
#import "RecentController.h"
#import "OptionsController.h"

#define SOApp ((SOApplication *)[UIApplication sharedApplication])
@interface SOApplication : UIApplication 
{
	IBOutlet	RomController           * romView;
	IBOutlet	NowPlayingController		* nowPlayingView;
	IBOutlet	SaveStatesController		* saveStatesView;
	IBOutlet	RecentController        * recentView;
	IBOutlet	OptionsController       * optionsView;
}

@property(assign)	RomController         * romView;
@property(assign)	NowPlayingController	* nowPlayingView;
@property(assign)	SaveStatesController	* saveStatesView;
@property(assign)	RecentController			* recentView;
@property(assign)	OptionsController			* optionsView;

@end
