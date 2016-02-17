/*
 * AutoPilotWindow.h
 *
 *  Created on: Feb 16, 2016
 *      Author: root
 */

#ifndef AUTOPILOTWINDOW_H_
#define AUTOPILOTWINDOW_H_


#include "../ui/Window.h"
#include "../ui/LogsElement.h"
#include "../net/LogParser.h"
#include "../net/LogPort.h"



namespace atpm {
namespace ui {

using namespace atpm::net;

class AutoPilotWindow:public Window {
public:
	AutoPilotWindow();
	virtual ~AutoPilotWindow();
	void ShowLog(atpm_string data);
private:
	LogsElement *logs;
	LogPort *port;
	LogParser *parser;
	SDL_Thread *parser_thread;
	atpm_int32 parser_wait;
private:
	void createParserThread();
		/**
			* @brief friend function for processing logs
			*/
   friend atpm_int32 parseLogs(void *arg);












};

} /* namespace ui */
} /* namespace atpm */

#endif /* AUTOPILOTWINDOW_H_ */
