#ifndef _HELPER_H_
#define _HELPER_H_

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WHITE 255,255,255,255
#define BLACK 0,0,0,255
#define RED   255,0,0,255
#define WW 550
#define WH (WW/16)*9

extern int ww;
extern int wh;
extern int running;

extern SDL_Window	*Window;
extern SDL_Renderer	*Renderer;
extern SDL_Event	event;
extern SDL_Surface	*temp_surface;
extern SDL_Texture	*logo;
extern SDL_Rect 	logo_dst;
extern SDL_Point	mouse;

void assets_in(void);
void assets_out(void);
void init(void);
void get_events(void);
void draw(void);
void exit_(void);
#endif
