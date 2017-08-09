#pragma once
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include <string>
#include "Buyable.h"
#include "PerkData.h"
#include "PerkEffects.h"

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
		
		genRate = Number(baseRate);
		name = hold.name;
		description = hold.description;
		current = hold.current;
		total = hold.total;
		next = hold.next;
		
		trueCost = hold.trueCost;
		baseCost = hold.baseCost;
		cost = (int)trueCost.getAmount();

		code = hold.code;
		x = xStart;
		y = yStart;
		endX = x + 80;
		endY = y + 80;
	}

	string getName() { return name; }
	string getCurrentDesc() { return current; }
	string getTotalDesc() { return total; }
	string getNextDesc() { return next; }

	/*
	 * Price formula : m^(ax) + b
	 * m - multiplier
	 * a - rate
	 * x - amount owned
	 * b - base cost
	 */

	/*
	 * Cost formula : bx^(a)m^(cx)
	 * b - base gen
	 * x - amount owned
	 * a - rate
	 * m - multiplier
	 * c - arbitrary number
	 */
	bool buy(int a, Currency& curr) {
		
		int amount = curr.getAmount();
		if (amount < cost) {
			return false;
		}
		amountOwned += a;
		curr.changeByAmount(-cost);
		updateCost();
		updateGenRate();
		return true;
	}

	bool canBuy(Currency& curr) {
		return curr.getAmount() >= cost;
	}


	void registerClick(Currency& c) {

	}

	string getGenRate() {
		return genRate.shortHand();
	}
	
	string getNextGenRate() {
		double temp = (baseRate * multiplier);
		return to_string((int)(temp + genRate.getTrueAmount()));
	}



protected:
	SDL_Surface * images[3];
	double baseRate;		//base generation
	double multiplier;
	Number genRate;			//Number
	Number baseCost;		//Number
	Number trueCost;		//base cost
	string current;
	string total;
	string next;
	int code;

	void addMultiplier(int m) {
		multiplier += m;
		updateGenRate();
	}
	void updateGenRate() {
		double temp = (baseRate * multiplier);
		genRate.changeByAmount(temp);
		cout << genRate.getTrueAmount();
		PerkEffects::updateValues(temp, code);
	}
	void updateCost() {
		trueCost.setAmount(baseCost.getAmount() * pow(1.25, amountOwned));
		cost = (int)trueCost.getAmount();
	}

};

