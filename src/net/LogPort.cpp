/*
 * LogPort.cpp
 *
 *  Created on: Feb 15, 2016
 *      Author: root
 */

#include "../net/LogPort.h"

namespace atpm {
namespace net {


LogItem::LogItem(atpm_byte *val,atpm_int32 _length):Value(val),Length(_length){


}

LogItem::~LogItem(){
	if(Value)
		delete[] Value;
}




LogPort::LogPort(atpm_uint16 _port)
:port(_port),sockfd(0),listening_thread(0),listen_wait(0) {


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

void createSocket(LogPort *port){
	AtpmLog::Debug("Creating Listening Socket\n");
	port->sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

		if(port->sockfd==-1)
		{
			throw AtpmException(strerror(errno));

		}
		struct timeval tv;
		tv.tv_sec = 1;
		tv.tv_usec = 0;

		if(setsockopt(port->sockfd,SOL_SOCKET,SO_RCVTIMEO,&tv,sizeof(tv))){
			throw AtpmException("Socket timeout option set error\n");
		}

		bzero(&port->servaddr,sizeof(port->servaddr));

		port->servaddr.sin_family = AF_INET;
		port->servaddr.sin_port=htons(port->port);
		port->servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

		errno=0;
		atpm_int32 err= bind(port->sockfd,(const struct sockaddr *)&port->servaddr,sizeof(port->servaddr));
		if(err==-1){
			throw AtpmException(strerror(errno));

		}
		AtpmLog::Debug("Listening logs on port:%u\n",port->port);
}
atpm_int32 readSocket(void *arg){
    LogPort *port=(LogPort*)arg;
	atpm_byte bytes[1024];
    socklen_t len=sizeof(port->servaddr);

    createSocket(port);

	while(port->listen_wait){
     errno=0;
	 atpm_int32 received_size= recvfrom(port->sockfd,bytes,1024,0,(struct sockaddr*)&port->cliaddr,&len);
	 if(received_size>0){
		AtpmLog::Debug("Received packet from %s:%d\n",inet_ntoa(port->cliaddr.sin_addr), ntohs(port->cliaddr.sin_port));
	 atpm_byte *temp=new atpm_byte[received_size];
	 memcpy(temp,bytes,received_size);
	 LogItem *log=new LogItem(temp,received_size);
	 port->logs_mutex.Lock();
	 port->logs.push(log);
	 port->logs_mutex.Unlock();
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


atpm_uint32 LogPort::LogSize(){
	logs_mutex.Lock();
	atpm_uint32 length= logs.size();
	logs_mutex.Unlock();
	return length;

}
	LogItem * LogPort::NextLog(){
		LogItem *item=NULL;
		 logs_mutex.Lock();
		  item= logs.front();
		 logs.pop();
		logs_mutex.Unlock();
		return item;
	}










} /* namespace log */
} /* namespace atpm */
