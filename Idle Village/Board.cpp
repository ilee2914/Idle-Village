#include "Board.h"

Board::Board() {
	item = IMG_Load("Images/Boards/popup_2.png");
	
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
	buyY = y + 428;

	rects[2].h = buyH;
	rects[2].w = buyW;
	rects[2].x = buyX;
	rects[2].y = buyY;
}

Board::~Board() {
	delete item;
}

void Board::display(SDL_Window* window, SDL_Surface* screen, Building* active, int& aB, int& xClick, int& yClick) {
	screen = SDL_GetWindowSurface(window);
	SDL_BlitSurface(item, NULL, screen, &rects[0]);
	if (handleClick(rects[1], xClick, yClick)) {
		aB = -1;
		selected = NULL;
		return;
	}
	SDL_BlitSurface(xButton, NULL, screen, &rects[1]);
	if (!selected) 
		selected = active->getItems()[0];
	TTF_Font * font = TTF_OpenFont("Fonts/alterebro.ttf", 17);
	for (Perk * p : active->getItems()) {
		p->display(window, screen);
		if (p->checkClick(xClick, yClick)) {
			selected = p;
		}
	}
	SDL_BlitSurface(selected->getItem(), NULL, screen, &selectedRect);
	SDL_BlitSurface(buyButton, NULL, screen, &rects[2]);
	TTF_CloseFont(font);
}

bool Board::handleClick(SDL_Rect& r, int& xC, int& yC) {
	int endX = r.x + r.w;
	int endY = r.y + r.h;
	return (xC >= r.x && xC <= endX && yC >= r.y && yC <= endY);
}

void Board::write(TTF_Font * font, string message, int x, int y, SDL_Window* window, SDL_Surface * screen) {
	SDL_Color textColor{ 255, 255, 255 };
	SDL_Surface * temp = TTF_RenderText_Blended(font, message.c_str(), textColor);
	SDL_Rect itemRect;

	itemRect.h = temp->h;
	itemRect.w = temp->w;
	itemRect.x = x;
	itemRect.y = y;
	SDL_BlitSurface(temp, NULL, screen, &itemRect);

	SDL_FreeSurface(temp);
	
}