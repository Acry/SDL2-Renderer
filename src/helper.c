#include "helper.h"
SDL_Window   	*Window	  = NULL;
SDL_Renderer 	*Renderer = NULL;

void init(void)
{

SDL_Init(SDL_INIT_EVERYTHING);
Window = SDL_CreateWindow("", 0, 0, 0, 0, SDL_WINDOW_HIDDEN|SDL_WINDOW_RESIZABLE);

//BEGIN ICON
SDL_Surface *icon;
icon=IMG_Load("./assets/gfx/icon.png");
SDL_SetWindowIcon(Window, icon);
SDL_FreeSurface(icon);
//END 	ICON

//After the window is created we can call the renderer creation and bind it to the window.
Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//I asked for GPU support and rendering will be sync'ed to the vertical sync of your Monitor,
//if applicable

//alpha blending
SDL_SetRenderDrawBlendMode(Renderer, SDL_BLENDMODE_BLEND);
//https://wiki.libsdl.org/SDL_SetRenderDrawBlendMode

//linear filtering (supported by OpenGL and Direct3D)
SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
//https://wiki.libsdl.org/SDL_HINT_RENDER_SCALE_QUALITY
}

void exit_(void)
{

SDL_DestroyRenderer(Renderer);
SDL_DestroyWindow(Window);
SDL_Quit();

}
