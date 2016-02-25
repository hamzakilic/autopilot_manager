/*
 * TaskPort.cpp
 *
 *  Created on: Feb 25, 2016
 *      Author: root
 */

#include "TaskPort.h"

namespace atpm {
namespace net {

TaskPort::TaskPort(atpm_string _host,atpm_uint16 _port):sockfd(0),port(_port),host(_host) {
	createSocket();

}

TaskPort::~TaskPort() {
	if(sockfd)
		close(sockfd);
}


void TaskPort::createSocket(){
	AtpmLog::Debug("Creating Task Socket\n");
	sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
		if(sockfd==-1)
		{
			throw AtpmException(strerror(errno));
		}
		bzero(&servaddr,sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port=htons(port);
		servaddr.sin_addr.s_addr=inet_addr(host.c_str());
		AtpmLog::Debug("Created Task Socket %s:%d\n",host.c_str(),port);
}

void TaskPort::SendTask(const atpm_byte *task,atpm_uint32 length){
	atpm_int32 err=0;
                errno=0;
				err=sendto(sockfd,task,length,0,(struct sockaddr *)&(servaddr),sizeof(struct sockaddr_in));
				if(err==-1){
				  throw AtpmException(strerror(errno));
				}
}


} /* namespace net */
} /* namespace atpm */
