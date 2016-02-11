/*
 ============================================================================
 Name        : autopilot_manager.cpp
 Author      : Hamza Kılıç
 Version     :
 Copyright   : Read LICENSE file
 Description : Hello World in C++,
 ============================================================================
 */




#include <common/AtpmCommon.h>
#include <common/AtpmException.h>
#include <ui/BaseWindow.h>
#include <ui/MainWindow.h>
#include <ui/BaseElement.h>
#include <ui/Rectangle.h>

using namespace std;
using namespace atpm;
using namespace atpm::common;
using namespace atpm::ui;


void initializeSDL(){
	AtpmLog::Debug("Initializing SDL\n");
	if(SDL_Init( SDL_INIT_VIDEO ) < 0 )
		throw AtpmException(SDL_GetError());

}
void quitSDL(){
	SDL_Quit();
}




int main(void) {
	atpm_uint32 quit=0;
	SDL_Event ev;
	try{
		initializeSDL();
       MainWindow window;
       Rectangle *rect=new Rectangle(window,30,30,Color(50,50,50,50));
       window.AddChild(rect);
       while(!quit){

    		   //Handle events on queue
    		   while( SDL_PollEvent( &ev ) != 0 )
    		   { //User requests quit
    			   if( ev.type == SDL_QUIT )
    			   { quit = 1; }
    			   //Handle window events
    			   window.HandleEvents( ev );

    		   }

    	   SDL_Delay(1000/25);
       }

	}catch(AtpmException &ex){
		cout<<ex.what()<<endl;
	}

	quitSDL();




	return 0;
}

