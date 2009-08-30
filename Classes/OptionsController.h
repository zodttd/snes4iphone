//
//  OptionsController.h
//  psx4iphone
//
//  Created by ME on 1/29/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface OptionsController : UIViewController 
{
	IBOutlet UISegmentedControl*	segmentedSkin;
	IBOutlet UISwitch*				switchScaling;
	IBOutlet UISwitch*				switchAutosave;
	IBOutlet UISwitch*				switchSmoothScaling;
	IBOutlet UISwitch*				switchFramerate;
	IBOutlet UISwitch*				switchCompatibility;
	IBOutlet UISwitch*				switchSpeedHack;
	NSMutableArray*					optionsArray;
}

- (void)optionChanged:(id)sender;
- (NSString*)getDocumentsDirectory;
- (void)getOptions;
- (int)getCurrentSkin;
- (int)getCurrentScaling;
- (int)getCurrentSmoothScaling;

@end
