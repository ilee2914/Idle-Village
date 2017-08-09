#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <queue>
#include <array>

#include "Clickable.h"

#include "Object.h"
#include "Board.h"
#include "Building.h"
#include "Buyable.h"
#include "Garden.h"
#include "Perk.h"

using namespace std;

enum class GameState {
	PLAY,
	EXIT
};

struct Point {
	int x;
	int y;
};

class MainGame {
public:
	MainGame();
	~MainGame();

	void run();

private:
	void initSystems();
	void gameLoop();
	void processInput();
	void reload();
	void loadPerks(Building &);

	void storeClick();
	bool processClick(int);

	SDL_Surface *screen;
	SDL_Window *window;
	SDL_Surface *darkOL;
	SDL_Rect darkOLRect{ 0,0,0,0 };
	SDL_Renderer *renderer;
	TTF_Font *gFont = NULL;
	int screenWidth;
	int screenHeight;
	GameState gameState;

	Object bg{ "Images/Background/background.png", 0, 0 };
	Object coinbox{ "Images/Interface/coin_box.png", 10, 10 };
	
	Currency food{ "corn"};
	Currency gold{ "gold" };
	Building farm{ "farm", 156, 136, 0 };
	Building market{ "market", 710, 323, 1 };
	Building blacksmith{ "blacksmith", 926, 20, 2 };
	Building barracks{ "barracks", 467, 6, 3 };
	Object farmer{ "Images/Background/farmer.png", farm.getXPos() + 266, farm.getYPos() + 194 };
	Garden garden{ farm.getXPos() + 5 , farm.getYPos() + 269 };
	Board board;

	const int dA = 5;
	vector<Clickable*> buildings = { &garden, &farm, &market, &blacksmith, &barracks};
	int activeBuilding = -1;
	vector<Clickable*> perks;
	queue<Point> clicks;


};
