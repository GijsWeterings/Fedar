#include <ros/ros.h>
#include <platedetector/assertPlate.h>
#include <platedetector/assertNoPlate.h>
#include <std_msgs/Int32.h>

bool platePresent;
ros::ServiceServer assertPlateService;
ros::ServiceServer assertNoPlateService;
void registerLight(std_msgs::Int32 msg);
bool assertPlate(platedetector::assertPlate::Request  &req, platedetector::assertPlate::Response &res);
bool assertNoPlate(platedetector::assertNoPlate::Request  &req, platedetector::assertNoPlate::Response &res);


bool assertPlate(platedetector::assertPlate::Request  &req, platedetector::assertPlate::Response &res){
    res.succ = platePresent;
    return true;
}

bool assertNoPlate(platedetector::assertNoPlate::Request  &req, platedetector::assertNoPlate::Response &res) {
    res.succ = !platePresent;
    return true;
}

void registerLight(std_msgs::Int32 msg) {
    if(msg.data == 0) {
        platePresent = true;
    }
    else {
        platePresent = false;
    }
}


int main(int argc, char **argv) {
    // Initialise node
    ros::init(argc, argv, "armcontrol");
    // Initialise Nodehandler
    ros::NodeHandle nh;

    // Refresh rate
    ros::Rate loop_rate(30);

    // Subscriber
    ros::Subscriber sub = nh.subscribe("light", 10, &registerLight);

    assertPlateService = nh.advertiseService("assertPlate", &assertPlate);
    assertNoPlateService = nh.advertiseService("assertNoPlate", &assertNoPlate);

    ros::spin();
    return 0;
}
