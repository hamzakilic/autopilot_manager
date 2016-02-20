/*
 * Log.h
 *
 *  Created on: Feb 11, 2016
 *      Author: root
 */

#ifndef ATPMLOG_H_
#define ATPMLOG_H_

#include "../common/AtpmCommon.h"
namespace atpm {
namespace common{

class AtpmLog {
private:
	AtpmLog();
	virtual ~AtpmLog();
public:
	static void Debug(const atpm_cstring *msg, ...);
	static void Info(const atpm_cstring *msg, ...);

};

} /* namespace atpm::common */
} //namespace atpm

#endif /* ATPMLOG_H_ */
