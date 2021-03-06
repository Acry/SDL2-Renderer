#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma region HEAD
#pragma region DESCRIPTION

/* This is a series of examples about the
 * SDL2 Renderer infrastructure.
 * 
 * I hope this helps C-Coders to get GLSL also.
 */

/* DEFINED PROGRESS GOALS
 * Want to make the same gradient like in
 * shader toy
 * https://www.shadertoy.com/new
 * 
 * 	void mainImage( out vec4 fragColor, in vec2 fragCoord )
 *	{
 *	// Normalized pixel coordinates (from 0 to 1)
 *	vec2 uv = fragCoord/iResolution.xy;
 * 
 *	// Time varying pixel color
 *	vec3 col = 0.5 + 0.5*cos(iTime+uv.xyx+vec3(0,2,4));
 * 
 *	// Output to screen
 *	fragColor = vec4(col,1.0); //color and Alpha
 *	}
 * 
 * 
 * 	float iTime	image/sound/buffer	Current time in seconds
 */

/* This is no optimized code for a good reason,
 * I got no chance to compete againt 5000+ cores in parallel on a
 * modern GPU. That will be the next demo in the SDL2-OpenGL series;
 * 
 */
#pragma endregion   DESCRIPTION

#pragma region INCLUDES
//system headers
#include <math.h>
//local headers
#include "helper.h"
#pragma endregion   INCLUDES

#pragma region CPP DEFINITIONS
#define WHITE 	255,255,255,255
#define BLACK 	0,0,0,255
#define RED   	255,0,0,255
#define WW 	255
#define WH 	255
#pragma endregion   CPP DEFINITIONS

#pragma region DATASTRUCTURES
#pragma endregion DATASTRUCTURES

#pragma region GLOBALS
int ww=WW;
int wh=WH;
#pragma region VISIBLES
#pragma endregion 	VISIBLES

#pragma endregion   GLOBALS

#pragma region FUNCTION PROTOTYPES
float	 iTime		(void);
void 	update_screen	(float t);
#pragma endregion FUNCTION PROTOTYPES

#pragma endregion 	HEAD

#pragma region MAIN FUNCTION
int main(int argc, char *argv[])
{

(void)argc;
(void)argv;

#pragma region INIT
init();
#pragma region WINDOW
SDL_SetWindowPosition(Window,0,0);
SDL_SetWindowSize(Window,ww,wh);
SDL_SetWindowTitle(Window, "SDL2 Renderer");
SDL_ShowWindow(Window);
#pragma endregion WINDOW
SDL_Event event;
int running = 1;
#pragma endregion   INIT

#pragma region MAIN LOOP
while(running){
	#pragma region EVENT LOOP
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running =0;
		}
		if(event.type == SDL_WINDOWEVENT){
			if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED){
				ww = event.window.data1;
				wh = event.window.data2;

			}
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
	#pragma endregion   EVENT LOOP
	update_screen(iTime());

}
#pragma endregion   MAIN LOOP
exit_();
return EXIT_SUCCESS;

}
#pragma endregion   MAIN FUNCTION

#pragma region FUNCTIONS
void update_screen(float t)
{
	SDL_RenderClear(Renderer);

	for (int i=0; i <ww; i++){
		for (int j=0; j <wh; j++){
			float r,g,b;
			// 	vec3 col = 0.5 + 0.5*cos(iTime+uv.xyx+vec3(0,2,4));
			//	0.5 + 0.5*cos(fTime+pix_map[i].pos.x+(1.0-pix_map[i].pos.y));
			r=0.5 + 0.5 * cosf(t+ (float)i/(float)ww + (1.0 - (float)j/(float)wh )+0.0);
			g=0.5 + 0.5 * cosf(t+ (float)i/(float)ww + (1.0 - (float)j/(float)wh )+2.0);
			b=0.5 + 0.5 * cosf(t+ (float)i/(float)ww + (1.0 - (float)j/(float)wh )+4.0);
			
			SDL_SetRenderDrawColor(Renderer, roundf(r * 255),roundf(g * 255),roundf(b * 255),255);
			SDL_RenderDrawPoint(Renderer,i,j);
		}
		
	}
	SDL_RenderPresent(Renderer);
}

float iTime(void)
{
	static Uint64 start 	= 0;
	static Uint64 frequency  = 0;
	
	if (start==0){
		start		=	SDL_GetPerformanceCounter();
		frequency	=	SDL_GetPerformanceFrequency();
		return 0.0f;
	}
	
	Uint64 counter = 0;
	counter=SDL_GetPerformanceCounter();
	Uint64 accumulate = counter - start;

	return   (float)accumulate / (float)frequency;

}
#pragma endregion   FUNCTIONS
