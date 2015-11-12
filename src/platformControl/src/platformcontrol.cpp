#include <threemxl/C3mxlROS.h>
#include <threemxl/C3mxl.h>

int main(int argc, char **argv) {
    // Initialise node
    ros::init(argc, argv, "platformcontrol");
    // Initialise Nodehandler
    ros::NodeHandle nh;

    // Rate of while loop
    ros::Rate loop_rate(1.0/5.0);
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

    motorLeft->setWheelDiameter(0.297);
    motorRight->setWheelDiameter(0.297);
    
    while(ros::ok()) {
        loop_rate.sleep();
     
        motorLeft->getLinearPos();
        motorRight->getLinearPos();
        
        motorLeft->setLinearPos(1.0, 20.0);
        motorRight->setLinearPos(1.0, 20.0);

        loop_rate.sleep();

        motorLeft->getLinearPos();
        motorRight->getLinearPos();

        motorLeft->setLinearPos(0.0, 25.0);
        motorRight->setLinearPos(0.0, 25.0);
    }
}

