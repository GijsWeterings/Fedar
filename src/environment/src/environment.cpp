#include <ros/ros.h>
#include <sound_play/sound_play.h>

int main(int argc, char **argv) {
    // Initialise "environment" node
    ros::init(argc, argv, "environment");

    // Initialise Nodehandler
    ros::NodeHandle nh;

    // Initialise SoundClient
    sound_play::SoundClient sc;

    // Enable publisher for sounds
   // ros::Publisher pub = nh.advertise<sound_play::SoundRequest>("robotsound", 5);

    // Set loop rate, limiting extreme 
    ros::Rate loop_rate(1.0/5.0);


    while(ros::ok()) {
        loop_rate.sleep();
        sc.say("Please be careful! Robot coming through");
    }
}
