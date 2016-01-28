// Generated by gencpp from file userInterface/sayTTSResponse.msg
// DO NOT EDIT!


#ifndef USERINTERFACE_MESSAGE_SAYTTSRESPONSE_H
#define USERINTERFACE_MESSAGE_SAYTTSRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace userInterface
{
template <class ContainerAllocator>
struct sayTTSResponse_
{
  typedef sayTTSResponse_<ContainerAllocator> Type;

  sayTTSResponse_()
    {
    }
  sayTTSResponse_(const ContainerAllocator& _alloc)
    {
    }






  typedef boost::shared_ptr< ::userInterface::sayTTSResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::userInterface::sayTTSResponse_<ContainerAllocator> const> ConstPtr;

}; // struct sayTTSResponse_

typedef ::userInterface::sayTTSResponse_<std::allocator<void> > sayTTSResponse;

typedef boost::shared_ptr< ::userInterface::sayTTSResponse > sayTTSResponsePtr;
typedef boost::shared_ptr< ::userInterface::sayTTSResponse const> sayTTSResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::userInterface::sayTTSResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::userInterface::sayTTSResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace userInterface

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::userInterface::sayTTSResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::userInterface::sayTTSResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::userInterface::sayTTSResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::userInterface::sayTTSResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::userInterface::sayTTSResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::userInterface::sayTTSResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::userInterface::sayTTSResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::userInterface::sayTTSResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::userInterface::sayTTSResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "userInterface/sayTTSResponse";
  }

  static const char* value(const ::userInterface::sayTTSResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::userInterface::sayTTSResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::userInterface::sayTTSResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::userInterface::sayTTSResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct sayTTSResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::userInterface::sayTTSResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::userInterface::sayTTSResponse_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // USERINTERFACE_MESSAGE_SAYTTSRESPONSE_H
