/*
 * TaskMotorCalibrate.h
 *
 *  Created on: Feb 27, 2016
 *      Author: root
 */

#ifndef TASKMOTORCALIBRATE_H_
#define TASKMOTORCALIBRATE_H_

#include "../task/Task.h"

namespace atpm {
namespace task {

class TaskMotorCalibrate:public Task  {
public:
	TaskMotorCalibrate();
	virtual ~TaskMotorCalibrate();
	virtual void Prepare();
};

} /* namespace task */
} /* namespace atpm */

#endif /* TASKMOTORCALIBRATE_H_ */
