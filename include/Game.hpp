#pragma once

#include "Player.hpp"
#include "Deck.hpp"

class Game{
public:
    Game();

    void play();
private:
    Deck deck_;
    Player player_{"Player"};
    Player dealer_{"Dealer", true};

    void initialDeal();
    void playerTurn();
    void dealerTurn();
    void determineWinner();
};