#ifndef _ROS_clearpath_base_FirmwareInfo_h
#define _ROS_clearpath_base_FirmwareInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class FirmwareInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int8_t firmware_major;
      int8_t firmware_minor;
      int8_t protocol_major;
      int8_t protocol_minor;
      uint32_t firmware_write_time;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_firmware_major;
      u_firmware_major.real = this->firmware_major;
      *(outbuffer + offset + 0) = (u_firmware_major.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->firmware_major);
      union {
        int8_t real;
        uint8_t base;
      } u_firmware_minor;
      u_firmware_minor.real = this->firmware_minor;
      *(outbuffer + offset + 0) = (u_firmware_minor.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->firmware_minor);
      union {
        int8_t real;
        uint8_t base;
      } u_protocol_major;
      u_protocol_major.real = this->protocol_major;
      *(outbuffer + offset + 0) = (u_protocol_major.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->protocol_major);
      union {
        int8_t real;
        uint8_t base;
      } u_protocol_minor;
      u_protocol_minor.real = this->protocol_minor;
      *(outbuffer + offset + 0) = (u_protocol_minor.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->protocol_minor);
      *(outbuffer + offset + 0) = (this->firmware_write_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->firmware_write_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->firmware_write_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->firmware_write_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->firmware_write_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_firmware_major;
      u_firmware_major.base = 0;
      u_firmware_major.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->firmware_major = u_firmware_major.real;
      offset += sizeof(this->firmware_major);
      union {
        int8_t real;
        uint8_t base;
      } u_firmware_minor;
      u_firmware_minor.base = 0;
      u_firmware_minor.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->firmware_minor = u_firmware_minor.real;
      offset += sizeof(this->firmware_minor);
      union {
        int8_t real;
        uint8_t base;
      } u_protocol_major;
      u_protocol_major.base = 0;
      u_protocol_major.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->protocol_major = u_protocol_major.real;
      offset += sizeof(this->protocol_major);
      union {
        int8_t real;
        uint8_t base;
      } u_protocol_minor;
      u_protocol_minor.base = 0;
      u_protocol_minor.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->protocol_minor = u_protocol_minor.real;
      offset += sizeof(this->protocol_minor);
      this->firmware_write_time =  ((uint32_t) (*(inbuffer + offset)));
      this->firmware_write_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->firmware_write_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->firmware_write_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->firmware_write_time);
     return offset;
    }

    const char * getType(){ return "clearpath_base/FirmwareInfo"; };
    const char * getMD5(){ return "dd399eb9c7b3816e8bea664a45a7e9ea"; };

  };

}
#endif