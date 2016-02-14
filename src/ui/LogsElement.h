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
#include <list>

using namespace std;

namespace atpm {
namespace ui {

class LogsElement:public RectangleElement {
public:
	LogsElement(BaseWindow &_window,atpm_float32 _x,atpm_float32 _y,atpm_float32 _width,atpm_float32 _height,atpm_uint8 _transparency, Color _fillColor,Color _foreColor);
	virtual ~LogsElement();
	void AddLog(atpm_string log);
	void OnRender();
private:
	list<atpm_string> logs;
	TTF_Font *gFont;
	Color foreColor;
};

} /* namespace ui */
} /* namespace atpm */

#endif /* LOGSELEMENT_H_ */
