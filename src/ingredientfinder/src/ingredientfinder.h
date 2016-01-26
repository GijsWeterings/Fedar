#include <map>
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <ar_track_alvar_msgs/AlvarMarker.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>

std::map<int, geometry_msgs::PoseStamped> markerMap;

void receivePoseMarker(ar_track_alvar_msgs::AlvarMarkers msg);

void publishTF();