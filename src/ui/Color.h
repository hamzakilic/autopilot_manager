/*
 * AtpmColor.h
 *
 *  Created on: Feb 12, 2016
 *      Author: root
 */

#ifndef COLOR_H_
#define COLOR_H_

#include "../common/AtpmCommon.h"

namespace atpm {
namespace ui {
using namespace atpm::common;
class Color {
public:
	Color(atpm_uint8 r=0,atpm_uint8 g=0,atpm_uint8 b=0,atpm_uint8 a=255);
	virtual ~Color();
	atpm_uint8 R;
	atpm_uint8 G;
	atpm_uint8 B;
	atpm_uint8 A;

};

} /* namespace ui */
} /* namespace atpm */

#endif /* COLOR_H_ */
