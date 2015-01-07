#ifndef _ROS_clearpath_base_SystemStatus_h
#define _ROS_clearpath_base_SystemStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace clearpath_base
{

  class SystemStatus : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t uptime;
      uint8_t voltages_length;
      double st_voltages;
      double * voltages;
      uint8_t currents_length;
      double st_currents;
      double * currents;
      uint8_t temperatures_length;
      double st_temperatures;
      double * temperatures;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->uptime >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uptime >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->uptime >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->uptime >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uptime);
      *(outbuffer + offset++) = voltages_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < voltages_length; i++){
      union {
        double real;
        uint64_t base;
      } u_voltagesi;
      u_voltagesi.real = this->voltages[i];
      *(outbuffer + offset + 0) = (u_voltagesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltagesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltagesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltagesi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_voltagesi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_voltagesi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_voltagesi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_voltagesi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->voltages[i]);
      }
      *(outbuffer + offset++) = currents_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < currents_length; i++){
      union {
        double real;
        uint64_t base;
      } u_currentsi;
      u_currentsi.real = this->currents[i];
      *(outbuffer + offset + 0) = (u_currentsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_currentsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_currentsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_currentsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_currentsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_currentsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_currentsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_currentsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->currents[i]);
      }
      *(outbuffer + offset++) = temperatures_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < temperatures_length; i++){
      union {
        double real;
        uint64_t base;
      } u_temperaturesi;
      u_temperaturesi.real = this->temperatures[i];
      *(outbuffer + offset + 0) = (u_temperaturesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperaturesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperaturesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperaturesi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_temperaturesi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_temperaturesi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_temperaturesi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_temperaturesi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->temperatures[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->uptime =  ((uint32_t) (*(inbuffer + offset)));
      this->uptime |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->uptime |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->uptime |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->uptime);
      uint8_t voltages_lengthT = *(inbuffer + offset++);
      if(voltages_lengthT > voltages_length)
        this->voltages = (double*)realloc(this->voltages, voltages_lengthT * sizeof(double));
      offset += 3;
      voltages_length = voltages_lengthT;
      for( uint8_t i = 0; i < voltages_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_voltages;
      u_st_voltages.base = 0;
      u_st_voltages.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_voltages.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_voltages.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_voltages.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_voltages.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_voltages.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_voltages.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_voltages.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_voltages = u_st_voltages.real;
      offset += sizeof(this->st_voltages);
        memcpy( &(this->voltages[i]), &(this->st_voltages), sizeof(double));
      }
      uint8_t currents_lengthT = *(inbuffer + offset++);
      if(currents_lengthT > currents_length)
        this->currents = (double*)realloc(this->currents, currents_lengthT * sizeof(double));
      offset += 3;
      currents_length = currents_lengthT;
      for( uint8_t i = 0; i < currents_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_currents;
      u_st_currents.base = 0;
      u_st_currents.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_currents.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_currents.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_currents.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_currents.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_currents.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_currents.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_currents.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_currents = u_st_currents.real;
      offset += sizeof(this->st_currents);
        memcpy( &(this->currents[i]), &(this->st_currents), sizeof(double));
      }
      uint8_t temperatures_lengthT = *(inbuffer + offset++);
      if(temperatures_lengthT > temperatures_length)
        this->temperatures = (double*)realloc(this->temperatures, temperatures_lengthT * sizeof(double));
      offset += 3;
      temperatures_length = temperatures_lengthT;
      for( uint8_t i = 0; i < temperatures_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_temperatures;
      u_st_temperatures.base = 0;
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_temperatures.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_temperatures = u_st_temperatures.real;
      offset += sizeof(this->st_temperatures);
        memcpy( &(this->temperatures[i]), &(this->st_temperatures), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "clearpath_base/SystemStatus"; };
    const char * getMD5(){ return "b24850c808eb727058fff35ba598006f"; };

  };

}
#endif