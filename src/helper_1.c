#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#include "helper_1.h"

SDL_Window *Window = NULL;
SDL_Renderer *Renderer = NULL;
SDL_Event event;
SDL_Surface *temp_surface;
SDL_Texture *logo;
SDL_Rect logo_dst;
SDL_Point mouse;
int ww;
int wh;
int running;

void init(void)
{
	ww = WW;
	wh = WH;
	SDL_Init(SDL_INIT_EVERYTHING);
	Window = SDL_CreateWindow("", 0, 0, 0, 0, SDL_WINDOW_HIDDEN | SDL_WINDOW_RESIZABLE);
	SDL_Surface *icon;
	icon = IMG_Load("./assets/gfx/icon.png");
	SDL_SetWindowIcon(Window, icon);
	SDL_FreeSurface(icon);
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode(Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	SDL_SetWindowPosition(Window, 0, 0);
	SDL_SetWindowSize(Window, ww, wh);
	SDL_ShowWindow(Window);
}

void assets_in(void)
{
	temp_surface = IMG_Load("./assets/gfx/logo.png");
	logo = SDL_CreateTextureFromSurface(Renderer, temp_surface);
	SDL_QueryTexture(logo, NULL, NULL, &logo_dst.w, &logo_dst.h);
	logo_dst.x = logo_dst.w;
	logo_dst.y = logo_dst.h;
}

void get_events(void)
{
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			running = 0;
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
}

void draw(void)
{
	SDL_SetRenderDrawColor(Renderer, WHITE);
	SDL_RenderClear(Renderer);
	SDL_RenderCopy(Renderer, logo, NULL, &logo_dst);
	SDL_RenderPresent(Renderer);
}

void assets_out(void)
{
	SDL_FreeSurface(temp_surface);
	SDL_DestroyTexture(logo);
}

void exit_(void)
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();
}
