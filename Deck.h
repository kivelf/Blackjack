#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

// class representing a deck of cards
class Deck {
public:
    Deck();               // constructor to initialize the deck
    void shuffle();       // shuffle the deck
    Card* dealCard();     // deal a card from the deck;; returns a pointer to an object of type Card
    void resetDeck();     // reset the deck with a new set of cards

private:
    std::vector<Card> cards; // vector to store the cards
    size_t currentCardIndex; // index of the current card to be dealt
};

#endif
