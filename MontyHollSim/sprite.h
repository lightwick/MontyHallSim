#pragma once
#include <string>
#include <cstdarg>
#include <SDL_image.h>
#include <SDL.h>

#include "window.h"

class sprite
{
public:
	sprite(const window &window, std::string img_path, float percentage, int x, int y);
	// applies sprite to renderer
	void apply() const;
	void draw(int x, int y) const;
	void resize();
	void spriteEvent(SDL_Event event);
	SDL_Rect getRect() { return _rect; }

	float size;
private:
	SDL_Texture* _texture;
	window _window;
	SDL_Rect _rect;
	SDL_Rect _basePic;
};

/*
* summary: variadic function same time period apart
* note : far from finished
*/
void animation(window _window, float fps, int n, ...);
