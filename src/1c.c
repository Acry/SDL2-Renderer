#include "helper.h"
/* DEFINED GOALS
 * 
 * demonstrate rendering of the xpm format
 *
 */

/* XPM */
char * icon_xpm[] = {
// w  h  number of colors characters per pixel
	"32 23 4                1",
// character    Color
	"           c None",
	"$          c #FFFFFF",
	".          c #000000",
	"+          c #FFFF00",
	"                                ",
	"            ........            ",
	"          ..++++++++..          ",
	"         .++++++++++++.         ",
	"        .++++++++++++++.        ",
	"       .++++++++++++++++.       ",
	"      .++++++++++++++++++.      ",
	"      .+++....++++....+++.      ",
	"     .++++..$.++++..$.++++.     ",
	"     .++++....++++....++++.     ",
	"     .++++++++++++++++++++.     ",
	"     .++++++++++++++++++++.     ",
	"     .+++++++++..+++++++++.     ",
	"     .+++++++++..+++++++++.     ",
	"     .++++++++++++++++++++.     ",
	"      .++++++++++++++++++.      ",
	"      .++...++++++++...++.      ",
	"       .++............++.       ",
	"        .++..........++.        ",
	"         .+++......+++.         ",
	"          ..++++++++..          ",
	"            ........            ",
	"                                "};

int main(int argc, char *argv[])
{

(void)argc;
(void)argv;

init();
SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
SDL_SetWindowPosition(Window, 0, 0);
SDL_SetWindowSize(Window, 400, 400);
SDL_SetWindowTitle(Window, "SDL 2 - resize with logical-render size");
SDL_RenderSetLogicalSize(Renderer, 320, 230);

SDL_Surface *temp_surface = NULL;
temp_surface = IMG_ReadXPMFromArray(icon_xpm);
SDL_Texture *Texture;
Texture = SDL_CreateTextureFromSurface(Renderer, temp_surface);
SDL_FreeSurface(temp_surface);

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
SDL_RenderClear(Renderer);
SDL_SetRenderDrawColor(Renderer, 111, 111, 111, 255);
SDL_RenderCopy(Renderer, Texture, NULL, NULL);
SDL_RenderPresent(Renderer);

}

SDL_DestroyTexture(Texture);
exit_();
return EXIT_SUCCESS;
}

