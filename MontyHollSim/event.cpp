#include <SDL_events.h>

#ifdef _DEBUG
#include <iostream>
#endif

#include "sprite.h"

extern bool isRunning;

SDL_Event event;

void keyEvent() // sprite& a)
{
	// a.spriteEvent(event);
	switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
		isRunning = false;
		break;
	case SDLK_UP:
		
	}
}

void windowEvent()
{
	switch (event.window.event)
	{
	case SDL_WINDOWEVENT_CLOSE:
		SDL_Window* temp = SDL_GetWindowFromID(event.window.windowID);
		SDL_DestroyWindow(temp);
		break;
	}
}

void pollEvent(sprite& a)
{
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT:
			windowEvent();
			break;
		case SDL_KEYDOWN:
			keyEvent();
			break;
		case SDL_QUIT:
			isRunning = false;
			std::cout << "requested exit";
			break;
		}
	}
}