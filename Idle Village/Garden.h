#pragma once
#include "Clickable.h"
#include "PerkEffects.h"

class Garden : public Clickable {
public:
	Garden() {
		x = 0;
		y = 0;
	}

	~Garden() {
		delete item;
	}

	Garden(int xPos, int yPos) {
		string temp = "Images/Buildings/garden.png";
		item = (IMG_Load(temp.c_str()));
		x = xPos;
		y = yPos;
		h = item->h;
		w = item->w;
		endX = x + w;
		endY = y + h;
	}

	void registerClick(Currency& l) {
		l.changeByAmount(PerkEffects::getClickValue().getAmount());
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