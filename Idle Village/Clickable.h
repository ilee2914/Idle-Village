#pragma once
#include "Object.h"
#include "Currency.h"
#include <vector>

class Clickable : public Object {
public:
	Clickable() {}
	Clickable(string imageLoc, int xPos, int yPos) : Object(imageLoc, xPos, yPos){}

	virtual void registerClick(Currency&) {
		return;
	}
	virtual void registerClick(Currency&, int, int) {
		return;
	}

	bool checkClick(int xC, int yC) {
		return (xC >= x && xC <= endX && yC >= y && yC <= endY);
	}
	
};

