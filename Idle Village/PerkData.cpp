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
double costRate;
double trueCost;
int code;
};
*/

string PerkData::postFix[20] = { "m", "b", "t", "b", "t", "qu", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

vector< vector <Data> > PerkData::dataset = {
	// Farm Data
	{
		Data{ "farmer", "Increases food per click", "Current FPC: ", ".", "Next level FPC: ", 0, .2, 1, 1, .2, 1, 0 },	//special
		Data{ "corn", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, .2, 1, .2, 10, 10, 1 },
		Data{ "carrot", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, .2, 1, 1, .2, 10, 1 },
		Data{ "equipment", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, .2, 1, .2, 1.21, 1, 1 },
		Data{ "livestock", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, .2, 1, .2, 1.21, 1, 1 },
		Data{ "fertilizer", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, .2, 1, .2, 1.21, 1, 1 },
		Data{ "GMO", "Poop on my face", "Current FPS per level: ", "Total corn FPS: ", "Next level FPS: ", 0, .2, 1, .2, 1.21, 1, 1 },
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