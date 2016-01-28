// Generated by gencpp from file platformcontrol/platformHome.msg
// DO NOT EDIT!


#ifndef PLATFORMCONTROL_MESSAGE_PLATFORMHOME_H
#define PLATFORMCONTROL_MESSAGE_PLATFORMHOME_H

#include <ros/service_traits.h>


#include <platformcontrol/platformHomeRequest.h>
#include <platformcontrol/platformHomeResponse.h>


namespace platformcontrol
{

struct platformHome
{

typedef platformHomeRequest Request;
typedef platformHomeResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct platformHome
} // namespace platformcontrol


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::platformcontrol::platformHome > {
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::platformcontrol::platformHome&) { return value(); }
};

template<>
struct DataType< ::platformcontrol::platformHome > {
  static const char* value()
  {
    return "platformcontrol/platformHome";
  }

  static const char* value(const ::platformcontrol::platformHome&) { return value(); }
};


// service_traits::MD5Sum< ::platformcontrol::platformHomeRequest> should match 
// service_traits::MD5Sum< ::platformcontrol::platformHome > 
template<>
struct MD5Sum< ::platformcontrol::platformHomeRequest>
{
  static const char* value()
  {
    return MD5Sum< ::platformcontrol::platformHome >::value();
  }
  static const char* value(const ::platformcontrol::platformHomeRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::platformcontrol::platformHomeRequest> should match 
// service_traits::DataType< ::platformcontrol::platformHome > 
template<>
struct DataType< ::platformcontrol::platformHomeRequest>
{
  static const char* value()
  {
    return DataType< ::platformcontrol::platformHome >::value();
  }
  static const char* value(const ::platformcontrol::platformHomeRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::platformcontrol::platformHomeResponse> should match 
// service_traits::MD5Sum< ::platformcontrol::platformHome > 
template<>
struct MD5Sum< ::platformcontrol::platformHomeResponse>
{
  static const char* value()
  {
    return MD5Sum< ::platformcontrol::platformHome >::value();
  }
  static const char* value(const ::platformcontrol::platformHomeResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::platformcontrol::platformHomeResponse> should match 
// service_traits::DataType< ::platformcontrol::platformHome > 
template<>
struct DataType< ::platformcontrol::platformHomeResponse>
{
  static const char* value()
  {
    return DataType< ::platformcontrol::platformHome >::value();
  }
  static const char* value(const ::platformcontrol::platformHomeResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // PLATFORMCONTROL_MESSAGE_PLATFORMHOME_H