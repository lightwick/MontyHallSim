#include <SDL.h>
#include <SDL_image.h>

#ifdef _DEBUG
	#include <iostream>
	#include "debug.h"
#endif

#include "window.h"
#include "event.h"
#include "sprite.h"

bool isRunning = true;
bool isOpen = false;

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	SDL_DisplayMode DM;
	SDL_GetDesktopDisplayMode(0, &DM); // index 0 being main moniter

	window main_window("main window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DM.w, DM.h);
	sprite opened(main_window, "./pic/opened.png", 190, DM.w / 2, DM.h / 2);
	sprite closed(main_window, "./pic/closed.png", 193, DM.w / 2, DM.h / 2);
	sprite car(main_window, "./pic/car.png", 20, DM.w / 2, DM.h / 2);

	printRect(opened);
	printRect(closed);
	// printRect(car);

	while (isRunning)
	{

		main_window.clear(0,100,100,0);

		if (isOpen) opened.apply();
		else closed.apply();

		pollEvent(opened);

		// shows rendered product to window
		SDL_RenderPresent(main_window._renderer);

#ifdef _DEBUG
		// escKey();
		//std::cout << i++ << std::endl;
#endif

	}
	SDL_Quit();

	return EXIT_SUCCESS;
}