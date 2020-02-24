#include "sprite.h"
#include <cstdlib>
#include <iostream>

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

void sprite::spriteEvent(SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_RIGHT:
		_rect.x += 10;
		break;
	case SDLK_LEFT:
		_rect.x -= 10;
		break;
	case SDLK_UP:
		_rect.y -= 10;
		break;
	case SDLK_DOWN:
		_rect.y += 10;
		break;
	}
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