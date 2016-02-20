/*
 * InputDataElement.h
 *
 *  Created on: Feb 18, 2016
 *      Author: root
 */

#ifndef INPUTDATAELEMENT_H_
#define INPUTDATAELEMENT_H_

#include "../ui/RectangleElement.h"
#include "../ui/Color.h"
#include "../net/LogParser.h"

namespace atpm {
namespace ui {
using namespace atpm::common;
using namespace atpm::net;


class InputDataElement:public RectangleElement {
public:
	InputDataElement(BaseWindow &_window,atpm_float32 _x,atpm_float32 _y,atpm_float32 _width,atpm_float32 _height,atpm_uint8 _transparency, Color _fillColor,Color _foreColor);
	virtual ~InputDataElement();
	void UpdateInputData(InputData _data);
	void OnRender();
private:
	InputData data;
	AtpmMutex mutex;
	TTF_Font *gFont;
	Color foreColor;
	atpm_string longtitude;
	atpm_string latitude;
	atpm_string sea_level;
	atpm_string gps_fix;
	atpm_string gps_status;
	atpm_string gps_time;
	atpm_string motor_0;
	atpm_string motor_1;
	atpm_string motor_2;
	atpm_string motor_3;
	atpm_string yaw;
	atpm_string pitch;
	atpm_string roll;
	atpm_string pressure;
	atpm_string altitude;
	atpm_string tempreature;



};

} /* namespace ui */
} /* namespace atpm */

#endif /* INPUTDATAELEMENT_H_ */
