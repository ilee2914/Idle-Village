#pragma once
#include "Object.h"
#include "Building.h"
#include "Perk.h"
#include <SDL/SDL_ttf.h>

class Board : public Object {
public:
	Board();
	~Board();

	void display(SDL_Window*, SDL_Surface*, Building*, int&, TTF_Font *, int&, int&, Currency&);
	bool handleClick(SDL_Rect&, int&, int&);
private:
	void write(string message, int xLeft, int xRight, int y, TTF_Font* gFont, SDL_Window* window, SDL_Surface * screen);
	void write(string message, int x, int y, TTF_Font*, SDL_Window* window, SDL_Surface * screen);

	SDL_Surface * message;
	SDL_Surface * xButton, *xActive, *buyButton, *buyActive, *buyUnable;

	int xX, xY, xH, xW, endxX, endxY;
	int buyX, buyY, buyH, buyW, endBuyX, endBuyY;

	SDL_Rect rects[3];
	SDL_Rect selectedRect{ 672, 170, 80, 80 };
	SDL_Rect nameRect{ 100, 100, 100, 100 };

	Perk * selected;
	
};

