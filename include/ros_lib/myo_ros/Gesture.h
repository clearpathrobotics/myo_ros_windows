#ifndef _ROS_myo_ros_Gesture_h
#define _ROS_myo_ros_Gesture_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace myo_ros
{

  class Gesture : public ros::Msg
  {
    public:
      int8_t gesture;
      enum { GESTURE_NONE = 0 };
      enum { GESTURE_FIST = 1 };
      enum { GESTURE_WAVE_IN = 2 };
      enum { GESTURE_WAVE_OUT = 3 };
      enum { GESTURE_FINGERS_SPREAD = 4 };
      enum { GESTURE_TWIST_IN = 5 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_gesture;
      u_gesture.real = this->gesture;
      *(outbuffer + offset + 0) = (u_gesture.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gesture);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_gesture;
      u_gesture.base = 0;
      u_gesture.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gesture = u_gesture.real;
      offset += sizeof(this->gesture);
     return offset;
    }

    const char * getType(){ return "myo_ros/Gesture"; };
    const char * getMD5(){ return "1a07228946401fd53b7c7680b24bf393"; };

  };

}
#endif