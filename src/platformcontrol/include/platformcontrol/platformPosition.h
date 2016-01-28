// Generated by gencpp from file platformcontrol/platformPosition.msg
// DO NOT EDIT!


#ifndef PLATFORMCONTROL_MESSAGE_PLATFORMPOSITION_H
#define PLATFORMCONTROL_MESSAGE_PLATFORMPOSITION_H

#include <ros/service_traits.h>


#include <platformcontrol/platformPositionRequest.h>
#include <platformcontrol/platformPositionResponse.h>


namespace platformcontrol
{

struct platformPosition
{

typedef platformPositionRequest Request;
typedef platformPositionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct platformPosition
} // namespace platformcontrol


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::platformcontrol::platformPosition > {
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::platformcontrol::platformPosition&) { return value(); }
};

template<>
struct DataType< ::platformcontrol::platformPosition > {
  static const char* value()
  {
    return "platformcontrol/platformPosition";
  }

  static const char* value(const ::platformcontrol::platformPosition&) { return value(); }
};


// service_traits::MD5Sum< ::platformcontrol::platformPositionRequest> should match 
// service_traits::MD5Sum< ::platformcontrol::platformPosition > 
template<>
struct MD5Sum< ::platformcontrol::platformPositionRequest>
{
  static const char* value()
  {
    return MD5Sum< ::platformcontrol::platformPosition >::value();
  }
  static const char* value(const ::platformcontrol::platformPositionRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::platformcontrol::platformPositionRequest> should match 
// service_traits::DataType< ::platformcontrol::platformPosition > 
template<>
struct DataType< ::platformcontrol::platformPositionRequest>
{
  static const char* value()
  {
    return DataType< ::platformcontrol::platformPosition >::value();
  }
  static const char* value(const ::platformcontrol::platformPositionRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::platformcontrol::platformPositionResponse> should match 
// service_traits::MD5Sum< ::platformcontrol::platformPosition > 
template<>
struct MD5Sum< ::platformcontrol::platformPositionResponse>
{
  static const char* value()
  {
    return MD5Sum< ::platformcontrol::platformPosition >::value();
  }
  static const char* value(const ::platformcontrol::platformPositionResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::platformcontrol::platformPositionResponse> should match 
// service_traits::DataType< ::platformcontrol::platformPosition > 
template<>
struct DataType< ::platformcontrol::platformPositionResponse>
{
  static const char* value()
  {
    return DataType< ::platformcontrol::platformPosition >::value();
  }
  static const char* value(const ::platformcontrol::platformPositionResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // PLATFORMCONTROL_MESSAGE_PLATFORMPOSITION_H
