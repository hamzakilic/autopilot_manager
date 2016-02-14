/*
 * LogsElement.cpp
 *
 *  Created on: Feb 14, 2016
 *      Author: root
 */

#include "../ui/LogsElement.h"

namespace atpm {
namespace ui {

LogsElement::LogsElement(BaseWindow &_window,atpm_float32 _x,atpm_float32 _y,atpm_float32 _width,atpm_float32 _height,atpm_uint8 _transparency, Color _fillColor)
:RectangleElement(_window,_x,_y,_width,_height,_transparency,_fillColor){
	// TODO Auto-generated constructor stub

}

LogsElement::~LogsElement() {
	// TODO Auto-generated destructor stub
}

void LogsElement::OnRender(){
	//RectangleElement::OnRender();
	TTF_Font *gFont =  TTF_OpenFont( "/work/projects/tobor/autopilot_manager/src/fonts/OpenSans-Bold.ttf", 14 );
	if(gFont==NULL)
		throw AtpmException("font loading exception\n");
	SDL_Color color;
	color.r=100;
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, "hamza", color );
	SDL_Texture *mTexture = SDL_CreateTextureFromSurface( window.GetRenderer(), textSurface );
	SDL_RenderCopy(window.GetRenderer(),mTexture,NULL,NULL);




}


} /* namespace ui */
} /* namespace atpm */
