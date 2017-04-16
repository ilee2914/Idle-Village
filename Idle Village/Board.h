#pragma once
#include "Object.h"
#include "Building.h"
#include "Perk.h"
#include <SDL/SDL_ttf.h>

class Board : public Object {
public:
	Board();
	~Board();

	void display(SDL_Window*, SDL_Surface*, Building*, int&, int&, int&);
	bool handleClick(SDL_Rect&, int&, int&);
private:
	void write(TTF_Font * font, string message, int x, int y, SDL_Window* window, SDL_Surface * screen);

	SDL_Surface * message;
	SDL_Surface * xButton, *xActive, *buyButton, *buyActive, *buyUnable;

	int xX, xY, xH, xW, endxX, endxY;
	int buyX, buyY, buyH, buyW, endBuyX, endBuyY;

	SDL_Rect rects[3];
	SDL_Rect selectedRect{ 668, 193, 80, 80 };

	Perk * selected;
	
};

