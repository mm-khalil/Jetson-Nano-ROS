#include <ros/ros.h>
#include <fstream>
#include <vector>
#include <tf/tf.h>
#include <iostream>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose2D.h>
#include "geometry_msgs/Point32.h"
#include "sensor_msgs/ChannelFloat32.h"
#include "sensor_msgs/Range.h"
#include <vector>
#include <cmath>
#include <time.h> 
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <termios.h>
#include "std_msgs/String.h"
#include <sstream>
#include <sensor_msgs/NavSatStatus.h>
#include <sensor_msgs/NavSatFix.h>
#include <geographic_msgs/GeoPoseStamped.h>
#include "std_msgs/UInt16.h"
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/WaypointPush.h>
#include <mavros_msgs/CommandCode.h>
//#include <list>

using namespace std;
ros::Publisher pub_pose_;



void moveforward()
{
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<geometry_msgs::TwistStamped>("/mavros/setpoint_velocity/cmd_vel",1000);
  geometry_msgs::TwistStamped msg;
  double BASE_SPEED = 0.4, MOVE_TIME = 10.0, CLOCK_SPEED = 100;
  ros::Rate rate(CLOCK_SPEED);
  
  // cout<<"Robot is Moving Forward"<<endl;
 	
  while( ros::ok() )
  {
   msg.twist.linear.x = 0.5;
   pub.publish(msg);
   ros::spinOnce();
   rate.sleep();  
  }

    		
}


void movebackward()
{  ros::NodeHandle nh;
   ros::Publisher pub = nh.advertise<geometry_msgs::TwistStamped>("/mavros/setpoint_velocity/cmd_vel",1000);
   geometry_msgs::TwistStamped msg;
   double BASE_SPEED = 0.4, MOVE_TIME = 10.0, CLOCK_SPEED = 40;
   ros::Rate rate(CLOCK_SPEED);

   // cout<<"Robot is Moving Backward"<<endl; 

   while( ros::ok() )
   {
            msg.twist.linear.x = 0.5;
            pub.publish(msg);
            ros::spinOnce();
            rate.sleep();	
   }
   

}





/*
void stop()
{	 


  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<geometry_msgs::TwistStamped>("/mavros/setpoint_velocity/cmd_vel",1000);
  geometry_msgs::TwistStamped msg;
  double BASE_SPEED = 0.4, MOVE_TIME = 10.0, CLOCK_SPEED = 40;

  ros::Rate rate(CLOCK_SPEED);
// Make the robot stop (robot perhaps has a speed already)
	
		while(ros::ok())
		{	
			geometry_msgs::TwistStamped move;
			msg.twist.linear.x  = 0;
			msg.twist.linear.y  = 0;
			msg.twist.linear.z  = 0;
			msg.twist.angular.x = 0;
			msg.twist.angular.y = 0;
			msg.twist.angular.z = 0;
			pub.publish(msg);
			cout<<"Stopped "<<endl;
			k++;
     		ros::spinOnce();
     		rate.sleep();
  		}
  	
}*/
	 
/*
void spinright()
{
	 ros::NodeHandle nh;
	 ros::Publisher pub = nh.advertise<geometry_msgs::TwistStamped>("/mavros/setpoint_velocity/cmd_vel",1000);

 	 geometry_msgs::TwistStamped msg;
 	 double BASE_SPEED = 0.4, MOVE_TIME = 10.0, CLOCK_SPEED = 40;
	 ros::Rate rate(CLOCK_SPEED);
	// Make the robot stop (robot perhaps has a speed already)
		
 	while(ros::ok() )
	{	
		
	       geometry_msgs::TwistStamped move;
	       msg.twist.angular.z = -0.5;
	       //cout<<"Spin" <<endl;
	       pub.publish(msg);
	       ros::spinOnce();
	       rate.sleep();
	     
	}
      msg.twist.linear.x  = 0;
      msg.twist.linear.y  = 0;
      msg.twist.linear.z  = 0;
      msg.twist.angular.x = 0;
      msg.twist.angular.y = 0;
      msg.twist.angular.z = 0;
       
      pub.publish(msg);
}*/

 	

/*
void spinleft()
{	

  ros::NodeHandle nh;
   ros::Publisher pub = nh.advertise<geometry_msgs::TwistStamped>("/mavros/setpoint_velocity/cmd_vel",1000);
  geometry_msgs::TwistStamped msg;
  double BASE_SPEED = 0.4, MOVE_TIME = 10.0, CLOCK_SPEED = 40;

  ros::Rate rate(CLOCK_SPEED);

 while(ros::ok())
	{	
		geometry_msgs::TwistStamped move;
		msg.twist.angular.z = +0.5;
		pub.publish(msg);
     		ros::spinOnce();
     		rate.sleep();     		
  	}	 
  	msg.twist.linear.x = 0;
      	msg.twist.linear.y = 0;
      	msg.twist.linear.z = 0;
      	msg.twist.angular.x = 0;
      	msg.twist.angular.y = 0;
      	msg.twist.angular.z = 0;
      	//pub.header.stamp = ros::Time::now();
      	pub.publish(msg);

}*/


void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "auto_set_mode");
    ros::NodeHandle nh;
    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, state_sub);
    ros::spinOnce();
    //rate.sleep();
    
    
    //subscribe Leader_position here
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    ros::spin();	
    
    
    
    //Decision (where to move)
    moveforward();
    
    
    
   
    
    
return 0;
}
