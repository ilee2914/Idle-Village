#pragma once
#include <string>
#include <vector>
using namespace std;

struct UpgradeEffect {
	string desc;
	int building;		
	int perkNumber;
	double effectMultiplier;
	double costReduction;
};

struct UpgradeData {
	int upgradeLevel;
	double baseCost;
	double costMult;
	vector<UpgradeEffect> effects;
};

struct Data {
	string name;
	string description;
	string current;
	string total;
	string next;
	int amountOwned;
	double baseGenRate;
	double multiplier;
	double genRate;
	double baseCost;
	double costRate;
	UpgradeData upgradeEffects;
	int code;
};

static class PerkData {
public:
	static vector< vector< Data > > dataset;
	static string postFix[20];

};