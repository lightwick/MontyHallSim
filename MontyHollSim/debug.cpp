#include <SDL.h>
#include "sprite.h"
#include <iostream>

extern bool isRunning;

void escKey()
{
	SDL_Event _event;
	if (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
		case SDL_QUIT:
		case SDL_KEYDOWN:
			isRunning = false;
			break;
		}
	}
}

void printRect(sprite& a)
{
	SDL_Rect _rect = a.getRect();
	std::cout << "width: " << _rect.w << " height: " << _rect.h << std::endl;
}