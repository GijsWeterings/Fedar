#ifndef ABSTRACTARM_H_
#define ABSTRACTARM_H_

#include <ros/ros.h>
#include <urdf/model.h>

#include <arm_constants.h>

#include <arm_navigation_msgs/JointLimits.h>

namespace arm_ns
{

class AbstractArm
{
public:
  AbstractArm();
  virtual ~AbstractArm();

  virtual void refreshEncoders() = 0;
  virtual bool executeTrajectory(boost::shared_ptr<SpecifiedTrajectory> traj) = 0;
  virtual void freezeRobot();

  /**
   * Move the joint to the desired angle. Do not wait for result,
   * but return immediately.
   *
   * @param jointIndex the joint to move
   * @param turningAngle the target angle
   * @return true iff command was successfully sent to Arm
   */
  virtual bool moveJoint(int jointIndex, double turningAngle) = 0;

  virtual int getJointIndex(std::string joint_name);

  virtual std::vector<std::string> getJointNames();
  virtual std::vector<int> getJointTypes();

  virtual std::vector<double> getMotorAngles();
  virtual std::vector<double> getMotorVelocities();

  virtual std::vector<arm_navigation_msgs::JointLimits> getMotorLimits();
  virtual double getMotorLimitMax(std::string joint_name);
  virtual double getMotorLimitMin(std::string joint_name);

  virtual void refreshMotorStatus();
  virtual bool someMotorCrashed() = 0;
  virtual bool allJointsReady() = 0;
  virtual bool allMotorsReady() = 0;


protected:
  std::vector<std::string> joint_names_;
  std::vector<int> joint_types_;

  std::vector<double> motor_angles_;
  std::vector<double> motor_velocities_;


  std::vector<arm_navigation_msgs::JointLimits> motor_limits_;
};

}

#endif /* ABSTRACTARM_H_ */
