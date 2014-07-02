//
//  SUUpdateDriver.h
//  Sparkle
//
//  Created by Andy Matuschak on 5/7/08.
//  Copyright 2008 Andy Matuschak. All rights reserved.
//

#ifndef SUUPDATEDRIVER_H
#define SUUPDATEDRIVER_H

#import <Cocoa/Cocoa.h>

extern NSString * const SUUpdateDriverFinishedNotification;

@class SUHost, SUUpdater;
@interface SUUpdateDriver : NSObject<NSURLDownloadDelegate>
{
	SUUpdater *updater; //assigned
	NSURL *appcastURL;
    BOOL isInterruptible;
}
@property (strong) SUHost *host;

- (instancetype) initWithUpdater:(SUUpdater *)updater;
- (void)checkForUpdatesAtURL:(NSURL *)URL host:(SUHost *)host;
- (void)abortUpdate;
@property (getter=isInterruptible, readonly) BOOL interruptible;
@property (readonly) BOOL finished;

@end

#endif