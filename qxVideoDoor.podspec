Pod::Spec.new do |spec|
  spec.name         = "qxVideoDoor"
  spec.version      = "0.0.6"
  spec.summary      = "A video open door SDK for iOS."
  spec.description  = <<-DESC
    qxVideoDoor 是一个为智能视频门铃设备设计的 iOS SDK，支持视频流播放、设备控制等功能。
  DESC
  spec.homepage     = "https://github.com/ltchen5555/videoDoor"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "itchen5555" => "longteng.chen@kingold.com" }
  spec.platform     = :ios, "14.0"
  spec.source       = { :git => "https://github.com/ltchen5555/videoDoor.git", :tag => "#{spec.version}" }
  spec.vendored_frameworks = [
    'Frameworks/JsstMediaSDK.framework',
    'Frameworks/JsstVoipSDK.framework'
  ]
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'arm64' }
  spec.frameworks   = 'AVFoundation', 'CoreMedia', 'CoreAudio', 'AudioToolbox'
  spec.requires_arc = true
  spec.swift_version = '5.0'
end
