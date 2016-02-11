/*
 * MainWindow.h
 *
 *  Created on: Feb 10, 2016
 *      Author: root
 */

#ifndef UI_MAINWINDOW_H_
#define UI_MAINWINDOW_H_
#include "../ui/BaseWindow.h"
#include "../ui/BaseElement.h"
#include <vector>

using namespace std;
namespace atpm {
namespace ui{

class MainWindow:public BaseWindow {
public:
	MainWindow();
	virtual ~MainWindow();
	virtual void AddChild(BaseElement *element);
	virtual void Render();
private:
	vector<BaseElement *> childs;
};

} /* namespace atpm::ui */
} //namespace atpm

#endif /* UI_MAINWINDOW_H_ */
