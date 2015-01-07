#ifndef _ROS_clearpath_base_ProcessorStatus_h
#define _ROS_clearpath_base_ProcessorStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class ProcessorStatus : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t errors_length;
      int32_t st_errors;
      int32_t * errors;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = errors_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < errors_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_errorsi;
      u_errorsi.real = this->errors[i];
      *(outbuffer + offset + 0) = (u_errorsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_errorsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_errorsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_errorsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->errors[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t errors_lengthT = *(inbuffer + offset++);
      if(errors_lengthT > errors_length)
        this->errors = (int32_t*)realloc(this->errors, errors_lengthT * sizeof(int32_t));
      offset += 3;
      errors_length = errors_lengthT;
      for( uint8_t i = 0; i < errors_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_errors;
      u_st_errors.base = 0;
      u_st_errors.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_errors.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_errors.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_errors.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_errors = u_st_errors.real;
      offset += sizeof(this->st_errors);
        memcpy( &(this->errors[i]), &(this->st_errors), sizeof(int32_t));
      }
     return offset;
    }

    const char * getType(){ return "clearpath_base/ProcessorStatus"; };
    const char * getMD5(){ return "9d74dc2afa1a3a812e1ca5482185d3cf"; };

  };

}
#endif