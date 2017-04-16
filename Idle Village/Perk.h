#pragma once
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include <string>
#include "Buyable.h"
#include "PerkData.h"

using namespace std;

class Perk : public Buyable {
public:
	Perk() = default;
	~Perk() = default;

	Perk(string i1, string i2, string i3) {
		images[0] = IMG_Load(i1.c_str());
		images[1] = IMG_Load(i2.c_str());
		images[2] = IMG_Load(i3.c_str());
		item = images[0];
	}

	void loadData(int& buildingNum, int& perkNum, int& xStart, int& yStart) {
		Data hold = PerkData::dataset[buildingNum][perkNum];
		baseRate = hold.baseRate;
		amountOwned = hold.amountOwned;
		multiplier = hold.multiplier;
		trueCost = hold.trueCost;
		costRate = hold.costRate;
		name = hold.name;
		description = hold.description;
		cost = (int)trueCost;
		x = xStart;
		y = yStart;
		endX = x + 80;
		endY = y + 80;
	}

	void buy(int a) {
		amountOwned += a;
		for (int i = 0; i < a; i++) {
			trueCost *= (1 + costRate);
		}
		cost = (int)trueCost;
		updateGenRate();
	}


	void registerClick(Currency& c) {
		if (c.getAmount() >= cost) {
			c.changeByAmount(-cost);
			buy(1);
		}

	}
	double getGenRate() {
		return genRate;
	}

protected:
	SDL_Surface * images[3];
	double baseRate;
	double multiplier;
	double genRate;
	double costRate;
	double trueCost;

	void addMultiplier(int m) {
		multiplier += m;
		updateGenRate();
	}
	void updateGenRate() {
		genRate = (baseRate * amountOwned) * multiplier;
	}

};

