#ifndef _ROS_clearpath_base_PowerSource_h
#define _ROS_clearpath_base_PowerSource_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace clearpath_base
{

  class PowerSource : public ros::Msg
  {
    public:
      float charge;
      int16_t capacity;
      bool present;
      bool in_use;
      uint8_t description;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_charge;
      u_charge.real = this->charge;
      *(outbuffer + offset + 0) = (u_charge.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charge.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charge.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charge.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charge);
      union {
        int16_t real;
        uint16_t base;
      } u_capacity;
      u_capacity.real = this->capacity;
      *(outbuffer + offset + 0) = (u_capacity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_capacity.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->capacity);
      union {
        bool real;
        uint8_t base;
      } u_present;
      u_present.real = this->present;
      *(outbuffer + offset + 0) = (u_present.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->present);
      union {
        bool real;
        uint8_t base;
      } u_in_use;
      u_in_use.real = this->in_use;
      *(outbuffer + offset + 0) = (u_in_use.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->in_use);
      *(outbuffer + offset + 0) = (this->description >> (8 * 0)) & 0xFF;
      offset += sizeof(this->description);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_charge;
      u_charge.base = 0;
      u_charge.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charge.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charge.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charge.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->charge = u_charge.real;
      offset += sizeof(this->charge);
      union {
        int16_t real;
        uint16_t base;
      } u_capacity;
      u_capacity.base = 0;
      u_capacity.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_capacity.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->capacity = u_capacity.real;
      offset += sizeof(this->capacity);
      union {
        bool real;
        uint8_t base;
      } u_present;
      u_present.base = 0;
      u_present.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->present = u_present.real;
      offset += sizeof(this->present);
      union {
        bool real;
        uint8_t base;
      } u_in_use;
      u_in_use.base = 0;
      u_in_use.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->in_use = u_in_use.real;
      offset += sizeof(this->in_use);
      this->description =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->description);
     return offset;
    }

    const char * getType(){ return "clearpath_base/PowerSource"; };
    const char * getMD5(){ return "adbe384d7d69a337a7f2b6bf1d0139cb"; };

  };

}
#endif