#pragma once
#include "sprite.h"

class door : public sprite
{
public:
	door(const window& window, int x, int y);
	void init();
	void draw();
private:
	int _x, _y;
	bool isOpen = false;
	static SDL_Texture* _open;
	static SDL_Texture* _closed;
};