#pragma once
#include <string>
#include <vector>
using namespace std;

struct Data {
	string name;
	string description;
	string current;
	string total;
	string next;
	int amountOwned;
	double baseRate;
	double multiplier;
	double genRate;
	double baseCost;
	double trueCost;
	int code;
};

static class PerkData {
public:
	static vector< vector< Data > > dataset;
	static string postFix[20];

};