#ifndef JOINTSTATEPUBLISHER_H_
#define JOINTSTATEPUBLISHER_H_

#include "ros/ros.h"
#include "sensor_msgs/JointState.h"

#include <vector>

#include <AbstractArm.h>

namespace arm_ns
{

class JointStatePublisher
{
public:
  JointStatePublisher(boost::shared_ptr<AbstractArm>);
  virtual ~JointStatePublisher();
  void update();

private:
  boost::shared_ptr<AbstractArm> arm;
  ros::Publisher pub;

};

}

#endif /* JOINTSTATEPUBLISHER_H_ */
