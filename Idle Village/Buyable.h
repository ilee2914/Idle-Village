#pragma once
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "Clickable.h"

class Buyable : public Clickable {
public:
	Buyable() = default;
	~Buyable() { SDL_FreeSurface(item); }

	virtual void buy(int a) = 0;
	int getCost() { return cost; }

	string getName() { return name; }
	string getDescription() { return description; }
	int getAmountOwned() { return amountOwned; }

protected:
	int cost;

	string name;
	string description;
	int amountOwned;
};