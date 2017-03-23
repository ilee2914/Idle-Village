#pragma once
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "Clickable.h"

class Buyable : public Clickable {
public:
	Buyable() = default;
	~Buyable() { SDL_FreeSurface(item); }

	virtual void buy(int a) = 0;
	int getPrice() { return price; }

	string getName() { return name; }
	string getDescription() { return description; }
	int getAmountOwned() { return amountOwned; }

protected:
	int price;

	string name;
	string description;
	int amountOwned;
	int x, y, width, height;
};