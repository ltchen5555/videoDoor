//
//  JsstVoipSDK.h
//  VoipSDKTest
//
//  Created by K on 2020/6/16.
//  Copyright © 2020 K. All rights reserved.
//

#import <Foundation/Foundation.h>




@interface JsstVoipSDK : NSObject

/**
  *     type（必填）： 0：门岗机访客类型
                     1：Y10A
  *     loginInfo： 登录信息，格式：NSDictionary（type：0必传，1：非必填）
             注：以下参数必传：cno、usr、psw、passKey
             例如：@{
                 @"cno":@"",        //客户号
                 @"usr":@"",        //账号
                 @"psw":@"",        //密码
                 @"passKey":@"",    //密钥
             }
  *     dataDic： 解析消息传入信息，格式：NSDictionary
            注：1、取捷顺返回的消息内容放入，根据type分为两种模式如下
            2、第一种（type：0）：以下参数必传：eventId、speakId、scenarios、personId、subsystemCode
             例如：@{
                 @"ip":@"11",     //信令ip
                 @"port":@"11",   //信令端口
                 @"eventId":@"111",    //事件id
                 @"speakId":@"11",     //对讲id
                 @"scenarios":@"11",   //场景
                 @"personId":@"11",    //人员id
                 @"subsystemCode":@"11"，  //项目编号
             }
            3、第二种（type：1）：以下参数必传：speakId、ip、port、equipId、personId、areaId
            例如：@{
                @"ip":@"11",     //信令ip
                @"port":@"11",   //信令端口
                @"speakId":@"111",    //对讲id
                @"equipId":@"11",    //equipId
                @"personId":@"11"，  //项目personId
                @"areaId":@"11"，  //项目areaId
            }
  *     resultCode: 3001:参数不完整
                    3002:对讲中
                    3003:对讲失败
                    3004:设备离线
                    3005:正常挂断
  */
+(void)showCallViewType:(NSInteger)type LoginInfo:(NSDictionary*)loginInfo Info:(NSDictionary*)dataDic CompletionBlock:(void (^)(NSString * resultCode))completionBlock;

/**
  *   此方法设置要优先于showCallViewLoginInfo
  *   isLocal：是否本地化部署
  *   url：本地化部署的接口地址
  */
+(void)setIsLocal:(BOOL)isLocal localConfigUrl:(NSString *)url;

/**
  *     app进入后台，重新进入前台时，需要重置视频播放
  */
+(void)resetVideoPlay;

/**
 *     debug:YES:跳过接口调用
 *     默认：NO
 */
+(void)setDebug:(BOOL)debug;



@end
