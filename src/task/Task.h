/*
 * Task.h
 *
 *  Created on: Feb 25, 2016
 *      Author: root
 */

#ifndef TASK_H_
#define TASK_H_

#include "../common/AtpmCommon.h"
#include "../common/AtpmException.h"
#include "../common/AtpmLog.h"
#include "../common/AtpmMutex.h"



namespace atpm {
namespace task {

using namespace atpm::common;

class Task {
public:
	Task();
	virtual ~Task();
	virtual void Prepare()=0;
	const atpm_byte  *Data()const;
	atpm_uint32 Length();
protected:
	atpm_byte *data;
	atpm_uint32 length;
};

} /* namespace task */
} /* namespace atpm */

#endif /* TASK_H_ */
