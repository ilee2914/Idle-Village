#pragma once
#include "Clickable.h"

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
	}

	void registerClick(Currency& l, vector<Clickable*> signs) {
		l.changeByAmount(1);
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