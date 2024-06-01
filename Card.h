#ifndef CARD_H
#define CARD_H

#include <string>

// enum for the suits of the cards
enum class Suit { Hearts, Diamonds, Clubs, Spades };

// enum for the ranks of the cards
enum class Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

// the class representing a card
class Card {
public:
    Card(Rank r, Suit s);           // constructor to initialize the card with a rank and suit

    std::string toString() const;   // get the card as a string
    int getValue() const;           // get the value of the card

private:
    Rank rank;  // rank of the card
    Suit suit;  // suit of the card
};

#endif
