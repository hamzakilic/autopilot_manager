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
#include "../ui/InputDataElement.h"
#include "../net/LogParser.h"
#include "../net/LogPort.h"
#include "../net/TaskPort.h"
#include "../task/Task.h"
#include "../task/TaskEcho.h"
#include "../task/TaskStartMotors.h"
#include "../task/TaskStopMotors.h"
#include "../task/TaskEmergency.h"
#include "../task/TaskTakeoff.h"
#include "../task/TaskMotorCalibrate.h"
#include "../task/TaskMotorValue.h"

namespace atpm {
namespace ui {

using namespace atpm::net;
using namespace atpm::task;

class AutoPilotWindow:public Window {
public:
	AutoPilotWindow();
	virtual ~AutoPilotWindow();
protected:
	virtual void HandleKey(SDL_KeyboardEvent &key);

private:
	LogsElement *logs;
	InputDataElement *input;
	LogPort *port;
	LogParser *parser;
	TaskPort  *tasker;
	SDL_Thread *parser_thread;
	atpm_int32 parser_wait;
	InputData input_data;
	atpm_uint32 echo_number;
	atpm_int32 motor_value;
private:
	void createParserThread();
	/**
	* @brief friend function for processing logs
	*/
   friend atpm_int32 parseLogs(void *arg);
   void ShowLog(atpm_string data);
   void UpdateInputData(InputData data);

   void SendTaskEcho();
   void SendTaskStartMotors();
   void SendTaskStopMotors();
   void SendTaskEmergency();
   void SendTaskTakeoff();
   void SendTaskMotorcalibrate();
   void SendTaskMotorvalue(atpm_int32 val);
















};

} /* namespace ui */
} /* namespace atpm */

#endif /* AUTOPILOTWINDOW_H_ */

