#pragma once

#include "Card.hpp"
#include <vector>
#include <random>
#include <memory>
#include <optional>

class Deck{
public:
    Deck();

    void shuffle();
    [[nodiscard]] std::shared_ptr<Card> dealCard();
    [[nodiscard]] bool isEmpty() const noexcept;

private:
    std::vector<std::shared_ptr<Card>> cards_;
    std::mt19937 rng_{std::random_device{}()};
};