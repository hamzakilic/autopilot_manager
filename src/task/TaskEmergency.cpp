/*
 * TaskEmergency.cpp
 *
 *  Created on: Feb 27, 2016
 *      Author: root
 */

#include "TaskEmergency.h"

namespace atpm {
namespace task {

TaskEmergency::TaskEmergency() {
	// TODO Auto-generated constructor stub

}

TaskEmergency::~TaskEmergency() {
	// TODO Auto-generated destructor stub
}

void TaskEmergency::Prepare(){

    atpm_uint16 command_type=2;
    atpm_uint32 hash=0;
    atpm_uint32 totallength=2+4+4;
    data=new atpm_byte[totallength];

    data[0]=command_type;
    data[1]=command_type>>8;
    data[2]=0;
    data[3]=0>>8;
    data[4]=0>>16;
    data[5]=0>>24;
     atpm_int32 counter;
    		for(counter=0;counter<6;++counter)
    			hash+=data[counter];

    data[6]=hash;
    data[7]=hash>>8;
    data[8]=hash>>16;
    data[9]=hash>>24;
    length=totallength;
}

} /* namespace task */
} /* namespace atpm */
