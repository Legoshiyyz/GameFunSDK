Pod::Spec.new do |spec|

  spec.name         = "GameFunSDK"
  spec.version      = "1.0.0"
  spec.summary      = "GameFunSDK for games"
  
  spec.description  = <<-DESC
  GameFunSDK for games
  Convenient game access
  DESC

  spec.homepage     = "https://github.com/Legoshiyyz/GameFunSDK"

  spec.license      = { :type => "MIT" }

  spec.author             = "GameFun Team"
  
  spec.platform     = :ios, "11.0"
  spec.ios.deployment_target = "11.0"
  
  spec.source       = { :git => "https://github.com/Legoshiyyz/GameFunSDK.git", :tag => "1.0.0" }

  spec.requires_arc = true
  spec.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  
  #是否使用静态库。如果podfile指明了use_frameworks!命令，但是pod仓库需要使用静态库则需要设置
  spec.static_framework = true
  spec.libraries = 'sqlite3'
  spec.frameworks = 'UIKit', 'StoreKit', 'GameKit', 'WebKit', 'UserNotifications', 'Photos', 'ImageIO', 'Foundation', 'CoreFoundation', 'QuartzCore', 'CoreGraphics', 'AVFoundation', 'CoreTelephony', 'Security', 'AuthenticationServices'
    
  spec.subspec 'Core' do |cr|
      cr.vendored_framework = 'SDK/GameFunSDK/Core/GameFunSDK.framework'
      cr.resources = 'SDK/GameFunSDK/Core/GAMFUN_ICON_B.bundle','SDK/GameFunSDK/Core/GAMFUN_ICON_ProgressHUD.bundle','SDK/GameFunSDK/Core/GAMFUN_DACON.bundle'
  end

  spec.subspec 'CustomUI' do |cu|
      cu.dependency 'IQKeyboardManager'
      cu.dependency 'GameFunSDK/Core'
  end
  
  # spec.subspec 'Facebook' do |fb|
  #     fb.source_files = 'SDK/GameFunSDK/SocialLibraries/Facebook'
  #     fb.vendored_library = 'SDK/GameFunSDK/SocialLibraries/Facebook/libGAMFUNSocialFacebook.a'
  #     fb.dependency 'FBSDKCoreKit'
  #     fb.dependency 'FBSDKLoginKit'
  #     fb.dependency 'FBSDKShareKit'
  #     fb.dependency 'GameFunSDK/Core'
  # end
  
  # spec.subspec 'Twitter' do |tt|
  #     tt.source_files = 'SDK/GameFunSDK/SocialLibraries/GAMFUNSocialTwitter'
  #     tt.vendored_library = 'SDK/GameFunSDK/SocialLibraries/GAMFUNSocialTwitter/libGAMFUNSocialTwitter.a'
  #     tt.dependency 'TwitterKit5', '~> 5.2.0'
  #     tt.dependency 'GameFunSDK/Core'
  # end
  
  spec.subspec 'Analytics' do |analy|
      analy.source_files = 'SDK/GameFunSDK/SocialLibraries/GAMFUNAnalytics'
      analy.vendored_library = 'SDK/GameFunSDK/SocialLibraries/GAMFUNAnalytics/libGAMFUNAnalytics.a'
      analy.dependency 'Firebase/Analytics'
      analy.dependency 'Firebase/DynamicLinks'
      analy.dependency 'Firebase/Auth'
      analy.dependency 'GoogleSignIn', '~> 6.2.2'
      analy.dependency 'GameFunSDK/Core'
  end
  
  # spec.subspec 'AppsFlyer' do |af|
  #     af.source_files = 'SDK/GameFunSDK/SocialLibraries/GAMFUNAppsFlyer'
  #     af.vendored_library = 'SDK/GameFunSDK/SocialLibraries/GAMFUNAppsFlyer/libGAMFUNAppsFlyer.a'
  #     af.dependency 'AppsFlyerFramework'
  #     af.dependency 'GameFunSDK/Core'
  # end
  
  # spec.subspec 'Tapjoy' do |tg|
  #     tg.source_files = 'SDK/GameFunSDK/SocialLibraries/GAMFUNTapjoy'
  #     tg.vendored_library = 'SDK/GameFunSDK/SocialLibraries/GAMFUNTapjoy/libGAMFUNTapjoy.a'
  #     tg.dependency 'TapjoySDK'
  #     tg.dependency 'GameFunSDK/Core'
  # end

end
