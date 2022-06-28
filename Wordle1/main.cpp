#include"Wordle1.hpp"
#include <string>


int main()
{
    Wordle1 game("BEADY");
    int color = 0;
    do
    {
        std::string word;
        std::cin >> word;
        std::string colours = game.test(word);
        //std::cout << colours << std::endl;
        game.printColor(color, 'x');
        game.draw();
        ;
    } while (!game.isFinished());



    return 0;
}
