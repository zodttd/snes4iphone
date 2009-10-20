#import <UIKit/UIKit.h>

extern void *app_Thread_Start(void *args);

@interface RomController : UIViewController < UITableViewDataSource, UITableViewDelegate > {
  NSMutableArray*         arrayOfCharacters;
  NSMutableDictionary*    objectsForCharacters;
	IBOutlet UITableView*	  tableview;
	IBOutlet UIWindow*		  window;
	IBOutlet UITabBar*		  tabBar;
	IBOutlet UISearchBar*   searchBar;	
#ifdef WITH_ADS
	AltAds*	                altAds;
#endif
	NSUInteger				      adNotReceived;
	NSString*				        currentPath;
  NSArray*                alphabetIndex;
}

- (void)refreshData:(NSString*)path;
- (void)initRootData;
- (void)startRootData:(float)secs;

@end
