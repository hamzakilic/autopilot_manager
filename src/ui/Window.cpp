/*
 * MainWindow.cpp
 *
 *  Created on: Feb 10, 2016
 *      Author: root
 */

#include <ui/Window.h>

namespace atpm {
namespace ui{

Window::Window(const atpm_cstring *_name,atpm_uint32 _width,atpm_uint32 _height,Color _background)
:BaseWindow(_name,_width,_height,_background){



}

Window::~Window() {

}
void Window::AddChild(BaseElement *element){
   childs.push_back(element);
}
void Window::Render(){

   mutex.Lock();
   DrawBackground();
   for(atpm_int32 i=0;i<childs.size();++i){
	      childs[i]->Render();
   }
   BaseWindow::Render();
   mutex.Unlock();



}


} /* namespace atpm::ui */
} /* namespace atpm*/
