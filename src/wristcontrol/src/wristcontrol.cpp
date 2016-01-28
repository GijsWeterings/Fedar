#include "wristcontrol.h"

C3mxlROS* initializeMotor(int id, float direction){
    // Initialize 3mxl node and set config
    C3mxlROS *motor = new C3mxlROS("/threemxl_com");
    CDxlConfig *config  = new CDxlConfig();
    config->setID(id);
    motor->setConfig(config);
    motor->init(false);
    motor->set3MxlMode(EXTERNAL_INIT);
    motor->setAcceleration(0.5);
    motor->setSpeed(direction * 0.2);
    motor->setTorque(direction * 0.2);
    usleep(10000);
    motor->set3MxlMode(POSITION_MODE);
    // motor->setPos(0.3, 0.1);
    return motor;
}

/**
 * Initializes a wrist motor
 * @param  id The 3mxl bus ID of the corresponding motor.
 * @return    Pointer to a C3mxlROS object, used to control the motor.
 */
bool initializeMotor(wristcontrol::wristInitializeMotors::Request  &req, wristcontrol::wristInitializeMotors::Response &res) {
    C3mxlROS *motor = new C3mxlROS("/threemxl_com");
    CDxlConfig *config  = new CDxlConfig();
    config->setID(110);
    motor->setConfig(config);
    motor->init(false);
    motor->set3MxlMode(EXTERNAL_INIT);
    motor->setAcceleration(0.5);
    motor->setSpeed(-0.2);
    motor->setTorque(-0.2);
    usleep(10000);
    motorWrist  = motor;
    updatePosition();

    while(motorWrist->presentSpeed() > 0.05) {
        usleep(1000);
        updatePosition();
    }
    // motor->setJointOffset(2.743);
    motor->set3MxlMode(POSITION_MODE);

    // motorWrist  = motor;
    //initializeMotor2(110, 1);

    return true;
}

/**
 * Callback for the scoopPosition service.
 * @param  request  string, valid values are "open" or "close".
 * @param  response set to true iff a valid scoop position was set.
 * @return          returns true iff service call executed normally.
 */
bool scoopMotion(wristcontrol::scoopPosition::Request  &req, wristcontrol::scoopPosition::Response &res) {
    if (req.position == "open") {
        openScoop();
        res.succ = true;
        usleep(10000);
        return true;
    }
    else if (req.position == "close") {
        closeScoop();
        res.succ = true;
        usleep(10000);
        return true;
    }
    else {
        res.succ = false;
        return false;
    }

}

/**
 * Closes the scoop to set angle
 */
void closeScoop() {
    updatePosition();
    motorWrist->setPos(-0.338, 1.0);
}

/**
 * Opens the scoop to set angle
 */
void openScoop() {
    updatePosition();
    motorWrist->setPos(1.722, 1.0);
}

/**
 * Updates position value retrieved from motor encoder.
 */
void updatePosition() {
    motorWrist->getPos();
}


int main(int argc, char **argv) {
    // Initialise node
    ros::init(argc, argv, "wristcontrol");

    // Initialise Nodehandler
    ros::NodeHandle nh;
    ros::Rate rate(30);

    initializeMotor(110, 1);

    scoopPosService = nh.advertiseService("scoopPosition", &scoopMotion);
    initializeService = nh.advertiseService("wristInitializeMotors", &initializeMotor);

    ros::spin();
}
