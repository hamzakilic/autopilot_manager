/*
 * AtpmException.h
 *
 *  Created on: Feb 10, 2016
 *      Author: root
 */

#ifndef ATPMEXCEPTION_H_
#define ATPMEXCEPTION_H_

#include "../common/AtpmCommon.h"

namespace atpm {
namespace common{

class AtpmException:public exception {
public:
	AtpmException(atpm_string &_msg)throw();
	AtpmException(const atpm_cstring * _msg)throw();
	AtpmException(const atpm_cstring * _msg,const atpm_cstring *_error)throw();
	virtual ~AtpmException()throw();
	virtual const atpm_cstring * what() const throw();
private:
	atpm_string msg;
};

} /* namespace atpm::common */
} //namespace atpm

#endif /* ATPMEXCEPTION_H_ */
