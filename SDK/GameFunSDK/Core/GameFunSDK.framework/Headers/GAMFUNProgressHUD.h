//
//  GAMFUNProgressHUD.h
//  GAMFUNProgressHUD
//
//  Created by Balalaika on 2020/1/18.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AvailabilityMacros.h>

extern NSString * _Nonnull const GAMFUNProgressHUDDidReceiveTouchEventNotification;
extern NSString * _Nonnull const GAMFUNProgressHUDDidTouchDownInsideNotification;
extern NSString * _Nonnull const GAMFUNProgressHUDWillDisappearNotification;
extern NSString * _Nonnull const GAMFUNProgressHUDDidDisappearNotification;
extern NSString * _Nonnull const GAMFUNProgressHUDWillAppearNotification;
extern NSString * _Nonnull const GAMFUNProgressHUDDidAppearNotification;

extern NSString * _Nonnull const GAMFUNProgressHUDStatusUserInfoKey;

typedef NS_ENUM(NSInteger, GAMFUNProgressHUDStyle) {
    GAMFUNProgressHUDStyleLight NS_SWIFT_NAME(light),   // default style, white HUD with black text, HUD background will be blurred
    GAMFUNProgressHUDStyleDark NS_SWIFT_NAME(dark),     // black HUD and white text, HUD background will be blurred
    GAMFUNProgressHUDStyleCustom NS_SWIFT_NAME(custom)  // uses the fore- and background color properties
};

typedef NS_ENUM(NSUInteger, GAMFUNProgressHUDMaskType) {
    GAMFUNProgressHUDMaskTypeNone NS_SWIFT_NAME(none) = 1,      // default mask type, allow user interactions while HUD is displayed
    GAMFUNProgressHUDMaskTypeClear NS_SWIFT_NAME(clear),        // don't allow user interactions with background objects
    GAMFUNProgressHUDMaskTypeBlack NS_SWIFT_NAME(black),        // don't allow user interactions with background objects and dim the UI in the back of the HUD (as seen in iOS 7 and above)
    GAMFUNProgressHUDMaskTypeGradient NS_SWIFT_NAME(gradient),  // don't allow user interactions with background objects and dim the UI with a a-la UIAlertView background gradient (as seen in iOS 6)
    GAMFUNProgressHUDMaskTypeCustom NS_SWIFT_NAME(custom)       // don't allow user interactions with background objects and dim the UI in the back of the HUD with a custom color
};

typedef NS_ENUM(NSUInteger, GAMFUNProgressHUDAnimationType) {
    GAMFUNProgressHUDAnimationTypeFlat NS_SWIFT_NAME(flat),     // default animation type, custom flat animation (indefinite animated ring)
    GAMFUNProgressHUDAnimationTypeNative NS_SWIFT_NAME(native)  // iOS native UIActivityIndicatorView
};

typedef void (^GAMFUNProgressHUDShowCompletion)(void);
typedef void (^GAMFUNProgressHUDDismissCompletion)(void);

@interface GAMFUNProgressHUD : UIView

#pragma mark - Customization

@property (assign, nonatomic) GAMFUNProgressHUDStyle defaultStyle UI_APPEARANCE_SELECTOR;                   // default is GAMFUNProgressHUDStyleLight
@property (assign, nonatomic) GAMFUNProgressHUDMaskType defaultMaskType UI_APPEARANCE_SELECTOR;             // default is GAMFUNProgressHUDMaskTypeNone
@property (assign, nonatomic) GAMFUNProgressHUDAnimationType defaultAnimationType UI_APPEARANCE_SELECTOR;   // default is GAMFUNProgressHUDAnimationTypeFlat
@property (strong, nonatomic, nullable) UIView *containerView;                                          // if nil then use default window level
@property (assign, nonatomic) CGSize minimumSize UI_APPEARANCE_SELECTOR;                        // default is CGSizeZero, can be used to avoid resizing for a larger message
@property (assign, nonatomic) CGFloat ringThickness UI_APPEARANCE_SELECTOR;                     // default is 2 pt
@property (assign, nonatomic) CGFloat ringRadius UI_APPEARANCE_SELECTOR;                        // default is 18 pt
@property (assign, nonatomic) CGFloat ringNoTextRadius UI_APPEARANCE_SELECTOR;                  // default is 24 pt
@property (assign, nonatomic) CGFloat cornerRadius UI_APPEARANCE_SELECTOR;                      // default is 14 pt
@property (strong, nonatomic, nonnull) UIFont *font UI_APPEARANCE_SELECTOR;                     // default is [UIFont preferredFontForTextStyle:UIFontTextStyleSubheadline]
@property (strong, nonatomic, nonnull) UIColor *backgroundColor UI_APPEARANCE_SELECTOR;         // default is [UIColor whiteColor]
@property (strong, nonatomic, nonnull) UIColor *foregroundColor UI_APPEARANCE_SELECTOR;         // default is [UIColor blackColor]
@property (strong, nonatomic, nullable) UIColor *foregroundImageColor UI_APPEARANCE_SELECTOR;   // default is the same as foregroundColor
@property (strong, nonatomic, nonnull) UIColor *backgroundLayerColor UI_APPEARANCE_SELECTOR;    // default is [UIColor colorWithWhite:0 alpha:0.4]
@property (assign, nonatomic) CGSize imageViewSize UI_APPEARANCE_SELECTOR;                      // default is 28x28 pt
@property (assign, nonatomic) BOOL shouldTintImages UI_APPEARANCE_SELECTOR;                     // default is YES
@property (strong, nonatomic, nonnull) UIImage *infoImage UI_APPEARANCE_SELECTOR;               // default is the bundled info image provided by Freepik
@property (strong, nonatomic, nonnull) UIImage *successImage UI_APPEARANCE_SELECTOR;            // default is the bundled success image provided by Freepik
@property (strong, nonatomic, nonnull) UIImage *errorImage UI_APPEARANCE_SELECTOR;              // default is the bundled error image provided by Freepik
@property (strong, nonatomic, nonnull) UIView *viewForExtension UI_APPEARANCE_SELECTOR;         // default is nil, only used if #define GAMFUN_APP_EXTENSIONS is set
@property (assign, nonatomic) NSTimeInterval graceTimeInterval;                                 // default is 0 seconds
@property (assign, nonatomic) NSTimeInterval minimumDismissTimeInterval;                        // default is 5.0 seconds
@property (assign, nonatomic) NSTimeInterval maximumDismissTimeInterval;                        // default is CGFLOAT_MAX

@property (assign, nonatomic) UIOffset offsetFromCenter UI_APPEARANCE_SELECTOR; // default is 0, 0

@property (assign, nonatomic) NSTimeInterval fadeInAnimationDuration UI_APPEARANCE_SELECTOR;    // default is 0.15
@property (assign, nonatomic) NSTimeInterval fadeOutAnimationDuration UI_APPEARANCE_SELECTOR;   // default is 0.15

@property (assign, nonatomic) UIWindowLevel maxSupportedWindowLevel; // default is UIWindowLevelNormal

@property (assign, nonatomic) BOOL hapticsEnabled;      // default is NO
@property (assign, nonatomic) BOOL motionEffectEnabled; // default is YES

+ (void)setDefaultStyle:(GAMFUNProgressHUDStyle)style;                      // default is GAMFUNProgressHUDStyleLight
+ (void)setDefaultMaskType:(GAMFUNProgressHUDMaskType)maskType;             // default is GAMFUNProgressHUDMaskTypeNone
+ (void)setDefaultAnimationType:(GAMFUNProgressHUDAnimationType)type;       // default is GAMFUNProgressHUDAnimationTypeFlat
+ (void)setContainerView:(nullable UIView*)containerView;               // default is window level
+ (void)setMinimumSize:(CGSize)minimumSize;                             // default is CGSizeZero, can be used to avoid resizing for a larger message
+ (void)setRingThickness:(CGFloat)ringThickness;                        // default is 2 pt
+ (void)setRingRadius:(CGFloat)radius;                                  // default is 18 pt
+ (void)setRingNoTextRadius:(CGFloat)radius;                            // default is 24 pt
+ (void)setCornerRadius:(CGFloat)cornerRadius;                          // default is 14 pt
+ (void)setBorderColor:(nonnull UIColor*)color;                         // default is nil
+ (void)setBorderWidth:(CGFloat)width;                                  // default is 0
+ (void)setFont:(nonnull UIFont*)font;                                  // default is [UIFont preferredFontForTextStyle:UIFontTextStyleSubheadline]
+ (void)setForegroundColor:(nonnull UIColor*)color;                     // default is [UIColor blackColor], only used for GAMFUNProgressHUDStyleCustom
+ (void)setForegroundImageColor:(nullable UIColor*)color;               // default is nil == foregroundColor, only used for GAMFUNProgressHUDStyleCustom
+ (void)setBackgroundColor:(nonnull UIColor*)color;                     // default is [UIColor whiteColor], only used for GAMFUNProgressHUDStyleCustom
+ (void)setHudViewCustomBlurEffect:(nullable UIBlurEffect*)blurEffect;  // default is nil, only used for GAMFUNProgressHUDStyleCustom, can be combined with backgroundColor
+ (void)setBackgroundLayerColor:(nonnull UIColor*)color;                // default is [UIColor colorWithWhite:0 alpha:0.5], only used for GAMFUNProgressHUDMaskTypeCustom
+ (void)setImageViewSize:(CGSize)size;                                  // default is 28x28 pt
+ (void)setShouldTintImages:(BOOL)shouldTintImages;                     // default is YES
+ (void)setInfoImage:(nonnull UIImage*)image;                           // default is the bundled info image provided by Freepik
+ (void)setSuccessImage:(nonnull UIImage*)image;                        // default is the bundled success image provided by Freepik
+ (void)setErrorImage:(nonnull UIImage*)image;                          // default is the bundled error image provided by Freepik
+ (void)setViewForExtension:(nonnull UIView*)view;                      // default is nil, only used if #define GAMFUN_APP_EXTENSIONS is set
+ (void)setGraceTimeInterval:(NSTimeInterval)interval;                  // default is 0 seconds
+ (void)setMinimumDismissTimeInterval:(NSTimeInterval)interval;         // default is 5.0 seconds
+ (void)setMaximumDismissTimeInterval:(NSTimeInterval)interval;         // default is infinite
+ (void)setFadeInAnimationDuration:(NSTimeInterval)duration;            // default is 0.15 seconds
+ (void)setFadeOutAnimationDuration:(NSTimeInterval)duration;           // default is 0.15 seconds
+ (void)setMaxSupportedWindowLevel:(UIWindowLevel)windowLevel;          // default is UIWindowLevelNormal
+ (void)setHapticsEnabled:(BOOL)hapticsEnabled;						    // default is NO
+ (void)setMotionEffectEnabled:(BOOL)motionEffectEnabled;               // default is YES

#pragma mark - Show Methods

+ (void)show;
+ (void)showWithMaskType:(GAMFUNProgressHUDMaskType)maskType __attribute__((deprecated("Use show and setDefaultMaskType: instead.")));
+ (void)showWithStatus:(nullable NSString*)status;
+ (void)showWithStatus:(nullable NSString*)status maskType:(GAMFUNProgressHUDMaskType)maskType __attribute__((deprecated("Use showWithStatus: and setDefaultMaskType: instead.")));

+ (void)showProgress:(float)progress;
+ (void)showProgress:(float)progress maskType:(GAMFUNProgressHUDMaskType)maskType __attribute__((deprecated("Use showProgress: and setDefaultMaskType: instead.")));
+ (void)showProgress:(float)progress status:(nullable NSString*)status;
+ (void)showProgress:(float)progress status:(nullable NSString*)status maskType:(GAMFUNProgressHUDMaskType)maskType __attribute__((deprecated("Use showProgress:status: and setDefaultMaskType: instead.")));

+ (void)setStatus:(nullable NSString*)status; // change the HUD loading status while it's showing

// stops the activity indicator, shows a glyph + status, and dismisses the HUD a little bit later
+ (void)showInfoWithStatus:(nullable NSString*)status;
+ (void)showInfoWithStatus:(nullable NSString*)status maskType:(GAMFUNProgressHUDMaskType)maskType __attribute__((deprecated("Use showInfoWithStatus: and setDefaultMaskType: instead.")));
+ (void)showSuccessWithStatus:(nullable NSString*)status;
+ (void)showSuccessWithStatus:(nullable NSString*)status maskType:(GAMFUNProgressHUDMaskType)maskType __attribute__((deprecated("Use showSuccessWithStatus: and setDefaultMaskType: instead.")));
+ (void)showErrorWithStatus:(nullable NSString*)status;
+ (void)showErrorWithStatus:(nullable NSString*)status maskType:(GAMFUNProgressHUDMaskType)maskType __attribute__((deprecated("Use showErrorWithStatus: and setDefaultMaskType: instead.")));

// shows a image + status, use white PNGs with the imageViewSize (default is 28x28 pt)
+ (void)showImage:(nonnull UIImage*)image status:(nullable NSString*)status;
+ (void)showImage:(nonnull UIImage*)image status:(nullable NSString*)status maskType:(GAMFUNProgressHUDMaskType)maskType __attribute__((deprecated("Use showImage:status: and setDefaultMaskType: instead.")));

+ (void)setOffsetFromCenter:(UIOffset)offset;
+ (void)resetOffsetFromCenter;

+ (void)popActivity; // decrease activity count, if activity count == 0 the HUD is dismissed
+ (void)dismiss;
+ (void)dismissWithCompletion:(nullable GAMFUNProgressHUDDismissCompletion)completion;
+ (void)dismissWithDelay:(NSTimeInterval)delay;
+ (void)dismissWithDelay:(NSTimeInterval)delay completion:(nullable GAMFUNProgressHUDDismissCompletion)completion;

+ (BOOL)isVisible;

+ (NSTimeInterval)displayDurationForString:(nullable NSString*)string;

@end

