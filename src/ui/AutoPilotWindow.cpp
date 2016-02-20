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
    :Window("Autopilot Manager",1024,1024,Color(20,20,20,255)),logs(0),input(0),port(0),parser(0) {

	logs=new  LogsElement(*this,0.0f,0.9f,0.8f,0.1f,180,Color(20,120,20,255),Color(255,255,255,255));
	input=new  InputDataElement(*this,0.8f,0.65f,0.2f,0.35f,180,Color(120,120,20,255),Color(255,255,255,255));

	AddChild(logs);
	AddChild(input);
	port=new LogPort(9999);
	parser=new LogParser();
	createParserThread();





}

AutoPilotWindow::~AutoPilotWindow() {
	//destroy parser thread
	parser_wait=0;
	if(parser_thread)
		SDL_WaitThread(parser_thread,NULL);
	parser_thread=NULL;

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





} /* namespace ui */
} /* namespace atpm */
