#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"

class Game {
public:
    Game();
    void play(); // start the game
    void playerTurn(); // handle the player's turn
    void dealerTurn(); // handle the dealer's turn
    void determineWinner(); // determine the winner of the round

private:
    Deck deck; // the deck of cards
    Player player; // the player
    Player dealer; // the dealer
};

#endif