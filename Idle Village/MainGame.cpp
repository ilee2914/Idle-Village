#include "MainGame.h"
#include <filesystem>

using namespace std;

MainGame::MainGame() {
	window = NULL;
	screenWidth = 1280;
	screenHeight = 720;
	gameState = GameState::PLAY;
	loadPerks(farm);
	loadPerks(market);
	loadPerks(blacksmith);
}

MainGame::~MainGame() {
	window = NULL;
}

void MainGame::run() {
	initSystems();
	gameLoop();
}

void MainGame::initSystems() {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	gFont = TTF_OpenFont("Fonts/alterebro.ttf", 25);
//	TTF_SetFontStyle(gFont, TTF_STYLE_UNDERLINE);
	SDL_CreateWindowAndRenderer(screenWidth, screenHeight, SDL_WINDOW_OPENGL, &window, &renderer);
}

void MainGame::reload() {
	Point toCheck = { 0,0 };
	if (!clicks.empty()) {
		toCheck = clicks.front();
		clicks.pop();
		cout << toCheck.x << " " << toCheck.y << endl;
	}
	bg.display(window, screen);
	
	for (int i = 0; i < dA; i++) {
		buildings[i]->display(window, screen);
		if (activeBuilding < 0 && buildings[i]->checkClick(toCheck.x, toCheck.y)) {
			if (processClick(i))
				toCheck = { 0, 0 };
		}
	}
	farmer.display(window, screen);
	if (activeBuilding > 0) {
		board.display(window, screen, dynamic_cast<Building*>(buildings[activeBuilding]), activeBuilding, toCheck.x, toCheck.y);
	}
	SDL_UpdateWindowSurface(window);
}


void MainGame::gameLoop() {
	clock_t this_time = clock();
	clock_t last_time = this_time;
	double time_counter = 0;
	double tick = CLOCKS_PER_SEC / 1;
	while (true) {
		processInput();
		this_time = clock();

		time_counter += (double)(this_time - last_time);

		last_time = this_time;

		if (time_counter > tick) {
			time_counter -= tick;
			/*
			for (Clickable * i : Perks) {
				Perk * p = dynamic_cast<Perk*>(i);
				leaf.changeByAmount(p->getGenRate());
			}*/
		}
		SDL_Delay(5);
		reload();
	}
}

void MainGame::processInput() {
	SDL_Event e;
	char key;
	SDL_PollEvent(&e);
		switch (e.type) {
		case SDL_MOUSEBUTTONUP:
			storeClick();
			break;
		case SDL_KEYDOWN:
			key = e.key.keysym.sym;
			if (key == 'a') {
			}
			break;
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		}
}

bool MainGame::processClick(int i) {
	if (i == 0) {
		buildings[0]->registerClick(food);
	}
	else {
		activeBuilding = i;
		while (!clicks.empty()) {
			clicks.pop();
		}
		return true;
	}
	return false;
}

void MainGame::storeClick() {
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	Point temp{ mouseX, mouseY };
	if (clicks.size() < 20) 
		clicks.push(temp);
}

void MainGame::loadPerks(Building & type) {
	namespace fs = std::experimental::filesystem;
	std::string path = "Images/Perks/" + type.getName();
	for (auto & p : fs::directory_iterator(path)) {
		string filename = fs::path(p).stem().string();
		vector<string> prks;
		for (auto & s : fs::directory_iterator(p)) {
			prks.push_back(fs::path(s).string());
		}
		for (unsigned int i = 0; i < prks.size(); i+=3) {
			Perk * temp = new Perk(prks.at(i), prks.at(i+1), prks.at(i+2));
			type.addPerk(temp);
		}
	}
}