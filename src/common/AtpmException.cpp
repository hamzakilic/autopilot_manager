/*
 * AtpmException.cpp
 *
 *  Created on: Feb 10, 2016
 *      Author: root
 */

#include "../common/AtpmException.h"


namespace atpm {
namespace common{

AtpmException::AtpmException(atpm_string &_msg)throw():msg(_msg){
	// TODO Auto-generated constructor stub

}
AtpmException::AtpmException(const atpm_cstring * _msg)throw():msg(_msg,strlen(_msg)){
	// TODO Auto-generated constructor stub

}

AtpmException::AtpmException(const atpm_cstring * _msg,const atpm_cstring *_error)throw():msg(_msg,strlen(_msg)){
	msg +=_error;
	msg+="\n";

}



AtpmException::~AtpmException()throw() {
	// TODO Auto-generated destructor stub
}

const atpm_cstring * AtpmException::what() const throw(){
	return msg.c_str();
}


} /* namespace atpm::common */
} //namespace atpm
