#include <map>
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <ar_track_alvar_msgs/AlvarMarker.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <ingredientfinder/ingredientPos.h>

std::map<int, float> markerMap;
ros::ServiceServer ingredientPosService;


void receivePoseMarker(ar_track_alvar_msgs::AlvarMarkers msg);

void publishTF();
