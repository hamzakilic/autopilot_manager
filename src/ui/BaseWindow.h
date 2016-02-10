/*
 * BaseWindow.h
 *
 *  Created on: Feb 10, 2016
 *      Author: root
 */

#ifndef UI_BASEWINDOW_H_
#define UI_BASEWINDOW_H_

#include "../common/AtpmCommon.h"
#include "../common/AtpmException.h"
#include "../common/AtpmLog.h"

namespace atpm {
namespace ui {

using namespace atpm::common;

class BaseWindow {
public:
	BaseWindow(const atpm_cstring *_name="BaseWindow",atpm_uint32 _width=300,atpm_uint32 _height=300);
	virtual ~BaseWindow();
    virtual void Show();
    void HandleEvents(SDL_Event &ev);
protected:
   virtual void HandleWindowShow();
   virtual void HandleWindowHidden();
   virtual void HandleWindowSizeChanged(atpm_uint32 newwidth,atpm_uint32 newheight);
   virtual void HandleWindowExposed();
   virtual void HandleWindowMouseEnter();
   virtual void HandleWindowMouseExit();
   virtual void HandleWindowKeyboardFocused();
   virtual void HandleWindowKeyboardFocusedLost();
   virtual void HandleWindowMinimized();
   virtual void HandleWindowMaximized();
   virtual void HandleWindowRestored();
   virtual void HandleWindowClose();






private:
	BaseWindow(const BaseWindow &r);
protected:
	atpm_string name;
	atpm_uint32 width;
	atpm_uint32 height;
	SDL_Renderer *renderer;
	SDL_Window *window;
	atpm_int32 windowId;




};

} /* namespace atpm::ui */
} /* namespace atpm */

#endif /* UI_BASEWINDOW_H_ */
