#pragma once
#include <string>
#include <SDL.h>

class window
{
public:
	window(std::string title, int x, int y, int w, int h);
	~window();
	void clear(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	SDL_Renderer* _renderer;
	SDL_Window *getWindow() { return _window; }
private:
	SDL_Window* _window;
	int _w, _h, _x, _y;
};