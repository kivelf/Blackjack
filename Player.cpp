#include "Player.h"
#include <iostream>

// initialize the player with default values
Player::Player() : balance(100), doubled(false), surrendered(false), currentHandIndex(0), takenAction(false) {
    hands.push_back(Hand()); // add an initial empty hand
}

// add a card to the current hand
void Player::hit(Card* card) {
    if (card) {
        hands[currentHandIndex].addCard(card);
        takenAction = true; // mark that the player has taken an action
    }
    else {
        std::cerr << "Error: Tried to add a null card.\n";
    }
}

// player chooses to stand
void Player::stand() {
    takenAction = true; // mark that the player has taken an action
}

// check if the player's current hand is busted
bool Player::isBusted() const {
    return hands[currentHandIndex].isBusted();
}

// clear all hands and reset to a single empty hand
void Player::clearHand() {
    hands.clear();
    hands.push_back(Hand());
    currentHandIndex = 0;
    takenAction = false; // reset the action flag
}

// get the total value of the current hand
int Player::getTotal() const {
    return hands[currentHandIndex].getTotal();
}

// get the player's balance
int Player::getBalance() const {
    return balance;
}

// adjust the player's balance by the given amount
void Player::adjustBalance(int amount) {
    balance += amount;
}

// get the current hand
// returns a reference to the current hand of the player
// thus allowing direct access to and modification of the hand without having to copy it
const Hand& Player::getHand() const {
    return hands[currentHandIndex];
}

// check if the player has doubled down
bool Player::isDoubled() const {
    return doubled;
}

// check if the player has surrendered
bool Player::isSurrendered() const {
    return surrendered;
}

// set the doubled down flag
void Player::setDoubled(bool doubled) {
    this->doubled = doubled; // the arrow operator (->) is used to access member variables of the current object
}

// set the surrendered flag
void Player::setSurrendered(bool surrendered) {
    this->surrendered = surrendered;
}

// reset doubled and surrendered flags
void Player::resetDoubleAndSurrender() {
    doubled = false;
    surrendered = false;
}

// check if the player can split their hand
bool Player::canSplit() const {
    return hands[currentHandIndex].canSplit();
}

// split the player's current hand
void Player::splitHand() {
    if (canSplit()) {
        Hand newHand = hands[currentHandIndex].split();
        hands.push_back(newHand);
    }
}

// get all of the player's hands
std::vector<Hand>& Player::getHands() {
    return hands;
}

// set the current hand index
void Player::setCurrentHandIndex(int index) {
    currentHandIndex = index;
}

// get the current hand index
int Player::getCurrentHandIndex() const {
    return currentHandIndex;
}

// check if the player has taken an action
bool Player::hasTakenAction() const {
    return takenAction;
}

// set the action flag
void Player::setTakenAction(bool takenAction) {
    this->takenAction = takenAction;
}

// check if the player has a blackjack (i.e. when the total of the first 2 drawn cards is 21)
bool Player::hasBlackjack() const {
    return hands[currentHandIndex].getTotal() == 21 && hands[currentHandIndex].getCards().size() == 2;
}
