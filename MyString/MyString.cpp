#include "MyString.hpp"


MyString::MyString()
{
	this->arr = new char[1];//1 elementowa tab-dlugosc
	this->arr[0] = '\0';//dla porz¹dku deklarujemy tablice 1 elem zerowa
}

MyString::MyString(char* input)
{
	int  length = std::strlen(input);
	this->arr = new char[length+1];
	//skopiowac input
	for (int i = 0; i < length; ++i)
	{
		arr[i] = input[i];
		arr[length] = '\0';
	}
}

MyString::~MyString()
{
}

void MyString::print()
{//wypisywanie 
	for (int i = 0; i < strlen(arr); ++i)
	{
		std::cout<<arr[i];
	}
	std::cout << std::endl;
}

MyString MyString::append(char* input)
{
	int length1 = std::strlen(arr); //zlicza d³ugoœc pierwszej tablicy - 3
	int length2 = std::strlen(input); // zlicza d³ugoœæ drugiej tablicy - 3
	int length3 = length1 + length2;// dodaje te d³ugoœci - 6

	char* newArr = new char[length3 + 1]; // tworzymy nowego stringa - dodajemy do d³ugoœci +1 dla zera - 7
	for (int i = 0; i < length1; i++) //wype³niamy znakami z pierwszej tablicy
	{
		newArr[i] = arr[i]; // [a,l,a]
	}
	for (int i = 0; i < length2; i++) //wype³niamy znakami z drugiej tablicy
	{
		newArr[i + length1] = input[i];// [a,l,a, k, o, t]
	}
	newArr[length3] = '\0'; //ustawia ostatnie miejsce w tablicy na zero
	return MyString(newArr);
}

void MyString::appendToSame(char* input)
{
}

MyString MyString::append(MyString input)
{
	MyString result;
	result = this->append(input.arr);
	return result;
}

void MyString::appendToSame(MyString input)
{
}

MyString MyString::firstWord()
{
	int length1 = std::strlen(arr);
	char* word =new char[length1];
	
	for (int i = 0; i < length1; ++i)
	{
		if (arr[i] != ' ');
		{
			word[i] = arr[i];
		}

	}

	return MyString(word);
}
