#pragma once
#include "Object.h"
#include <SDL/SDL_ttf.h>
class Board : public Object {
public:
	Board();
	~Board();

	void display(SDL_Window* window,  TTF_Font* gFont);
private:
	void write(TTF_Font * font, string message, int x, int y, SDL_Window* window, SDL_Surface * screen);

	SDL_Surface * message;
	
};

