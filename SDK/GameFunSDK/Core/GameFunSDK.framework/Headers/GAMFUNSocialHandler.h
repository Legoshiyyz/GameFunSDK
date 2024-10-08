//
//  GAMFUNSocialHandler.h
//  GameFunSDK
//
//  Created by Balalaika on 2020/2/21.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GameFunSDK/GAMFUNSocialPlatformProvider.h>

NS_ASSUME_NONNULL_BEGIN

@interface GAMFUNSocialHandler : NSObject <GAMFUNSocialPlatformProvider>

/**
*  Implementation of base classes for all platforms
*
*  @discuss
*  Prerequisites: need to be configured in the main project other link flag -ObjC
*  All implementations of GAMFUNSocialHandler corresponding to the platform type subclasses need to rewrite the following methods:
*
*  1.+(NSArray*) socialPlatformTypes;
*  Returns an array of corresponding platform types.
*
*  2.Rewrite the load function:
*  Example code:
*   +(void)load
*   {
*       [super load];//must call
*   }
*
*  Guaranteed to call the base class [GAMFUNSocialHandler load] after overloading
*
*  3.Rewrite the defaultManager single instance method to ensure that the defaultManager can be found at runtime to get the current single instance method, ensuring its uniqueness.
*/
#pragma mark - Subclasses that need to be overloaded

+ (void)load;

+ (NSArray*)socialPlatformTypes;

+ (instancetype)defaultManager;


#pragma mark -
@property (nonatomic, copy) NSString *appID;
@property (nonatomic, copy) NSString *appSecret;
@property (nonatomic, copy) NSString *redirectURL;


@property (nonatomic, weak) UIViewController *currentViewController;

@end

NS_ASSUME_NONNULL_END
