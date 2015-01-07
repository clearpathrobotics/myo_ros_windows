#ifndef _ROS_clearpath_base_DistanceTiming_h
#define _ROS_clearpath_base_DistanceTiming_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class DistanceTiming : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t distances_length;
      double st_distances;
      double * distances;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = distances_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < distances_length; i++){
      union {
        double real;
        uint64_t base;
      } u_distancesi;
      u_distancesi.real = this->distances[i];
      *(outbuffer + offset + 0) = (u_distancesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distancesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distancesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distancesi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_distancesi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_distancesi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_distancesi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_distancesi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->distances[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t distances_lengthT = *(inbuffer + offset++);
      if(distances_lengthT > distances_length)
        this->distances = (double*)realloc(this->distances, distances_lengthT * sizeof(double));
      offset += 3;
      distances_length = distances_lengthT;
      for( uint8_t i = 0; i < distances_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_distances;
      u_st_distances.base = 0;
      u_st_distances.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_distances.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_distances.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_distances.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_distances.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_distances.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_distances.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_distances.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_distances = u_st_distances.real;
      offset += sizeof(this->st_distances);
        memcpy( &(this->distances[i]), &(this->st_distances), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "clearpath_base/DistanceTiming"; };
    const char * getMD5(){ return "5cd97954696edc5d59dd80cb0218765a"; };

  };

}
#endif