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
    :Window("Autopilot Manager",1024,1024,Color(20,20,20,255)),logs(0),input(0),port(0),parser(0),tasker(0),echo_number(0) {

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
				printf("class type one comed\n");
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

			case SDLK_a:SendEchoTask();break;
			}
	}
	/*else if(key.type==SDL_KEYUP){
		switch(key.keysym.sym ){
					case SDLK_UP:AtpmLog::Debug("AutoPilotWindow HandleKey Called Key is:Up\n");break;
					case SDLK_LCTRL:case SDLK_RCTRL: AtpmLog::Debug("AutoPilotWindow Control Called Key is:Up\n");break;
					}*/


}



void AutoPilotWindow::SendEchoTask(){
	stringstream ss;
	ss<<"Hello Hamza "<<echo_number++;
    TaskEcho echo(ss.str());
    echo.Prepare();
    tasker->SendTask(echo.Data(),echo.Length());
}



} /* namespace ui */
} /* namespace atpm */
