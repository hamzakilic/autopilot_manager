/*
 * Task.cpp
 *
 *  Created on: Feb 25, 2016
 *      Author: root
 */

#include "Task.h"

namespace atpm {
namespace task {

Task::Task():length(0),data(0) {

}

Task::~Task() {
	if(data)
		delete[] data;
}

const atpm_byte  * Task::Data()const{
return data;
}
atpm_uint32 Task::Length(){
return length;
}

} /* namespace task */
} /* namespace atpm */
