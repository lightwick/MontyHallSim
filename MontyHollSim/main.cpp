#include <SDL.h>
#include <SDL_image.h>

#ifdef _DEBUG
	#include <iostream>
	#include "debug.h"
	#define UNDEFINED 100
#endif

#include "window.h"
#include "event.h"
#include "sprite.h"
#include "door.h"

bool isRunning = true;

void Init_Door(window _window)
{
	SDL_Surface* open = IMG_Load("./pic/opened.png");
	SDL_Surface* closed = IMG_Load("./pic/closed.png");
	SDL_Texture* door::open = SDL_CreateTextureFromSurface(_window._renderer, surface);
}

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	SDL_DisplayMode DM;
	SDL_GetDesktopDisplayMode(0, &DM); // index 0 being main moniter

	window main_window("main window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DM.w, DM.h);
	Init_Door();

	sprite opened(main_window, "./pic/opened.png", 192, DM.w / 2 - 1, DM.h / 2 + 13);
	sprite closed(main_window, "./pic/closed.png", 190, DM.w / 2, DM.h / 2);
	sprite car(main_window, "./pic/car.png", 20, DM.w / 2, DM.h / 2);

	while (isRunning)
	{
		main_window.clear(0,100,100,0);

		closed.setRect(DM.w/2,DM.h/2);
		closed.apply();
		closed.setRect(DM.w / 4, DM.h / 2);
		closed.apply();

		// shows rendered product to window
		SDL_RenderPresent(main_window._renderer);

#ifdef _DEBUG
		escKey();
		static int i = 0;
		std::cout << i++ << std::endl;
#endif

	}
	SDL_Quit();

	return EXIT_SUCCESS;
}

#ifdef _DEBUG
void escKey()
{
	SDL_Event _event;
	if (SDL_PollEvent(&_event))
	{
		switch (_event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		}
	}
}
#endif