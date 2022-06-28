#include "Knapsack.hpp"
#include <iostream>

int main()
{

	Shop shop;
	shop.print();
	Robber robber(30);
	robber.backpack.print();
	//robber.robWhatever(shop);
	//robber.robGreedy(shop);
	robber.robRandom(shop);
	robber.backpack.print();
	shop.print();

	return 0;
}
