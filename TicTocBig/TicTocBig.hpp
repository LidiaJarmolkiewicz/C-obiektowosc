#pragma once
#include <iostream>

enum class CheckerState { EMPTY, X, O }; 

class Board
{
	CheckerState table[10][10] = {};
	bool checkerColumns();
	bool checkerRows();

public:
	CheckerState check(int x, int y)const;
	bool set(CheckerState cs, int x, int y);
	bool isOver();
	bool whoWon();

};

class Player
{
	CheckerState colour; 

public:
	bool makeTurn(Board* board);
	Player(CheckerState _colour);

};

class Game
{
	Player* currentPlayer;
	Player* player1; 
	Player* player2;
	Board board;
	void swapPlayer();
public:
	void start(); 
	void reset(); 
	Game(Player* player1, Player* player2);


};



std::ostream& operator<<(std::ostream& s, const Board& board);

std::ostream& operator<<(std::ostream& s, const CheckerState& cs);
