/*
 * TaskEcho.h
 *
 *  Created on: Feb 25, 2016
 *      Author: root
 */

#ifndef TASKECHO_H_
#define TASKECHO_H_

#include "../task/Task.h"

namespace atpm {
namespace task {

class TaskEcho:public Task {
public:
	TaskEcho(atpm_string _msg);
	virtual ~TaskEcho();
	virtual void Prepare();
private:
	atpm_string msg;

};

} /* namespace task */
} /* namespace atpm */

#endif /* TASKECHO_H_ */
