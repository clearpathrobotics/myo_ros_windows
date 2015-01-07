# myo_ros_windows

## Overview
This serves as the Windows-side portion of what is required to get Myo to work on a ROS network. It broadcasts the data as low-level as possible and relies on nodes running in ROS to translate the data into robot commands. Note: This approach may be revisited if the goal is to avoid modification to out-of-the-box robot software configurations, as there are standards for robots responding to cmd_vel, but nothing regarding exposing orientations (for example) as an input format. For now, the idea is that transforms from Myo data to commands (ex. Twist messages) would take place on the ROS side, and examples should be in the myo_ros package (not the myo_ros_windows package).

At present, the integration with ROS is accomplished via rosserial. The rosserial libraries currently sit in include/ros_lib. 

Sources for the Myo-specific messages currently live in the "myo_ros" package, along with the actual translations between Myo topics and robot behaviour. They are exported into the rosserial libraries upon rosserial library generation.

API is as of SDK v0.8.0. Requires Visual Studio 2013+ to compile due to new support being added for round().

## ROS API
### Subscribed Topics
- vibration (myo_ros/Vibration.msg): A vibration pattern for the Myo
- unlock_override (std_msgs/Bool.msg): Set to true to disable the Myo locking after it's been locked for the first time.

### Published Topics
- rotation (geometry_msgs/Quaternion.msg): The rotation of the Myo. Myo coordinate frames still TBA by Thalmic.
- gesture (myo_ros/Gesture.msg): Gesture as detected by the Myo
- gyro (geometry_msgs/Vector3): Gyroscope data in deg/s
- accel (geometry_msgs/Vector3): Accelerometer data in g
- status (myo_ros/Status.msg): Status of the Myo

## Maybe:
- Broadcast tfs by default? This may be best suited as a translation which occurs on the ROS side due to the larger amount of built-in related libraries

## TODO:
- Broadcast an IMU message (need covariance for this)