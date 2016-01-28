#include <ros/ros.h>
#include <threemxl/C3mxlROS.h>
#include <threemxl/C3mxl.h>
#include <std_msgs/Float32.h>
#include <tf/transform_broadcaster.h>
#include <wristcontrol/scoopPosition.h>
#include <wristcontrol/wristInitializeMotors.h>

bool initializeMotor(wristcontrol::wristInitializeMotors::Request  &req, wristcontrol::wristInitializeMotors::Response &res);

bool scoopMotion(wristcontrol::scoopPosition::Request  &req, wristcontrol::scoopPosition::Response &res);

void closeScoop();

void openScoop();

void updatePosition();

C3mxlROS *motorWrist;
ros::ServiceServer scoopPosService;
ros::ServiceServer initializeService;
