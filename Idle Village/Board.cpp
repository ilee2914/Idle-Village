#include "Board.h"

Board::Board() {
	item = IMG_Load("Images/board.png");
	x = 182;
	y = 182;
}


Board::~Board() {
	delete item;
}

/*
void Board::display(SDL_Window* window, SDL_Surface * screen, Sign* post, TTF_Font *gFont) {
	screen = SDL_GetWindowSurface(window);
	SDL_Rect itemRect;

	itemRect.h = item->h;
	itemRect.w = item->w;
	itemRect.x = x;
	itemRect.y = y;

	SDL_BlitSurface(item, NULL, screen, &itemRect);

	string name = post->getName();
	write(gFont, name, 250, 250, window, screen);

	int currX = 280;
	int currY = 320;
	int index = 0;
	SDL_Surface * obj = IMG_Load("Images/border.png");

	itemRect.h = obj->h;
	itemRect.w = obj->w;
	TTF_Font * font = TTF_OpenFont("Fonts/SqueakyChalkSound.ttf", 17);

	for (Clickable * x : *(post->getItems())) {
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

		// create a writeNumber function
		// make buy button
	}

	TTF_CloseFont(font);
	SDL_FreeSurface(obj);
}
*/
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