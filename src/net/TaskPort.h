/*
 * TaskPort.h
 *
 *  Created on: Feb 25, 2016
 *      Author: root
 */

#ifndef TASKPORT_H_
#define TASKPORT_H_

#include "../common/AtpmCommon.h"
#include "../common/AtpmException.h"
#include "../common/AtpmLog.h"
#include "../common/AtpmMutex.h"



namespace atpm {
namespace net {

using namespace atpm::common;

class TaskPort {
public:
	TaskPort(atpm_string _host,atpm_uint16 _port);
	virtual ~TaskPort();
	void SendTask(const atpm_byte *task,atpm_uint32 length);
private:
	/**
		 * @brief function for creating socket
		 */
		void createSocket();

		atpm_uint16 port;
		atpm_int32 sockfd;
		struct sockaddr_in servaddr;
		atpm_string host;

};

} /* namespace net */
} /* namespace atpm */

#endif /* TASKPORT_H_ */
