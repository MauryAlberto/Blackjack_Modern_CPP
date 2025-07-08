#pragma once

#include <string>
#include <compare>
#include <utility>

enum class Suit {Hearts, Diamonds, Clubs, Spades };
enum class Rank {Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
                 Jack, Queen, King, Ace};

class Card{
    public:
        constexpr Card(Rank rank, Suit suit) noexcept : rank_{rank}, suit_{suit} {}

        [[nodiscard]] std::string toString() const;
        [[nodiscard]] Rank getRank() const noexcept {return rank_;}
        [[nodiscard]] Suit getSuit() const noexcept {return suit_;}
        [[nodiscard]] int getValue() const noexcept;
        [[nodiscard]] bool isAce() const noexcept {return rank_ == Rank::Ace;}

        auto operator<=>(const Card&) const = default;

    private:
        Suit suit_;
        Rank rank_;
};