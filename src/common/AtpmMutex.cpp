/*
 * AtpmMutex.cpp
 *
 *  Created on: Feb 17, 2016
 *      Author: root
 */

#include "AtpmMutex.h"

namespace atpm {
namespace common {

AtpmMutex::AtpmMutex():mutex(0) {
	mutex=SDL_CreateMutex();
	if(mutex==NULL)
		throw AtpmException("Creating Mutex Failed:",SDL_GetError());

}

AtpmMutex::~AtpmMutex() {
	if(mutex)
		SDL_DestroyMutex(mutex);
}
void AtpmMutex::Lock(){
	SDL_LockMutex(mutex);
}
	void AtpmMutex::Unlock(){
		SDL_UnlockMutex(mutex);

	}

} /* namespace common */
} /* namespace atpm */
