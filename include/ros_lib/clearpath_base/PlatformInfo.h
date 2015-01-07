#ifndef _ROS_clearpath_base_PlatformInfo_h
#define _ROS_clearpath_base_PlatformInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class PlatformInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      char * model;
      int8_t revision;
      uint32_t serial;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_model = strlen( (const char*) this->model);
      memcpy(outbuffer + offset, &length_model, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->model, length_model);
      offset += length_model;
      union {
        int8_t real;
        uint8_t base;
      } u_revision;
      u_revision.real = this->revision;
      *(outbuffer + offset + 0) = (u_revision.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->revision);
      *(outbuffer + offset + 0) = (this->serial >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->serial >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->serial >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->serial >> (8 * 3)) & 0xFF;
      offset += sizeof(this->serial);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
        int8_t real;
        uint8_t base;
      } u_revision;
      u_revision.base = 0;
      u_revision.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->revision = u_revision.real;
      offset += sizeof(this->revision);
      this->serial =  ((uint32_t) (*(inbuffer + offset)));
      this->serial |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->serial |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->serial |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->serial);
     return offset;
    }

    const char * getType(){ return "clearpath_base/PlatformInfo"; };
    const char * getMD5(){ return "ff95c25c6ef78f06bbb7ef85aad5735e"; };

  };

}
#endif