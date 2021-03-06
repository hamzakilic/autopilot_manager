/*
 * AutoPilotWindow.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: root
 */

#include "AutoPilotWindow.h"

namespace atpm {
namespace ui {

AutoPilotWindow::AutoPilotWindow()
    :Window("Autopilot Manager",1024,1024,Color(20,20,20,255)),logs(0),input(0),port(0),parser(0),tasker(0),echo_number(0),motor_value(0) {

	logs=new  LogsElement(*this,0.0f,0.9f,0.8f,0.1f,180,Color(20,120,20,255),Color(255,255,255,255));
	input=new  InputDataElement(*this,0.8f,0.65f,0.2f,0.35f,180,Color(120,120,20,255),Color(255,255,255,255));

	AddChild(logs);
	AddChild(input);
	port=new LogPort(9999);
	parser=new LogParser();
	tasker=new TaskPort("192.168.2.35",9999);
	createParserThread();





}

AutoPilotWindow::~AutoPilotWindow() {
	//destroy parser thread
	parser_wait=0;
	if(parser_thread)
		SDL_WaitThread(parser_thread,NULL);
	parser_thread=NULL;
    if(tasker)
    	delete tasker;
	if(parser)
		delete parser;
	if(port)
		delete port;
	if(logs)
	   delete logs;
	if(input)
		delete input;
}

atpm_int32 parseLogs(void *arg){

	AutoPilotWindow *window=(AutoPilotWindow*)arg;
	while(window->parser_wait){
		if(window->port->LogSize()){
			LogItem *item=window->port->NextLog();
			BaseData *data= window->parser->Parse(item->Value,item->Length);
			delete item;
			if(data==NULL){

				continue;
			}
			if(data->class_type==1)//StringData
			{

				StringData *string_data=(StringData*)data;
				window->ShowLog(atpm_string(string_data->log_data));
				delete string_data;

			}
			if(data->class_type==2){//inputdata

				InputData *input_data=(InputData*)data;
			    window->UpdateInputData(*input_data);
				delete input_data;
			}



		}else SDL_Delay(100);
	}
	return 0;


}


void AutoPilotWindow::createParserThread(){

	parser_wait=1;
		parser_thread= SDL_CreateThread(parseLogs,"Parsing Thread",this);
		if(parser_thread==NULL)
			throw AtpmException("AutoPilotWindow create ParsingThread Failed:",SDL_GetError());

}

void AutoPilotWindow::ShowLog(atpm_string data){

	logs->AddLog(data);
}

void AutoPilotWindow::UpdateInputData(InputData data){
  input_data=data;
  input->UpdateInputData(data);
}



void AutoPilotWindow::HandleKey(SDL_KeyboardEvent &key){
	if(key.type==SDL_KEYDOWN){
		switch(key.keysym.sym ){

			case SDLK_e:SendTaskEcho();break;
			case SDLK_ESCAPE:SendTaskEmergency();break;
			case SDLK_s:SendTaskStartMotors();break;
			case SDLK_q:SendTaskStopMotors();break;
			case SDLK_b:SendTaskBalance();break;
			case SDLK_t:SendTaskTakeoff();break;
			case SDLK_c:SendTaskMotorcalibrate();break;
			case SDLK_UP:motor_value+=25; SendTaskMotorvalue(motor_value);break;
			case SDLK_DOWN:motor_value-=25;SendTaskMotorvalue(motor_value);break;


			}
	}
	/*else if(key.type==SDL_KEYUP){
		switch(key.keysym.sym ){
					case SDLK_UP:AtpmLog::Debug("AutoPilotWindow HandleKey Called Key is:Up\n");break;
					case SDLK_LCTRL:case SDLK_RCTRL: AtpmLog::Debug("AutoPilotWindow Control Called Key is:Up\n");break;
					}*/


}



void AutoPilotWindow::SendTaskEcho(){
	stringstream ss;
	ss<<"Hello Hamza "<<echo_number++;
    TaskEcho task(ss.str());
    task.Prepare();
    tasker->SendTask(task.Data(),task.Length());
}

void AutoPilotWindow::SendTaskStartMotors(){
	TaskStartMotors task;
	task.Prepare();
    tasker->SendTask(task.Data(),task.Length());



}

void AutoPilotWindow::SendTaskStopMotors(){

	TaskStopMotors task;
	task.Prepare();
    tasker->SendTask(task.Data(),task.Length());
}

void AutoPilotWindow::SendTaskEmergency(){
	TaskEmergency task;
	task.Prepare();
    tasker->SendTask(task.Data(),task.Length());
}

void AutoPilotWindow::SendTaskTakeoff(){

	TaskTakeoff task;
	task.Prepare();
    tasker->SendTask(task.Data(),task.Length());
}
void AutoPilotWindow::SendTaskBalance(){

	TaskBalance task;
	task.Prepare();
    tasker->SendTask(task.Data(),task.Length());
}

void AutoPilotWindow::SendTaskMotorcalibrate(){

	TaskMotorCalibrate task;
	task.Prepare();
    tasker->SendTask(task.Data(),task.Length());
}

void AutoPilotWindow::SendTaskMotorvalue(atpm_int32 val){

    if(val<0){
    	motor_value=0;
    	val=0;
    }
    if(val>1000){
    	motor_value=1000;
    	val=1000;
    }
	TaskMotorValue task(val);
	task.Prepare();
    tasker->SendTask(task.Data(),task.Length());
}





} /* namespace ui */
} /* namespace atpm */
