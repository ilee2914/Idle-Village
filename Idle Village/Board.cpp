#include "Board.h"

Board::Board() {
	item = IMG_Load("Images/Boards/popup.png");

	h = item->h;
	w = item->w;
	x = (1280 - w) / 2;
	y = (720 - h) / 2;

	rects[0].h = h;
	rects[0].w = w;
	rects[0].x = x;
	rects[0].y = y;

	xButton = IMG_Load("Images/Boards/close_button.png");
	xActive = IMG_Load("Images/Boards/close_button_active.png");

	xH = xButton->h;
	xW = xButton->w;
	xX = 672 + x;
	xY = y + 40;

	rects[1].h = xH;
	rects[1].w = xW;
	rects[1].x = xX;
	rects[1].y = xY;

	buyButton = IMG_Load("Images/Boards/buy_button.png");
	buyActive = IMG_Load("Images/Boards/buy_button_active.png");
	buyUnable = IMG_Load("Images/Boards/buy_unable.png");

	buyH = xButton->h;
	buyW = xButton->w;
	buyX = 576 + x;
	buyY = y + 448;

	rects[2].h = buyH;
	rects[2].w = buyW;
	rects[2].x = buyX;
	rects[2].y = buyY;
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
	int temp = 370;
	write(selected->getName(), 777, 952, 180, gFont, window, screen);
	write(selected->getDesc(), 690, 280, gFont, window, screen);

	string output = "";
	write("Level : " + to_string(selected->getAmountOwned()), 690, temp, gFont, window, screen);
	temp += 20;

	write(selected->getCurrentDesc() + selected->getGenRate(), 690, temp, gFont, window, screen);
	temp += 20;
	if (selected->getTotalDesc().compare(".") != 0) {
		write(selected->getTotalDesc() + selected->getGenRate(), 690, temp, gFont, window, screen);
		temp += 20;
	}
	temp += 20;
	write("Price: " + to_string(selected->getCost()), 690, temp, gFont, window, screen);
	temp += 20;
	write(selected->getNextDesc() + selected->getNextGenRate(), 690, temp, gFont, window, screen);

	SDL_BlitSurface(selected->getItem(), NULL, screen, &selectedRect);
	if (selected->canBuy(curr)) {
		SDL_BlitSurface(buyButton, NULL, screen, &rects[2]);
	}
	else {
		SDL_BlitSurface(buyUnable, NULL, screen, &rects[2]);
	}
	
	//Handle X click
	if (handleClick(rects[1], xClick, yClick)) {
		aB = -1;
		selected = NULL;
		return;
	}
	//Handle Buys
	if (handleClick(rects[2], xClick, yClick)) {
		selected->buy(1, curr);
	}
}

bool Board::handleClick(SDL_Rect& r, int& xC, int& yC) {
	int endX = r.x + r.w;
	int endY = r.y + r.h;
	return (xC >= r.x && xC <= endX && yC >= r.y && yC <= endY);
}

void Board::write(string message, int x, int y, TTF_Font* gFont, SDL_Window* window, SDL_Surface * screen) {
	screen = SDL_GetWindowSurface(window);
	TTF_CloseFont(gFont);
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