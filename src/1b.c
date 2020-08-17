#pragma GCC diagnostic ignored "-Wunknown-pragmas"
/*
 * Scale png
 * png size 179 x 99
 * just a little break after reaching sizes
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
		int pause = 1;
		int count = 0;
		while (running) {
				get_events();
				// Update rect
				// With vsync the function is called 60 times per second
				if (pause) {
						if (flip) { // scale up
								logo_dst.x-=1;
								logo_dst.y-=1;
								logo_dst.h+=2;
								logo_dst.w+=2;
								if (logo_dst.h >= wh) {
										flip=0;
										pause = 0;
								}
						}
						else {	  // scale down
								logo_dst.x+=1;
								logo_dst.y+=1;
								logo_dst.h-=2;
								logo_dst.w-=2;
								if (logo_dst.h <= wh/2) {
										flip=1;
										pause = 0;
								}
						}
				}
				else {
						count++;
						if (count == 60) {
								count = 0;
								pause = 1;
						}
				}
				draw();
		}
		assets_out();
		exit_();
		return EXIT_SUCCESS;
}
