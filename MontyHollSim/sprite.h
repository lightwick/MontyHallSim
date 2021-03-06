#pragma once
#include <string>
#include <cstdarg>
#include <SDL_image.h>
#include <SDL.h>

#include "window.h"

class sprite
{
public:
	sprite();
	sprite(const window &window, std::string img_path, float percentage, int x, int y);
	// applies sprite to renderer
	void apply() const;
	void setRect(int x, int y);
	void spriteEvent(SDL_Event event);
	SDL_Rect getRect() { return _rect; }
private:
	SDL_Texture* _texture;
protected:
	window _window;
	SDL_Rect _rect;
};

/*
* summary: variadic function same time period apart
* note : fps not implemented yet
*/
void animation(window _window, float fps, int n, ...);
