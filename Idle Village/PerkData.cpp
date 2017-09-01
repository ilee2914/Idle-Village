#include "PerkData.h"


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

string PerkData::postFix[20] = { "m", "b", "t", "b", "t", "qu", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

vector< vector <Data> > PerkData::dataset = {
	// Farm Data
	{
		Data{ "farmer", "Increases food per click", "Current FPC: ", ".", "Next level FPC: ", 0, 1, 1, 1, 5, 1.47, 0 },	//special
		Data{ "corn", "Increases food per secondd", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, 1, 1, 0, 25, 1.17, 1 },
		Data{ "carrot", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, 5, 1, 0, 300, 1.27, 1 },
		Data{ "equipment", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, 40, 1, 0, 2500, 1.4, 1 },
		Data{ "livestock", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, 500, 1, 0, 30000, 1.55, 1 },
		Data{ "fertilizer", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, 2500, 1, 0, 500000, 1.69, 1 },
		Data{ "GMO", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, 10000, 1, 0, 2000000, 1.81, 1 },
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