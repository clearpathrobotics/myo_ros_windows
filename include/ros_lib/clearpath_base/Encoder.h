#ifndef _ROS_clearpath_base_Encoder_h
#define _ROS_clearpath_base_Encoder_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace clearpath_base
{

  class Encoder : public ros::Msg
  {
    public:
      double travel;
      double speed;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_travel;
      u_travel.real = this->travel;
      *(outbuffer + offset + 0) = (u_travel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_travel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_travel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_travel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_travel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_travel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_travel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_travel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->travel);
      union {
        double real;
        uint64_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_travel;
      u_travel.base = 0;
      u_travel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_travel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_travel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_travel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_travel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_travel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_travel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_travel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->travel = u_travel.real;
      offset += sizeof(this->travel);
      union {
        double real;
        uint64_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
     return offset;
    }

    const char * getType(){ return "clearpath_base/Encoder"; };
    const char * getMD5(){ return "620a74fe7e8deb0e96bf85b534453633"; };

  };

}
#endif