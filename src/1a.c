/* 
 * Scale png
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
while(running){
get_events();

// Update rect


if (flip){ // scale up
	logo_dst.x-=1;
	logo_dst.y-=1;
	logo_dst.h+=2;
	logo_dst.w+=2;
	if (logo_dst.h >= wh/2)
		flip=0;
}
else{	  // scale down
	logo_dst.x+=1;
	logo_dst.y+=1;
	logo_dst.h-=2;
	logo_dst.w-=2;
	if (logo_dst.h <= wh/6)
		flip=1;
}

draw();
}
assets_out();
exit_();
return EXIT_SUCCESS;
}
