#ifndef _ROS_clearpath_base_AckermannSetpt_h
#define _ROS_clearpath_base_AckermannSetpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class AckermannSetpt : public ros::Msg
  {
    public:
      std_msgs::Header header;
      double steering;
      double throttle;
      double brake;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_steering;
      u_steering.real = this->steering;
      *(outbuffer + offset + 0) = (u_steering.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steering.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steering.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_steering.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_steering.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_steering.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_steering.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->steering);
      union {
        double real;
        uint64_t base;
      } u_throttle;
      u_throttle.real = this->throttle;
      *(outbuffer + offset + 0) = (u_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_throttle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_throttle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_throttle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_throttle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->throttle);
      union {
        double real;
        uint64_t base;
      } u_brake;
      u_brake.real = this->brake;
      *(outbuffer + offset + 0) = (u_brake.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brake.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brake.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brake.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_brake.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_brake.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_brake.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_brake.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->brake);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_steering;
      u_steering.base = 0;
      u_steering.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steering.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steering.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_steering.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_steering.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_steering.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_steering.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->steering = u_steering.real;
      offset += sizeof(this->steering);
      union {
        double real;
        uint64_t base;
      } u_throttle;
      u_throttle.base = 0;
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_throttle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->throttle = u_throttle.real;
      offset += sizeof(this->throttle);
      union {
        double real;
        uint64_t base;
      } u_brake;
      u_brake.base = 0;
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_brake.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->brake = u_brake.real;
      offset += sizeof(this->brake);
     return offset;
    }

    const char * getType(){ return "clearpath_base/AckermannSetpt"; };
    const char * getMD5(){ return "46d60e86aa5967736d40185bb6efb208"; };

  };

}
#endif