/* This is a series of examples about the
 * SDL2 Renderer infrastructure.
 * 
 * render smooth sinewave
 * 
 * https://www.shadertoy.com/view/4sf3RN
 * https://www.iquilezles.org/www/articles/distance/distance.htm
 */

#include <math.h>
#include "helper.h"

#define WW 256 * 2
#define WH 256 * 2

struct _vec2
{
	double x;
	double y;
};

struct _vec3
{
	double x;
	double y;
	double z;
};

struct _vec4
{
	double x;
	double y;
	double z;
	double a;
};

struct rgba
{
	double rn;
	int r;
	double gn;
	int g;
	double bn;
	int b;
	double an;
	int a;
};

// https://wiki.libsdl.org/SDL_Color

SDL_Point iResolution = {WW, WH};
int ww = WW;
int wh = WH;
double GetCurve(double);
double GetCurveDeriv(double);
double clamp(double x, double min, double max);

double norm_RGB(double);
double rescale_RGB(double);

double norm_NDC_x(double);
double norm_NDC_y(double);

double rescale_NDC_x(double);
double rescale_NDC_y(double);

struct _vec2 *vec2(double, double);
struct _vec3 *vec3(double, double, double);
struct _vec4 *vec4(double, double, double, double);

void setColor(struct _vec4 *);
void mix(struct _vec3 *, struct _vec4 *, float);

int main(int argc, char *argv[])
{

	(void)argc;
	(void)argv;

	init();
	SDL_SetWindowPosition(Window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	SDL_SetWindowSize(Window, iResolution.x, iResolution.y);
	SDL_SetWindowTitle(Window, "6a - RenderDrawPoint 2");
	SDL_ShowWindow(Window);
	struct _vec4 *color = vec4(0.0, 0.0, 0.0, 1.0);
	setColor(color);
	struct _vec3 *mix_color = vec3(1.0, 0.0, 0.0);
	SDL_Event event;
	int running = 1;

	while (running)
	{
		color->x = 0.0;
		color->y = 0.0;
		color->z = 0.0;
		setColor(color);
		SDL_RenderClear(Renderer);

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

		for (int x = 0; x < iResolution.x; x++)
		{
			for (int y = 0; y < iResolution.y; y++)
			{
				if (fabs(y - iResolution.y * 0.5) < 1.0)
				{
					// Draw Horizontal Line
					color->x = 0.25;
					color->y = 0.25;
					color->z = 0.25;
					setColor(color);
					SDL_RenderDrawPoint(Renderer, x, y);
				}
				double curveX = x / (double)iResolution.x;
				double sinY = (GetCurve(curveX) * 0.25 + 0.5) * (double)iResolution.y;
				double sinYdeltaX = (GetCurveDeriv(curveX) * 0.25) * (double)iResolution.y / (double)iResolution.x;
				double distanceToCurve = fabs(sinY - y) / sqrt(1.0 + sinYdeltaX * sinYdeltaX);
				double setPixel = distanceToCurve - 1.0; // thickness
				mix(mix_color, color, clamp(setPixel, 0.0, 1.0));
				setColor(color);
				SDL_RenderDrawPoint(Renderer, x, y);
				color->x = 0.0;
				color->y = 0.0;
				color->z = 0.0;
				setColor(color);
			}
		}
		SDL_RenderPresent(Renderer);
	}

	exit_();
	return EXIT_SUCCESS;
}

double GetCurve(double x)
{
	return sin(x * 3.14159 * 4.0);
}

double GetCurveDeriv(double x)
{
	return 3.14159 * 4.0 * cos(x * 3.14159 * 4.0);
}

double clamp(double x, double min, double max)
{

	if (x < min)
		x = min;
	else if (x > max)
		x = max;

	return x;
}

double norm_RGB(double x)
{
	return (x - 0) / (255 - 0);
}
double rescale_RGB(double xr)
{
	return xr * 255;
}
double norm_NDC_x(double x)
{
	return (2 * (x - 0) / (ww - 0)) - 1;
}
double norm_NDC_y(double y)
{
	return (2 * (y - 0) / (wh - 0)) - 1;
}

double rescale_NDC_x(double xr)
{
	return ww * (xr - -1) / 2;
}
double rescale_NDC_y(double xr)
{
	return wh * (xr - -1) / 2;
}

/*
The lerp (mix so called in GLSL) function returns the linear blend of x and y, i.e. the product of x and (1 - a) plus the product of y and a. The input parameters can be floating scalars or float vectors. In case of float vectors the operation is done component-wise.

http://developer.download.nvidia.com/cg/lerp.html
https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/mix.xhtml
 x×(1−a)+y×ax×(1−a)+y×a.
*/
void mix(struct _vec3 *a, struct _vec4 *b, float w)
{
	// lerp
	// - returns linear interpolation of two scalars or vectors based on a weight
	// float  lerp(float a, float b, float w);
	// a- Vector or scalar to weight; returned when w is zero.
	// b-Vector or scalar to weight; returned when w is one.
	// w-Vector or scalar weight.
	// 	return a + w * (b - a);
	//x×(1−w)+b×wa×(1−w)+b×w.

	// b->x = a->x * (1.0 - w) + b->x * w * a->x * (1.0 - w) + b->x * w;
	b->x = a->x + w * (b->x - a->x);
	// SDL_Log("r:%f",b->x);

	// b->y = a->y * (1.0 - w) + b->y * w * a->y * (1.0 - w) + b->y * w;
	b->y = a->y + w * (b->y - a->y);
	// SDL_Log("g:%f",b->y);

	// b->z = a->z * (1.0 - w) + b->z * w * a->z * (1.0 - w) + b->z * w;
	b->z = a->z + w * (b->z - a->z);
	// SDL_Log("b:%f",b->z);

	b->a = 1.0;
}

struct _vec2 *vec2(double x, double y)
{
	struct _vec2 *vec2;
	vec2 = calloc(1, sizeof(struct _vec2));
	vec2->x = x;
	vec2->y = y;
	return vec2;
}

struct _vec3 *vec3(double x, double y, double z)
{
	struct _vec3 *vec3;
	vec3 = calloc(1, sizeof(struct _vec3));
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
	return vec3;
}

struct _vec4 *vec4(double x, double y, double z, double a)
{
	struct _vec4 *vec4;
	vec4 = calloc(1, sizeof(struct _vec4));
	vec4->x = x;
	vec4->y = y;
	vec4->z = z;
	vec4->a = a;
	return vec4;
}

void setColor(struct _vec4 *color)
{
	int r = round(rescale_RGB(color->x));
	int g = round(rescale_RGB(color->y));
	int b = round(rescale_RGB(color->z));
	int a = round(rescale_RGB(color->a));
	SDL_SetRenderDrawColor(Renderer, r, g, b, a);
}