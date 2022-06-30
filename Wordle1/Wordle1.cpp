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

void Wordle1::printColor(int color,char x)
{
	std::cout << "\033[1;" << color << "m" << x << "\033[0m";
}

void Wordle1::draw()
{
	system("cls");

	for (int i = 0; i < attempt; ++i)
	{
		std::cout << " " << guesses[i] << '\t';


		for (int k = 0; k < 5; ++k)
		{

			if (answers[i][k] == 'G')
			{
				printColor(32, 'G');

			}

			else if (answers[i][k] == 'O')
			{
				printColor(31, 'O');

			}

			else if (answers[i][k] == 'B')
			{
				printColor(34, 'B');

			}

		}
		std::cout << std::endl;
	}

}

bool Wordle1::isFinished()

{
	if (attempt == 6 || guesses[attempt-1] == secret)
		return true;
	//if (attempt == 0) 
		//return false;
	
}
