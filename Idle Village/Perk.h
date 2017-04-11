#pragma once
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include <string>
#include "Buyable.h"

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
		/*baseRate = bR;
		amountOwned = aO;
		multiplier = m;
		price = p;
		truePrice = price;
		priceRate = pR;
		name = n;
		description = d;*/
	}

	void buy(int a) {
		amountOwned += a;
		for (int i = 0; i < a; i++) {
			truePrice *= (1 + priceRate);
		}
		price = (int)truePrice;
		updateGenRate();
	}


	void registerClick(Currency& c) {
		if (c.getAmount() >= price) {
			c.changeByAmount(-price);
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
	double priceRate;
	double truePrice;

	void addMultiplier(int m) {
		multiplier += m;
		updateGenRate();
	}
	void updateGenRate() {
		genRate = (baseRate * amountOwned) * multiplier;
	}

};

