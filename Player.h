#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include <vector>

class Player {
public:
    Player();

    void hit(Card* card); // add a card to the player's hand
    void stand(); // player stands with their current hand
    bool isBusted() const; // check if the player's hand is busted
    void clearHand(); // clear the player's hand
    int getTotal() const; // get the total value of the player's current hand
    int getBalance() const; // get the player's balance
    void adjustBalance(int amount); // adjust the player's balance by a certain amount
    const Hand& getHand() const; // get the player's current hand
    bool isDoubled() const; // check if the player has doubled down
    bool isSurrendered() const; // check if the player has surrendered
    void setDoubled(bool doubled); // set the doubled down flag
    void setSurrendered(bool surrendered); // set the surrendered flag
    void resetDoubleAndSurrender(); // reset doubled and surrendered flags

    // methods for splitting
    bool canSplit() const; // check if the player can split their hand
    void splitHand(); // split the player's hand
    std::vector<Hand>& getHands(); // get all of the player's hands
    void setCurrentHandIndex(int index); // set the current hand index
    int getCurrentHandIndex() const; // get the current hand index

    // method to check if player has taken action
    bool hasTakenAction() const; // check if the player has taken an action
    void setTakenAction(bool takenAction); // set the action flag

    // method to check for blackjack
    bool hasBlackjack() const; // check if the player has a hand with blackjack

private:
    std::vector<Hand> hands; // all hands the player has
    int currentHandIndex; // index of the current hand being played
    int balance; // player's balance
    bool doubled; // flag for doubling down the bet
    bool surrendered; // flag for surrendering
    bool takenAction; // flag to track if the player has taken action
};

#endif
