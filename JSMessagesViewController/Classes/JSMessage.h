//
<<<<<<< HEAD
//  Created by Jesse Squires
//  http://www.hexedbits.com
//
//
//  Documentation
//  http://cocoadocs.org/docsets/JSMessagesViewController
//
//
//  The MIT License
//  Copyright (c) 2013 Jesse Squires
//  http://opensource.org/licenses/MIT
//

#import <Foundation/Foundation.h>
#import "JSMessageData.h"

/**
 *  The Data with which timestamps are displayed in the messages table view.
 */
typedef NS_ENUM(NSUInteger, JSMessagesType) {
    /**
     *  Displays a Text Only message bubble, Coping Support Included.
     */
    JSTextMessage,
    /**
     *  Displays a Image above Description with text bubble, Action Included.
     */
    JSImageMessage,
    /**
     *  Displays a Image thumbnail for video with Play Button above Description with text bubble, Action Included.
     */
    JSVideoMessage
};


/**
 *  A `JSMessage` object represents a single user message. This is a concrete class that implements the `JSMessageData` protocol. It contains the message text, its sender, and the date that the message was sent.
 */
@interface JSMessage : NSObject <JSMessageData, NSCoding, NSCopying>

/**
 *  The body text of the message. The default value is the empty string `@" "`. This value must not be `nil`.
 */
@property (copy, nonatomic) NSString *text;

/**
 *  The name of user who sent the message. The default value is `nil`.
 */
@property (copy, nonatomic) NSString *sender;

/**
 *  The date that the message was sent. The default value is `nil`.
 */
@property (strong, nonatomic) NSDate *date;

#pragma mark - Initialization

/**
 *  Initializes and returns a message object having the given text, sender, and date.
 *
 *  @param text   The body text of the message.
 *  @param sender The name of the user who sent the message.
 *  @param date   The date that the message was sent.
 *
 *  @return An initialized `JSMessage` object or `nil` if the object could not be successfully initialized.
 */
- (instancetype)initWithText:(NSString *)text
                      sender:(NSString *)sender
                        date:(NSDate *)date;

/**
 *  Returns the type of Message used.
 */
@property (nonatomic) JSMessagesType type;

/**
 *  Returns the text of Message to be displayed used as a message or a description.
 */
@property (strong, nonatomic) NSString* textMessage;
/**
 *  Returns image that would be used as Thumbnail.
 */
@property (strong, nonatomic) UIImage *thumbnailImage;


/**
 *  Returns URL view that would be displayed.
 */
@property (strong, nonatomic) NSURL* mediaURL;



/**
 *  Initialize the message object with Text Message.
 *
 *  @param text Text message to be displayed in the bubble message.
 */
- (instancetype)initWithTextMessage:(NSString*)text;


/**
 *  Initialize the message object with Image Message Type.
 *
 *  @param thumbnailImage image to be displayed inside Image bubble
 *  @param description greyed Text shown under the image descriptive to the image content
 *  @param mediaURL URL for image to be shown if message tapped
 */
- (instancetype)initWithImageMessage:(UIImage *) thumbnailImage
                  description:(NSString*) description
                 linkedToURL:(NSURL*) mediaURL;


/**
 *  Initialize the message object with Video Message Type.
 *
 *  @param thumbnailImage image to be displayed inside Image bubble, Play Button Overlay will be added on it.
 *  @param description greyed Text shown under the image descriptive to the video content
 *  @param mediaURL URL for Video to be shown if message tapped
 */
- (instancetype)initWithVideoMessage:(UIImage *) thumbnailImage
                  description:(NSString*) description
                 linkedToURL:(NSURL*) mediaURL;

@end
