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
namespace log {
using namespace atpm::common;



#define ATPM_LOG_INFO 0x01
#define ATPM_LOG_ERROR 0x02
#define ATPM_LOG_FATAL 0x04
#define ATPM_LOG_DATA 0x08

#define ATPM_LOG_DATA_TYPE_STRING 0x01
#define ATPM_LOG_DATA_TYPE_INPUT 0x02


#define STRINGDATALENGTH 1024


struct StringData{
	atpm_uint8 log_length;
	atpm_cstring log_data[STRINGDATALENGTH];
};

struct InputData{
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


};



class LogParser {
public:
	LogParser();
	virtual ~LogParser();
	void Parse(const atpm_byte *data,atpm_int32 length);
};

} /* namespace log */
} /* namespace atpm */

#endif /* LOGPARSER_H_ */
