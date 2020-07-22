#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

void custom_func(const geometry_msgs::Twist &msg)
{
	ROS_INFO("Merry go round");
}

int main (int argc, char ** argv)
{
	ros::init(argc, argv, "circle_move_Snode");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("turtle1/cmd_vel",10,custom_func);

	ros::spin();
}