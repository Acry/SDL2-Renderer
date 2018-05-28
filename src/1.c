//BEGIN HEAD
//BEGIN DESCRIPTION

/* This is a series of examples about the
 * SDL2 Renderer infrastructure.
 * Check comments in helper.c
 * 
 * Rendering a png to the screen
 */


/* DEFINED PROGRESS GOALS
 * 
 * None atm
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
#define WHITE 255,255,255,255
#define BLACK 0,0,0,255
#define RED   255,0,0,255
#define WW 550
#define WH (WW/16)*12
//END   CPP DEFINITIONS

//BEGIN DATASTRUCTURES
//END	DATASTRUCTURES

//BEGIN GLOBALS
int ww=WW;
int wh=WH;

//BEGIN VISIBLES
SDL_Surface    *temp_surface	= NULL;

SDL_Texture    *logo		= NULL;
SDL_Rect 	logo_dst;
//END 	VISIBLES

SDL_Point	mouse;

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
//Got the renderer now
//Now I am going to create a texture from the surface I loaded
//follow the function definition
assets_in();

//BEGIN WINDOW
SDL_SetWindowPosition(Window,0,0);
SDL_SetWindowSize(Window,ww,wh);
SDL_SetWindowTitle(Window, "SDL2 Renderer");
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
	//It's way quicker to blank the whole screen instead of rects
	//remember - on the gpu now.
	SDL_SetRenderDrawColor(Renderer, WHITE);
	SDL_RenderClear(Renderer);
	//passing some pointers, what and where to draw before 
	//the scene is drawn.
	//What is passed first will be on the bottom level
	//like a stack
	SDL_RenderCopy(Renderer, logo, NULL, &logo_dst);

	SDL_RenderPresent(Renderer);
	//END   RENDERING
}
//END   MAIN LOOP

assets_out();
exit_();
return EXIT_SUCCESS;

}
//END   MAIN FUNCTION

//BEGIN FUNCTIONS
void assets_in(void)
{
	// The Texture in this case is declared in globally
	// so it's available for other functions without passing it
	// as argument.
	
	// SDL_Texture    *logo		= NULL;
	// It is a typedef'ed struct declared in SDL_render.h
	//BEGIN LOGO
	temp_surface = IMG_Load("./assets/gfx/logo.png");
	// That wasn't new - just loading the image format to a surface
	
	// Now I call CreateTextureFromSurface to convert the image
	// to pass it to the GPU-Memory
	
	// https://wiki.libsdl.org/SDL_CreateTextureFromSurface
	logo = SDL_CreateTextureFromSurface(Renderer, temp_surface);
	
	// Since one can't just simply query the the texture all the time
	// like with surfaces (surface->w/w)
	// I call
	SDL_QueryTexture(logo, NULL, NULL, &logo_dst.w, &logo_dst.h);
	// instead.
	// https://wiki.libsdl.org/SDL_QueryTexture
	// not passing format or access here. just interesting in the
	// dimensions

	logo_dst.x=(ww/2)-(logo_dst.w/2);
	logo_dst.y=(wh/2)-(logo_dst.h/2);
	//END 	LOGO
	// Now the Texture is set and we are good to render is.
	// check the main loop

}

void assets_out(void)
{
	//Need to deallocate what was allocated
	SDL_FreeSurface(temp_surface);
	SDL_DestroyTexture(logo);
}

//END   FUNCTIONS
