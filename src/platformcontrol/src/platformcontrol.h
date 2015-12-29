#include <threemxl/C3mxlROS.h>
#include <threemxl/C3mxl.h>
#include <std_msgs/Float32.h>
#include <tf/transform_broadcaster.h>


void updatePosition();

C3mxlROS* initializeWheel(int id);

void executeTrajectory(const std_msgs::Float32::ConstPtr& msg);

void updateTF();

C3mxlROS *motorLeft;
C3mxlROS *motorRight;
static tf::TransformBroadcaster br;
