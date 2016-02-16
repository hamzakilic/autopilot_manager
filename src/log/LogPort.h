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
#include "../log/LogParser.h"


namespace atpm {
namespace log {

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
	LogPort(atpm_uint16 _port,LogParser &_parser);
	virtual ~LogPort();
private:
	void createSocket();
	void createListeningThread();
	void createParserThread();
	/**
	 * @brief friend function for reading socket
	 */
	friend  atpm_int32 readSocket(void *arg);
	/**
	 * @brief friend function for processing logs
	 */
	friend atpm_int32 parseLogs(void *arg);
	atpm_uint16 port;
	atpm_int32 sockfd;
	struct sockaddr_in servaddr;
	struct sockaddr_in cliaddr;
	queue<LogItem*> logs;
	SDL_mutex * logs_mutex;
	SDL_Thread *listening_thread;
	atpm_int32 listen_wait;
	SDL_Thread *parser_thread;
	atpm_int32 parser_wait;
	LogParser &parser;



};








} /* namespace log */
} /* namespace atpm */

#endif /* LOGPORT_H_ */
