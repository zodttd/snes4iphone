//
//  snes4iphone
//
//  Created by Spookysoft on 9/6/08.
//  Copyright Spookysoft 2008. All rights reserved.
//

#import <UIKit/UIKit.h>

int main(int argc, char *argv[]) {
	
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
	//UIApplicationUseLegacyEvents(1);
	int retVal = UIApplicationMain(argc, argv, @"SOApplication", nil);
	[pool release];
	return retVal;
}
