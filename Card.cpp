#include "Card.h"
#include <sstream>

// constructor to initialize the card with a rank and suit
Card::Card(Rank r, Suit s) : rank(r), suit(s) {}

// get the card as a string
std::string Card::toString() const {
    std::ostringstream oss;
    // convert the rank to string
    switch (rank) {
    case Rank::Two: oss << "2"; break;
    case Rank::Three: oss << "3"; break;
    case Rank::Four: oss << "4"; break;
    case Rank::Five: oss << "5"; break;
    case Rank::Six: oss << "6"; break;
    case Rank::Seven: oss << "7"; break;
    case Rank::Eight: oss << "8"; break;
    case Rank::Nine: oss << "9"; break;
    case Rank::Ten: oss << "10"; break;
    case Rank::Jack: oss << "J"; break;
    case Rank::Queen: oss << "Q"; break;
    case Rank::King: oss << "K"; break;
    case Rank::Ace: oss << "A"; break;
    }

    // add the suit to the string
    oss << " of ";
    switch (suit) {
    case Suit::Hearts: oss << "Hearts"; break;
    case Suit::Diamonds: oss << "Diamonds"; break;
    case Suit::Clubs: oss << "Clubs"; break;
    case Suit::Spades: oss << "Spades"; break;
    }

    return oss.str();  // return the card as a string
}

// get the value of the card
int Card::getValue() const {
    if (rank >= Rank::Two && rank <= Rank::Ten)
        return static_cast<int>(rank);  // number cards return their rank value...
    else if (rank >= Rank::Jack && rank <= Rank::King)
        return 10;  // ...while face cards (Jack, Queen, King) return 10
    else // Ace
        return 11;  // Ace returns 11, but can also be 1 (this is handled in the game logic, no need to worry about it here!)
}
