//
//  BookmarksController.m
//  ShoutOut
//
//  Created by ME on 9/13/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "SOApplication.h"


@implementation BookmarksController

- (void)dealloc {
	[ super dealloc ];
}

- (void)viewDidLoad {
	[super viewDidLoad];
	self.navigationItem.hidesBackButton = YES;
}

-(void)awakeFromNib
{
	self.navigationItem.hidesBackButton = YES;
	[textBookmark setText:[NSString stringWithCString:get_documents_path("/")]]; //@"/var/mobile/Media/ROMs/GBA/"];
	// always put any sort of initializations in here. They will only be called once.
	adNotReceived = 0;

	[self getBookmarks];
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	self.navigationItem.hidesBackButton = YES;
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated {
}

- (void)viewDidDisappear:(BOOL)animated {
}

- (void)didReceiveMemoryWarning {
	[super didReceiveMemoryWarning];
}

- (NSString*)getDocumentsDirectory
{
	NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
	NSString *documentsDirectory = [paths objectAtIndex: 0];
	return documentsDirectory;
	//return @"/Applications/gpSPhone.app";
}

- (void)textFieldDidBeginEditing:(UITextField *)textField {
	[textField setText:[NSString stringWithCString:get_documents_path("/")]];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
	[self addBookmark:textField.text withFile:textField.text withDir:textField.text];
	[textField resignFirstResponder];
	[textField setText:[NSString stringWithCString:get_documents_path("/")]];
	return YES;
}

- (void)addBookmark:(NSString*)thisPath withFile:(NSString*)thisFile withDir:(NSString*)thisDir {
	if(thisPath && thisFile && thisDir)
	{
		[bookmarksArray addObject:[NSDictionary dictionaryWithObjectsAndKeys:
								thisPath, @"path",
								thisFile, @"file",
								thisDir, @"directory",								   
								nil]];
		[tableview reloadData];
		
	}
	else
	{
		return;
	}
	
	
	NSString *path=[[self getDocumentsDirectory] stringByAppendingPathComponent:@"bookmarks.bin"];
	NSData *plistData;
	
	NSString *error;
	
	
	
	plistData = [NSPropertyListSerialization dataFromPropertyList:bookmarksArray
				 
												format:NSPropertyListBinaryFormat_v1_0
				 
												errorDescription:&error];
	
	if(plistData)
		
	{
		
		NSLog(@"No error creating plist data.");
		
		[plistData writeToFile:path atomically:NO];
		
	}
	else
	{
		
		NSLog(error);
		
		[error release];
		
	}
}

- (void)getBookmarks {
	NSString *path=[[self getDocumentsDirectory] stringByAppendingPathComponent:@"bookmarks.bin"];
	
	NSData *plistData;
	id plist;
	NSString *error;
	
	NSPropertyListFormat format;
	
	plistData = [NSData dataWithContentsOfFile:path];
	
	
	
	plist = [NSPropertyListSerialization propertyListFromData:plistData
			 
											 mutabilityOption:NSPropertyListImmutable
			 
													   format:&format
			 
											 errorDescription:&error];
	
	if(!plist)
	{
		
		NSLog(error);
		
		[error release];
		
		bookmarksArray = [[NSMutableArray alloc] init];
	}
	else
	{
		bookmarksArray = [[NSMutableArray alloc] initWithArray:plist];
	}
}

// *** Tablesource stuffs.
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	// Number of sections is the number of region dictionaries
	
	if(bookmarksArray==nil) {
		return 1;
	} else {
		return 2;
	}
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	if(bookmarksArray==nil) {
		return 1;
	}
	
	if(section < 1)
	{
		return 1;
	}

	return [bookmarksArray count];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
	if(indexPath.section < 1) {
		return 55.0; // this is the height of the ad
	}
	
	return 44.0; // this is the generic cell height
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
	UITableViewCell *cell;
	
	if(indexPath.section < 1) 
	{
		cell = [tableview dequeueReusableCellWithIdentifier:@"adCell4"];
		/*
		if(cell != nil)
		{
			[cell release];
			cell = nil;
		}
    */
		if(cell == nil)
		{
			cell = [[UITableViewCell alloc] initWithFrame:CGRectZero reuseIdentifier:@"adCell4"];
			// Request an ad for this table view cell
      altAds = [SOApp.delegate getAdViewWithIndex:3];
			[cell.contentView addSubview:altAds];
		}
		else
		{
		  altAds = [SOApp.delegate getAdViewWithIndex:3];
			[cell.contentView addSubview:altAds];
		}
		
		cell.text = @"";
	}
	else
	{
		cell = [tableview dequeueReusableCellWithIdentifier:@"cell"];
		if (cell == nil) 
		{
			cell = [[[UITableViewCell alloc] initWithFrame:CGRectZero reuseIdentifier:@"cell"] autorelease];
		}
		cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
		if([[[bookmarksArray objectAtIndex:indexPath.row] objectForKey:@"path"] compare:@""] != NSOrderedSame)
		{
			UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 320, 44)];
			label.numberOfLines = 1;
			label.adjustsFontSizeToFitWidth = YES;
			label.minimumFontSize = 9.0f;
			label.lineBreakMode = UILineBreakModeMiddleTruncation;
			label.text = [[[bookmarksArray objectAtIndex:indexPath.row] objectForKey:@"path"] lastPathComponent];
			[cell.contentView addSubview:label];
			[label release];
		}
	}
	
	// Set up the cell
	return cell;
}

- (void)setCurrentlyPlaying:(NSString*) str
{	
	self.navigationItem.prompt = str;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	if( indexPath.section < 1 )
	{
		return;
	}
	char *cListingsPath;
	if([[[bookmarksArray objectAtIndex:indexPath.row] objectForKey:@"path"] compare:@""] != NSOrderedSame )
	{
		cListingsPath = (char*)[[[bookmarksArray objectAtIndex:indexPath.row] objectForKey:@"path"] UTF8String];
		[SOApp.nowPlayingView setCurrentStation:[[bookmarksArray objectAtIndex:indexPath.row] objectForKey:@"path"] 
		 withFile:[[bookmarksArray objectAtIndex:indexPath.row] objectForKey:@"file"] 
		 withDir:[[bookmarksArray objectAtIndex:indexPath.row] objectForKey:@"directory"]];
	}
	
	[SOApp.nowPlayingView startEmu:cListingsPath];
	[SOApp.delegate switchToNowPlaying];
	//[tabBar didMoveToWindowNowPlaying];
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
	
	if (editingStyle == UITableViewCellEditingStyleDelete) {
		// Delete the row from the data source
		//[tableview deleteRowAtIndexPaths:[NSArray arrayWithObject:indexPath] withRowAnimation:YES];
		[bookmarksArray removeObjectAtIndex:indexPath.row];
		[tableview reloadData];
		NSString *path=[[self getDocumentsDirectory] stringByAppendingPathComponent:@"bookmarks.bin"];
		NSData *plistData;
		
		NSString *error;
		
		
		
		plistData = [NSPropertyListSerialization dataFromPropertyList:bookmarksArray
					 
															   format:NSPropertyListBinaryFormat_v1_0
					 
													 errorDescription:&error];
		
		if(plistData)
			
		{
			
			NSLog(@"No error creating plist data.");
			
			[plistData writeToFile:path atomically:YES];
			
		}
		else
		{
			
			NSLog(error);
			
			[error release];
			
		}
		
	}	
	if (editingStyle == UITableViewCellEditingStyleInsert) {
		// Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
	}	
}

@end