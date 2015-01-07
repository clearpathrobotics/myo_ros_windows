#ifndef _ROS_multi_msgs_Agent_h
#define _ROS_multi_msgs_Agent_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

namespace multi_msgs
{

  class Agent : public ros::Msg
  {
    public:
      geometry_msgs::PoseWithCovarianceStamped pose;
      uint8_t compatible_tasks_length;
      int16_t st_compatible_tasks;
      int16_t * compatible_tasks;
      float energy;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset++) = compatible_tasks_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < compatible_tasks_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_compatible_tasksi;
      u_compatible_tasksi.real = this->compatible_tasks[i];
      *(outbuffer + offset + 0) = (u_compatible_tasksi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_compatible_tasksi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->compatible_tasks[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_energy;
      u_energy.real = this->energy;
      *(outbuffer + offset + 0) = (u_energy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_energy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_energy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_energy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->energy);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      uint8_t compatible_tasks_lengthT = *(inbuffer + offset++);
      if(compatible_tasks_lengthT > compatible_tasks_length)
        this->compatible_tasks = (int16_t*)realloc(this->compatible_tasks, compatible_tasks_lengthT * sizeof(int16_t));
      offset += 3;
      compatible_tasks_length = compatible_tasks_lengthT;
      for( uint8_t i = 0; i < compatible_tasks_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_compatible_tasks;
      u_st_compatible_tasks.base = 0;
      u_st_compatible_tasks.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_compatible_tasks.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_compatible_tasks = u_st_compatible_tasks.real;
      offset += sizeof(this->st_compatible_tasks);
        memcpy( &(this->compatible_tasks[i]), &(this->st_compatible_tasks), sizeof(int16_t));
      }
      union {
        float real;
        uint32_t base;
      } u_energy;
      u_energy.base = 0;
      u_energy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_energy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_energy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_energy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->energy = u_energy.real;
      offset += sizeof(this->energy);
     return offset;
    }

    const char * getType(){ return "multi_msgs/Agent"; };
    const char * getMD5(){ return "45a9c23d3d62eb2e3cada5d8cd3c1073"; };

  };

}
#endif