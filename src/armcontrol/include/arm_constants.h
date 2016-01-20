#ifndef ARM_CONSTANTS_H_
#define ARM_CONSTANTS_H_

namespace arm_ns
{
/// The number of motors in the arm
const int NUM_MOTORS = 3;

/// The number of joints in the arm
const int NUM_JOINTS = NUM_MOTORS;

// /// KNI time is in 10 milliseconds (most of the time), ROS time is in seconds
// static const double KNI_TO_ROS_TIME = 100.0;
//
// /// the conversion factor from KNI coordinates (in mm) to ROS coordinates (in m)
// static const double KNI_TO_ROS_LENGTH = 0.001;
//
// /// velocity limit <= 180 [enc / 10 ms]
// static const int KNI_MAX_VELOCITY = 180;
//
// /// acceleration limit = 1 or 2 [enc / (10 ms)^2]
// static const int KNI_MAX_ACCELERATION = 2;
//
// static const size_t MOVE_BUFFER_SIZE = 16;  // TODO: find out exact value

} // namespace arm_ns


#endif /* ARM_CONSTANTS_H_ */
