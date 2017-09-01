#pragma once
#include "Clickable.h"
#include "Perk.h"

class Building : public Clickable {
public:
	Building() {
		x = 0;
		y = 0;
	}

	~Building() {
		delete item;
	}

	Building(string imageLoc, int xPos, int yPos, int bN) : Clickable("Images/Buildings/" + imageLoc + ".png", xPos, yPos){
		name = imageLoc;
		buildingNum = bN;
	}

	vector<Perk*> getItems() {
		return items;
	}

	void addPerk(Perk * x) {
		x->loadData(buildingNum, perkCount, currX, currY);
		items.push_back(x);
		if (index % 3 != 0) {
			currX += 109;
		}
		else {
			currX -= 218;
			currY += 107;
		}
		perkCount++;
		index++;
	}

private:
	vector<Perk*> items;
	int buildingNum;
	int perkCount = 0;
	int currX = 339;
	int currY = 170;
	int index = 1;
	
};