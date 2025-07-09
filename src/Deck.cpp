#include "Deck.hpp"

Deck::Deck(){
    for(int rank = static_cast<int>(Rank::Two); rank <= static_cast<int>(Rank::Ace); ++rank){
        for(int suit = static_cast<int>(Suit::Hearts); suit <= static_cast<int>(Suit::Spades); ++suit){
            cards_.emplace_back(static_cast<Rank>(rank), static_cast<Suit>(suit));

        }
    }
}

void Deck::shuffle(){
    std::shuffle(cards_.begin(), cards_.end(), rng_);
}

std::optional<Card> Deck::dealCard(){
    if(isEmpty()){
        return std::nullopt;
    }

    Card card = cards_.back();
    cards_.pop_back();
    return card;
}

bool Deck::isEmpty() const noexcept{
    return cards_.empty();
}