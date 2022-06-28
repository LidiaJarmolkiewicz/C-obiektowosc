#pragma once
#include<string>
#include<iostream>
class Wordle1
{
	std::string secret;
	std::string guesses[6];
	std::string answers[6];
	int attempt=0;
	


public:
	Wordle1(std::string secret);
	std::string test(std::string guess);
	void printColor(int color,char x);
	void draw();
	bool isFinished(); 
	
};





	// std::cout << '\t'
// wynik metody draw
//IRATE \t BBGBO
//CEASE \t BGGBB
//HEAVY \t BGGBB
//BEADY \t GGGGG

