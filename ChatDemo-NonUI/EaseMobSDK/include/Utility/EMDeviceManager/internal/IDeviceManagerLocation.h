//
//  IDeviceManagerLocation.h
//  EaseMobClientSDK
//
//  Created by Ji Fang on 5/3/14.
//  Copyright (c) 2014 EaseMob. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDeviceManagerBase.h"
#import <CoreLocation/CLLocation.h>

@protocol IDeviceManagerLocation <IDeviceManagerBase>

@required

#pragma mark - location service
@property (nonatomic, readonly) BOOL isLocationServicesEnabled;
@property (nonatomic, readonly) CLLocation *lastLocation;

- (void)startUpdatingLocation;
- (void)stopUpdatingLocation;
- (void)refreshLocation;

- (NSString *)decodeAddressFromLatitude:(double)latitude
                           andLongitude:(double)longitude
                                  error:(EMError **)pError;
- (void)asyncDecodeAddressFromLatitude:(double)latitude
                          andLongitude:(double)longitude;
- (void)asyncDecodeAddressFromLatitude:(double)latitude
                          andLongitude:(double)longitude
                            completion:(void (^)(NSString *address, EMError *))completion
                               onQueue:(dispatch_queue_t)queue;

/**
 *	@brief	世界标准地理坐标(WGS-84) 转换成 中国国测局地理坐标（GCJ-02）<火星坐标>
 *
 *  ####只在中国大陆的范围的坐标有效，以外直接返回世界标准坐标
 *
 *	@param 	location 	世界标准地理坐标(WGS-84)
 *
 *	@return	中国国测局地理坐标（GCJ-02）<火星坐标>
 */
+ (CLLocationCoordinate2D)wgs84ToGcj02:(CLLocationCoordinate2D)location;

/**
 *	@brief	中国国测局地理坐标（GCJ-02） 转换成 世界标准地理坐标（WGS-84）
 *
 *  ####此接口有1－2米左右的误差，需要精确定位情景慎用
 *
 *	@param 	location 	中国国测局地理坐标（GCJ-02）
 *
 *	@return	世界标准地理坐标（WGS-84）
 */
+ (CLLocationCoordinate2D)gcj02ToWgs84:(CLLocationCoordinate2D)location;

/**
 *	@brief	世界标准地理坐标(WGS-84) 转换成 百度地理坐标（BD-09)
 *
 *	@param 	location 	世界标准地理坐标(WGS-84)
 *
 *	@return	百度地理坐标（BD-09)
 */
+ (CLLocationCoordinate2D)wgs84ToBd09:(CLLocationCoordinate2D)location;

/**
 *	@brief	中国国测局地理坐标（GCJ-02）<火星坐标> 转换成 百度地理坐标（BD-09)
 *
 *	@param 	location 	中国国测局地理坐标（GCJ-02）<火星坐标>
 *
 *	@return	百度地理坐标（BD-09)
 */
+ (CLLocationCoordinate2D)gcj02ToBd09:(CLLocationCoordinate2D)location;

/**
 *	@brief	百度地理坐标（BD-09) 转换成 中国国测局地理坐标（GCJ-02）<火星坐标>
 *
 *	@param 	location 	百度地理坐标（BD-09)
 *
 *	@return	中国国测局地理坐标（GCJ-02）<火星坐标>
 */
+ (CLLocationCoordinate2D)bd09ToGcj02:(CLLocationCoordinate2D)location;

/**
 *	@brief	百度地理坐标（BD-09) 转换成 世界标准地理坐标（WGS-84）
 *
 *  ####此接口有1－2米左右的误差，需要精确定位情景慎用
 *
 *	@param 	location 	百度地理坐标（BD-09)
 *
 *	@return	世界标准地理坐标（WGS-84）
 */
+ (CLLocationCoordinate2D)bd09ToWgs84:(CLLocationCoordinate2D)location;

@end
