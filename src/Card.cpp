#include "../include/Card.hpp"
#include <sstream>
#include <stdexcept>

std::string suitToString(Suit suit){
    switch(suit){
        case Suit::Hearts:      return "♥";
        case Suit::Diamonds:    return "♦";
        case Suit::Clubs:       return "♣";
        case Suit::Spades:      return "♠";
        default:                throw std::invalid_argument("Unknown Suit");

    }
}

std::string rankToString(Rank rank){
    switch(rank){
        case Rank::Two:     return "2";
        case Rank::Three:   return "3";
        case Rank::Four:    return "4";
        case Rank::Five:    return "5";
        case Rank::Six:     return "6";
        case Rank::Seven:   return "7";
        case Rank::Eight:   return "8";
        case Rank::Nine:    return "9";
        case Rank::Ten:     return "10";
        case Rank::Jack:    return "J";
        case Rank::Queen:   return "Q";
        case Rank::King:    return "K";
        case Rank::Ace:     return "A";
        default:            throw std::invalid_argument("Unknown Rank");
    }
}

[[nodiscard]] std::string Card::toString() const {
    return rankToString(rank_) + suitToString(suit_);
}

[[nodiscard]] int Card::getValue() const noexcept {
    switch(rank_){
        case Rank::Ten:
        case Rank::Jack:
        case Rank::King:
        case Rank::Queen:   return 10;
        case Rank::Ace:     return 11;
        default:            return static_cast<int>(rank_);
    }
}