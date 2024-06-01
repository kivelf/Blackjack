#include "Deck.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>
#include <iostream>

// constructor to initialize the deck by resetting it
Deck::Deck() {
    resetDeck();
}

// shuffle the cards in the deck
void Deck::shuffle() {
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count())));
    currentCardIndex = 0; // reset current card index after shuffling
}

// deal a card from the deck
Card* Deck::dealCard() {
    if (currentCardIndex < cards.size()) {
        return &cards[currentCardIndex++]; // return a pointer to the current card and increments the index
        // the &-operator takes the gets the memory address of the card object
        // and this address is assigned to the pointer returned by the method
    }
    std::cerr << "Error: No more cards in the deck.\n"; // error if no more cards
    return nullptr;
}

// reset the deck with a full set of cards
void Deck::resetDeck() {
    cards.clear(); // clear any existing cards
    // add all 52 cards to the deck
    for (int s = 0; s < 4; ++s) {
        for (int r = 2; r <= 14; ++r) {
            cards.emplace_back(static_cast<Rank>(r), static_cast<Suit>(s)); // constructs a new Card object with the
            // specified rank and suit and adds it to the cards container;;
            // emplace_back() is a function of the std::vector class and is
            // used to construct an element in place at the end of the container
        }
    }
    shuffle(); // shuffling the new deck...
}
