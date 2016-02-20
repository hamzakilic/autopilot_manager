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

    TextureHelper texHelper(texture);

    atpm_uint32 calcColor=fillColor.A<<24;
	calcColor|=fillColor.R<<16;
	calcColor|=fillColor.G<<8;
	calcColor|=fillColor.B;
	texHelper.Lock();

    atpm_int32 pixelCount=texHelper.PixelCount();

    for(atpm_uint32 h=0;h<texHelper.Height();++h){

    	for(atpm_uint32 w=0;w<texHelper.Width();++w){
    	texHelper.Pixels[h*texHelper.Width()+w]=calcColor;

    	}
    }

    texHelper.Unlock();




}

} /* namespace ui */
} /* namespace atpm */
