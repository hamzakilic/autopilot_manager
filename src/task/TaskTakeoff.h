/*
 * TaskTakeoff.h
 *
 *  Created on: Feb 27, 2016
 *      Author: root
 */

#ifndef TASKTAKEOFF_H_
#define TASKTAKEOFF_H_


#include "../task/Task.h"

namespace atpm {
namespace task {

class TaskTakeoff:public Task {
public:
	TaskTakeoff();
	virtual ~TaskTakeoff();
	virtual void Prepare();
};

} /* namespace task */
} /* namespace atpm */

#endif /* TASKTAKEOFF_H_ */
