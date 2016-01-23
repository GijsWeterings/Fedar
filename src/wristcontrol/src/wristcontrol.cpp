#include "wristcontrol.h"

/**
 * Initializes a wrist motor
 * @param  id The 3mxl bus ID of the corresponding motor.
 * @return    Pointer to a C3mxlROS object, used to control the motor.
 */
C3mxlROS* initializeWheel(int id) {
    // Initialize 3mxl node and set config
    C3mxlROS *motor = new C3mxlROS("/threemxl_com");
    CDxlConfig *config  = new CDxlConfig();
    config->setID(id);
    motor->setConfig(config);
    motor->init(false);

    motor->set3MxlMode(POSITION_MODE);

    return motor;
}

/**
 * Callback for the scoopPosition service.
 * @param  request  string, valid values are "open" or "close".
 * @param  response set to true iff a valid scoop position was set.
 * @return          returns true iff service call executed normally.
 */
bool add(wristcontrol::scoopPosition::Request  &req,         wristcontrol::scoopPosition::Response &res) {
    if (req.position == "open") {
        openScoop();
        res.succ = true;
        rate.sleep();
        return true;
    }
    else if (req.position == "close") {
        closeScoop();
        res.succ = true;
        rate.sleep();
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
    motorWrist->setPos(0.1, 1.0);
}

/**
 * Opens the scoop to set angle
 */
void openScoop() {
    updatePosition();
    motorWrist->setPos(0.9, 1.0);
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

    motorWrist  = initializeWheel(110);

    scoopPosservice = nh.advertiseService("scoopPosition", scoopMotion);

    // Subscriber
    //ros::Subscriber sub = nh.subscribe("wristposition", 1000, closeScoop);

    ros::spin();
}
