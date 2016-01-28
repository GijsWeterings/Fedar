#include <ros/ros.h>

#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit/move_group_interface/move_group.h>
#include <shape_tools/solid_primitive_dims.h>
#include <manipulation_msgs/Grasp.h>
#include <manipulation_msgs/PlaceLocation.h>
#include <armcontrol/armPosition.h>

// moveit::planning_interface::MoveGroup armgroup;
ros::ServiceServer positionService;
static const std::string ROBOT_DESCRIPTION="robot_description";

bool setPosition(armcontrol::armPosition::Request  &req, armcontrol::armPosition::Response &res) {
    moveit::planning_interface::MoveGroup group("left_arm");
    group.setPlanningTime(5.0);

    // moveit::planning_interface::MoveGroup armgroup;
    moveit::planning_interface::MoveGroup::Plan plan;

    group.setJointValueTarget("upper_arm_joint", req.upperarm);
    group.setJointValueTarget("lower_arm_joint", req.lowerarm);

    if(!group.plan(plan)) {
        ROS_INFO("Can't plan this!");
        return false;
    }

    std::vector<trajectory_msgs::JointTrajectoryPoint> points = plan.trajectory_.joint_trajectory.points;

    for(int i = 0; i < points.size(); i++) {
        points[i].time_from_start = points[i].time_from_start + ros::Duration(1*i);
    }

    plan.trajectory_.joint_trajectory.points = points;
    group.execute(plan);
    ROS_INFO("executed");
    return true;
}

// void pick() {
//
// }

// void addCollisionObjects(ros::Publisher pub_co) {
//     moveit_msgs::CollisionObject co;
//     co.header.stamp = ros::Time::now();
//     co.header.frame_id = "base_link";
//
//     // remove pole
//     co.id = "pole";
//     co.operation = moveit_msgs::CollisionObject::REMOVE;
//     pub_co.publish(co);
//
//     // add pole
//     co.operation = moveit_msgs::CollisionObject::ADD;
//     co.primitives.resize(1);
//     co.primitives[0].type = shape_msgs::SolidPrimitive::BOX;
//     co.primitives[0].dimensions.resize(shape_tools::SolidPrimitiveDimCount<shape_msgs::SolidPrimitive::BOX>::value);
//     co.primitives[0].dimensions[shape_msgs::SolidPrimitive::BOX_X] = 0.3;
//     co.primitives[0].dimensions[shape_msgs::SolidPrimitive::BOX_Y] = 0.1;
//     co.primitives[0].dimensions[shape_msgs::SolidPrimitive::BOX_Z] = 1.0;
//     co.primitive_poses.resize(1);
//     co.primitive_poses[0].position.x = 0.7;
//     co.primitive_poses[0].position.y = -0.4;
//     co.primitive_poses[0].position.z = 0.85;
//     co.primitive_poses[0].orientation.w = 1.0;
//     pub_co.publish(co);
//
//     // remove table
//     co.id = "table";
//     co.operation = moveit_msgs::CollisionObject::REMOVE;
//     pub_co.publish(co);
//
//     // add table
//     co.operation = moveit_msgs::CollisionObject::ADD;
//     co.primitives[0].dimensions[shape_msgs::SolidPrimitive::BOX_X] = 0.5;
//     co.primitives[0].dimensions[shape_msgs::SolidPrimitive::BOX_Y] = 1.5;
//     co.primitives[0].dimensions[shape_msgs::SolidPrimitive::BOX_Z] = 0.35;
//     co.primitive_poses[0].position.x = 0.7;
//     co.primitive_poses[0].position.y = -0.2;
//     co.primitive_poses[0].position.z = 0.175;
//     pub_co.publish(co);
//
//     co.id = "part";
//     co.operation = moveit_msgs::CollisionObject::REMOVE;
//     pub_co.publish(co);
//
//     co.operation = moveit_msgs::CollisionObject::ADD;
//     co.primitives[0].dimensions[shape_msgs::SolidPrimitive::BOX_X] = 0.15;
//     co.primitives[0].dimensions[shape_msgs::SolidPrimitive::BOX_Y] = 0.1;
//     co.primitives[0].dimensions[shape_msgs::SolidPrimitive::BOX_Z] = 0.3;
//
//     co.primitive_poses[0].position.x = 0.6;
//     co.primitive_poses[0].position.y = -0.7;
//     co.primitive_poses[0].position.z = 0.5;
//     pub_co.publish(co);
// }

int main(int argc, char **argv) {
    ros::init (argc, argv, "left_arm_pick_place");
    ros::AsyncSpinner spinner(1);
    spinner.start();


    ros::NodeHandle nh;


    ros::Publisher pub_co = nh.advertise<moveit_msgs::CollisionObject>("collision_object", 10);

    ros::WallDuration(10.0).sleep();


    // moveit::planning_interface::MoveGroup armgroup = group;

    // addCollisionObjects(pub_co);

    // wait a bit for ros things to initialize
    // ros::WallDuration(1.0).sleep();
    // ROS_INFO("I should plan now");
    // pick(group);
    // ROS_INFO("planned");
    //
    positionService = nh.advertiseService("armPosition", &setPosition);

    ros::spin();
    return 0;
    }
