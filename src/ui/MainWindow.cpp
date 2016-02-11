/*
 * MainWindow.cpp
 *
 *  Created on: Feb 10, 2016
 *      Author: root
 */

#include "../ui/MainWindow.h"

namespace atpm {
namespace ui{

MainWindow::MainWindow() {
	// TODO Auto-generated constructor stub

}

MainWindow::~MainWindow() {
	// TODO Auto-generated destructor stub
}
void MainWindow::AddChild(BaseElement *element){
   childs.push_back(element);
}
void MainWindow::Render(){
   for(atpm_int32 i=0;i<childs.size();++i){
	   childs[i]->Render();
   }
}


} /* namespace atpm::ui */
} /* namespace atpm*/
