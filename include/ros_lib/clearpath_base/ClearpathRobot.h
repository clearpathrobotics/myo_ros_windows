#ifndef _ROS_clearpath_base_ClearpathRobot_h
#define _ROS_clearpath_base_ClearpathRobot_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace clearpath_base
{

  class ClearpathRobot : public ros::Msg
  {
    public:
      char * name;
      char * model;
      int32_t platform_revision;
      uint32_t serial;
      int32_t horizon_version[2];
      int32_t firmware_version[2];
      int32_t firmware_revision;
      char * write_date;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_model = strlen( (const char*) this->model);
      memcpy(outbuffer + offset, &length_model, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->model, length_model);
      offset += length_model;
      union {
        int32_t real;
        uint32_t base;
      } u_platform_revision;
      u_platform_revision.real = this->platform_revision;
      *(outbuffer + offset + 0) = (u_platform_revision.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_platform_revision.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_platform_revision.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_platform_revision.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->platform_revision);
      *(outbuffer + offset + 0) = (this->serial >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->serial >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->serial >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->serial >> (8 * 3)) & 0xFF;
      offset += sizeof(this->serial);
      unsigned char * horizon_version_val = (unsigned char *) this->horizon_version;
      for( uint8_t i = 0; i < 2; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_horizon_versioni;
      u_horizon_versioni.real = this->horizon_version[i];
      *(outbuffer + offset + 0) = (u_horizon_versioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_horizon_versioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_horizon_versioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_horizon_versioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->horizon_version[i]);
      }
      unsigned char * firmware_version_val = (unsigned char *) this->firmware_version;
      for( uint8_t i = 0; i < 2; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_firmware_versioni;
      u_firmware_versioni.real = this->firmware_version[i];
      *(outbuffer + offset + 0) = (u_firmware_versioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_firmware_versioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_firmware_versioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_firmware_versioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->firmware_version[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_firmware_revision;
      u_firmware_revision.real = this->firmware_revision;
      *(outbuffer + offset + 0) = (u_firmware_revision.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_firmware_revision.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_firmware_revision.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_firmware_revision.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->firmware_revision);
      uint32_t length_write_date = strlen( (const char*) this->write_date);
      memcpy(outbuffer + offset, &length_write_date, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->write_date, length_write_date);
      offset += length_write_date;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_model;
      memcpy(&length_model, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model-1]=0;
      this->model = (char *)(inbuffer + offset-1);
      offset += length_model;
      union {
        int32_t real;
        uint32_t base;
      } u_platform_revision;
      u_platform_revision.base = 0;
      u_platform_revision.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_platform_revision.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_platform_revision.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_platform_revision.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->platform_revision = u_platform_revision.real;
      offset += sizeof(this->platform_revision);
      this->serial =  ((uint32_t) (*(inbuffer + offset)));
      this->serial |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->serial |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->serial |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->serial);
      uint8_t * horizon_version_val = (uint8_t*) this->horizon_version;
      for( uint8_t i = 0; i < 2; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_horizon_versioni;
      u_horizon_versioni.base = 0;
      u_horizon_versioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_horizon_versioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_horizon_versioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_horizon_versioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->horizon_version[i] = u_horizon_versioni.real;
      offset += sizeof(this->horizon_version[i]);
      }
      uint8_t * firmware_version_val = (uint8_t*) this->firmware_version;
      for( uint8_t i = 0; i < 2; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_firmware_versioni;
      u_firmware_versioni.base = 0;
      u_firmware_versioni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_firmware_versioni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_firmware_versioni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_firmware_versioni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->firmware_version[i] = u_firmware_versioni.real;
      offset += sizeof(this->firmware_version[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_firmware_revision;
      u_firmware_revision.base = 0;
      u_firmware_revision.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_firmware_revision.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_firmware_revision.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_firmware_revision.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->firmware_revision = u_firmware_revision.real;
      offset += sizeof(this->firmware_revision);
      uint32_t length_write_date;
      memcpy(&length_write_date, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_write_date; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_write_date-1]=0;
      this->write_date = (char *)(inbuffer + offset-1);
      offset += length_write_date;
     return offset;
    }

    const char * getType(){ return "clearpath_base/ClearpathRobot"; };
    const char * getMD5(){ return "1bdab2b789676c1b350ab6739da650c7"; };

  };

}
#endif