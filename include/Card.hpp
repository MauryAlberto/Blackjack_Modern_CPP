#pragma once

#include <string>
#include <compare>
#include <utility>

enum class Suit {Hearts, Diamonds, Clubs, Spades };
enum class Rank {Two = 2, Three, Four, Five, Six, Seve, Eight, Nine, Ten,
                 Jack = 10, Queen = 10, King = 10, Ace = 11};

class Card{
    public:
        constexpr Card(Suit suit, Rank rank) noexcept : suit_{suit}, rank_{rank} {}

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