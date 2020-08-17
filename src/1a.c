#pragma GCC diagnostic ignored "-Wunknown-pragmas"
/*
 * Scale png
 * png size 179 x 99
 */
#include <math.h>
#include "helper_1.h"

int main(int argc, char *argv[])
{

		(void)argc;
		(void)argv;

		init();
		assets_in();
		SDL_SetWindowTitle(Window, "Scale");

		running = 1;
		int flip = 1;
		while (running) {
				get_events();
				// Update rect
				// With vsync the function is called 60 times per second
				if (flip) { // scale up
						logo_dst.x-=1;
						logo_dst.y-=1;
						logo_dst.h+=2;
						logo_dst.w+=2;
						if (logo_dst.h >= wh)
								flip=0;
				}
				else {	  // scale down
						logo_dst.x+=1;
						logo_dst.y+=1;
						logo_dst.h-=2;
						logo_dst.w-=2;
						if (logo_dst.h <= wh/2)
								flip=1;
				}
				draw();
		}
		assets_out();
		exit_();
		return EXIT_SUCCESS;
}
