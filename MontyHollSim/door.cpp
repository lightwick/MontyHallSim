#include "door.h"

door::door(const window& window, int x, int y) :
	_x(x), _y(y)
{
	_window = window;
	setRect(x, y);
}

void door::init()
{
	SDL_Surface* open = IMG_Load("./pic/opened.png");
	SDL_Surface* close = IMG_Load("./pic/closed.png");
	
	_open = SDL_CreateTextureFromSurface(_window._renderer, open);
	_closed = SDL_CreateTextureFromSurface(_window._renderer, close);

	SDL_FreeSurface(open);
	SDL_FreeSurface(close);
}

void door::draw()
{

}