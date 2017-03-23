#pragma once

#include <iostream>
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

	void storeClick();
	void activate(int);

	SDL_Surface * screen;
	SDL_Window* window;
	SDL_Renderer *renderer;
	TTF_Font *gFont = NULL;
	int screenWidth;
	int screenHeight;
	GameState gameState;

	Object bg{ "Images/Background/background720.png", 0, 0 };
	Currency food{ "corn" };
	Building farmhouse{ "farmhouse", 150, 150 };
	Garden garden{ farmhouse.getXPos() + 9 , farmhouse.getYPos() + 269 };
	Board board;

	static const int dA = 2;
	vector<Clickable*> buildings = { &farmhouse, &garden };
	int activeBuilding = -1;
	queue<Point> clicks;
};
