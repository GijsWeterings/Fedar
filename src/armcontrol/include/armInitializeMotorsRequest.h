// Generated by gencpp from file armcontrol/armInitializeMotorsRequest.msg
// DO NOT EDIT!


#ifndef ARMCONTROL_MESSAGE_ARMINITIALIZEMOTORSREQUEST_H
#define ARMCONTROL_MESSAGE_ARMINITIALIZEMOTORSREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace armcontrol
{
template <class ContainerAllocator>
struct armInitializeMotorsRequest_
{
  typedef armInitializeMotorsRequest_<ContainerAllocator> Type;

  armInitializeMotorsRequest_()
    {
    }
  armInitializeMotorsRequest_(const ContainerAllocator& _alloc)
    {
    }






  typedef boost::shared_ptr< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> const> ConstPtr;

}; // struct armInitializeMotorsRequest_

typedef ::armcontrol::armInitializeMotorsRequest_<std::allocator<void> > armInitializeMotorsRequest;

typedef boost::shared_ptr< ::armcontrol::armInitializeMotorsRequest > armInitializeMotorsRequestPtr;
typedef boost::shared_ptr< ::armcontrol::armInitializeMotorsRequest const> armInitializeMotorsRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace armcontrol

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "armcontrol/armInitializeMotorsRequest";
  }

  static const char* value(const ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct armInitializeMotorsRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::armcontrol::armInitializeMotorsRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // ARMCONTROL_MESSAGE_ARMINITIALIZEMOTORSREQUEST_H
