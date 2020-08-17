#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma region HEAD
#pragma region DESCRIPTION

/* This is a series of examples about the
 * SDL2 Renderer infrastructure.
 * 
 * 
 */

/* DEFINED PROGRESS GOALS
 * Want to make the same gradient like in surfaces Nr.6,
 * but resized to the window dimensions.
 * 
 */
#pragma endregion DESCRIPTION

#pragma region INCLUDES
//system headers
#include <math.h>
//local headers
#include "helper.h"
#pragma endregion INCLUDES

#pragma region CPP DEFINITIONS
#define WHITE 255, 255, 255, 255
#define BLACK 0, 0, 0, 255
#define RED 255, 0, 0, 255
#define WW 255
#define WH 255
#pragma endregion CPP DEFINITIONS

#pragma region DATASTRUCTURES
#pragma endregion DATASTRUCTURES

#pragma region GLOBALS
int ww = WW;
int wh = WH;
#pragma region VISIBLES
#pragma endregion VISIBLES

#pragma endregion GLOBALS

#pragma region FUNCTION PROTOTYPES
void update_screen(void);
#pragma endregion FUNCTION PROTOTYPES

#pragma endregion HEAD

#pragma region MAIN FUNCTION
int main(int argc, char *argv[])
{

	(void)argc;
	(void)argv;

#pragma region INIT
	init();
#pragma region WINDOW
	SDL_SetWindowPosition(Window, 0, 0);
	SDL_SetWindowSize(Window, ww, wh);
	SDL_SetWindowTitle(Window, "SDL2 Renderer");
	SDL_ShowWindow(Window);
#pragma endregion WINDOW

	SDL_Event event;
	int running = 1;
#pragma endregion INIT

#pragma region MAIN LOOP
	while (running)
	{

#pragma region EVENT LOOP
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = 0;
			}
			if (event.type == SDL_WINDOWEVENT)
			{
				if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
				{
					ww = event.window.data1;
					wh = event.window.data2;
					update_screen();
				}
			}
			if (event.type == SDL_MOUSEMOTION)
			{
				;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_RIGHT)
				{
					;
				}
				if (event.button.button == SDL_BUTTON_MIDDLE)
				{
					;
				}
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					;
				}
			}
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = 0;
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
#pragma endregion EVENT LOOP
	}
#pragma endregion MAIN LOOP
	exit_();
	return EXIT_SUCCESS;
}
#pragma endregion MAIN FUNCTION

#pragma region FUNCTIONS
void update_screen(void)
{
	SDL_RenderClear(Renderer);
#pragma region GRADIENT
	for (int i = 0; i < ww; i++)
	{
		for (int j = 0; j < wh; j++)
		{
			SDL_SetRenderDrawColor(Renderer, roundf((255.0 / (float)ww) * (float)i), roundf(255.0 - ((255.0 / (float)wh) * (float)j)), roundf(255.0 - ((255.0 / (float)ww) * (float)i)), 255);
			SDL_RenderDrawPoint(Renderer, i, j);
		}
	}
#pragma endregion GRADIENT
	SDL_RenderPresent(Renderer);
}
#pragma endregion FUNCTIONS
