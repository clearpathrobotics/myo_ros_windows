#ifndef _ROS_myo_ros_Vibration_h
#define _ROS_myo_ros_Vibration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace myo_ros
{

  class Vibration : public ros::Msg
  {
    public:
      int8_t vibration;
      enum { VIBRATION_SHORT = 0 };
      enum { VIBRATION_MEDIUM = 1 };
      enum { VIBRATION_LONG = 2 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_vibration;
      u_vibration.real = this->vibration;
      *(outbuffer + offset + 0) = (u_vibration.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vibration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_vibration;
      u_vibration.base = 0;
      u_vibration.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->vibration = u_vibration.real;
      offset += sizeof(this->vibration);
     return offset;
    }

    const char * getType(){ return "myo_ros/Vibration"; };
    const char * getMD5(){ return "a04c436c928c55e5388a6669b535a8cc"; };

  };

}
#endif