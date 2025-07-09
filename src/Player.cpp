#include "Player.hpp"

void Player::addCard(Card card){
    hand_.push_back(card);
}

void Player::clearHand(){
    hand_.clear();
}

int Player::getHandValue() const{
    int value = 0;
    int aceCount = 0;

    for(const auto& card : hand_){
        value += card.getValue();

        if(card.getRank() == Rank::Ace){
            ++aceCount;
        }
    }

    while(value > 21 && aceCount > 0){
        value -= 10;
        --aceCount;
    }

    return value;
}

void Player::showHand(bool hideFirstCard, bool singleDraw) const{
    if(singleDraw){
        std::cout << "[" << hand_.back().toString() << "]\n";
        return;
    }

    std::cout << name_ << ":";

    for(size_t i = 0; i < hand_.size(); ++i){
        if(hideFirstCard && isDealer_ && i == 0){
            std::cout << " [??]";
        }else{
            std::cout << " [" << hand_[i].toString() << "]";
        }
    }

    std::cout << "\n";

    if(!hideFirstCard && !isDealer_){
        std::cout << "Your hand value: " << getHandValue() << "\n\n";
    }else if(!hideFirstCard && isDealer_){
        std::cout << "Dealer hand value: " << getHandValue() << "\n\n";
    }
}