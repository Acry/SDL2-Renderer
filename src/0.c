// setup renderer
#include <stdlib.h>
#include <SDL2/SDL.h>

SDL_Window   *Window;
SDL_Renderer *Renderer;

int main(int argc, char *argv[])
{

(void)argc;
(void)argv;

Window = SDL_CreateWindow("", 0, 0, 0, 0, SDL_WINDOW_HIDDEN);
SDL_SetWindowPosition(Window,0,0);
SDL_SetWindowSize(Window,540,540);
SDL_SetWindowTitle(Window, "SDL 2 - Renderer");
SDL_ShowWindow(Window);

Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
SDL_Event event;
int running = 1;

while(running){
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_RIGHT){
				running=0;
			}
		}
	}




SDL_SetRenderDrawColor(Renderer, 111, 111, 111, 255);
SDL_RenderClear(Renderer);
SDL_RenderPresent(Renderer);

}

SDL_DestroyRenderer(Renderer);
SDL_DestroyWindow(Window);
SDL_Quit();
return EXIT_SUCCESS;

}
