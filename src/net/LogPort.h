/*
 * LogPort.h
 *
 *  Created on: Feb 15, 2016
 *      Author: root
 */

#ifndef LOGPORT_H_
#define LOGPORT_H_

#include "../common/AtpmCommon.h"
#include "../common/AtpmException.h"
#include "../common/AtpmLog.h"
#include "../common/AtpmMutex.h"
#include "../net/LogParser.h"



namespace atpm {
namespace net {

using namespace atpm::common;

class LogItem{
public:
	LogItem(atpm_byte *_val,atpm_int32 _length);
	virtual ~LogItem();
	const atpm_byte *Value;
	const atpm_int32 Length;
};



class LogPort {
public:
	LogPort(atpm_uint16 _port);
	virtual ~LogPort();
	atpm_uint32 LogSize();
	LogItem * NextLog();
public:

private:

	void createListeningThread();

	/**
	 * @brief friend function for creating socket
	 */
	friend void createSocket(LogPort *arg);

	/**
	 * @brief friend function for reading socket
	 */
	friend  atpm_int32 readSocket(void *arg);

	atpm_uint16 port;
	atpm_int32 sockfd;
	struct sockaddr_in servaddr;
	struct sockaddr_in cliaddr;
	queue<LogItem*> logs;
	AtpmMutex  logs_mutex;
	SDL_Thread *listening_thread;
	atpm_int32 listen_wait;


private:




};








} /* namespace log */
} /* namespace atpm */

#endif /* LOGPORT_H_ */
