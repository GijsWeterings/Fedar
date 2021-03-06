// Generated by gencpp from file platedetector/assertPlate.msg
// DO NOT EDIT!


#ifndef PLATEDETECTOR_MESSAGE_ASSERTPLATE_H
#define PLATEDETECTOR_MESSAGE_ASSERTPLATE_H

#include <ros/service_traits.h>


#include <platedetector/assertPlateRequest.h>
#include <platedetector/assertPlateResponse.h>


namespace platedetector
{

struct assertPlate
{

typedef assertPlateRequest Request;
typedef assertPlateResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct assertPlate
} // namespace platedetector


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::platedetector::assertPlate > {
  static const char* value()
  {
    return "f680ede81341c83926ff269af0efb2e6";
  }

  static const char* value(const ::platedetector::assertPlate&) { return value(); }
};

template<>
struct DataType< ::platedetector::assertPlate > {
  static const char* value()
  {
    return "platedetector/assertPlate";
  }

  static const char* value(const ::platedetector::assertPlate&) { return value(); }
};


// service_traits::MD5Sum< ::platedetector::assertPlateRequest> should match 
// service_traits::MD5Sum< ::platedetector::assertPlate > 
template<>
struct MD5Sum< ::platedetector::assertPlateRequest>
{
  static const char* value()
  {
    return MD5Sum< ::platedetector::assertPlate >::value();
  }
  static const char* value(const ::platedetector::assertPlateRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::platedetector::assertPlateRequest> should match 
// service_traits::DataType< ::platedetector::assertPlate > 
template<>
struct DataType< ::platedetector::assertPlateRequest>
{
  static const char* value()
  {
    return DataType< ::platedetector::assertPlate >::value();
  }
  static const char* value(const ::platedetector::assertPlateRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::platedetector::assertPlateResponse> should match 
// service_traits::MD5Sum< ::platedetector::assertPlate > 
template<>
struct MD5Sum< ::platedetector::assertPlateResponse>
{
  static const char* value()
  {
    return MD5Sum< ::platedetector::assertPlate >::value();
  }
  static const char* value(const ::platedetector::assertPlateResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::platedetector::assertPlateResponse> should match 
// service_traits::DataType< ::platedetector::assertPlate > 
template<>
struct DataType< ::platedetector::assertPlateResponse>
{
  static const char* value()
  {
    return DataType< ::platedetector::assertPlate >::value();
  }
  static const char* value(const ::platedetector::assertPlateResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // PLATEDETECTOR_MESSAGE_ASSERTPLATE_H
