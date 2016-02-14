/*
 * Rectangle.h
 *
 *  Created on: Feb 12, 2016
 *      Author: root
 */

#ifndef RECTANGLEELEMENT_H_
#define RECTANGLEELEMENT_H_

#include "../ui/BaseElement.h"
#include "../ui/Color.h"
#include "../ui/TextureHelper.h"

namespace atpm {
namespace ui {

class RectangleElement:public BaseElement {
public:
	RectangleElement(BaseWindow &_window,atpm_float32 _x,atpm_float32 _y,atpm_float32 _width,atpm_float32 _height,atpm_uint8 _transparency, Color _fillColor);
	virtual ~RectangleElement();
	void OnRender();
protected:
	Color fillColor;
};

} /* namespace ui */
} /* namespace atpm */

#endif /* RECTANGLE_H_ */
