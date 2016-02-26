/*
 * TaskStopMotors.h
 *
 *  Created on: Feb 27, 2016
 *      Author: root
 */

#ifndef TASKSTOPMOTORS_H_
#define TASKSTOPMOTORS_H_

#include "../task/Task.h"

namespace atpm {
namespace task {

class TaskStopMotors:public Task {
public:
	TaskStopMotors();
	virtual ~TaskStopMotors();
	virtual void Prepare();
};

} /* namespace task */
} /* namespace atpm */

#endif /* TASKSTOPMOTORS_H_ */
