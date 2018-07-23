#include <iostream>
#include <ctime>
#include "UnoPlayer.h"
#include "UnoGame.h"

using namespace std;

int main()
{
	srand(time(NULL));
	UnoGame game;
	game.StartGame();

	cout << endl << "Thanks for playing!\n";
	return 0;
}