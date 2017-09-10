#include "PerkData.h"


string PerkData::postFix[20] = { "m", "b", "t", "b", "t", "qu", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};


/*
struct UpgradeEffect {
string desc;
int building;
int perkNumber;
double effectMultiplier;
double costReduction;
};

struct UpgradeData {
int upgradeLevel;
vector<UpgradeEffect> effects;
}; */

UpgradeData farmer = { 0, 50, 20,
	vector<UpgradeEffect> {
		UpgradeEffect{ "Increases multiplier by 2", 1, 0, 2, -1 },
		UpgradeEffect{ "Increases multiplier by 3", 1, 0, 3, -1 },
		UpgradeEffect{ "Increases multiplier by .1 for every building owned other than this", 0, 1, -2, -1 }
	}
};

UpgradeData corn = { 0, 500, 20,
	vector<UpgradeEffect> {
		UpgradeEffect{ "Increases multiplier by 2", 1, 1, 2, -1 },
		UpgradeEffect{ "Increases multiplier by 2", 1, 1, 2, -1 },
		UpgradeEffect{ "Increases multiplier by 3", 1, 1, 3, -1 },
		UpgradeEffect{ "Increases multiplier by 3", 1, 1, 3, -1 },
		UpgradeEffect{ "Increases multiplier by 5", 1, 1, 5, -1 },
	}
};

UpgradeData carrot = { 0, 3000, 20, 
	vector<UpgradeEffect> {
		UpgradeEffect{ "Increases multiplier by 2", 1, 2, 2, -1 },
		UpgradeEffect{ "Increases multiplier by 3", 1, 2, 3, -1 },
		UpgradeEffect{ "Increases multiplier by 4", 1, 2, 4, -1 },
		UpgradeEffect{ "Increases multiplier by 5", 1, 2, 5, -1 },
	}
};
UpgradeData equipment = { 0, 20000, 20,
	vector<UpgradeEffect> {
		UpgradeEffect{ "Increases all farm multipliers by 1.5", 1, -1, 1.5, -1 },
		UpgradeEffect{ "Increases all farm multipliers by 1.5", 1, -1, 1.5, -1 },
		UpgradeEffect{ "Increases all farm multipliers by 1.5", 1, -1, 1.5, -1 },
		UpgradeEffect{ "Increases all farm multipliers by 1.5", 1, -1, 1.5, -1 },
		UpgradeEffect{ "Increases all farm multiplieers by 3", 1, -1, 3, -1 }
	}
};

UpgradeData livestock = { 0, 250000, 20,
	vector<UpgradeEffect> {
		UpgradeEffect{ "Increases multiplier by 3", 1, 4, 3, -1 },
	}
};

UpgradeData fertilizer = { 0, 1500000, 20,
	vector<UpgradeEffect> {
		UpgradeEffect{ "Increases multiplier by 3", 1, 5, 3, -1 },
		UpgradeEffect{ "Increases multiplier by 3", 1, 5, 3, -1 },
		UpgradeEffect{ "Increases multiplier by 3", 1, 5, 3, -1 },
		UpgradeEffect{ "Increases multiplier 5", 1, 5, 5, -1 },
	}
};

UpgradeData GMO = { 0, 1500000, 20,
	vector<UpgradeEffect> {
		UpgradeEffect{ "Increases multiplier by 3", 1, 6, 3, -1 },
		UpgradeEffect{ "Increases multiplier by 3", 1, 6, 3, -1 },
		UpgradeEffect{ "Reduces cost of all farm perks by 10%", 1, -1, 3, .9 },
		UpgradeEffect{ "Reduces cost farm multipliers by 5", 1, 6, 5, -1 },
	}
};


/*
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
double costRate;
int code;
};
*/

vector< vector <Data> > PerkData::dataset = {
	// Farm Data
	{
		Data{ "farmer", "Increases food per click", "Current FPC: ", ".", "Next level FPC: ", 0, 1, 1, 1, 5, 1.47, farmer, 0 },	//special
		Data{ "corn", "Increases food per secondd", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, 1, 1, 0, 25, 1.17, corn, 1 },
		Data{ "carrot", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, 5, 1, 0, 300, 1.27, carrot, 1 },
		Data{ "equipment", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, 40, 1, 0, 2500, 1.4, equipment, 1 },
		Data{ "livestock", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, 500, 1, 0, 30000, 1.55, equipment, 1 },
		Data{ "fertilizer", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, 2500, 1, 0, 500000, 1.69, fertilizer, 1 },
		Data{ "GMO", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, 10000, 1, 0, 2000000, 1.81, GMO, 1 },
	},
	{
		Data{ "trade", "Poop on my face", "Current FPS per level: ", "Total corn GPS: ", "Next level GPS: ", 0, .2, 1, .2, 1.21, 1, 1 },
		Data{ "cart", "Poop on my face", "Current FPS per level: ", "Total corn GPS: ", "Next level GPS: ", 0, .2, 1, .2, 1.21, 1, 1 },
		Data{ "caravan", "Poop on my face", "Current FPS per level: ", "Total corn GPS: ", "Next level GPS: ", 0, .2, 1, .2, 1.21, 1, 1 },
		Data{ "boat", "Poop on my face", "Current FPS per level: ", "Total corn GPS: ", "Next level GPS: ", 0, .2, 1, .2, 1.21, 1, 1 },
		Data{ "bank", "Poop on my face", "Current FPS per level: ", "Total corn GPS: ", "Next level GPS: ", 0, .2, 1, .2, 1.21, 1, 1 },
	},
	{
		Data{ "sword", "", "","","", 0, 1, 1, 1, 1, 1 },
		Data{ "bow", "", "","","", 0, 1, 1, 1, 1, 1 },
		Data{ "shield", "", "","","", 0, 1, 1, 1, 1, 1 },
		Data{ "boots", "", "","","", 0, 1, 1, 1, 1, 1 },
		Data{ "backpack", "", "","","", 0, 1, 1, 1, 1, 1 },
		Data{ "tech", "", "","","", 0, 1, 1, 1, 1, 1 }, //special
	},
};