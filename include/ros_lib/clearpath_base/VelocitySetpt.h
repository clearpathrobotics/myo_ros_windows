#ifndef _ROS_clearpath_base_VelocitySetpt_h
#define _ROS_clearpath_base_VelocitySetpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class VelocitySetpt : public ros::Msg
  {
    public:
      std_msgs::Header header;
      double trans;
      double rot;
      double accel;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_trans;
      u_trans.real = this->trans;
      *(outbuffer + offset + 0) = (u_trans.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_trans.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_trans.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_trans.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_trans.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_trans.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_trans.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_trans.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->trans);
      union {
        double real;
        uint64_t base;
      } u_rot;
      u_rot.real = this->rot;
      *(outbuffer + offset + 0) = (u_rot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rot.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rot.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rot.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rot.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rot.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rot);
      union {
        double real;
        uint64_t base;
      } u_accel;
      u_accel.real = this->accel;
      *(outbuffer + offset + 0) = (u_accel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_accel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_accel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_accel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_accel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->accel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_trans;
      u_trans.base = 0;
      u_trans.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_trans.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_trans.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_trans.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_trans.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_trans.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_trans.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_trans.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->trans = u_trans.real;
      offset += sizeof(this->trans);
      union {
        double real;
        uint64_t base;
      } u_rot;
      u_rot.base = 0;
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rot = u_rot.real;
      offset += sizeof(this->rot);
      union {
        double real;
        uint64_t base;
      } u_accel;
      u_accel.base = 0;
      u_accel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_accel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_accel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_accel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_accel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->accel = u_accel.real;
      offset += sizeof(this->accel);
     return offset;
    }

    const char * getType(){ return "clearpath_base/VelocitySetpt"; };
    const char * getMD5(){ return "7484db97a3f5854502dee1b95a48014c"; };

  };

}
#endif