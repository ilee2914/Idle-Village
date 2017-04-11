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

	Building(string imageLoc, int xPos, int yPos) {
		string temp = "Images/Buildings/" + imageLoc + ".png";
		item = (IMG_Load(temp.c_str()));
		name = imageLoc;
		x = xPos;
		y = yPos;
		h = item->h;
		w = item->w;
		endX = x + w;
		endY = y + h;
	}

	vector<Perk*> getItems() {
		return items;
	}

	void addPerk(Perk * x) {
		items.push_back(x);
	}

private:
	vector<Perk*> items;
};