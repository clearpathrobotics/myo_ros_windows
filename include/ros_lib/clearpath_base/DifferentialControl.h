#ifndef _ROS_clearpath_base_DifferentialControl_h
#define _ROS_clearpath_base_DifferentialControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class DifferentialControl : public ros::Msg
  {
    public:
      std_msgs::Header header;
      double l_p;
      double l_i;
      double l_d;
      double l_ffwd;
      double l_stic;
      double l_sat;
      double r_p;
      double r_i;
      double r_d;
      double r_ffwd;
      double r_stic;
      double r_sat;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_l_p;
      u_l_p.real = this->l_p;
      *(outbuffer + offset + 0) = (u_l_p.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l_p.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l_p.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l_p.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_l_p.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_l_p.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_l_p.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_l_p.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->l_p);
      union {
        double real;
        uint64_t base;
      } u_l_i;
      u_l_i.real = this->l_i;
      *(outbuffer + offset + 0) = (u_l_i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l_i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l_i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l_i.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_l_i.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_l_i.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_l_i.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_l_i.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->l_i);
      union {
        double real;
        uint64_t base;
      } u_l_d;
      u_l_d.real = this->l_d;
      *(outbuffer + offset + 0) = (u_l_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l_d.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l_d.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l_d.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_l_d.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_l_d.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_l_d.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_l_d.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->l_d);
      union {
        double real;
        uint64_t base;
      } u_l_ffwd;
      u_l_ffwd.real = this->l_ffwd;
      *(outbuffer + offset + 0) = (u_l_ffwd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l_ffwd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l_ffwd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l_ffwd.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_l_ffwd.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_l_ffwd.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_l_ffwd.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_l_ffwd.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->l_ffwd);
      union {
        double real;
        uint64_t base;
      } u_l_stic;
      u_l_stic.real = this->l_stic;
      *(outbuffer + offset + 0) = (u_l_stic.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l_stic.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l_stic.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l_stic.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_l_stic.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_l_stic.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_l_stic.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_l_stic.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->l_stic);
      union {
        double real;
        uint64_t base;
      } u_l_sat;
      u_l_sat.real = this->l_sat;
      *(outbuffer + offset + 0) = (u_l_sat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l_sat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l_sat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l_sat.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_l_sat.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_l_sat.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_l_sat.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_l_sat.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->l_sat);
      union {
        double real;
        uint64_t base;
      } u_r_p;
      u_r_p.real = this->r_p;
      *(outbuffer + offset + 0) = (u_r_p.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r_p.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_r_p.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_r_p.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_r_p.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_r_p.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_r_p.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_r_p.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->r_p);
      union {
        double real;
        uint64_t base;
      } u_r_i;
      u_r_i.real = this->r_i;
      *(outbuffer + offset + 0) = (u_r_i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r_i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_r_i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_r_i.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_r_i.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_r_i.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_r_i.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_r_i.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->r_i);
      union {
        double real;
        uint64_t base;
      } u_r_d;
      u_r_d.real = this->r_d;
      *(outbuffer + offset + 0) = (u_r_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r_d.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_r_d.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_r_d.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_r_d.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_r_d.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_r_d.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_r_d.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->r_d);
      union {
        double real;
        uint64_t base;
      } u_r_ffwd;
      u_r_ffwd.real = this->r_ffwd;
      *(outbuffer + offset + 0) = (u_r_ffwd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r_ffwd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_r_ffwd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_r_ffwd.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_r_ffwd.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_r_ffwd.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_r_ffwd.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_r_ffwd.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->r_ffwd);
      union {
        double real;
        uint64_t base;
      } u_r_stic;
      u_r_stic.real = this->r_stic;
      *(outbuffer + offset + 0) = (u_r_stic.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r_stic.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_r_stic.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_r_stic.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_r_stic.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_r_stic.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_r_stic.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_r_stic.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->r_stic);
      union {
        double real;
        uint64_t base;
      } u_r_sat;
      u_r_sat.real = this->r_sat;
      *(outbuffer + offset + 0) = (u_r_sat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r_sat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_r_sat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_r_sat.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_r_sat.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_r_sat.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_r_sat.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_r_sat.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->r_sat);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_l_p;
      u_l_p.base = 0;
      u_l_p.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l_p.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l_p.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l_p.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_l_p.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_l_p.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_l_p.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_l_p.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->l_p = u_l_p.real;
      offset += sizeof(this->l_p);
      union {
        double real;
        uint64_t base;
      } u_l_i;
      u_l_i.base = 0;
      u_l_i.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l_i.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l_i.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l_i.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_l_i.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_l_i.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_l_i.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_l_i.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->l_i = u_l_i.real;
      offset += sizeof(this->l_i);
      union {
        double real;
        uint64_t base;
      } u_l_d;
      u_l_d.base = 0;
      u_l_d.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l_d.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l_d.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l_d.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_l_d.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_l_d.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_l_d.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_l_d.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->l_d = u_l_d.real;
      offset += sizeof(this->l_d);
      union {
        double real;
        uint64_t base;
      } u_l_ffwd;
      u_l_ffwd.base = 0;
      u_l_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_l_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_l_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_l_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_l_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->l_ffwd = u_l_ffwd.real;
      offset += sizeof(this->l_ffwd);
      union {
        double real;
        uint64_t base;
      } u_l_stic;
      u_l_stic.base = 0;
      u_l_stic.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l_stic.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l_stic.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l_stic.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_l_stic.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_l_stic.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_l_stic.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_l_stic.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->l_stic = u_l_stic.real;
      offset += sizeof(this->l_stic);
      union {
        double real;
        uint64_t base;
      } u_l_sat;
      u_l_sat.base = 0;
      u_l_sat.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l_sat.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l_sat.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l_sat.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_l_sat.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_l_sat.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_l_sat.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_l_sat.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->l_sat = u_l_sat.real;
      offset += sizeof(this->l_sat);
      union {
        double real;
        uint64_t base;
      } u_r_p;
      u_r_p.base = 0;
      u_r_p.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r_p.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_r_p.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_r_p.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_r_p.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_r_p.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_r_p.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_r_p.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->r_p = u_r_p.real;
      offset += sizeof(this->r_p);
      union {
        double real;
        uint64_t base;
      } u_r_i;
      u_r_i.base = 0;
      u_r_i.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r_i.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_r_i.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_r_i.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_r_i.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_r_i.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_r_i.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_r_i.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->r_i = u_r_i.real;
      offset += sizeof(this->r_i);
      union {
        double real;
        uint64_t base;
      } u_r_d;
      u_r_d.base = 0;
      u_r_d.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r_d.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_r_d.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_r_d.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_r_d.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_r_d.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_r_d.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_r_d.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->r_d = u_r_d.real;
      offset += sizeof(this->r_d);
      union {
        double real;
        uint64_t base;
      } u_r_ffwd;
      u_r_ffwd.base = 0;
      u_r_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_r_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_r_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_r_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_r_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_r_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_r_ffwd.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->r_ffwd = u_r_ffwd.real;
      offset += sizeof(this->r_ffwd);
      union {
        double real;
        uint64_t base;
      } u_r_stic;
      u_r_stic.base = 0;
      u_r_stic.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r_stic.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_r_stic.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_r_stic.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_r_stic.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_r_stic.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_r_stic.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_r_stic.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->r_stic = u_r_stic.real;
      offset += sizeof(this->r_stic);
      union {
        double real;
        uint64_t base;
      } u_r_sat;
      u_r_sat.base = 0;
      u_r_sat.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r_sat.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_r_sat.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_r_sat.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_r_sat.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_r_sat.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_r_sat.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_r_sat.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->r_sat = u_r_sat.real;
      offset += sizeof(this->r_sat);
     return offset;
    }

    const char * getType(){ return "clearpath_base/DifferentialControl"; };
    const char * getMD5(){ return "ae0672163e13fc0bb6491960c53a3259"; };

  };

}
#endif