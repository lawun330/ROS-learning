#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

#define _USE_MATH_DEFINES  //used to use PI value

//declaring variable types
float linear_time, angular_time;
float M_array[2], T_array[2];

//assigning variables
int rate = 10;  
int angle_travel  = 0;
float theta = 0.0;			//to tune the required angle
int counter = 0;			//for checking a complete square


/////////////////////////////////////
float* MoveStraightVals(float linear_distance, float linear_velocity)
{
	linear_time					= abs(linear_distance / linear_velocity); 
	float linear_ticks			= linear_time * rate;
	static float move_array[2] 	= {linear_velocity, linear_ticks};	
	return move_array;
}

float* TurnVals(float angle, float angular_velocity)
{
	angular_time 				= abs(angle/ angular_velocity);
	float angular_ticks 		= angular_time * rate;
	static float turn_array[2] 	= {angular_velocity, angular_ticks};
	return turn_array;
}

/////////////////////////////////////

int main (int argc, char ** argv)
{
	ros::init(argc, argv, "square_move_Pnode");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",10);

	geometry_msgs::Twist vel_msg;
	ros::Rate r(rate);

	while (ros::isShuttingDown() == false)
	{

		//front
		float * M_array = MoveStraightVals(4, 2);

		for (float i=0; i<M_array[1]; i++)
		{
			vel_msg.linear.x 	= M_array[0];
			vel_msg.angular.z 	= 0;
			pub.publish(vel_msg);
			r.sleep();	
		}	 
		counter += 1;

		//turn
		float * T_array = TurnVals((M_PI/2 + theta),0.2);

		for (float j=0; j<T_array[1]; j++)
		{
			vel_msg.linear.x 	= 0;
			vel_msg.angular.z 	= T_array[0];
			pub.publish(vel_msg);
			r.sleep();
		}
		counter += 1;

		if (counter == 8){ros::shutdown();} 	//the square is drawn
		

	}
	return 0;
}