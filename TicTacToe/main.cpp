#include "TicTacToe.hpp"
#include<iostream>

int main()
{
	Player* p1 = new Player(CheckerState::X);
	Player* p2 = new Player(CheckerState::O);
	Game g(p1, p2);
	g.start();
	//Board board;
	//std::cout << board;
	delete p1;
	delete p2;

	return 0;
}
