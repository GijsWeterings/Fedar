#include <ros/ros.h>
#include <threemxl/C3mxlROS.h>
#include <threemxl/C3mxl.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/JointState.h>

C3mxlROS* motor_upper;
C3mxlROS* motor_lower;
ros::Publisher jointPublisher;
ros::Subscriber sub;

void updateMotor();
void getJointNames(std::vector<std::string>& names);
void getJointAngles(std::vector<double>& angles);
void getJointVelocities(std::vector<double>& vels);

/**
 * Initializes a motor
 * @param  id The 3mxl bus ID of the corresponding motor.
 * @return    Pointer to a C3mxlROS object, used to control the motor.
 */
C3mxlROS* initializeMotor(int id){
    // Initialize 3mxl node and set config
    C3mxlROS *motor = new C3mxlROS("/threemxl_com");
    CDxlConfig *config  = new CDxlConfig();
    config->setID(id);
    motor->setConfig(config);
    motor->init(false);

    return motor;
}

void updateMotor() {
    motor_upper->getPos();
    motor_lower->getPos();
}

void getJointNames(std::vector<std::string>& names) {
    names.clear();
    names.push_back("upper_arm_joint");
    names.push_back("lower_arm_joint");
}

void getJointAngles(std::vector<float>& angles) {
    angles.clear();
    angles.push_back(motor_upper->presentPos());
    angles.push_back(motor_lower->presentPos());
}

void getJointVelocities(std::vector<float>& vels) {
    vels.clear();
    vels.push_back(motor_upper->presentSpeed());
    vels.push_back(motor_lower->presentSpeed());
}

void jointPublish(ros::Publisher jP) {
    updateMotor();

    /* ************** Publish joint angles ************** */
    sensor_msgs::JointState msg;// = boost::make_shared<sensor_msgs::JointState>();
    // msg.reset(new sensor_msgs::JointState);
    std::vector<std::string> joint_names;
    std::vector<float> angles;
    std::vector<float> vels;

    getJointNames(joint_names);
    getJointAngles(angles);
    getJointVelocities(vels);

    for (int i = 0; i < 2 ; ++i) {
      msg.name.push_back(joint_names[i]);
      msg.position.push_back(angles[i]);
      msg.velocity.push_back(vels[i]);
    }

    msg.header.stamp = ros::Time::now();
    jP.publish(msg);
}

int main(int argc, char **argv) {
    // Initialise node
    ros::init(argc, argv, "joint_state_publisher_fedar");
    // Initialise Nodehandler
    ros::NodeHandle nh;

    ros::Publisher jointPublisher = nh.advertise<sensor_msgs::JointState>("joint_states", 100);

    // Refresh rate
    ros::Rate loop_rate(30);

    motor_upper  = initializeMotor(108);
    motor_lower  = initializeMotor(109);

    while(ros::ok()) {
        jointPublish(jointPublisher);
        ros::spinOnce();
        loop_rate.sleep();
    }
}
