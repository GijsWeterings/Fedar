// Generated by gencpp from file ingredientfinder/ingredientPosRequest.msg
// DO NOT EDIT!


#ifndef INGREDIENTFINDER_MESSAGE_INGREDIENTPOSREQUEST_H
#define INGREDIENTFINDER_MESSAGE_INGREDIENTPOSREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ingredientfinder
{
template <class ContainerAllocator>
struct ingredientPosRequest_
{
  typedef ingredientPosRequest_<ContainerAllocator> Type;

  ingredientPosRequest_()
    : alvar_id(0)  {
    }
  ingredientPosRequest_(const ContainerAllocator& _alloc)
    : alvar_id(0)  {
    }



   typedef int32_t _alvar_id_type;
  _alvar_id_type alvar_id;




  typedef boost::shared_ptr< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ingredientPosRequest_

typedef ::ingredientfinder::ingredientPosRequest_<std::allocator<void> > ingredientPosRequest;

typedef boost::shared_ptr< ::ingredientfinder::ingredientPosRequest > ingredientPosRequestPtr;
typedef boost::shared_ptr< ::ingredientfinder::ingredientPosRequest const> ingredientPosRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ingredientfinder

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ca09af0db86c73dab5766adae8c0c76a";
  }

  static const char* value(const ::ingredientfinder::ingredientPosRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xca09af0db86c73daULL;
  static const uint64_t static_value2 = 0xb5766adae8c0c76aULL;
};

template<class ContainerAllocator>
struct DataType< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ingredientfinder/ingredientPosRequest";
  }

  static const char* value(const ::ingredientfinder::ingredientPosRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 alvar_id\n\
";
  }

  static const char* value(const ::ingredientfinder::ingredientPosRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.alvar_id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ingredientPosRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ingredientfinder::ingredientPosRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ingredientfinder::ingredientPosRequest_<ContainerAllocator>& v)
  {
    s << indent << "alvar_id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.alvar_id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // INGREDIENTFINDER_MESSAGE_INGREDIENTPOSREQUEST_H
