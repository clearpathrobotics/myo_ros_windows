#ifndef _ROS_clearpath_base_DifferentialOutput_h
#define _ROS_clearpath_base_DifferentialOutput_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class DifferentialOutput : public ros::Msg
  {
    public:
      std_msgs::Header header;
      double left;
      double right;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_left;
      u_left.real = this->left;
      *(outbuffer + offset + 0) = (u_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left);
      union {
        double real;
        uint64_t base;
      } u_right;
      u_right.real = this->right;
      *(outbuffer + offset + 0) = (u_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_left;
      u_left.base = 0;
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left = u_left.real;
      offset += sizeof(this->left);
      union {
        double real;
        uint64_t base;
      } u_right;
      u_right.base = 0;
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right = u_right.real;
      offset += sizeof(this->right);
     return offset;
    }

    const char * getType(){ return "clearpath_base/DifferentialOutput"; };
    const char * getMD5(){ return "8f32685125452f5bdf68130369af5296"; };

  };

}
#endif