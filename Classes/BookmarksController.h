//
//  BookmarksController.h
//  ShoutOut
//
//  Created by ME on 9/13/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BookmarksController : UIViewController < UITableViewDataSource, UITableViewDelegate > {
	IBOutlet UITableView		* tableview;
	IBOutlet UITabBar			* tabBar;
	IBOutlet UITextField		* textBookmark;
	IBOutlet UIWindow			* window;
	NSMutableArray				* bookmarksArray;
#ifdef WITH_ADS
	AltAds*	 altAds;
#endif
	NSUInteger					  adNotReceived;
}

- (void)getBookmarks;
- (void)addBookmark:(NSString*)thisPath withFile:(NSString*)thisFile withDir:(NSString*)thisDir;
- (NSString*)getDocumentsDirectory;

@end
