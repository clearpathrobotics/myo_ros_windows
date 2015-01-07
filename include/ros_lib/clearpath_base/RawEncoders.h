#ifndef _ROS_clearpath_base_RawEncoders_h
#define _ROS_clearpath_base_RawEncoders_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class RawEncoders : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t ticks_length;
      int32_t st_ticks;
      int32_t * ticks;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = ticks_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ticks_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_ticksi;
      u_ticksi.real = this->ticks[i];
      *(outbuffer + offset + 0) = (u_ticksi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ticksi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ticksi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ticksi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ticks[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t ticks_lengthT = *(inbuffer + offset++);
      if(ticks_lengthT > ticks_length)
        this->ticks = (int32_t*)realloc(this->ticks, ticks_lengthT * sizeof(int32_t));
      offset += 3;
      ticks_length = ticks_lengthT;
      for( uint8_t i = 0; i < ticks_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_ticks;
      u_st_ticks.base = 0;
      u_st_ticks.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ticks.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ticks.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ticks.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_ticks = u_st_ticks.real;
      offset += sizeof(this->st_ticks);
        memcpy( &(this->ticks[i]), &(this->st_ticks), sizeof(int32_t));
      }
     return offset;
    }

    const char * getType(){ return "clearpath_base/RawEncoders"; };
    const char * getMD5(){ return "d105c5e4b407d4a68215fce86175fe75"; };

  };

}
#endif