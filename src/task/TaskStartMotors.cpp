/*
 * TaskStartMotors.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: root
 */

#include "TaskStartMotors.h"

namespace atpm {
namespace task {

TaskStartMotors::TaskStartMotors() {
	// TODO Auto-generated constructor stub

}

TaskStartMotors::~TaskStartMotors() {
	// TODO Auto-generated destructor stub
}

void TaskStartMotors::Prepare(){

    atpm_uint16 command_type=3;
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
