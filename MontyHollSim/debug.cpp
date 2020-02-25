#include <SDL.h>

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