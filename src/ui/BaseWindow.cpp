/*
 * BaseWindow.cpp
 *
 *  Created on: Feb 10, 2016
 *      Author: root
 */

#include "../ui/BaseWindow.h"

namespace atpm {
namespace ui{

BaseWindow::BaseWindow(const atpm_cstring * _name,atpm_uint32 _width,atpm_uint32 _height):name(_name,strlen(_name)), width(_width),height(_height),renderer(0),window(0),windowId(0) {

	window = SDL_CreateWindow( name.c_str() , SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN);
	if(window==NULL)
		throw AtpmException("Could not create window");
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if(renderer==NULL)
		throw AtpmException("Could not create renderer");

	windowId=SDL_GetWindowID(window);

}

BaseWindow::~BaseWindow() {
	if(renderer!=NULL)
		SDL_DestroyRenderer(renderer);
   if(window!=NULL){
	   SDL_DestroyWindow(window);
   }

}

BaseWindow::BaseWindow(const BaseWindow &r){
   throw AtpmException("Dont Call BaseWindow Copy Constructor");
}


void BaseWindow::Show(){


}

void BaseWindow::HandleEvents(SDL_Event &ev){

	if( ev.type == SDL_WINDOWEVENT && ev.window.windowID == windowId ) {
        switch( ev.window.event )
        {
            //Window appeared
            case SDL_WINDOWEVENT_SHOWN:
            HandleWindowShow();
            break;

            //Window disappeared
            case SDL_WINDOWEVENT_HIDDEN:
            HandleWindowHidden();
            break;

            //Get new dimensions and repaint
            case SDL_WINDOWEVENT_SIZE_CHANGED:
            HandleWindowSizeChanged(ev.window.data1,ev.window.data2);
            break;

            //Repaint on expose
            case SDL_WINDOWEVENT_EXPOSED:
            HandleWindowExposed();
            break;

            //Mouse enter
            case SDL_WINDOWEVENT_ENTER:
            HandleWindowMouseEnter();
            break;

            //Mouse exit
            case SDL_WINDOWEVENT_LEAVE:
            HandleWindowMouseExit();
            break;

            //Keyboard focus gained
            case SDL_WINDOWEVENT_FOCUS_GAINED:
            HandleWindowKeyboardFocused();
            break;

            //Keyboard focus lost
            case SDL_WINDOWEVENT_FOCUS_LOST:
            HandleWindowKeyboardFocusedLost();
            break;

            //Window minimized
            case SDL_WINDOWEVENT_MINIMIZED:
            HandleWindowMinimized();
            break;

            //Window maxized
            case SDL_WINDOWEVENT_MAXIMIZED:
            HandleWindowMaximized();
            break;

            //Window restored
            case SDL_WINDOWEVENT_RESTORED:
            HandleWindowRestored();
            break;

            //Hide on close
            case SDL_WINDOWEVENT_CLOSE:
            HandleWindowClose();
            break;
        }
	}else if(ev.type==SDL_KEYDOWN && ev.window.windowID == windowId){
		HandleKey(ev.key);
	}else  if(ev.type==SDL_MOUSEMOTION && ev.window.windowID == windowId){
		HandleMouse(ev.motion);
	}

}


void BaseWindow::HandleMouse(SDL_MouseMotionEvent &mouse){
	AtpmLog::Debug("BaseWindow HandleMouse Called x:%d y:%d\n",mouse.x,mouse.y);
}

void BaseWindow::HandleKey(SDL_KeyboardEvent &key){
	switch(key.type){
	case SDL_KEYDOWN:AtpmLog::Debug("BaseWindow HandleKey Called KeyDown\n");break;
	case SDL_KEYUP:AtpmLog::Debug("BaseWindow HandleKey Called KeyUp\n");break;
	default:break;
	}
	switch(key.keysym.sym ){
	case SDLK_UP:AtpmLog::Debug("BaseWindow HandleKey Called Key is:Up\n");break;

	}
}

void BaseWindow::HandleWindowShow(){
AtpmLog::Debug("BaseWindow HandleWindowShow Called\n");

}
void BaseWindow::HandleWindowHidden(){
	AtpmLog::Debug("BaseWindow HandleWindowHidden Called\n");


}
void BaseWindow::HandleWindowSizeChanged(atpm_uint32 newwidth,atpm_uint32 newheight){
	AtpmLog::Debug("BaseWindow HandleWindowSizeChanged Called\n");


}
void BaseWindow::HandleWindowExposed(){
	AtpmLog::Debug("BaseWindow HandleWindowExposed Called\n");
	Render();

}
void BaseWindow::HandleWindowMouseEnter(){
	AtpmLog::Debug("BaseWindow HandleWindowMouseEnter Called\n");


}
void BaseWindow::HandleWindowMouseExit(){
	AtpmLog::Debug("BaseWindow HandleWindowMouseExit Called\n");


}
void BaseWindow::HandleWindowKeyboardFocused(){
	AtpmLog::Debug("BaseWindow HandleWindowKeyboardFocused Called\n");


}
void BaseWindow::HandleWindowKeyboardFocusedLost(){
	AtpmLog::Debug("BaseWindow HandleWindowKeyboardFocusedLost Called\n");


}
void BaseWindow::HandleWindowMinimized(){
	AtpmLog::Debug("BaseWindow HandleWindowMinimized Called\n");

}
void BaseWindow::HandleWindowMaximized(){
	AtpmLog::Debug("BaseWindow HandleWindowMaximized Called\n");


}
void BaseWindow::HandleWindowRestored(){
	AtpmLog::Debug("BaseWindow HandleWindowRestored Called\n");


}

void BaseWindow::HandleWindowClose(){
	AtpmLog::Debug("BaseWindow HandleWindowClose Called\n");

}
 void BaseWindow::DrawBackground(){
	SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
		SDL_RenderClear(renderer);
}

void BaseWindow::Render(){
	AtpmLog::Debug("BaseWindow Render Called\n");

    SDL_RenderPresent(renderer);
}
SDL_Renderer * BaseWindow::GetRenderer(){
	return renderer;
}
SDL_Window * BaseWindow::GetSdlWindow(){
	return window;

}



} /* namespace atpm::ui */
} //namespace atpm
