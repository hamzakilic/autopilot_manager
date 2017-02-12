/*
 * InputDataElement.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: root
 */

#include "../ui/InputDataElement.h"

namespace atpm {
namespace ui {

InputDataElement::InputDataElement(BaseWindow &_window,atpm_float32 _x,atpm_float32 _y,atpm_float32 _width,atpm_float32 _height,atpm_uint8 _transparency, Color _fillColor,Color _foreColor)
:RectangleElement(_window,_x,_y,_width,_height,_transparency,_fillColor),foreColor(_foreColor){

	gFont =  TTF_OpenFont( "/work/projects/tobor/autopilot_manager/src/fonts/OpenSans-Regular.ttf", 14 );
					if(gFont==NULL)
						throw AtpmException("font loading exception\n");

	}

InputDataElement::~InputDataElement() {

		if(gFont)
			TTF_CloseFont(gFont);
	}

void InputDataElement::UpdateInputData(InputData _data){
   mutex.Lock();
   data=_data;
   mutex.Unlock();
}

void InputDataElement::OnRender(){

	RectangleElement::OnRender();

    mutex.Lock();

    stringstream ss;

	longtitude="Longtitude:";
    ss<<data.longtitude;
	longtitude+=ss.str();
    ss.str("");

	latitude="Latitude:";
	ss<<data.latitude;
	latitude+=ss.str();
	ss.str("");

	sea_level="Sealevel:";
	ss<<data.sealevel;
	sea_level+=ss.str();
	ss.str("");


	gps_fix="GFix:";
	switch(data.gps_fix){
	  case 0:
		  ss<<"No Fix";break;
	  case 1:
	  	  ss<<"Dead Reckoning";break;
	  case 2:
	  	  ss<<"2D Fix";break;
	  case 3:
	  	  ss<<"3D Fix";break;
	  case 4:
	  	  ss<<"Gps+ Dead Reck";break;
	  case 5:
	  	  ss<<"Time Fix";break;
	  default:
	  	  ss<<"Unknown Option";break;

	  }
	gps_fix+=ss.str();
	ss.str("");

    gps_time="GTime:";
    if(data.year<10)
    	ss<<"000"<<(atpm_int32)data.year<<"-";
    else if(data.year<100)
    	ss<<"00"<<(atpm_int32)data.year<<"-";
    else if(data.year<1000)
        	ss<<"0"<<(atpm_int32)data.year<<"-";
    else
    ss<<(atpm_int32)data.year<<"-";


    if(data.month<10)
    	ss<<"0"<< (atpm_int32)data.month<<"-";
    else ss<<(atpm_int32) data.month<<"-";


    if(data.day<10)
    	ss<<"0"<< (atpm_int32)data.day<<" ";
    else ss<< (atpm_int32)data.day<<" ";


    if(data.hour<10)
    	ss<<"0"<<(atpm_int32)data.hour<<":";
    else ss<<(atpm_int32)data.hour<<":";

    if(data.min<10)
        	ss<<"0"<<(atpm_int32)data.min<<":";
        else ss<<(atpm_int32)data.min<<":";

    if(data.sec<10)
        	ss<<"0"<<(atpm_int32)data.sec;
        else ss<<(atpm_int32)data.sec;
    gps_time+=ss.str();
    ss.str("");

	gps_status="GStatus:";
	if(data.status)
			ss<<"No fix";
		else ss<<"Fix ok";
	gps_status+=ss.str();

	ss.str("");



	motor_0="Motor[0]:";
	ss<<(atpm_int32)data.motor_values[0];
	motor_0+=ss.str();
	ss.str("");

	motor_1="Motor[1]:";
	ss<<(atpm_int32)data.motor_values[1];
	motor_1+=ss.str();
	ss.str("");

	motor_2="Motor[2]:";
	ss<<(atpm_int32)data.motor_values[2];
	motor_2+=ss.str();
	ss.str("");

	motor_3="Motor[3]:";
	ss<<(atpm_int32)data.motor_values[3];
	motor_3+=ss.str();
	ss.str("");

	yaw="yaw:";
	ss<<data.yaw;
	yaw+=ss.str();
	ss.str("");

	pitch="pitch:";
	ss<<data.pitch;
	pitch+=ss.str();
	ss.str("");


	roll="roll:";
	ss<<data.roll;
	roll+=ss.str();
	ss.str("");

	altitude="altitude:";
	ss<<data.altitude;
	altitude+=ss.str();
	ss.str("");

	pressure="pressure:";
	ss<<data.pressure;
	pressure+=ss.str();
	ss.str("");

	tempreature="tempreature:";
	ss<<data.tempreature;
	tempreature+=ss.str();
	ss.str("");



    list<atpm_string> logs;
    logs.push_back(longtitude);
    logs.push_back(latitude);
    logs.push_back(sea_level);
    logs.push_back(gps_fix);
    logs.push_back(gps_status);
    logs.push_back(gps_time);
    logs.push_back(motor_0);
    logs.push_back(motor_1);
    logs.push_back(motor_2);
    logs.push_back(motor_3);
    logs.push_back(yaw);
    logs.push_back(pitch);
    logs.push_back(roll);
    logs.push_back(altitude);
    logs.push_back(pressure);
    logs.push_back(tempreature);
	SDL_Color color;
	color.r=foreColor.R;
	color.g=foreColor.G;
	color.b=foreColor.B;
	color.a=foreColor.A;

	TextureHelper texElementHelper(texture);
	texElementHelper.Lock();



	atpm_int32 rows=5;

	for(list<atpm_string>::iterator it=logs.begin();it!=logs.end();++it){

	SDL_Surface* textSurface = TTF_RenderUTF8_Blended(gFont, (*it).c_str(), color );


	if(textSurface==NULL)
		throw AtpmException("TTF surface create failed",SDL_GetError());


	 for(atpm_uint32 h=0;h<textSurface->h;++h){
	    	for(atpm_uint32 w=0;w<textSurface->w;++w){
	    		atpm_uint32 argb=((atpm_uint32*)(textSurface->pixels))[h*textSurface->w+w];
	    		if(w+10<=texElementHelper.Width())
	    	     texElementHelper.Pixels[rows*texElementHelper.Width()+w+10]= argb;

	    	}

	    	rows++;
	    	if(rows>=texElementHelper.Height())
	    		break;

	 }
	// if(rows>=texElementHelper.Height())
	 //	    		break;







	SDL_FreeSurface(textSurface);



	}
	texElementHelper.Unlock();
	mutex.Unlock();




}


} /* namespace ui */
} /* namespace atpm */
