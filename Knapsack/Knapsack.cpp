#include "Knapsack.hpp"
#include <random>

Shop::Shop()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, 15);
	for (int i = 0; i < 10; ++i)
	{
		items[i].weight = distr(gen);
		items[i].value = distr(gen);
	}
    
}

Item Shop::steal(int index)
{
    Item itemCopy = items[index];
    items[index].weight = 0;
    items[index].value = 0;

    return itemCopy;
}

Item Shop::peek(int index)
{
    return items[index];
}

void Shop::print()
{
    std::cout << "towary w sklepie" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
       
        std::cout << items[i].weight << '\t' << items[i].value << std::endl;
        
    }
}

Backpack::Backpack(int _capacity):capacity(_capacity)
{
    for (int i = 0; i < 10; ++i)
    {
        stolen[i].weight = 0;
        stolen[i].value = 0;
    }
}

int Backpack::calculateCurrentValue() const
{
   int actualValue = 0;
    for (int i = 0; i < 10; ++i)
    {
        actualValue += stolen[i].value;
    }

    return actualValue;
}

int Backpack::calculateCurrentWeight() const
{
    int actualWeight = 0;
    for (int i = 0; i < 10; ++i)
    {
        actualWeight += stolen[i].weight;
    }

    return actualWeight;
}

int Backpack::put(Item item)
{
    stolen[firstAvailableIndex].weight = item.weight;
    stolen[firstAvailableIndex].value = item.value;
    ++firstAvailableIndex;
    return calculateCurrentWeight();
}

bool Backpack::fits(int weight)
{
  
    return calculateCurrentWeight()+weight<=capacity;
}

void Backpack::print()
{
    std::cout << "rzeczy w plecaku :" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
       
        std::cout << stolen[i].weight <<'\t'<< stolen[i].value << std::endl;
    }
}

Robber::Robber(int capacity) :backpack(Backpack (capacity))
{
}

void Robber::robWhatever(Shop& shop)
{
    for (int i = 0; i < 10; ++i)
    {
        Item it = shop.peek(i);
        int itWeight = it.weight;
        if (backpack.fits(itWeight))
        {
            Item stolenItem = shop.steal(i);
            backpack.put(stolenItem);
        }

    }
}

void Robber::robRandom(Shop& shop)
{
    for (int i = 0; i < 10; ++i)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0,9);

        int x = distr(gen);
        Item it = shop.peek(x);
        int itWeight = it.weight;
        if (backpack.fits(itWeight))
        {
            Item stolenItem = shop.steal(x);
            backpack.put(stolenItem);
        }

    }
}

void Robber::robGreedy(Shop& shop)
{
	float tabEfficiency[10] = {};
	for (int k = 0; k < 10; ++k)
	{
		Item tempIt = shop.peek(k);

        tabEfficiency[k] = (tempIt.value) / float(tempIt.weight);
        std::cout << "wspolczynniki:   " << tabEfficiency[k] << std::endl;
	}
   
    for (int k = 0; k < 10; ++k)//iteruje po shop
	{
		float maxEfficiency = 0;
        int maxIndex = 0;

		for (int i = 0; i < 10; ++i)//iteruje po tabEfficiency
		{
            if (tabEfficiency[i] > maxEfficiency)
            {
                maxEfficiency = tabEfficiency[i];
                maxIndex = i;
            }
		}
		Item it = shop.peek(maxIndex);
		int itWeight = it.weight;
		if (backpack.fits(itWeight))
		{
			Item stolenItem = shop.steal(maxIndex);
			backpack.put(stolenItem);
		}
		tabEfficiency[maxIndex] = 0;


    }

}
