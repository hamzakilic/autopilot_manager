/*
 * LogPort.cpp
 *
 *  Created on: Feb 15, 2016
 *      Author: root
 */

#include "../log/LogPort.h"

namespace atpm {
namespace log {


LogItem::LogItem(atpm_byte *val,atpm_int32 _length):Value(val),Length(_length){

}

LogItem::~LogItem(){
	if(Value)
		delete[] Value;
}




LogPort::LogPort(atpm_uint16 _port,LogParser &_parser)
:port(_port),sockfd(0),listening_thread(0),listen_wait(0),parser_thread(0),parser_wait(0),logs_mutex(0),parser(_parser) {
  logs_mutex=SDL_CreateMutex();
  if(logs_mutex==NULL)
	  throw AtpmException("SDL create mutex failed",SDL_GetError());
 createSocket();
 createListeningThread();

}

LogPort::~LogPort() {
	AtpmLog::Debug("Destructing LogPort\n");
	listen_wait=0;
	AtpmLog::Debug("LogPort waiting listening thread\n");
	if(listening_thread)
	SDL_WaitThread(listening_thread,NULL);
	listening_thread=NULL;
	AtpmLog::Debug("Destructed LogPort\n");
	close(sockfd);

}

void LogPort::createSocket(){
	AtpmLog::Debug("Creating Listening Socket\n");
	sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
		if(sockfd==-1)
		{
			throw AtpmException(strerror(errno));

		}
		struct timeval tv;
		tv.tv_sec = 1;
		tv.tv_usec = 0;

		if(setsockopt(sockfd,SOL_SOCKET,SO_RCVTIMEO,&tv,sizeof(tv))){
			throw AtpmException("Socket timeout option set error\n");
		}

		bzero(&servaddr,sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
		servaddr.sin_port=htons(port);
		errno=0;
		atpm_int32 err= bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
		if(err==-1){
			throw AtpmException(strerror(errno));

		}
		AtpmLog::Debug("Listening logs on port:%d\n",port);
}
atpm_int32 readSocket(void *arg){
    LogPort *port=(LogPort*)arg;
	atpm_byte bytes[1024];
    socklen_t len=sizeof(port->cliaddr);

	while(port->listen_wait){
     errno=0;
	 atpm_int32 received_size= recvfrom(port->sockfd,bytes,1024,0,(struct sockaddr*)&port->cliaddr,&len);
	 if(received_size>0){
	 atpm_byte *temp=new atpm_byte[received_size];
	 memcpy(temp,bytes,received_size);
	 LogItem *log=new LogItem(temp,received_size);
	 SDL_LockMutex(port->logs_mutex);
	 port->logs.push(log);
	 SDL_UnlockMutex(port->logs_mutex);
	 }else{
		 AtpmLog::Debug("LogPort recvfrom timeout: %s\n",strerror(errno));
	 }

	}

	return 0;
}

void LogPort::createListeningThread(){

	listen_wait=1;
	listening_thread= SDL_CreateThread(readSocket,"Listening Thread",this);
	if(listening_thread==NULL)
		throw AtpmException("LogPort create ListeningThread Failed:",SDL_GetError());

}



atpm_int32 parseLogs(void *arg){

	LogPort *port=(LogPort*)arg;
	while(port->parser_wait){
		if(port->logs.size()){
			LogItem *item=NULL;
			SDL_LockMutex(port->logs_mutex);
			item= port->logs.front();
			port->logs.pop();
			SDL_UnlockMutex(port->logs_mutex);
			port->parser.Parse(item->Value,item->Length);
			delete item;

		}else SDL_Delay(100);
	}
	return 0;


}

void LogPort::createParserThread(){

	parser_wait=1;
		parser_thread= SDL_CreateThread(parseLogs,"Parsing Thread",this);
		if(parser_thread==NULL)
			throw AtpmException("LogPort create ParsingThread Failed:",SDL_GetError());

}




} /* namespace log */
} /* namespace atpm */
