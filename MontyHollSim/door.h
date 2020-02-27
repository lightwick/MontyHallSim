#pragma once
#include "sprite.h"

class door : public sprite
{
public:
	door(const window& window, int x, int y);
	init();
private:
	int _x, _y;
	bool isOpen = false;
	static SDL_Texture* open;
	static SDL_Texture* closed;
};