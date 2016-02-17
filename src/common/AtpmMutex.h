/*
 * AtpmMutex.h
 *
 *  Created on: Feb 17, 2016
 *      Author: root
 */

#ifndef ATPMMUTEX_H_
#define ATPMMUTEX_H_

#include "../common/AtpmCommon.h"
#include "../common/AtpmException.h"

namespace atpm {
namespace common {

class AtpmMutex {
public:
	AtpmMutex();
	virtual ~AtpmMutex();
	void Lock();
	void Unlock();
private:
	SDL_mutex *mutex;
};

} /* namespace common */
} /* namespace atpm */

#endif /* ATPMMUTEX_H_ */
