#include "ingredientfinder.h"

/**
* Callback on "ar_pose_marker" topic. Stores all visible markers
* in markerMap with id as key and pose as value.
* Retrieve using markerMap.find(<<id>>)->second.pose
*/
void receivePoseMarker(ar_track_alvar_msgs::AlvarMarkers msg) {
    int size = msg.markers.size();
    // tf::TransformListener tflisten;
    //
    // tf::StampedTransform transform;
    // try{
    //   tflisten.lookupTransform("/world", "/camera_link",
    //                            ros::Time(0), transform);
    // }
    // catch (tf::TransformException ex){
    //   ROS_ERROR("%s",ex.what());
    //   ros::Duration(1.0).sleep();
    // }

    for(int i = 0; i < size; i++) {
        // Ignore marker id 255, it only identifies noise.
        if(msg.markers[i].id == 255) { continue; }

        markerMap[msg.markers[i].id] = offset + msg.markers[i].pose.pose.position.y;
    }
}

// void publishTF() {
//     static tf::TransformBroadcaster br;
//
//     for(auto const& marker : markerMap) {
//         tf::Transform transform;
//         tf::Quaternion q;
//
//         geometry_msgs::Pose p = marker.second.pose;
//
//         transform.setOrigin( tf::Vector3(p.position.x, p.position.y, p.position.z) );
//         q.setRPY(p.orientation.x, p.orientation.y, p.orientation.z);
//         transform.setRotation(q);
//         br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "ingredient/" + marker.first));
//     }
//
// }
//
bool ingredientPos(ingredientfinder::ingredientPos::Request  &req, ingredientfinder::ingredientPos::Response &res) {
    res.platformtarget = markerMap[req.alvar_id];
    return true;
}

void getLatestOffset(std_msgs::Float64 msg) {
    offset = msg.data;
}


int main(int argc, char** argv) {
    ros::init(argc, argv, "ingredientfinder");
    ros::NodeHandle nh;
    ros::Subscriber sub;
    ros::Subscriber fedarPos;

    sub = nh.subscribe("ar_pose_marker", 10, &receivePoseMarker);
    fedarPos = nh.subscribe("worldOffset", 10, &getLatestOffset);

    ingredientPosService = nh.advertiseService("ingredientPos", &ingredientPos);


    ros::Rate loop_rate(10);
    while(ros::ok()) {
        // publishTF();
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
};
