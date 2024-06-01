#include "Hand.h"
#include <sstream>

// initialize an empty hand
Hand::Hand() {}

// add a card to the hand
void Hand::addCard(Card* card) {
    if (card) { // in C++ a null-pointer is false, while a non-null pointer evaluates to true
        cards.push_back(card);
    }
}

// calculate the total value of the hand
int Hand::getTotal() const {
    int total = 0;
    int numAces = 0;
    for (Card* card : cards) {
        int value = card->getValue(); //  the arrow operator is used to access a member function of an object through a pointer
        // the line could also be written like: (*card).getValue()
        if (value == 11) { // ace - initially treated as 11
            numAces++;
        }
        total += value;
    }
    // adjust for aces if total is over 21
    while (total > 21 && numAces > 0) {
        total -= 10;
        numAces--;
    }
    return total;
}

// check if the hand is busted
bool Hand::isBusted() const {
    return getTotal() > 21;
}

// clear the hand
void Hand::clear() {
    cards.clear();
}

// get a string representation of the hand
std::string Hand::toString() const {
    std::stringstream ss;
    for (Card* card : cards) {
        ss << card->toString() << ", ";
    }
    std::string handString = ss.str();
    if (!handString.empty()) {
        handString.pop_back(); // remove the trailing space (last char)
        handString.pop_back(); // remove the trailing comma (previous to last char)
    }
    return handString;
}

// check if the hand can be split
bool Hand::canSplit() const {
    return cards.size() == 2 && cards[0]->getValue() == cards[1]->getValue();
}

// split the hand into two
Hand Hand::split() {
    Hand newHand;
    if (canSplit()) {
        newHand.addCard(cards.back());
        cards.pop_back(); // removes the last element from the vector
    }
    return newHand;
}

// get the cards in the hand
std::vector<Card*> Hand::getCards() const {
    return cards;
}
