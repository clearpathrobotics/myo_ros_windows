#ifndef _ROS_clearpath_base_PowerStatus_h
#define _ROS_clearpath_base_PowerStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "clearpath_base/PowerSource.h"

namespace clearpath_base
{

  class PowerStatus : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t sources_length;
      clearpath_base::PowerSource st_sources;
      clearpath_base::PowerSource * sources;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = sources_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sources_length; i++){
      offset += this->sources[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t sources_lengthT = *(inbuffer + offset++);
      if(sources_lengthT > sources_length)
        this->sources = (clearpath_base::PowerSource*)realloc(this->sources, sources_lengthT * sizeof(clearpath_base::PowerSource));
      offset += 3;
      sources_length = sources_lengthT;
      for( uint8_t i = 0; i < sources_length; i++){
      offset += this->st_sources.deserialize(inbuffer + offset);
        memcpy( &(this->sources[i]), &(this->st_sources), sizeof(clearpath_base::PowerSource));
      }
     return offset;
    }

    const char * getType(){ return "clearpath_base/PowerStatus"; };
    const char * getMD5(){ return "f246c359530c58415aee4fe89d1aca04"; };

  };

}
#endif