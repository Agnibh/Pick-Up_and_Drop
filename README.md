# Advanced Monte Carlo Localization-Project

This project was developed for the course [Udacity Robotics Software Engineer Nanodegree Program](https://www.udacity.com/course/robotics-software-engineer--nd209).

<img src="navigation.gif"/>

Used AMCL,SLAM to navigte a custom robot and wrote nodes in C++ to simulate a robot capable of navigating to pick up and deliver virtual objects.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gazebo

## Build Instructions

* Create a catkin_ws, feel free to skip if you already have one!

     $ cd /home/workspace/

     $ mkdir -p /home/workspace/catkin_ws/src/

     $ cd catkin_ws/src/

     $ catkin_init_workspace

     $ cd ..

* Clone the package in catkin_ws/src/

     $ cd /home/https://github.com/Agnibh/Pick-Up_and_Drop.git

* Build the  package

     $ cd /home/workspace/catkin_ws/ 

     $ catkin_make

* After building the package, source your environment

     $ cd /home/workspace/catkin_ws/

     $ source devel/setup.bash

* Once the package has been built, you can launch the simulation environment using

     $ cd /home/workspace/catkin_ws/src/scripts

     $ ./home_service.sh

