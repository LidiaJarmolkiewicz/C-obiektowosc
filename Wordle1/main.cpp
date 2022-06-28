#include"Wordle1.hpp"
#include <string>


int main()
{
    Wordle1 game("BEADY");
    
    do
    {
        std::string word;
        std::cin >> word;
        std::string colours = game.test(word);
        //std::cout << colours << std::endl;
       
        game.draw();
        game.printColor('x');
    } while (!game.isFinished());



    return 0;
}
