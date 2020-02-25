#include <SDL_events.h>
#define CHANGING_VALUE 5
#ifdef _DEBUG
#include <iostream>
#endif

#include "sprite.h"

extern bool isRunning;
extern bool isOpen;

SDL_Event event;

void keyEvent(sprite& a)
{
	a.spriteEvent(event);
	switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
		isRunning = false;
		break;
	case SDLK_UP:
		a.size += CHANGING_VALUE;
		break;
	case SDLK_DOWN:
		a.size -= CHANGING_VALUE;
		break;
	case SDLK_SPACE:
		isOpen = !isOpen;
		break;
	}
	a.resize();
	std::cout << a.size << std::endl;
}

void pollEvent(sprite& a)
{
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			keyEvent(a);
			break;
		case SDL_QUIT:
			isRunning = false;
			std::cout << "requested exit";
			break;
		}
	}
}