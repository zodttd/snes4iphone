//
//  BookmarksController.h
//  ShoutOut
//
//  Created by ME on 9/13/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface RecentController : UIViewController < UITableViewDataSource, UITableViewDelegate > {
	IBOutlet UITableView		* tableview;
	IBOutlet UITabBar			* tabBar;
	IBOutlet UITextField		* textBookmark;
	IBOutlet UIWindow			* window;
	NSMutableArray				* recentArray;
#ifdef WITH_ADS
	AltAds*	 altAds;
#endif
	NSUInteger					  adNotReceived;
}

- (void)getRecent;
- (void)addRecent:(NSString*)thisPath;
- (NSString*)getDocumentsDirectory;

@end
