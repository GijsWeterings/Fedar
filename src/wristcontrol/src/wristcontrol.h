#include <ros/ros.h>
#include <threemxl/C3mxlROS.h>
#include <threemxl/C3mxl.h>
#include <std_msgs/Float32.h>
#include <tf/transform_broadcaster.h>
#include <wristcontrol/scoopPosition.h>

C3mxlROS* initializeWheel(int id);

bool scoopMotion(std::string& request, bool& response);

void closeScoop();

void openScoop();

void updatePosition();

C3mxlROS *motorWrist;
ros::ServiceServer scoopPosservice;
ros::Rate rate(30);
