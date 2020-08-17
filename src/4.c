#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma region HEAD
#pragma region DESCRIPTION

/* This is a series of examples about the
 * SDL2 Renderer infrastructure.
 *
 * Rendering and rotating a png with different Center
 * https://wiki.libsdl.org/SDL_RenderCopyEx
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
#define WHITE 255,255,255,255
#define BLACK 0,0,0,255
#define RED   255,0,0,255
#define WW 550
#define WH (WW/16)*9
#pragma endregion   CPP DEFINITIONS

#pragma region DATASTRUCTURES
#pragma endregion DATASTRUCTURES

#pragma region GLOBALS
int ww=WW;
int wh=WH;

#pragma region VISIBLES
SDL_Surface    *temp_surface	= NULL;

SDL_Texture    *logo		= NULL;
SDL_Rect 	logo_dst;
#pragma endregion 	VISIBLES

SDL_Point	mouse;

#pragma endregion   GLOBALS

#pragma region FUNCTION PROTOTYPES
void assets_in(void);
void assets_out(void);
#pragma endregion FUNCTION PROTOTYPES

#pragma endregion 	HEAD

#pragma region MAIN FUNCTION
int main(int argc, char *argv[])
{

		(void)argc;
		(void)argv;

		#pragma region INIT
		init();
		assets_in();

		#pragma region WINDOW
		SDL_SetWindowPosition(Window, 0, 0);
		SDL_SetWindowSize(Window, ww, wh);
		SDL_SetWindowTitle(Window, "RenderCopyEx - Rotate 2");
		SDL_ShowWindow(Window);
		#pragma endregion WINDOW
		// An angle in degrees that indicates the rotation that will be applied to
		// dstrect, rotating it in a clockwise direction.
		double a=0;
		// Rotation Center:
		SDL_Point c={ logo_dst.x, logo_dst.y };
		SDL_Event event;
		int running = 1;
		#pragma endregion   INIT

		#pragma region MAIN LOOP
		while (running) {

				#pragma region EVENT LOOP
				while (SDL_PollEvent(&event)) {
						if (event.type == SDL_QUIT) {
								running =0;
						}
						if (event.type == SDL_MOUSEMOTION) {
								;
						}
						if (event.type == SDL_MOUSEBUTTONDOWN) {
								if (event.button.button == SDL_BUTTON_RIGHT) {
										;
								}
								if (event.button.button == SDL_BUTTON_MIDDLE) {
										;
								}
								if (event.button.button==SDL_BUTTON_LEFT) {
										;
								}
						}
						if (event.type == SDL_KEYDOWN) {
								switch (event.key.keysym.sym) {
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
				a+=0.1;
				#pragma region RENDERING
				SDL_SetRenderDrawColor(Renderer, WHITE);
				SDL_RenderClear(Renderer);

				// Using Extended Rendercopy
				// Renderer|Texture|SrcRect|DstRect|Rotation-angle & center
				SDL_RenderCopyEx(Renderer, logo, NULL, &logo_dst, a, &c, 0);

				SDL_RenderPresent(Renderer);
				#pragma endregion   RENDERING
		}
		#pragma endregion   MAIN LOOP

		assets_out();
		exit_();
		return EXIT_SUCCESS;

}
#pragma endregion   MAIN FUNCTION

#pragma region FUNCTIONS
void assets_in(void)
{

		#pragma region LOGO
		temp_surface = IMG_Load("./assets/gfx/logo.png");
		logo = SDL_CreateTextureFromSurface(Renderer, temp_surface);
		SDL_QueryTexture(logo, NULL, NULL, &logo_dst.w, &logo_dst.h);
		logo_dst.x=(ww/2)-(logo_dst.w/2);
		logo_dst.y=(wh/2)-(logo_dst.h/2);
		#pragma endregion 	LOGO

}

void assets_out(void)
{

		SDL_FreeSurface(temp_surface);
		SDL_DestroyTexture(logo);
}

#pragma endregion   FUNCTIONS
