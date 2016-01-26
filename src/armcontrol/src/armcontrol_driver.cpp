#include <ros/ros.h>
#include <threemxl/C3mxlROS.h>
#include <threemxl/C3mxl.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/JointState.h>
#include <threemxl/dxlassert.h>


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
C3mxlROS* initializeMotor(int id, int direction){
    // Initialize 3mxl node and set config
    C3mxlROS *motor = new C3mxlROS("/threemxl_com");
    CDxlConfig *config  = new CDxlConfig();
    config->setID(id);
    motor->setConfig(config);
    motor->init(false);
    DXL_SAFE_CALL(motor->set3MxlMode(EXTERNAL_INIT));
    DXL_SAFE_CALL(motor->setAcceleration(0.5));
    DXL_SAFE_CALL(motor->setSpeed(-0.1));
    DXL_SAFE_CALL(motor->setTorque(0.1));
    // usleep(10000);
    // motor->set3MxlMode(POSITION_MODE);
    // motor->setPos(0.3, 0.1);

    return motor;
}

void executeTrajectory(trajectory_msgs::JointTrajectory msg) {
    ROS_INFO("%s", "Executing trajectory[]...");
    updateMotor();

    // if(!(msg.joint_names[0] == "upper_arm" && msg.joint_names[1] == "lower_arm")) {
    //     ROS_ERROR("%s", msg.joint_names[0]);
    //     ROS_ERROR("%s", "[ARM] We're dealing with different motors, abort!");
    //     return;
    // }

    std_msgs::Header header = msg.header;
    // Wait for starting point header.stamp
    while(ros::Time::now() < header.stamp) {
        usleep(100);
    }

    ros::Time start = ros::Time::now();
    int32_t size = msg.points.size();
    ROS_INFO("%d", size);
    // ROS_INFO("%d", msg.points[0]);
    for(int32_t i = 0; i < size; i++) {
        ROS_INFO("%s", "Running next point");
        trajectory_msgs::JointTrajectoryPoint this_point = msg.points[i];

        motor_lower->setPos(this_point.positions[0], this_point.velocities[0], this_point.accelerations[0]);
        motor_upper->setPos(this_point.positions[1], this_point.velocities[1], this_point.accelerations[1]);

        updateMotor();
        while(ros::Time::now() - start < this_point.time_from_start) {
            usleep(100);
        }
    }
}

void updateMotor() {
    motor_upper->getPos();
    motor_lower->getPos();
    ROS_INFO("%s", "Received pos...");

}

void getJointNames(std::vector<std::string>& names) {
    names.clear();
    names.push_back("upper_arm");
    names.push_back("lower_arm");
}

void getJointAngles(std::vector<double>& angles) {
    angles.clear();
    angles.push_back(motor_upper->presentPos());
    angles.push_back(motor_lower->presentPos());
}

void getJointVelocities(std::vector<double>& vels) {
    vels.clear();
    vels.push_back(motor_upper->presentSpeed());
    vels.push_back(motor_lower->presentSpeed());
}

void jointPublish() {
    updateMotor();

    /* ************** Publish joint angles ************** */
    sensor_msgs::JointStatePtr msg = boost::make_shared<sensor_msgs::JointState>();
    std::vector<std::string> joint_names;
    std::vector<double> angles;
    std::vector<double> vels;

    getJointNames(joint_names);
    getJointAngles(angles);
    getJointVelocities(vels);

    for (int i = 0; i < 2 ; ++i) {
      msg->name.push_back(joint_names[i]);
      msg->position.push_back(angles[i]);
      msg->velocity.push_back(vels[i]);
    }

    msg->header.stamp = ros::Time::now();
    jointPublisher.publish(msg);
}

int main(int argc, char **argv) {
    // Initialise node
    ros::init(argc, argv, "armcontrol");
    // Initialise Nodehandler
    ros::NodeHandle nh;

    ROS_INFO("LAUNCH");

    // Refresh rate
    ros::Rate loop_rate(30);

    motor_upper  = initializeMotor(108, -1);
    //motor_lower  = initializeMotor(109, 1);

    // Subscriber
    ros::Subscriber sub = nh.subscribe("command", 10, executeTrajectory);

    while(ros::ok()) {
        ros::spinOnce();
        loop_rate.sleep();
    }
}
