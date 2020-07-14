#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <iostream>
#include <nav_msgs/Odometry.h>

ros::Publisher marker_pub;
bool pickup = false;

void add_marker_callback(const nav_msgs::Odometry odom){

    // Set our initial shape type to be a cube
    uint32_t shape = visualization_msgs::Marker::CUBE;
  
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers";
    marker.id = 0;

    marker.type = shape;
    
    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.3;
    marker.scale.y = 0.3;
    marker.scale.z = 0.3;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Show the marker initially
    if(pickup==false && (odom.pose.pose.position.x < 1 ||(odom.pose.pose.position.x > 1 && odom.twist.twist.linear.x > 1.0e-5))){
        marker.action = visualization_msgs::Marker::ADD;
	marker.pose.position.x = 7;
        marker.pose.position.y = 8;
    }

    // Delete the marker when pick up point is reached
    else if(pickup == false && odom.twist.twist.linear.x < 1.0e-5){
	marker.action = visualization_msgs::Marker::DELETE;
	pickup = true;
    }

    // Show the marker when dropoff is reached
    else if(pickup == true && odom.twist.twist.linear.x < 0.1 && odom.pose.pose.position.x <0){
        marker.pose.position.x = -7;
        marker.pose.position.y = 8;
	marker.action = visualization_msgs::Marker::ADD;
    }

    // Delete the marker when travelling from pickup to dropoff
    else{
	marker.action = visualization_msgs::Marker::DELETE;
    }

    marker_pub.publish(marker);

}

int main( int argc, char** argv ) 
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber sub1 = n.subscribe("/odom", 1, add_marker_callback);

  ros::spin();
  return 0;
}
