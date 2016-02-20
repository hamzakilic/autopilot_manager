/*
 * LogParser.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: root
 */

#include "../net/LogParser.h"

namespace atpm {
namespace net {



BaseData::~BaseData(){

}

StringData::StringData():log_length(0){
	memset(log_data,0,STRINGDATALENGTH);

}
InputData::InputData(){
	year=0;
	month=0;
	day=0;
    hour=0;
    min=0;
sec=0;
longtitude=0;
latitude=0;
sealevel=0;
gps_fix=0;
status=0;
msss=0;
motor_values[0]=0;
motor_values[1]=0;
motor_values[2]=0;
motor_values[3]=0;

}

LogParser::LogParser() {
	// TODO Auto-generated constructor stub

}

LogParser::~LogParser() {
	// TODO Auto-generated destructor stub
}


InputData *createInputData(const atpm_byte *input_data){
	 InputData *data=new  InputData;
        data->class_type=2;
		data->latitude=atpm_to_int32(input_data[0])<<24;
		data->latitude+=atpm_to_int32(input_data[1])<<16;
		data->latitude+=atpm_to_int32(input_data[2])<<8;
		data->latitude+=atpm_to_int32(input_data[3]);

		data->longtitude=atpm_to_int32(input_data[4])<<24;
		data->longtitude+=atpm_to_int32(input_data[5])<<16;
		data->longtitude+=atpm_to_int32(input_data[6])<<8;
		data->longtitude+=atpm_to_int32(input_data[7]);

		data->sealevel=atpm_to_int32(input_data[8])<<24;
		data->sealevel+=atpm_to_int32(input_data[9])<<16;
		data->sealevel+=atpm_to_int32(input_data[10])<<8;
		data->sealevel+=atpm_to_int32(input_data[11]);

		data->gps_fix=input_data[12];
		data->status=input_data[13];

		data->msss=atpm_to_int32(input_data[14])<<24;
		data->msss+=atpm_to_int32(input_data[15])<<16;
		data->msss+=atpm_to_int32(input_data[16])<<8;
		data->msss+=atpm_to_int32(input_data[17]);

		data->year=atpm_to_uint16(input_data[18])<<8;
		data->year+=atpm_to_uint16(input_data[19]);

		data->month=input_data[20];
		data->day=input_data[21];
		data->hour=input_data[22];
		data->min=input_data[23];
		data->sec=input_data[24];

		data->motor_values[0]=atpm_to_int16(input_data[25])<<8;
		data->motor_values[0]+=atpm_to_int16(input_data[26]);

		data->motor_values[1]=atpm_to_int16(input_data[27])<<8;
		data->motor_values[1]+=atpm_to_int16(input_data[28]);

		data->motor_values[2]=atpm_to_int16(input_data[29])<<8;
		data->motor_values[2]+=atpm_to_int16(input_data[30]);

		data->motor_values[3]=atpm_to_int16(input_data[31])<<8;
		data->motor_values[3]+=atpm_to_int16(input_data[32]);

		  atpm_int32 temp=0;

		 temp=input_data[33]<<24;
		 temp+=input_data[34]<<16;
		 temp+=input_data[35]<<8;
		 temp+=input_data[36];
		 data->roll=temp/1000.0f;

		 temp=input_data[37]<<24;
		 temp+=input_data[38]<<16;
		 temp+=input_data[39]<<8;
		 temp+=input_data[40];
		 data->pitch=temp/1000.0f;


		 temp=input_data[41]<<24;
		 temp+=input_data[42]<<16;
		 temp+=input_data[43]<<8;
		 temp=input_data[44];
		 data->yaw=temp/1000.0f;

		 temp=input_data[45]<<24;
		 temp+=input_data[46]<<16;
		 temp+=input_data[47]<<8;
		 temp+=input_data[48];
		 data->pressure=temp/1000.0f;

         temp=input_data[49]<<24;
         temp+=input_data[50]<<16;
         temp+=input_data[51]<<8;
         temp+=input_data[52];
         data->tempreature=temp/1000.0f;

         temp=input_data[53]<<24;
         temp+=input_data[54]<<16;
         temp+=input_data[55]<<8;
         temp+=input_data[56];
         data->altitude=temp/1000.0f;


		return data;

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
											  		  InputData *data=createInputData(value+8);
											  		  return data;
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
