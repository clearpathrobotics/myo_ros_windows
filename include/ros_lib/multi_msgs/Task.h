#ifndef _ROS_multi_msgs_Task_h
#define _ROS_multi_msgs_Task_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace multi_msgs
{

  class Task : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped pose;
      uint64_t task_id;
      uint8_t prev_task_id_length;
      uint64_t st_prev_task_id;
      uint64_t * prev_task_id;
      int16_t task_type;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_task_id;
      u_task_id.real = this->task_id;
      *(outbuffer + offset + 0) = (u_task_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_task_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_task_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_task_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->task_id);
      *(outbuffer + offset++) = prev_task_id_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < prev_task_id_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_prev_task_idi;
      u_prev_task_idi.real = this->prev_task_id[i];
      *(outbuffer + offset + 0) = (u_prev_task_idi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_prev_task_idi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_prev_task_idi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_prev_task_idi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->prev_task_id[i]);
      }
      union {
        int16_t real;
        uint16_t base;
      } u_task_type;
      u_task_type.real = this->task_type;
      *(outbuffer + offset + 0) = (u_task_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_task_type.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->task_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_task_id;
      u_task_id.base = 0;
      u_task_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_task_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_task_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_task_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->task_id = u_task_id.real;
      offset += sizeof(this->task_id);
      uint8_t prev_task_id_lengthT = *(inbuffer + offset++);
      if(prev_task_id_lengthT > prev_task_id_length)
        this->prev_task_id = (uint64_t*)realloc(this->prev_task_id, prev_task_id_lengthT * sizeof(uint64_t));
      offset += 3;
      prev_task_id_length = prev_task_id_lengthT;
      for( uint8_t i = 0; i < prev_task_id_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_st_prev_task_id;
      u_st_prev_task_id.base = 0;
      u_st_prev_task_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_prev_task_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_prev_task_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_prev_task_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_prev_task_id = u_st_prev_task_id.real;
      offset += sizeof(this->st_prev_task_id);
        memcpy( &(this->prev_task_id[i]), &(this->st_prev_task_id), sizeof(uint64_t));
      }
      union {
        int16_t real;
        uint16_t base;
      } u_task_type;
      u_task_type.base = 0;
      u_task_type.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_task_type.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->task_type = u_task_type.real;
      offset += sizeof(this->task_type);
     return offset;
    }

    const char * getType(){ return "multi_msgs/Task"; };
    const char * getMD5(){ return "eca4ae9bf91c4d8681585c586d145014"; };

  };

}
#endif