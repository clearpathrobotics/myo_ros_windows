#ifndef _ROS_clearpath_base_Encoders_h
#define _ROS_clearpath_base_Encoders_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "clearpath_base/Encoder.h"

namespace clearpath_base
{

  class Encoders : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t encoders_length;
      clearpath_base::Encoder st_encoders;
      clearpath_base::Encoder * encoders;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = encoders_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < encoders_length; i++){
      offset += this->encoders[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t encoders_lengthT = *(inbuffer + offset++);
      if(encoders_lengthT > encoders_length)
        this->encoders = (clearpath_base::Encoder*)realloc(this->encoders, encoders_lengthT * sizeof(clearpath_base::Encoder));
      offset += 3;
      encoders_length = encoders_lengthT;
      for( uint8_t i = 0; i < encoders_length; i++){
      offset += this->st_encoders.deserialize(inbuffer + offset);
        memcpy( &(this->encoders[i]), &(this->st_encoders), sizeof(clearpath_base::Encoder));
      }
     return offset;
    }

    const char * getType(){ return "clearpath_base/Encoders"; };
    const char * getMD5(){ return "2ea748832c2014369ffabd316d5aad8c"; };

  };

}
#endif