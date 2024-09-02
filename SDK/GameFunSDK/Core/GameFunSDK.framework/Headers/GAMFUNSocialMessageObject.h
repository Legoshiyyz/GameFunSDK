//
//  GAMFUNSocialMessageObject.h
//  GameFunSDK
//
//  Created by Balalaika on 2020/2/21.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Photos/Photos.h>

/**
 *  Social platform type
 */
typedef NS_ENUM(NSInteger, GAMFUNSocialPlateType) {
    GAMFUNSocialPlate_Facebook       = 1,             // Facebook
    GAMFUNSocialPlate_WhatsApp       = 2,             // WhatsApp
    
    //The following content is not open yet
    GAMFUNSocialPlate_Messenger      = 3,             // Messenger
    GAMFUNSocialPlate_TTkApp         = 4,             // TTkApp
    GAMFUNSocialPlate_TTkApi         = 5,             // TTkApi
    GAMFUNSocialPlate_BimApp         = 6,             // BimApp
    GAMFUNSocialPlate_BimApi         = 7              // BimApi
};

/**
 *  Share content type
 */
typedef NS_ENUM(NSInteger, GAMFUNShareContentType) {
    GAMFUNShareContent_Link          = 1,
    GAMFUNShareContent_FBGameInvite  = 2,
    GAMFUNShareContent_Photo         = 3,
    
    //The following content is not open yet
    GAMFUNShareContent_Video         = 4,
    GAMFUNShareContent_Media         = 5,
};

/**
 *  Share custom templates
 */
typedef NS_ENUM(NSInteger, GAMFUNShareTemplate) {
    GAMFUNShareTemplate_Default        = 1,             // the link of game page
    GAMFUNShareTemplate_Invite         = 2,             // invite link
    
    //The following content is not open yet
    GAMFUNShareTemplate_Notice         = 3,             // notice link
    GAMFUNShareTemplate_Showoff        = 4,             // showoff link
};

NS_ASSUME_NONNULL_BEGIN

//GAMFUNSocialMessageObject
//The model is temporarily internal, so game developers do n’t need to pay attention
@interface GAMFUNSocialMessageObject : NSObject

/**
 Social platform type
 Share required fields
*/
@property (nonatomic) GAMFUNSocialPlateType plateType;

/**
 Share content type
 Share required fields
*/
@property (nonatomic) GAMFUNShareContentType contentType;

/**
 Share custom templates
 When the sharing content type is GAMFUNShareContent_Link is a required field
*/
@property (nonatomic) GAMFUNShareTemplate shareTemplate;

/**
 link URL
 Currently the link content is defined by the SDK based on the shareTemplate, and developers do not need to use.
*/
@property (nonatomic, copy, nullable) NSURL *contentURL;

/**
 Some quote text of the link.（Facebook）
If specified, the quote text will render with custom styling on top of the link.
*/
@property (nonatomic, copy, nullable) NSString *quote;

/**
 Share photos array
 
 Supported types
 facebook:（UIImage、NSURL、PHAsset）
 messenger: (UIImage、NSURL)
 whatsApp: (UIImage、NSURL)
*/
@property (nonatomic, copy) NSArray *photos;

/**
 Share photos array
 
 Supported types
 facebook:（UIImage、NSURL、PHAsset）
 messenger: (UIImage、NSURL)
 whatsApp: (UIImage、NSURL)
*/
@property (nonatomic, copy) UIImage *photoImage;

/**
 Video
 
 Supported types
 facebook:（NSData、PHAsset、NSURL）
 messenger: (NSURL)
 whatsApp: (NSURL)
 */
/**
 video data.
*/
@property (nonatomic, strong, nullable) NSData *videoData;

/**
 The representation of the video in the Photos library.
 @return PHAsset that represents the video in the Photos library.
*/
@property (nonatomic, copy, nullable) PHAsset *videoAsset;

/**
 The file URL to the video.
 @return URL that points to the location of the video on disk
*/
@property (nonatomic, copy, nullable) NSURL *videoURL;

/**
 Share content string
 
 Supported types
 whatsApp: (NSString)
*/
@property (nonatomic, copy) NSString *contentString;


@end

/************************* Facebook ******************************/

// FacebookInvite Model
@interface GAMFUNSocialFBInvite : NSObject

@property (nonatomic, copy, nullable) NSString *quote; // Some quote text of the link

@end

// FacebookGameInvite to friends Model
@interface GAMFUNSocialFBFriendsGameInvite : NSObject

@property (nonatomic, copy, nullable) NSString *inviteString;

@end

// Facebook Image Model
@interface GAMFUNSocialFBImages : NSObject

@property (nonatomic, copy) UIImage *photoImage; // share image <UIImage>

@end

/************************* WhatsApp ******************************/

// WhatsApp Link Model
@interface GAMFUNSocialWAInvite : NSObject

@property (nonatomic, copy) NSString *contentString; // share content string

@end

// WhatsApp Image Model
@interface GAMFUNSocialWAImages : NSObject

@property (nonatomic, copy) NSArray *photos; // share images array（UIImage、NSData、PHAsset、NSURL）

@end

// ttk invite model
@interface GAMFUNSocialTTkInvite : NSObject

@property (nonatomic, copy) NSString *ttkUid;
@property (nonatomic, copy) NSString *contentString;
@property (nonatomic, copy) NSString *buttonTitle;
@property (nonatomic, copy) NSString *imageUrl;

@end

// ttk notice model
@interface GAMFUNSocialTTkNotice : NSObject

@property (nonatomic, copy) NSString *ttkUid;
@property (nonatomic, copy) NSString *contentString;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *imageUrl;

@end

// botim invite model
@interface GAMFUNSocialBimInvite : NSObject

@property (nonatomic, copy) NSString *bimUid;
@property (nonatomic, copy) NSString *contentString;
@property (nonatomic, copy) NSString *buttonTitle;
@property (nonatomic, copy) NSString *imageUrl;

@end

// botim notice model
@interface GAMFUNSocialBimNotice : NSObject

@property (nonatomic, copy) NSString *bimUid;
@property (nonatomic, copy) NSString *contentString;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *imageUrl;

@end

// botim card message model
@interface GAMFUNSocialBimMessage : NSObject

@property (nonatomic, copy) NSString *bimUid;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *contentString;
@property (nonatomic, copy) NSString *imageUrl;

@end


NS_ASSUME_NONNULL_END
