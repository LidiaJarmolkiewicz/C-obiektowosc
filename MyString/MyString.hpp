#pragma once
#include<string>
#include<iostream>

class MyString//immutable-niezmienny
{
	char* arr;
public:
	MyString();
	MyString(char* input);
	~MyString();
	void print();
	MyString append(char* input);//-to spe�nia cechy immutability - metoda append zwraca nowy obiekt typu MyString
	void appendToSame(char* input);//zmienia aktualny obiekt MyString--to nie spe�nia cecy immutability

	MyString append(MyString input);
	void appendToSame(MyString input);

	MyString firstWord();

};
