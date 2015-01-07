#ifndef _ROS_clearpath_base_TurnSetpt_h
#define _ROS_clearpath_base_TurnSetpt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class TurnSetpt : public ros::Msg
  {
    public:
      std_msgs::Header header;
      double trans_vel;
      double turn_radius;
      double trans_accel;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_trans_vel;
      u_trans_vel.real = this->trans_vel;
      *(outbuffer + offset + 0) = (u_trans_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_trans_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_trans_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_trans_vel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_trans_vel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_trans_vel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_trans_vel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_trans_vel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->trans_vel);
      union {
        double real;
        uint64_t base;
      } u_turn_radius;
      u_turn_radius.real = this->turn_radius;
      *(outbuffer + offset + 0) = (u_turn_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_turn_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_turn_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_turn_radius.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_turn_radius.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_turn_radius.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_turn_radius.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_turn_radius.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->turn_radius);
      union {
        double real;
        uint64_t base;
      } u_trans_accel;
      u_trans_accel.real = this->trans_accel;
      *(outbuffer + offset + 0) = (u_trans_accel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_trans_accel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_trans_accel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_trans_accel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_trans_accel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_trans_accel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_trans_accel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_trans_accel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->trans_accel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_trans_vel;
      u_trans_vel.base = 0;
      u_trans_vel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_trans_vel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_trans_vel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_trans_vel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_trans_vel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_trans_vel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_trans_vel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_trans_vel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->trans_vel = u_trans_vel.real;
      offset += sizeof(this->trans_vel);
      union {
        double real;
        uint64_t base;
      } u_turn_radius;
      u_turn_radius.base = 0;
      u_turn_radius.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_turn_radius.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_turn_radius.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_turn_radius.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_turn_radius.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_turn_radius.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_turn_radius.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_turn_radius.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->turn_radius = u_turn_radius.real;
      offset += sizeof(this->turn_radius);
      union {
        double real;
        uint64_t base;
      } u_trans_accel;
      u_trans_accel.base = 0;
      u_trans_accel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_trans_accel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_trans_accel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_trans_accel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_trans_accel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_trans_accel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_trans_accel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_trans_accel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->trans_accel = u_trans_accel.real;
      offset += sizeof(this->trans_accel);
     return offset;
    }

    const char * getType(){ return "clearpath_base/TurnSetpt"; };
    const char * getMD5(){ return "023314e739de17bd5207788d54c661df"; };

  };

}
#endif