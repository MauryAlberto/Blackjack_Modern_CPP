#pragma once

#include "Card.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include <ranges>

class Player{
public:
    explicit Player(std::string name, bool isDealer = false) : name_{std::move(name)}, isDealer_{isDealer} {}

    void addCard(Card card);
    void clearHand();

    [[nodiscard]] int getHandValue() const;
    [[nodiscard]] bool isBusted() const {return getHandValue() > 21;}
    
    void showHand(bool hideFirstCard = false, bool singleDraw = false) const;
    [[nodiscard]] const std::string& getName() const noexcept {return name_;}

private:
    std::string name_;
    std::vector<Card> hand_;
    bool isDealer_;
};