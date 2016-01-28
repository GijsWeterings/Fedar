#include <ros.h>
#include <std_msgs/Int32.h>

ros::NodeHandle nh;

std_msgs::Int32 msg;
ros::Publisher light("light", &msg);

void setup()
{
  nh.initNode();
  nh.advertise(light);
}

void loop()
{
  int LDRRead = analogRead(A0);
  if (LDRRead <= 20){
    msg.data = 0;
  }
  else{
    msg.data = 1;
  }
  light.publish( &msg );
  nh.spinOnce();
  delay(100);
}

