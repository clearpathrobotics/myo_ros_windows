#ifndef _ROS_clearpath_base_SafetyStatus_h
#define _ROS_clearpath_base_SafetyStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class SafetyStatus : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t flags;
      bool estop;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flags >> (8 * 1)) & 0xFF;
      offset += sizeof(this->flags);
      union {
        bool real;
        uint8_t base;
      } u_estop;
      u_estop.real = this->estop;
      *(outbuffer + offset + 0) = (u_estop.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->estop);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->flags =  ((uint16_t) (*(inbuffer + offset)));
      this->flags |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->flags);
      union {
        bool real;
        uint8_t base;
      } u_estop;
      u_estop.base = 0;
      u_estop.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->estop = u_estop.real;
      offset += sizeof(this->estop);
     return offset;
    }

    const char * getType(){ return "clearpath_base/SafetyStatus"; };
    const char * getMD5(){ return "cf78d6042b92d64ebda55641e06d66fa"; };

  };

}
#endif