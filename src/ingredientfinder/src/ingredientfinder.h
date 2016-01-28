#include <map>
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <ar_track_alvar_msgs/AlvarMarker.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <ingredientfinder/ingredientPos.h>
#include <std_msgs/Float64.h>

std::map<int, float> markerMap;
ros::ServiceServer ingredientPosService;

float offset;

void receivePoseMarker(ar_track_alvar_msgs::AlvarMarkers msg);

void publishTF();
