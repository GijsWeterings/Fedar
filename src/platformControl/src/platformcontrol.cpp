#include <threemxl/C3mxlROS.h>
#include <threemxl/C3mxl.h>

int main(int argc, char **argv) {
    // Initialise node
    ros::init(argc, argv, "platformcontrol");
    // Initialise Nodehandler
    ros::NodeHandle nh;

    // Rate of while loop
    ros::Rate loop_rate(3);
    C3mxlROS *motorLeft  = new C3mxlROS("/threemxl_com");
    C3mxlROS *motorRight = new C3mxlROS("/threemxl_com");

    CDxlConfig *configLeft  = new CDxlConfig();
    CDxlConfig *configRight = new CDxlConfig();

    motorLeft->setConfig(configLeft->setID(106));
    motorRight->setConfig(configRight->setID(107));

    motorLeft->init(false);
    motorRight->init(false);

    motorLeft->set3MxlMode(POSITION_MODE);
    motorRight->set3MxlMode(POSITION_MODE);

    motorLeft->setSpeed(1.0);
    motorRight->setSpeed(1.0);

    while(ros::ok()) {
        loop_rate.sleep();
        motorLeft->getPos();
        motorRight->getPos();
        std::cout << motorLeft->presentPos() << " - " << motorRight->presentPos() << std::endl;
        motorLeft->setPos(motorLeft->presentPos() + 0.3);
        motorRight->setPos(motorRight->presentPos() + 0.3);
    }
}

