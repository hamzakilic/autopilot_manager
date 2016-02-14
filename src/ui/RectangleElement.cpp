/*
 * Rectangle.cpp
 *
 *  Created on: Feb 12, 2016
 *      Author: root
 */

#include "../ui/RectangleElement.h"


namespace atpm {
namespace ui {

RectangleElement::RectangleElement(BaseWindow &_window,atpm_float32 _x,atpm_float32 _y, atpm_float32 _width,atpm_float32 _height,atpm_uint8 _transparency,Color _fillColor)
:BaseElement(_window,_x,_y,_width,_height,_transparency),fillColor(_fillColor){
	// TODO Auto-generated constructor stub

}

RectangleElement::~RectangleElement() {
	// TODO Auto-generated destructor stub
}


void RectangleElement::OnRender(){
    AtpmLog::Debug("Rendering Rectangle\n");

	atpm_uint32 textureFormat;
	atpm_int32 access,w,h;
	SDL_QueryTexture(texture,&textureFormat,&access,&w,&h);

	atpm_uint32 *pixels;
	atpm_int32 pitch;
	atpm_uint32 calcColor=fillColor.R<<24;
	calcColor|=fillColor.G<<16;
	calcColor|=fillColor.B<<8;
	calcColor|=fillColor.A;

	SDL_LockTexture(texture,NULL,(void**)&pixels,&pitch);
    atpm_int32 pixelCount=pitch/4*h;

    for(atpm_uint32 i=0;i<pixelCount;++i)
    	pixels[i]=calcColor;


	SDL_UnlockTexture(texture);



}

} /* namespace ui */
} /* namespace atpm */
