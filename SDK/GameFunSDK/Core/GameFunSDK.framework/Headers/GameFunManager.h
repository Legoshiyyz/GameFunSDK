//
//  TTkGameManager.h
//  GameFunSDK
//
//  Created by Balalaika on 2020/1/21.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GameFunSDK/GAMFUNConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface GameFunManager : NSObject

+ (instancetype)defaultManager;

/**
 Initialization
 */
- (void)setupWithAppId:(NSString *)appid Secret:(NSString *)secret GameId:(NSString *)gameid Application:(UIApplication *)application Options:(NSDictionary *)launchOptions;

- (void)applicationDidEnterBackground:(UIApplication *)application;
- (void)applicationWillEnterForeground:(UIApplication *)application;
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (void)applicationWillTerminate:(UIApplication *)application;

/**
 Launch Animation
 Start the default animation, use it selectively, and don't care if you implement it.
 */
- (void)launchAnimationCompletion:(GAMFUNLaunchCompletion)completion;

/**
 Initialization of apns
 */
- (void)setupAPNS;

#pragma mark - Login

/**
 Login with UI
 */
- (void)loginWithCustomUICompletion:(GAMFUNUserCompletionHandler)completion;
- (void)loginWithCustomUIWithRootController:(UIViewController *)root Completion:(GAMFUNUserCompletionHandler)completion;

/**
 Login User Type
 */
- (GAMFUNLoginType)loginType;

/**
 Login User Information(Model data is only available when logged in.)
 */
- (GAMFUNUserModel *)loginUserModel;

/**
 AccessToken is only available when logged in.
 */
- (void)getAvailableAccessToken:(GAMFUNUserCompletionHandler)completion;

/**
 Botim Login
 
 @param completion login callback
 */
- (void)loginWithBotimCompletion:(GAMFUNUserCompletionHandler)completion;

/**
 Botim is install
*/
- (BOOL)botimIsInstall;

//login
- (void)loginWithTTkCompletion:(GAMFUNUserCompletionHandler)completion;

/**
 Apple Login
 
 @param completion login callback
 */
- (void)loginWithAppleCompletion:(GAMFUNUserCompletionHandler)completion;

/**
 Gamecenter Login
 
 @param completion login callback
 */
- (void)loginWithGameCenterCompletion:(GAMFUNUserCompletionHandler)completion;

/**
 Facebook Login
 
 @param completion login callback
 */
- (void)loginWithFacebookCompletion:(GAMFUNUserCompletionHandler)completion;

/**
 Google Login
 
 @param completion login callback
 */
- (void)loginWithGoogleCompletion:(GAMFUNUserCompletionHandler)completion;

/**
 Twitter Login
 
 @param completion login callback
 */
- (void)loginWithTwitterCompletion:(GAMFUNUserCompletionHandler)completion;

/**
 Third-party callback（Must be implemented in AppDelegate）
 */
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

/**
 Guests Login
 
 @param completion login callback
 */
- (void)guestLoginCompletion:(GAMFUNUserCompletionHandler)completion;

/**
 Get User Information
 
 @param completion user information callback
 */
- (void)userInfoCompletion:(GAMFUNUserCompletionHandler)completion;

/**
 Logout
 
 @param completion logout reult
 */
- (void)logout:(GAMFUNLogoutCompleteHandler)completion;

/**
 Delete Account
 
 @param completion delete reult
 */
- (void)deleteAccount:(GAMFUNDeleteCompleteHandler)completion;

/**
 Get Mig Code
 
 @param completion migCode
 */
- (void)getMigCode:(GAMFUNCompletionHandler)completion;

/**
 Notification of account being kicked out
 
 @param handler notification information
 */
- (void)accountKickedNotification:(GAMFUNAccountKickedHandler)handler;

/**
 Notification of account being banned
 
 @param handler notification information
 */
- (void)accountBannedNotification:(GAMFUNAccountBannedHandler)handler;

#pragma mark - Share

/**
 *  FB share
 *
 *  @param messageObject  share content type @see GAMFUNSocialFBLink GAMFUNSocialFBImages
 *  @param completion   callback
 */
- (void)facebookShareMessage:(id)messageObject completion:(GAMFUNShareCompleteHandler)completion;

/**
 *  WhatsApp share
 *
 *  @param messageObject  share content type @see GAMFUNSocialWALink GAMFUNSocialWAImages
 *  @param completion   callback
 */
- (void)whatsAppShareMessage:(id)messageObject completion:(GAMFUNShareCompleteHandler)completion;

/**
 *  Use System Album
 *
 *  @param completion   callback
 *  callback data @GAMFUNSocialSystemPhotoCompletionHandler
 */
- (void)openSystemPhotoCompletion:(GAMFUNSocialSystemPhotoCompletionHandler)completion;

/**
*  share message
*
*  @param message  share content type @see GAMFUNSocialTTkInvite & GAMFUNSocialTTkNotice
*  @param completion   callback
*/
- (void)sendToMessageTottk:(id)message Completion:(GAMFUNShareCompleteHandler)completion;

/**
*  botim share
*
*  @param message  share content type @see GAMFUNSocialBimMessage
*  @param completion   callback
*/
- (void)sendToMessageToBotim:(id)message Completion:(GAMFUNShareCompleteHandler)completion;


#pragma mark - Push Notification

/**
 Recieve deviceToken（Must be implemented in AppDelegate）
 
 @param token apns return the token
 */
- (void)registerDeviceToken:(NSData *)token;

/**
 Remove all notifications
 */
- (void)cleanNotification;

/**
 Receive remote notifications
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;

/**
 Get remote notification information
 */
- (void)getRemoteNotification:(GAMFUNNotificationCompletionHandler)completion;

/**
 Set whether users receive pushes
 
 @param pushOn YES:open push NO:close push
 @param handler return the setting result YES:success NO:failure
 */
- (void)settingPush:(BOOL)pushOn Result:(void(^)(BOOL success))handler;

/**
 Determine if system push is on
 
 @param handler The return value is a boolean YES:Notification turned on, NO:Notification closed
 */
- (void)checkSystemNotificationEnable:(void(^)(BOOL isOn))handler;

/**
 Open system notification settings page
 */
- (void)systemNotificationSetting;

#pragma mark - TTk消息

/**
Get friends list from server

@param completion friends list callback
*/
- (void)getFriendsFromServerCompletion:(GAMFUNTTkFriendsCompletionHandler)completion;

/**
Get playing friends list from server

@param completion friends list callback
*/
- (void)getPlayingFriendsFromServerCompletion:(GAMFUNTTkFriendsCompletionHandler)completion;


#pragma mark - Botim

/**
 Get botim friends list from server
 
 @param completion friends list callback
 */
- (void)getFriendsFromBotimCompletion:(GAMFUNBimFriendsCompletionHandler)completion;

/**
 Get botim playing friends list from server
 
 @param completion friends list callback
 */
- (void)getPlayingFriendsFromBotimCompletion:(GAMFUNBimFriendsCompletionHandler)completion;


#pragma mark - Pay

/**
 Product
 
 @param sku goods ID
 @param completion product detail completion callback
 */
- (void)getProductDetailWithSKU:(NSString *)sku Completion:(GAMFUNProductCompletionHandler)completion;

/**
 Purchase (The following new method with name parameter is recommended.)
 
 @param sku goods ID
 @param progress Purchase process callback
 @param completion Purchase completion callback
 */
- (void)buyProductWithSKU:(NSString *)sku Progress:(GAMFUNOrderProgressHandler)progress Completion:(GAMFUNOrderCompletionHandler)completion;

/**
 Purchase (recommended)
 
 @param sku goods ID
 @param name goods name
 @param progress Purchase process callback
 @param completion Purchase completion callback
 */
- (void)buyProductWithSKU:(NSString *)sku WithName:(NSString *)name Progress:(GAMFUNOrderProgressHandler)progress Completion:(GAMFUNOrderCompletionHandler)completion;

/**
 
 @param sku goods ID
 @param currency pay currency
 @param completion Purchase completion callback
 */
- (void)xslBuyProductWithSKU:(NSString *)sku Currency:(NSString *)currency Completion:(GAMFUNOrderCompletionHandler)completion;

/**
 Purchase (Selector)
 
 @param sku goods ID
 @param name goods name
 @param currency pay currency
 @param completion Purchase completion callback
 */
- (void)selectBWithProductSKU:(NSString *)sku Name:(NSString *)name Currency:(NSString *)currency Completion:(GAMFUNOrderCompletionHandler)completion;

/**
 Purchase (Selector)
 
 @param sku goods ID
 @param name goods name
 @param currency pay currency
 @param gameOrder game order ID
 @param progress Purchase process callback
 @param completion Purchase completion callback
 */
- (void)selectBWithProductSKU:(NSString *)sku
                         Name:(NSString *)name
                     Currency:(NSString *)currency
                    GameOrder:(NSString *)gameOrder
                     Progress:(GAMFUNOrderProgressHandler)progress
                   Completion:(GAMFUNOrderCompletionHandler)completion;

- (NSString *)getCurrentOrderID;

/**
 Checking Order
 
 @param orderID order id
 @param completion search result, callback to return order information
 */
- (void)queryOrderWithOrderId:(NSString *)orderID Completion:(GAMFUNOrderCompletionHandler)completion;

#pragma mark - Configuration information

/**
 Get User Agreement URL
 */
- (NSString *)getAgreementUrlString;

/**
 Open Agreement View
 */
- (void)showAgreementView;

/**
 Open Mig View
 */
- (void)showMigView;

/**
 setup mig code
 */
- (void)setupMigCode:(NSString *)code;


#pragma mark - SDK Configuration

#pragma - Configure the domain
/**
 Switch SDK server environment
 */
- (void)setServerDomainTest;//test environment
- (void)setServerDomainProduction;//production environment
- (void)setSDKServerDomain:(NSString *)domain;
- (void)setSDKDevelopServerDomain:(NSString *)domain;

/**
 Get the current SDK server domain
 */
- (NSString *)SDKServerDomain;

#pragma - Log Information
/**
 Log information output. open & close
 */
- (void)openLogInfo;
- (void)closeLogInfo;

#pragma - Environment
/**
 set env
 */
- (void)setPEnvTest;//test environment
- (void)setPEnvProduction;//production environment
- (int)getPEnv;//1 production   2 test

#pragma mark - App Update
/**
 Get app version info
 
 @param completion version info callback
 */
- (void)checkAppVersionCompletion:(GAMFUNVersionCompletionHandler)completion;

/**
 Open appstore show details of app.
 
 @param identifier App Store item identifier (NSNumber) of the product
 */
- (void)openAppStoreWithStoreIdentifier:(NSString *)identifier;

#pragma mark - Universal Link

- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler;

#pragma mark - af track

/**
Track

@param event track event type (GAMFUNTrackEvent)
@param values event params
*/
- (void)tracker_event:(GAMFUNTrackEvent)event withValues:(NSDictionary * _Nullable)values;

/**
Track

@param event track event name (NSString)
@param values event params
*/
- (void)tracker_eventName:(NSString *)event withValues:(NSDictionary * _Nullable)values;

/**
 Contact us
 
 Contact us with messenger app.
*/
- (void)contactusWithMessenger;

@end

NS_ASSUME_NONNULL_END
