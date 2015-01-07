#ifndef _ROS_grizzly_msgs_RawStatus_h
#define _ROS_grizzly_msgs_RawStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace grizzly_msgs
{

  class RawStatus : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float voltage;
      float user_current;
      float body_temp_adc;
      bool fans_on;
      int16_t rc_override;
      uint16_t rc_velocity;
      uint16_t rc_rotation;
      uint8_t error;
      enum { ERROR_COMMAND_TIMEOUT = 1 };
      enum { ERROR_UNDERVOLT = 2 };
      enum { ERROR_ESTOP = 4 };
      enum { ERROR_ESTOP_RESET = 8 };
      enum { ERROR_BRK_DET = 16 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
      union {
        float real;
        uint32_t base;
      } u_user_current;
      u_user_current.real = this->user_current;
      *(outbuffer + offset + 0) = (u_user_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_user_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_user_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_user_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->user_current);
      union {
        float real;
        uint32_t base;
      } u_body_temp_adc;
      u_body_temp_adc.real = this->body_temp_adc;
      *(outbuffer + offset + 0) = (u_body_temp_adc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_body_temp_adc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_body_temp_adc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_body_temp_adc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->body_temp_adc);
      union {
        bool real;
        uint8_t base;
      } u_fans_on;
      u_fans_on.real = this->fans_on;
      *(outbuffer + offset + 0) = (u_fans_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fans_on);
      union {
        int16_t real;
        uint16_t base;
      } u_rc_override;
      u_rc_override.real = this->rc_override;
      *(outbuffer + offset + 0) = (u_rc_override.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rc_override.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rc_override);
      *(outbuffer + offset + 0) = (this->rc_velocity >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rc_velocity >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rc_velocity);
      *(outbuffer + offset + 0) = (this->rc_rotation >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rc_rotation >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rc_rotation);
      *(outbuffer + offset + 0) = (this->error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      union {
        float real;
        uint32_t base;
      } u_user_current;
      u_user_current.base = 0;
      u_user_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_user_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_user_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_user_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->user_current = u_user_current.real;
      offset += sizeof(this->user_current);
      union {
        float real;
        uint32_t base;
      } u_body_temp_adc;
      u_body_temp_adc.base = 0;
      u_body_temp_adc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_body_temp_adc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_body_temp_adc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_body_temp_adc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->body_temp_adc = u_body_temp_adc.real;
      offset += sizeof(this->body_temp_adc);
      union {
        bool real;
        uint8_t base;
      } u_fans_on;
      u_fans_on.base = 0;
      u_fans_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fans_on = u_fans_on.real;
      offset += sizeof(this->fans_on);
      union {
        int16_t real;
        uint16_t base;
      } u_rc_override;
      u_rc_override.base = 0;
      u_rc_override.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rc_override.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->rc_override = u_rc_override.real;
      offset += sizeof(this->rc_override);
      this->rc_velocity =  ((uint16_t) (*(inbuffer + offset)));
      this->rc_velocity |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->rc_velocity);
      this->rc_rotation =  ((uint16_t) (*(inbuffer + offset)));
      this->rc_rotation |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->rc_rotation);
      this->error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->error);
     return offset;
    }

    const char * getType(){ return "grizzly_msgs/RawStatus"; };
    const char * getMD5(){ return "1f60c3c0abd6518a31d1f3fa02872ac9"; };

  };

}
#endif