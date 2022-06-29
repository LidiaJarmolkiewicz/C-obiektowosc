#include "TicTacToe.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& s, const Board& board)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int k = 0; k < 3; ++k)
		{
			s << board.check(i, k);
			s << " ";
			
		}
		s<<std::endl;
}

	 return s;
}

std::ostream& operator<<(std::ostream& s, const CheckerState& cs)
{
	if (cs == CheckerState::X)
	{
		s<<"X";
	}

	if (cs == CheckerState::O)
	{
		s << "O";
	}

	if (cs == CheckerState::EMPTY)
	{
		s << "-";
	}
	
	return s;
}

bool Board::checkerColumns()
{
	bool result = false;
	for (int i = 0; i < 3; ++i)
	{
		if (table[i][0] == table[i][1] &&
			table[i][1] == table[i][2] &&
			table[i][0] != CheckerState::EMPTY)
			result =true;
	}

	return result;
}

bool Board::checkerRows()
{

	bool result = false;
	for (int i = 0; i < 3; ++i)
	{
		if (table[0][i] == table[1][i] &&
			table[1][i] == table[2][i] &&
			table[0][i] != CheckerState::EMPTY)
			result = true;
	}

	return result;
}

bool Board::checkerDiagonal()
{

	bool result = false;
	for (int i = 0; i < 3; ++i)
	{
		if( (table[0][0] == table[1][1] &&table[1][1] == table[2][2] && table[0][0] != CheckerState::EMPTY)
			|| (table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2] != CheckerState::EMPTY))
		
			result = true;
	}

	return result;
}

CheckerState Board::check(int x, int y) const
{
	return table[x][y];
}

bool Board::set(CheckerState cs, int x, int y)
{
	table[x][y] = cs;
	return true;
}

bool Board::isOver()
{
	return(checkerRows() || checkerColumns() || checkerDiagonal());
	
}

bool Board::whoWon()
{
	return false;
}



bool Player::makeTurn(Board* board)
{

	std::cout << "Current player: "<<colour  <<std::endl;
	int x = 0; int y = 0;
	do {
		std::cout << "enter x,y " << std::endl;
		std::cin >> x;
		std::cin >> y;
	} while (board->check(x,y)!=CheckerState::EMPTY);
	board->set(colour, x, y);
	return false;
}

Player::Player(CheckerState colour)
{
	this->colour = colour;
	
}



void Game::swapPlayer()
{
	if (currentPlayer == player1)
	{
		currentPlayer =player2;
	}
	else
		currentPlayer = player1;
}

void Game::start()
{
	currentPlayer = player1;
	do
	{
		currentPlayer->makeTurn(&board);
		
		std::cout << board;
		swapPlayer();

	} while (!board.isOver());
	if (board.whoWon())
	{
		std::cout << "won player X" << std::endl;
	}
	else
	{
		std::cout << "won player O" << std::endl;
	}
		
}

Game::Game(Player* player1, Player* player2)
{
	this->player1 = player1;
	this->player2 = player2;
	
}


