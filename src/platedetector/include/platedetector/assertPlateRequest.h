// Generated by gencpp from file platedetector/assertPlateRequest.msg
// DO NOT EDIT!


#ifndef PLATEDETECTOR_MESSAGE_ASSERTPLATEREQUEST_H
#define PLATEDETECTOR_MESSAGE_ASSERTPLATEREQUEST_H


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
struct assertPlateRequest_
{
  typedef assertPlateRequest_<ContainerAllocator> Type;

  assertPlateRequest_()
    {
    }
  assertPlateRequest_(const ContainerAllocator& _alloc)
    {
    }






  typedef boost::shared_ptr< ::platedetector::assertPlateRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::platedetector::assertPlateRequest_<ContainerAllocator> const> ConstPtr;

}; // struct assertPlateRequest_

typedef ::platedetector::assertPlateRequest_<std::allocator<void> > assertPlateRequest;

typedef boost::shared_ptr< ::platedetector::assertPlateRequest > assertPlateRequestPtr;
typedef boost::shared_ptr< ::platedetector::assertPlateRequest const> assertPlateRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::platedetector::assertPlateRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::platedetector::assertPlateRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::platedetector::assertPlateRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::platedetector::assertPlateRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::platedetector::assertPlateRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::platedetector::assertPlateRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::platedetector::assertPlateRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::platedetector::assertPlateRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::platedetector::assertPlateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::platedetector::assertPlateRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::platedetector::assertPlateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "platedetector/assertPlateRequest";
  }

  static const char* value(const ::platedetector::assertPlateRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::platedetector::assertPlateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::platedetector::assertPlateRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::platedetector::assertPlateRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct assertPlateRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::platedetector::assertPlateRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::platedetector::assertPlateRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // PLATEDETECTOR_MESSAGE_ASSERTPLATEREQUEST_H
