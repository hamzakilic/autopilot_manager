/*
 * TaskEcho.cpp
 *
 *  Created on: Feb 25, 2016
 *      Author: root
 */

#include "TaskEcho.h"

namespace atpm {
namespace task {

TaskEcho::TaskEcho(atpm_string _msg):msg(_msg) {


}

TaskEcho::~TaskEcho() {
	// TODO Auto-generated destructor stub
}


void TaskEcho::Prepare(){
    atpm_int32 strlength=msg.length();
    atpm_uint16 command_type=1;
    atpm_uint32 hash=0;
    atpm_uint32 totallength=strlength+2+4+4;
    data=new atpm_byte[totallength];

    data[0]=command_type;
    data[1]=command_type>>8;
    data[2]=strlength;
    data[3]=strlength>>8;
    data[4]=strlength>>16;
    data[5]=strlength>>24;
   atpm_int32 counter;
    		for(counter=0;counter<6;++counter)
    			hash+=data[counter];

    data[6]=hash;
    data[7]=hash>>8;
    data[8]=hash>>16;
    data[9]=hash>>24;
    memcpy(data+10,msg.c_str(),strlength);
    length=totallength;
}

} /* namespace task */
} /* namespace atpm */
