/*
 * TaskBalance.h
 *
 *  Created on: Apr 24, 2016
 *      Author: root
 */

#ifndef TASKBALANCE_H_
#define TASKBALANCE_H_

#include "Task.h"

namespace atpm {
namespace task {

class TaskBalance:public Task  {
public:
	TaskBalance();
	virtual ~TaskBalance();
	virtual void Prepare();
};

} /* namespace task */
} /* namespace atpm */

#endif /* TASKBALANCE_H_ */
