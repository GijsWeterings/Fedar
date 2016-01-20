#include "platformcontrol.h"

/**
 * Initializes a wheel motor
 * @param  id The 3mxl bus ID of the corresponding motor.
 * @return    Pointer to a C3mxlROS object, used to control the motor.
 */
C3mxlROS* initializeWheel(int id){
    // Initialize 3mxl node and set config
    C3mxlROS *motor = new C3mxlROS("/threemxl_com");
    CDxlConfig *config  = new CDxlConfig();
    config->setID(id);
    motor->setConfig(config);
    motor->init(false);

    motor->set3MxlMode(POSITION_MODE);

    // Set the wheel diameter, so the encoder data can be translated to distance
    motor->setWheelDiameter(0.297);

    return motor;
}

void executeTrajectory(const std_msgs::Float32::ConstPtr& msg) {
    updatePosition();

    motorLeft->setLinearPos(msg->data, 20.0);
    motorRight->setLinearPos(msg->data, 20.0);
}

void updatePosition() {
    motorLeft->getLinearPos();
    motorRight->getLinearPos();
}

void updateTF() {
    updatePosition();

    tf::Transform transform;
    transform.setOrigin( tf::Vector3(0, motorLeft->presentPos(), 0.0) );

    //br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "base_link"));
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
    ros::Subscriber sub = nh.subscribe("platformposition", 1000, executeTrajectory);

    while(ros::ok()) {
        updateTF();
        ros::spinOnce();
        loop_rate.sleep();
    }
}
