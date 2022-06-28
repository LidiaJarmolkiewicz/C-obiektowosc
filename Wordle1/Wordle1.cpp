#include"Wordle1.hpp"
#include<string>

Wordle1::Wordle1(std::string secret)
{
	this->secret = secret;
	
}

std::string Wordle1::test(std::string guess)
{
	if (attempt < 6)
	{

		guesses[attempt] = guess;
		answers[attempt] = std::string(5, 'B');


		for (int i = 0; i < 5; ++i)
		{

			if (secret[i] == guess[i])
			{
				answers[attempt][i] = 'G';
				
			}
			else {

				for (int k = 0; k < 5; ++k)
				{
					if (secret[i] == guess[k])
					{
						answers[attempt][k] = 'O';
					}

				}
			}

		}
		++attempt;
		return answers[attempt - 1];

	}
	
	
	return std::string();
	
}

void Wordle1::printColor(char x)
{
	if (x == 'G')
	{
		std::cout << "\033[1;32mG\033[0m\n";
	}
	else if (x == 'O')
	{
		std::cout << "\033[1;31mO\033[0m\n";
	}
	else if (x == 'B')
	{
		std::cout << "\033[1;30mB\033[0m\n";
	}
}

void Wordle1::draw()
{
	system("cls");
	
	for (int i = 0; i < 6; ++i)
	{
		for (int k = 0; k < 5; ++k)
		{
			if (answers[i][k] == 'G')
			{
				printColor('G');

			}
			else if (answers[i][k] == 'O')
			{
				printColor('O');
			}
			else if (answers[i][k] == 'B')
			{
				printColor('B');
			}

		}
		

		std::cout << guesses[i] << '\t' << answers[i] << std::endl;

		


	}
	

	
}

bool Wordle1::isFinished()
{
	if (attempt == 6 || guesses[attempt-1] == secret)
		return true;
	else
		return false;
	
}
