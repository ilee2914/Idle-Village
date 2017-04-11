#pragma once
#include "Object.h"
#include "Building.h"
#include <SDL/SDL_ttf.h>

class Board : public Object {
public:
	Board();
	~Board();

	void display(SDL_Window*, SDL_Surface*, Building*, TTF_Font*);
private:
	void write(TTF_Font * font, string message, int x, int y, SDL_Window* window, SDL_Surface * screen);

	SDL_Surface * message;
	SDL_Surface * xButton, *xActive, *buyButton, *buyActive;

	int xX, xY, xH, xW;
	int buyX, buyY, buyH, buyW;
	
};

