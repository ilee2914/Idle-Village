#pragma once
#include <string>
#include "PerkData.h"
using namespace std;
class Number {
public:
	Number() {
		trueAmount = 0;
	}

	Number(double val) {
		trueAmount = val;
	}

	int getAmount() {
		displayAmount = (int)trueAmount;
		return displayAmount;
	}
	double getTrueAmount() {
		return trueAmount;
	}

	void changeByAmount(double a) {
		trueAmount += a;
	}

	void setAmount(double a) {
		trueAmount = a;
	}

	string shortHand() {
		string val = read();
		string test;
		int pointIndex = val.find(".");
		int num = 0;
		if (pointIndex <= 6) {
			test = val.substr(0, pointIndex);
		}
		else {
			num =  (pointIndex + 2) % 3 + 1;
			string p = PerkData::postFix[(pointIndex-7)/3];
			test = val.substr(0, num) + "." + val.substr(num, 3)+p;
		}

		return test;
		
	}

	string read() {
		return to_string(trueAmount);
	}
private:
	double trueAmount;
	int displayAmount;
};