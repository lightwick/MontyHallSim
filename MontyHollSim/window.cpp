#include "window.h"
#include <iostream>

window::window(std::string title, int x, int y, int w, int h) :
	_x(x), _y(y), _w(w), _h(h)
{
	_window = SDL_CreateWindow(title.c_str(), _x, _y, _w, _h, SDL_WINDOW_VULKAN|SDL_WINDOW_BORDERLESS);
	SDL_SetWindowIcon(_window, icon);

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (_window == nullptr) std::cerr << "Error creating following window: " << title <<std::endl;
}

window::~window()
{
	SDL_DestroyWindow(_window);
}

void window::clear(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(_renderer, r, g, b, a);
	SDL_RenderClear(_renderer);
}