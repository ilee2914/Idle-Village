#pragma once

#include <SDL/SDL_ttf.h>
#include "Object.h"
#include "Number.h"

class Currency : public Object {
public:
	Currency(string imageLoc) {
		string temp = "Images/Currencies/" + imageLoc + ".png";
		item = (IMG_Load(temp.c_str()));
		value = Number(0);
	}

	~Currency() {
		delete item;
	}

	int getAmount() {
		return value.getAmount();
	}

	void changeByAmount(double a) {
		value.changeByAmount(a);
	}

	void setAmount(int a) {
		value.setAmount(a);
	}

	void displayNumber(SDL_Window* window, SDL_Surface * screen, TTF_Font * font, int y) {
		screen = SDL_GetWindowSurface(window);
		SDL_Color textColor{ 255, 255, 137 };
		string message = value.shortHand();
		int w, h;
		TTF_SizeText(font, message.c_str(), &w, &h);

		SDL_Surface * temp = TTF_RenderText_Solid(font, message.c_str(), textColor);
		displayRect.h = h;
		displayRect.w = w;
		displayRect.x = 215-w;
		displayRect.y = y;
		SDL_BlitSurface(temp, NULL, screen, &displayRect);

		SDL_FreeSurface(temp);
	}

private:
	Number value;

	SDL_Rect displayRect;
};

