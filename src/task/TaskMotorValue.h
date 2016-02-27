/*
 * TaskMotorValue.h
 *
 *  Created on: Feb 27, 2016
 *      Author: root
 */

#ifndef TASKMOTORVALUE_H_
#define TASKMOTORVALUE_H_

#include "../task/Task.h"
namespace atpm {
namespace task {

class TaskMotorValue:public Task {
public:
	TaskMotorValue(atpm_uint32 _value);
	virtual ~TaskMotorValue();
	virtual void Prepare();
private:
	atpm_uint32 value;

};

} /* namespace task */
} /* namespace atpm */

#endif /* TASKMOTORVALUE_H_ */
