// Generated by gencpp from file platformcontrol/platformPositionRequest.msg
// DO NOT EDIT!


#ifndef PLATFORMCONTROL_MESSAGE_PLATFORMPOSITIONREQUEST_H
#define PLATFORMCONTROL_MESSAGE_PLATFORMPOSITIONREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace platformcontrol
{
template <class ContainerAllocator>
struct platformPositionRequest_
{
  typedef platformPositionRequest_<ContainerAllocator> Type;

  platformPositionRequest_()
    {
    }
  platformPositionRequest_(const ContainerAllocator& _alloc)
    {
    }






  typedef boost::shared_ptr< ::platformcontrol::platformPositionRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::platformcontrol::platformPositionRequest_<ContainerAllocator> const> ConstPtr;

}; // struct platformPositionRequest_

typedef ::platformcontrol::platformPositionRequest_<std::allocator<void> > platformPositionRequest;

typedef boost::shared_ptr< ::platformcontrol::platformPositionRequest > platformPositionRequestPtr;
typedef boost::shared_ptr< ::platformcontrol::platformPositionRequest const> platformPositionRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::platformcontrol::platformPositionRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::platformcontrol::platformPositionRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace platformcontrol

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::platformcontrol::platformPositionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::platformcontrol::platformPositionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::platformcontrol::platformPositionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::platformcontrol::platformPositionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::platformcontrol::platformPositionRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::platformcontrol::platformPositionRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::platformcontrol::platformPositionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::platformcontrol::platformPositionRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::platformcontrol::platformPositionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "platformcontrol/platformPositionRequest";
  }

  static const char* value(const ::platformcontrol::platformPositionRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::platformcontrol::platformPositionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::platformcontrol::platformPositionRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::platformcontrol::platformPositionRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct platformPositionRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::platformcontrol::platformPositionRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::platformcontrol::platformPositionRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // PLATFORMCONTROL_MESSAGE_PLATFORMPOSITIONREQUEST_H
