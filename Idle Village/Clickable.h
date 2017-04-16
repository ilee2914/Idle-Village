#pragma once
#include "Object.h"
#include "Currency.h"
#include <vector>

class Clickable : public Object {
public:
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

