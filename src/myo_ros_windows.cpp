// Copyright (C) 2013-2014 Thalmic Labs Inc.
// Confidential and not for redistribution. See LICENSE.txt.
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

// The only file that needs to be included to use the Myo C++ SDK is myo.hpp.
#include <myo/myo.hpp>

// ROS/rosserial includes
#include "ros.h"
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Quaternion.h>
#include <myo_ros/Gesture.h>
#include <myo_ros/Vibration.h>
#include <myo_ros/Status.h>
#include <std_msgs/Bool.h>

// Static classes that handle callbacks + Myo instance
// This is a limitation of rosserial + Windows. In uCs, this doesn't matter, and in Linux, we use boost::bind
myo::Myo* my_myo = NULL;

// Creates vibrations
void vibrationCallback(const myo_ros::Vibration& vibration) {
	if (my_myo) {
		my_myo->vibrate(static_cast<myo::Myo::VibrationType>(vibration.vibration));
	}
}

// Sets the unlock timing
void unlockCallback(const std_msgs::Bool& unlock) {
	if (my_myo) {
		if (unlock.data == true)
		{
			my_myo->unlock(myo::Myo::unlockHold);
		}
		else
		{
			my_myo->unlock(myo::Myo::unlockTimed);
		}
	}
}

// Classes that inherit from myo::DeviceListener can be used to receive events from Myo devices. DeviceListener
// provides several virtual functions for handling different kinds of events. If you do not override an event, the
// default behavior is to do nothing.
class DataCollector : public myo::DeviceListener {
public:
	// Information that will be going out
	geometry_msgs::Quaternion msg_rotation;
	myo_ros::Gesture msg_gesture;
	myo_ros::Status msg_status;
	geometry_msgs::Vector3 msg_gyro;
	geometry_msgs::Vector3 msg_accel;

	// Various pointers - Pointers because rosserial publishers don't have default constructors yet
	ros::Publisher* pub_rotation;
	ros::Publisher* pub_gesture;
	ros::Publisher* pub_gyro;
	ros::Publisher* pub_accel;
	ros::Publisher* pub_status;
	ros::Subscriber<myo_ros::Vibration>* sub_vibration;
	ros::Subscriber<std_msgs::Bool>* sub_unlock_override;

    DataCollector(ros::NodeHandle &nh)
    {

		// Subscribe & publish setup
		pub_rotation = new ros::Publisher("rotation", &msg_rotation);
		nh.advertise(*pub_rotation);
		pub_gesture = new ros::Publisher("gesture", &msg_gesture);
		nh.advertise(*pub_gesture);
		pub_gyro = new ros::Publisher("gyro", &msg_gyro);
		nh.advertise(*pub_gyro);
		pub_accel = new ros::Publisher("accel", &msg_accel);
		nh.advertise(*pub_accel);
		pub_status = new ros::Publisher("status", &msg_status);
		nh.advertise(*pub_status);

		sub_vibration = new ros::Subscriber<myo_ros::Vibration>("vibration", &vibrationCallback);
		nh.subscribe(*sub_vibration);
		sub_unlock_override = new ros::Subscriber<std_msgs::Bool>("unlock_override", &unlockCallback);
		nh.subscribe(*sub_unlock_override);
    }

	// onConnect() is called when a paired Myo is connected
	void onConnect(myo::Myo* myo, uint64_t timestamp) {
		my_myo = myo;
	}

	// onConnect() is called when a paired Myo is disconnected
	void onDisconnect(myo::Myo* myo, uint64_t timestamp) {
		my_myo = NULL;
	}

    // onOrientationData() is called whenever the Myo device provides its current orientation, which is represented
    // as a unit quaternion.
    void onOrientationData(myo::Myo* myo, uint64_t timestamp, const myo::Quaternion<float>& quat)
    {
		msg_rotation.w = quat.w();
		msg_rotation.x = quat.x();
		msg_rotation.y = quat.y();
		msg_rotation.z = quat.z();
		pub_rotation->publish(&msg_rotation);
    }

    // onPose() is called whenever the Myo detects that the person wearing it has changed their pose, for example,
    // making a fist, or not making a fist anymore.
    void onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose)
    {
		msg_gesture.gesture = pose.type();
		pub_gesture->publish(&msg_gesture);
    }

	// onGyroscopeData() called when a paired Myo has provided new gyroscope data in units of deg/s
	void onGyroscopeData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3<float> &gyro) {
		msg_gyro.x = gyro.x();
		msg_gyro.y = gyro.y();
		msg_gyro.z = gyro.z();
		pub_gyro->publish(&msg_gyro);
	}

	// onAccelerometerData() called when a paired Myo has provided new accelerometer data in units of g.
	void onAccelerometerData(myo::Myo *myo, uint64_t timestamp, const myo::Vector3< float > &accel) {
		msg_accel.x = accel.x();
		msg_accel.y = accel.y();
		msg_accel.z = accel.z();
		pub_accel->publish(&msg_accel);
	}

	// onArmSync() is called whenever Myo has recognized a Sync Gesture after someone has put it on their
	// arm. This lets Myo know which arm it's on and which way it's facing.
	void onArmSync(myo::Myo* myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection)
	{
		msg_status.sync = true;
		msg_status.unlock = false; 
		msg_status.arm = static_cast<int8_t>(arm);
		msg_status.direction = static_cast<int8_t>(xDirection);
		pub_status->publish(&msg_status);
	}

	// onArmUnsync() is called whenever Myo has detected that it was moved from a stable position on a person's arm after
	// it recognized the arm. Typically this happens when someone takes Myo off of their arm, but it can also happen
	// when Myo is moved around on the arm.
	void onArmUnsync(myo::Myo* myo, uint64_t timestamp)
	{
		msg_status.sync = false;
		msg_status.unlock = false;
		msg_status.arm = static_cast<int8_t>(myo::armUnknown);
		msg_status.direction = static_cast<int8_t>(myo::xDirectionUnknown);
		pub_status->publish(&msg_status);
	}

	// onUnlock() is called whenever Myo has become unlocked, and will start delivering pose events.
	void onUnlock(myo::Myo* myo, uint64_t timestamp)
	{
		msg_status.unlock = true;
		pub_status->publish(&msg_status);
	}

	// onLock() is called whenever Myo has become locked. No pose events will be sent until the Myo is unlocked again.
	void onLock(myo::Myo* myo, uint64_t timestamp)
	{
		msg_status.unlock = false;
		pub_status->publish(&msg_status);
	}
};

int main(int argc, char** argv)
{
    // We catch any exceptions that might occur below -- see the catch statement for more details.
    try {

    // First, we create a Hub. The Hub provides access to one or more Myos.
    myo::Hub hub("org.ros.myo_ros_windows");

    std::cout << "Attempting to find a Myo..." << std::endl;

    // Next, we try to find a Myo (any Myo) that's nearby and connect to it. waitForAnyMyo() takes a timeout
    // value in milliseconds. In this case we will try to find a Myo for 10 seconds, and if that fails, the function
    // will return a null pointer.
	my_myo = hub.waitForMyo(10000);

    // If waitForMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
	if (!my_myo) {
        throw std::runtime_error("Unable to find a Myo!");
    }

    // We've found a Myo, let's output its MAC address.
    std::cout << "Connected to a Myo." << std::endl << std::endl;

	// Now we connect to ROS
	ros::NodeHandle nh;
	if (argc < 2) {
		std::cout << "No server:port argument found, using localhost:11411";
		nh.initNode("localhost:11411");
	}
	else {
		nh.initNode(argv[1]);
	}

    // Next we construct an instance of our DeviceListener, so that we can register it with the Hub.
    DataCollector collector (nh);

    // Hub::addListener() takes the address of any object whose class inherits from DeviceListener, and will cause
    // Hub::run() to send events to all registered device listeners.
    hub.addListener(&collector);

    // Finally we enter our main loop.
    while (1) {
        // In each iteration of our main loop, we run the Myo event loop for a set number of milliseconds.
        // In this case, we wish to update our display 20 times a second, so we run for 1000/20 milliseconds.
        hub.run(1000/20);

		// Spin ROS
		nh.spinOnce();
    }

    // If a standard exception occurred, we print out its message and exit.
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "Press enter to continue.";
        std::cin.ignore();
        return 1;
    }
}
