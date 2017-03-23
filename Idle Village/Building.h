#pragma once
#include "Clickable.h"

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
		x = xPos;
		y = yPos;
		h = item->h;
		w = item->w;
		endX = x + w;
		endY = y + h;
	}
	
	void registerClick(Currency& l, array<bool, 5> actives, int id) {
		cout << "fuck";
		bool set = false;

		if (!set)
			active = true;
	}

	bool isActive() {
		return active;
	}

	vector<Clickable*> * getItems() {
		return items;
	}

private:
	bool active = false;
	vector<Clickable*> *items;
};