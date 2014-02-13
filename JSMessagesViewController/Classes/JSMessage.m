//

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

//  JSMessage.m
//  JSMessagesDemo
//
//  Created by Ahmed Ghalab on 12/6/13.
//  Copyright (c) 2013 Hexed Bits. All rights reserved.
//

#import "JSMessage.h"

@implementation JSMessage

#pragma mark - Initialization

- (instancetype)initWithText:(NSString *)text
                      sender:(NSString *)sender
                        date:(NSDate *)date
{
    self = [super init];
    if (self) {
        _text = text ? text : @" ";
        _sender = sender;
        _date = date;
    }
    return self;
}

- (id)init
{
    self = [super init];
    if (self) {
        // Set Default Values ..
        self.mediaURL = nil;
        self.textMessage = nil;
        self.thumbnailImage = nil;
    }
    return self;
}

- (void)dealloc
{
    _text = nil;
    _sender = nil;
    _date = nil;
}

#pragma mark - NSCoding

- (id)initWithCoder:(NSCoder *)aDecoder
{
    self = [super init];
    if (self) {
        _text = [aDecoder decodeObjectForKey:@"text"];
        _sender = [aDecoder decodeObjectForKey:@"sender"];
        _date = [aDecoder decodeObjectForKey:@"date"];
    }
    return self;
}

- (void)encodeWithCoder:(NSCoder *)aCoder
{
    [aCoder encodeObject:self.text forKey:@"text"];
    [aCoder encodeObject:self.sender forKey:@"sender"];
    [aCoder encodeObject:self.date forKey:@"date"];
}

#pragma mark - NSCopying

- (id)copyWithZone:(NSZone *)zone
{
    return [[[self class] allocWithZone:zone] initWithText:[self.text copy]
                                                    sender:[self.sender copy]
                                                      date:[self.date copy]];
}
#pragma mark - Intialization Methods
- (instancetype)initWithTextMessage:(NSString*)text
{
    self = [super init];
    if(self) {
        self.type = JSTextMessage;
        self.textMessage = text;
    }
    return self;

}

- (instancetype)initWithImageMessage:(UIImage *) thumbnailImage
                  description:(NSString*) description
                 linkedToURL:(NSURL*) mediaURL
{
    self = [super init];
    if(self) {
        self.type = JSImageMessage;
        
        self.thumbnailImage = thumbnailImage;
        self.mediaURL = mediaURL;
        
        self.textMessage = description;
    }
    return self;
}


- (instancetype)initWithVideoMessage:(UIImage *) thumbnailImage
                  description:(NSString*) description
                 linkedToURL:(NSURL*) mediaURL
{
    self = [super init];
    if(self) {
        self.type = JSVideoMessage;
        
        self.thumbnailImage = thumbnailImage;
        self.mediaURL = mediaURL;
        
        self.textMessage = description;
    }
    return self;
}

@end
