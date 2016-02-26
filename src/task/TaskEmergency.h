/*
 * TaskEmergency.h
 *
 *  Created on: Feb 27, 2016
 *      Author: root
 */

#ifndef TASKEMERGENCY_H_
#define TASKEMERGENCY_H_

#include "../task/Task.h"

namespace atpm {
namespace task {

class TaskEmergency:public Task {
public:
	TaskEmergency();
	virtual ~TaskEmergency();
	virtual void Prepare();
};

} /* namespace task */
} /* namespace atpm */

#endif /* TASKEMERGENCY_H_ */
