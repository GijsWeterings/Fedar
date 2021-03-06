// Generated by gencpp from file platedetector/assertNoPlateResponse.msg
// DO NOT EDIT!


#ifndef PLATEDETECTOR_MESSAGE_ASSERTNOPLATERESPONSE_H
#define PLATEDETECTOR_MESSAGE_ASSERTNOPLATERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace platedetector
{
template <class ContainerAllocator>
struct assertNoPlateResponse_
{
  typedef assertNoPlateResponse_<ContainerAllocator> Type;

  assertNoPlateResponse_()
    : succ(false)  {
    }
  assertNoPlateResponse_(const ContainerAllocator& _alloc)
    : succ(false)  {
    }



   typedef uint8_t _succ_type;
  _succ_type succ;




  typedef boost::shared_ptr< ::platedetector::assertNoPlateResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::platedetector::assertNoPlateResponse_<ContainerAllocator> const> ConstPtr;

}; // struct assertNoPlateResponse_

typedef ::platedetector::assertNoPlateResponse_<std::allocator<void> > assertNoPlateResponse;

typedef boost::shared_ptr< ::platedetector::assertNoPlateResponse > assertNoPlateResponsePtr;
typedef boost::shared_ptr< ::platedetector::assertNoPlateResponse const> assertNoPlateResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::platedetector::assertNoPlateResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::platedetector::assertNoPlateResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace platedetector

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::platedetector::assertNoPlateResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::platedetector::assertNoPlateResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::platedetector::assertNoPlateResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::platedetector::assertNoPlateResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::platedetector::assertNoPlateResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::platedetector::assertNoPlateResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::platedetector::assertNoPlateResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f680ede81341c83926ff269af0efb2e6";
  }

  static const char* value(const ::platedetector::assertNoPlateResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf680ede81341c839ULL;
  static const uint64_t static_value2 = 0x26ff269af0efb2e6ULL;
};

template<class ContainerAllocator>
struct DataType< ::platedetector::assertNoPlateResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "platedetector/assertNoPlateResponse";
  }

  static const char* value(const ::platedetector::assertNoPlateResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::platedetector::assertNoPlateResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool succ\n\
\n\
";
  }

  static const char* value(const ::platedetector::assertNoPlateResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::platedetector::assertNoPlateResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.succ);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct assertNoPlateResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::platedetector::assertNoPlateResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::platedetector::assertNoPlateResponse_<ContainerAllocator>& v)
  {
    s << indent << "succ: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.succ);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PLATEDETECTOR_MESSAGE_ASSERTNOPLATERESPONSE_H
