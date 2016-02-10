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
       while(!quit){
    	   while( !quit ) {
    		   //Handle events on queue
    		   while( SDL_PollEvent( &ev ) != 0 )
    		   { //User requests quit
    			   if( ev.type == SDL_QUIT )
    			   { quit = 1; }
    			   //Handle window events
    			   window.HandleEvents( ev );
    		   //Only draw when not minimized if( !gWindow.isMinimized() ) { //Clear screen SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF ); SDL_RenderClear( gRenderer ); //Render text textures gSceneTexture.render( ( gWindow.getWidth() - gSceneTexture.getWidth() ) / 2, ( gWindow.getHeight() - gSceneTexture.getHeight() ) / 2 ); //Update screen SDL_RenderPresent( gRenderer ); } }
    		   }
    	   }
       }

	}catch(AtpmException &ex){
		cout<<ex.what()<<endl;
	}

	quitSDL();




	return 0;
}

