/*
 * LogsElement.h
 *
 *  Created on: Feb 14, 2016
 *      Author: root
 */

#ifndef LOGSELEMENT_H_
#define LOGSELEMENT_H_

#include "../ui/RectangleElement.h"
#include "../ui/Color.h"


namespace atpm {
namespace ui {

class LogsElement:public RectangleElement {
public:
	LogsElement(BaseWindow &_window,atpm_float32 _x,atpm_float32 _y,atpm_float32 _width,atpm_float32 _height,atpm_uint8 _transparency, Color _fillColor);
	virtual ~LogsElement();
	void OnRender();
private:
	atpm_string log;
};

} /* namespace ui */
} /* namespace atpm */

#endif /* LOGSELEMENT_H_ */
