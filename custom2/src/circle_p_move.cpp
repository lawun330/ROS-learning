#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iostream>

using namespace std;

float radius;
float arc;

int main (int argc, char ** argv)
{
	ros::init(argc, argv,"circle__move_Pnode");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",10);

	ros::Rate r(10);
	geometry_msgs::Twist vel_msg;


	cout << "Enter radius value - ";
	cin  >> radius; 
	cout << "Enter velocity value - "; 
	cin  >> arc;

	while (ros::ok())
	{
		time
		vel_msg.linear.x 	= arc;				//although it is an arc it acts like speed
		vel_msg.angular.z	= arc/radius;		//theta = arc s/radius
		pub.publish(vel_msg);
		r.sleep();
		{ros::shutdown();}
	}
	return 0;

}