// Generated by gencpp from file fedar_msgs/Job.msg
// DO NOT EDIT!


#ifndef FEDAR_MSGS_MESSAGE_JOB_H
#define FEDAR_MSGS_MESSAGE_JOB_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace fedar_msgs
{
template <class ContainerAllocator>
struct Job_
{
  typedef Job_<ContainerAllocator> Type;

  Job_()
    : ingredients()  {
    }
  Job_(const ContainerAllocator& _alloc)
    : ingredients(_alloc)  {
    }



   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _ingredients_type;
  _ingredients_type ingredients;




  typedef boost::shared_ptr< ::fedar_msgs::Job_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fedar_msgs::Job_<ContainerAllocator> const> ConstPtr;

}; // struct Job_

typedef ::fedar_msgs::Job_<std::allocator<void> > Job;

typedef boost::shared_ptr< ::fedar_msgs::Job > JobPtr;
typedef boost::shared_ptr< ::fedar_msgs::Job const> JobConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fedar_msgs::Job_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fedar_msgs::Job_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace fedar_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'fedar_msgs': ['/home/gijs/Fedar/src/fedar_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::fedar_msgs::Job_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fedar_msgs::Job_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fedar_msgs::Job_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fedar_msgs::Job_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fedar_msgs::Job_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fedar_msgs::Job_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fedar_msgs::Job_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9e8c55b375e95f879fbd5622ca7c3ae1";
  }

  static const char* value(const ::fedar_msgs::Job_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9e8c55b375e95f87ULL;
  static const uint64_t static_value2 = 0x9fbd5622ca7c3ae1ULL;
};

template<class ContainerAllocator>
struct DataType< ::fedar_msgs::Job_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fedar_msgs/Job";
  }

  static const char* value(const ::fedar_msgs::Job_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fedar_msgs::Job_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32[] ingredients\n\
";
  }

  static const char* value(const ::fedar_msgs::Job_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fedar_msgs::Job_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ingredients);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Job_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fedar_msgs::Job_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fedar_msgs::Job_<ContainerAllocator>& v)
  {
    s << indent << "ingredients[]" << std::endl;
    for (size_t i = 0; i < v.ingredients.size(); ++i)
    {
      s << indent << "  ingredients[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.ingredients[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // FEDAR_MSGS_MESSAGE_JOB_H