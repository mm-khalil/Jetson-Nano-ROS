#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int8.h>


void chatterCallback1(const std_msgs::String::ConstPtr& msg1)
{
  ROS_INFO("I heard: [%s]", msg1->data.c_str());
}



void chatterCallback2(const std_msgs::Int8::msg2)
{
  ROS_INFO("I heard: [%s]", msg2->data);
}




int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  
  ros::NodeHandle n1;
  ros::NodeHandle n2;

  
  ros::Subscriber sub1 = n1.subscribe("chatter", 1000, chatterCallback1);
  ros::Subscriber sub2 = n2.subscribe("chatter", 1000, chatterCallback2);
  
  
  ros::spin();
  return 0;
}
