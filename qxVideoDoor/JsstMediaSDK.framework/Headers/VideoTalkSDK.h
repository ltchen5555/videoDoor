//
//  VideoTalkSDK.h
//  JSH3
//
//  Created by K on 17/3/21.
//  Copyright © 2017年 jieshun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class VideoTalkSDK;
@protocol VideoTalkSDKDelete <NSObject>

/*
    deviceId: 连接的设备的对讲id
    resultCode： 2001:登录成功
                2002:登录失败
                2003:对讲成功
                2004:对讲失败
                2005:已登录
                1001:设备未注册
                1002:设备忙
                1003:响应超时
                1004:通讯异常
                1005:设备离线
                1006:未收到视频流
                1007:未收到音频流
                1011:设备离线
                1012:设备不存在
 */
-(void)VideoTalkSDKDeleteError:(VideoTalkSDK *)VideoTalk deviceId:(NSString*)deviceId errorResultCode:(NSString *)resultCode;

/*
    deviceId: 连接的设备的对讲id
    resultCode： 2101:注册成功
                2102:注册失败
                2103:对讲成功
                2104:对讲失败
                2105:对讲超时
                2106:媒体ID冲突
 */
-(void)VideoTalkSDKDeleteError_V2:(VideoTalkSDK *)VideoTalk deviceId:(NSString*)deviceId errorResultCode:(NSString *)resultCode;

@end

@interface VideoTalkSDK : NSObject

@property(nonatomic,weak) id<VideoTalkSDKDelete> delegate;

#pragma mark - 初始化
/*
 *  初始化登录
 */
-(NSInteger)initMediaSDKServerIP:(NSString *)serverIP serverPort:(NSString *)serverPort userId:(NSString *)userId;
/*
 *  请求对讲
 */
-(NSInteger)reqMediaTalk:(NSString *)devTakeId view:(UIView*)playCtrl;
/*
 *  停止对讲
 */
-(NSInteger)stopJsstMediaTalk;
/*
 *  销毁对讲
 */
-(void)destoryJsstMediaTalk;
/*
 *  调整窗口大小
 */
-(void)adjustJsstMediaTalkVideoFrame:(CGRect)frame deviceId:(NSString *)deviceId view:(UIView *)view;
/*
 *  静音 :  YES:静音    NO:解除静音
 */
-(void)setSilentJsstMediaTalkMode:(BOOL)silent;
/*
 *  重置视频解码（app进去后台，再返回app时需调用）
 */
- (void)resetVideoDecoder;

/*
 *  重置视频编码（app进去后台调用）
 */
- (void)resetVideoEcoder;

/*
*  请求视频播放
*/
-(NSInteger)reqVideoMonitor:(NSString*)devId :(UIView*)playCtrl;

/*
*  停止视频播放
*/
-(NSInteger)stopVideoMonitor:(NSString*)devId;

/*
*  免提
*/
-(void)setSpeakerMode:(BOOL)bSpeaker;

/*
*  V2.0的初始化接口
*/
-(NSInteger)initMediaSDKServerIP_V2:(NSString *)mdIP mdPort:(NSString *)mdPort userId:(NSString *)userMId;

/*
*  V2.0的两方通话
*/
-(NSInteger)reqMediaTalk_V2:(NSString *)devTakeId :(UIView*)playCtrl :(UIView*)captureCtrl :(int)typeCtrl;

/*
*  V2.0的挂断
*/
-(NSInteger)stopJsstMediaTalk_V2:(NSString *)devTakeId :(int)typeCtrl;

/*
 * V2.0的静音 :  YES:静音    NO:解除静音
 */
-(void)setSilentJsstMediaTalkMode_V2:(BOOL)silent;

/*
*  V2.0的销毁对讲
*/
-(void)destoryJsstMediaTalk_V2;

@end
