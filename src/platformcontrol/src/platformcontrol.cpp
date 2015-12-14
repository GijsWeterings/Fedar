#include <threemxl/C3mxlROS.h>
#include <threemxl/C3mxl.h>
#include <trajectory_msgs/JointTrajectory.h>

C3mxlROS* initializeWheel(int id);
void executeTrajectory(trajectory_msgs::JointTrajectory msg);

C3mxlROS *motorLeft;
C3mxlROS *motorRight;

/**
 * Initializes a wheel motor
 * @param  id The 3mxl bus ID of the corresponding motor.
 * @return    Pointer to a C3mxlROS object, used to control the motor.
 */
C3mxlROS* initializeWheel(int id){
    // Initialize 3mxl node
    C3mxlROS *motor = new C3mxlROS("/threemxl_com");

    // Initialize config for motor
    CDxlConfig *config  = new CDxlConfig();

    // Set motor ID and assign config to motor node.
    motor->setConfig(config->setID(id));

    // Initialize motor
    motor->init(false);

    // Set motor to POSITION_MODE, so we can give it a position in meters
    motor->set3MxlMode(POSITION_MODE);

    // Set the wheel diameter, so the encoder data can be translated to distance
    motor->setWheelDiameter(0.297);

    return motor;
}

void executeTrajectory(trajectory_msgs::JointTrajectory msg) {
    // Update
    motorLeft->getLinearPos();
    motorRight->getLinearPos();

    motorLeft->setLinearPos(3.0, 20.0);
    motorRight->setLinearPos(3.0, 20.0);
}


int main(int argc, char **argv) {
    // Initialise node
    ros::init(argc, argv, "platformcontrol");
    // Initialise Nodehandler
    ros::NodeHandle nh;

    // Refresh rate
    ros::Rate loop_rate(30);

    motorLeft  = initializeWheel(106);
    motorRight = initializeWheel(107);

    // Subscriber
    ros::Subscriber sub = nh.subscribe("motorcontrol", 1000, executeTrajectory);

    ros::spin();
}
