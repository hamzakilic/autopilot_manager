/*
 * LogParser.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: root
 */

#include "../net/LogParser.h"

namespace atpm {
namespace net {



StringData::StringData():log_length(0){
	memset(log_data,0,STRINGDATALENGTH);

}

LogParser::LogParser() {
	// TODO Auto-generated constructor stub

}

LogParser::~LogParser() {
	// TODO Auto-generated destructor stub
}

BaseData* LogParser::Parse(const atpm_byte *value,atpm_int32 length){

	if(length>=8){
	        	//doing seperation and hash calculation
	            atpm_uint8 log_type=value[0];
	            atpm_uint16 log_data_type=value[1]+(((atpm_uint16)value[2])<<8);

	            atpm_uint8 log_length=value[3];

	            atpm_uint32 sended_hash=((atpm_uint32)value[4]);
	            sended_hash+=((atpm_uint32)value[5])<<8 ;
	            sended_hash+=((atpm_uint32)value[6])<<16;
	            sended_hash+=((atpm_uint32)value[7])<<24;

	            atpm_uint32 calculated_hash=log_type;
	            calculated_hash+=((atpm_uint8 *)&log_data_type)[0];
	            calculated_hash+=((atpm_uint8 *)&log_data_type)[1];
	            calculated_hash+=log_length;
					if(calculated_hash==sended_hash)
					{

						switch(log_data_type)
											  {

											  	  case ATPM_LOG_DATA_TYPE_STRING:
											  	  {
											  		    StringData *data=new StringData();
											  		    data->class_type=1;
											  		    data->log_length=log_length;
											  		    memcpy(data->log_data,value+8,log_length);
											  		    return data;

											  	  }
											  	  case ATPM_LOG_DATA_TYPE_INPUT:
											  	  {

											  		  break;
											  	  }
											  default:
												  AtpmLog::Debug("Unknown log data type %d\n",log_data_type);

											  }



					}else{
						AtpmLog::Debug("Calculated hash is not equal\n");
					}
	        	}
	return NULL;

}

} /* namespace log */
} /* namespace atpm */
