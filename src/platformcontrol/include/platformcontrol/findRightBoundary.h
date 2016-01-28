// Generated by gencpp from file platformcontrol/findRightBoundary.msg
// DO NOT EDIT!


#ifndef PLATFORMCONTROL_MESSAGE_FINDRIGHTBOUNDARY_H
#define PLATFORMCONTROL_MESSAGE_FINDRIGHTBOUNDARY_H

#include <ros/service_traits.h>


#include <platformcontrol/findRightBoundaryRequest.h>
#include <platformcontrol/findRightBoundaryResponse.h>


namespace platformcontrol
{

struct findRightBoundary
{

typedef findRightBoundaryRequest Request;
typedef findRightBoundaryResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct findRightBoundary
} // namespace platformcontrol


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::platformcontrol::findRightBoundary > {
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::platformcontrol::findRightBoundary&) { return value(); }
};

template<>
struct DataType< ::platformcontrol::findRightBoundary > {
  static const char* value()
  {
    return "platformcontrol/findRightBoundary";
  }

  static const char* value(const ::platformcontrol::findRightBoundary&) { return value(); }
};


// service_traits::MD5Sum< ::platformcontrol::findRightBoundaryRequest> should match 
// service_traits::MD5Sum< ::platformcontrol::findRightBoundary > 
template<>
struct MD5Sum< ::platformcontrol::findRightBoundaryRequest>
{
  static const char* value()
  {
    return MD5Sum< ::platformcontrol::findRightBoundary >::value();
  }
  static const char* value(const ::platformcontrol::findRightBoundaryRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::platformcontrol::findRightBoundaryRequest> should match 
// service_traits::DataType< ::platformcontrol::findRightBoundary > 
template<>
struct DataType< ::platformcontrol::findRightBoundaryRequest>
{
  static const char* value()
  {
    return DataType< ::platformcontrol::findRightBoundary >::value();
  }
  static const char* value(const ::platformcontrol::findRightBoundaryRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::platformcontrol::findRightBoundaryResponse> should match 
// service_traits::MD5Sum< ::platformcontrol::findRightBoundary > 
template<>
struct MD5Sum< ::platformcontrol::findRightBoundaryResponse>
{
  static const char* value()
  {
    return MD5Sum< ::platformcontrol::findRightBoundary >::value();
  }
  static const char* value(const ::platformcontrol::findRightBoundaryResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::platformcontrol::findRightBoundaryResponse> should match 
// service_traits::DataType< ::platformcontrol::findRightBoundary > 
template<>
struct DataType< ::platformcontrol::findRightBoundaryResponse>
{
  static const char* value()
  {
    return DataType< ::platformcontrol::findRightBoundary >::value();
  }
  static const char* value(const ::platformcontrol::findRightBoundaryResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // PLATFORMCONTROL_MESSAGE_FINDRIGHTBOUNDARY_H
