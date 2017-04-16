#pragma once
#include <string>
#include <vector>
using namespace std;

struct Data {
	string name;
	string description;
	int amountOwned;
	double baseRate;
	double multiplier;
	double genRate;
	double costRate;
	double trueCost;
};

static class PerkData {
public:
	static vector< vector< Data > > dataset;
};