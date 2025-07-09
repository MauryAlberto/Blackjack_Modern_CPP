#pragma once

#include "Card.hpp"
#include <vector>
#include <random>
#include <memory>
#include <optional>
#include <algorithm>
#include <iterator>

class Deck{
public:
    Deck();

    void shuffle();
    [[nodiscard]] std::optional<Card> dealCard();
    [[nodiscard]] bool isEmpty() const noexcept;

private:
    std::vector<Card> cards_;
    std::mt19937 rng_{std::random_device{}()};
};