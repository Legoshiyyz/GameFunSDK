//
//  Created by Balalaika on 2020/1/18.
//  Copyright © 2020 GMCT. All rights reserved.
//

#define IOS6 [[[UIDevice currentDevice] systemVersion] floatValue] < 7.0
#define IOS7 [[[UIDevice currentDevice] systemVersion] floatValue] < 8.0

#define MAXFLOAT    0x1.fffffep+127f

#import <GameFunSDK/GAMFUNProgressHUD.h>

#pragma mark - GAMFUNProgressHUD

/**
 *  GAMFUNHUD default setting
 *
 */
#define SETUP_GAMFUNHUD   {\
[GAMFUNProgressHUD setMinimumDismissTimeInterval:1.5];\
[GAMFUNProgressHUD setDefaultStyle:GAMFUNProgressHUDStyleCustom];\
[GAMFUNProgressHUD setBackgroundColor:[UIColor colorWithRed:(240/255.0) green:(240/255.0) blue:(240/255.0) alpha:1]];\
[GAMFUNProgressHUD setDefaultMaskType:GAMFUNProgressHUDMaskTypeClear];\
}

/**
 *  GAMFUNHUD show (Hidden by default)
 *
 */
#define GAMFUNHUD_Normal(meg)   {\
[GAMFUNProgressHUD showWithStatus:meg];\
[GAMFUNProgressHUD dismissAfterDelay:1.5];\
}

/**
 *  GAMFUNHUD show (Not hidden by default)
 *
 */
#define GAMFUNHUD_NO_Stop(meg) {\
[GAMFUNProgressHUD showWithStatus:meg];\
}

/**
 *  GAMFUNHUD hide
 *
 */
#define GAMFUNHUD_Stop dispatch_async(dispatch_get_main_queue(), ^{[GAMFUNProgressHUD dismiss];});

/**
 *  GAMFUNHUD request failed
 */
#define GAMFUNHUD_HTTP_ERROR(msg) dispatch_async(dispatch_get_main_queue(), ^{[GAMFUNProgressHUD showErrorWithStatus:msg?msg:@"Faild"];});

/**
 *  GAMFUNHUD request success
 */
#define GAMFUNHUD_HTTP_SUCCESS(msg) dispatch_async(dispatch_get_main_queue(), ^{[GAMFUNProgressHUD showSuccessWithStatus:msg?msg:@"Success"];});

/**
 *  GAMFUNHUD tips
 */
#define GAMFUNHUD_HINT(msg) dispatch_async(dispatch_get_main_queue(), ^{[GAMFUNProgressHUD showInfoWithStatus:msg];});

/**
 *  GAMFUNHUD error message
 */
#define GAMFUNHUD_ERROR(msg) dispatch_async(dispatch_get_main_queue(), ^{[GAMFUNProgressHUD showErrorWithStatus:msg];});

/**
 *  GAMFUNHUD success message
 */
#define GAMFUNHUD_SUCCESS(msg) dispatch_async(dispatch_get_main_queue(), ^{[GAMFUNProgressHUD showSuccessWithStatus:msg];});

