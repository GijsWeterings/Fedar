# Fedar: Food Establishment Digital Autonomous Robot
Welcome to Fedar!

## Install instructions
1. If not done already, install [ROS Indigo](http://wiki.ros.org/indigo/Installation/Ubuntu).
2. Clone this project
```
git clone git@github.com:GijsWeterings/Fedar.git ~/Fedar
cd ~/Fedar
```
3. Create [Catkin workspace](http://wiki.ros.org/catkin/Tutorials/create_a_workspace)
```
source /opt/ros/indigo/setup.bash
cd ~/Fedar/src
catkin_init_workspace
cd ..
catkin_make
source devel/setup.bash
```
## Building the project
```
cd ~/Fedar
catkin_make
```
