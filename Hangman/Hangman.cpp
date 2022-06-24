#include "Hangman.hpp"
#include<iostream>


Hangman::Hangman(std::string secret):attempt(4)
{
	this->secret = secret;
	this->guessedWord = secret;
	for (int i = 0; i < secret.length(); ++i)
	{
		guessedWord[i] =  '_' ;
	}
		
	for (int i = 0; i < 26; ++i)
	{
		alphabet[i] = false;
	}

}

std::string Hangman::getGuess()
{
	return guessedWord;
}

std::string Hangman::getAlphabet()
{
	std::string result;
	for (int i = 0; i < 26; ++i)
	{
		if (!alphabet[i])
		{
			result += 'a' + i;
		}
		else
		{
			result += '_';
		}

	}
	return result;
}

bool Hangman::guess(char c)
{
	bool isLetterDiscovered = false;

	alphabet[c - 'a'] = true;


	for (int i = 0; i < secret.length(); i++)
	{
		if (secret[i] == c)
		{
			isLetterDiscovered = true;
			guessedWord[i] = c;
		}
		
	}
	if (isLetterDiscovered==false)
	{
		--attempt;
		
	}

	if (guessedWord == secret) {
		return true;
	}
	else {
		return false;
	}
	 

}
	
	std::string Hangman::getSecret()
	{
		return secret;
	}

	int Hangman::attemptsLeft()
	{
		std::cout << "liczba prob= " << attempt << std::endl;
		return attempt;

	}


	


