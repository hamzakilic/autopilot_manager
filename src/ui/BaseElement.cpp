/*
 * BaseElement.cpp
 *
 *  Created on: Feb 12, 2016
 *      Author: root
 */

#include "BaseElement.h"

namespace atpm {
namespace ui{

BaseElement::BaseElement(BaseWindow &_window,atpm_float32 _x,atpm_float32 _y, atpm_float32 _width,atpm_float32 _height,atpm_uint8 _transparency)
:window(_window),x(_x),y(_y),width(_width),height(_height),window_width(0),window_height(0),transparency(_transparency),texture(0) {


}


BaseElement::~BaseElement() {
	AtpmLog::Debug("Destroying BaseElement\n");
	if(texture)
	SDL_DestroyTexture(texture);
}

void BaseElement::CreateTexture(){
	atpm_int32 w,h;
	SDL_GetWindowSize(window.GetSdlWindow(),&w,&h);
	if(w!=window_width || h!=window_height){//window size changed
	 window_width=w;
	 window_height=h;
	if(texture)
		SDL_DestroyTexture(texture);

		SDL_GetWindowSize(window.GetSdlWindow(),&window_width,&window_height);
		texture=SDL_CreateTexture(window.GetRenderer() , SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width*window_width, height*window_height);
		if(texture==NULL)
			throw AtpmException("Could not create texture\n");
		SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_BLEND);
		if(SDL_SetTextureAlphaMod(texture,transparency))
					{
					throw AtpmException("Texture alpha mod is not supported\n");
					}
	}

}

void BaseElement::Render(){
	CreateTexture();
	OnRender();
	SDL_Rect rect;
		rect.x=x*window_width;
		rect.y=y*window_height;
		rect.w=width*window_width;
		rect.h=height*window_height;
		SDL_RenderCopy(window.GetRenderer(),texture,NULL,&rect);

}




} /* namespace ui */
} /* namespace atpm */
