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
#include <ui/BaseElement.h>
#include <ui/RectangleElement.h>
#include <ui/LogsElement.h>
#include <net/LogPort.h>
#include <net/LogParser.h>
#include <ui/Window.h>
#include <ui/AutoPilotWindow.h>

using namespace std;
using namespace atpm;
using namespace atpm::common;
using namespace atpm::ui;
using namespace atpm::net;


void initTTFSDL(){


	if(TTF_Init()==-1) {
		string error="SDL ttf init error:";
		error.append(TTF_GetError());
	    throw AtpmException(error);
	}


	SDL_version compile_version;
			const SDL_version *link_version=TTF_Linked_Version();
			SDL_TTF_VERSION(&compile_version);
			printf("compiled with SDL_ttf version: %d.%d.%d\n",
			        compile_version.major,
			        compile_version.minor,
			        compile_version.patch);
			printf("running with SDL_ttf version: %d.%d.%d\n",
			        link_version->major,
			        link_version->minor,
			        link_version->patch);
			if(compile_version.major!=link_version->major || compile_version.minor!=link_version->minor )
				throw AtpmException("SDL ttf version problem\n");
}

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
		/*LogParser parser2;
		LogPort port2(9999,parser2);
		port2.Test();*/

		initializeSDL();
        initTTFSDL();





       AutoPilotWindow window;

       while(!quit){

    		   //Handle events on queue
    		   while( SDL_PollEvent( &ev ) != 0 )
    		   { //User requests quit
    			   if( ev.type == SDL_QUIT )
    			   {
    				   quit = 1;
    				   break;
    			   }
    			   //Handle window events
    			   window.HandleEvents( ev );

    		   }

    	   SDL_Delay(1000/25);
    	   window.Render();
       }
       //delete rect;


	}catch(AtpmException &ex){
		cout<<ex.what()<<endl;
	}

	quitSDL();




	return 0;
}

