/*
 * MainWindow.h
 *
 *  Created on: Feb 10, 2016
 *      Author: root
 */

#ifndef UI_WINDOW_H_
#define UI_WINDOW_H_
#include "../ui/BaseWindow.h"
#include "../ui/BaseElement.h"
#include "../common/AtpmMutex.h"


#include <vector>

using namespace std;

namespace atpm {
namespace ui{




class Window:public BaseWindow {
public:
	Window(const atpm_cstring *_name="Window",atpm_uint32 _width=300,atpm_uint32 _height=300,Color _background=(0,0,0,255));
	virtual ~Window();
	virtual void AddChild(BaseElement *element);
	virtual void Render();

private:
	vector<BaseElement *> childs;
	AtpmMutex mutex;




};

} /* namespace atpm::ui */
} //namespace atpm

#endif /* UI_MAINWINDOW_H_ */
