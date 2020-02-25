#include "sprite.h"
#include <cstdlib>
#include <iostream>
#ifdef _DEBUG
#define MOVEMENT 1;
#endif
// surface -> texture -> renderer -> window
// x and y position of middle of the image
sprite::sprite(const window &window, std::string img_path, float percentage, int x, int y):
	_window(window), size(percentage)
{
	SDL_Surface* surface = IMG_Load(img_path.c_str());
	_basePic.w = surface->w;
	_basePic.h = surface->h;
	_rect.w = surface->w * percentage / 100;
	_rect.h = surface->h * percentage / 100;
	_rect.x = x-_rect.w/2;
	_rect.y = y-_rect.h/2;
	_texture = SDL_CreateTextureFromSurface(window._renderer, surface);
	SDL_FreeSurface(surface);
}

void sprite::apply() const
{
	SDL_RenderCopy(_window._renderer, _texture, NULL, &_rect);
}

void sprite::resize()
{
	_rect.w = _basePic.w * size / 100;
	_rect.h = _basePic.h * size / 100;
}

int x_ch=0, y_ch = 0;

void sprite::spriteEvent(SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_d:
		_rect.x += MOVEMENT;
		x_ch++;
		break;
	case SDLK_a:
		_rect.x -= MOVEMENT;
		x_ch--;
		break;
	case SDLK_w:
		_rect.y -= MOVEMENT;
		y_ch--;
		break;
	case SDLK_s:
		_rect.y += MOVEMENT;
		y_ch++;
		break;
	}
	std::cout << "x value change: " << x_ch << " y value change: " << y_ch << std::endl;
}

void animation(window window, float fps, int n ,...)
{
	va_list vl;
	va_start(vl, n);
	SDL_Surface** image = new SDL_Surface *[n];
	for (int i = 0; i < n; i++)
	{
		image[i] = IMG_Load(va_arg(vl, std::string).c_str());
		SDL_Texture* texture = SDL_CreateTextureFromSurface(window._renderer, image[i]);
		SDL_FreeSurface(image[i]);
	}
	va_end(vl);
}