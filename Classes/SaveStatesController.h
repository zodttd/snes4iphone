//
//  BookmarksController.h
//  ShoutOut
//
//  Created by ME on 9/13/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SaveStatesController : UIViewController < UITableViewDataSource, UITableViewDelegate > {
  NSMutableArray*         arrayOfCharacters;
  NSMutableDictionary*    objectsForCharacters;
	IBOutlet UITableView*   tableview;
	IBOutlet UIWindow*      window;
	IBOutlet UITabBar*      tabBar;
	IBOutlet UISearchBar*   searchBar;
#ifdef WITH_ADS
	AltAds*	                altAds;
#endif
	NSUInteger				      adNotReceived;
	NSString*				        currentPath;
  NSArray*                alphabetIndex;
}

- (void)refreshData:(NSString*)path;
- (void)initSaveData;
- (void)startSaveData:(float)secs;

@end
