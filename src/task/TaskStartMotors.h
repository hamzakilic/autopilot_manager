/*
 * TaskStartMotors.h
 *
 *  Created on: Feb 26, 2016
 *      Author: root
 */

#ifndef TASKSTARTMOTORS_H_
#define TASKSTARTMOTORS_H_

#include "../task/Task.h"

namespace atpm {
namespace task {

class TaskStartMotors:public Task {
public:
	TaskStartMotors();
	virtual ~TaskStartMotors();
	virtual void Prepare();
};

} /* namespace task */
} /* namespace atpm */

#endif /* TASKSTARTMOTORS_H_ */
