//
//  GAMFUNUserModel.h
//  GameFunSDK
//
//  Created by Balalaika on 2020/2/16.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  User Type
 */
typedef NS_ENUM(NSInteger, GAMFUNLoginType) {
    GAMFUNLoginType_unloggedIn       = 0,             // unlogin
    GAMFUNLoginType_TTk              = 1,             // TTk user
    GAMFUNLoginType_GameCenter       = 2,             // GameCenter user
    GAMFUNLoginType_Facebook         = 3,             // Facebook user
    GAMFUNLoginType_Guest            = 4,             // Guest user
    GAMFUNLoginType_Apple            = 5,             // Apple user
    GAMFUNLoginType_Twitter          = 6,             // Twitter user
    GAMFUNLoginType_Botim            = 7,             // Botim user
    GAMFUNLoginType_Google           = 8,             // Google user
    GAMFUNLoginType_Custom           = 9,             // custom user
};

NS_ASSUME_NONNULL_BEGIN

@interface GAMFUNUserModel : NSObject

@property (nonatomic) GAMFUNLoginType userType; //user type
@property (nonatomic, copy) NSString *userId; //TTkGame userid
@property (nonatomic, copy) NSString *thirdUid; //third-party uid
@property (nonatomic, copy) NSString *accessToken; //TTkGame authorization token
@property (nonatomic, copy) NSString *nickname; //nick name
@property (nonatomic, copy) NSString *openId; //custom name
@property (nonatomic, copy) NSString *photoUrl; //photo
@property (nonatomic, copy) NSString *pushOff;

@end

NS_ASSUME_NONNULL_END
