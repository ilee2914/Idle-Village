#include "MainGame.h"
#include <iostream>
#include <array>

int main(int argc, char* argv[])
{
	MainGame game;
	cout << sizeof(game);
	game.run();
	system("PAUSE");
	return 0;
}