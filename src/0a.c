// setup renderer with helper
#include "helper.h"

int main(int argc, char *argv[])
{

(void)argc;
(void)argv;

init();

SDL_SetWindowPosition(Window,0,0);
SDL_SetWindowSize(Window,540,540);
SDL_SetWindowTitle(Window, "SDL 2 - Renderer");
SDL_ShowWindow(Window);
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

exit_();
return EXIT_SUCCESS;

}
