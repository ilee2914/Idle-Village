#include "MainGame.h"

using namespace std;

MainGame::MainGame() {
	window = NULL;
	screenWidth = 1280;
	screenHeight = 720;
	gameState = GameState::PLAY;
	//fillPlants();
}

MainGame::~MainGame() {
	window = NULL;
}

void MainGame::run() {
	initSystems();
	gameLoop();
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
		if (buildings[i]->checkClick(toCheck.x, toCheck.y)) {
			activate(i);
		}
	}
	/*
	Clickable * actShop = checkActive();
	if (actShop != nullptr) {
		//board.display(window, screen, gFont);
	}
	*/
	SDL_UpdateWindowSurface(window);
}

void MainGame::activate(int i) {
	activeBuilding = i;
	while (!clicks.empty()) {
		clicks.pop();
	}
}

void MainGame::initSystems() {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	gFont = TTF_OpenFont("Fonts/SqueakyChalkSound.ttf", 25);
//	TTF_SetFontStyle(gFont, TTF_STYLE_UNDERLINE);
	SDL_CreateWindowAndRenderer(screenWidth, screenHeight, SDL_WINDOW_OPENGL, &window, &renderer);
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
			for (Clickable * i : plants) {
				Plant * p = dynamic_cast<Plant*>(i);
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
		case SDL_MOUSEBUTTONDOWN:
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
void MainGame::storeClick() {
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	Point temp{ mouseX, mouseY };
	if (clicks.size() < 20) 
		clicks.push(temp);
}
/*
void MainGame::checkClick(vector<Clickable*> items) {
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	for (int i = 0; i < items.size(); i++) {
		int startX = items[i]->getXPos();
		int endX = startX + items[i]->getWidth();
		int startY = items[i]->getYPos();
		int endY = startY + items[i]->getHeight();
		if (mouseX >= startX && mouseX <= endX) {
			if (mouseY >= startY && mouseY <= endY) {
				items[i]->registerClick(food, items);
				return;
			}
		}
	}
}

Clickable * MainGame::checkActive() {
	for (unsigned int i = 0; i < alwaysActive.size(); i++) {
		Sign * temp = dynamic_cast<Sign*>(alwaysActive.at(i));
		if (temp->isActive()) {
			return temp;
		}
	}
	return nullptr;
}

void MainGame::fillPlants() {
	Plant * daisy = new Plant{ "daisy", .1, 0, 1, 0, 20, .2, "Daisy", "Pretty flower" };
	Plant * sunf = new Plant{ "sunflower", .1, 0, 1, 0, 128, .2, "SunFlower", "Pretty flower" };
	Plant * apple = new Plant{ "appletree", .1, 0, 1, 0, 512, .4, "shit", "fuck" };
	Plant * acorn = new Plant{ "acorn", .1, 0, 1, 0, 512, .4, "shit", "fuck" };
	Plant * mush = new Plant{ "mushroom", .1, 0, 1, 0, 512, .4, "shit", "fuck" };
	Plant * sap = new Plant{ "saplingTree", .1, 0, 1, 0, 512, .4, "shit", "fuck" };

	plants.push_back(daisy);
	plants.push_back(sunf);
	plants.push_back(apple);
	plants.push_back(acorn);
	plants.push_back(mush);
	plants.push_back(sap);


	int currX = 280;
	int currY = 320;
	SDL_Surface * obj = IMG_Load("Images/border.png");
	SDL_Rect itemRect;

	itemRect.h = obj->h;
	itemRect.w = obj->w;
	
	for (int i = 0; i < plants.size(); i++) {
		plants.at(i)->changeXPos(currX);
		plants.at(i)->changeYPos(currY);
		plants.at(i)->changeHeight(itemRect.h);
		plants.at(i)->changeWidth(itemRect.w);

		if (i % 2 == 0) {
			currX += 248;
		}
		else {
			currX -= 248;
			currY += 52;
			
		}
		
	}

}
*/