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
#include <ui/RectangleElement.h>
#include <ui/LogsElement.h>

using namespace std;
using namespace atpm;
using namespace atpm::common;
using namespace atpm::ui;



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

		initializeSDL();
        initTTFSDL();





       MainWindow window;
       RectangleElement *rect=new RectangleElement(window,0,0,0.5f,1.0f,100,Color(255,255,0,255));
       LogsElement *rect2=new LogsElement(window,0.2,0,0.5f,0.5f,100,Color(0,255,0,255));
       window.AddChild(rect);
       window.AddChild(rect2);
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
       delete rect;
       delete rect2;

	}catch(AtpmException &ex){
		cout<<ex.what()<<endl;
	}

	quitSDL();




	return 0;
}

