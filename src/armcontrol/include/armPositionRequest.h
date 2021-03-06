// Generated by gencpp from file armcontrol/armPositionRequest.msg
// DO NOT EDIT!


#ifndef ARMCONTROL_MESSAGE_ARMPOSITIONREQUEST_H
#define ARMCONTROL_MESSAGE_ARMPOSITIONREQUEST_H


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
struct armPositionRequest_
{
  typedef armPositionRequest_<ContainerAllocator> Type;

  armPositionRequest_()
    : upperarm(0.0)
    , lowerarm(0.0)  {
    }
  armPositionRequest_(const ContainerAllocator& _alloc)
    : upperarm(0.0)
    , lowerarm(0.0)  {
    }



   typedef double _upperarm_type;
  _upperarm_type upperarm;

   typedef double _lowerarm_type;
  _lowerarm_type lowerarm;




  typedef boost::shared_ptr< ::armcontrol::armPositionRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::armcontrol::armPositionRequest_<ContainerAllocator> const> ConstPtr;

}; // struct armPositionRequest_

typedef ::armcontrol::armPositionRequest_<std::allocator<void> > armPositionRequest;

typedef boost::shared_ptr< ::armcontrol::armPositionRequest > armPositionRequestPtr;
typedef boost::shared_ptr< ::armcontrol::armPositionRequest const> armPositionRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::armcontrol::armPositionRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::armcontrol::armPositionRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::armcontrol::armPositionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::armcontrol::armPositionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::armcontrol::armPositionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::armcontrol::armPositionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::armcontrol::armPositionRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::armcontrol::armPositionRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::armcontrol::armPositionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6b2e53660d6841d8f112321c6040b63e";
  }

  static const char* value(const ::armcontrol::armPositionRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6b2e53660d6841d8ULL;
  static const uint64_t static_value2 = 0xf112321c6040b63eULL;
};

template<class ContainerAllocator>
struct DataType< ::armcontrol::armPositionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "armcontrol/armPositionRequest";
  }

  static const char* value(const ::armcontrol::armPositionRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::armcontrol::armPositionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 upperarm\n\
float64 lowerarm\n\
";
  }

  static const char* value(const ::armcontrol::armPositionRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::armcontrol::armPositionRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.upperarm);
      stream.next(m.lowerarm);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct armPositionRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::armcontrol::armPositionRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::armcontrol::armPositionRequest_<ContainerAllocator>& v)
  {
    s << indent << "upperarm: ";
    Printer<double>::stream(s, indent + "  ", v.upperarm);
    s << indent << "lowerarm: ";
    Printer<double>::stream(s, indent + "  ", v.lowerarm);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARMCONTROL_MESSAGE_ARMPOSITIONREQUEST_H
