/*
 * LogParser.h
 *
 *  Created on: Feb 16, 2016
 *      Author: root
 */

#ifndef LOGPARSER_H_
#define LOGPARSER_H_

#include "../common/AtpmCommon.h"
#include "../common/AtpmException.h"
#include "../common/AtpmLog.h"






namespace atpm {
namespace net {
using namespace atpm::common;




#define ATPM_LOG_INFO 0x01
#define ATPM_LOG_ERROR 0x02
#define ATPM_LOG_FATAL 0x04
#define ATPM_LOG_DATA 0x08

#define ATPM_LOG_DATA_TYPE_STRING 0x01
#define ATPM_LOG_DATA_TYPE_INPUT 0x02


#define STRINGDATALENGTH 1024

class BaseData{
public:
	virtual ~BaseData();
	atpm_int32 class_type;
};

class StringData:public BaseData{
public:
	StringData();

	atpm_uint8 log_length;
	atpm_cstring log_data[STRINGDATALENGTH];
};

class InputData:public BaseData{
public:
	InputData();
	atpm_uint16 year;
	atpm_uint8 month;
	atpm_uint8 day;
	atpm_uint8 hour;
	atpm_uint8 min;
	atpm_uint8 sec;
	atpm_int32 longtitude; //degrees
	atpm_int32 latitude;//degreess;
	atpm_int32 sealevel;//mm
	atpm_uint8 gps_fix;
	atpm_uint8 status;//if zero gpxFixOK
	atpm_uint32 msss;//
	atpm_int16 motor_values[4];
	atpm_float32 yaw;
	atpm_float32 pitch;
	atpm_float32 roll;
	atpm_float32 tempreature;
	atpm_float32 pressure;
	atpm_float32 altitude;



};



class LogParser {
public:
	LogParser();
	virtual ~LogParser();
	BaseData * Parse(const atpm_byte *data,atpm_int32 length);

};

} /* namespace log */
} /* namespace atpm */

#endif /* LOGPARSER_H_ */
