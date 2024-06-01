#include "Game.h"
#include <iostream>
#include <algorithm>
using namespace std;

// initialize the game by shuffling the deck
Game::Game() {
    deck.shuffle();  // shuffle the deck at the start of the game
}

// start the game loop
void Game::play() {
    while (player.getBalance() >= 10) {  // continue playing as long as the player has enough money to bet
        player.clearHand();  // clear hands at the beginning of each round
        dealer.clearHand();
        deck.resetDeck();   // resetting the deck at the beginning of each round

        // deal initial two cards to player and dealer
        player.hit(deck.dealCard());
        player.hit(deck.dealCard());
        dealer.hit(deck.dealCard());
        dealer.hit(deck.dealCard());

        if (!player.hasBlackjack()) {   // if the player hasn't gotten 21 points with the first 2 cards
            playerTurn();  // handle player's turn
        }
        
        determineWinner();  // determine the winner of the round;; the dealer's turn is also handled there

        cout << "Balance at the beginning of the round: " << player.getBalance() << " euros\n";
    }

    cout << "Game over! You don't have enough money to continue playing!!\n";
}

// handle the player's turn
void Game::playerTurn() {
    string action;
    player.setTakenAction(false); // reset action flag at the start of the turn

    while (true) {
        // display the current state of the player's and dealer's hands
        cout << "Your hand: " << player.getTotal() << " (" << player.getHand().toString() << ")\n";
        cout << "Dealer's hand: " << dealer.getTotal() << " (" << dealer.getHand().toString() << ")\n";
        cout << "Hit, stand, double, surrender, or split? ";
        cin >> action;
        transform(action.begin(), action.end(), action.begin(), ::tolower); // converts all characters in the action string to lowercase

        if (action == "hit") {
            player.hit(deck.dealCard());
            if (player.isBusted()) {
                cout << "You busted!\n";
                break;
            }
        }
        else if (action == "stand") {
            player.stand();
            break;
        }
        else if (action == "double" && !player.hasTakenAction()) {
            player.hit(deck.dealCard());
            player.setDoubled(true);
            break;
        }
        else if (action == "surrender" && !player.hasTakenAction()) {
            player.setSurrendered(true);
            break;
        }
        else if (action == "split" && player.canSplit() && !player.hasTakenAction()) {
            player.splitHand();
            for (int i = 0; i < player.getHands().size(); ++i) {
                player.setCurrentHandIndex(i);
                cout << "Playing hand " << (i + 1) << ":\n";
                playerTurn();
            }
            break;
        }
        else {
            cout << "Invalid input! Please enter 'hit', 'stand', 'double', 'surrender', or 'split'.\n";
        }
    }
}

// handle the dealer's turn
void Game::dealerTurn() {
    while (dealer.getTotal() < 17) {
        dealer.hit(deck.dealCard());
    }
}

// determine the winner of the round
void Game::determineWinner() {
    if (!player.isBusted() && !player.isSurrendered()) {    // if player hasn't busted or surrendered, dealer takes their turn
        dealerTurn(); // dealer takes their turn to ensure proper comparison
    }
    
    for (int i = 0; i < player.getHands().size(); ++i) {
        player.setCurrentHandIndex(i); // set current hand for comparison
        cout << "Your final hand: " << player.getTotal() << " (" << player.getHand().toString() << ")\n";
        cout << "Dealer's final hand: " << dealer.getTotal() << " (" << dealer.getHand().toString() << ")\n";

        int bet = player.isDoubled() ? 20 : 10; //  sets bet to 20 if player.isDoubled() returns true, otherwise sets it to 10

        if (player.isSurrendered()) {
            cout << "You surrendered!\n";
            player.adjustBalance(-5); // half of the original bet
        }
        else if (player.hasBlackjack()) {
            cout << "Blackjack!! You win!\n";
            player.adjustBalance(15); // in case of Blackjack the player wins 150% of their original bet (so 15 euro in our game)
        }
        else if (player.isBusted()) {
            cout << "You busted! Dealer wins!\n";
            player.adjustBalance(-bet);
        }
        else if (dealer.isBusted() || player.getTotal() > dealer.getTotal()) {
            cout << "You win!\n";
            player.adjustBalance(bet);
        }
        else if (player.getTotal() < dealer.getTotal()) {
            cout << "Dealer wins!\n";
            player.adjustBalance(-bet);
        }
        else {
            cout << "It's a tie!\n";
        }
    }

    player.resetDoubleAndSurrender(); // reset flags for next round
    player.clearHand();  // clear hands at the end of each round
    dealer.clearHand();

    cout << "Your balance: " << player.getBalance() << " euros\n";
    cout << "______________________________\n";
}
