/*
 * TaskMotorValue.cpp
 *
 *  Created on: Feb 27, 2016
 *      Author: root
 */

#include "TaskMotorValue.h"

namespace atpm {
namespace task {

TaskMotorValue::TaskMotorValue(atpm_uint32 _value):value(_value) {
	// TODO Auto-generated constructor stub

}

TaskMotorValue::~TaskMotorValue() {
	// TODO Auto-generated destructor stub
}
void TaskMotorValue::Prepare(){
    atpm_int32 val_len=sizeof(value);
    atpm_uint16 command_type=7;
    atpm_uint32 hash=0;
    atpm_uint32 totallength=(2+4+4)+val_len;
    data=new atpm_byte[totallength];

    data[0]=command_type;
    data[1]=command_type>>8;
    data[2]=val_len;
    data[3]=val_len>>8;
    data[4]=val_len>>16;
    data[5]=val_len>>24;
     atpm_int32 counter;
    		for(counter=0;counter<6;++counter)
    			hash+=data[counter];

    data[6]=hash;
    data[7]=hash>>8;
    data[8]=hash>>16;
    data[9]=hash>>24;
    data[10]=value;
    data[11]=value>>8;
    data[12]=value>>16;
    data[13]=value>>24;
    length=totallength;
}

} /* namespace task */
} /* namespace atpm */
