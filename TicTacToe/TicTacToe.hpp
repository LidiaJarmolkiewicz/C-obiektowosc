#pragma once
#include <iostream>

enum class CheckerState { EMPTY,X,O }; //3 stany!

class Board
{
	CheckerState table[3][3]={}; 
	bool checkerColumns();
	bool checkerRows();
	bool checkerDiagonal();
public:
	CheckerState check(int x, int y)const;
	bool set(CheckerState cs, int x, int y);
	bool isOver(); //sugeruje rozbic to na 3 metody - sprawdzanie wierszy (petla), sprawdzanie kolumn (petla), sprawdzanie przeatnych/diagonali
	bool whoWon(); //or CheckerState whoWon();
	
};

class Player
{
	CheckerState colour; // mala niedoskonalosc - gracz moglby byc reprezentowany przez puste pola, zamiast X lub O, bo korzysta z 3-stanowego enuma

public:
	bool makeTurn(Board* board);
	Player(CheckerState _colour);
	
};

class Game
{
	Player* currentPlayer;
	Player* player1; //Player *player1, *player2;
	Player* player2;
	Board board;
	void swapPlayer();
public:
	void start(); //petla gry
	void reset(); //czysci plansze
	Game(Player* player1, Player* player2 );
	

};

/*
X - -
- O -
X X O
*/
std::ostream& operator<<(std::ostream& s, const Board& board);

std::ostream& operator<<(std::ostream& s, const CheckerState& cs);
