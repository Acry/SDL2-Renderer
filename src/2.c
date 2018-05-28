//BEGIN HEAD
//BEGIN DESCRIPTION

/* This is a series of examples about the
 * SDL2 Renderer infrastructure.
 * 
 * use of SDL_RenderDrawPoint
 * defined in SDL_render.h
 * https://wiki.libsdl.org/SDL_RenderDrawPoint
 * 
 */

/* DEFINED PROGRESS GOALS
 * Want to make the same gradient like in Surfaces Series Nr.6
 * In Demo 3 the Gradient will resize with the window dimensions.
 * 
 */
//END   DESCRIPTION

//BEGIN INCLUDES
//system headers
#include <math.h>
//local headers
#include "helper.h"
//END   INCLUDES

//BEGIN CPP DEFINITIONS
#define WHITE 	255,255,255,255
#define BLACK 	0,0,0,255
#define RED   	255,0,0,255
#define WW 	255
#define WH 	255
//END   CPP DEFINITIONS

//BEGIN DATASTRUCTURES
//END	DATASTRUCTURES

//BEGIN GLOBALS
int ww=WW;
int wh=WH;

//BEGIN VISIBLES
//END 	VISIBLES

//END   GLOBALS

//BEGIN FUNCTION PROTOTYPES
void assets_in	(void);
void assets_out	(void);
//END	FUNCTION PROTOTYPES

//END 	HEAD

//BEGIN MAIN FUNCTION
int main(int argc, char *argv[])
{

(void)argc;
(void)argv;

//BEGIN INIT
init();
//BEGIN WINDOW
SDL_SetWindowPosition(Window,0,0);
SDL_SetWindowSize(Window,ww,wh);
SDL_SetWindowTitle(Window, "RenderDrawPoint");
SDL_ShowWindow(Window);
//END WINDOW

SDL_Event event;
int running = 1;
//END   INIT

//BEGIN MAIN LOOP
while(running){

	//BEGIN EVENT LOOP
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running =0;
		}
		if(event.type == SDL_MOUSEMOTION){
			;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_RIGHT){
				;
			}
			if(event.button.button == SDL_BUTTON_MIDDLE){
				;
			}
			if(event.button.button==SDL_BUTTON_LEFT){
				;
			}
		}
		if(event.type == SDL_KEYDOWN ){
			switch(event.key.keysym.sym ){
				case SDLK_ESCAPE:
					running =0;
					break;

				case SDLK_r:
				case SDLK_BACKSPACE:
					break;

				case SDLK_p:	
				case SDLK_SPACE:
					break;
					
				default:
					break;
			}
		}
	}
	//END   EVENT LOOP
	//BEGIN RENDERING
	SDL_SetRenderDrawColor(Renderer, WHITE);
	SDL_RenderClear(Renderer);
// 	That was the algo from the surfaces example:
// 	for (int i=0; i <screen->w; i++){
// 		for (int j=0; j <screen->h; j++){
// 			color=SDL_MapRGBA(screen->format, i, 255-j, 255-i, 255);
// 			putpixel(screen,i,j,color);
// 		}
// 		
// 	}
// 	Adapt that:
	int i;
	for (i=0; i <ww; i++){
		for (int j=0; j <wh; j++){
			SDL_SetRenderDrawColor(Renderer, i, 255-j, 255-i, 255);
			SDL_RenderDrawPoint(Renderer,i,j);
		}
	}
	SDL_RenderPresent(Renderer);
	//END   RENDERING
	
}
//END   MAIN LOOP
exit_();
return EXIT_SUCCESS;
}
//END   MAIN FUNCTION

//BEGIN FUNCTIONS
//END   FUNCTIONS
