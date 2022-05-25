#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <std_msgs/Int8.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  
  ros::NodeHandle n1;
  ros::NodeHandle n2;
  
  ros::Publisher chatter_pub1 = n1.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher chatter_pub2 = n2.advertise<std_msgs::String>("chatter", 1000);
  
  ros::Rate loop_rate(10);
  int count = 0;
  
  while (ros::ok())
  {
    //publish Leader or Follower
    std_msgs::String msg1;
    std::stringstream ss;
    ss << "follower";
    msg1.data = ss.str();
    ROS_INFO("%s", msg1.data.c_str());
    chatter_pub1.publish(msg1);
 
 
    //publish Distance
    std_msgs::Int8 msg2;
    msg2.data = 17;
    ROS_INFO("%d", msg2.data);
    chatter_pub2.publish(msg2);



    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  
  return 0;
}

