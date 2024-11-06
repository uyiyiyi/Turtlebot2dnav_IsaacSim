#include "turtle_2dnav/global_planner.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "octomap_planner");
	ros::NodeHandle n;
	planner planner_object;

	ros::Subscriber octree_sub = n.subscribe<octomap_msgs::Octomap>("/octomap_binary", 1, boost::bind(&octomapCallback, _1, &planner_object));
	// ros::Subscriber odom_sub = n.subscribe<nav_msgs::Odometry>("/rovio/odometry", 1, boost::bind(&odomCb, _1, &planner_object));
	ros::Subscriber goal_sub = n.subscribe<geometry_msgs::PointStamped>("/goal/clicked_point", 1, boost::bind(&goalCb, _1, &planner_object));
	ros::Subscriber start_sub = n.subscribe<geometry_msgs::PointStamped>("/start/clicked_point", 1, boost::bind(&startCb, _1, &planner_object));

//	vis_pub = n.advertise<visualization_msgs::Marker>( "visualization_marker", 0 );
	vis_pub = n.advertise<nav_msgs::Path>( "visualization_marker", 0 );
//	traj_pub = n.advertise<trajectory_msgs::MultiDOFJointTrajectory>("waypoints",1);
	traj_pub = n.advertise<nav_msgs::Path>("waypoints",1);
	
	std::cout << "OMPL version: " << OMPL_VERSION << std::endl;

	ros::spin();

	return 0;
}
