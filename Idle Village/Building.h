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

	Building(string imageLoc, int xPos, int yPos, int bN) {
		string temp = "Images/Buildings/" + imageLoc + ".png";
		item = (IMG_Load(temp.c_str()));
		name = imageLoc;
		x = xPos;
		y = yPos;
		h = item->h;
		w = item->w;
		endX = x + w;
		endY = y + h;
		buildingNum = bN;
	}

	vector<Perk*> getItems() {
		return items;
	}

	void addPerk(Perk * x) {
		x->loadData(buildingNum, perkCount, currX, currY);
		items.push_back(x);
		if (index % 3 != 0) {
			currX += 103;
		}
		else {
			currX -= 206;
			currY += 105;
		}
		perkCount++;
		index++;
	}

private:
	vector<Perk*> items;
	int buildingNum;
	int perkCount = 0;
	int currX = 345;
	int currY = 195;
	int index = 1;
	
};