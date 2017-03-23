#pragma once

#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>

using namespace std;

class Object {
public :

	Object() {
		x = 0;
		y = 0;
	}

	Object(string imageLoc,int xPos, int yPos) {
		item = (IMG_Load(imageLoc.c_str()));
		x = xPos;
		y = yPos;
		h = item->h;
		w = item->w;
		endX = x + w;
		endY = y + h;
	}

	SDL_Surface * getItem() { return item; }
	int getXPos() { return x; }
	int getYPos() { return y; }
	int getHeight() { return h; }
	int getWidth() { return w; }

	void changeXPos(int p) { x = p; }
	void changeYPos(int p) { y = p; }
	void changeHeight(int p) { h = p; }
	void changeWidth(int p) { w = p; }


	virtual void display(SDL_Window* window, SDL_Surface* screen) {
		display(window, screen, x, y);
	}

	virtual void display(SDL_Window* window, SDL_Surface* screen, int xC, int yC) {
		screen = SDL_GetWindowSurface(window);
		SDL_Rect itemRect;

		itemRect.h = h;
		itemRect.w = w;
		itemRect.x = xC;
		itemRect.y = yC;

		SDL_BlitSurface(item, NULL, screen, &itemRect);
	}
protected :
	SDL_Surface * item;
	int x, y;
	int endX, endY;
	int h = 0;
	int w = 0;
};