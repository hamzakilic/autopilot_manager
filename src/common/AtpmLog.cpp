/*
 * Log.cpp
 *
 *  Created on: Feb 11, 2016
 *      Author: root
 */

#include "AtpmLog.h"

namespace atpm {
namespace common{

AtpmLog::AtpmLog() {
	// TODO Auto-generated constructor stub

}

AtpmLog::~AtpmLog() {
	// TODO Auto-generated destructor stub
}

void AtpmLog::Debug(const atpm_cstring *msg, ...){
	        va_list arg;
			va_start(arg, msg);
			char buffer[1024];
			memset(buffer,0,1024);
			vsnprintf(buffer,1023,msg,arg);
			va_end(arg);
			cout<<buffer;


}

}
} /* namespace atpm */
