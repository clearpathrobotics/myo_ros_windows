#ifndef _ROS_grizzly_msgs_Ambience_h
#define _ROS_grizzly_msgs_Ambience_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace grizzly_msgs
{

  class Ambience : public ros::Msg
  {
    public:
      uint8_t position_light;
      uint8_t autopilot_light;
      uint8_t beacon;
      uint8_t headlight;
      uint8_t taillight;
      uint8_t beep;
      enum { PATTERN_ON = 255 };
      enum { PATTERN_FLASH = 15 };
      enum { PATTERN_DFLASH = 9 };
      enum { PATTERN_QUICKFLASH = 1 };
      enum { PATTERN_OFF = 0 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->position_light >> (8 * 0)) & 0xFF;
      offset += sizeof(this->position_light);
      *(outbuffer + offset + 0) = (this->autopilot_light >> (8 * 0)) & 0xFF;
      offset += sizeof(this->autopilot_light);
      *(outbuffer + offset + 0) = (this->beacon >> (8 * 0)) & 0xFF;
      offset += sizeof(this->beacon);
      *(outbuffer + offset + 0) = (this->headlight >> (8 * 0)) & 0xFF;
      offset += sizeof(this->headlight);
      *(outbuffer + offset + 0) = (this->taillight >> (8 * 0)) & 0xFF;
      offset += sizeof(this->taillight);
      *(outbuffer + offset + 0) = (this->beep >> (8 * 0)) & 0xFF;
      offset += sizeof(this->beep);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->position_light =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->position_light);
      this->autopilot_light =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->autopilot_light);
      this->beacon =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->beacon);
      this->headlight =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->headlight);
      this->taillight =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->taillight);
      this->beep =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->beep);
     return offset;
    }

    const char * getType(){ return "grizzly_msgs/Ambience"; };
    const char * getMD5(){ return "61f98d62162f451c695060a2c339b6b0"; };

  };

}
#endif