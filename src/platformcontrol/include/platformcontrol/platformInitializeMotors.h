// Generated by gencpp from file platformcontrol/platformInitializeMotors.msg
// DO NOT EDIT!


#ifndef PLATFORMCONTROL_MESSAGE_PLATFORMINITIALIZEMOTORS_H
#define PLATFORMCONTROL_MESSAGE_PLATFORMINITIALIZEMOTORS_H

#include <ros/service_traits.h>


#include <platformcontrol/platformInitializeMotorsRequest.h>
#include <platformcontrol/platformInitializeMotorsResponse.h>


namespace platformcontrol
{

struct platformInitializeMotors
{

typedef platformInitializeMotorsRequest Request;
typedef platformInitializeMotorsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct platformInitializeMotors
} // namespace platformcontrol


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::platformcontrol::platformInitializeMotors > {
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::platformcontrol::platformInitializeMotors&) { return value(); }
};

template<>
struct DataType< ::platformcontrol::platformInitializeMotors > {
  static const char* value()
  {
    return "platformcontrol/platformInitializeMotors";
  }

  static const char* value(const ::platformcontrol::platformInitializeMotors&) { return value(); }
};


// service_traits::MD5Sum< ::platformcontrol::platformInitializeMotorsRequest> should match 
// service_traits::MD5Sum< ::platformcontrol::platformInitializeMotors > 
template<>
struct MD5Sum< ::platformcontrol::platformInitializeMotorsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::platformcontrol::platformInitializeMotors >::value();
  }
  static const char* value(const ::platformcontrol::platformInitializeMotorsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::platformcontrol::platformInitializeMotorsRequest> should match 
// service_traits::DataType< ::platformcontrol::platformInitializeMotors > 
template<>
struct DataType< ::platformcontrol::platformInitializeMotorsRequest>
{
  static const char* value()
  {
    return DataType< ::platformcontrol::platformInitializeMotors >::value();
  }
  static const char* value(const ::platformcontrol::platformInitializeMotorsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::platformcontrol::platformInitializeMotorsResponse> should match 
// service_traits::MD5Sum< ::platformcontrol::platformInitializeMotors > 
template<>
struct MD5Sum< ::platformcontrol::platformInitializeMotorsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::platformcontrol::platformInitializeMotors >::value();
  }
  static const char* value(const ::platformcontrol::platformInitializeMotorsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::platformcontrol::platformInitializeMotorsResponse> should match 
// service_traits::DataType< ::platformcontrol::platformInitializeMotors > 
template<>
struct DataType< ::platformcontrol::platformInitializeMotorsResponse>
{
  static const char* value()
  {
    return DataType< ::platformcontrol::platformInitializeMotors >::value();
  }
  static const char* value(const ::platformcontrol::platformInitializeMotorsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // PLATFORMCONTROL_MESSAGE_PLATFORMINITIALIZEMOTORS_H
