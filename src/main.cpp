#include "Game.hpp"

int main(){
    char choice;
    do{
        Game game;
        game.play();
        std::cout << "\nplay again? (y/n): ";
        std::cin >> choice;
        std::cin.ignore();
        std::cout << "\n";
    }while(choice != 'n' && choice != 'N');
    std::cout << "Goodbye!\n";

    return 0;
}

