#ifndef _ROS_myo_ros_Status_h
#define _ROS_myo_ros_Status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace myo_ros
{

  class Status : public ros::Msg
  {
    public:
      bool sync;
      bool unlock;
      int8_t arm;
      int8_t direction;
      enum { ARM_RIGHT = 0 };
      enum { ARM_LEFT = 1 };
      enum { ARM_UNKNOWN = 2 };
      enum { DIR_WRIST = 0 };
      enum { DIR_ELBOW = 1 };
      enum { DIR_UNKNOWN = 2 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_sync;
      u_sync.real = this->sync;
      *(outbuffer + offset + 0) = (u_sync.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sync);
      union {
        bool real;
        uint8_t base;
      } u_unlock;
      u_unlock.real = this->unlock;
      *(outbuffer + offset + 0) = (u_unlock.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->unlock);
      union {
        int8_t real;
        uint8_t base;
      } u_arm;
      u_arm.real = this->arm;
      *(outbuffer + offset + 0) = (u_arm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->arm);
      union {
        int8_t real;
        uint8_t base;
      } u_direction;
      u_direction.real = this->direction;
      *(outbuffer + offset + 0) = (u_direction.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->direction);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_sync;
      u_sync.base = 0;
      u_sync.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sync = u_sync.real;
      offset += sizeof(this->sync);
      union {
        bool real;
        uint8_t base;
      } u_unlock;
      u_unlock.base = 0;
      u_unlock.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->unlock = u_unlock.real;
      offset += sizeof(this->unlock);
      union {
        int8_t real;
        uint8_t base;
      } u_arm;
      u_arm.base = 0;
      u_arm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->arm = u_arm.real;
      offset += sizeof(this->arm);
      union {
        int8_t real;
        uint8_t base;
      } u_direction;
      u_direction.base = 0;
      u_direction.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->direction = u_direction.real;
      offset += sizeof(this->direction);
     return offset;
    }

    const char * getType(){ return "myo_ros/Status"; };
    const char * getMD5(){ return "9a559e7a7b7cc8b08470c0498ffb52d6"; };

  };

}
#endif