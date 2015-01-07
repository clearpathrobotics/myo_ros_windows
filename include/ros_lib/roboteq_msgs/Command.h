#ifndef _ROS_roboteq_msgs_Command_h
#define _ROS_roboteq_msgs_Command_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roboteq_msgs
{

  class Command : public ros::Msg
  {
    public:
      float commanded_velocity;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_commanded_velocity;
      u_commanded_velocity.real = this->commanded_velocity;
      *(outbuffer + offset + 0) = (u_commanded_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_commanded_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_commanded_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_commanded_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->commanded_velocity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_commanded_velocity;
      u_commanded_velocity.base = 0;
      u_commanded_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_commanded_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_commanded_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_commanded_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->commanded_velocity = u_commanded_velocity.real;
      offset += sizeof(this->commanded_velocity);
     return offset;
    }

    const char * getType(){ return "roboteq_msgs/Command"; };
    const char * getMD5(){ return "55127b9d38b8d2d2ecd090775b958451"; };

  };

}
#endif