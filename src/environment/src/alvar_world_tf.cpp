#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
#include <ar_track_alvar_msgs/AlvarMarker.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <map>
#include <geometry_msgs/Pose.h>

#include <ros/console.h>

void receivePoseMarker(ar_track_alvar_msgs::AlvarMarkers msg);

void receivePoseMarker(ar_track_alvar_msgs::AlvarMarkers msg) {
    ROS_INFO("Hello %s", "world");

    // int size = msg.markers.size();
    // foreach(ar_track_alvar_msgs::AlvarMarker marker : msg.markers) {
    //     ROS_INFO("Hello %d", size);
    // }

}

int main(int argc, char** argv) {
  ros::init(argc, argv, "alvar_world_tf");
  ros::NodeHandle nh;

  tf::TransformBroadcaster broadcaster;
  ros::Subscriber sub;

  std::map<int, std::string> mymap;
  mymap[1] = "foo";

  ros::Rate rate(10.0);

  sub = nh.subscribe("ar_pose_marker", 1000, receivePoseMarker);
  //
  // while(nh.ok()) {
  //
  //   rate.sleep();
  // }


  ros::spin();

  return 0;
};
