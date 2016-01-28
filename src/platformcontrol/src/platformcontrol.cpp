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

bool initializeMotor(platformcontrol::platformInitializeMotors::Request  &req, platformcontrol::platformInitializeMotors::Response &res) {
    motorLeft  = initializeWheel(106);
    motorRight = initializeWheel(107);
    return true;
}

bool goHome(platformcontrol::platformHome::Request  &req, platformcontrol::platformHome::Response &res) {
    goToPos(minPos);
    return true;
}

bool goTo(platformcontrol::platformPosition::Request  &req, platformcontrol::platformPosition::Response &res) {
    goToPos(req.position);
    return true;
}

bool findLeftBoundary(platformcontrol::findLeftBoundary::Request  &req, platformcontrol::findLeftBoundary::Response &res) {
    minPos = 0.0;

    goToPos(minPos);
    return true;
}

bool findRightBoundary(platformcontrol::findRightBoundary::Request  &req, platformcontrol::findRightBoundary::Response &res) {
    maxPos = 1.35;
    goToPos(maxPos);
    return true;
}

void goToPos(float pos) {
    motorLeft->setLinearPos(pos, 2.0);
    motorRight->setLinearPos(pos, 2.0);
}

void executeTrajectory(const std_msgs::Float32::ConstPtr& msg) {
    updatePosition();
    goToPos(msg->data);
}

void updatePosition() {
    motorLeft->getLinearPos();
    motorRight->getLinearPos();
}

void updateTF() {
    // updatePosition();
    // motorLeft->getPos();
    // motorRight->getPos();
    // //motorLeft->presentPos()
    tf::TransformBroadcaster br;

    tf::Transform transform;
    tf::Quaternion q;
    transform.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
    q.setRPY(0.0, 0.0, 0.0);
    transform.setRotation(q);

    // br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "base_link", "world"));
}

void worldOffset(ros::Publisher pub) {
    std_msgs::Float64 msg;
    updatePosition();

    msg.data = motorLeft->presentLinearPos();
    pub.publish(msg);
}

int main(int argc, char **argv) {
    // Initialise node
    ros::init(argc, argv, "platformcontrol");

    // Initialise Nodehandler
    ros::NodeHandle nh;

    ros::Publisher pub;

    // Refresh rate
    ros::Rate loop_rate(30);

    // Subscriber
    // ros::Subscriber sub = nh.subscribe("platformposition", 1000, executeTrajectory);
    //

    pub = nh.advertise<std_msgs::Float64>("worldOffset", 10);


    platformInitializeMotorsService = nh.advertiseService("platformInitializeMotors", &initializeMotor);
    platformPositionService = nh.advertiseService("platformPosition", &goTo);
    platformHomeService = nh.advertiseService("platformHome", &goHome);
    findLeftBoundaryService = nh.advertiseService("findLeftBoundary", &findLeftBoundary);
    findRightBoundaryService = nh.advertiseService("findRightBoundary", &findRightBoundary);

    while(ros::ok()) {
        worldOffset(pub);
        updateTF();
        ros::spinOnce();
        loop_rate.sleep();
    }
}
