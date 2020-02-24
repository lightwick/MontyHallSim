#include <SDL.h>
#include <SDL_image.h>

#ifdef _DEBUG
	#include <iostream>
	#include "debug.h"
#endif

#include "window.h"
#include "event.h"
#include "sprite.h"
#include "WindowsOS.h"

bool isRunning = true;

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	SDL_DisplayMode DM;
	SDL_GetDesktopDisplayMode(0, &DM); // index 0 being main moniter

	window main_window("main window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DM.w, DM.h);
	sprite opened(main_window, "./pic/opened.png", 190, DM.w / 2, DM.h / 2);
	sprite closed(main_window, "./pic/closed.png", 190, DM.w / 2, DM.h / 2);
	sprite car(main_window, "./pic/car.png", 190, DM.w / 2, DM.h / 2);
	while (isRunning)
	{
		main_window.clear(0,100,100,0);

		car.apply();
		opened.apply();

		pollEvent(car);

		// shows rendered product to window
		SDL_RenderPresent(main_window._renderer);

#ifdef _DEBUG
		// escKey();
		static int i = 0;
		//std::cout << i++ << std::endl;
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
		switch (_event.type)
		{
		case SDL_QUIT:
		case SDL_KEYDOWN:
			isRunning = false;
			break;
		}
	}
}
#endif