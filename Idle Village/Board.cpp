#include "Board.h"

Board::Board() {
	item = IMG_Load("Images/Boards/popup.png");

	h = item->h;
	w = item->w;
	x = (1280 - w) / 2;
	y = (720 - h) / 2;

	rects[0] = SDL_Rect{ x, y, h, w };

	xButton = IMG_Load("Images/Boards/close_button.png");
	xActive = IMG_Load("Images/Boards/close_button_active.png");

	xH = xButton->h;
	xW = xButton->w;
	xX = 672 + x;
	xY = y + 40;

	rects[1] = SDL_Rect{ xX, xY, xH, xW };

	buyButton = IMG_Load("Images/Boards/buy_button.png");
	buyActive = IMG_Load("Images/Boards/buy_button_active.png");
	buyUnable = IMG_Load("Images/Boards/buy_unable.png");

	buyH = xButton->h;
	buyW = xButton->w;
	buyX = 576 + x;
	buyY = y + 448;

	rects[2] = SDL_Rect{ buyX, buyY, buyH, buyW };

	upgradeLoc = SDL_Rect{ 810, 390, 40, 40 };

	upgradeBox = SDL_CreateRGBSurface(0, 300, 75, 32, 0, 0, 0, 0);
	upgradeBoxLoc = SDL_Rect{ upgradeLoc.x + 20, upgradeLoc.y - upgradeBox->h + 20, 40, 40 };
//	for (int i = 0; i < 3; i++) {
//		= SDL_Rect{ upgrades[i].x + 20, upgrades[i].y - upgradeBox->h + 20, 40, 40 };
//	}
}

Board::~Board() {
	/*TTF_CloseFont(font);
	SDL_FreeSurface(message);
	SDL_FreeSurface(xButton);
	SDL_FreeSurface(xActive);
	SDL_FreeSurface(buyButton);
	SDL_FreeSurface(buyActive);
	SDL_FreeSurface(buyUnable);*/
	delete item;
}

void Board::display(SDL_Window* window, SDL_Surface* screen, Building* active, int& aB, TTF_Font* gFont, int& xClick, int& yClick, Currency& curr) {
	screen = SDL_GetWindowSurface(window);
	SDL_BlitSurface(item, NULL, screen, &rects[0]);
	SDL_BlitSurface(xButton, NULL, screen, &rects[1]);

	if (!selected)
		selected = active->getItems()[0];
	for (Perk * p : active->getItems()) {
		p->display(window, screen);
		if (p->checkClick(xClick, yClick)) {
			selected = p;
		}
	}
	int temp = 280; //370
	write(selected->getName(), 777, 952, 180, gFont, window, screen);
	//write(selected->getDesc(), 690, 280, gFont, window, screen);

	write("Level : " + to_string(selected->getAmountOwned()), 690, temp, gFont, window, screen);
	temp += 20;

	write(selected->getCurrentDesc() + selected->getGenRate(), 690, temp, gFont, window, screen);
	temp += 20;
	/*if (selected->getTotalDesc().compare(".") != 0) {
		write(selected->getTotalDesc() + selected->getGenRate(), 690, temp, gFont, window, screen);
		temp += 20;
	}*/
	temp += 20;
	write("Price: " + to_string(selected->getCost()), 690, temp, gFont, window, screen);
	temp += 20;
	write(selected->getNextDesc() + selected->getNextGenRate(), 690, temp, gFont, window, screen);
	temp += 50;
	SDL_BlitSurface(selected->getItem(), NULL, screen, &selectedRect);
	write("Next upgrade : ", 690, temp, gFont, window, screen);
	SDL_BlitScaled(selected->getLevel(0), NULL, screen, &upgradeLoc);
	
	int xPos, yPos;
	SDL_GetMouseState(&xPos, &yPos);

	if (selected->canBuy(curr)) {
		SDL_BlitSurface(buyButton, NULL, screen, &rects[2]);
	}
	else {
		SDL_BlitSurface(buyUnable, NULL, screen, &rects[2]);
	}
	
	//Handle X click
	if (handleMouse(rects[1], xClick, yClick)) {
		aB = -1;
		selected = NULL;
		return;
	}
	//Handle Buys
	if (handleMouse(rects[2], xClick, yClick)) {
		selected->buy(1, curr);
	}
	if (handleMouse(upgradeLoc, xPos, yPos)) {
		SDL_BlitSurface(upgradeBox, NULL, screen, &upgradeBoxLoc);
		write("HelloHelloHelloHelloHello", upgradeBoxLoc.x + 10, upgradeBoxLoc.y, gFont, window, screen);
	}
	
}

bool Board::handleMouse(SDL_Rect& r, int& xC, int& yC) {
	int endX = r.x + r.w;
	int endY = r.y + r.h;
	return (xC >= r.x && xC <= endX && yC >= r.y && yC <= endY);
}

void Board::write(string message, int x, int y, TTF_Font* gFont, SDL_Window* window, SDL_Surface * screen) {
	if (gFont) {
		TTF_CloseFont(gFont);
	}
	screen = SDL_GetWindowSurface(window);
	gFont = TTF_OpenFont("Fonts/alterebro.ttf", 28);
	SDL_Color textColor{ 255, 255, 255 };
	SDL_Surface * temp = TTF_RenderText_Blended(gFont, message.c_str(), textColor);
	SDL_Rect itemRect;

	itemRect.h = temp->h;
	itemRect.w = temp->w;
	itemRect.x = x;
	itemRect.y = y;
	SDL_BlitSurface(temp, NULL, screen, &itemRect);

	SDL_FreeSurface(temp);
	TTF_CloseFont(gFont);
	gFont = TTF_OpenFont("Fonts/alterebro.ttf", 65);
}

void Board::write(string message, int xLeft, int xRight, int y, TTF_Font* gFont, SDL_Window* window, SDL_Surface * screen) {
	screen = SDL_GetWindowSurface(window);
	SDL_Color textColor{ 255, 255, 255 };
	int w, h;
	TTF_SizeText(gFont, message.c_str(), &w, &h);

	SDL_Surface * temp = TTF_RenderText_Blended(gFont, message.c_str(), textColor);
	SDL_Rect itemRect;

	itemRect.h = temp->h;
	itemRect.w = temp->w;
	itemRect.x = (xRight-xLeft-w)/2 + xLeft;
	itemRect.y = y;
	SDL_BlitSurface(temp, NULL, screen, &itemRect);

	SDL_FreeSurface(temp);
}