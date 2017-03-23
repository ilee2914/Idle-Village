#pragma once
#pragma once

#include "Object.h"

class Currency : public Object {
public:
	Currency(string imageLoc) {
		string temp = "Images/Currencies/" + imageLoc + ".png";
		item = (IMG_Load(temp.c_str()));
	}

	~Currency() {
		delete item;
	}

	int getAmount() {
		displayAmount = (int)trueAmount;
		return displayAmount;
	}

	void changeByAmount(double a) {
		trueAmount += a;
	}

	void setAmount(int a) {
		trueAmount = a;
	}

private:
	double trueAmount;
	int displayAmount;
};

