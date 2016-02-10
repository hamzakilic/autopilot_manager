/*
 * common.h
 *
 *  Created on: Feb 10, 2016
 *      Author: root
 */

#ifndef ATPMCOMMON_H_
#define ATPMCOMMON_H_

#include <cstring>
#include <iostream>
#include <exception>
#include <string>

#include <SDL2/SDL.h>


using namespace std;
namespace atpm{
namespace common{


#define DEBUG



/**
 * @brief common types for portability
 */
typedef int atpm_int32;
typedef uint atpm_uint32;
typedef short atpm_int16;
typedef unsigned short atpm_uint16;
typedef char atpm_int8;
typedef unsigned char atpm_uint8;
typedef atpm_int8 atpm_byte;
typedef float atpm_float32;
typedef long atpm_int64;
typedef unsigned long atpm_uint64;
typedef string atpm_string;
typedef char  atpm_cstring;


}/*namespace atpm::common end*/
}//namespace atpm


#endif /* ATPMCOMMON_H_ */
