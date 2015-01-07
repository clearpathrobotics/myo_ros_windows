#ifndef _ROS_clearpath_base_DifferentialSpeed_h
#define _ROS_clearpath_base_DifferentialSpeed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class DifferentialSpeed : public ros::Msg
  {
    public:
      std_msgs::Header header;
      double left_speed;
      double right_speed;
      double left_accel;
      double right_accel;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_left_speed;
      u_left_speed.real = this->left_speed;
      *(outbuffer + offset + 0) = (u_left_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_speed);
      union {
        double real;
        uint64_t base;
      } u_right_speed;
      u_right_speed.real = this->right_speed;
      *(outbuffer + offset + 0) = (u_right_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_speed);
      union {
        double real;
        uint64_t base;
      } u_left_accel;
      u_left_accel.real = this->left_accel;
      *(outbuffer + offset + 0) = (u_left_accel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_accel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_accel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_accel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_accel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_accel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_accel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_accel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_accel);
      union {
        double real;
        uint64_t base;
      } u_right_accel;
      u_right_accel.real = this->right_accel;
      *(outbuffer + offset + 0) = (u_right_accel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_accel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_accel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_accel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_accel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_accel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_accel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_accel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_accel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_left_speed;
      u_left_speed.base = 0;
      u_left_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_speed = u_left_speed.real;
      offset += sizeof(this->left_speed);
      union {
        double real;
        uint64_t base;
      } u_right_speed;
      u_right_speed.base = 0;
      u_right_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_speed = u_right_speed.real;
      offset += sizeof(this->right_speed);
      union {
        double real;
        uint64_t base;
      } u_left_accel;
      u_left_accel.base = 0;
      u_left_accel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_accel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_accel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_accel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_left_accel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_left_accel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_left_accel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_left_accel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->left_accel = u_left_accel.real;
      offset += sizeof(this->left_accel);
      union {
        double real;
        uint64_t base;
      } u_right_accel;
      u_right_accel.base = 0;
      u_right_accel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_accel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_accel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_accel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_right_accel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_right_accel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_right_accel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_right_accel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->right_accel = u_right_accel.real;
      offset += sizeof(this->right_accel);
     return offset;
    }

    const char * getType(){ return "clearpath_base/DifferentialSpeed"; };
    const char * getMD5(){ return "4b62e763320bacb9c7f63f6ebd46ceba"; };

  };

}
#endif