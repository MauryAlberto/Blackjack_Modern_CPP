#include "Game.hpp"
#include <chrono>
#include <thread>

Game::Game(){

}

void Game::play(){
    std::cout << "Welcome to Blackjack!\n\n";
    initialDeal();
    playerTurn();
    dealerTurn();
    determineWinner();
}

void Game::initialDeal(){
    deck_.shuffle();
    std::cout << "Initial Deal: \n";

    for(int i = 0; i < 2; i++){
        std::optional<Card> card = deck_.dealCard();
        if(card){
            dealer_.addCard(*card);
        }else{
            std::cerr << "Deck is empty. Cannont continue dealing.\n";
            return;
        }
    }

    dealer_.showHand(true);

    for(int i = 0; i < 2; i++){
        std::optional<Card> card = deck_.dealCard();
        if(card){
            player_.addCard(*card);
        }else{
            std::cerr << "Deck is empty. Cannont continue dealing.\n";
            return;
        }
    }

    player_.showHand();
}

void Game::playerTurn(){
    while(true){
        std::cout << "Do you want to (h)it or (s)tand?: ";
        char choice;
        std::cin >> choice;
        std::cin.ignore();

        while(choice != 's' && choice != 'S' && choice != 'h' && choice != 'H'){
            std::cout << "Do you want to (h)it or (s)tand?: ";
            std::cin >> choice;
            std::cin.ignore();
        }

        std::cout << "\n";

        if(choice == 's' || choice == 'S'){
            std::cout << player_.getName() << " stands with a hand value of " << player_.getHandValue() << ".\n";
            return;
        }else if(choice == 'h' || choice == 'H'){
            std::optional<Card> card = deck_.dealCard();
            if(card){
                player_.addCard(*card);
                std::cout << "You drew: ";
                player_.showHand(false, true);
                std::cout << "Your hand value: " << player_.getHandValue() << "\n\n";
                std::this_thread::sleep_for(std::chrono::seconds(3));

                if(player_.isBusted()){
                    std::cout << player_.getName() << " busted with a hand value of " << player_.getHandValue() << "!\n";
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    return;
                }
            }else{
                std::cerr << "Deck is empty. Cannot deal more cards.\n";
                return;
            }
        }
    }
}

void Game::dealerTurn(){
    std::cout << "Dealer's turn: \n";
    dealer_.showHand(false, false);
    std::this_thread::sleep_for(std::chrono::seconds(3));


    while(dealer_.getHandValue() < 17){
        std::cout << "Dealer hits...\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        
        std::optional<Card> card = deck_.dealCard();
        if(card.has_value()){
            dealer_.addCard(card.value());
            dealer_.showHand(false, false);
        }else{
            std::cerr << "Deck is empty. Cannot deal more cards.\n";
            break;
        }
    }

    if(dealer_.isBusted()){
        std::cout << "Dealer busts!\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }else{
        std::cout << "Dealer stands with " << dealer_.getHandValue() << ".\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

void Game::determineWinner(){
    int playerValue = player_.getHandValue();
    int dealerValue = dealer_.getHandValue();

    std::cout << "\nFinal Results: \n\n";
    std::cout << "Player hand (" << playerValue << "): ";
    player_.showHand(false, false);
    std::cout << "Dealer hand (" << dealerValue << "): ";
    dealer_.showHand(false, false);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    if (playerValue > 21) {
        std::cout << "You busted! Dealer wins.\n";
    } else if (dealerValue > 21) {
        std::cout << "Dealer busted! You win!\n";
    } else if (playerValue > dealerValue) {
        std::cout << "You win with a higher hand!\n";
    } else if (playerValue < dealerValue) {
        std::cout << "Dealer wins with a higher hand.\n";
    } else {
        std::cout << "It's a tie! (Push)\n";
    }
}