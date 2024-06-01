#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
public:
    Hand();

    void addCard(Card* card); // add a card to the hand
    int getTotal() const; // get the total value of the hand
    bool isBusted() const; // check if the hand is busted
    void clear(); // clear the hand
    std::string toString() const; // get a string representation of the hand

    // methods for splitting
    bool canSplit() const; // check if the hand can be split
    Hand split(); // split the hand
    std::vector<Card*> getCards() const; // get the cards in the hand

private:
    std::vector<Card*> cards; // the cards in the hand
};

#endif
