/*
 * BaseElement.h
 *
 *  Created on: Feb 12, 2016
 *      Author: root
 */

#ifndef BASEELEMENT_H_
#define BASEELEMENT_H_

#include "../common/AtpmCommon.h"
#include "../common/AtpmException.h"
#include "../common/AtpmLog.h"
#include "../common/AtpmMutex.h"
#include "../ui/BaseWindow.h"

namespace atpm {
namespace ui{
using namespace atpm::common;
class BaseElement {
public:
	BaseElement(BaseWindow &_window,atpm_float32 _x,atpm_float32 _y, atpm_float32 _width=1.0f,atpm_float32 _height=1.0f,atpm_uint8 _transparency=255);
	virtual ~BaseElement();
	virtual void Render();
protected:
	virtual void CreateTexture();
	virtual void OnRender()=0;




protected:
	BaseWindow &window;
	atpm_float32 width;
	atpm_float32 height;
	atpm_float32 x;
	atpm_float32 y;
	atpm_uint8 transparency;
	SDL_Texture *texture;
	atpm_int32 window_height;
	atpm_int32 window_width;


};

} /* namespace atpm::ui */
} // namespace atpm

#endif /* BASEELEMENT_H_ */
