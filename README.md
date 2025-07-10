# Blackjack in Modern C++17

A command-line Blackjack (21) game implemented in **C++17**, showcasing object-oriented design, `std::optional` usage, and simple CLI interactivity. This project is organized using CMake.

---

## Project Structure

```
Blackjack/
├── include/
│   ├── Card.hpp
│   ├── Deck.hpp
│   ├── Game.hpp
│   └── Player.hpp
├── src/
│   ├── Card.cpp
│   ├── Deck.cpp
│   ├── Game.cpp
|   ├── main.cpp
│   └── Player.cpp
├── .gitignore
├── CMakeLists.txt
└── README.md
```

---

## Getting Started

### Prerequisites

- A **C++17** compliant compiler
- [CMake](https://cmake.org/) (version 3.10+)
- A terminal with `make` or `ninja`

### 🛠 Build Instructions

```bash
git clone https://github.com/MauryAlberto/Blackjack_Modern_CPP.git
cd Blackjack_Modern_CPP
mkdir build && cd build
cmake ..
make
./blackjack
```

---

## Gameplay Rules

- Player and dealer are each dealt 2 cards initially.
- Dealer’s first card is hidden until player stands or busts.
- Player chooses to `hit` (draw) or `stand`.
- Dealer draws until their hand is 17 or higher.
- Closest to 21 without going over wins.

---

## Features

- Clean OOP structure: `Card`, `Deck`, `Player`, `Game`
- No raw pointers — no dynamic memory management required
- Uses `std::optional` for safe card drawing
- Unicode suits (`♥♦♣♠`) for clean output
- Simple CLI input/output
- Delays using `std::this_thread::sleep_for` to simulate realism

---

## Sample Output

```
Welcome to Blackjack!

Initial Deal: 
Dealer: [??] [10♣]
Player: [K♥] [8♦]
Your hand value: 18

Do you want to (h)it or (s)tand?: h

You drew: [2♦]
Your hand value: 20

Do you want to (h)it or (s)tand?: s

Player stands with a hand value of 20.

Dealer's turn: 
Dealer: [5♣] [10♣]
Dealer hand value: 15

Dealer hits...
Dealer: [5♣] [10♣] [Q♠]
Dealer hand value: 25

Dealer busts!

Final Results: 

Player hand (20): Player: [K♥] [8♦] [2♦]
Your hand value: 20

Dealer hand (25): Dealer: [5♣] [10♣] [Q♠]
Dealer hand value: 25

Dealer busted! You win!

play again? (y/n): n

Goodbye!

```

---

## Key Concepts Demonstrated

- C++17 `std::optional` for safe return values
- RAII design (no memory leaks)
- CMake project configuration
- Encapsulation & separation of concerns in OOP