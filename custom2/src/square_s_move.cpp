#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

void custom_func(const geometry_msgs::Twist &msg)
{
	ROS_INFO("GOING");
}

int main (int argc, char ** argv)
{
	ros::init(argc, argv, "square_move_Snode");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("turtle1/cmd_vel",10,custom_func);

	ros::spin();
}