#include <iostream>

#include "deck.h"


int main(int argc, char **argv) {
    Deck deck; //create deck

    deck.shuffle(); //shuffles the deck


    //Draws 10 cards and prints each one
    std::cout << "\n******Draw 10 cards:********* " << std::endl;
    for (int i = 0; i < 10; i++) {
        Card* oneCard = deck.draw();
        oneCard->printCard();
    }

    deck.shuffle(); //reshuffles the deck

    //Draws 10 cards and prints each one
    std::cout << "\n*********Draw 10 cards:********** " << std::endl;
    for (int i = 0; i < 10; i++) {
        Card* oneCard = deck.draw();
        oneCard->printCard();
    }

    return 0;
}
