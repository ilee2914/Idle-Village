#include "Board.h"

Board::Board() {
	item = IMG_Load("Images/Boards/popup_2.png");
	
	h = item->h;
	w = item->w;
	x = (1280 - w) / 2;
	y = (720 - h) / 2;

	xButton = IMG_Load("Images/Boards/close_button.png");
	xActive = IMG_Load("Images/Boards/close_button_active.png");

	xH = xButton->h;
	xW = xButton->w;
	xX = 672 + x;
	xY = y + 40;

	buyButton = IMG_Load("Images/Boards/buy_button.png");
	buyActive = IMG_Load("Images/Boards/but_button_active.png");

	buyH = xButton->h;
	buyW = xButton->w;
	buyX = 576 + x;
	buyY = y + 428;
}


Board::~Board() {
	delete item;
}


void Board::display(SDL_Window* window, SDL_Surface * screen, Building* active, TTF_Font *gFont) {
	screen = SDL_GetWindowSurface(window);
	SDL_Rect itemRect;

	itemRect.h = h;
	itemRect.w = w;
	itemRect.x = x;
	itemRect.y = y;

	SDL_BlitSurface(item, NULL, screen, &itemRect);
	
	itemRect.h = xH;
	itemRect.w = xW;
	itemRect.x = xX;
	itemRect.y = xY;

	SDL_BlitSurface(xButton, NULL, screen, &itemRect);

	itemRect.h = buyH;
	itemRect.w = buyW;
	itemRect.x = buyX;
	itemRect.y = buyY;

	SDL_BlitSurface(buyButton, NULL, screen, &itemRect);
	
	TTF_Font * font = TTF_OpenFont("Fonts/SqueakyChalkSound.ttf", 17);
/*
	for (Clickable * x : active->getItems()) {
		Buyable * i = dynamic_cast<Buyable*>(x);
		i->display(window, screen, currX, currY);
		itemRect.x = currX;
		itemRect.y = currY-5;
		SDL_BlitSurface(obj, NULL, screen, &itemRect);
		write(font, i->getName(), currX + 50, currY - 5, window, screen);
		write(font, to_string((i->getPrice())), currX + 50, currY + 20, window, screen);
		write(font, to_string(i->getAmountOwned()), currX + 230, currY + 0, window, screen);
		
		if (index % 2 == 0) {
			currX += 248;
		}
		else {
			currX -= 248;
			currY += 52;
		}

		index++;
	}
*/
	TTF_CloseFont(font);
	//SDL_FreeSurface(obj);
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