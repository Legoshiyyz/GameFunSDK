//
//  GAMFUNConfig.h
//  GameFunSDK
//
//  Created by Balalaika on 2020/2/1.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GameFunSDK/GAMFUNUserModel.h>
#import <GameFunSDK/GAMFUNFriendModel.h>
#import <GameFunSDK/GAMFUNPlayingFriendModel.h>
#import <GameFunSDK/GAMFUNOrderModel.h>
#import <GameFunSDK/GAMFUNSocialMessageObject.h>
#import <GameFunSDK/GAMFUNAppVersionModel.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  pay progress status enum
 */
typedef NS_ENUM(NSInteger, GAMFUNOderStatus) {
    GAMFUNOrderStatus_ProductQuerying          = 1, // order querying
    GAMFUNOrderStatus_Generating               = 2, // order init
    GAMFUNOrderStatus_Generated                = 3, // order init success
    GAMFUNOrderStatus_ProductPurchasing        = 4, // order in trading progress
    GAMFUNOrderStatus_ProductPurchased         = 5, // order purchased
    GAMFUNOrderStatus_ReceiptChecking          = 6, // order verifying
};

/**
 *  track event enum
 */
typedef NS_ENUM(NSInteger, GAMFUNTrackEvent) {
    GAMFUNTrackEvent_Activity          = 1,  // activity event
    GAMFUNTrackEvent_Guide             = 2,  // guide event
    GAMFUNTrackEvent_GuideCompletion   = 3,  // guide completion
    GAMFUNTrackEvent_Reward            = 4,  // reward event
    GAMFUNTrackEvent_Rank              = 5,  // rank event
    GAMFUNTrackEvent_VipInfo           = 6,  // vip info event
    GAMFUNTrackEvent_AdClick           = 7,  // ad click event
    GAMFUNTrackEvent_Launch            = 8,  // ad launch event
    GAMFUNTrackEvent_Login             = 9,  // ad login event
    GAMFUNTrackEvent_Purchase          = 10, // ad purchase event
    GAMFUNTrackEvent_Other             = 11, // other event
};

#define GAMFUNNotificationOrderCallBack        @"sec_club_notification_order_callback"

/**
 *  track event param keys
 */
#define GAMFUNTrackParamLaunchFirst            @"secl_launch_first"
#define GAMFUNTrackParamUserUid                @"secl_user_uid"
#define GAMFUNTrackParamUserType               @"secl_user_type"
#define GAMFUNTrackParamActivityId             @"secl_activity_id"
#define GAMFUNTrackParamActivityAction         @"secl_activity_action"

#define GAMFUNTrackParamGuideId                @"secl_tutorial_id"
#define GAMFUNTrackParamGuideSuccess           @"secl_success"
#define GAMFUNTrackParamGuideDetail            @"secl_tutorial_detail"

#define GAMFUNTrackParamRewardId               @"secl_reward_id"
#define GAMFUNTrackParamUserVip                @"secl_user_vip"
#define GAMFUNTrackParamAdId                   @"secl_ad_id"


/**
 *  The launch animation finished callback
 *
 *  @param isFinish the animation finished
 *
 */
typedef void (^GAMFUNLaunchCompletion)(BOOL isFinish);

/**
 *  Login action
 *
 *  @param actionType the action type
 *
 */
typedef void (^GAMFUNLoginAction)(GAMFUNLoginType actionType);

/**
 *  Login callback
 *
 *  @param userInfo user detail information. model class <GAMFUNUserModel>
 *  @param error error message
 */
typedef void (^GAMFUNUserCompletionHandler)(id _Nullable userInfo, NSError *_Nullable error);

/**
 *  Social platform authorization callback
 *
 *  @param loginResult platform authorization information. result class <NSDictionary>
 *  @param error error message
 */
typedef void (^GAMFUNSocialPlateLoginCompletionHandler)(id _Nullable loginResult, NSError *_Nullable error);

/**
 *  Social platform cancels the authorization operation callback
 *
 *  @param logoutResult unauthorization infomation. result class <NSDictionary>
 *  @param error error message
 */
typedef void (^GAMFUNSocialPlateLogoutCompletionHandler)(id _Nullable logoutResult, NSError *_Nullable error);

/**
 *  Recieve notification callbackd
 *
 *  @param result notification result
 *  @param error error message
 */
typedef void (^GAMFUNNotificationCompletionHandler)(id _Nullable result, NSError *_Nullable error);

/**
 *  Using the system album select photos callback
 *
 *  @param mediaInfo selected media information. result class <NSDictionary>
 *  mediaInfo:
 *   keys            values
 *  MediaType       <NSString>   eg. Photo：public.image  Video：public.movie
 *  ImageURL        <NSURL>
 *  OriginalImage   <UIImage>
 *  ReferenceURL    <NSURL>      an NSURL that references an asset
 *
 *  @param error error message
 */
typedef void (^GAMFUNSocialSystemPhotoCompletionHandler)(id _Nullable mediaInfo, NSError *_Nullable error);

/**
 *  Logout callback
 *
 *  @param success <BOOL>
 *  @param error error message
 */
typedef void (^GAMFUNLogoutCompleteHandler)(BOOL success, NSError *_Nullable error);

/**
 *  Delete account callback
 *
 *  @param success <BOOL>
 *  @param error error message
 */
typedef void (^GAMFUNDeleteCompleteHandler)(BOOL success, NSError *_Nullable error);

/**
 *  Account Kicked Notification
 *
 *  @param information notification message
 */
typedef void (^GAMFUNAccountKickedHandler)(NSString *_Nullable information);

/**
 *  Account Banned Notification
 *
 *  @param information reason message
 *  @param time banned time （timestamp）
 */
typedef void (^GAMFUNAccountBannedHandler)(NSString *_Nullable information, NSString *_Nullable time);

/**
 *  TTk Friends list callback
 *
 *  @param list <NSArray>
 *  @param error error message
 */
typedef void (^GAMFUNTTkFriendsCompletionHandler)(id _Nullable list, NSError *_Nullable error);

/**
 *  Botim Friends list callback
 *
 *  @param list <NSArray>
 *  @param error error message
 */
typedef void (^GAMFUNBimFriendsCompletionHandler)(id _Nullable list, NSError *_Nullable error);

/**
 *  Share callback
 *
 *  @param success <BOOL>
 *  @param error error message
 */
typedef void (^GAMFUNShareCompleteHandler)(BOOL success, NSError *_Nullable error);

/**
 *  Universal Link Handle
 *
 *  @param url url of link
 *  @param error error message
 */
typedef void (^GAMFUNUniversalLinkHandler)(NSURL *url, NSError *_Nullable error);

/**
 *  Pay progress status callback
 *
 *  @param orderStatus <NS_ENUM>
 */
typedef void (^GAMFUNOrderProgressHandler)(GAMFUNOderStatus orderStatus);

/**
 *  Pay result callback
 *
 *  @param orderInfo order detail information
 *  @param error error message
 */
typedef void (^GAMFUNOrderCompletionHandler)(id _Nullable orderInfo, NSError *_Nullable error);

/**
 *  Product detail callback
 *
 *  @param productInfo product detail information
 *  @param error error message
 */
typedef void (^GAMFUNProductCompletionHandler)(id _Nullable productInfo, NSError *_Nullable error);

/**
 *  Get version info callback
 *
 *  @param hasNewVersion has new version
 *  @param versionInfo the version detail information. class model <GAMFUNAppVersion>
 *  @param error error message
 */
typedef void (^GAMFUNVersionCompletionHandler)(BOOL hasNewVersion, GAMFUNAppVersionModel *_Nullable versionInfo, NSError *_Nullable error);

/**
 *  Common result callback
 *
 *  @param result common result
 *  @param error error message
 */
typedef void (^GAMFUNCompletionHandler)(id _Nullable result, NSError *_Nullable error);


/////////////////////////////////////////////////////////////////////////////
//Platform error code --start
/////////////////////////////////////////////////////////////////////////////
/**
 *  Error Type
 */
typedef NS_ENUM(NSInteger, GAMFUNPlatformErrorType) {
    GAMFUNPlatformErrorType_Unknow              = 2000,             // unknow error
    GAMFUNPlatformErrorType_AuthorizeFailed     = 2001,             // authorization failed
    GAMFUNPlatformErrorType_ForUserInfoFailed   = 2002,             // get user information failed
    GAMFUNPlatformErrorType_LoginFailed         = 2003,             // login failed
    GAMFUNPlatformErrorType_FriendsListFailed   = 2004,             // get friends list failed
    GAMFUNPlatformErrorType_MessageSendFailed   = 2005,             // send message failed
    GAMFUNPlatformErrorType_PayFailed           = 2006,             // pay failed
    GAMFUNPlatformErrorType_ShareFailed         = 2007,             // share failed
    GAMFUNPlatformErrorType_NotInstall          = 2008,             // the application uninstall
    GAMFUNPlatformErrorType_NotNetWork          = 2009,             // net work error
    GAMFUNPlatformErrorType_SourceError         = 2010,             // third error
    GAMFUNPlatformErrorType_NoPermission        = 2011,             // no permissions
    GAMFUNPlatformErrorType_UnauthorizedRequest = 2012,             // unauthorized request, need login.
};

/** The domain name used for the GAMFUNPlatformErrorType */
extern NSString* const GAMFUNPlatformErrorDomain;

/////////////////////////////////////////////////////////////////////////////
//Platform error code --end
/////////////////////////////////////////////////////////////////////////////


@interface GAMFUNConfig : NSObject

/**
 *  Create an error object
 *
 *  @param errorType Error type
 *  @param userInfo  Customized error message
 *
 *  @return   Returns an object of type NSError
 */
+ (NSError *)errorWithGAMFUNErrorType:(GAMFUNPlatformErrorType)errorType userInfo:(id)userInfo;

@end


NS_ASSUME_NONNULL_END
