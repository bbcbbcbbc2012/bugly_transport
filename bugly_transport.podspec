#
#  bugly_transport.podspec
#  Bugly
#
#  Created by Hua Xiang on 2024/03/06.
#

Pod::Spec.new do |s|
    s.name             = 'bugly_transport'
    s.version          = '0.0.2'
    s.summary          = 'bugly_transport'
    s.homepage         = 'https://github.com/BuglyDevTeam'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'Bugly-Team' => 'hodxiang@tencent.com' }
    s.source           = { :git => 'https://git.woa.com/hodxiang/bugly_transport_artifact.git', :tag => s.version.to_s }

    s.ios.deployment_target = '9.0'
    s.osx.deployment_target = '11.0'

    s.library = 'z'
    s.frameworks = 'Foundation'
    s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES' }

    s.vendored_frameworks = 'bugly_transport.xcframework', "third_party/curl.xcframework"

  end