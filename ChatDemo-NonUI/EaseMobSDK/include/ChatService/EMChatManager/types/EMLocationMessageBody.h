/*!
 @header EMLocationMessageBody.h
 @abstract 聊天的位置消息体对象类型
 @author Ji Fang
 @version 1.00 2014/01/01 Creation (1.00)
 */

#import "EMMessageBody.h"

@class EMChatLocation;

/*!
 @class
 @abstract 聊天的位置消息体对象
 */
@interface EMLocationMessageBody : EMMessageBody

/*!
 @property
 @abstract 纬度
 */
@property (nonatomic, readonly) double latitude;

/*!
 @property
 @abstract 经度
 */
@property (nonatomic, readonly) double longitude;

/*!
 @property
 @abstract 地理位置信息
 */
@property (nonatomic, readonly) NSString *address;

/*!
 @property
 @abstract 位置消息体内部的位置对象
 */
@property (nonatomic, readonly) EMChatLocation *location;

/*!
 @method
 @abstract 以位置对象创建位置消息体实例
 @discussion
 @param message 位置对象
 @result 位置消息体
 */
- (id)initWithMessage:(EMChatLocation *)message;

@end