#include <ros/ros.h>
#include <threemxl/C3mxlROS.h>
#include <threemxl/C3mxl.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <tf/transform_broadcaster.h>
#include <platformcontrol/findLeftBoundary.h>
#include <platformcontrol/findRightBoundary.h>
#include <platformcontrol/platformHome.h>
#include <platformcontrol/platformInitializeMotors.h>
#include <platformcontrol/platformPosition.h>


C3mxlROS *motorLeft;
C3mxlROS *motorRight;
// static tf::TransformBroadcaster br;
ros::ServiceServer platformInitializeMotorsService;
ros::ServiceServer platformPositionService;
ros::ServiceServer platformHomeService;
ros::ServiceServer findLeftBoundaryService;
ros::ServiceServer findRightBoundaryService;

float minPos;
float maxPos;


C3mxlROS* initializeWheel(int id);

bool initializeMotor(platformcontrol::platformInitializeMotors::Request  &req, platformcontrol::platformInitializeMotors::Response &res);

bool goHome(platformcontrol::platformHome::Request  &req, platformcontrol::platformHome::Response &res);

bool goTo(platformcontrol::platformPosition::Request  &req, platformcontrol::platformPosition::Response &res);

bool findLeftBoundary(platformcontrol::findLeftBoundary::Request  &req, platformcontrol::findLeftBoundary::Response &res);

bool findRightBoundary(platformcontrol::findRightBoundary::Request  &req, platformcontrol::findRightBoundary::Response &res);

void goToPos(float pos);

void executeTrajectory(const std_msgs::Float32::ConstPtr& msg);

void updatePosition();

void updateTF();

void worldOffset(ros::Publisher pub);
