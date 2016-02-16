/*
 * LogsElement.cpp
 *
 *  Created on: Feb 14, 2016
 *      Author: root
 */

#include "../ui/LogsElement.h"

namespace atpm {
namespace ui {

LogsElement::LogsElement(BaseWindow &_window,atpm_float32 _x,atpm_float32 _y,atpm_float32 _width,atpm_float32 _height,atpm_uint8 _transparency, Color _fillColor,Color _foreColor)
:RectangleElement(_window,_x,_y,_width,_height,_transparency,_fillColor),gFont(0),foreColor(_foreColor){
	gFont =  TTF_OpenFont( "/work/projects/tobor/autopilot_manager/src/fonts/OpenSans-Regular.ttf", 14 );
				if(gFont==NULL)
					throw AtpmException("font loading exception\n");

}

LogsElement::~LogsElement() {

	if(gFont)
		TTF_CloseFont(gFont);
}

void LogsElement::AddLog(atpm_string log){
	if(logs.size()==20)
		logs.pop_front();
   logs.push_back(log);

}

void LogsElement::OnRender(){
	RectangleElement::OnRender();
	SDL_Color color;
	color.r=foreColor.R;
	color.g=foreColor.G;
	color.b=foreColor.B;
	color.a=foreColor.A;

	TextureHelper texElementHelper(texture);
	texElementHelper.Lock();
	atpm_int32 rows=0;

	for(list<atpm_string>::iterator it=logs.begin();it!=logs.end();++it){
	SDL_Surface* textSurface = TTF_RenderUTF8_Blended(gFont, (*it).c_str(), color );


	if(textSurface==NULL)
		throw AtpmException("TTF surface create failed",SDL_GetError());


	 for(atpm_uint32 h=0;h<textSurface->h;++h){
	    	for(atpm_uint32 w=0;w<textSurface->w;++w){
	    		atpm_uint32 argb=((atpm_uint32*)(textSurface->pixels))[h*textSurface->w+w];
	    	 texElementHelper.Pixels[rows*texElementHelper.Width()+w]= argb;

	    	}

	    	rows++;
	 }





	SDL_FreeSurface(textSurface);



	}
	texElementHelper.Unlock();





}


} /* namespace ui */
} /* namespace atpm */
