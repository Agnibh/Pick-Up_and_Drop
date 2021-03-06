#!/bin/sh

xterm  -e  " source devel/setup.bash" &
sleep 5
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find add_markers)/world/agnibh.world" &
sleep 5
xterm  -e  " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(rospack find add_markers)/map/myMap.yaml" &
sleep 5
xterm  -e  " roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm  -e  " rosrun pick_objects pick_objects" &
sleep 5
xterm  -e  " rosrun add_markers add_markers" 

