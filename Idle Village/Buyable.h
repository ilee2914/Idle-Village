#pragma once
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "Clickable.h"

class Buyable : public Clickable {
public:
	Buyable() = default;
	~Buyable() { SDL_FreeSurface(item); }

	virtual bool buy(int a, Currency& curr) = 0;
	int getCost() { return cost; }

	string getName() { return name; }
	string getDesc() { return description; }
	int getAmountOwned() { return amountOwned; }

protected:
	int cost;

	string name;
	string description;
	int amountOwned;
};